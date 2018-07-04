#include "onnx/onnxifi.h"
#include "onnx_xla/backend.h"
#include <thread>
#include <mutex>
#include <condition_variable>

//TODO: Robust error handling
//TODO: Implement Event functions
//TODO: Figure out how to determine type of device, what information to store
//      about hardware, and how to modify execution as a result

#define ONNXIFI_CATCH_EXCPETION()                                              \
  catch (const std::exception &e) {                                            \
    std::cerr << "Internal Error: " << e.what() << std::endl;                  \
    return ONNXIFI_STATUS_INTERNAL_ERROR;                                      \
  }                                                                            \
  catch (...) {                                                                \
    return ONNXIFI_STATUS_INTERNAL_ERROR;                                      \
  }


//TODO: More formal representation of backendID - CPU, GPU, TPU?
struct OnnxXlaBackendID {
  int device_id{0};
};

struct EventControl {
  EventControl() : signalled_(false) {}
  volatile bool signalled_;
  std::mutex mutex_;
  std::condition_variable condvar_;
};


//Backend engine
//  backendID will eventually determine translation detail
struct BackendControl {
public:
  BackendControl(OnnxXlaBackendID* id) : backendID(id) {}
  //use OnnxParser and XlaTransform to return executor
  onnx_xla::XlaExecutor* build(const void* serializedModel, size_t serializedModelSize) {
   
    onnx_xla::OnnxParser parser(serializedModel, serializedModelSize);
    std::unique_ptr<ONNX_NAMESPACE::Graph> ir = parser.parse();
    std::string build_name = ir->name();
    onnx_xla::XlaTransform runner(std::move(ir), build_name);
    runner.translateGraph();
    return runner.executor();
  }
private:
  OnnxXlaBackendID* backendID;
};

//Create 1 backendID
//TODO: Determining # of CPU, GPU, TPU devices and return
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI ONNXIFI_SYMBOL_NAME(
    onnxGetBackendIDs)(onnxBackendID *backendIDs, size_t *numBackends) {
  try {
    *backendIDs = reinterpret_cast<onnxBackendID>(new OnnxXlaBackendID());
    *numBackends = 1;
    return ONNXIFI_STATUS_SUCCESS;
  }
  ONNXIFI_CATCH_EXCPETION();
}

//Free memory for given backend ID
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI
ONNXIFI_SYMBOL_NAME(onnxReleaseBackendID)(onnxBackendID backendID) {
  try {
    if (!backendID) {
      return ONNXIFI_STATUS_INVALID_ID;
    }
    auto *backend_id = reinterpret_cast<OnnxXlaBackendID *>(backendID);
    delete backend_id;
    return ONNXIFI_STATUS_SUCCESS;
  }
  ONNXIFI_CATCH_EXCPETION();
}


//Returning info for given ID
//TODO: Expand for different IDs and fill in commented infoType parts
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI ONNXIFI_SYMBOL_NAME(
    onnxGetBackendInfo)(onnxBackendID backendID, onnxBackendInfo infoType,
                        void *infoValue, size_t *infoValueSize) {
  try {
    if (!infoValueSize) {
      return ONNXIFI_STATUS_INVALID_POINTER;
    }
#define SET_STRING(str)                                                        \
  {                                                                            \
    snprintf((char *)(infoValue), *infoValueSize, str);                        \
    *infoValueSize = strlen(str) + 1;                                          \
  }

#define SET_UINT64(x)                                                          \
  {                                                                            \
    if (*infoValueSize < sizeof(uint64_t)) {                                   \
      return ONNXIFI_STATUS_INVALID_POINTER;                                   \
    }                                                                          \
    *(uint64_t *)(infoValue) = x;                                              \
    *infoValueSize = sizeof(uint64_t);                                         \
  }
    if (infoType == ONNXIFI_BACKEND_NAME) {
      SET_STRING("OnnxXla");
    } else if (infoType == ONNXIFI_BACKEND_VENDOR) {
      SET_STRING("Google");
    } else if (infoType == ONNXIFI_BACKEND_VERSION) {
      SET_STRING("1.0.0");
    } else if (infoType == ONNXIFI_BACKEND_EXTENSIONS) {
      *infoValueSize = 0;
    } else if (infoType == ONNXIFI_BACKEND_DEVICE) {
      SET_STRING("cpu (for now in development)");
    } else if (infoType == ONNXIFI_BACKEND_DEVICE_TYPE) {
      SET_UINT64(ONNXIFI_DEVICE_TYPE_CPU);
    } else if (infoType == ONNXIFI_BACKEND_CAPABILITIES) {
      //SET_UINT64(0UL);
    } else if (infoType == ONNXIFI_BACKEND_INIT_PROPERTIES) {
      //SET_UINT64(0UL);
    } else if (infoType == ONNXIFI_BACKEND_MEMORY_TYPES) {
      SET_UINT64(ONNXIFI_MEMORY_TYPE_CPU);
    } else if (infoType == ONNXIFI_BACKEND_MEMORY_SIZE) {
      /*size_t free, total;
      if (cudaMemGetInfo(&free, &total) != cudaSuccess) {
        return ONNXIFI_STATUS_BACKEND_UNAVAILABLE;
      }
      SET_UINT64(uint64_t(total));*/
    }
    // Dummy numbers
    else if (infoType == ONNXIFI_BACKEND_MAX_GRAPH_SIZE) {
      //SET_UINT64(1000000UL);
    } else if (infoType == ONNXIFI_BACKEND_MAX_GRAPH_COUNT) {
      //SET_UINT64(1UL);
    } else if (infoType == ONNXIFI_BACKEND_MACS_FP32) {
      //SET_UINT64(0UL);
    } else if (infoType == ONNXIFI_BACKEND_MACS_FP16) {
      //SET_UINT64(0UL);
    } else if (infoType == ONNXIFI_BACKEND_MEMORY_BANDWIDTH) {
      //SET_UINT64(0UL);
    } else if (infoType == ONNXIFI_BACKEND_CPU_MEMORY_READ_BANDWIDTH) {
      //SET_UINT64(0UL);
    } else if (infoType == ONNXIFI_BACKEND_CPU_MEMORY_WRITE_BANDWIDTH) {
      //SET_UINT64(0UL);
    } else {
      return ONNXIFI_STATUS_UNSUPPORTED_PARAMETER;
    }
    return ONNXIFI_STATUS_SUCCESS;
#undef RETURN_STRING
#undef SET_UINT64
  }

  ONNXIFI_CATCH_EXCPETION();
}

