/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HWINDOW
#define HCPP_HWINDOW

namespace HalconCpp
{

// Represents an instance of a HALCON window.
class LIntExport HWindow : public HHandle
{

public:

  // Create an uninitialized instance
  HWindow():HHandle() {}

  // Copy constructor
  HWindow(const HWindow& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HWindow& operator=(const HWindow&) = default;
#endif

  // Copy constructor
  HWindow(const HHandle& handle);

  // Create HWindow from handle, taking ownership
  explicit HWindow(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('window')!
  virtual void AssertType(Hphandle handle) const;

public:



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // open_window: Open a graphics window.
  explicit HWindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, const HTuple& FatherWindow, const HString& Mode, const HString& Machine);

  // open_window: Open a graphics window.
  explicit HWindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, void* FatherWindow, const HString& Mode, const HString& Machine);

  // open_window: Open a graphics window.
  explicit HWindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, void* FatherWindow, const char* Mode, const char* Machine);

#ifdef _WIN32
  // open_window: Open a graphics window.
  explicit HWindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, void* FatherWindow, const wchar_t* Mode, const wchar_t* Machine);
#endif


/*****************************************************************************
 * Non-generic convenience members                                           *
 *****************************************************************************/

// open_window: Open a graphics window.
HWindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height);

// Click: Wait until mouse click in window occurs
void Click() const;


  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Display an XLD object.
  void DispXld(const HXLD& XLDObject) const;

  // Gets a copy of the background image of the HALCON window.
  HImage GetWindowBackgroundImage() const;

  // Detach the background image from a HALCON window.
  void DetachBackgroundFromWindow() const;

  // Attach a background image to a HALCON window.
  void AttachBackgroundToWindow(const HImage& Image) const;

  // Detach an existing drawing object from a HALCON window.
  void DetachDrawingObjectFromWindow(const HDrawingObject& DrawHandle) const;

  // Attach an existing drawing object to a HALCON window.
  void AttachDrawingObjectToWindow(const HDrawingObject& DrawHandle) const;

  // Modify the pose of a 3D plot.
  void UpdateWindowPose(const HTuple& LastRow, const HTuple& LastCol, const HTuple& CurrentRow, const HTuple& CurrentCol, const HString& Mode) const;

  // Modify the pose of a 3D plot.
  void UpdateWindowPose(double LastRow, double LastCol, double CurrentRow, double CurrentCol, const HString& Mode) const;

  // Modify the pose of a 3D plot.
  void UpdateWindowPose(double LastRow, double LastCol, double CurrentRow, double CurrentCol, const char* Mode) const;

#ifdef _WIN32
  // Modify the pose of a 3D plot.
  void UpdateWindowPose(double LastRow, double LastCol, double CurrentRow, double CurrentCol, const wchar_t* Mode) const;
#endif

  // Calculates image coordinates for a point in a 3D plot window.
  void UnprojectCoordinates(const HImage& Image, const HTuple& Row, const HTuple& Column, Hlong* ImageRow, Hlong* ImageColumn, HTuple* Height) const;

  // Calculates image coordinates for a point in a 3D plot window.
  void UnprojectCoordinates(const HImage& Image, double Row, double Column, Hlong* ImageRow, Hlong* ImageColumn, Hlong* Height) const;

  // Get the operating system window handle.
  void* GetOsWindowHandle(void** OSDisplayHandle) const;

  // Set the device context of a virtual graphics window (Windows NT).
  void SetWindowDc(void* WINHDC) const;

  // Create a virtual graphics window under Windows.
  void NewExternWindow(void* WINHWnd, Hlong Row, Hlong Column, Hlong Width, Hlong Height);

  // Interactive output from two window buffers.
  void SlideImage(const HWindow& WindowHandleSource2, const HWindow& WindowHandle) const;

  // Modify position and size of a window.
  void SetWindowExtents(Hlong Row, Hlong Column, Hlong Width, Hlong Height) const;

  // Open a graphics window.
  void OpenWindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, const HTuple& FatherWindow, const HString& Mode, const HString& Machine);

  // Open a graphics window.
  void OpenWindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, void* FatherWindow, const HString& Mode, const HString& Machine);

  // Open a graphics window.
  void OpenWindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, void* FatherWindow, const char* Mode, const char* Machine);

#ifdef _WIN32
  // Open a graphics window.
  void OpenWindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, void* FatherWindow, const wchar_t* Mode, const wchar_t* Machine);
