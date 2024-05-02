/**
     \file       MediaHandlers.h

    \brief   QuickTime Interfaces.

    \introduced_in  QuickTime 5.0.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1990-2001 by Apple Computer, Inc., all rights reserved

    \ingroup QuickTime

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __MEDIAHANDLERS__
#define __MEDIAHANDLERS__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __SOUND__
#include <Sound.h>
#endif

#ifndef __MOVIES__
#include <Movies.h>
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

    typedef CALLBACK_API(void, PrePrerollCompleteProcPtr)(MediaHandler mh,
                                                          OSErr err, void *refcon);
    typedef STACK_UPP_TYPE(PrePrerollCompleteProcPtr) PrePrerollCompleteUPP;
    enum
    {
        handlerHasSpatial = 1 << 0,
        handlerCanClip = 1 << 1,
        handlerCanMatte = 1 << 2,
        handlerCanTransferMode = 1 << 3,
        handlerNeedsBuffer = 1 << 4,
        handlerNoIdle = 1 << 5,
        handlerNoScheduler = 1 << 6,
        handlerWantsTime = 1 << 7,
        handlerCGrafPortOnly = 1 << 8,
        handlerCanSend = 1 << 9,
        handlerCanHandleComplexMatrix = 1 << 10,
        handlerWantsDestinationPixels = 1 << 11,
        handlerCanSendImageData = 1 << 12,
        handlerCanPicSave = 1 << 13
    };

    // media task flags
    enum
    {
        mMustDraw = 1 << 3,
        mAtEnd = 1 << 4,
        mPreflightDraw = 1 << 5,
        mSyncDrawing = 1 << 6,
        mPrecompositeOnly = 1 << 9,
        mSoundOnly = 1 << 10,
        mDoIdleActionsBeforeDraws = 1 << 11,
        mDisableIdleActions = 1 << 12
    };

    // media task result flags
    enum
    {
        mDidDraw = 1 << 0,
        mNeedsToDraw = 1 << 2,
        mDrawAgain = 1 << 3,
        mPartialDraw = 1 << 4,
        mWantIdleActions = 1 << 5
    };

    enum
    {
        forceUpdateRedraw = 1 << 0,
        forceUpdateNewBuffer = 1 << 1
    };

    // media hit test flags
    enum
    {
        mHitTestBounds =
            1L << 0, //    point must only be within targetRefCon's bounding box
        mHitTestImage =
            1L << 1,                 //  point must be within the shape of the targetRefCon's image
        mHitTestInvisible = 1L << 2, //  invisible targetRefCon's may be hit tested
        mHitTestIsClick = 1L << 3    //  for codecs that want mouse events
    };

    // media is opaque flags
    enum
    {
        mOpaque = 1L << 0,
        mInvisible = 1L << 1
    };

    // MediaSetPublicInfo/MediaGetPublicInfo selectors
    enum
    {
        kMediaQTIdleFrequencySelector = FOUR_CHAR_CODE('idfq')
    };

    struct GetMovieCompleteParams
    {
        short version;
        Movie theMovie;
        Track theTrack;
        Media theMedia;
        TimeScale movieScale;
        TimeScale mediaScale;
        TimeValue movieDuration;
        TimeValue trackDuration;
        TimeValue mediaDuration;
        Fixed effectiveRate;
        TimeBase timeBase;
        short volume;
        Fixed width;
        Fixed height;
        MatrixRecord trackMovieMatrix;
        CGrafPtr moviePort;
        GDHandle movieGD;
        PixMapHandle trackMatte;
        QTAtomContainer inputMap;
    };
    typedef struct GetMovieCompleteParams GetMovieCompleteParams;
    enum
    {
        kMediaVideoParamBrightness = 1,
        kMediaVideoParamContrast = 2,
        kMediaVideoParamHue = 3,
        kMediaVideoParamSharpness = 4,
        kMediaVideoParamSaturation = 5,
        kMediaVideoParamBlackLevel = 6,
        kMediaVideoParamWhiteLevel = 7
    };

    // These are for MediaGetInfo() and MediaSetInfo().
    enum
    {
        kMHInfoEncodedFrameRate =
            FOUR_CHAR_CODE('orat') // Parameter is a MHInfoEncodedFrameRateRecord*.
    };

    // This holds the frame rate at which the track was encoded.
    struct MHInfoEncodedFrameRateRecord
    {
        Fixed encodedFrameRate;
    };
    typedef struct MHInfoEncodedFrameRateRecord MHInfoEncodedFrameRateRecord;

    typedef Handle *dataHandlePtr;
    typedef dataHandlePtr *dataHandleHandle;

    struct QTCustomActionTargetRecord
    {
        Movie movie;
        DoMCActionUPP doMCActionCallbackProc;
        long callBackRefcon;
        Track track;
        long trackObjectRefCon;
        Track defaultTrack;
        long defaultObjectRefCon;
        long reserved1;
        long reserved2;
    };
    typedef struct QTCustomActionTargetRecord QTCustomActionTargetRecord;
    typedef QTCustomActionTargetRecord *QTCustomActionTargetPtr;
    struct MediaEQSpectrumBandsRecord
    {
        short count;
        UnsignedFixedPtr frequency; // pointer to array of frequencies
    };
    typedef struct MediaEQSpectrumBandsRecord MediaEQSpectrumBandsRecord;
    typedef MediaEQSpectrumBandsRecord *MediaEQSpectrumBandsRecordPtr;
    /**
     *  CallComponentExecuteWiredAction()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    CallComponentExecuteWiredAction(ComponentInstance ci,
                                    QTAtomContainer actionContainer,
                                    QTAtom actionAtom,
                                    QTCustomActionTargetPtr target,
                                    QTEventRecordPtr event)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0xFFF7, 0x7000, 0xA82A);

    // MediaCallRange2
    // These are unique to each type of media handler
    // They are also included in the public interfaces

    /***** These are the calls for dealing with the Generic media handler *****/
    /**
     *  MediaInitialize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaInitialize(MediaHandler mh, GetMovieCompleteParams *gmc)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0501, 0x7000, 0xA82A);

    /**
     *  MediaSetHandlerCapabilities()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetHandlerCapabilities(MediaHandler mh, long flags, long flagsMask)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0502, 0x7000, 0xA82A);

    /**
     *  MediaIdle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaIdle(MediaHandler mh, TimeValue atMediaTime, long flagsIn, long *flagsOut,
              const TimeRecord *movieTime)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x0503, 0x7000, 0xA82A);

    /**
     *  MediaGetMediaInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetMediaInfo(MediaHandler mh, Handle h)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0504, 0x7000, 0xA82A);

    /**
     *  MediaPutMediaInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaPutMediaInfo(MediaHandler mh, Handle h)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0505, 0x7000, 0xA82A);

    /**
     *  MediaSetActive()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetActive(MediaHandler mh, Boolean enableMedia)
        FIVEWORDINLINE(0x2F3C, 0x0002, 0x0506, 0x7000, 0xA82A);

    /**
     *  MediaSetRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetRate(MediaHandler mh, Fixed rate)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0507, 0x7000, 0xA82A);

    /**
     *  MediaGGetStatus()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGGetStatus(MediaHandler mh, ComponentResult *statusErr)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0508, 0x7000, 0xA82A);

    /**
     *  MediaTrackEdited()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaTrackEdited(MediaHandler mh)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x0509, 0x7000, 0xA82A);

    /**
     *  MediaSetMediaTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetMediaTimeScale(MediaHandler mh, TimeScale newTimeScale)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x050A, 0x7000, 0xA82A);

    /**
     *  MediaSetMovieTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetMovieTimeScale(MediaHandler mh, TimeScale newTimeScale)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x050B, 0x7000, 0xA82A);

    /**
     *  MediaSetGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetGWorld(MediaHandler mh, CGrafPtr aPort, GDHandle aGD)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x050C, 0x7000, 0xA82A);

    /**
     *  MediaSetDimensions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetDimensions(MediaHandler mh, Fixed width, Fixed height)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x050D, 0x7000, 0xA82A);

    /**
     *  MediaSetClip()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetClip(MediaHandler mh, RgnHandle theClip)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x050E, 0x7000, 0xA82A);

    /**
     *  MediaSetMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetMatrix(MediaHandler mh, MatrixRecord *trackMovieMatrix)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x050F, 0x7000, 0xA82A);

    /**
     *  MediaGetTrackOpaque()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetTrackOpaque(MediaHandler mh, Boolean *trackIsOpaque)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0510, 0x7000, 0xA82A);

    /**
     *  MediaSetGraphicsMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetGraphicsMode(MediaHandler mh, long mode, const RGBColor *opColor)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0511, 0x7000, 0xA82A);

    /**
     *  MediaGetGraphicsMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetGraphicsMode(MediaHandler mh, long *mode, RGBColor *opColor)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0512, 0x7000, 0xA82A);

    /**
     *  MediaGSetVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGSetVolume(MediaHandler mh, short volume)
        FIVEWORDINLINE(0x2F3C, 0x0002, 0x0513, 0x7000, 0xA82A);

    /**
     *  MediaSetSoundBalance()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetSoundBalance(MediaHandler mh, short balance)
        FIVEWORDINLINE(0x2F3C, 0x0002, 0x0514, 0x7000, 0xA82A);

    /**
     *  MediaGetSoundBalance()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetSoundBalance(MediaHandler mh, short *balance)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0515, 0x7000, 0xA82A);

    /**
     *  MediaGetNextBoundsChange()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetNextBoundsChange(MediaHandler mh, TimeValue *when)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0516, 0x7000, 0xA82A);

    /**
     *  MediaGetSrcRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetSrcRgn(MediaHandler mh, RgnHandle rgn, TimeValue atMediaTime)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0517, 0x7000, 0xA82A);

    /**
     *  MediaPreroll()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaPreroll(MediaHandler mh, TimeValue time, Fixed rate)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0518, 0x7000, 0xA82A);

    /**
     *  MediaSampleDescriptionChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSampleDescriptionChanged(MediaHandler mh, long index)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0519, 0x7000, 0xA82A);

    /**
     *  MediaHasCharacteristic()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaHasCharacteristic(MediaHandler mh, OSType characteristic, Boolean *hasIt)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x051A, 0x7000, 0xA82A);

    /**
     *  MediaGetOffscreenBufferSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetOffscreenBufferSize(MediaHandler mh, Rect *bounds, short depth,
                                CTabHandle ctab)
        FIVEWORDINLINE(0x2F3C, 0x000A, 0x051B, 0x7000, 0xA82A);

    /**
     *  MediaSetHints()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetHints(MediaHandler mh, long hints)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x051C, 0x7000, 0xA82A);

    /**
     *  MediaGetName()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetName(MediaHandler mh, Str255 name, long requestedLanguage,
                 long *actualLanguage)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x051D, 0x7000, 0xA82A);

    /**
     *  MediaForceUpdate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaForceUpdate(MediaHandler mh, long forceUpdateFlags)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x051E, 0x7000, 0xA82A);

    /**
     *  MediaGetDrawingRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetDrawingRgn(MediaHandler mh, RgnHandle *partialRgn)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x051F, 0x7000, 0xA82A);

    /**
     *  MediaGSetActiveSegment()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGSetActiveSegment(MediaHandler mh, TimeValue activeStart,
                           TimeValue activeDuration)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0520, 0x7000, 0xA82A);

    /**
     *  MediaInvalidateRegion()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaInvalidateRegion(MediaHandler mh, RgnHandle invalRgn)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0521, 0x7000, 0xA82A);

    /**
     *  MediaGetNextStepTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetNextStepTime(MediaHandler mh, short flags, TimeValue mediaTimeIn,
                         TimeValue *mediaTimeOut, Fixed rate)
        FIVEWORDINLINE(0x2F3C, 0x000E, 0x0522, 0x7000, 0xA82A);

    /**
     *  MediaSetNonPrimarySourceData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetNonPrimarySourceData(MediaHandler mh, long inputIndex,
                                 long dataDescriptionSeed, Handle dataDescription,
                                 void *data, long dataSize,
                                 ICMCompletionProcRecordPtr asyncCompletionProc,
                                 ICMConvertDataFormatUPP transferProc, void *refCon)
        FIVEWORDINLINE(0x2F3C, 0x0020, 0x0523, 0x7000, 0xA82A);

    /**
     *  MediaChangedNonPrimarySource()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaChangedNonPrimarySource(MediaHandler mh, long inputIndex)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0524, 0x7000, 0xA82A);

    /**
     *  MediaTrackReferencesChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaTrackReferencesChanged(MediaHandler mh)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x0525, 0x7000, 0xA82A);

    /**
     *  MediaGetSampleDataPointer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetSampleDataPointer(MediaHandler mh, long sampleNum, Ptr *dataPtr,
                              long *dataSize, long *sampleDescIndex)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x0526, 0x7000, 0xA82A);

    /**
     *  MediaReleaseSampleDataPointer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaReleaseSampleDataPointer(MediaHandler mh, long sampleNum)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0527, 0x7000, 0xA82A);

    /**
     *  MediaTrackPropertyAtomChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaTrackPropertyAtomChanged(MediaHandler mh)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x0528, 0x7000, 0xA82A);

    /**
     *  MediaSetTrackInputMapReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetTrackInputMapReference(MediaHandler mh, QTAtomContainer inputMap)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0529, 0x7000, 0xA82A);

    /**
     *  MediaSetVideoParam()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetVideoParam(MediaHandler mh, long whichParam, unsigned short *value)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x052B, 0x7000, 0xA82A);

    /**
     *  MediaGetVideoParam()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetVideoParam(MediaHandler mh, long whichParam, unsigned short *value)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x052C, 0x7000, 0xA82A);

    /**
     *  MediaCompare()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaCompare(MediaHandler mh, Boolean *isOK, Media srcMedia,
                 ComponentInstance srcMediaComponent)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x052D, 0x7000, 0xA82A);

    /**
     *  MediaGetClock()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetClock(MediaHandler mh, ComponentInstance *clock)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x052E, 0x7000, 0xA82A);

    /**
     *  MediaSetSoundOutputComponent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetSoundOutputComponent(MediaHandler mh, Component outputComponent)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x052F, 0x7000, 0xA82A);

    /**
     *  MediaGetSoundOutputComponent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetSoundOutputComponent(MediaHandler mh, Component *outputComponent)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0530, 0x7000, 0xA82A);

    /**
     *  MediaSetSoundLocalizationData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetSoundLocalizationData(MediaHandler mh, Handle data)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0531, 0x7000, 0xA82A);

    /**
     *  MediaGetInvalidRegion()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetInvalidRegion(MediaHandler mh, RgnHandle rgn)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x053C, 0x7000, 0xA82A);

    /**
     *  MediaSampleDescriptionB2N()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSampleDescriptionB2N(MediaHandler mh,
                              SampleDescriptionHandle sampleDescriptionH)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x053E, 0x7000, 0xA82A);

    /**
     *  MediaSampleDescriptionN2B()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSampleDescriptionN2B(MediaHandler mh,
                              SampleDescriptionHandle sampleDescriptionH)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x053F, 0x7000, 0xA82A);

    /**
     *  MediaQueueNonPrimarySourceData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaQueueNonPrimarySourceData(MediaHandler mh, long inputIndex,
                                   long dataDescriptionSeed, Handle dataDescription,
                                   void *data, long dataSize,
                                   ICMCompletionProcRecordPtr asyncCompletionProc,
                                   const ICMFrameTimeRecord *frameTime,
                                   ICMConvertDataFormatUPP transferProc,
                                   void *refCon)
        FIVEWORDINLINE(0x2F3C, 0x0024, 0x0540, 0x7000, 0xA82A);

    /**
     *  MediaFlushNonPrimarySourceData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaFlushNonPrimarySourceData(MediaHandler mh, long inputIndex)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0541, 0x7000, 0xA82A);

    /**
     *  MediaGetURLLink()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetURLLink(MediaHandler mh, Point displayWhere, Handle *urlLink)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0543, 0x7000, 0xA82A);

    /**
     *  MediaMakeMediaTimeTable()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaMakeMediaTimeTable(MediaHandler mh, long **offsets, TimeValue startTime,
                            TimeValue endTime, TimeValue timeIncrement,
                            short firstDataRefIndex, short lastDataRefIndex,
                            long *retDataRefSkew)
        FIVEWORDINLINE(0x2F3C, 0x0018, 0x0545, 0x7000, 0xA82A);

    /**
     *  MediaHitTestForTargetRefCon()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaHitTestForTargetRefCon(MediaHandler mh, long flags, Point loc,
                                long *targetRefCon)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x0546, 0x7000, 0xA82A);

    /**
     *  MediaHitTestTargetRefCon()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaHitTestTargetRefCon(MediaHandler mh, long targetRefCon, long flags,
                             Point loc, Boolean *wasHit)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x0547, 0x7000, 0xA82A);

    /**
     *  MediaGetActionsForQTEvent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaGetActionsForQTEvent(MediaHandler mh, QTEventRecordPtr event,
                              long targetRefCon, QTAtomContainer *container,
                              QTAtom *atom)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x0548, 0x7000, 0xA82A);

    /**
     *  MediaDisposeTargetRefCon()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaDisposeTargetRefCon(MediaHandler mh, long targetRefCon)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0549, 0x7000, 0xA82A);

    /**
     *  MediaTargetRefConsEqual()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaTargetRefConsEqual(MediaHandler mh, long firstRefCon, long secondRefCon,
                            Boolean *equal)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x054A, 0x7000, 0xA82A);

    /**
     *  MediaSetActionsCallback()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaSetActionsCallback(MediaHandler mh, ActionsUPP actionsCallbackProc,
                            void *refcon)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x054B, 0x7000, 0xA82A);

    /**
     *  MediaPrePrerollBegin()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaPrePrerollBegin(MediaHandler mh, TimeValue time, Fixed rate,
                         PrePrerollCompleteUPP completeProc, void *refcon)
        FIVEWORDINLINE(0x2F3C, 0x0010, 0x054C, 0x7000, 0xA82A);

    /**
     *  MediaPrePrerollCancel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaPrePrerollCancel(MediaHandler mh, void *refcon)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x054D, 0x7000, 0xA82A);

    /**
     *  MediaEnterEmptyEdit()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaEnterEmptyEdit(MediaHandler mh)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x054F, 0x7000, 0xA82A);

    /**
     *  MediaCurrentMediaQueuedData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MediaCurrentMediaQueuedData(MediaHandler mh, long *milliSecs)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0550, 0x7000, 0xA82A);

    /**
     *  MediaGetEffectiveVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetEffectiveVolume(MediaHandler mh, short *volume)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0551, 0x7000, 0xA82A);

    /**
     *  MediaResolveTargetRefCon()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaResolveTargetRefCon(MediaHandler mh, QTAtomContainer container,
                             QTAtom atom, long *targetRefCon)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x0552, 0x7000, 0xA82A);

    /**
     *  MediaGetSoundLevelMeteringEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetSoundLevelMeteringEnabled(MediaHandler mh, Boolean *enabled)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0553, 0x7000, 0xA82A);

    /**
     *  MediaSetSoundLevelMeteringEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaSetSoundLevelMeteringEnabled(MediaHandler mh, Boolean enable)
        FIVEWORDINLINE(0x2F3C, 0x0002, 0x0554, 0x7000, 0xA82A);

    /**
     *  MediaGetSoundLevelMeterInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetSoundLevelMeterInfo(MediaHandler mh, LevelMeterInfoPtr levelInfo)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0555, 0x7000, 0xA82A);

    /**
     *  MediaGetEffectiveSoundBalance()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetEffectiveSoundBalance(MediaHandler mh, short *balance)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0556, 0x7000, 0xA82A);

    /**
     *  MediaSetScreenLock()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaSetScreenLock(MediaHandler mh, Boolean lockIt)
        FIVEWORDINLINE(0x2F3C, 0x0002, 0x0557, 0x7000, 0xA82A);

    /**
     *  MediaSetDoMCActionCallback()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaSetDoMCActionCallback(MediaHandler mh,
                               DoMCActionUPP doMCActionCallbackProc, void *refcon)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0558, 0x7000, 0xA82A);

    /**
     *  MediaGetErrorString()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetErrorString(MediaHandler mh, ComponentResult theError,
                        Str255 errorString)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0559, 0x7000, 0xA82A);

    /**
     *  MediaGetSoundEqualizerBands()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetSoundEqualizerBands(MediaHandler mh,
                                MediaEQSpectrumBandsRecordPtr spectrumInfo)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x055A, 0x7000, 0xA82A);

    /**
     *  MediaSetSoundEqualizerBands()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaSetSoundEqualizerBands(MediaHandler mh,
                                MediaEQSpectrumBandsRecordPtr spectrumInfo)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x055B, 0x7000, 0xA82A);

    /**
     *  MediaGetSoundEqualizerBandLevels()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetSoundEqualizerBandLevels(MediaHandler mh, UInt8 *bandLevels)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x055C, 0x7000, 0xA82A);

    /**
     *  MediaDoIdleActions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaDoIdleActions(MediaHandler mh)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x055D, 0x7000, 0xA82A);

    /**
     *  MediaSetSoundBassAndTreble()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaSetSoundBassAndTreble(MediaHandler mh, short bass, short treble)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x055E, 0x7000, 0xA82A);

    /**
     *  MediaGetSoundBassAndTreble()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaGetSoundBassAndTreble(MediaHandler mh, short *bass, short *treble)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x055F, 0x7000, 0xA82A);

    /**
     *  MediaTimeBaseChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MediaTimeBaseChanged(MediaHandler mh)
        FIVEWORDINLINE(0x2F3C, 0x0000, 0x0560, 0x7000, 0xA82A);

    /**
     *  MediaMCIsPlayerEvent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MediaMCIsPlayerEvent(MediaHandler mh, const EventRecord *e, Boolean *handledIt)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0561, 0x7000, 0xA82A);

    /**
     *  MediaGetMediaLoadState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MediaGetMediaLoadState(MediaHandler mh, long *mediaLoadState)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0562, 0x7000, 0xA82A);

    /**
     *  MediaVideoOutputChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MediaVideoOutputChanged(MediaHandler mh, ComponentInstance vout)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0563, 0x7000, 0xA82A);

    /**
     *  MediaEmptySampleCache()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MediaEmptySampleCache(MediaHandler mh, long sampleNum, long sampleCount)
        FIVEWORDINLINE(0x2F3C, 0x0008, 0x0564, 0x7000, 0xA82A);

    /**
     *  MediaGetPublicInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MediaGetPublicInfo(MediaHandler mh, OSType infoSelector, void *infoDataPtr,
                       Size *ioDataSize)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x0565, 0x7000, 0xA82A);

    /**
     *  MediaSetPublicInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MediaSetPublicInfo(MediaHandler mh, OSType infoSelector, void *infoDataPtr,
                       Size dataSize)
        FIVEWORDINLINE(0x2F3C, 0x000C, 0x0566, 0x7000, 0xA82A);

    /**
     *  MediaGetUserPreferredCodecs()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MediaGetUserPreferredCodecs(MediaHandler mh,
                                CodecComponentHandle *userPreferredCodecs)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0567, 0x7000, 0xA82A);

    /**
     *  MediaSetUserPreferredCodecs()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MediaSetUserPreferredCodecs(MediaHandler mh,
                                CodecComponentHandle userPreferredCodecs)
        FIVEWORDINLINE(0x2F3C, 0x0004, 0x0568, 0x7000, 0xA82A);

    // selectors for component calls
    enum
    {
        kCallComponentExecuteWiredActionSelect = -9,
        kMediaInitializeSelect = 0x0501,
        kMediaSetHandlerCapabilitiesSelect = 0x0502,
        kMediaIdleSelect = 0x0503,
        kMediaGetMediaInfoSelect = 0x0504,
        kMediaPutMediaInfoSelect = 0x0505,
        kMediaSetActiveSelect = 0x0506,
        kMediaSetRateSelect = 0x0507,
        kMediaGGetStatusSelect = 0x0508,
        kMediaTrackEditedSelect = 0x0509,
        kMediaSetMediaTimeScaleSelect = 0x050A,
        kMediaSetMovieTimeScaleSelect = 0x050B,
        kMediaSetGWorldSelect = 0x050C,
        kMediaSetDimensionsSelect = 0x050D,
        kMediaSetClipSelect = 0x050E,
        kMediaSetMatrixSelect = 0x050F,
        kMediaGetTrackOpaqueSelect = 0x0510,
        kMediaSetGraphicsModeSelect = 0x0511,
        kMediaGetGraphicsModeSelect = 0x0512,
        kMediaGSetVolumeSelect = 0x0513,
        kMediaSetSoundBalanceSelect = 0x0514,
        kMediaGetSoundBalanceSelect = 0x0515,
        kMediaGetNextBoundsChangeSelect = 0x0516,
        kMediaGetSrcRgnSelect = 0x0517,
        kMediaPrerollSelect = 0x0518,
        kMediaSampleDescriptionChangedSelect = 0x0519,
        kMediaHasCharacteristicSelect = 0x051A,
        kMediaGetOffscreenBufferSizeSelect = 0x051B,
        kMediaSetHintsSelect = 0x051C,
        kMediaGetNameSelect = 0x051D,
        kMediaForceUpdateSelect = 0x051E,
        kMediaGetDrawingRgnSelect = 0x051F,
        kMediaGSetActiveSegmentSelect = 0x0520,
        kMediaInvalidateRegionSelect = 0x0521,
        kMediaGetNextStepTimeSelect = 0x0522,
        kMediaSetNonPrimarySourceDataSelect = 0x0523,
        kMediaChangedNonPrimarySourceSelect = 0x0524,
        kMediaTrackReferencesChangedSelect = 0x0525,
        kMediaGetSampleDataPointerSelect = 0x0526,
        kMediaReleaseSampleDataPointerSelect = 0x0527,
        kMediaTrackPropertyAtomChangedSelect = 0x0528,
        kMediaSetTrackInputMapReferenceSelect = 0x0529,
        kMediaSetVideoParamSelect = 0x052B,
        kMediaGetVideoParamSelect = 0x052C,
        kMediaCompareSelect = 0x052D,
        kMediaGetClockSelect = 0x052E,
        kMediaSetSoundOutputComponentSelect = 0x052F,
        kMediaGetSoundOutputComponentSelect = 0x0530,
        kMediaSetSoundLocalizationDataSelect = 0x0531,
        kMediaGetInvalidRegionSelect = 0x053C,
        kMediaSampleDescriptionB2NSelect = 0x053E,
        kMediaSampleDescriptionN2BSelect = 0x053F,
        kMediaQueueNonPrimarySourceDataSelect = 0x0540,
        kMediaFlushNonPrimarySourceDataSelect = 0x0541,
        kMediaGetURLLinkSelect = 0x0543,
        kMediaMakeMediaTimeTableSelect = 0x0545,
        kMediaHitTestForTargetRefConSelect = 0x0546,
        kMediaHitTestTargetRefConSelect = 0x0547,
        kMediaGetActionsForQTEventSelect = 0x0548,
        kMediaDisposeTargetRefConSelect = 0x0549,
        kMediaTargetRefConsEqualSelect = 0x054A,
        kMediaSetActionsCallbackSelect = 0x054B,
        kMediaPrePrerollBeginSelect = 0x054C,
        kMediaPrePrerollCancelSelect = 0x054D,
        kMediaEnterEmptyEditSelect = 0x054F,
        kMediaCurrentMediaQueuedDataSelect = 0x0550,
        kMediaGetEffectiveVolumeSelect = 0x0551,
        kMediaResolveTargetRefConSelect = 0x0552,
        kMediaGetSoundLevelMeteringEnabledSelect = 0x0553,
        kMediaSetSoundLevelMeteringEnabledSelect = 0x0554,
        kMediaGetSoundLevelMeterInfoSelect = 0x0555,
        kMediaGetEffectiveSoundBalanceSelect = 0x0556,
        kMediaSetScreenLockSelect = 0x0557,
        kMediaSetDoMCActionCallbackSelect = 0x0558,
        kMediaGetErrorStringSelect = 0x0559,
        kMediaGetSoundEqualizerBandsSelect = 0x055A,
        kMediaSetSoundEqualizerBandsSelect = 0x055B,
        kMediaGetSoundEqualizerBandLevelsSelect = 0x055C,
        kMediaDoIdleActionsSelect = 0x055D,
        kMediaSetSoundBassAndTrebleSelect = 0x055E,
        kMediaGetSoundBassAndTrebleSelect = 0x055F,
        kMediaTimeBaseChangedSelect = 0x0560,
        kMediaMCIsPlayerEventSelect = 0x0561,
        kMediaGetMediaLoadStateSelect = 0x0562,
        kMediaVideoOutputChangedSelect = 0x0563,
        kMediaEmptySampleCacheSelect = 0x0564,
        kMediaGetPublicInfoSelect = 0x0565,
        kMediaSetPublicInfoSelect = 0x0566,
        kMediaGetUserPreferredCodecsSelect = 0x0567,
        kMediaSetUserPreferredCodecsSelect = 0x0568
    };
#if CALL_NOT_IN_CARBON
    /**
     *  NewPrePrerollCompleteUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    PrePrerollCompleteUPP
    NewPrePrerollCompleteUPP(PrePrerollCompleteProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppPrePrerollCompleteProcInfo = 0x00000EC0
    }; // pascal no_return_value Func(4_bytes, 2_bytes, 4_bytes)
#ifdef __cplusplus
    inline PrePrerollCompleteUPP
    NewPrePrerollCompleteUPP(PrePrerollCompleteProcPtr userRoutine)
    {
        return (PrePrerollCompleteUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppPrePrerollCompleteProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewPrePrerollCompleteUPP(userRoutine)                                   \
    (PrePrerollCompleteUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),        \
                                                 uppPrePrerollCompleteProcInfo, \
                                                 GetCurrentArchitecture())
#endif
#endif

    /**
     *  DisposePrePrerollCompleteUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    DisposePrePrerollCompleteUPP(PrePrerollCompleteUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposePrePrerollCompleteUPP(PrePrerollCompleteUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposePrePrerollCompleteUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  InvokePrePrerollCompleteUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    InvokePrePrerollCompleteUPP(MediaHandler mh, OSErr err, void *refcon,
                                PrePrerollCompleteUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokePrePrerollCompleteUPP(MediaHandler mh, OSErr err,
                                            void *refcon,
                                            PrePrerollCompleteUPP userUPP)
    {
        CALL_THREE_PARAMETER_UPP(userUPP, uppPrePrerollCompleteProcInfo, mh, err,
                                 refcon);
    }
#else
#define InvokePrePrerollCompleteUPP(mh, err, refcon, userUPP)                \
    CALL_THREE_PARAMETER_UPP((userUPP), uppPrePrerollCompleteProcInfo, (mh), \
                             (err), (refcon))
#endif
#endif

#endif // CALL_NOT_IN_CARBON

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
// support for pre-Carbon UPP routines: New...Proc and Call...Proc
#define NewPrePrerollCompleteProc(userRoutine) \
    NewPrePrerollCompleteUPP(userRoutine)
#define CallPrePrerollCompleteProc(userRoutine, mh, err, refcon) \
    InvokePrePrerollCompleteUPP(mh, err, refcon, userRoutine)
#endif // CALL_NOT_IN_CARBON

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

#endif // __MEDIAHANDLERS__
