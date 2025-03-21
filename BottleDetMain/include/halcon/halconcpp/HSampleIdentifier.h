/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HSAMPLEIDENTIFIER
#define HCPP_HSAMPLEIDENTIFIER

namespace HalconCpp
{

// Represents an instance of a sample identifier.
class LIntExport HSampleIdentifier : public HHandle
{

public:

  // Create an uninitialized instance
  HSampleIdentifier():HHandle() {}

  // Copy constructor
  HSampleIdentifier(const HSampleIdentifier& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HSampleIdentifier& operator=(const HSampleIdentifier&) = default;
#endif

  // Copy constructor
  HSampleIdentifier(const HHandle& handle);

  // Create HSampleIdentifier from handle, taking ownership
  explicit HSampleIdentifier(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('sample_identifier')!
  virtual void AssertType(Hphandle handle) const;

public:

  // Deep copy of all data represented by this object instance
  HSampleIdentifier Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // read_sample_identifier: Read a sample identifier from a file.
  explicit HSampleIdentifier(const HString& FileName);

  // read_sample_identifier: Read a sample identifier from a file.
  explicit HSampleIdentifier(const char* FileName);

#ifdef _WIN32
  // read_sample_identifier: Read a sample identifier from a file.
  explicit HSampleIdentifier(const wchar_t* FileName);
#endif

  // create_sample_identifier: Create a new sample identifier.
  explicit HSampleIdentifier(const HTuple& GenParamName, const HTuple& GenParamValue);




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Free the memory of a sample identifier.
  void ClearSampleIdentifier() const;

  // Deserialize a serialized sample identifier.
  void DeserializeSampleIdentifier(const HSerializedItem& SerializedItemHandle);

  // Read a sample identifier from a file.
  void ReadSampleIdentifier(const HString& FileName);

  // Read a sample identifier from a file.
  void ReadSampleIdentifier(const char* FileName);

#ifdef _WIN32
  // Read a sample identifier from a file.
  void ReadSampleIdentifier(const wchar_t* FileName);
#endif

  // Serialize a sample identifier.
  HSerializedItem SerializeSampleIdentifier() const;

  // Write a sample identifier to a file.
  void WriteSampleIdentifier(const HString& FileName) const;

  // Write a sample identifier to a file.
  void WriteSampleIdentifier(const char* FileName) const;

#ifdef _WIN32
  // Write a sample identifier to a file.
  void WriteSampleIdentifier(const wchar_t* FileName) const;
#endif

  // Identify objects with a sample identifier. 
  HTuple ApplySampleIdentifier(const HImage& Image, Hlong NumResults, double RatingThreshold, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Rating) const;

  // Identify objects with a sample identifier. 
  Hlong ApplySampleIdentifier(const HImage& Image, Hlong NumResults, double RatingThreshold, const HTuple& GenParamName, const HTuple& GenParamValue, double* Rating) const;

  // Get selected parameters of a sample identifier.
  HTuple GetSampleIdentifierParam(const HString& GenParamName) const;

  // Get selected parameters of a sample identifier.
  HTuple GetSampleIdentifierParam(const char* GenParamName) const;

#ifdef _WIN32
  // Get selected parameters of a sample identifier.
  HTuple GetSampleIdentifierParam(const wchar_t* GenParamName) const;
#endif

  // Set selected parameters of a sample identifier.
  void SetSampleIdentifierParam(const HString& GenParamName, const HTuple& GenParamValue) const;

  // Set selected parameters of a sample identifier.
  void SetSampleIdentifierParam(const HString& GenParamName, double GenParamValue) const;

  // Set selected parameters of a sample identifier.
  void SetSampleIdentifierParam(const char* GenParamName, double GenParamValue) const;

#ifdef _WIN32
  // Set selected parameters of a sample identifier.
  void SetSampleIdentifierParam(const wchar_t* GenParamName, double GenParamValue) const;
#endif

  // Retrieve information about an object of a sample identifier.
  HTuple GetSampleIdentifierObjectInfo(const HTuple& ObjectIdx, const HTuple& InfoName) const;

  // Retrieve information about an object of a sample identifier.
  HTuple GetSampleIdentifierObjectInfo(Hlong ObjectIdx, const HString& InfoName) const;

  // Retrieve information about an object of a sample identifier.
  HTuple GetSampleIdentifierObjectInfo(Hlong ObjectIdx, const char* InfoName) const;

#ifdef _WIN32
  // Retrieve information about an object of a sample identifier.
  HTuple GetSampleIdentifierObjectInfo(Hlong ObjectIdx, const wchar_t* InfoName) const;
#endif

  // Define a name or a description for an object of a sample identifier.
  void SetSampleIdentifierObjectInfo(const HTuple& ObjectIdx, const HString& InfoName, const HTuple& InfoValue) const;

  // Define a name or a description for an object of a sample identifier.
  void SetSampleIdentifierObjectInfo(Hlong ObjectIdx, const HString& InfoName, const HString& InfoValue) const;

  // Define a name or a description for an object of a sample identifier.
  void SetSampleIdentifierObjectInfo(Hlong ObjectIdx, const char* InfoName, const char* InfoValue) const;

#ifdef _WIN32
  // Define a name or a description for an object of a sample identifier.
  void SetSampleIdentifierObjectInfo(Hlong ObjectIdx, const wchar_t* InfoName, const wchar_t* InfoValue) const;
#endif

  // Remove training data from a sample identifier.  
  void RemoveSampleIdentifierTrainingData(const HTuple& ObjectIdx, const HTuple& ObjectSampleIdx) const;

  // Remove training data from a sample identifier.  
  void RemoveSampleIdentifierTrainingData(Hlong ObjectIdx, Hlong ObjectSampleIdx) const;

  // Remove preparation data from a sample identifier.  
  void RemoveSampleIdentifierPreparationData(const HTuple& ObjectIdx, const HTuple& ObjectSampleIdx) const;

  // Remove preparation data from a sample identifier.  
  void RemoveSampleIdentifierPreparationData(Hlong ObjectIdx, Hlong ObjectSampleIdx) const;

  // Train a sample identifier.  
  void TrainSampleIdentifier(const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Add training data to an existing sample identifier. 
  Hlong AddSampleIdentifierTrainingData(const HImage& SampleImage, const HTuple& ObjectIdx, const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Add training data to an existing sample identifier. 
  Hlong AddSampleIdentifierTrainingData(const HImage& SampleImage, Hlong ObjectIdx, const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Adapt the internal data structure of a sample identifier to the objects to be identified.  
  void PrepareSampleIdentifier(const HString& RemovePreparationData, const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Adapt the internal data structure of a sample identifier to the objects to be identified.  
  void PrepareSampleIdentifier(const char* RemovePreparationData, const HTuple& GenParamName, const HTuple& GenParamValue) const;

#ifdef _WIN32
  // Adapt the internal data structure of a sample identifier to the objects to be identified.  
  void PrepareSampleIdentifier(const wchar_t* RemovePreparationData, const HTuple& GenParamName, const HTuple& GenParamValue) const;
#endif

  // Add preparation data to an existing sample identifier. 
  Hlong AddSampleIdentifierPreparationData(const HImage& SampleImage, const HTuple& ObjectIdx, const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Add preparation data to an existing sample identifier. 
  Hlong AddSampleIdentifierPreparationData(const HImage& SampleImage, Hlong ObjectIdx, const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Create a new sample identifier.
  void CreateSampleIdentifier(const HTuple& GenParamName, const HTuple& GenParamValue);

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HSampleIdentifier> HSampleIdentifierArrayRef;
typedef HSmartPtr< HSampleIdentifierArrayRef > HSampleIdentifierArrayPtr;


// Represents multiple tool instances
class LIntExport HSampleIdentifierArray : public HHandleBaseArray
{

public:

  // Create empty array
  HSampleIdentifierArray();

  // Create array from native array of tool instances
  HSampleIdentifierArray(const HSampleIdentifier* classes, Hlong length);

  // Copy constructor
  HSampleIdentifierArray(const HSampleIdentifierArray &tool_array);

  // Destructor
  virtual ~HSampleIdentifierArray();

  // Assignment operator
  HSampleIdentifierArray &operator=(const HSampleIdentifierArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HSampleIdentifier* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HSampleIdentifierArrayPtr *mArrayPtr;
};

}

#endif
