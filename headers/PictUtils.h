/**
     \file       PictUtils.h

    \brief   Picture Utilities Interfaces.

    \introduced_in  Mac OS 8.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1990-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Misc

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __PICTUTILS__
#define __PICTUTILS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __PALETTES__
#include <Palettes.h>
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

  /** verbs for the GetPictInfo, GetPixMapInfo, and NewPictInfo calls */
  enum
  {
    returnColorTable = 0x0001,
    returnPalette = 0x0002,
    recordComments = 0x0004,
    recordFontInfo = 0x0008,
    suppressBlackAndWhite = 0x0010
  };

  enum
  {
    /** color pick methods */
    systemMethod = 0,  /** system color pick method */
    popularMethod = 1, /** method that chooses the most popular set of colors */
    medianMethod = 2   /** method that chooses a good average mix of colors */
  };

  enum
  {
    /** color bank types */
    ColorBankIsCustom = -1,
    ColorBankIsExactAnd555 = 0,
    ColorBankIs555 = 1
  };

  typedef long PictInfoID;
  struct CommentSpec
  {
    short count; /** number of occurrances of this comment ID */
    short ID;    /** ID for the comment in the picture */
  };
  typedef struct CommentSpec CommentSpec;
  typedef CommentSpec *CommentSpecPtr;
  typedef CommentSpecPtr *CommentSpecHandle;
  struct FontSpec
  {
    short pictFontID; /** ID of the font in the picture */
    short sysFontID;  /** ID of the same font in the current system file */
    long size[4];     /** bit array of all the sizes found (1..127) (bit 0 means >
                         127) */
    short style;      /** combined style of all occurrances of the font */
    long
        nameOffset; /** offset into the fontNamesHdl handle for the font©s name */
  };
  typedef struct FontSpec FontSpec;
  typedef FontSpec *FontSpecPtr;
  typedef FontSpecPtr *FontSpecHandle;
  struct PictInfo
  {
    short version;                   /** this is always zero, for now */
    long uniqueColors;               /** the number of actual colors in the picture(s)/pixmap(s)
                                      */
    PaletteHandle thePalette;        /** handle to the palette information */
    CTabHandle theColorTable;        /** handle to the color table */
    Fixed hRes;                      /** maximum horizontal resolution for all the pixmaps */
    Fixed vRes;                      /** maximum vertical resolution for all the pixmaps */
    short depth;                     /** maximum depth for all the pixmaps (in the picture) */
    Rect sourceRect;                 /** the picture frame rectangle (this contains the entire
                                        picture) */
    long textCount;                  /** total number of text strings in the picture */
    long lineCount;                  /** total number of lines in the picture */
    long rectCount;                  /** total number of rectangles in the picture */
    long rRectCount;                 /** total number of round rectangles in the picture */
    long ovalCount;                  /** total number of ovals in the picture */
    long arcCount;                   /** total number of arcs in the picture */
    long polyCount;                  /** total number of polygons in the picture */
    long regionCount;                /** total number of regions in the picture */
    long bitMapCount;                /** total number of bitmaps in the picture */
    long pixMapCount;                /** total number of pixmaps in the picture */
    long commentCount;               /** total number of comments in the picture */
    long uniqueComments;             /** the number of unique comments in the picture */
    CommentSpecHandle commentHandle; /** handle to all the comment information */
    long uniqueFonts;                /** the number of unique fonts in the picture */
    FontSpecHandle fontHandle;       /** handle to the FontSpec information */
    Handle fontNamesHandle;          /** handle to the font names */
    long reserved1;
    long reserved2;
  };
  typedef struct PictInfo PictInfo;
  typedef PictInfo *PictInfoPtr;
  typedef PictInfoPtr *PictInfoHandle;
  typedef CALLBACK_API(OSErr, InitPickMethodProcPtr)(SInt16 colorsRequested,
                                                     UInt32 *dataRef,
                                                     SInt16 *colorBankType);
  typedef CALLBACK_API(OSErr, RecordColorsProcPtr)(UInt32 dataRef,
                                                   RGBColor *colorsArray,
                                                   SInt32 colorCount,
                                                   SInt32 *uniqueColors);
  typedef CALLBACK_API(OSErr, CalcColorTableProcPtr)(UInt32 dataRef,
                                                     SInt16 colorsRequested,
                                                     void *colorBankPtr,
                                                     CSpecArray resultPtr);
  typedef CALLBACK_API(OSErr, DisposeColorPickMethodProcPtr)(UInt32 dataRef);
  typedef STACK_UPP_TYPE(InitPickMethodProcPtr) InitPickMethodUPP;
  typedef STACK_UPP_TYPE(RecordColorsProcPtr) RecordColorsUPP;
  typedef STACK_UPP_TYPE(CalcColorTableProcPtr) CalcColorTableUPP;
  typedef STACK_UPP_TYPE(DisposeColorPickMethodProcPtr) DisposeColorPickMethodUPP;
  /**
   *  NewInitPickMethodUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  InitPickMethodUPP
  NewInitPickMethodUPP(InitPickMethodProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppInitPickMethodProcInfo = 0x00000FA0
  }; /** pascal 2_bytes Func(2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline InitPickMethodUPP
  NewInitPickMethodUPP(InitPickMethodProcPtr userRoutine)
  {
    return (InitPickMethodUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppInitPickMethodProcInfo,
                                                   GetCurrentArchitecture());
  }
#else
#define NewInitPickMethodUPP(userRoutine)                                     \
  (InitPickMethodUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppInitPickMethodProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewRecordColorsUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  RecordColorsUPP
  NewRecordColorsUPP(RecordColorsProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppRecordColorsProcInfo = 0x00003FE0
  }; /** pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline RecordColorsUPP NewRecordColorsUPP(RecordColorsProcPtr userRoutine)
  {
    return (RecordColorsUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppRecordColorsProcInfo,
                                                 GetCurrentArchitecture());
  }
#else
#define NewRecordColorsUPP(userRoutine)                                     \
  (RecordColorsUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppRecordColorsProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewCalcColorTableUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  CalcColorTableUPP
  NewCalcColorTableUPP(CalcColorTableProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppCalcColorTableProcInfo = 0x00003EE0
  }; /** pascal 2_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline CalcColorTableUPP
  NewCalcColorTableUPP(CalcColorTableProcPtr userRoutine)
  {
    return (CalcColorTableUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppCalcColorTableProcInfo,
                                                   GetCurrentArchitecture());
  }
#else
#define NewCalcColorTableUPP(userRoutine)                                     \
  (CalcColorTableUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppCalcColorTableProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewDisposeColorPickMethodUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  DisposeColorPickMethodUPP
  NewDisposeColorPickMethodUPP(DisposeColorPickMethodProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppDisposeColorPickMethodProcInfo = 0x000000E0
  }; /** pascal 2_bytes Func(4_bytes) */
