/**
     \file       USB.h

    \brief   Public API for USB Services Library (and associated components)

    \introduced_in  USB 1.4
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1998-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Hardware

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __USB__
#define __USB__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __NAMEREGISTRY__
#include <NameRegistry.h>
#endif

#ifndef __CODEFRAGMENTS__
#include <CodeFragments.h>
#endif

#ifndef __DEVICES__
#include <Devices.h>
#endif

#ifndef __MACERRORS__
#include <MacErrors.h>
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

  // ************* Constants *************
  enum
  {
    // Flags   kUSBTaskTimeFlag = 1,
    // Flags
    kUSBPowerReset = 4,
    kUSBHubReaddress = 8,
    kUSBAddressRequest = 16,
    kUSBReturnOnException = 32,
    kUSBNo5SecTimeout = 64,
    kUSBTimeout = 128,
    kUSBNoDataTimeout = 256,
    kUSBDebugAwareFlag = 512,
    kUSBResetDescriptorCache = 1024,
    kUSBHighSpeedFlag = 2048,
    kUSBDevZeroDetatch = 4096,
    kUSBLowSpeedFlag = 8192,
    kUSBTaskTimeSetAddressFlag = 16384
  };

  enum
  {
    // Hub messages   kUSBHubPortResetRequest = 1,
    kUSBHubPortSuspendRequest = 2,
    // Hub messages
  };

  enum
  {
    kVendorID_AppleComputer = 0x05AC
  };

  // ************* types *************
  typedef SInt32 USBReference;
  typedef USBReference USBDeviceRef;
  // ************* types *************
  typedef USBReference USBInterfaceRef;
  typedef USBReference USBPipeRef;
  typedef USBReference USBBusRef;
  typedef UInt32 USBPipeState;
  typedef UInt32 USBCount;
  typedef UInt32 USBFlags;
  typedef UInt8 USBRequest;
  typedef UInt8 USBDirection;
  typedef UInt8 USBRqRecipient;
  typedef UInt8 USBRqType;
  typedef UInt16 USBRqIndex;
  typedef UInt16 USBRqValue;

  struct usbControlBits
  {
    UInt8 BMRequestType;
    UInt8 BRequest;
    USBRqValue WValue;
    USBRqIndex WIndex;
    UInt16 reserved4;
  };
  typedef struct usbControlBits usbControlBits;
  struct USBIsocFrame
  {
    OSStatus frStatus;
    UInt16 frReqCount;
    UInt16 frActCount;
  };
  typedef struct USBIsocFrame USBIsocFrame;
  enum
  {
    kUSBMaxIsocFrameReqCount =
        1023 // maximum size (bytes) of any one Isoc frame};

    struct usbIsocBits{
        USBIsocFrame * FrameList;
        UInt32 Nu // maximum size (bytes) of any one Isoc frame
    };
  typedef struct usbIsocBits usbIsocBits;
  struct usbHubBits
  {
    UInt32 Request;
    UInt32 Spare;
  };
  typedef struct usbHubBits usbHubBits;
  typedef struct USBPB USBPB;
  typedef CALLBACK_API_C(void, USBCompletion)(USBPB *pb);
  union USBVariantBits
  {
    usbControlBits cntl;
    usbIsocBits isoc;
    usbHubBits hub;
  };
  typedef union USBVariantBits USBVariantBits;
  struct USBPB
  {

    void *qlink;
    UInt16 qType;
    UInt16 pbLength;
    UInt16 pbVersion;
    UInt16 reserved1;
    UInt32 reserved2;

    OSStatus usbStatus;
    USBCompletion usbCompletion;
    UInt32 usbRefcon;

    USBReference usbReference;

    void *usbBuffer;
    USBCount usbReqCount;
    USBCount usbActCount;

    USBFlags usbFlags;

    USBVariantBits usb;

    UInt32 usbFrame;

    UInt8 usbClassType;
    UInt8 usbSubclass;
    UInt8 usbProtocol;
    UInt8 usbOther;

    UInt32 reserved6;
    UInt16 reserved7;
    UInt16 reserved8;
  };

  typedef USBPB *USBPBPtr;
#if !defined(OLDUSBNAMES)
#define OLDUSBNAMES 0
#endif

#if OLDUSBNAMES
#define usbBMRequestType usb.cntl.BMRequestType
#define usbBRequest usb.cntl.BRequest
#define usbWValue usb.cntl.WValue
#define usbWIndex usb.cntl.WIndex
#endif
  struct uslReq
  {
    USBDirection usbDirection;
    USBRqType usbType;
    USBRqRecipient usbRecipient;
    USBRequest usbRequest;
  };
  typedef struct uslReq uslReq;

  enum
  {
    // BT 19Aug98, bump up to v1.10 for Isoc  kUSBCurrentPBVersion = 0x0100, // v1.00  kUSBIsocPBVersion = 0x0109,    // v1.10  kUSBCurrentHubPB = kUSBIsocPBVersion
  };

#define kUSBNoCallBack ((USBCompletion)-1L)

  ty                     // BT 19Aug98, bump up to v1.10 for Isoc
      enum {             // v1.00
        kUSBControl = 0, // v1.10
        kUSBIsoc = 1,
        kUSBBulk = 2,
        kUSBInterrupt = 3,
        kUSBAnyType = 0xFF
      };

  // endpoint type enum { kUSBOut = 0, kUSBIn = 1, kUSBNone = 2, kUSBAnyDirn = 3 };

  // USBDirection
  enum
  {
    kUSBStandard = 0,
    kUSBClass = 1,
    kUSBVendor = 2
  };

  // USBRqType
  enum
  {
    kUSBDevice = 0,
    kUSBInterface = 1,
    kUSBEndpoint = 2,
    kUSBOther = 3
  };

  // endpoint type
  enum
  {
    kUSBRqGetStatus = 0,
    kUSBRqClearFeature = 1,
    kUSBRqReserved1 = 2,
    kUSBRqSetFeature = 3,
    kUSBRqReserved2 = 4,
    kUSBRqSetAddress = 5,
    kUSBRqGetDescriptor = 6,
    kUSBRqSetDescriptor = 7,
    kUSBRqGetConfig = 8,
    kUSBRqSetConfig = 9,
    kUSBRqGetInterface = 10,
    kUSBRqSetInterface = 11,
    kUSBRqSyncFrame = 12
  };

  // USBRequest

  enum
  {
    kUSBDeviceDesc = 1,
    kUSBConfDesc = 2,
    kUSBStringDesc = 3,
    kUSBInterfaceDesc = 4,
    kUSBEndpointDesc = 5,
    kUSBHIDDesc = 0x21,
    kUSBReportDesc = 0x22,
    kUSBPhysicalDesc = 0x23,
    kUSBHUBDesc = 0x29
  };

  // descriptorType
  enum
  {
    kUSBFeatureDeviceRemoteWakeup = 1,
    kUSBFeatureEndpointStall = 0
  };

  // Feature selectors enum {
  kUSBActive = 0, // Pipe can accept new transactions  kUSBIdle = 1,       // Pipe will not accept new transactions  kUSBStalled = 2,    // An error occured on the pipe  kUSBSuspended = 4,  // Device is suspended  kUSBNoBandwidth = 8 /* (Isoc or Int) Pipe could not be initialised due to
      bandwidth constraint * /
};

enum
{
  // descriptorType
  kUSB500mAAvailable = 250,
  kUSB100mA = 50,
  kUSBAtrBusPowered = 0x80,
  // Feature selectors
  kUSBAtrRemoteWakeup = 0x20
}; // Pipe can accept new transactions
// Pipe will not accept new transactions
enum
{
  kUSBRel10 = 0x0 // An error occured on the pipe
// Device is suspended
#define USB_CONSTANT16(x) ((((x) >> 8) & 0x0ff) | ((x & 0xff) << 8))
  enum {
      kUSBDeviceDescriptorLength = 0x12,
      kUSBInterfaceDescriptorLength = 0x09,
      kUSBConfigDescriptorLength = 0x09};

  struct USBDeviceDescriptor{UInt8 length; UInt8 descType; UInt16 usbRel; UInt8 deviceClass; UInt8 deviceSubClass; UInt8 protocol; UInt8 maxPacketSize; UInt16 vendor; UInt16 product; UInt16 devRel; UInt8 manuIdx; UInt8 prodIdx; UInt8 serialIdx; UInt8 numConf;};
typedef struct USBDeviceDescriptor USBDeviceDescriptor;
typedef USBDeviceDescriptor *USBDeviceDescriptorPtr;
struct USBDescriptorHeader
{
  UInt8 length;
  UInt8 descriptorType;
};
typedef struct USBDescriptorHeader USBDescriptorHeader;
typedef USBDescriptorHeader *USBDescriptorHeaderPtr;
struct USBConfigurationDescriptor
{
  UInt8 length;
  UInt8 descriptorType;
  UInt16 totalLength;
  UInt8 numInterfaces;
  UInt8 configValue;
  UInt8 configStrIndex;
  UInt8 attributes;
  UInt8 maxPower;
};
typedef struct USBConfigurationDescriptor USBConfigurationDescriptor;
typedef USBConfigurationDescriptor *USBConfigurationDescriptorPtr;
struct USBInterfaceDescriptor
{
  UInt8 length;
  UInt8 descriptorType;
  UInt8 interfaceNumber;
  UInt8 alternateSetting;
  UInt8 numEndpoints;
  UInt8 interfaceClass;
  UInt8 interfaceSubClass;
  UInt8 interfaceProtocol;
  UInt8 interfaceStrIndex;
};
typedef struct USBInterfaceDescriptor USBInterfaceDescriptor;
typedef USBInterfaceDescriptor *USBInterfaceDescriptorPtr;
struct USBEndPointDescriptor
{
  UInt8 length;
  UInt8 descriptorType;
  UInt8 endpointAddress;
  UInt8 attributes;
  UInt16 maxPacketSize;
  UInt8 interval;
};
typedef struct USBEndPointDescriptor USBEndPointDescriptor;
typedef USBEndPointDescriptor *USBEndPointDescriptorPtr;
struct USBHIDDescriptor
{
  UInt8 descLen;
  UInt8 descType;
  UInt16 descVersNum;
  UInt8 hidCountryCode;
  UInt8 hidNumDescriptors;
  UInt8 hidDescriptorType;
  UInt8 hidDescriptorLengthLo; /* can't make this a single 16bit value or the
                                  compiler will add a filler byte*/
  UInt8 hidDescriptorLengthHi;
};
typedef struct USBHIDDescriptor USBHIDDescriptor;
typedef USBHIDDescriptor *USBHIDDescriptorPtr;
struct USBHIDReportDesc
{
  UInt8 hidDescriptorType;
  UInt8 hidDescriptorLengthLo; /* can't make this a single 16bit value or the
                                  compiler will add a filler byte*/
  UInt8 hidDescriptorLengthHi;
};
typedef struct USBHIDReportDesc USBHIDReportDesc;
typedef USBHIDReportDesc *USBHIDReportDescPtr;
struct USBHubPortStatus
{
  UInt16 portFlags; // Port status flags   UInt16 portChangeFlags; // Port changed flags };
  typedef struct USBHubPortStatus USBHubPortStatus;
  typedef USBHubPortStatus *USBHubPortStatusPtr;
  // ********* ProtoTypes *************** // For dealing with endianisms #if CALL_NOT_IN_CARBON
  /**
   *  HostToUSBWord()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt16
  HostToUSBWord(UInt16 value);

  /**/ / Port status flags *USBToHostWord() // Port changed flags
          *
          *Availability : *    \non_carbon_cfm in USBServicesLib 1.0 and
      later
              // ********* ProtoTypes ***************
              // For dealing with endianisms
              * /
          UInt16
          USBToHostWord(UInt16 value);

