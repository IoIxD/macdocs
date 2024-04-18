/**
     \file       AVComponents.h

    \brief   Standard includes for standard AV panels

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1989-2001 by Apple Computer, Inc., all rights reserved

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __AVCOMPONENTS__
#define __AVCOMPONENTS__

#ifndef __DIALOGS__
#include <Dialogs.h>
#endif

#ifndef __VIDEO__
#include <Video.h>
#endif

#ifndef __DISPLAYS__
#include <Displays.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __CMAPPLICATION__
#include <CMApplication.h>
#endif

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
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

/**
    The subtypes listed here are for example only.  The display manager will
   find _all_ panels with the appropriate types.  These panels return class
   information that is used to devide them up into groups to be displayed in the
   AV Windows (class means "geometry" or "color" or other groupings like that.
*/
enum {
  kAVPanelType = FOUR_CHAR_CODE('avpc'), /** Panel subtypes        */
  kBrightnessPanelSubType = FOUR_CHAR_CODE('brit'),
  kContrastPanelSubType = FOUR_CHAR_CODE('cont'),
  kBitDepthPanelSubType = FOUR_CHAR_CODE('bitd'),
  kAVEngineType = FOUR_CHAR_CODE('avec'), /** Engine subtypes          */
  kBrightnessEngineSubType = FOUR_CHAR_CODE('brit'),
  kContrastEngineSubType = FOUR_CHAR_CODE(
      'cont'), /**    kBitDepthEngineSubType     = 'bitd',       // Not used */
  kAVPortType = FOUR_CHAR_CODE(
      'avdp'), /** subtypes are defined in each port's public .h file */
  kAVUtilityType = FOUR_CHAR_CODE('avuc'),
  kAVBackChannelSubType = FOUR_CHAR_CODE('avbc'),
  kAVCommunicationType = FOUR_CHAR_CODE('avcm'),
  kAVDialogType = FOUR_CHAR_CODE('avdg')
};

/** PortComponent subtypes are up to the port and display manager does not use
   the subtype to find port components.  Instead, display manager uses an
   internal cache to search for portcompoennts. It turns out to be useful to
   have a unique subtype so that engines can see if they should apply themselves
   to a particular port component.

   PortKinds are the "class" of port.  When a port is registered with display
   manager (creating a display ID), the caller of DMNewDisplayIDByPortComponent
   passes a portKind.  Ports of this type are returned by DMNewDevicePortList.

   PortKinds are NOT subtypes of components
   PortKinds ARE used to register and find port components with Display Manager.
   Here are the basic port kinds:

   Video displays are distinct from video out because there are some video out
   ports that are not actaully displays. if EZAV is looking to configure
   displays, it needs to look for kAVVideoDisplayPortKind not
   kAVVideoOutPortKind.
*/
enum {
  kAVVideoDisplayPortKind =
      FOUR_CHAR_CODE('pkdo'), /** Video Display (CRT or panel display) */
  kAVVideoOutPortKind =
      FOUR_CHAR_CODE('pkvo'), /** Video out port (camera output). */
  kAVVideoInPortKind =
      FOUR_CHAR_CODE('pkvi'), /** Video in port (camera input)               */
  kAVSoundOutPortKind =
      FOUR_CHAR_CODE('pkso'), /** Sound out port (speaker or speaker jack) */
  kAVSoundInPortKind = FOUR_CHAR_CODE(
      'pksi'), /** Sound in port (microphone or microphone jack)  */
  kAVDeviceType =
      FOUR_CHAR_CODE('avdc'), /** Device Component subtypes are up to the
                                 manufacturor since each device may contain
                                 multiple function types (eg telecaster) */
  kAVDisplayDeviceKind = FOUR_CHAR_CODE('dkvo'), /** Display device*/
  /** Device Component subtypes are up to the manufacturor since each device may
     contain multiple function types (eg telecaster)*/
  kAVCategoryType = FOUR_CHAR_CODE('avcc'),
  kAVSoundInSubType = FOUR_CHAR_CODE('avao'),
  kAVSoundOutSubType = FOUR_CHAR_CODE('avai'),
  kAVVideoInSubType = FOUR_CHAR_CODE('vdin'),
  kAVVideoOutSubType = FOUR_CHAR_CODE('vdou'),
  kAVInvalidType = FOUR_CHAR_CODE(
      'badt') /** Some calls return a component type, in case of errors, these
                 types are set to kAVInvalidComponentType */
};

