/**
     \file       QuickTimeComponents.h

    \brief   QuickTime Interfaces.

    \introduced_in  QuickTime 5.0.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1990-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Quicktime

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QUICKTIMECOMPONENTS__
#define __QUICKTIMECOMPONENTS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __COMPONENTS__
#include <Components.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __VIDEO__
#include <Video.h>
#endif

#ifndef __SOUND__
#include <Sound.h>
#endif

#ifndef __IMAGECOMPRESSION__
#include <ImageCompression.h>
#endif

#ifndef __MOVIES__
#include <Movies.h>
#endif

#ifndef __QUICKTIMEMUSIC__
#include <QuickTimeMusic.h>
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
        clockComponentType = FOUR_CHAR_CODE('clok'),
        systemTickClock = FOUR_CHAR_CODE('tick'),   /** subtype: 60ths since boot   */
        systemSecondClock = FOUR_CHAR_CODE('seco'), /** subtype: seconds since 1904 */
        systemMillisecondClock =
            FOUR_CHAR_CODE('mill'), /** subtype: 1000ths since boot       */
        systemMicrosecondClock =
            FOUR_CHAR_CODE('micr') /** subtype: 1000000ths since boot */
    };

    enum
    {
        kClockRateIsLinear = 1,
        kClockImplementsCallBacks = 2,
        kClockCanHandleIntermittentSound = 4 /** sound clocks only */
    };

#if OLDROUTINENAMES
#define GetClockTime(aClock, out) ClockGetTime(aClock, out)
#endif
    /*** These are Clock procedures **/
    /**
     *  ClockGetTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    ClockGetTime(ComponentInstance aClock, TimeRecord *out);

    /**
     *  ClockNewCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    QTCallBack
    ClockNewCallBack(ComponentInstance aClock, TimeBase tb, short callBackType);

    /**
     *  ClockDisposeCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    ClockDisposeCallBack(ComponentInstance aClock, QTCallBack cb);

    /**
     *  ClockCallMeWhen()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    ClockCallMeWhen(ComponentInstance aClock, QTCallBack cb, long param1,
                    long param2, long param3);

    /**
     *  ClockCancelCallBack()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    ClockCancelCallBack(ComponentInstance aClock, QTCallBack cb);

    /**
     *  ClockRateChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    ClockRateChanged(ComponentInstance aClock, QTCallBack cb);

    /**
     *  ClockTimeChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    ClockTimeChanged(ComponentInstance aClock, QTCallBack cb);

    /**
     *  ClockSetTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    ClockSetTimeBase(ComponentInstance aClock, TimeBase tb);

    /**
     *  ClockStartStopChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    ClockStartStopChanged(ComponentInstance aClock, QTCallBack cb,
                          Boolean startChanged, Boolean stopChanged);

    /**
     *  ClockGetRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    ClockGetRate(ComponentInstance aClock, Fixed *rate);

    enum
    {
        StandardCompressionType = FOUR_CHAR_CODE('scdi'),
        StandardCompressionSubType = FOUR_CHAR_CODE('imag'),
        StandardCompressionSubTypeSound = FOUR_CHAR_CODE('soun')
    };

    typedef CALLBACK_API(Boolean, SCModalFilterProcPtr)(DialogRef theDialog,
                                                        EventRecord *theEvent,
                                                        short *itemHit,
                                                        long refcon);
    typedef CALLBACK_API(short, SCModalHookProcPtr)(DialogRef theDialog,
                                                    short itemHit, void *params,
                                                    long refcon);
    typedef STACK_UPP_TYPE(SCModalFilterProcPtr) SCModalFilterUPP;
    typedef STACK_UPP_TYPE(SCModalHookProcPtr) SCModalHookUPP;
    /**  Preference flags.*/
    enum
    {
        scListEveryCodec = 1L << 1,
        scAllowZeroFrameRate = 1L << 2,
        scAllowZeroKeyFrameRate = 1L << 3,
        scShowBestDepth = 1L << 4,
        scUseMovableModal = 1L << 5,
        scDisableFrameRateItem = 1L << 6,
        scShowDataRateAsKilobits = 1L << 7
    };

    /**  Possible test flags for setting test image.*/
    enum
    {
        scPreferCropping = 1 << 0,
        scPreferScaling = 1 << 1,
        scPreferScalingAndCropping = scPreferScaling | scPreferCropping,
        scDontDetermineSettingsFromTestImage = 1 << 2
    };

    /**  Dimensions of the image preview box.*/
    enum
    {
        scTestImageWidth = 80,
        scTestImageHeight = 80
    };

    /**  Possible items returned by hookProc.*/
    enum
    {
        scOKItem = 1,
        scCancelItem = 2,
        scCustomItem = 3
    };

    /**  Result returned when user cancelled.*/
    enum
    {
        scUserCancelled = 1
    };

    /** Component selectors*/
    enum
    {
        scPositionRect = 2,
        scPositionDialog = 3,
        scSetTestImagePictHandle = 4,
        scSetTestImagePictFile = 5,
        scSetTestImagePixMap = 6,
        scGetBestDeviceRect = 7,
        scRequestImageSettings = 10,
        scCompressImage = 11,
        scCompressPicture = 12,
        scCompressPictureFile = 13,
        scRequestSequenceSettings = 14,
        scCompressSequenceBegin = 15,
        scCompressSequenceFrame = 16,
        scCompressSequenceEnd = 17,
        scDefaultPictHandleSettings = 18,
        scDefaultPictFileSettings = 19,
        scDefaultPixMapSettings = 20,
        scGetInfo = 21,
        scSetInfo = 22,
        scNewGWorld = 23
    };

    /**  Get/SetInfo structures.*/

    struct SCSpatialSettings
    {
        CodecType codecType;
        CodecComponent codec;
        short depth;
        CodecQ spatialQuality;
    };
    typedef struct SCSpatialSettings SCSpatialSettings;
    struct SCTemporalSettings
    {
        CodecQ temporalQuality;
        Fixed frameRate;
        long keyFrameRate;
    };
    typedef struct SCTemporalSettings SCTemporalSettings;
    struct SCDataRateSettings
    {
        long dataRate;
        long frameDuration;
        CodecQ minSpatialQuality;
        CodecQ minTemporalQuality;
    };
    typedef struct SCDataRateSettings SCDataRateSettings;
    struct SCExtendedProcs
    {
        SCModalFilterUPP filterProc;
        SCModalHookUPP hookProc;
        long refcon;
        Str31 customName;
    };
    typedef struct SCExtendedProcs SCExtendedProcs;
    /**  Get/SetInfo selectors*/
    enum
    {
        scSpatialSettingsType =
            FOUR_CHAR_CODE('sptl'), /** pointer to SCSpatialSettings struct*/
        scTemporalSettingsType =
            FOUR_CHAR_CODE('tprl'), /** pointer to SCTemporalSettings struct*/
        scDataRateSettingsType =
            FOUR_CHAR_CODE('drat'),                /** pointer to SCDataRateSettings struct*/
        scColorTableType = FOUR_CHAR_CODE('clut'), /** pointer to CTabHandle*/
        scProgressProcType =
            FOUR_CHAR_CODE('prog'), /** pointer to ProgressRecord struct*/
        scExtendedProcsType =
            FOUR_CHAR_CODE('xprc'),                       /** pointer to SCExtendedProcs struct*/
        scPreferenceFlagsType = FOUR_CHAR_CODE('pref'),   /** pointer to long*/
        scSettingsStateType = FOUR_CHAR_CODE('ssta'),     /** pointer to Handle*/
        scSequenceIDType = FOUR_CHAR_CODE('sequ'),        /** pointer to ImageSequence*/
        scWindowPositionType = FOUR_CHAR_CODE('wndw'),    /** pointer to Point*/
        scCodecFlagsType = FOUR_CHAR_CODE('cflg'),        /** pointer to CodecFlags*/
        scCodecSettingsType = FOUR_CHAR_CODE('cdec'),     /** pointer to Handle*/
        scForceKeyValueType = FOUR_CHAR_CODE('ksim'),     /** pointer to long*/
        scSoundSampleRateType = FOUR_CHAR_CODE('ssrt'),   /** pointer to UnsignedFixed*/
        scSoundSampleSizeType = FOUR_CHAR_CODE('ssss'),   /** pointer to short*/
        scSoundChannelCountType = FOUR_CHAR_CODE('sscc'), /** pointer to short*/
        scSoundCompressionType = FOUR_CHAR_CODE('ssct'),  /** pointer to OSType*/
        scCompressionListType = FOUR_CHAR_CODE('ctyl'),   /** pointer to OSType Handle*/
        scCodecManufacturerType = FOUR_CHAR_CODE('cmfr')  /** pointer to OSType*/
    };

    /**  scTypeNotFoundErr returned by Get/SetInfo when type cannot be found.*/

    struct SCParams
    {
        long flags;
        CodecType theCodecType;
        CodecComponent theCodec;
        CodecQ spatialQuality;
        CodecQ temporalQuality;
        short depth;
        Fixed frameRate;
        long keyFrameRate;
        long reserved1;
        long reserved2;
    };
    typedef struct SCParams SCParams;
    enum
    {
        scGetCompression = 1,
        scShowMotionSettings = 1L << 0,
        scSettingsChangedItem = -1
    };

    enum
    {
        scCompressFlagIgnoreIdenticalFrames = 1
    };

    /** QTAtomTypes for atoms found in settings atom containers*/
    enum
    {
        kQTSettingsVideo =
            FOUR_CHAR_CODE('vide'), /** Container for video/image compression related
                                       atoms (Get/SetInfo selectors)*/
        kQTSettingsSound =
            FOUR_CHAR_CODE('soun'), /** Container for sound compression related atoms
                                       (Get/SetInfo selectors)*/
        kQTSettingsComponentVersion =
            FOUR_CHAR_CODE('vers') /** . Version of component that wrote settings
                                      (QTSettingsVersionAtomRecord)*/
    };

    /** Format of 'vers' atom found in settings atom containers*/
    struct QTSettingsVersionAtomRecord
    {
        long componentVersion; /** standard compression component version*/
        short flags;           /** low bit is 1 if little endian platform, 0 if big endian
                                  platform*/
        short reserved;        /** should be 0*/
    };
    typedef struct QTSettingsVersionAtomRecord QTSettingsVersionAtomRecord;
