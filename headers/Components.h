/**
     \file       Components.h

    \brief   Component Manager Interfaces.

    \introduced_in  QuickTime 5.0
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1991-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Managers

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __COMPONENTS__
#define __COMPONENTS__

#ifndef __MACERRORS__
#include <MacErrors.h>
#endif

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
    kAppleManufacturer = FOUR_CHAR_CODE('appl'), /** Apple supplied components */
    kComponentResourceType =
        FOUR_CHAR_CODE('thng'), /** a components resource type */
    kComponentAliasResourceType =
        FOUR_CHAR_CODE('thga') /** component alias resource type */
  };

  enum
  {
    kAnyComponentType = 0,
    kAnyComponentSubType = 0,
    kAnyComponentManufacturer = 0,
    kAnyComponentFlagsMask = 0
  };

  enum
  {
    cmpIsMissing = 1L << 29,
    cmpWantsRegisterMessage = 1L << 31
  };

  enum
  {
    kComponentOpenSelect = -1,              /** ComponentInstance for this open */
    kComponentCloseSelect = -2,             /** ComponentInstance for this close */
    kComponentCanDoSelect = -3,             /** selector # being queried */
    kComponentVersionSelect = -4,           /** no params */
    kComponentRegisterSelect = -5,          /** no params */
    kComponentTargetSelect = -6,            /** ComponentInstance for top of call chain */
    kComponentUnregisterSelect = -7,        /** no params */
    kComponentGetMPWorkFunctionSelect = -8, /** some params */
    kComponentExecuteWiredActionSelect =
        -9, /** QTAtomContainer actionContainer, QTAtom actionAtom,
               QTCustomActionTargetPtr target, QTEventRecordPtr event */
    kComponentGetPublicResourceSelect =
        -10 /** OSType resourceType, short resourceId, Handle *resource */
  };

  /** Component Resource Extension flags */
  enum
  {
    componentDoAutoVersion = (1 << 0),
    componentWantsUnregister = (1 << 1),
    componentAutoVersionIncludeFlags = (1 << 2),
    componentHasMultiplePlatforms = (1 << 3),
    componentLoadResident = (1 << 4)
  };

  /** Set Default Component flags */
  enum
  {
    defaultComponentIdentical = 0,
    defaultComponentAnyFlags = 1,
    defaultComponentAnyManufacturer = 2,
    defaultComponentAnySubType = 4,
    defaultComponentAnyFlagsAnyManufacturer =
        (defaultComponentAnyFlags + defaultComponentAnyManufacturer),
    defaultComponentAnyFlagsAnyManufacturerAnySubType =
        (defaultComponentAnyFlags + defaultComponentAnyManufacturer +
         defaultComponentAnySubType)
  };

  /** RegisterComponentResource flags */
  enum
  {
    registerComponentGlobal = 1,
    registerComponentNoDuplicates = 2,
    registerComponentAfterExisting = 4,
    registerComponentAliasesOnly = 8
  };

  struct ComponentDescription
  {
    OSType componentType;         /** A unique 4-byte code indentifying the command set */
    OSType componentSubType;      /** Particular flavor of this instance */
    OSType componentManufacturer; /** Vendor indentification */
    unsigned long
        componentFlags; /** 8 each for Component,Type,SubType,Manuf/revision */
    unsigned long
        componentFlagsMask; /** Mask for specifying which flags to consider in
                               search, zero during registration */
  };
  typedef struct ComponentDescription ComponentDescription;

  struct ResourceSpec
  {
    OSType resType; /** 4-byte code    */
    short resID;    /**         */
  };
  typedef struct ResourceSpec ResourceSpec;
  struct ComponentResource
  {
    ComponentDescription cd;    /** Registration parameters */
    ResourceSpec component;     /** resource where Component code is found */
    ResourceSpec componentName; /** name string resource */
    ResourceSpec componentInfo; /** info string resource */
    ResourceSpec componentIcon; /** icon resource */
  };
  typedef struct ComponentResource ComponentResource;
  typedef ComponentResource *ComponentResourcePtr;
  typedef ComponentResourcePtr *ComponentResourceHandle;
  struct ComponentPlatformInfo
  {
    long componentFlags;    /** flags of Component */
    ResourceSpec component; /** resource where Component code is found */
    short platformType;     /** gestaltSysArchitecture result */
  };
  typedef struct ComponentPlatformInfo ComponentPlatformInfo;
  struct ComponentResourceExtension
  {
    long componentVersion;       /** version of Component */
    long componentRegisterFlags; /** flags for registration */
    short componentIconFamily;   /** resource id of Icon Family */
  };
  typedef struct ComponentResourceExtension ComponentResourceExtension;
  struct ComponentPlatformInfoArray
  {
    long count;
    ComponentPlatformInfo platformArray[1];
  };
  typedef struct ComponentPlatformInfoArray ComponentPlatformInfoArray;
  struct ExtComponentResource
  {
    ComponentDescription cd;     /** registration parameters */
    ResourceSpec component;      /** resource where Component code is found */
    ResourceSpec componentName;  /** name string resource */
    ResourceSpec componentInfo;  /** info string resource */
    ResourceSpec componentIcon;  /** icon resource */
    long componentVersion;       /** version of Component */
    long componentRegisterFlags; /** flags for registration */
    short componentIconFamily;   /** resource id of Icon Family */
    long count;                  /** elements in platformArray */
    ComponentPlatformInfo platformArray[1];
  };
  typedef struct ExtComponentResource ExtComponentResource;
  typedef ExtComponentResource *ExtComponentResourcePtr;
  typedef ExtComponentResourcePtr *ExtComponentResourceHandle;
  struct ComponentAliasResource
  {
    ComponentResource cr;         /** Registration parameters */
    ComponentDescription aliasCD; /** component alias description */
  };
  typedef struct ComponentAliasResource ComponentAliasResource;
  /**  Structure received by Component:        */
  struct ComponentParameters
  {
    UInt8 flags;     /** call modifiers: sync/async, deferred, immed, etc */
    UInt8 paramSize; /** size in bytes of actual parameters passed to this call */
    short what;      /** routine selector, negative for Component management calls */
    long params[1];  /** actual parameters for the indicated routine */
  };
  typedef struct ComponentParameters ComponentParameters;
  struct ComponentRecord
  {
    long data[1];
  };
  typedef struct ComponentRecord ComponentRecord;
  typedef ComponentRecord *Component;
  struct ComponentInstanceRecord
  {
    long data[1];
  };
  typedef struct ComponentInstanceRecord ComponentInstanceRecord;
  typedef ComponentInstanceRecord *ComponentInstance;
  struct RegisteredComponentRecord
  {
    long data[1];
  };
  typedef struct RegisteredComponentRecord RegisteredComponentRecord;
  typedef RegisteredComponentRecord *RegisteredComponentRecordPtr;
  struct RegisteredComponentInstanceRecord
  {
    long data[1];
  };
  typedef struct RegisteredComponentInstanceRecord
      RegisteredComponentInstanceRecord;
  typedef RegisteredComponentInstanceRecord *RegisteredComponentInstanceRecordPtr;
  typedef long ComponentResult;
  enum
  {
    platform68k = 1, /** platform type (response from gestaltComponentPlatform) */
    platformPowerPC =
        2,                   /** (when gestaltComponentPlatform is not implemented, use */
    platformInterpreted = 3, /** gestaltSysArchitecture) */
    platformWin32 = 4,
    platformPowerPCNativeEntryPoint = 5
  };

  enum
  {
    mpWorkFlagDoWork = (1 << 0),
    mpWorkFlagDoCompletion = (1 << 1),
    mpWorkFlagCopyWorkBlock = (1 << 2),
    mpWorkFlagDontBlock = (1 << 3),
    mpWorkFlagGetProcessorCount = (1 << 4),
    mpWorkFlagGetIsRunning = (1 << 6)
  };

  enum
  {
    cmpAliasNoFlags = 0,
    cmpAliasOnlyThisFile = 1
  };

  struct ComponentMPWorkFunctionHeaderRecord
  {
    UInt32 headerSize;
    UInt32 recordSize;
    UInt32 workFlags;
    UInt16 processorCount;
    UInt8 unused;
    UInt8 isRunning;
  };
  typedef struct ComponentMPWorkFunctionHeaderRecord
      ComponentMPWorkFunctionHeaderRecord;
  typedef ComponentMPWorkFunctionHeaderRecord
      *ComponentMPWorkFunctionHeaderRecordPtr;
  typedef CALLBACK_API(ComponentResult, ComponentMPWorkFunctionProcPtr)(
      void *globalRefCon, ComponentMPWorkFunctionHeaderRecordPtr header);
  typedef CALLBACK_API(ComponentResult,
                       ComponentRoutineProcPtr)(ComponentParameters *cp,
                                                Handle componentStorage);
  typedef CALLBACK_API(OSErr, GetMissingComponentResourceProcPtr)(
      Component c, OSType resType, short resID, void *refCon, Handle *resource);
  typedef STACK_UPP_TYPE(ComponentMPWorkFunctionProcPtr)
      ComponentMPWorkFunctionUPP;
  typedef STACK_UPP_TYPE(ComponentRoutineProcPtr) ComponentRoutineUPP;
  typedef STACK_UPP_TYPE(GetMissingComponentResourceProcPtr)
      GetMissingComponentResourceUPP;
  /**
      The parameter list for each ComponentFunction is unique. It is
      therefore up to users to create the appropriate procInfo for their
      own ComponentFunctions where necessary.
  */
  typedef UniversalProcPtr ComponentFunctionUPP;
  /**
   *  NewComponentFunctionUPP()
   *
   *  Discussion:
   *    For use in writing a Carbon compliant Component.  It is used to
   *    create a ComponentFunctionUPP needed to call
   *    CallComponentFunction in the Components dispatch routine.
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentFunctionUPP
  NewComponentFunctionUPP(ProcPtr userRoutine, ProcInfoType procInfo);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline DEFINE_API(ComponentFunctionUPP)
      NewComponentFunctionUPP(ProcPtr userRoutine, ProcInfoType procInfo)
  {
    return (ComponentFunctionUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), (ProcInfoType)procInfo, GetCurrentArchitecture());
  }
#else
#define NewComponentFunctionUPP(userRoutine, procInfo)                \
  ((ComponentFunctionUPP)NewRoutineDescriptor((ProcPtr)(userRoutine), \
                                              (ProcInfoType)procInfo, \
                                              GetCurrentArchitecture()))
#endif
#endif

  /**
   *  DisposeComponentFunctionUPP()
   *
   *  Discussion:
   *    For use in writing a Carbon compliant Component.  It is used to
   *    dispose of a ComponentFunctionUPP created by
   *    NewComponentFunctionUPP.
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeComponentFunctionUPP(ComponentFunctionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline DEFINE_API(void)
      DisposeComponentFunctionUPP(ComponentFunctionUPP userUPP)
  {
    DisposeRoutineDescriptor(userUPP);
  }
#else
#define DisposeComponentFunctionUPP(userUPP) (DisposeRoutineDescriptor(userUPP))
#endif
#endif

#if TARGET_RT_MAC_CFM
  /**
      CallComponentUPP is a global variable exported from InterfaceLib.
      It is the ProcPtr passed to CallUniversalProc to manually call a component
     function.
  */
  /**
   *  CallComponentUPP
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  extern UniversalProcPtr CallComponentUPP;
#endif

#define ComponentCallNow(callNumber, paramSize)                                );

  /**
   *  RegisterComponentResource()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  Component
  RegisterComponentResource(ComponentResourceHandle cr, short global);

  /**
   *  UnregisterComponent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  OSErr
  UnregisterComponent(Component aComponent);

  /**
   *  FindNextComponent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  Component
  FindNextComponent(Component aComponent, ComponentDescription *looking);

  /**
   *  CountComponents()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  long
  CountComponents(ComponentDescription *looking);

  /**
   *  GetComponentInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  OSErr
  GetComponentInfo(Component aComponent, ComponentDescription *cd,
                   Handle componentName, Handle componentInfo,
                   Handle componentIcon);

  /**
   *  GetComponentListModSeed()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  long
  GetComponentListModSeed(void);

  /**
   *  GetComponentTypeModSeed()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 2.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  long
  GetComponentTypeModSeed(OSType componentType);

  /*********************************************************
   * Component Instance Allocation and dispatch routines
   ********************************************************/
  /**
   *  OpenAComponent()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 2.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  OSErr
  OpenAComponent(Component aComponent, ComponentInstance *ci);

  /**
   *  OpenComponent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  ComponentInstance
  OpenComponent(Component aComponent);

  /**
   *  CloseComponent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  OSErr
  CloseComponent(ComponentInstance aComponentInstance);

  /**
   *  GetComponentInstanceError()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  OSErr
  GetComponentInstanceError(ComponentInstance aComponentInstance);

  /*********************************************************
   * Component aliases
   ********************************************************/
  /**
   *  ResolveComponentAlias()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 3.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  Component
  ResolveComponentAlias(Component aComponent);

  /*********************************************************
   * Component public resources and public string lists
   ********************************************************/
  /** Note: GetComponentPublicResource returns a Handle, not a resource.  The
   * caller must dispose it with DisposeHandle. */
  /**
   *  GetComponentPublicResource()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 4.0 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetComponentPublicResource(Component aComponent, OSType resourceType,
                             short resourceID, Handle *theResource);

  /**
   *  GetComponentPublicResourceList()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 4.0 and later
   *    \carbon_lib        in CarbonLib 1.0.2 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetComponentPublicResourceList(OSType resourceType, short resourceID,
                                 long flags, ComponentDescription *cd,
                                 GetMissingComponentResourceUPP missingProc,
                                 void *refCon, void *atomContainerPtr);

  /**
   *  GetComponentPublicIndString()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 4.0 and later
   *    \carbon_lib        in CarbonLib 1.3 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  GetComponentPublicIndString(Component aComponent, Str255 theString,
                              short strListID, short index);

  /*********************************************************
   *                                                       *
   *                   CALLS MADE BY COMPONENTS            *
   *                                                       *
   ********************************************************/
  /*********************************************************
   * Component Management routines
   ********************************************************/
  /**
   *  SetComponentInstanceError()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  void
  SetComponentInstanceError(ComponentInstance aComponentInstance, OSErr theError);

  /**
   *  GetComponentRefcon()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  long
  GetComponentRefcon(Component aComponent);

  /**
   *  SetComponentRefcon()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  void
  SetComponentRefcon(Component aComponent, long theRefcon);

  /**
   *  OpenComponentResFile()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  short
  OpenComponentResFile(Component aComponent);

  /**
   *  OpenAComponentResFile()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 2.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  OSErr
  OpenAComponentResFile(Component aComponent, short *resRef);

  /**
   *  CloseComponentResFile()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  OSErr
  CloseComponentResFile(short refnum);

  /** Note: GetComponentResource returns a Handle, not a resource.  The caller
   * must dispose it with DisposeHandle. */
  /**
   *  GetComponentResource()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 3.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  OSErr
  GetComponentResource(Component aComponent, OSType resType, short resID,
                       Handle *theResource);

  /**
   *  GetComponentIndString()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 3.0 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  OSErr
  GetComponentIndString(Component aComponent, Str255 theString, short strListID,
                        short index);

  /*********************************************************
   * Component Instance Management routines
   ********************************************************/
  /**
   *  GetComponentInstanceStorage()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  Handle
  GetComponentInstanceStorage(ComponentInstance aComponentInstance);

  /**
   *  SetComponentInstanceStorage()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  void
  SetComponentInstanceStorage(ComponentInstance aComponentInstance,
                              Handle theStorage);

#if CALL_NOT_IN_CARBON
  /**
   *  GetComponentInstanceA5()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  long
  GetComponentInstanceA5(ComponentInstance aComponentInstance);

  /**
   *  SetComponentInstanceA5()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  void
  SetComponentInstanceA5(ComponentInstance aComponentInstance, long theA5);

#endif /** CALL_NOT_IN_CARBON */

  /**
   *  CountComponentInstances()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  long
  CountComponentInstances(Component aComponent);

  /** useful helper routines for convenient method dispatching */
  /**
   *  CallComponentFunction()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long
  CallComponentFunction(ComponentParameters *params, ComponentFunctionUPP func);

  /**
   *  CallComponentFunctionWithStorage()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  long
  CallComponentFunctionWithStorage(Handle storage, ComponentParameters *params,
                                   ComponentFunctionUPP func);

#if TARGET_CPU_PPC && TARGET_OS_MAC
  /**
   *  CallComponentFunctionWithStorageProcInfo()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 2.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  long
  CallComponentFunctionWithStorageProcInfo(Handle storage,
                                           ComponentParameters *params,
                                           ProcPtr func,
                                           ProcInfoType funcProcInfo);

#else
#define CallComponentFunctionWithStorageProcInfo(storage, params, func, \
                                                 funcProcInfo)          \
  CallComponentFunctionWithStorage(storage, params, func)

#endif /** TARGET_CPU_PPC && TARGET_OS_MAC */

  /**
   *  DelegateComponentCall()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  long
  DelegateComponentCall(ComponentParameters *originalParams, ComponentInstance ci);

  /**
   *  SetDefaultComponent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  OSErr
  SetDefaultComponent(Component aComponent, short flags);

  /**
   *  OpenDefaultComponent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  ComponentInstance
  OpenDefaultComponent(OSType componentType, OSType componentSubType);

  /**
   *  OpenADefaultComponent()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 2.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  OSErr
  OpenADefaultComponent(OSType componentType, OSType componentSubType,
                        ComponentInstance *ci);

  /**
   *  CaptureComponent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  Component
  CaptureComponent(Component capturedComponent, Component capturingComponent);

  /**
   *  UncaptureComponent()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  OSErr
  UncaptureComponent(Component aComponent);

  /**
   *  RegisterComponentResourceFile()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  long
  RegisterComponentResourceFile(short resRefNum, short global);

  /**
   *  GetComponentIconSuite()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  OSErr
  GetComponentIconSuite(Component aComponent, Handle *iconSuite);

  /*********************************************************
   *                                                       *
   *           Direct calls to the Components              *
   *                                                       *
   ********************************************************/
  /** Old style names*/

  /**
   *  ComponentFunctionImplemented()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  long
  ComponentFunctionImplemented(ComponentInstance ci, short ftnNumber);

  /**
   *  GetComponentVersion()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  long
  GetComponentVersion(ComponentInstance ci);

  /**
   *  ComponentSetTarget()
   *

   *    \non_carbon_cfm   in InterfaceLib 7.1 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  long
  ComponentSetTarget(ComponentInstance ci, ComponentInstance target);

  /** New style names*/

  /**
   *  CallComponentOpen()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 2.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  ComponentResult
  CallComponentOpen(ComponentInstance ci, ComponentInstance self);

  /**
   *  CallComponentClose()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 2.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  ComponentResult
  CallComponentClose(ComponentInstance ci, ComponentInstance self);

  /**
   *  CallComponentCanDo()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 2.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  ComponentResult
  CallComponentCanDo(ComponentInstance ci, short ftnNumber);

  /**
   *  CallComponentVersion()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 2.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  ComponentResult
  CallComponentVersion(ComponentInstance ci);

  /**
   *  CallComponentRegister()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 2.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  ComponentResult
  CallComponentRegister(ComponentInstance ci);

  /**
   *  CallComponentTarget()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 2.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  ComponentResult
  CallComponentTarget(ComponentInstance ci, ComponentInstance target);

  /**
   *  CallComponentUnregister()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 2.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  ComponentResult
  CallComponentUnregister(ComponentInstance ci);

  /**
   *  CallComponentGetMPWorkFunction()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 2.5 and later
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  ComponentResult
  CallComponentGetMPWorkFunction(ComponentInstance ci,
                                 ComponentMPWorkFunctionUPP *workFunction,
                                 void **refCon);

  /**
   *  CallComponentGetPublicResource()
   *

   *    \non_carbon_cfm   in InterfaceLib via QuickTime 4.0 and later
   *    \carbon_lib        in CarbonLib 1.1 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentResult
  CallComponentGetPublicResource(ComponentInstance ci, OSType resourceType,
                                 short resourceID, Handle *resource);

#if !TARGET_OS_MAC
/**
        CallComponent is used by ComponentGlue routines to manually call a
   component function.
     */
