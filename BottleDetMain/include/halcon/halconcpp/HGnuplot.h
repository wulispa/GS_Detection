/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HGNUPLOT
#define HCPP_HGNUPLOT

namespace HalconCpp
{

// Represents an instance of a connection to a gnuplot process.
class LIntExport HGnuplot : public HHandle
{

public:

  // Create an uninitialized instance
  HGnuplot():HHandle() {}

  // Copy constructor
  HGnuplot(const HGnuplot& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HGnuplot& operator=(const HGnuplot&) = default;
#endif

  // Copy constructor
  HGnuplot(const HHandle& handle);

  // Create HGnuplot from handle, taking ownership
  explicit HGnuplot(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('gnuplot')!
  virtual void AssertType(Hphandle handle) const;

public:




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Plot a function using gnuplot.
  void GnuplotPlotFunct1d(const HFunction1D& Function) const;

  // Plot control values using gnuplot.
  void GnuplotPlotCtrl(const HTuple& Values) const;

  // Visualize images using gnuplot.
  void GnuplotPlotImage(const HImage& Image, Hlong SamplesX, Hlong SamplesY, const HTuple& ViewRotX, const HTuple& ViewRotZ, const HString& Hidden3D) const;

  // Visualize images using gnuplot.
  void GnuplotPlotImage(const HImage& Image, Hlong SamplesX, Hlong SamplesY, double ViewRotX, double ViewRotZ, const HString& Hidden3D) const;

  // Visualize images using gnuplot.
  void GnuplotPlotImage(const HImage& Image, Hlong SamplesX, Hlong SamplesY, double ViewRotX, double ViewRotZ, const char* Hidden3D) const;

#ifdef _WIN32
  // Visualize images using gnuplot.
  void GnuplotPlotImage(const HImage& Image, Hlong SamplesX, Hlong SamplesY, double ViewRotX, double ViewRotZ, const wchar_t* Hidden3D) const;
#endif

  // Close all open gnuplot files or terminate an active gnuplot sub-process.
  void GnuplotClose() const;

  // Open a gnuplot file for visualization of images and control values.
  void GnuplotOpenFile(const HString& FileName);

  // Open a gnuplot file for visualization of images and control values.
  void GnuplotOpenFile(const char* FileName);

#ifdef _WIN32
  // Open a gnuplot file for visualization of images and control values.
  void GnuplotOpenFile(const wchar_t* FileName);
#endif

  // Open a pipe to a gnuplot process for visualization of images and control values.
  void GnuplotOpenPipe();

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HGnuplot> HGnuplotArrayRef;
typedef HSmartPtr< HGnuplotArrayRef > HGnuplotArrayPtr;


// Represents multiple tool instances
class LIntExport HGnuplotArray : public HHandleBaseArray
{

public:

  // Create empty array
  HGnuplotArray();

  // Create array from native array of tool instances
  HGnuplotArray(const HGnuplot* classes, Hlong length);

  // Copy constructor
  HGnuplotArray(const HGnuplotArray &tool_array);

  // Destructor
  virtual ~HGnuplotArray();

  // Assignment operator
  HGnuplotArray &operator=(const HGnuplotArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HGnuplot* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HGnuplotArrayPtr *mArrayPtr;
};

}

#endif