#ifdef __cplusplus
  inline DisposeColorPickMethodUPP
  NewDisposeColorPickMethodUPP(DisposeColorPickMethodProcPtr userRoutine)
  {
    return (DisposeColorPickMethodUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppDisposeColorPickMethodProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewDisposeColorPickMethodUPP(userRoutine)                \
  (DisposeColorPickMethodUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppDisposeColorPickMethodProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeInitPickMethodUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeInitPickMethodUPP(InitPickMethodUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeInitPickMethodUPP(InitPickMethodUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeInitPickMethodUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeRecordColorsUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeRecordColorsUPP(RecordColorsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeRecordColorsUPP(RecordColorsUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeRecordColorsUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeCalcColorTableUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeCalcColorTableUPP(CalcColorTableUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeCalcColorTableUPP(CalcColorTableUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeCalcColorTableUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeDisposeColorPickMethodUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeDisposeColorPickMethodUPP(DisposeColorPickMethodUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void
  DisposeDisposeColorPickMethodUPP(DisposeColorPickMethodUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeDisposeColorPickMethodUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeInitPickMethodUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeInitPickMethodUPP(SInt16 colorsRequested, UInt32 *dataRef,
                          SInt16 *colorBankType, InitPickMethodUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeInitPickMethodUPP(SInt16 colorsRequested, UInt32 *dataRef,
                                       SInt16 *colorBankType,
                                       InitPickMethodUPP userUPP)
  {
    return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppInitPickMethodProcInfo,
                                           colorsRequested, dataRef,
                                           colorBankType);
  }
#else
#define InvokeInitPickMethodUPP(colorsRequested, dataRef, colorBankType, \
                                userUPP)                                 \
  (OSErr)                                                                \
      CALL_THREE_PARAMETER_UPP((userUPP), uppInitPickMethodProcInfo,     \
                               (colorsRequested), (dataRef), (colorBankType))
#endif
#endif

  /**
   *  InvokeRecordColorsUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeRecordColorsUPP(UInt32 dataRef, RGBColor *colorsArray, SInt32 colorCount,
                        SInt32 *uniqueColors, RecordColorsUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeRecordColorsUPP(UInt32 dataRef, RGBColor *colorsArray,
                                     SInt32 colorCount, SInt32 *uniqueColors,
                                     RecordColorsUPP userUPP)
  {
    return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppRecordColorsProcInfo,
                                          dataRef, colorsArray, colorCount,
                                          uniqueColors);
  }
#else
#define InvokeRecordColorsUPP(dataRef, colorsArray, colorCount, uniqueColors, \
                              userUPP)                                        \
  (OSErr)                                                                     \
      CALL_FOUR_PARAMETER_UPP((userUPP), uppRecordColorsProcInfo, (dataRef),  \
                              (colorsArray), (colorCount), (uniqueColors))
#endif
#endif

  /**
   *  InvokeCalcColorTableUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeCalcColorTableUPP(UInt32 dataRef, SInt16 colorsRequested,
                          void *colorBankPtr, CSpecArray resultPtr,
                          CalcColorTableUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeCalcColorTableUPP(UInt32 dataRef, SInt16 colorsRequested,
                                       void *colorBankPtr, CSpecArray resultPtr,
                                       CalcColorTableUPP userUPP)
  {
    return (OSErr)CALL_FOUR_PARAMETER_UPP(userUPP, uppCalcColorTableProcInfo,
                                          dataRef, colorsRequested, colorBankPtr,
                                          resultPtr);
  }
#else
#define InvokeCalcColorTableUPP(dataRef, colorsRequested, colorBankPtr,        \
                                resultPtr, userUPP)                            \
  (OSErr)                                                                      \
      CALL_FOUR_PARAMETER_UPP((userUPP), uppCalcColorTableProcInfo, (dataRef), \
                              (colorsRequested), (colorBankPtr), (resultPtr))
#endif
#endif

  /**
   *  InvokeDisposeColorPickMethodUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeDisposeColorPickMethodUPP(UInt32 dataRef,
                                  DisposeColorPickMethodUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr
  InvokeDisposeColorPickMethodUPP(UInt32 dataRef,
                                  DisposeColorPickMethodUPP userUPP)
  {
    return (OSErr)CALL_ONE_PARAMETER_UPP(
        userUPP, uppDisposeColorPickMethodProcInfo, dataRef);
  }
#else
#define InvokeDisposeColorPickMethodUPP(dataRef, userUPP)                      \
  (OSErr) CALL_ONE_PARAMETER_UPP((userUPP), uppDisposeColorPickMethodProcInfo, \
                                 (dataRef))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewInitPickMethodProc(userRoutine) NewInitPickMethodUPP(userRoutine)
#define NewRecordColorsProc(userRoutine) NewRecordColorsUPP(userRoutine)
#define NewCalcColorTableProc(userRoutine) NewCalcColorTableUPP(userRoutine)
#define NewDisposeColorPickMethodProc(userRoutine) \
  NewDisposeColorPickMethodUPP(userRoutine)
#define CallInitPickMethodProc(userRoutine, colorsRequested, dataRef, \
                               colorBankType)                         \
  InvokeInitPickMethodUPP(colorsRequested, dataRef, colorBankType, userRoutine)
#define CallRecordColorsProc(userRoutine, dataRef, colorsArray, colorCount, \
                             uniqueColors)                                  \
  InvokeRecordColorsUPP(dataRef, colorsArray, colorCount, uniqueColors,     \
                        userRoutine)
#define CallCalcColorTableProc(userRoutine, dataRef, colorsRequested,        \
                               colorBankPtr, resultPtr)                      \
  InvokeCalcColorTableUPP(dataRef, colorsRequested, colorBankPtr, resultPtr, \
                          userRoutine)
#define CallDisposeColorPickMethodProc(userRoutine, dataRef) \
  InvokeDisposeColorPickMethodUPP(dataRef, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

  /**
   *  GetPictInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetPictInfo(PicHandle thePictHandle, PictInfo *thePictInfo, short verb,
              short colorsRequested, short colorPickMethod, short version);

  /**
   *  GetPixMapInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetPixMapInfo(PixMapHandle thePixMapHandle, PictInfo *thePictInfo, short verb,
                short colorsRequested, short colorPickMethod, short version);

  /**
   *  NewPictInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  NewPictInfo(PictInfoID *thePictInfoID, short verb, short colorsRequested,
              short colorPickMethod, short version);

  /**
   *  RecordPictInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  RecordPictInfo(PictInfoID thePictInfoID, PicHandle thePictHandle);

  /**
   *  RecordPixMapInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  RecordPixMapInfo(PictInfoID thePictInfoID, PixMapHandle thePixMapHandle);

  /**
   *  RetrievePictInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  RetrievePictInfo(PictInfoID thePictInfoID, PictInfo *thePictInfo,
                   short colorsRequested);

  /**
   *  DisposePictInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DisposePictInfo(PictInfoID thePictInfoID);

#if OLDROUTINENAMES
#define DisposPictInfo(thePictInfoID) DisposePictInfo(thePictInfoID)
#endif /** OLDROUTINENAMES */

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

#endif /** __PICTUTILS__ */