#if CALL_NOT_IN_CARBON
  /**
   *  CallComponent()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   *    Windows:          in qtmlClient.lib 3.0 and later
   */
  ComponentResult
  CallComponent(ComponentInstance ci, ComponentParameters *cp);

#endif /** CALL_NOT_IN_CARBON */

#endif /** !TARGET_OS_MAC */

  /**
      CallComponentDispatch is a CarbonLib routine that replaces CallComponent
     inline glue to call a component function.
   */
  /**
   *  CallComponentDispatch()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentResult
  CallComponentDispatch(ComponentParameters *cp);

  /** UPP call backs */
  /**
   *  NewComponentMPWorkFunctionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentMPWorkFunctionUPP
  NewComponentMPWorkFunctionUPP(ComponentMPWorkFunctionProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppComponentMPWorkFunctionProcInfo = 0x000003F0
  }; /** pascal 4_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ComponentMPWorkFunctionUPP
  NewComponentMPWorkFunctionUPP(ComponentMPWorkFunctionProcPtr userRoutine)
  {
    return (ComponentMPWorkFunctionUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppComponentMPWorkFunctionProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewComponentMPWorkFunctionUPP(userRoutine)                \
  (ComponentMPWorkFunctionUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppComponentMPWorkFunctionProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewComponentRoutineUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentRoutineUPP
  NewComponentRoutineUPP(ComponentRoutineProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppComponentRoutineProcInfo = 0x000003F0
  }; /** pascal 4_bytes Func(4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline ComponentRoutineUPP
  NewComponentRoutineUPP(ComponentRoutineProcPtr userRoutine)
  {
    return (ComponentRoutineUPP)NewRoutineDescriptor((ProcPtr)(userRoutine),
                                                     uppComponentRoutineProcInfo,
                                                     GetCurrentArchitecture());
  }
#else
#define NewComponentRoutineUPP(userRoutine)                               \
  (ComponentRoutineUPP) NewRoutineDescriptor((ProcPtr)(userRoutine),      \
                                             uppComponentRoutineProcInfo, \
                                             GetCurrentArchitecture())
#endif
#endif

  /**
   *  NewGetMissingComponentResourceUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  GetMissingComponentResourceUPP
  NewGetMissingComponentResourceUPP(
      GetMissingComponentResourceProcPtr userRoutine);
#if !OPAQUE_UPP_TYPES
  enum
  {
    uppGetMissingComponentResourceProcInfo = 0x0000FBE0
  }; /** pascal 2_bytes Func(4_bytes, 4_bytes, 2_bytes, 4_bytes, 4_bytes) */