#define SCGetCompression(ci, params, where) \
    SCGetCompressionExtended(ci, params, where, 0, 0, 0, 0)
    /*** These are Progress procedures **/
    /**
     *  SCGetCompressionExtended()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCGetCompressionExtended(ComponentInstance ci, SCParams *params, Point where,
                             SCModalFilterUPP filterProc, SCModalHookUPP hookProc,
                             long refcon, StringPtr customName);

    /**
     *  SCPositionRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCPositionRect(ComponentInstance ci, Rect *rp, Point *where);

    /**
     *  SCPositionDialog()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCPositionDialog(ComponentInstance ci, short id, Point *where);

    /**
     *  SCSetTestImagePictHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCSetTestImagePictHandle(ComponentInstance ci, PicHandle testPict,
                             Rect *testRect, short testFlags);

    /**
     *  SCSetTestImagePictFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCSetTestImagePictFile(ComponentInstance ci, short testFileRef, Rect *testRect,
                           short testFlags);

    /**
     *  SCSetTestImagePixMap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCSetTestImagePixMap(ComponentInstance ci, PixMapHandle testPixMap,
                         Rect *testRect, short testFlags);

    /**
     *  SCGetBestDeviceRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCGetBestDeviceRect(ComponentInstance ci, Rect *r);

    /**
     *  SCRequestImageSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCRequestImageSettings(ComponentInstance ci);

    /**
     *  SCCompressImage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCCompressImage(ComponentInstance ci, PixMapHandle src, const Rect *srcRect,
                    ImageDescriptionHandle *desc, Handle *data);

    /**
     *  SCCompressPicture()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCCompressPicture(ComponentInstance ci, PicHandle srcPicture,
                      PicHandle dstPicture);

    /**
     *  SCCompressPictureFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCCompressPictureFile(ComponentInstance ci, short srcRefNum, short dstRefNum);

    /**
     *  SCRequestSequenceSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCRequestSequenceSettings(ComponentInstance ci);

    /**
     *  SCCompressSequenceBegin()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCCompressSequenceBegin(ComponentInstance ci, PixMapHandle src,
                            const Rect *srcRect, ImageDescriptionHandle *desc);

    /**
     *  SCCompressSequenceFrame()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCCompressSequenceFrame(ComponentInstance ci, PixMapHandle src,
                            const Rect *srcRect, Handle *data, long *dataSize,
                            short *notSyncFlag);

    /**
     *  SCCompressSequenceEnd()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCCompressSequenceEnd(ComponentInstance ci);

    /**
     *  SCDefaultPictHandleSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCDefaultPictHandleSettings(ComponentInstance ci, PicHandle srcPicture,
                                short motion);

    /**
     *  SCDefaultPictFileSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCDefaultPictFileSettings(ComponentInstance ci, short srcRef, short motion);

    /**
     *  SCDefaultPixMapSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCDefaultPixMapSettings(ComponentInstance ci, PixMapHandle src, short motion);

    /**
     *  SCGetInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCGetInfo(ComponentInstance ci, OSType infoType, void *info);

    /**
     *  SCSetInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCSetInfo(ComponentInstance ci, OSType infoType, void *info);

    /**
     *  SCNewGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCNewGWorld(ComponentInstance ci, GWorldPtr *gwp, Rect *rp, GWorldFlags flags);

    /**
     *  SCSetCompressFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCSetCompressFlags(ComponentInstance ci, long flags);

    /**
     *  SCGetCompressFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCGetCompressFlags(ComponentInstance ci, long *flags);

    /**
     *  SCGetSettingsAsText()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCGetSettingsAsText(ComponentInstance ci, Handle *text);

    /**
     *  SCGetSettingsAsAtomContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCGetSettingsAsAtomContainer(ComponentInstance ci, QTAtomContainer *settings);

    /**
     *  SCSetSettingsFromAtomContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SCSetSettingsFromAtomContainer(ComponentInstance ci, QTAtomContainer settings);

    /** Note: if you're using SCCompressSequenceFrameAsync with a scForceKeyValue
     * setting, you must call SCAsyncIdle occasionally at main task time. */
    /**
     *  SCCompressSequenceFrameAsync()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    SCCompressSequenceFrameAsync(ComponentInstance ci, PixMapHandle src,
                                 const Rect *srcRect, Handle *data, long *dataSize,
                                 short *notSyncFlag,
                                 ICMCompletionProcRecordPtr asyncCompletionProc);

    /**
     *  SCAsyncIdle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    SCAsyncIdle(ComponentInstance ci);

    enum
    {
        TweenComponentType = FOUR_CHAR_CODE('twen')
    };

    typedef ComponentInstance TweenerComponent;
    /**
     *  TweenerInitialize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TweenerInitialize(TweenerComponent tc, QTAtomContainer container,
                      QTAtom tweenAtom, QTAtom dataAtom);

    /**
     *  TweenerDoTween()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TweenerDoTween(TweenerComponent tc, TweenRecord *tr);

    /**
     *  TweenerReset()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TweenerReset(TweenerComponent tc);

    enum
    {
        TCSourceRefNameType = FOUR_CHAR_CODE('name')
    };

    enum
    {
        tcDropFrame = 1 << 0,
        tc24HourMax = 1 << 1,
        tcNegTimesOK = 1 << 2,
        tcCounter = 1 << 3
    };

    struct TimeCodeDef
    {
        long flags;              /** drop-frame, etc.*/
        TimeScale fTimeScale;    /** time scale of frameDuration (eg. 2997)*/
        TimeValue frameDuration; /** duration of each frame (eg. 100)*/
        UInt8 numFrames;         /** frames/sec for timecode (eg. 30) OR frames/tick for
                                    counter mode*/
        UInt8 padding;           /** unused padding byte*/
    };
    typedef struct TimeCodeDef TimeCodeDef;
    enum
    {
        tctNegFlag = 0x80 /** negative bit is in minutes*/
    };

    struct TimeCodeTime
    {
        UInt8 hours;
        UInt8 minutes;
        UInt8 seconds;
        UInt8 frames;
    };
    typedef struct TimeCodeTime TimeCodeTime;
    struct TimeCodeCounter
    {
        long counter;
    };
    typedef struct TimeCodeCounter TimeCodeCounter;
    union TimeCodeRecord
    {
        TimeCodeTime t;
        TimeCodeCounter c;
    };
    typedef union TimeCodeRecord TimeCodeRecord;
    struct TimeCodeDescription
    {
        long descSize; /** standard sample description header*/
        long dataFormat;
        long resvd1;
        short resvd2;
        short dataRefIndex;
        long flags; /** timecode specific stuff*/
        TimeCodeDef timeCodeDef;
        long srcRef[1];
    };
    typedef struct TimeCodeDescription TimeCodeDescription;
    typedef TimeCodeDescription *TimeCodeDescriptionPtr;
    typedef TimeCodeDescriptionPtr *TimeCodeDescriptionHandle;
    enum
    {
        tcdfShowTimeCode = 1 << 0
    };

    struct TCTextOptions
    {
        short txFont;
        short txFace;
        short txSize;
        short pad; /** let's make it longword aligned - thanks.. */
        RGBColor foreColor;
        RGBColor backColor;
    };
    typedef struct TCTextOptions TCTextOptions;
    typedef TCTextOptions *TCTextOptionsPtr;
    /**
     *  TCGetCurrentTimeCode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    HandlerError
    TCGetCurrentTimeCode(MediaHandler mh, long *frameNum, TimeCodeDef *tcdef,
                         TimeCodeRecord *tcrec, UserData *srcRefH);

    /**
     *  TCGetTimeCodeAtTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    HandlerError
    TCGetTimeCodeAtTime(MediaHandler mh, TimeValue mediaTime, long *frameNum,
                        TimeCodeDef *tcdef, TimeCodeRecord *tcdata,
                        UserData *srcRefH);

    /**
     *  TCTimeCodeToString()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    HandlerError
    TCTimeCodeToString(MediaHandler mh, TimeCodeDef *tcdef, TimeCodeRecord *tcrec,
                       StringPtr tcStr);

    /**
     *  TCTimeCodeToFrameNumber()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    HandlerError
    TCTimeCodeToFrameNumber(MediaHandler mh, TimeCodeDef *tcdef,
                            TimeCodeRecord *tcrec, long *frameNumber);

    /**
     *  TCFrameNumberToTimeCode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    HandlerError
    TCFrameNumberToTimeCode(MediaHandler mh, long frameNumber, TimeCodeDef *tcdef,
                            TimeCodeRecord *tcrec);

    /**
     *  TCGetSourceRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    HandlerError
    TCGetSourceRef(MediaHandler mh, TimeCodeDescriptionHandle tcdH, UserData *srefH);

    /**
     *  TCSetSourceRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    HandlerError
    TCSetSourceRef(MediaHandler mh, TimeCodeDescriptionHandle tcdH, UserData srefH);

    /**
     *  TCSetTimeCodeFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    HandlerError
    TCSetTimeCodeFlags(MediaHandler mh, long flags, long flagsMask);

    /**
     *  TCGetTimeCodeFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    HandlerError
    TCGetTimeCodeFlags(MediaHandler mh, long *flags);

    /**
     *  TCSetDisplayOptions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    HandlerError
    TCSetDisplayOptions(MediaHandler mh, TCTextOptionsPtr textOptions);

    /**
     *  TCGetDisplayOptions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    HandlerError
    TCGetDisplayOptions(MediaHandler mh, TCTextOptionsPtr textOptions);

    typedef ComponentInstance MovieImportComponent;
    typedef ComponentInstance MovieExportComponent;
    enum
    {
        MovieImportType = FOUR_CHAR_CODE('eat '),
        MovieExportType = FOUR_CHAR_CODE('spit')
    };

    enum
    {
        canMovieImportHandles = 1 << 0,
        canMovieImportFiles = 1 << 1,
        hasMovieImportUserInterface = 1 << 2,
        canMovieExportHandles = 1 << 3,
        canMovieExportFiles = 1 << 4,
        hasMovieExportUserInterface = 1 << 5,
        movieImporterIsXMLBased = 1 << 5,
        dontAutoFileMovieImport = 1 << 6,
        canMovieExportAuxDataHandle = 1 << 7,
        canMovieImportValidateHandles = 1 << 8,
        canMovieImportValidateFile = 1 << 9,
        dontRegisterWithEasyOpen = 1 << 10,
        canMovieImportInPlace = 1 << 11,
        movieImportSubTypeIsFileExtension = 1 << 12,
        canMovieImportPartial = 1 << 13,
        hasMovieImportMIMEList = 1 << 14,
        canMovieImportAvoidBlocking = 1 << 15,
        canMovieExportFromProcedures = 1 << 15,
        canMovieExportValidateMovie = 1L << 16,
        movieExportNeedsResourceFork = 1L << 17,
        canMovieImportDataReferences = 1L << 18,
        movieExportMustGetSourceMediaType = 1L << 19,
        canMovieImportWithIdle = 1L << 20,
        canMovieImportValidateDataReferences = 1L << 21,
        reservedForUseByGraphicsImporters = 1L << 23
    };

    enum
    {
        movieImportCreateTrack = 1,
        movieImportInParallel = 2,
        movieImportMustUseTrack = 4,
        movieImportWithIdle = 16
    };

    enum
    {
        movieImportResultUsedMultipleTracks = 8,
        movieImportResultNeedIdles = 32,
        movieImportResultComplete = 64
    };

    enum
    {
        kMovieExportTextOnly = 0,
        kMovieExportAbsoluteTime = 1,
        kMovieExportRelativeTime = 2
    };

    enum
    {
        kMIDIImportSilenceBefore = 1 << 0,
        kMIDIImportSilenceAfter = 1 << 1,
        kMIDIImport20Playable = 1 << 2,
        kMIDIImportWantLyrics = 1 << 3
    };

    enum
    {
        kQTMediaConfigResourceType = FOUR_CHAR_CODE('mcfg'),
        kQTMediaConfigResourceVersion = 2,
        kQTMediaGroupResourceType = FOUR_CHAR_CODE('mgrp'),
        kQTMediaGroupResourceVersion = 1
    };

    enum
    {
        kQTMediaMIMEInfoHasChanged = (1L << 1), /** the MIME type(s) is(are) new or
                                                   has changed since the last time*/
                                                /**  someone asked about it*/
        kQTMediaFileInfoHasChanged =
            (1L << 2), /** the file extension(s) is(are) new or has changed since the
                          last time*/
                       /**  anyone asked about it*/
        kQTMediaConfigCanUseApp =
            (1L << 18), /** this MIME type can be configured to use app*/
        kQTMediaConfigCanUsePlugin =
            (1L << 19),                    /** this MIME type can be configured to use plug-in*/
        kQTMediaConfigUNUSED = (1L << 20), /** currently unused*/
        kQTMediaConfigBinaryFile =
            (1L << 23),             /** file should be transfered in binary mode*/
        kQTMediaConfigTextFile = 0, /** not a bit, defined for clarity*/
        kQTMediaConfigMacintoshFile =
            (1L << 24), /** file's resource fork is significant*/
        kQTMediaConfigAssociateByDefault =
            (1L << 27), /** take this file association by default*/
        kQTMediaConfigUseAppByDefault =
            (1L << 28), /** use the app by default for this MIME type*/
        kQTMediaConfigUsePluginByDefault =
            (1L << 29), /** use the plug-in by default for this MIME type*/
        kQTMediaConfigDefaultsMask =
            (kQTMediaConfigUseAppByDefault | kQTMediaConfigUsePluginByDefault),
        kQTMediaConfigDefaultsShift =
            12 /** ((flags & kQTMediaConfigDefaultsMask) >>
                  kQTMediaConfigDefaultsShift) to get default setting*/
    };

    /** mime type group constants for groupID field of 'mcfg' resource*/
    enum
    {
        kQTMediaConfigStreamGroupID = FOUR_CHAR_CODE('strm'),
        kQTMediaConfigInteractiveGroupID = FOUR_CHAR_CODE('intr'),
        kQTMediaConfigVideoGroupID = FOUR_CHAR_CODE('eyes'),
        kQTMediaConfigAudioGroupID = FOUR_CHAR_CODE('ears'),
        kQTMediaConfigMPEGGroupID = FOUR_CHAR_CODE('mpeg'),
        kQTMediaConfigMP3GroupID = FOUR_CHAR_CODE('mp3 '),
        kQTMediaConfigImageGroupID = FOUR_CHAR_CODE('ogle'),
        kQTMediaConfigMiscGroupID = FOUR_CHAR_CODE('misc')
    };

    /** file type group constants for groupID field of 'mcfg' resource*/
    enum
    {
        kQTMediaInfoNetGroup = FOUR_CHAR_CODE('net '),
        kQTMediaInfoWinGroup = FOUR_CHAR_CODE('win '),
        kQTMediaInfoMacGroup = FOUR_CHAR_CODE('mac '),
        kQTMediaInfoMiscGroup = 0x3F3F3F3F /** '????'*/
    };

    enum
    {
        kMimeInfoMimeTypeTag = FOUR_CHAR_CODE('mime'),
        kMimeInfoFileExtensionTag = FOUR_CHAR_CODE('ext '),
        kMimeInfoDescriptionTag = FOUR_CHAR_CODE('desc'),
        kMimeInfoGroupTag = FOUR_CHAR_CODE('grop'),
        kMimeInfoDoNotOverrideExistingFileTypeAssociation = FOUR_CHAR_CODE('nofa')
    };

    enum
    {
        kQTFileTypeAIFF = FOUR_CHAR_CODE('AIFF'),
        kQTFileTypeAIFC = FOUR_CHAR_CODE('AIFC'),
        kQTFileTypeDVC = FOUR_CHAR_CODE('dvc!'),
        kQTFileTypeMIDI = FOUR_CHAR_CODE('Midi'),
        kQTFileTypePicture = FOUR_CHAR_CODE('PICT'),
        kQTFileTypeMovie = FOUR_CHAR_CODE('MooV'),
        kQTFileTypeText = FOUR_CHAR_CODE('TEXT'),
        kQTFileTypeWave = FOUR_CHAR_CODE('WAVE'),
        kQTFileTypeSystemSevenSound = FOUR_CHAR_CODE('sfil'),
        kQTFileTypeMuLaw = FOUR_CHAR_CODE('ULAW'),
        kQTFileTypeAVI = FOUR_CHAR_CODE('VfW '),
        kQTFileTypeSoundDesignerII = FOUR_CHAR_CODE('Sd2f'),
        kQTFileTypeAudioCDTrack = FOUR_CHAR_CODE('trak'),
        kQTFileTypePICS = FOUR_CHAR_CODE('PICS'),
        kQTFileTypeGIF = FOUR_CHAR_CODE('GIFf'),
        kQTFileTypePNG = FOUR_CHAR_CODE('PNGf'),
        kQTFileTypeTIFF = FOUR_CHAR_CODE('TIFF'),
        kQTFileTypePhotoShop = FOUR_CHAR_CODE('8BPS'),
        kQTFileTypeSGIImage = FOUR_CHAR_CODE('.SGI'),
        kQTFileTypeBMP = FOUR_CHAR_CODE('BMPf'),
        kQTFileTypeJPEG = FOUR_CHAR_CODE('JPEG'),
        kQTFileTypeJFIF = FOUR_CHAR_CODE('JPEG'),
        kQTFileTypeMacPaint = FOUR_CHAR_CODE('PNTG'),
        kQTFileTypeTargaImage = FOUR_CHAR_CODE('TPIC'),
        kQTFileTypeQuickDrawGXPicture = FOUR_CHAR_CODE('qdgx'),
        kQTFileTypeQuickTimeImage = FOUR_CHAR_CODE('qtif'),
        kQTFileType3DMF = FOUR_CHAR_CODE('3DMF'),
        kQTFileTypeFLC = FOUR_CHAR_CODE('FLC '),
        kQTFileTypeFlash = FOUR_CHAR_CODE('SWFL'),
        kQTFileTypeFlashPix = FOUR_CHAR_CODE('FPix')
    };

    /** QTAtomTypes for atoms in import/export settings containers*/
    enum
    {
        kQTSettingsDVExportNTSC = FOUR_CHAR_CODE(
            'dvcv'), /** True is export as NTSC, false is export as PAL. (Boolean)*/
        kQTSettingsDVExportLockedAudio =
            FOUR_CHAR_CODE('lock'), /** True if audio locked to video. (Boolean)*/
        kQTSettingsEffect =
            FOUR_CHAR_CODE('effe'), /** Parent atom whose contents are atoms of an
                                       effects description*/
        kQTSettingsGraphicsFileImportSequence = FOUR_CHAR_CODE(
            'sequ'), /** Parent atom of graphic file movie import component*/
        kQTSettingsGraphicsFileImportSequenceEnabled = FOUR_CHAR_CODE(
            'enab'), /** . If true, import numbered image sequence (Boolean)*/
        kQTSettingsMovieExportEnableVideo =
            FOUR_CHAR_CODE('envi'), /** Enable exporting of video track (Boolean)*/
        kQTSettingsMovieExportEnableSound =
            FOUR_CHAR_CODE('enso'), /** Enable exporting of sound track (Boolean)*/
        kQTSettingsMovieExportSaveOptions =
            FOUR_CHAR_CODE('save'), /** Parent atom of save options*/
        kQTSettingsMovieExportSaveForInternet =
            FOUR_CHAR_CODE('fast'), /** . Save for Internet*/
        kQTSettingsMovieExportSaveCompressedMovie =
            FOUR_CHAR_CODE('cmpm'),               /** . Save compressed movie resource*/
        kQTSettingsMIDI = FOUR_CHAR_CODE('MIDI'), /** MIDI import related container*/
        kQTSettingsMIDISettingFlags =
            FOUR_CHAR_CODE('sttg'),               /** . MIDI import settings (UInt32)*/
        kQTSettingsText = FOUR_CHAR_CODE('text'), /** Text related container*/
        kQTSettingsTextDescription = FOUR_CHAR_CODE(
            'desc'), /** . Text import settings (TextDescription record)*/
        kQTSettingsTextSize = FOUR_CHAR_CODE(
            'size'), /** . Width/height to create during import (FixedPoint)*/
        kQTSettingsTextSettingFlags =
            FOUR_CHAR_CODE('sttg'), /** . Text export settings (UInt32)*/
        kQTSettingsTextTimeFraction =
            FOUR_CHAR_CODE('timf'),               /** . Movie time fraction for export (UInt32)*/
        kQTSettingsTime = FOUR_CHAR_CODE('time'), /** Time related container*/
        kQTSettingsTimeDuration =
            FOUR_CHAR_CODE('dura'), /** . Time related container*/
        kQTSettingsAudioCDTrack =
            FOUR_CHAR_CODE('trak'), /** Audio CD track related container*/
        kQTSettingsAudioCDTrackRateShift =
            FOUR_CHAR_CODE('rshf') /** . Rate shift to be performed (SInt16)*/
    };

    struct MovieExportGetDataParams
    {
        long recordSize;

        long trackID;

        TimeScale sourceTimeScale;
        TimeValue requestedTime;
        TimeValue actualTime;

        Ptr dataPtr;
        long dataSize;

        SampleDescriptionHandle desc;
        OSType descType;
        long descSeed;

        long requestedSampleCount;
        long actualSampleCount;
        TimeValue durationPerSample;
        long sampleFlags;
    };
    typedef struct MovieExportGetDataParams MovieExportGetDataParams;
    typedef CALLBACK_API(OSErr, MovieExportGetDataProcPtr)(
        void *refCon, MovieExportGetDataParams *params);
    typedef CALLBACK_API(OSErr, MovieExportGetPropertyProcPtr)(void *refcon,
                                                               long trackID,
                                                               OSType propertyType,
                                                               void *propertyValue);
    enum
    {
        kQTPresetsListResourceType = FOUR_CHAR_CODE('stg#'),
        kQTPresetsPlatformListResourceType = FOUR_CHAR_CODE('stgp')
    };

    enum
    {
        kQTPresetInfoIsDivider = 1
    };

    struct QTPresetInfo
    {
        OSType presetKey;            /** unique key for this preset in presetsArray */
        UInt32 presetFlags;          /** flags about this preset */
        OSType settingsResourceType; /** resource type of settings resource */
        SInt16 settingsResourceID;   /** resource id of settings resource */
        SInt16 padding1;
        SInt16 nameStringListID; /** name string list resource id */
        SInt16 nameStringIndex;  /** name string index */
        SInt16 infoStringListID; /** info string list resource id */
        SInt16 infoStringIndex;  /** info string index */
    };
    typedef struct QTPresetInfo QTPresetInfo;
    struct QTPresetListRecord
    {
        UInt32 flags; /** flags for whole list */
        UInt32 count; /** number of elements in presetsArray */
        UInt32 reserved;
        QTPresetInfo presetsArray[1]; /** info about each preset */
    };
    typedef struct QTPresetListRecord QTPresetListRecord;
    enum
    {
        kQTMovieExportSourceInfoResourceType = FOUR_CHAR_CODE('src#'),
        kQTMovieExportSourceInfoIsMediaType = 1L << 0,
        kQTMovieExportSourceInfoIsMediaCharacteristic = 1L << 1,
        kQTMovieExportSourceInfoIsSourceType = 1L << 2
    };

    struct QTMovieExportSourceInfo
    {
        OSType mediaType; /** Media type of source */
        UInt16 minCount;  /** min number of sources of this kind required, zero if none
                             required */
        UInt16 maxCount;  /** max number of sources of this kind allowed, -1 if
                             unlimited allowed */
        long flags;       /** reserved for flags */
    };
    typedef struct QTMovieExportSourceInfo QTMovieExportSourceInfo;
    struct QTMovieExportSourceRecord
    {
        long count;
        long reserved;
        QTMovieExportSourceInfo sourceArray[1];
    };
    typedef struct QTMovieExportSourceRecord QTMovieExportSourceRecord;
    typedef STACK_UPP_TYPE(MovieExportGetDataProcPtr) MovieExportGetDataUPP;
    typedef STACK_UPP_TYPE(MovieExportGetPropertyProcPtr) MovieExportGetPropertyUPP;
    /**
     *  NewSCModalFilterUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SCModalFilterUPP
    NewSCModalFilterUPP(SCModalFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppSCModalFilterProcInfo = 0x00003FD0
    }; /** pascal 1_byte Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline SCModalFilterUPP NewSCModalFilterUPP(SCModalFilterProcPtr userRoutine)
    {
        return (SCModalFilterUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                      uppSCModalFilterProcInfo,
                                                      GetCurrentArchitecture());
    }
#else
#define NewSCModalFilterUPP(userRoutine)                                       \
    (SCModalFilterUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppSCModalFilterProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSCModalHookUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SCModalHookUPP
    NewSCModalHookUPP(SCModalHookProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppSCModalHookProcInfo = 0x00003EE0
    }; /** pascal 2_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline SCModalHookUPP NewSCModalHookUPP(SCModalHookProcPtr userRoutine)
    {
        return (SCModalHookUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppSCModalHookProcInfo, GetCurrentArchitecture());
    }
#else
#define NewSCModalHookUPP(userRoutine)                                       \
    (SCModalHookUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppSCModalHookProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewMovieExportGetDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    MovieExportGetDataUPP
    NewMovieExportGetDataUPP(MovieExportGetDataProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppMovieExportGetDataProcInfo = 0x000003E0
    }; /** pascal 2_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline MovieExportGetDataUPP
    NewMovieExportGetDataUPP(MovieExportGetDataProcPtr userRoutine)
    {
        return (MovieExportGetDataUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppMovieExportGetDataProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewMovieExportGetDataUPP(userRoutine)                                   \
    (MovieExportGetDataUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),        \
                                                 uppMovieExportGetDataProcInfo, \
                                                 GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewMovieExportGetPropertyUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    MovieExportGetPropertyUPP
    NewMovieExportGetPropertyUPP(MovieExportGetPropertyProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppMovieExportGetPropertyProcInfo = 0x00003FE0
    }; /** pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline MovieExportGetPropertyUPP
    NewMovieExportGetPropertyUPP(MovieExportGetPropertyProcPtr userRoutine)
    {
        return (MovieExportGetPropertyUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppMovieExportGetPropertyProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewMovieExportGetPropertyUPP(userRoutine)                  \
    (MovieExportGetPropertyUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppMovieExportGetPropertyProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  DisposeSCModalFilterUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSCModalFilterUPP(SCModalFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSCModalFilterUPP(SCModalFilterUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSCModalFilterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSCModalHookUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSCModalHookUPP(SCModalHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSCModalHookUPP(SCModalHookUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSCModalHookUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeMovieExportGetDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeMovieExportGetDataUPP(MovieExportGetDataUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeMovieExportGetDataUPP(MovieExportGetDataUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeMovieExportGetDataUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeMovieExportGetPropertyUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeMovieExportGetPropertyUPP(MovieExportGetPropertyUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void
    DisposeMovieExportGetPropertyUPP(MovieExportGetPropertyUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeMovieExportGetPropertyUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  InvokeSCModalFilterUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    Boolean
    InvokeSCModalFilterUPP(DialogRef theDialog, EventRecord *theEvent,
                           short *itemHit, long refcon, SCModalFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline Boolean InvokeSCModalFilterUPP(DialogRef theDialog,
                                          EventRecord *theEvent, short *itemHit,
                                          long refcon, SCModalFilterUPP userUPP)
    {
        return (Boolean)CALL_FOUR_PARAMETER_UPP(userUPP, uppSCModalFilterProcInfo,
                                                theDialog, theEvent, itemHit, refcon);
    }
#else
#define InvokeSCModalFilterUPP(theDialog, theEvent, itemHit, refcon, userUPP) \
    (Boolean)                                                                 \
        CALL_FOUR_PARAMETER_UPP((userUPP), uppSCModalFilterProcInfo,          \
                                (theDialog), (theEvent), (itemHit), (refcon))
#endif
#endif

    /**
     *  InvokeSCModalHookUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    short
    InvokeSCModalHookUPP(DialogRef theDialog, short itemHit, void *params,
                         long refcon, SCModalHookUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline short InvokeSCModalHookUPP(DialogRef theDialog, short itemHit,
                                      void *params, long refcon,
                                      SCModalHookUPP userUPP)
    {
        return (short)CALL_FOUR_PARAMETER_UPP(userUPP, uppSCModalHookProcInfo,
                                              theDialog, itemHit, params, refcon);
    }
#else
#define InvokeSCModalHookUPP(theDialog, itemHit, params, refcon, userUPP) \
    (short)CALL_FOUR_PARAMETER_UPP((userUPP), uppSCModalHookProcInfo,     \
                                   (theDialog), (itemHit), (params), (refcon))
#endif
#endif

    /**
     *  InvokeMovieExportGetDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeMovieExportGetDataUPP(void *refCon, MovieExportGetDataParams *params,
                                MovieExportGetDataUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeMovieExportGetDataUPP(void *refCon,
                                             MovieExportGetDataParams *params,
                                             MovieExportGetDataUPP userUPP)
    {
        return (OSErr)CALL_TWO_PARAMETER_UPP(userUPP, uppMovieExportGetDataProcInfo,
                                             refCon, params);
    }
#else
#define InvokeMovieExportGetDataUPP(refCon, params, userUPP)                 \
    (OSErr) CALL_TWO_PARAMETER_UPP((userUPP), uppMovieExportGetDataProcInfo, \
                                   (refCon), (params))
#endif
#endif

    /**
     *  InvokeMovieExportGetPropertyUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeMovieExportGetPropertyUPP(void *refcon, long trackID, OSType propertyType,
                                    void *propertyValue,
                                    MovieExportGetPropertyUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr
    InvokeMovieExportGetPropertyUPP(void *refcon, long trackID, OSType propertyType,
                                    void *propertyValue,
                                    MovieExportGetPropertyUPP userUPP)
    {
        return (OSErr)CALL_FOUR_PARAMETER_UPP(
            userUPP, uppMovieExportGetPropertyProcInfo, refcon, trackID, propertyType,
            propertyValue);
    }
#else
#define InvokeMovieExportGetPropertyUPP(refcon, trackID, propertyType,           \
                                        propertyValue, userUPP)                  \
    (OSErr) CALL_FOUR_PARAMETER_UPP((userUPP),                                   \
                                    uppMovieExportGetPropertyProcInfo, (refcon), \
                                    (trackID), (propertyType), (propertyValue))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewSCModalFilterProc(userRoutine) NewSCModalFilterUPP(userRoutine)
#define NewSCModalHookProc(userRoutine) NewSCModalHookUPP(userRoutine)
#define NewMovieExportGetDataProc(userRoutine) \
    NewMovieExportGetDataUPP(userRoutine)
#define NewMovieExportGetPropertyProc(userRoutine) \
    NewMovieExportGetPropertyUPP(userRoutine)
#define CallSCModalFilterProc(userRoutine, theDialog, theEvent, itemHit, \
                              refcon)                                    \
    InvokeSCModalFilterUPP(theDialog, theEvent, itemHit, refcon, userRoutine)
#define CallSCModalHookProc(userRoutine, theDialog, itemHit, params, refcon) \
    InvokeSCModalHookUPP(theDialog, itemHit, params, refcon, userRoutine)
#define CallMovieExportGetDataProc(userRoutine, refCon, params) \
    InvokeMovieExportGetDataUPP(refCon, params, userRoutine)
#define CallMovieExportGetPropertyProc(userRoutine, refcon, trackID, \
                                       propertyType, propertyValue)  \
    InvokeMovieExportGetPropertyUPP(refcon, trackID, propertyType,   \
                                    propertyValue, userRoutine)
#endif /** CALL_NOT_IN_CARBON */

    /**
     *  MovieImportHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportHandle(MovieImportComponent ci, Handle dataH, Movie theMovie,
                      Track targetTrack, Track *usedTrack, TimeValue atTime,
                      TimeValue *addedDuration, long inFlags, long *outFlags);

    /**
     *  MovieImportFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportFile(MovieImportComponent ci, const FSSpec *theFile, Movie theMovie,
                    Track targetTrack, Track *usedTrack, TimeValue atTime,
                    TimeValue *addedDuration, long inFlags, long *outFlags);

    /**
     *  MovieImportSetSampleDuration()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportSetSampleDuration(MovieImportComponent ci, TimeValue duration,
                                 TimeScale scale);

    /**
     *  MovieImportSetSampleDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportSetSampleDescription(MovieImportComponent ci,
                                    SampleDescriptionHandle desc, OSType mediaType);

    /**
     *  MovieImportSetMediaFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportSetMediaFile(MovieImportComponent ci, AliasHandle alias);

    /**
     *  MovieImportSetDimensions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportSetDimensions(MovieImportComponent ci, Fixed width, Fixed height);

    /**
     *  MovieImportSetChunkSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportSetChunkSize(MovieImportComponent ci, long chunkSize);

    /**
     *  MovieImportSetProgressProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportSetProgressProc(MovieImportComponent ci, MovieProgressUPP proc,
                               long refcon);

    /**
     *  MovieImportSetAuxiliaryData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportSetAuxiliaryData(MovieImportComponent ci, Handle data,
                                OSType handleType);

    /**
     *  MovieImportSetFromScrap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportSetFromScrap(MovieImportComponent ci, Boolean fromScrap);

    /**
     *  MovieImportDoUserDialog()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportDoUserDialog(MovieImportComponent ci, const FSSpec *theFile,
                            Handle theData, Boolean *canceled);

    /**
     *  MovieImportSetDuration()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportSetDuration(MovieImportComponent ci, TimeValue duration);

    /**
     *  MovieImportGetAuxiliaryDataType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportGetAuxiliaryDataType(MovieImportComponent ci, OSType *auxType);

    /**
     *  MovieImportValidate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportValidate(MovieImportComponent ci, const FSSpec *theFile,
                        Handle theData, Boolean *valid);

    /**
     *  MovieImportGetFileType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportGetFileType(MovieImportComponent ci, OSType *fileType);

    /**
     *  MovieImportDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportDataRef(MovieImportComponent ci, Handle dataRef, OSType dataRefType,
                       Movie theMovie, Track targetTrack, Track *usedTrack,
                       TimeValue atTime, TimeValue *addedDuration, long inFlags,
                       long *outFlags);

    /**
     *  MovieImportGetSampleDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportGetSampleDescription(MovieImportComponent ci,
                                    SampleDescriptionHandle *desc,
                                    OSType *mediaType);

    /**
     *  MovieImportGetMIMETypeList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportGetMIMETypeList(MovieImportComponent ci, QTAtomContainer *mimeInfo);

    /**
     *  MovieImportSetOffsetAndLimit()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportSetOffsetAndLimit(MovieImportComponent ci, unsigned long offset,
                                 unsigned long limit);

    /**
     *  MovieImportGetSettingsAsAtomContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportGetSettingsAsAtomContainer(MovieImportComponent ci,
                                          QTAtomContainer *settings);

    /**
     *  MovieImportSetSettingsFromAtomContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieImportSetSettingsFromAtomContainer(MovieImportComponent ci,
                                            QTAtomContainer settings);

    /**
     *  MovieImportSetOffsetAndLimit64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MovieImportSetOffsetAndLimit64(MovieImportComponent ci, const wide *offset,
                                   const wide *limit);

    /**
     *  MovieImportIdle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MovieImportIdle(MovieImportComponent ci, long inFlags, long *outFlags);

    /**
     *  MovieImportValidateDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MovieImportValidateDataRef(MovieImportComponent ci, Handle dataRef,
                               OSType dataRefType, UInt8 *valid);

    /**
     *  MovieImportGetLoadState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MovieImportGetLoadState(MovieImportComponent ci, long *importerLoadState);

    /**
     *  MovieImportGetMaxLoadedTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    MovieImportGetMaxLoadedTime(MovieImportComponent ci, TimeValue *time);

    /**
     *  MovieImportEstimateCompletionTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MovieImportEstimateCompletionTime(MovieImportComponent ci, TimeRecord *time);

    /**
     *  MovieImportSetDontBlock()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MovieImportSetDontBlock(MovieImportComponent ci, Boolean dontBlock);

    /**
     *  MovieImportGetDontBlock()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    MovieImportGetDontBlock(MovieImportComponent ci, Boolean *willBlock);

    /**
     *  MovieExportToHandle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportToHandle(MovieExportComponent ci, Handle dataH, Movie theMovie,
                        Track onlyThisTrack, TimeValue startTime,
                        TimeValue duration);

    /**
     *  MovieExportToFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportToFile(MovieExportComponent ci, const FSSpec *theFile,
                      Movie theMovie, Track onlyThisTrack, TimeValue startTime,
                      TimeValue duration);

    /**
     *  MovieExportGetAuxiliaryData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportGetAuxiliaryData(MovieExportComponent ci, Handle dataH,
                                OSType *handleType);

    /**
     *  MovieExportSetProgressProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportSetProgressProc(MovieExportComponent ci, MovieProgressUPP proc,
                               long refcon);

    /**
     *  MovieExportSetSampleDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportSetSampleDescription(MovieExportComponent ci,
                                    SampleDescriptionHandle desc, OSType mediaType);

    /**
     *  MovieExportDoUserDialog()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportDoUserDialog(MovieExportComponent ci, Movie theMovie,
                            Track onlyThisTrack, TimeValue startTime,
                            TimeValue duration, Boolean *canceled);

    /**
     *  MovieExportGetCreatorType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportGetCreatorType(MovieExportComponent ci, OSType *creator);

    /**
     *  MovieExportToDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportToDataRef(MovieExportComponent ci, Handle dataRef,
                         OSType dataRefType, Movie theMovie, Track onlyThisTrack,
                         TimeValue startTime, TimeValue duration);

    /**
     *  MovieExportFromProceduresToDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportFromProceduresToDataRef(MovieExportComponent ci, Handle dataRef,
                                       OSType dataRefType);

    /**
     *  MovieExportAddDataSource()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportAddDataSource(MovieExportComponent ci, OSType trackType,
                             TimeScale scale, long *trackID,
                             MovieExportGetPropertyUPP getPropertyProc,
                             MovieExportGetDataUPP getDataProc, void *refCon);

    /**
     *  MovieExportValidate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportValidate(MovieExportComponent ci, Movie theMovie,
                        Track onlyThisTrack, Boolean *valid);

    /**
     *  MovieExportGetSettingsAsAtomContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportGetSettingsAsAtomContainer(MovieExportComponent ci,
                                          QTAtomContainer *settings);

    /**
     *  MovieExportSetSettingsFromAtomContainer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportSetSettingsFromAtomContainer(MovieExportComponent ci,
                                            QTAtomContainer settings);

    /**
     *  MovieExportGetFileNameExtension()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportGetFileNameExtension(MovieExportComponent ci, OSType *extension);

    /**
     *  MovieExportGetShortFileTypeString()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportGetShortFileTypeString(MovieExportComponent ci, Str255 typeString);

    /**
     *  MovieExportGetSourceMediaType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportGetSourceMediaType(MovieExportComponent ci, OSType *mediaType);

    /**
     *  MovieExportSetGetMoviePropertyProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    MovieExportSetGetMoviePropertyProc(MovieExportComponent ci,
                                       MovieExportGetPropertyUPP getPropertyProc,
                                       void *refCon);

    /** Text Export Display Info data structure*/
    struct TextDisplayData
    {
        long displayFlags;
        long textJustification;
        RGBColor bgColor;
        Rect textBox;

        short beginHilite;
        short endHilite;
        RGBColor hiliteColor;
        Boolean doHiliteColor;
        SInt8 filler;
        TimeValue scrollDelayDur;
        Point dropShadowOffset;
        short dropShadowTransparency;
    };
    typedef struct TextDisplayData TextDisplayData;

    typedef ComponentInstance TextExportComponent;
    typedef ComponentInstance GraphicImageMovieImportComponent;
    /**
     *  TextExportGetDisplayData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TextExportGetDisplayData(TextExportComponent ci, TextDisplayData *textDisplay);

    /**
     *  TextExportGetTimeFraction()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TextExportGetTimeFraction(TextExportComponent ci, long *movieTimeFraction);

    /**
     *  TextExportSetTimeFraction()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TextExportSetTimeFraction(TextExportComponent ci, long movieTimeFraction);

    /**
     *  TextExportGetSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TextExportGetSettings(TextExportComponent ci, long *setting);

    /**
     *  TextExportSetSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    TextExportSetSettings(TextExportComponent ci, long setting);

    /**
     *  MIDIImportGetSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MIDIImportGetSettings(TextExportComponent ci, long *setting);

    /**
     *  MIDIImportSetSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MIDIImportSetSettings(TextExportComponent ci, long setting);

    /**
     *  MovieExportNewGetDataAndPropertiesProcs()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportNewGetDataAndPropertiesProcs(
        MovieExportComponent ci, OSType trackType, TimeScale *scale, Movie theMovie,
        Track theTrack, TimeValue startTime, TimeValue duration,
        MovieExportGetPropertyUPP *getPropertyProc,
        MovieExportGetDataUPP *getDataProc, void **refCon);

    /**
     *  MovieExportDisposeGetDataAndPropertiesProcs()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    MovieExportDisposeGetDataAndPropertiesProcs(
        MovieExportComponent ci, MovieExportGetPropertyUPP getPropertyProc,
        MovieExportGetDataUPP getDataProc, void *refCon);

    enum
    {
        movieExportUseConfiguredSettings =
            FOUR_CHAR_CODE('ucfg'),                   /** pointer to Boolean*/
        movieExportWidth = FOUR_CHAR_CODE('wdth'),    /** pointer to Fixed*/
        movieExportHeight = FOUR_CHAR_CODE('hegt'),   /** pointer to Fixed*/
        movieExportDuration = FOUR_CHAR_CODE('dura'), /** pointer to TimeRecord*/
        movieExportVideoFilter =
            FOUR_CHAR_CODE('iflt'),                   /** pointer to QTAtomContainer*/
        movieExportTimeScale = FOUR_CHAR_CODE('tmsc') /** pointer to TimeScale*/
    };

    /**
     *  GraphicsImageImportSetSequenceEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImageImportSetSequenceEnabled(GraphicImageMovieImportComponent ci,
                                          Boolean enable);

    /**
     *  GraphicsImageImportGetSequenceEnabled()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    GraphicsImageImportGetSequenceEnabled(GraphicImageMovieImportComponent ci,
                                          Boolean *enable);

    /****************

        File Preview Components

    ***************/
    typedef ComponentInstance pnotComponent;
    enum
    {
        pnotComponentWantsEvents = 1,
        pnotComponentNeedsNoCache = 2
    };

    enum
    {
        ShowFilePreviewComponentType = FOUR_CHAR_CODE('pnot'),
        CreateFilePreviewComponentType = FOUR_CHAR_CODE('pmak')
    };

    /**
     *  PreviewShowData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    PreviewShowData(pnotComponent p, OSType dataType, Handle data,
                    const Rect *inHere);

    /**
     *  PreviewMakePreview()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    PreviewMakePreview(pnotComponent p, OSType *previewType, Handle *previewResult,
                       const FSSpec *sourceFile, ICMProgressProcRecordPtr progress);

    /**
     *  PreviewMakePreviewReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    PreviewMakePreviewReference(pnotComponent p, OSType *previewType, short *resID,
                                const FSSpec *sourceFile);

    /**
     *  PreviewEvent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    PreviewEvent(pnotComponent p, EventRecord *e, Boolean *handledEvent);

    typedef ComponentInstance DataCompressorComponent;
    typedef ComponentInstance DataDecompressorComponent;
    typedef ComponentInstance DataCodecComponent;
    enum
    {
        DataCompressorComponentType = FOUR_CHAR_CODE('dcom'),
        DataDecompressorComponentType = FOUR_CHAR_CODE('ddec'),
        AppleDataCompressorSubType = FOUR_CHAR_CODE('adec'),
        zlibDataCompressorSubType = FOUR_CHAR_CODE('zlib')
    };

    /*** These are DataCodec procedures **/
    /**
     *  DataCodecDecompress()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataCodecDecompress(DataCodecComponent dc, void *srcData, UInt32 srcSize,
                        void *dstData, UInt32 dstBufferSize);

    /**
     *  DataCodecGetCompressBufferSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataCodecGetCompressBufferSize(DataCodecComponent dc, UInt32 srcSize,
                                   UInt32 *dstSize);

    /**
     *  DataCodecCompress()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataCodecCompress(DataCodecComponent dc, void *srcData, UInt32 srcSize,
                      void *dstData, UInt32 dstBufferSize, UInt32 *actualDstSize,
                      UInt32 *decompressSlop);

    /**
     *  DataCodecBeginInterruptSafe()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataCodecBeginInterruptSafe(DataCodecComponent dc, unsigned long maxSrcSize);

    /**
     *  DataCodecEndInterruptSafe()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataCodecEndInterruptSafe(DataCodecComponent dc);

    /**
     *  DataCodecDecompressPartial()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataCodecDecompressPartial(DataCodecComponent dc, void **next_in,
                               unsigned long *avail_in, unsigned long *total_in,
                               void **next_out, unsigned long *avail_out,
                               unsigned long *total_out, Boolean *didFinish);

    /**
     *  DataCodecCompressPartial()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataCodecCompressPartial(DataCodecComponent dc, void **next_in,
                             unsigned long *avail_in, unsigned long *total_in,
                             void **next_out, unsigned long *avail_out,
                             unsigned long *total_out, Boolean tryToFinish,
                             Boolean *didFinish);

    typedef CALLBACK_API(void, DataHCompletionProcPtr)(Ptr request, long refcon,
                                                       OSErr err);
    typedef STACK_UPP_TYPE(DataHCompletionProcPtr) DataHCompletionUPP;

    enum
    {
        kDataHCanRead = 1L << 0,
        kDataHSpecialRead = 1L << 1,
        kDataHSpecialReadFile = 1L << 2,
        kDataHCanWrite = 1L << 3,
        kDataHSpecialWrite = 1 << 4,
        kDataHSpecialWriteFile = 1 << 5,
        kDataHCanStreamingWrite = 1 << 6,
        kDataHMustCheckDataRef = 1 << 7
    };

    /** Data reference records for specific data ref types*/
    struct HandleDataRefRecord
    {
        Handle dataHndl;
    };
    typedef struct HandleDataRefRecord HandleDataRefRecord;
    typedef HandleDataRefRecord *HandleDataRefPtr;
    typedef HandleDataRefPtr *HandleDataRef;
    struct PointerDataRefRecord
    {
        void *data;
        Size dataLength;
    };
    typedef struct PointerDataRefRecord PointerDataRefRecord;
    typedef PointerDataRefRecord *PointerDataRefPtr;
    typedef PointerDataRefPtr *PointerDataRef;
    /** Data reference extensions*/
    enum
    {
        kDataRefExtensionChokeSpeed = FOUR_CHAR_CODE('chok'),
        kDataRefExtensionFileName = FOUR_CHAR_CODE('fnam'),
        kDataRefExtensionMIMEType = FOUR_CHAR_CODE('mime'),
        kDataRefExtensionMacOSFileType = FOUR_CHAR_CODE('ftyp'),
        kDataRefExtensionInitializationData = FOUR_CHAR_CODE('data')
    };

    enum
    {
        kDataHChokeToMovieDataRate = 1 << 0, /** param is 0*/
        kDataHChokeToParam = 1 << 1          /** param is bytes per second*/
    };

    struct DataHChokeAtomRecord
    {
        long flags; /** one of kDataHChokeTo constants*/
        long param;
    };
    typedef struct DataHChokeAtomRecord DataHChokeAtomRecord;

    struct DataHVolumeListRecord
    {
        short vRefNum;
        long flags;
    };
    typedef struct DataHVolumeListRecord DataHVolumeListRecord;
    typedef DataHVolumeListRecord *DataHVolumeListPtr;
    typedef DataHVolumeListPtr *DataHVolumeList;
    enum
    {
        kDataHExtendedSchedule = FOUR_CHAR_CODE('xtnd')
    };

    struct DataHScheduleRecord
    {
        TimeRecord timeNeededBy;
        long extendedID;   /** always is kDataHExtendedSchedule*/
        long extendedVers; /** always set to 0*/
        Fixed priority;    /** 100.0 or more means must have. lower numbers©*/
    };
    typedef struct DataHScheduleRecord DataHScheduleRecord;
    typedef DataHScheduleRecord *DataHSchedulePtr;
    /** Flags for DataHGetInfoFlags*/
    enum
    {
        kDataHInfoFlagNeverStreams =
            1 << 0, /** set if this data handler doesn't stream*/
        kDataHInfoFlagCanUpdateDataRefs =
            1 << 1, /** set if this data handler might update data reference*/
        kDataHInfoFlagNeedsNetworkBandwidth =
            1 << 2 /** set if this data handler may need to occupy the network*/
    };

    /** Types for DataHGetFileTypeOrdering*/
    enum
    {
        kDataHFileTypeMacOSFileType = FOUR_CHAR_CODE('ftyp'),
        kDataHFileTypeExtension = FOUR_CHAR_CODE('fext'),
        kDataHFileTypeMIME = FOUR_CHAR_CODE('mime')
    };

    typedef OSType *DataHFileTypeOrderingPtr;
    typedef DataHFileTypeOrderingPtr *DataHFileTypeOrderingHandle;

    /**
     *  DataHGetData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetData(DataHandler dh, Handle h, long hOffset, long offset, long size);

    /**
     *  DataHPutData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHPutData(DataHandler dh, Handle h, long hOffset, long *offset, long size);

    /**
     *  DataHFlushData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHFlushData(DataHandler dh);

    /**
     *  DataHOpenForWrite()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHOpenForWrite(DataHandler dh);

    /**
     *  DataHCloseForWrite()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHCloseForWrite(DataHandler dh);

    /**
     *  DataHOpenForRead()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHOpenForRead(DataHandler dh);

    /**
     *  DataHCloseForRead()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHCloseForRead(DataHandler dh);

    /**
     *  DataHSetDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHSetDataRef(DataHandler dh, Handle dataRef);

    /**
     *  DataHGetDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetDataRef(DataHandler dh, Handle *dataRef);

    /**
     *  DataHCompareDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHCompareDataRef(DataHandler dh, Handle dataRef, Boolean *equal);

    /**
     *  DataHTask()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHTask(DataHandler dh);

    /**
     *  DataHScheduleData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHScheduleData(DataHandler dh, Ptr PlaceToPutDataPtr, long FileOffset,
                      long DataSize, long RefCon, DataHSchedulePtr scheduleRec,
                      DataHCompletionUPP CompletionRtn);

    /**
     *  DataHFinishData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHFinishData(DataHandler dh, Ptr PlaceToPutDataPtr, Boolean Cancel);

    /**
     *  DataHFlushCache()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHFlushCache(DataHandler dh);

    /**
     *  DataHResolveDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHResolveDataRef(DataHandler dh, Handle theDataRef, Boolean *wasChanged,
                        Boolean userInterfaceAllowed);

    /**
     *  DataHGetFileSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetFileSize(DataHandler dh, long *fileSize);

    /**
     *  DataHCanUseDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHCanUseDataRef(DataHandler dh, Handle dataRef, long *useFlags);

    /**
     *  DataHGetVolumeList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetVolumeList(DataHandler dh, DataHVolumeList *volumeList);

    /**
     *  DataHWrite()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHWrite(DataHandler dh, Ptr data, long offset, long size,
               DataHCompletionUPP completion, long refCon);

    /**
     *  DataHPreextend()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHPreextend(DataHandler dh, unsigned long maxToAdd,
                   unsigned long *spaceAdded);

    /**
     *  DataHSetFileSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHSetFileSize(DataHandler dh, long fileSize);

    /**
     *  DataHGetFreeSpace()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetFreeSpace(DataHandler dh, unsigned long *freeSize);

    /**
     *  DataHCreateFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHCreateFile(DataHandler dh, OSType creator, Boolean deleteExisting);

    /**
     *  DataHGetPreferredBlockSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetPreferredBlockSize(DataHandler dh, long *blockSize);

    /**
     *  DataHGetDeviceIndex()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetDeviceIndex(DataHandler dh, long *deviceIndex);

    /**
     *  DataHIsStreamingDataHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHIsStreamingDataHandler(DataHandler dh, Boolean *yes);

    /**
     *  DataHGetDataInBuffer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetDataInBuffer(DataHandler dh, long startOffset, long *size);

    /**
     *  DataHGetScheduleAheadTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetScheduleAheadTime(DataHandler dh, long *millisecs);

    /**
     *  DataHSetCacheSizeLimit()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHSetCacheSizeLimit(DataHandler dh, Size cacheSizeLimit);

    /**
     *  DataHGetCacheSizeLimit()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetCacheSizeLimit(DataHandler dh, Size *cacheSizeLimit);

    /**
     *  DataHGetMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetMovie(DataHandler dh, Movie *theMovie, short *id);

    /**
     *  DataHAddMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHAddMovie(DataHandler dh, Movie theMovie, short *id);

    /**
     *  DataHUpdateMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHUpdateMovie(DataHandler dh, Movie theMovie, short id);

    /**
     *  DataHDoesBuffer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHDoesBuffer(DataHandler dh, Boolean *buffersReads, Boolean *buffersWrites);

    /**
     *  DataHGetFileName()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetFileName(DataHandler dh, Str255 str);

    /**
     *  DataHGetAvailableFileSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetAvailableFileSize(DataHandler dh, long *fileSize);

    /**
     *  DataHGetMacOSFileType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetMacOSFileType(DataHandler dh, OSType *fileType);

    /**
     *  DataHGetMIMEType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetMIMEType(DataHandler dh, Str255 mimeType);

    /**
     *  DataHSetDataRefWithAnchor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHSetDataRefWithAnchor(DataHandler dh, Handle anchorDataRef,
                              OSType dataRefType, Handle dataRef);

    /**
     *  DataHGetDataRefWithAnchor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHGetDataRefWithAnchor(DataHandler dh, Handle anchorDataRef,
                              OSType dataRefType, Handle *dataRef);

    /**
     *  DataHSetMacOSFileType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHSetMacOSFileType(DataHandler dh, OSType fileType);

    /**
     *  DataHSetTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHSetTimeBase(DataHandler dh, TimeBase tb);

    /**
     *  DataHGetInfoFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    DataHGetInfoFlags(DataHandler dh, UInt32 *flags);

    /**
     *  DataHScheduleData64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    DataHScheduleData64(DataHandler dh, Ptr PlaceToPutDataPtr,
                        const wide *FileOffset, long DataSize, long RefCon,
                        DataHSchedulePtr scheduleRec,
                        DataHCompletionUPP CompletionRtn);

    /**
     *  DataHWrite64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    DataHWrite64(DataHandler dh, Ptr data, const wide *offset, long size,
                 DataHCompletionUPP completion, long refCon);

    /**
     *  DataHGetFileSize64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    DataHGetFileSize64(DataHandler dh, wide *fileSize);

    /**
     *  DataHPreextend64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    DataHPreextend64(DataHandler dh, const wide *maxToAdd, wide *spaceAdded);

    /**
     *  DataHSetFileSize64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    DataHSetFileSize64(DataHandler dh, const wide *fileSize);

    /**
     *  DataHGetFreeSpace64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    DataHGetFreeSpace64(DataHandler dh, wide *freeSize);

    /**
     *  DataHAppend64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    DataHAppend64(DataHandler dh, void *data, wide *fileOffset, unsigned long size);

    /**
     *  DataHReadAsync()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    DataHReadAsync(DataHandler dh, void *dataPtr, UInt32 dataSize,
                   const wide *dataOffset, DataHCompletionUPP completion,
                   long refCon);

    /**
     *  DataHPollRead()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    DataHPollRead(DataHandler dh, void *dataPtr, UInt32 *dataSizeSoFar);

    /**
     *  DataHGetDataAvailability()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    DataHGetDataAvailability(DataHandler dh, long offset, long len,
                             long *missing_offset, long *missing_len);

    /**
     *  DataHGetFileSizeAsync()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    DataHGetFileSizeAsync(DataHandler dh, wide *fileSize,
                          DataHCompletionUPP completionRtn, long refCon);

    /**
     *  DataHGetDataRefAsType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    DataHGetDataRefAsType(DataHandler dh, OSType requestedType, Handle *dataRef);

    /**
     *  DataHSetDataRefExtension()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    DataHSetDataRefExtension(DataHandler dh, Handle extension, OSType idType);

    /**
     *  DataHGetDataRefExtension()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    DataHGetDataRefExtension(DataHandler dh, Handle *extension, OSType idType);

    /**
     *  DataHGetMovieWithFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    DataHGetMovieWithFlags(DataHandler dh, Movie *theMovie, short *id, short flags);

    /**
     *  DataHGetFileTypeOrdering()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    DataHGetFileTypeOrdering(DataHandler dh,
                             DataHFileTypeOrderingHandle *orderingListHandle);

    /** flags for DataHCreateFileWithFlags*/
    enum
    {
        kDataHCreateFileButDontCreateResFile = (1L << 0)
    };

    /**
     *  DataHCreateFileWithFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    DataHCreateFileWithFlags(DataHandler dh, OSType creator, Boolean deleteExisting,
                             UInt32 flags);

    /**
     *  DataHGetMIMETypeAsync()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    DataHGetMIMETypeAsync(DataHandler dh, Str255 mimeType,
                          DataHCompletionUPP completionRtn, long refCon);

    /**
     *  DataHGetInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0.1 and later
     *    \carbon_lib        not available in CarbonLib 1.x, is available on Mac OS
     X version 10.1 and later
     *    \mac_os_x         in version 10.1 and later
     *    Windows:          in qtmlClient.lib 5.0.1 and later
     */
    ComponentResult
    DataHGetInfo(DataHandler dh, OSType what, void *info);

    /**
     *  DataHPlaybackHints()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    DataHPlaybackHints(DataHandler dh, long flags, unsigned long minFileOffset,
                       unsigned long maxFileOffset, long bytesPerSecond);

    /**
     *  DataHPlaybackHints64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.1 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.1 and later
     */
    ComponentResult
    DataHPlaybackHints64(DataHandler dh, long flags, const wide *minFileOffset,
                         const wide *maxFileOffset, long bytesPerSecond);

    /** Symbolic constants for DataHGetDataRate*/
    enum
    {
        kDataHGetDataRateInfiniteRate =
            0x7FFFFFFF /** all the data arrived instantaneously*/
    };

    /**
     *  DataHGetDataRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    DataHGetDataRate(DataHandler dh, long flags, long *bytesPerSecond);

    /** Flags for DataHSetTimeHints*/
    enum
    {
        kDataHSetTimeHintsSkipBandwidthRequest =
            1 << 0 /** set if this data handler should use the network without
                      requesting bandwidth*/
    };

    /**
     *  DataHSetTimeHints()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    DataHSetTimeHints(DataHandler dh, long flags, long bandwidthPriority,
                      TimeScale scale, TimeValue minTime, TimeValue maxTime);

    /** Standard type for video digitizers */
    enum
    {
        videoDigitizerComponentType = FOUR_CHAR_CODE('vdig'),
        vdigInterfaceRev = 2
    };

    /** Input Format Standards */
    enum
    {
        ntscIn = 0,      /** current input format */
        currentIn = 0,   /** ntsc input format */
        palIn = 1,       /** pal input format */
        secamIn = 2,     /** secam input format */
        ntscReallyIn = 3 /** ntsc input format */
    };

    /** Input Formats */
    enum
    {
        compositeIn = 0,        /** input is composite format */
        sVideoIn = 1,           /** input is sVideo format */
        rgbComponentIn = 2,     /** input is rgb component format */
        rgbComponentSyncIn = 3, /** input is rgb component format (sync on green?)*/
        yuvComponentIn = 4,     /** input is yuv component format */
        yuvComponentSyncIn = 5, /** input is yuv component format (sync on green?) */
        tvTunerIn = 6,
        sdiIn = 7
    };

    /** Video Digitizer PlayThru States */
    enum
    {
        vdPlayThruOff = 0,
        vdPlayThruOn = 1
    };

    /** Input Color Space Modes */
    enum
    {
        vdDigitizerBW = 0, /** black and white */
        vdDigitizerRGB = 1 /** rgb color */
    };

    /** Phase Lock Loop Modes */
    enum
    {
        vdBroadcastMode = 0, /** Broadcast / Laser Disk video mode */
        vdVTRMode = 1        /** VCR / Magnetic media mode */
    };

    /** Field Select Options */
    enum
    {
        vdUseAnyField = 0, /** Digitizers choice on field use */
        vdUseOddField = 1, /** Use odd field for half size vert and smaller */
        vdUseEvenField = 2 /** Use even field for half size vert and smaller */
    };

    /** vdig types */
    enum
    {
        vdTypeBasic = 0, /** basic, no clipping */
        vdTypeAlpha = 1, /** supports clipping with alpha channel */
        vdTypeMask = 2,  /** supports clipping with mask plane */
        vdTypeKey = 3    /** supports clipping with key color(s) */
    };

    /** Digitizer Input Capability/Current Flags */
    enum
    {
        digiInDoesNTSC = 1L << 0,      /** digitizer supports NTSC input format */
        digiInDoesPAL = 1L << 1,       /** digitizer supports PAL input format */
        digiInDoesSECAM = 1L << 2,     /** digitizer supports SECAM input format */
        digiInDoesGenLock = 1L << 7,   /** digitizer does genlock */
        digiInDoesComposite = 1L << 8, /** digitizer supports composite input type */
        digiInDoesSVideo = 1L << 9,    /** digitizer supports S-Video input type */
        digiInDoesComponent =
            1L << 10, /** digitizer supports component = rgb, input type */
        digiInVTR_Broadcast =
            1L << 11,               /** digitizer can differentiate between the two */
        digiInDoesColor = 1L << 12, /** digitizer supports color */
        digiInDoesBW = 1L << 13,    /** digitizer supports black & white */
        /** Digitizer Input Current Flags = these are valid only during active
           operating conditions,   */
        digiInSignalLock = 1L << 31 /** digitizer detects input signal is locked, this
                                       bit = horiz lock || vertical lock */
    };

    /** Digitizer Output Capability/Current Flags */
    enum
    {
        digiOutDoes1 = 1L << 0,       /** digitizer supports 1 bit pixels */
        digiOutDoes2 = 1L << 1,       /** digitizer supports 2 bit pixels */
        digiOutDoes4 = 1L << 2,       /** digitizer supports 4 bit pixels */
        digiOutDoes8 = 1L << 3,       /** digitizer supports 8 bit pixels */
        digiOutDoes16 = 1L << 4,      /** digitizer supports 16 bit pixels */
        digiOutDoes32 = 1L << 5,      /** digitizer supports 32 bit pixels */
        digiOutDoesDither = 1L << 6,  /** digitizer dithers in indexed modes */
        digiOutDoesStretch = 1L << 7, /** digitizer can arbitrarily stretch */
        digiOutDoesShrink = 1L << 8,  /** digitizer can arbitrarily shrink */
        digiOutDoesMask = 1L << 9,    /** digitizer can mask to clipping regions */
        digiOutDoesDouble =
            1L << 11, /** digitizer can stretch to exactly double size */
        digiOutDoesQuad =
            1L << 12, /** digitizer can stretch exactly quadruple size */
        digiOutDoesQuarter =
            1L << 13, /** digitizer can shrink to exactly quarter size */
        digiOutDoesSixteenth =
            1L << 14,                 /** digitizer can shrink to exactly sixteenth size */
        digiOutDoesRotate = 1L << 15, /** digitizer supports rotate transformations */
        digiOutDoesHorizFlip =
            1L << 16, /** digitizer supports horizontal flips Sx < 0 */
        digiOutDoesVertFlip =
            1L << 17,               /** digitizer supports vertical flips Sy < 0 */
        digiOutDoesSkew = 1L << 18, /** digitizer supports skew = shear,twist, */
        digiOutDoesBlend = 1L << 19,
        digiOutDoesWarp = 1L << 20,
        digiOutDoesHW_DMA = 1L << 21, /** digitizer not constrained to local device */
        digiOutDoesHWPlayThru = 1L
                                << 22,    /** digitizer doesn't need time to play thru */
        digiOutDoesILUT = 1L << 23,       /** digitizer does inverse LUT for index modes */
        digiOutDoesKeyColor = 1L << 24,   /** digitizer does key color functions too */
        digiOutDoesAsyncGrabs = 1L << 25, /** digitizer supports async grabs */
        digiOutDoesUnreadableScreenBits =
            1L << 26,                       /** playthru doesn't generate readable bits on screen*/
        digiOutDoesCompress = 1L << 27,     /** supports alternate output data types */
        digiOutDoesCompressOnly = 1L << 28, /** can't provide raw frames anywhere */
        digiOutDoesPlayThruDuringCompress =
            1L << 29, /** digi can do playthru while providing compressed data */
        digiOutDoesCompressPartiallyVisible =
            1L << 30, /** digi doesn't need all bits visible on screen to do hardware
                         compress */
        digiOutDoesNotNeedCopyOfCompressData =
            1L << 31 /** digi doesn't need any bufferization when providing compressed
                        data */
    };

    /** Types */
    typedef ComponentInstance VideoDigitizerComponent;
    typedef ComponentResult VideoDigitizerError;
    struct DigitizerInfo
    {
        short vdigType;
        long inputCapabilityFlags;
        long outputCapabilityFlags;
        long inputCurrentFlags;
        long outputCurrentFlags;
        short slot;          /** temporary for connection purposes */
        GDHandle gdh;        /** temporary for digitizers that have preferred screen */
        GDHandle maskgdh;    /** temporary for digitizers that have mask planes */
        short minDestHeight; /** Smallest resizable height */
        short minDestWidth;  /** Smallest resizable width */
        short maxDestHeight; /** Largest resizable height */
        short maxDestWidth;  /** Largest resizable width */
        short blendLevels;   /** Number of blend levels supported (2 if 1 bit mask) */
        long reserved;       /** reserved */
    };
    typedef struct DigitizerInfo DigitizerInfo;
    struct VdigType
    {
        long digType;
        long reserved;
    };
    typedef struct VdigType VdigType;
    struct VdigTypeList
    {
        short count;
        VdigType list[1];
    };
    typedef struct VdigTypeList VdigTypeList;
    struct VdigBufferRec
    {
        PixMapHandle dest;
        Point location;
        long reserved;
    };
    typedef struct VdigBufferRec VdigBufferRec;
    struct VdigBufferRecList
    {
        short count;
        MatrixRecordPtr matrix;
        RgnHandle mask;
        VdigBufferRec list[1];
    };
    typedef struct VdigBufferRecList VdigBufferRecList;
    typedef VdigBufferRecList *VdigBufferRecListPtr;
    typedef VdigBufferRecListPtr *VdigBufferRecListHandle;
    typedef CALLBACK_API(void, VdigIntProcPtr)(long flags, long refcon);
    typedef STACK_UPP_TYPE(VdigIntProcPtr) VdigIntUPP;
    struct VDCompressionList
    {
        CodecComponent codec;
        CodecType cType;
        Str63 typeName;
        Str63 name;
        long formatFlags;
        long compressFlags;
        long reserved;
    };
    typedef struct VDCompressionList VDCompressionList;
    typedef VDCompressionList *VDCompressionListPtr;
    typedef VDCompressionListPtr *VDCompressionListHandle;
    enum
    {
        dmaDepth1 = 1,
        dmaDepth2 = 2,
        dmaDepth4 = 4,
        dmaDepth8 = 8,
        dmaDepth16 = 16,
        dmaDepth32 = 32,
        dmaDepth2Gray = 64,
        dmaDepth4Gray = 128,
        dmaDepth8Gray = 256
    };

    enum
    {
        kVDIGControlledFrameRate = -1
    };

    /**
     *  VDGetMaxSrcRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetMaxSrcRect(VideoDigitizerComponent ci, short inputStd, Rect *maxSrcRect);

    /**
     *  VDGetActiveSrcRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetActiveSrcRect(VideoDigitizerComponent ci, short inputStd,
                       Rect *activeSrcRect);

    /**
     *  VDSetDigitizerRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetDigitizerRect(VideoDigitizerComponent ci, Rect *digitizerRect);

    /**
     *  VDGetDigitizerRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetDigitizerRect(VideoDigitizerComponent ci, Rect *digitizerRect);

    /**
     *  VDGetVBlankRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetVBlankRect(VideoDigitizerComponent ci, short inputStd, Rect *vBlankRect);

    /**
     *  VDGetMaskPixMap()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetMaskPixMap(VideoDigitizerComponent ci, PixMapHandle maskPixMap);

    /**
     *  VDGetPlayThruDestination()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetPlayThruDestination(VideoDigitizerComponent ci, PixMapHandle *dest,
                             Rect *destRect, MatrixRecord *m, RgnHandle *mask);

    /**
     *  VDUseThisCLUT()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDUseThisCLUT(VideoDigitizerComponent ci, CTabHandle colorTableHandle);

    /**
     *  VDSetInputGammaValue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetInputGammaValue(VideoDigitizerComponent ci, Fixed channel1, Fixed channel2,
                         Fixed channel3);

    /**
     *  VDGetInputGammaValue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetInputGammaValue(VideoDigitizerComponent ci, Fixed *channel1,
                         Fixed *channel2, Fixed *channel3);

    /**
     *  VDSetBrightness()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetBrightness(VideoDigitizerComponent ci, unsigned short *brightness);

    /**
     *  VDGetBrightness()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetBrightness(VideoDigitizerComponent ci, unsigned short *brightness);

    /**
     *  VDSetContrast()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetContrast(VideoDigitizerComponent ci, unsigned short *contrast);

    /**
     *  VDSetHue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetHue(VideoDigitizerComponent ci, unsigned short *hue);

    /**
     *  VDSetSharpness()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetSharpness(VideoDigitizerComponent ci, unsigned short *sharpness);

    /**
     *  VDSetSaturation()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetSaturation(VideoDigitizerComponent ci, unsigned short *saturation);

    /**
     *  VDGetContrast()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetContrast(VideoDigitizerComponent ci, unsigned short *contrast);

    /**
     *  VDGetHue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetHue(VideoDigitizerComponent ci, unsigned short *hue);

    /**
     *  VDGetSharpness()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetSharpness(VideoDigitizerComponent ci, unsigned short *sharpness);

    /**
     *  VDGetSaturation()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetSaturation(VideoDigitizerComponent ci, unsigned short *saturation);

    /**
     *  VDGrabOneFrame()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGrabOneFrame(VideoDigitizerComponent ci);

    /**
     *  VDGetMaxAuxBuffer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetMaxAuxBuffer(VideoDigitizerComponent ci, PixMapHandle *pm, Rect *r);

    /**
     *  VDGetDigitizerInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetDigitizerInfo(VideoDigitizerComponent ci, DigitizerInfo *info);

    /**
     *  VDGetCurrentFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetCurrentFlags(VideoDigitizerComponent ci, long *inputCurrentFlag,
                      long *outputCurrentFlag);

    /**
     *  VDSetKeyColor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetKeyColor(VideoDigitizerComponent ci, long index);

    /**
     *  VDGetKeyColor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetKeyColor(VideoDigitizerComponent ci, long *index);

    /**
     *  VDAddKeyColor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDAddKeyColor(VideoDigitizerComponent ci, long *index);

    /**
     *  VDGetNextKeyColor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetNextKeyColor(VideoDigitizerComponent ci, long index);

    /**
     *  VDSetKeyColorRange()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetKeyColorRange(VideoDigitizerComponent ci, RGBColor *minRGB,
                       RGBColor *maxRGB);

    /**
     *  VDGetKeyColorRange()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetKeyColorRange(VideoDigitizerComponent ci, RGBColor *minRGB,
                       RGBColor *maxRGB);

    /**
     *  VDSetDigitizerUserInterrupt()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetDigitizerUserInterrupt(VideoDigitizerComponent ci, long flags,
                                VdigIntUPP userInterruptProc, long refcon);

    /**
     *  VDSetInputColorSpaceMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetInputColorSpaceMode(VideoDigitizerComponent ci, short colorSpaceMode);

    /**
     *  VDGetInputColorSpaceMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetInputColorSpaceMode(VideoDigitizerComponent ci, short *colorSpaceMode);

    /**
     *  VDSetClipState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetClipState(VideoDigitizerComponent ci, short clipEnable);

    /**
     *  VDGetClipState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetClipState(VideoDigitizerComponent ci, short *clipEnable);

    /**
     *  VDSetClipRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetClipRgn(VideoDigitizerComponent ci, RgnHandle clipRegion);

    /**
     *  VDClearClipRgn()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDClearClipRgn(VideoDigitizerComponent ci, RgnHandle clipRegion);

    /**
     *  VDGetCLUTInUse()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetCLUTInUse(VideoDigitizerComponent ci, CTabHandle *colorTableHandle);

    /**
     *  VDSetPLLFilterType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetPLLFilterType(VideoDigitizerComponent ci, short pllType);

    /**
     *  VDGetPLLFilterType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetPLLFilterType(VideoDigitizerComponent ci, short *pllType);

    /**
     *  VDGetMaskandValue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetMaskandValue(VideoDigitizerComponent ci, unsigned short blendLevel,
                      long *mask, long *value);

    /**
     *  VDSetMasterBlendLevel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetMasterBlendLevel(VideoDigitizerComponent ci, unsigned short *blendLevel);

    /**
     *  VDSetPlayThruDestination()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetPlayThruDestination(VideoDigitizerComponent ci, PixMapHandle dest,
                             RectPtr destRect, MatrixRecordPtr m, RgnHandle mask);

    /**
     *  VDSetPlayThruOnOff()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetPlayThruOnOff(VideoDigitizerComponent ci, short state);

    /**
     *  VDSetFieldPreference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetFieldPreference(VideoDigitizerComponent ci, short fieldFlag);

    /**
     *  VDGetFieldPreference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetFieldPreference(VideoDigitizerComponent ci, short *fieldFlag);

    /**
     *  VDPreflightDestination()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDPreflightDestination(VideoDigitizerComponent ci, Rect *digitizerRect,
                           PixMap **dest, RectPtr destRect, MatrixRecordPtr m);

    /**
     *  VDPreflightGlobalRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDPreflightGlobalRect(VideoDigitizerComponent ci, GrafPtr theWindow,
                          Rect *globalRect);

    /**
     *  VDSetPlayThruGlobalRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetPlayThruGlobalRect(VideoDigitizerComponent ci, GrafPtr theWindow,
                            Rect *globalRect);

    /**
     *  VDSetInputGammaRecord()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetInputGammaRecord(VideoDigitizerComponent ci, VDGamRecPtr inputGammaPtr);

    /**
     *  VDGetInputGammaRecord()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetInputGammaRecord(VideoDigitizerComponent ci, VDGamRecPtr *inputGammaPtr);

    /**
     *  VDSetBlackLevelValue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetBlackLevelValue(VideoDigitizerComponent ci, unsigned short *blackLevel);

    /**
     *  VDGetBlackLevelValue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetBlackLevelValue(VideoDigitizerComponent ci, unsigned short *blackLevel);

    /**
     *  VDSetWhiteLevelValue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetWhiteLevelValue(VideoDigitizerComponent ci, unsigned short *whiteLevel);

    /**
     *  VDGetWhiteLevelValue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetWhiteLevelValue(VideoDigitizerComponent ci, unsigned short *whiteLevel);

    /**
     *  VDGetVideoDefaults()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetVideoDefaults(VideoDigitizerComponent ci, unsigned short *blackLevel,
                       unsigned short *whiteLevel, unsigned short *brightness,
                       unsigned short *hue, unsigned short *saturation,
                       unsigned short *contrast, unsigned short *sharpness);

    /**
     *  VDGetNumberOfInputs()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetNumberOfInputs(VideoDigitizerComponent ci, short *inputs);

    /**
     *  VDGetInputFormat()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetInputFormat(VideoDigitizerComponent ci, short input, short *format);

    /**
     *  VDSetInput()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetInput(VideoDigitizerComponent ci, short input);

    /**
     *  VDGetInput()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetInput(VideoDigitizerComponent ci, short *input);

    /**
     *  VDSetInputStandard()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetInputStandard(VideoDigitizerComponent ci, short inputStandard);

    /**
     *  VDSetupBuffers()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetupBuffers(VideoDigitizerComponent ci, VdigBufferRecListHandle bufferList);

    /**
     *  VDGrabOneFrameAsync()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGrabOneFrameAsync(VideoDigitizerComponent ci, short buffer);

    /**
     *  VDDone()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDDone(VideoDigitizerComponent ci, short buffer);

    /**
     *  VDSetCompression()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetCompression(VideoDigitizerComponent ci, OSType compressType, short depth,
                     Rect *bounds, CodecQ spatialQuality, CodecQ temporalQuality,
                     long keyFrameRate);

    /**
     *  VDCompressOneFrameAsync()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDCompressOneFrameAsync(VideoDigitizerComponent ci);

    /**
     *  VDCompressDone()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDCompressDone(VideoDigitizerComponent ci, Boolean *done, Ptr *theData,
                   long *dataSize, UInt8 *similarity, TimeRecord *t);

    /**
     *  VDReleaseCompressBuffer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDReleaseCompressBuffer(VideoDigitizerComponent ci, Ptr bufferAddr);

    /**
     *  VDGetImageDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetImageDescription(VideoDigitizerComponent ci, ImageDescriptionHandle desc);

    /**
     *  VDResetCompressSequence()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDResetCompressSequence(VideoDigitizerComponent ci);

    /**
     *  VDSetCompressionOnOff()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetCompressionOnOff(VideoDigitizerComponent ci, Boolean state);

    /**
     *  VDGetCompressionTypes()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetCompressionTypes(VideoDigitizerComponent ci, VDCompressionListHandle h);

    /**
     *  VDSetTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetTimeBase(VideoDigitizerComponent ci, TimeBase t);

    /**
     *  VDSetFrameRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetFrameRate(VideoDigitizerComponent ci, Fixed framesPerSecond);

    /**
     *  VDGetDataRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetDataRate(VideoDigitizerComponent ci, long *milliSecPerFrame,
                  Fixed *framesPerSecond, long *bytesPerSecond);

    /**
     *  VDGetSoundInputDriver()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetSoundInputDriver(VideoDigitizerComponent ci, Str255 soundDriverName);

    /**
     *  VDGetDMADepths()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetDMADepths(VideoDigitizerComponent ci, long *depthArray,
                   long *preferredDepth);

    /**
     *  VDGetPreferredTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetPreferredTimeScale(VideoDigitizerComponent ci, TimeScale *preferred);

    /**
     *  VDReleaseAsyncBuffers()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDReleaseAsyncBuffers(VideoDigitizerComponent ci);

    /** 83 is reserved for compatibility reasons */
    /**
     *  VDSetDataRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetDataRate(VideoDigitizerComponent ci, long bytesPerSecond);

    /**
     *  VDGetTimeCode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetTimeCode(VideoDigitizerComponent ci, TimeRecord *atTime,
                  void *timeCodeFormat, void *timeCodeTime);

    /**
     *  VDUseSafeBuffers()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDUseSafeBuffers(VideoDigitizerComponent ci, Boolean useSafeBuffers);

    /**
     *  VDGetSoundInputSource()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetSoundInputSource(VideoDigitizerComponent ci, long videoInput,
                          long *soundInput);

    /**
     *  VDGetCompressionTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetCompressionTime(VideoDigitizerComponent ci, OSType compressionType,
                         short depth, Rect *srcRect, CodecQ *spatialQuality,
                         CodecQ *temporalQuality, unsigned long *compressTime);

    /**
     *  VDSetPreferredPacketSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetPreferredPacketSize(VideoDigitizerComponent ci,
                             long preferredPacketSizeInBytes);

    /**
     *  VDSetPreferredImageDimensions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetPreferredImageDimensions(VideoDigitizerComponent ci, long width,
                                  long height);

    /**
     *  VDGetPreferredImageDimensions()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetPreferredImageDimensions(VideoDigitizerComponent ci, long *width,
                                  long *height);

    /**
     *  VDGetInputName()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDGetInputName(VideoDigitizerComponent ci, long videoInput, Str255 name);

    /**
     *  VDSetDestinationPort()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.1 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    VideoDigitizerError
    VDSetDestinationPort(VideoDigitizerComponent ci, CGrafPtr destPort);

    enum
    {
        xmlParseComponentType = FOUR_CHAR_CODE('pars'),
        xmlParseComponentSubType = FOUR_CHAR_CODE('xml ')
    };

    enum
    {
        xmlIdentifierInvalid = 0,
        xmlIdentifierUnrecognized = (long)0xFFFFFFFF,
        xmlContentTypeInvalid = 0,
        xmlContentTypeElement = 1,
        xmlContentTypeCharData = 2
    };

    enum
    {
        elementFlagAlwaysSelfContained =
            1L << 0, /**    Element doesn't have contents or closing tag even if it
                        doesn't end with />, as in the HTML <img> tag*/
        elementFlagPreserveWhiteSpace =
            1L << 1, /**  Preserve whitespace in content, default is to remove it */
        xmlParseFlagAllowUppercase =
            1L << 0, /**    Entities and attributes do not have to be lowercase
                        (strict XML), but can be upper or mixed case as in HTML*/
        xmlParseFlagAllowUnquotedAttributeValues =
            1L << 1,                         /**    Attributes values do not have to be enclosed in quotes
                                                (strict XML), but can be left unquoted if they contain no
                                                spaces*/
        xmlParseFlagEventParseOnly = 1L << 2 /**    Do event parsing only*/
    };

    enum
    {
        attributeValueKindCharString = 0,
        attributeValueKindInteger = 1L << 0, /**    Number*/
        attributeValueKindPercent = 1L << 1, /**    Number or percent*/
        attributeValueKindBoolean = 1L << 2, /**    "true" or "false"*/
        attributeValueKindOnOff = 1L << 3,   /**    "on" or "off"*/
        attributeValueKindColor = 1L << 4,   /**    Either "#rrggbb" or a color name*/
        attributeValueKindEnum =
            1L << 5, /**    one of a number of strings; the enum strings are passed as
                        a zero-separated, double-zero-terminated C string in the
                        attributeKindValueInfo param*/
        attributeValueKindCaseSensEnum =
            1L
            << 6, /**    one of a number of strings; the enum strings are passed as
                     for attributeValueKindEnum, but the values are case-sensitive*/
        MAX_ATTRIBUTE_VALUE_KIND = attributeValueKindCaseSensEnum
    };

    enum
    {
        nameSpaceIDNone = 0
    };

    /**  A Parsed XML attribute value, one of number/percent, boolean/on-off, color,
     * or enumerated type*/
    union XMLAttributeValue
    {
        SInt32 number;   /**    The value when valueKind is attributeValueKindInteger or
                            attributeValueKindPercent*/
        Boolean boolean; /**    The value when valueKind is attributeValueKindBoolean
                            or attributeValueKindOnOff*/
        RGBColor color;  /**    The value when valueKind is attributeValueKindColor*/
        UInt32 enumType; /**    The value when valueKind is attributeValueKindEnum*/
    };
    typedef union XMLAttributeValue XMLAttributeValue;
    /**  An XML attribute-value pair*/
    struct XMLAttribute
    {
        UInt32 identifier;       /**    Tokenized identifier, if the attribute name was
                                    recognized by the parser*/
        char *name;              /**    Attribute name, Only present if identifier ==
                                    xmlIdentifierUnrecognized*/
        long valueKind;          /**    Type of parsed value, if the value was recognized and
                                    parsed; otherwise, attributeValueKindCharString*/
        XMLAttributeValue value; /**    Parsed attribute value*/
        char *valueStr;          /**    Always present*/
    };
    typedef struct XMLAttribute XMLAttribute;
    typedef XMLAttribute *XMLAttributePtr;
    /**  Forward struct declarations for recursively-defined tree structure*/
    typedef struct XMLContent XMLContent;
    typedef XMLContent *XMLContentPtr;
    /**
        An XML Element, i.e.
            <element attr="value" attr="value" ...> [contents] </element>
        or
            <element attr="value" attr="value" .../>
    */
    struct XMLElement
    {
        UInt32 identifier; /**    Tokenized identifier, if the element name was
                              recognized by the parser*/
        char *name;        /**    Element name, only present if identifier ==
                              xmlIdentifierUnrecognized*/
        XMLAttributePtr
            attributes;         /**    Array of attributes, terminated with an attribute with
                                   identifier == xmlIdentifierInvalid*/
        XMLContentPtr contents; /**    Array of contents, terminated with a content
                                   with kind == xmlIdentifierInvalid*/
    };
    typedef struct XMLElement XMLElement;
    typedef XMLElement *XMLElementPtr;
    /**
        The content of an XML element is a series of parts, each of which may be
       either another element or simply character data.
    */
    union XMLElementContent
    {
        XMLElement element; /**    The contents when the content kind is
                               xmlContentTypeElement*/
        char *charData;     /**    The contents when the content kind is
                               xmlContentTypeCharData*/
    };
    typedef union XMLElementContent XMLElementContent;
    struct XMLContent
    {
        UInt32 kind;
        XMLElementContent actualContent;
    };

    struct XMLDocRecord
    {
        void *xmlDataStorage; /**    opaque storage*/
        XMLElement rootElement;
    };
    typedef struct XMLDocRecord XMLDocRecord;
    typedef XMLDocRecord *XMLDoc;
    /**callback routines for event parsing*/
    typedef CALLBACK_API(ComponentResult, StartDocumentHandler)(long refcon);
    typedef CALLBACK_API(ComponentResult, EndDocumentHandler)(long refcon);
    typedef CALLBACK_API(ComponentResult, StartElementHandler)(const char *name,
                                                               const char **atts,
                                                               long refcon);
    typedef CALLBACK_API(ComponentResult, EndElementHandler)(const char *name,
                                                             long refcon);
    typedef CALLBACK_API(ComponentResult, CharDataHandler)(const char *charData,
                                                           long refcon);
    typedef CALLBACK_API(ComponentResult,
                         PreprocessInstructionHandler)(const char *name,
                                                       const char **atts,
                                                       long refcon);
    typedef CALLBACK_API(ComponentResult, CommentHandler)(const char *comment,
                                                          long refcon);
    typedef STACK_UPP_TYPE(StartDocumentHandler) StartDocumentHandlerUPP;
    typedef STACK_UPP_TYPE(EndDocumentHandler) EndDocumentHandlerUPP;
    typedef STACK_UPP_TYPE(StartElementHandler) StartElementHandlerUPP;
    typedef STACK_UPP_TYPE(EndElementHandler) EndElementHandlerUPP;
    typedef STACK_UPP_TYPE(CharDataHandler) CharDataHandlerUPP;
    typedef STACK_UPP_TYPE(PreprocessInstructionHandler)
        PreprocessInstructionHandlerUPP;
    typedef STACK_UPP_TYPE(CommentHandler) CommentHandlerUPP;
    /**
     *  XMLParseDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseDataRef(ComponentInstance aParser, Handle dataRef, OSType dataRefType,
                    long parseFlags, XMLDoc *document);

    /**  Parses the XML file pointed to by dataRef, returning a XMLDoc parse tree*/
    /**
     *  XMLParseFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseFile(ComponentInstance aParser, ConstFSSpecPtr fileSpec,
                 long parseFlags, XMLDoc *document);

    /**  Parses the XML file pointed to by fileSpec, returning a XMLDoc parse tree*/
    /**
     *  XMLParseDisposeXMLDoc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseDisposeXMLDoc(ComponentInstance aParser, XMLDoc document);

    /**  Disposes of a XMLDoc parse tree*/
    /**
     *  XMLParseGetDetailedParseError()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseGetDetailedParseError(ComponentInstance aParser, long *errorLine,
                                  StringPtr errDesc);

    /**
        Returns a more detailed description of the error and the line in which it
       occurred, if a file failed to parse properly.
    */
    /**
     *  XMLParseAddElement()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseAddElement(ComponentInstance aParser, char *elementName,
                       UInt32 nameSpaceID, UInt32 *elementID, long elementFlags);

    /**
        Tell the parser of an element to be recognized. The tokenized element unique
       identifier is passed in *elementID, unless *elementID is zero, whereupon a
       unique ID is generated and returned. Thus, a valid element identifier can
       never be zero.
    */
    /**
     *  XMLParseAddAttribute()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseAddAttribute(ComponentInstance aParser, UInt32 elementID,
                         UInt32 nameSpaceID, char *attributeName,
                         UInt32 *attributeID);

    /**
        Tells the parser of an attribute for the specified element. The tokenized
       attribute unique ID is passed in *attributeID, unless *attributeID is zero,
       whereupon a unique ID is generated and returned. Thus, a valid attribute
       identifier can never be zero.
    */
    /**
     *  XMLParseAddMultipleAttributes()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseAddMultipleAttributes(ComponentInstance aParser, UInt32 elementID,
                                  UInt32 *nameSpaceIDs, char *attributeNames,
                                  UInt32 *attributeIDs);

    /**
        Tells the parser of several attributes for the specified element. The
       attributes are passed as a zero-delimited, double-zero-terminated C string in
       attributeNames, and the attribute IDs are passed in on attributeIDs as an
       array; if any attributeIDs are zero, unique IDs are generated for those and
       returned
    */
    /**
     *  XMLParseAddAttributeAndValue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseAddAttributeAndValue(ComponentInstance aParser, UInt32 elementID,
                                 UInt32 nameSpaceID, char *attributeName,
                                 UInt32 *attributeID, UInt32 attributeValueKind,
                                 void *attributeValueKindInfo);

    /**
        Tells the parser of an attribute, which may have a particular type of value,
       for the specified element. Params are as in XMLParseAddAttribute, plus all
       the kinds of values the attribute may have are passed in attributeValueKind,
       and optional additional information required to tokenize the particular kind
       of attribute is passed in attributeValueKindInfo
    */
    /**
     *  XMLParseAddMultipleAttributesAndValues()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseAddMultipleAttributesAndValues(ComponentInstance aParser,
                                           UInt32 elementID, UInt32 *nameSpaceIDs,
                                           char *attributeNames,
                                           UInt32 *attributeIDs,
                                           UInt32 *attributeValueKinds,
                                           void **attributeValueKindInfos);

    /**
        Tells the parser of several attributes, which may have a particular type of
       value, for the specified element. Params are as in
       XMLParseAddMultipleAttributes, plus all the kinds of values the attributes
       may have are passed in attributeValueKinds, and optional additional
       information required to tokenize the particular kind of attributes is passed
       in attributeValueKindInfos
    */
    /**
     *  XMLParseAddAttributeValueKind()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseAddAttributeValueKind(ComponentInstance aParser, UInt32 elementID,
                                  UInt32 attributeID, UInt32 attributeValueKind,
                                  void *attributeValueKindInfo);

    /**
        Tells the parser that the particular attribute may have an additional kind
       of value, as specified by attributeValueKind and attributeValueKindInfo
    */
    /**
     *  XMLParseAddNameSpace()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseAddNameSpace(ComponentInstance aParser, char *nameSpaceURL,
                         UInt32 *nameSpaceID);

    /**
        Tell the parser of a namespace to be recognized. The tokenized namespace
       unique identifier is passed in *nameSpaceID, unless *nameSpaceID is zero,
       whereupon a unique ID is generated and returned. Thus, a valid nameSpaceID
       identifier can never be zero.
    */
    /**
     *  XMLParseSetOffsetAndLimit()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseSetOffsetAndLimit(ComponentInstance aParser, UInt32 offset,
                              UInt32 limit);

    /**  Specifies the offset and limit for reading from the dataref to be used when
     * parsing*/
    /**
     *  XMLParseSetEventParseRefCon()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseSetEventParseRefCon(ComponentInstance aParser, long refcon);

    /**  Set the event parse refcon*/
    /**
     *  XMLParseSetStartDocumentHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseSetStartDocumentHandler(ComponentInstance aParser,
                                    StartDocumentHandlerUPP startDocument);

    /**  Set the start document handler UPP for event parsing*/
    /**
     *  XMLParseSetEndDocumentHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseSetEndDocumentHandler(ComponentInstance aParser,
                                  EndDocumentHandlerUPP endDocument);

    /**  Set the end document handler UPP for event parsing*/
    /**
     *  XMLParseSetStartElementHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseSetStartElementHandler(ComponentInstance aParser,
                                   StartElementHandlerUPP startElement);

    /**  Set the start element handler UPP for event parsing*/
    /**
     *  XMLParseSetEndElementHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseSetEndElementHandler(ComponentInstance aParser,
                                 EndElementHandlerUPP endElement);

    /**  Set the end element handler UPP for event parsing*/
    /**
     *  XMLParseSetCharDataHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseSetCharDataHandler(ComponentInstance aParser,
                               CharDataHandlerUPP charData);

    /**  Set the character data handler UPP for event parsing*/
    /**
     *  XMLParseSetPreprocessInstructionHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseSetPreprocessInstructionHandler(
        ComponentInstance aParser,
        PreprocessInstructionHandlerUPP preprocessInstruction);

    /**  Set the preprocess instruction handler UPP for event parsing*/
    /**
     *  XMLParseSetCommentHandler()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    XMLParseSetCommentHandler(ComponentInstance aParser, CommentHandlerUPP comment);

    /**  Set the comment handler UPP for event parsing*/
    /**
        Helper Macros

            These macros allow you to easily add entities and attributes to the
       parser in an error free manner when the identifiers are defined in a
       particular manner. For these to work, you must define the identifiers as
       follows:

            For entities, they must be defined as element_elementName, as in:

                enum
                {
                    element_xml =   1,      //  "xml"
                    element_head,           //  "head"
                    element_body            //  "body"
                };

            If the element name has characters that are illegal in an identifier,
            some of the macros support that, but the identifier must not contain
            the illegal characters:

                enum
                {
                    element_rootlayout      //  "root-layout"
                }

            For attribute names, similar rules apply except that they must be
       defined as attr_attributeName, as in:

                enum
                {
                    attr_src    =   1,      //  "src"
                    attr_href,
                    attr_width,
                    attr_height
                }

            Finally, the existence of local variables elementID and attributeID is
       required.
    */

