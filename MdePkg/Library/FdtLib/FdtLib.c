/** @file
  Flattened Device Tree Library.

  Copyright (c) 2023, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <libfdt/libfdt/libfdt.h>

/**
  Create a empty Flattened Device Tree.

  @param[in] Buffer         The pointer to allocate a pool for FDT blob.
  @param[in] BufferSize     The BufferSize to the pool size.

  @return Zero for successfully, otherwise failed.

**/
INTN
EFIAPI
FdtCreateEmptyTree(
  IN VOID   *Buffer,
  IN UINTN  BufferSize
  )
{
  INTN  ReturnStatus;

  ReturnStatus = fdt_create_empty_tree(Buffer, (INTN)BufferSize);

  return ReturnStatus;
}

/**
  Returns a offset of next node from the given node.

  @param[in] Fdt            The pointer to FDT blob.
  @param[in] Offset         The offset to previous node.
  @param[in] Depth          The depth to the level of tree hierarchy.

  @return The offset to next node offset.

**/
INT32
EFIAPI
FdtNextNode (
  IN CONST VOID  *Fdt,
  IN INT32       Offset,
  IN INT32       *Depth
  )
{
  INT32  FdtOffset;

  FdtOffset = fdt_next_node(Fdt, Offset, Depth);

  return FdtOffset;
}

/**
  Returns a offset of first node under the given node.

  @param[in] Fdt            The pointer to FDT blob.
  @param[in] Offset         The offset to previous node.

  @return The offset to next node offset.

**/
INT32
EFIAPI
FdtFirstSubnode(
  IN CONST VOID  *Fdt,
  IN INT32       Offset
  )
{
  INT32  FdtOffset;

  FdtOffset = fdt_first_subnode(Fdt, Offset);

  return FdtOffset;
}

/**
  Returns a offset of next node from the given node.

  @param[in] Fdt            The pointer to FDT blob.
  @param[in] Offset         The offset to previous node.

  @return The offset to next node offset.

**/
INT32
EFIAPI
FdtNextSubnode(
  IN CONST VOID  *Fdt,
  IN INT32       Offset
  )
{
  INT32  FdtOffset;

  FdtOffset = fdt_next_subnode(Fdt, Offset);

  return FdtOffset;
}

/**
  Returns a offset of first node which includes the given name.

  @param[in] Fdt             The pointer to FDT blob.
  @param[in] ParentOffset    The offset to the node which start find under.
  @param[in] Name            The name to search the node with the name.
  @param[in] NameLength      The length of the name to check only.

  @return The offset to node offset with given node name.

**/
INT32
EFIAPI
FdtSubnodeOffsetNameLen (
  IN CONST VOID   *Fdt,
  IN INT32        ParentOffset,
  IN CONST CHAR8  *Name,
  IN INT32        NameLength
  )
{
  INT32  FdtOffset;

  FdtOffset = fdt_subnode_offset_namelen(Fdt, ParentOffset, Name, NameLength);

  return FdtOffset;
}

/**
  Returns a offset of first node which includes the given property name and value.

  @param[in] Fdt             The pointer to FDT blob.
  @param[in] StartOffset     The offset to the starting node to find.
  @param[in] PropertyName    The property name to search the node including the named property.
  @param[in] PropertyValue   The property value to check the same property value.
  @param[in] PropertyLength  The length of the value in PropertValue.

  @return The offset to node offset with given property.

**/
INT32
EFIAPI
FdtNodeOffsetByPropValue(
  IN CONST VOID   *Fdt,
  IN INT32        StartOffset,
  IN CONST CHAR8  *PropertyName,
  IN CONST VOID   *PropertyValue,
  IN INT32        PropertyLength
  )
{
  INT32  FdtOffset;

  FdtOffset = fdt_node_offset_by_prop_value(Fdt, StartOffset, PropertyName, PropertyValue, PropertyLength);

  return FdtOffset;
}