#endif

  // Open a textual window.
  void OpenTextwindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, Hlong BorderWidth, const HString& BorderColor, const HString& BackgroundColor, const HTuple& FatherWindow, const HString& Mode, const HString& Machine);

  // Open a textual window.
  void OpenTextwindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, Hlong BorderWidth, const HString& BorderColor, const HString& BackgroundColor, void* FatherWindow, const HString& Mode, const HString& Machine);

  // Open a textual window.
  void OpenTextwindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, Hlong BorderWidth, const char* BorderColor, const char* BackgroundColor, void* FatherWindow, const char* Mode, const char* Machine);

#ifdef _WIN32
  // Open a textual window.
  void OpenTextwindow(Hlong Row, Hlong Column, Hlong Width, Hlong Height, Hlong BorderWidth, const wchar_t* BorderColor, const wchar_t* BackgroundColor, void* FatherWindow, const wchar_t* Mode, const wchar_t* Machine);
#endif

  // Copy inside an output window.
  void MoveRectangle(const HTuple& Row1, const HTuple& Column1, const HTuple& Row2, const HTuple& Column2, const HTuple& DestRow, const HTuple& DestColumn) const;

  // Copy inside an output window.
  void MoveRectangle(Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2, Hlong DestRow, Hlong DestColumn) const;

  // Get the window type.
  HString GetWindowType() const;

  // Access to a window's pixel data.
  void GetWindowPointer3(Hlong* ImageRed, Hlong* ImageGreen, Hlong* ImageBlue, Hlong* Width, Hlong* Height) const;

  // Information about a window's size and position.
  void GetWindowExtents(Hlong* Row, Hlong* Column, Hlong* Width, Hlong* Height) const;

  // Write the window content in an image object.
  HImage DumpWindowImage() const;

  // Write the window content to a file.
  void DumpWindow(const HTuple& Device, const HString& FileName) const;

  // Write the window content to a file.
  void DumpWindow(const HString& Device, const HString& FileName) const;

  // Write the window content to a file.
  void DumpWindow(const char* Device, const char* FileName) const;

#ifdef _WIN32
  // Write the window content to a file.
  void DumpWindow(const wchar_t* Device, const wchar_t* FileName) const;
#endif

  // Copy all pixels within rectangles between output windows.
  void CopyRectangle(const HWindow& WindowHandleDestination, const HTuple& Row1, const HTuple& Column1, const HTuple& Row2, const HTuple& Column2, const HTuple& DestRow, const HTuple& DestColumn) const;

  // Copy all pixels within rectangles between output windows.
  void CopyRectangle(const HWindow& WindowHandleDestination, Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2, Hlong DestRow, Hlong DestColumn) const;

  // Close an output window.
  static void CloseWindow(const HWindowArray& WindowHandle);

  // Close an output window.
  void CloseWindow() const;

  // Delete the contents of an output window.
  void ClearWindow() const;

  // Delete a rectangle on the output window.
  void ClearRectangle(const HTuple& Row1, const HTuple& Column1, const HTuple& Row2, const HTuple& Column2) const;

  // Delete a rectangle on the output window.
  void ClearRectangle(Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2) const;

  // Print text in a window.
  void WriteString(const HTuple& String) const;

  // Print text in a window.
  void WriteString(const HString& String) const;

  // Print text in a window.
  void WriteString(const char* String) const;

#ifdef _WIN32
  // Print text in a window.
  void WriteString(const wchar_t* String) const;
#endif

  // Set the shape of the text cursor.
  void SetTshape(const HString& TextCursor) const;

  // Set the shape of the text cursor.
  void SetTshape(const char* TextCursor) const;

#ifdef _WIN32
  // Set the shape of the text cursor.
  void SetTshape(const wchar_t* TextCursor) const;
#endif

  // Set the position of the text cursor.
  void SetTposition(Hlong Row, Hlong Column) const;

  // Read a string in a text window.
  HString ReadString(const HString& InString, Hlong Length) const;

  // Read a string in a text window.
  HString ReadString(const char* InString, Hlong Length) const;

#ifdef _WIN32
  // Read a string in a text window.
  HString ReadString(const wchar_t* InString, Hlong Length) const;
