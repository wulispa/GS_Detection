/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HSURFACEMODEL
#define HCPP_HSURFACEMODEL

namespace HalconCpp
{

// Represents an instance of a surface model.
class LIntExport HSurfaceModel : public HHandle
{

public:

  // Create an uninitialized instance
  HSurfaceModel():HHandle() {}

  // Copy constructor
  HSurfaceModel(const HSurfaceModel& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HSurfaceModel& operator=(const HSurfaceModel&) = default;
#endif

  // Copy constructor
  HSurfaceModel(const HHandle& handle);

  // Create HSurfaceModel from handle, taking ownership
  explicit HSurfaceModel(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('surface_model')!
  virtual void AssertType(Hphandle handle) const;

public:

  // Deep copy of all data represented by this object instance
  HSurfaceModel Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // read_surface_model: Read a surface model from a file.
  explicit HSurfaceModel(const HString& FileName);

  // read_surface_model: Read a surface model from a file.
  explicit HSurfaceModel(const char* FileName);

#ifdef _WIN32
  // read_surface_model: Read a surface model from a file.
  explicit HSurfaceModel(const wchar_t* FileName);
#endif

  // create_surface_model: Create the data structure needed to perform surface-based matching.
  explicit HSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const HTuple& GenParamName, const HTuple& GenParamValue);

  // create_surface_model: Create the data structure needed to perform surface-based matching.
  explicit HSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const HString& GenParamName, const HString& GenParamValue);

  // create_surface_model: Create the data structure needed to perform surface-based matching.
  explicit HSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const char* GenParamName, const char* GenParamValue);

#ifdef _WIN32
  // create_surface_model: Create the data structure needed to perform surface-based matching.
  explicit HSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const wchar_t* GenParamName, const wchar_t* GenParamValue);
#endif




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Free the memory of a surface model.
  static void ClearSurfaceModel(const HSurfaceModelArray& SurfaceModelID);

  // Free the memory of a surface model.
  void ClearSurfaceModel() const;

  // Deserialize a surface model.
  void DeserializeSurfaceModel(const HSerializedItem& SerializedItemHandle);

  // Serialize a surface_model.
  HSerializedItem SerializeSurfaceModel() const;

  // Read a surface model from a file.
  void ReadSurfaceModel(const HString& FileName);

  // Read a surface model from a file.
  void ReadSurfaceModel(const char* FileName);

#ifdef _WIN32
  // Read a surface model from a file.
  void ReadSurfaceModel(const wchar_t* FileName);
#endif

  // Write a surface model to a file.
  void WriteSurfaceModel(const HString& FileName) const;

  // Write a surface model to a file.
  void WriteSurfaceModel(const char* FileName) const;

#ifdef _WIN32
  // Write a surface model to a file.
  void WriteSurfaceModel(const wchar_t* FileName) const;
#endif

  // Refine the pose of a surface model in a 3D scene.
  HPoseArray RefineSurfaceModelPose(const HObjectModel3D& ObjectModel3D, const HPoseArray& InitialPose, const HTuple& MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResultArray* SurfaceMatchingResultID) const;

  // Refine the pose of a surface model in a 3D scene.
  HPose RefineSurfaceModelPose(const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;

  // Refine the pose of a surface model in a 3D scene.
  HPose RefineSurfaceModelPose(const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const char* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;

#ifdef _WIN32
  // Refine the pose of a surface model in a 3D scene.
  HPose RefineSurfaceModelPose(const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const wchar_t* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;
#endif

  // Find the best matches of a surface model in a 3D scene.
  HPoseArray FindSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, const HTuple& MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResultArray* SurfaceMatchingResultID) const;

  // Find the best matches of a surface model in a 3D scene.
  HPose FindSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;

  // Find the best matches of a surface model in a 3D scene.
  HPose FindSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const char* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;

#ifdef _WIN32
  // Find the best matches of a surface model in a 3D scene.
  HPose FindSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const wchar_t* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;
#endif

  // Return the parameters and properties of a surface model.
  HTuple GetSurfaceModelParam(const HTuple& GenParamName) const;

  // Return the parameters and properties of a surface model.
  HTuple GetSurfaceModelParam(const HString& GenParamName) const;

  // Return the parameters and properties of a surface model.
  HTuple GetSurfaceModelParam(const char* GenParamName) const;

#ifdef _WIN32
  // Return the parameters and properties of a surface model.
  HTuple GetSurfaceModelParam(const wchar_t* GenParamName) const;
#endif

  // Create the data structure needed to perform surface-based matching.
  void CreateSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const HTuple& GenParamName, const HTuple& GenParamValue);

  // Create the data structure needed to perform surface-based matching.
  void CreateSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const HString& GenParamName, const HString& GenParamValue);

  // Create the data structure needed to perform surface-based matching.
  void CreateSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const char* GenParamName, const char* GenParamValue);