/**
   Interface Signatures are used to identify what kind of component
   calls can be made for a given component. Today this applies only
   to ports, but could be applied to other components as well.
*/
enum {
  kAVGenericInterfaceSignature = FOUR_CHAR_CODE('dmgr'),
  kAVAppleVisionInterfaceSignature = FOUR_CHAR_CODE('avav')
};

/** =============================                    */
/** Panel Class Constants                            */
/** =============================                    */
enum {
  kAVPanelClassDisplayDefault = FOUR_CHAR_CODE('cdsp'),
  kAVPanelClassColor = FOUR_CHAR_CODE('cclr'),
  kAVPanelClassGeometry = FOUR_CHAR_CODE('cgeo'),
  kAVPanelClassSound = FOUR_CHAR_CODE('csnd'),
  kAVPanelClassPreferences = FOUR_CHAR_CODE('cprf'),
  kAVPanelClassLCD = FOUR_CHAR_CODE('clcd'),
  kAVPanelClassMonitorSound = FOUR_CHAR_CODE('cres'),
  kAVPanelClassAlert = FOUR_CHAR_CODE('calr'),
  kAVPanelClassExtras = FOUR_CHAR_CODE('cext'),
  kAVPanelClassRearrange = FOUR_CHAR_CODE('crea')
};

/** =============================                    */
/** AV Notification Types                            */
/** =============================                    */
/**
   This notification will be sent whenever a
   device has been reset, for whatever reason.
*/
enum { kAVNotifyDeviceReset = FOUR_CHAR_CODE('rset') };

/** =============================                    */
/** Component interface revision levels and history  */
/** =============================                    */
enum {
  kAVPanelComponentInterfaceRevOne = 1,
  kAVPanelComponentInterfaceRevTwo = 2,
  kAVEngineComponentInterfaceRevOne = 1,
  kAVPortComponentInterfaceRevOne = 1,
  kAVDeviceComponentInterfaceRevOne = 1,
  kAVUtilityComponentInterfaceRevOne = 1
};

/** =============================                    */
/** Adornment Constants                              */
/** =============================                    */
enum { kAVPanelAdornmentNoBorder = 0, kAVPanelAdornmentStandardBorder = 1 };

enum { kAVPanelAdornmentNoName = 0, kAVPanelAdornmentStandardName = 1 };

/** =============================                    */
/** Selector Ranges                                  */
/** =============================                    */
enum {
  kBaseAVComponentSelector =
      256, /** First apple-defined selector for AV components */
  kAppleAVComponentSelector =
      512 /** First apple-defined type-specific selector for AV components */
};

/** =============================                */
/** Panel Standard component selectors           */
/** =============================                */
enum {
  kAVPanelFakeRegisterSelect = kComponentRegisterSelect, /** -5 */
  kAVPanelSetCustomDataSelect = 0,
  kAVPanelGetDitlSelect = 1,
  kAVPanelGetTitleSelect = 2,
  kAVPanelInstallSelect = 3,
  kAVPanelEventSelect = 4,
  kAVPanelItemSelect = 5,
  kAVPanelRemoveSelect = 6,
  kAVPanelValidateInputSelect = 7,
  kAVPanelGetSettingsIdentifiersSelect = 8,
  kAVPanelGetSettingsSelect = 9,
  kAVPanelSetSettingsSelect = 10,
  kAVPanelSelectorGetFidelitySelect = kBaseAVComponentSelector,
  kAVPanelSelectorTargetDeviceSelect = 257,
  kAVPanelSelectorGetPanelClassSelect = 258,
  kAVPanelSelectorGetPanelAdornmentSelect = 259,
  kAVPanelSelectorGetBalloonHelpStringSelect = 260,
  kAVPanelSelectorAppleGuideRequestSelect = 261,
  kAVPanelSelectorGetFocusStatusSelect = 262,
  kAVPanelSelectorSetFocusStatusSelect = 263
};

/** =============================                */
/** Engine Standard component selectors          */
/** =============================                */
enum {
  kAVEngineGetEngineFidelitySelect = kBaseAVComponentSelector,
  kAVEngineTargetDeviceSelect = 257
};