#define xmlpc_GLUE(a, b) a##b
#define xmlpc_GLUE2(a, b) xmlpc_GLUE(a, b)
#define XML_ADD_ELEMENT_NS(elementName, nameSpaceID) \
    elementID = xmlpc_GLUE2(element_, elementName);  \
    XMLParseAddElement(xmlParser, #elementName, nameSpaceID, &elementID, 0)
#define XML_ADD_ELEMENT(elementName) \
    XML_ADD_ELEMENT_NS(elementName, nameSpaceIDNone)

    /**
        Adds the specified element to the parser, i.e. XML_ADD_ELEMENT(head) adds
       the element "head" with a unique identifier of element_head
    */

#define XML_ADD_COMPLEX_ELEMENT_NS(elementName, elemID, nameSpaceID) \
    elementID = xmlpc_GLUE2(element_, elemID);                       \
    XMLParseAddElement(xmlParser, #elementName, nameSpaceID, &elementID, 0)
#define XML_ADD_COMPLEX_ELEMENT(elementName, elemID) \
    XML_ADD_COMPLEX_ELEMENT_NS(elementName, elemID, nameSpaceIDNone)

    /**
        Adds the specified element to the parser, not using the same string to
       generate the identifier and the element name. Use for element names that
       contain characters which are illegal in identifiers, i.e
       XML_ADD_COMPLEX_ELEMENT("root-layout",rootlayout) adds the element
       "root-layout" with a unique identifier of element_rootlayout
    */

#define XML_ADD_ATTRIBUTE_NS(attrName, nameSpaceID)                    \
    attributeID = xmlpc_GLUE2(attr_, attrName);                        \
    XMLParseAddAttribute(xmlParser, elementID, nameSpaceID, #attrName, \
                         &attributeID);
#define XML_ADD_ATTRIBUTE(attrName) \
    XML_ADD_ATTRIBUTE_NS(attrName, nameSpaceIDNone)

    /**
        Adds the specified attribute to the current element in the parser, i.e.
       XML_ADD_ATTRIBUTE(src) adds the attribute "src" to the current element, and
       identifies it by attr_src
    */

#define XML_ADD_COMPLEX_ATTRIBUTE_NS(attrName, attrID, nameSpaceID)    \
    attributeID = xmlpc_GLUE2(attr_, attrID);                          \
    XMLParseAddAttribute(xmlParser, elementID, nameSpaceID, #attrName, \
                         &attributeID);
#define XML_ADD_COMPLEX_ATTRIBUTE(attrName, attrID) \
    XML_ADD_COMPLEX_ATTRIBUTE_NS(attrName, attrID, nameSpaceIDNone)

    /**
        Adds the specified attribute to the current element in the parser, i.e.
       XML_ADD_ATTRIBUTE(element_img, src) adds the attribute "src" to the
       element_img element, and identifies it by attr_src Adds the specified
       attribute to the current element in the parser, not using the same string to
        generate the identifier and the element name. Use for attribute names that
       contain characters which are illegal in identifiers, i.e
       XML_ADD_COMPLEX_ATTRIBUTE("http-equiv",httpequiv) adds the element
        "http-equiv" with a unique identifier of attr_httpequiv
    */

#define XML_ADD_ATTRIBUTE_AND_VALUE_NS(attrName, valueKind, valueKindInfo,     \
                                       nameSpaceID)                            \
    attributeID = xmlpc_GLUE2(attr_, attrName);                                \
    XMLParseAddAttributeAndValue(xmlParser, elementID, nameSpaceID, #attrName, \
                                 &attributeID, valueKind, valueKindInfo);
#define XML_ADD_ATTRIBUTE_AND_VALUE(attrName, valueKind, valueKindInfo) \
    XML_ADD_ATTRIBUTE_AND_VALUE_NS(attrName, valueKind, valueKindInfo,  \
                                   nameSpaceIDNone)

#define XML_ADD_COMPLEX_ATTRIBUTE_AND_VALUE_NS(attrName, attrID, valueKind,    \
                                               valueKindInfo, nameSpaceID)     \
    attributeID = xmlpc_GLUE2(attr_, attrID);                                  \
    XMLParseAddAttributeAndValue(xmlParser, elementID, nameSpaceID, #attrName, \
                                 &attributeID, valueKind, valueKindInfo);
