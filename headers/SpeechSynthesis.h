/**
     \file       SpeechSynthesis.h

    \brief   Speech Interfaces.

    \introduced_in  Mac OS 8
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1989-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Speech

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __SPEECHSYNTHESIS__
#define __SPEECHSYNTHESIS__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <MixedMode.h>
#endif

#ifndef __FILES__
#include <Files.h>
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
    kTextToSpeechSynthType = FOUR_CHAR_CODE('ttsc'),
    kTextToSpeechVoiceType = FOUR_CHAR_CODE('ttvd'),
    kTextToSpeechVoiceFileType = FOUR_CHAR_CODE('ttvf'),
    kTextToSpeechVoiceBundleType = FOUR_CHAR_CODE('ttvb')
  };

  enum
  {
    kNoEndingProsody = 1,
    kNoSpeechInterrupt = 2,
    kPreflightThenPause = 4
  };

  enum
  {
    kImmediate = 0,
    kEndOfWord = 1,
    kEndOfSentence = 2
  };

  /*------------------------------------------*/
  /* GetSpeechInfo & SetSpeechInfo selectors  */
  /*------------------------------------------*/
  enum
  {
    soStatus = FOUR_CHAR_CODE('stat'),
    soErrors = FOUR_CHAR_CODE('erro'),
    soInputMode = FOUR_CHAR_CODE('inpt'),
    soCharacterMode = FOUR_CHAR_CODE('char'),
    soNumberMode = FOUR_CHAR_CODE('nmbr'),
    soRate = FOUR_CHAR_CODE('rate'),
    soPitchBase = FOUR_CHAR_CODE('pbas'),
    soPitchMod = FOUR_CHAR_CODE('pmod'),
    soVolume = FOUR_CHAR_CODE('volm'),
    soSynthType = FOUR_CHAR_CODE('vers'),
    soRecentSync = FOUR_CHAR_CODE('sync'),
    soPhonemeSymbols = FOUR_CHAR_CODE('phsy'),
    soCurrentVoice = FOUR_CHAR_CODE('cvox'),
    soCommandDelimiter = FOUR_CHAR_CODE('dlim'),
    soReset = FOUR_CHAR_CODE('rset'),
    soCurrentA5 = FOUR_CHAR_CODE('myA5'),
    soRefCon = FOUR_CHAR_CODE('refc'),
    soTextDoneCallBack =
        FOUR_CHAR_CODE('tdcb'),                    /* use with SpeechTextDoneProcPtr*/
    soSpeechDoneCallBack = FOUR_CHAR_CODE('sdcb'), /* use with SpeechDoneProcPtr*/
    soSyncCallBack = FOUR_CHAR_CODE('sycb'),       /* use with SpeechSyncProcPtr*/
    soErrorCallBack = FOUR_CHAR_CODE('ercb'),      /* use with SpeechErrorProcPtr*/
    soPhonemeCallBack = FOUR_CHAR_CODE('phcb'),    /* use with SpeechPhonemeProcPtr*/
    soWordCallBack = FOUR_CHAR_CODE('wdcb'),
    soSynthExtension = FOUR_CHAR_CODE('xtnd'),
    soSoundOutput = FOUR_CHAR_CODE('sndo')
  };

  /*------------------------------------------*/
  /* Speaking Mode Constants                  */
  /*------------------------------------------*/
  enum
  {
    modeText = FOUR_CHAR_CODE('TEXT'), /* input mode constants             */
    modePhonemes = FOUR_CHAR_CODE('PHON'),
    modeNormal =
        FOUR_CHAR_CODE('NORM'), /* character mode and number mode constants */
    modeLiteral = FOUR_CHAR_CODE('LTRL')
  };

  enum
  {
    soVoiceDescription = FOUR_CHAR_CODE('info'),
    soVoiceFile = FOUR_CHAR_CODE('fref')
  };

  typedef struct OpaqueSpeechChannel *SpeechChannel;

  struct VoiceSpec
  {
    OSType creator;
    OSType id;
  };
  typedef struct VoiceSpec VoiceSpec;
  typedef VoiceSpec *VoiceSpecPtr;

  enum
  {
    kNeuter = 0,
    kMale = 1,
    kFemale = 2
  };

  struct VoiceDescription
  {
    long length;
    VoiceSpec voice;
    long version;
    Str63 name;
    Str255 comment;
    short gender;
    short age;
    short script;
    short language;
    short region;
    long reserved[4];
  };
  typedef struct VoiceDescription VoiceDescription;

  struct VoiceFileInfo
  {
    FSSpec fileSpec;
    short resID;
  };
  typedef struct VoiceFileInfo VoiceFileInfo;
  struct SpeechStatusInfo
  {
    Boolean outputBusy;
    Boolean outputPaused;
    long inputBytesLeft;
    short phonemeCode;
  };
  typedef struct SpeechStatusInfo SpeechStatusInfo;

  struct SpeechErrorInfo
  {
    short count;
    OSErr oldest;
    long oldPos;
    OSErr newest;
    long newPos;
  };
  typedef struct SpeechErrorInfo SpeechErrorInfo;

  struct SpeechVersionInfo
  {
    OSType synthType;
    OSType synthSubType;
    OSType synthManufacturer;
    long synthFlags;
    NumVersion synthVersion;
  };
  typedef struct SpeechVersionInfo SpeechVersionInfo;

  struct PhonemeInfo
  {
    short opcode;
    Str15 phStr;
    Str31 exampleStr;
    short hiliteStart;
    short hiliteEnd;
  };
  typedef struct PhonemeInfo PhonemeInfo;

  struct PhonemeDescriptor
  {
    short phonemeCount;
    PhonemeInfo thePhonemes[1];
  };
  typedef struct PhonemeDescriptor PhonemeDescriptor;
  struct SpeechXtndData
  {
    OSType synthCreator;
    Byte synthData[2];
  };
  typedef struct SpeechXtndData SpeechXtndData;

  struct DelimiterInfo
  {
    Byte startDelimiter[2];
    Byte endDelimiter[2];
  };
  typedef struct DelimiterInfo DelimiterInfo;

  typedef CALLBACK_API(void, SpeechTextDoneProcPtr)(SpeechChannel chan,
                                                    long refCon,
                                                    const void **nextBuf,
                                                    unsigned long *byteLen,
                                                    long *controlFlags);
  typedef CALLBACK_API(void, SpeechDoneProcPtr)(SpeechChannel chan, long refCon);
  typedef CALLBACK_API(void, SpeechSyncProcPtr)(SpeechChannel chan, long refCon,
                                                OSType syncMessage);
  typedef CALLBACK_API(void, SpeechErrorProcPtr)(SpeechChannel chan, long refCon,
                                                 OSErr theError, long bytePos);
  typedef CALLBACK_API(void, SpeechPhonemeProcPtr)(SpeechChannel chan,
                                                   long refCon,
                                                   short phonemeOpcode);
  typedef CALLBACK_API(void, SpeechWordProcPtr)(SpeechChannel chan, long refCon,
                                                unsigned long wordPos,
                                                unsigned short wordLen);
  typedef STACK_UPP_TYPE(SpeechTextDoneProcPtr) SpeechTextDoneUPP;
  typedef STACK_UPP_TYPE(SpeechDoneProcPtr) SpeechDoneUPP;
  typedef STACK_UPP_TYPE(SpeechSyncProcPtr) SpeechSyncUPP;
  typedef STACK_UPP_TYPE(SpeechErrorProcPtr) SpeechErrorUPP;
  typedef STACK_UPP_TYPE(SpeechPhonemeProcPtr) SpeechPhonemeUPP;
  typedef STACK_UPP_TYPE(SpeechWordProcPtr) SpeechWordUPP;
  /**
   *  NewSpeechTextDoneUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SpeechTextDoneUPP
  NewSpeechTextDoneUPP(SpeechTextDoneProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppSpeechTextDoneProcInfo = 0x0000FFC0
  }; /* pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes, 4_bytes, 4_bytes)
      */