  /**
   *  HostToUSBLong()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt32
  HostToUSBLong(UInt32 value);

  /**
   *  USBToHostLong()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt32
  USBToHostLong(UInt32 value);

  // Main prototypes // Transfer commands /**
  *USBDeviceRequest() *
          *Availability : *    \non_carbon_cfm in USBServicesLib 1.0 and
      later
              *    \carbon_lib not available
          *    \mac_os_x not available
          * /
          OSStatus
          USBDeviceRequest(USBPB * pb);

  /**
   *  USBBulkWrite()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  // Main prototypes
  // Transfer commands

  /**
   *  USBBulkRead()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBBulkRead(USBPB *pb);

  /**
   *  USBIntRead()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBIntRead(USBPB *pb);

  /**
   *  USBIntWrite()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.2 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBIntWrite(USBPB *pb);

  /**
   *  USBIsocRead()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBIsocRead(USBPB *pb);

  /**
   *  USBIsocWrite()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.1 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBIsocWrite(USBPB *pb);

  // Pipe state control /**
  *USBClearPipeStallByReference() *
          *Availability : *    \non_carbon_cfm in USBServicesLib 1.0 and
      later
              *    \carbon_lib not available
          *    \mac_os_x not available
          * /
          OSStatus
          USBClearPipeStallByReference(USBPipeRef ref);

  /**
   *  USBAbortPipeByReference()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBAbortPipeByReference(USBReference ref);
  // Pipe state control
  /**
   *  USBResetPipeByReference()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBResetPipeByReference(USBReference ref);

  /**
   *  USBSetPipeIdleByReference()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBSetPipeIdleByReference(USBPipeRef ref);

  /**
   *  USBSetPipeActiveByReference()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBSetPipeActiveByReference(USBPipeRef ref);

  /**
   *  USBClosePipeByReference()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBClosePipeByReference(USBPipeRef ref);

  /**
   *  USBGetPipeStatusByReference()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBGetPipeStatusByReference(USBReference ref, USBPipeState *state);

  // Configuration services /**
  *USBFindNextInterface() *
          *Availability : *    \non_carbon_cfm in USBServicesLib 1.0 and
      later
              *    \carbon_lib not available
          *    \mac_os_x not available
          * /
          OSStatus
          USBFindNextInterface(USBPB * pb);

  /**
   *  USBOpenDevice()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBOpenDevice(USBPB *pb);

  // Configuration services
  *USBSetConfiguration() *
          *Availability : *    \non_carbon_cfm in USBServicesLib 1.1 and
      later
              *    \carbon_lib not available
          *    \mac_os_x not available
          * /
          OSStatus
          USBSetConfiguration(USBPB * pb);

  /**
   *  USBNewInterfaceRef()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBNewInterfaceRef(USBPB *pb);

  /**
   *  USBDisposeInterfaceRef()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBDisposeInterfaceRef(USBPB *pb);

  /**
   *  USBConfigureInterface()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBConfigureInterface(USBPB *pb);

  /**
   *  USBFindNextPipe()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBFindNextPipe(USBPB *pb);

  /**
   *  USBSetPipePolicy()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.4 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBSetPipePolicy(USBPB *pb);

  // Dealing with descriptors. // Note most of this is temprorary /**
  *USBGetConfigurationDescriptor() *
          *Availability : *    \non_carbon_cfm in USBServicesLib 1.0 and
      later
              *    \carbon_lib not available
          *    \mac_os_x not available
          * /
          OSStatus
          USBGetConfigurationDescriptor(USBPB * pb);

  /**
   *  USBGetFullConfigurationDescriptor()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBGetFullConfigurationDescriptor(USBPB *pb);

  /**
  // Dealing with descriptors.
  // Note most of this is temprorary
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBGetStringDescriptor(USBPB *pb);

  /**
   *  USBFindNextEndpointDescriptorImmediate()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBFindNextEndpointDescriptorImmediate(USBPB *pb);

  /**
   *  USBFindNextInterfaceDescriptorImmediate()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBFindNextInterfaceDescriptorImmediate(USBPB *pb);

  /**
   *  USBFindNextAssociatedDescriptor()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBFindNextAssociatedDescriptor(USBPB *pb);

  // Utility functions /**
  *USBResetDevice() *
          *Availability : *    \non_carbon_cfm in USBServicesLib 1.1 and
      later
              *    \carbon_lib not available
          *    \mac_os_x not available
          * /
          OSStatus
          USBResetDevice(USBPB * pb);

  /**
   *  USBPortStatus()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.4 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBPortStatus(USBPB *pb);

  /**
   *  USBSuspendDevice()
   *
  // Utility functions
   *    \non_carbon_cfm   in USBServicesLib 1.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBSuspendDevice(USBPB *pb);

  /**
   *  USBResumeDeviceByReference()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBResumeDeviceByReference(USBReference refIn);

  /**
   *  USBGetBandwidthAvailableByReference()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.4 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBGetBandwidthAvailableByReference(USBReference ref, UInt32 *avail);

  /**
   *  USBGetFrameNumberImmediate()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBGetFrameNumberImmediate(USBPB *pb);

  /**
   *  USBDelay()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBDelay(USBPB *pb);

  /**
   *  USBSAbortQueuesByReference()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBSAbortQueuesByReference(USBReference ref);

  /**
   *  USBAllocMem()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBAllocMem(USBPB *pb);

  /**
   *  USBDeallocMem()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBDeallocMem(USBPB *pb);

  // Expert interface functions /**
  *USBExpertInstallInterfaceDriver() *
          *Availability : *    \non_carbon_cfm in USBServicesLib 1.0 and
      later
              *    \carbon_lib not available
          *    \mac_os_x not available
          * /
          OSStatus
          USBExpertInstallInterfaceDriver(USBDeviceRef ref, USBDeviceDescriptorPtr desc,
                                          USBInterfaceDescriptorPtr interfacePtr,
                                          USBReference hubRef, UInt32 busPowerAvailable);

  /**
   *  USBExpertRemoveInterfaceDriver()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBExpertRemoveInterfaceDriver(USBDeviceRef ref);

  /**
   *  USBExpertInstallDeviceDriver()
  // Expert interface functions
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBExpertInstallDeviceDriver(USBDeviceRef ref, USBDeviceDescriptorPtr desc,
                               USBReference hubRef, UInt32 port,
                               UInt32 busPowerAvailable);

  /**
   *  USBExpertRemoveDeviceDriver()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBExpertRemoveDeviceDriver(USBDeviceRef ref);

  /**
   *  USBExpertStatus()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBExpertStatus(USBDeviceRef ref, void *pointer, UInt32 value);

  /**
   *  USBExpertFatalError()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBExpertFatalError(USBDeviceRef ref, OSStatus status, void *pointer,
                      UInt32 value);

  /**
   *  USBExpertNotify()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBFamilyExpertLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBExpertNotify(void *note);

  /**
   *  USBExpertStatusLevel()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.2 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBExpertStatusLevel(UInt32 level, USBDeviceRef ref, StringPtr status,
                       UInt32 value);

  /**
   *  USBExpertGetStatusLevel()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt32
  USBExpertGetStatusLevel(void);

  /**
   *  USBExpertSetStatusLevel()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.3 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  void
  USBExpertSetStatusLevel(UInt32 level);

  /**
   *  USBExpertSetDevicePowerStatus()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBExpertSetDevicePowerStatus(USBDeviceRef ref, UInt32 reserved1,
                                UInt32 reserved2, UInt32 powerStatus,
                                UInt32 busPowerAvailable, UInt32 busPowerNeeded);

#endif // CALL_NOT_IN_CARBON
  enum
  {
    kUSBDevicePower_PowerOK = 0,
    kUSBDevicePower_BusPowerInsufficient = 1,
    kUSBDevicePower_BusPowerNotAllFeatures = 2,
    kUSBDevicePower_SelfPowerInsufficient = 3,
    kUSBDevicePower_SelfPowerNotAllFeatures = 4,
    kUSBDevicePower_HubPortOk = 5,
    kUSBDevicePower_HubPortOverCurrent = 6,
    kUSBDevicePower_BusPoweredHubOnLowPowerPort = 7,
    kUSBDevicePower_BusPoweredHubToBusPoweredHub = 8,
    kUSBDevicePower_Reserved3 = 9,
    kUSBDevicePower_Reserved4 = 10
  };

  // For hubs only #if CALL_NOT_IN_CARBON
  /**
   *  USBHubAddDevice()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBHubAddDevice(USBPB *pb);

  /**/ / CALL_NOT_IN_CARBON *USBHubConfigurePipeZero() *
          *Availability : *    \non_carbon_cfm in USBServicesLib 1.0 and
      later
              *    \carbon_lib not available
          *    \mac_os_x not available
          * /
          OSStatus
          USBHubConfigurePipeZero(USBPB * pb);

