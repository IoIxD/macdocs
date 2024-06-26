/**
     \file       Quickdraw.h

    \brief   Interface to Quickdraw Graphics

     Version:    Universal Interfaces 3.4.1

    \copyright � 1985-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Quickdraw

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QUICKDRAW__
#define __QUICKDRAW__

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __QUICKDRAWTEXT__
#include <QuickdrawText.h>
#endif

#ifndef __CGCONTEXT__
#include <CGContext.h>
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
    invalColReq = -1 /*invalid color table request*/
  };

  enum
  {
    /* transfer modes */
    srcCopy = 0, /*the 16 transfer modes*/
    srcOr = 1,
    srcXor = 2,
    srcBic = 3,
    notSrcCopy = 4,
    notSrcOr = 5,
    notSrcXor = 6,
    notSrcBic = 7,
    patCopy = 8,
    patOr = 9,
    patXor = 10,
    patBic = 11,
    notPatCopy = 12,
    notPatOr = 13,
    notPatXor = 14,
    notPatBic = 15, /* Special Text Transfer Mode */
    grayishTextOr = 49,
    hilitetransfermode = 50,
    hilite = 50, /* Arithmetic transfer modes */
    blend = 32,
    addPin = 33,
    addOver = 34,
    subPin = 35,
    addMax = 37,
    adMax = 37,
    subOver = 38,
    adMin = 39,
    ditherCopy = 64, /* Transparent mode constant */
    transparent = 36
  };

  enum
  {
    italicBit = 1,
    ulineBit = 2,
    outlineBit = 3,
    shadowBit = 4,
    condenseBit = 5,
    extendBit = 6
  };

  enum
  {
    /* QuickDraw color separation constants */
    normalBit = 0,  /*normal screen mapping*/
    inverseBit = 1, /*inverse screen mapping*/
    redBit = 4,     /*RGB additive mapping*/
    greenBit = 3,
    blueBit = 2,
    cyanBit = 8, /*CMYBk subtractive mapping*/
    magentaBit = 7,
    yellowBit = 6,
    blackBit = 5
  };

  enum
  {
    blackColor = 33, /*colors expressed in these mappings*/
    whiteColor = 30,
    redColor = 205,
    greenColor = 341,
    blueColor = 409,
    cyanColor = 273,
    magentaColor = 137,
    yellowColor = 69
  };

  enum
  {
    picLParen = 0, /*standard picture comments*/
    picRParen = 1,
    clutType = 0,   /*0 if lookup table*/
    fixedType = 1,  /*1 if fixed table*/
    directType = 2, /*2 if direct values*/
    gdDevType = 0   /*0 = monochrome 1 = color*/
  };

  enum
  {
    interlacedDevice = 2, /* 1 if single pixel lines look bad */
    hwMirroredDevice = 4, /* 1 if device is HW mirrored */
    roundedDevice = 5,    /* 1 if device has been �rounded� into the GrayRgn */
    hasAuxMenuBar = 6,    /* 1 if device has an aux menu bar on it */
    burstDevice = 7,
    ext32Device = 8,
    ramInit = 10,      /*1 if initialized from 'scrn' resource*/
    mainScreen = 11,   /* 1 if main screen */
    allInit = 12,      /* 1 if all devices initialized */
    screenDevice = 13, /*1 if screen device [not used]*/
    noDriver = 14,     /* 1 if no driver for this GDevice */
    screenActive = 15, /*1 if in use*/
    hiliteBit = 7,     /*flag bit in LMGet/SetHiliteMode*/
    pHiliteBit = 0,    /*flag bit in LMGet/SetHiliteMode when used with BitClr*/
    defQDColors = 127, /*resource ID of clut for default QDColors*/
                       /* pixel type */
    RGBDirect = 16,    /* 16 & 32 bits/pixel pixelType value */
                       /* pmVersion values */
    baseAddr32 = 4     /*pixmap base address is 32-bit address*/
  };

  enum
  {
    sysPatListID = 0,
    iBeamCursor = 1,
    crossCursor = 2,
    plusCursor = 3,
    watchCursor = 4
  };

  enum
  {
    kQDGrafVerbFrame = 0,
    kQDGrafVerbPaint = 1,
    kQDGrafVerbErase = 2,
    kQDGrafVerbInvert = 3,
    kQDGrafVerbFill = 4
  };

#if OLDROUTINENAMES
  enum
  {
    frame = kQDGrafVerbFrame,
    paint = kQDGrafVerbPaint,
    erase = kQDGrafVerbErase,
    invert = kQDGrafVerbInvert,
    fill = kQDGrafVerbFill
  };

#endif /* OLDROUTINENAMES */

  typedef SInt8 GrafVerb;
  enum
  {
    chunky = 0,
    chunkyPlanar = 1,
    planar = 2
  };

  typedef SInt8 PixelType;
  typedef short Bits16[16];

  /***************   IMPORTANT NOTE REGARDING Pattern
  ************************************** Patterns were originally defined as:

          C:          typedef unsigned char Pattern[8];
          Pascal:     Pattern = PACKED ARRAY [0..7] OF 0..255;

     The old array definition of Pattern would cause 68000 based CPU's to crash in
  certain circum- stances. The new struct definition is safe, but may require
  source code changes to compile.

  *********************************************************************************************/
  struct Pattern
  {
    UInt8 pat[8];
  };
  typedef struct Pattern Pattern;
  /**
   ConstPatternParam is no longer needed.  It was first created when Pattern was
   an array. Now that Pattern is a struct, it is more straight forward to just add
   the "const" qualifier on the parameter type (e.g. "const Pattern * pat" instead
   of "ConstPatternParam pat").
  */
  typedef const Pattern *ConstPatternParam;
  typedef Pattern *PatPtr;
  typedef PatPtr *PatHandle;
  typedef SignedByte QDByte;
  typedef QDByte *QDPtr;
  typedef QDPtr *QDHandle;
  typedef short QDErr;
  enum
  {
    singleDevicesBit = 0,
    dontMatchSeedsBit = 1,
    allDevicesBit = 2
  };

  enum
  {
    singleDevices = 1 << singleDevicesBit,
    dontMatchSeeds = 1 << dontMatchSeedsBit,
    allDevices = 1 << allDevicesBit
  };

  typedef unsigned long DeviceLoopFlags;
  /**
      PrinterStatusOpcode.  For communication with downloading and printing
     services.
  */
  typedef SInt32 PrinterStatusOpcode;
  enum
  {
    kPrinterFontStatus = 0,
    kPrinterScalingStatus = 1
  };

  struct PrinterFontStatus
  {
    SInt32 oResult;
    SInt16 iFondID;
    Style iStyle;
  };
  typedef struct PrinterFontStatus PrinterFontStatus;
  struct PrinterScalingStatus
  {
    Point oScalingFactors;
  };
  typedef struct PrinterScalingStatus PrinterScalingStatus;
  struct BitMap
  {
    Ptr baseAddr;
    short rowBytes;
    Rect bounds;
  };
  typedef struct BitMap BitMap;
  typedef BitMap *BitMapPtr;
  typedef BitMapPtr *BitMapHandle;
  struct Cursor
  {
    Bits16 data;
    Bits16 mask;
    Point hotSpot;
  };
  typedef struct Cursor Cursor;
  typedef Cursor *CursPtr;
  typedef CursPtr *CursHandle;
  struct PenState
  {
    Point pnLoc;
    Point pnSize;
    short pnMode;
    Pattern pnPat;
  };
  typedef struct PenState PenState;
#if !OPAQUE_TOOLBOX_STRUCTS
  struct MacRegion
  {
    unsigned short rgnSize; /* size in bytes; don't rely on it */
    Rect rgnBBox;           /* enclosing rectangle; in Carbon use GetRegionBounds */
  };
  typedef struct MacRegion MacRegion;
/**
   The type name "Region" has a name space collision on Win32.
   Use MacRegion to be cross-platfrom safe.
*/
#if TARGET_OS_MAC
  typedef MacRegion Region;
#endif /* TARGET_OS_MAC */

  typedef MacRegion *RgnPtr;
  typedef RgnPtr *RgnHandle;
#else
typedef struct OpaqueRgnHandle *RgnHandle;
#endif /* !OPAQUE_TOOLBOX_STRUCTS */

  struct Picture
  {
    short picSize;
    Rect picFrame;
  };
  typedef struct Picture Picture;
  typedef Picture *PicPtr;
  typedef PicPtr *PicHandle;
  struct MacPolygon
  {
    short polySize;
    Rect polyBBox;
    Point polyPoints[1];
  };
  typedef struct MacPolygon MacPolygon;
/**
   The type name "Polygon" has a name space collision on Win32.
   Use MacPolygon to be cross-platfrom safe.
*/
#if TARGET_OS_MAC
  typedef MacPolygon Polygon;
#endif /* TARGET_OS_MAC */

  typedef MacPolygon *PolyPtr;
  typedef PolyPtr *PolyHandle;
  typedef CALLBACK_API(void, QDTextProcPtr)(short byteCount, const void *textBuf,
                                            Point numer, Point denom);
  typedef CALLBACK_API(void, QDLineProcPtr)(Point newPt);
  typedef CALLBACK_API(void, QDRectProcPtr)(GrafVerb verb, const Rect *r);
  typedef CALLBACK_API(void, QDRRectProcPtr)(GrafVerb verb, const Rect *r,
                                             short ovalWidth, short ovalHeight);
  typedef CALLBACK_API(void, QDOvalProcPtr)(GrafVerb verb, const Rect *r);
  typedef CALLBACK_API(void, QDArcProcPtr)(GrafVerb verb, const Rect *r,
                                           short startAngle, short arcAngle);
  typedef CALLBACK_API(void, QDPolyProcPtr)(GrafVerb verb, PolyHandle poly);
  typedef CALLBACK_API(void, QDRgnProcPtr)(GrafVerb verb, RgnHandle rgn);
  typedef CALLBACK_API(void, QDBitsProcPtr)(const BitMap *srcBits,
                                            const Rect *srcRect,
                                            const Rect *dstRect, short mode,
                                            RgnHandle maskRgn);
  typedef CALLBACK_API(void, QDCommentProcPtr)(short kind, short dataSize,
                                               Handle dataHandle);
  typedef CALLBACK_API(short, QDTxMeasProcPtr)(short byteCount,
                                               const void *textAddr, Point *numer,
                                               Point *denom, FontInfo *info);
  typedef CALLBACK_API(void, QDGetPicProcPtr)(void *dataPtr, short byteCount);
  typedef CALLBACK_API(void, QDPutPicProcPtr)(const void *dataPtr,
                                              short byteCount);
  typedef CALLBACK_API(void, QDOpcodeProcPtr)(const Rect *fromRect,
                                              const Rect *toRect, UInt16 opcode,
                                              SInt16 version);
  typedef CALLBACK_API_C(OSStatus, QDStdGlyphsProcPtr)(void *dataStream,
                                                       ByteCount size);
  typedef CALLBACK_API(void, QDJShieldCursorProcPtr)(short left, short top,
                                                     short right, short bottom);
  typedef STACK_UPP_TYPE(QDTextProcPtr) QDTextUPP;
  typedef STACK_UPP_TYPE(QDLineProcPtr) QDLineUPP;
  typedef STACK_UPP_TYPE(QDRectProcPtr) QDRectUPP;
  typedef STACK_UPP_TYPE(QDRRectProcPtr) QDRRectUPP;
  typedef STACK_UPP_TYPE(QDOvalProcPtr) QDOvalUPP;
  typedef STACK_UPP_TYPE(QDArcProcPtr) QDArcUPP;
  typedef STACK_UPP_TYPE(QDPolyProcPtr) QDPolyUPP;
  typedef STACK_UPP_TYPE(QDRgnProcPtr) QDRgnUPP;
  typedef STACK_UPP_TYPE(QDBitsProcPtr) QDBitsUPP;
  typedef STACK_UPP_TYPE(QDCommentProcPtr) QDCommentUPP;
  typedef STACK_UPP_TYPE(QDTxMeasProcPtr) QDTxMeasUPP;
  typedef STACK_UPP_TYPE(QDGetPicProcPtr) QDGetPicUPP;
  typedef STACK_UPP_TYPE(QDPutPicProcPtr) QDPutPicUPP;
  typedef STACK_UPP_TYPE(QDOpcodeProcPtr) QDOpcodeUPP;
  typedef STACK_UPP_TYPE(QDStdGlyphsProcPtr) QDStdGlyphsUPP;
  typedef STACK_UPP_TYPE(QDJShieldCursorProcPtr) QDJShieldCursorUPP;
  struct QDProcs
  {
    QDTextUPP textProc;
    QDLineUPP lineProc;
    QDRectUPP rectProc;
    QDRRectUPP rRectProc;
    QDOvalUPP ovalProc;
    QDArcUPP arcProc;
    QDPolyUPP polyProc;
    QDRgnUPP rgnProc;
    QDBitsUPP bitsProc;
    QDCommentUPP commentProc;
    QDTxMeasUPP txMeasProc;
    QDGetPicUPP getPicProc;
    QDPutPicUPP putPicProc;
  };
  typedef struct QDProcs QDProcs;
  typedef QDProcs *QDProcsPtr;
  /**
   *  NewQDTextUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDTextUPP
  NewQDTextUPP(QDTextProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDTextProcInfo = 0x00003F80
  }; /* pascal no_return_value Func(2_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline QDTextUPP NewQDTextUPP(QDTextProcPtr userRoutine)
  {
    return (QDTextUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDTextProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDTextUPP(userRoutine)                                             \
  (QDTextUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppQDTextProcInfo, \
                                   GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDLineUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDLineUPP
  NewQDLineUPP(QDLineProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDLineProcInfo = 0x000000C0
  }; /* pascal no_return_value Func(4_bytes) */