/** =============================                    */
/** Video Port Specific calls                        */
/** =============================                    */
enum {
  kAVPortCheckTimingModeSelect = 0,
  kAVPortReserved1Select = 1, /** Reserved*/
  kAVPortReserved2Select = 2, /** Reserved*/
  kAVPortGetDisplayTimingInfoSelect = kAppleAVComponentSelector,
  kAVPortGetDisplayProfileCountSelect = 513,
  kAVPortGetIndexedDisplayProfileSelect = 514,
  kAVPortGetDisplayGestaltSelect = 515,
  kAVPortGetDisplayTimingCountSelect = 516,
  kAVPortGetIndexedDisplayTimingSelect = 517,
  kAVPortGetDisplayTimingRangeCountSelect = 518,
  kAVPortGetIndexedDisplayTimingRangeSelect = 519
};

/** =============================                    */
/** AV Port Specific calls                           */
/** =============================                    */
enum {
  kAVPortGetAVDeviceFidelitySelect =
      kBaseAVComponentSelector, /** Port Standard Component selectors */
  kAVPortGetWiggleSelect = 257,
  kAVPortSetWiggleSelect = 258,
  kAVPortGetNameSelect = 259,
  kAVPortGetGraphicInfoSelect = 260,
  kAVPortSetActiveSelect = 261,
  kAVPortGetActiveSelect = 262,
  kAVPortUnsed1Select = 263, /** Selector removed as part of API change.  We
                                don't want to mess up the following selectors,
                                so we put in this spacer (ie kPadSelector). */
  kAVPortGetAVIDSelect = 264,
  kAVPortSetAVIDSelect = 265,
  kAVPortSetDeviceAVIDSelect =
      266, /** For registrar to set device (instead of hitting global directly)
              -- should only be called once */
  kAVPortGetDeviceAVIDSelect =
      267, /** Called by display mgr for generic ports */
  kAVPortGetPowerStateSelect = 268,
  kAVPortSetPowerStateSelect = 269,
  kAVPortGetMakeAndModelSelect = 270, /** Get Make and model information*/
  kAVPortGetInterfaceSignatureSelect =
      271, /** To determine what VideoPort-specific calls can be made*/
  kAVPortReserved3Select = 272, /** Reserved*/
  kAVPortGetManufactureInfoSelect =
      273 /** Get more Make and model information  */
};

/** =============================                    */
/** Device Component Standard Component selectors    */
/** =============================                    */
enum {
  kAVDeviceGetNameSelect = kBaseAVComponentSelector,
  kAVDeviceGetGraphicInfoSelect = 257,
  kAVDeviceGetPowerStateSelect = 258,
  kAVDeviceSetPowerStateSelect = 259,
  kAVDeviceGetAVIDSelect = 260,
  kAVDeviceSetAVIDSelect = 261
};

/** =============================                    */
/** AV Back-Channel Selectors                        */
/** =============================                    */
enum {
  kAVBackChannelReservedSelector = 1,
  kAVBackChannelPreModalFilterSelect = 2,
  kAVBackChannelModalFilterSelect = 3,
  kAVBackChannelAppleGuideLaunchSelect = 4
};

/** =============================                */
/** Engine Standard component selectors          */
/** =============================                */
#if CALL_NOT_IN_CARBON
/**
 *  AVEngineComponentGetFidelity()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVEngineComponentGetFidelity(ComponentInstance engineComponent,
                             DisplayIDType displayID,
                             DMFidelityType *engineFidelity)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0100, 0x7000, 0xA82A);

/**
 *  AVEngineComponentTargetDevice()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVEngineComponentTargetDevice(ComponentInstance engineComponent,
                              DisplayIDType displayID)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0101, 0x7000, 0xA82A);

#endif /** CALL_NOT_IN_CARBON */

