/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HDEFORMABLESURFACEMATCHINGRESULT
#define HCPP_HDEFORMABLESURFACEMATCHINGRESULT

namespace HalconCpp
{

// Represents an instance of a deformable surface matching result.
class LIntExport HDeformableSurfaceMatchingResult : public HHandle
{

public:

  // Create an uninitialized instance
  HDeformableSurfaceMatchingResult():HHandle() {}

  // Copy constructor
  HDeformableSurfaceMatchingResult(const HDeformableSurfaceMatchingResult& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HDeformableSurfaceMatchingResult& operator=(const HDeformableSurfaceMatchingResult&) = default;
#endif

  // Copy constructor
  HDeformableSurfaceMatchingResult(const HHandle& handle);

  // Create HDeformableSurfaceMatchingResult from handle, taking ownership
  explicit HDeformableSurfaceMatchingResult(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('deformable_surface_matching_result')!
  virtual void AssertType(Hphandle handle) const;

public:




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Get details of a result from deformable surface based matching.
  HTuple GetDeformableSurfaceMatchingResult(const HTuple& ResultName, const HTuple& ResultIndex) const;

  // Get details of a result from deformable surface based matching.
  HTuple GetDeformableSurfaceMatchingResult(const HString& ResultName, Hlong ResultIndex) const;

  // Get details of a result from deformable surface based matching.
  HTuple GetDeformableSurfaceMatchingResult(const char* ResultName, Hlong ResultIndex) const;

#ifdef _WIN32
  // Get details of a result from deformable surface based matching.
  HTuple GetDeformableSurfaceMatchingResult(const wchar_t* ResultName, Hlong ResultIndex) const;
#endif

  // Free the memory of a deformable surface matching result.
  static void ClearDeformableSurfaceMatchingResult(const HDeformableSurfaceMatchingResultArray& DeformableSurfaceMatchingResult);

  // Free the memory of a deformable surface matching result.
  void ClearDeformableSurfaceMatchingResult() const;

  // Refine the position and deformation of a deformable surface model in a 3D scene.
  static HTuple RefineDeformableSurfaceModel(const HDeformableSurfaceModel& DeformableSurfaceModel, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const HObjectModel3D& InitialDeformationObjectModel3D, const HTuple& GenParamName, const HTuple& GenParamValue, HDeformableSurfaceMatchingResultArray* DeformableSurfaceMatchingResult);

  // Refine the position and deformation of a deformable surface model in a 3D scene.
  double RefineDeformableSurfaceModel(const HDeformableSurfaceModel& DeformableSurfaceModel, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const HObjectModel3D& InitialDeformationObjectModel3D, const HString& GenParamName, const HString& GenParamValue);

  // Refine the position and deformation of a deformable surface model in a 3D scene.
  double RefineDeformableSurfaceModel(const HDeformableSurfaceModel& DeformableSurfaceModel, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const HObjectModel3D& InitialDeformationObjectModel3D, const char* GenParamName, const char* GenParamValue);

#ifdef _WIN32
  // Refine the position and deformation of a deformable surface model in a 3D scene.
  double RefineDeformableSurfaceModel(const HDeformableSurfaceModel& DeformableSurfaceModel, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const HObjectModel3D& InitialDeformationObjectModel3D, const wchar_t* GenParamName, const wchar_t* GenParamValue);
#endif

  // Find the best match of a deformable surface model in a 3D scene.
  static HTuple FindDeformableSurfaceModel(const HDeformableSurfaceModel& DeformableSurfaceModel, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const HTuple& MinScore, const HTuple& GenParamName, const HTuple& GenParamValue, HDeformableSurfaceMatchingResultArray* DeformableSurfaceMatchingResult);

  // Find the best match of a deformable surface model in a 3D scene.
  double FindDeformableSurfaceModel(const HDeformableSurfaceModel& DeformableSurfaceModel, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double MinScore, const HTuple& GenParamName, const HTuple& GenParamValue);

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HDeformableSurfaceMatchingResult> HDeformableSurfaceMatchingResultArrayRef;
typedef HSmartPtr< HDeformableSurfaceMatchingResultArrayRef > HDeformableSurfaceMatchingResultArrayPtr;


// Represents multiple tool instances
class LIntExport HDeformableSurfaceMatchingResultArray : public HHandleBaseArray
{

public:

  // Create empty array
  HDeformableSurfaceMatchingResultArray();

  // Create array from native array of tool instances
  HDeformableSurfaceMatchingResultArray(const HDeformableSurfaceMatchingResult* classes, Hlong length);

  // Copy constructor
  HDeformableSurfaceMatchingResultArray(const HDeformableSurfaceMatchingResultArray &tool_array);

  // Destructor
  virtual ~HDeformableSurfaceMatchingResultArray();

  // Assignment operator
  HDeformableSurfaceMatchingResultArray &operator=(const HDeformableSurfaceMatchingResultArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HDeformableSurfaceMatchingResult* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HDeformableSurfaceMatchingResultArrayPtr *mArrayPtr;
};

}

#endif
