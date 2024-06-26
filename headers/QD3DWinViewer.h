/**
     \file       QD3DWinViewer.h

    \brief   Win32 Viewer Controller Interface File.

    \introduced_in  Quickdraw 3D 1.6
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1995-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Quickdraw3D

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QD3DWINVIEWER__
#define __QD3DWINVIEWER__

#ifndef __QD3D__
#include <QD3D.h>
#endif

#ifndef __QD3DGROUP__
#include <QD3DGroup.h>
#endif

#if TARGET_OS_WIN32
#include <windows.h>
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
#pragma options align = power
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
#pragma pack(2)
#endif

#if PRAGMA_ENUM_ALWAYSINT
#if defined(__fourbyteints__) && !__fourbyteints__
#define __QD3DWINVIEWER__RESTORE_TWOBYTEINTS
#pragma fourbyteints on
#endif
#pragma enumsalwaysint on
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =int
#elif PRAGMA_ENUM_PACK
#if __option(pack_enums)
#define __QD3DWINVIEWER__RESTORE_PACKED_ENUMS
#pragma options(!pack_enums)
#endif
#endif

#if TARGET_OS_WIN32
  typedef void *TQ3ViewerObject;
  typedef CALLBACK_API_C(TQ3Status, TQ3ViewerDrawingCallbackMethod)(
      TQ3ViewerObject theViewer, const void *data);
  typedef CALLBACK_API_C(TQ3Status, TQ3ViewerWindowResizeCallbackMethod)(
      TQ3ViewerObject theViewer, const void *data);
  typedef CALLBACK_API_C(TQ3Status, TQ3ViewerPaneResizeNotifyCallbackMethod)(
      TQ3ViewerObject theViewer, const void *data);
  enum
  {
    kQ3ViewerShowBadge = 1 << 0,
    kQ3ViewerActive = 1 << 1,
    kQ3ViewerControllerVisible = 1 << 2,
    kQ3ViewerButtonCamera = 1 << 3,
    kQ3ViewerButtonTruck = 1 << 4,
    kQ3ViewerButtonOrbit = 1 << 5,
    kQ3ViewerButtonZoom = 1 << 6,
    kQ3ViewerButtonDolly = 1 << 7,
    kQ3ViewerButtonReset = 1 << 8,
    kQ3ViewerButtonNone = 1 << 9,
    kQ3ViewerOutputTextMode = 1 << 10,
    kQ3ViewerDraggingInOff = 1 << 11,
    kQ3ViewerButtonOptions = 1 << 12,
    kQ3ViewerPaneGrowBox = 1 << 13,
    kQ3ViewerDefault = 1 << 15
  };

  enum
  {
    kQ3ViewerEmpty = 0,
    kQ3ViewerHasModel = 1 << 0,
    kQ3ViewerHasUndo = 1 << 1
  };

  enum TQ3ViewerCameraView
  {
    kQ3ViewerCameraRestore = 0,
    kQ3ViewerCameraFit = 1,
    kQ3ViewerCameraFront = 2,
    kQ3ViewerCameraBack = 3,
    kQ3ViewerCameraLeft = 4,
    kQ3ViewerCameraRight = 5,
    kQ3ViewerCameraTop = 6,
    kQ3ViewerCameraBottom = 7
  };
  typedef enum TQ3ViewerCameraView TQ3ViewerCameraView;

  /******************************************************************************
   **                                                                          **
   **                             WM_NOTIFY structures                         **
   **                                                                          **
   *****************************************************************************/
  struct TQ3ViewerDropFiles
  {
    NMHDR nmhdr;
    HANDLE hDrop;
  };
  typedef struct TQ3ViewerDropFiles TQ3ViewerDropFiles;
  struct TQ3ViewerSetView
  {
    NMHDR nmhdr;
    TQ3ViewerCameraView view;
  };
  typedef struct TQ3ViewerSetView TQ3ViewerSetView;
  struct TQ3ViewerSetViewNumber
  {
    NMHDR nmhdr;
    unsigned long number;
  };
  typedef struct TQ3ViewerSetViewNumber TQ3ViewerSetViewNumber;
  struct TQ3ViewerButtonSet
  {
    NMHDR nmhdr;
    unsigned long button;
  };
  typedef struct TQ3ViewerButtonSet TQ3ViewerButtonSet;
  /******************************************************************************
   **                                                                          **
   **                             WM_NOTIFY defines                            **
   **                                                                          **
   *****************************************************************************/

#define Q3VNM_DROPFILES 0x5000
#define Q3VNM_CANUNDO 0x5001
#define Q3VNM_DRAWCOMPLETE 0x5002
#define Q3VNM_SETVIEW 0x5003
#define Q3VNM_SETVIEWNUMBER 0x5004
#define Q3VNM_BUTTONSET 0x5005
#define Q3VNM_BADGEHIT 0x5006