/** =============================                */
/** Panel Standard Component calls               */
/** =============================                */
#if CALL_NOT_IN_CARBON
/**
 *  AVPanelFakeRegister()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelFakeRegister(ComponentInstance ci)
    FIVEWORDINLINE(0x2F3C, 0x0000, 0xFFFB, 0x7000, 0xA82A);

/**
 *  AVPanelSetCustomData()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelSetCustomData(ComponentInstance ci, long theCustomData)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0000, 0x7000, 0xA82A);

/**
 *  AVPanelGetDitl()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelGetDitl(ComponentInstance ci, Handle *ditl)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0001, 0x7000, 0xA82A);

/**
 *  AVPanelGetTitle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelGetTitle(ComponentInstance ci, StringPtr title)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0002, 0x7000, 0xA82A);

/**
 *  AVPanelInstall()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelInstall(ComponentInstance ci, DialogRef dialog, long itemOffset)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0003, 0x7000, 0xA82A);

/**
 *  AVPanelEvent()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelEvent(ComponentInstance ci, DialogRef dialog, long itemOffset,
             EventRecord *event, short *itemHit, Boolean *handled)
    FIVEWORDINLINE(0x2F3C, 0x0014, 0x0004, 0x7000, 0xA82A);

/**
 *  AVPanelItem()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelItem(ComponentInstance ci, DialogRef dialog, long itemOffset,
            short itemNum)
    FIVEWORDINLINE(0x2F3C, 0x000A, 0x0005, 0x7000, 0xA82A);

/**
 *  AVPanelRemove()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelRemove(ComponentInstance ci, DialogRef dialog, long itemOffset)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0006, 0x7000, 0xA82A);

/**
 *  AVPanelValidateInput()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelValidateInput(ComponentInstance ci, Boolean *ok)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0007, 0x7000, 0xA82A);

/**
 *  AVPanelGetSettingsIdentifiers()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelGetSettingsIdentifiers(ComponentInstance ci, short *theID,
                              OSType *theType)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0008, 0x7000, 0xA82A);

/**
 *  AVPanelGetSettings()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelGetSettings(ComponentInstance ci, Handle *userDataHand, long flags,
                   DialogRef theDialog, long itemsOffset)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x0009, 0x7000, 0xA82A);

/**
 *  AVPanelSetSettings()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelSetSettings(ComponentInstance ci, Handle userDataHand, long flags,
                   DialogRef theDialog, long itemsOffset)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x000A, 0x7000, 0xA82A);

/**
 *  AVPanelGetFidelity()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelGetFidelity(ComponentInstance panelComponent, DisplayIDType displayID,
                   DMFidelityType *panelFidelity)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0100, 0x7000, 0xA82A);

/**
 *  AVPanelComponentTargetDevice()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelComponentTargetDevice(ComponentInstance panelComponent,
                             DisplayIDType displayID, DialogRef theDialog,
                             long itemsOffset)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0101, 0x7000, 0xA82A);

/**
 *  AVPanelComponentGetPanelClass()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelComponentGetPanelClass(ComponentInstance panelComponent,
                              ResType *panelClass, ResType *subClass,
                              Ptr reserved1, Ptr reserved2)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x0102, 0x7000, 0xA82A);

/**
 *  AVPanelComponentGetPanelAdornment()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelComponentGetPanelAdornment(ComponentInstance panelComponent,
                                  long *panelBorderType, long *panelNameType)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0103, 0x7000, 0xA82A);

/**
 *  AVPanelComponentGetBalloonHelpString()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelComponentGetBalloonHelpString(ComponentInstance panelComponent,
                                     short item, StringPtr balloonString)
    FIVEWORDINLINE(0x2F3C, 0x0006, 0x0104, 0x7000, 0xA82A);

/**
 *  AVPanelComponentAppleGuideRequest()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelComponentAppleGuideRequest(ComponentInstance panelComponent,
                                  OSType agSelector, void *agDataReply)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0105, 0x7000, 0xA82A);

/**
 *  AVPanelComponentGetFocusStatus()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelComponentGetFocusStatus(ComponentInstance panelComponent,
                               Boolean *hasFocus)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0106, 0x7000, 0xA82A);

/**
 *  AVPanelComponentSetFocusStatus()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPanelComponentSetFocusStatus(ComponentInstance panelComponent,
                               DialogPtr theDialog, long itemOffset,
                               Boolean gettingFocus, Boolean *tookFocus)
    FIVEWORDINLINE(0x2F3C, 0x000E, 0x0107, 0x7000, 0xA82A);

#endif /** CALL_NOT_IN_CARBON */