  /**
   *  USBHubSetAddress()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
  // For hubs only
   *    \mac_os_x         not available
   */
  OSStatus
  USBHubSetAddress(USBPB *pb);

  /**
   *  USBHubDeviceRemoved()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBHubDeviceRemoved(USBPB *pb);

  /**
   *  USBMakeBMRequestType()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.0 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  UInt8
  USBMakeBMRequestType(UInt8 direction, UInt8 reqtype, UInt8 recipient);

  /**
   *  USBControlRequest()
   *
   *  Availability:
   *    \non_carbon_cfm   in USBServicesLib 1.2 and later
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  OSStatus
  USBControlRequest(USBPB *pb);

#endif // CALL_NOT_IN_CARBON
  typedef UInt32 USBLocationID;
  enum
  {
    kUSBLocationNibbleFormat =
        0 /* Other values are reserved for future types (like when we have more
             than 16 ports per hub)*/
  };

  enum
  {
    kNoDeviceRef = -1
  };

  // Status Level constants/**
  Level 1 : Fatal errors
                Level 2 : General errors that may or
                          may not effect operation
                                  Level 3 : General driver messages.The "AddStatus" call that drivers use comes
                                                through as a level 3. This is also the default level at boot time.Level 4 : Important status messages from the Expert and
                              USL.Level 5 : General status
                                                messages from the Expert and
                              USL.* /
                                  enum {
                                    kUSBStatusLevelFatal = 1,
                                    kUSBStatusLevelError = 2,
                                    kUSBStatusLevelClient = 3,
                                    kUSBStatusLevelGeneral = 4,
                                    kUSBStatusLevelVerbose = 5
                                  };

  // Expert Notification Typestypedef UInt8 USBNotificationType;
  enum
  {
    kNotifyAddDevice = 0x00,
    kNoti // CALL_NOT_IN_CARBON
        kNotifyAddInterface = 0x02,
    kNotifyRemoveInterface = 0x03,
    kNotifyGetDeviceDescriptor = 0x04,
    kNotifyGetInterfaceDescriptor = 0x05,
    kNotifyGetNextDeviceByClass = 0x06,
    kNotifyGetDriverConnectionID = 0x07,
    kNotifyInstallDeviceNotification = 0x08,
    kNotifyRemoveDeviceNotification = 0x09,
    kNotifyDeviceRefToBusRef = 0x0A,
    kNotifyDriverNotify = 0x0C,
    // Status Level constants
    kNotifyAnyEvent = 0xFF,
    kNotifyPowerState = 0x17,
    kNotifyStatus = 0x18,
    kNotifyFatalError = 0x19,
    kNotifyStatusLevel = 0x20
  };

  typedef USBNotificationType USBDriverMessage;
  /**
     USB Manager wildcard constants for USBGetNextDeviceByClass
     and USBInstallDeviceNotification.
  */
  typedef UInt16 USBManagerWildcard;
  enum
  {
    kUSBAnyClass = 0xFFFF,
    kUSBAnySubClass = 0xFFFF,
    // Expert Notification Types
    kUSBAnyVendor = 0xFFFF,
    kUSBAnyProduct = 0xFFFF
  };

  struct ExpertNotificationData
  {
    USBNotificationType notification;
    UInt8 filler[1]; // unused due to 2-byte 68k alignment  USBDeviceRef *deviceRef;
    UInt32 busPowerAvailable;
    void *data;
    UInt32 info1;
    UInt32 info2;
  };
  typedef struct ExpertNotificationData ExpertNotificationData;
  typedef ExpertNotificationData *ExpertNotificationDataPtr;
  // Definition of function pointer passed in ExpertEntryProctypedef CALLBACK_API_C(OSStatus, ExpertNotificationProcPtr)(
    ExpertNotificationDataPtr pNotificationData);
    // Definition of expert's callback installation functiontypedef CALLBACK_API_C(OSStatus, ExpertEntryProcPtr)(
    ExpertNotificationProcPtr pExpertNotify);
    // Device Notification Callback Routinetypedef CALLBACK_API_C(void, USBDeviceNotificationCallbackProcPtr)(void *pb);
    // Device Notification Parameter Blockstruct USBDeviceNotificationParameterBlock {
    UInt16 pbLength;
    UInt16 pbVersion;
    USBNotificationType usbDeviceNotification;
    UInt8 reserved1[1]; // needed because of 2-byte 68k alignment  USBDeviceRef usbDeviceRef;
    UInt16 usbClass;
    UInt16 usbSubClass;
    UInt16 usbProtocol;
    UInt16 usbVendor;
    UInt16 usbProduct;
    OSStatus result;
    UInt32 token;
    USBDeviceNotificationCallbackProcPtr callback;
    UInt32 refcon;
};
typedef struct USBDeviceNotificationParameterBlock
    USBDeviceNotificationParameterBlock;
