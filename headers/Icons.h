/**
     \file       Icons.h

    \brief   Icon Utilities and Icon Services Interfaces.

    \introduced_in  Mac OS 9.x
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1990-2001 by Apple Computer, Inc. All rights reserved

    \ingroup System

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __ICONS__
#define __ICONS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __FILES__
#include <Files.h>
#endif

#ifndef __CODEFRAGMENTS__
#include <CodeFragments.h>
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

  /* The following are icons for which there are both icon suites and SICNs. */
  /* Avoid using icon resources if possible. Use IconServices instead. */
  enum
  {
    kGenericDocumentIconResource = -4000,
    kGenericStationeryIconResource = -3985,
    kGenericEditionFileIconResource = -3989,
    kGenericApplicationIconResource = -3996,
    kGenericDeskAccessoryIconResource = -3991,
    kGenericFolderIconResource = -3999,
    kPrivateFolderIconResource = -3994,
    kFloppyIconResource = -3998,
    kTrashIconResource = -3993,
    kGenericRAMDiskIconResource = -3988,
    kGenericCDROMIconResource = -3987
  };

  /* The following are icons for which there are SICNs only. */
  /* Avoid using icon resources if possible. Use IconServices instead. */
  enum
  {
    kDesktopIconResource = -3992,
    kOpenFolderIconResource = -3997,
    kGenericHardDiskIconResource = -3995,
    kGenericFileServerIconResource = -3972,
    kGenericSuitcaseIconResource = -3970,
    kGenericMoverObjectIconResource = -3969
  };

  /* The following are icons for which there are icon suites only. */
  /* Avoid using icon resources if possible. Use IconServices instead. */
  enum
  {
    kGenericPreferencesIconResource = -3971,
    kGenericQueryDocumentIconResource = -16506,
    kGenericExtensionIconResource = -16415,
    kSystemFolderIconResource = -3983,
    kHelpIconResource = -20271,
    kAppleMenuFolderIconResource = -3982
  };

  /* Obsolete. Use named constants defined above. */
  enum
  {
    genericDocumentIconResource = kGenericDocumentIconResource,
    genericStationeryIconResource = kGenericStationeryIconResource,
    genericEditionFileIconResource = kGenericEditionFileIconResource,
    genericApplicationIconResource = kGenericApplicationIconResource,
    genericDeskAccessoryIconResource = kGenericDeskAccessoryIconResource,
    genericFolderIconResource = kGenericFolderIconResource,
    privateFolderIconResource = kPrivateFolderIconResource,
    floppyIconResource = kFloppyIconResource,
    trashIconResource = kTrashIconResource,
    genericRAMDiskIconResource = kGenericRAMDiskIconResource,
    genericCDROMIconResource = kGenericCDROMIconResource,
    desktopIconResource = kDesktopIconResource,
    openFolderIconResource = kOpenFolderIconResource,
    genericHardDiskIconResource = kGenericHardDiskIconResource,
    genericFileServerIconResource = kGenericFileServerIconResource,
    genericSuitcaseIconResource = kGenericSuitcaseIconResource,
    genericMoverObjectIconResource = kGenericMoverObjectIconResource,
    genericPreferencesIconResource = kGenericPreferencesIconResource,
    genericQueryDocumentIconResource = kGenericQueryDocumentIconResource,
    genericExtensionIconResource = kGenericExtensionIconResource,
    systemFolderIconResource = kSystemFolderIconResource,
    appleMenuFolderIconResource = kAppleMenuFolderIconResource
  };

  /* Avoid using icon resources if possible. Use IconServices instead. */
  enum
  {
    kStartupFolderIconResource = -3981,
    kOwnedFolderIconResource = -3980,
    kDropFolderIconResource = -3979,
    kSharedFolderIconResource = -3978,
    kMountedFolderIconResource = -3977,
    kControlPanelFolderIconResource = -3976,
    kPrintMonitorFolderIconResource = -3975,
    kPreferencesFolderIconResource = -3974,
    kExtensionsFolderIconResource = -3973,
    kFontsFolderIconResource = -3968,
    kFullTrashIconResource = -3984
  };

  /* Obsolete. Use named constants defined above. */
  enum
  {
    startupFolderIconResource = kStartupFolderIconResource,
    ownedFolderIconResource = kOwnedFolderIconResource,
    dropFolderIconResource = kDropFolderIconResource,
    sharedFolderIconResource = kSharedFolderIconResource,
    mountedFolderIconResource = kMountedFolderIconResource,
    controlPanelFolderIconResource = kControlPanelFolderIconResource,
    printMonitorFolderIconResource = kPrintMonitorFolderIconResource,
    preferencesFolderIconResource = kPreferencesFolderIconResource,
    extensionsFolderIconResource = kExtensionsFolderIconResource,
    fontsFolderIconResource = kFontsFolderIconResource,
    fullTrashIconResource = kFullTrashIconResource
  };

  /* The following icon types can only be used as an icon element */
  /* inside a 'icns' icon family */
  enum
  {
    kThumbnail32BitData = FOUR_CHAR_CODE('it32'),
    kThumbnail8BitMask = FOUR_CHAR_CODE('t8mk')
  };

  enum
  {
    kHuge1BitMask = FOUR_CHAR_CODE('ich#'),
    kHuge4BitData = FOUR_CHAR_CODE('ich4'),
    kHuge8BitData = FOUR_CHAR_CODE('ich8'),
    kHuge32BitData = FOUR_CHAR_CODE('ih32'),
    kHuge8BitMask = FOUR_CHAR_CODE('h8mk')
  };

  /* The following icon types can be used as a resource type */
  /* or as an icon element type inside a 'icns' icon family */
  enum
  {
    kLarge1BitMask = FOUR_CHAR_CODE('ICN#'),
    kLarge4BitData = FOUR_CHAR_CODE('icl4'),
    kLarge8BitData = FOUR_CHAR_CODE('icl8'),
    kLarge32BitData = FOUR_CHAR_CODE('il32'),
    kLarge8BitMask = FOUR_CHAR_CODE('l8mk'),
    kSmall1BitMask = FOUR_CHAR_CODE('ics#'),
    kSmall4BitData = FOUR_CHAR_CODE('ics4'),
    kSmall8BitData = FOUR_CHAR_CODE('ics8'),
    kSmall32BitData = FOUR_CHAR_CODE('is32'),
    kSmall8BitMask = FOUR_CHAR_CODE('s8mk'),
    kMini1BitMask = FOUR_CHAR_CODE('icm#'),
    kMini4BitData = FOUR_CHAR_CODE('icm4'),
    kMini8BitData = FOUR_CHAR_CODE('icm8')
  };

  /*  Icon Variants */
  /* These can be used as an element of an 'icns' icon family */
  /* or as a parameter to GetIconRefVariant */
  enum
  {
    kTileIconVariant = FOUR_CHAR_CODE('tile'),
    kRolloverIconVariant = FOUR_CHAR_CODE('over'),
    kDropIconVariant = FOUR_CHAR_CODE('drop'),
    kOpenIconVariant = FOUR_CHAR_CODE('open'),
    kOpenDropIconVariant = FOUR_CHAR_CODE('odrp')
  };

  /* Obsolete. Use names defined above. */
  enum
  {
    large1BitMask = kLarge1BitMask,
    large4BitData = kLarge4BitData,
    large8BitData = kLarge8BitData,
    small1BitMask = kSmall1BitMask,
    small4BitData = kSmall4BitData,
    small8BitData = kSmall8BitData,
    mini1BitMask = kMini1BitMask,
    mini4BitData = kMini4BitData,
    mini8BitData = kMini8BitData
  };

  /* Alignment type values. */
  enum
  {
    kAlignNone = 0x00,
    kAlignVerticalCenter = 0x01,
    kAlignTop = 0x02,
    kAlignBottom = 0x03,
    kAlignHorizontalCenter = 0x04,
    kAlignAbsoluteCenter = kAlignVerticalCenter | kAlignHorizontalCenter,
    kAlignCenterTop = kAlignTop | kAlignHorizontalCenter,
    kAlignCenterBottom = kAlignBottom | kAlignHorizontalCenter,
    kAlignLeft = 0x08,
    kAlignCenterLeft = kAlignVerticalCenter | kAlignLeft,
    kAlignTopLeft = kAlignTop | kAlignLeft,
    kAlignBottomLeft = kAlignBottom | kAlignLeft,
    kAlignRight = 0x0C,
    kAlignCenterRight = kAlignVerticalCenter | kAlignRight,
    kAlignTopRight = kAlignTop | kAlignRight,
    kAlignBottomRight = kAlignBottom | kAlignRight
  };

  /* Obsolete. Use names defined above. */
  enum
  {
    atNone = kAlignNone,
    atVerticalCenter = kAlignVerticalCenter,
    atTop = kAlignTop,
    atBottom = kAlignBottom,
    atHorizontalCenter = kAlignHorizontalCenter,
    atAbsoluteCenter = kAlignAbsoluteCenter,
    atCenterTop = kAlignCenterTop,
    atCenterBottom = kAlignCenterBottom,
    atLeft = kAlignLeft,
    atCenterLeft = kAlignCenterLeft,
    atTopLeft = kAlignTopLeft,
    atBottomLeft = kAlignBottomLeft,
    atRight = kAlignRight,
    atCenterRight = kAlignCenterRight,
    atTopRight = kAlignTopRight,
    atBottomRight = kAlignBottomRight
  };

  typedef SInt16 IconAlignmentType;
  /* Transform type values. */
  enum
  {
    kTransformNone = 0x00,
    kTransformDisabled = 0x01,
    kTransformOffline = 0x02,
    kTransformOpen = 0x03,
    kTransformLabel1 = 0x0100,
    kTransformLabel2 = 0x0200,
    kTransformLabel3 = 0x0300,
    kTransformLabel4 = 0x0400,
    kTransformLabel5 = 0x0500,
    kTransformLabel6 = 0x0600,
    kTransformLabel7 = 0x0700,
    kTransformSelected = 0x4000,
    kTransformSelectedDisabled = kTransformSelected | kTransformDisabled,
    kTransformSelectedOffline = kTransformSelected | kTransformOffline,
    kTransformSelectedOpen = kTransformSelected | kTransformOpen
  };

  /* Obsolete. Use names defined above. */
  enum
  {
    ttNone = kTransformNone,
    ttDisabled = kTransformDisabled,
    ttOffline = kTransformOffline,
    ttOpen = kTransformOpen,
    ttLabel1 = kTransformLabel1,
    ttLabel2 = kTransformLabel2,
    ttLabel3 = kTransformLabel3,
    ttLabel4 = kTransformLabel4,
    ttLabel5 = kTransformLabel5,
    ttLabel6 = kTransformLabel6,
    ttLabel7 = kTransformLabel7,
    ttSelected = kTransformSelected,
    ttSelectedDisabled = kTransformSelectedDisabled,
    ttSelectedOffline = kTransformSelectedOffline,
    ttSelectedOpen = kTransformSelectedOpen
  };

  typedef SInt16 IconTransformType;
  /* Selector mask values. */
  enum
  {
    kSelectorLarge1Bit = 0x00000001,
    kSelectorLarge4Bit = 0x00000002,
    kSelectorLarge8Bit = 0x00000004,
    kSelectorLarge32Bit = 0x00000008,
    kSelectorLarge8BitMask = 0x00000010,
    kSelectorSmall1Bit = 0x00000100,
    kSelectorSmall4Bit = 0x00000200,
    kSelectorSmall8Bit = 0x00000400,
    kSelectorSmall32Bit = 0x00000800,
    kSelectorSmall8BitMask = 0x00001000,
    kSelectorMini1Bit = 0x00010000,
    kSelectorMini4Bit = 0x00020000,
    kSelectorMini8Bit = 0x00040000,
    kSelectorHuge1Bit = 0x01000000,
    kSelectorHuge4Bit = 0x02000000,
    kSelectorHuge8Bit = 0x04000000,
    kSelectorHuge32Bit = 0x08000000,
    kSelectorHuge8BitMask = 0x10000000,
    kSelectorAllLargeData = 0x000000FF,
    kSelectorAllSmallData = 0x0000FF00,
    kSelectorAllMiniData = 0x00FF0000,
    kSelectorAllHugeData = (long)0xFF000000,
    kSelectorAll1BitData = kSelectorLarge1Bit | kSelectorSmall1Bit |
                           kSelectorMini1Bit | kSelectorHuge1Bit,
    kSelectorAll4BitData = kSelectorLarge4Bit | kSelectorSmall4Bit |
                           kSelectorMini4Bit | kSelectorHuge4Bit,
    kSelectorAll8BitData = kSelectorLarge8Bit | kSelectorSmall8Bit |
                           kSelectorMini8Bit | kSelectorHuge8Bit,
    kSelectorAll32BitData =
        kSelectorLarge32Bit | kSelectorSmall32Bit | kSelectorHuge32Bit,
    kSelectorAllAvailableData = (long)0xFFFFFFFF
  };

  /* Obsolete. Use names defined above. */
  enum
  {
    svLarge1Bit = kSelectorLarge1Bit,
    svLarge4Bit = kSelectorLarge4Bit,
    svLarge8Bit = kSelectorLarge8Bit,
    svSmall1Bit = kSelectorSmall1Bit,
    svSmall4Bit = kSelectorSmall4Bit,
    svSmall8Bit = kSelectorSmall8Bit,
    svMini1Bit = kSelectorMini1Bit,
    svMini4Bit = kSelectorMini4Bit,
    svMini8Bit = kSelectorMini8Bit,
    svAllLargeData = kSelectorAllLargeData,
    svAllSmallData = kSelectorAllSmallData,
    svAllMiniData = kSelectorAllMiniData,
    svAll1BitData = kSelectorAll1BitData,
    svAll4BitData = kSelectorAll4BitData,
    svAll8BitData = kSelectorAll8BitData,
    svAllAvailableData = kSelectorAllAvailableData
  };

  typedef UInt32 IconSelectorValue;
  typedef CALLBACK_API(OSErr, IconActionProcPtr)(ResType theType, Handle *theIcon,
                                                 void *yourDataPtr);
  typedef CALLBACK_API(Handle, IconGetterProcPtr)(ResType theType,
                                                  void *yourDataPtr);
  typedef STACK_UPP_TYPE(IconActionProcPtr) IconActionUPP;
  typedef STACK_UPP_TYPE(IconGetterProcPtr) IconGetterUPP;
  /**
   *  NewIconActionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  IconActionUPP
  NewIconActionUPP(IconActionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppIconActionProcInfo = 0x00000FE0
  }; /* pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline IconActionUPP NewIconActionUPP(IconActionProcPtr userRoutine)
  {
    return (IconActionUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppIconActionProcInfo, GetCurrentArchitecture());
  }
#else
#define NewIconActionUPP(userRoutine)   \
  (IconActionUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppIconActionProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewIconGetterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  IconGetterUPP
  NewIconGetterUPP(IconGetterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppIconGetterProcInfo = 0x000003F0
  }; /* pascal 4_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline IconGetterUPP NewIconGetterUPP(IconGetterProcPtr userRoutine)
  {
    return (IconGetterUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppIconGetterProcInfo, GetCurrentArchitecture());
  }
#else
#define NewIconGetterUPP(userRoutine)   \
  (IconGetterUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppIconGetterProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeIconActionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeIconActionUPP(IconActionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeIconActionUPP(IconActionUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeIconActionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeIconGetterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeIconGetterUPP(IconGetterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeIconGetterUPP(IconGetterUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeIconGetterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeIconActionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeIconActionUPP(ResType theType, Handle *theIcon, void *yourDataPtr,
                      IconActionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr InvokeIconActionUPP(ResType theType, Handle *theIcon,
                                   void *yourDataPtr, IconActionUPP userUPP)
  {
    return (OSErr)CALL_THREE_PARAMETER_UPP(userUPP, uppIconActionProcInfo,
                                           theType, theIcon, yourDataPtr);
  }
#else
#define InvokeIconActionUPP(theType, theIcon, yourDataPtr, userUPP)  \
  (OSErr) CALL_THREE_PARAMETER_UPP((userUPP), uppIconActionProcInfo, \
                                   (theType), (theIcon), (yourDataPtr))
#endif
#endif

  /**
   *  InvokeIconGetterUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Handle
  InvokeIconGetterUPP(ResType theType, void *yourDataPtr, IconGetterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline Handle InvokeIconGetterUPP(ResType theType, void *yourDataPtr,
                                    IconGetterUPP userUPP)
  {
    return (Handle)CALL_TWO_PARAMETER_UPP(userUPP, uppIconGetterProcInfo, theType,
                                          yourDataPtr);
  }
#else
#define InvokeIconGetterUPP(theType, yourDataPtr, userUPP)                     \
  (Handle) CALL_TWO_PARAMETER_UPP((userUPP), uppIconGetterProcInfo, (theType), \
                                  (yourDataPtr))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewIconActionProc(userRoutine) NewIconActionUPP(userRoutine)
#define NewIconGetterProc(userRoutine) NewIconGetterUPP(userRoutine)
#define CallIconActionProc(userRoutine, theType, theIcon, yourDataPtr) \
  InvokeIconActionUPP(theType, theIcon, yourDataPtr, userRoutine)
#define CallIconGetterProc(userRoutine, theType, yourDataPtr) \
  InvokeIconGetterUPP(theType, yourDataPtr, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

  typedef IconGetterProcPtr IconGetter;
  typedef IconActionProcPtr IconAction;
  /* CIconHandle, GetCIcon(), PlotCIcon(), and DisposeCIcon() moved here from
   * Quickdraw.h*/
  struct CIcon
  {
    PixMap iconPMap;        /*the icon's pixMap*/
    BitMap iconMask;        /*the icon's mask*/
    BitMap iconBMap;        /*the icon's bitMap*/
    Handle iconData;        /*the icon's data*/
    SInt16 iconMaskData[1]; /*icon's mask and BitMap data*/
  };
  typedef struct CIcon CIcon;
  typedef CIcon *CIconPtr;
  typedef CIconPtr *CIconHandle;
  /**
   *  GetCIcon()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  CIconHandle
  GetCIcon(SInt16 iconID);

  /**
   *  PlotCIcon()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  PlotCIcon(const Rect *theRect, CIconHandle theIcon);

  /**
   *  DisposeCIcon()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeCIcon(CIconHandle theIcon);

  /* GetIcon and PlotIcon moved here from ToolUtils*/
  /**
   *  GetIcon()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Handle
  GetIcon(SInt16 iconID);

  /**
   *  PlotIcon()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  PlotIcon(const Rect *theRect, Handle theIcon);

  /**
      Note:   IconSuiteRef and IconCacheRef should be an abstract types,
              but too much source code already relies on them being of type
     Handle.
  */
  typedef Handle IconSuiteRef;
  typedef Handle IconCacheRef;
  /* IconRefs are 32-bit values identifying cached icon data. IconRef 0 is
   * invalid.*/
  typedef struct OpaqueIconRef *IconRef;
  /**
   *  PlotIconID()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  PlotIconID(const Rect *theRect, IconAlignmentType align,
             IconTransformType transform, SInt16 theResID);

  /**
   *  NewIconSuite()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  NewIconSuite(IconSuiteRef *theIconSuite);

  /**
  \brief Add an icon to an icon family

  <pre>AddIconToSuite adds the data in theIconData into the the icon family
referenced by theSuite at the location reseved for theType of icon data.
AddIconToSuite will replace any old data in that slot without disposing of it,
so you may want to call GetIconFromSuite to obtain the old handle (if any),
to dispose. AddIconToSuite is use most often with NewIconSuite to fill an
empty family after it has been created.
</pre>
* \note <pre>This routine is not currently documented in MPW header files (hence, it is
not in any THINK C or THINK Pascal header file either). The information
given above comes from Macintosh Technical Note #306. This tech. note
also gives the inline glue for the call as follows:
pascal OSErr AddIconToSuite (Handle theIconData, Handle theSuite,
ResType theType) = {0x303C, 0x0608, 0xABC9};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  AddIconToSuite(Handle theIconData, IconSuiteRef theSuite, ResType theType);

  /**
  \brief GetIconFromSuite Obtain a specified icon from an icon family

  <pre>GetIconFromSuite returns a handle to the pixel data of the family member
of theSuite specified by theType. If you intend to dispose of this handle, be
sure to call AddIconToSuite with a NIL handle to zero out the family entry.
</pre>
* \note <pre>This routine is not currently documented in MPW header files (hence, it is
not in any THINK C or THINK Pascal header file either). The information
given above comes from Macintosh Technical Note #306. This tech. note
also gives the inline glue for the call as follows:
pascal OSErr GetIconFromSuite (Handle *theIconData, Handle theSuite,
ResType theType) = {0x303C, 0x0609, 0xABC9};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  GetIconFromSuite(Handle *theIconData, IconSuiteRef theSuite, ResType theType);

  /**
  \brief Perform action for specified members of an icon family

  <pre>ForEachIconDo will call actionProc  for each icon in the family specified by
theSelector and theSuite. theSelector is a bit level flag that specifies which
members to operate on; they can be added together to create composite selectors
that work on several different family members. See the Notes section below
for the possible selector values.
</pre>
* \note <pre>ForEachIconDo takes a selector value that specifies which icons in the
family to operate on. The values for theSelector  are as follows:
svLarge1Bit svMini8Bit
svLarge4Bit svAllLargeData
svLarge8Bit svAllSmallData
svSmall1Bit svAllMiniData
svSmall4Bit svAll1BitData
svSmall8Bit svAll4BitData
svMini1Bit svAll8BitData
svMini4Bit svAllAvailableData
The actionProc  procedure should have the following form:
pascal OSErr ActionProc (Handle *theIconData, ResType the Type,
void *yourDataPtr);
This routine is not currently documented in MPW header files (hence, it is
not in any THINK C or THINK Pascal header file either). The information
given above comes from Macintosh Technical Note #306. This tech. note
also gives the inline glue for the call as follows:
pascal OSErr ForEachIconDo (Handle theSuite, long selector,
ProcPtr action, void *yourDataPtr)
= {0x303C, 0x080A, 0xABC9};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  ForEachIconDo(IconSuiteRef theSuite, IconSelectorValue selector,
                IconActionUPP action, void *yourDataPtr);

  /**
   *  GetIconSuite()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetIconSuite(IconSuiteRef *theIconSuite, SInt16 theResID,
               IconSelectorValue selector);

  /**
  \brief DisposeIconSuite Dispose of icon family

  <pre>DisposeIconSuite call disposes the icon family handle itself; in addition if
disposeData  is TRUE, any of the icon data handles that do not belong to a
resource form will also be disposed.
</pre>
* \note <pre>This routine is not currently documented in MPW header files (hence, it is
not in any THINK C or THINK Pascal header file either). The information
given above comes from Macintosh Technical Note #306. This tech. note
also gives the inline glue for the call as follows:
pascal OSErr DisposeIconSuite (Handle theSuite, Boolean disposeData)
= {0x303C, 0x0302, 0xABC9};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  DisposeIconSuite(IconSuiteRef theIconSuite, Boolean disposeData);

  /**
   *  PlotIconSuite()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  PlotIconSuite(const Rect *theRect, IconAlignmentType align,
                IconTransformType transform, IconSuiteRef theIconSuite);

  /**
   *  MakeIconCache()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  MakeIconCache(IconCacheRef *theCache, IconGetterUPP makeIcon, void *yourDataPtr);

  /**
   *  LoadIconCache()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  LoadIconCache(const Rect *theRect, IconAlignmentType align,
                IconTransformType transform, IconCacheRef theIconCache);

  /**
   *  PlotIconMethod()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  PlotIconMethod(const Rect *theRect, IconAlignmentType align,
                 IconTransformType transform, IconGetterUPP theMethod,
                 void *yourDataPtr);

  /**
  \brief Get color and string used in the lable menu of the Finder

  <pre>GetLabel returns the actual color and string used in the label menu of the
Finder and in the labels control panel. in labelColor  and labelString
respectively. This information is useful case you wish to include the label text
or color when displaying a file's icon in your application.
</pre>
* \note <pre>This routine is not currently documented in MPW header files (hence, it is
not in any THINK C or THINK Pascal header file either). The information
given above comes from Macintosh Technical Note #306. This tech. note
also gives the inline glue for the call as follows:
pascal OSErr GetLabel (short labelNumber, RGBColor labelColor,
Str255 labelString) = {0x303C, 0x061F, 0xABC9};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  GetLabel(SInt16 labelNumber, RGBColor *labelColor, Str255 labelString);

  /**
   *  PtInIconID()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  PtInIconID(Point testPt, const Rect *iconRect, IconAlignmentType align,
             SInt16 iconID);

  /**
  \brief Hit test a point against indicated icon

  <pre>PtInIconSuite returns TRUE if testPoint  is in the icon mask of the
appropriate member of iconSuite . iconRect, alignment , and the current
GrafPort should be the same as when the icon was last drawn.
</pre>
* \note <pre>This routine is not currently documented in MPW header files (hence, it is
not in any THINK C or THINK Pascal header file either). The information
given above comes from Macintosh Technical Note #306. This tech. note
also gives the inline glue for the call as follows:
pascal Boolean PtInIconSuite (Point testPoint,
const Rect *iconRect, short alignment, short iconSuite)
= {0x303C, 0x070E, 0xABC9};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  Boolean
  PtInIconSuite(Point testPt, const Rect *iconRect, IconAlignmentType align,
                IconSuiteRef theIconSuite);

  /**
   *  PtInIconMethod()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  PtInIconMethod(Point testPt, const Rect *iconRect, IconAlignmentType align,
                 IconGetterUPP theMethod, void *yourDataPtr);

  /**
   *  RectInIconID()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  RectInIconID(const Rect *testRect, const Rect *iconRect,
               IconAlignmentType align, SInt16 iconID);

  /**
  \brief Hit test a rectangle against indicated icon

  <pre>RectInIconSuite returns TRUE if testRect intersects the icon mask of the
appropriate member of iconSuite . iconRect, alignment , and the current
GrafPort should be the same as when the icon was last drawn.
</pre>
* \note <pre>This routine is not currently documented in MPW header files (hence, it is
not in any THINK C or THINK Pascal header file either). The information
given above comes from Macintosh Technical Note #306. This tech. note
also gives the inline glue for the call as follows:
pascal Boolean RectInIconSuite (const Rect *testRect,
const Rect *iconRect, short alignment, short iconSuite)
= {0x303C, 0x0711, 0xABC9};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  Boolean
  RectInIconSuite(const Rect *testRect, const Rect *iconRect,
                  IconAlignmentType align, IconSuiteRef theIconSuite);

  /**
   *  RectInIconMethod()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  RectInIconMethod(const Rect *testRect, const Rect *iconRect,
                   IconAlignmentType align, IconGetterUPP theMethod,
                   void *yourDataPtr);

  /**
   *  IconIDToRgn()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  IconIDToRgn(RgnHandle theRgn, const Rect *iconRect, IconAlignmentType align,
              SInt16 iconID);

  /**
  \brief Create a region from an icon mask

  <pre>IconSuiteToRgn selects an icon from iconSuite , based on iconRect, and
creates a region from the icon mask of that icon. The icon mask is aligned
according to the alignment  parameter. The region created is returned in
theRgn. This allows you to do accurate hit testing and outline dragging of the
icon in your application. theRgn must be allocated before calling
IconSuiteToRgn .
</pre>
* \note <pre>This routine is not currently documented in MPW header files (hence, it is
not in any THINK C or THINK Pascal header file either). The information
given above comes from Macintosh Technical Note #306. This tech. note
also gives the inline glue for the call as follows:
pascal OSErr IconSuiteToRgn (RgnHandle theRgn, const Rect *iconRect,
short alignment, Handle theIconSuite)
= {0x303C, 0x0714, 0xABC9};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  IconSuiteToRgn(RgnHandle theRgn, const Rect *iconRect, IconAlignmentType align,
                 IconSuiteRef theIconSuite);

  /**
   *  IconMethodToRgn()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  IconMethodToRgn(RgnHandle theRgn, const Rect *iconRect, IconAlignmentType align,
                  IconGetterUPP theMethod, void *yourDataPtr);

  /**
  \brief Specify a default label for an icon family

  <pre>SetSuiteLabel allows you to specify a label that is used to draw an icon of
this suite when no label is specified in PlotIconSuite . This is used primarily
when you want to make sure that a family passes to a system routine gets drawn
with the proper label. The default label can be overridden by specifying a label
in PlotIconSuite .
</pre>
* \note <pre>This routine is not currently documented in MPW header files (hence, it is
not in any THINK C or THINK Pascal header file either). The information
given above comes from Macintosh Technical Note #306. This tech. note
also gives the inline glue for the call as follows:
pascal OSErr SetSuiteLabel (Handle theSuite, short theLabel)
= {0x303C, 0x0316, 0xABC9};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  SetSuiteLabel(IconSuiteRef theSuite, SInt16 theLabel);

  /**
  \brief Specify a default label for an icon family

  <pre>GetSuiteLabel returns any label set previously with SetSuiteLabel .
</pre>
* \note <pre>This routine is not currently documented in MPW header files (hence, it is
not in any THINK C or THINK Pascal header file either). The information
given above comes from Macintosh Technical Note #306. This tech. note
also gives the inline glue for the call as follows:
pascal short GetSuiteLabel (Handle theSuite )
= {0x303C, 0x0217, 0xABC9};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  SInt16
  GetSuiteLabel(IconSuiteRef theSuite);

  /**
  \brief GetIconCacheData Get data associated with an icon cache

  <pre>GetIconCacheData obtains the data pointer value associated with theCache .
The data pointer is returned in yourDataPtr .
</pre>
* \note <pre>This routine is not currently documented in MPW header files (hence, it is
not in any THINK C or THINK Pascal header file either). The information
given above comes from Macintosh Technical Note #306. This tech. note
also gives the inline glue for the call as follows:
pascal OSErr GetIconCacheData (Handle theCache, Ptr *yourDataPtr)
= {0x303C, 0x0419, 0xABC9};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  GetIconCacheData(IconCacheRef theCache, void **theData);

  /**
  \brief SetIconCacheData Set the data associated with an icon cache

  <pre>SetIconCacheData sets the data pointer value associated with the theCache
to yourDataPtr .
</pre>
* \note <pre>This routine is not currently documented in MPW header files (hence, it is
not in any THINK C or THINK Pascal header file either). The information
given above comes from Macintosh Technical Note #306. This tech. note
also gives the inline glue for the call as follows:
pascal OSErr SetIconCacheData (Handle theCache, Ptr yourDataPtr)
= {0x303C, 0x041A, 0xABC9};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  SetIconCacheData(IconCacheRef theCache, void *theData);

  /**
  \brief GetIconCacheProc Get procedure associated with an icon cache


   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  GetIconCacheProc(IconCacheRef theCache, IconGetterUPP *theProc);

  /**
  \brief SetIconCacheProc Set the procedure associated with an icon cache

  <pre>SetIconCacheProc sets the ProcPtr value associated with the theCache  to
theProc.
</pre>
* \note <pre>SetIconCacheProc takes a ProcPtr parameter, theProc The ProcPtr
should have the following format:
Handle GetAnIcon (ResType theType, Ptr yourDataPtr);
This function should return either the icon data to be used to draw or nil to
signify that this entry in the icon cache does not exist. See
Drawing Icons with System 7 for more on icon caches.
This routine is not currently documented in MPW header files (hence, it is
not in any THINK C or THINK Pascal header file either). The information
given above comes from Macintosh Technical Note #306. This tech. note
also gives the inline glue for the call as follows:
pascal OSErr SetIconCacheProc (Handle theCache, Ptr yourDataPtr)
= {0x303C, 0x041C, 0xABC9};
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  SetIconCacheProc(IconCacheRef theCache, IconGetterUPP theProc);

  /**
   *  PlotIconHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  PlotIconHandle(const Rect *theRect, IconAlignmentType align,
                 IconTransformType transform, Handle theIcon);

  /**
   *  PlotSICNHandle()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  PlotSICNHandle(const Rect *theRect, IconAlignmentType align,
                 IconTransformType transform, Handle theSICN);

  /**
  \brief Display an icon image with System 7 icon resource types

  <pre>PlotCIconHandle plots an icon image in the current GrafPort at local
coordinates specified by a rectangle.
theRectis the address of an 8-byte Rect structure, expressed in local
coordinates.
alignment alignment method used in case the icon does not exactly fit the
rectangle give. See the Notes section below.
transform desired appearance of the icon on the screen. See the Notes section
belwo
theCIconH handle to a standard QuickDraw color icon. Use GetCIcon to load a
color icon. Don't forget to dispose of it when you are done with
DisposCIcon (sometimes they can take up quite a bit of memory).
</pre>
* \returns <pre>error code
</pre>
* \note <pre>PlotCIconHandle takes a parameter which specifies the aligment of the
icon in the destination rectangle. Most icons do not fully fill their rectangle,
and it is sometimes necessary to draw the icon relative to other data (like
menu text). For this reason, you can specify one of these standard alignment
values for the alignment parameter. You can add a vertical alignment to a
horizontal alignment to create a composite alignment value.
atNone
atVerticalCenter
atTop
atBottom
atHorizontalCenter
atLeft
atRight
The transform parameter specifies the mode or "transform" in which the
icon should be drawn. Transforms are analogous to certain Finder states for
the icons. For example the transform that you would use to show an icon of
a disk that has been ejected is ttOffline. The following transforms are
available.
ttNone
ttDisabled
ttOffline
ttOpen
ttSelected
</pre>
* \copyright THINK Reference © 1991-1992 Symantec Corporation
   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
*    \carbon_lib        in CarbonLib 1.0 and later
*    \mac_os_x         in version 10.0 and later
*/
  OSErr
  PlotCIconHandle(const Rect *theRect, IconAlignmentType align,
                  IconTransformType transform, CIconHandle theCIcon);

  /**
     IconServices is an efficient mechanism to share icon data amongst multiple
     clients. It avoids duplication of data; it provides efficient caching,
     releasing memory when the icon data is no longer needed; it can provide
     the appropriate icon for any filesystem object; it can provide commonly
     used icons (caution, note, help...); it is Appearance-savvy: the icons
     are switched when appropriate.
     IconServices refer to cached icon data using IconRef, a 32-bit opaque
     value. IconRefs are reference counted. When there are no more "owners"
     of an IconRef, the memory used by the icon bitmap is disposed of.
     Two files of same type and creator with no custom icon will have the same
     IconRef. Files with custom icons will have their own IconRef.
  */

  /**
     Use the special creator kSystemIconsCreator to get "standard" icons
     that are not associated with a file, such as the help icon.
     Note that all lowercase creators are reserved by Apple.
  */
  enum
  {
    kSystemIconsCreator = FOUR_CHAR_CODE('macs')
  };

  /**
     Type of the predefined/generic icons. For example, the call:
        err = GetIconRef(kOnSystemDisk, kSystemIconsCreator, kHelpIcon, &iconRef);
     will retun in iconRef the IconRef for the standard help icon.
  */

  /* Generic Finder icons */
  enum
  {
    kClipboardIcon = FOUR_CHAR_CODE('CLIP'),
    kClippingUnknownTypeIcon = FOUR_CHAR_CODE('clpu'),
    kClippingPictureTypeIcon = FOUR_CHAR_CODE('clpp'),
    kClippingTextTypeIcon = FOUR_CHAR_CODE('clpt'),
    kClippingSoundTypeIcon = FOUR_CHAR_CODE('clps'),
    kDesktopIcon = FOUR_CHAR_CODE('desk'),
    kFinderIcon = FOUR_CHAR_CODE('FNDR'),
    kFontSuitcaseIcon = FOUR_CHAR_CODE('FFIL'),
    kFullTrashIcon = FOUR_CHAR_CODE('ftrh'),
    kGenericApplicationIcon = FOUR_CHAR_CODE('APPL'),
    kGenericCDROMIcon = FOUR_CHAR_CODE('cddr'),
    kGenericControlPanelIcon = FOUR_CHAR_CODE('APPC'),
    kGenericControlStripModuleIcon = FOUR_CHAR_CODE('sdev'),
    kGenericComponentIcon = FOUR_CHAR_CODE('thng'),
    kGenericDeskAccessoryIcon = FOUR_CHAR_CODE('APPD'),
    kGenericDocumentIcon = FOUR_CHAR_CODE('docu'),
    kGenericEditionFileIcon = FOUR_CHAR_CODE('edtf'),
    kGenericExtensionIcon = FOUR_CHAR_CODE('INIT'),
    kGenericFileServerIcon = FOUR_CHAR_CODE('srvr'),
    kGenericFontIcon = FOUR_CHAR_CODE('ffil'),
    kGenericFontScalerIcon = FOUR_CHAR_CODE('sclr'),
    kGenericFloppyIcon = FOUR_CHAR_CODE('flpy'),
    kGenericHardDiskIcon = FOUR_CHAR_CODE('hdsk'),
    kGenericIDiskIcon = FOUR_CHAR_CODE('idsk'),
    kGenericRemovableMediaIcon = FOUR_CHAR_CODE('rmov'),
    kGenericMoverObjectIcon = FOUR_CHAR_CODE('movr'),
    kGenericPCCardIcon = FOUR_CHAR_CODE('pcmc'),
    kGenericPreferencesIcon = FOUR_CHAR_CODE('pref'),
    kGenericQueryDocumentIcon = FOUR_CHAR_CODE('qery'),
    kGenericRAMDiskIcon = FOUR_CHAR_CODE('ramd'),
    kGenericSharedLibaryIcon = FOUR_CHAR_CODE('shlb'),
    kGenericStationeryIcon = FOUR_CHAR_CODE('sdoc'),
    kGenericSuitcaseIcon = FOUR_CHAR_CODE('suit'),
    kGenericURLIcon = FOUR_CHAR_CODE('gurl'),
    kGenericWORMIcon = FOUR_CHAR_CODE('worm'),
    kInternationalResourcesIcon = FOUR_CHAR_CODE('ifil'),
    kKeyboardLayoutIcon = FOUR_CHAR_CODE('kfil'),
    kSoundFileIcon = FOUR_CHAR_CODE('sfil'),
    kSystemSuitcaseIcon = FOUR_CHAR_CODE('zsys'),
    kTrashIcon = FOUR_CHAR_CODE('trsh'),
    kTrueTypeFontIcon = FOUR_CHAR_CODE('tfil'),
    kTrueTypeFlatFontIcon = FOUR_CHAR_CODE('sfnt'),
    kTrueTypeMultiFlatFontIcon = FOUR_CHAR_CODE('ttcf'),
    kUserIDiskIcon = FOUR_CHAR_CODE('udsk'),
    kInternationResourcesIcon = kInternationalResourcesIcon /* old misspelling*/
  };

  /* Internet locations */
  enum
  {
    kInternetLocationHTTPIcon = FOUR_CHAR_CODE('ilht'),
    kInternetLocationFTPIcon = FOUR_CHAR_CODE('ilft'),
    kInternetLocationAppleShareIcon = FOUR_CHAR_CODE('ilaf'),
    kInternetLocationAppleTalkZoneIcon = FOUR_CHAR_CODE('ilat'),
    kInternetLocationFileIcon = FOUR_CHAR_CODE('ilfi'),
    kInternetLocationMailIcon = FOUR_CHAR_CODE('ilma'),
    kInternetLocationNewsIcon = FOUR_CHAR_CODE('ilnw'),
    kInternetLocationNSLNeighborhoodIcon = FOUR_CHAR_CODE('ilns'),
    kInternetLocationGenericIcon = FOUR_CHAR_CODE('ilge')
  };

  /* Folders */
  enum
  {
    kGenericFolderIcon = FOUR_CHAR_CODE('fldr'),
    kDropFolderIcon = FOUR_CHAR_CODE('dbox'),
    kMountedFolderIcon = FOUR_CHAR_CODE('mntd'),
    kOpenFolderIcon = FOUR_CHAR_CODE('ofld'),
    kOwnedFolderIcon = FOUR_CHAR_CODE('ownd'),
    kPrivateFolderIcon = FOUR_CHAR_CODE('prvf'),
    kSharedFolderIcon = FOUR_CHAR_CODE('shfl')
  };

  /* Sharing Privileges icons */
  enum
  {
    kSharingPrivsNotApplicableIcon = FOUR_CHAR_CODE('shna'),
    kSharingPrivsReadOnlyIcon = FOUR_CHAR_CODE('shro'),
    kSharingPrivsReadWriteIcon = FOUR_CHAR_CODE('shrw'),
    kSharingPrivsUnknownIcon = FOUR_CHAR_CODE('shuk'),
    kSharingPrivsWritableIcon = FOUR_CHAR_CODE('writ')
  };

  /* Users and Groups icons */
  enum
  {
    kUserFolderIcon = FOUR_CHAR_CODE('ufld'),
    kWorkgroupFolderIcon = FOUR_CHAR_CODE('wfld'),
    kGuestUserIcon = FOUR_CHAR_CODE('gusr'),
    kUserIcon = FOUR_CHAR_CODE('user'),
    kOwnerIcon = FOUR_CHAR_CODE('susr'),
    kGroupIcon = FOUR_CHAR_CODE('grup')
  };

  /* Special folders */
  enum
  {
    kAppearanceFolderIcon = FOUR_CHAR_CODE('appr'),
    kAppleExtrasFolderIcon = FOUR_CHAR_CODE('aex�'),
    kAppleMenuFolderIcon = FOUR_CHAR_CODE('amnu'),
    kApplicationsFolderIcon = FOUR_CHAR_CODE('apps'),
    kApplicationSupportFolderIcon = FOUR_CHAR_CODE('asup'),
    kAssistantsFolderIcon = FOUR_CHAR_CODE('ast�'),
    kColorSyncFolderIcon = FOUR_CHAR_CODE('prof'),
    kContextualMenuItemsFolderIcon = FOUR_CHAR_CODE('cmnu'),
    kControlPanelDisabledFolderIcon = FOUR_CHAR_CODE('ctrD'),
    kControlPanelFolderIcon = FOUR_CHAR_CODE('ctrl'),
    kControlStripModulesFolderIcon = FOUR_CHAR_CODE('sdv�'),
    kDocumentsFolderIcon = FOUR_CHAR_CODE('docs'),
    kExtensionsDisabledFolderIcon = FOUR_CHAR_CODE('extD'),
    kExtensionsFolderIcon = FOUR_CHAR_CODE('extn'),
    kFavoritesFolderIcon = FOUR_CHAR_CODE('favs'),
    kFontsFolderIcon = FOUR_CHAR_CODE('font'),
    kHelpFolderIcon = FOUR_CHAR_CODE('�hlp'),
    kInternetFolderIcon = FOUR_CHAR_CODE('int�'),
    kInternetPlugInFolderIcon = FOUR_CHAR_CODE('�net'),
    kInternetSearchSitesFolderIcon = FOUR_CHAR_CODE('issf'),
    kLocalesFolderIcon = FOUR_CHAR_CODE('�loc'),
    kMacOSReadMeFolderIcon = FOUR_CHAR_CODE('mor�'),
    kPublicFolderIcon = FOUR_CHAR_CODE('pubf'),
    kPreferencesFolderIcon = FOUR_CHAR_CODE('prf�'),
    kPrinterDescriptionFolderIcon = FOUR_CHAR_CODE('ppdf'),
    kPrinterDriverFolderIcon = FOUR_CHAR_CODE('�prd'),
    kPrintMonitorFolderIcon = FOUR_CHAR_CODE('prnt'),
    kRecentApplicationsFolderIcon = FOUR_CHAR_CODE('rapp'),
    kRecentDocumentsFolderIcon = FOUR_CHAR_CODE('rdoc'),
    kRecentServersFolderIcon = FOUR_CHAR_CODE('rsrv'),
    kScriptingAdditionsFolderIcon = FOUR_CHAR_CODE('�scr'),
    kSharedLibrariesFolderIcon = FOUR_CHAR_CODE('�lib'),
    kScriptsFolderIcon = FOUR_CHAR_CODE('scr�'),
    kShutdownItemsDisabledFolderIcon = FOUR_CHAR_CODE('shdD'),
    kShutdownItemsFolderIcon = FOUR_CHAR_CODE('shdf'),
    kSpeakableItemsFolder = FOUR_CHAR_CODE('spki'),
    kStartupItemsDisabledFolderIcon = FOUR_CHAR_CODE('strD'),
    kStartupItemsFolderIcon = FOUR_CHAR_CODE('strt'),
    kSystemExtensionDisabledFolderIcon = FOUR_CHAR_CODE('macD'),
    kSystemFolderIcon = FOUR_CHAR_CODE('macs'),
    kTextEncodingsFolderIcon = FOUR_CHAR_CODE('�tex'),
    kUsersFolderIcon = FOUR_CHAR_CODE('usr�'),
    kUtilitiesFolderIcon = FOUR_CHAR_CODE('uti�'),
    kVoicesFolderIcon = FOUR_CHAR_CODE('fvoc')
  };

  /* Badges */
  enum
  {
    kAppleScriptBadgeIcon = FOUR_CHAR_CODE('scrp'),
    kLockedBadgeIcon = FOUR_CHAR_CODE('lbdg'),
    kMountedBadgeIcon = FOUR_CHAR_CODE('mbdg'),
    kSharedBadgeIcon = FOUR_CHAR_CODE('sbdg'),
    kAliasBadgeIcon = FOUR_CHAR_CODE('abdg'),
    kAlertCautionBadgeIcon = FOUR_CHAR_CODE('cbdg')
  };

  /* Alert icons */
  enum
  {
    kAlertNoteIcon = FOUR_CHAR_CODE('note'),
    kAlertCautionIcon = FOUR_CHAR_CODE('caut'),
    kAlertStopIcon = FOUR_CHAR_CODE('stop')
  };

  /* Networking icons */
  enum
  {
    kAppleTalkIcon = FOUR_CHAR_CODE('atlk'),
    kAppleTalkZoneIcon = FOUR_CHAR_CODE('atzn'),
    kAFPServerIcon = FOUR_CHAR_CODE('afps'),
    kFTPServerIcon = FOUR_CHAR_CODE('ftps'),
    kHTTPServerIcon = FOUR_CHAR_CODE('htps'),
    kGenericNetworkIcon = FOUR_CHAR_CODE('gnet'),
    kIPFileServerIcon = FOUR_CHAR_CODE('isrv')
  };

  /* Toolbar icons */
  enum
  {
    kToolbarCustomizeIcon = FOUR_CHAR_CODE('tcus'),
    kToolbarDeleteIcon = FOUR_CHAR_CODE('tdel'),
    kToolbarFavoritesIcon = FOUR_CHAR_CODE('tfav'),
    kToolbarHomeIcon = FOUR_CHAR_CODE('thom')
  };

  /* Other icons */
  enum
  {
    kAppleLogoIcon = FOUR_CHAR_CODE('capl'),
    kAppleMenuIcon = FOUR_CHAR_CODE('sapl'),
    kBackwardArrowIcon = FOUR_CHAR_CODE('baro'),
    kFavoriteItemsIcon = FOUR_CHAR_CODE('favr'),
    kForwardArrowIcon = FOUR_CHAR_CODE('faro'),
    kGridIcon = FOUR_CHAR_CODE('grid'),
    kHelpIcon = FOUR_CHAR_CODE('help'),
    kKeepArrangedIcon = FOUR_CHAR_CODE('arng'),
    kLockedIcon = FOUR_CHAR_CODE('lock'),
    kNoFilesIcon = FOUR_CHAR_CODE('nfil'),
    kNoFolderIcon = FOUR_CHAR_CODE('nfld'),
    kNoWriteIcon = FOUR_CHAR_CODE('nwrt'),
    kProtectedApplicationFolderIcon = FOUR_CHAR_CODE('papp'),
    kProtectedSystemFolderIcon = FOUR_CHAR_CODE('psys'),
    kRecentItemsIcon = FOUR_CHAR_CODE('rcnt'),
    kShortcutIcon = FOUR_CHAR_CODE('shrt'),
    kSortAscendingIcon = FOUR_CHAR_CODE('asnd'),
    kSortDescendingIcon = FOUR_CHAR_CODE('dsnd'),
    kUnlockedIcon = FOUR_CHAR_CODE('ulck'),
    kConnectToIcon = FOUR_CHAR_CODE('cnct'),
    kGenericWindowIcon = FOUR_CHAR_CODE('gwin'),
    kQuestionMarkIcon = FOUR_CHAR_CODE('ques'),
    kDeleteAliasIcon = FOUR_CHAR_CODE('dali'),
    kEjectMediaIcon = FOUR_CHAR_CODE('ejec'),
    kBurningIcon = FOUR_CHAR_CODE('burn'),
    kRightContainerArrowIcon = FOUR_CHAR_CODE('rcar')
  };

  //  IconServicesUsageFlags
  typedef UInt32 IconServicesUsageFlags;
  enum
  {
    kIconServicesNormalUsageFlag = 0
  };

  /**
    kIconServicesCatalogInfoMask - Minimal bitmask for use with
      GetIconRefFromFileInfo(). Use this mask with FSGetCatalogInfo
      before calling GetIconRefFromFileInfo().
  */
  enum
  {
    kIconServicesCatalogInfoMask =
        (kFSCatInfoNodeID | kFSCatInfoParentDirID | kFSCatInfoVolume |
         kFSCatInfoNodeFlags | kFSCatInfoFinderInfo | kFSCatInfoFinderXInfo |
         kFSCatInfoUserAccess)
  };

  /**
   *  PlotIconRefFlags
   *
   *  Discussion:
   *    Flags that can be passed to the PlotIconRefInContext routine.
   */
  typedef UInt32 PlotIconRefFlags;
  enum
  {

    /**
     * Draw the icon image and alpha channel.
     */
    kPlotIconRefNormalFlags = 0L,

    /**
     * Only draw the alpha channel.
     */
    kPlotIconRefNoImage = (1 << 1),

    /**
     * Only draw the image.
     */
    kPlotIconRefNoMask = (1 << 2)
  };

  /**
      IconFamily 'icns' resources contain an entire IconFamily (all sizes and
     depths). For custom icons, icns IconFamily resources of the custom icon
     resource ID are fetched first before the classic custom icons (individual
     'ics#, ICN#, etc) are fetched.  If the fetch of the icns resource succeeds
     then the icns is looked at exclusively for the icon data. For custom icons,
     new icon features such as 32-bit deep icons are only fetched from the icns
     resource. This is to avoid incompatibilities with cut & paste of new style
     icons with an older version of the MacOS Finder. DriverGestalt is called with
     code kdgMediaIconSuite by IconServices after calling FSM to determine a
     driver icon for a particular device.  The result of the kdgMediaIconSuite
     call to DriverGestalt should be a pointer an an IconFamily.  In this manner
     driver vendors can provide rich, detailed drive icons instead of the 1-bit
     variety previously supported.
  */
  enum
  {
    kIconFamilyType = FOUR_CHAR_CODE('icns')
  };

  struct IconFamilyElement
  {
    OSType elementType; /* 'ICN#', 'icl8', etc...*/
    Size elementSize;   /* Size of this element*/
    unsigned char elementData[1];
  };
  typedef struct IconFamilyElement IconFamilyElement;
  struct IconFamilyResource
  {
    OSType resourceType; /* Always 'icns'*/
    Size resourceSize;   /* Total size of this resource*/
    IconFamilyElement elements[1];
  };
  typedef struct IconFamilyResource IconFamilyResource;
  typedef IconFamilyResource *IconFamilyPtr;
  typedef IconFamilyPtr *IconFamilyHandle;
  /**
    ==============================================================================
     Initialization and Termination
    ==============================================================================
  */

  /**
     IconServicesInit

     Call this routine once per classic 68K application initialization.
     This routine does not need to be called at boot time.
  */