/** =============================                */
/** Port Component Standard Component selectors  */
/** =============================                */
#if CALL_NOT_IN_CARBON
/**
 *  AVPortGetAVDeviceFidelity()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetAVDeviceFidelity(ComponentInstance portComponent, AVIDType deviceAVID,
                          DMFidelityType *portFidelity)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0100, 0x7000, 0xA82A);

/**
 *  AVPortGetWiggle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetWiggle(ComponentInstance portComponent, Boolean *wiggleDevice)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0101, 0x7000, 0xA82A);

/**
 *  AVPortSetWiggle()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortSetWiggle(ComponentInstance portComponent, Boolean wiggleDevice)
    FIVEWORDINLINE(0x2F3C, 0x0002, 0x0102, 0x7000, 0xA82A);

/**
 *  AVPortGetName()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetName(ComponentInstance portComponent, Str255 portName)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0103, 0x7000, 0xA82A);

/**
 *  AVPortGetGraphicInfo()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetGraphicInfo(ComponentInstance portComponent, PicHandle *thePict,
                     Handle *theIconSuite, AVLocationPtr theLocation)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0104, 0x7000, 0xA82A);

/**
 *  AVPortSetActive()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortSetActive(ComponentInstance portComponent, Boolean setActive)
    FIVEWORDINLINE(0x2F3C, 0x0002, 0x0105, 0x7000, 0xA82A);

/**
 *  AVPortGetActive()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetActive(ComponentInstance portComponent, Boolean *isPortActive,
                Boolean *portCanBeActivated, void *reserved)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0106, 0x7000, 0xA82A);

/**
 *  AVPortGetAVID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetAVID(ComponentInstance portComponent, AVIDType *avPortID)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0108, 0x7000, 0xA82A);

/**
 *  AVPortSetAVID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortSetAVID(ComponentInstance portComponent, AVIDType avPortID)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0109, 0x7000, 0xA82A);

/**
 *  AVPortSetDeviceAVID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortSetDeviceAVID(ComponentInstance portComponent, AVIDType avDeviceID)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x010A, 0x7000, 0xA82A);

/**
 *  AVPortGetDeviceAVID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetDeviceAVID(ComponentInstance portComponent, AVIDType *avDeviceID)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x010B, 0x7000, 0xA82A);

/**
 *  AVPortGetPowerState()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetPowerState(ComponentInstance portComponent,
                    AVPowerStatePtr getPowerState)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x010C, 0x7000, 0xA82A);

/**
 *  AVPortSetPowerState()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortSetPowerState(ComponentInstance portComponent,
                    AVPowerStatePtr setPowerState)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x010D, 0x7000, 0xA82A);

/**
 *  AVPortGetMakeAndModel()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetMakeAndModel(ComponentInstance portComponent,
                      DisplayIDType theDisplayID, ResType *manufacturer,
                      UInt32 *model, UInt32 *serialNumber)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x010E, 0x7000, 0xA82A);

/**
 *  AVPortGetInterfaceSignature()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetInterfaceSignature(ComponentInstance portComponent,
                            OSType *interfaceSignature)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x010F, 0x7000, 0xA82A);

/**
 *  AVPortGetManufactureInfo()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetManufactureInfo(ComponentInstance portComponent,
                         DisplayIDType theDisplayID,
                         DMMakeAndModelPtr theMakeAndModel)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0111, 0x7000, 0xA82A);

/** =============================                */
/** Video Out Port Component Selectors           */
/** =============================                */
/**
 *  AVPortCheckTimingMode()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortCheckTimingMode(ComponentInstance displayComponent,
                      DisplayIDType theDisplayID,
                      VDDisplayConnectInfoPtr connectInfo,
                      VDTimingInfoPtr modeTiming,
                      VDDetailedTimingPtr theDetailedTiming)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x0000, 0x7000, 0xA82A);

/**
 *  AVPortGetDisplayTimingInfo()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetDisplayTimingInfo(ComponentInstance displayComponent,
                           VDTimingInfoPtr modeTiming, UInt32 requestedVersion,
                           DMDisplayTimingInfoPtr modeInfo,
                           VDDetailedTimingPtr theDetailedTiming)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x0200, 0x7000, 0xA82A);

/**
 *  AVPortGetDisplayProfileCount()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetDisplayProfileCount(ComponentInstance displayComponent,
                             UInt32 reserved, UInt32 *profileCount,
                             UInt32 *profileSeed)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0201, 0x7000, 0xA82A);

/**
 *  AVPortGetIndexedDisplayProfile()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetIndexedDisplayProfile(ComponentInstance displayComponent,
                               UInt32 reserved, UInt32 profileIndex,
                               UInt32 profileSeed, CMProfileRef *indexedProfile)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x0202, 0x7000, 0xA82A);

/**
 *  AVPortGetDisplayGestalt()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetDisplayGestalt(ComponentInstance displayComponent,
                        ResType displayGestaltSelector,
                        UInt32 *displayGestaltResponse)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x0203, 0x7000, 0xA82A);

/**
 *  AVPortGetDisplayTimingCount()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetDisplayTimingCount(ComponentInstance displayComponent, void *reserved,
                            UInt32 *timingCount, UInt32 *timingsSeed)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0204, 0x7000, 0xA82A);

/**
 *  AVPortGetIndexedDisplayTiming()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetIndexedDisplayTiming(ComponentInstance displayComponent,
                              void *reserved, UInt32 timingIndex,
                              UInt32 timingsSeed,
                              VDDetailedTimingPtr indexedTiming)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x0205, 0x7000, 0xA82A);

/**
 *  AVPortGetDisplayTimingRangeCount()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetDisplayTimingRangeCount(ComponentInstance displayComponent,
                                 void *reserved, UInt32 *rangeCount,
                                 UInt32 *rangeSeed)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0206, 0x7000, 0xA82A);

/**
 *  AVPortGetIndexedDisplayTimingRange()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVPortGetIndexedDisplayTimingRange(ComponentInstance displayComponent,
                                   void *reserved, UInt32 rangeIndex,
                                   UInt32 rangeSeed,
                                   VDDisplayTimingRangePtr indexedRange)
    FIVEWORDINLINE(0x2F3C, 0x0010, 0x0207, 0x7000, 0xA82A);

#endif /** CALL_NOT_IN_CARBON */

