/**
     \file       QD3DLight.h

    \brief   Generic light routines

    \introduced_in  Quickdraw 3D 1.6
    \avaliable_from Universal Interfaces 3.4.1

    \copyright � 1995-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Quickdraw3D

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __QD3DLIGHT__
#define __QD3DLIGHT__

#ifndef __QD3D__
#include <QD3D.h>
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
#pragma options align = power
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
#pragma pack(2)
#endif

#if PRAGMA_ENUM_ALWAYSINT
#if defined(__fourbyteints__) && !__fourbyteints__
#define __QD3DLIGHT__RESTORE_TWOBYTEINTS
#pragma fourbyteints on
#endif
#pragma enumsalwaysint on
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =int
#elif PRAGMA_ENUM_PACK
#if __option(pack_enums)
#define __QD3DLIGHT__RESTORE_PACKED_ENUMS
#pragma options(!pack_enums)
#endif
#endif

/******************************************************************************
 **                                                                          **
 **                         Enum Definitions                                 **
 **                                                                          **
 *****************************************************************************/
enum TQ3AttenuationType {
  kQ3AttenuationTypeNone = 0,
  kQ3AttenuationTypeInverseDistance = 1,
  kQ3AttenuationTypeInverseDistanceSquared = 2
};
typedef enum TQ3AttenuationType TQ3AttenuationType;

enum TQ3FallOffType {
  kQ3FallOffTypeNone = 0,
  kQ3FallOffTypeLinear = 1,
  kQ3FallOffTypeExponential = 2,
  kQ3FallOffTypeCosine = 3
};
typedef enum TQ3FallOffType TQ3FallOffType;

/******************************************************************************
 **                                                                          **
 **                         Data Structure Definitions                       **
 **                                                                          **
 *****************************************************************************/
struct TQ3LightData {
  TQ3Boolean isOn;
  float brightness;
  TQ3ColorRGB color;
};
typedef struct TQ3LightData TQ3LightData;
struct TQ3DirectionalLightData {
  TQ3LightData lightData;
  TQ3Boolean castsShadows;
  TQ3Vector3D direction;
};
typedef struct TQ3DirectionalLightData TQ3DirectionalLightData;
struct TQ3PointLightData {
  TQ3LightData lightData;
  TQ3Boolean castsShadows;
  TQ3AttenuationType attenuation;
  TQ3Point3D location;
};
typedef struct TQ3PointLightData TQ3PointLightData;
struct TQ3SpotLightData {
  TQ3LightData lightData;
  TQ3Boolean castsShadows;
  TQ3AttenuationType attenuation;
  TQ3Point3D location;
  TQ3Vector3D direction;
  float hotAngle;
  float outerAngle;
  TQ3FallOffType fallOff;
};
typedef struct TQ3SpotLightData TQ3SpotLightData;
/******************************************************************************
 **                                                                          **
 **                 Light routines (apply to all TQ3LightObjects)            **
 **                                                                          **
 *****************************************************************************/
#if CALL_NOT_IN_CARBON
/**
 *  Q3Light_GetType()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3ObjectType
Q3Light_GetType(TQ3LightObject light);

/**
 *  Q3Light_GetState()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3Light_GetState(TQ3LightObject light, TQ3Boolean *isOn);

/**
 *  Q3Light_GetBrightness()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3Light_GetBrightness(TQ3LightObject light, float *brightness);

/**
 *  Q3Light_GetColor()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3Light_GetColor(TQ3LightObject light, TQ3ColorRGB *color);

/**
 *  Q3Light_SetState()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3Light_SetState(TQ3LightObject light, TQ3Boolean isOn);

/**
 *  Q3Light_SetBrightness()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3Light_SetBrightness(TQ3LightObject light, float brightness);

/**
 *  Q3Light_SetColor()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3Light_SetColor(TQ3LightObject light, const TQ3ColorRGB *color);

/**
 *  Q3Light_GetData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3Light_GetData(TQ3LightObject light, TQ3LightData *lightData);

/**
 *  Q3Light_SetData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3Light_SetData(TQ3LightObject light, const TQ3LightData *lightData);

/******************************************************************************
 **                                                                          **
 **                         Specific Light Routines                          **
 **                                                                          **
 *****************************************************************************/
/******************************************************************************
 **                                                                          **
 **                         Ambient Light                                    **
 **                                                                          **
 *****************************************************************************/
/**
 *  Q3AmbientLight_New()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3LightObject
Q3AmbientLight_New(const TQ3LightData *lightData);

/**
 *  Q3AmbientLight_GetData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3AmbientLight_GetData(TQ3LightObject light, TQ3LightData *lightData);

/**
 *  Q3AmbientLight_SetData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3AmbientLight_SetData(TQ3LightObject light, const TQ3LightData *lightData);

/******************************************************************************
 **                                                                          **
 **                     Directional Light                                    **
 **                                                                          **
 *****************************************************************************/