#endif

  // Read a character from a window.
  HString ReadChar(HString* Code) const;

  // Set the position of the text cursor to the beginning of the next line.
  void NewLine() const;

  // Get the shape of the text cursor.
  HString GetTshape() const;

  // Get cursor position.
  void GetTposition(Hlong* Row, Hlong* Column) const;

  // Get the maximum size of all characters of a font.
  HTuple GetFontExtents(HTuple* MaxDescent, HTuple* MaxWidth, HTuple* MaxHeight) const;

  // Get the maximum size of all characters of a font.
  Hlong GetFontExtents(Hlong* MaxDescent, Hlong* MaxWidth, Hlong* MaxHeight) const;

  // Get the spatial size of a string.
  HTuple GetStringExtents(const HTuple& Values, HTuple* Descent, HTuple* Width, HTuple* Height) const;

  // Get the spatial size of a string.
  Hlong GetStringExtents(const HString& Values, Hlong* Descent, Hlong* Width, Hlong* Height) const;

  // Get the spatial size of a string.
  Hlong GetStringExtents(const char* Values, Hlong* Descent, Hlong* Width, Hlong* Height) const;

#ifdef _WIN32
  // Get the spatial size of a string.
  Hlong GetStringExtents(const wchar_t* Values, Hlong* Descent, Hlong* Width, Hlong* Height) const;
#endif

  // Query the available fonts.
  HTuple QueryFont() const;

  // Query all shapes available for text cursors.
  HTuple QueryTshape() const;

  // Set the font used for text output.
  void SetFont(const HString& Font) const;

  // Set the font used for text output.
  void SetFont(const char* Font) const;

#ifdef _WIN32
  // Set the font used for text output.
  void SetFont(const wchar_t* Font) const;
#endif

  // Get the current font.
  HString GetFont() const;

  // Get window parameters.
  HTuple GetWindowParam(const HString& Param) const;

  // Get window parameters.
  HTuple GetWindowParam(const char* Param) const;

#ifdef _WIN32
  // Get window parameters.
  HTuple GetWindowParam(const wchar_t* Param) const;
#endif

  // Set window parameters.
  void SetWindowParam(const HString& Param, const HTuple& Value) const;

  // Set window parameters.
  void SetWindowParam(const HString& Param, const HString& Value) const;

  // Set window parameters.
  void SetWindowParam(const char* Param, const char* Value) const;

#ifdef _WIN32
  // Set window parameters.
  void SetWindowParam(const wchar_t* Param, const wchar_t* Value) const;
#endif

  // Define the region output shape.
  void SetShape(const HString& Shape) const;

  // Define the region output shape.
  void SetShape(const char* Shape) const;

#ifdef _WIN32
  // Define the region output shape.
  void SetShape(const wchar_t* Shape) const;
#endif

  // Set the color definition via RGB values.
  void SetRgb(const HTuple& Red, const HTuple& Green, const HTuple& Blue) const;

  // Set the color definition via RGB values.
  void SetRgb(Hlong Red, Hlong Green, Hlong Blue) const;

  // Define a color lookup table index.
  void SetPixel(const HTuple& Pixel) const;

  // Define a color lookup table index.
  void SetPixel(Hlong Pixel) const;

  // Define an interpolation method for gray value output. 
  void SetPartStyle(Hlong Style) const;

  // Modify the displayed image part.
  void SetPart(const HTuple& Row1, const HTuple& Column1, const HTuple& Row2, const HTuple& Column2) const;

  // Modify the displayed image part.
  void SetPart(Hlong Row1, Hlong Column1, Hlong Row2, Hlong Column2) const;

  // Define the gray value output mode.
  void SetPaint(const HTuple& Mode) const;

  // Define the line width for region contour output.
  void SetLineWidth(double Width) const;

  // Define a contour output pattern.
  void SetLineStyle(const HTuple& Style) const;

  // Define the approximation error for contour display.
  void SetLineApprox(Hlong Approximation) const;

  // Define the pixel output function.
  void SetInsert(const HString& Mode) const;

  // Define the pixel output function.
  void SetInsert(const char* Mode) const;

#ifdef _WIN32
  // Define the pixel output function.
  void SetInsert(const wchar_t* Mode) const;
#endif

  // Define output colors (HSI-coded).
  void SetHsi(const HTuple& Hue, const HTuple& Saturation, const HTuple& Intensity) const;

  // Define output colors (HSI-coded).
  void SetHsi(Hlong Hue, Hlong Saturation, Hlong Intensity) const;

  // Define gray values for region output.
  void SetGray(const HTuple& GrayValues) const;

  // Define gray values for region output.
  void SetGray(Hlong GrayValues) const;

  // Define the region fill mode.
  void SetDraw(const HString& Mode) const;

  // Define the region fill mode.
  void SetDraw(const char* Mode) const;

#ifdef _WIN32
  // Define the region fill mode.
  void SetDraw(const wchar_t* Mode) const;
