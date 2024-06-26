/**
     \file       AppleEvents.h

    \brief   AppleEvent Package Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1989-2001 by Apple Computer, Inc., all rights reserved

    \ingroup AppleEvent

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __APPLEEVENTS__
#define __APPLEEVENTS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

/**
    Note:   The functions and types for the building and parsing AppleEvent
            messages has moved to AEDataModel.h
*/
#ifndef __AEDATAMODEL__
#include <AEDataModel.h>
#endif

/**
    Note:   The functions for interacting with events has moved to
   AEInteraction.h
*/
#ifndef __AEINTERACTION__
#include <AEInteraction.h>
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
        /** Keywords for Apple event parameters */
        keyDirectObject = FOUR_CHAR_CODE('----'),
        keyErrorNumber = FOUR_CHAR_CODE('errn'),
        keyErrorString = FOUR_CHAR_CODE('errs'),
        keyProcessSerialNumber =
            FOUR_CHAR_CODE('psn '),              /** Keywords for special handlers */
        keyPreDispatch = FOUR_CHAR_CODE('phac'), /** preHandler accessor call */
        keySelectProc = FOUR_CHAR_CODE('selh'),  /** more selector call */
                                                 /** Keyword for recording */
        keyAERecorderCount =
            FOUR_CHAR_CODE('recr'), /** available only in vers 1.0.1 and greater */
                                    /** Keyword for version information */
        keyAEVersion =
            FOUR_CHAR_CODE('vers') /** available only in vers 1.0.1 and greater */
    };

    /** Event Class */
    enum
    {
        kCoreEventClass = FOUR_CHAR_CODE('aevt')
    };

    /** Event ID©s */
    enum
    {
        kAEOpenApplication = FOUR_CHAR_CODE('oapp'),
        kAEOpenDocuments = FOUR_CHAR_CODE('odoc'),
        kAEPrintDocuments = FOUR_CHAR_CODE('pdoc'),
        kAEQuitApplication = FOUR_CHAR_CODE('quit'),
        kAEAnswer = FOUR_CHAR_CODE('ansr'),
        kAEApplicationDied = FOUR_CHAR_CODE('obit'),
        kAEShowPreferences = FOUR_CHAR_CODE(
            'pref') /** sent by Mac OS X when the user chooses the Preferences item */
    };

    /** Constants for recording */
    enum
    {
        kAEStartRecording =
            FOUR_CHAR_CODE('reca'), /** available only in vers 1.0.1 and greater */
        kAEStopRecording =
            FOUR_CHAR_CODE('recc'), /** available only in vers 1.0.1 and greater */
        kAENotifyStartRecording =
            FOUR_CHAR_CODE('rec1'), /** available only in vers 1.0.1 and greater */
        kAENotifyStopRecording =
            FOUR_CHAR_CODE('rec0'), /** available only in vers 1.0.1 and greater */
        kAENotifyRecording =
            FOUR_CHAR_CODE('recr') /** available only in vers 1.0.1 and greater */
    };

    /**
     * AEEventSource is defined as an SInt8 for compatability with pascal.
     * Important note: keyEventSourceAttr is returned by AttributePtr as a
     * typeShortInteger. Be sure to pass at least two bytes of storage to
     * AEGetAttributePtr - the result can be compared directly against the following
     * enums.
     */
    typedef SInt8 AEEventSource;
    enum
    {
        kAEUnknownSource = 0,
        kAEDirectCall = 1,
        kAESameProcess = 2,
        kAELocalProcess = 3,
        kAERemoteProcess = 4
    };

    /***************************************************************************
      These calls are used to set up and modify the event dispatch table.
    **************************************************************************/
    /**
     *  AEInstallEventHandler()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    AEInstallEventHandler(AEEventClass theAEEventClass, AEEventID theAEEventID,
                          AEEventHandlerUPP handler, long handlerRefcon,
                          Boolean isSysHandler);

    /**
     *  AERemoveEventHandler()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    AERemoveEventHandler(AEEventClass theAEEventClass, AEEventID theAEEventID,
                         AEEventHandlerUPP handler, Boolean isSysHandler);

    /**
     *  AEGetEventHandler()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    AEGetEventHandler(AEEventClass theAEEventClass, AEEventID theAEEventID,
                      AEEventHandlerUPP *handler, long *handlerRefcon,
                      Boolean isSysHandler);

    /***************************************************************************
      These calls are used to set up and modify special hooks into the
      AppleEvent manager.
    **************************************************************************/
    /**
     *  AEInstallSpecialHandler()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    AEInstallSpecialHandler(AEKeyword functionClass, AEEventHandlerUPP handler,
                            Boolean isSysHandler);

    /**
     *  AERemoveSpecialHandler()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    AERemoveSpecialHandler(AEKeyword functionClass, AEEventHandlerUPP handler,
                           Boolean isSysHandler);

    /**
     *  AEGetSpecialHandler()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    AEGetSpecialHandler(AEKeyword functionClass, AEEventHandlerUPP *handler,
                        Boolean isSysHandler);

    /***************************************************************************
      This call was added in version 1.0.1. If called with the keyword
      keyAERecorderCount ('recr'), the number of recorders that are
      currently active is returned in 'result'
      (available only in vers 1.0.1 and greater).
    **************************************************************************/
    /**
     *  AEManagerInfo()
     *

     *    \non_carbon_cfm   in InterfaceLib 7.1 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    AEManagerInfo(AEKeyword keyWord, long *result);

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

#endif /** __APPLEEVENTS__ */