#ifdef __cplusplus
  inline SpeechTextDoneUPP
  NewSpeechTextDoneUPP(SpeechTextDoneProcPtr userRoutine)
  {
    return (SpeechTextDoneUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                   uppSpeechTextDoneProcInfo,
                                                   GetCurrentArchitecture());
  }
#else
#define NewSpeechTextDoneUPP(userRoutine)                                     \
  (SpeechTextDoneUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppSpeechTextDoneProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewSpeechDoneUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SpeechDoneUPP
  NewSpeechDoneUPP(SpeechDoneProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppSpeechDoneProcInfo = 0x000003C0
  }; /* pascal no_return_value Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline SpeechDoneUPP NewSpeechDoneUPP(SpeechDoneProcPtr userRoutine)
  {
    return (SpeechDoneUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppSpeechDoneProcInfo, GetCurrentArchitecture());
  }
#else
#define NewSpeechDoneUPP(userRoutine)   \
  (SpeechDoneUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppSpeechDoneProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewSpeechSyncUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SpeechSyncUPP
  NewSpeechSyncUPP(SpeechSyncProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppSpeechSyncProcInfo = 0x00000FC0
  }; /* pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline SpeechSyncUPP NewSpeechSyncUPP(SpeechSyncProcPtr userRoutine)
  {
    return (SpeechSyncUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppSpeechSyncProcInfo, GetCurrentArchitecture());
  }
#else
#define NewSpeechSyncUPP(userRoutine)   \
  (SpeechSyncUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppSpeechSyncProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewSpeechErrorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SpeechErrorUPP
  NewSpeechErrorUPP(SpeechErrorProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppSpeechErrorProcInfo = 0x00003BC0
  }; /* pascal no_return_value Func(4_bytes, 4_bytes, 2_bytes, 4_bytes) */
#ifdef __cplusplus
  inline SpeechErrorUPP NewSpeechErrorUPP(SpeechErrorProcPtr userRoutine)
  {
    return (SpeechErrorUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppSpeechErrorProcInfo, GetCurrentArchitecture());
  }
#else
#define NewSpeechErrorUPP(userRoutine)                                     \
  (SpeechErrorUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppSpeechErrorProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewSpeechPhonemeUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SpeechPhonemeUPP
  NewSpeechPhonemeUPP(SpeechPhonemeProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppSpeechPhonemeProcInfo = 0x00000BC0
  }; /* pascal no_return_value Func(4_bytes, 4_bytes, 2_bytes) */
#ifdef __cplusplus
  inline SpeechPhonemeUPP NewSpeechPhonemeUPP(SpeechPhonemeProcPtr userRoutine)
  {
    return (SpeechPhonemeUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                  uppSpeechPhonemeProcInfo,
                                                  GetCurrentArchitecture());
  }
#else
#define NewSpeechPhonemeUPP(userRoutine)                                     \
  (SpeechPhonemeUPP)                                                         \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppSpeechPhonemeProcInfo, \
                           GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewSpeechWordUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  SpeechWordUPP
  NewSpeechWordUPP(SpeechWordProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppSpeechWordProcInfo = 0x00002FC0
  }; /* pascal no_return_value Func(4_bytes, 4_bytes, 4_bytes, 2_bytes) */
#ifdef __cplusplus
  inline SpeechWordUPP NewSpeechWordUPP(SpeechWordProcPtr userRoutine)
  {
    return (SpeechWordUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppSpeechWordProcInfo, GetCurrentArchitecture());
  }
#else
#define NewSpeechWordUPP(userRoutine)   \
  (SpeechWordUPP) NewRoutineDescriptor( \
      (ProcPtr)(userRoutine), uppSpeechWordProcInfo, GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeSpeechTextDoneUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeSpeechTextDoneUPP(SpeechTextDoneUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeSpeechTextDoneUPP(SpeechTextDoneUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeSpeechTextDoneUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeSpeechDoneUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeSpeechDoneUPP(SpeechDoneUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeSpeechDoneUPP(SpeechDoneUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeSpeechDoneUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeSpeechSyncUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeSpeechSyncUPP(SpeechSyncUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeSpeechSyncUPP(SpeechSyncUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeSpeechSyncUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeSpeechErrorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeSpeechErrorUPP(SpeechErrorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeSpeechErrorUPP(SpeechErrorUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeSpeechErrorUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeSpeechPhonemeUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeSpeechPhonemeUPP(SpeechPhonemeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeSpeechPhonemeUPP(SpeechPhonemeUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeSpeechPhonemeUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeSpeechWordUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeSpeechWordUPP(SpeechWordUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeSpeechWordUPP(SpeechWordUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeSpeechWordUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeSpeechTextDoneUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeSpeechTextDoneUPP(SpeechChannel chan, long refCon, const void **nextBuf,
                          unsigned long *byteLen, long *controlFlags,
                          SpeechTextDoneUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeSpeechTextDoneUPP(SpeechChannel chan, long refCon,
                                      const void **nextBuf,
                                      unsigned long *byteLen, long *controlFlags,
                                      SpeechTextDoneUPP userUPP)
  {
    CALL_FIVE_PARAMETER_UPP(userUPP, uppSpeechTextDoneProcInfo, chan, refCon,
                            nextBuf, byteLen, controlFlags);
  }
#else
#define InvokeSpeechTextDoneUPP(chan, refCon, nextBuf, byteLen, controlFlags, \
                                userUPP)                                      \
  CALL_FIVE_PARAMETER_UPP((userUPP), uppSpeechTextDoneProcInfo, (chan),       \
                          (refCon), (nextBuf), (byteLen), (controlFlags))
#endif
#endif

  /**
   *  InvokeSpeechDoneUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeSpeechDoneUPP(SpeechChannel chan, long refCon, SpeechDoneUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeSpeechDoneUPP(SpeechChannel chan, long refCon,
                                  SpeechDoneUPP userUPP)
  {
    CALL_TWO_PARAMETER_UPP(userUPP, uppSpeechDoneProcInfo, chan, refCon);
  }
#else
#define InvokeSpeechDoneUPP(chan, refCon, userUPP) \
  CALL_TWO_PARAMETER_UPP((userUPP), uppSpeechDoneProcInfo, (chan), (refCon))
#endif
#endif

  /**
   *  InvokeSpeechSyncUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeSpeechSyncUPP(SpeechChannel chan, long refCon, OSType syncMessage,
                      SpeechSyncUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeSpeechSyncUPP(SpeechChannel chan, long refCon,
                                  OSType syncMessage, SpeechSyncUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppSpeechSyncProcInfo, chan, refCon,
                             syncMessage);
  }
#else
#define InvokeSpeechSyncUPP(chan, refCon, syncMessage, userUPP)                \
  CALL_THREE_PARAMETER_UPP((userUPP), uppSpeechSyncProcInfo, (chan), (refCon), \
                           (syncMessage))
#endif
#endif

  /**
   *  InvokeSpeechErrorUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeSpeechErrorUPP(SpeechChannel chan, long refCon, OSErr theError,
                       long bytePos, SpeechErrorUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeSpeechErrorUPP(SpeechChannel chan, long refCon,
                                   OSErr theError, long bytePos,
                                   SpeechErrorUPP userUPP)
  {
    CALL_FOUR_PARAMETER_UPP(userUPP, uppSpeechErrorProcInfo, chan, refCon,
                            theError, bytePos);
  }
#else
#define InvokeSpeechErrorUPP(chan, refCon, theError, bytePos, userUPP)         \
  CALL_FOUR_PARAMETER_UPP((userUPP), uppSpeechErrorProcInfo, (chan), (refCon), \
                          (theError), (bytePos))
#endif
#endif

  /**
   *  InvokeSpeechPhonemeUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeSpeechPhonemeUPP(SpeechChannel chan, long refCon, short phonemeOpcode,
                         SpeechPhonemeUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeSpeechPhonemeUPP(SpeechChannel chan, long refCon,
                                     short phonemeOpcode,
                                     SpeechPhonemeUPP userUPP)
  {
    CALL_THREE_PARAMETER_UPP(userUPP, uppSpeechPhonemeProcInfo, chan, refCon,
                             phonemeOpcode);
  }
#else
#define InvokeSpeechPhonemeUPP(chan, refCon, phonemeOpcode, userUPP)    \
  CALL_THREE_PARAMETER_UPP((userUPP), uppSpeechPhonemeProcInfo, (chan), \
                           (refCon), (phonemeOpcode))
#endif
#endif

  /**
   *  InvokeSpeechWordUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  InvokeSpeechWordUPP(SpeechChannel chan, long refCon, unsigned long wordPos,
                      unsigned short wordLen, SpeechWordUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void InvokeSpeechWordUPP(SpeechChannel chan, long refCon,
                                  unsigned long wordPos, unsigned short wordLen,
                                  SpeechWordUPP userUPP)
  {
    CALL_FOUR_PARAMETER_UPP(userUPP, uppSpeechWordProcInfo, chan, refCon, wordPos,
                            wordLen);
  }
#else
#define InvokeSpeechWordUPP(chan, refCon, wordPos, wordLen, userUPP)          \
  CALL_FOUR_PARAMETER_UPP((userUPP), uppSpeechWordProcInfo, (chan), (refCon), \
                          (wordPos), (wordLen))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewSpeechTextDoneProc(userRoutine) NewSpeechTextDoneUPP(userRoutine)
#define NewSpeechDoneProc(userRoutine) NewSpeechDoneUPP(userRoutine)
#define NewSpeechSyncProc(userRoutine) NewSpeechSyncUPP(userRoutine)
#define NewSpeechErrorProc(userRoutine) NewSpeechErrorUPP(userRoutine)
#define NewSpeechPhonemeProc(userRoutine) NewSpeechPhonemeUPP(userRoutine)
#define NewSpeechWordProc(userRoutine) NewSpeechWordUPP(userRoutine)
#define CallSpeechTextDoneProc(userRoutine, chan, refCon, nextBuf, byteLen, \
                               controlFlags)                                \
  InvokeSpeechTextDoneUPP(chan, refCon, nextBuf, byteLen, controlFlags,     \
                          userRoutine)
#define CallSpeechDoneProc(userRoutine, chan, refCon) \
  InvokeSpeechDoneUPP(chan, refCon, userRoutine)
#define CallSpeechSyncProc(userRoutine, chan, refCon, syncMessage) \
  InvokeSpeechSyncUPP(chan, refCon, syncMessage, userRoutine)
#define CallSpeechErrorProc(userRoutine, chan, refCon, theError, bytePos) \
  InvokeSpeechErrorUPP(chan, refCon, theError, bytePos, userRoutine)
#define CallSpeechPhonemeProc(userRoutine, chan, refCon, phonemeOpcode) \
  InvokeSpeechPhonemeUPP(chan, refCon, phonemeOpcode, userRoutine)
#define CallSpeechWordProc(userRoutine, chan, refCon, wordPos, wordLen) \
  InvokeSpeechWordUPP(chan, refCon, wordPos, wordLen, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

  /**
   *  SpeechManagerVersion()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  NumVersion
  SpeechManagerVersion(void);

  /**
   *  MakeVoiceSpec()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  MakeVoiceSpec(OSType creator, OSType id, VoiceSpec *voice);

  /**
   *  CountVoices()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  CountVoices(short *numVoices);

  /**
   *  GetIndVoice()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetIndVoice(short index, VoiceSpec *voice);

  /**
   *  GetVoiceDescription()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetVoiceDescription(const VoiceSpec *voice, VoiceDescription *info,
                      long infoLength);

  /**
   *  GetVoiceInfo()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetVoiceInfo(const VoiceSpec *voice, OSType selector, void *voiceInfo);

  /**
   *  NewSpeechChannel()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  NewSpeechChannel(VoiceSpec *voice, /* can be NULL */
                   SpeechChannel *chan);

  /**
   *  DisposeSpeechChannel()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  DisposeSpeechChannel(SpeechChannel chan);

  /**
   *  SpeakString()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SpeakString(ConstStr255Param textToBeSpoken);

  /**
   *  SpeakText()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SpeakText(SpeechChannel chan, const void *textBuf, unsigned long textBytes);

  /**
   *  SpeakBuffer()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SpeakBuffer(SpeechChannel chan, const void *textBuf, unsigned long textBytes,
              long controlFlags);

  /**
   *  StopSpeech()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  StopSpeech(SpeechChannel chan);

  /**
   *  StopSpeechAt()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  StopSpeechAt(SpeechChannel chan, long whereToStop);

  /**
   *  PauseSpeechAt()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  PauseSpeechAt(SpeechChannel chan, long whereToPause);

  /**
   *  ContinueSpeech()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  ContinueSpeech(SpeechChannel chan);

  /**
   *  SpeechBusy()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  short
  SpeechBusy(void);

  /**
   *  SpeechBusySystemWide()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  short
  SpeechBusySystemWide(void);

  /**
   *  SetSpeechRate()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetSpeechRate(SpeechChannel chan, Fixed rate);

  /**
   *  GetSpeechRate()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetSpeechRate(SpeechChannel chan, Fixed *rate);

  /**
   *  SetSpeechPitch()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetSpeechPitch(SpeechChannel chan, Fixed pitch);

  /**
   *  GetSpeechPitch()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetSpeechPitch(SpeechChannel chan, Fixed *pitch);

  /**
   *  SetSpeechInfo()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  SetSpeechInfo(SpeechChannel chan, OSType selector, const void *speechInfo);

  /**
   *  GetSpeechInfo()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetSpeechInfo(SpeechChannel chan, OSType selector, void *speechInfo);

  /**
   *  TextToPhonemes()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  TextToPhonemes(SpeechChannel chan, const void *textBuf, unsigned long textBytes,
                 Handle phonemeBuf, long *phonemeBytes);

  /**
   *  UseDictionary()
   *

   *    \non_carbon_cfm   in SpeechLib 1.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  UseDictionary(SpeechChannel chan, Handle dictionary);

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

#endif /* __SPEECHSYNTHESIS__ */