#endif

  // Define the image matrix output clipping.
  void SetComprise(const HString& Mode) const;

  // Define the image matrix output clipping.
  void SetComprise(const char* Mode) const;

#ifdef _WIN32
  // Define the image matrix output clipping.
  void SetComprise(const wchar_t* Mode) const;
#endif

  // Set multiple output colors.
  void SetColored(Hlong NumberOfColors) const;

  // Set output color.
  void SetColor(const HTuple& Color) const;

  // Set output color.
  void SetColor(const HString& Color) const;

  // Set output color.
  void SetColor(const char* Color) const;

#ifdef _WIN32
  // Set output color.
  void SetColor(const wchar_t* Color) const;
#endif

  // Get the current region output shape.
  HString GetShape() const;

  // Get the current color in RGB-coding.
  void GetRgb(HTuple* Red, HTuple* Green, HTuple* Blue) const;

  // Get the current color lookup table index.
  HTuple GetPixel() const;

  // Get the current interpolation mode for gray value display.
  Hlong GetPartStyle() const;

  // Get the image part.
  void GetPart(HTuple* Row1, HTuple* Column1, HTuple* Row2, HTuple* Column2) const;

  // Get the image part.
  void GetPart(Hlong* Row1, Hlong* Column1, Hlong* Row2, Hlong* Column2) const;

  // Get the current display mode for gray values.
  HTuple GetPaint() const;

  // Get the current line width for contour display.
  double GetLineWidth() const;

  // Get the current graphic mode for contours.
  HTuple GetLineStyle() const;

  // Get the current approximation error for contour display.
  Hlong GetLineApprox() const;

  // Get the current display mode.
  HString GetInsert() const;

  // Get the HSI coding of the current color.
  HTuple GetHsi(HTuple* Saturation, HTuple* Intensity) const;

  // Get the current region fill mode.
  HString GetDraw() const;

  // Query the gray value display modes.
  HTuple QueryPaint() const;

  // Query the possible graphic modes.
  HTuple QueryInsert() const;

  // Query the displayable gray values.
  HTuple QueryGray() const;

  // Query all color names.
  HTuple QueryAllColors() const;

  // Query all color names displayable in the window.
  HTuple QueryColor() const;

  // Query the icon for region output
  HRegion GetIcon() const;

  // Icon definition for region output.
  void SetIcon(const HRegion& Icon) const;

  // Displays regions in a window.
  void DispRegion(const HRegion& DispRegions) const;

  // Displays arbitrarily oriented rectangles.
  void DispRectangle2(const HTuple& CenterRow, const HTuple& CenterCol, const HTuple& Phi, const HTuple& Length1, const HTuple& Length2) const;

  // Displays arbitrarily oriented rectangles.
  void DispRectangle2(double CenterRow, double CenterCol, double Phi, double Length1, double Length2) const;

  // Display of rectangles aligned to the coordinate axes.
  void DispRectangle1(const HTuple& Row1, const HTuple& Column1, const HTuple& Row2, const HTuple& Column2) const;

  // Display of rectangles aligned to the coordinate axes.
  void DispRectangle1(double Row1, double Column1, double Row2, double Column2) const;

  // Displays a polyline.
  void DispPolygon(const HTuple& Row, const HTuple& Column) const;

  // Draws lines in a window.
  void DispLine(const HTuple& Row1, const HTuple& Column1, const HTuple& Row2, const HTuple& Column2) const;

  // Draws lines in a window.
  void DispLine(double Row1, double Column1, double Row2, double Column2) const;

  // Displays crosses in a window.
  void DispCross(const HTuple& Row, const HTuple& Column, double Size, double Angle) const;

  // Displays crosses in a window.
  void DispCross(double Row, double Column, double Size, double Angle) const;

  // Displays gray value images.
  void DispImage(const HImage& Image) const;

  // Displays images with several channels.
  void DispChannel(const HImage& MultichannelImage, const HTuple& Channel) const;

  // Displays images with several channels.
  void DispChannel(const HImage& MultichannelImage, Hlong Channel) const;

  // Displays a color (RGB) image
  void DispColor(const HImage& ColorImage) const;

  // Displays ellipses.
  void DispEllipse(const HTuple& CenterRow, const HTuple& CenterCol, const HTuple& Phi, const HTuple& Radius1, const HTuple& Radius2) const;

  // Displays ellipses.
  void DispEllipse(Hlong CenterRow, Hlong CenterCol, double Phi, double Radius1, double Radius2) const;

  // Displays a noise distribution.
  void DispDistribution(const HTuple& Distribution, Hlong Row, Hlong Column, Hlong Scale) const;

  // Displays circles in a window.
  void DispCircle(const HTuple& Row, const HTuple& Column, const HTuple& Radius) const;

  // Displays circles in a window.
  void DispCircle(double Row, double Column, double Radius) const;

  // Displays arrows in a window.
  void DispArrow(const HTuple& Row1, const HTuple& Column1, const HTuple& Row2, const HTuple& Column2, const HTuple& Size) const;

  // Displays arrows in a window.
  void DispArrow(double Row1, double Column1, double Row2, double Column2, double Size) const;

  // Displays circular arcs in a window.
  void DispArc(const HTuple& CenterRow, const HTuple& CenterCol, const HTuple& Angle, const HTuple& BeginRow, const HTuple& BeginCol) const;

  // Displays circular arcs in a window.
  void DispArc(double CenterRow, double CenterCol, double Angle, Hlong BeginRow, Hlong BeginCol) const;

  // Displays image objects (image, region, XLD).
  void DispObj(const HObject& Object) const;

  // Set the current mouse pointer shape.
  void SetMshape(const HString& Cursor) const;

  // Set the current mouse pointer shape.
  void SetMshape(const char* Cursor) const;