typedef USBDeviceNotificationParameterBlock
    *USBDeviceNotificationParameterBlockPtr;
// Definition of US// unused due to 2-byte 68k alignment
                                                               UInt32 refcon);
                                                               // Public Functions#if CALL_NOT_IN_CARBON
                                                               /**
                                                                *  USBGetVersion()
                                                                *
                                                                *  Availability:
                                                                *    \non_carbon_cfm   in USBServicesLib 1.3 and later
                                                                *    \carbon_lib        not available
                                                               // Definition of function pointer passed in ExpertEntryProc
                                                                */
                                                               UInt32
                                                                   // Definition of expert's callback installation function

                                                                   /**
                                                                   // Device Notification Callback Routine
                                                                    *
                                                                   // Device Notification Parameter Block
                                                                    *    \non_carbon_cfm   in USBManagerLib 1.0 and later
                                                                    *    \carbon_lib        not available
                                                                    *    \mac_os_x         not available
                                                                    */
                                                                   OSStatus // needed because of 2-byte 68k alignment
                                                                   USBGetNextDeviceByClass(USBDeviceRef *deviceRef, CFragConnectionID *connID,
                                                                                           UInt16 theClass, UInt16 theSubClass,
                                                                                           UInt16 theProtocol);

                                                               /**
                                                                *  USBGetDeviceDescriptor()
                                                                *
                                                                *  Availability:
                                                                *    \non_carbon_cfm   in USBManagerLib 1.0 and later
                                                                *    \carbon_lib        not available
                                                                *    \mac_os_x         not available
                                                                */
                                                               OSStatus
                                                               USBGetDeviceDescriptor(USBDeviceRef *deviceRef,
                                                                                      USBDeviceDescriptor *deviceDescriptor, UInt32 size);
                                                               // Definition of USBDriverNotificationCallback Routine
                                                               /**
                                                                *  USBGetInterfaceDescriptor()
                                                               // Public Functions
                                                                *  Availability:
                                                                *    \non_carbon_cfm   in USBManagerLib 1.0 and later
                                                                *    \carbon_lib        not available
                                                                *    \mac_os_x         not available
                                                                */
                                                               OSStatus
                                                               USBGetInterfaceDescriptor(USBInterfaceRef *interfaceRef,
                                                                                         USBInterfaceDescriptor *interfaceDescriptor,
                                                                                         UInt32 size);

                                                               /**
                                                                *  USBGetDriverConnectionID()
                                                                *
                                                                *  Availability:
                                                                *    \non_carbon_cfm   in USBManagerLib 1.0 and later
                                                                *    \carbon_lib        not available
                                                                *    \mac_os_x         not available
                                                                */
                                                               OSStatus
                                                               USBGetDriverConnectionID(USBDeviceRef *deviceRef, CFragConnectionID *connID);

                                                               /**
                                                                *  USBInstallDeviceNotification()
                                                                *
                                                                *  Availability:
                                                                *    \non_carbon_cfm   in USBManagerLib 1.0 and later
                                                                *    \carbon_lib        not available
                                                                *    \mac_os_x         not available
                                                                */
                                                               void
                                                               USBInstallDeviceNotification(USBDeviceNotificationParameterBlock *pb);

                                                               /**
                                                                *  USBRemoveDeviceNotification()
                                                                *
                                                                *  Availability:
                                                                *    \non_carbon_cfm   in USBManagerLib 1.0 and later
                                                                *    \carbon_lib        not available
                                                                *    \mac_os_x         not available
                                                                */
                                                               OSStatus
                                                               USBRemoveDeviceNotification(UInt32 token);

                                                               /**
                                                                *  USBDeviceRefToBusRef()
                                                                *
                                                                *  Availability:
                                                                *    \non_carbon_cfm   in USBManagerLib 1.0 and later
                                                                *    \carbon_lib        not available
                                                                *    \mac_os_x         not available
                                                                */
                                                               OSStatus
                                                               USBDeviceRefToBusRef(USBDeviceRef *deviceRef, USBBusRef *busRef);

                                                               /**
                                                                *  USBDriverNotify()
                                                                *
                                                                *  Availability:
                                                                *    \non_carbon_cfm   in USBManagerLib 1.1 and later
                                                                *    \carbon_lib        not available
                                                                *    \mac_os_x         not available
                                                                */
                                                               OSStatus
                                                               USBDriverNotify(USBReference reference, USBDriverMessage mesg, UInt32 refcon,
                                                                               USBDriverNotificationCallbackPtr callback);

                                                               /**
                                                                *  USBExpertNotifyParent()
                                                                *
                                                                *  Availability:
                                                                *    \non_carbon_cfm   in USBManagerLib 1.1 and later
                                                                *    \carbon_lib        not available
                                                                *    \mac_os_x         not available
                                                                */
                                                               OSStatus
                                                               USBExpertNotifyParent(USBReference reference, void *pointer);

                                                               /**
                                                                *  USBAddDriverForFSSpec()
                                                                *
                                                                *  Availability:
                                                                *    \non_carbon_cfm   in USBManagerLib 1.3 and later
                                                                *    \carbon_lib        not available
                                                                *    \mac_os_x         not available
                                                                */
                                                               OSStatus
                                                               USBAddDriverForFSSpec(USBReference reference, FSSpec *fileSpec);

                                                               /**
                                                                *  USBAddShimFromDisk()
                                                                *
                                                                *  Availability:
                                                                *    \non_carbon_cfm   in USBManagerLib 1.4 and later
                                                                *    \carbon_lib        not available
                                                                *    \mac_os_x         not available
                                                                */
                                                               OSStatus
                                                               USBAddShimFromDisk(FSSpec *shimFilePtr);

                                                               /**
                                                                *  USBReferenceToRegEntry()
                                                                *
                                                                *  Availability:
                                                                *    \non_carbon_cfm   in USBManagerLib 1.4 and later
                                                                *    \carbon_lib        not available
                                                                *    \mac_os_x         not available
                                                                */
                                                               OSStatus
                                                               USBReferenceToRegEntry(RegEntryID *parentEntry, USBDeviceRef parentDeviceRef);

                                                               /**
                                                                *  USBConfigureADBShim()
                                                                *
                                                                *  Availability:
                                                                *    \non_carbon_cfm   in USBManagerLib 1.4 and later
                                                                *    \carbon_lib        not available
                                                                *    \mac_os_x         not available
                                                                */
                                                               OSStatus
                                                               USBConfigureADBShim(UInt32 inCommandID, void *arg1, void *arg2);