#define XML_ADD_COMPLEX_ATTRIBUTE_AND_VALUE(attrName, attrID, valueKind, \
                                            valueKindInfo)               \
    XML_ADD_COMPLEX_ATTRIBUTE_AND_VALUE_NS(attrName, attrID, valueKind,  \
                                           valueKindInfo, nameSpaceIDNone)

    /**
        General Sequence Grab stuff
    */
    typedef ComponentInstance SeqGrabComponent;
    typedef ComponentInstance SGChannel;
    enum
    {
        SeqGrabComponentType = FOUR_CHAR_CODE('barg'),
        SeqGrabChannelType = FOUR_CHAR_CODE('sgch'),
        SeqGrabPanelType = FOUR_CHAR_CODE('sgpn'),
        SeqGrabCompressionPanelType = FOUR_CHAR_CODE('cmpr'),
        SeqGrabSourcePanelType = FOUR_CHAR_CODE('sour')
    };

    enum
    {
        seqGrabToDisk = 1,
        seqGrabToMemory = 2,
        seqGrabDontUseTempMemory = 4,
        seqGrabAppendToFile = 8,
        seqGrabDontAddMovieResource = 16,
        seqGrabDontMakeMovie = 32,
        seqGrabPreExtendFile = 64,
        seqGrabDataProcIsInterruptSafe = 128,
        seqGrabDataProcDoesOverlappingReads = 256
    };

    typedef unsigned long SeqGrabDataOutputEnum;
    enum
    {
        seqGrabRecord = 1,
        seqGrabPreview = 2,
        seqGrabPlayDuringRecord = 4
    };

    typedef unsigned long SeqGrabUsageEnum;
    enum
    {
        seqGrabHasBounds = 1,
        seqGrabHasVolume = 2,
        seqGrabHasDiscreteSamples = 4,
        seqGrabDoNotBufferizeData = 8,
        seqGrabCanMoveWindowWhileRecording = 16
    };

    typedef unsigned long SeqGrabChannelInfoEnum;
    struct SGOutputRecord
    {
        long data[1];
    };
    typedef struct SGOutputRecord SGOutputRecord;
    typedef SGOutputRecord *SGOutput;
    struct SeqGrabFrameInfo
    {
        long frameOffset;
        long frameTime;
        long frameSize;
        SGChannel frameChannel;
        long frameRefCon;
    };
    typedef struct SeqGrabFrameInfo SeqGrabFrameInfo;
    typedef SeqGrabFrameInfo *SeqGrabFrameInfoPtr;
    struct SeqGrabExtendedFrameInfo
    {
        wide frameOffset;
        long frameTime;
        long frameSize;
        SGChannel frameChannel;
        long frameRefCon;
        SGOutput frameOutput;
    };
    typedef struct SeqGrabExtendedFrameInfo SeqGrabExtendedFrameInfo;
    typedef SeqGrabExtendedFrameInfo *SeqGrabExtendedFrameInfoPtr;
    enum
    {
        grabPictOffScreen = 1,
        grabPictIgnoreClip = 2,
        grabPictCurrentImage = 4
    };

    enum
    {
        sgFlagControlledGrab = (1 << 0),
        sgFlagAllowNonRGBPixMaps = (1 << 1)
    };

    typedef CALLBACK_API(OSErr, SGDataProcPtr)(SGChannel c, Ptr p, long len,
                                               long *offset, long chRefCon,
                                               TimeValue time, short writeType,
                                               long refCon);
    typedef STACK_UPP_TYPE(SGDataProcPtr) SGDataUPP;
    struct SGDeviceName
    {
        Str63 name;
        Handle icon;
        long flags;
        long refCon;
        long reserved; /** zero*/
    };
    typedef struct SGDeviceName SGDeviceName;
    enum
    {
        sgDeviceNameFlagDeviceUnavailable = (1 << 0)
    };

    struct SGDeviceListRecord
    {
        short count;
        short selectedIndex;
        long reserved; /** zero*/
        SGDeviceName entry[1];
    };
    typedef struct SGDeviceListRecord SGDeviceListRecord;
    typedef SGDeviceListRecord *SGDeviceListPtr;
    typedef SGDeviceListPtr *SGDeviceList;
    enum
    {
        sgDeviceListWithIcons = (1 << 0),
        sgDeviceListDontCheckAvailability = (1 << 1)
    };

    enum
    {
        seqGrabWriteAppend = 0,
        seqGrabWriteReserve = 1,
        seqGrabWriteFill = 2
    };

    enum
    {
        seqGrabUnpause = 0,
        seqGrabPause = 1,
        seqGrabPauseForMenu = 3
    };

    enum
    {
        channelFlagDontOpenResFile = 2,
        channelFlagHasDependency = 4
    };

    typedef CALLBACK_API(Boolean, SGModalFilterProcPtr)(DialogRef theDialog,
                                                        const EventRecord *theEvent,
                                                        short *itemHit,
                                                        long refCon);
    typedef STACK_UPP_TYPE(SGModalFilterProcPtr) SGModalFilterUPP;
    enum
    {
        sgPanelFlagForPanel = 1
    };

    enum
    {
        seqGrabSettingsPreviewOnly = 1
    };

    enum
    {
        channelPlayNormal = 0,
        channelPlayFast = 1,
        channelPlayHighQuality = 2,
        channelPlayAllData = 4
    };

    /**
     *  SGInitialize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGInitialize(SeqGrabComponent s);

    /**
     *  SGSetDataOutput()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetDataOutput(SeqGrabComponent s, const FSSpec *movieFile, long whereFlags);

    /**
     *  SGGetDataOutput()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetDataOutput(SeqGrabComponent s, FSSpec *movieFile, long *whereFlags);

    /**
     *  SGSetGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetGWorld(SeqGrabComponent s, CGrafPtr gp, GDHandle gd);

    /**
     *  SGGetGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetGWorld(SeqGrabComponent s, CGrafPtr *gp, GDHandle *gd);

    /**
     *  SGNewChannel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGNewChannel(SeqGrabComponent s, OSType channelType, SGChannel *ref);

    /**
     *  SGDisposeChannel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGDisposeChannel(SeqGrabComponent s, SGChannel c);

    /**
     *  SGStartPreview()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGStartPreview(SeqGrabComponent s);

    /**
     *  SGStartRecord()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGStartRecord(SeqGrabComponent s);

    /**
     *  SGIdle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGIdle(SeqGrabComponent s);

    /**
     *  SGStop()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGStop(SeqGrabComponent s);

    /**
     *  SGPause()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPause(SeqGrabComponent s, Byte pause);

    /**
     *  SGPrepare()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPrepare(SeqGrabComponent s, Boolean prepareForPreview,
              Boolean prepareForRecord);

    /**
     *  SGRelease()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGRelease(SeqGrabComponent s);

    /**
     *  SGGetMovie()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Movie
    SGGetMovie(SeqGrabComponent s);

    /**
     *  SGSetMaximumRecordTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetMaximumRecordTime(SeqGrabComponent s, unsigned long ticks);

    /**
     *  SGGetMaximumRecordTime()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetMaximumRecordTime(SeqGrabComponent s, unsigned long *ticks);

    /**
     *  SGGetStorageSpaceRemaining()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetStorageSpaceRemaining(SeqGrabComponent s, unsigned long *bytes);

    /**
     *  SGGetTimeRemaining()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetTimeRemaining(SeqGrabComponent s, long *ticksLeft);

    /**
     *  SGGrabPict()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGrabPict(SeqGrabComponent s, PicHandle *p, const Rect *bounds,
               short offscreenDepth, long grabPictFlags);

    /**
     *  SGGetLastMovieResID()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetLastMovieResID(SeqGrabComponent s, short *resID);

    /**
     *  SGSetFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetFlags(SeqGrabComponent s, long sgFlags);

    /**
     *  SGGetFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetFlags(SeqGrabComponent s, long *sgFlags);

    /**
     *  SGSetDataProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetDataProc(SeqGrabComponent s, SGDataUPP proc, long refCon);

    /**
     *  SGNewChannelFromComponent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGNewChannelFromComponent(SeqGrabComponent s, SGChannel *newChannel,
                              Component sgChannelComponent);

    /**
     *  SGDisposeDeviceList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGDisposeDeviceList(SeqGrabComponent s, SGDeviceList list);

    /**
     *  SGAppendDeviceListToMenu()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGAppendDeviceListToMenu(SeqGrabComponent s, SGDeviceList list, MenuRef mh);

    /**
     *  SGSetSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetSettings(SeqGrabComponent s, UserData ud, long flags);

    /**
     *  SGGetSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetSettings(SeqGrabComponent s, UserData *ud, long flags);

    /**
     *  SGGetIndChannel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetIndChannel(SeqGrabComponent s, short index, SGChannel *ref,
                    OSType *chanType);

    /**
     *  SGUpdate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGUpdate(SeqGrabComponent s, RgnHandle updateRgn);

    /**
     *  SGGetPause()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetPause(SeqGrabComponent s, Byte *paused);

    typedef const Component *ConstComponentListPtr;
    /**
     *  SGSettingsDialog()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSettingsDialog(SeqGrabComponent s, SGChannel c, short numPanels,
                     ConstComponentListPtr panelList, long flags,
                     SGModalFilterUPP proc, long procRefNum);

    /**
     *  SGGetAlignmentProc()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetAlignmentProc(SeqGrabComponent s, ICMAlignmentProcRecordPtr alignmentProc);

    /**
     *  SGSetChannelSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetChannelSettings(SeqGrabComponent s, SGChannel c, UserData ud, long flags);

    /**
     *  SGGetChannelSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetChannelSettings(SeqGrabComponent s, SGChannel c, UserData *ud, long flags);

    /**
     *  SGGetMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetMode(SeqGrabComponent s, Boolean *previewMode, Boolean *recordMode);

    /**
     *  SGSetDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetDataRef(SeqGrabComponent s, Handle dataRef, OSType dataRefType,
                 long whereFlags);

    /**
     *  SGGetDataRef()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetDataRef(SeqGrabComponent s, Handle *dataRef, OSType *dataRefType,
                 long *whereFlags);

    /**
     *  SGNewOutput()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGNewOutput(SeqGrabComponent s, Handle dataRef, OSType dataRefType,
                long whereFlags, SGOutput *sgOut);

    /**
     *  SGDisposeOutput()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGDisposeOutput(SeqGrabComponent s, SGOutput sgOut);

    /**
     *  SGSetOutputFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetOutputFlags(SeqGrabComponent s, SGOutput sgOut, long whereFlags);

    /**
     *  SGSetChannelOutput()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetChannelOutput(SeqGrabComponent s, SGChannel c, SGOutput sgOut);

    /**
     *  SGGetDataOutputStorageSpaceRemaining()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetDataOutputStorageSpaceRemaining(SeqGrabComponent s, SGOutput sgOut,
                                         unsigned long *space);

    /**
     *  SGHandleUpdateEvent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGHandleUpdateEvent(SeqGrabComponent s, const EventRecord *event,
                        Boolean *handled);

    /**
     *  SGSetOutputNextOutput()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetOutputNextOutput(SeqGrabComponent s, SGOutput sgOut, SGOutput nextOut);

    /**
     *  SGGetOutputNextOutput()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetOutputNextOutput(SeqGrabComponent s, SGOutput sgOut, SGOutput *nextOut);

    /**
     *  SGSetOutputMaximumOffset()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetOutputMaximumOffset(SeqGrabComponent s, SGOutput sgOut,
                             const wide *maxOffset);

    /**
     *  SGGetOutputMaximumOffset()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetOutputMaximumOffset(SeqGrabComponent s, SGOutput sgOut, wide *maxOffset);

    /**
     *  SGGetOutputDataReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetOutputDataReference(SeqGrabComponent s, SGOutput sgOut, Handle *dataRef,
                             OSType *dataRefType);

    /**
     *  SGWriteExtendedMovieData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGWriteExtendedMovieData(SeqGrabComponent s, SGChannel c, Ptr p, long len,
                             wide *offset, SGOutput *sgOut);

    /**
     *  SGGetStorageSpaceRemaining64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    SGGetStorageSpaceRemaining64(SeqGrabComponent s, wide *bytes);

    /**
     *  SGGetDataOutputStorageSpaceRemaining64()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    SGGetDataOutputStorageSpaceRemaining64(SeqGrabComponent s, SGOutput sgOut,
                                           wide *space);

    /**
        calls from Channel to seqGrab
    */
    /**
     *  SGWriteMovieData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGWriteMovieData(SeqGrabComponent s, SGChannel c, Ptr p, long len, long *offset);

    /**
     *  SGAddFrameReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGAddFrameReference(SeqGrabComponent s, SeqGrabFrameInfoPtr frameInfo);

    /**
     *  SGGetNextFrameReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetNextFrameReference(SeqGrabComponent s, SeqGrabFrameInfoPtr frameInfo,
                            TimeValue *frameDuration, long *frameNumber);

    /**
     *  SGGetTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetTimeBase(SeqGrabComponent s, TimeBase *tb);

    /**
     *  SGSortDeviceList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSortDeviceList(SeqGrabComponent s, SGDeviceList list);

    /**
     *  SGAddMovieData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGAddMovieData(SeqGrabComponent s, SGChannel c, Ptr p, long len, long *offset,
                   long chRefCon, TimeValue time, short writeType);

    /**
     *  SGChangedSource()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGChangedSource(SeqGrabComponent s, SGChannel c);

    /**
     *  SGAddExtendedFrameReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGAddExtendedFrameReference(SeqGrabComponent s,
                                SeqGrabExtendedFrameInfoPtr frameInfo);

    /**
     *  SGGetNextExtendedFrameReference()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetNextExtendedFrameReference(SeqGrabComponent s,
                                    SeqGrabExtendedFrameInfoPtr frameInfo,
                                    TimeValue *frameDuration, long *frameNumber);

    /**
     *  SGAddExtendedMovieData()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGAddExtendedMovieData(SeqGrabComponent s, SGChannel c, Ptr p, long len,
                           wide *offset, long chRefCon, TimeValue time,
                           short writeType, SGOutput *whichOutput);

    /**
     *  SGAddOutputDataRefToMedia()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGAddOutputDataRefToMedia(SeqGrabComponent s, SGOutput sgOut, Media theMedia,
                              SampleDescriptionHandle desc);

    /**** Sequence Grab CHANNEL Component Stuff ***/

    /**
     *  SGSetChannelUsage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetChannelUsage(SGChannel c, long usage);

    /**
     *  SGGetChannelUsage()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetChannelUsage(SGChannel c, long *usage);

    /**
     *  SGSetChannelBounds()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetChannelBounds(SGChannel c, const Rect *bounds);

    /**
     *  SGGetChannelBounds()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetChannelBounds(SGChannel c, Rect *bounds);

    /**
     *  SGSetChannelVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetChannelVolume(SGChannel c, short volume);

    /**
     *  SGGetChannelVolume()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetChannelVolume(SGChannel c, short *volume);

    /**
     *  SGGetChannelInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetChannelInfo(SGChannel c, long *channelInfo);

    /**
     *  SGSetChannelPlayFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetChannelPlayFlags(SGChannel c, long playFlags);

    /**
     *  SGGetChannelPlayFlags()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetChannelPlayFlags(SGChannel c, long *playFlags);

    /**
     *  SGSetChannelMaxFrames()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetChannelMaxFrames(SGChannel c, long frameCount);

    /**
     *  SGGetChannelMaxFrames()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetChannelMaxFrames(SGChannel c, long *frameCount);

    /**
     *  SGSetChannelRefCon()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetChannelRefCon(SGChannel c, long refCon);

    /**
     *  SGSetChannelClip()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetChannelClip(SGChannel c, RgnHandle theClip);

    /**
     *  SGGetChannelClip()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetChannelClip(SGChannel c, RgnHandle *theClip);

    /**
     *  SGGetChannelSampleDescription()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetChannelSampleDescription(SGChannel c, Handle sampleDesc);

    /**
     *  SGGetChannelDeviceList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetChannelDeviceList(SGChannel c, long selectionFlags, SGDeviceList *list);

    /**
     *  SGSetChannelDevice()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetChannelDevice(SGChannel c, StringPtr name);

    /**
     *  SGSetChannelMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetChannelMatrix(SGChannel c, const MatrixRecord *m);

    /**
     *  SGGetChannelMatrix()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetChannelMatrix(SGChannel c, MatrixRecord *m);

    /**
     *  SGGetChannelTimeScale()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetChannelTimeScale(SGChannel c, TimeScale *scale);

    /**
     *  SGChannelPutPicture()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGChannelPutPicture(SGChannel c);

    /**
     *  SGChannelSetRequestedDataRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGChannelSetRequestedDataRate(SGChannel c, long bytesPerSecond);

    /**
     *  SGChannelGetRequestedDataRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGChannelGetRequestedDataRate(SGChannel c, long *bytesPerSecond);

    /**
     *  SGChannelSetDataSourceName()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGChannelSetDataSourceName(SGChannel c, ConstStr255Param name,
                               ScriptCode scriptTag);

    /**
     *  SGChannelGetDataSourceName()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGChannelGetDataSourceName(SGChannel c, Str255 name, ScriptCode *scriptTag);

    /**
     *  SGChannelSetCodecSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    SGChannelSetCodecSettings(SGChannel c, Handle settings);

    /**
     *  SGChannelGetCodecSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    SGChannelGetCodecSettings(SGChannel c, Handle *settings);

    /**
     *  SGGetChannelTimeBase()
     *

     *    \non_carbon_cfm   in QuickTimeLib 4.0 and later
     *    \carbon_lib        in CarbonLib 1.0.2 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 4.0 and later
     */
    ComponentResult
    SGGetChannelTimeBase(SGChannel c, TimeBase *tb);

    /**
        calls from seqGrab to Channel
    */
    /**
     *  SGInitChannel()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGInitChannel(SGChannel c, SeqGrabComponent owner);

    /**
     *  SGWriteSamples()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGWriteSamples(SGChannel c, Movie m, AliasHandle theFile);

    /**
     *  SGGetDataRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetDataRate(SGChannel c, long *bytesPerSecond);

    /**
     *  SGAlignChannelRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGAlignChannelRect(SGChannel c, Rect *r);

    /**
        Dorky dialog panel calls
    */
    /**
     *  SGPanelGetDitl()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPanelGetDitl(SeqGrabComponent s, Handle *ditl);

    /**
     *  SGPanelGetTitle()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPanelGetTitle(SeqGrabComponent s, Str255 title);

    /**
     *  SGPanelCanRun()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPanelCanRun(SeqGrabComponent s, SGChannel c);

    /**
     *  SGPanelInstall()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPanelInstall(SeqGrabComponent s, SGChannel c, DialogRef d, short itemOffset);

    /**
     *  SGPanelEvent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPanelEvent(SeqGrabComponent s, SGChannel c, DialogRef d, short itemOffset,
                 const EventRecord *theEvent, short *itemHit, Boolean *handled);

    /**
     *  SGPanelItem()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPanelItem(SeqGrabComponent s, SGChannel c, DialogRef d, short itemOffset,
                short itemNum);

    /**
     *  SGPanelRemove()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPanelRemove(SeqGrabComponent s, SGChannel c, DialogRef d, short itemOffset);

    /**
     *  SGPanelSetGrabber()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPanelSetGrabber(SeqGrabComponent s, SeqGrabComponent sg);

    /**
     *  SGPanelSetResFile()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPanelSetResFile(SeqGrabComponent s, short resRef);

    /**
     *  SGPanelGetSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPanelGetSettings(SeqGrabComponent s, SGChannel c, UserData *ud, long flags);

    /**
     *  SGPanelSetSettings()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPanelSetSettings(SeqGrabComponent s, SGChannel c, UserData ud, long flags);

    /**
     *  SGPanelValidateInput()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPanelValidateInput(SeqGrabComponent s, Boolean *ok);

    /**
     *  SGPanelSetEventFilter()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGPanelSetEventFilter(SeqGrabComponent s, SGModalFilterUPP proc, long refCon);

    /**** Sequence Grab VIDEO CHANNEL Component Stuff ***/
    /**
        Video stuff
    */
    struct SGCompressInfo
    {
        Ptr buffer;
        unsigned long bufferSize;
        UInt8 similarity;
        UInt8 reserved;
    };
    typedef struct SGCompressInfo SGCompressInfo;
    typedef CALLBACK_API(ComponentResult, SGGrabBottleProcPtr)(SGChannel c,
                                                               short bufferNum,
                                                               long refCon);
    typedef CALLBACK_API(ComponentResult,
                         SGGrabCompleteBottleProcPtr)(SGChannel c, short bufferNum,
                                                      Boolean *done, long refCon);
    typedef CALLBACK_API(ComponentResult,
                         SGDisplayBottleProcPtr)(SGChannel c, short bufferNum,
                                                 MatrixRecord *mp,
                                                 RgnHandle clipRgn, long refCon);
    typedef CALLBACK_API(ComponentResult, SGCompressBottleProcPtr)(SGChannel c,
                                                                   short bufferNum,
                                                                   long refCon);
    typedef CALLBACK_API(ComponentResult, SGCompressCompleteBottleProcPtr)(
        SGChannel c, short bufferNum, Boolean *done, SGCompressInfo *ci,
        long refCon);
    typedef CALLBACK_API(ComponentResult,
                         SGAddFrameBottleProcPtr)(SGChannel c, short bufferNum,
                                                  TimeValue atTime, TimeScale scale,
                                                  const SGCompressInfo *ci,
                                                  long refCon);
    typedef CALLBACK_API(ComponentResult,
                         SGTransferFrameBottleProcPtr)(SGChannel c, short bufferNum,
                                                       MatrixRecord *mp,
                                                       RgnHandle clipRgn,
                                                       long refCon);
    typedef CALLBACK_API(ComponentResult, SGGrabCompressCompleteBottleProcPtr)(
        SGChannel c, Boolean *done, SGCompressInfo *ci, TimeRecord *t, long refCon);
    typedef CALLBACK_API(ComponentResult, SGDisplayCompressBottleProcPtr)(
        SGChannel c, Ptr dataPtr, ImageDescriptionHandle desc, MatrixRecord *mp,
        RgnHandle clipRgn, long refCon);
    typedef STACK_UPP_TYPE(SGGrabBottleProcPtr) SGGrabBottleUPP;
    typedef STACK_UPP_TYPE(SGGrabCompleteBottleProcPtr) SGGrabCompleteBottleUPP;
    typedef STACK_UPP_TYPE(SGDisplayBottleProcPtr) SGDisplayBottleUPP;
    typedef STACK_UPP_TYPE(SGCompressBottleProcPtr) SGCompressBottleUPP;
    typedef STACK_UPP_TYPE(SGCompressCompleteBottleProcPtr)
        SGCompressCompleteBottleUPP;
    typedef STACK_UPP_TYPE(SGAddFrameBottleProcPtr) SGAddFrameBottleUPP;
    typedef STACK_UPP_TYPE(SGTransferFrameBottleProcPtr) SGTransferFrameBottleUPP;
    typedef STACK_UPP_TYPE(SGGrabCompressCompleteBottleProcPtr)
        SGGrabCompressCompleteBottleUPP;
    typedef STACK_UPP_TYPE(SGDisplayCompressBottleProcPtr)
        SGDisplayCompressBottleUPP;
    struct VideoBottles
    {
        short procCount;
        SGGrabBottleUPP grabProc;
        SGGrabCompleteBottleUPP grabCompleteProc;
        SGDisplayBottleUPP displayProc;
        SGCompressBottleUPP compressProc;
        SGCompressCompleteBottleUPP compressCompleteProc;
        SGAddFrameBottleUPP addFrameProc;
        SGTransferFrameBottleUPP transferFrameProc;
        SGGrabCompressCompleteBottleUPP grabCompressCompleteProc;
        SGDisplayCompressBottleUPP displayCompressProc;
    };
    typedef struct VideoBottles VideoBottles;
    /**
     *  SGGetSrcVideoBounds()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetSrcVideoBounds(SGChannel c, Rect *r);

    /**
     *  SGSetVideoRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetVideoRect(SGChannel c, const Rect *r);

    /**
     *  SGGetVideoRect()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetVideoRect(SGChannel c, Rect *r);

    /**
     *  SGGetVideoCompressorType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetVideoCompressorType(SGChannel c, OSType *compressorType);

    /**
     *  SGSetVideoCompressorType()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetVideoCompressorType(SGChannel c, OSType compressorType);

    /**
     *  SGSetVideoCompressor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetVideoCompressor(SGChannel c, short depth, CompressorComponent compressor,
                         CodecQ spatialQuality, CodecQ temporalQuality,
                         long keyFrameRate);

    /**
     *  SGGetVideoCompressor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetVideoCompressor(SGChannel c, short *depth, CompressorComponent *compressor,
                         CodecQ *spatialQuality, CodecQ *temporalQuality,
                         long *keyFrameRate);

    /**
     *  SGGetVideoDigitizerComponent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentInstance
    SGGetVideoDigitizerComponent(SGChannel c);

    /**
     *  SGSetVideoDigitizerComponent()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetVideoDigitizerComponent(SGChannel c, ComponentInstance vdig);

    /**
     *  SGVideoDigitizerChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGVideoDigitizerChanged(SGChannel c);

    /**
     *  SGSetVideoBottlenecks()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetVideoBottlenecks(SGChannel c, VideoBottles *vb);

    /**
     *  SGGetVideoBottlenecks()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetVideoBottlenecks(SGChannel c, VideoBottles *vb);

    /**
     *  SGGrabFrame()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGrabFrame(SGChannel c, short bufferNum);

    /**
     *  SGGrabFrameComplete()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGrabFrameComplete(SGChannel c, short bufferNum, Boolean *done);

    /**
     *  SGDisplayFrame()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGDisplayFrame(SGChannel c, short bufferNum, const MatrixRecord *mp,
                   RgnHandle clipRgn);

    /**
     *  SGCompressFrame()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGCompressFrame(SGChannel c, short bufferNum);

    /**
     *  SGCompressFrameComplete()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGCompressFrameComplete(SGChannel c, short bufferNum, Boolean *done,
                            SGCompressInfo *ci);

    /**
     *  SGAddFrame()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGAddFrame(SGChannel c, short bufferNum, TimeValue atTime, TimeScale scale,
               const SGCompressInfo *ci);

    /**
     *  SGTransferFrameForCompress()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGTransferFrameForCompress(SGChannel c, short bufferNum, const MatrixRecord *mp,
                               RgnHandle clipRgn);

    /**
     *  SGSetCompressBuffer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetCompressBuffer(SGChannel c, short depth, const Rect *compressSize);

    /**
     *  SGGetCompressBuffer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetCompressBuffer(SGChannel c, short *depth, Rect *compressSize);

    /**
     *  SGGetBufferInfo()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetBufferInfo(SGChannel c, short bufferNum, PixMapHandle *bufferPM,
                    Rect *bufferRect, GWorldPtr *compressBuffer,
                    Rect *compressBufferRect);

    /**
     *  SGSetUseScreenBuffer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetUseScreenBuffer(SGChannel c, Boolean useScreenBuffer);

    /**
     *  SGGetUseScreenBuffer()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetUseScreenBuffer(SGChannel c, Boolean *useScreenBuffer);

    /**
     *  SGGrabCompressComplete()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGrabCompressComplete(SGChannel c, Boolean *done, SGCompressInfo *ci,
                           TimeRecord *tr);

    /**
     *  SGDisplayCompress()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGDisplayCompress(SGChannel c, Ptr dataPtr, ImageDescriptionHandle desc,
                      MatrixRecord *mp, RgnHandle clipRgn);

    /**
     *  SGSetFrameRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetFrameRate(SGChannel c, Fixed frameRate);

    /**
     *  SGGetFrameRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetFrameRate(SGChannel c, Fixed *frameRate);

    /**
     *  SGSetPreferredPacketSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetPreferredPacketSize(SGChannel c, long preferredPacketSizeInBytes);

    /**
     *  SGGetPreferredPacketSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetPreferredPacketSize(SGChannel c, long *preferredPacketSizeInBytes);

    /**
     *  SGSetUserVideoCompressorList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetUserVideoCompressorList(SGChannel c, Handle compressorTypes);

    /**
     *  SGGetUserVideoCompressorList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetUserVideoCompressorList(SGChannel c, Handle *compressorTypes);

    /**** Sequence Grab SOUND CHANNEL Component Stuff ***/

    /**
        Sound stuff
    */
    /**
     *  SGSetSoundInputDriver()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetSoundInputDriver(SGChannel c, ConstStr255Param driverName);

    /**
     *  SGGetSoundInputDriver()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    SGGetSoundInputDriver(SGChannel c);

    /**
     *  SGSoundInputDriverChanged()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSoundInputDriverChanged(SGChannel c);

    /**
     *  SGSetSoundRecordChunkSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetSoundRecordChunkSize(SGChannel c, long seconds);

    /**
     *  SGGetSoundRecordChunkSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    long
    SGGetSoundRecordChunkSize(SGChannel c);

    /**
     *  SGSetSoundInputRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetSoundInputRate(SGChannel c, Fixed rate);

    /**
     *  SGGetSoundInputRate()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    Fixed
    SGGetSoundInputRate(SGChannel c);

    /**
     *  SGSetSoundInputParameters()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetSoundInputParameters(SGChannel c, short sampleSize, short numChannels,
                              OSType compressionType);

    /**
     *  SGGetSoundInputParameters()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetSoundInputParameters(SGChannel c, short *sampleSize, short *numChannels,
                              OSType *compressionType);

    /**
     *  SGSetAdditionalSoundRates()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetAdditionalSoundRates(SGChannel c, Handle rates);

    /**
     *  SGGetAdditionalSoundRates()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetAdditionalSoundRates(SGChannel c, Handle *rates);

    /**
        Text stuff
    */
    /**
     *  SGSetFontName()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetFontName(SGChannel c, StringPtr pstr);

    /**
     *  SGSetFontSize()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetFontSize(SGChannel c, short fontSize);

    /**
     *  SGSetTextForeColor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetTextForeColor(SGChannel c, RGBColor *theColor);

    /**
     *  SGSetTextBackColor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetTextBackColor(SGChannel c, RGBColor *theColor);

    /**
     *  SGSetJustification()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetJustification(SGChannel c, short just);

    /**
     *  SGGetTextReturnToSpaceValue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetTextReturnToSpaceValue(SGChannel c, short *rettospace);

    /**
     *  SGSetTextReturnToSpaceValue()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetTextReturnToSpaceValue(SGChannel c, short rettospace);

    /**
        Music stuff
    */
    /**
     *  SGGetInstrument()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGGetInstrument(SGChannel c, ToneDescription *td);

    /**
     *  SGSetInstrument()
     *

     *    \non_carbon_cfm   in QuickTimeLib 2.5 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    SGSetInstrument(SGChannel c, ToneDescription *td);

    enum
    {
        sgChannelAtom = FOUR_CHAR_CODE('chan'),
        sgChannelSettingsAtom = FOUR_CHAR_CODE('ctom'),
        sgChannelDescription = FOUR_CHAR_CODE('cdsc'),
        sgChannelSettings = FOUR_CHAR_CODE('cset')
    };

    enum
    {
        sgDeviceNameType = FOUR_CHAR_CODE('name'),
        sgUsageType = FOUR_CHAR_CODE('use '),
        sgPlayFlagsType = FOUR_CHAR_CODE('plyf'),
        sgClipType = FOUR_CHAR_CODE('clip'),
        sgMatrixType = FOUR_CHAR_CODE('mtrx'),
        sgVolumeType = FOUR_CHAR_CODE('volu')
    };

    enum
    {
        sgPanelSettingsAtom = FOUR_CHAR_CODE('ptom'),
        sgPanelDescription = FOUR_CHAR_CODE('pdsc'),
        sgPanelSettings = FOUR_CHAR_CODE('pset')
    };

    enum
    {
        sgcSoundCompressionType = FOUR_CHAR_CODE('scmp'),
        sgcSoundSampleRateType = FOUR_CHAR_CODE('srat'),
        sgcSoundChannelCountType = FOUR_CHAR_CODE('schn'),
        sgcSoundSampleSizeType = FOUR_CHAR_CODE('ssiz'),
        sgcSoundInputType = FOUR_CHAR_CODE('sinp'),
        sgcSoundGainType = FOUR_CHAR_CODE('gain')
    };

    enum
    {
        sgcVideoHueType = FOUR_CHAR_CODE('hue '),
        sgcVideoSaturationType = FOUR_CHAR_CODE('satr'),
        sgcVideoContrastType = FOUR_CHAR_CODE('trst'),
        sgcVideoSharpnessType = FOUR_CHAR_CODE('shrp'),
        sgcVideoBrigtnessType = FOUR_CHAR_CODE('brit'),
        sgcVideoBlackLevelType = FOUR_CHAR_CODE('blkl'),
        sgcVideoWhiteLevelType = FOUR_CHAR_CODE('whtl'),
        sgcVideoInputType = FOUR_CHAR_CODE('vinp'),
        sgcVideoFormatType = FOUR_CHAR_CODE('vstd'),
        sgcVideoFilterType = FOUR_CHAR_CODE('vflt'),
        sgcVideoRectType = FOUR_CHAR_CODE('vrct'),
        sgcVideoDigitizerType = FOUR_CHAR_CODE('vdig')
    };

    typedef ComponentInstance QTVideoOutputComponent;
    /** Component type and subtype enumerations*/
    enum
    {
        QTVideoOutputComponentType = FOUR_CHAR_CODE('vout'),
        QTVideoOutputComponentBaseSubType = FOUR_CHAR_CODE('base')
    };

    /** QTVideoOutput Component flags*/

    enum
    {
        kQTVideoOutputDontDisplayToUser = 1L << 0
    };

    /** Display mode atom types*/

    enum
    {
        kQTVODisplayModeItem = FOUR_CHAR_CODE('qdmi'),
        kQTVODimensions = FOUR_CHAR_CODE(
            'dimn'), /** atom contains two longs - pixel count - width, height*/
        kQTVOResolution =
            FOUR_CHAR_CODE('resl'), /** atom contains two Fixed - hRes, vRes in dpi*/
        kQTVORefreshRate =
            FOUR_CHAR_CODE('refr'), /** atom contains one Fixed - refresh rate in Hz*/
        kQTVOPixelType = FOUR_CHAR_CODE(
            'pixl'),                        /** atom contains one OSType - pixel format of mode*/
        kQTVOName = FOUR_CHAR_CODE('name'), /** atom contains string (no length byte)
                                               - name of mode for display to user*/
        kQTVODecompressors =
            FOUR_CHAR_CODE('deco'), /** atom contains other atoms indicating supported
                                       decompressors*/
                                    /** kQTVODecompressors sub-atoms*/
        kQTVODecompressorType = FOUR_CHAR_CODE(
            'dety'), /** atom contains one OSType - decompressor type code*/
        kQTVODecompressorContinuous =
            FOUR_CHAR_CODE('cont'), /** atom contains one Boolean - true if this type
                                       is displayed continuously*/
        kQTVODecompressorComponent = FOUR_CHAR_CODE(
            'cmpt') /** atom contains one Component - component id of decompressor*/
    };

    /*** These are QTVideoOutput procedures **/
    /**
     *  QTVideoOutputGetDisplayModeList()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputGetDisplayModeList(QTVideoOutputComponent vo,
                                    QTAtomContainer *outputs);

    /**
     *  QTVideoOutputGetCurrentClientName()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputGetCurrentClientName(QTVideoOutputComponent vo, Str255 str);

    /**
     *  QTVideoOutputSetClientName()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputSetClientName(QTVideoOutputComponent vo, ConstStr255Param str);

    /**
     *  QTVideoOutputGetClientName()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputGetClientName(QTVideoOutputComponent vo, Str255 str);

    /**
     *  QTVideoOutputBegin()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputBegin(QTVideoOutputComponent vo);

    /**
     *  QTVideoOutputEnd()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputEnd(QTVideoOutputComponent vo);

    /**
     *  QTVideoOutputSetDisplayMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputSetDisplayMode(QTVideoOutputComponent vo, long displayModeID);

    /**
     *  QTVideoOutputGetDisplayMode()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputGetDisplayMode(QTVideoOutputComponent vo, long *displayModeID);

    /**
     *  QTVideoOutputCustomConfigureDisplay()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputCustomConfigureDisplay(QTVideoOutputComponent vo,
                                        ModalFilterUPP filter);

    /**
     *  QTVideoOutputSaveState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputSaveState(QTVideoOutputComponent vo, QTAtomContainer *state);

    /**
     *  QTVideoOutputRestoreState()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputRestoreState(QTVideoOutputComponent vo, QTAtomContainer state);

    /**
     *  QTVideoOutputGetGWorld()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputGetGWorld(QTVideoOutputComponent vo, GWorldPtr *gw);

    /**
     *  QTVideoOutputGetGWorldParameters()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputGetGWorldParameters(QTVideoOutputComponent vo, Ptr *baseAddr,
                                     long *rowBytes, CTabHandle *colorTable);

    /**
     *  QTVideoOutputGetIndSoundOutput()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputGetIndSoundOutput(QTVideoOutputComponent vo, long index,
                                   Component *outputComponent);

    /**
     *  QTVideoOutputGetClock()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputGetClock(QTVideoOutputComponent vo, ComponentInstance *clock);

    /**
     *  QTVideoOutputSetEchoPort()
     *

     *    \non_carbon_cfm   in QuickTimeLib 3.0 and later
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 3.0 and later
     */
    ComponentResult
    QTVideoOutputSetEchoPort(QTVideoOutputComponent vo, CGrafPtr echoPort);

    /**
     *  QTVideoOutputGetIndImageDecompressor()
     *

     *    \non_carbon_cfm   in QuickTimeLib 5.0 and later
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     *    Windows:          in qtmlClient.lib 5.0 and later
     */
    ComponentResult
    QTVideoOutputGetIndImageDecompressor(QTVideoOutputComponent vo, long index,
                                         Component *codec);

    /** UPP call backs */
    /**
     *  NewDataHCompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    DataHCompletionUPP
    NewDataHCompletionUPP(DataHCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppDataHCompletionProcInfo = 0x00000BC0
    }; /** pascal no_return_value Func(4_bytes, 4_bytes, 2_bytes) */
