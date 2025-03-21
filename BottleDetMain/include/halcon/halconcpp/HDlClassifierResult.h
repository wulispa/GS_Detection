/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HDLCLASSIFIERRESULT
#define HCPP_HDLCLASSIFIERRESULT

namespace HalconCpp
{

// Represents an instance of a Deep Neural Network inference step result.
class LIntExport HDlClassifierResult : public HHandle
{

public:

  // Create an uninitialized instance
  HDlClassifierResult():HHandle() {}

  // Copy constructor
  HDlClassifierResult(const HDlClassifierResult& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HDlClassifierResult& operator=(const HDlClassifierResult&) = default;
#endif

  // Copy constructor
  HDlClassifierResult(const HHandle& handle);

  // Create HDlClassifierResult from handle, taking ownership
  explicit HDlClassifierResult(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('dl_classifier_result')!
  virtual void AssertType(Hphandle handle) const;

public:



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // apply_dl_classifier: Infer the class affiliations for a set of images using a deep-learning-based classifier.
  explicit HDlClassifierResult(const HImage& Images, const HDlClassifier& DLClassifierHandle);




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Clear a handle containing the results of the deep-learning-based classification.
  static void ClearDlClassifierResult(const HDlClassifierResultArray& DLClassifierResultHandle);

  // Clear a handle containing the results of the deep-learning-based classification.
  void ClearDlClassifierResult() const;

  // Retrieve classification results inferred by a deep-learning-based classifier.
  HTuple GetDlClassifierResult(const HTuple& Index, const HTuple& GenResultName) const;

  // Retrieve classification results inferred by a deep-learning-based classifier.
  HTuple GetDlClassifierResult(const HString& Index, const HString& GenResultName) const;

  // Retrieve classification results inferred by a deep-learning-based classifier.
  HTuple GetDlClassifierResult(const char* Index, const char* GenResultName) const;

#ifdef _WIN32
  // Retrieve classification results inferred by a deep-learning-based classifier.
  HTuple GetDlClassifierResult(const wchar_t* Index, const wchar_t* GenResultName) const;
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HDlClassifierResult> HDlClassifierResultArrayRef;
typedef HSmartPtr< HDlClassifierResultArrayRef > HDlClassifierResultArrayPtr;


// Represents multiple tool instances
class LIntExport HDlClassifierResultArray : public HHandleBaseArray
{

public:

  // Create empty array
  HDlClassifierResultArray();

  // Create array from native array of tool instances
  HDlClassifierResultArray(const HDlClassifierResult* classes, Hlong length);

  // Copy constructor
  HDlClassifierResultArray(const HDlClassifierResultArray &tool_array);

  // Destructor
  virtual ~HDlClassifierResultArray();

  // Assignment operator
  HDlClassifierResultArray &operator=(const HDlClassifierResultArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HDlClassifierResult* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HDlClassifierResultArrayPtr *mArrayPtr;
};

}

#endif
