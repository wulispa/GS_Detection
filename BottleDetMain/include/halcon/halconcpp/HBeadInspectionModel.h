/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HBEADINSPECTIONMODEL
#define HCPP_HBEADINSPECTIONMODEL

namespace HalconCpp
{

// Represents an instance of the data structure used to inspect beads.
class LIntExport HBeadInspectionModel : public HHandle
{

public:

  // Create an uninitialized instance
  HBeadInspectionModel():HHandle() {}

  // Copy constructor
  HBeadInspectionModel(const HBeadInspectionModel& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HBeadInspectionModel& operator=(const HBeadInspectionModel&) = default;
#endif

  // Copy constructor
  HBeadInspectionModel(const HHandle& handle);

  // Create HBeadInspectionModel from handle, taking ownership
  explicit HBeadInspectionModel(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('bead_inspection_model')!
  virtual void AssertType(Hphandle handle) const;

public:



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // create_bead_inspection_model: Create a model to inspect beads or adhesive in images.
  explicit HBeadInspectionModel(const HXLD& BeadContour, const HTuple& TargetThickness, const HTuple& ThicknessTolerance, const HTuple& PositionTolerance, const HString& Polarity, const HTuple& GenParamName, const HTuple& GenParamValue);

  // create_bead_inspection_model: Create a model to inspect beads or adhesive in images.
  explicit HBeadInspectionModel(const HXLD& BeadContour, Hlong TargetThickness, Hlong ThicknessTolerance, Hlong PositionTolerance, const HString& Polarity, const HString& GenParamName, Hlong GenParamValue);

  // create_bead_inspection_model: Create a model to inspect beads or adhesive in images.
  explicit HBeadInspectionModel(const HXLD& BeadContour, Hlong TargetThickness, Hlong ThicknessTolerance, Hlong PositionTolerance, const char* Polarity, const char* GenParamName, Hlong GenParamValue);

#ifdef _WIN32
  // create_bead_inspection_model: Create a model to inspect beads or adhesive in images.
  explicit HBeadInspectionModel(const HXLD& BeadContour, Hlong TargetThickness, Hlong ThicknessTolerance, Hlong PositionTolerance, const wchar_t* Polarity, const wchar_t* GenParamName, Hlong GenParamValue);
#endif




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Get the value of a parameter in a specific bead inspection model.
  HTuple GetBeadInspectionParam(const HTuple& GenParamName) const;

  // Get the value of a parameter in a specific bead inspection model.
  HTuple GetBeadInspectionParam(const HString& GenParamName) const;

  // Get the value of a parameter in a specific bead inspection model.
  HTuple GetBeadInspectionParam(const char* GenParamName) const;

#ifdef _WIN32
  // Get the value of a parameter in a specific bead inspection model.
  HTuple GetBeadInspectionParam(const wchar_t* GenParamName) const;
#endif

  // Set parameters of the bead inspection model.
  void SetBeadInspectionParam(const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Set parameters of the bead inspection model.
  void SetBeadInspectionParam(const HString& GenParamName, const HString& GenParamValue) const;

  // Set parameters of the bead inspection model.
  void SetBeadInspectionParam(const char* GenParamName, const char* GenParamValue) const;

#ifdef _WIN32
  // Set parameters of the bead inspection model.
  void SetBeadInspectionParam(const wchar_t* GenParamName, const wchar_t* GenParamValue) const;
#endif

  // Inspect beads in an image, as defined by the bead inspection model.
  HXLD ApplyBeadInspectionModel(const HImage& Image, HXLD* RightContour, HXLD* ErrorSegment, HTuple* ErrorType) const;

  // Delete the bead inspection model and free the allocated memory.
  void ClearBeadInspectionModel() const;

  // Create a model to inspect beads or adhesive in images.
  void CreateBeadInspectionModel(const HXLD& BeadContour, const HTuple& TargetThickness, const HTuple& ThicknessTolerance, const HTuple& PositionTolerance, const HString& Polarity, const HTuple& GenParamName, const HTuple& GenParamValue);

  // Create a model to inspect beads or adhesive in images.
  void CreateBeadInspectionModel(const HXLD& BeadContour, Hlong TargetThickness, Hlong ThicknessTolerance, Hlong PositionTolerance, const HString& Polarity, const HString& GenParamName, Hlong GenParamValue);

  // Create a model to inspect beads or adhesive in images.
  void CreateBeadInspectionModel(const HXLD& BeadContour, Hlong TargetThickness, Hlong ThicknessTolerance, Hlong PositionTolerance, const char* Polarity, const char* GenParamName, Hlong GenParamValue);

#ifdef _WIN32
  // Create a model to inspect beads or adhesive in images.
  void CreateBeadInspectionModel(const HXLD& BeadContour, Hlong TargetThickness, Hlong ThicknessTolerance, Hlong PositionTolerance, const wchar_t* Polarity, const wchar_t* GenParamName, Hlong GenParamValue);
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HBeadInspectionModel> HBeadInspectionModelArrayRef;
typedef HSmartPtr< HBeadInspectionModelArrayRef > HBeadInspectionModelArrayPtr;


// Represents multiple tool instances
class LIntExport HBeadInspectionModelArray : public HHandleBaseArray
{

public:

  // Create empty array
  HBeadInspectionModelArray();

  // Create array from native array of tool instances
  HBeadInspectionModelArray(const HBeadInspectionModel* classes, Hlong length);

  // Copy constructor
  HBeadInspectionModelArray(const HBeadInspectionModelArray &tool_array);

  // Destructor
  virtual ~HBeadInspectionModelArray();

  // Assignment operator
  HBeadInspectionModelArray &operator=(const HBeadInspectionModelArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HBeadInspectionModel* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HBeadInspectionModelArrayPtr *mArrayPtr;
};

}

#endif