#endif // CALL_NOT_IN_CARBON
                                                               typedef CALLBACK_API_C(void, HIDInterruptProcPtr)(UInt32 refcon, void *theData);
                                                               typedef CALLBACK_API_C(void,
                                                                                      HIDNotificationProcPtr)(UInt32 refcon, UInt32 reportSize,
                                                                                                              void *theReport,
                                                                                                              USBReference theInterfaceRef);
                                                               // HID Install Interrupt prototypetypedef CALLBACK_API_C(OSStatus, USBHIDInstallInterruptProcPtr)(
    HIDInterruptProcPtr pInterruptProc, UInt32 refcon);
    // HID Poll Device prototypetypedef CALLBACK_API_C(OSStatus, USBHIDPollDeviceProcPtr)(void);
    // HID Control Device prototypetypedef CALLBACK_API_C(OSStatus,
                       USBHIDControlDeviceProcPtr)(UInt32 theControlSelector,
                                                   void *theControlData);
                       // HID Get Device Info prototypetypedef CALLBACK_API_C(OSStatus,
                       USBHIDGetDeviceInfoProcPtr)(UInt32 theInfoSelector,
                                                   void *theInfo);
                       // HID Enter Polled Mode prototypetypedef CALLBACK_API_C(OSStatus, USBHIDEnterPolledModeProcPtr)(void);
                       // HID Exit Polled Mode prototypetypedef CALLBACK_API_C(OSStatus, USBHIDExitPolledModeProcPtr)(void);
                       // HID Install Notification prototypetypedef CALLBACK_API_C(OSStatus, USBHIDInstallNotificationProcPtr)(
    HIDNotificationProcPtr pNotificationProc, UInt32 refcon);
    enum
    {
      kHIDStandardDispatchVersion = 0,
      kHIDReservedDispatchVersion = 1,
      kHIDNotificationDispatchVersion = 2,
      kHIDCurrentDispatchVersion = 2
    };

    struct USBHIDRev2DispatchTable
    {
      UInt32 hidDispatchVersion;
      USBHIDInstallInterruptProcPtr pUSBHIDInstallInterrupt;
      USBHIDPollDeviceProcPtr pUSBHIDPollDevice;
      USBHIDControlDeviceProcPtr pUSBHIDControlDevice;
      USBHIDGetDeviceInfoProcPtr pUSBHIDGetDeviceInfo;
      USBHIDEnterPolledModeProcPtr pUSBHIDEnterPolledMode;
      USBHIDExitPolledModeProcPtr pUSBHIDExitPolledMode;
      USBHIDInstallNotificationProcPtr pUSBHIDInstallNotification;
    };
    typedef struct USBHIDRev2DispatchTable USBHIDRev2DispatchTable;
    typedef USBHIDRev2DispatchTable *USBHIDRev2DispatchTablePtr;
    struct USBHIDModuleDispatchTable
    {
      UInt32 hidDispatchVersion;
      USBHI // CALL_NOT_IN_CARBON
          USBHIDPollDeviceProcPtr pUSBHIDPollDevice;
      USBHIDControlDeviceProcPtr pUSBHIDControlDevice;
      USBHIDGetDeviceInfoProcPtr pUSBHIDGetDeviceInfo;
      USBHIDEnterPolledModeProcPtr pUSBHIDEnterPolledMode;
      USBHIDExitPolledModeProcPtr pUSBHIDExitPolledMode;
    };
    // HID Install Interrupt prototype
    typedef USBHIDModuleDispatchTable *USBHIDModuleDispatchTablePtr;
    //  Prototypes Tue, Mar 17, 1998 4:54:30 PM #if CALL_NOT_IN_CARBON
    // HID Poll Device prototype
    *USBHIDInstallInterrupt()
        // HID Control Device prototype
        * Availability : *    \non_carbon_cfm not available
                         *    \carbon_lib not available
                         // HID Get Device Info prototype
                         *
                         /
                         OSStatus
                         USBHIDInstallInterrupt(HIDInterruptProcPtr HIDInterruptFunction, UInt32 refcon);
    // HID Enter Polled Mode prototype
    /**
    // HID Exit Polled Mode prototype
     *
    // HID Install Notification prototype
     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSStatus
    USBHIDPollDevice(void);

    /**
     *  USBHIDControlDevice()
     *
     *  Availability:
     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSStatus
    USBHIDControlDevice(UInt32 theControlSelector, void *theControlData);

    /**
     *  USBHIDGetDeviceInfo()
     *
     *  Availability:
     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSStatus
    USBHIDGetDeviceInfo(UInt32 theInfoSelector, void *theInfo);

    /**
     *  USBHIDEnterPolledMode()
     *
    //  Prototypes Tue, Mar 17, 1998 4:54:30 PM
     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSStatus
    USBHIDEnterPolledMode(void);

    /**
     *  USBHIDExitPolledMode()
     *
     *  Availability:
     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSStatus
    USBHIDExitPolledMode(void);

    /**
     *  USBHIDInstallNotification()
     *
     *  Availability:
     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    OSStatus
    USBHIDInstallNotification(HIDNotificationProcPtr HIDNotificationFunction,
                              UInt32 refcon);

    /**
     *  HIDNotification()
     *
     *  Availability:
     *    \non_carbon_cfm   not available
     *    \carbon_lib        not available
     *    \mac_os_x         not available
     */
    void
    HIDNotification(UInt32 devicetype, UInt8 NewHIDData[], UInt8 OldHIDData[]);

