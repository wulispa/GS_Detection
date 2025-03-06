/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 23.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HENCRYPTEDITEM
#define HCPP_HENCRYPTEDITEM

namespace HalconCpp
{

// Represents an instance of an encrypted item.
class LIntExport HEncryptedItem : public HHandle
{

public:

  // Create an uninitialized instance
  HEncryptedItem():HHandle() {}

  // Copy constructor
  HEncryptedItem(const HEncryptedItem& source) : HHandle(source) {}

#if __cplusplus >= 201103
  // C++11 deprecates declaration of an implicit default assignment operator if
  // the class has a custom copy constructor.
  HEncryptedItem& operator=(const HEncryptedItem&) = default;
#endif

  // Copy constructor
  HEncryptedItem(const HHandle& handle);

  // Create HEncryptedItem from handle, taking ownership
  explicit HEncryptedItem(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('encrypted_item')!
  virtual void AssertType(Hphandle handle) const;

public:



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // read_encrypted_item: Read an encrypted item from a file.
  explicit HEncryptedItem(const HString& FileName);

  // read_encrypted_item: Read an encrypted item from a file.
  explicit HEncryptedItem(const char* FileName);

#ifdef _WIN32
  // read_encrypted_item: Read an encrypted item from a file.
  explicit HEncryptedItem(const wchar_t* FileName);
#endif




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Read an encrypted item from a file.
  void ReadEncryptedItem(const HString& FileName);

  // Read an encrypted item from a file.
  void ReadEncryptedItem(const char* FileName);

#ifdef _WIN32
  // Read an encrypted item from a file.
  void ReadEncryptedItem(const wchar_t* FileName);
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HEncryptedItem> HEncryptedItemArrayRef;
typedef HSmartPtr< HEncryptedItemArrayRef > HEncryptedItemArrayPtr;


// Represents multiple tool instances
class LIntExport HEncryptedItemArray : public HHandleBaseArray
{

public:

  // Create empty array
  HEncryptedItemArray();

  // Create array from native array of tool instances
  HEncryptedItemArray(const HEncryptedItem* classes, Hlong length);

  // Copy constructor
  HEncryptedItemArray(const HEncryptedItemArray &tool_array);

  // Destructor
  virtual ~HEncryptedItemArray();

  // Assignment operator
  HEncryptedItemArray &operator=(const HEncryptedItemArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HEncryptedItem* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HEncryptedItemArrayPtr *mArrayPtr;
};

}

#endif
