/**
     \file       TextServices.h

    \brief   Text Services Manager Interfaces.

    \introduced_in  Mac OS 9
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1991-2001 by Apple Computer, Inc., all rights reserved.

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __TEXTSERVICES__
#define __TEXTSERVICES__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __EVENTS__
#include <Events.h>
#endif

#ifndef __MENUS__
#include <Menus.h>
#endif

#ifndef __AEDATAMODEL__
#include <AEDataModel.h>
#endif

#ifndef __AEREGISTRY__
#include <AERegistry.h>
#endif

#ifndef __AEINTERACTION__
#include <AEInteraction.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __CARBONEVENTS__
#include <CarbonEvents.h>
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

enum {
  kTextService = FOUR_CHAR_CODE(
      'tsvc'), /** component type for the component description */
  kInputMethodService = FOUR_CHAR_CODE(
      'inpm'),         /** component subtype for the component description */
  kTSMVersion = 0x0150 /** Version of the Text Services Manager is 1.5 */
};

enum {
  kUnicodeDocument = FOUR_CHAR_CODE(
      'udoc'), /** TSM Document type for Unicode-savvy application */
  kUnicodeTextService =
      FOUR_CHAR_CODE('utsv') /** Component type for Unicode Text Service */
};

/** Language and Script constants*/
enum {
  kUnknownLanguage = 0xFFFF,
  kUnknownScript = 0xFFFF,
  kNeutralScript = 0xFFFF
};

enum {
  /** Component Flags in ComponentDescription */
  bTakeActiveEvent = 15,    /** bit set if the component takes active event */
  bHandleAERecording = 16,  /** bit set if the component takes care of recording
                               Apple Events <new in vers2.0> */
  bScriptMask = 0x00007F00, /** bit 8 - 14 */
  bLanguageMask = 0x000000FF,                       /** bit 0 - 7  */
  bScriptLanguageMask = bScriptMask + bLanguageMask /** bit 0 - 14  */
};

enum {
  /** Typing method property constants for Input Methods */
  kIMJaTypingMethodProperty = FOUR_CHAR_CODE(
      'jtyp'), /** Typing method property for Japanese input methods*/
  kIMJaTypingMethodRoman = FOUR_CHAR_CODE('roma'), /** Roman typing*/
  kIMJaTypingMethodKana = FOUR_CHAR_CODE('kana')   /** Kana typing*/
};

enum {
  /** Low level routines which are dispatched directly to the Component Manager
   */
  kCMGetScriptLangSupport = 0x0001,   /** Component Manager call selector 1 */
  kCMInitiateTextService = 0x0002,    /** Component Manager call selector 2 */
  kCMTerminateTextService = 0x0003,   /** Component Manager call selector 3 */
  kCMActivateTextService = 0x0004,    /** Component Manager call selector 4 */
  kCMDeactivateTextService = 0x0005,  /** Component Manager call selector 5 */
  kCMTextServiceEvent = 0x0006,       /** Component Manager call selector 6 */
  kCMGetTextServiceMenu = 0x0007,     /** Component Manager call selector 7 */
  kCMTextServiceMenuSelect = 0x0008,  /** Component Manager call selector 8 */
  kCMFixTextService = 0x0009,         /** Component Manager call selector 9 */
  kCMSetTextServiceCursor = 0x000A,   /** Component Manager call selector 10 */
  kCMHidePaletteWindows = 0x000B,     /** Component Manager call selector 11 */
  kCMGetTextServiceProperty = 0x000C, /** Component Manager call selector 12 */
  kCMSetTextServiceProperty = 0x000D  /** Component Manager call selector 13 */
};

enum {
  /** New low level routines which are dispatched directly to the Component
     Manager */
  kCMUCTextServiceEvent = 0x000E /** Component Manager call selector 14 */
};

/** extract Script/Language code from Component flag ... */
#define mGetScriptCode(cdRec)                                                  \
  ((ScriptCode)((cdRec.componentFlags & bScriptMask) >> 8))
#define mGetLanguageCode(cdRec) ((LangCode)cdRec.componentFlags & bLanguageMask)

/** New opaque definitions for types */
typedef struct OpaqueTSMDocumentID *TSMDocumentID;
typedef OSType InterfaceTypeList[1];

