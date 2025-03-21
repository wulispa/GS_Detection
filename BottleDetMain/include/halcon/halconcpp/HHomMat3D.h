/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HHOMMAT3D
#define HCPP_HHOMMAT3D

namespace HalconCpp
{

// Represents a homogeneous 3D transformation matrix.
class LIntExport HHomMat3D : public HDataBase
{

public:

  // Copy constructor
  HHomMat3D(const HHomMat3D& source) : HDataBase(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HHomMat3D& operator=(const HHomMat3D&) = default;
#endif

  // Constructor from HTuple
  explicit HHomMat3D(const HTuple& tuple) : HDataBase(tuple) {}

  // Deep copy of all data represented by this object instance
  HHomMat3D Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // hom_mat3d_identity: Generate the homogeneous transformation matrix of the identical 3D transformation.
  explicit HHomMat3D();




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Deserialize a serialized homogeneous 3D transformation matrix.
  void DeserializeHomMat3d(const HSerializedItem& SerializedItemHandle);

  // Serialize a homogeneous 3D transformation matrix.
  HSerializedItem SerializeHomMat3d() const;

  // Project a homogeneous 3D point using a projective transformation matrix.
  HTuple ProjectiveTransHomPoint3d(const HTuple& Px, const HTuple& Py, const HTuple& Pz, const HTuple& Pw, HTuple* Qy, HTuple* Qz, HTuple* Qw) const;

  // Project a homogeneous 3D point using a projective transformation matrix.
  double ProjectiveTransHomPoint3d(double Px, double Py, double Pz, double Pw, double* Qy, double* Qz, double* Qw) const;

  // Project a 3D point using a projective transformation matrix.
  HTuple ProjectiveTransPoint3d(const HTuple& Px, const HTuple& Py, const HTuple& Pz, HTuple* Qy, HTuple* Qz) const;

  // Project a 3D point using a projective transformation matrix.
  double ProjectiveTransPoint3d(double Px, double Py, double Pz, double* Qy, double* Qz) const;

  // Apply an arbitrary affine 3D transformation to points.
  HTuple AffineTransPoint3d(const HTuple& Px, const HTuple& Py, const HTuple& Pz, HTuple* Qy, HTuple* Qz) const;

  // Apply an arbitrary affine 3D transformation to points.
  double AffineTransPoint3d(double Px, double Py, double Pz, double* Qy, double* Qz) const;

  // Approximate a 3D transformation from point correspondences.
  void VectorToHomMat3d(const HString& TransformationType, const HTuple& Px, const HTuple& Py, const HTuple& Pz, const HTuple& Qx, const HTuple& Qy, const HTuple& Qz);

  // Approximate a 3D transformation from point correspondences.
  void VectorToHomMat3d(const char* TransformationType, const HTuple& Px, const HTuple& Py, const HTuple& Pz, const HTuple& Qx, const HTuple& Qy, const HTuple& Qz);

#ifdef _WIN32
  // Approximate a 3D transformation from point correspondences.
  void VectorToHomMat3d(const wchar_t* TransformationType, const HTuple& Px, const HTuple& Py, const HTuple& Pz, const HTuple& Qx, const HTuple& Qy, const HTuple& Qz);
#endif

  // Compute the determinant of a homogeneous 3D transformation matrix.
  double HomMat3dDeterminant() const;

  // Transpose a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dTranspose() const;

  // Invert a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dInvert() const;

  // Multiply two homogeneous 3D transformation matrices.
  HHomMat3D HomMat3dCompose(const HHomMat3D& HomMat3DRight) const;

  // Add a rotation to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dRotateLocal(const HTuple& Phi, const HTuple& Axis) const;

  // Add a rotation to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dRotateLocal(double Phi, const HString& Axis) const;

  // Add a rotation to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dRotateLocal(double Phi, const char* Axis) const;

#ifdef _WIN32
  // Add a rotation to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dRotateLocal(double Phi, const wchar_t* Axis) const;
#endif

  // Add a rotation to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dRotate(const HTuple& Phi, const HTuple& Axis, const HTuple& Px, const HTuple& Py, const HTuple& Pz) const;

  // Add a rotation to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dRotate(double Phi, const HString& Axis, double Px, double Py, double Pz) const;

  // Add a rotation to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dRotate(double Phi, const char* Axis, double Px, double Py, double Pz) const;

#ifdef _WIN32
  // Add a rotation to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dRotate(double Phi, const wchar_t* Axis, double Px, double Py, double Pz) const;
#endif

  // Add a scaling to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dScaleLocal(const HTuple& Sx, const HTuple& Sy, const HTuple& Sz) const;

  // Add a scaling to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dScaleLocal(double Sx, double Sy, double Sz) const;

  // Add a scaling to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dScale(const HTuple& Sx, const HTuple& Sy, const HTuple& Sz, const HTuple& Px, const HTuple& Py, const HTuple& Pz) const;

  // Add a scaling to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dScale(double Sx, double Sy, double Sz, double Px, double Py, double Pz) const;

  // Add a translation to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dTranslateLocal(const HTuple& Tx, const HTuple& Ty, const HTuple& Tz) const;

  // Add a translation to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dTranslateLocal(double Tx, double Ty, double Tz) const;

  // Add a translation to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dTranslate(const HTuple& Tx, const HTuple& Ty, const HTuple& Tz) const;

  // Add a translation to a homogeneous 3D transformation matrix.
  HHomMat3D HomMat3dTranslate(double Tx, double Ty, double Tz) const;

  // Generate the homogeneous transformation matrix of the identical 3D transformation.
  void HomMat3dIdentity();

  // Project an affine 3D transformation matrix to a 2D projective transformation matrix.
  HHomMat2D HomMat3dProject(const HTuple& PrincipalPointRow, const HTuple& PrincipalPointCol, const HTuple& Focus) const;

  // Project an affine 3D transformation matrix to a 2D projective transformation matrix.
  HHomMat2D HomMat3dProject(double PrincipalPointRow, double PrincipalPointCol, double Focus) const;

  // Project a homogeneous 3D point using a 3x4 projection matrix.
  HTuple ProjectHomPointHomMat3d(const HTuple& Px, const HTuple& Py, const HTuple& Pz, const HTuple& Pw, HTuple* Qy, HTuple* Qw) const;

  // Project a homogeneous 3D point using a 3x4 projection matrix.
  double ProjectHomPointHomMat3d(double Px, double Py, double Pz, double Pw, double* Qy, double* Qw) const;

  // Project a 3D point using a 3x4 projection matrix.
  HTuple ProjectPointHomMat3d(const HTuple& Px, const HTuple& Py, const HTuple& Pz, HTuple* Qy) const;

  // Project a 3D point using a 3x4 projection matrix.
  double ProjectPointHomMat3d(double Px, double Py, double Pz, double* Qy) const;

  // Convert a homogeneous transformation matrix into a 3D pose.
  HPose HomMat3dToPose() const;

  // Approximate a 3D affine transformation from 3D point-to-line correspondences.
  void PointPlueckerLineToHomMat3d(const HString& TransformationType, const HTuple& PointX, const HTuple& PointY, const HTuple& PointZ, const HTuple& LineDirectionX, const HTuple& LineDirectionY, const HTuple& LineDirectionZ, const HTuple& LineMomentX, const HTuple& LineMomentY, const HTuple& LineMomentZ);

  // Approximate a 3D affine transformation from 3D point-to-line correspondences.
  void PointPlueckerLineToHomMat3d(const char* TransformationType, const HTuple& PointX, const HTuple& PointY, const HTuple& PointZ, const HTuple& LineDirectionX, const HTuple& LineDirectionY, const HTuple& LineDirectionZ, const HTuple& LineMomentX, const HTuple& LineMomentY, const HTuple& LineMomentZ);

#ifdef _WIN32
  // Approximate a 3D affine transformation from 3D point-to-line correspondences.
  void PointPlueckerLineToHomMat3d(const wchar_t* TransformationType, const HTuple& PointX, const HTuple& PointY, const HTuple& PointZ, const HTuple& LineDirectionX, const HTuple& LineDirectionY, const HTuple& LineDirectionZ, const HTuple& LineMomentX, const HTuple& LineMomentY, const HTuple& LineMomentZ);
#endif

};

class LIntExport HHomMat3DArray : public HDataArray
{
public:
  HHomMat3DArray();
  HHomMat3DArray(HHomMat3D* classes, Hlong length);
  /* Define a default constructor to prevent compilers that support
   * C++11 R-Value References v3.0 declaring an implicite move
   * assignment/constructor. */
  ~HHomMat3DArray() {}
protected:
  virtual void CreateArray(Hlong length);
  virtual int GetFixedSize() const;
};

}

#endif
