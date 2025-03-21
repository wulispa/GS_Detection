/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HXLDEXTPARA
#define HCPP_HXLDEXTPARA

namespace HalconCpp
{

// Represents an instance of an XLD extended parallel object(-array).
class LIntExport HXLDExtPara : public HXLD
{

public:

  // Create an uninitialized instance
  HXLDExtPara():HXLD() {}

  // Copy constructor
  HXLDExtPara(const HXLDExtPara& source) : HXLD(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HXLDExtPara& operator=(const HXLDExtPara&) = default;
#endif

  // Copy constructor
  HXLDExtPara(const HObject& object);

  // Create HXLDExtPara from object id. For copy=false takes
  // over management of input key. Type of key must match!
  explicit HXLDExtPara(Hkey key, bool copy=true);

  // Access of object tuple element
  const HXLDExtPara operator [] (Hlong index) const;

  // Deep copy of all data represented by this object instance
  HXLDExtPara Clone() const;




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Join modified XLD parallels lying on the same polygon.
  HXLDPoly MaxParallelsXld() const;

  // Calculate the difference of two object tuples.
  HXLDExtPara ObjDiff(const HXLDExtPara& ObjectsSub) const;

  // Copy an iconic object in the HALCON database.
  HXLDExtPara CopyObj(Hlong Index, Hlong NumObj) const;

  // Concatenate two iconic object tuples.
  HXLDExtPara ConcatObj(const HXLDExtPara& Objects2) const;

  // Select objects from an object tuple.
  HXLDExtPara SelectObj(const HTuple& Index) const;

  // Select objects from an object tuple.
  HXLDExtPara SelectObj(Hlong Index) const;

  // Compare iconic objects regarding equality.
  Hlong CompareObj(const HXLDExtPara& Objects2, const HTuple& Epsilon) const;

  // Compare iconic objects regarding equality.
  Hlong CompareObj(const HXLDExtPara& Objects2, double Epsilon) const;

  // Compare image objects regarding equality.
  Hlong TestEqualObj(const HXLDExtPara& Objects2) const;

  // Compute the mapping between the distorted image and the rectified image based upon the points of a regular grid.
  HImage GenGridRectificationMap(const HImage& Image, HXLDExtPara* Meshes, Hlong GridSpacing, const HTuple& Rotation, const HTuple& Row, const HTuple& Column, const HString& MapType) const;

  // Compute the mapping between the distorted image and the rectified image based upon the points of a regular grid.
  HImage GenGridRectificationMap(const HImage& Image, HXLDExtPara* Meshes, Hlong GridSpacing, const HString& Rotation, const HTuple& Row, const HTuple& Column, const HString& MapType) const;

  // Compute the mapping between the distorted image and the rectified image based upon the points of a regular grid.
  HImage GenGridRectificationMap(const HImage& Image, HXLDExtPara* Meshes, Hlong GridSpacing, const char* Rotation, const HTuple& Row, const HTuple& Column, const char* MapType) const;

#ifdef _WIN32
  // Compute the mapping between the distorted image and the rectified image based upon the points of a regular grid.
  HImage GenGridRectificationMap(const HImage& Image, HXLDExtPara* Meshes, Hlong GridSpacing, const wchar_t* Rotation, const HTuple& Row, const HTuple& Column, const wchar_t* MapType) const;
#endif

  // Deserialize a serialized XLD object.
  void DeserializeXld(const HSerializedItem& SerializedItemHandle);

  // Serialize an XLD object.
  HSerializedItem SerializeXld() const;

  // Choose all contours or polygons containing a given point.
  HXLDExtPara SelectXldPoint(const HTuple& Row, const HTuple& Column) const;

  // Choose all contours or polygons containing a given point.
  HXLDExtPara SelectXldPoint(double Row, double Column) const;

  // Select contours or polygons using shape features.
  HXLDExtPara SelectShapeXld(const HTuple& Features, const HString& Operation, const HTuple& Min, const HTuple& Max) const;

  // Select contours or polygons using shape features.
  HXLDExtPara SelectShapeXld(const HString& Features, const HString& Operation, double Min, double Max) const;

  // Select contours or polygons using shape features.
  HXLDExtPara SelectShapeXld(const char* Features, const char* Operation, double Min, double Max) const;

#ifdef _WIN32
  // Select contours or polygons using shape features.
  HXLDExtPara SelectShapeXld(const wchar_t* Features, const wchar_t* Operation, double Min, double Max) const;
#endif

  // Transform the shape of contours or polygons.
  HXLDExtPara ShapeTransXld(const HString& Type) const;

  // Transform the shape of contours or polygons.
  HXLDExtPara ShapeTransXld(const char* Type) const;

#ifdef _WIN32
  // Transform the shape of contours or polygons.
  HXLDExtPara ShapeTransXld(const wchar_t* Type) const;
#endif

  // Insert objects into an iconic object tuple.
  HXLDExtPara InsertObj(const HXLDExtPara& ObjectsInsert, Hlong Index) const;

  // Remove objects from an iconic object tuple.
  HXLDExtPara RemoveObj(const HTuple& Index) const;

  // Remove objects from an iconic object tuple.
  HXLDExtPara RemoveObj(Hlong Index) const;

  // Replaces one or more elements of an iconic object tuple.
  HXLDExtPara ReplaceObj(const HXLDExtPara& ObjectsReplace, const HTuple& Index) const;

  // Replaces one or more elements of an iconic object tuple.
  HXLDExtPara ReplaceObj(const HXLDExtPara& ObjectsReplace, Hlong Index) const;

private:

  // Verify matching semantic type ('xld_ext_para')!
  void AssertObjectClass();

};

}

#endif
