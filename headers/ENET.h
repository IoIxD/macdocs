/**
     \file       ENET.h

    \brief   Ethernet Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1990-2001 by Apple Computer, Inc., all rights reserved

    \ingroup Networking
    
    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __ENET__
#define __ENET__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __OSUTILS__
#include <OSUtils.h>
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
  ENetSetGeneral = 253, /*Set "general" mode*/
  ENetGetInfo = 252,    /*Get info*/
  ENetRdCancel = 251,   /*Cancel read*/
  ENetRead = 250,       /*Read*/
  ENetWrite = 249,      /*Write*/
  ENetDetachPH = 248,   /*Detach protocol handler*/
  ENetAttachPH = 247,   /*Attach protocol handler*/
  ENetAddMulti = 246,   /*Add a multicast address*/
  ENetDelMulti = 245    /*Delete a multicast address*/
};

enum {
  EAddrRType = FOUR_CHAR_CODE('eadr') /*Alternate address resource type*/
};

typedef struct EParamBlock EParamBlock;
typedef EParamBlock *EParamBlkPtr;
typedef CALLBACK_API_REGISTER68K(void, ENETCompletionProcPtr,
                                 (EParamBlkPtr thePBPtr));
typedef REGISTER_UPP_TYPE(ENETCompletionProcPtr) ENETCompletionUPP;
struct EParamBlock {
  QElem *qLink;                   /*General EParams*/
  short qType;                    /*queue type*/
  short ioTrap;                   /*routine trap*/
  Ptr ioCmdAddr;                  /*routine address*/
  ENETCompletionUPP ioCompletion; /*completion routine*/
  OSErr ioResult;                 /*result code*/
  StringPtr ioNamePtr;            /*->filename*/
  short ioVRefNum;                /*volume reference or drive number*/
  short ioRefNum;                 /*driver reference number*/
  short csCode;                   /*Call command code*/
  union {
    struct {
      short eProtType; /*Ethernet protocol type*/
      Ptr ePointer;    /*No support for PowerPC code*/
      short eBuffSize; /*buffer size*/
      short eDataSize; /*number of bytes read*/
    } EParms1;
    struct {
      Byte eMultiAddr[6]; /*Multicast Address*/
    } EParms2;
  } u;
};

#if CALL_NOT_IN_CARBON
/**
 *  NewENETCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(ENETCompletionUPP)
NewENETCompletionUPP(ENETCompletionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
enum {
  uppENETCompletionProcInfo = 0x00009802
}; /* register no_return_value Func(4_bytes:A0) */
#ifdef __cplusplus
inline ENETCompletionUPP
NewENETCompletionUPP(ENETCompletionProcPtr userRoutine) {
  return (ENETCompletionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                 uppENETCompletionProcInfo,
                                                 GetCurrentArchitecture());
}
#else
#define NewENETCompletionUPP(userRoutine)                                      \
  (ENETCompletionUPP)                                                          \
      NewRoutineDescriptor((ProcPtr)(userRoutine), uppENETCompletionProcInfo,  \
                           GetCurrentArchitecture())
#endif
#endif

/**
 *  DisposeENETCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API_C(void)
DisposeENETCompletionUPP(ENETCompletionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
inline void DisposeENETCompletionUPP(ENETCompletionUPP userUPP) {
  DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
}
#else
#define DisposeENETCompletionUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

/**
 *  InvokeENETCompletionUPP()
 *

 *    \non_carbon_cfm   available as macro/inline
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
#if TARGET_OS_MAC && TARGET_CPU_68K && !TARGET_RT_MAC_CFM
#pragma parameter InvokeENETCompletionUPP(__A0, __A1)
#endif
EXTERN_API_C(void)
InvokeENETCompletionUPP(EParamBlkPtr thePBPtr, ENETCompletionUPP userUPP)
    ONEWORDINLINE(0x4E91);
#if !OPAQUE_UPP_TYPES &&                                                       \
    (!TARGET_OS_MAC || !TARGET_CPU_68K || TARGET_RT_MAC_CFM)
#ifdef __cplusplus
inline void InvokeENETCompletionUPP(EParamBlkPtr thePBPtr,
                                    ENETCompletionUPP userUPP) {
  CALL_ONE_PARAMETER_UPP(userUPP, uppENETCompletionProcInfo, thePBPtr);
}
#else
#define InvokeENETCompletionUPP(thePBPtr, userUPP)                             \
  CALL_ONE_PARAMETER_UPP((userUPP), uppENETCompletionProcInfo, (thePBPtr))
#endif
#endif

#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/* support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewENETCompletionProc(userRoutine) NewENETCompletionUPP(userRoutine)
#define CallENETCompletionProc(userRoutine, thePBPtr)                          \
  InvokeENETCompletionUPP(thePBPtr, userRoutine)
#endif /* CALL_NOT_IN_CARBON */

#if CALL_NOT_IN_CARBON
/**
 *  EWrite()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
EWrite(EParamBlkPtr thePBptr, Boolean async);

/**
 *  EAttachPH()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
EAttachPH(EParamBlkPtr thePBptr, Boolean async);

/**
 *  EDetachPH()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
EDetachPH(EParamBlkPtr thePBptr, Boolean async);

/**
 *  ERead()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
ERead(EParamBlkPtr thePBptr, Boolean async);

/**
 *  ERdCancel()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
ERdCancel(EParamBlkPtr thePBptr, Boolean async);

/**
 *  EGetInfo()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
EGetInfo(EParamBlkPtr thePBptr, Boolean async);

/**
 *  ESetGeneral()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
ESetGeneral(EParamBlkPtr thePBptr, Boolean async);

/**
 *  EAddMulti()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
EAddMulti(EParamBlkPtr thePBptr, Boolean async);

/**
 *  EDelMulti()
 *

 *    \non_carbon_cfm   in InterfaceLib 7.1 and later
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
EXTERN_API(OSErr)
EDelMulti(EParamBlkPtr thePBptr, Boolean async);

#endif /* CALL_NOT_IN_CARBON */

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

#endif /* __ENET__ */
