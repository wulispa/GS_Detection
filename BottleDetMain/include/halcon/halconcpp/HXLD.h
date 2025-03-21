/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HXLD
#define HCPP_HXLD

namespace HalconCpp
{

// Represents an instance of an XLD object-(array).
class LIntExport HXLD : public HObject
{

public:

  // Create an uninitialized instance
  HXLD():HObject() {}

  // Copy constructor
  HXLD(const HXLD& source) : HObject(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HXLD& operator=(const HXLD&) = default;
#endif

  // Copy constructor
  HXLD(const HObject& object);

  // Create HXLD from object id. For copy=false takes
  // over management of input key. Type of key must match!
  explicit HXLD(Hkey key, bool copy=true);

  // Access of object tuple element
  const HXLD operator [] (Hlong index) const;

  // Deep copy of all data represented by this object instance
  HXLD Clone() const;




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Return an XLD parallel's data (as lines).
  void GetParallelsXld(HTuple* Row1, HTuple* Col1, HTuple* Length1, HTuple* Phi1, HTuple* Row2, HTuple* Col2, HTuple* Length2, HTuple* Phi2) const;

  // Display an XLD object.
  void DispXld(const HWindow& WindowHandle) const;

  // Receive an XLD object over a socket connection.
  void ReceiveXld(const HSocket& Socket);

  // Send an XLD object over a socket connection.
  void SendXld(const HSocket& Socket) const;

  // Calculate the difference of two object tuples.
  HXLD ObjDiff(const HXLD& ObjectsSub) const;

  // Paint XLD objects into an image.
  HImage PaintXld(const HImage& Image, const HTuple& Grayval) const;

  // Paint XLD objects into an image.
  HImage PaintXld(const HImage& Image, double Grayval) const;

  // Copy an iconic object in the HALCON database.
  HXLD CopyObj(Hlong Index, Hlong NumObj) const;

  // Concatenate two iconic object tuples.
  HXLD ConcatObj(const HXLD& Objects2) const;

  // Select objects from an object tuple.
  HXLD SelectObj(const HTuple& Index) const;

  // Select objects from an object tuple.
  HXLD SelectObj(Hlong Index) const;

  // Compare iconic objects regarding equality.
  Hlong CompareObj(const HXLD& Objects2, const HTuple& Epsilon) const;

  // Compare iconic objects regarding equality.
  Hlong CompareObj(const HXLD& Objects2, double Epsilon) const;

  // Compare image objects regarding equality.
  Hlong TestEqualObj(const HXLD& Objects2) const;

  // Compute the mapping between the distorted image and the rectified image based upon the points of a regular grid.
  HImage GenGridRectificationMap(const HImage& Image, HXLD* Meshes, Hlong GridSpacing, const HTuple& Rotation, const HTuple& Row, const HTuple& Column, const HString& MapType) const;

  // Compute the mapping between the distorted image and the rectified image based upon the points of a regular grid.
  HImage GenGridRectificationMap(const HImage& Image, HXLD* Meshes, Hlong GridSpacing, const HString& Rotation, const HTuple& Row, const HTuple& Column, const HString& MapType) const;

  // Compute the mapping between the distorted image and the rectified image based upon the points of a regular grid.
  HImage GenGridRectificationMap(const HImage& Image, HXLD* Meshes, Hlong GridSpacing, const char* Rotation, const HTuple& Row, const HTuple& Column, const char* MapType) const;

#ifdef _WIN32
  // Compute the mapping between the distorted image and the rectified image based upon the points of a regular grid.
  HImage GenGridRectificationMap(const HImage& Image, HXLD* Meshes, Hlong GridSpacing, const wchar_t* Rotation, const HTuple& Row, const HTuple& Column, const wchar_t* MapType) const;
#endif

  // Deserialize a serialized XLD object.
  void DeserializeXld(const HSerializedItem& SerializedItemHandle);

  // Serialize an XLD object.
  HSerializedItem SerializeXld() const;

  // Test whether contours or polygons are closed.
  HTuple TestClosedXld() const;

  // Arbitrary geometric moments of contours or polygons treated as point clouds.
  HTuple MomentsAnyPointsXld(const HString& Mode, const HTuple& Area, const HTuple& CenterRow, const HTuple& CenterCol, const HTuple& P, const HTuple& Q) const;

  // Arbitrary geometric moments of contours or polygons treated as point clouds.
  double MomentsAnyPointsXld(const HString& Mode, double Area, double CenterRow, double CenterCol, Hlong P, Hlong Q) const;

  // Arbitrary geometric moments of contours or polygons treated as point clouds.
  double MomentsAnyPointsXld(const char* Mode, double Area, double CenterRow, double CenterCol, Hlong P, Hlong Q) const;

#ifdef _WIN32
  // Arbitrary geometric moments of contours or polygons treated as point clouds.
  double MomentsAnyPointsXld(const wchar_t* Mode, double Area, double CenterRow, double CenterCol, Hlong P, Hlong Q) const;
#endif

  // Anisometry of contours or polygons treated as point clouds.
  HTuple EccentricityPointsXld() const;

  // Parameters of the equivalent ellipse of contours or polygons treated as point clouds.
  HTuple EllipticAxisPointsXld(HTuple* Rb, HTuple* Phi) const;

  // Parameters of the equivalent ellipse of contours or polygons treated as point clouds.
  double EllipticAxisPointsXld(double* Rb, double* Phi) const;

  // Calculate the orientation of contours or polygons treated as point clouds.
  HTuple OrientationPointsXld() const;

  // Geometric moments M20@f$M_{20}$, M02@f$M_{02}$, and M11@f$M_{11}$ of contours or polygons treated as point clouds.
  HTuple MomentsPointsXld(HTuple* M20, HTuple* M02) const;

  // Geometric moments M20@f$M_{20}$, M02@f$M_{02}$, and M11@f$M_{11}$ of contours or polygons treated as point clouds.
  double MomentsPointsXld(double* M20, double* M02) const;

  // Area and center of gravity (centroid) of contours and polygons treated as point clouds.
  HTuple AreaCenterPointsXld(HTuple* Row, HTuple* Column) const;

  // Area and center of gravity (centroid) of contours and polygons treated as point clouds.
  double AreaCenterPointsXld(double* Row, double* Column) const;

  // Test XLD contours or polygons for self intersection.
  HTuple TestSelfIntersectionXld(const HString& CloseXLD) const;

  // Test XLD contours or polygons for self intersection.
  HTuple TestSelfIntersectionXld(const char* CloseXLD) const;

#ifdef _WIN32
  // Test XLD contours or polygons for self intersection.
  HTuple TestSelfIntersectionXld(const wchar_t* CloseXLD) const;
#endif

  // Choose all contours or polygons containing a given point.
  HXLD SelectXldPoint(const HTuple& Row, const HTuple& Column) const;

  // Choose all contours or polygons containing a given point.
  HXLD SelectXldPoint(double Row, double Column) const;

  // Test whether one or more contours or polygons enclose the given point(s).
  HTuple TestXldPoint(const HTuple& Row, const HTuple& Column) const;

  // Test whether one or more contours or polygons enclose the given point(s).
  Hlong TestXldPoint(double Row, double Column) const;

  // Select contours or polygons using shape features.
  HXLD SelectShapeXld(const HTuple& Features, const HString& Operation, const HTuple& Min, const HTuple& Max) const;

  // Select contours or polygons using shape features.
  HXLD SelectShapeXld(const HString& Features, const HString& Operation, double Min, double Max) const;

  // Select contours or polygons using shape features.
  HXLD SelectShapeXld(const char* Features, const char* Operation, double Min, double Max) const;

#ifdef _WIN32
  // Select contours or polygons using shape features.
  HXLD SelectShapeXld(const wchar_t* Features, const wchar_t* Operation, double Min, double Max) const;
#endif

  // Calculate the orientation of contours or polygons.
  HTuple OrientationXld() const;

  // Shape features derived from the ellipse parameters of contours or polygons.
  HTuple EccentricityXld(HTuple* Bulkiness, HTuple* StructureFactor) const;

  // Shape features derived from the ellipse parameters of contours or polygons.
  double EccentricityXld(double* Bulkiness, double* StructureFactor) const;

  // Shape factor for the compactness of contours or polygons.
  HTuple CompactnessXld() const;

  // Maximum distance between two contour or polygon points.
  void DiameterXld(HTuple* Row1, HTuple* Column1, HTuple* Row2, HTuple* Column2, HTuple* Diameter) const;

  // Maximum distance between two contour or polygon points.
  void DiameterXld(double* Row1, double* Column1, double* Row2, double* Column2, double* Diameter) const;

  // Shape factor for the convexity of contours or polygons.
  HTuple ConvexityXld() const;

  // Shape factor for the circularity (similarity to a circle) of contours or polygons.
  HTuple CircularityXld() const;

  // Parameters of the equivalent ellipse of contours or polygons.
  HTuple EllipticAxisXld(HTuple* Rb, HTuple* Phi) const;

  // Parameters of the equivalent ellipse of contours or polygons.
  double EllipticAxisXld(double* Rb, double* Phi) const;

  // Smallest enclosing rectangle with arbitrary orientation of contours or polygons.
  void SmallestRectangle2Xld(HTuple* Row, HTuple* Column, HTuple* Phi, HTuple* Length1, HTuple* Length2) const;

  // Smallest enclosing rectangle with arbitrary orientation of contours or polygons.
  void SmallestRectangle2Xld(double* Row, double* Column, double* Phi, double* Length1, double* Length2) const;

  // Enclosing rectangle parallel to the coordinate axes of contours or polygons.
  void SmallestRectangle1Xld(HTuple* Row1, HTuple* Column1, HTuple* Row2, HTuple* Column2) const;

  // Enclosing rectangle parallel to the coordinate axes of contours or polygons.
  void SmallestRectangle1Xld(double* Row1, double* Column1, double* Row2, double* Column2) const;

  // Smallest enclosing circle of contours or polygons.
  void SmallestCircleXld(HTuple* Row, HTuple* Column, HTuple* Radius) const;

  // Smallest enclosing circle of contours or polygons.
  void SmallestCircleXld(double* Row, double* Column, double* Radius) const;

  // Transform the shape of contours or polygons.
  HXLD ShapeTransXld(const HString& Type) const;

  // Transform the shape of contours or polygons.
  HXLD ShapeTransXld(const char* Type) const;

#ifdef _WIN32
  // Transform the shape of contours or polygons.
  HXLD ShapeTransXld(const wchar_t* Type) const;
#endif

  // Length of contours or polygons.
  HTuple LengthXld() const;

  // Arbitrary geometric moments of contours or polygons.
  HTuple MomentsAnyXld(const HString& Mode, const HTuple& PointOrder, const HTuple& Area, const HTuple& CenterRow, const HTuple& CenterCol, const HTuple& P, const HTuple& Q) const;

  // Arbitrary geometric moments of contours or polygons.
  double MomentsAnyXld(const HString& Mode, const HString& PointOrder, double Area, double CenterRow, double CenterCol, Hlong P, Hlong Q) const;

  // Arbitrary geometric moments of contours or polygons.
  double MomentsAnyXld(const char* Mode, const char* PointOrder, double Area, double CenterRow, double CenterCol, Hlong P, Hlong Q) const;

#ifdef _WIN32
  // Arbitrary geometric moments of contours or polygons.
  double MomentsAnyXld(const wchar_t* Mode, const wchar_t* PointOrder, double Area, double CenterRow, double CenterCol, Hlong P, Hlong Q) const;
#endif

  // Geometric moments M20@f$M_{20}$, M02@f$M_{02}$, and M11@f$M_{11}$ of contours or polygons.
  HTuple MomentsXld(HTuple* M20, HTuple* M02) const;

  // Geometric moments M20@f$M_{20}$, M02@f$M_{02}$, and M11@f$M_{11}$ of contours or polygons.
  double MomentsXld(double* M20, double* M02) const;

  // Area and center of gravity (centroid) of contours and polygons.
  HTuple AreaCenterXld(HTuple* Row, HTuple* Column, HTuple* PointOrder) const;

  // Area and center of gravity (centroid) of contours and polygons.
  double AreaCenterXld(double* Row, double* Column, HString* PointOrder) const;

  // Determine the 3D pose of a rectangle from its perspective 2D projection
  HPoseArray GetRectanglePose(const HCamPar& CameraParam, const HTuple& Width, const HTuple& Height, const HString& WeightingMode, double ClippingFactor, HTuple* CovPose, HTuple* Error) const;

  // Determine the 3D pose of a rectangle from its perspective 2D projection
  HPose GetRectanglePose(const HCamPar& CameraParam, double Width, double Height, const HString& WeightingMode, double ClippingFactor, HTuple* CovPose, HTuple* Error) const;

  // Determine the 3D pose of a rectangle from its perspective 2D projection
  HPose GetRectanglePose(const HCamPar& CameraParam, double Width, double Height, const char* WeightingMode, double ClippingFactor, HTuple* CovPose, HTuple* Error) const;

#ifdef _WIN32
  // Determine the 3D pose of a rectangle from its perspective 2D projection
  HPose GetRectanglePose(const HCamPar& CameraParam, double Width, double Height, const wchar_t* WeightingMode, double ClippingFactor, HTuple* CovPose, HTuple* Error) const;
#endif

  // Determine the 3D pose of a circle from its perspective 2D projection. 
  HTuple GetCirclePose(const HCamPar& CameraParam, const HTuple& Radius, const HString& OutputType, HTuple* Pose2) const;

  // Determine the 3D pose of a circle from its perspective 2D projection. 
  HTuple GetCirclePose(const HCamPar& CameraParam, double Radius, const HString& OutputType, HTuple* Pose2) const;

  // Determine the 3D pose of a circle from its perspective 2D projection. 
  HTuple GetCirclePose(const HCamPar& CameraParam, double Radius, const char* OutputType, HTuple* Pose2) const;

#ifdef _WIN32
  // Determine the 3D pose of a circle from its perspective 2D projection. 
  HTuple GetCirclePose(const HCamPar& CameraParam, double Radius, const wchar_t* OutputType, HTuple* Pose2) const;
#endif

  // Compute the width, height, and aspect ratio of the enclosing rectangle parallel to the coordinate axes of contours or polygons.
  HTuple HeightWidthRatioXld(HTuple* Width, HTuple* Ratio) const;

  // Compute the width, height, and aspect ratio of the enclosing rectangle parallel to the coordinate axes of contours or polygons.
  double HeightWidthRatioXld(double* Width, double* Ratio) const;

  // Insert objects into an iconic object tuple.
  HXLD InsertObj(const HXLD& ObjectsInsert, Hlong Index) const;

  // Remove objects from an iconic object tuple.
  HXLD RemoveObj(const HTuple& Index) const;

  // Remove objects from an iconic object tuple.
  HXLD RemoveObj(Hlong Index) const;

  // Replaces one or more elements of an iconic object tuple.
  HXLD ReplaceObj(const HXLD& ObjectsReplace, const HTuple& Index) const;

  // Replaces one or more elements of an iconic object tuple.
  HXLD ReplaceObj(const HXLD& ObjectsReplace, Hlong Index) const;

  // Shape factor for the rectangularity of contours or polygons.
  HTuple RectangularityXld() const;

private:

  // Verify matching semantic type ('xld')!
  void AssertObjectClass();

};

}

#endif