#endif // CALL_NOT_IN_CARBON
    enum
    {
      kHIDRqGetReport = 1,
      kHIDRqGetIdle = 2,
      kHIDRqGetProtocol = 3,
      kHIDRqSetReport = 9,
      kHIDRqSetIdle = 10,
      kHIDRqSetProtocol = 11
    };

    enum
    {
      kHIDRtInputReport = 1,
      kHIDRtOutputReport = 2,
      kHIDRtFeatureReport = 3
    };

    enum
    {
      kHIDBootProtocolValue = 0,
      kHIDReportProtocolValue = 1
    };

    enum
    {
      kHIDKeyboardInterfaceProtocol = 1,
      kHIDMouseInterfaceProtocol = 2
    };

    enum
    {
      kHIDSetLEDStateByBits = 1,
      kHIDSetLEDStateByBitMask = 1,
      kHIDSetLEDStateByIDNumber = 2,
      kHIDRemoveInterruptHandler = 3,
      kHIDEnableDemoMode = 4,
      kHIDDisableDemoMode = 5,
      kHIDRemoveNotification = 0x1000
    };

    enum
    {
      kHIDGetLEDStateByBits = 1,    // not supported in 1.0 of keyboard module  kHIDGetLEDStateByBitMask = 1, // not supported in 1.0 of keyboard module  kHIDGetLEDStateByIDNumber = 2,
      kHIDGetDeviceCountryCode = 3, // not supported in 1.0 HID modules  kHIDGetDeviceUnitsPerInch = 4, // only supported in mouse HID module  kHIDGetInterruptHandler = 5,
      kHIDGetCurrentKeys = 6,       // only supported in keyboard HID module  kHIDGetInterruptRefcon = 7,
      kHIDGetVendorID = 8,
      kHIDGetProductID = 9
    };

    enum
    {
      kNumLockLED = 0,
      kCapsLockLED = 1,
      kScrollLockLED = 2,
      kComposeLED = 3,
      kKanaLED = 4
    };

    enum
    {
      kNumLockLEDMask = 1 << kNumLockLED,
      kCapsLockLEDMask = 1 << kCapsLockLED,
      kScrollLockLEDMask = 1 << kScrollLockLED,
      kComposeLEDMask = 1 << kComposeLED,
      kKanaLEDMask = 1 << kKanaLED
    };
    // CALL_NOT_IN_CARBON
    enum
    {
      kUSBCapsLockKey = 0x39,
      kUSBNumLockKey = 0x53,
      kUSBScrollLockKey = 0x47
    };

    struct USBMouseData
    {
      UInt16 buttons;
      SInt16 XDelta;
      SInt16 YDelta;
    };
    typedef struct USBMouseData USBMouseData;
    typedef USBMouseData *USBMouseDataPtr;
    struct USBKeyboardData
    {
      UInt16 keycount;
      UInt16 usbkeycode[32];
    };
    typedef struct USBKeyboardData USBKeyboardData;
    typedef USBKeyboardData *USBKeyboardDataPtr;
    union USBHIDData
    {
      USBKeyboardData kbd;
      USBMouseData mouse;
    };
    typedef union USBHIDData USBHIDData;
    typedef USBHIDData *USBHIDDataPtr;