#ifdef __cplusplus
  inline QDLineUPP NewQDLineUPP(QDLineProcPtr userRoutine)
  {
    return (QDLineUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDLineProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDLineUPP(userRoutine)                                             \
  (QDLineUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppQDLineProcInfo, \
                                   GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDRectUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDRectUPP
  NewQDRectUPP(QDRectProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDRectProcInfo = 0x00000340
  }; /* pascal no_return_value Func(1_byte, 4_bytes) */
#ifdef __cplusplus
  inline QDRectUPP NewQDRectUPP(QDRectProcPtr userRoutine)
  {
    return (QDRectUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDRectProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDRectUPP(userRoutine)                                             \
  (QDRectUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppQDRectProcInfo, \
                                   GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDRRectUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDRRectUPP
  NewQDRRectUPP(QDRRectProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDRRectProcInfo = 0x00002B40
  }; /* pascal no_return_value Func(1_byte, 4_bytes, 2_bytes, 2_bytes) */
#ifdef __cplusplus
  inline QDRRectUPP NewQDRRectUPP(QDRRectProcPtr userRoutine)
  {
    return (QDRRectUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDRRectProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDRRectUPP(userRoutine)   \
  (QDRRectUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppQDRRectProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDOvalUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDOvalUPP
  NewQDOvalUPP(QDOvalProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDOvalProcInfo = 0x00000340
  }; /* pascal no_return_value Func(1_byte, 4_bytes) */
#ifdef __cplusplus
  inline QDOvalUPP NewQDOvalUPP(QDOvalProcPtr userRoutine)
  {
    return (QDOvalUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDOvalProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDOvalUPP(userRoutine)                                             \
  (QDOvalUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppQDOvalProcInfo, \
                                   GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDArcUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDArcUPP
  NewQDArcUPP(QDArcProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDArcProcInfo = 0x00002B40
  }; /* pascal no_return_value Func(1_byte, 4_bytes, 2_bytes, 2_bytes) */
#ifdef __cplusplus
  inline QDArcUPP NewQDArcUPP(QDArcProcPtr userRoutine)
  {
    return (QDArcUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDArcProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDArcUPP(userRoutine)                                            \
  (QDArcUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppQDArcProcInfo, \
                                  GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDPolyUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDPolyUPP
  NewQDPolyUPP(QDPolyProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDPolyProcInfo = 0x00000340
  }; /* pascal no_return_value Func(1_byte, 4_bytes) */
#ifdef __cplusplus
  inline QDPolyUPP NewQDPolyUPP(QDPolyProcPtr userRoutine)
  {
    return (QDPolyUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDPolyProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDPolyUPP(userRoutine)                                             \
  (QDPolyUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppQDPolyProcInfo, \
                                   GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDRgnUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDRgnUPP
  NewQDRgnUPP(QDRgnProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDRgnProcInfo = 0x00000340
  }; /* pascal no_return_value Func(1_byte, 4_bytes) */
#ifdef __cplusplus
  inline QDRgnUPP NewQDRgnUPP(QDRgnProcPtr userRoutine)
  {
    return (QDRgnUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDRgnProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDRgnUPP(userRoutine)                                            \
  (QDRgnUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppQDRgnProcInfo, \
                                  GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDBitsUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDBitsUPP
  NewQDBitsUPP(QDBitsProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDBitsProcInfo = 0x0000EFC0
  }; /* pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes, 2_bytes, 4_bytes)
      */
#ifdef __cplusplus
  inline QDBitsUPP NewQDBitsUPP(QDBitsProcPtr userRoutine)
  {
    return (QDBitsUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDBitsProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDBitsUPP(userRoutine)                                             \
  (QDBitsUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppQDBitsProcInfo, \
                                   GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDCommentUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDCommentUPP
  NewQDCommentUPP(QDCommentProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDCommentProcInfo = 0x00000E80
  }; /* pascal no_return_value Func(2_bytes, 2_bytes, 4_bytes) */
#ifdef __cplusplus
  inline QDCommentUPP NewQDCommentUPP(QDCommentProcPtr userRoutine)
  {
    return (QDCommentUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDCommentProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDCommentUPP(userRoutine)   \
  (QDCommentUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppQDCommentProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDTxMeasUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDTxMeasUPP
  NewQDTxMeasUPP(QDTxMeasProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDTxMeasProcInfo = 0x0000FFA0
  }; /* pascal 2_bytes Func(2_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline QDTxMeasUPP NewQDTxMeasUPP(QDTxMeasProcPtr userRoutine)
  {
    return (QDTxMeasUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDTxMeasProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDTxMeasUPP(userRoutine)   \
  (QDTxMeasUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppQDTxMeasProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDGetPicUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDGetPicUPP
  NewQDGetPicUPP(QDGetPicProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDGetPicProcInfo = 0x000002C0
  }; /* pascal no_return_value Func(4_bytes, 2_bytes) */
#ifdef __cplusplus
  inline QDGetPicUPP NewQDGetPicUPP(QDGetPicProcPtr userRoutine)
  {
    return (QDGetPicUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDGetPicProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDGetPicUPP(userRoutine)   \
  (QDGetPicUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppQDGetPicProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDPutPicUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDPutPicUPP
  NewQDPutPicUPP(QDPutPicProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDPutPicProcInfo = 0x000002C0
  }; /* pascal no_return_value Func(4_bytes, 2_bytes) */
#ifdef __cplusplus
  inline QDPutPicUPP NewQDPutPicUPP(QDPutPicProcPtr userRoutine)
  {
    return (QDPutPicUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDPutPicProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDPutPicUPP(userRoutine)   \
  (QDPutPicUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppQDPutPicProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDOpcodeUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDOpcodeUPP
  NewQDOpcodeUPP(QDOpcodeProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDOpcodeProcInfo = 0x00002BC0
  }; /* pascal no_return_value Func(4_bytes, 4_bytes, 2_bytes, 2_bytes) */
#ifdef __cplusplus
  inline QDOpcodeUPP NewQDOpcodeUPP(QDOpcodeProcPtr userRoutine)
  {
    return (QDOpcodeUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDOpcodeProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDOpcodeUPP(userRoutine)   \
  (QDOpcodeUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppQDOpcodeProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDStdGlyphsUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDStdGlyphsUPP
  NewQDStdGlyphsUPP(QDStdGlyphsProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDStdGlyphsProcInfo = 0x000003F1
  }; /* 4_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline QDStdGlyphsUPP NewQDStdGlyphsUPP(QDStdGlyphsProcPtr userRoutine)
  {
    return (QDStdGlyphsUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppQDStdGlyphsProcInfo, GetCurrentArchitecture());
  }
#else
#define NewQDStdGlyphsUPP(userRoutine)                                     \
  (QDStdGlyphsUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppQDStdGlyphsProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewQDJShieldCursorUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  QDJShieldCursorUPP
  NewQDJShieldCursorUPP(QDJShieldCursorProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDJShieldCursorProcInfo = 0x00002A80
  }; /* pascal no_return_value Func(2_bytes, 2_bytes, 2_bytes, 2_bytes) */
#ifdef __cplusplus
  inline QDJShieldCursorUPP
  NewQDJShieldCursorUPP(QDJShieldCursorProcPtr userRoutine)
  {
    return (QDJShieldCursorUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                    uppQDJShieldCursorProcInfo,
                                                    GetCurrentArchitecture());
  }
#else
#define NewQDJShieldCursorUPP(userRoutine)                                     \
  (QDJShieldCursorUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppQDJShieldCursorProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeQDTextUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDTextUPP(QDTextUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDTextUPP(QDTextUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDTextUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDLineUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDLineUPP(QDLineUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDLineUPP(QDLineUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDLineUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDRectUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDRectUPP(QDRectUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDRectUPP(QDRectUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDRectUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDRRectUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDRRectUPP(QDRRectUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDRRectUPP(QDRRectUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDRRectUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDOvalUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDOvalUPP(QDOvalUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDOvalUPP(QDOvalUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDOvalUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDArcUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDArcUPP(QDArcUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDArcUPP(QDArcUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDArcUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDPolyUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDPolyUPP(QDPolyUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDPolyUPP(QDPolyUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDPolyUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDRgnUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDRgnUPP(QDRgnUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDRgnUPP(QDRgnUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDRgnUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDBitsUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDBitsUPP(QDBitsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDBitsUPP(QDBitsUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDBitsUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDCommentUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDCommentUPP(QDCommentUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDCommentUPP(QDCommentUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDCommentUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDTxMeasUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDTxMeasUPP(QDTxMeasUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDTxMeasUPP(QDTxMeasUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDTxMeasUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDGetPicUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDGetPicUPP(QDGetPicUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDGetPicUPP(QDGetPicUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDGetPicUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDPutPicUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDPutPicUPP(QDPutPicUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDPutPicUPP(QDPutPicUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDPutPicUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDOpcodeUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDOpcodeUPP(QDOpcodeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDOpcodeUPP(QDOpcodeUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDOpcodeUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDStdGlyphsUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDStdGlyphsUPP(QDStdGlyphsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDStdGlyphsUPP(QDStdGlyphsUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDStdGlyphsUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeQDJShieldCursorUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeQDJShieldCursorUPP(QDJShieldCursorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDJShieldCursorUPP(QDJShieldCursorUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDJShieldCursorUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeQDTextUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDTextUPP(short byteCount, const void *textBuf, Point numer, Point denom,
                  QDTextUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDTextUPP(short byteCount, const void *textBuf, Point numer,
                              Point denom, QDTextUPP userUPP)
  {
    CALL_FOUR_PARAMETER_UPP(userUPP, uppQDTextProcInfo, byteCount, textBuf, numer,
                            denom);
  }
#else
#define InvokeQDTextUPP(byteCount, textBuf, numer, denom, userUPP)   \
  CALL_FOUR_PARAMETER_UPP((userUPP), uppQDTextProcInfo, (byteCount), \
                          (textBuf), (numer), (denom))
#endif
#endif

  /**
   *  InvokeQDLineUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDLineUPP(Point newPt, QDLineUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDLineUPP(Point newPt, QDLineUPP userUPP)
  {
    CALL_ONE_PARAMETER_UPP(userUPP, uppQDLineProcInfo, newPt);
  }
#else
#define InvokeQDLineUPP(newPt, userUPP) \
  CALL_ONE_PARAMETER_UPP((userUPP), uppQDLineProcInfo, (newPt))
#endif
#endif

  /**
   *  InvokeQDRectUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDRectUPP(GrafVerb verb, const Rect *r, QDRectUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDRectUPP(GrafVerb verb, const Rect *r, QDRectUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppQDRectProcInfo, verb, r);
  }
#else
#define InvokeQDRectUPP(verb, r, userUPP) \
  CALL_TWO_PARAMETER_UPP((userUPP), uppQDRectProcInfo, (verb), (r))
#endif
#endif

  /**
   *  InvokeQDRRectUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDRRectUPP(GrafVerb verb, const Rect *r, short ovalWidth,
                   short ovalHeight, QDRRectUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDRRectUPP(GrafVerb verb, const Rect *r, short ovalWidth,
                               short ovalHeight, QDRRectUPP userUPP)
  {
    CALL_FOUR_PARAMETER_UPP(userUPP, uppQDRRectProcInfo, verb, r, ovalWidth,
                            ovalHeight);
  }
#else
#define InvokeQDRRectUPP(verb, r, ovalWidth, ovalHeight, userUPP)     \
  CALL_FOUR_PARAMETER_UPP((userUPP), uppQDRRectProcInfo, (verb), (r), \
                          (ovalWidth), (ovalHeight))
#endif
#endif

  /**
   *  InvokeQDOvalUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDOvalUPP(GrafVerb verb, const Rect *r, QDOvalUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDOvalUPP(GrafVerb verb, const Rect *r, QDOvalUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppQDOvalProcInfo, verb, r);
  }
#else
#define InvokeQDOvalUPP(verb, r, userUPP) \
  CALL_TWO_PARAMETER_UPP((userUPP), uppQDOvalProcInfo, (verb), (r))
#endif
#endif

  /**
   *  InvokeQDArcUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDArcUPP(GrafVerb verb, const Rect *r, short startAngle, short arcAngle,
                 QDArcUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDArcUPP(GrafVerb verb, const Rect *r, short startAngle,
                             short arcAngle, QDArcUPP userUPP)
  {
    CALL_FOUR_PARAMETER_UPP(userUPP, uppQDArcProcInfo, verb, r, startAngle,
                            arcAngle);
  }
#else
#define InvokeQDArcUPP(verb, r, startAngle, arcAngle, userUPP)      \
  CALL_FOUR_PARAMETER_UPP((userUPP), uppQDArcProcInfo, (verb), (r), \
                          (startAngle), (arcAngle))
#endif
#endif

  /**
   *  InvokeQDPolyUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDPolyUPP(GrafVerb verb, PolyHandle poly, QDPolyUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDPolyUPP(GrafVerb verb, PolyHandle poly, QDPolyUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppQDPolyProcInfo, verb, poly);
  }
#else
#define InvokeQDPolyUPP(verb, poly, userUPP) \
  CALL_TWO_PARAMETER_UPP((userUPP), uppQDPolyProcInfo, (verb), (poly))
#endif
#endif

  /**
   *  InvokeQDRgnUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDRgnUPP(GrafVerb verb, RgnHandle rgn, QDRgnUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDRgnUPP(GrafVerb verb, RgnHandle rgn, QDRgnUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppQDRgnProcInfo, verb, rgn);
  }
#else
#define InvokeQDRgnUPP(verb, rgn, userUPP) \
  CALL_TWO_PARAMETER_UPP((userUPP), uppQDRgnProcInfo, (verb), (rgn))
#endif
#endif

  /**
   *  InvokeQDBitsUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDBitsUPP(const BitMap *srcBits, const Rect *srcRect, const Rect *dstRect,
                  short mode, RgnHandle maskRgn, QDBitsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDBitsUPP(const BitMap *srcBits, const Rect *srcRect,
                              const Rect *dstRect, short mode, RgnHandle maskRgn,
                              QDBitsUPP userUPP)
  {
    CALL_FIVE_PARAMETER_UPP(userUPP, uppQDBitsProcInfo, srcBits, srcRect, dstRect,
                            mode, maskRgn);
  }
#else
#define InvokeQDBitsUPP(srcBits, srcRect, dstRect, mode, maskRgn, userUPP)    \
  CALL_FIVE_PARAMETER_UPP((userUPP), uppQDBitsProcInfo, (srcBits), (srcRect), \
                          (dstRect), (mode), (maskRgn))
#endif
#endif

  /**
   *  InvokeQDCommentUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDCommentUPP(short kind, short dataSize, Handle dataHandle,
                     QDCommentUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDCommentUPP(short kind, short dataSize, Handle dataHandle,
                                 QDCommentUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppQDCommentProcInfo, kind, dataSize,
                             dataHandle);
  }
#else
#define InvokeQDCommentUPP(kind, dataSize, dataHandle, userUPP)     \
  CALL_THREE_PARAMETER_UPP((userUPP), uppQDCommentProcInfo, (kind), \
                           (dataSize), (dataHandle))
#endif
#endif

  /**
   *  InvokeQDTxMeasUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  short
  InvokeQDTxMeasUPP(short byteCount, const void *textAddr, Point *numer,
                    Point *denom, FontInfo *info, QDTxMeasUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline short InvokeQDTxMeasUPP(short byteCount, const void *textAddr,
                                 Point *numer, Point *denom, FontInfo *info,
                                 QDTxMeasUPP userUPP)
  {
    return (short)CALL_FIVE_PARAMETER_UPP(userUPP, uppQDTxMeasProcInfo, byteCount,
                                          textAddr, numer, denom, info);
  }
#else
#define InvokeQDTxMeasUPP(byteCount, textAddr, numer, denom, info, userUPP)   \
  (short)CALL_FIVE_PARAMETER_UPP((userUPP), uppQDTxMeasProcInfo, (byteCount), \
                                 (textAddr), (numer), (denom), (info))
#endif
#endif

  /**
   *  InvokeQDGetPicUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDGetPicUPP(void *dataPtr, short byteCount, QDGetPicUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDGetPicUPP(void *dataPtr, short byteCount,
                                QDGetPicUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppQDGetPicProcInfo, dataPtr, byteCount);
  }
#else
#define InvokeQDGetPicUPP(dataPtr, byteCount, userUPP) \
  CALL_TWO_PARAMETER_UPP((userUPP), uppQDGetPicProcInfo, (dataPtr), (byteCount))
#endif
#endif

  /**
   *  InvokeQDPutPicUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDPutPicUPP(const void *dataPtr, short byteCount, QDPutPicUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDPutPicUPP(const void *dataPtr, short byteCount,
                                QDPutPicUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppQDPutPicProcInfo, dataPtr, byteCount);
  }
#else
#define InvokeQDPutPicUPP(dataPtr, byteCount, userUPP) \
  CALL_TWO_PARAMETER_UPP((userUPP), uppQDPutPicProcInfo, (dataPtr), (byteCount))
#endif
#endif

  /**
   *  InvokeQDOpcodeUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDOpcodeUPP(const Rect *fromRect, const Rect *toRect, UInt16 opcode,
                    SInt16 version, QDOpcodeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDOpcodeUPP(const Rect *fromRect, const Rect *toRect,
                                UInt16 opcode, SInt16 version,
                                QDOpcodeUPP userUPP)
  {
    CALL_FOUR_PARAMETER_UPP(userUPP, uppQDOpcodeProcInfo, fromRect, toRect,
                            opcode, version);
  }
#else
#define InvokeQDOpcodeUPP(fromRect, toRect, opcode, version, userUPP) \
  CALL_FOUR_PARAMETER_UPP((userUPP), uppQDOpcodeProcInfo, (fromRect), \
                          (toRect), (opcode), (version))
#endif
#endif

  /**
   *  InvokeQDStdGlyphsUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  InvokeQDStdGlyphsUPP(void *dataStream, ByteCount size, QDStdGlyphsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokeQDStdGlyphsUPP(void *dataStream, ByteCount size,
                                       QDStdGlyphsUPP userUPP)
  {
    return (OSStatus)CALL_TWO_PARAMETER_UPP(userUPP, uppQDStdGlyphsProcInfo,
                                            dataStream, size);
  }
#else
#define InvokeQDStdGlyphsUPP(dataStream, size, userUPP)                \
  (OSStatus) CALL_TWO_PARAMETER_UPP((userUPP), uppQDStdGlyphsProcInfo, \
                                    (dataStream), (size))
#endif
#endif

  /**
   *  InvokeQDJShieldCursorUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeQDJShieldCursorUPP(short left, short top, short right, short bottom,
                           QDJShieldCursorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeQDJShieldCursorUPP(short left, short top, short right,
                                       short bottom, QDJShieldCursorUPP userUPP)
  {
    CALL_FOUR_PARAMETER_UPP(userUPP, uppQDJShieldCursorProcInfo, left, top, right,
                            bottom);
  }
#else
#define InvokeQDJShieldCursorUPP(left, top, right, bottom, userUPP)      \
  CALL_FOUR_PARAMETER_UPP((userUPP), uppQDJShieldCursorProcInfo, (left), \
                          (top), (right), (bottom))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewQDTextProc(userRoutine) NewQDTextUPP(userRoutine)
#define NewQDLineProc(userRoutine) NewQDLineUPP(userRoutine)
#define NewQDRectProc(userRoutine) NewQDRectUPP(userRoutine)
#define NewQDRRectProc(userRoutine) NewQDRRectUPP(userRoutine)
#define NewQDOvalProc(userRoutine) NewQDOvalUPP(userRoutine)
#define NewQDArcProc(userRoutine) NewQDArcUPP(userRoutine)
#define NewQDPolyProc(userRoutine) NewQDPolyUPP(userRoutine)
#define NewQDRgnProc(userRoutine) NewQDRgnUPP(userRoutine)
#define NewQDBitsProc(userRoutine) NewQDBitsUPP(userRoutine)
#define NewQDCommentProc(userRoutine) NewQDCommentUPP(userRoutine)
#define NewQDTxMeasProc(userRoutine) NewQDTxMeasUPP(userRoutine)
#define NewQDGetPicProc(userRoutine) NewQDGetPicUPP(userRoutine)
#define NewQDPutPicProc(userRoutine) NewQDPutPicUPP(userRoutine)
#define NewQDOpcodeProc(userRoutine) NewQDOpcodeUPP(userRoutine)
#define NewQDStdGlyphsProc(userRoutine) NewQDStdGlyphsUPP(userRoutine)
#define NewQDJShieldCursorProc(userRoutine) NewQDJShieldCursorUPP(userRoutine)
#define CallQDTextProc(userRoutine, byteCount, textBuf, numer, denom) \
  InvokeQDTextUPP(byteCount, textBuf, numer, denom, userRoutine)
#define CallQDLineProc(userRoutine, newPt) InvokeQDLineUPP(newPt, userRoutine)
#define CallQDRectProc(userRoutine, verb, r) \
  InvokeQDRectUPP(verb, r, userRoutine)
#define CallQDRRectProc(userRoutine, verb, r, ovalWidth, ovalHeight) \
  InvokeQDRRectUPP(verb, r, ovalWidth, ovalHeight, userRoutine)
#define CallQDOvalProc(userRoutine, verb, r) \
  InvokeQDOvalUPP(verb, r, userRoutine)
#define CallQDArcProc(userRoutine, verb, r, startAngle, arcAngle) \
  InvokeQDArcUPP(verb, r, startAngle, arcAngle, userRoutine)
#define CallQDPolyProc(userRoutine, verb, poly) \
  InvokeQDPolyUPP(verb, poly, userRoutine)
#define CallQDRgnProc(userRoutine, verb, rgn) \
  InvokeQDRgnUPP(verb, rgn, userRoutine)
#define CallQDBitsProc(userRoutine, srcBits, srcRect, dstRect, mode, maskRgn) \
  InvokeQDBitsUPP(srcBits, srcRect, dstRect, mode, maskRgn, userRoutine)
#define CallQDCommentProc(userRoutine, kind, dataSize, dataHandle) \
  InvokeQDCommentUPP(kind, dataSize, dataHandle, userRoutine)
#define CallQDTxMeasProc(userRoutine, byteCount, textAddr, numer, denom, info) \
  InvokeQDTxMeasUPP(byteCount, textAddr, numer, denom, info, userRoutine)
#define CallQDGetPicProc(userRoutine, dataPtr, byteCount) \
  InvokeQDGetPicUPP(dataPtr, byteCount, userRoutine)
#define CallQDPutPicProc(userRoutine, dataPtr, byteCount) \
  InvokeQDPutPicUPP(dataPtr, byteCount, userRoutine)
#define CallQDOpcodeProc(userRoutine, fromRect, toRect, opcode, version) \
  InvokeQDOpcodeUPP(fromRect, toRect, opcode, version, userRoutine)
#define CallQDStdGlyphsProc(userRoutine, dataStream, size) \
  InvokeQDStdGlyphsUPP(dataStream, size, userRoutine)
#define CallQDJShieldCursorProc(userRoutine, left, top, right, bottom) \
  InvokeQDJShieldCursorUPP(left, top, right, bottom, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

#if !OPAQUE_TOOLBOX_STRUCTS
  struct GrafPort
  {
    short device;      /* not available in Carbon*/
    BitMap portBits;   /* in Carbon use GetPortBitMapForCopyBits or IsPortColor*/
    Rect portRect;     /* in Carbon use Get/SetPortBounds*/
    RgnHandle visRgn;  /* in Carbon use Get/SetPortVisibleRegion*/
    RgnHandle clipRgn; /* in Carbon use Get/SetPortClipRegion*/
    Pattern bkPat;     /* not available in Carbon all GrafPorts are CGrafPorts*/
    Pattern fillPat;   /* not available in Carbon all GrafPorts are CGrafPorts*/
    Point pnLoc;       /* in Carbon use GetPortPenLocation or MoveTo*/
    Point pnSize;      /* in Carbon use Get/SetPortPenSize*/
    short pnMode;      /* in Carbon use Get/SetPortPenMode*/
    Pattern pnPat;     /* not available in Carbon all GrafPorts are CGrafPorts*/
    short pnVis;       /* in Carbon use GetPortPenVisibility or Show/HidePen*/
    short txFont;      /* in Carbon use GetPortTextFont or TextFont*/
    StyleField txFace; /* in Carbon use GetPortTextFace or TextFace*/
    /*StyleField occupies 16-bits, but only first 8-bits are used*/
    short txMode;     /* in Carbon use GetPortTextMode or TextMode*/
    short txSize;     /* in Carbon use GetPortTextSize or TextSize*/
    Fixed spExtra;    /* in Carbon use GetPortSpExtra or SpaceExtra*/
    long fgColor;     /* not available in Carbon */
    long bkColor;     /* not available in Carbon*/
    short colrBit;    /* not available in Carbon*/
    short patStretch; /* not available in Carbon*/
    Handle picSave;   /* in Carbon use IsPortPictureBeingDefined*/
    Handle rgnSave;   /* not available in Carbon*/
    Handle polySave;  /* not available in Carbon*/
    QDProcsPtr
        grafProcs; /* not available in Carbon all GrafPorts are CGrafPorts*/
  };
  typedef struct GrafPort GrafPort;
  typedef GrafPort *GrafPtr;
  /**
   *  This set of definitions "belongs" in Windows.
   *  But, there is a circularity in the headers where Windows includes Controls
   * and Controls includes Windows. To break the circle, the information needed by
   * Controls is moved from Windows to Quickdraw.
   */
  typedef GrafPtr WindowPtr;
  typedef WindowPtr DialogPtr;
#else
typedef struct OpaqueWindowPtr *WindowPtr;
typedef struct OpaqueDialogPtr *DialogPtr;
typedef struct OpaqueGrafPtr *GrafPtr;
#endif /* !OPAQUE_TOOLBOX_STRUCTS */

  typedef WindowPtr WindowRef;
  /* DragConstraint constants to pass to DragGray,DragTheRgn, or
   * ConstrainedDragRgn*/
  typedef UInt16 DragConstraint;
  enum
  {
    kNoConstraint = 0,
    kVerticalConstraint = 1,
    kHorizontalConstraint = 2
  };

  typedef CALLBACK_API(void, DragGrayRgnProcPtr)(void);
  /**
   *  Here ends the list of things that "belong" in Windows.
   */

  struct RGBColor
  {
    unsigned short red;   /*magnitude of red component*/
    unsigned short green; /*magnitude of green component*/
    unsigned short blue;  /*magnitude of blue component*/
  };
  typedef struct RGBColor RGBColor;
  typedef RGBColor *RGBColorPtr;
  typedef RGBColorPtr *RGBColorHdl;
  typedef CALLBACK_API(Boolean, ColorSearchProcPtr)(RGBColor *rgb,
                                                    long *position);
  typedef CALLBACK_API(Boolean, ColorComplementProcPtr)(RGBColor *rgb);
  typedef STACK_UPP_TYPE(DragGrayRgnProcPtr) DragGrayRgnUPP;
  typedef STACK_UPP_TYPE(ColorSearchProcPtr) ColorSearchUPP;
  typedef STACK_UPP_TYPE(ColorComplementProcPtr) ColorComplementUPP;
  /**
   *  NewDragGrayRgnUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DragGrayRgnUPP
  NewDragGrayRgnUPP(DragGrayRgnProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDragGrayRgnProcInfo = 0x00000000
  }; /* pascal no_return_value Func() */
#ifdef __cplusplus
  inline DragGrayRgnUPP NewDragGrayRgnUPP(DragGrayRgnProcPtr userRoutine)
  {
    return (DragGrayRgnUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDragGrayRgnProcInfo, GetCurrentArchitecture());
  }
#else
#define NewDragGrayRgnUPP(userRoutine)                                     \
  (DragGrayRgnUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppDragGrayRgnProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewColorSearchUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ColorSearchUPP
  NewColorSearchUPP(ColorSearchProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppColorSearchProcInfo = 0x000003D0
  }; /* pascal 1_byte Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ColorSearchUPP NewColorSearchUPP(ColorSearchProcPtr userRoutine)
  {
    return (ColorSearchUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppColorSearchProcInfo, GetCurrentArchitecture());
  }
#else
#define NewColorSearchUPP(userRoutine)                                     \
  (ColorSearchUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppColorSearchProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewColorComplementUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ColorComplementUPP
  NewColorComplementUPP(ColorComplementProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppColorComplementProcInfo = 0x000000D0
  }; /* pascal 1_byte Func(4_bytes) */
#ifdef __cplusplus
  inline ColorComplementUPP
  NewColorComplementUPP(ColorComplementProcPtr userRoutine)
  {
    return (ColorComplementUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                    uppColorComplementProcInfo,
                                                    GetCurrentArchitecture());
  }
#else
#define NewColorComplementUPP(userRoutine)                                     \
  (ColorComplementUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppColorComplementProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeDragGrayRgnUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDragGrayRgnUPP(DragGrayRgnUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDragGrayRgnUPP(DragGrayRgnUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDragGrayRgnUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeColorSearchUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeColorSearchUPP(ColorSearchUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeColorSearchUPP(ColorSearchUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeColorSearchUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeColorComplementUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeColorComplementUPP(ColorComplementUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeColorComplementUPP(ColorComplementUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeColorComplementUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeDragGrayRgnUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeDragGrayRgnUPP(DragGrayRgnUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeDragGrayRgnUPP(DragGrayRgnUPP userUPP)
  {
    CALL_ZERO_PARAMETER_UPP(userUPP, uppDragGrayRgnProcInfo);
  }
#else
#define InvokeDragGrayRgnUPP(userUPP) \
  CALL_ZERO_PARAMETER_UPP((userUPP), uppDragGrayRgnProcInfo)
#endif
#endif

  /**
   *  InvokeColorSearchUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  InvokeColorSearchUPP(RGBColor *rgb, long *position, ColorSearchUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokeColorSearchUPP(RGBColor *rgb, long *position,
                                      ColorSearchUPP userUPP)
  {
    return (Boolean)CALL_TWO_PARAMETER_UPP(userUPP, uppColorSearchProcInfo, rgb,
                                           position);
  }
#else
#define InvokeColorSearchUPP(rgb, position, userUPP)                         \
  (Boolean) CALL_TWO_PARAMETER_UPP((userUPP), uppColorSearchProcInfo, (rgb), \
                                   (position))
#endif
#endif

  /**
   *  InvokeColorComplementUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  InvokeColorComplementUPP(RGBColor *rgb, ColorComplementUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Boolean InvokeColorComplementUPP(RGBColor *rgb,
                                          ColorComplementUPP userUPP)
  {
    return (Boolean)CALL_ONE_PARAMETER_UPP(userUPP, uppColorComplementProcInfo,
                                           rgb);
  }
#else
#define InvokeColorComplementUPP(rgb, userUPP) \
  (Boolean) CALL_ONE_PARAMETER_UPP((userUPP), uppColorComplementProcInfo, (rgb))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewDragGrayRgnProc(userRoutine) NewDragGrayRgnUPP(userRoutine)
#define NewColorSearchProc(userRoutine) NewColorSearchUPP(userRoutine)
#define NewColorComplementProc(userRoutine) NewColorComplementUPP(userRoutine)
#define CallDragGrayRgnProc(userRoutine) InvokeDragGrayRgnUPP(userRoutine)
#define CallColorSearchProc(userRoutine, rgb, position) \
  InvokeColorSearchUPP(rgb, position, userRoutine)
#define CallColorComplementProc(userRoutine, rgb) \
  InvokeColorComplementUPP(rgb, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

  struct ColorSpec
  {
    short value;  /*index or other value*/
    RGBColor rgb; /*true color*/
  };
  typedef struct ColorSpec ColorSpec;
  typedef ColorSpec *ColorSpecPtr;
  typedef ColorSpec CSpecArray[1];
  struct ColorTable
  {
    long ctSeed;        /*unique identifier for table*/
    short ctFlags;      /*high bit: 0 = PixMap; 1 = device*/
    short ctSize;       /*number of entries in CTTable*/
    CSpecArray ctTable; /*array [0..0] of ColorSpec*/
  };
  typedef struct ColorTable ColorTable;
  typedef ColorTable *CTabPtr;
  typedef CTabPtr *CTabHandle;
  struct xColorSpec
  {
    short value;  /*index or other value*/
    RGBColor rgb; /*true color*/
    short xalpha;
  };
  typedef struct xColorSpec xColorSpec;
  typedef xColorSpec *xColorSpecPtr;
  typedef xColorSpec xCSpecArray[1];
  struct MatchRec
  {
    unsigned short red;
    unsigned short green;
    unsigned short blue;
    long matchData;
  };
  typedef struct MatchRec MatchRec;
/**
    QuickTime 3.0 makes PixMap data structure available on non-Mac OS's.
    In order to implement PixMap in these alternate environments, the PixMap
    had to be extended. The pmReserved field was changed to pmExt which is
    a Handle to extra info.  The planeBytes field was changed to pixelFormat.

    In OS X, Quickdraw also uses the new PixMap data structure.
*/
#ifndef OLDPIXMAPSTRUCT
#if TARGET_OS_MAC && TARGET_API_MAC_OS8
#define OLDPIXMAPSTRUCT 1
#else
#define OLDPIXMAPSTRUCT 0
#endif /* TARGET_OS_MAC && TARGET_API_MAC_OS8 */

#endif /* !defined(OLDPIXMAPSTRUCT) */

#if OLDPIXMAPSTRUCT
#define GETPIXMAPPIXELFORMAT(pm) ((pm)->pixelSize)
#else
#define GETPIXMAPPIXELFORMAT(pm) \
  (((pm)->pixelFormat != 0) ? (pm)->pixelFormat : (pm)->pixelSize)
#endif

#if TARGET_OS_MAC && TARGET_API_MAC_OS8
#define NON_MAC_PIXEL_FORMATS 0
#else
#define NON_MAC_PIXEL_FORMATS 1
#endif

  /* pixel formats*/
  enum
  {
    k1MonochromePixelFormat = 0x00000001,  /* 1 bit indexed*/
    k2IndexedPixelFormat = 0x00000002,     /* 2 bit indexed*/
    k4IndexedPixelFormat = 0x00000004,     /* 4 bit indexed*/
    k8IndexedPixelFormat = 0x00000008,     /* 8 bit indexed*/
    k16BE555PixelFormat = 0x00000010,      /* 16 bit BE rgb 555 (Mac)*/
    k24RGBPixelFormat = 0x00000018,        /* 24 bit rgb */
    k32ARGBPixelFormat = 0x00000020,       /* 32 bit argb    (Mac)*/
    k1IndexedGrayPixelFormat = 0x00000021, /* 1 bit indexed gray*/
    k2IndexedGrayPixelFormat = 0x00000022, /* 2 bit indexed gray*/
    k4IndexedGrayPixelFormat = 0x00000024, /* 4 bit indexed gray*/
    k8IndexedGrayPixelFormat = 0x00000028  /* 8 bit indexed gray*/
  };

  /* values for PixMap.pixelFormat*/
  enum
  {
    k16LE555PixelFormat = FOUR_CHAR_CODE('L555'),  /* 16 bit LE rgb 555 (PC)*/
    k16LE5551PixelFormat = FOUR_CHAR_CODE('5551'), /* 16 bit LE rgb 5551*/
    k16BE565PixelFormat = FOUR_CHAR_CODE('B565'),  /* 16 bit BE rgb 565*/
    k16LE565PixelFormat = FOUR_CHAR_CODE('L565'),  /* 16 bit LE rgb 565*/
    k24BGRPixelFormat = FOUR_CHAR_CODE('24BG'),    /* 24 bit bgr */
    k32BGRAPixelFormat = FOUR_CHAR_CODE('BGRA'),   /* 32 bit bgra    (Matrox)*/
    k32ABGRPixelFormat = FOUR_CHAR_CODE('ABGR'),   /* 32 bit abgr    */
    k32RGBAPixelFormat = FOUR_CHAR_CODE('RGBA'),   /* 32 bit rgba    */
    kYUVSPixelFormat =
        FOUR_CHAR_CODE('yuvs'), /* YUV 4:2:2 byte ordering 16-unsigned = 'YUY2'*/
    kYUVUPixelFormat =
        FOUR_CHAR_CODE('yuvu'),                   /* YUV 4:2:2 byte ordering 16-signed*/
    kYVU9PixelFormat = FOUR_CHAR_CODE('YVU9'),    /* YVU9 Planar    9*/
    kYUV411PixelFormat = FOUR_CHAR_CODE('Y411'),  /* YUV 4:1:1 Interleaved  16*/
    kYVYU422PixelFormat = FOUR_CHAR_CODE('YVYU'), /* YVYU 4:2:2 byte ordering 16*/
    kUYVY422PixelFormat = FOUR_CHAR_CODE('UYVY'), /* UYVY 4:2:2 byte ordering 16*/
    kYUV211PixelFormat = FOUR_CHAR_CODE('Y211'),  /* YUV 2:1:1 Packed   8*/
    k2vuyPixelFormat = FOUR_CHAR_CODE('2vuy')     /* UYVY 4:2:2 byte ordering   16*/
  };

  struct PixMap
  {
    Ptr baseAddr;    /*pointer to pixels*/
    short rowBytes;  /*offset to next line*/
    Rect bounds;     /*encloses bitmap*/
    short pmVersion; /*pixMap version number*/
    short packType;  /*defines packing format*/
    long packSize;   /*length of pixel data*/
    Fixed hRes;      /*horiz. resolution (ppi)*/
    Fixed vRes;      /*vert. resolution (ppi)*/
    short pixelType; /*defines pixel type*/
    short pixelSize; /*# bits in pixel*/
    short cmpCount;  /*# components in pixel*/
    short cmpSize;   /*# bits per component*/
#if OLDPIXMAPSTRUCT
    long planeBytes;    /*offset to next plane*/
    CTabHandle pmTable; /*color map for this pixMap*/
    long pmReserved;
#else
  OSType pixelFormat; /*fourCharCode representation*/
  CTabHandle pmTable; /*color map for this pixMap*/
  void *pmExt;        /*Handle to pixMap extension*/
#endif
  };
  typedef struct PixMap PixMap;
  typedef PixMap *PixMapPtr;
  typedef PixMapPtr *PixMapHandle;
  struct PixPat
  {
    short patType;       /*type of pattern*/
    PixMapHandle patMap; /*the pattern's pixMap*/
    Handle patData;      /*pixmap's data*/
    Handle patXData;     /*expanded Pattern data*/
    short patXValid;     /*flags whether expanded Pattern valid*/
    Handle patXMap;      /*Handle to expanded Pattern data*/
    Pattern pat1Data;    /*old-Style pattern/RGB color*/
  };
  typedef struct PixPat PixPat;
  typedef PixPat *PixPatPtr;
  typedef PixPatPtr *PixPatHandle;
  struct CCrsr
  {
    short crsrType;       /*type of cursor*/
    PixMapHandle crsrMap; /*the cursor's pixmap*/
    Handle crsrData;      /*cursor's data*/
    Handle crsrXData;     /*expanded cursor data*/
    short crsrXValid;     /*depth of expanded data (0 if none)*/
    Handle crsrXHandle;   /*future use*/
    Bits16 crsr1Data;     /*one-bit cursor*/
    Bits16 crsrMask;      /*cursor's mask*/
    Point crsrHotSpot;    /*cursor's hotspot*/
    long crsrXTable;      /*private*/
    long crsrID;          /*private*/
  };
  typedef struct CCrsr CCrsr;
  typedef CCrsr *CCrsrPtr;
  typedef CCrsrPtr *CCrsrHandle;
  struct GammaTbl
  {
    short gVersion;        /*gamma version number*/
    short gType;           /*gamma data type*/
    short gFormulaSize;    /*Formula data size*/
    short gChanCnt;        /*number of channels of data*/
    short gDataCnt;        /*number of values/channel*/
    short gDataWidth;      /*bits/corrected value (data packed to next larger byte
                              size)*/
    short gFormulaData[1]; /*data for formulas followed by gamma values*/
  };
  typedef struct GammaTbl GammaTbl;
  typedef GammaTbl *GammaTblPtr;
  typedef GammaTblPtr *GammaTblHandle;
  struct ITab
  {
    long iTabSeed;   /*copy of CTSeed from source CTable*/
    short iTabRes;   /*bits/channel resolution of iTable*/
    Byte iTTable[1]; /*byte colortable index values*/
  };
  typedef struct ITab ITab;
  typedef ITab *ITabPtr;
  typedef ITabPtr *ITabHandle;
  struct SProcRec
  {
    Handle nxtSrch;          /*SProcHndl Handle to next SProcRec*/
    ColorSearchUPP srchProc; /*search procedure proc ptr*/
  };
  typedef struct SProcRec SProcRec;
  typedef SProcRec *SProcPtr;
  typedef SProcPtr *SProcHndl;
  struct CProcRec
  {
    Handle nxtComp;              /*CProcHndl Handle to next CProcRec*/
    ColorComplementUPP compProc; /*complement procedure proc ptr*/
  };
  typedef struct CProcRec CProcRec;
  typedef CProcRec *CProcPtr;
  typedef CProcPtr *CProcHndl;
/**
    QuickTime 3.0 makes GDevice data structure available on non-Mac OS's.
    In order to implement GDevice in these alternate environments, the GDevice
    had to be extended. The gdReserved field was changed to gdExt which is
    a Handle to extra info.
*/
#ifndef OLDGDEVICESTRUCT
#if TARGET_OS_MAC && TARGET_API_MAC_OS8
#define OLDGDEVICESTRUCT 1
#else
#define OLDGDEVICESTRUCT 0
#endif /* TARGET_OS_MAC && TARGET_API_MAC_OS8 */

#endif /* !defined(OLDGDEVICESTRUCT) */

  typedef struct GDevice GDevice;
  typedef GDevice *GDPtr;
  typedef GDPtr *GDHandle;
  struct GDevice
  {
    short gdRefNum;         /*driver's unit number*/
    short gdID;             /*client ID for search procs*/
    short gdType;           /*fixed/CLUT/direct*/
    ITabHandle gdITable;    /*Handle to inverse lookup table*/
    short gdResPref;        /*preferred resolution of GDITable*/
    SProcHndl gdSearchProc; /*search proc list head*/
    CProcHndl gdCompProc;   /*complement proc list*/
    short gdFlags;          /*grafDevice flags word*/
    PixMapHandle gdPMap;    /*describing pixMap*/
    long gdRefCon;          /*reference value*/
    GDHandle gdNextGD;      /*GDHandle Handle of next gDevice*/
    Rect gdRect;            /* device's bounds in global coordinates*/
    long gdMode;            /*device's current mode*/
    short gdCCBytes;        /*depth of expanded cursor data*/
    short gdCCDepth;        /*depth of expanded cursor data*/
    Handle gdCCXData;       /*Handle to cursor's expanded data*/
    Handle gdCCXMask;       /*Handle to cursor's expanded mask*/
#if OLDGDEVICESTRUCT
    long gdReserved; /*future use. MUST BE 0*/
#else
  Handle gdExt; /*QuickTime 3.0 private info*/
#endif
  };

  struct GrafVars
  {
    RGBColor rgbOpColor;     /*color for addPin  subPin and average*/
    RGBColor rgbHiliteColor; /*color for hiliting*/
    Handle pmFgColor;        /*palette Handle for foreground color*/
    short pmFgIndex;         /*index value for foreground*/
    Handle pmBkColor;        /*palette Handle for background color*/
    short pmBkIndex;         /*index value for background*/
    short pmFlags;           /*flags for Palette Manager*/
  };
  typedef struct GrafVars GrafVars;
  typedef GrafVars *GVarPtr;
  typedef GVarPtr *GVarHandle;

#if !OPAQUE_TOOLBOX_STRUCTS
  typedef struct CGrafPort CGrafPort;
  typedef CGrafPort *CGrafPtr;
#else
typedef GrafPtr CGrafPtr;
#endif /* !OPAQUE_TOOLBOX_STRUCTS */

  typedef CALLBACK_API_C(OSStatus,
                         QDPrinterStatusProcPtr)(PrinterStatusOpcode opcode,
                                                 CGrafPtr currentPort,
                                                 void *printerStatus);
  typedef STACK_UPP_TYPE(QDPrinterStatusProcPtr) QDPrinterStatusUPP;

  struct CQDProcs
  {
    QDTextUPP textProc;
    QDLineUPP lineProc;
    QDRectUPP rectProc;
    QDRRectUPP rRectProc;
    QDOvalUPP ovalProc;
    QDArcUPP arcProc;
    QDPolyUPP polyProc;
    QDRgnUPP rgnProc;
    QDBitsUPP bitsProc;
    QDCommentUPP commentProc;
    QDTxMeasUPP txMeasProc;
    QDGetPicUPP getPicProc;
    QDPutPicUPP putPicProc;
    QDOpcodeUPP opcodeProc;
    UniversalProcPtr
        newProc1; /* this is the StdPix bottleneck -- see ImageCompression.h */
    QDStdGlyphsUPP
        glyphsProc; /* was newProc2; now used in Unicode text drawing */
    QDPrinterStatusUPP
        printerStatusProc; /* was newProc3;  now used to communicate status
                              between Printing code and System imaging code */
    UniversalProcPtr newProc4;
    UniversalProcPtr newProc5;
    UniversalProcPtr newProc6;
  };
  typedef struct CQDProcs CQDProcs;
  typedef CQDProcs *CQDProcsPtr;
#if !OPAQUE_TOOLBOX_STRUCTS
  struct CGrafPort
  {
    short device;            /* not available in Carbon*/
    PixMapHandle portPixMap; /* in Carbon use GetPortPixMap*/
    short portVersion;       /* in Carbon use IsPortColor*/
    Handle grafVars;         /* not available in Carbon*/
    short chExtra;           /* in Carbon use GetPortChExtra*/
    short pnLocHFrac;        /* in Carbon use Get/SetPortFracHPenLocation*/
    Rect portRect;           /* in Carbon use Get/SetPortBounds*/
    RgnHandle visRgn;        /* in Carbon use Get/SetPortVisibleRegion*/
    RgnHandle clipRgn;       /* in Carbon use Get/SetPortClipRegion*/
    PixPatHandle bkPixPat;   /* in Carbon use GetPortBackPixPat or BackPixPat*/
    RGBColor rgbFgColor;     /* in Carbon use GetPortForeColor or RGBForeColor*/
    RGBColor rgbBkColor;     /* in Carbon use GetPortBackColor or RGBBackColor*/
    Point pnLoc;             /* in Carbon use GetPortPenLocation or MoveTo*/
    Point pnSize;            /* in Carbon use Get/SetPortPenSize*/
    short pnMode;            /* in Carbon use Get/SetPortPenMode*/
    PixPatHandle pnPixPat;   /* in Carbon use Get/SetPortPenPixPat*/
    PixPatHandle fillPixPat; /* in Carbon use GetPortFillPixPat*/
    short pnVis;             /* in Carbon use GetPortPenVisibility or Show/HidePen*/
    short txFont;            /* in Carbon use GetPortTextFont or TextFont*/
    StyleField txFace;       /* in Carbon use GetPortTextFace or TextFace*/
    /*StyleField occupies 16-bits, but only first 8-bits are used*/
    short txMode;          /* in Carbon use GetPortTextMode or TextMode*/
    short txSize;          /* in Carbon use GetPortTextSize or TextSize*/
    Fixed spExtra;         /* in Carbon use GetPortSpExtra or SpaceExtra*/
    long fgColor;          /* not available in Carbon*/
    long bkColor;          /* not available in Carbon*/
    short colrBit;         /* not available in Carbon*/
    short patStretch;      /* not available in Carbon*/
    Handle picSave;        /* in Carbon use IsPortPictureBeingDefined*/
    Handle rgnSave;        /* in Carbon use IsPortRegionBeingDefined*/
    Handle polySave;       /* in Carbon use IsPortPolyBeingDefined*/
    CQDProcsPtr grafProcs; /* in Carbon use Get/SetPortGrafProcs*/
  };

#endif /* !OPAQUE_TOOLBOX_STRUCTS */

#if OPAQUE_TOOLBOX_STRUCTS
  typedef WindowPtr CWindowPtr;
#else
typedef CGrafPtr CWindowPtr;
#endif /* OPAQUE_TOOLBOX_STRUCTS */

  struct ReqListRec
  {
    short reqLSize;    /*request list size*/
    short reqLData[1]; /*request list data*/
  };
  typedef struct ReqListRec ReqListRec;
  struct OpenCPicParams
  {
    Rect srcRect;
    Fixed hRes;
    Fixed vRes;
    short version;
    short reserved1;
    long reserved2;
  };
  typedef struct OpenCPicParams OpenCPicParams;
  enum
  {
    kCursorImageMajorVersion = 0x0001,
    kCursorImageMinorVersion = 0x0000
  };

  struct CursorImageRec
  {
    UInt16 majorVersion;
    UInt16 minorVersion;
    PixMapHandle cursorPixMap;
    BitMapHandle cursorBitMask;
  };
  typedef struct CursorImageRec CursorImageRec;
  typedef CursorImageRec *CursorImagePtr;
  typedef CALLBACK_API(void, DeviceLoopDrawingProcPtr)(short depth,
                                                       short deviceFlags,
                                                       GDHandle targetDevice,
                                                       long userData);
  typedef STACK_UPP_TYPE(DeviceLoopDrawingProcPtr) DeviceLoopDrawingUPP;
#if CALL_NOT_IN_CARBON
  /**
   *  NewQDPrinterStatusUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  QDPrinterStatusUPP
  NewQDPrinterStatusUPP(QDPrinterStatusProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppQDPrinterStatusProcInfo = 0x00000FF1
  }; /* 4_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline QDPrinterStatusUPP
  NewQDPrinterStatusUPP(QDPrinterStatusProcPtr userRoutine)
  {
    return (QDPrinterStatusUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                    uppQDPrinterStatusProcInfo,
                                                    GetCurrentArchitecture());
  }
#else
#define NewQDPrinterStatusUPP(userRoutine)                                     \
  (QDPrinterStatusUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppQDPrinterStatusProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

  /**
   *  NewDeviceLoopDrawingUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DeviceLoopDrawingUPP
  NewDeviceLoopDrawingUPP(DeviceLoopDrawingProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDeviceLoopDrawingProcInfo = 0x00003E80
  }; /* pascal no_return_value Func(2_bytes, 2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline DeviceLoopDrawingUPP
  NewDeviceLoopDrawingUPP(DeviceLoopDrawingProcPtr userRoutine)
  {
    return (DeviceLoopDrawingUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDeviceLoopDrawingProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewDeviceLoopDrawingUPP(userRoutine)                                \
  (DeviceLoopDrawingUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),       \
                                              uppDeviceLoopDrawingProcInfo, \
                                              GetCurrentArchitecture())
#endif
#endif

#if CALL_NOT_IN_CARBON
  /**
   *  DisposeQDPrinterStatusUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  DisposeQDPrinterStatusUPP(QDPrinterStatusUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeQDPrinterStatusUPP(QDPrinterStatusUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeQDPrinterStatusUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

  /**
   *  DisposeDeviceLoopDrawingUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDeviceLoopDrawingUPP(DeviceLoopDrawingUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeDeviceLoopDrawingUPP(DeviceLoopDrawingUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDeviceLoopDrawingUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

#if CALL_NOT_IN_CARBON
  /**
   *  InvokeQDPrinterStatusUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  InvokeQDPrinterStatusUPP(PrinterStatusOpcode opcode, CGrafPtr currentPort,
                           void *printerStatus, QDPrinterStatusUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokeQDPrinterStatusUPP(PrinterStatusOpcode opcode,
                                           CGrafPtr currentPort,
                                           void *printerStatus,
                                           QDPrinterStatusUPP userUPP)
  {
    return (OSStatus)CALL_THREE_PARAMETER_UPP(userUPP, uppQDPrinterStatusProcInfo,
                                              opcode, currentPort, printerStatus);
  }
#else
#define InvokeQDPrinterStatusUPP(opcode, currentPort, printerStatus, userUPP) \
  (OSStatus)                                                                  \
      CALL_THREE_PARAMETER_UPP((userUPP), uppQDPrinterStatusProcInfo,         \
                               (opcode), (currentPort), (printerStatus))
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

  /**
   *  InvokeDeviceLoopDrawingUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeDeviceLoopDrawingUPP(short depth, short deviceFlags,
                             GDHandle targetDevice, long userData,
                             DeviceLoopDrawingUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeDeviceLoopDrawingUPP(short depth, short deviceFlags,
                                         GDHandle targetDevice, long userData,
                                         DeviceLoopDrawingUPP userUPP)
  {
    CALL_FOUR_PARAMETER_UPP(userUPP, uppDeviceLoopDrawingProcInfo, depth,
                            deviceFlags, targetDevice, userData);
  }
#else
#define InvokeDeviceLoopDrawingUPP(depth, deviceFlags, targetDevice, userData, \
                                   userUPP)                                    \
  CALL_FOUR_PARAMETER_UPP((userUPP), uppDeviceLoopDrawingProcInfo, (depth),    \
                          (deviceFlags), (targetDevice), (userData))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewQDPrinterStatusProc(userRoutine) NewQDPrinterStatusUPP(userRoutine)
#define NewDeviceLoopDrawingProc(userRoutine) \
  NewDeviceLoopDrawingUPP(userRoutine)
#define CallQDPrinterStatusProc(userRoutine, opcode, currentPort, \
                                printerStatus)                    \
  InvokeQDPrinterStatusUPP(opcode, currentPort, printerStatus, userRoutine)
#define CallDeviceLoopDrawingProc(userRoutine, depth, deviceFlags,       \
                                  targetDevice, userData)                \
  InvokeDeviceLoopDrawingUPP(depth, deviceFlags, targetDevice, userData, \
                             userRoutine)
#endif /* CALL_NOT_IN_CARBON */

#if !OPAQUE_TOOLBOX_STRUCTS || !TARGET_API_MAC_CARBON
  struct QDGlobals
  {
    char privates[76];
    long randSeed;     /* in Carbon use GetQDGlobalsRandomSeed*/
    BitMap screenBits; /* in Carbon use GetQDGlobalsScreenBits*/
    Cursor arrow;      /* in Carbon use GetQDGlobalsArrow*/
    Pattern dkGray;    /* in Carbon use GetQDGlobalsDarkGray*/
    Pattern ltGray;    /* in Carbon use GetQDGlobalsLightGray*/
    Pattern gray;      /* in Carbon use GetQDGlobalsGray*/
    Pattern black;     /* in Carbon use GetQDGlobalsBlack*/
    Pattern white;     /* in Carbon use GetQDGlobalsWhite*/
    GrafPtr thePort;   /* in Carbon use GetQDGlobalsThePort*/
  };
  typedef struct QDGlobals QDGlobals;
  typedef QDGlobals *QDGlobalsPtr;
  typedef QDGlobalsPtr *QDGlobalsHdl;
  extern QDGlobals qd;

#endif /* !OPAQUE_TOOLBOX_STRUCTS || !TARGET_API_MAC_CARBON */

#if CALL_NOT_IN_CARBON
  /**
   *  InitGraf()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InitGraf(void *globalPtr);

  /**
   *  OpenPort()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  OpenPort(GrafPtr port);

  /**
   *  InitPort()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  InitPort(GrafPtr port);

  /**
   *  ClosePort()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  ClosePort(GrafPtr port);

/**
   These are Carbon only routines. They do nothing at all on
   Mac OS 8, but work flawlessly on Mac OS X.
*/
#endif /* CALL_NOT_IN_CARBON */

  /**
   *  LockPortBits()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  LockPortBits(GrafPtr port);

  /**
   *  UnlockPortBits()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  UnlockPortBits(GrafPtr port);

  /* Break a region up into rectangles.*/

  enum
  {
    kQDParseRegionFromTop = (1 << 0),
    kQDParseRegionFromBottom = (1 << 1),
    kQDParseRegionFromLeft = (1 << 2),
    kQDParseRegionFromRight = (1 << 3),
    kQDParseRegionFromTopLeft = kQDParseRegionFromTop | kQDParseRegionFromLeft,
    kQDParseRegionFromBottomRight =
        kQDParseRegionFromBottom | kQDParseRegionFromRight
  };

  typedef SInt32 QDRegionParseDirection;
  enum
  {
    kQDRegionToRectsMsgInit = 1,
    kQDRegionToRectsMsgParse = 2,
    kQDRegionToRectsMsgTerminate = 3
  };

  typedef CALLBACK_API_C(OSStatus,
                         RegionToRectsProcPtr)(UInt16 message, RgnHandle rgn,
                                               const Rect *rect, void *refCon);
  typedef STACK_UPP_TYPE(RegionToRectsProcPtr) RegionToRectsUPP;
  /**
   *  NewRegionToRectsUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  RegionToRectsUPP
  NewRegionToRectsUPP(RegionToRectsProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppRegionToRectsProcInfo = 0x00003FB1
  }; /* 4_bytes Func(2_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline RegionToRectsUPP NewRegionToRectsUPP(RegionToRectsProcPtr userRoutine)
  {
    return (RegionToRectsUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppRegionToRectsProcInfo,
                                                  GetCurrentArchitecture());
  }
#else
#define NewRegionToRectsUPP(userRoutine)                                     \
  (RegionToRectsUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppRegionToRectsProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeRegionToRectsUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeRegionToRectsUPP(RegionToRectsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeRegionToRectsUPP(RegionToRectsUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeRegionToRectsUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeRegionToRectsUPP()
   *
   *  Availability:
   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  InvokeRegionToRectsUPP(UInt16 message, RgnHandle rgn, const Rect *rect,
                         void *refCon, RegionToRectsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSStatus InvokeRegionToRectsUPP(UInt16 message, RgnHandle rgn,
                                         const Rect *rect, void *refCon,
                                         RegionToRectsUPP userUPP)
  {
    return (OSStatus)CALL_FOUR_PARAMETER_UPP(userUPP, uppRegionToRectsProcInfo,
                                             message, rgn, rect, refCon);
  }
#else
#define InvokeRegionToRectsUPP(message, rgn, rect, refCon, userUPP)       \
  (OSStatus) CALL_FOUR_PARAMETER_UPP((userUPP), uppRegionToRectsProcInfo, \
                                     (message), (rgn), (rect), (refCon))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewRegionToRectsProc(userRoutine) NewRegionToRectsUPP(userRoutine)
#define CallRegionToRectsProc(userRoutine, message, rgn, rect, refCon) \
  InvokeRegionToRectsUPP(message, rgn, rect, refCon, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

  /**
   *  QDRegionToRects()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSStatus
  QDRegionToRects(RgnHandle rgn, QDRegionParseDirection dir,
                  RegionToRectsUPP proc, void *userData);

#if !TARGET_OS_MAC
#if CALL_NOT_IN_CARBON
  /**
   *  UpdatePort()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  UpdatePort(GrafPtr port);

  /**
  \brief Find which GrafPort is currently active

  <pre>GetPort copies a pointer to the current active GrafPort into a local variable.
savePort is the address of a GrafPtr. Upon return, it will contain a copy of
the global variable thePort (i.e., a pointer to the current active
GrafPort ).
</pre>
* \returns <pre>none
</pre>
* \note <pre>GetPort is often used to save the value of the current GrafPort before
activating a different one. See SetPort for an example.
You may prefer to access the global variable thePort directly:
GetPort ( &savePort );
... is synonymous with ...
savePort = thePort;
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   not available
*    \carbon_lib        not available
*    \mac_os_x         not available
*/
  void *
  GetPortNativeWindow(GrafPtr macPort);

  /**
   *  GetNativeWindowPort()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  GrafPtr
  GetNativeWindowPort(void *nativeWindow);

  /**
   *  MacRegionToNativeRegion()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void *
  MacRegionToNativeRegion(RgnHandle macRegion);

  /**
   *  NativeRegionToMacRegion()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  RgnHandle
  NativeRegionToMacRegion(void *nativeRegion);

#endif /* CALL_NOT_IN_CARBON */

#endif /* !TARGET_OS_MAC */

#if TARGET_OS_WIN32
#if CALL_NOT_IN_CARBON
  /**
   *  GetPortHWND()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void *
  GetPortHWND(GrafPtr port);

  /**
   *  GetHWNDPort()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  GrafPtr
  GetHWNDPort(void *theHWND);

#define GetPortHWND(port) (HWND) GetPortNativeWindow(port)
#define GetHWNDPort(theHWND) GetNativeWindowPort(theHWND)
  /**
   *  GetPortHDC()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void *
  GetPortHDC(GrafPtr port);

  /**
   *  GetPortHBITMAP()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void *
  GetPortHBITMAP(GrafPtr port);

  /**
   *  GetPortHPALETTE()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void *
  GetPortHPALETTE(GrafPtr port);

  /**
   *  GetPortHFONT()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void *
  GetPortHFONT(GrafPtr port);

  /**
   *  GetDIBFromPICT()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void *
  GetDIBFromPICT(PicHandle hPict);

  /**
   *  GetPICTFromDIB()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  PicHandle
  GetPICTFromDIB(void *h);

#endif /* CALL_NOT_IN_CARBON */

#endif /* TARGET_OS_WIN32 */

/**
 *  [Mac]SetPort()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacSetPort SetPort
#endif
  void
  MacSetPort(GrafPtr port);

  /**
   *  GetPort()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  GetPort(GrafPtr *port);

  /**
   *  QDSwapPort()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.5 and later
   *    \mac_os_x         in version 10.1 and later
   */
  Boolean
  QDSwapPort(CGrafPtr inNewPort, CGrafPtr *outOldPort);

  /**
  \brief Set the device field for a GrafPort

  <pre>GrafDevice is used in communications between Quickdraw and the Font
Manager. It sets device-specific information that affects the way characters
are drawn.
theDevice is a device specific value. It is broken into 2 bytes as follows:
high byte device driver reference number (always negative)
low byte device-dependent modifier code
</pre>
* \returns <pre>none
</pre>
* \note <pre>This stores theDevice  into the device field of the current GrafPort . You
will not use this function in normal applications.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  GrafDevice(short device);

  /**
  \brief Assigns a new bit map to the active GrafPort

  <pre>SetPortBits replaces the portBits field of the active GrafPort with a new
value, effectively changing the entire contents of the port.
</pre>
* \returns <pre>none
</pre>
* \note <pre>SetPortBits is useful for performing off-screen drawing. For instance,
you can use a series of Quickdraw calls to create an image in an off-screen
memory buffer, then use CopyBits to copy the bit-mapped image into the
normal screen.
Be sure that newBitMap  is fully prepared before using this call; that is,
the memory for the bit-image has been allocated and the baseAddr ,
rowBytes , and bounds fields have been set up.
Note that BitMap.rowBytes must be an even number and that it must be as
large or larger, in bits, than the width of the BitMap.bounds. The total
amount of memory needed for the off-screen bitMap is the product of the
height of the rectangle times the bytes-per-row. Here's a formula that
performs the calculation:
rectHigh = bounds.bottom - bounds.top;
rectWide = bounds.right - bounds.left;
rowBytes = ((rectWide -1) / 16) + 1) * 2;
buffSize = rowBytes * rectHigh; /* size in bytes */
The third line above correctly adjusts for the required word alignment.
Example
#include < Quickdraw.h >
#include < Memory.h >
OffScreenDraw( short rWide, short rHigh, Rect rDest )
// rWide, rHigh; size of off-screen rectangle
// rDest; on-screen destination */
{
  BitMap saveBits;
  BitMap tempBits;
  short bytesPerRow;
  saveBits = thePort->portBits; /* save current */
  /* now create an off-screen "canvas" */
  bytesPerRow = (((rWide - 1) / 16) + 1) * 2;
  tempBits.baseAddr = (QDPtr)NewPtr(bytesPerRow * rHigh);
  tempBits.rowBytes = bytesPerRow;
  SetRect(&tempBits.bounds, 0, 0, rWide, rHigh);
  </ pre>
              * \copyright THINK Reference © 1991 - 1992 Symantec Corporation

                                                        *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
          *    \carbon_lib in CarbonLib 1.0 and
      later
          *    \mac_os_x in version 10.0 and
      later
              * /
          void
          SetPortBits(const BitMap *bm);

  /**
  \brief Change height and width of current GrafPort

  <pre>PortSize modifies the width and height of the current GrafPort 's portRect .
It is normally called by the Window Manager for window-sizing functions.
newWidth and . . .
newHeight are the desired width and height for the portRect.
</pre>
* \returns <pre>none
</pre>
* \note <pre>This is a simple way to extend the size of the current port's portRect - the
active area of the current GrafPort .
The portRect.top and portRect.left fields stay the same. The portRect.right
and portRect.bottom change to reflect the desired newWidth  and newHeight .
Note that this does not affect other fields of the GrafPort ; drawing continues
to be clipped to the intersection of portRect , visRgn, and clipRgn.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  PortSize(short width, short height);

  /**
  \brief Change position of top-left corner of portRect

  <pre>MovePortTo repositions the portRect of the current GrafPort . It is used by
the Window Manager to reposition windows.
leftGlobal and . . .
topGlobal are the desired coordinates for the top and left fields of the
GrafPort 's portRect .
</pre>
* \returns <pre>none
</pre>
* \note <pre>This changes the position at which subsequent drawing will appear for the
active GrafPort . It effectively moves the active area of the GrafPort by
adding offsets to all fields of the portRect such that the top-left corner is
moved to the global coordinate pair leftGlobal , topGlobal . The height and
width of the portRect remain the same and the local coordinate system is not
changed.
As with PortSize , this does not affect other fields of the GrafPort ;
drawing continues to be clipped to the intersection of portRect , visRgn, and
clipRgn.
Unlike SetOrigin , this has no effect on the local coordinate system. It
moves the port to a different part of the BitMap.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  MovePortTo(short leftGlobal, short topGlobal);

  /**
   *  SetOrigin()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  SetOrigin(short h, short v);

  /**
   *  SetClip()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  SetClip(RgnHandle rgn);

  /**
   *  GetClip()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  GetClip(RgnHandle rgn);

  /**
   *  ClipRect()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ClipRect(const Rect *r);

  /**
   *  BackPat()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  BackPat(const Pattern *pat);

  /**
  \brief Initialize cursor to the standard arrow

  <pre>InitCursor sets the cursor shape to the standard arrow cursor and sets the
cursor level to 0, making it visible. It is normally called once, in the early
part of a program.
</pre>
* \returns <pre>none
</pre>
* \note <pre>The 68-byte Cursor structure for the standard arrow cursor can be found
in the Quickdraw data area. Its symbolic name is arrow.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  InitCursor(void);

/**
 *  [Mac]SetCursor()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacSetCursor SetCursor
#endif
    void
    MacSetCursor(const Cursor *crsr);

    /**
    \brief Remove the mouse cursor from the screen

    <pre>
* \note <pre>Each use of HideCursor must be balanced with a subsequent call to
ShowCursor .
This call decrements the cursor level: the cursor level is set to 0 when you
call InitCursor , and is decremented by each call to HideCursor and
incremented by each call to ShowCursor . It is visible only when the
cursor level is at 0.
An alternative to this call, ShieldCursor , hides the cursor only if it is
currently positioned within a specified rectangle.
A related function, ObscureCursor , hides the cursor until the mouse is
moved.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    void
    HideCursor(void);

/**
 *  [Mac]ShowCursor()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacShowCursor ShowCursor
#endif
    void
    MacShowCursor(void);

    /**
    \brief Hide cursor until mouse moves



*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    void
    ObscureCursor(void);

    /**
    \brief Make subsequent pen motion invisible

    <pre>HidePen decrements the "pen level". If the level is set to a value other than
0, the pen is hidden and subsequent draw operations are not visible.
</pre>
* \returns <pre>none
</pre>
* \note <pre>HidePen manipulates the pnVis field of the current GrafPort . Using
HidePen decrements the field and ShowPen increments it. When pnVis
is not equal 0, then the pen is hidden and drawing functions ( LineTo,
FrameRect , etc.) do not affect the BitMap. The pnVis field is set to 0
when the GrafPort is initialized.
The decrement/increment system makes it easy to nest drawing functions.
Always balance a HidePen call with ShowPen , and vice versa.
You can get the current "pen level" by reading the field directly from the
GrafPort structure. Note that it is not a Boolean field; the pen is visible
only when pnVis==0.
The OpenRgn , OpenPicture , and OpenPoly functions automatically call
HidePen so, by default, subsequent drawing activities are hidden.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    void
    HidePen(void);

    /**
    \brief Balance a previous HidePen ; make pen visible

    <pre>HidePen decrements the field and ShowPen increments it. When the
pnVis field is not equal 0, the pen is hidden and drawing functions ( LineTo,
FrameRect , etc.) do not affect the bitMap. The pnVis field is set to 0
(visible) when the GrafPort is initialized.
The decrement/increment system makes it easy to nest drawing functions.
Always balance a HidePen call with ShowPen , and vice versa.
You can get the current "pen level" by reading the pnVis field directly from
the GrafPort structure. Note that it is not a Boolean field; the pen is visible
only when pnVis == 0.
The CloseRgn , ClosePicture , and ClosePoly functions automatically
call ShowPen to balance the previous automatic call to HidePen .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    void
    ShowPen(void);

    /**
    \brief Obtain current pen position

    <pre>GetPen obtains the current pen position, in local coordinates.
penPtis the address of a 4-byte Point structure. Upon return, it will
contain the pen position of the current GrafPort , in local coordinates.
</pre>
* \returns <pre>none
</pre>
* \note <pre>This stores the Point into a local variable, e.g.:
PointthePt;
GetPen( &thePt );
You can obtain this and other pen-related information via GetPenState .
You can position the pen via MoveTo .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
    void
        GetPen(Point * pt);

    /**
    \brief Obtain current location, size, and mode of pen

    <pre>GetPenState fills a structure with pen-related information, including the
pen location, size, transfer mode, and pattern. It is useful in writing nested
drawing functions.
thePnState is the address of an 18-byte PenState structure. Upon return, the
structure is filled with information about the pen of the current
GrafPort .
</pre>
* \returns <pre>none
</pre>
* \note <pre>The PenState structure receives information copied directly from the
current GrafPort ; pnLoc, pnSize, pnMode, and pnPat.
Nested drawing procedures can use this function to obtain the current
status of the pen, in order to restore the state later. This may be coupled
with ShowPen ...HidePen to fully implement invisible nesting.
Example
#include < Quickdraw.h >
DrawSomething()
{
PenState savePenState;
GetPenState ( &savePenState ); /* save current state */
    ShowPen(); /* we want pen to be visible */
    /* ...draw some figure here which may change the state... */
    SetPenState(&savePenState); /* restore the pen's visible state */
  }
  </ pre>
              * \copyright THINK Reference © 1991 - 1992 Symantec Corporation

                                                        *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
          *    \carbon_lib in CarbonLib 1.0 and
      later
          *    \mac_os_x in version 10.0 and
      later
              * /
          void
          GetPenState(PenState *pnState);

  /**
  \brief Set the pen location, size, pattern and mode

  <pre>SetPenState sets the location, size, pattern and transfer mode of the pen of
the current GrafPort . It is typically used to restore the pen characteristics
after they were saved via a prior call to GetPenState .
</pre>
* \returns <pre>none
</pre>
* \note <pre>You can reset the pen characteristics to their initial state via
PenNormal .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  SetPenState(const PenState *pnState);

  /**
  \brief Set dimensions of pen for current GrafPort

  <pre>PenSize selects the height and width, in pixels, of the graphics pen for the
current GrafPort . The initial pen size is (1,1).
wideand . . .
highare the desired width and height of the pen. A setting of (0,0) - or
setting either parameter less than 0 - makes the pen invisible
</pre>
* \returns <pre>none
</pre>
* \note <pre>The wide and high values are stored in pnSize field of the current
GrafPort structure, except that if either value is less than 0, then both
parts of pnSize are set to 0, making the pen invisible.
You can also set the pen size and other pen-related parameters via the
SetPenState function. You can may obtain the size of the pen by accessing
the pnSize field of the current GrafPort ; e.g.:
short width, height;
width = thePort -> pnSize.h;
height = thePort -> pnSize.v;
You can obtain this and related information via GetPenState .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  PenSize(short width, short height);

  /**
  \brief Set the graphics pen pattern transfer mode

  <pre>PenMode selects the pattern transfer mode to be used in pen drawing and
painting operations.
newPnMode is a short and may be one of the following constants defined in
Quickdraw.h :
patCopy 8overwrite background entirely
patOr9overwrite where pattern is black
patXor10invert where pattern and bkgd are both black
patBic11force white where pattern is black
notPatCopy 12invert pattern, then patCopy
notPatOr 13invert pattern, then patOr
notPatXor 14invert pattern, then patXor
notPatBic 15invert pattern, then patBic
</pre>
* \returns <pre>none
</pre>
* \note <pre>This function modifies the pnMode field of the current GrafPort structure.
It affects all drawing operations such as LineTo and FrameRect , as well
as painting operations such as PaintOval , PaintRoundRect , etc.
See Transfer Modes for a graphic depiction of the effect of the various
pen modes.
You can obtain the current setting by accessing the pnMode field of a
GrafPort :
curPnMode = thePort->pnMode;
This function does not affect how text is drawn. Use TextMode to modify
the text-drawing pen's transfer mode.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  PenMode(short mode);

  /**
   *  PenPat()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  PenPat(const Pattern *pat);

  /**
   *  PenNormal()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  PenNormal(void);

  /**
  \brief Set pen location without drawing

  <pre>MoveTo moves the pen to the specified location, in local coordinates. This
does no drawing.
horizand . . .
vertare a location in local coordinates of the current GrafPort .
</pre>
* \returns <pre>none
</pre>
* \note <pre>The pen is repositioned at the selected point without performing any
drawing. The position is "absolute" as it relates to the origin of the current
GrafPort . Use Move to move the pen to a position relative to its current
position.
Use Line or LineTo to draw a line as the pen is moved.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  MoveTo(short h, short v);

  /**
  \brief the pen relative to its current location

  <pre>Move moves the pen a specified distance from its current location. It does not
perform any drawing.
distHoriz is the distance, in pixels, to move the pen horizontally. Positive
values move to the right; negative to the left.
distVert is the distance, in pixels, to move the pen vertically. Positive
values move down; negative move up.
</pre>
* \returns <pre>none
</pre>
* \note <pre>MoveTo is functionally identical to:
MoveTo ( thePort->pnLoc.h+distHoriz , thePort->pnLoc.v+distVert );
This does not do any drawing. Use Line or LineTo draw as the pen is
moved.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  Move(short dh, short dv);

/**
 *  [Mac]LineTo()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacLineTo LineTo
#endif
  void
  MacLineTo(short h, short v);

  /**
   *  Line()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  Line(short dh, short dv);

  /**
   *  ForeColor()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ForeColor(long color);

  /**
   *  BackColor()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  BackColor(long color);

  /**
  \brief Select color plane for subsequent drawing

  <pre>ColorBit selects the "color plane" to which Quickdraw should direct
subsequent drawing operations. This function is part of the "old model"
Quickdraw color support.
whichPlane specifies the plane number. Black-and-white devices have only one
color plane (plane 0). Quickdraw supports drawing to devices that
can interpret up to 32 planes of color information.
</pre>
* \returns <pre>none
</pre>
* \note <pre>This sets the value of the colrBit field of the current GrafPort structure.
It is used for drawing in color while remaining compatible with pre-MacII
Macs. It may also be used in sophisticated applications for creating overlays.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  ColorBit(short whichBit);

/**
 *  [Mac]SetRect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacSetRect SetRect
#endif
  void
  MacSetRect(Rect *r, short left, short top, short right, short bottom);

/**
 *  [Mac]OffsetRect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacOffsetRect OffsetRect
#endif
  void
  MacOffsetRect(Rect *r, short dh, short dv);

/**
 *  [Mac]InsetRect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacInsetRect InsetRect
#endif
  void
  MacInsetRect(Rect *r, short dh, short dv);

  /**
  \brief Get the intersection of two rectangles; check for overlap
  \param    *rect1 addresses of two Rect ...
\param    *rect2 ... structures to intersect
  <pre>SectRect checks to see if two rectangles share any points in common and
obtains the coordinates of the intersecting rectangle
rect1and . . .
rect2are addresses of two 8-byte Rect structures. They should use the
same coordinate system.
resultRect is the address of a third Rect structure. Upon return, it will contain
the coordinates of the intersection of rect1 and rect2 . If rect1 and
rect2 share no common points, this returns as the empty rectangle
(0,0)(0,0).
</pre>
* \returns <pre>a Boolean value indicating whether or not rect1 and rect2 share
any common points. It is one of:
FALSENo overlap
TRUESome overlap; resultRect  is non-empty.
</pre>
* \note <pre>The figures below illustrate:

In the figure on the left, the intersection of rectangles A and B is shown in
black, labeled as rectangle C. The call to SectRect will return TRUE, and
resultRect  will contain the coordinates of rectangle C.
The figure on the right illustrates an important concept: a shared border
or a single shared point are not considered as part of the mathematical
intersection of two rectangles. Rectangles D and E are right next to each
other and share a common border.  However, their "overlap" area is a
single mathematical line, enclosing no bits of the bitMap. The call to
SectRect would return FALSE, and resultRect  would be set to
(0,0)(0,0).
It is OK to specify resultRect  as the same rectangle as either of rect1 or
rect2 . For instance, the following line would find the intersection of
rectangles A and B, and store its coordinates into rectangle A, overwriting
the original value.
SectRect ( &rA, &rB, &rA );
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  Boolean
  SectRect(const Rect *src1, const Rect *src2, Rect *dstRect);

/**
 *  [Mac]UnionRect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacUnionRect UnionRect
#endif
  void
  MacUnionRect(const Rect *src1, const Rect *src2, Rect *dstRect);

/**
 *  [Mac]EqualRect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacEqualRect EqualRect
#endif
  Boolean
  MacEqualRect(const Rect *rect1, const Rect *rect2);

  /**
  \brief Determine if a rectangle is empty

  <pre>EmptyRect tests to see if a rectangle is empty; i.e., if the bottom border is
less than or equal to the top, or the right border is less than or equal to the
left.
theRectis the address of an 8-byte Rect structure.
</pre>
* \returns <pre>a Boolean indicating whether the rectangle is empty . It is one of:
FALSENot empty; encloses at least one pixel
TRUEEmpty
</pre>
* \note <pre>This is functionally equivalent to the following equality test:
( (theRect.bottom <= theRect.top) || (theRect.right <= theRect.left) )
When a Toolbox function returns "the empty rectangle", it returns a
rectangle with borders (0,0)(0,0). However, in this function, the
meaning is broader, including all rectangles not enclosing any pixels.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  Boolean
  EmptyRect(const Rect *r);

/**
 *  [Mac]FrameRect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacFrameRect FrameRect
#endif
  void
  MacFrameRect(const Rect *r);

  /**
   *  PaintRect()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  PaintRect(const Rect *r);

  /**
   *  EraseRect()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  EraseRect(const Rect *r);

/**
 *  [Mac]InvertRect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacInvertRect InvertRect
#endif
  void
  MacInvertRect(const Rect *r);

/**
 *  [Mac]FillRect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacFillRect FillRect
#endif
  void
  MacFillRect(const Rect *r, const Pattern *pat);

  /**
   *  FrameOval()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  FrameOval(const Rect *r);

  /**
   *  PaintOval()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  PaintOval(const Rect *r);

  /**
   *  EraseOval()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  EraseOval(const Rect *r);

  /**
   *  InvertOval()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvertOval(const Rect *r);

  /**
   *  FillOval()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  FillOval(const Rect *r, const Pattern *pat);

  /**
   *  FrameRoundRect()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  FrameRoundRect(const Rect *r, short ovalWidth, short ovalHeight);

  /**
   *  PaintRoundRect()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  PaintRoundRect(const Rect *r, short ovalWidth, short ovalHeight);

  /**
   *  EraseRoundRect()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  EraseRoundRect(const Rect *r, short ovalWidth, short ovalHeight);

  /**
   *  InvertRoundRect()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvertRoundRect(const Rect *r, short ovalWidth, short ovalHeight);

  /**
   *  FillRoundRect()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  FillRoundRect(const Rect *r, short ovalWidth, short ovalHeight,
                const Pattern *pat);

  /**
   *  FrameArc()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  FrameArc(const Rect *r, short startAngle, short arcAngle);

  /**
   *  PaintArc()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  PaintArc(const Rect *r, short startAngle, short arcAngle);

  /**
   *  EraseArc()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  EraseArc(const Rect *r, short startAngle, short arcAngle);

  /**
   *  InvertArc()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvertArc(const Rect *r, short startAngle, short arcAngle);

  /**
   *  FillArc()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  FillArc(const Rect *r, short startAngle, short arcAngle, const Pattern *pat);

  /**
   *  NewRgn()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  RgnHandle
  NewRgn(void);

  /**
   *  OpenRgn()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  OpenRgn(void);

  /**
   *  CloseRgn()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  CloseRgn(RgnHandle dstRgn);

  /**
   *  BitMapToRegion()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  BitMapToRegion(RgnHandle region, const BitMap *bMap);

  /**
   *  HandleToRgn()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  HandleToRgn(Handle oldRegion, RgnHandle region);

  /**
   *  RgnToHandle()
   *
   *  Availability:
   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.1 and later
   */
  void
  RgnToHandle(RgnHandle region, Handle flattenedRgnDataHdl);

  /**
   *  DisposeRgn()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeRgn(RgnHandle rgn);

/**
 *  [Mac]CopyRgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacCopyRgn CopyRgn
#endif
  void
  MacCopyRgn(RgnHandle srcRgn, RgnHandle dstRgn);

  /**
   *  SetEmptyRgn()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  SetEmptyRgn(RgnHandle rgn);

/**
 *  [Mac]SetRectRgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacSetRectRgn SetRectRgn
#endif
  void
  MacSetRectRgn(RgnHandle rgn, short left, short top, short right, short bottom);

  /**
   *  RectRgn()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  RectRgn(RgnHandle rgn, const Rect *r);

/**
 *  [Mac]OffsetRgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacOffsetRgn OffsetRgn
#endif
  void
  MacOffsetRgn(RgnHandle rgn, short dh, short dv);

  /**
   *  InsetRgn()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InsetRgn(RgnHandle rgn, short dh, short dv);

  /**
   *  SectRgn()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  SectRgn(RgnHandle srcRgnA, RgnHandle srcRgnB, RgnHandle dstRgn);

/**
 *  [Mac]UnionRgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacUnionRgn UnionRgn
#endif
  void
  MacUnionRgn(RgnHandle srcRgnA, RgnHandle srcRgnB, RgnHandle dstRgn);

  /**
   *  DiffRgn()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DiffRgn(RgnHandle srcRgnA, RgnHandle srcRgnB, RgnHandle dstRgn);

/**
 *  [Mac]XorRgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacXorRgn XorRgn
#endif
  void
  MacXorRgn(RgnHandle srcRgnA, RgnHandle srcRgnB, RgnHandle dstRgn);

  /**
  \brief Check if a rectangle intersects a region

  <pre>RectInRgn returns an indication of whether any pixel enclosed by a specified
rectangle intersects with a specified region.
theRectis the address of an 8-byte Rect structure, defined in local or global
coordinates.
theRgnis a handle to a region. It should be defined in the same coordinate
system as theRect .
</pre>
* \returns <pre>a Boolean value indicating whether the rectangle intersects with the
region. It is one of:
FALSENo intersection
TRUEAt least one pixel is in both areas
</pre>
* \note <pre>Remember that the outlines of theRect and theRgn are infinitely thin, so
just sharing a line or point does not constitute an intersection. This
returns TRUE when a pixel (the dot below and to the right of the point
coordinates) is enclosed by both areas.
An error in the early ROMs occasionally causes this function to incorrectly
return TRUE when the enclosing coordinates overlap (even though they do
not share any pixels). You may need to convert the rectangle to a region
(RectRgn ) and intersect the regions ( SectRgn ) to be real sure of the
answer here. Later versions of the ROMs work correctly.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  Boolean
  RectInRgn(const Rect *r, RgnHandle rgn);

/**
 *  [Mac]EqualRgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacEqualRgn EqualRgn
#endif
  Boolean
  MacEqualRgn(RgnHandle rgnA, RgnHandle rgnB);

  /**
  \brief Determine if a Region is empty

  <pre>EmptyRgn returns an indication of whether a region is empty.
theRgnis the handle of a region, in local or global coordinates.
</pre>
* \returns <pre>a Boolean value indicating whether the region is empty. It is one of:
FALSENot empty, encloses at least one pixel
TRUEEmpty
</pre>
* \note <pre>Use this after performing region calculations. For instance:
SectRgn ( srcRgnA, srcRgnB, destRgn );
if ( EmptyRgn ( destRgn ) ) {
.
. ... no intersection ...
.
}
This is also useful after InsetRgn to see if the region has been shrunk
infinitely small. Or, you might use this to check up on GrafPort structure
fields such as visRgn or clipRgn.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  Boolean
  EmptyRgn(RgnHandle rgn);

/**
 *  [Mac]FrameRgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacFrameRgn FrameRgn
#endif
  void
  MacFrameRgn(RgnHandle rgn);

/**
 *  [Mac]PaintRgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacPaintRgn PaintRgn
#endif
  void
  MacPaintRgn(RgnHandle rgn);

  /**
   *  EraseRgn()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  EraseRgn(RgnHandle rgn);

/**
 *  [Mac]InvertRgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacInvertRgn InvertRgn
#endif
  void
  MacInvertRgn(RgnHandle rgn);

/**
 *  [Mac]FillRgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacFillRgn FillRgn
#endif
  void
  MacFillRgn(RgnHandle rgn, const Pattern *pat);

  /**
   *  ScrollRect()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ScrollRect(const Rect *r, short dh, short dv, RgnHandle updateRgn);

  /**
   *  CopyBits()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  CopyBits(const BitMap *srcBits, const BitMap *dstBits, const Rect *srcRect,
           const Rect *dstRect, short mode,
           RgnHandle maskRgn) /* can be NULL */;

  /**
  \brief Calculate a mask for use in CopyMask
  \param    srcPtr address within a BitMap of place to start calculating
\param    destPtr address within a BitMap of where to store 1s and 0s
  <pre>SeedFill examines a portion of a source bitmap and fills a portion of a
destination bitMap with 1s. It finds an enclosed area surrounding a specified
point in the source, and floods that area in the destination (as in the lasso tool
of many paint programs) with 1s (black paint).  Use this function as one step
in implementing a "paint bucket" tool.
srcPtris the address of a 16-bit word inside a bitMap data area. SeedFill
will use this as if it were the upper left corner of a rectangle, as
defined by height and wrdsWide .  It will examine this implied
rectangle as it floods portions of the destination bitMap.
destPtris the address of a 16-bit word inside a bitMap data area. SeedFill
will use this as if it were the upper left corner of a rectangle, as
defined by height and wrdsWide . It will fill all or part of this
"rectangle" with 1s.
Note: Both srcPtr and destPtr must point to even (word) addresses.
srcRowBytes and . . .
destRowBytes are the widths of the BitMap into which srcPtr and destPtr,
respectively point; i.e., the function will add this value to its
current address pointer to move "down one line" in the bitMap.
heightis the height, in pixels, of both the source data area and the
destination area.
wrdsWide is the width, in 16-bit words , of both the source and destination
data area.
seedH and...
seedVidentify the point to start flooding. These are offsets, in pixels,
from the boundary of the implied rectangle defined by srcPtr ,
height, and wrdsWide .
</pre>
* \returns <pre>none
</pre>
* \note <pre>Use SeedFill to flood an area of a destination bitMap with black paint
(i.e., 1s). The flooded area will match the inside and boundary of a section
of the source that is enclosed by black pixels. Note that destPtr and srcPtr
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  SeedFill(const void *srcPtr, void *dstPtr, short srcRow, short dstRow,
           short height, short words, short seedH, short seedV);

  /**
   *  CalcMask()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  CalcMask(const void *srcPtr, void *dstPtr, short srcRow, short dstRow,
           short height, short words);

  /**
   *  CopyMask()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  CopyMask(const BitMap *srcBits, const BitMap *maskBits, const BitMap *dstBits,
           const Rect *srcRect, const Rect *maskRect, const Rect *dstRect);

  /**
   *  OpenPicture()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  PicHandle
  OpenPicture(const Rect *picFrame);

  /**
   *  PicComment()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  PicComment(short kind, short dataSize, Handle dataHandle);

  /**
   *  ClosePicture()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ClosePicture(void);

  /**
   *  DrawPicture()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DrawPicture(PicHandle myPicture, const Rect *dstRect);

  /**
   *  KillPicture()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  KillPicture(PicHandle myPicture);

  /**
   *  OpenPoly()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  PolyHandle
  OpenPoly(void);

  /**
   *  ClosePoly()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ClosePoly(void);

  /**
   *  KillPoly()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  KillPoly(PolyHandle poly);

  /**
  \brief Move a polygon

  <pre>OffsetPoly modifies a polygon's definition, moving it in any direction on the
coordinate plane. Note that this does not have any visible effect on the screen,
until such time as the polygon is drawn or filled.
thePoly is a handle leading to a variable-length Polygon structure. It is
typically a value obtained via OpenPoly .
distHoriz specifies the horizontal distance, in pixels, to move the polygon.
Positive values move to the right; negative to the left.
distVert specifies the vertical distance, in pixels, to move the polygon.
Positive values move downward; negative upward.
</pre>
* \returns <pre>none
</pre>
* \note <pre>The polygon retains its shape and size. Use MapPoly to shrink or expand
the polygon.
This is an especially efficient operation, since it changes only the value in
the polyBBox field of the Polygon structure; all endpoints that make up the
bulk of the data are stored relative to first point.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  OffsetPoly(PolyHandle poly, short dh, short dv);

  /**
   *  FramePoly()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  FramePoly(PolyHandle poly);

  /**
   *  PaintPoly()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  PaintPoly(PolyHandle poly);

  /**
   *  ErasePoly()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  ErasePoly(PolyHandle poly);

  /**
   *  InvertPoly()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvertPoly(PolyHandle poly);

  /**
   *  FillPoly()
   *
   *  Availability:
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  FillPoly(PolyHandle poly, const Pattern *pat);

  /**
  \brief Pack horizontal and vertical coordinates into Point

  <pre>SetPt stores two coordinate values into a Point structure.
thePoint is the address of a 4-byte Point structure. Upon return, it will
contain the coordinates specified by horiz and vert .
horizand . . .
vertare coordinate values, ranging from -32767 to 32767. Negative
values are upward and toward the left; positive values are downward
and toward the right.
</pre>
* \returns <pre>none
</pre>
* \note <pre>SetPt is functionally equivalent to the faster:
thePoint-> h = horiz;
thePoint-> v = vert;
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  void
  SetPt(Point *pt, short h, short v);

  /**
  \brief Obtain global (screen) value of local point

  <pre>LocalToGlobal converts the coordinates of a local point (relative to the
current GrafPort origin) to global (screen) coordinates. It can then be
compared to other global points or converted to the local coordinates of a
different GrafPort .
thePoint is the address of a 4-byte Point structure, expressed in coordinates
of the current GrafPort . Upon return, it will contain the coordinates
of that same position, expressed to the global, screen coordinates.
</pre>
* \returns <pre>none
</pre>
* \note <pre>The result of the conversion is based relative to coordinate (0,0) of the
device's BitMap; typically the screen.
To convert the coordinates of a rectangle from local to global, you can apply
this call to both corners; e.g.:
RecttheRect;
LocalToGlobal ( & topleft(theRect);
LocalToGlobal ( &.botRight(theRect) );
Rectangles and other graphic elements (regions and polygons) can be
converted to the global coordinate system via a 3-step sequence:
1Use LocalToGlobal to obtain the global coordinates of one corner of a
local item.
2Use SubPt or DeltaPoint to determine the difference between the local
and global coordinate systems.
3Use OffsetXxx to reposition the item.
For instance, the following sequence converts a local Polygon to global
coordinates:
Point tmpPt,localPt;
PolyHandle thePoly;
tmpPt=localPt=topLeft( (*thePoly)-> polyBBox );/* get corner */
  LocalToGlobal(&tmpPt);                 /* convert to global */
  SubPt(localPt, &tmpPt);                /* find difference */
  OffsetPoly(thePoly, tmpPt.h, tmpPt.v); /* move the item */
  </ pre>
              * \copyright THINK Reference © 1991 - 1992 Symantec Corporation

                                                        *    \non_carbon_cfm in InterfaceLib 7.1 and
      later
          *    \carbon_lib in CarbonLib 1.0 and
      later
          *    \mac_os_x in version 10.0 and
      later
              * /
          void
          LocalToGlobal(Point *pt);

  /**
  \brief Obtain local coordinates of global point

  <pre>GlobalToLocal converts a point from global (screen) coordinates to values
expressed in coordinates of the current GrafPort . It is used to obtain the local
address of a mouse-down event and as a step in converting between coordinates
of two different grafPorts.
thePoint is the address of a 4-byte Point structure, expressed in global
(screen) coordinates. Upon return, it will contain the coordinates of
that same position, expressed in the coordinate system of the current
GrafPort .
</pre>
* \returns <pre>none
</pre>
* \note <pre>The specified Point is converted, in place. Upon return, it is the same
physical location, expressed in global coordinates.
For instance, mouse-down events are reported in global coordinates, but
TextEdit and the Control Manager functions expect local (window-relative)
coordinates. Thus, a typical sequence may include:
EventRecord myEvent;
ControlHandle myCtl;
short ctlCode;
GetNextEvent ( everyEvent , &myEvent );
if ( myEvent.what ) == mouseDown {
GlobalToLocal ( &myEvent. where );/* get local equivalent */
  ctlCode = FindControl(myEvent.where, myWindow, &myCtl);
  if (ctlCode == inThumb)
  /*. . . etc. . . */
}
This function is also used as an intermediate step in converting between
    coordinates of two different grafPorts(e.g., windows)
        .For instance,
    to
    convert the position of rectangle theRect from the coordinates of windowA
    to the coordinates of windowB : SetPort(windowA);
LocalToGlobal(&topLeft(theRect));
LocalToGlobal(&botRight(theRect));
SetPort(windowB);
GlobalToLocal(&topLeft(theRect));
GlobalToLocal(&botRight(theRect));
To convert between the coordinates of regions and polygons, calculate the</ pre>
                                                                        * \copyright THINK Reference © 1991 - 1992 Symantec Corporation

                                                                                                                  *    \non_carbon_cfm in InterfaceLib 7.1 and
                                                                later
                                                                    *    \carbon_lib in CarbonLib 1.0 and
                                                                later
                                                                    *    \mac_os_x in version 10.0 and
                                                                later
                                                                        * /
                                                                    void
                                                                    GlobalToLocal(Point *pt);

/**
\brief Obtain pseudo-random signed integer

<pre>Random generates and returns a different pseudo-random number each time
it is called. The return value ranges from -32767 to 32767.
</pre>
* \returns <pre>a signed integer; the next in a sequence of pseudo-random values,
uniformly distributed over the range -32767 to 32767.
</pre>
* \note <pre>To obtain a number within a selected range multiply the return value by
the range, divide by 65536, and add the desired minimum value. See the
Example, below.
The numbers are generated in a sequence based upon the starting, or "seed"
value, which is stored in the global 32-bit variable randSeed .
The seed is initialized to 1 by InitGraf . If you start a sequence by storing
a value in randSeed , you can restart the same sequence by setting randSeed
to the same value. A more typical operation is to start the sequence with
some relatively unguessable value, such as the system time:
GetDateTime ( &randSeed ); /* store 32-bit value in seed */
theRand = Random(); /* get a random number */
The Quickdraw global variable randSeed can also be used as a seed to start a
        pseudo -
    random sequence.Example
/* example function returns value between min and max */
#include < Quickdraw.h >
    unsigned short
    RangedRdm(unsigned short min, unsigned short max)
/* assume that min is less than max */
{
  unsigned qdRdm; /* treat return value as 0-65536 */
  long range, t;
  qdRdm = Random();
  range = max - min;
  t = (qdRdm * range) / 65536; /* now 0 <= t <= range */
  return (t + min);
}
</ pre>
            * \copyright THINK Reference © 1991 - 1992 Symantec Corporation

                                                      *    \non_carbon_cfm in InterfaceLib 7.1 and
    later
        *    \carbon_lib in CarbonLib 1.0 and
    later
        *    \mac_os_x in version 10.0 and
    later
            * /
        short
        Random(void);

/**
\brief Convert a string of hex digits to binary data
\param    destPtr generic pointer; address of any data type
<pre>StuffHex reads a pascal-style string of hexadecimal digits, converts them to
binary data and stores the result into any data type.
destPtris the address of any type of data object; typically the address of a
Pattern or Cursor, even a BitMap. Upon return, the memory
pointed to by destPtr will be overwritten with binary data.
hexString is the address of a Pascal-style string (a length-prefixed array of
characters). Following the length byte, all characters must be in the
range '0' to '9' and 'A' to 'F'.
</pre>
* \returns <pre>none
</pre>
* \note <pre>This call performs no range checking , so make sure that the buffer at
destPtr is large enough to receive all the binary data defined in hexString .
The destination buffer may need to be as large as 127 bytes.
This function can be useful during program development, but it is rarely
needed in a finished program - your compiler is capable of converting hex
digits into binary data. For instance, the sequence:
StuffHex ( &myPat, "\p0103070F1F3F7FFF" )
can be eliminated by defining the pattern at compile time; e.g.,
Pattern myPat = { 0x1, 0x3, 0x7, 0xF, 0x1F, 0x3F, 0x7F, 0xFF };
Furthermore, most objects that you might wish to pack with binary data
should probably be predefined and available as a program resource.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void StuffHex(void *thingPtr, ConstStr255Param s);

/**
 *  [Mac]GetPixel()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacGetPixel GetPixel
#endif
Boolean
MacGetPixel(short h, short v);

/**
\brief Resize coordinate pair to ratio of two rectangles

<pre>ScalePt converts each coordinate of a point to a value calculated as the ratio
of the sizes of two rectangles. You could use this function to scale an object
(such as a pen size or a character rectangle) to match the size of a smaller or
larger window.
thePoint is the address of the point to convert. Upon return, its horizontal
coordinates has been scaled by the ratio of the two rectangles' widths
and the vertical coordinates has been scaled relative to the heights. It
will never be set less than (1,1).
numerRect and . . .
denomRect are addresses of rectangles. Their location is irrelevant; their
widths and heights are used to calculate ratios, which are applied to
the coordinates of thePoint .
</pre>
* \returns <pre>none
</pre>
* \note <pre>Since a point is an undimensional object, you can't really scale it. The
ScalePt function treats thePoint as if it were the bottom-right corner of
a rectangle whose top-left corner is at (0,0). That imaginary rectangle is
scaled to the ratio of numerRect  divided by denomRect . This call is
functionally equivalent to:
numerWide = numerRect.right - numerRect.left;
denomWide = denomRect.right - denomRect.left;
numerHigh = numerRect.bottom - numerRect.top;
denomHigh = denomRect.bottom - denomRect.top;
thePoint.h = (thePoint.h * numerWide) / denomWide;
thePoint.v = (thePoint.v * numerHigh) / denomHigh;
Note: thePoint will never be set smaller than (1,1).
Use MapPt to perform the more common operation of finding the
coordinates of a point inside one rectangle that corresponds to a
similarly-located point within another.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void ScalePt(Point *pt, const Rect *srcRect, const Rect *dstRect);

/**
\brief Map point relative to two rectangles

<pre>MapPt maps a point within one rectangle to a similarly-located position in a
different rectangle. Use this to scale individual points of an object being moved
to a larger or smaller rectangle.
thePoint is the address of a 4-byte Point structure. On entry, it is the
coordinates of a point, relative to srcRect that you wish to convert;
upon return, it contains the coordinates of a point relative to the size
and position of destRect .
srcRect and . . .
destRect are the addresses of two 8-byte Rect structures.  For typical
operations, thePoint is an element of an object enclosed by srcRect .
It gets mapped to a similar position within destRect .
</pre>
* \returns <pre>none
</pre>
* \note <pre>This function is typically used to convert individual points of an object
(e.g., a "freehand" drawing) within one rectangle to similar positions
within a larger or smaller rectangle. Other tools exist to scale rectangles
(MapRect ), regions ( MapRgn ), and polygons ( MapPoly ).
For instance, a corner of srcRect will map exactly to the corresponding
corner of destRect ; similarly, the center of srcRect maps to the center of
destRect . Other points will be positioned at distances from the edges
relative to the ratio of the sizes of the rectangles.
srcRect destRect
It is OK if the two rectangles overlap, and thePoint need not be enclosed by
srcRect (in that case, its remapped position will be outside of destRect ).
This call is functionally equivalent to the long-winded:
h1=r1.bottom-r1.top; h2=r2.bottom - r2.top; /* calc heights */
w1 = r1.right - r1.left;
w2 = r2.right - r2.left;             /* and widths */
thePoint.h = (thePoint.h * w1) / w2; /* apply ratio of sizes */
</ pre>
            * \copyright THINK Reference © 1991 - 1992 Symantec Corporation

                                                      *    \non_carbon_cfm in InterfaceLib 7.1 and
    later
        *    \carbon_lib in CarbonLib 1.0 and
    later
        *    \mac_os_x in version 10.0 and
    later
            * /
        void
        MapPt(Point *pt, const Rect *srcRect, const Rect *dstRect);

/**
\brief Scale and reposition a rectangle

<pre>MapRect maps the corner points of a rectangle, converting them by a size
ratio and offset of two other rectangles. Use this to scale or reposition an
object that is being moved to a larger or smaller rectangle.
theRectis the address of an 8-byte Rect structure. On entry, it describes a
rectangle within srcRect that you wish to remap. Upon return, its
corner points have been recalculated relative to the size and position
of destRect .
srcRect and . . .
destRect are the addresses of two 8-byte Rect structures.  For typical
operations, theRect is an element of an object enclosed by srcRect .
It gets mapped to a similar position within destRect .
</pre>
* \returns <pre>none
</pre>
* \note <pre>Use this function to resize and reposition a rectangle that you wish to
expand or shrink as you move it from one rectangular area to another
(typically smaller or larger) one.
theRect is expanded or shrunk by the ratio of the sizes of srcRect and
destRect. It is moved to a similarly-located position within destRect . This
is a purely mathematical operation and has no effect on the screen until
theRect is subsequently drawn or filled.
This call is functionally equivalent to:
MapPt( & topleft(theRect), &srcRect, &destRect );
MapPt( & bottomRight(theRect), &srcRect, &destRect );
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void MapRect(Rect *r, const Rect *srcRect, const Rect *dstRect);

/**
 *  MapRgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void MapRgn(RgnHandle rgn, const Rect *srcRect, const Rect *dstRect);

/**
\brief Scale and reposition a polygon

<pre>MapPoly resizes and repositions a polygon, converting its coordinates by the
size-ratio and offset of two rectangles. Use this to scale and reposition a
polygon.
thePoly is a handle leading to a variable-length Polygon structure. On
entry, it describes a polygon within srcRect that you wish to remap.
Upon return, all its vertex coordinates have been recalculated
relative to the size and position of destRect .
srcRect and . . .
destRect are the addresses of two 8-byte Rect structures.  For typical
operations, thePoly is enclosed by srcRect . It gets mapped to a
similar position within destRect .
</pre>
* \returns <pre>none
</pre>
* \note <pre>Use this function to resize and reposition a polygon that you wish to expand
or shrink as you move it from one rectangular area to another (typically
smaller or larger) one.

srcRect destRect
thePoly is expanded or shrunk by the ratio of the sizes of srcRect and
destRect. It is moved to a similarly-located position within destRect . This
is a purely mathematical operation and has no effect on the screen unless
thePoly is subsequently drawn or filled.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void MapPoly(PolyHandle poly, const Rect *srcRect, const Rect *dstRect);

/**
\brief Set graphProcs field to point to custom routines

<pre>SetStdProcs stores the addresses of the standard Quickdraw procedures into
a structure intended to be used in a GrafPort .
ll_procs is the address of a 52-byte QDProcs structure. Upon return, all
fields of the structure have been set to contain the addresses of the
standard low-level routines used by Quickdraw.
</pre>
* \returns <pre>none
</pre>
* \note <pre>SetStdProcs is used by applications that want to intercept selected
low-level routines (e.g., the picture-comment handler) while continuing
to use the other standard routines.
Since Quickdraw lives up to its name, most applications won't need to
replace its code. If you do wish to install a custom Quickdraw function
handler (sometimes called a "bottleneck" routine), follow these steps:
•Create a function that accepts the same parameters in the same order as
one of Quickdraw's StdXxx functions.
•Open a GrafPort (OpenPort or NewWindow )
•Create a standard QDProcs structure by allocating it and then using
SetStdProcs to initialize it.
•Store the address of your custom procedure into the appropriate field of
the QDProcs structure.
•Store the address of your QDProcs structure into the grafProcs field of
the desired GrafPort .
Now, when your application invokes a Quickdraw function that passes
through the intercepted bottleneck, your custom handler will get control.
You need not replace all the functionality of a bottleneck-you may choose to
simply pre-process the parameters passed to you and then invoke the
original handler, as illustrated in the following example:
Example
#include < Quickdraw.h >
#define MY_COMMENT 1234
QDProcs myQDProcs; /* uninitialized data structure */
pascal short myCommentProc(void);             /* declare the function */
SetStdProcs(&myQDProcs);                      /* initialize with defaults */
myQDProcs.commentProc = (QDPtr)myCommentProc; /* change one proc */
thePort->grafProcs = &myQDProcs;              /* install the change */
</ pre>
            * \copyright THINK Reference © 1991 - 1992 Symantec Corporation

                                                      *    \non_carbon_cfm in InterfaceLib 7.1 and
    later
        *    \carbon_lib in CarbonLib 1.0 and
    later
        *    \mac_os_x in version 10.0 and
    later
            * /
        void
        SetStdProcs(QDProcs *procs);

/**
 *  StdRect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void StdRect(GrafVerb verb, const Rect *r);

/**
 *  StdRRect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void StdRRect(GrafVerb verb, const Rect *r, short ovalWidth, short ovalHeight);

/**
 *  StdOval()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void StdOval(GrafVerb verb, const Rect *r);

/**
 *  StdArc()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void StdArc(GrafVerb verb, const Rect *r, short startAngle, short arcAngle);

/**
 *  StdPoly()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void StdPoly(GrafVerb verb, PolyHandle poly);

/**
 *  StdRgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void StdRgn(GrafVerb verb, RgnHandle rgn);

/**
 *  StdBits()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void StdBits(const BitMap *srcBits, const Rect *srcRect, const Rect *dstRect,
             short mode, RgnHandle maskRgn);

/**
 *  StdComment()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void StdComment(short kind, short dataSize, Handle dataHandle);

/**
\brief The default Quickdraw  picture-retrieving routine
\param    destPtr where to store the picture definition data
<pre>
* \note <pre>Use StdGetPic only if your applicatin intercepts the Quickdraw
bottleneck routines (see SetStdProcs ).
This is a bottleneck routine that is frequently intercepted by application
programs. By creating a custom version of StdGetPic and StdPutPic that
is able to access a disk file, you can store and retrieve pictures larger than
the maximum limits set by Quickdraw.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void StdGetPic(void *dataPtr, short byteCount);

/**
 *  StdPutPic()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void StdPutPic(const void *dataPtr, short byteCount);

/**
 *  StdOpcode()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void StdOpcode(const Rect *fromRect, const Rect *toRect, UInt16 opcode,
               SInt16 version);

/**
\brief Add coordinates of two points

<pre>AddPt adds the coordinates of two Points, storing the result into the second.
srcPtis a 4-byte Point structure. Its low word is the horizontal
coordinate and its high word is the vertical coordinate.
destPtis the address of a 4-byte Point structure. Upon return, it will
contain the sums (srcPt.h+destPt.h) and (srcPt.v+destPt.v).
</pre>
* \returns <pre>none
</pre>
* \note <pre>AddPt is functionally equivalent to:
destPt.h += srcPt.h;
destPt.v += srcPt.v;
Use SubPt or DeltaPoint to calculate the difference between two Points.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void AddPt(Point src, Point *dst);

/**
\brief Check if two points are identical

<pre>EqualPt compares the coordinates of two points and returns an indication
whether they are identical. This function is used if you have no need
whatsoever of execution speed.
point1and . . .
point2are 4-byte Point structures.
</pre>
* \returns <pre>a Boolean indicating whether the points are identical. It is one of:
FALSENot the same
TRUEExactly the same
</pre>
* \note <pre>EqualPt can be used to make your code more readable. The sequence:
if (EqualPt ( point1, point2 ) {
... they are equal ...
}
is functionally equivalent to:
if ( (pt1.h == pt2.h) && (pt1.v==pt2.v) ) { /* compare shorts twice
*/
... they are equal...
}
or the more efficient : if (*(long *)&pt1 == *(long *)&pt2){/* compare longs once */
                                                            ... they are equal...} < / pre >
                        * \copyright THINK Reference © 1991 - 1992 Symantec Corporation

                                                                  *    \non_carbon_cfm in InterfaceLib 7.1 and
        later *    \carbon_lib in CarbonLib 1.0 and later *    \mac_os_x in version 10.0 and later * / Boolean EqualPt(Point pt1, Point pt2);

/**
 *  [Mac]PtInRect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacPtInRect PtInRect
#endif
Boolean
MacPtInRect(Point pt, const Rect *r);

/**
\brief Find smallest rectangle enclosing two points

<pre>Pt2Rect determines the coordinates of the smallest rectangle that will
enclose the pixels represented by two points.
pt1and . . .
pt2are any two 4-byte Point structures.
resultRect is the address of an 8-byte Rect structure. Upon return it will
contain the coordinates of a rectangle that encloses pt1 and pt2 .
</pre>
* \returns <pre>none
</pre>
* \note <pre>If pt1 or pt2 have the same horizontal or vertical coordinate resultRect
is set to the empty rectangle (0,0)(0,0).
The points may be in any order. The points are stored into the correct part
of the Rect structure; i.e., the highest vertical coordinate of either point is
stored as resultRect.top, and so forth.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void Pt2Rect(Point pt1, Point pt2, Rect *dstRect);

/**
\brief Obtain angle between point and rectangle center

<pre>PtToAngle determines an angular measure between the vertical center of a
rectangle and a specified point.
theRectis the address of an 8-byte Rect structure.
thePtis a point, in the same coordinate system as theRect .
angleis the address of an integer. Upon return, it will contain an angle
measured from a line extending from the center of theRect to the
middle of its top line. See the diagram, below.
</pre>
* \returns <pre>none
</pre>
* \note <pre>This can be used to obtain an angle value for use in any of the arc paint and
fill functions that require an angle parameter.
The angle is not a true mathematical angle in circular degrees; as with arc
and wedge functions, all angles are based on the corners of a rectangle as
shown:
Thus, the angles are distorted to match the shape of the rectangle. For
instance:

In the figures, both "angles" are 45 °, even though the one on the right is
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void PtToAngle(const Rect *r, Point pt, short *angle);

/**
\brief Subtract coordinates of one point from another

<pre>SubPt subtracts the coordinates of one Point from another, storing the result
into the second.
srcPtis a 4-byte Point structure. Its low word is the horizontal
coordinate and its high word is the vertical coordinate.
destPtis the address of a 4-byte Point structure. Upon return, it will
contain the differences: (destPt.h-srcPt.h) and (destPt.v-destPt.v).
</pre>
* \returns <pre>none
</pre>
* \note <pre>The SubPt operation separates the horizontal coordinate from the vertical
coordinates before calculating the difference. It is functionally equivalent
to:
destPt.h -= srcPt. h;
destPt.v -= srcPt. v;
Perhaps more useful is DeltaPoint , which returns the difference as the
return value of the function.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void SubPt(Point src, Point *dst);

/**
\brief Check if a specified pixel is enclosed by a region

<pre>PtInRgn returns an indication of whether or not a point (actually, the pixel
below and to the right of a mathematical coordinate) is enclosed by the outline
of a region.
thePtis a Point, expressed in local or global coordinates.
theRgnis the handle of a region, in the same coordinate system as thePt.
</pre>
* \returns <pre>a Boolean value indicating whether the point is inside of the region.
It is one of:
FALSENot in the region
TRUEIn the region
</pre>
* \note <pre>This is useful in determining if a mouse-down event has occurred while
the cursor was positioned in the area of a region. Note that since the
EventRecord .where field is expressed in global coordinates, so you may
need to convert as follows:
GetNextEvent ( everyEvent , &theEvent );
.
:
GlobalToLocal ( &theEvent.where );
if (PtInRgn ( theEvent.where, theRgn ) {
... /* yes, it was in that region */
...
}
</ pre>
            * \copyright THINK Reference © 1991 - 1992 Symantec Corporation

                                                      *    \non_carbon_cfm in InterfaceLib 7.1 and
    later
        *    \carbon_lib in CarbonLib 1.0 and
    later
        *    \mac_os_x in version 10.0 and
    later
            * /
        Boolean
        PtInRgn(Point pt, RgnHandle rgn);

/**
 *  StdLine()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void StdLine(Point newPt);

#if CALL_NOT_IN_CARBON
/**
 *  OpenCPort()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void OpenCPort(CGrafPtr port);

/**
 *  InitCPort()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void InitCPort(CGrafPtr port);

/**
 *  CloseCPort()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void CloseCPort(CGrafPtr port);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  NewPixMap()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
PixMapHandle
NewPixMap(void);

/**
 *  DisposePixMap()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void DisposePixMap(PixMapHandle pm);

/**
\brief Duplicate pixMap's structure to an existing pixmap

<pre>CopyPixMap copies the data of one pixel map into another.
srcPm is the handle of an existing pixel map you wish to duplicate.
destPm is the handle of destination pixel map.
</pre>
* \returns <pre>none
</pre>
* \note <pre>CopyPixMap copies the contents of the color table, giving the destination
PixMap its own.
The image is not copied -- only the pointer that is the pixMap's baseAddr
field (base address).
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void CopyPixMap(PixMapHandle srcPM, PixMapHandle dstPM);

/**
 *  NewPixPat()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
PixPatHandle
NewPixPat(void);

/**
 *  DisposePixPat()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void DisposePixPat(PixPatHandle pp);

/**
\brief Duplicate pixPat's structure to an existing region

<pre>CopyPixPat copies the data of one pixPat into another.
srcPP is the handle of an existing pixPat you wish to duplicate.
destPP is the handle of destination pixPat.
</pre>
* \returns <pre>none
</pre>
* \note <pre>CopyPixPat copies the entire contents of the pixel pattern, including
color table, data handle, expanded data handle, expanded map, and pixMap
handle.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void CopyPixPat(PixPatHandle srcPP, PixPatHandle dstPP);

/**
 *  PenPixPat()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void PenPixPat(PixPatHandle pp);

/**
 *  BackPixPat()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void BackPixPat(PixPatHandle pp);

/**
 *  GetPixPat()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
PixPatHandle
GetPixPat(short patID);

/**
\brief Provides best possible RGB match on current device

<pre>MakeRGBPat generates a pixPat that approximates the requested color.
thePpat is the handle of the pixel pattern to create in memory.
myColor is the closest match to the requested RGB currently available.
</pre>
* \returns <pre>none
</pre>
* \note <pre>MakeRGBPat generates the closest possible color match to the requested
RGB, given the current equipment.  On a device with 4 bits per pixel,
MakeRGBPat will yield 125 possible colors -- as opposed to 16 colors
on the same device if you'd just set the foreground color and commenced
drawing.
MakeRGBPat makes more colors theoretically possible by alternating
between four colors in a pattern.  While this gives you an increased range
of colors, the alternating color selection doesn't allow for a very solid
pattern and should be avoided when using elements that are one pixel wide.
Each 8-by-8 pattern component is composed of computed colors. Colors
are arranged in an RGB pattern as follows (with pattern map boundary
always containing (0,0,8,8) and the rowbytes equal to 2:
01
23
Value RGB
0computed RGB color
1computed RGB color
2computed RGB color
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void MakeRGBPat(PixPatHandle pp, const RGBColor *myColor);

/**
 *  FillCRect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void FillCRect(const Rect *r, PixPatHandle pp);

/**
 *  FillCOval()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void FillCOval(const Rect *r, PixPatHandle pp);

/**
 *  FillCRoundRect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void FillCRoundRect(const Rect *r, short ovalWidth, short ovalHeight,
                    PixPatHandle pp);

/**
 *  FillCArc()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void FillCArc(const Rect *r, short startAngle, short arcAngle, PixPatHandle pp);

/**
 *  FillCRgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void FillCRgn(RgnHandle rgn, PixPatHandle pp);

/**
 *  FillCPoly()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void FillCPoly(PolyHandle poly, PixPatHandle pp);

/**
 *  RGBForeColor()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void RGBForeColor(const RGBColor *color);

/**
 *  RGBBackColor()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void RGBBackColor(const RGBColor *color);

/**
 *  SetCPixel()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetCPixel(short h, short v, const RGBColor *cPix);

/**
\brief Replaces a portPixMap of the active CGrafPort with a handle

<pre>SetPortPix replaces the portPixMap field of the active CGrafPort with a
new value, effectively changing the entire contents of the port.
</pre>
* \returns <pre>none
</pre>
* \note <pre>This is the Color Quickdraw equivalent of the SetPortBits procedure that
QuickDraw uses on GrafPorts.  SetPortPix cannot be used at all on
old-style GrafPort s. Conversely, a SetPortBits call used in conjunction
with a cGrafPort , will likewise yield nothing.
Like its predecessor, SetPortPix is useful for performing off-screen
drawing. For instance, you can use a series of Color Quickdraw calls to
create an image in an off-screen memory buffer, then use CopyBits to
copy the bit-mapped image into the normal screen.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void SetPortPix(PixMapHandle pm);

/**
\brief Find the RGB of a specified pixel

<pre>GetCPixel obtains the RGB of a pixel associated with a coordinate pair.
horizand . . .
vert identify the pixel in question (which hangs below and to the
right of the specified point). These are expressed in the
coordinate system of the current CGrafPort .
color is the RGB color of the pixel.
</pre>
* \returns <pre>none
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void GetCPixel(short h, short v, RGBColor *cPix);

/**
\brief Obtain foreground color set in current port

<pre>GetForeColor is used to obtain the red, green, and blue complements of the
foreground color in the current port.
color is the address of either the rgbFgColor field or the global variable
QDColors , depending on whether the current port is a grafPort or a
cGrafPort.
</pre>
* \returns <pre> none
Notes :GetForeColor works regardless of whether the current port is a grafPort
or a cGrafPort. The difference is that for CGrafPort , the value comes from
the rgbFgColor field while GrafPort colors are specific values set by the
global variable QDColors . In turn, QDColors is a pointer to a table where
Quickdraw colors are stored as follows:
Value Color Red Green Blue
0 black 0x0000 0x0000 0x0000
1 yellow 0xFC00 0xF37D 0x052F
2 magenta 0xF2D7 0x0856 0x84EC
3 red 0xDD6B 0x08C2 0x06A2
4 cyan 0x0241 0xAB54 0xEAFF
5 green 0x0000 0x8000 0x11B0
6 blue 0x0000 0x0000 0xD400
7 white 0xFFFF 0xFFFF 0xFFFF
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void GetForeColor(RGBColor *color);

/**
\brief Obtain foreground color set in current port

<pre>GetBackColor is used to obtain the red, green and blue, components of the
foreground color in the current port.
color is the address of either the rgbBkColor field or the global variable
QDColors , depending on whether the current port is a grafPort or a
cGrafPort.
</pre>
* \returns <pre> none
Notes :GetBackColor works regardless of whether the current port is a grafPort
or a cGrafPort. The difference is that for CGrafPort , the value comes from
the rgbBkColor field while GrafPort colors are specific values set by the
global variable QDColors . In turn, QDColors is a pointer to a table where
Quickdraw colors are stored as follows:
Value Color Red Green Blue
0 black 0x0000 0x0000 0x0000
1 yellow 0xFC00 0xF37D 0x052F
2 magenta 0xF2D7 0x0856 0x84EC
3 red 0xDD6B 0x08C2 0x06A2
4 cyan 0x0241 0xAB54 0xEAFF
5 green 0x0000 0x8000 0x11B0
6 blue 0x0000 0x0000 0xD400
7 white 0xFFFF 0xFFFF 0xFFFF
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void GetBackColor(RGBColor *color);

/**
\brief Calculate a mask for use in CopyMask or CopyBits
\param    matchProc pointer to match seed RGB values
<pre>SeedCFill examines a portion of a source bitMap or pixMap and fills a
portion of a destination bitMap or pixMap with 1s where paint can flow. It
finds an enclosed area surrounding a specified point in the source (seed), and
floods that area in the destination with 1s (RGB value equals that of seed).
Use this function as one step in implementing a "paint bucket" tool.
srcMap is the address (srcBits) of a rectangle inside a bitMap or
pixMap data area. SeedCFill examines this rectangle as it
floods portions of the destination bitMap.
destMap is the address (destBits) of a rectangle inside a bitMap or
pixMap data area. SeedCFill fills all or part of this rectangle
with 1s.
srcRect and . . .
destRect are the rectangles within the BitMap or PixMap into which
srcMap and destMap, respectively point; i.e., the function
will add this value to its current address pointer to move "down
one line" in the bitMap.
seedH and...
seedV identify the point to start flooding.
matchProc returns 0s for RGB values to be filled -- returns 1s when the
values should not be filled.
matchData returns the value assigned.
</pre>
* \returns <pre>none
</pre>
* \note <pre>The default setting for SeedCFill allows paint to flow from the seed
position to all positions that touch it and whose RGB value equals that of the
seed. Setting matchProc and matchData to zero calls the default mode.
Use SeedCFill to flood an area of a destination bitMap pixMap with paint
(i.e., 1s) in the exact color of the source. The flooded area will match the
inside and boundary of a section of the source which is enclosed by RGB
pixels.
To flood with some other pattern requires intermediate steps of using
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void SeedCFill(const BitMap *srcBits, const BitMap *dstBits, const Rect *srcRect,
               const Rect *dstRect, short seedH, short seedV,
               ColorSearchUPP matchProc, long matchData);

/**
\brief Calculate a mask for use in CopyMask
\param    matchProc custom matching routine; NIL = default
<pre>CalcCMask examines a portion of a bitmap and creates a mask that can be
used with CopyMask . It finds the outermost outline of any figure in the
bitmap (as in the lasso tool of many paint programs) and creates a mask having
1s in the places where paint would "leak" were you to pour it inside the figure.
The object of this procedure is the reverse of SeedCFill in that it protects
areas from being filled with color.
srcMap is the address (srcBits) of a rectangle inside a BitMap or
PixMap data area. CalcCMask examines this rectangle as it floods
portions of the destination bitMap.
destMap is the address (destBits) of a rectangle inside a BitMap or
PixMap data area. CalcCMask fills all or part of this rectangle
with 1s.
*srcRect  and . . .
*destRect are the rectangles within the BitMap or PixMap into which srcMap
 and destMap, respectively point; i.e., the function will add this
value to its current address pointer to move "down one line" in the
BitMap.
seedRGB is the RGBvalue of the pixel from which calculations begin.
matchProc  is a pointer to a custom routine to be used instead of the default
searchProc. It should return 1's for RGB values that define the edges
of the mask and 0's for values that do not. Pass NIL in this parameter
to use the default searchProc. See
Custom Search and Complement Procedures for more on
writing a custom searchProc.
matchData  holds application specific data. Pass 0 in this parameter to obtain
the default behavior.
</pre>
* \returns <pre>none
</pre>
* \note <pre>Use CalcCMask to build a mask which can be used in conjunction with
CopyMask to implement the "lasso" tool of many paint programs.
CalcCMask creates an area into which paint won't flow. By default, paint
can leak to all adjacent pixels whose RGB values don't match that of the
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void CalcCMask(const BitMap *srcBits, const BitMap *dstBits, const Rect *srcRect,
               const Rect *dstRect, const RGBColor *seedRGB,
               ColorSearchUPP matchProc, long matchData);

/**
 *  OpenCPicture()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
PicHandle
OpenCPicture(const OpenCPicParams *newHeader);

/**
\brief Set RGB values used by addPin, subPin and blend modes

<pre>OpColor sets the red, green, and blue values used by addPin, subPin, and
blend modes.
RGBColor  is a record type which specifies a color's red, green,
and blue components as 16-bit unsigned integers.
</pre>
* \returns <pre>none
</pre>
* \note <pre>This sets drawing mode color values, which are stored in the grafVars
handle in the CGrafPort . This procedure will have no effect unless the
current port is a cGrafPort.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void OpColor(const RGBColor *color);

/**
\brief Choose new highlighting color

<pre>HiliteColor lets you change the highlighting color used by current
cGrafPort.
RGBColor  is a record type which specifies a color's red, green, and blue
components as 16-bit unsigned integers.
</pre>
* \returns <pre>none
</pre>
* \note <pre>Highlight color is used whenever a drawing operation uses the highlight
transfer mode. A cGrafPort's highlight colors are initialized from the
HiliteRGB global variable stored in the port's grafVars handle.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void HiliteColor(const RGBColor *color);

/**
 *  DisposeCTable()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void DisposeCTable(CTabHandle cTable);

/**
 *  GetCTable()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
CTabHandle
GetCTable(short ctID);

/**
 *  GetCCursor()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
CCrsrHandle
GetCCursor(short crsrID);

/**
 *  SetCCursor()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetCCursor(CCrsrHandle cCrsr);

/**
 *  AllocCursor()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void AllocCursor(void);

/**
 *  DisposeCCursor()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void DisposeCCursor(CCrsrHandle cCrsr);

/* GetCIcon(), PlotCIcon(), and DisposeCIcon() moved to Icons.h*/

/**
\brief Set graphProcs field to point to custom routines

<pre>SetStdCProcs stores the addresses of the standard Quickdraw procedures
into a structure intended to be used in a CGrafPort .
*cProcsis the address a CQDProcs structure. Upon return, all fields of
the structure have been set to contain the addresses of the standard
low-level routines used by Color Quickdraw.
</pre>
* \returns <pre>none
</pre>
* \note <pre>This is used by applications that wish to intercept selected low-level
routines (e.g., the picture-comment handler) while continuing to use the
other standard routines.
SetStdCProcs has to be used in place of the older SetStdProcs
whenever your application is drawing in a cGrafPort .
Most applications won't need to replace code. If you do wish to install a
custom Color Quickdraw function handler (sometimes called a "bottleneck"
routine), follow these steps:
•Create a function which accepts the same parameters in the same order as
one of Color Quickdraw's StdXxx functions.
•Open a CGrafPort (OpenCPort or NewCWindow ).
•Create a standard CQDProcs structure by allocating it and then using
SetStdCProcs to initialize it.
•Store the address of your custom procedure into the appropriate field of
the CQDProcs structure.
•Store the address of your CQDProcs structure into the cGrafProcs field of
the desired CGrafPort .
Now, when your application invokes a Color Quickdraw function that passes
through the intercepted bottleneck, your custom handler will get control.
You need not replace all the functionality of a bottleneck -- you may choose
to simply pre-process the parameters passed to you and then invoke the
original handler.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void SetStdCProcs(CQDProcs *procs);

/**
\brief Gives a handle to device with the deepest pixMap
\param    CGrafPort and 5) call SetGDevice  yet again to bring back the formerly
<pre>GetMaxDevice provides a handle to the greatest pixel-depth gDevice in
the entire global rectangle.
globalRect is the rectangle in global coordinates.
</pre>
* \returns <pre>a GDHandle ; a handle leading to the device in
the list with the most available colors.
</pre>
* \note <pre>You can use this routine when creating an offscreen PixMap for subsequent
transfer to visible display areas. Alternatively, you might want control of a
drawing's colors, especially if it's going to be printed on a device with a
different color table than the screen. In either case, you need control of the
color and, hence, the gDevices.
In either case, if your application spans devices with varying color
capabilities, GetMaxDevice lets you use a PixMap to set up the colors to
take advantage of the best color table from among all the devices.
If you decide to use a PixMap as for a device with the greatest pixel depth,
you have to obtain an offscreen CGrafPort for that particular monitor.
What's involved in that is: 1)save the current gDevice with the GetGDevice
procedure; 2) call GetMaxDevice ; 3) use SetGDevice to make the new
choice the currently active screen; 4) call OpenCPort to create the new
CGrafPort ; and 5) call SetGDevice yet again to bring back the formerly
active gDevice. Because OpenCPort uses the global theGDevice to initialize
its PixMap the current CGrafPort and the deepest screen become one and the
same.
All of the above, however, is simply preparation. Now you get storage for
the pixels by defining the PixMap's boundaries to the image's height and
width, and setting the rowBytes to take into account the particular pixel size
being used on that device--( ( width* portPixMap ^^.pixSize )+ 15 )DIV 16
* 2 --always bearing in mind that rowBytes has to be even to work at all
and a multiple of 4 to work best. Now define the interior of the PixMap by
setting portRect . The amount of storage is now height times the value of
rowBytes . If you allocate the storage as a handle, then your application can
lock the handle and place a pointer to it in the PixMap's base address.
Next, in order to draw to the CGrafPort , you save the current gDevice, set
theGDevice to be the maximum device, and restore theGDevice when the
drawing operation is complete.
After you've done all of this preparation, be sure to protect it since all of
the above can be brought to nothing if the user changes the depth of the
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
GDHandle
GetMaxDevice(const Rect *globalRect);

/**
\brief Get unique seed value for color table

<pre>GetCTSeed returns a seed value unique to the application's color table and is
for use in its ctSeed field.
</pre>
* \returns <pre>a 32-bit long; a value greater than that stored in minSeed.
</pre>
* \note <pre>GetCTSeed distinquishes the color table from the destination and ensures
proper color table translation.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
long GetCTSeed(void);

/**
\brief Provides a handle to the first gDevice in the DeviceList

<pre>GetDeviceList  can be used to show which device is first on the Device list.
Returns: a GDHandle ; a handle to the first gDevice.
</pre>
* \note <pre> A handle to the first item in the device list can be found in the
DeviceList global variable.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
GDHandle
GetDeviceList(void);

/**
\brief Provides a handle to the startup gDevice.

<pre>GetMainDevice  can be used to show which device is listed as the monitor with
the menu bar. GetMainDevice gets this value from the MainDevice global
variable.
Returns: a GDHandle ; a handle to the gDevice that carries the menu bar.
</pre>
* \note <pre> Contains information on the size and depth of the gDevice of the
monitor containing the menu bar. Unless a different screen has been
called out in parameter RAM as the main device, this is the screen with
its video card in the lowest-numbered slot.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
GDHandle
GetMainDevice(void);

/**
 *  GetNextDevice()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
GDHandle
GetNextDevice(GDHandle curDevice);

/**
\brief TestDeviceAttribute Check whether or not an attribute is set

<pre>TestDeviceAttribute returns an indication as to what kind of gDevice you
have and whether or not it is set.
curDevice is the handle that leads to the device being tested in the gDevice
record.
attribute is one of seven graphics device characteristics that can be on or off.
</pre>
* \returns <pre> a Boolean value indicating the status of a particular
attribute It is one of:
FALSE Not set
TRUE Attribute set
</pre>
* \note <pre>Scanning through a device list, TestDeviceAttribute tells you if your
device is a display and if it's active. It does not necessarily tell if the
monitor is turned on, or if there is a monitor attached to the card.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
Boolean
TestDeviceAttribute(GDHandle gdh, short attribute);

/**
\brief SetDeviceAttribute Set the device's display characteristics

<pre>Use SetDeviceAttribute to set a device's display characteristics. This
routine is rarely called by applications.
gdhis the handle that communicates with the gDevice record.
attribute is one of seven graphics device characteristics that can be on or off.
valueis a Boolean value that indicates whether the specified attribute is
set (TRUE) or not (FALSE) as follows:
gdDevType: TRUE = Color; FALSE = Monochrome
ramInit: TRUE = Device initialized from RAM
mainScreen: TRUE = Device is startup screen
allInit:TRUE = Device initialized from 'scrn' resource (see below)
screenDevice: TRUE = Device is a display monitor
noDriver: TRUE = No driver for device
screenActive: TRUE = Active device
</pre>
* \returns <pre>none
For more information, see The 'scrn' Resource .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void SetDeviceAttribute(GDHandle gdh, short attribute, Boolean value);

/**
 *  InitGDevice()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void InitGDevice(short qdRefNum, long mode, GDHandle gdh);

/**
 *  NewGDevice()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
GDHandle
NewGDevice(short refNum, long mode);

/**
 *  DisposeGDevice()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void DisposeGDevice(GDHandle gdh);

/**
\brief Set the current device to the specified device

<pre>SetGDevice sets the specified graphics device record as the current device.
Your application won't generally need to use this procedure except to draw
offscreen graphics devices.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void SetGDevice(GDHandle gd);

/**
\brief Get handle to current GDevice

<pre>GetGDevice returns a handle to the current GDevice. You can use the
functions GetDeviceList and GetNextDevice to step through all devices.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
GDHandle
GetGDevice(void);

/**
 *  Color2Index()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
long Color2Index(const RGBColor *myColor);

/**
\brief Find specific RGB

<pre>Index2Color finds the RGB color that matches an indexed value on a color
table.
indexis the padded pixel value
rgbis the RGB read from the current device
</pre>
* \returns <pre>none
</pre>
* \note <pre>Index2Color is a color conversion procedure that finds the RGB color
that best matches a given color table index. This color does not have to be
the same color originally requested through RGBForeColor ,
RGBBackColor , SetCPixel , or Color2Index since it is the RGB that is
available from the current gDevice.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void Index2Color(long index, RGBColor *aColor);

/**
\brief Find a color's complement

<pre>InvertColor finds the RGB color that complements a specified color
theColor is an RGB's complement
</pre>
* \returns <pre>none
</pre>
* \note <pre>InvertColor' s default procedure for finding a color's complement is to
use the 1's complement of each component of the requested color.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void InvertColor(RGBColor *myColor);

/**
 *  RealColor()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
RealColor(const RGBColor *color);

/**
 *  GetSubTable()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void GetSubTable(CTabHandle myColors, short iTabRes, CTabHandle targetTbl);

/**
 *  MakeITable()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void MakeITable(CTabHandle cTabH, ITabHandle iTabH, short res);

/**
 *  AddSearch()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void AddSearch(ColorSearchUPP searchProc);

/**
 *  AddComp()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void AddComp(ColorComplementUPP compProc);

/**
 *  DelSearch()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void DelSearch(ColorSearchUPP searchProc);

/**
 *  DelComp()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void DelComp(ColorComplementUPP compProc);

/**
\brief Identify this client to search and complement procedures

<pre>SetClientID sets the gdID field in the device record so that its search and
complement procedures will recognize this particular client program.
idis the client program being given identification
</pre>
* \returns <pre>none
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void SetClientID(short id);

/**
\brief Protect or un-protect color table entry

<pre>ProtectEntry is used by the Color Manager to provide protection or remove
protection from a color table entry.
indexis the identification of the entry to be affected by this procedure.
protectFlag specifies whether to protect the entry or remove its protection . It
must be one of:
FALSEremove protection from any specified entry
TRUEprotect entry, returns a protection error if entry is already
protected.
</pre>
* \returns <pre>none
</pre>
* \note <pre>Once an entry is protected, other clients cannot affect it.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void ProtectEntry(short index, Boolean protect);

/**
\brief Reserve or dereserve color table entry

<pre>ReserveEntry is used by the Color Manager to provide selective protection
or remove reservation from a color table entry.
indexis the identification of the entry to be affected by this procedure.
ReserveFlag specifies whether to reserve the entry or remove its reservation .
It must be one of:
FALSEdereserve any specified entry
TRUEReserve an entry so another client's search procedure won't be
able to match it and it won't be returned to another client by
Color2Index , RGBForeColor , RGBBackColor , etc.
</pre>
* \returns <pre>none
</pre>
* \note <pre>ReserveEntry acts like selective protection by copying the low byte of
gdID into the low byte of colorSpec .value while leaving the high byte alone.
It won't allow changes if the current gdID is different than the one in the
colorSpec .value field of the reserved entry.  Returns a protection error if
a requested match is already reserved. All entries are subject to being
dereserved.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void ReserveEntry(short index, Boolean reserve);

/**
\brief Set a group of color table entries for the current gDevice

<pre>SetEntries sets the enumerated color table entries for the current gDevice.
startis the given position where the specified number of entries begin.
count yields the total number of color table entries in the group being set.
aTableis a cSpecArray, not a color table
</pre>
* \returns <pre>none
</pre>
* \note <pre>SetEntries sets many color table entries to the current gDevice. Its
aTable parameter points to a cSpecArray (rather than a color table) in
which the colorSpec .value field of the entries has to fall within the logical
range for the gDevice's assigned pixel depth. For example, if the gDevice
lists a 4-bit pixel size, the colorSpec .value fields must be in the 1 to 15
range and, if the device has 8-bit pixels, the colorSpec .value fields range
from 0 to 255. All values are zero-based so setting three entries means
that you pass a 2 in the count parameter.
Since SetEntries lists its positional information in terms of logical space
instead of memory locations as used by the gDevice, specifying a color table
change won't necessarily get you a change in the hardware's color
table--but it will be correctly reflected in the colors on the screen.
There are actually two SetEntries modes-- index mode and sequence
mode.
For the latter, the distinguishing characteristic is a specified start
position and a length. Index mode SetEntries , on the other hand, leave the
specifying of where the data will be installed up to the cSpecArray (which
handles such chores on an individual basis for each entry).
While sequence mode loads new colors in the same order they appear in the
aTable, with clientID fields for changed entries copied from the gDevice's
gdID field, index mode installs each entry based on a position specified by
its colorSpec .value field in the cSpecArray . Then, in the gDevice's color
table, all changed entries' colorSpec .value fields get the gdID value. You
initiate the index mode by passing -1 for the start position, with a valid
count and pointer to the cSpecArray .
Changing a color table entry invalidates all cached fonts as well as the seed
number, meaning that the inverse table will be rebuilt by the next drawing
operation. If any requested entry is protected or out of range, you get a
protection error and nothing else. If a requested entry is reserved, the
gDevice's gdID has to match the low byte of the intended colorSpec .value
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void SetEntries(short start, short count, CSpecArray aTable);

/**
\brief Saves selected entries to a result table

<pre>SaveEntries saves selected entries from a source table to a result table
scrTable is the source of the entries to be saved.
ResultTable is the table in which the saved entries are placed.
*selection is the parameter enumerating the entries to be saved.
</pre>
* \returns <pre>none
</pre>
* \note <pre>If an entry is missing from the source table, its position on the request list
part of the ReqListRec data structure is set to colReqErr , and that position
of the result table has random values returned. When an entry can't be
found, an error is posted to QDError , but every entry that is found yields
valid values in the result table. The source table and the selection
parameter are always assumed to have the same number of entries.
You can have a NIL as the source table parameter but if you do, the active
gDevice's color table is used as the source. SaveEntries ' output is
identical to RestoreEntries ' input.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void SaveEntries(CTabHandle srcTable, CTabHandle resultTable, ReqListRec *selection);

/**
\brief Sets entries into dstTable without rebuilding inverse table

<pre>RestoreEntries saves selected entries so you can put them back later
scrTable is the source of the entries to be saved.
dstTable is the table in which the restorable entries are placed.
*selection is the parameter enumerating the entries for saving and retrieval.
</pre>
* \returns <pre>none
</pre>
* \note <pre>RestoreEntries lets you change the color table without changing its
ctSeed. You can then execute an application and restore the original colors.
What may happen, however, is that the background will be in the wrong
color after restoration since it is not redrawn. Getting around this means
having the application build its own new inverse table and redrawing the
background colors. That, in turn, means that the ctSeed would have to be
explicitly changed.
The dstTable entries are listed in the selection parameter (see
ReqListRec ) and the source and selection are assumed to have the same
number of entries. If a requested entry can't be found, its position on the
list is set to colReqErr and an error is returned.
A NIL for dstTable updates the gDevice's color table (as will a pointer to
the device color table), which updates the hardware to the new colors. The
seed doesn't change and the results are valid but the RGBForeColor may
change. RestoreEntries ignores color table protection and reservation.
Since Palette Manager was designed to give applications their own set of
colors, you'll likely have little need for RestoreEntries .
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void RestoreEntries(CTabHandle srcTable, CTabHandle dstTable, ReqListRec *selection);

/**
\brief Return error result from last QuickDraw  call

<pre>The QDError function, introduced with Color QuickDraw  returns the
error result from the last Color QuickDraw or Color Manager call. It has
a number of new result codes, and it has also been modified so that it does not
fail on a black-and-white system (where it always returns FALSE). Its format
is the same:
</pre>
* \returns <pre>the error result from the last Color QuickDraw or
Color Manager call
</pre>
* \note <pre>QuickDraw uses stack space for work buffers. For complex operations
such as depth conversion, dithering, and image resizing, stack space may
not be sufficient. Color QuickDraw now attempts to get temporary
memory from other parts of the system. If that is still not enough, QDError
returns this code:
mfStackErr (-149)Insufficient stack
If your application receives this result code, divide the operation-for
example, divide the image into left and right halves-and try again.
When you record drawing operations in an open region, the resulting region
description may overflow the 64 KB limit. Should this happen, QDError
returns -147.
regionTooBigError (-147)Region too big or complex
Since the resulting region is potentially corrupt, the closeRgn procedure
returns an empty region if it detects QDError has been set to -147. A similar
error can occur during conversion of a bitmap to a region.
rgnTooBigErr (-500)Bitmap would convert to a region greater than 64 KB
The BitMapToRegion function can also generate an error if a pixel map is
supplied that is greater than 1 bit per pixel.
pixmapTooDeepErr (-148)Pixel map record is deeper than 1 bit per pixel
You may be able to recover from this problem by imaging your too-deep pixel
map into a 1-bit pixel map and calling BitMapToRegion again.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
short QDError(void);

/**
 *  CopyDeepMask()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void CopyDeepMask(const BitMap *srcBits, const BitMap *maskBits,
                  const BitMap *dstBits, const Rect *srcRect, const Rect *maskRect,
                  const Rect *dstRect, short mode,
                  RgnHandle maskRgn) /* can be NULL */;

/**
 *  DeviceLoop()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void DeviceLoop(RgnHandle drawingRgn, DeviceLoopDrawingUPP drawingProc,
                long userData, DeviceLoopFlags flags);

/**
\brief Get table of masks from ROM

<pre>GetMaskTable returns a pointer to a ROM table containing the following
useful masks:
0x0000, 0x8000, 0xC000, 0xE000 Table of 16 right masks
0xF000, 0xF800, 0xFC00, 0xFE00
0xFF00, 0xFF80, 0xFFC0, 0xFFE0
0xFFF0, 0xFFF8, 0xFFFC, 0xFFFE
0xFFFF, 0x7FFF, 0x3FFF, 0x1FFF Table of 16 left masks
0x0FFF, 0x07FF, 0x03FF, 0x01FF
0x00FF, 0x007F, 0x003F, 0x001F
0X000F, 0x0007, 0x0003, 0x0001
0x8000, 0x4000, 0x2000, 0x1000 Table of 16 bit masks
0x0800, 0x0400, 0x0200, 0x0100
0x0080, 0x0040, 0x0020, 0x0010
0x0008, 0x0004, 0x0002, 0x0001
</pre>
* \returns <pre> a pointer to a table of 48 masks
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter __A0 GetMaskTable
#endif
Ptr GetMaskTable(void);

/**
 *  GetPattern()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
PatHandle
GetPattern(short patternID);

/**
 *  [Mac]GetCursor()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
#if TARGET_OS_MAC
#define MacGetCursor GetCursor
#endif
CursHandle
MacGetCursor(short cursorID);

/**
 *  GetPicture()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
PicHandle
GetPicture(short pictureID);

/**
\brief Calculate distance between two points
\param    aPt any Point
\param    bPt any other point, same coordinate system
<pre>DeltaPoint returns the distance between two points, returned as a 32-bit
value with the high-order word being the vertical distance and the low-order
word being the horizontal distance.
aPtand . . .
bPtare any two points, expressed in the same coordinate system.
</pre>
* \returns <pre>a 32-bit long integer; it identifies the distance between aPt and
bPt.  The high word is the vertical offset and the low word is the
horizontal offset. Negative values indicate that bPt is above and to
the left of aPt ; positive values indicate below and to the right.
</pre>
* \note <pre>This performs the same function as SubPt, except the difference is given
as the returned value instead of stored into a variable.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
long DeltaPoint(Point ptA, Point ptB);

/**
\brief Hide cursor while moving (or while in) a rectangle

<pre>ShieldCursor ( &shieldRect, thePort->portBits.bounds.topLeft );
.
:
ShowCursor ();/* when you no longer need to shield */
An alternative method is to convert shieldRect to global coordinates(via
                                                                         LocalToGlobal) before the call,
    and pass(0, 0) as offsetPt.</ pre>
                * \copyright THINK Reference © 1991 -
            1992 Symantec Corporation

                *    \non_carbon_cfm in InterfaceLib 7.1 and
        later
            *    \carbon_lib in CarbonLib 1.0 and
        later
            *    \mac_os_x in version 10.0 and
        later
                * /
            void ShieldCursor(const Rect *shieldRect, Point offsetPt);

/**
\brief Obtain screen resolution in pixels-per-inch

<pre>ScreenRes lets you obtain the screen resolution in pixels-per-inch. It can
be useful in scaling objects to make maximum use of the screen real estate.
horizPPI and . . .
vertPPI are the addresses of a 16-bit integers. Upon return, they will
contain the screen resolution, expressed in pixels-per-inch.
</pre>
* \returns <pre>none
</pre>
* \note <pre>This function just copies the values of the low-memory variables ScrHRes
and ScrVRes to your own variables. The addresses of these variables are
defined in Quickdraw.h. Thus, ScreenRes is functionally equivalent to:
horizPPI = ScrHRes;
vertPPI = ScrVRes;
A more-often needed value is the total size of the screen, in pixels. Obtain
that by reading the bounds field from the screenBits BitMap:
horizPixels = screenBits .bounds.right;
vertPixels = screenBits .bounds.bottom;
The global variable, GrayRgn (a RgnHandle ) describes the size and shape of
the desktop. This is especially handy to take advantage of Macs that have
more than one screen.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void ScreenRes(short *scrnHRes, short *scrnVRes);

/**
 *  GetIndPattern()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void GetIndPattern(Pattern *thePat, short patternListID, short index);

#if CALL_NOT_IN_CARBON
/**
 *  ptinrect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
ptinrect(const Point *pt, const Rect *r);

/**
 *  pt2rect()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void pt2rect(const Point *pt1, const Point *pt2, Rect *destRect);

/**
 *  pttoangle()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void pttoangle(const Rect *r, const Point *pt, short *angle);

/**
 *  ptinrgn()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
ptinrgn(const Point *pt, RgnHandle rgn);

/**
 *  addpt()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void addpt(const Point *src, Point *dst);

/**
 *  subpt()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void subpt(const Point *src, Point *dst);

/**
 *  equalpt()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Boolean
equalpt(const Point *pt1, const Point *pt2);

/**
 *  stuffhex()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void stuffhex(void *thingPtr, const char *s);

/**
 *  stdline()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void stdline(const Point *newPt);

/**
 *  shieldcursor()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void shieldcursor(const Rect *shieldRect, Point *offsetPt);

#endif /* CALL_NOT_IN_CARBON */

/**
 *  deltapoint()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
long deltapoint(Point *ptA, Point *ptB);

#if OLDROUTINENAMES
#define DisposPixMap(pm) DisposePixMap(pm)
#define DisposPixPat(pp) DisposePixPat(pp)
#define DisposCTable(cTable) DisposeCTable(cTable)
#define DisposCCursor(cCrsr) DisposeCCursor(cCrsr)
#define DisposGDevice(gdh) DisposeGDevice(gdh)
#endif /* OLDROUTINENAMES */

/**
    From ToolUtils.i
*/

/**
\brief Perform RLL byte compression on arbitrary data

<pre>PackBits compresses up to 32,768 bytes of data by replacing sequences of 3
or more identical bytes with a 2-byte code. It is most often used to compress
image data, as found in a BitMap or a PixMap. The worst case compression can
be calculated using the formula: (srcLen + (srcLen + 126) / 127).
srcPtris the address of a pointer to some data to be compressed. Upon
return, the pointer has been adjusted to just beyond the data that has
been compressed; i.e., ready for the next call.
destPtris the address of a pointer to a buffer to hold the compressed data.
Upon return, it has been adjusted to just beyond the end of the
compressed data.
srcLenis the size, in bytes, of the data to be compressed.
</pre>
* \returns <pre>none
</pre>
* \note <pre>Since image data is often full of "white-space", this is ideal for packing
data for long-term RAM storage and before writing it to disk or storing it in
a resource. It is not quite so useful for compressing text or other data. Note
the misnomer: PackBits does not pack bits; it packs sequences of bytes.
PackBits was formerly limited to compressing data in 127 bytes blocks.
To compress more than 127 bytes, a programmer would have to break the
data up and make multiple calls to PackBits . Starting with System
Software version 6.0.2, this restriction has been lifted. If you want your
program to run on Systems prior to version 6.0.2, you must obey the
127-byte limit.
Typical usage is to pack each line of a BitMap or PixMap separately, as in
the example below. The example procedure, PackScreen, typically
compresses a black and white screen image from 32K down to about 4K or
5K.
Example
#include < ToolUtils.h >
PtrsavePtr;
longmapSize, PackScreen( Ptr);
mapSize = (long) screenBits .bounds.bottom * screenBits .rowBytes;
savePtr = NewPtr ( mapSize + 1 ); /* allocate storage buffer */
</ pre>
            * \copyright THINK Reference © 1991 - 1992 Symantec Corporation

                                                      *    \non_carbon_cfm in InterfaceLib 7.1 and
    later
        *    \carbon_lib in CarbonLib 1.0 and
    later
        *    \mac_os_x in version 10.0 and
    later
            * /
        void
        PackBits(Ptr *srcPtr, Ptr *dstPtr, short srcBytes);

/**
\brief Uncompress data stored via PackBits

<pre>restoring it via UnpackBits .
Since the destLen value must be known in advance, any generalized
packed-data save/restore procedure would need to have this value
accompany the compressed data.
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation

*    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
void UnpackBits(Ptr *srcPtr, Ptr *dstPtr, short dstBytes);

/**
\brief Calculate slope given an angle

<pre>theSlope = SlopeFromAngle ( 17 ); /* get slope of 17 ° angle */
/* -------- calculate dv and dh; the vertical and horizontal distance */
dv = startPt.v - endPt.v; /* vertical is easy */
dh = FixRound(FixMul(INT2FIX(dv), theSlope));
MoveTo(startPt.h, startPt.v); /* move to start point */
Line(dh, dv);                 /* draw calculated distance */
</ pre>
            * \copyright THINK Reference © 1991 - 1992 Symantec Corporation

                                                      *    \non_carbon_cfm in InterfaceLib 7.1 and
    later
        *    \carbon_lib in CarbonLib 1.0 and
    later
        *    \mac_os_x in version 10.0 and
    later
            * /
        Fixed
        SlopeFromAngle(short angle);

/**
\brief Calculate angle given slope

<pre>vertical change between any two points on the line) AngleFromSlope
calculates the angle of that line. The calculation is approximate to the nearest
degree.
theSlope a 4-byte Fixed value; the dh/dv ratio of points on a line.
</pre>
* \returns <pre>a signed short integer representing the angle most closely matching
the specified slope ratio. Positive values are clockwise from vertical
and negative values are counterclockwise.
</pre>
* \note <pre>The returned angle is expressed in circular degrees, going clockwise with
12 o'clock at 0 °, 3 o'clock at 90 °, etc.  Negative values are
counterclockwise from straight up; e.g., 9 o'clock is -90 °.
The following example calculates the slope of a line represented by two
endpoints and uses AngleFromSlope to derive the angle of the line.
Example
#include < ToolUtils.h >
#define INT2FIX(i) ((long) i << 16 )/* short to Fixed conversion macro */
Fixed theSlope;
Point startPt, endPt;
short theAngle, dh, dv;
dh = startPt.h - endPt.h; /* calculate the deltas */
dv = startPt.v - endPt.v;
theSlope = FixRatio(INT2FIX(dh), INT2FIX(dv)); /* slope=dh/dv */
theAngle = AngleFromSlope(theSlope);
</ pre>
            * \copyright THINK Reference © 1991 - 1992 Symantec Corporation

                                                      *    \non_carbon_cfm in InterfaceLib 7.1 and
    later
        *    \carbon_lib in CarbonLib 1.0 and
    later
        *    \mac_os_x in version 10.0 and
    later
            * /
        short
        AngleFromSlope(Fixed slope);

/* New transfer modes */
enum
{
  colorXorXFer = 52,
  noiseXFer = 53,
  customXFer = 54
};

/* Custom XFer flags */
enum
{
  kXFer1PixelAtATime = 0x00000001, /* 1 pixel passed to custom XFer proc*/
  kXFerConvertPixelToRGB32 =
      0x00000002 /* All color depths converted to 32 bit RGB*/
};

struct CustomXFerRec
{
  UInt32 version;
  void *srcPixels;
  void *destPixels;
  void *resultPixels;
  UInt32 refCon;
  UInt32 pixelSize;
  UInt32 pixelCount;
  Point firstPixelHV;
  Rect destBounds;
};
typedef struct CustomXFerRec CustomXFerRec;
typedef CustomXFerRec *CustomXFerRecPtr;
typedef CALLBACK_API(void, CustomXFerProcPtr)(CustomXFerRecPtr info);
/**
 *  GetPortCustomXFerProc()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr GetPortCustomXFerProc(CGrafPtr port, CustomXFerProcPtr *proc, UInt32 *flags,
                            UInt32 *refCon);

/**
 *  SetPortCustomXFerProc()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr SetPortCustomXFerProc(CGrafPtr port, CustomXFerProcPtr proc, UInt32 flags,
                            UInt32 refCon);

enum
{
  kCursorComponentsVersion = 0x00010001
};

enum
{
  kCursorComponentType = FOUR_CHAR_CODE('curs')
};

/* Cursor Component capabilities flags */
enum
{
  cursorDoesAnimate = 1L << 0,
  cursorDoesHardware = 1L << 1,
  cursorDoesUnreadableScreenBits = 1L << 2
};

/* Cursor Component output mode flags */
enum
{
  kRenderCursorInHardware = 1L << 0,
  kRenderCursorInSoftware = 1L << 1
};

/* Cursor Component Info */
struct CursorInfo
{
  long version; /* use kCursorComponentsVersion */
  long capabilities;
  long animateDuration; /* approximate time between animate tickles */
  Rect bounds;
  Point hotspot;
  long reserved; /* must set to zero */
};
typedef struct CursorInfo CursorInfo;
/* Cursor Component Selectors */
enum
{
  kCursorComponentInit = 0x0001,
  kCursorComponentGetInfo = 0x0002,
  kCursorComponentSetOutputMode = 0x0003,
  kCursorComponentSetData = 0x0004,
  kCursorComponentReconfigure = 0x0005,
  kCursorComponentDraw = 0x0006,
  kCursorComponentErase = 0x0007,
  kCursorComponentMove = 0x0008,
  kCursorComponentAnimate = 0x0009,
  kCursorComponentLastReserved = 0x0050
};

/**
 *  OpenCursorComponent()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr OpenCursorComponent(Component c, ComponentInstance *ci);

/**
 *  CloseCursorComponent()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr CloseCursorComponent(ComponentInstance ci);

/**
 *  SetCursorComponent()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr SetCursorComponent(ComponentInstance ci);

/**
 *  CursorComponentChanged()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr CursorComponentChanged(ComponentInstance ci);

/**
 *  CursorComponentSetData()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr CursorComponentSetData(ComponentInstance ci, long data);

/* Quickdraw-specific ColorSync matching */
/* Available in CarbonLib... */
/**
 *  IsValidPort()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
IsValidPort(CGrafPtr port);

#if ACCESSOR_CALLS_ARE_FUNCTIONS
/* GrafPort */
/* Getters */
/**
 *  GetPortPixMap()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
PixMapHandle
GetPortPixMap(CGrafPtr port);

/**
 *  GetPortBitMapForCopyBits()
 *
 *  Discussion:
 *    GetPortBitMapForCopyBits is provided for the specific purpose of
 *    using the return value as a parameter to CopyBits. The return
 *    value can be used as the srcBits or dstBits parameter to CopyBits
 *    regardless of whether the port is color. If the port parameter is
 *    a color port, however, the returned BitMapPtr does not actually
 *    point to a BitMap; it points to the PixMapHandle and other fields
 *    in the CGrafPort structure. You should not dereference the
 *    BitMapPtr or otherwise depend on its contents unless you've
 *    confirmed that this port is a non-color port.
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0.2 and later
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
const BitMap *
GetPortBitMapForCopyBits(CGrafPtr port);

/**
 *  GetPortBounds()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Rect *
GetPortBounds(CGrafPtr port, Rect *rect);

/**
 *  GetPortForeColor()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
RGBColor *
GetPortForeColor(CGrafPtr port, RGBColor *foreColor);

/**
 *  GetPortBackColor()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
RGBColor *
GetPortBackColor(CGrafPtr port, RGBColor *backColor);

/**
 *  GetPortOpColor()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
RGBColor *
GetPortOpColor(CGrafPtr port, RGBColor *opColor);

/**
 *  GetPortHiliteColor()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
RGBColor *
GetPortHiliteColor(CGrafPtr port, RGBColor *hiliteColor);

/**
 *  GetPortGrafProcs()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
CQDProcsPtr
GetPortGrafProcs(CGrafPtr port);

/**
 *  GetPortTextFont()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
short GetPortTextFont(CGrafPtr port);

/**
 *  GetPortTextFace()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Style GetPortTextFace(CGrafPtr port);

/**
 *  GetPortTextMode()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
short GetPortTextMode(CGrafPtr port);

/**
 *  GetPortTextSize()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
short GetPortTextSize(CGrafPtr port);

/**
 *  GetPortChExtra()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
short GetPortChExtra(CGrafPtr port);

/**
 *  GetPortFracHPenLocation()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
short GetPortFracHPenLocation(CGrafPtr port);

/**
 *  GetPortSpExtra()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Fixed GetPortSpExtra(CGrafPtr port);

/**
 *  GetPortPenVisibility()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
short GetPortPenVisibility(CGrafPtr port);

/**
 *  GetPortVisibleRegion()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
RgnHandle
GetPortVisibleRegion(CGrafPtr port, RgnHandle visRgn);

/**
 *  GetPortClipRegion()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
RgnHandle
GetPortClipRegion(CGrafPtr port, RgnHandle clipRgn);

/**
 *  GetPortBackPixPat()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
PixPatHandle
GetPortBackPixPat(CGrafPtr port, PixPatHandle backPattern);

/**
 *  GetPortPenPixPat()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
PixPatHandle
GetPortPenPixPat(CGrafPtr port, PixPatHandle penPattern);

/**
 *  GetPortFillPixPat()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
PixPatHandle
GetPortFillPixPat(CGrafPtr port, PixPatHandle fillPattern);

/**
 *  GetPortPenSize()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Point *
GetPortPenSize(CGrafPtr port, Point *penSize);

/**
 *  GetPortPenMode()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt32
GetPortPenMode(CGrafPtr port);

/**
 *  GetPortPenLocation()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Point *
GetPortPenLocation(CGrafPtr port, Point *penLocation);

/**
 *  IsPortRegionBeingDefined()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
IsPortRegionBeingDefined(CGrafPtr port);

/**
 *  IsPortPictureBeingDefined()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
IsPortPictureBeingDefined(CGrafPtr port);

/**
 *  IsPortPolyBeingDefined()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.3 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
IsPortPolyBeingDefined(CGrafPtr port);

/**
 *  IsPortOffscreen()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
IsPortOffscreen(CGrafPtr port);

/**
 *  IsPortColor()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0.2 and later
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
IsPortColor(CGrafPtr port);

/**
 *  IsPortVisibleRegionEmpty()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.1 and later
 */
Boolean
IsPortVisibleRegionEmpty(CGrafPtr port);

/**
 *  IsPortClipRegionEmpty()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.1 and later
 */
Boolean
IsPortClipRegionEmpty(CGrafPtr port);

/**
 *  SectRegionWithPortClipRegion()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.1 and later
 */
void SectRegionWithPortClipRegion(CGrafPtr port, RgnHandle ioRegion);

/**
 *  SectRegionWithPortVisibleRegion()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.1 and later
 */
void SectRegionWithPortVisibleRegion(CGrafPtr port, RgnHandle ioRegion);

/* Swappers */
/**
 *  SwapPortPicSaveHandle()
 *
 *  Summary:
 *    Sets the port's picSave Handle, and returns the previous picSave
 *
 *  Discussion:
 *    Historically, the picSave field in a GrafPort is != NULL if a
 *    Picture is being defined; and it has been documented that picture
 *    definition can be temporarily suspended by saving the current
 *    picSave Handle and setting picSave to NULL. Restoring the saved
 *    picSave Handle resumes picture definition.
 *
 *  Parameters:
 *
 *    port:
 *      The port whose picSave field is being swapped.
 *
 *    inPicSaveHdl:
 *      The picSave Handle to be set.
 *
 *  Result:
 *    The previous picSave Handle in the port.
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.5 and later
 *    \mac_os_x         in version 10.1 and later
 */
Handle
SwapPortPicSaveHandle(CGrafPtr port, Handle inPicSaveHdl);

/* Setters */
/**
 *  SetPortBounds()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetPortBounds(CGrafPtr port, const Rect *rect);

/**
 *  SetPortOpColor()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetPortOpColor(CGrafPtr port, const RGBColor *opColor);

/**
 *  SetPortGrafProcs()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetPortGrafProcs(CGrafPtr port, CQDProcsPtr procs);

/**
 *  SetPortTextFont()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.5 and later
 *    \mac_os_x         in version 10.1 and later
 */
void SetPortTextFont(CGrafPtr port, short txFont);

/**
 *  SetPortTextSize()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.5 and later
 *    \mac_os_x         in version 10.1 and later
 */
void SetPortTextSize(CGrafPtr port, short txSize);

/**
 *  SetPortTextFace()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.5 and later
 *    \mac_os_x         in version 10.1 and later
 */
void SetPortTextFace(CGrafPtr port, StyleParameter face);

/**
 *  SetPortTextMode()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.5 and later
 *    \mac_os_x         in version 10.1 and later
 */
void SetPortTextMode(CGrafPtr port, short mode);

/**
 *  SetPortVisibleRegion()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetPortVisibleRegion(CGrafPtr port, RgnHandle visRgn);

/**
 *  SetPortClipRegion()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetPortClipRegion(CGrafPtr port, RgnHandle clipRgn);

/**
 *  SetPortPenPixPat()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetPortPenPixPat(CGrafPtr port, PixPatHandle penPattern);

/**
 *  SetPortFillPixPat()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.2 and later
 *    \carbon_lib        in CarbonLib 1.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetPortFillPixPat(CGrafPtr port, PixPatHandle penPattern);

/**
 *  SetPortBackPixPat()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetPortBackPixPat(CGrafPtr port, PixPatHandle backPattern);

/**
 *  SetPortPenSize()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetPortPenSize(CGrafPtr port, Point penSize);

/**
 *  SetPortPenMode()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetPortPenMode(CGrafPtr port, SInt32 penMode);

/**
 *  SetPortFracHPenLocation()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetPortFracHPenLocation(CGrafPtr port, short pnLocHFrac);

/* PixMap */
/**
 *  GetPixBounds()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Rect *
GetPixBounds(PixMapHandle pixMap, Rect *bounds);

/**
 *  GetPixDepth()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
short GetPixDepth(PixMapHandle pixMap);

/* QDGlobals */
/* Getters */
/**
 *  GetQDGlobalsRandomSeed()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
long GetQDGlobalsRandomSeed(void);

/**
 *  GetQDGlobalsScreenBits()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
BitMap *
GetQDGlobalsScreenBits(BitMap *screenBits);

/**
 *  GetQDGlobalsArrow()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Cursor *
GetQDGlobalsArrow(Cursor *arrow);

/**
 *  GetQDGlobalsDarkGray()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Pattern *
GetQDGlobalsDarkGray(Pattern *dkGray);

/**
 *  GetQDGlobalsLightGray()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Pattern *
GetQDGlobalsLightGray(Pattern *ltGray);

/**
 *  GetQDGlobalsGray()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Pattern *
GetQDGlobalsGray(Pattern *gray);

/**
 *  GetQDGlobalsBlack()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Pattern *
GetQDGlobalsBlack(Pattern *black);

/**
 *  GetQDGlobalsWhite()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Pattern *
GetQDGlobalsWhite(Pattern *white);

/**
 *  GetQDGlobalsThePort()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
CGrafPtr
GetQDGlobalsThePort(void);

/* Setters */
/**
 *  SetQDGlobalsRandomSeed()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetQDGlobalsRandomSeed(long randomSeed);

/**
 *  SetQDGlobalsArrow()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetQDGlobalsArrow(const Cursor *arrow);

/* Regions */
/**
 *  GetRegionBounds()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Rect *
GetRegionBounds(RgnHandle region, Rect *bounds);

/**
 *  IsRegionRectangular()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
IsRegionRectangular(RgnHandle region);

/* Utilities */
/* To prevent upward dependencies, GetWindowFromPort() is defined in Window
 * Manager interface: */
/*      pascal WindowRef        GetWindowFromPort(CGrafPtr port); */
/* NewPtr/OpenCPort doesn't work with opaque structures */
/**
 *  CreateNewPort()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
CGrafPtr
CreateNewPort(void);

/**
 *  DisposePort()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void DisposePort(CGrafPtr port);

/**
 *  SetQDError()
 *
 *  Availability:
 *    \non_carbon_cfm   in CarbonAccessors.o 1.0.2 and later
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
void SetQDError(OSErr err);

#endif /* ACCESSOR_CALLS_ARE_FUNCTIONS */

/**
   Routines available on Mac OS X to flush buffered window ports...
   These calls do nothing on Mac OS 8/9. QDIsPortBuffered will always return
   false there.
*/

/**
 *  QDIsPortBuffered()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
QDIsPortBuffered(CGrafPtr port);

/**
 *  QDIsPortBufferDirty()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
QDIsPortBufferDirty(CGrafPtr port);

/**
 *  QDFlushPortBuffer()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0.2 and later
 *    \mac_os_x         in version 10.0 and later
 */
void QDFlushPortBuffer(CGrafPtr port, RgnHandle region); /* can be NULL */

/**
 *  QDGetDirtyRegion()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
QDGetDirtyRegion(CGrafPtr port, RgnHandle rgn);

/**
 *  QDSetDirtyRegion()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
QDSetDirtyRegion(CGrafPtr port, RgnHandle rgn);

/**
 *  QDAddRectToDirtyRegion()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.5 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
QDAddRectToDirtyRegion(CGrafPtr inPort, const Rect *inBounds);

/**
 *  QDAddRegionToDirtyRegion()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.5 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSStatus
QDAddRegionToDirtyRegion(CGrafPtr inPort, RgnHandle inRegion);

/**
 *  CreateCGContextForPort()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 * X version 10.0 and later \mac_os_x         in version 10.0 and later
 */
OSStatus
CreateCGContextForPort(CGrafPtr inPort, CGContextRef *outContext);

/**
 *  ClipCGContextToRegion()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 * X version 10.0 and later \mac_os_x         in version 10.0 and later
 */
OSStatus
ClipCGContextToRegion(CGContextRef gc, const Rect *portRect, RgnHandle region);

/**
 *  SyncCGContextOriginWithPort()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 * X version 10.0 and later \mac_os_x         in version 10.0 and later
 */
OSStatus
SyncCGContextOriginWithPort(CGContextRef inContext, CGrafPtr port);

/**
 *  QDBeginCGContext()
 *
 *  Summary:
 *    Allow CoreGraphics drawing in a CGrafPort
 *
 *  Discussion:
 *    So far, CreateCGContextForPort() was used to create a CGContext
 *    for CG drawing from a CGrafPort. However, if the current port is
 *    a printing port, the CreateCGContextForPort fails; consequently,
 *    there was no way to mix Quickdraw and CoreGraphics drawing and
 *    still print it. If, instead, the CoreGraphics drawing is
 *    bracketed by QDBeginCGContext/QDEndCGContext calls, the drawing
 *    will also appear in print. There are some restrictions on the
 *    usage of QDBeginCGContext/QDEndCGContext:
 *    - Between QDBeginCGContext and QDEndCGContext, Quickdraw drawing
 *    is disabled; only CoreGraphics drawing is allowed
 *    - QDBeginCGContext/QDEndCGContext calls can not be nested
 *    - QDEndCGContext releases the CGContext returned from
 *    QDBeginCGContext and sets it to NULL.
 *
 *  Parameters:
 *
 *    inPort:
 *      The current port
 *
 *    outContext:
 *      The CGContextRef to be used for CG drawing
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 * X version 10.1 and later \mac_os_x         in version 10.1 and later
 */
OSStatus
QDBeginCGContext(CGrafPtr inPort, CGContextRef *outContext);

/**
 *  QDEndCGContext()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 * X version 10.1 and later \mac_os_x         in version 10.1 and later
 */
OSStatus
QDEndCGContext(CGrafPtr inPort, CGContextRef *inoutContext);

/**
    The following routines are implemented in CarbonLib, and on Mac OS X in QD
   proper. They save the pixel data of a region in a packed format for quick
   save/restore without using a lot of memory to do a large, hollow region, such
   as the region used when drag hiliting (which is where this is used).
*/

typedef struct OpaqueQDRegionBitsRef *QDRegionBitsRef;
/**
 *  QDSaveRegionBits()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.1 and later
 */
QDRegionBitsRef
QDSaveRegionBits(RgnHandle region);

/**
 *  QDRestoreRegionBits()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.1 and later
 */
OSStatus
QDRestoreRegionBits(RgnHandle region, QDRegionBitsRef regionBits);

/**
 *  QDDisposeRegionBits()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.1 and later
 */
OSStatus
QDDisposeRegionBits(QDRegionBitsRef regionBits);

/**
   Developers need a way to go from a CGDirectDisplay environment to Quickdraw.
   The following is equivalent to CreateNewPort(), but instead of taking the
   portPixMap from the current GDevice, it uses the GDevice corresponding to
   the CGSDisplayID passed in. If the CGSDisplayID is invalid, the mainDevice
   is used instead.
*/
/**
 *  CreateNewPortForCGDisplayID()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 * X version 10.0 and later \mac_os_x         in version 10.0 and later
 */
CGrafPtr
CreateNewPortForCGDisplayID(UInt32 inCGDisplayID);

/**
   In Mac OS X, developers should be able to turn the WaitCursor (spinning
   wheel) on and off. QDDisplayWaitCursor() keeps track of nested calls. Passing
   FALSE will resume automatic wait cursor operation. Call this function only
   from an application in the foreground.
*/
/**
 *  QDDisplayWaitCursor()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 * X version 10.0 and later \mac_os_x         in version 10.0 and later
 */
void QDDisplayWaitCursor(Boolean forceWaitCursor);

/**
 *  QDSetPatternOrigin()
 *
 *  Summary:
 *    Sets the pattern origin for the current port.
 *
 *  Discussion:
 *    When a QuickDraw drawing operation uses a pattern (either a
 *    black&white pattern or a PixPat), the pattern's image is aligned
 *    with port origin, modified by the pattern origin of the port. For
 *    example, if the background pattern is a 10x10 image, and a
 *    rectangle with coordinates (3, 3, 10, 10) is filled with that
 *    pattern, then only the bottom right 7x7 portion of the pattern
 *    image will be drawn into the rectangle. When drawing a pattern,
 *    QuickDraw always starts with the port origin and then adjusts it
 *    by the pattern origin to determine the actual origin point of
 *    pattern drawing. QDSetPatternOrigin can be used to set the
 *    pattern origin relative to the port origin. It is often used in
 *    conjuction with SetOrigin to maintain the pattern alignment at
 *    (0,0) in a window's content area, regardless of the port origin;
 *    for example, after changing the port's origin to (10,10), an
 *    application might change the port's pattern origin to (-10, -10)
 *    so that patterns are still aligned with the window's content area.
 *
 *  Parameters:
 *
 *    origin:
 *      The new pattern origin of the port.
 *
 *  Availability:
 *    \non_carbon_cfm   in NQD 8.5 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.1 and later
 */
void QDSetPatternOrigin(Point origin);

/**
 *  QDGetPatternOrigin()
 *
 *  Summary:
 *    Returns the pattern origin of the current port.
 *
 *  Parameters:
 *
 *    origin:
 *      On exit, contains the current port's pattern origin.
 *
 *  Availability:
 *    \non_carbon_cfm   in NQD 8.5 and later
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.1 and later
 */
void QDGetPatternOrigin(Point *origin);

/**
    LowMem accessor functions previously in LowMem.h
*/
/**
 *  LMGetScrVRes()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt16
LMGetScrVRes(void);

/**
 *  LMSetScrVRes()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetScrVRes(SInt16 value);

/**
 *  LMGetScrHRes()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt16
LMGetScrHRes(void);

/**
 *  LMSetScrHRes()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetScrHRes(SInt16 value);

/**
 *  LMGetMainDevice()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
GDHandle
LMGetMainDevice(void);

/**
 *  LMSetMainDevice()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetMainDevice(GDHandle value);

/**
 *  LMGetDeviceList()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
GDHandle
LMGetDeviceList(void);

/**
 *  LMSetDeviceList()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetDeviceList(GDHandle value);

/**
 *  LMGetQDColors()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Handle
LMGetQDColors(void);

/**
 *  LMSetQDColors()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetQDColors(Handle value);

/**
 *  LMGetWidthListHand()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Handle
LMGetWidthListHand(void);

/**
 *  LMSetWidthListHand()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetWidthListHand(Handle value);

/**
 *  LMGetHiliteMode()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
UInt8 LMGetHiliteMode(void);

/**
 *  LMSetHiliteMode()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetHiliteMode(UInt8 value);

/**
 *  LMGetWidthPtr()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Ptr LMGetWidthPtr(void);

/**
 *  LMSetWidthPtr()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetWidthPtr(Ptr value);

/**
 *  LMGetWidthTabHandle()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Handle
LMGetWidthTabHandle(void);

/**
 *  LMSetWidthTabHandle()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetWidthTabHandle(Handle value);

/**
 *  LMGetLastSPExtra()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt32
LMGetLastSPExtra(void);

/**
 *  LMSetLastSPExtra()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetLastSPExtra(SInt32 value);

/**
 *  LMGetLastFOND()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Handle
LMGetLastFOND(void);

/**
 *  LMSetLastFOND()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetLastFOND(Handle value);

/**
 *  LMGetFractEnable()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
UInt8 LMGetFractEnable(void);

/**
 *  LMSetFractEnable()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetFractEnable(UInt8 value);

/**
 *  LMGetTheGDevice()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
GDHandle
LMGetTheGDevice(void);

/**
 *  LMSetTheGDevice()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetTheGDevice(GDHandle value);

#if TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#define LMGetHiliteRGB(hiliteRGBValue) (*(hiliteRGBValue) = *(RGBColor *)0x0DA0)
#define LMSetHiliteRGB(hiliteRGBValue) \
  ((*(RGBColor *)0x0DA0) = *(hiliteRGBValue))
#else
/**
 *  LMGetHiliteRGB()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMGetHiliteRGB(RGBColor *hiliteRGBValue);

/**
 *  LMSetHiliteRGB()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetHiliteRGB(const RGBColor *hiliteRGBValue);

#endif /* TARGET_CPU_68K && !TARGET_RT_MAC_CFM */

/**
 *  LMGetCursorNew()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
LMGetCursorNew(void);

/**
 *  LMSetCursorNew()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetCursorNew(Boolean value);

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

#endif /* __QUICKDRAW__ */
in CarbonLib 1.0 and later *    \mac_os_x in version 10.0 and later * / UInt8 LMGetHiliteMode(void);

/**
 *  LMSetHiliteMode()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetHiliteMode(UInt8 value);

/**
 *  LMGetWidthPtr()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Ptr LMGetWidthPtr(void);

/**
 *  LMSetWidthPtr()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetWidthPtr(Ptr value);

/**
 *  LMGetWidthTabHandle()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Handle
LMGetWidthTabHandle(void);

/**
 *  LMSetWidthTabHandle()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetWidthTabHandle(Handle value);

/**
 *  LMGetLastSPExtra()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
SInt32
LMGetLastSPExtra(void);

/**
 *  LMSetLastSPExtra()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetLastSPExtra(SInt32 value);

/**
 *  LMGetLastFOND()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Handle
LMGetLastFOND(void);

/**
 *  LMSetLastFOND()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetLastFOND(Handle value);

/**
 *  LMGetFractEnable()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
UInt8 LMGetFractEnable(void);

/**
 *  LMSetFractEnable()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetFractEnable(UInt8 value);

/**
 *  LMGetTheGDevice()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
GDHandle
LMGetTheGDevice(void);

/**
 *  LMSetTheGDevice()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetTheGDevice(GDHandle value);

#if TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#define LMGetHiliteRGB(hiliteRGBValue) (*(hiliteRGBValue) = *(RGBColor *)0x0DA0)
#define LMSetHiliteRGB(hiliteRGBValue) \
  ((*(RGBColor *)0x0DA0) = *(hiliteRGBValue))
#else
/**
 *  LMGetHiliteRGB()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMGetHiliteRGB(RGBColor *hiliteRGBValue);

/**
 *  LMSetHiliteRGB()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetHiliteRGB(const RGBColor *hiliteRGBValue);

#endif /* TARGET_CPU_68K && !TARGET_RT_MAC_CFM */

/**
 *  LMGetCursorNew()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
Boolean
LMGetCursorNew(void);

/**
 *  LMSetCursorNew()
 *
 *  Availability:
 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
void LMSetCursorNew(Boolean value);

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

#endif /* __QUICKDRAW__ */