/** =============================                */
/** AV Device Component Selectors                */
/** =============================                */
#if CALL_NOT_IN_CARBON
/**
 *  AVDeviceGetName()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVDeviceGetName(ComponentInstance deviceComponent, Str255 portName)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0100, 0x7000, 0xA82A);

/**
 *  AVDeviceGetGraphicInfo()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVDeviceGetGraphicInfo(ComponentInstance deviceComponent, PicHandle *thePict,
                       Handle *theIconSuite, AVLocationPtr theLocation)
    FIVEWORDINLINE(0x2F3C, 0x000C, 0x0101, 0x7000, 0xA82A);

/**
 *  AVDeviceGetPowerState()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVDeviceGetPowerState(ComponentInstance deviceComponent,
                      AVPowerStatePtr getPowerState)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0102, 0x7000, 0xA82A);

/**
 *  AVDeviceSetPowerState()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVDeviceSetPowerState(ComponentInstance deviceComponent,
                      AVPowerStatePtr setPowerState)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0103, 0x7000, 0xA82A);

/**
 *  AVDeviceGetAVID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVDeviceGetAVID(ComponentInstance deviceComponent, AVIDType *avDeviceID)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0104, 0x7000, 0xA82A);

/**
 *  AVDeviceSetAVID()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVDeviceSetAVID(ComponentInstance deviceComponent, AVIDType avDeviceID)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0105, 0x7000, 0xA82A);

#endif /** CALL_NOT_IN_CARBON */

/** =============================                */
/** AV BackChannel Component Selectors           */
/** =============================                */
#if CALL_NOT_IN_CARBON
/**
 *  AVBackChannelPreModalFilter()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVBackChannelPreModalFilter(ComponentInstance compInstance)
    FIVEWORDINLINE(0x2F3C, 0x0000, 0x0002, 0x7000, 0xA82A);

/**
 *  AVBackChannelModalFilter()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVBackChannelModalFilter(ComponentInstance compInstance, EventRecord *theEvent)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0003, 0x7000, 0xA82A);

/**
 *  AVBackChannelAppleGuideLaunch()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
AVBackChannelAppleGuideLaunch(ComponentInstance compInstance,
                              StringPtr theSubject)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0004, 0x7000, 0xA82A);

#endif /** CALL_NOT_IN_CARBON */