#ifdef _WIN32
  // Set the current mouse pointer shape.
  void SetMshape(const wchar_t* Cursor) const;
#endif

  // Query the current mouse pointer shape.
  HString GetMshape() const;

  // Query all available mouse pointer shapes.
  HTuple QueryMshape() const;

  // Query the subpixel mouse position.
  void GetMpositionSubPix(double* Row, double* Column, Hlong* Button) const;

  // Query the mouse position.
  void GetMposition(Hlong* Row, Hlong* Column, Hlong* Button) const;

  // Wait until a mouse button is pressed and get the subpixel mouse position.
  void GetMbuttonSubPix(double* Row, double* Column, Hlong* Button) const;

  // Wait until a mouse button is pressed.
  void GetMbutton(Hlong* Row, Hlong* Column, Hlong* Button) const;

  // Write look-up-table (lut) as file.
  void WriteLut(const HString& FileName) const;

  // Write look-up-table (lut) as file.
  void WriteLut(const char* FileName) const;

#ifdef _WIN32
  // Write look-up-table (lut) as file.
  void WriteLut(const wchar_t* FileName) const;
#endif

  // Graphical view of the look-up-table (lut).
  void DispLut(Hlong Row, Hlong Column, Hlong Scale) const;

  // Query all available look-up-tables (lut).
  HTuple QueryLut() const;

  // Get modification parameters of look-up-table (lut).
  double GetLutStyle(double* Saturation, double* Intensity) const;

  // Changing the look-up-table (lut).
  void SetLutStyle(double Hue, double Saturation, double Intensity) const;

  // Get current look-up-table (lut).
  HTuple GetLut() const;

  // Set "`look-up-table"' (lut).
  void SetLut(const HTuple& LookUpTable) const;

  // Set "`look-up-table"' (lut).
  void SetLut(const HString& LookUpTable) const;

  // Set "`look-up-table"' (lut).
  void SetLut(const char* LookUpTable) const;

#ifdef _WIN32
  // Set "`look-up-table"' (lut).
  void SetLut(const wchar_t* LookUpTable) const;
#endif

  // Get mode of fixing of current look-up-table (lut).
  HString GetFix() const;

  // Set fixing of "`look-up-table"' (lut)
  void SetFix(const HString& Mode) const;

  // Set fixing of "`look-up-table"' (lut)
  void SetFix(const char* Mode) const;

#ifdef _WIN32
  // Set fixing of "`look-up-table"' (lut)
  void SetFix(const wchar_t* Mode) const;
#endif

  // Get fixing of "`look-up-table"' (lut) for "`real color images"'
  HString GetFixedLut() const;

  // Fix "`look-up-table"' (lut) for "`real color images"'.
  void SetFixedLut(const HString& Mode) const;

  // Fix "`look-up-table"' (lut) for "`real color images"'.
  void SetFixedLut(const char* Mode) const;

#ifdef _WIN32
  // Fix "`look-up-table"' (lut) for "`real color images"'.
  void SetFixedLut(const wchar_t* Mode) const;