#ifdef __cplusplus
    inline DataHCompletionUPP
    NewDataHCompletionUPP(DataHCompletionProcPtr userRoutine)
    {
        return (DataHCompletionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                        uppDataHCompletionProcInfo,
                                                        GetCurrentArchitecture());
    }
#else
#define NewDataHCompletionUPP(userRoutine)                                       \
    (DataHCompletionUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppDataHCompletionProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewVdigIntUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    VdigIntUPP
    NewVdigIntUPP(VdigIntProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppVdigIntProcInfo = 0x000003C0
    }; /** pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline VdigIntUPP NewVdigIntUPP(VdigIntProcPtr userRoutine)
    {
        return (VdigIntUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppVdigIntProcInfo, GetCurrentArchitecture());
    }
#else
#define NewVdigIntUPP(userRoutine)     \
    (VdigIntUPP) NewRoutineDescriptor( \
        (ProcPtr)(userRoutine), uppVdigIntProcInfo, GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewStartDocumentHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    StartDocumentHandlerUPP
    NewStartDocumentHandlerUPP(StartDocumentHandler userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppStartDocumentHandlerProcInfo = 0x000000F0
    }; /** pascal 4_bytes Func(4_bytes) */
#ifdef __cplusplus
    inline StartDocumentHandlerUPP
    NewStartDocumentHandlerUPP(StartDocumentHandler userRoutine)
    {
        return (StartDocumentHandlerUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppStartDocumentHandlerProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewStartDocumentHandlerUPP(userRoutine)                  \
    (StartDocumentHandlerUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppStartDocumentHandlerProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewEndDocumentHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    EndDocumentHandlerUPP
    NewEndDocumentHandlerUPP(EndDocumentHandler userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppEndDocumentHandlerProcInfo = 0x000000F0
    }; /** pascal 4_bytes Func(4_bytes) */
#ifdef __cplusplus
    inline EndDocumentHandlerUPP
    NewEndDocumentHandlerUPP(EndDocumentHandler userRoutine)
    {
        return (EndDocumentHandlerUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppEndDocumentHandlerProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewEndDocumentHandlerUPP(userRoutine)                                   \
    (EndDocumentHandlerUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),        \
                                                 uppEndDocumentHandlerProcInfo, \
                                                 GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewStartElementHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    StartElementHandlerUPP
    NewStartElementHandlerUPP(StartElementHandler userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppStartElementHandlerProcInfo = 0x00000FF0
    }; /** pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline StartElementHandlerUPP
    NewStartElementHandlerUPP(StartElementHandler userRoutine)
    {
        return (StartElementHandlerUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppStartElementHandlerProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewStartElementHandlerUPP(userRoutine)                  \
    (StartElementHandlerUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppStartElementHandlerProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewEndElementHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    EndElementHandlerUPP
    NewEndElementHandlerUPP(EndElementHandler userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppEndElementHandlerProcInfo = 0x000003F0
    }; /** pascal 4_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline EndElementHandlerUPP
    NewEndElementHandlerUPP(EndElementHandler userRoutine)
    {
        return (EndElementHandlerUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppEndElementHandlerProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewEndElementHandlerUPP(userRoutine)                                  \
    (EndElementHandlerUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),       \
                                                uppEndElementHandlerProcInfo, \
                                                GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewCharDataHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    CharDataHandlerUPP
    NewCharDataHandlerUPP(CharDataHandler userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppCharDataHandlerProcInfo = 0x000003F0
    }; /** pascal 4_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline CharDataHandlerUPP NewCharDataHandlerUPP(CharDataHandler userRoutine)
    {
        return (CharDataHandlerUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                        uppCharDataHandlerProcInfo,
                                                        GetCurrentArchitecture());
    }
#else
#define NewCharDataHandlerUPP(userRoutine)                                       \
    (CharDataHandlerUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppCharDataHandlerProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewPreprocessInstructionHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    PreprocessInstructionHandlerUPP
    NewPreprocessInstructionHandlerUPP(PreprocessInstructionHandler userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppPreprocessInstructionHandlerProcInfo = 0x00000FF0
    }; /** pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline PreprocessInstructionHandlerUPP
    NewPreprocessInstructionHandlerUPP(PreprocessInstructionHandler userRoutine)
    {
        return (PreprocessInstructionHandlerUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppPreprocessInstructionHandlerProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewPreprocessInstructionHandlerUPP(userRoutine)                  \
    (PreprocessInstructionHandlerUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppPreprocessInstructionHandlerProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewCommentHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    CommentHandlerUPP
    NewCommentHandlerUPP(CommentHandler userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppCommentHandlerProcInfo = 0x000003F0
    }; /** pascal 4_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline CommentHandlerUPP NewCommentHandlerUPP(CommentHandler userRoutine)
    {
        return (CommentHandlerUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                       uppCommentHandlerProcInfo,
                                                       GetCurrentArchitecture());
    }
#else
#define NewCommentHandlerUPP(userRoutine)                                       \
    (CommentHandlerUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppCommentHandlerProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSGDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SGDataUPP
    NewSGDataUPP(SGDataProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppSGDataProcInfo = 0x003BFFE0
    }; /** pascal 2_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes,
          2_bytes, 4_bytes) */
#ifdef __cplusplus
    inline SGDataUPP NewSGDataUPP(SGDataProcPtr userRoutine)
    {
        return (SGDataUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppSGDataProcInfo, GetCurrentArchitecture());
    }
#else
#define NewSGDataUPP(userRoutine)                                               \
    (SGDataUPP) NewRoutineDescriptor((ProcPtr)(userRoutine), uppSGDataProcInfo, \
                                     GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSGModalFilterUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SGModalFilterUPP
    NewSGModalFilterUPP(SGModalFilterProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppSGModalFilterProcInfo = 0x00003FD0
    }; /** pascal 1_byte Func(4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline SGModalFilterUPP NewSGModalFilterUPP(SGModalFilterProcPtr userRoutine)
    {
        return (SGModalFilterUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                      uppSGModalFilterProcInfo,
                                                      GetCurrentArchitecture());
    }
#else
#define NewSGModalFilterUPP(userRoutine)                                       \
    (SGModalFilterUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppSGModalFilterProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSGGrabBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SGGrabBottleUPP
    NewSGGrabBottleUPP(SGGrabBottleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppSGGrabBottleProcInfo = 0x00000EF0
    }; /** pascal 4_bytes Func(4_bytes, 2_bytes, 4_bytes) */
#ifdef __cplusplus
    inline SGGrabBottleUPP NewSGGrabBottleUPP(SGGrabBottleProcPtr userRoutine)
    {
        return (SGGrabBottleUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                     uppSGGrabBottleProcInfo,
                                                     GetCurrentArchitecture());
    }
#else
#define NewSGGrabBottleUPP(userRoutine)                                       \
    (SGGrabBottleUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppSGGrabBottleProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSGGrabCompleteBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SGGrabCompleteBottleUPP
    NewSGGrabCompleteBottleUPP(SGGrabCompleteBottleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppSGGrabCompleteBottleProcInfo = 0x00003EF0
    }; /** pascal 4_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline SGGrabCompleteBottleUPP
    NewSGGrabCompleteBottleUPP(SGGrabCompleteBottleProcPtr userRoutine)
    {
        return (SGGrabCompleteBottleUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppSGGrabCompleteBottleProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewSGGrabCompleteBottleUPP(userRoutine)                  \
    (SGGrabCompleteBottleUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppSGGrabCompleteBottleProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSGDisplayBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SGDisplayBottleUPP
    NewSGDisplayBottleUPP(SGDisplayBottleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppSGDisplayBottleProcInfo = 0x0000FEF0
    }; /** pascal 4_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline SGDisplayBottleUPP
    NewSGDisplayBottleUPP(SGDisplayBottleProcPtr userRoutine)
    {
        return (SGDisplayBottleUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                        uppSGDisplayBottleProcInfo,
                                                        GetCurrentArchitecture());
    }
#else
#define NewSGDisplayBottleUPP(userRoutine)                                       \
    (SGDisplayBottleUPP)                                                         \
        NewRoutineDescriptor((ProcPtr)(userRoutine), uppSGDisplayBottleProcInfo, \
                             GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSGCompressBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SGCompressBottleUPP
    NewSGCompressBottleUPP(SGCompressBottleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppSGCompressBottleProcInfo = 0x00000EF0
    }; /** pascal 4_bytes Func(4_bytes, 2_bytes, 4_bytes) */
#ifdef __cplusplus
    inline SGCompressBottleUPP
    NewSGCompressBottleUPP(SGCompressBottleProcPtr userRoutine)
    {
        return (SGCompressBottleUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                         uppSGCompressBottleProcInfo,
                                                         GetCurrentArchitecture());
    }
#else
#define NewSGCompressBottleUPP(userRoutine)                                 \
    (SGCompressBottleUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),      \
                                               uppSGCompressBottleProcInfo, \
                                               GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSGCompressCompleteBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SGCompressCompleteBottleUPP
    NewSGCompressCompleteBottleUPP(SGCompressCompleteBottleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppSGCompressCompleteBottleProcInfo = 0x0000FEF0
    }; /** pascal 4_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline SGCompressCompleteBottleUPP
    NewSGCompressCompleteBottleUPP(SGCompressCompleteBottleProcPtr userRoutine)
    {
        return (SGCompressCompleteBottleUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppSGCompressCompleteBottleProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewSGCompressCompleteBottleUPP(userRoutine)                  \
    (SGCompressCompleteBottleUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppSGCompressCompleteBottleProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSGAddFrameBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SGAddFrameBottleUPP
    NewSGAddFrameBottleUPP(SGAddFrameBottleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppSGAddFrameBottleProcInfo = 0x0003FEF0
    }; /** pascal 4_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes)
        */
#ifdef __cplusplus
    inline SGAddFrameBottleUPP
    NewSGAddFrameBottleUPP(SGAddFrameBottleProcPtr userRoutine)
    {
        return (SGAddFrameBottleUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                         uppSGAddFrameBottleProcInfo,
                                                         GetCurrentArchitecture());
    }
#else
#define NewSGAddFrameBottleUPP(userRoutine)                                 \
    (SGAddFrameBottleUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),      \
                                               uppSGAddFrameBottleProcInfo, \
                                               GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSGTransferFrameBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SGTransferFrameBottleUPP
    NewSGTransferFrameBottleUPP(SGTransferFrameBottleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppSGTransferFrameBottleProcInfo = 0x0000FEF0
    }; /** pascal 4_bytes Func(4_bytes, 2_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline SGTransferFrameBottleUPP
    NewSGTransferFrameBottleUPP(SGTransferFrameBottleProcPtr userRoutine)
    {
        return (SGTransferFrameBottleUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppSGTransferFrameBottleProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewSGTransferFrameBottleUPP(userRoutine)                  \
    (SGTransferFrameBottleUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppSGTransferFrameBottleProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSGGrabCompressCompleteBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SGGrabCompressCompleteBottleUPP
    NewSGGrabCompressCompleteBottleUPP(
        SGGrabCompressCompleteBottleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppSGGrabCompressCompleteBottleProcInfo = 0x0000FFF0
    }; /** pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
    inline SGGrabCompressCompleteBottleUPP NewSGGrabCompressCompleteBottleUPP(
        SGGrabCompressCompleteBottleProcPtr userRoutine)
    {
        return (SGGrabCompressCompleteBottleUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppSGGrabCompressCompleteBottleProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewSGGrabCompressCompleteBottleUPP(userRoutine)                  \
    (SGGrabCompressCompleteBottleUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppSGGrabCompressCompleteBottleProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  NewSGDisplayCompressBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    SGDisplayCompressBottleUPP
    NewSGDisplayCompressBottleUPP(SGDisplayCompressBottleProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
    enum
    {
        uppSGDisplayCompressBottleProcInfo = 0x0003FFF0
    }; /** pascal 4_bytes Func(4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes)
        */
#ifdef __cplusplus
    inline SGDisplayCompressBottleUPP
    NewSGDisplayCompressBottleUPP(SGDisplayCompressBottleProcPtr userRoutine)
    {
        return (SGDisplayCompressBottleUPP)NewRoutineDescriptor(
            (ProcPtr)(userRoutine), uppSGDisplayCompressBottleProcInfo,
            GetCurrentArchitecture());
    }
#else
#define NewSGDisplayCompressBottleUPP(userRoutine)                  \
    (SGDisplayCompressBottleUPP) NewRoutineDescriptor(              \
        (ProcPtr)(userRoutine), uppSGDisplayCompressBottleProcInfo, \
        GetCurrentArchitecture())
#endif
#endif

    /**
     *  DisposeDataHCompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeDataHCompletionUPP(DataHCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeDataHCompletionUPP(DataHCompletionUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeDataHCompletionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeVdigIntUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeVdigIntUPP(VdigIntUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeVdigIntUPP(VdigIntUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeVdigIntUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeStartDocumentHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeStartDocumentHandlerUPP(StartDocumentHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeStartDocumentHandlerUPP(StartDocumentHandlerUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeStartDocumentHandlerUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeEndDocumentHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeEndDocumentHandlerUPP(EndDocumentHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeEndDocumentHandlerUPP(EndDocumentHandlerUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeEndDocumentHandlerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeStartElementHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeStartElementHandlerUPP(StartElementHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeStartElementHandlerUPP(StartElementHandlerUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeStartElementHandlerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeEndElementHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeEndElementHandlerUPP(EndElementHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeEndElementHandlerUPP(EndElementHandlerUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeEndElementHandlerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeCharDataHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeCharDataHandlerUPP(CharDataHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeCharDataHandlerUPP(CharDataHandlerUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeCharDataHandlerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposePreprocessInstructionHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposePreprocessInstructionHandlerUPP(PreprocessInstructionHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposePreprocessInstructionHandlerUPP(
        PreprocessInstructionHandlerUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposePreprocessInstructionHandlerUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeCommentHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeCommentHandlerUPP(CommentHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeCommentHandlerUPP(CommentHandlerUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeCommentHandlerUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSGDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSGDataUPP(SGDataUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSGDataUPP(SGDataUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSGDataUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSGModalFilterUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSGModalFilterUPP(SGModalFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSGModalFilterUPP(SGModalFilterUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSGModalFilterUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSGGrabBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSGGrabBottleUPP(SGGrabBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSGGrabBottleUPP(SGGrabBottleUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSGGrabBottleUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSGGrabCompleteBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSGGrabCompleteBottleUPP(SGGrabCompleteBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSGGrabCompleteBottleUPP(SGGrabCompleteBottleUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSGGrabCompleteBottleUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSGDisplayBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSGDisplayBottleUPP(SGDisplayBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSGDisplayBottleUPP(SGDisplayBottleUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSGDisplayBottleUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSGCompressBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSGCompressBottleUPP(SGCompressBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSGCompressBottleUPP(SGCompressBottleUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSGCompressBottleUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSGCompressCompleteBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSGCompressCompleteBottleUPP(SGCompressCompleteBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void
    DisposeSGCompressCompleteBottleUPP(SGCompressCompleteBottleUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSGCompressCompleteBottleUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSGAddFrameBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSGAddFrameBottleUPP(SGAddFrameBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSGAddFrameBottleUPP(SGAddFrameBottleUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSGAddFrameBottleUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSGTransferFrameBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSGTransferFrameBottleUPP(SGTransferFrameBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSGTransferFrameBottleUPP(SGTransferFrameBottleUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSGTransferFrameBottleUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSGGrabCompressCompleteBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSGGrabCompressCompleteBottleUPP(SGGrabCompressCompleteBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void DisposeSGGrabCompressCompleteBottleUPP(
        SGGrabCompressCompleteBottleUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSGGrabCompressCompleteBottleUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  DisposeSGDisplayCompressBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    DisposeSGDisplayCompressBottleUPP(SGDisplayCompressBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void
    DisposeSGDisplayCompressBottleUPP(SGDisplayCompressBottleUPP userUPP)
    {
        DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
    }
#else
#define DisposeSGDisplayCompressBottleUPP(userUPP) \
    DisposeRoutineDescriptor(userUPP)
#endif
#endif

    /**
     *  InvokeDataHCompletionUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeDataHCompletionUPP(Ptr request, long refcon, OSErr err,
                             DataHCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeDataHCompletionUPP(Ptr request, long refcon, OSErr err,
                                         DataHCompletionUPP userUPP)
    {
        CALL_THREE_PARAMETER_UPP(userUPP, uppDataHCompletionProcInfo, request, refcon,
                                 err);
    }
#else
#define InvokeDataHCompletionUPP(request, refcon, err, userUPP)                \
    CALL_THREE_PARAMETER_UPP((userUPP), uppDataHCompletionProcInfo, (request), \
                             (refcon), (err))
#endif
#endif

    /**
     *  InvokeVdigIntUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    void
    InvokeVdigIntUPP(long flags, long refcon, VdigIntUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline void InvokeVdigIntUPP(long flags, long refcon, VdigIntUPP userUPP)
    {
        CALL_TWO_PARAMETER_UPP(userUPP, uppVdigIntProcInfo, flags, refcon);
    }
#else
#define InvokeVdigIntUPP(flags, refcon, userUPP) \
    CALL_TWO_PARAMETER_UPP((userUPP), uppVdigIntProcInfo, (flags), (refcon))
#endif
#endif

    /**
     *  InvokeStartDocumentHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeStartDocumentHandlerUPP(long refcon, StartDocumentHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult
    InvokeStartDocumentHandlerUPP(long refcon, StartDocumentHandlerUPP userUPP)
    {
        return (ComponentResult)CALL_ONE_PARAMETER_UPP(
            userUPP, uppStartDocumentHandlerProcInfo, refcon);
    }
#else
#define InvokeStartDocumentHandlerUPP(refcon, userUPP) \
    (ComponentResult) CALL_ONE_PARAMETER_UPP(          \
        (userUPP), uppStartDocumentHandlerProcInfo, (refcon))
#endif
#endif

    /**
     *  InvokeEndDocumentHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeEndDocumentHandlerUPP(long refcon, EndDocumentHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult
    InvokeEndDocumentHandlerUPP(long refcon, EndDocumentHandlerUPP userUPP)
    {
        return (ComponentResult)CALL_ONE_PARAMETER_UPP(
            userUPP, uppEndDocumentHandlerProcInfo, refcon);
    }
#else
#define InvokeEndDocumentHandlerUPP(refcon, userUPP) \
    (ComponentResult) CALL_ONE_PARAMETER_UPP(        \
        (userUPP), uppEndDocumentHandlerProcInfo, (refcon))
#endif
#endif

    /**
     *  InvokeStartElementHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeStartElementHandlerUPP(const char *name, const char **atts, long refcon,
                                 StartElementHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult
    InvokeStartElementHandlerUPP(const char *name, const char **atts, long refcon,
                                 StartElementHandlerUPP userUPP)
    {
        return (ComponentResult)CALL_THREE_PARAMETER_UPP(
            userUPP, uppStartElementHandlerProcInfo, name, atts, refcon);
    }
#else
#define InvokeStartElementHandlerUPP(name, atts, refcon, userUPP) \
    (ComponentResult) CALL_THREE_PARAMETER_UPP(                   \
        (userUPP), uppStartElementHandlerProcInfo, (name), (atts), (refcon))
#endif
#endif

    /**
     *  InvokeEndElementHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeEndElementHandlerUPP(const char *name, long refcon,
                               EndElementHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult
    InvokeEndElementHandlerUPP(const char *name, long refcon,
                               EndElementHandlerUPP userUPP)
    {
        return (ComponentResult)CALL_TWO_PARAMETER_UPP(
            userUPP, uppEndElementHandlerProcInfo, name, refcon);
    }
#else
#define InvokeEndElementHandlerUPP(name, refcon, userUPP) \
    (ComponentResult) CALL_TWO_PARAMETER_UPP(             \
        (userUPP), uppEndElementHandlerProcInfo, (name), (refcon))
#endif
#endif

    /**
     *  InvokeCharDataHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeCharDataHandlerUPP(const char *charData, long refcon,
                             CharDataHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult InvokeCharDataHandlerUPP(const char *charData,
                                                    long refcon,
                                                    CharDataHandlerUPP userUPP)
    {
        return (ComponentResult)CALL_TWO_PARAMETER_UPP(
            userUPP, uppCharDataHandlerProcInfo, charData, refcon);
    }
#else
#define InvokeCharDataHandlerUPP(charData, refcon, userUPP) \
    (ComponentResult) CALL_TWO_PARAMETER_UPP(               \
        (userUPP), uppCharDataHandlerProcInfo, (charData), (refcon))
#endif
#endif

    /**
     *  InvokePreprocessInstructionHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokePreprocessInstructionHandlerUPP(const char *name, const char **atts,
                                          long refcon,
                                          PreprocessInstructionHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult
    InvokePreprocessInstructionHandlerUPP(const char *name, const char **atts,
                                          long refcon,
                                          PreprocessInstructionHandlerUPP userUPP)
    {
        return (ComponentResult)CALL_THREE_PARAMETER_UPP(
            userUPP, uppPreprocessInstructionHandlerProcInfo, name, atts, refcon);
    }
#else
#define InvokePreprocessInstructionHandlerUPP(name, atts, refcon, userUPP)  \
    (ComponentResult) CALL_THREE_PARAMETER_UPP(                             \
        (userUPP), uppPreprocessInstructionHandlerProcInfo, (name), (atts), \
        (refcon))
#endif
#endif

    /**
     *  InvokeCommentHandlerUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.3 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeCommentHandlerUPP(const char *comment, long refcon,
                            CommentHandlerUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult InvokeCommentHandlerUPP(const char *comment, long refcon,
                                                   CommentHandlerUPP userUPP)
    {
        return (ComponentResult)CALL_TWO_PARAMETER_UPP(
            userUPP, uppCommentHandlerProcInfo, comment, refcon);
    }
#else
#define InvokeCommentHandlerUPP(comment, refcon, userUPP) \
    (ComponentResult) CALL_TWO_PARAMETER_UPP(             \
        (userUPP), uppCommentHandlerProcInfo, (comment), (refcon))
#endif
#endif

    /**
     *  InvokeSGDataUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    OSErr
    InvokeSGDataUPP(SGChannel c, Ptr p, long len, long *offset, long chRefCon,
                    TimeValue time, short writeType, long refCon,
                    SGDataUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline OSErr InvokeSGDataUPP(SGChannel c, Ptr p, long len, long *offset,
                                 long chRefCon, TimeValue time, short writeType,
                                 long refCon, SGDataUPP userUPP)
    {
        return (OSErr)CALL_EIGHT_PARAMETER_UPP(userUPP, uppSGDataProcInfo, c, p, len,
                                               offset, chRefCon, time, writeType,
                                               refCon);
    }
#else
#define InvokeSGDataUPP(c, p, len, offset, chRefCon, time, writeType, refCon, \
                        userUPP)                                              \
    (OSErr) CALL_EIGHT_PARAMETER_UPP((userUPP), uppSGDataProcInfo, (c), (p),  \
                                     (len), (offset), (chRefCon), (time),     \
                                     (writeType), (refCon))
#endif
#endif

    /**
     *  InvokeSGModalFilterUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    Boolean
    InvokeSGModalFilterUPP(DialogRef theDialog, const EventRecord *theEvent,
                           short *itemHit, long refCon, SGModalFilterUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline Boolean InvokeSGModalFilterUPP(DialogRef theDialog,
                                          const EventRecord *theEvent,
                                          short *itemHit, long refCon,
                                          SGModalFilterUPP userUPP)
    {
        return (Boolean)CALL_FOUR_PARAMETER_UPP(userUPP, uppSGModalFilterProcInfo,
                                                theDialog, theEvent, itemHit, refCon);
    }
#else
#define InvokeSGModalFilterUPP(theDialog, theEvent, itemHit, refCon, userUPP) \
    (Boolean)                                                                 \
        CALL_FOUR_PARAMETER_UPP((userUPP), uppSGModalFilterProcInfo,          \
                                (theDialog), (theEvent), (itemHit), (refCon))
#endif
#endif

    /**
     *  InvokeSGGrabBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeSGGrabBottleUPP(SGChannel c, short bufferNum, long refCon,
                          SGGrabBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult InvokeSGGrabBottleUPP(SGChannel c, short bufferNum,
                                                 long refCon,
                                                 SGGrabBottleUPP userUPP)
    {
        return (ComponentResult)CALL_THREE_PARAMETER_UPP(
            userUPP, uppSGGrabBottleProcInfo, c, bufferNum, refCon);
    }
#else
#define InvokeSGGrabBottleUPP(c, bufferNum, refCon, userUPP) \
    (ComponentResult) CALL_THREE_PARAMETER_UPP(              \
        (userUPP), uppSGGrabBottleProcInfo, (c), (bufferNum), (refCon))
#endif
#endif

    /**
     *  InvokeSGGrabCompleteBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeSGGrabCompleteBottleUPP(SGChannel c, short bufferNum, Boolean *done,
                                  long refCon, SGGrabCompleteBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult
    InvokeSGGrabCompleteBottleUPP(SGChannel c, short bufferNum, Boolean *done,
                                  long refCon, SGGrabCompleteBottleUPP userUPP)
    {
        return (ComponentResult)CALL_FOUR_PARAMETER_UPP(
            userUPP, uppSGGrabCompleteBottleProcInfo, c, bufferNum, done, refCon);
    }
#else
#define InvokeSGGrabCompleteBottleUPP(c, bufferNum, done, refCon, userUPP)       \
    (ComponentResult)                                                            \
        CALL_FOUR_PARAMETER_UPP((userUPP), uppSGGrabCompleteBottleProcInfo, (c), \
                                (bufferNum), (done), (refCon))
#endif
#endif

    /**
     *  InvokeSGDisplayBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeSGDisplayBottleUPP(SGChannel c, short bufferNum, MatrixRecord *mp,
                             RgnHandle clipRgn, long refCon,
                             SGDisplayBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult InvokeSGDisplayBottleUPP(SGChannel c, short bufferNum,
                                                    MatrixRecord *mp,
                                                    RgnHandle clipRgn, long refCon,
                                                    SGDisplayBottleUPP userUPP)
    {
        return (ComponentResult)CALL_FIVE_PARAMETER_UPP(
            userUPP, uppSGDisplayBottleProcInfo, c, bufferNum, mp, clipRgn, refCon);
    }
#else
#define InvokeSGDisplayBottleUPP(c, bufferNum, mp, clipRgn, refCon, userUPP) \
    (ComponentResult)                                                        \
        CALL_FIVE_PARAMETER_UPP((userUPP), uppSGDisplayBottleProcInfo, (c),  \
                                (bufferNum), (mp), (clipRgn), (refCon))
#endif
#endif

    /**
     *  InvokeSGCompressBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeSGCompressBottleUPP(SGChannel c, short bufferNum, long refCon,
                              SGCompressBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult InvokeSGCompressBottleUPP(SGChannel c, short bufferNum,
                                                     long refCon,
                                                     SGCompressBottleUPP userUPP)
    {
        return (ComponentResult)CALL_THREE_PARAMETER_UPP(
            userUPP, uppSGCompressBottleProcInfo, c, bufferNum, refCon);
    }
#else
#define InvokeSGCompressBottleUPP(c, bufferNum, refCon, userUPP) \
    (ComponentResult) CALL_THREE_PARAMETER_UPP(                  \
        (userUPP), uppSGCompressBottleProcInfo, (c), (bufferNum), (refCon))
#endif
#endif

    /**
     *  InvokeSGCompressCompleteBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeSGCompressCompleteBottleUPP(SGChannel c, short bufferNum, Boolean *done,
                                      SGCompressInfo *ci, long refCon,
                                      SGCompressCompleteBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult
    InvokeSGCompressCompleteBottleUPP(SGChannel c, short bufferNum, Boolean *done,
                                      SGCompressInfo *ci, long refCon,
                                      SGCompressCompleteBottleUPP userUPP)
    {
        return (ComponentResult)CALL_FIVE_PARAMETER_UPP(
            userUPP, uppSGCompressCompleteBottleProcInfo, c, bufferNum, done, ci,
            refCon);
    }
#else
#define InvokeSGCompressCompleteBottleUPP(c, bufferNum, done, ci, refCon,       \
                                          userUPP)                              \
    (ComponentResult)                                                           \
        CALL_FIVE_PARAMETER_UPP((userUPP), uppSGCompressCompleteBottleProcInfo, \
                                (c), (bufferNum), (done), (ci), (refCon))
#endif
#endif

    /**
     *  InvokeSGAddFrameBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeSGAddFrameBottleUPP(SGChannel c, short bufferNum, TimeValue atTime,
                              TimeScale scale, const SGCompressInfo *ci,
                              long refCon, SGAddFrameBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult
    InvokeSGAddFrameBottleUPP(SGChannel c, short bufferNum, TimeValue atTime,
                              TimeScale scale, const SGCompressInfo *ci,
                              long refCon, SGAddFrameBottleUPP userUPP)
    {
        return (ComponentResult)CALL_SIX_PARAMETER_UPP(
            userUPP, uppSGAddFrameBottleProcInfo, c, bufferNum, atTime, scale, ci,
            refCon);
    }
#else
#define InvokeSGAddFrameBottleUPP(c, bufferNum, atTime, scale, ci, refCon,  \
                                  userUPP)                                  \
    (ComponentResult)                                                       \
        CALL_SIX_PARAMETER_UPP((userUPP), uppSGAddFrameBottleProcInfo, (c), \
                               (bufferNum), (atTime), (scale), (ci), (refCon))
#endif
#endif

    /**
     *  InvokeSGTransferFrameBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeSGTransferFrameBottleUPP(SGChannel c, short bufferNum, MatrixRecord *mp,
                                   RgnHandle clipRgn, long refCon,
                                   SGTransferFrameBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult
    InvokeSGTransferFrameBottleUPP(SGChannel c, short bufferNum, MatrixRecord *mp,
                                   RgnHandle clipRgn, long refCon,
                                   SGTransferFrameBottleUPP userUPP)
    {
        return (ComponentResult)CALL_FIVE_PARAMETER_UPP(
            userUPP, uppSGTransferFrameBottleProcInfo, c, bufferNum, mp, clipRgn,
            refCon);
    }
#else
#define InvokeSGTransferFrameBottleUPP(c, bufferNum, mp, clipRgn, refCon,    \
                                       userUPP)                              \
    (ComponentResult)                                                        \
        CALL_FIVE_PARAMETER_UPP((userUPP), uppSGTransferFrameBottleProcInfo, \
                                (c), (bufferNum), (mp), (clipRgn), (refCon))
#endif
#endif

    /**
     *  InvokeSGGrabCompressCompleteBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeSGGrabCompressCompleteBottleUPP(SGChannel c, Boolean *done,
                                          SGCompressInfo *ci, TimeRecord *t,
                                          long refCon,
                                          SGGrabCompressCompleteBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult InvokeSGGrabCompressCompleteBottleUPP(
        SGChannel c, Boolean *done, SGCompressInfo *ci, TimeRecord *t, long refCon,
        SGGrabCompressCompleteBottleUPP userUPP)
    {
        return (ComponentResult)CALL_FIVE_PARAMETER_UPP(
            userUPP, uppSGGrabCompressCompleteBottleProcInfo, c, done, ci, t, refCon);
    }
#else
#define InvokeSGGrabCompressCompleteBottleUPP(c, done, ci, t, refCon, userUPP) \
    (ComponentResult) CALL_FIVE_PARAMETER_UPP(                                 \
        (userUPP), uppSGGrabCompressCompleteBottleProcInfo, (c), (done), (ci), \
        (t), (refCon))
#endif
#endif

    /**
     *  InvokeSGDisplayCompressBottleUPP()
     *

     *    \non_carbon_cfm   available as macro/inline
     *    \carbon_lib        in CarbonLib 1.0 and later
     *    \mac_os_x         in version 10.0 and later
     */
    ComponentResult
    InvokeSGDisplayCompressBottleUPP(SGChannel c, Ptr dataPtr,
                                     ImageDescriptionHandle desc, MatrixRecord *mp,
                                     RgnHandle clipRgn, long refCon,
                                     SGDisplayCompressBottleUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
    inline ComponentResult InvokeSGDisplayCompressBottleUPP(
        SGChannel c, Ptr dataPtr, ImageDescriptionHandle desc, MatrixRecord *mp,
        RgnHandle clipRgn, long refCon, SGDisplayCompressBottleUPP userUPP)
    {
        return (ComponentResult)CALL_SIX_PARAMETER_UPP(
            userUPP, uppSGDisplayCompressBottleProcInfo, c, dataPtr, desc, mp,
            clipRgn, refCon);
    }
#else
#define InvokeSGDisplayCompressBottleUPP(c, dataPtr, desc, mp, clipRgn,        \
                                         refCon, userUPP)                      \
    (ComponentResult) CALL_SIX_PARAMETER_UPP(                                  \
        (userUPP), uppSGDisplayCompressBottleProcInfo, (c), (dataPtr), (desc), \
        (mp), (clipRgn), (refCon))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewDataHCompletionProc(userRoutine) NewDataHCompletionUPP(userRoutine)
#define NewVdigIntProc(userRoutine) NewVdigIntUPP(userRoutine)
#define NewStartDocumentHandlerProc(userRoutine) \
    NewStartDocumentHandlerUPP(userRoutine)
#define NewEndDocumentHandlerProc(userRoutine) \
    NewEndDocumentHandlerUPP(userRoutine)
#define NewStartElementHandlerProc(userRoutine) \
    NewStartElementHandlerUPP(userRoutine)
#define NewEndElementHandlerProc(userRoutine) \
    NewEndElementHandlerUPP(userRoutine)
#define NewCharDataHandlerProc(userRoutine) NewCharDataHandlerUPP(userRoutine)
#define NewPreprocessInstructionHandlerProc(userRoutine) \
    NewPreprocessInstructionHandlerUPP(userRoutine)
#define NewCommentHandlerProc(userRoutine) NewCommentHandlerUPP(userRoutine)
#define NewSGDataProc(userRoutine) NewSGDataUPP(userRoutine)
#define NewSGModalFilterProc(userRoutine) NewSGModalFilterUPP(userRoutine)
#define NewSGGrabBottleProc(userRoutine) NewSGGrabBottleUPP(userRoutine)
#define NewSGGrabCompleteBottleProc(userRoutine) \
    NewSGGrabCompleteBottleUPP(userRoutine)
#define NewSGDisplayBottleProc(userRoutine) NewSGDisplayBottleUPP(userRoutine)
#define NewSGCompressBottleProc(userRoutine) NewSGCompressBottleUPP(userRoutine)
#define NewSGCompressCompleteBottleProc(userRoutine) \
    NewSGCompressCompleteBottleUPP(userRoutine)
#define NewSGAddFrameBottleProc(userRoutine) NewSGAddFrameBottleUPP(userRoutine)
#define NewSGTransferFrameBottleProc(userRoutine) \
    NewSGTransferFrameBottleUPP(userRoutine)
#define NewSGGrabCompressCompleteBottleProc(userRoutine) \
    NewSGGrabCompressCompleteBottleUPP(userRoutine)
#define NewSGDisplayCompressBottleProc(userRoutine) \
    NewSGDisplayCompressBottleUPP(userRoutine)
#define CallDataHCompletionProc(userRoutine, request, refcon, err) \
    InvokeDataHCompletionUPP(request, refcon, err, userRoutine)
#define CallVdigIntProc(userRoutine, flags, refcon) \
    InvokeVdigIntUPP(flags, refcon, userRoutine)
#define CallStartDocumentHandlerProc(userRoutine, refcon) \
    InvokeStartDocumentHandlerUPP(refcon, userRoutine)
#define CallEndDocumentHandlerProc(userRoutine, refcon) \
    InvokeEndDocumentHandlerUPP(refcon, userRoutine)
#define CallStartElementHandlerProc(userRoutine, name, atts, refcon) \
    InvokeStartElementHandlerUPP(name, atts, refcon, userRoutine)
#define CallEndElementHandlerProc(userRoutine, name, refcon) \
    InvokeEndElementHandlerUPP(name, refcon, userRoutine)
#define CallCharDataHandlerProc(userRoutine, charData, refcon) \
    InvokeCharDataHandlerUPP(charData, refcon, userRoutine)
#define CallPreprocessInstructionHandlerProc(userRoutine, name, atts, refcon) \
    InvokePreprocessInstructionHandlerUPP(name, atts, refcon, userRoutine)
#define CallCommentHandlerProc(userRoutine, comment, refcon) \
    InvokeCommentHandlerUPP(comment, refcon, userRoutine)
#define CallSGDataProc(userRoutine, c, p, len, offset, chRefCon, time,    \
                       writeType, refCon)                                 \
    InvokeSGDataUPP(c, p, len, offset, chRefCon, time, writeType, refCon, \
                    userRoutine)
#define CallSGModalFilterProc(userRoutine, theDialog, theEvent, itemHit, \
                              refCon)                                    \
    InvokeSGModalFilterUPP(theDialog, theEvent, itemHit, refCon, userRoutine)
#define CallSGGrabBottleProc(userRoutine, c, bufferNum, refCon) \
    InvokeSGGrabBottleUPP(c, bufferNum, refCon, userRoutine)
#define CallSGGrabCompleteBottleProc(userRoutine, c, bufferNum, done, refCon) \
    InvokeSGGrabCompleteBottleUPP(c, bufferNum, done, refCon, userRoutine)
#define CallSGDisplayBottleProc(userRoutine, c, bufferNum, mp, clipRgn, \
                                refCon)                                 \
    InvokeSGDisplayBottleUPP(c, bufferNum, mp, clipRgn, refCon, userRoutine)
#define CallSGCompressBottleProc(userRoutine, c, bufferNum, refCon) \
    InvokeSGCompressBottleUPP(c, bufferNum, refCon, userRoutine)
#define CallSGCompressCompleteBottleProc(userRoutine, c, bufferNum, done, ci, \
                                         refCon)                              \
    InvokeSGCompressCompleteBottleUPP(c, bufferNum, done, ci, refCon, userRoutine)
#define CallSGAddFrameBottleProc(userRoutine, c, bufferNum, atTime, scale, ci, \
                                 refCon)                                       \
    InvokeSGAddFrameBottleUPP(c, bufferNum, atTime, scale, ci, refCon,         \
                              userRoutine)
#define CallSGTransferFrameBottleProc(userRoutine, c, bufferNum, mp, clipRgn, \
                                      refCon)                                 \
    InvokeSGTransferFrameBottleUPP(c, bufferNum, mp, clipRgn, refCon, userRoutine)
#define CallSGGrabCompressCompleteBottleProc(userRoutine, c, done, ci, t, \
                                             refCon)                      \
    InvokeSGGrabCompressCompleteBottleUPP(c, done, ci, t, refCon, userRoutine)
#define CallSGDisplayCompressBottleProc(userRoutine, c, dataPtr, desc, mp,  \
                                        clipRgn, refCon)                    \
    InvokeSGDisplayCompressBottleUPP(c, dataPtr, desc, mp, clipRgn, refCon, \
                                     userRoutine)