#ifdef __cplusplus
  inline GetMissingComponentResourceUPP NewGetMissingComponentResourceUPP(
      GetMissingComponentResourceProcPtr userRoutine)
  {
    return (GetMissingComponentResourceUPP)NewRoutineDescriptor(
        (ProcPtr)(userRoutine), uppGetMissingComponentResourceProcInfo,
        GetCurrentArchitecture());
  }
#else
#define NewGetMissingComponentResourceUPP(userRoutine)                \
  (GetMissingComponentResourceUPP) NewRoutineDescriptor(              \
      (ProcPtr)(userRoutine), uppGetMissingComponentResourceProcInfo, \
      GetCurrentArchitecture())
#endif
#endif

  /**
   *  DisposeComponentMPWorkFunctionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeComponentMPWorkFunctionUPP(ComponentMPWorkFunctionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void
  DisposeComponentMPWorkFunctionUPP(ComponentMPWorkFunctionUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeComponentMPWorkFunctionUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeComponentRoutineUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeComponentRoutineUPP(ComponentRoutineUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void DisposeComponentRoutineUPP(ComponentRoutineUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeComponentRoutineUPP(userUPP) DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  DisposeGetMissingComponentResourceUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  void
  DisposeGetMissingComponentResourceUPP(GetMissingComponentResourceUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline void
  DisposeGetMissingComponentResourceUPP(GetMissingComponentResourceUPP userUPP)
  {
    DisposeRoutineDescriptor((UniversalProcPtr)userUPP);
  }
#else
#define DisposeGetMissingComponentResourceUPP(userUPP) \
  DisposeRoutineDescriptor(userUPP)
#endif
#endif

  /**
   *  InvokeComponentMPWorkFunctionUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentResult
  InvokeComponentMPWorkFunctionUPP(void *globalRefCon,
                                   ComponentMPWorkFunctionHeaderRecordPtr header,
                                   ComponentMPWorkFunctionUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline ComponentResult
  InvokeComponentMPWorkFunctionUPP(void *globalRefCon,
                                   ComponentMPWorkFunctionHeaderRecordPtr header,
                                   ComponentMPWorkFunctionUPP userUPP)
  {
    return (ComponentResult)CALL_TWO_PARAMETER_UPP(
        userUPP, uppComponentMPWorkFunctionProcInfo, globalRefCon, header);
  }
#else
#define InvokeComponentMPWorkFunctionUPP(globalRefCon, header, userUPP) \
  (ComponentResult) CALL_TWO_PARAMETER_UPP(                             \
      (userUPP), uppComponentMPWorkFunctionProcInfo, (globalRefCon), (header))
#endif
#endif

  /**
   *  InvokeComponentRoutineUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  ComponentResult
  InvokeComponentRoutineUPP(ComponentParameters *cp, Handle componentStorage,
                            ComponentRoutineUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline ComponentResult InvokeComponentRoutineUPP(ComponentParameters *cp,
                                                   Handle componentStorage,
                                                   ComponentRoutineUPP userUPP)
  {
    return (ComponentResult)CALL_TWO_PARAMETER_UPP(
        userUPP, uppComponentRoutineProcInfo, cp, componentStorage);
  }
#else
#define InvokeComponentRoutineUPP(cp, componentStorage, userUPP) \
  (ComponentResult) CALL_TWO_PARAMETER_UPP(                      \
      (userUPP), uppComponentRoutineProcInfo, (cp), (componentStorage))
#endif
#endif

  /**
   *  InvokeGetMissingComponentResourceUPP()
   *

   *    \non_carbon_cfm   available as macro/inline
   *    \carbon_lib        in CarbonLib 1.0 and later
   *    \mac_os_x         in version 10.0 and later
   */
  OSErr
  InvokeGetMissingComponentResourceUPP(Component c, OSType resType, short resID,
                                       void *refCon, Handle *resource,
                                       GetMissingComponentResourceUPP userUPP);