#if CALL_NOT_IN_CARBON
  /**
   *  IconServicesInit()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSErr
  IconServicesInit(CFragInitBlockPtr initBlockPtr);

  /**
     IconServicesTerminate:

     Call this routine once from the termination of a classic 68K application.
     This routine does not need to be called at boot time.
  */

  /**
   *  IconServicesTerminate()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  IconServicesTerminate(void);

#endif /* CALL_NOT_IN_CARBON */

  /**
    ==============================================================================
     Converting data structures
    ==============================================================================
  */

  /**
     IconRefToIconFamily
     This routines returns a new IconFamily that contains the data corresponding
     to the specified IconRef.
  */

  /**
   *  IconRefToIconFamily()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  IconRefToIconFamily(IconRef theIconRef, IconSelectorValue whichIcons,
                      IconFamilyHandle *iconFamily);

  /**
     IconFamilyToIconSuite
     This routine transfers the data from an icon family handle into an icon
     suite.
  */

  /**
   *  IconFamilyToIconSuite()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  IconFamilyToIconSuite(IconFamilyHandle iconFamily, IconSelectorValue whichIcons,
                        IconSuiteRef *iconSuite);

  /**
     IconSuiteToIconFamily
     This routine transfers the data in an icon suite into an icon family.
  */

  /**
   *  IconSuiteToIconFamily()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  IconSuiteToIconFamily(IconSuiteRef iconSuite, IconSelectorValue whichIcons,
                        IconFamilyHandle *iconFamily);

  /**
     SetIconFamilyData
     Change the data of an icon family. The data is copied.
     The type can be one of the icon type, or 'PICT'.
     The data will be compressed if needed.
  */

  /**
   *  SetIconFamilyData()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetIconFamilyData(IconFamilyHandle iconFamily, OSType iconType, Handle h);

  /**
     GetIconFamilyData
     Return a copy of the data in the icon family.
     The type can be one of the icon type, or 'PICT'
     The data will be returned uncompressed.
     The handle (h) will be resized as appropriate. If no data of the
     requested type is present, the handle size will be set to 0.
  */

  /**
   *  GetIconFamilyData()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetIconFamilyData(IconFamilyHandle iconFamily, OSType iconType, Handle h);

  /**
    ==============================================================================
     Reference counting
    ==============================================================================
  */

  /**
     GetIconRefOwners

     This routine returns the reference count for the IconRef, or number of
     owners.

     A valid IconRef always has at least one owner.
  */

  /**
   *  GetIconRefOwners()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetIconRefOwners(IconRef theIconRef, UInt16 *owners);

  /**
     AcquireIconRef
     This routine increments the reference count for the IconRef
  */

  /**
   *  AcquireIconRef()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  AcquireIconRef(IconRef theIconRef);

  /**
     ReleaseIconRef

     This routine decrements the reference count for the IconRef.

     When the reference count reaches 0, all memory allocated for the icon
     is disposed. Any subsequent use of the IconRef is invalid.
  */

  /**
   *  ReleaseIconRef()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ReleaseIconRef(IconRef theIconRef);

  /**
    ==============================================================================
     Getting an IconRef
    ==============================================================================
  */

  /**
     GetIconRefFromFile

     This routine returns an icon ref for the specified file, folder or volume.
     The label information is provided separately, since two files with the same
     icon but a different label would share the same iconRef. The label can be
     used in PlotIconRef() for example.

     Use this routine if you have no information about the file system object. If
     you have already done a GetCatInfo on the file and want to save some I/O,
     call GetIconRefFromFolder() if you know it's a folder with no custom icon or
     call GetIconRef() if it's a file with no custom icon.
     This routine increments the reference count of the returned IconRef. Call
     ReleaseIconRef() when you're done with it.
  */

  /**
   *  GetIconRefFromFile()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetIconRefFromFile(const FSSpec *theFile, IconRef *theIconRef, SInt16 *theLabel);

  /**
     GetIconRef

     This routine returns an icon ref for an icon in the desktop database or
     for a registered icon.
     The system registers a set of icon such as the help icon with the creator
     code kSystemIconsCreator. See above for a list of the registered system
     types. The vRefNum is used as a hint on where to look for the icon first. Use
     kOnSystemDisk if you don't know what to pass.
     This routine increments the reference count of the returned IconRef. Call
     ReleaseIconRef() when you're done with it.
  */

  /**
   *  GetIconRef()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetIconRef(SInt16 vRefNum, OSType creator, OSType iconType, IconRef *theIconRef);

  /**
     GetIconRefFromFolder

     This routine returns an icon ref for a folder with no custom icon.
     Use the more generic, but slightly slower, GetIconRefFromFile() if
     you don't already have the necessary info about the file.
     Attributes should be CInfoPBRec.dirInfo.ioFlAttrib for this folder.
     Access privileges should be CInfoPBRec.dirInfo.ioACUser for this folder.
     This routine increments the reference count of the IconRef. Call
     ReleaseIconRef() when you're done with it.
  */

  /**
   *  GetIconRefFromFolder()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetIconRefFromFolder(SInt16 vRefNum, SInt32 parentFolderID, SInt32 folderID,
                       SInt8 attributes, SInt8 accessPrivileges,
                       IconRef *theIconRef);

  /* GetIconRefFromFileInfo*/
  /**
   *  GetIconRefFromFileInfo()
   *
   *  Summary:
   *    This routine returns an IconRef for a file with minimal file I/O.
   *
   *  Discussion:
   *    To minimize file operations, FSGetCatalogInfo should be called
   *    prior to calling this routine. The FSCatalogInfo should
   *    correspond to kIconServicesCatalogInfoMask The name should be
   *    fetched and passed in. If either the name or the correct catalog
   *    info is not passed in, this routine will do file operations for
   *    this information instead.
   *
   *  Parameters:
   *
   *    inRef:
   *      An FSRef for the target file
   *
   *    inFileNameLength:
   *      The length of the name of the target file
   *
   *    inFileName:
   *      The name of the target file
   *
   *    inWhichInfo:
   *      The mask of file info already acquired.
   *
   *    inCatalogInfo:
   *      The catalog info already acquired.
   *
   *    inUsageFlags:
   *      The usage flags for this call (use
   *      kIconServicesNormalUsageFlag).
   *
   *    outIconRef:
   *      The output IconRef for the routine.
   *
   *    outLabel:
   *      The output label for the icon/file.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.1 and later
   *    \mac_os_x         in version 10.1 and later
   */
  OSStatus
  GetIconRefFromFileInfo(const FSRef *inRef, UniCharCount inFileNameLength,
                         const UniChar *inFileName, /* can be NULL */
                         FSCatalogInfoBitmap inWhichInfo,
                         const FSCatalogInfo *inCatalogInfo, /* can be NULL */
                         IconServicesUsageFlags inUsageFlags, IconRef *outIconRef,
                         SInt16 *outLabel);

  /**
    ==============================================================================
     Adding and modifying IconRef
    ==============================================================================
  */

  /**
     RegisterIconRefFromIconFamily
     This routine adds a new entry to the IconRef registry. Other clients will be
     able to access it using the (creator, iconType) pair specified here.
     Lower-case creators are reserved for the system.
     Consider using RegisterIconRefFromResource() if possible, since the data
     registered using RegisterIconRefFromFamily() cannot be purged.
     The iconFamily data is copied and the caller is reponsible for disposing of
     it. This routine increments the reference count of the IconRef. Call
     ReleaseIconRef() when you're done with it.
  */

  /**
   *  RegisterIconRefFromIconFamily()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  RegisterIconRefFromIconFamily(OSType creator, OSType iconType,
                                IconFamilyHandle iconFamily, IconRef *theIconRef);

  /**
     RegisterIconRefFromResource

     Registers an IconRef from a resouce file.
     Lower-case creators are reserved for the system.
     The icon data to be fetched is either classic icon data or an icon family.
     The 'icns' icon family is searched for before the classic icon data.
     This routine increments the reference count of the IconRef. Call
     ReleaseIconRef() when you're done with it.
  */

  /**
   *  RegisterIconRefFromResource()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  RegisterIconRefFromResource(OSType creator, OSType iconType,
                              const FSSpec *resourceFile, SInt16 resourceID,
                              IconRef *theIconRef);

  /* RegisterIconRefFromFSRef*/
  /**
   *  RegisterIconRefFromFSRef()
   *
   *  Discussion:
   *    This routine registers an IconRef from a ".icns" file and
   *    associates it with a creator/type pair.
   *
   *  Parameters:
   *
   *    creator:
   *      The creator code for the icns file.
   *
   *    iconType:
   *      The type code for the icns file
   *
   *    icon\file
   *      The FSRef of the icns file.
   *
   *    theIconRef:
   *      The output IconRef for the routine.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.1 and later
   *    \mac_os_x         in version 10.1 and later
   */
  OSStatus
  RegisterIconRefFromFSRef(OSType creator, OSType iconType, const FSRef *iconFile,
                           IconRef *theIconRef);

  /**
     UnregisterIconRef

     Removes the specified icon from the icon cache (if there are no users of it).
     If some clients are using this iconRef, then the IconRef will be removed when
     the last user calls ReleaseIconRef.
  */

  /**
   *  UnregisterIconRef()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  UnregisterIconRef(OSType creator, OSType iconType);

  /**
     UpdateIconRef

     Call this routine to force an update of the data for iconRef.

     For example after changing an icon in the desktop database or changing the
     custom icon of a file. Note that after _adding_ a custom icon to file or
     folder, you need to call GetIconRefFromFile() to get a new IconRef specific
     to this file.

     This routine does nothing if the IconRef is a registered icon.
  */

  /**
   *  UpdateIconRef()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  UpdateIconRef(IconRef theIconRef);

  /**
     OverrideIconRefFromResource

     This routines replaces the bitmaps of the specified IconRef with the ones
     in the specified resource file.
  */

  /**
   *  OverrideIconRefFromResource()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  OverrideIconRefFromResource(IconRef theIconRef, const FSSpec *resourceFile,
                              SInt16 resourceID);

  /**
     OverrideIconRef

     This routines replaces the bitmaps of the specified IconRef with the ones
     from the new IconRef.
  */

  /**
   *  OverrideIconRef()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  OverrideIconRef(IconRef oldIconRef, IconRef newIconRef);

  /**
     RemoveIconRefOverride
     This routine remove an override if one was applied to the icon and
     reverts back to the original bitmap data.
  */

  /**
   *  RemoveIconRefOverride()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  RemoveIconRefOverride(IconRef theIconRef);

  /**
    ==============================================================================
     Creating composite IconRef
    ==============================================================================
  */

  /**
     CompositeIconRef

     Superimposes an IconRef on top of another one
  */

  /**
   *  CompositeIconRef()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  CompositeIconRef(IconRef backgroundIconRef, IconRef foregroundIconRef,
                   IconRef *compositeIconRef);

  /**
     IsIconRefComposite
     Indicates if a given icon ref is a composite of two other icon refs (and
     which ones) If it isn't a composite, backgroundIconRef and foreGroundIconRef
     will be 0.
  */

  /**
   *  IsIconRefComposite()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  IsIconRefComposite(IconRef compositeIconRef, IconRef *backgroundIconRef,
                     IconRef *foregroundIconRef);

  /**
    ==============================================================================
     Using IconRef
    ==============================================================================
  */

  /**
     IsValidIconRef
     Return true if the iconRef passed in is a valid icon ref
  */

  /**
   *  IsValidIconRef()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  IsValidIconRef(IconRef theIconRef);

  /**
     PlotIconRef

     This routine plots the IconRef.  It mostly takes the same parameters as
     PlotIconSuite. Pass kIconServicesNormalUsageFlag as a default value for
     IconServicesUsageFlags.
  */

  /**
   *  PlotIconRef()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  PlotIconRef(const Rect *theRect, IconAlignmentType align,
              IconTransformType transform,
              IconServicesUsageFlags theIconServicesUsageFlags,
              IconRef theIconRef);

  /* PlotIconRefInContext*/
  /**
   *  PlotIconRefInContext()
   *
   *  Discussion:
   *    This routines plots an IconRef using Quartz/CoreGraphics.
   *
   *  Parameters:
   *
   *    inContext:
   *      The graphics context to use.
   *
   *    inRect:
   *      The rect to plot the icon in.
   *
   *    inAlign:
   *      The icon alignment.
   *
   *    inTransform:
   *      The icon transform.
   *
   *    inLabelColor:
   *      The icon label color.
   *
   *    inFlags:
   *      The drawing flags to use (usually kPlotIconRefNormalFlags).
   *
   *    inIconRef:
   *      The IconRef to plot.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.1 and later
   *    \mac_os_x         in version 10.1 and later
   */
  OSStatus
  PlotIconRefInContext(CGContextRef inContext, const CGRect *inRect,
                       IconAlignmentType inAlign, IconTransformType inTransform,
                       const RGBColor *inLabelColor, PlotIconRefFlags inFlags,
                       IconRef inIconRef);

  /**
     PtInIconRef

     This routine indicates if testPt would hit the icon designated by iconRef.
     It mostly takes the same parameters as PtInIconSuite.
     Pass kIconServicesNormalUsageFlag as a default value for
     IconServicesUsageFlags.
  */

  /**
   *  PtInIconRef()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  PtInIconRef(const Point *testPt, const Rect *iconRect, IconAlignmentType align,
              IconServicesUsageFlags theIconServicesUsageFlags,
              IconRef theIconRef);

  /**
     RectInIconRef

     This routine indicates if testRect would intersect the icon designated by
     iconRef. It mostly takes the same parameters as RectInIconSuite. Pass
     kIconServicesNormalUsageFlag as a default value for IconServicesUsageFlags.
  */

  /**
   *  RectInIconRef()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  RectInIconRef(const Rect *testRect, const Rect *iconRect,
                IconAlignmentType align,
                IconServicesUsageFlags iconServicesUsageFlags, IconRef theIconRef);

  /**
     IconRefToRgn

     This routine returns a region for the icon.
     It mostly takes the same parameters as IconSuiteToRgn.
     Pass kIconServicesNormalUsageFlag as a default value for
     IconServicesUsageFlags.
  */

  /**
   *  IconRefToRgn()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  IconRefToRgn(RgnHandle theRgn, const Rect *iconRect, IconAlignmentType align,
               IconServicesUsageFlags iconServicesUsageFlags, IconRef theIconRef);

  /**
     GetIconSizesFromIconRef

     This routine returns an IconSelectorValue indicating the depths and sizes of
     icon data which are actually available.  It takes an IconSelectorValue
     indicating which sizes/depths the caller is interested and returns an
     IconSelectorValue indicating which sizes/depths exist.

     Caution:

     This is potentially an extremely expensive call as IconServices may be forced
     to attempt fetching the data for the IconRef's sizes/depths which may result
     in hitting the local disk or even the network to obtain the data to determine
     which sizes/depths actually exist.
     Pass kIconServicesNormalUsageFlag as a default value for
     IconServicesUsageFlags.
  */

  /**
   *  GetIconSizesFromIconRef()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetIconSizesFromIconRef(IconSelectorValue iconSelectorInput,
                          IconSelectorValue *iconSelectorOutputPtr,
                          IconServicesUsageFlags iconServicesUsageFlags,
                          IconRef theIconRef);

  /**
    ==============================================================================
     Flushing IconRef data
    ==============================================================================
  */

  /**
     FlushIconRefs

     Making this call will dispose of all the data for the specified icons if
     the data can be reacquired, for example if the data is provided from a
     resource.
     '****' is a wildcard for all types or all creators.
  */

  /**
   *  FlushIconRefs()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FlushIconRefs(OSType creator, OSType iconType);

  /**
     FlushIconRefsByVolume

     This routine disposes of the data for the icons related to the indicated
     volume if this data can be reacquired, for example if the data is provided
     from a resource.
  */

  /**
   *  FlushIconRefsByVolume()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  FlushIconRefsByVolume(SInt16 vRefNum);

  /**
    ==============================================================================
     Controling custom icons
    ==============================================================================
  */

  /**
     SetCustomIconsEnabled

     Enable or disable custom icons on the specified volume.
  */

  /**
   *  SetCustomIconsEnabled()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetCustomIconsEnabled(SInt16 vRefNum, Boolean enableCustomIcons);

  /**
     GetCustomIconsEnabled

     Return true if custom icons are enabled on the specified volume, false
     otherwise.
  */

  /**
   *  GetCustomIconsEnabled()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetCustomIconsEnabled(SInt16 vRefNum, Boolean *customIconsEnabled);

  /**
     IsIconRefMaskEmpty
     Returns true if the mask for this icon is blank
  */

  /**
   *  IsIconRefMaskEmpty()
   *

   *    \non_carbon_cfm   in IconServicesLib 8.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  Boolean
  IsIconRefMaskEmpty(IconRef iconRef);

  /**
     GetIconRefVariant
     Icon variants allows different images to be used with different icon state.
     For example, the 'open' variant for a folder could be represented with
     an open folder.
     Given an icon ref and a desired variant, this routine returns an icon
     ref (which may be the same as the input icon ref) and a transformation
     which should be used with PlotIconRef() to render the icon appropriately.
     The returned icon ref should be used to do hit-testing.
  */

  /**
   *  GetIconRefVariant()
   *

   *    \non_carbon_cfm   in IconServicesLib 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  IconRef
  GetIconRefVariant(IconRef inIconRef, OSType inVariant,
                    IconTransformType *outTransform);

  /**
    ==============================================================================
     Icon files (.icns files)
    ==============================================================================
  */

  /**
     RegisterIconRefFromIconFile
     This routine adds a new entry to the IconRef registry. Other clients will be
     able to access it using the (creator, iconType) pair specified here.
     Lower-case creators are reserved for the system.
     If the creator is kSystemIconsCreator and the iconType is 0, a new IconRef
     is always returned. Otherwise, if the creator and type have already been
     registered, the previously registered IconRef is returned.
     This routine increments the reference count of the IconRef. Call
     ReleaseIconRef() when you're done with it.
  */

  /**
   *  RegisterIconRefFromIconFile()
   *

   *    \non_carbon_cfm   in IconServicesLib 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  RegisterIconRefFromIconFile(OSType creator, OSType iconType,
                              const FSSpec *iconFile, IconRef *theIconRef);

  /**
     ReadIconFile
     Read the specified icon file into the icon family handle.
     The caller is responsible for disposing the iconFamily
  */

  /**
   *  ReadIconFile()
   *

   *    \non_carbon_cfm   in IconServicesLib 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ReadIconFile(const FSSpec *iconFile, IconFamilyHandle *iconFamily);

  /* ReadIconFromFSRef*/
  /**
   *  ReadIconFromFSRef()
   *
   *  Discussion:
   *    This routine reads an icon (icns) file into memory.
   *
   *  Parameters:
   *
   *    ref:
   *      The FSRef for the icon file.
   *
   *    iconFamily:
   *      The handle for the icon family.
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
   X version 10.1 and later
   *    \mac_os_x         in version 10.1 and later
   */
  OSStatus
  ReadIconFromFSRef(const FSRef *ref, IconFamilyHandle *iconFamily);

  /**
     WriteIconFile
     Write the iconFamily handle to the specified file
  */

  /**
   *  WriteIconFile()
   *

   *    \non_carbon_cfm   in IconServicesLib 9.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  WriteIconFile(IconFamilyHandle iconFamily, const FSSpec *iconFile);

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

#endif /* __ICONS__ */
* / or disposing the iconFamily
               * /

           /**
            *  ReadIconFile()
            *

            *    \non_carbon_cfm   in IconServicesLib 9.0 and later
            *    \carbon_lib        in CarbonLib 1.0 and later
            *    \mac_os_x         in version 10.0 and later
            */
           OSErr
           ReadIconFile(const FSSpec *iconFile, IconFamilyHandle *iconFamily);

/* ReadIconFromFSRef*/
/**
 *  ReadIconFromFSRef()
 *
 *  Discussion:
 *    This routine reads an icon (icns) file into memory.
 *
 *  Parameters:
 *
 *    ref:
 *      The FSRef for the icon file.
 *
 *    iconFamily:
 *      The handle for the icon family.
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
 X version 10.1 and later
 *    \mac_os_x         in version 10.1 and later
 */
OSStatus
ReadIconFromFSRef(const FSRef *ref, IconFamilyHandle *iconFamily);

/**
   WriteIconFile
   Write the iconFamily handle to the specified file
*/

/**
 *  WriteIconFile()
 *

 *    \non_carbon_cfm   in IconServicesLib 9.0 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
OSErr WriteIconFile(IconFamilyHandle iconFamily, const FSSpec *iconFile);

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

#endif /* __ICONS__ */
* /*/*/ * /*/*/ * /*/*/ * /*/*/ */*/