/**
 *  Q3DirectionalLight_New()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3LightObject
Q3DirectionalLight_New(const TQ3DirectionalLightData *directionalLightData);

/**
 *  Q3DirectionalLight_GetCastShadowsState()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3DirectionalLight_GetCastShadowsState(TQ3LightObject light,
                                       TQ3Boolean *castsShadows);

/**
 *  Q3DirectionalLight_GetDirection()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3DirectionalLight_GetDirection(TQ3LightObject light, TQ3Vector3D *direction);

/**
 *  Q3DirectionalLight_SetCastShadowsState()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3DirectionalLight_SetCastShadowsState(TQ3LightObject light,
                                       TQ3Boolean castsShadows);

/**
 *  Q3DirectionalLight_SetDirection()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3DirectionalLight_SetDirection(TQ3LightObject light,
                                const TQ3Vector3D *direction);

/**
 *  Q3DirectionalLight_GetData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3DirectionalLight_GetData(TQ3LightObject light,
                           TQ3DirectionalLightData *directionalLightData);

/**
 *  Q3DirectionalLight_SetData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3DirectionalLight_SetData(TQ3LightObject light,
                           const TQ3DirectionalLightData *directionalLightData);

/******************************************************************************
 **                                                                          **
 **                     Point Light                                          **
 **                                                                          **
 *****************************************************************************/
/**
 *  Q3PointLight_New()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3LightObject
Q3PointLight_New(const TQ3PointLightData *pointLightData);

/**
 *  Q3PointLight_GetCastShadowsState()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3PointLight_GetCastShadowsState(TQ3LightObject light,
                                 TQ3Boolean *castsShadows);

/**
 *  Q3PointLight_GetAttenuation()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3PointLight_GetAttenuation(TQ3LightObject light,
                            TQ3AttenuationType *attenuation);

/**
 *  Q3PointLight_GetLocation()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3PointLight_GetLocation(TQ3LightObject light, TQ3Point3D *location);

/**
 *  Q3PointLight_GetData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3PointLight_GetData(TQ3LightObject light, TQ3PointLightData *pointLightData);

/**
 *  Q3PointLight_SetCastShadowsState()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3PointLight_SetCastShadowsState(TQ3LightObject light, TQ3Boolean castsShadows);

/**
 *  Q3PointLight_SetAttenuation()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3PointLight_SetAttenuation(TQ3LightObject light,
                            TQ3AttenuationType attenuation);

/**
 *  Q3PointLight_SetLocation()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3PointLight_SetLocation(TQ3LightObject light, const TQ3Point3D *location);

/**
 *  Q3PointLight_SetData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3PointLight_SetData(TQ3LightObject light,
                     const TQ3PointLightData *pointLightData);

/******************************************************************************
 **                                                                          **
 **                     Spot Light                                           **
 **                                                                          **
 *****************************************************************************/
/**
 *  Q3SpotLight_New()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3LightObject
Q3SpotLight_New(const TQ3SpotLightData *spotLightData);

/**
 *  Q3SpotLight_GetCastShadowsState()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_GetCastShadowsState(TQ3LightObject light, TQ3Boolean *castsShadows);

/**
 *  Q3SpotLight_GetAttenuation()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_GetAttenuation(TQ3LightObject light,
                           TQ3AttenuationType *attenuation);

/**
 *  Q3SpotLight_GetLocation()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_GetLocation(TQ3LightObject light, TQ3Point3D *location);

/**
 *  Q3SpotLight_GetDirection()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_GetDirection(TQ3LightObject light, TQ3Vector3D *direction);

/**
 *  Q3SpotLight_GetHotAngle()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_GetHotAngle(TQ3LightObject light, float *hotAngle);

/**
 *  Q3SpotLight_GetOuterAngle()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_GetOuterAngle(TQ3LightObject light, float *outerAngle);

/**
 *  Q3SpotLight_GetFallOff()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_GetFallOff(TQ3LightObject light, TQ3FallOffType *fallOff);

/**
 *  Q3SpotLight_GetData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_GetData(TQ3LightObject light, TQ3SpotLightData *spotLightData);

/**
 *  Q3SpotLight_SetCastShadowsState()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_SetCastShadowsState(TQ3LightObject light, TQ3Boolean castsShadows);

/**
 *  Q3SpotLight_SetAttenuation()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_SetAttenuation(TQ3LightObject light,
                           TQ3AttenuationType attenuation);

/**
 *  Q3SpotLight_SetLocation()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_SetLocation(TQ3LightObject light, const TQ3Point3D *location);

/**
 *  Q3SpotLight_SetDirection()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_SetDirection(TQ3LightObject light, const TQ3Vector3D *direction);

/**
 *  Q3SpotLight_SetHotAngle()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_SetHotAngle(TQ3LightObject light, float hotAngle);

/**
 *  Q3SpotLight_SetOuterAngle()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_SetOuterAngle(TQ3LightObject light, float outerAngle);

/**
 *  Q3SpotLight_SetFallOff()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_SetFallOff(TQ3LightObject light, TQ3FallOffType fallOff);

/**
 *  Q3SpotLight_SetData()
 *
 *  Availability:
 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
TQ3Status
Q3SpotLight_SetData(TQ3LightObject light,
                    const TQ3SpotLightData *spotLightData);

#endif // CALL_NOT_IN_CARBON 
#if PRAGMA_ENUM_ALWAYSINT
#pragma enumsalwaysint reset
#ifdef __QD3DLIGHT__RESTORE_TWOBYTEINTS
#pragma fourbyteints off
#endif
#elif PRAGMA_ENUM_OPTIONS
#pragma option enum =reset
#elif defined(__QD3DLIGHT__RESTORE_PACKED_ENUMS)
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

#endif // __QD3DLIGHT__ // __QD3DLIGHT__ 