/** MixedMode ProcInfo constants for component calls */
enum {
  uppAVEngineComponentGetFidelityProcInfo = 0x00000FF0,
  uppAVEngineComponentTargetDeviceProcInfo = 0x000003F0,
  uppAVPanelFakeRegisterProcInfo = 0x000000F0,
  uppAVPanelSetCustomDataProcInfo = 0x000003F0,
  uppAVPanelGetDitlProcInfo = 0x000003F0,
  uppAVPanelGetTitleProcInfo = 0x000003F0,
  uppAVPanelInstallProcInfo = 0x00000FF0,
  uppAVPanelEventProcInfo = 0x0003FFF0,
  uppAVPanelItemProcInfo = 0x00002FF0,
  uppAVPanelRemoveProcInfo = 0x00000FF0,
  uppAVPanelValidateInputProcInfo = 0x000003F0,
  uppAVPanelGetSettingsIdentifiersProcInfo = 0x00000FF0,
  uppAVPanelGetSettingsProcInfo = 0x0000FFF0,
  uppAVPanelSetSettingsProcInfo = 0x0000FFF0,
  uppAVPanelGetFidelityProcInfo = 0x00000FF0,
  uppAVPanelComponentTargetDeviceProcInfo = 0x00003FF0,
  uppAVPanelComponentGetPanelClassProcInfo = 0x0000FFF0,
  uppAVPanelComponentGetPanelAdornmentProcInfo = 0x00000FF0,
  uppAVPanelComponentGetBalloonHelpStringProcInfo = 0x00000EF0,
  uppAVPanelComponentAppleGuideRequestProcInfo = 0x00000FF0,
  uppAVPanelComponentGetFocusStatusProcInfo = 0x000003F0,
  uppAVPanelComponentSetFocusStatusProcInfo = 0x0000DFF0,
  uppAVPortGetAVDeviceFidelityProcInfo = 0x00000FF0,
  uppAVPortGetWiggleProcInfo = 0x000003F0,
  uppAVPortSetWiggleProcInfo = 0x000001F0,
  uppAVPortGetNameProcInfo = 0x000003F0,
  uppAVPortGetGraphicInfoProcInfo = 0x00003FF0,
  uppAVPortSetActiveProcInfo = 0x000001F0,
  uppAVPortGetActiveProcInfo = 0x00003FF0,
  uppAVPortGetAVIDProcInfo = 0x000003F0,
  uppAVPortSetAVIDProcInfo = 0x000003F0,
  uppAVPortSetDeviceAVIDProcInfo = 0x000003F0,
  uppAVPortGetDeviceAVIDProcInfo = 0x000003F0,
  uppAVPortGetPowerStateProcInfo = 0x000003F0,
  uppAVPortSetPowerStateProcInfo = 0x000003F0,
  uppAVPortGetMakeAndModelProcInfo = 0x0000FFF0,
  uppAVPortGetInterfaceSignatureProcInfo = 0x000003F0,
  uppAVPortGetManufactureInfoProcInfo = 0x00000FF0,
  uppAVPortCheckTimingModeProcInfo = 0x0000FFF0,
  uppAVPortGetDisplayTimingInfoProcInfo = 0x0000FFF0,
  uppAVPortGetDisplayProfileCountProcInfo = 0x00003FF0,
  uppAVPortGetIndexedDisplayProfileProcInfo = 0x0000FFF0,
  uppAVPortGetDisplayGestaltProcInfo = 0x00000FF0,
  uppAVPortGetDisplayTimingCountProcInfo = 0x00003FF0,
  uppAVPortGetIndexedDisplayTimingProcInfo = 0x0000FFF0,
  uppAVPortGetDisplayTimingRangeCountProcInfo = 0x00003FF0,
  uppAVPortGetIndexedDisplayTimingRangeProcInfo = 0x0000FFF0,
  uppAVDeviceGetNameProcInfo = 0x000003F0,
  uppAVDeviceGetGraphicInfoProcInfo = 0x00003FF0,
  uppAVDeviceGetPowerStateProcInfo = 0x000003F0,
  uppAVDeviceSetPowerStateProcInfo = 0x000003F0,
  uppAVDeviceGetAVIDProcInfo = 0x000003F0,
  uppAVDeviceSetAVIDProcInfo = 0x000003F0,
  uppAVBackChannelPreModalFilterProcInfo = 0x000000F0,
  uppAVBackChannelModalFilterProcInfo = 0x000003F0,
  uppAVBackChannelAppleGuideLaunchProcInfo = 0x000003F0
};

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

#endif /** __AVCOMPONENTS__ */