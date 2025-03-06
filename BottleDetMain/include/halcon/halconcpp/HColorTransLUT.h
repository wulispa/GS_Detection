/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HCOLORTRANSLUT
#define HCPP_HCOLORTRANSLUT

namespace HalconCpp
{

// Represents an instance of a color space transformation lookup table
class LIntExport HColorTransLUT : public HHandle
{

public:

  // Create an uninitialized instance
  HColorTransLUT():HHandle() {}

  // Copy constructor
  HColorTransLUT(const HColorTransLUT& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HColorTransLUT& operator=(const HColorTransLUT&) = default;
#endif

  // Copy constructor
  HColorTransLUT(const HHandle& handle);

  // Create HColorTransLUT from handle, taking ownership
  explicit HColorTransLUT(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('color_trans_lut')!
  virtual void AssertType(Hphandle handle) const;

public:



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // create_color_trans_lut: Creates the look-up-table for transformation of an image from the RGB color space to an arbitrary color space.
  explicit HColorTransLUT(const HString& ColorSpace, const HString& TransDirection, Hlong NumBits);

  // create_color_trans_lut: Creates the look-up-table for transformation of an image from the RGB color space to an arbitrary color space.
  explicit HColorTransLUT(const char* ColorSpace, const char* TransDirection, Hlong NumBits);

#ifdef _WIN32
  // create_color_trans_lut: Creates the look-up-table for transformation of an image from the RGB color space to an arbitrary color space.
  explicit HColorTransLUT(const wchar_t* ColorSpace, const wchar_t* TransDirection, Hlong NumBits);
#endif




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Release the look-up-table needed for color space transformation.
  void ClearColorTransLut() const;

  // Color space transformation using pre-generated look-up-table.
  HImage ApplyColorTransLut(const HImage& Image1, const HImage& Image2, const HImage& Image3, HImage* ImageResult2, HImage* ImageResult3) const;

  // Creates the look-up-table for transformation of an image from the RGB color space to an arbitrary color space.
  void CreateColorTransLut(const HString& ColorSpace, const HString& TransDirection, Hlong NumBits);

  // Creates the look-up-table for transformation of an image from the RGB color space to an arbitrary color space.
  void CreateColorTransLut(const char* ColorSpace, const char* TransDirection, Hlong NumBits);

#ifdef _WIN32
  // Creates the look-up-table for transformation of an image from the RGB color space to an arbitrary color space.
  void CreateColorTransLut(const wchar_t* ColorSpace, const wchar_t* TransDirection, Hlong NumBits);
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HColorTransLUT> HColorTransLUTArrayRef;
typedef HSmartPtr< HColorTransLUTArrayRef > HColorTransLUTArrayPtr;


// Represents multiple tool instances
class LIntExport HColorTransLUTArray : public HHandleBaseArray
{

public:

  // Create empty array
  HColorTransLUTArray();

  // Create array from native array of tool instances
  HColorTransLUTArray(const HColorTransLUT* classes, Hlong length);

  // Copy constructor
  HColorTransLUTArray(const HColorTransLUTArray &tool_array);

  // Destructor
  virtual ~HColorTransLUTArray();

  // Assignment operator
  HColorTransLUTArray &operator=(const HColorTransLUTArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HColorTransLUT* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HColorTransLUTArrayPtr *mArrayPtr;
};

}

#endif