/** Text Service Info List */
struct TextServiceInfo {
  Component fComponent;
  Str255 fItemName;
};
typedef struct TextServiceInfo TextServiceInfo;
typedef TextServiceInfo *TextServiceInfoPtr;
struct TextServiceList {
  short fTextServiceCount; /** number of entries in the 'fServices' array */
  TextServiceInfo
      fServices[1]; /** Note: array of 'TextServiceInfo' records follows */
};
typedef struct TextServiceList TextServiceList;
typedef TextServiceList *TextServiceListPtr;
typedef TextServiceListPtr *TextServiceListHandle;
struct ScriptLanguageRecord {
  ScriptCode fScript;
  LangCode fLanguage;
};
typedef struct ScriptLanguageRecord ScriptLanguageRecord;
struct ScriptLanguageSupport {
  short fScriptLanguageCount; /** number of entries in the
                                 'fScriptLanguageArray' array */
  ScriptLanguageRecord
      fScriptLanguageArray[1]; /** Note: array of 'ScriptLanguageRecord' records
                                  follows */
};
typedef struct ScriptLanguageSupport ScriptLanguageSupport;
typedef ScriptLanguageSupport *ScriptLanguageSupportPtr;
typedef ScriptLanguageSupportPtr *ScriptLanguageSupportHandle;
/** High level TSM Doucment routines */
/**
 *  NewTSMDocument()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
NewTSMDocument(short numOfInterface, InterfaceTypeList supportedInterfaceTypes,
               TSMDocumentID *idocID, long refcon)
    TWOWORDINLINE(0x7000, 0xAA54);

/**
 *  DeleteTSMDocument()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
DeleteTSMDocument(TSMDocumentID idocID) TWOWORDINLINE(0x7001, 0xAA54);

/**
 *  ActivateTSMDocument()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
ActivateTSMDocument(TSMDocumentID idocID) TWOWORDINLINE(0x7002, 0xAA54);

/**
 *  DeactivateTSMDocument()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
DeactivateTSMDocument(TSMDocumentID idocID) TWOWORDINLINE(0x7003, 0xAA54);

/**
 *  FixTSMDocument()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
FixTSMDocument(TSMDocumentID idocID) TWOWORDINLINE(0x7007, 0xAA54);

/**
 *  GetServiceList()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
GetServiceList(short numOfInterface, OSType *supportedInterfaceTypes,
               TextServiceListHandle *serviceInfo, long *seedValue)
    TWOWORDINLINE(0x7008, 0xAA54);

/**
 *  OpenTextService()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
OpenTextService(TSMDocumentID idocID, Component aComponent,
                ComponentInstance *aComponentInstance)
    TWOWORDINLINE(0x7009, 0xAA54);

/**
 *  CloseTextService()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
CloseTextService(TSMDocumentID idocID, ComponentInstance aComponentInstance)
    TWOWORDINLINE(0x700A, 0xAA54);

/**
 *  SendAEFromTSMComponent()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
SendAEFromTSMComponent(const AppleEvent *theAppleEvent, AppleEvent *reply,
                       AESendMode sendMode, AESendPriority sendPriority,
                       long timeOutInTicks, AEIdleUPP idleProc,
                       AEFilterUPP filterProc) TWOWORDINLINE(0x700B, 0xAA54);

/**
 *  SendTextInputEvent()
 *
 *  Discussion:
 *    This API replaces SendAEFromTSMComponent on Mac OS X only. Input
 *    Methods on Mac OS X are Carbon Event based instead of AppleEvent
 *    based.  The Carbon TextInput events which they generate are
 *    provided to TSM for dispatching via this API.
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib N.e.v.e.r and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
SendTextInputEvent(EventRef inEvent);

/**
 *  SetDefaultInputMethod()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
SetDefaultInputMethod(Component ts, ScriptLanguageRecord *slRecordPtr)
    TWOWORDINLINE(0x700C, 0xAA54);

/**
 *  GetDefaultInputMethod()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
GetDefaultInputMethod(Component *ts, ScriptLanguageRecord *slRecordPtr)
    TWOWORDINLINE(0x700D, 0xAA54);

/**
 *  SetTextServiceLanguage()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
SetTextServiceLanguage(ScriptLanguageRecord *slRecordPtr)
    TWOWORDINLINE(0x700E, 0xAA54);

/**
 *  GetTextServiceLanguage()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
GetTextServiceLanguage(ScriptLanguageRecord *slRecordPtr)
    TWOWORDINLINE(0x700F, 0xAA54);

/**
 *  UseInputWindow()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSErr)
UseInputWindow(TSMDocumentID idocID, Boolean useWindow)
    TWOWORDINLINE(0x7010, 0xAA54);

/**
 *  TSMSetInlineInputRegion()
 *
 *  Discussion:
 *    Tell TSM about the region occupied by an inline input session. If
 *    the location of certain mouse events (clicks, mouse moved) occur
 *    within the specified inline input region, TSM will forward these
 *    events to the current Input Method so that it can interact with
 *    the user. Note: If you do not specify this information, TSM will
 *    need to intercept mouse events in the entire content region as
 *    the default, when an input method is active, in order to ensure
 *    that input methods can manage user interaction properly.
 *
 *  Parameters:
 *
 *    inTSMDocument:
 *      The document.
 *
 *    inWindow:
 *      The window that contains the inline input session. You can pass
 *      NULL for this parameter to indicate the user focus window.
 *
 *    inRegion:
 *      The region occupied by the current inline input region. This
 *      should be in the coordinates of the port associated with the
 *      window you passed to inPort. It will need to be recomputed when
 *      the text content of the inline input session content changes
 *      (i.e. due to Update Active Input Area events) and when the
 *      region moves for other reasons, such as window resized,
 *      scrolling, etc. If you pass a NULL region for this parameter,
 *      TSM will default to intercept mouse events in the focus
 *      window's content region.
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(OSStatus)
TSMSetInlineInputRegion(TSMDocumentID inTSMDocument, WindowRef inWindow,
                        RgnHandle inRegion);

/** Following calls from Classic event loops not needed for Carbon clients. */
#if CALL_NOT_IN_CARBON
/**
 *  TSMEvent()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Boolean)
TSMEvent(EventRecord *event) TWOWORDINLINE(0x7004, 0xAA54);

/**
 *  TSMMenuSelect()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Boolean)
TSMMenuSelect(long menuResult) TWOWORDINLINE(0x7005, 0xAA54);

/**
 *  SetTSMCursor()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(Boolean)
SetTSMCursor(Point mousePos) TWOWORDINLINE(0x7006, 0xAA54);

/** Following ServiceWindow API replaced by Window Manager API in Carbon. */
/**
 *  NewServiceWindow()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
NewServiceWindow(void *wStorage, const Rect *boundsRect, ConstStr255Param title,
                 Boolean visible, short theProc, WindowRef behind,
                 Boolean goAwayFlag, ComponentInstance ts, WindowRef *window)
    TWOWORDINLINE(0x7011, 0xAA54);

/**
 *  CloseServiceWindow()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
CloseServiceWindow(WindowRef window) TWOWORDINLINE(0x7012, 0xAA54);

/**
 *  GetFrontServiceWindow()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
GetFrontServiceWindow(WindowRef *window) TWOWORDINLINE(0x7013, 0xAA54);

/**
 *  FindServiceWindow()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(short)
FindServiceWindow(Point thePoint, WindowRef *theWindow)
    TWOWORDINLINE(0x7017, 0xAA54);

/**
 *  NewCServiceWindow()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
NewCServiceWindow(void *wStorage, const Rect *boundsRect,
                  ConstStr255Param title, Boolean visible, short theProc,
                  WindowRef behind, Boolean goAwayFlag, ComponentInstance ts,
                  WindowRef *window) TWOWORDINLINE(0x701A, 0xAA54);

/** Explicit initialization not needed for Carbon clients, since TSM is */
/** instanciated per-context. */
/**
 *  InitTSMAwareApplication()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
InitTSMAwareApplication(void) TWOWORDINLINE(0x7014, 0xAA54);

/**
 *  CloseTSMAwareApplication()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
CloseTSMAwareApplication(void) TWOWORDINLINE(0x7015, 0xAA54);

/** Component Manager Interfaces to Input Methods */
#endif /** CALL_NOT_IN_CARBON */