#ifdef _WIN32
  // Create the data structure needed to perform surface-based matching.
  void CreateSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const wchar_t* GenParamName, const wchar_t* GenParamValue);
#endif

  // Find the best matches of a surface model in a 3D scene and images.
  HPoseArray FindSurfaceModelImage(const HImage& Image, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, const HTuple& MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResultArray* SurfaceMatchingResultID) const;

  // Find the best matches of a surface model in a 3D scene and images.
  HPose FindSurfaceModelImage(const HImage& Image, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;

  // Find the best matches of a surface model in a 3D scene and images.
  HPose FindSurfaceModelImage(const HImage& Image, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const char* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;

#ifdef _WIN32
  // Find the best matches of a surface model in a 3D scene and images.
  HPose FindSurfaceModelImage(const HImage& Image, const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const wchar_t* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;
#endif

  // Refine the pose of a surface model in a 3D scene and in images.
  HPoseArray RefineSurfaceModelPoseImage(const HImage& Image, const HObjectModel3D& ObjectModel3D, const HPoseArray& InitialPose, const HTuple& MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResultArray* SurfaceMatchingResultID) const;

  // Refine the pose of a surface model in a 3D scene and in images.
  HPose RefineSurfaceModelPoseImage(const HImage& Image, const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;

  // Refine the pose of a surface model in a 3D scene and in images.
  HPose RefineSurfaceModelPoseImage(const HImage& Image, const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const char* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;

#ifdef _WIN32
  // Refine the pose of a surface model in a 3D scene and in images.
  HPose RefineSurfaceModelPoseImage(const HImage& Image, const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const wchar_t* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;
#endif

  // Set parameters and properties of a surface model.
  void SetSurfaceModelParam(const HString& GenParamName, const HTuple& GenParamValue) const;

  // Set parameters and properties of a surface model.
  void SetSurfaceModelParam(const HString& GenParamName, double GenParamValue) const;

  // Set parameters and properties of a surface model.
  void SetSurfaceModelParam(const char* GenParamName, double GenParamValue) const;

#ifdef _WIN32
  // Set parameters and properties of a surface model.
  void SetSurfaceModelParam(const wchar_t* GenParamName, double GenParamValue) const;
#endif

  // Find boxes in 3D data.
  static HPoseArray FindBox3d(const HObjectModel3D& ObjectModel3DScene, const HTuple& SideLen1, const HTuple& SideLen2, const HTuple& SideLen3, const HTuple& MinScore, const HDict& GenParam, HTuple* Score, HObjectModel3DArray* ObjectModel3DBox, HDict* BoxInformation);

  // Find boxes in 3D data.
  static HPose FindBox3d(const HObjectModel3D& ObjectModel3DScene, const HTuple& SideLen1, const HTuple& SideLen2, const HTuple& SideLen3, double MinScore, const HDict& GenParam, HTuple* Score, HObjectModel3DArray* ObjectModel3DBox, HDict* BoxInformation);

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HSurfaceModel> HSurfaceModelArrayRef;
typedef HSmartPtr< HSurfaceModelArrayRef > HSurfaceModelArrayPtr;


// Represents multiple tool instances
class LIntExport HSurfaceModelArray : public HHandleBaseArray
{

public:

  // Create empty array
  HSurfaceModelArray();

  // Create array from native array of tool instances
  HSurfaceModelArray(const HSurfaceModel* classes, Hlong length);

  // Copy constructor
  HSurfaceModelArray(const HSurfaceModelArray &tool_array);

  // Destructor
  virtual ~HSurfaceModelArray();

  // Assignment operator
  HSurfaceModelArray &operator=(const HSurfaceModelArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HSurfaceModel* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HSurfaceModelArrayPtr *mArrayPtr;
};

}

#endif
