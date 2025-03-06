/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HTEXTUREINSPECTIONMODEL
#define HCPP_HTEXTUREINSPECTIONMODEL

namespace HalconCpp
{

// Represents an instance of a texture model for texture inspection.
class LIntExport HTextureInspectionModel : public HHandle
{

public:

  // Create an uninitialized instance
  HTextureInspectionModel():HHandle() {}

  // Copy constructor
  HTextureInspectionModel(const HTextureInspectionModel& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HTextureInspectionModel& operator=(const HTextureInspectionModel&) = default;
#endif

  // Copy constructor
  HTextureInspectionModel(const HHandle& handle);

  // Create HTextureInspectionModel from handle, taking ownership
  explicit HTextureInspectionModel(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('texture_inspection_model')!
  virtual void AssertType(Hphandle handle) const;

public:

  // Deep copy of all data represented by this object instance
  HTextureInspectionModel Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // create_texture_inspection_model: Create a texture inspection model.
  explicit HTextureInspectionModel(const HString& ModelType);

  // create_texture_inspection_model: Create a texture inspection model.
  explicit HTextureInspectionModel(const char* ModelType);

#ifdef _WIN32
  // create_texture_inspection_model: Create a texture inspection model.
  explicit HTextureInspectionModel(const wchar_t* ModelType);
#endif




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Add training images to the texture inspection model.
  HTuple AddTextureInspectionModelImage(const HImage& Image) const;

  // Inspection of the texture within an image.
  HRegion ApplyTextureInspectionModel(const HImage& Image, HTextureInspectionResult* TextureInspectionResultID) const;

  // Clear a texture inspection model and free the allocated memory.
  static void ClearTextureInspectionModel(const HTextureInspectionModelArray& TextureInspectionModel);

  // Clear a texture inspection model and free the allocated memory.
  void ClearTextureInspectionModel() const;

  // Create a texture inspection model.
  void CreateTextureInspectionModel(const HString& ModelType);

  // Create a texture inspection model.
  void CreateTextureInspectionModel(const char* ModelType);

#ifdef _WIN32
  // Create a texture inspection model.
  void CreateTextureInspectionModel(const wchar_t* ModelType);
#endif

  // Deserialize a serialized texture inspection model.
  void DeserializeTextureInspectionModel(const HSerializedItem& SerializedItemHandle);

  // Get the training images contained in a texture inspection model.
  HImage GetTextureInspectionModelImage() const;

  // Query parameters of a texture inspection model.
  HTuple GetTextureInspectionModelParam(const HTuple& GenParamName) const;

  // Query parameters of a texture inspection model.
  HTuple GetTextureInspectionModelParam(const HString& GenParamName) const;

  // Query parameters of a texture inspection model.
  HTuple GetTextureInspectionModelParam(const char* GenParamName) const;

#ifdef _WIN32
  // Query parameters of a texture inspection model.
  HTuple GetTextureInspectionModelParam(const wchar_t* GenParamName) const;
#endif

  // Read a texture inspection model from a file.
  void ReadTextureInspectionModel(const HString& FileName);

  // Read a texture inspection model from a file.
  void ReadTextureInspectionModel(const char* FileName);

#ifdef _WIN32
  // Read a texture inspection model from a file.
  void ReadTextureInspectionModel(const wchar_t* FileName);
#endif

  // Clear all or a user-defined subset of the images of a texture inspection model.
  static HTuple RemoveTextureInspectionModelImage(const HTextureInspectionModelArray& TextureInspectionModel, const HTuple& Indices);

  // Clear all or a user-defined subset of the images of a texture inspection model.
  HTuple RemoveTextureInspectionModelImage(const HTuple& Indices) const;

  // Serialize a texture inspection model.
  HSerializedItem SerializeTextureInspectionModel() const;

  // Set parameters of a texture inspection model.
  void SetTextureInspectionModelParam(const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Set parameters of a texture inspection model.
  void SetTextureInspectionModelParam(const HString& GenParamName, Hlong GenParamValue) const;

  // Set parameters of a texture inspection model.
  void SetTextureInspectionModelParam(const char* GenParamName, Hlong GenParamValue) const;

#ifdef _WIN32
  // Set parameters of a texture inspection model.
  void SetTextureInspectionModelParam(const wchar_t* GenParamName, Hlong GenParamValue) const;
#endif

  // Train a texture inspection model.
  void TrainTextureInspectionModel() const;

  // Write a texture inspection model to a file.
  void WriteTextureInspectionModel(const HString& FileName) const;

  // Write a texture inspection model to a file.
  void WriteTextureInspectionModel(const char* FileName) const;

#ifdef _WIN32
  // Write a texture inspection model to a file.
  void WriteTextureInspectionModel(const wchar_t* FileName) const;
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HTextureInspectionModel> HTextureInspectionModelArrayRef;
typedef HSmartPtr< HTextureInspectionModelArrayRef > HTextureInspectionModelArrayPtr;


// Represents multiple tool instances
class LIntExport HTextureInspectionModelArray : public HHandleBaseArray
{

public:

  // Create empty array
  HTextureInspectionModelArray();

  // Create array from native array of tool instances
  HTextureInspectionModelArray(const HTextureInspectionModel* classes, Hlong length);

  // Copy constructor
  HTextureInspectionModelArray(const HTextureInspectionModelArray &tool_array);

  // Destructor
  virtual ~HTextureInspectionModelArray();

  // Assignment operator
  HTextureInspectionModelArray &operator=(const HTextureInspectionModelArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HTextureInspectionModel* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HTextureInspectionModelArrayPtr *mArrayPtr;
};

}

#endif