#if !OPAQUE_UPP_TYPES
#ifdef __cplusplus
  inline OSErr
  InvokeGetMissingComponentResourceUPP(Component c, OSType resType, short resID,
                                       void *refCon, Handle *resource,
                                       GetMissingComponentResourceUPP userUPP)
  {
    return (OSErr)CALL_FIVE_PARAMETER_UPP(userUPP,
                                          uppGetMissingComponentResourceProcInfo,
                                          c, resType, resID, refCon, resource);
  }
#else
#define InvokeGetMissingComponentResourceUPP(c, resType, resID, refCon,        \
                                             resource, userUPP)                \
  (OSErr) CALL_FIVE_PARAMETER_UPP((userUPP),                                   \
                                  uppGetMissingComponentResourceProcInfo, (c), \
                                  (resType), (resID), (refCon), (resource))
#endif
#endif

#if CALL_NOT_IN_CARBON || OLDROUTINENAMES
/** support for pre-Carbon UPP routines: New...Proc and Call...Proc */
#define NewComponentMPWorkFunctionProc(userRoutine) \
  NewComponentMPWorkFunctionUPP(userRoutine)
#define NewComponentRoutineProc(userRoutine) NewComponentRoutineUPP(userRoutine)
#define NewGetMissingComponentResourceProc(userRoutine) \
  NewGetMissingComponentResourceUPP(userRoutine)