//TODO: Figure out how to get compatibility e.g. sufficient to run OnnxParser?
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI ONNXIFI_SYMBOL_NAME(
    onnxGetBackendCompatibility)(onnxBackendID backendID, size_t onnxModelSize,
                                 const void *onnxModel) {
  try {
    if (!onnxModel) {
      return ONNXIFI_STATUS_INVALID_POINTER;
    }
    if (onnxModelSize == 0) {
      return ONNXIFI_STATUS_INVALID_SIZE;
    }

    return ONNXIFI_STATUS_SUCCESS;

  }
  ONNXIFI_CATCH_EXCPETION();
}

//TODO: any arguments to pass?
//Create and return a BackendControl object
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI ONNXIFI_SYMBOL_NAME(
    onnxInitBackend)(onnxBackendID backendID, const uint64_t *auxPropertiesList,
                     onnxBackend *backend) {
  try {
    auto *backend_id = reinterpret_cast<OnnxXlaBackendID *>(backendID);
    *backend = reinterpret_cast<onnxBackend>(new BackendControl(backend_id));
    return ONNXIFI_STATUS_SUCCESS;
  }
  ONNXIFI_CATCH_EXCPETION();
}

//Release BackendControl object
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI
ONNXIFI_SYMBOL_NAME(onnxReleaseBackend)(onnxBackend backend) {
  try {
    if (!backend) {
      return ONNXIFI_STATUS_INVALID_BACKEND;
    }
    auto *backendController = reinterpret_cast<BackendControl *>(backend);
    delete backendController;
    return ONNXIFI_STATUS_SUCCESS;
  }
  ONNXIFI_CATCH_EXCPETION();
}


//Create and return XlaExecutor object
// TODO: Ignore the weightDescriptors for now and rely on initialization list
//TODO: error handling with error status codes passed
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI ONNXIFI_SYMBOL_NAME(
    onnxInitGraph)(onnxBackend backend, size_t onnxModelSize,
                   const void *onnxModel, uint32_t weightsCount,
                   const onnxTensorDescriptor *weightDescriptors,
                   onnxGraph *graph) {
  try {
    if (!backend) {
      return ONNXIFI_STATUS_INVALID_BACKEND;
    }
    if (!onnxModel) {
      return ONNXIFI_STATUS_INVALID_POINTER;
    }
    if (onnxModelSize == 0) {
      return ONNXIFI_STATUS_INVALID_SIZE;
    }
    auto *backendController = reinterpret_cast<BackendControl *>(backend);
    *graph = (onnxGraph) backendController->build(onnxModel, onnxModelSize);
    return ONNXIFI_STATUS_SUCCESS;
  }
  ONNXIFI_CATCH_EXCPETION();
}

