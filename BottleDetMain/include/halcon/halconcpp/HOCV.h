/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HOCV
#define HCPP_HOCV

namespace HalconCpp
{

// Represents an instance of a tool for optical character verification.
class LIntExport HOCV : public HHandle
{

public:

  // Create an uninitialized instance
  HOCV():HHandle() {}

  // Copy constructor
  HOCV(const HOCV& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HOCV& operator=(const HOCV&) = default;
#endif

  // Copy constructor
  HOCV(const HHandle& handle);

  // Create HOCV from handle, taking ownership
  explicit HOCV(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('ocv')!
  virtual void AssertType(Hphandle handle) const;

public:

  // Deep copy of all data represented by this object instance
  HOCV Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // read_ocv: Reading an OCV tool from file.
  explicit HOCV(const HString& FileName);

  // read_ocv: Reading an OCV tool from file.
  explicit HOCV(const char* FileName);

#ifdef _WIN32
  // read_ocv: Reading an OCV tool from file.
  explicit HOCV(const wchar_t* FileName);
#endif

  // create_ocv_proj: Create a new OCV tool based on gray value projections.
  explicit HOCV(const HTuple& PatternNames);




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Verification of a pattern using an OCV tool.
  HTuple DoOcvSimple(const HImage& Pattern, const HTuple& PatternName, const HString& AdaptPos, const HString& AdaptSize, const HString& AdaptAngle, const HString& AdaptGray, double Threshold) const;

  // Verification of a pattern using an OCV tool.
  double DoOcvSimple(const HImage& Pattern, const HString& PatternName, const HString& AdaptPos, const HString& AdaptSize, const HString& AdaptAngle, const HString& AdaptGray, double Threshold) const;

  // Verification of a pattern using an OCV tool.
  double DoOcvSimple(const HImage& Pattern, const char* PatternName, const char* AdaptPos, const char* AdaptSize, const char* AdaptAngle, const char* AdaptGray, double Threshold) const;

#ifdef _WIN32
  // Verification of a pattern using an OCV tool.
  double DoOcvSimple(const HImage& Pattern, const wchar_t* PatternName, const wchar_t* AdaptPos, const wchar_t* AdaptSize, const wchar_t* AdaptAngle, const wchar_t* AdaptGray, double Threshold) const;
#endif

  // Training of an OCV tool.
  void TraindOcvProj(const HImage& Pattern, const HTuple& Name, const HString& Mode) const;

  // Training of an OCV tool.
  void TraindOcvProj(const HImage& Pattern, const HString& Name, const HString& Mode) const;

  // Training of an OCV tool.
  void TraindOcvProj(const HImage& Pattern, const char* Name, const char* Mode) const;

#ifdef _WIN32
  // Training of an OCV tool.
  void TraindOcvProj(const HImage& Pattern, const wchar_t* Name, const wchar_t* Mode) const;
#endif

  // Deserialize a serialized OCV tool.
  void DeserializeOcv(const HSerializedItem& SerializedItemHandle);

  // Serialize an OCV tool.
  HSerializedItem SerializeOcv() const;

  // Reading an OCV tool from file.
  void ReadOcv(const HString& FileName);

  // Reading an OCV tool from file.
  void ReadOcv(const char* FileName);

#ifdef _WIN32
  // Reading an OCV tool from file.
  void ReadOcv(const wchar_t* FileName);
#endif

  // Saving an OCV tool to file.
  void WriteOcv(const HString& FileName) const;

  // Saving an OCV tool to file.
  void WriteOcv(const char* FileName) const;

#ifdef _WIN32
  // Saving an OCV tool to file.
  void WriteOcv(const wchar_t* FileName) const;
#endif

  // Clear an OCV tool.
  void CloseOcv() const;

  // Create a new OCV tool based on gray value projections.
  void CreateOcvProj(const HTuple& PatternNames);

  // Create a new OCV tool based on gray value projections.
  void CreateOcvProj(const HString& PatternNames);

  // Create a new OCV tool based on gray value projections.
  void CreateOcvProj(const char* PatternNames);

#ifdef _WIN32
  // Create a new OCV tool based on gray value projections.
  void CreateOcvProj(const wchar_t* PatternNames);
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HOCV> HOCVArrayRef;
typedef HSmartPtr< HOCVArrayRef > HOCVArrayPtr;


// Represents multiple tool instances
class LIntExport HOCVArray : public HHandleBaseArray
{

public:

  // Create empty array
  HOCVArray();

  // Create array from native array of tool instances
  HOCVArray(const HOCV* classes, Hlong length);

  // Copy constructor
  HOCVArray(const HOCVArray &tool_array);

  // Destructor
  virtual ~HOCVArray();

  // Assignment operator
  HOCVArray &operator=(const HOCVArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HOCV* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HOCVArrayPtr *mArrayPtr;
};

}

#endif