#endif

  // Interactive movement of a region with restriction of positions.
  HRegion DragRegion3(const HRegion& SourceRegion, const HRegion& MaskRegion, Hlong Row, Hlong Column) const;

  // Interactive movement of a region with fixpoint specification.
  HRegion DragRegion2(const HRegion& SourceRegion, Hlong Row, Hlong Column) const;

  // Interactive moving of a region.
  HRegion DragRegion1(const HRegion& SourceRegion) const;

  // Interactive modification of a NURBS curve using interpolation.
  HXLDCont DrawNurbsInterpMod(const HString& Rotate, const HString& Move, const HString& Scale, const HString& KeepRatio, const HString& Edit, Hlong Degree, const HTuple& RowsIn, const HTuple& ColsIn, const HTuple& TangentsIn, HTuple* ControlRows, HTuple* ControlCols, HTuple* Knots, HTuple* Rows, HTuple* Cols, HTuple* Tangents) const;

  // Interactive modification of a NURBS curve using interpolation.
  HXLDCont DrawNurbsInterpMod(const char* Rotate, const char* Move, const char* Scale, const char* KeepRatio, const char* Edit, Hlong Degree, const HTuple& RowsIn, const HTuple& ColsIn, const HTuple& TangentsIn, HTuple* ControlRows, HTuple* ControlCols, HTuple* Knots, HTuple* Rows, HTuple* Cols, HTuple* Tangents) const;

#ifdef _WIN32
  // Interactive modification of a NURBS curve using interpolation.
  HXLDCont DrawNurbsInterpMod(const wchar_t* Rotate, const wchar_t* Move, const wchar_t* Scale, const wchar_t* KeepRatio, const wchar_t* Edit, Hlong Degree, const HTuple& RowsIn, const HTuple& ColsIn, const HTuple& TangentsIn, HTuple* ControlRows, HTuple* ControlCols, HTuple* Knots, HTuple* Rows, HTuple* Cols, HTuple* Tangents) const;
#endif

  // Interactive drawing of a NURBS curve using interpolation.
  HXLDCont DrawNurbsInterp(const HString& Rotate, const HString& Move, const HString& Scale, const HString& KeepRatio, Hlong Degree, HTuple* ControlRows, HTuple* ControlCols, HTuple* Knots, HTuple* Rows, HTuple* Cols, HTuple* Tangents) const;

  // Interactive drawing of a NURBS curve using interpolation.
  HXLDCont DrawNurbsInterp(const char* Rotate, const char* Move, const char* Scale, const char* KeepRatio, Hlong Degree, HTuple* ControlRows, HTuple* ControlCols, HTuple* Knots, HTuple* Rows, HTuple* Cols, HTuple* Tangents) const;

#ifdef _WIN32
  // Interactive drawing of a NURBS curve using interpolation.
  HXLDCont DrawNurbsInterp(const wchar_t* Rotate, const wchar_t* Move, const wchar_t* Scale, const wchar_t* KeepRatio, Hlong Degree, HTuple* ControlRows, HTuple* ControlCols, HTuple* Knots, HTuple* Rows, HTuple* Cols, HTuple* Tangents) const;
#endif

  // Interactive modification of a NURBS curve.
  HXLDCont DrawNurbsMod(const HString& Rotate, const HString& Move, const HString& Scale, const HString& KeepRatio, const HString& Edit, Hlong Degree, const HTuple& RowsIn, const HTuple& ColsIn, const HTuple& WeightsIn, HTuple* Rows, HTuple* Cols, HTuple* Weights) const;

  // Interactive modification of a NURBS curve.
  HXLDCont DrawNurbsMod(const char* Rotate, const char* Move, const char* Scale, const char* KeepRatio, const char* Edit, Hlong Degree, const HTuple& RowsIn, const HTuple& ColsIn, const HTuple& WeightsIn, HTuple* Rows, HTuple* Cols, HTuple* Weights) const;

#ifdef _WIN32
  // Interactive modification of a NURBS curve.
  HXLDCont DrawNurbsMod(const wchar_t* Rotate, const wchar_t* Move, const wchar_t* Scale, const wchar_t* KeepRatio, const wchar_t* Edit, Hlong Degree, const HTuple& RowsIn, const HTuple& ColsIn, const HTuple& WeightsIn, HTuple* Rows, HTuple* Cols, HTuple* Weights) const;
#endif

  // Interactive drawing of a NURBS curve.
  HXLDCont DrawNurbs(const HString& Rotate, const HString& Move, const HString& Scale, const HString& KeepRatio, Hlong Degree, HTuple* Rows, HTuple* Cols, HTuple* Weights) const;

  // Interactive drawing of a NURBS curve.
  HXLDCont DrawNurbs(const char* Rotate, const char* Move, const char* Scale, const char* KeepRatio, Hlong Degree, HTuple* Rows, HTuple* Cols, HTuple* Weights) const;