/**
 *  GetScriptLanguageSupport()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(ComponentResult)
GetScriptLanguageSupport(ComponentInstance ts,
                         ScriptLanguageSupportHandle *scriptHdl)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0001, 0x7000, 0xA82A);

/**
 *  InitiateTextService()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(ComponentResult)
InitiateTextService(ComponentInstance ts)
    FIVEWORDINLINE(0x2F3C, 0x0000, 0x0002, 0x7000, 0xA82A);

/**
 *  TerminateTextService()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(ComponentResult)
TerminateTextService(ComponentInstance ts)
    FIVEWORDINLINE(0x2F3C, 0x0000, 0x0003, 0x7000, 0xA82A);

/**
 *  ActivateTextService()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(ComponentResult)
ActivateTextService(ComponentInstance ts)
    FIVEWORDINLINE(0x2F3C, 0x0000, 0x0004, 0x7000, 0xA82A);

/**
 *  DeactivateTextService()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(ComponentResult)
DeactivateTextService(ComponentInstance ts)
    FIVEWORDINLINE(0x2F3C, 0x0000, 0x0005, 0x7000, 0xA82A);

/**
 *  GetTextServiceMenu()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(ComponentResult)
GetTextServiceMenu(ComponentInstance ts, MenuRef *serviceMenu)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x0007, 0x7000, 0xA82A);

/** New Text Service call in Carbon. */
/** Note: Only Raw Key and Mouse-flavored events are passed to Text Services on
 * MacOS X. */
