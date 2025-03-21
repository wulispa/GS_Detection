/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HSURFACEMATCHINGRESULT
#define HCPP_HSURFACEMATCHINGRESULT

namespace HalconCpp
{

// Represents an instance of a surface matching result.
class LIntExport HSurfaceMatchingResult : public HHandle
{

public:

  // Create an uninitialized instance
  HSurfaceMatchingResult():HHandle() {}

  // Copy constructor
  HSurfaceMatchingResult(const HSurfaceMatchingResult& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HSurfaceMatchingResult& operator=(const HSurfaceMatchingResult&) = default;
#endif

  // Copy constructor
  HSurfaceMatchingResult(const HHandle& handle);

  // Create HSurfaceMatchingResult from handle, taking ownership
  explicit HSurfaceMatchingResult(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('surface_matching_result')!
  virtual void AssertType(Hphandle handle) const;

public:




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Get details of a result from surface based matching.
  HTuple GetSurfaceMatchingResult(const HTuple& ResultName, Hlong ResultIndex) const;

  // Get details of a result from surface based matching.
  HTuple GetSurfaceMatchingResult(const HString& ResultName, Hlong ResultIndex) const;

  // Get details of a result from surface based matching.
  HTuple GetSurfaceMatchingResult(const char* ResultName, Hlong ResultIndex) const;

#ifdef _WIN32
  // Get details of a result from surface based matching.
  HTuple GetSurfaceMatchingResult(const wchar_t* ResultName, Hlong ResultIndex) const;
#endif

  // Free the memory of a surface matching result.
  static void ClearSurfaceMatchingResult(const HSurfaceMatchingResultArray& SurfaceMatchingResultID);

  // Free the memory of a surface matching result.
  void ClearSurfaceMatchingResult() const;

  // Refine the pose of a surface model in a 3D scene.
  static HPoseArray RefineSurfaceModelPose(const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, const HPoseArray& InitialPose, const HTuple& MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResultArray* SurfaceMatchingResultID);

  // Refine the pose of a surface model in a 3D scene.
  HPose RefineSurfaceModelPose(const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score);

  // Refine the pose of a surface model in a 3D scene.
  HPose RefineSurfaceModelPose(const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const char* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score);

#ifdef _WIN32
  // Refine the pose of a surface model in a 3D scene.
  HPose RefineSurfaceModelPose(const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const wchar_t* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score);
#endif

  // Find the best matches of a surface model in a 3D scene.
  static HPoseArray FindSurfaceModel(const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, const HTuple& MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResultArray* SurfaceMatchingResultID);

  // Find the best matches of a surface model in a 3D scene.
  HPose FindSurfaceModel(const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score);

  // Find the best matches of a surface model in a 3D scene.
  HPose FindSurfaceModel(const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const char* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score);

#ifdef _WIN32
  // Find the best matches of a surface model in a 3D scene.
  HPose FindSurfaceModel(const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const wchar_t* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score);
#endif

  // Find the best matches of a surface model in a 3D scene and images.
  static HPoseArray FindSurfaceModelImage(const HImage& Image, const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, const HTuple& MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResultArray* SurfaceMatchingResultID);

  // Find the best matches of a surface model in a 3D scene and images.
  HPose FindSurfaceModelImage(const HImage& Image, const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score);

  // Find the best matches of a surface model in a 3D scene and images.
  HPose FindSurfaceModelImage(const HImage& Image, const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const char* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score);

#ifdef _WIN32
  // Find the best matches of a surface model in a 3D scene and images.
  HPose FindSurfaceModelImage(const HImage& Image, const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const wchar_t* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score);
#endif

  // Refine the pose of a surface model in a 3D scene and in images.
  static HPoseArray RefineSurfaceModelPoseImage(const HImage& Image, const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, const HPoseArray& InitialPose, const HTuple& MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResultArray* SurfaceMatchingResultID);

  // Refine the pose of a surface model in a 3D scene and in images.
  HPose RefineSurfaceModelPoseImage(const HImage& Image, const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score);

  // Refine the pose of a surface model in a 3D scene and in images.
  HPose RefineSurfaceModelPoseImage(const HImage& Image, const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const char* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score);

#ifdef _WIN32
  // Refine the pose of a surface model in a 3D scene and in images.
  HPose RefineSurfaceModelPoseImage(const HImage& Image, const HSurfaceModel& SurfaceModelID, const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const wchar_t* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score);
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HSurfaceMatchingResult> HSurfaceMatchingResultArrayRef;
typedef HSmartPtr< HSurfaceMatchingResultArrayRef > HSurfaceMatchingResultArrayPtr;


// Represents multiple tool instances
class LIntExport HSurfaceMatchingResultArray : public HHandleBaseArray
{

public:

  // Create empty array
  HSurfaceMatchingResultArray();

  // Create array from native array of tool instances
  HSurfaceMatchingResultArray(const HSurfaceMatchingResult* classes, Hlong length);

  // Copy constructor
  HSurfaceMatchingResultArray(const HSurfaceMatchingResultArray &tool_array);

  // Destructor
  virtual ~HSurfaceMatchingResultArray();

  // Assignment operator
  HSurfaceMatchingResultArray &operator=(const HSurfaceMatchingResultArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HSurfaceMatchingResult* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HSurfaceMatchingResultArrayPtr *mArrayPtr;
};

}

#endif
