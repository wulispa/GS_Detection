/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HXLDDISTTRANS
#define HCPP_HXLDDISTTRANS

namespace HalconCpp
{

// Represents an instance of a XLD distance transformation.
class LIntExport HXLDDistTrans : public HHandle
{

public:

  // Create an uninitialized instance
  HXLDDistTrans():HHandle() {}

  // Copy constructor
  HXLDDistTrans(const HXLDDistTrans& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HXLDDistTrans& operator=(const HXLDDistTrans&) = default;
#endif

  // Copy constructor
  HXLDDistTrans(const HHandle& handle);

  // Create HXLDDistTrans from handle, taking ownership
  explicit HXLDDistTrans(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('xld_dist_trans')!
  virtual void AssertType(Hphandle handle) const;

public:

  // Deep copy of all data represented by this object instance
  HXLDDistTrans Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // read_distance_transform_xld: Read an XLD distance transform from a file.
  explicit HXLDDistTrans(const HString& FileName);

  // read_distance_transform_xld: Read an XLD distance transform from a file.
  explicit HXLDDistTrans(const char* FileName);

#ifdef _WIN32
  // read_distance_transform_xld: Read an XLD distance transform from a file.
  explicit HXLDDistTrans(const wchar_t* FileName);
#endif

  // create_distance_transform_xld: Create the XLD distance transform.
  explicit HXLDDistTrans(const HXLDCont& Contour, const HString& Mode, const HTuple& MaxDistance);

  // create_distance_transform_xld: Create the XLD distance transform.
  explicit HXLDDistTrans(const HXLDCont& Contour, const HString& Mode, double MaxDistance);

  // create_distance_transform_xld: Create the XLD distance transform.
  explicit HXLDDistTrans(const HXLDCont& Contour, const char* Mode, double MaxDistance);

#ifdef _WIN32
  // create_distance_transform_xld: Create the XLD distance transform.
  explicit HXLDDistTrans(const HXLDCont& Contour, const wchar_t* Mode, double MaxDistance);
#endif




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Clear a XLD distance transform.
  void ClearDistanceTransformXld() const;

  // Determine the pointwise distance of two contours using an XLD distance transform.
  HXLDCont ApplyDistanceTransformXld(const HXLDCont& Contour) const;

  // Read an XLD distance transform from a file.
  void ReadDistanceTransformXld(const HString& FileName);

  // Read an XLD distance transform from a file.
  void ReadDistanceTransformXld(const char* FileName);

#ifdef _WIN32
  // Read an XLD distance transform from a file.
  void ReadDistanceTransformXld(const wchar_t* FileName);
#endif

  // Deserialize an XLD distance transform.
  void DeserializeDistanceTransformXld(const HSerializedItem& SerializedItemHandle);

  // Serialize an XLD distance transform.
  HSerializedItem SerializeDistanceTransformXld() const;

  // Write an XLD distance transform into a file.
  void WriteDistanceTransformXld(const HString& FileName) const;

  // Write an XLD distance transform into a file.
  void WriteDistanceTransformXld(const char* FileName) const;

#ifdef _WIN32
  // Write an XLD distance transform into a file.
  void WriteDistanceTransformXld(const wchar_t* FileName) const;
#endif

  // Set new parameters for an XLD distance transform.
  void SetDistanceTransformXldParam(const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Set new parameters for an XLD distance transform.
  void SetDistanceTransformXldParam(const HString& GenParamName, const HString& GenParamValue) const;

  // Set new parameters for an XLD distance transform.
  void SetDistanceTransformXldParam(const char* GenParamName, const char* GenParamValue) const;

#ifdef _WIN32
  // Set new parameters for an XLD distance transform.
  void SetDistanceTransformXldParam(const wchar_t* GenParamName, const wchar_t* GenParamValue) const;
#endif

  // Get the parameters used to build an XLD distance transform.
  HTuple GetDistanceTransformXldParam(const HTuple& GenParamName) const;

  // Get the parameters used to build an XLD distance transform.
  HTuple GetDistanceTransformXldParam(const HString& GenParamName) const;

  // Get the parameters used to build an XLD distance transform.
  HTuple GetDistanceTransformXldParam(const char* GenParamName) const;

#ifdef _WIN32
  // Get the parameters used to build an XLD distance transform.
  HTuple GetDistanceTransformXldParam(const wchar_t* GenParamName) const;
#endif

  // Get the reference contour used to build the XLD distance transform.
  HXLDCont GetDistanceTransformXldContour() const;

  // Create the XLD distance transform.
  void CreateDistanceTransformXld(const HXLDCont& Contour, const HString& Mode, const HTuple& MaxDistance);

  // Create the XLD distance transform.
  void CreateDistanceTransformXld(const HXLDCont& Contour, const HString& Mode, double MaxDistance);

  // Create the XLD distance transform.
  void CreateDistanceTransformXld(const HXLDCont& Contour, const char* Mode, double MaxDistance);

#ifdef _WIN32
  // Create the XLD distance transform.
  void CreateDistanceTransformXld(const HXLDCont& Contour, const wchar_t* Mode, double MaxDistance);
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HXLDDistTrans> HXLDDistTransArrayRef;
typedef HSmartPtr< HXLDDistTransArrayRef > HXLDDistTransArrayPtr;


// Represents multiple tool instances
class LIntExport HXLDDistTransArray : public HHandleBaseArray
{

public:

  // Create empty array
  HXLDDistTransArray();

  // Create array from native array of tool instances
  HXLDDistTransArray(const HXLDDistTrans* classes, Hlong length);

  // Copy constructor
  HXLDDistTransArray(const HXLDDistTransArray &tool_array);

  // Destructor
  virtual ~HXLDDistTransArray();

  // Assignment operator
  HXLDDistTransArray &operator=(const HXLDDistTransArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HXLDDistTrans* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HXLDDistTransArrayPtr *mArrayPtr;
};

}

#endif