/**
 *  TextServiceEventRef()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.1 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(ComponentResult)
TextServiceEventRef(ComponentInstance ts, EventRef event)
    FIVEWORDINLINE(0x2F3C, 0x0006, 0x0006, 0x7000, 0xA82A);

#if CALL_NOT_IN_CARBON
/**
 *  TextServiceEvent()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
TextServiceEvent(ComponentInstance ts, short numOfEvents, EventRecord *event)
    FIVEWORDINLINE(0x2F3C, 0x0006, 0x0006, 0x7000, 0xA82A);

/**
 *  UCTextServiceEvent()
 *

 *    \non_carbon_cfm   in InterfaceLib 8.5 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
UCTextServiceEvent(ComponentInstance ts, short numOfEvents, EventRecord *event,
                   UniChar unicodeString[], UniCharCount unicodeStrLength)
    FIVEWORDINLINE(0x2F3C, 0x000E, 0x000E, 0x7000, 0xA82A);

/**
 *  TextServiceMenuSelect()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
TextServiceMenuSelect(ComponentInstance ts, MenuRef serviceMenu, short item)
    FIVEWORDINLINE(0x2F3C, 0x0006, 0x0008, 0x7000, 0xA82A);

/**
 *  SetTextServiceCursor()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(ComponentResult)
SetTextServiceCursor(ComponentInstance ts, Point mousePos)
    FIVEWORDINLINE(0x2F3C, 0x0004, 0x000A, 0x7000, 0xA82A);

#endif /** CALL_NOT_IN_CARBON */

/**
 *  FixTextService()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(ComponentResult)
FixTextService(ComponentInstance ts)
    FIVEWORDINLINE(0x2F3C, 0x0000, 0x0009, 0x7000, 0xA82A);

/**
 *  HidePaletteWindows()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(ComponentResult)
HidePaletteWindows(ComponentInstance ts)
    FIVEWORDINLINE(0x2F3C, 0x0000, 0x000B, 0x7000, 0xA82A);

/**
 *  GetTextServiceProperty()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(ComponentResult)
GetTextServiceProperty(ComponentInstance ts, OSType propertySelector,
                       SInt32 *result)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x000C, 0x7000, 0xA82A);

/**
 *  SetTextServiceProperty()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.0 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(ComponentResult)
SetTextServiceProperty(ComponentInstance ts, OSType propertySelector,
                       SInt32 value)
    FIVEWORDINLINE(0x2F3C, 0x0008, 0x000D, 0x7000, 0xA82A);

/** Get the active TSMDocument in the current application context.       */
/** If TSM has enabled bottom line input mode because no TSMDocument     */
/** is active, NULL will be returned.                                    */
/**
 *  TSMGetActiveDocument()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        in CarbonLib 1.3 and later
 *    \mac_os_x         in version 10.0 and later
 */
EXTERN_API(TSMDocumentID)
TSMGetActiveDocument(void);

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

#endif /** __TEXTSERVICES__ */