//Verify IO metadata and use initIO to store location of IO
//TODO: memoryType field ignored for now
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI ONNXIFI_SYMBOL_NAME(
    onnxSetGraphIO)(onnxGraph graph, uint32_t inputsCount,
                    const onnxTensorDescriptor *inputDescriptors,
                    uint32_t outputsCount,
                    const onnxTensorDescriptor *outputDescriptors) {
  try {
    if (!graph) {
      return ONNXIFI_STATUS_INVALID_GRAPH;
    }
    if (!inputDescriptors || !outputDescriptors) {
      return ONNXIFI_STATUS_INVALID_POINTER;
    }
    auto *executor = reinterpret_cast<onnx_xla::XlaExecutor*>(graph);
    executor->initIO(inputsCount, inputDescriptors, outputsCount, outputDescriptors);
    return ONNXIFI_STATUS_SUCCESS;
  }
  ONNXIFI_CATCH_EXCPETION();
}

//Runs the XlaExecutor by sending literals to server and executing computation 
//TODO: support for synchronization primitives; For now assume, they are always set
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI ONNXIFI_SYMBOL_NAME(
    onnxRunGraph)(onnxGraph graph, const onnxMemoryFence *inputFence,
                  onnxMemoryFence *outputFence) {
  try {
    if (!graph) {
      return ONNXIFI_STATUS_INVALID_GRAPH;
    }
    auto *executor = reinterpret_cast<onnx_xla::XlaExecutor *>(graph);
    executor->sendLiterals();
    executor->executeComputation();
    return ONNXIFI_STATUS_SUCCESS;
  }
  ONNXIFI_CATCH_EXCPETION();
}

//Frees executor memory
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI
ONNXIFI_SYMBOL_NAME(onnxReleaseGraph)(onnxGraph graph) {
  try {
    if (!graph) {
      return ONNXIFI_STATUS_INVALID_GRAPH;
    }
    auto *executor = reinterpret_cast<onnx_xla::XlaExecutor *>(graph);
    delete executor;
    return ONNXIFI_STATUS_SUCCESS;
  }
  ONNXIFI_CATCH_EXCPETION();
}

//Initialize event by creating EventControl object on the heap
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI ONNXIFI_SYMBOL_NAME(
    onnxInitEvent)(onnxBackend backend, onnxEvent* event) {
  try {
    if (!event)  {
      return ONNXIFI_STATUS_INVALID_POINTER;
    }
    *event = NULL;

    if (!backend)  {
      return ONNXIFI_STATUS_INVALID_BACKEND;
    }

    *event = reinterpret_cast<onnxEvent>(new EventControl());
    return ONNXIFI_STATUS_SUCCESS;
  }
  ONNXIFI_CATCH_EXCPETION();


}

//Signal Event by changing the signalled boolean under mutex hold
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI ONNXIFI_SYMBOL_NAME(
    onnxSignalEvent)(onnxEvent event)  {
  try {
    if (!event)  {
      return ONNXIFI_STATUS_INVALID_EVENT;
    }
    auto *eventController = reinterpret_cast<EventControl *>(event);
    {
       std::lock_guard<std::mutex> lk(eventController->mutex_);
       if (eventController->signalled_)  {
         return ONNXIFI_STATUS_INVALID_STATE;
       }
       eventController->signalled_ = true;
    }
    eventController->condvar_.notify_all();
    return ONNXIFI_STATUS_SUCCESS;
  }
  ONNXIFI_CATCH_EXCPETION();
}

//Wait for signalled to be turned true using conditional variable to coordinate
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI ONNXIFI_SYMBOL_NAME(
    onnxWaitEvent)(onnxEvent event)  {
  try {
    if (!event)  {
      return ONNXIFI_STATUS_INVALID_EVENT;
    }
    
    auto *eventController = reinterpret_cast<EventControl *>(event);  
    std::unique_lock<std::mutex> lk(eventController->mutex_);
    eventController->condvar_.wait(lk, [&eventController]
                                       {return eventController->signalled_;});
    lk.unlock();
    eventController->condvar_.notify_all();
        
    return ONNXIFI_STATUS_SUCCESS;
  }
  ONNXIFI_CATCH_EXCPETION();

}

//Free memory that was allocated for the EventControl object
ONNXIFI_PUBLIC ONNXIFI_CHECK_RESULT onnxStatus ONNXIFI_ABI ONNXIFI_SYMBOL_NAME(
    onnxReleaseEvent)(onnxEvent event)  {
  try {
    if (!event)  {
      return ONNXIFI_STATUS_INVALID_EVENT;
    }
    auto *eventController = reinterpret_cast<EventControl *>(event);
    delete eventController;
    return ONNXIFI_STATUS_SUCCESS;
  }
  ONNXIFI_CATCH_EXCPETION();

}
