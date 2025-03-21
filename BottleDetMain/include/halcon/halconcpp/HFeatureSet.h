/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HFEATURESET
#define HCPP_HFEATURESET

namespace HalconCpp
{

// Represents an instance of a training used for the classifier.
class LIntExport HFeatureSet : public HHandle
{

public:

  // Create an uninitialized instance
  HFeatureSet():HHandle() {}

  // Copy constructor
  HFeatureSet(const HFeatureSet& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HFeatureSet& operator=(const HFeatureSet&) = default;
#endif

  // Copy constructor
  HFeatureSet(const HHandle& handle);

  // Create HFeatureSet from handle, taking ownership
  explicit HFeatureSet(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('feature_set')!
  virtual void AssertType(Hphandle handle) const;

public:



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // read_sampset: Read a training data set from a file.
  explicit HFeatureSet(const HString& FileName);

  // read_sampset: Read a training data set from a file.
  explicit HFeatureSet(const char* FileName);

#ifdef _WIN32
  // read_sampset: Read a training data set from a file.
  explicit HFeatureSet(const wchar_t* FileName);
#endif




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Read a training data set from a file.
  void ReadSampset(const HString& FileName);

  // Read a training data set from a file.
  void ReadSampset(const char* FileName);

#ifdef _WIN32
  // Read a training data set from a file.
  void ReadSampset(const wchar_t* FileName);
#endif

  // Train the classifier with one data set.
  void LearnSampsetBox(const HClassBox& ClassifHandle, const HString& Outfile, Hlong NSamples, double StopError, Hlong ErrorN) const;

  // Train the classifier with one data set.
  void LearnSampsetBox(const HClassBox& ClassifHandle, const char* Outfile, Hlong NSamples, double StopError, Hlong ErrorN) const;

#ifdef _WIN32
  // Train the classifier with one data set.
  void LearnSampsetBox(const HClassBox& ClassifHandle, const wchar_t* Outfile, Hlong NSamples, double StopError, Hlong ErrorN) const;
#endif

  // Free memory of a data set.
  void ClearSampset() const;

  // Classify a set of arrays.
  double TestSampsetBox(const HClassBox& ClassifHandle) const;

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HFeatureSet> HFeatureSetArrayRef;
typedef HSmartPtr< HFeatureSetArrayRef > HFeatureSetArrayPtr;


// Represents multiple tool instances
class LIntExport HFeatureSetArray : public HHandleBaseArray
{

public:

  // Create empty array
  HFeatureSetArray();

  // Create array from native array of tool instances
  HFeatureSetArray(const HFeatureSet* classes, Hlong length);

  // Copy constructor
  HFeatureSetArray(const HFeatureSetArray &tool_array);

  // Destructor
  virtual ~HFeatureSetArray();

  // Assignment operator
  HFeatureSetArray &operator=(const HFeatureSetArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HFeatureSet* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HFeatureSetArrayPtr *mArrayPtr;
};

}

#endif
