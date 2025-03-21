/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HMESSAGEQUEUE
#define HCPP_HMESSAGEQUEUE

namespace HalconCpp
{

// Represents an instance of a message queue for inter-thread communication.
class LIntExport HMessageQueue : public HHandle
{

public:

  // Copy constructor
  HMessageQueue(const HMessageQueue& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HMessageQueue& operator=(const HMessageQueue&) = default;
#endif

  // Copy constructor
  HMessageQueue(const HHandle& handle);

  // Create HMessageQueue from handle, taking ownership
  explicit HMessageQueue(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('message_queue')!
  virtual void AssertType(Hphandle handle) const;

public:



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // create_message_queue: Create a new empty message queue.
  explicit HMessageQueue();




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Query message queue parameters or information about the queue.
  HTuple GetMessageQueueParam(const HTuple& GenParamName) const;

  // Query message queue parameters or information about the queue.
  HTuple GetMessageQueueParam(const HString& GenParamName) const;

  // Query message queue parameters or information about the queue.
  HTuple GetMessageQueueParam(const char* GenParamName) const;

#ifdef _WIN32
  // Query message queue parameters or information about the queue.
  HTuple GetMessageQueueParam(const wchar_t* GenParamName) const;
#endif

  // Set message queue parameters or invoke commands on the queue.
  void SetMessageQueueParam(const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Set message queue parameters or invoke commands on the queue.
  void SetMessageQueueParam(const HString& GenParamName, const HTuple& GenParamValue) const;

  // Set message queue parameters or invoke commands on the queue.
  void SetMessageQueueParam(const char* GenParamName, const HTuple& GenParamValue) const;

#ifdef _WIN32
  // Set message queue parameters or invoke commands on the queue.
  void SetMessageQueueParam(const wchar_t* GenParamName, const HTuple& GenParamValue) const;
#endif

  // Receive one or more messages from the message queue.
  HMessageArray DequeueMessage(const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Receive one or more messages from the message queue.
  HMessage DequeueMessage(const HString& GenParamName, const HTuple& GenParamValue) const;

  // Receive one or more messages from the message queue.
  HMessage DequeueMessage(const char* GenParamName, const HTuple& GenParamValue) const;

#ifdef _WIN32
  // Receive one or more messages from the message queue.
  HMessage DequeueMessage(const wchar_t* GenParamName, const HTuple& GenParamValue) const;
#endif

  // Enqueue one or more messages to the message queue.
  void EnqueueMessage(const HMessageArray& MessageHandle, const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Enqueue one or more messages to the message queue.
  void EnqueueMessage(const HMessage& MessageHandle, const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Close a message queue handle and release all associated resources.
  static void ClearMessageQueue(const HMessageQueueArray& QueueHandle);

  // Close a message queue handle and release all associated resources.
  void ClearMessageQueue() const;

  // Create a new empty message queue.
  void CreateMessageQueue();

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HMessageQueue> HMessageQueueArrayRef;
typedef HSmartPtr< HMessageQueueArrayRef > HMessageQueueArrayPtr;


// Represents multiple tool instances
class LIntExport HMessageQueueArray : public HHandleBaseArray
{

public:

  // Create empty array
  HMessageQueueArray();

  // Create array from native array of tool instances
  HMessageQueueArray(const HMessageQueue* classes, Hlong length);

  // Copy constructor
  HMessageQueueArray(const HMessageQueueArray &tool_array);

  // Destructor
  virtual ~HMessageQueueArray();

  // Assignment operator
  HMessageQueueArray &operator=(const HMessageQueueArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HMessageQueue* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HMessageQueueArrayPtr *mArrayPtr;
};

}

#endif