#ifdef _WIN32
  // Interactive drawing of a NURBS curve.
  HXLDCont DrawNurbs(const wchar_t* Rotate, const wchar_t* Move, const wchar_t* Scale, const wchar_t* KeepRatio, Hlong Degree, HTuple* Rows, HTuple* Cols, HTuple* Weights) const;
#endif

  // Interactive modification of a contour.
  HXLDCont DrawXldMod(const HXLDCont& ContIn, const HString& Rotate, const HString& Move, const HString& Scale, const HString& KeepRatio, const HString& Edit) const;

  // Interactive modification of a contour.
  HXLDCont DrawXldMod(const HXLDCont& ContIn, const char* Rotate, const char* Move, const char* Scale, const char* KeepRatio, const char* Edit) const;

#ifdef _WIN32
  // Interactive modification of a contour.
  HXLDCont DrawXldMod(const HXLDCont& ContIn, const wchar_t* Rotate, const wchar_t* Move, const wchar_t* Scale, const wchar_t* KeepRatio, const wchar_t* Edit) const;
#endif

  // Interactive drawing of a contour.
  HXLDCont DrawXld(const HString& Rotate, const HString& Move, const HString& Scale, const HString& KeepRatio) const;

  // Interactive drawing of a contour.
  HXLDCont DrawXld(const char* Rotate, const char* Move, const char* Scale, const char* KeepRatio) const;

#ifdef _WIN32
  // Interactive drawing of a contour.
  HXLDCont DrawXld(const wchar_t* Rotate, const wchar_t* Move, const wchar_t* Scale, const wchar_t* KeepRatio) const;
#endif

  // Interactive drawing of any orientated rectangle.
  void DrawRectangle2Mod(double RowIn, double ColumnIn, double PhiIn, double Length1In, double Length2In, double* Row, double* Column, double* Phi, double* Length1, double* Length2) const;

  // Interactive drawing of any orientated rectangle.
  void DrawRectangle2(double* Row, double* Column, double* Phi, double* Length1, double* Length2) const;

  // Draw a rectangle parallel to the coordinate axis.
  void DrawRectangle1Mod(double Row1In, double Column1In, double Row2In, double Column2In, double* Row1, double* Column1, double* Row2, double* Column2) const;

  // Draw a rectangle parallel to the coordinate axis.
  void DrawRectangle1(double* Row1, double* Column1, double* Row2, double* Column2) const;

  // Draw a point.
  void DrawPointMod(double RowIn, double ColumnIn, double* Row, double* Column) const;

  // Draw a point.
  void DrawPoint(double* Row, double* Column) const;

  // Draw a line.
  void DrawLineMod(double Row1In, double Column1In, double Row2In, double Column2In, double* Row1, double* Column1, double* Row2, double* Column2) const;

  // Draw a line.
  void DrawLine(double* Row1, double* Column1, double* Row2, double* Column2) const;

  // Interactive drawing of an ellipse.
  void DrawEllipseMod(double RowIn, double ColumnIn, double PhiIn, double Radius1In, double Radius2In, double* Row, double* Column, double* Phi, double* Radius1, double* Radius2) const;

  // Interactive drawing of an ellipse.
  void DrawEllipse(double* Row, double* Column, double* Phi, double* Radius1, double* Radius2) const;

  // Interactive drawing of a circle.
  void DrawCircleMod(double RowIn, double ColumnIn, double RadiusIn, double* Row, double* Column, double* Radius) const;

  // Interactive drawing of a circle.
  void DrawCircle(double* Row, double* Column, double* Radius) const;

  // Interactive drawing of a closed region.
  HRegion DrawRegion() const;

  // Interactive drawing of a polygon row.
  HRegion DrawPolygon() const;

  // Project and visualize the 3D model of the calibration plate in the image.
  void DispCaltab(const HString& CalPlateDescr, const HCamPar& CameraParam, const HPose& CalPlatePose, double ScaleFac) const;

  // Project and visualize the 3D model of the calibration plate in the image.
  void DispCaltab(const char* CalPlateDescr, const HCamPar& CameraParam, const HPose& CalPlatePose, double ScaleFac) const;

#ifdef _WIN32
  // Project and visualize the 3D model of the calibration plate in the image.
  void DispCaltab(const wchar_t* CalPlateDescr, const HCamPar& CameraParam, const HPose& CalPlatePose, double ScaleFac) const;