#define CallComponentMPWorkFunctionProc(userRoutine, globalRefCon, header) \
  InvokeComponentMPWorkFunctionUPP(globalRefCon, header, userRoutine)
#define CallComponentRoutineProc(userRoutine, cp, componentStorage) \
  InvokeComponentRoutineUPP(cp, componentStorage, userRoutine)
#define CallGetMissingComponentResourceProc(userRoutine, c, resType, resID, \
                                            refCon, resource)               \
  InvokeGetMissingComponentResourceUPP(c, resType, resID, refCon, resource, \
                                       userRoutine)
#endif /** CALL_NOT_IN_CARBON */

  /** ProcInfos */

  /** MixedMode ProcInfo constants for component calls */
  enum
  {
    uppComponentFunctionImplementedProcInfo = 0x000002F0,
    uppGetComponentVersionProcInfo = 0x000000F0,
    uppComponentSetTargetProcInfo = 0x000003F0,
    uppCallComponentOpenProcInfo = 0x000003F0,
    uppCallComponentCloseProcInfo = 0x000003F0,
    uppCallComponentCanDoProcInfo = 0x000002F0,
    uppCallComponentVersionProcInfo = 0x000000F0,
    uppCallComponentRegisterProcInfo = 0x000000F0,
    uppCallComponentTargetProcInfo = 0x000003F0,
    uppCallComponentUnregisterProcInfo = 0x000000F0,
    uppCallComponentGetMPWorkFunctionProcInfo = 0x00000FF0,
    uppCallComponentGetPublicResourceProcInfo = 0x00003BF0
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

#endif /** __COMPONENTS__ */