#if CALL_NOT_IN_CARBON
    /**
     *  StartCompoundClassDriver()// not supported in 1.0 of keyboard module
     */ / not supported in 1.0 of keyboard module * Availability : *    \non_carbon_cfm not avail // not supported in 1.0 HID modules
                                                                   *    \carbon_lib not avai      // only supported in mouse HID module
                                                                   *    \mac_os_x not available * /// only supported in keyboard HID module
                                                                   void
                                                                   StartCompoundClassDriver(USBDeviceRef device, UInt16 classID, UInt16 subClass);

#endif // CALL_NOT_IN_CARBON
    enum
    {
      kUSBCompositeClass = 0,
      kUSBAudioClass = 1,
      kUSBCommClass = 2,
      kUSBHIDClass = 3,
      kUSBDisplayClass = 4,
      kUSBPrintingClass = 7,
      kUSBMassStorageClass = 8,
      kUSBHubClass = 9,
      kUSBDataClass = 10,
      kUSBVendorSpecificClass = 0xFF
    };

    enum
    {
      kUSBCompositeSubClass = 0,
      kUSBHubSubClass = 1,
      kUSBPrinterSubclass = 1,
      kUSBVendorSpecificSubClass = 0xFF
    };

    enum
    {
      kUSBHIDInterfaceClass = 0x03
    };

    enum
    {
      kUSBNoInterfaceSubClass = 0x00,
      kUSBBootInterfaceSubClass = 0x01
    };

    enum
    {
      kUSBNoInterfaceProtocol = 0x00,
      kUSBKeyboardInterfaceProtocol = 0x01,
      kUSBMouseInterfaceProtocol = 0x02,
      kUSBVendorSpecificProtocol = 0xFF
    };

    enum
    {
      kUSBPrinterUnidirectionalProtocol = 0x01,
      kUSBPrinterBidirectionalProtocol = 0x02
    };