#endif

  // Convert image coordinates to window coordinates
  void ConvertCoordinatesImageToWindow(const HTuple& RowImage, const HTuple& ColumnImage, HTuple* RowWindow, HTuple* ColumnWindow) const;

  // Convert image coordinates to window coordinates
  void ConvertCoordinatesImageToWindow(double RowImage, double ColumnImage, double* RowWindow, double* ColumnWindow) const;

  // Convert window coordinates to image coordinates
  void ConvertCoordinatesWindowToImage(const HTuple& RowWindow, const HTuple& ColumnWindow, HTuple* RowImage, HTuple* ColumnImage) const;

  // Convert window coordinates to image coordinates
  void ConvertCoordinatesWindowToImage(double RowWindow, double ColumnWindow, double* RowImage, double* ColumnImage) const;

  // Display text in a window.
  void DispText(const HTuple& String, const HString& CoordSystem, const HTuple& Row, const HTuple& Column, const HTuple& Color, const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Display text in a window.
  void DispText(const HString& String, const HString& CoordSystem, Hlong Row, Hlong Column, const HString& Color, const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Display text in a window.
  void DispText(const char* String, const char* CoordSystem, Hlong Row, Hlong Column, const char* Color, const HTuple& GenParamName, const HTuple& GenParamValue) const;

#ifdef _WIN32
  // Display text in a window.
  void DispText(const wchar_t* String, const wchar_t* CoordSystem, Hlong Row, Hlong Column, const wchar_t* Color, const HTuple& GenParamName, const HTuple& GenParamValue) const;
#endif

  // Flush the contents of a window.
  void FlushBuffer() const;

  // Get the current color in RGBA-coding.
  void GetRgba(HTuple* Red, HTuple* Green, HTuple* Blue, HTuple* Alpha) const;

  // Send an event to a buffer window signaling a mouse double click event.
  HString SendMouseDoubleClickEvent(const HTuple& Row, const HTuple& Column, Hlong Button) const;

  // Send an event to a buffer window signaling a mouse double click event.
  HString SendMouseDoubleClickEvent(Hlong Row, Hlong Column, Hlong Button) const;

  // Send an event to a window buffer signaling a mouse down event.
  HString SendMouseDownEvent(const HTuple& Row, const HTuple& Column, Hlong Button) const;

  // Send an event to a window buffer signaling a mouse down event.
  HString SendMouseDownEvent(Hlong Row, Hlong Column, Hlong Button) const;

  // Send an event to a buffer window signaling a mouse drag event.
  HString SendMouseDragEvent(const HTuple& Row, const HTuple& Column, Hlong Button) const;

  // Send an event to a buffer window signaling a mouse drag event.
  HString SendMouseDragEvent(Hlong Row, Hlong Column, Hlong Button) const;

  // Send an event to a buffer window signaling a mouse up event.
  HString SendMouseUpEvent(const HTuple& Row, const HTuple& Column, Hlong Button) const;

  // Send an event to a buffer window signaling a mouse up event.
  HString SendMouseUpEvent(Hlong Row, Hlong Column, Hlong Button) const;

  // Sets the callback for content updates in buffer window.
  void SetContentUpdateCallback(void* CallbackFunction, const HTuple& CallbackContext) const;

  // Sets the callback for content updates in buffer window.
  void SetContentUpdateCallback(void* CallbackFunction, void* CallbackContext) const;

  // Set the color definition via RGBA values.
  void SetRgba(const HTuple& Red, const HTuple& Green, const HTuple& Blue, const HTuple& Alpha) const;

  // Set the color definition via RGBA values.
  void SetRgba(Hlong Red, Hlong Green, Hlong Blue, Hlong Alpha) const;

  // Get the current contour display fill style.
  HString GetContourStyle() const;

  // Define the contour display fill style.
  void SetContourStyle(const HString& Style) const;

  // Define the contour display fill style.
  void SetContourStyle(const char* Style) const;

#ifdef _WIN32
  // Define the contour display fill style.
  void SetContourStyle(const wchar_t* Style) const;
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HWindow> HWindowArrayRef;
typedef HSmartPtr< HWindowArrayRef > HWindowArrayPtr;


// Represents multiple tool instances
class LIntExport HWindowArray : public HHandleBaseArray
{

public:

  // Create empty array
  HWindowArray();

  // Create array from native array of tool instances
  HWindowArray(const HWindow* classes, Hlong length);

  // Copy constructor
  HWindowArray(const HWindowArray &tool_array);

  // Destructor
  virtual ~HWindowArray();

  // Assignment operator
  HWindowArray &operator=(const HWindowArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HWindow* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HWindowArrayPtr *mArrayPtr;
};

}

#endif