/**
  Returns a property with the given name from the given node.

  @param[in] Fdt            The pointer to FDT blob.
  @param[in] NodeOffset     The offset to the given node.
  @param[in] Name           The name to the property which need be searched
  @param[in] Length         The length to the size of the property found.

  @return The property to the structure of the found property.

**/
CONST struct fdt_property *
EFIAPI
FdtGetProperty (
  IN CONST VOID   *Fdt,
  IN INT32        NodeOffset,
  IN CONST CHAR8  *Name,
  IN INT32        *Length
  )
{
  CONST struct fdt_property  *FdtProperty;

  FdtProperty = fdt_get_property(Fdt, NodeOffset, Name, Length);

  return FdtProperty;
}

/**
  Returns a offset of first property in the given node.

  @param[in] Fdt            The pointer to FDT blob.
  @param[in] Offset         The offset to the node which need be searched.

  @return The offset to first property offset in the given node.

**/
INT32
EFIAPI
FdtFirstPropertyOffset(
  IN CONST VOID  *Fdt,
  IN INT32       NodeOffset
  )
{
  INT32  FdtOffset;

  FdtOffset = fdt_first_property_offset(Fdt, NodeOffset);

  return FdtOffset;
}

/**
  Returns a offset of next property from the given property.

  @param[in] Fdt            The pointer to FDT blob.
  @param[in] Offset         The offset to previous property.

  @return The offset to next property offset.

**/
INT32
EFIAPI
FdtNextPropertyOffset(
  IN CONST VOID  *Fdt,
  IN INT32       Offset
  )
{
  INT32  FdtOffset;

  FdtOffset = fdt_next_property_offset(Fdt, Offset);

  return FdtOffset;
}

/**
  Returns a property from the given offset of the property.

  @param[in] Fdt            The pointer to FDT blob.
  @param[in] Offset         The offset to the given offset of the property.
  @param[in] Length         The length to the size of the property found.

  @return The property to the structure of the given property offset.

**/
CONST struct fdt_property *
EFIAPI
FdtGetPropertyByOffset(
  IN CONST VOID  *Fdt,
  IN INT32       Offset,
  IN INT32       *Length
  )
{
  CONST struct fdt_property  *FdtProperty;

  FdtProperty = fdt_get_property_by_offset(Fdt, Offset, Length);

  return FdtProperty;

}

/**
  Returns a string by the given string offset.

  @param[in] Fdt            The pointer to FDT blob.
  @param[in] StrOffset      The offset to the location in the strings block of FDT.
  @param[in] Length         The length to the size of string which need be retrieved.

  @return The string to the given string offset.

**/
CONST CHAR8 *
EFIAPI
FdtGetString (
  IN CONST VOID  *Fdt,
  IN INT32       StrOffset,
  IN INT32       *Length        OPTIONAL
  )
{
  CONST CHAR8  *FdtString;

  FdtString = fdt_get_string(Fdt, StrOffset, Length);

  return FdtString;
}

/**
  Add a new node to the FDT.

  @param[in] Fdt            The pointer to FDT blob.
  @param[in] ParentOffset   The offset to the node offset which want to add in.
  @param[in] Name           The name to name the node.

  @return  The offset to the new node.

**/
INT32
EFIAPI
FdtAddSubnode(
  IN VOID         *Fdt,
  IN INT32        ParentOffset,
  IN CONST CHAR8  *Name
  )
{
  INT32  FdtOffset;

  FdtOffset = fdt_add_subnode(Fdt, ParentOffset, Name);

  return FdtOffset;
}

/**
  Add or modify a porperty in the given node.

  @param[in] Fdt            The pointer to FDT blob.
  @param[in] NodeOffset     The offset to the node offset which want to add in.
  @param[in] Name           The name to name the property.
  @param[in] Value          The value to the property value.
  @param[in] Length         The length to the size of the property.

  @return  Zero for successfully, otherwise failed.

**/
INT32
EFIAPI
FdtSetProp(
  IN VOID         *Fdt,
  IN INT32        NodeOffset,
  IN CONST CHAR8  *Name,
  IN CONST VOID   *Value,
  IN UINT32       Length
  )
{
  INT32  ReturnStatus;

  ReturnStatus = fdt_setprop(Fdt, NodeOffset, Name, Value, (INTN)Length);

  return ReturnStatus;
}