/**
     \file       DiskInit.h

    \brief   Disk Initialization Package ('PACK' 2) Interfaces.

    \introduced_in  System 8.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup AppleDisk

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __DISKINIT__
#define __DISKINIT__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#if PRAGMA_IMPORT
#pragma import on
#endif

#if PRAGMA_STRUCT_ALIGN
#pragma options align = mac68k
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
#pragma pack(2)
#endif

  struct HFSDefaults
  {
    char sigWord[2]; /** signature word */
    long abSize;     /** allocation block size in bytes */
    long clpSize;    /** clump size in bytes */
    long nxFreeFN;   /** next free file number */
    long btClpSize;  /** B-Tree clump size in bytes */
    short rsrv1;     /** reserved */
    short rsrv2;     /** reserved */
    short rsrv3;     /** reserved */
  };
  typedef struct HFSDefaults HFSDefaults;
  enum
  {
    kHFSPlusDefaultsVersion = 1
  };

  struct HFSPlusDefaults
  {
    UInt16 version;             /** version of this structure */
    UInt16 flags;               /** currently undefined; pass zero */
    UInt32 blockSize;           /** allocation block size in bytes */
    UInt32 rsrcClumpSize;       /** clump size for resource forks */
    UInt32 dataClumpSize;       /** clump size for data forks */
    UInt32 nextFreeFileID;      /** next free file number */
    UInt32 catalogClumpSize;    /** clump size for catalog B-tree */
    UInt32 catalogNodeSize;     /** node size for catalog B-tree */
    UInt32 extentsClumpSize;    /** clump size for extents B-tree */
    UInt32 extentsNodeSize;     /** node size for extents B-tree */
    UInt32 attributesClumpSize; /** clump size for attributes B-tree */
    UInt32 attributesNodeSize;  /** node size for attributes B-tree */
    UInt32 allocationClumpSize; /** clump size for allocation bitmap file */
  };
  typedef struct HFSPlusDefaults HFSPlusDefaults;
#if CALL_NOT_IN_CARBON
  /**
   *  DILoad()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DILoad(void);

  /**
   *  DIUnload()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DIUnload(void);

  /**
   *  DIBadMount()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  short
  DIBadMount(Point where, UInt32 evtMessage);

  /**
   *  DIFormat()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DIFormat(short drvNum);

  /**
   *  DIVerify()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DIVerify(short drvNum);

  /**
   *  DIZero()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DIZero(short drvNum, ConstStr255Param volName);

  /**
      DIXFormat, DIXZero, and DIReformat are only available when FSM (File System
     Manager) is installed. FSM is part of Macintosh PC Exchange and System 7.5.
  */
  /**
   *  DIXFormat()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DIXFormat(short drvNum, Boolean fmtFlag, unsigned long fmtArg,
            unsigned long *actSize);

  /**
   *  DIXZero()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DIXZero(short drvNum, ConstStr255Param volName, short fsid, short mediaStatus,
          short volTypeSelector, unsigned long volSize, void *extendedInfoPtr);

  /**
   *  DIReformat()
   *

   *    \non_carbon_cfm   in InterfaceLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  DIReformat(short drvNum, short fsid, ConstStr255Param volName,
             ConstStr255Param msgText);

#endif /** CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
  /**
   *  dibadmount()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  dibadmount(Point *where, long evtMessage);

  /**
   *  dizero()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  dizero(short drvnum, const char *volName);

#endif /** CALL_NOT_IN_CARBON */

#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack()
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif

#ifdef __cplusplus
}
#endif

#endif /** __DISKINIT__ */