#endif /** CALL_NOT_IN_CARBON */

    /** selectors for component calls */
    enum
    {
        kClockGetTimeSelect = 0x0001,
        kClockNewCallBackSelect = 0x0002,
        kClockDisposeCallBackSelect = 0x0003,
        kClockCallMeWhenSelect = 0x0004,
        kClockCancelCallBackSelect = 0x0005,
        kClockRateChangedSelect = 0x0006,
        kClockTimeChangedSelect = 0x0007,
        kClockSetTimeBaseSelect = 0x0008,
        kClockStartStopChangedSelect = 0x0009,
        kClockGetRateSelect = 0x000A,
        kSCGetCompressionExtendedSelect = 0x0001,
        kSCPositionRectSelect = 0x0002,
        kSCPositionDialogSelect = 0x0003,
        kSCSetTestImagePictHandleSelect = 0x0004,
        kSCSetTestImagePictFileSelect = 0x0005,
        kSCSetTestImagePixMapSelect = 0x0006,
        kSCGetBestDeviceRectSelect = 0x0007,
        kSCRequestImageSettingsSelect = 0x000A,
        kSCCompressImageSelect = 0x000B,
        kSCCompressPictureSelect = 0x000C,
        kSCCompressPictureFileSelect = 0x000D,
        kSCRequestSequenceSettingsSelect = 0x000E,
        kSCCompressSequenceBeginSelect = 0x000F,
        kSCCompressSequenceFrameSelect = 0x0010,
        kSCCompressSequenceEndSelect = 0x0011,
        kSCDefaultPictHandleSettingsSelect = 0x0012,
        kSCDefaultPictFileSettingsSelect = 0x0013,
        kSCDefaultPixMapSettingsSelect = 0x0014,
        kSCGetInfoSelect = 0x0015,
        kSCSetInfoSelect = 0x0016,
        kSCNewGWorldSelect = 0x0017,
        kSCSetCompressFlagsSelect = 0x0018,
        kSCGetCompressFlagsSelect = 0x0019,
        kSCGetSettingsAsTextSelect = 0x001A,
        kSCGetSettingsAsAtomContainerSelect = 0x001B,
        kSCSetSettingsFromAtomContainerSelect = 0x001C,
        kSCCompressSequenceFrameAsyncSelect = 0x001D,
        kSCAsyncIdleSelect = 0x001E,
        kTweenerInitializeSelect = 0x0001,
        kTweenerDoTweenSelect = 0x0002,
        kTweenerResetSelect = 0x0003,
        kTCGetCurrentTimeCodeSelect = 0x0101,
        kTCGetTimeCodeAtTimeSelect = 0x0102,
        kTCTimeCodeToStringSelect = 0x0103,
        kTCTimeCodeToFrameNumberSelect = 0x0104,
        kTCFrameNumberToTimeCodeSelect = 0x0105,
        kTCGetSourceRefSelect = 0x0106,
        kTCSetSourceRefSelect = 0x0107,
        kTCSetTimeCodeFlagsSelect = 0x0108,
        kTCGetTimeCodeFlagsSelect = 0x0109,
        kTCSetDisplayOptionsSelect = 0x010A,
        kTCGetDisplayOptionsSelect = 0x010B,
        kMovieImportHandleSelect = 0x0001,
        kMovieImportFileSelect = 0x0002,
        kMovieImportSetSampleDurationSelect = 0x0003,
        kMovieImportSetSampleDescriptionSelect = 0x0004,
        kMovieImportSetMediaFileSelect = 0x0005,
        kMovieImportSetDimensionsSelect = 0x0006,
        kMovieImportSetChunkSizeSelect = 0x0007,
        kMovieImportSetProgressProcSelect = 0x0008,
        kMovieImportSetAuxiliaryDataSelect = 0x0009,
        kMovieImportSetFromScrapSelect = 0x000A,
        kMovieImportDoUserDialogSelect = 0x000B,
        kMovieImportSetDurationSelect = 0x000C,
        kMovieImportGetAuxiliaryDataTypeSelect = 0x000D,
        kMovieImportValidateSelect = 0x000E,
        kMovieImportGetFileTypeSelect = 0x000F,
        kMovieImportDataRefSelect = 0x0010,
        kMovieImportGetSampleDescriptionSelect = 0x0011,
        kMovieImportGetMIMETypeListSelect = 0x0012,
        kMovieImportSetOffsetAndLimitSelect = 0x0013,
        kMovieImportGetSettingsAsAtomContainerSelect = 0x0014,
        kMovieImportSetSettingsFromAtomContainerSelect = 0x0015,
        kMovieImportSetOffsetAndLimit64Select = 0x0016,
        kMovieImportIdleSelect = 0x0017,
        kMovieImportValidateDataRefSelect = 0x0018,
        kMovieImportGetLoadStateSelect = 0x0019,
        kMovieImportGetMaxLoadedTimeSelect = 0x001A,
        kMovieImportEstimateCompletionTimeSelect = 0x001B,
        kMovieImportSetDontBlockSelect = 0x001C,
        kMovieImportGetDontBlockSelect = 0x001D,
        kMovieExportToHandleSelect = 0x0080,
        kMovieExportToFileSelect = 0x0081,
        kMovieExportGetAuxiliaryDataSelect = 0x0083,
        kMovieExportSetProgressProcSelect = 0x0084,
        kMovieExportSetSampleDescriptionSelect = 0x0085,
        kMovieExportDoUserDialogSelect = 0x0086,
        kMovieExportGetCreatorTypeSelect = 0x0087,
        kMovieExportToDataRefSelect = 0x0088,
        kMovieExportFromProceduresToDataRefSelect = 0x0089,
        kMovieExportAddDataSourceSelect = 0x008A,
        kMovieExportValidateSelect = 0x008B,
        kMovieExportGetSettingsAsAtomContainerSelect = 0x008C,
        kMovieExportSetSettingsFromAtomContainerSelect = 0x008D,
        kMovieExportGetFileNameExtensionSelect = 0x008E,
        kMovieExportGetShortFileTypeStringSelect = 0x008F,
        kMovieExportGetSourceMediaTypeSelect = 0x0090,
        kMovieExportSetGetMoviePropertyProcSelect = 0x0091,
        kTextExportGetDisplayDataSelect = 0x0100,
        kTextExportGetTimeFractionSelect = 0x0101,
        kTextExportSetTimeFractionSelect = 0x0102,
        kTextExportGetSettingsSelect = 0x0103,
        kTextExportSetSettingsSelect = 0x0104,
        kMIDIImportGetSettingsSelect = 0x0100,
        kMIDIImportSetSettingsSelect = 0x0101,
        kMovieExportNewGetDataAndPropertiesProcsSelect = 0x0100,
        kMovieExportDisposeGetDataAndPropertiesProcsSelect = 0x0101,
        kGraphicsImageImportSetSequenceEnabledSelect = 0x0100,
        kGraphicsImageImportGetSequenceEnabledSelect = 0x0101,
        kPreviewShowDataSelect = 0x0001,
        kPreviewMakePreviewSelect = 0x0002,
        kPreviewMakePreviewReferenceSelect = 0x0003,
        kPreviewEventSelect = 0x0004,
        kDataCodecDecompressSelect = 0x0001,
        kDataCodecGetCompressBufferSizeSelect = 0x0002,
        kDataCodecCompressSelect = 0x0003,
        kDataCodecBeginInterruptSafeSelect = 0x0004,
        kDataCodecEndInterruptSafeSelect = 0x0005,
        kDataCodecDecompressPartialSelect = 0x0006,
        kDataCodecCompressPartialSelect = 0x0007,
        kDataHGetDataSelect = 0x0002,
        kDataHPutDataSelect = 0x0003,
        kDataHFlushDataSelect = 0x0004,
        kDataHOpenForWriteSelect = 0x0005,
        kDataHCloseForWriteSelect = 0x0006,
        kDataHOpenForReadSelect = 0x0008,
        kDataHCloseForReadSelect = 0x0009,
        kDataHSetDataRefSelect = 0x000A,
        kDataHGetDataRefSelect = 0x000B,
        kDataHCompareDataRefSelect = 0x000C,
        kDataHTaskSelect = 0x000D,
        kDataHScheduleDataSelect = 0x000E,
        kDataHFinishDataSelect = 0x000F,
        kDataHFlushCacheSelect = 0x0010,
        kDataHResolveDataRefSelect = 0x0011,
        kDataHGetFileSizeSelect = 0x0012,
        kDataHCanUseDataRefSelect = 0x0013,
        kDataHGetVolumeListSelect = 0x0014,
        kDataHWriteSelect = 0x0015,
        kDataHPreextendSelect = 0x0016,
        kDataHSetFileSizeSelect = 0x0017,
        kDataHGetFreeSpaceSelect = 0x0018,
        kDataHCreateFileSelect = 0x0019,
        kDataHGetPreferredBlockSizeSelect = 0x001A,
        kDataHGetDeviceIndexSelect = 0x001B,
        kDataHIsStreamingDataHandlerSelect = 0x001C,
        kDataHGetDataInBufferSelect = 0x001D,
        kDataHGetScheduleAheadTimeSelect = 0x001E,
        kDataHSetCacheSizeLimitSelect = 0x001F,
        kDataHGetCacheSizeLimitSelect = 0x0020,
        kDataHGetMovieSelect = 0x0021,
        kDataHAddMovieSelect = 0x0022,
        kDataHUpdateMovieSelect = 0x0023,
        kDataHDoesBufferSelect = 0x0024,
        kDataHGetFileNameSelect = 0x0025,
        kDataHGetAvailableFileSizeSelect = 0x0026,
        kDataHGetMacOSFileTypeSelect = 0x0027,
        kDataHGetMIMETypeSelect = 0x0028,
        kDataHSetDataRefWithAnchorSelect = 0x0029,
        kDataHGetDataRefWithAnchorSelect = 0x002A,
        kDataHSetMacOSFileTypeSelect = 0x002B,
        kDataHSetTimeBaseSelect = 0x002C,
        kDataHGetInfoFlagsSelect = 0x002D,
        kDataHScheduleData64Select = 0x002E,
        kDataHWrite64Select = 0x002F,
        kDataHGetFileSize64Select = 0x0030,
        kDataHPreextend64Select = 0x0031,
        kDataHSetFileSize64Select = 0x0032,
        kDataHGetFreeSpace64Select = 0x0033,
        kDataHAppend64Select = 0x0034,
        kDataHReadAsyncSelect = 0x0035,
        kDataHPollReadSelect = 0x0036,
        kDataHGetDataAvailabilitySelect = 0x0037,
        kDataHGetFileSizeAsyncSelect = 0x003A,
        kDataHGetDataRefAsTypeSelect = 0x003B,
        kDataHSetDataRefExtensionSelect = 0x003C,
        kDataHGetDataRefExtensionSelect = 0x003D,
        kDataHGetMovieWithFlagsSelect = 0x003E,
        kDataHGetFileTypeOrderingSelect = 0x0040,
        kDataHCreateFileWithFlagsSelect = 0x0041,
        kDataHGetMIMETypeAsyncSelect = 0x0042,
        kDataHGetInfoSelect = 0x0043,
        kDataHPlaybackHintsSelect = 0x0103,
        kDataHPlaybackHints64Select = 0x010E,
        kDataHGetDataRateSelect = 0x0110,
        kDataHSetTimeHintsSelect = 0x0111,
        kVDGetMaxSrcRectSelect = 0x0001,
        kVDGetActiveSrcRectSelect = 0x0002,
        kVDSetDigitizerRectSelect = 0x0003,
        kVDGetDigitizerRectSelect = 0x0004,
        kVDGetVBlankRectSelect = 0x0005,
        kVDGetMaskPixMapSelect = 0x0006,
        kVDGetPlayThruDestinationSelect = 0x0008,
        kVDUseThisCLUTSelect = 0x0009,
        kVDSetInputGammaValueSelect = 0x000A,
        kVDGetInputGammaValueSelect = 0x000B,
        kVDSetBrightnessSelect = 0x000C,
        kVDGetBrightnessSelect = 0x000D,
        kVDSetContrastSelect = 0x000E,
        kVDSetHueSelect = 0x000F,
        kVDSetSharpnessSelect = 0x0010,
        kVDSetSaturationSelect = 0x0011,
        kVDGetContrastSelect = 0x0012,
        kVDGetHueSelect = 0x0013,
        kVDGetSharpnessSelect = 0x0014,
        kVDGetSaturationSelect = 0x0015,
        kVDGrabOneFrameSelect = 0x0016,
        kVDGetMaxAuxBufferSelect = 0x0017,
        kVDGetDigitizerInfoSelect = 0x0019,
        kVDGetCurrentFlagsSelect = 0x001A,
        kVDSetKeyColorSelect = 0x001B,
        kVDGetKeyColorSelect = 0x001C,
        kVDAddKeyColorSelect = 0x001D,
        kVDGetNextKeyColorSelect = 0x001E,
        kVDSetKeyColorRangeSelect = 0x001F,
        kVDGetKeyColorRangeSelect = 0x0020,
        kVDSetDigitizerUserInterruptSelect = 0x0021,
        kVDSetInputColorSpaceModeSelect = 0x0022,
        kVDGetInputColorSpaceModeSelect = 0x0023,
        kVDSetClipStateSelect = 0x0024,
        kVDGetClipStateSelect = 0x0025,
        kVDSetClipRgnSelect = 0x0026,
        kVDClearClipRgnSelect = 0x0027,
        kVDGetCLUTInUseSelect = 0x0028,
        kVDSetPLLFilterTypeSelect = 0x0029,
        kVDGetPLLFilterTypeSelect = 0x002A,
        kVDGetMaskandValueSelect = 0x002B,
        kVDSetMasterBlendLevelSelect = 0x002C,
        kVDSetPlayThruDestinationSelect = 0x002D,
        kVDSetPlayThruOnOffSelect = 0x002E,
        kVDSetFieldPreferenceSelect = 0x002F,
        kVDGetFieldPreferenceSelect = 0x0030,
        kVDPreflightDestinationSelect = 0x0032,
        kVDPreflightGlobalRectSelect = 0x0033,
        kVDSetPlayThruGlobalRectSelect = 0x0034,
        kVDSetInputGammaRecordSelect = 0x0035,
        kVDGetInputGammaRecordSelect = 0x0036,
        kVDSetBlackLevelValueSelect = 0x0037,
        kVDGetBlackLevelValueSelect = 0x0038,
        kVDSetWhiteLevelValueSelect = 0x0039,
        kVDGetWhiteLevelValueSelect = 0x003A,
        kVDGetVideoDefaultsSelect = 0x003B,
        kVDGetNumberOfInputsSelect = 0x003C,
        kVDGetInputFormatSelect = 0x003D,
        kVDSetInputSelect = 0x003E,
        kVDGetInputSelect = 0x003F,
        kVDSetInputStandardSelect = 0x0040,
        kVDSetupBuffersSelect = 0x0041,
        kVDGrabOneFrameAsyncSelect = 0x0042,
        kVDDoneSelect = 0x0043,
        kVDSetCompressionSelect = 0x0044,
        kVDCompressOneFrameAsyncSelect = 0x0045,
        kVDCompressDoneSelect = 0x0046,
        kVDReleaseCompressBufferSelect = 0x0047,
        kVDGetImageDescriptionSelect = 0x0048,
        kVDResetCompressSequenceSelect = 0x0049,
        kVDSetCompressionOnOffSelect = 0x004A,
        kVDGetCompressionTypesSelect = 0x004B,
        kVDSetTimeBaseSelect = 0x004C,
        kVDSetFrameRateSelect = 0x004D,
        kVDGetDataRateSelect = 0x004E,
        kVDGetSoundInputDriverSelect = 0x004F,
        kVDGetDMADepthsSelect = 0x0050,
        kVDGetPreferredTimeScaleSelect = 0x0051,
        kVDReleaseAsyncBuffersSelect = 0x0052,
        kVDSetDataRateSelect = 0x0054,
        kVDGetTimeCodeSelect = 0x0055,
        kVDUseSafeBuffersSelect = 0x0056,
        kVDGetSoundInputSourceSelect = 0x0057,
        kVDGetCompressionTimeSelect = 0x0058,
        kVDSetPreferredPacketSizeSelect = 0x0059,
        kVDSetPreferredImageDimensionsSelect = 0x005A,
        kVDGetPreferredImageDimensionsSelect = 0x005B,
        kVDGetInputNameSelect = 0x005C,
        kVDSetDestinationPortSelect = 0x005D,
        kXMLParseDataRefSelect = 0x0001,
        kXMLParseFileSelect = 0x0002,
        kXMLParseDisposeXMLDocSelect = 0x0003,
        kXMLParseGetDetailedParseErrorSelect = 0x0004,
        kXMLParseAddElementSelect = 0x0005,
        kXMLParseAddAttributeSelect = 0x0006,
        kXMLParseAddMultipleAttributesSelect = 0x0007,
        kXMLParseAddAttributeAndValueSelect = 0x0008,
        kXMLParseAddMultipleAttributesAndValuesSelect = 0x0009,
        kXMLParseAddAttributeValueKindSelect = 0x000A,
        kXMLParseAddNameSpaceSelect = 0x000B,
        kXMLParseSetOffsetAndLimitSelect = 0x000C,
        kXMLParseSetEventParseRefConSelect = 0x000D,
        kXMLParseSetStartDocumentHandlerSelect = 0x000E,
        kXMLParseSetEndDocumentHandlerSelect = 0x000F,
        kXMLParseSetStartElementHandlerSelect = 0x0010,
        kXMLParseSetEndElementHandlerSelect = 0x0011,
        kXMLParseSetCharDataHandlerSelect = 0x0012,
        kXMLParseSetPreprocessInstructionHandlerSelect = 0x0013,
        kXMLParseSetCommentHandlerSelect = 0x0014,
        kSGInitializeSelect = 0x0001,
        kSGSetDataOutputSelect = 0x0002,
        kSGGetDataOutputSelect = 0x0003,
        kSGSetGWorldSelect = 0x0004,
        kSGGetGWorldSelect = 0x0005,
        kSGNewChannelSelect = 0x0006,
        kSGDisposeChannelSelect = 0x0007,
        kSGStartPreviewSelect = 0x0010,
        kSGStartRecordSelect = 0x0011,
        kSGIdleSelect = 0x0012,
        kSGStopSelect = 0x0013,
        kSGPauseSelect = 0x0014,
        kSGPrepareSelect = 0x0015,
        kSGReleaseSelect = 0x0016,
        kSGGetMovieSelect = 0x0017,
        kSGSetMaximumRecordTimeSelect = 0x0018,
        kSGGetMaximumRecordTimeSelect = 0x0019,
        kSGGetStorageSpaceRemainingSelect = 0x001A,
        kSGGetTimeRemainingSelect = 0x001B,
        kSGGrabPictSelect = 0x001C,
        kSGGetLastMovieResIDSelect = 0x001D,
        kSGSetFlagsSelect = 0x001E,
        kSGGetFlagsSelect = 0x001F,
        kSGSetDataProcSelect = 0x0020,
        kSGNewChannelFromComponentSelect = 0x0021,
        kSGDisposeDeviceListSelect = 0x0022,
        kSGAppendDeviceListToMenuSelect = 0x0023,
        kSGSetSettingsSelect = 0x0024,
        kSGGetSettingsSelect = 0x0025,
        kSGGetIndChannelSelect = 0x0026,
        kSGUpdateSelect = 0x0027,
        kSGGetPauseSelect = 0x0028,
        kSGSettingsDialogSelect = 0x0029,
        kSGGetAlignmentProcSelect = 0x002A,
        kSGSetChannelSettingsSelect = 0x002B,
        kSGGetChannelSettingsSelect = 0x002C,
        kSGGetModeSelect = 0x002D,
        kSGSetDataRefSelect = 0x002E,
        kSGGetDataRefSelect = 0x002F,
        kSGNewOutputSelect = 0x0030,
        kSGDisposeOutputSelect = 0x0031,
        kSGSetOutputFlagsSelect = 0x0032,
        kSGSetChannelOutputSelect = 0x0033,
        kSGGetDataOutputStorageSpaceRemainingSelect = 0x0034,
        kSGHandleUpdateEventSelect = 0x0035,
        kSGSetOutputNextOutputSelect = 0x0036,
        kSGGetOutputNextOutputSelect = 0x0037,
        kSGSetOutputMaximumOffsetSelect = 0x0038,
        kSGGetOutputMaximumOffsetSelect = 0x0039,
        kSGGetOutputDataReferenceSelect = 0x003A,
        kSGWriteExtendedMovieDataSelect = 0x003B,
        kSGGetStorageSpaceRemaining64Select = 0x003C,
        kSGGetDataOutputStorageSpaceRemaining64Select = 0x003D,
        kSGWriteMovieDataSelect = 0x0100,
        kSGAddFrameReferenceSelect = 0x0101,
        kSGGetNextFrameReferenceSelect = 0x0102,
        kSGGetTimeBaseSelect = 0x0103,
        kSGSortDeviceListSelect = 0x0104,
        kSGAddMovieDataSelect = 0x0105,
        kSGChangedSourceSelect = 0x0106,
        kSGAddExtendedFrameReferenceSelect = 0x0107,
        kSGGetNextExtendedFrameReferenceSelect = 0x0108,
        kSGAddExtendedMovieDataSelect = 0x0109,
        kSGAddOutputDataRefToMediaSelect = 0x010A,
        kSGSetChannelUsageSelect = 0x0080,
        kSGGetChannelUsageSelect = 0x0081,
        kSGSetChannelBoundsSelect = 0x0082,
        kSGGetChannelBoundsSelect = 0x0083,
        kSGSetChannelVolumeSelect = 0x0084,
        kSGGetChannelVolumeSelect = 0x0085,
        kSGGetChannelInfoSelect = 0x0086,
        kSGSetChannelPlayFlagsSelect = 0x0087,
        kSGGetChannelPlayFlagsSelect = 0x0088,
        kSGSetChannelMaxFramesSelect = 0x0089,
        kSGGetChannelMaxFramesSelect = 0x008A,
        kSGSetChannelRefConSelect = 0x008B,
        kSGSetChannelClipSelect = 0x008C,
        kSGGetChannelClipSelect = 0x008D,
        kSGGetChannelSampleDescriptionSelect = 0x008E,
        kSGGetChannelDeviceListSelect = 0x008F,
        kSGSetChannelDeviceSelect = 0x0090,
        kSGSetChannelMatrixSelect = 0x0091,
        kSGGetChannelMatrixSelect = 0x0092,
        kSGGetChannelTimeScaleSelect = 0x0093,
        kSGChannelPutPictureSelect = 0x0094,
        kSGChannelSetRequestedDataRateSelect = 0x0095,
        kSGChannelGetRequestedDataRateSelect = 0x0096,
        kSGChannelSetDataSourceNameSelect = 0x0097,
        kSGChannelGetDataSourceNameSelect = 0x0098,
        kSGChannelSetCodecSettingsSelect = 0x0099,
        kSGChannelGetCodecSettingsSelect = 0x009A,
        kSGGetChannelTimeBaseSelect = 0x009B,
        kSGInitChannelSelect = 0x0180,
        kSGWriteSamplesSelect = 0x0181,
        kSGGetDataRateSelect = 0x0182,
        kSGAlignChannelRectSelect = 0x0183,
        kSGPanelGetDitlSelect = 0x0200,
        kSGPanelGetTitleSelect = 0x0201,
        kSGPanelCanRunSelect = 0x0202,
        kSGPanelInstallSelect = 0x0203,
        kSGPanelEventSelect = 0x0204,
        kSGPanelItemSelect = 0x0205,
        kSGPanelRemoveSelect = 0x0206,
        kSGPanelSetGrabberSelect = 0x0207,
        kSGPanelSetResFileSelect = 0x0208,
        kSGPanelGetSettingsSelect = 0x0209,
        kSGPanelSetSettingsSelect = 0x020A,
        kSGPanelValidateInputSelect = 0x020B,
        kSGPanelSetEventFilterSelect = 0x020C,
        kSGGetSrcVideoBoundsSelect = 0x0100,
        kSGSetVideoRectSelect = 0x0101,
        kSGGetVideoRectSelect = 0x0102,
        kSGGetVideoCompressorTypeSelect = 0x0103,
        kSGSetVideoCompressorTypeSelect = 0x0104,
        kSGSetVideoCompressorSelect = 0x0105,
        kSGGetVideoCompressorSelect = 0x0106,
        kSGGetVideoDigitizerComponentSelect = 0x0107,
        kSGSetVideoDigitizerComponentSelect = 0x0108,
        kSGVideoDigitizerChangedSelect = 0x0109,
        kSGSetVideoBottlenecksSelect = 0x010A,
        kSGGetVideoBottlenecksSelect = 0x010B,
        kSGGrabFrameSelect = 0x010C,
        kSGGrabFrameCompleteSelect = 0x010D,
        kSGDisplayFrameSelect = 0x010E,
        kSGCompressFrameSelect = 0x010F,
        kSGCompressFrameCompleteSelect = 0x0110,
        kSGAddFrameSelect = 0x0111,
        kSGTransferFrameForCompressSelect = 0x0112,
        kSGSetCompressBufferSelect = 0x0113,
        kSGGetCompressBufferSelect = 0x0114,
        kSGGetBufferInfoSelect = 0x0115,
        kSGSetUseScreenBufferSelect = 0x0116,
        kSGGetUseScreenBufferSelect = 0x0117,
        kSGGrabCompressCompleteSelect = 0x0118,
        kSGDisplayCompressSelect = 0x0119,
        kSGSetFrameRateSelect = 0x011A,
        kSGGetFrameRateSelect = 0x011B,
        kSGSetPreferredPacketSizeSelect = 0x0121,
        kSGGetPreferredPacketSizeSelect = 0x0122,
        kSGSetUserVideoCompressorListSelect = 0x0123,
        kSGGetUserVideoCompressorListSelect = 0x0124,
        kSGSetSoundInputDriverSelect = 0x0100,
        kSGGetSoundInputDriverSelect = 0x0101,
        kSGSoundInputDriverChangedSelect = 0x0102,
        kSGSetSoundRecordChunkSizeSelect = 0x0103,
        kSGGetSoundRecordChunkSizeSelect = 0x0104,
        kSGSetSoundInputRateSelect = 0x0105,
        kSGGetSoundInputRateSelect = 0x0106,
        kSGSetSoundInputParametersSelect = 0x0107,
        kSGGetSoundInputParametersSelect = 0x0108,
        kSGSetAdditionalSoundRatesSelect = 0x0109,
        kSGGetAdditionalSoundRatesSelect = 0x010A,
        kSGSetFontNameSelect = 0x0100,
        kSGSetFontSizeSelect = 0x0101,
        kSGSetTextForeColorSelect = 0x0102,
        kSGSetTextBackColorSelect = 0x0103,
        kSGSetJustificationSelect = 0x0104,
        kSGGetTextReturnToSpaceValueSelect = 0x0105,
        kSGSetTextReturnToSpaceValueSelect = 0x0106,
        kSGGetInstrumentSelect = 0x0100,
        kSGSetInstrumentSelect = 0x0101,
        kQTVideoOutputGetDisplayModeListSelect = 0x0001,
        kQTVideoOutputGetCurrentClientNameSelect = 0x0002,
        kQTVideoOutputSetClientNameSelect = 0x0003,
        kQTVideoOutputGetClientNameSelect = 0x0004,
        kQTVideoOutputBeginSelect = 0x0005,
        kQTVideoOutputEndSelect = 0x0006,
        kQTVideoOutputSetDisplayModeSelect = 0x0007,
        kQTVideoOutputGetDisplayModeSelect = 0x0008,
        kQTVideoOutputCustomConfigureDisplaySelect = 0x0009,
        kQTVideoOutputSaveStateSelect = 0x000A,
        kQTVideoOutputRestoreStateSelect = 0x000B,
        kQTVideoOutputGetGWorldSelect = 0x000C,
        kQTVideoOutputGetGWorldParametersSelect = 0x000D,
        kQTVideoOutputGetIndSoundOutputSelect = 0x000E,
        kQTVideoOutputGetClockSelect = 0x000F,
        kQTVideoOutputSetEchoPortSelect = 0x0010,
        kQTVideoOutputGetIndImageDecompressorSelect = 0x0011
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

#endif /** __QUICKTIMECOMPONENTS__ */