/******************************************************************************
 **                                                                          **
 **                         Win32 Window Class Name                          **
 **     Can be passed as a parameter to CreateWindow or CreateWindowEx       **
 **                                                                          **
 *****************************************************************************/
#define kQ3ViewerClassName "QD3DViewerWindow"

/******************************************************************************
 **                                                                          **
 **                         Win32 Clipboard type                             **
 **                                                                          **
 *****************************************************************************/
#define kQ3ViewerClipboardFormat "QuickDraw 3D Metafile"
/******************************************************************************
 **                                                                          **
 **     Return viewer version number                                         **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
  /**
   *  Q3WinViewerGetVersion()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerGetVersion(unsigned long *majorRevision,
                        unsigned long *minorRevision);

  /******************************************************************************
   **                                                                          **
   **     Return viewer release version number                                 **
   **     (in 'vers' format - e.g. 0x01518000 ==> 1.5.1 release)               **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerGetReleaseVersion()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerGetReleaseVersion(unsigned long *releaseRevision);

  /******************************************************************************
   **                                                                          **
   **                     Creation and destruction                             **
   **             Note that this is not a QuickDraw 3D object                  **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerNew()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3ViewerObject
  Q3WinViewerNew(HWND window, const RECT *rect, unsigned long flags);

  /**
   *  Q3WinViewerDispose()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerDispose(TQ3ViewerObject viewer);

  /******************************************************************************
   **                                                                          **
   **                 Functions to attach data to a WinViewer                  **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerUseFile()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerUseFile(TQ3ViewerObject viewer, HANDLE fileHandle);

  /**
   *  Q3WinViewerUseData()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerUseData(TQ3ViewerObject viewer, void *data, unsigned long size);

  /******************************************************************************
   **                                                                          **
   **             Functions to write data out from the WinViewer               **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerWriteFile()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerWriteFile(TQ3ViewerObject viewer, HANDLE fileHandle);

  /**
   *  Q3WinViewerWriteData()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerWriteData(TQ3ViewerObject viewer, void *data, unsigned long dataSize,
                       unsigned long *actualDataSize);

  /******************************************************************************
   **                                                                          **
   **     Use this function to force the WinViewer to re-draw                  **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerDraw()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerDraw(TQ3ViewerObject viewer);

  /**
   *  Q3WinViewerDrawContent()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerDrawContent(TQ3ViewerObject viewer);

  /**
   *  Q3WinViewerDrawControlStrip()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerDrawControlStrip(TQ3ViewerObject viewer);

  /******************************************************************************
   **                                                                          **
   **     Function used by the WinViewer to filter and handle events           **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerMouseDown()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  BOOL
  Q3WinViewerMouseDown(TQ3ViewerObject viewer, long x, long y);

  /**
   *  Q3WinViewerContinueTracking()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  BOOL
  Q3WinViewerContinueTracking(TQ3ViewerObject viewer, long x, long y);

  /**
   *  Q3WinViewerMouseUp()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  BOOL
  Q3WinViewerMouseUp(TQ3ViewerObject viewer, long x, long y);

  /******************************************************************************
   **                                                                          **
   **     This function returns a Bitmap of the contents of the                **
   **     WinViewer's window.  The application should dispose the Bitmap.      **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerGetBitmap()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  HBITMAP
  Q3WinViewerGetBitmap(TQ3ViewerObject viewer);

  /******************************************************************************
   **                                                                          **
   **                 Calls for dealing with Buttons                           **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerGetButtonRect()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerGetButtonRect(TQ3ViewerObject viewer, unsigned long button,
                           RECT *rectangle);

  /**
   *  Q3WinViewerGetCurrentButton()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  unsigned long
  Q3WinViewerGetCurrentButton(TQ3ViewerObject viewer);

  /**
   *  Q3WinViewerSetCurrentButton()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerSetCurrentButton(TQ3ViewerObject viewer, unsigned long button);

  /******************************************************************************
   **                                                                          **
   **     Functions to set/get the group to be displayed by the WinViewer.     **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerUseGroup()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerUseGroup(TQ3ViewerObject viewer, TQ3GroupObject group);

  /**
   *  Q3WinViewerGetGroup()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3GroupObject
  Q3WinViewerGetGroup(TQ3ViewerObject viewer);

  /******************************************************************************
   **                                                                          **
   **     Functions to set/get the color used to clear the window              **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerSetBackgroundColor()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerSetBackgroundColor(TQ3ViewerObject viewer, TQ3ColorARGB *color);

  /**
   *  Q3WinViewerGetBackgroundColor()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerGetBackgroundColor(TQ3ViewerObject viewer, TQ3ColorARGB *color);

  /******************************************************************************
   **                                                                          **
   **     Getting/Setting a WinViewer's View object.                           **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerGetView()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3ViewObject
  Q3WinViewerGetView(TQ3ViewerObject viewer);

  /**
   *  Q3WinViewerRestoreView()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerRestoreView(TQ3ViewerObject viewer);

  /******************************************************************************
   **                                                                          **
   **     Calls for setting/getting WinViewer flags                            **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerSetFlags()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerSetFlags(TQ3ViewerObject viewer, unsigned long flags);

  /**
   *  Q3WinViewerGetFlags()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  unsigned long
  Q3WinViewerGetFlags(TQ3ViewerObject viewer);

  /******************************************************************************
   **                                                                          **
   **     Calls related to bounds/dimensions.  Bounds is the size of           **
   **     the window.  Dimensions can either be the Rect from the ViewHints    **
   **     or the current dimensions of the window (if you do a Set).           **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerSetBounds()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerSetBounds(TQ3ViewerObject viewer, RECT *bounds);

  /**
   *  Q3WinViewerGetBounds()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerGetBounds(TQ3ViewerObject viewer, RECT *bounds);

  /**
   *  Q3WinViewerSetDimension()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerSetDimension(TQ3ViewerObject viewer, unsigned long width,
                          unsigned long height);

  /**
   *  Q3WinViewerGetDimension()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerGetDimension(TQ3ViewerObject viewer, unsigned long *width,
                          unsigned long *height);

  /**
   *  Q3WinViewerGetMinimumDimension()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerGetMinimumDimension(TQ3ViewerObject viewer, unsigned long *width,
                                 unsigned long *height);

  /******************************************************************************
   **                                                                          **
   **                         Window related calls                             **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerSetWindow()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerSetWindow(TQ3ViewerObject viewer, HWND window);

  /**
   *  Q3WinViewerGetWindow()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  HWND
  Q3WinViewerGetWindow(TQ3ViewerObject viewer);

  /**
   *  Q3WinViewerGetViewer()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3ViewerObject
  Q3WinViewerGetViewer(HWND theWindow);

  /**
   *  Q3WinViewerGetControlStrip()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  HWND
  Q3WinViewerGetControlStrip(TQ3ViewerObject viewer);

  /******************************************************************************
   **                                                                          **
   **     Adjust Cursor provided for compatibility with Mac Viewer             **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerAdjustCursor()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Boolean
  Q3WinViewerAdjustCursor(TQ3ViewerObject viewer, long x, long y);

  /**
   *  Q3WinViewerCursorChanged()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerCursorChanged(TQ3ViewerObject viewer);

  /******************************************************************************
   **                                                                          **
   **     Returns the state of the WinViewer.  See the constant defined at the **
   **     top of this file.                                                    **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerGetState()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  unsigned long
  Q3WinViewerGetState(TQ3ViewerObject viewer);

  /******************************************************************************
   **                                                                          **
   **                         Clipboard utilities                              **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerClear()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerClear(TQ3ViewerObject viewer);

  /**
   *  Q3WinViewerCut()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerCut(TQ3ViewerObject viewer);

  /**
   *  Q3WinViewerCopy()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerCopy(TQ3ViewerObject viewer);

  /**
   *  Q3WinViewerPaste()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerPaste(TQ3ViewerObject viewer);

  /******************************************************************************
   **                                                                          **
   **                             Undo                                         **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerUndo()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerUndo(TQ3ViewerObject viewer);

  /**
   *  Q3WinViewerGetUndoString()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Boolean
  Q3WinViewerGetUndoString(TQ3ViewerObject viewer, char *theString,
                           unsigned long stringSize, unsigned long *actualSize);

  /******************************************************************************
   **                                                                          **
   **                         New Camera Stuff                                 **
   **                                                                          **
   *****************************************************************************/
  /**
   *  Q3WinViewerGetCameraCount()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerGetCameraCount(TQ3ViewerObject viewer, unsigned long *count);

  /**
   *  Q3WinViewerSetCameraNumber()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerSetCameraNumber(TQ3ViewerObject viewer, unsigned long cameraNo);

  /**
   *  Q3WinViewerSetCameraView()
   *

   *    \non_carbon_cfm   not available
   *    \carbon_lib        not available
   *    \mac_os_x         not available
   */
  TQ3Status
  Q3WinViewerSetCameraView(TQ3ViewerObject viewer, TQ3ViewerCameraView viewType);

#endif /* CALL_NOT_IN_CARBON */

#endif /* TARGET_OS_WIN32 */

#if PRAGMA_ENUM_ALWAYSINT
#pragma enumsalwaysint reset
#ifdef __QD3DWINVIEWER__RESTORE_TWOBYTEINTS
#pragma fourbyteints off
#endif
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =reset
#elif defined(__QD3DWINVIEWER__RESTORE_PACKED_ENUMS)
#pragma options(pack_enums)
#endif

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

#endif /* __QD3DWINVIEWER__ */
