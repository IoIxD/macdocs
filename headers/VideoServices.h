/**
     \file       VideoServices.h

    \brief   Video Services Library Interfaces.

    \introduced_in  PowerSurge 1.0.2
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1994-2001 by Apple Computer, Inc., all rights reserved

    \ingroup System

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __VIDEOSERVICES__
#define __VIDEOSERVICES__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __NAMEREGISTRY__
#include <NameRegistry.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
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

  enum
  {
    kTransparentEncoding = 0,
    kInvertingEncoding = 1
  };

  enum
  {
    kTransparentEncodingShift = (kTransparentEncoding << 1),
    kTransparentEncodedPixel = (0x01 << kTransparentEncodingShift),
    kInvertingEncodingShift = (kInvertingEncoding << 1),
    kInvertingEncodedPixel = (0x01 << kInvertingEncodingShift)
  };

  enum
  {
    kHardwareCursorDescriptorMajorVersion = 0x0001,
    kHardwareCursorDescriptorMinorVersion = 0x0000
  };

  typedef UInt32 *UInt32Ptr;
  struct HardwareCursorDescriptorRec
  {
    UInt16 majorVersion;
    UInt16 minorVersion;
    UInt32 height;
    UInt32 width;
    UInt32 bitDepth;
    UInt32 maskBitDepth;
    UInt32 numColors;
    UInt32Ptr colorEncodings;
    UInt32 flags;
    UInt32 supportedSpecialEncodings;
    UInt32 specialEncodings[16];
  };
  typedef struct HardwareCursorDescriptorRec HardwareCursorDescriptorRec;
  typedef HardwareCursorDescriptorRec *HardwareCursorDescriptorPtr;
  enum
  {
    kHardwareCursorInfoMajorVersion = 0x0001,
    kHardwareCursorInfoMinorVersion = 0x0000
  };

  struct HardwareCursorInfoRec
  {
    UInt16 majorVersion; /* Test tool should check for
                            kHardwareCursorInfoMajorVersion1*/
    UInt16 minorVersion; /* Test tool should check for
                            kHardwareCursorInfoMinorVersion1*/
    UInt32 cursorHeight;
    UInt32 cursorWidth;
    CTabPtr colorMap;   // nil or big enough for hardware's max colors  Ptr hardwareCursor;
    UInt32 reserved[6]; // Test tool should check for 0s
  };
  typedef struct Hardwar // Test tool should check for 0s
      typedef HardwareCursorInfoRec *HardwareCursorInfoPtr;

  enum
  {
    kVBLInterruptServiceType = FOUR_CHAR_CODE('vbl '),
    kHBLInterruptServiceType = FOUR_CHAR_CODE('hbl '),
    kFrameInterruptServiceType = FOUR_CHAR_CODE('fram'),
    kConnectInterruptServiceType =
        FOUR_CHAR_CODE('dci '),   // Renamed -- Use kFBCheckInterruptServiceType  kFBConnectInterruptServiceType =
    kConnectInterruptServiceType, /* Demand to check configuration (Hardware
                            // Renamed -- Use kFBCheckInterruptServiceType
kFBChangedInterruptServiceType =
    FOUR_CHAR_CODE('chng'), /* Demand to rebuild (Hardware has reinitialized
                               on dependent change)*/
    kFBOfflineInterruptServiceType = FOUR_CHAR_CODE(
        'remv'), /* Demand to remove framebuffer (Hardware not available on
                    dependent change -- but must not buserror)*/
    kFBOnlineInterruptServiceType = FOUR_CHAR_CODE(
        'add ') // Notice that hardware is available (after being removed)
  };

  enum
  {
    kMaxDisplayC // Notice that hardware is available (after being removed)
    64           // Max data size for VSLSetDisplayConfiguration
  };

  typedef ResType InterruptServiceType;
  typedef UInt32 InterruptServiceIDType;
  typedef I // Max data size for VSLSetDisplayConfiguration
#if CALL_NOT_IN_CARBON
      /**
       *  VSLNewInterruptService()
       *

       *    \non_carbon_cfm   in VideoServicesLib 1.0 and later
       *    \carbon_lib        not available
       *    \mac_os_x         not available
       */
      OSErr
      VSLNewInterruptService(RegEntryID *serviceDevice,
                             InterruptServiceType serviceType,
                             InterruptServiceIDPtr serviceID);

  /**
   *  VSLWaitOnInterruptService()
   *

   *    \non_carbon_cfm   in VideoServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  VSLWaitOnInterruptService(InterruptServiceIDType serviceID, Duration timeout);

  /**
   *  VSLDisposeInterruptService()
   *

   *    \non_carbon_cfm   in VideoServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  VSLDisposeInterruptService(InterruptServiceIDType serviceID);

  /**
   *  VSLDoInterruptService()
   *

   *    \non_carbon_cfm   in VideoServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  VSLDoInterruptService(InterruptServiceIDType serviceID);

  /**
   *  VSLPrepareCursorForHardwareCursor()
   *

   *    \non_carbon_cfm   in VideoServicesLib 1.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  Boolean
  VSLPrepareCursorForHardwareCursor(
      void *cursorRef, HardwareCursorDescriptorPtr hardwareDescriptor,
      HardwareCursorInfoPtr hwCursorInfo);

  /**
   *  VSLSetDisplayConfiguration()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  VSLSetDisplayConfiguration(RegEntryID *device, RegPropertyName *propertyName,
                             void *configData, long configDataSize);

#endif // CALL_NOT_IN_CARBON
#if PRAGMA_STRUCT_ALIGN
#pragma options align = reset
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif P // CALL_NOT_IN_CARBON
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

#endif // __VIDEOSERVICES__ // __VIDEOSERVICES__