enum {
  kServiceCategoryUSB = FOUR_CHAR_CODE('usb ') // USB};

enum {
  kUSBDriverFileType = FOUR_CHAR_CODE('ndrv'),
  kUSBDriverRsrcType = FOUR_CHAR_CODE('usbd'),
  kUSBShimRsrcType = FOUR_CHAR_CODE('usbs')
};

enum { kTheUSBDriverDescriptionSignature = FOUR_CHAR_CODE('usbd') };

enum { kInitialUSBDriverDescriptor = 0 };

typedef UInt32 USBDriverDescVersion;
//  Driver Loading Optionstypedef UInt32 USBDriverLoadingOptions;
enum {
  kUSBDoNotMatchGenericDevice =
      0x00000001, // Driver's VendorID must match Device's VendorID  kUSBDoNotMatchInterface =
      0// CALL_NOT_IN_CARBON 
      0x00000004, // Do not load this driver if protocol field doesn't match.  kUSBInterfaceMatchOnly =
      0x00000008 // Only load this driver as an interface driver.};

enum { kClassDriverPluginVersion = 0x00001100 };

struct USBDeviceInfo {
  UInt16 usbVendorID;            // USB Vendor ID  UInt16 usbProductID;           // USB Product ID.  UInt16 usbDeviceReleaseNumber; // Release Number of Device  UInt16 usbDeviceProtocol;      // Protocol Info.};
typedef struct USBDeviceInfo USBDeviceInfo;
typedef USBDeviceInfo *USBDeviceInfoPtr;
struct USBInterfaceInfo {
  UInt8 usbConfigValue;       // Configuration Value  UInt8 usbInterfaceNum;      // Interface Number  UInt8 usbInterfaceClass;    // Interface Class  UInt8 usbInterfaceSubClass; // Interface SubClass  UInt8 usbInterfaceProtocol; // Interface Protocol};
typedef struct USBInterfaceInfo USBInterfaceInfo;
typedef USBInterfaceInfo *USBInterfaceInfoPtr;
struct USBDriverType {
  Str31 nameInfoStr;    // Driver's name when loading into the Name Registry.  UInt8 usbDriverClass; // USB Class this driver belongs to.  UInt8 usbDriverSubClass;     // Module type  NumVersion usbDriverVersion; // Class driver version number.};
typedef struct USBDriverType USBDriverType;
typedef USBDriverType *USBDriverTypePtr;
struct USBDriverDescription {
  OSType usbDriverDescSignature; // Signature field of this structure.  USBDriverDescVersion
      usbDriverDescVersion;          // Version of this data structure.  USBDeviceInfo usbDeviceInfo;       // Product & Vendor Info  USBInterfaceInfo usbInterfaceInfo; // Interface info  USBDriverType usbDriverType;       // Driver Info.  USBDriverLoadingOptions
      usbDriverLoadingOptions; // Options for class driver loading.};
typedef struct USBDriverDescription USBDriverDescription;
typedef USBDriverDescription *USBDriverDescriptionPtr;
/**
   Dispatch Table
   Definition of class driver's HW Validation proc.
*/
typedef CALLBACK_API_C(OSStatus,
                       USBDValidateHWProcPtr)(USBDeviceRef device,
                                              USBDeviceDescriptorPtr pDesc);
/**
   Definition of class driver's device initialization proc.
   Called if the driver is being loaded for a device
*/
typedef CALLBACK_API_C(OSStatus, USBDInitializeDeviceProcPtr)(
    USBDeviceRef device, USBDeviceDescriptorPtr pDesc,
    UInt32 busPowerAvailable);
// Definition of class driver's interface initialization proc.typedef CALLBACK_API_C(OSStatus, USBDInitializeInterfaceProcPtr)(
    UInt32 interfaceNum, USBInterfaceDescriptor// USB
    USBDeviceDescriptorPtr pDevice, USBInterfaceRef interfaceRef);
// Definition of class driver's finalization proc.typedef CALLBACK_API_C(OSStatus,
                       USBDFinalizeProcPtr)(USBDeviceRef device,
                                            USBDeviceDescriptorPtr pDesc);
typedef UInt32 USBDriverNotification;
enum {
  kNotifySystemSleepRequest = 0x00000001,
  kNotifySystemSleepDemand = 0x00000002,
  kNotifySystemSleepWakeUp = 0x00000003,
  kNotifySystemSleepRevoke = 0x00000004,
  kNotifyHubEnumQuery = 0x00000006,
  kNotifyChildMessage = 0x00000007,
  kNotifyExpertTerminating = 0x00000008,
//  Driver Loading Options
  kNotifyAllowROMDriverRemoval = 0x0000000E
};

/**// Driver's VendorID must match Device's VendorID
   Definition of driver's notification proc.
   Added refcon fo// Do not load this driver as an interface driver.
*/
typedef CALLBACK_A// Do not load this driver if protocol field doesn't match.
    USBDriverNotification notification, void *pointer, UInt32 refcon);
struct USBClassDr// Only load this driver as an interface driver.
  UInt32 pluginVersion;
  USBDValidateHWProcPtr validateHWProc; // Proc for driver to verify proper HW  USBDInitializeDeviceProcPtr
      initializeDeviceProc; // Proc that initializes the class driver.  USBDInitializeInterfaceProcPtr
      initializeInterfaceProc; /* Proc that initializes a particular interface
                                  in the class driver.*/
  USBDFinalizeProcPtr finalizePro// USB Vendor ID
      notificationProc; // Proc t// USB Product ID.
typedef struct USBClassDriverPlug// Release Number of Device
    USBClassDriverPluginDispatchT// Protocol Info.
typedef USBClassDriverPluginDispatchTable *USBClassDriverPluginDispatchTablePtr;
// Shim Definesenum { kTheUSBShimDescriptionSignature = FOUR_CHAR_CODE('usbs') };

typedef UInt32 USBShimDescVersion;
enum { kCurrentUSBShimDescVers// Configuration Value
// Interface Number
//  Shim Loading Optionstypede// Interface Class
enum {// Interface SubClass
  kUSBRegisterShimAsSharedLibr// Interface Protocol
      0x00000001 // Driver's VendorID must match Device's VendorID};

struct USBShimDescription {
  OSType usbShimDescSignature;           // Signature field of this structure.  USBShimDescVersion usbShimDescVersion; // Version of this data structure.  USBShimLoadingOptions usbDriverLoadingOptions; // Options for shim loading.  Str63 libraryName; // For optional shared library registration};
typedef struct USBShimDe// Driver's name when loading into the Name Registry.
typedef USBShimDescripti// USB Class this driver belongs to.
// Hub defines// Module type
enum { kUSBHubDescriptorType = // Class driver version number.

enum {
  // Hub features   kUSBHubLocalPowerChangeFeature = 0,
  kUSBHubOverCurrentChangeFeature = 1, // port features   kUSBHubPortConnectionFeature = 0,
  kUSBHubPortEnableFeature = 1,// Signature field of this structure.
  kUSBHubPortSuspendFeature = 2,
  kUSBHubPortOverCurrentFeature = 3,// Version of this data structure.
  kUSBHubPortResetFeature = 4,// Product & Vendor Info
  kUSBHubPortPowerFeature = 8,// Interface info
  kUSBHubPortLowSpeedFeature = 9,// Driver Info.
  kUSBHubPortConnectionChangeFeature = 16,
  kUSBHubPortEnableChangeFeatur// Options for class driver loading.
  kUSBHubPortSuspendChangeFeature = 18,
  kUSBHubPortOverCurrentChangeFeature = 19,
  kUSBHubPortResetChangeFeature = 20
};

enum {
  kHubPortConnection = 1,
  kHubPortEnabled = 2,
  kHubPortSuspend = 4,
  kHubPortOverCurrent = 8,
  kHubPortBeingReset = 16,
  kHubPortPower = 0x0100,
  kHubPortLowSpeed = 0x0200,
  kHubPortHighSpeed = 0x0400,
  kHubPortTestMode = 0x0800,
  kHubPortPortIndicator = 0x1000
};
// Definition of class driver's interface initialization proc.
enum {
  // Originally this was a Boolean, (low speed)?  kUSBFullSpeed = 0,
  kUSBLowSpeed = 1,
// Definition of class driver's finalization proc.
};

enum {
  kHubLocalPowerStatus = 1,
  kHubOverCurrentIndicator = 2,
  kHubLocalPowerStatusChange = 1,
  kHubOverCurrentIndicatorChange = 2
};

enum { off = false, on = true };

struct hubDescriptor {
  // See usbDoc pg 250??   UInt8 dummy; // to align charcteristics 
  UInt8 length;
  UInt8 hubType;
  UInt8 numPorts;

  UInt16 characteristics;
  UInt8 powerOnToGood; // Port settling time, in 2ms   UInt8 hubCurrent;

  // These are received packed, will have to be unpacked   UInt8 removablePortFlags[8];
  UInt8 pwrCtlPortFlags[8];
};
typedef struct hubDescriptor hubDescriptor;
// Proc for driver to verify proper HW
#if PRAGMA_STRUCT_ALIGN
#pragma options align = rese // Proc that initializes the class driver.
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack() // Proc that finalizes the class driver.
#endif
// Proc to pass notifications to the driver.
#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
// Shim Defines

#ifdef __cplusplus
}
#endif

//  Shim Loading Options
// Driver's VendorID must match Device's VendorID
// Signature field of this structure.
// Version of this data structure.
// Options for shim loading.
// For optional shared library registration
// Hub defines
// Hub features
// port features
// Originally this was a Boolean, (low speed)?
// See usbDoc pg 250??
// to align charcteristics
// Port settling time, in 2ms
// These are received packed, will have to be unpacked
// __USB__
