/**
     \file       GXMath.h

    \brief   QuickDraw GX math routine interfaces.

    \introduced_in  Quickdraw GX 1.1
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup QuickDraw

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __GXMATH__
#define __GXMATH__

#ifndef __CONDITIONALMACROS__
#include <ConditionalMacros.h>
#endif

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __FIXMATH__
#include <FixMath.h>
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

#if defined(__MWERKS__) && TARGET_CPU_68K
#pragma push
#pragma pointers_in_D0
#endif

struct gxPoint {
  Fixed x;
  Fixed y;
};
typedef struct gxPoint gxPoint;

typedef unsigned short gxColorValue;
struct gxPolar {
  Fixed radius;
  Fixed angle;
};
typedef struct gxPolar gxPolar;
struct gxMapping {
  Fixed map[3][3];
};
typedef struct gxMapping gxMapping;
#define gxColorValue1 ((gxColorValue)0x0000FFFF)
#define gxPositiveInfinity ((long)0x7FFFFFFFL)
#define gxNegativeInfinity ((long)0x80000000L)

#if CALL_NOT_IN_CARBON
/**
 *  CopyToMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
CopyToMapping(gxMapping *target, const gxMapping *source)
    THREEWORDINLINE(0x303C, 0x0031, 0xA832);

/**
 *  InvertMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
InvertMapping(gxMapping *target, const gxMapping *source)
    THREEWORDINLINE(0x303C, 0x0032, 0xA832);

/**
 *  MapMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
MapMapping(gxMapping *target, const gxMapping *source)
    THREEWORDINLINE(0x303C, 0x0033, 0xA832);

/**
 *  MoveMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
MoveMapping(gxMapping *target, Fixed hOffset, Fixed vOffset)
    THREEWORDINLINE(0x303C, 0x0034, 0xA832);

/**
 *  MoveMappingTo()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
MoveMappingTo(gxMapping *target, Fixed hPosition, Fixed vPosition)
    THREEWORDINLINE(0x303C, 0x0035, 0xA832);

/**
 *  NormalizeMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
NormalizeMapping(gxMapping *target) THREEWORDINLINE(0x303C, 0x0036, 0xA832);

/**
 *  RotateMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
RotateMapping(gxMapping *target, Fixed angle, Fixed xCenter, Fixed yCenter)
    THREEWORDINLINE(0x303C, 0x0037, 0xA832);

/**
 *  ScaleMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
ScaleMapping(gxMapping *target, Fixed hFactor, Fixed vFactor, Fixed xCenter,
             Fixed yCenter) THREEWORDINLINE(0x303C, 0x0038, 0xA832);

/**
 *  ResetMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
ResetMapping(gxMapping *target) THREEWORDINLINE(0x303C, 0x0039, 0xA832);

/**
 *  SkewMapping()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxMapping *
SkewMapping(gxMapping *target, Fixed skewX, Fixed skewY, Fixed xCenter,
            Fixed yCenter) THREEWORDINLINE(0x303C, 0x003A, 0xA832);

/**
 *  MapPoints()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
MapPoints(const gxMapping *source, long count, gxPoint theVector[])
    THREEWORDINLINE(0x303C, 0x003B, 0xA832);

/**
 *  FirstBit()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
FirstBit(unsigned long x) THREEWORDINLINE(0x303C, 0x003C, 0xA832);

/**
 *  WideScale()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
WideScale(const wide *source) THREEWORDINLINE(0x303C, 0x003D, 0xA832);

/**
 *  LinearRoot()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
LinearRoot(Fixed first, Fixed last, Fract t[])
    THREEWORDINLINE(0x303C, 0x003E, 0xA832);

/**
 *  QuadraticRoot()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
QuadraticRoot(Fixed first, Fixed control, Fixed last, Fract t[])
    THREEWORDINLINE(0x303C, 0x003F, 0xA832);

/**
 *  PolarToPoint()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxPoint *
PolarToPoint(const gxPolar *ra, gxPoint *xy)
    THREEWORDINLINE(0x303C, 0x0040, 0xA832);

/**
 *  PointToPolar()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
gxPolar *
PointToPolar(const gxPoint *xy, gxPolar *ra)
    THREEWORDINLINE(0x303C, 0x0041, 0xA832);

/**
 *  FractCubeRoot()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fract
FractCubeRoot(Fract source) THREEWORDINLINE(0x303C, 0x0042, 0xA832);

/**
 *  FractDivide()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fract
FractDivide(Fract dividend, Fract divisor)
    THREEWORDINLINE(0x303C, 0x0043, 0xA832);

/**
 *  FractMultiply()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fract
FractMultiply(Fract multiplicand, Fract multiplier)
    THREEWORDINLINE(0x303C, 0x0044, 0xA832);

/**
 *  FractSineCosine()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fract
FractSineCosine(Fixed degrees, Fract *cosine)
    THREEWORDINLINE(0x303C, 0x0045, 0xA832);

/**
 *  FractSquareRoot()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fract
FractSquareRoot(Fract source) THREEWORDINLINE(0x303C, 0x0046, 0xA832);

/**
 *  FixedDivide()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fixed
FixedDivide(Fixed dividend, Fixed divisor)
    THREEWORDINLINE(0x303C, 0x0047, 0xA832);

/**
 *  FixedMultiply()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
Fixed
FixedMultiply(Fixed multiplicand, Fixed multiplier)
    THREEWORDINLINE(0x303C, 0x0048, 0xA832);

/** This next call is (source * multiplier / divisor) -- it avoids underflow,
 * overflow by using wides */
/**
 *  MultiplyDivide()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
MultiplyDivide(long source, long multiplier, long divisor)
    THREEWORDINLINE(0x303C, 0x0049, 0xA832);

/**
 *  Magnitude()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
unsigned long
Magnitude(long deltaX, long deltaY) THREEWORDINLINE(0x303C, 0x004A, 0xA832);

/**
 *  VectorMultiplyDivide()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
VectorMultiplyDivide(long count, const long *vector1, long step1,
                     const long *vector2, long step2, long divisor)
    THREEWORDINLINE(0x303C, 0x004B, 0xA832);

/** wide operations are defined within FixMath.h for PowerPC */
#endif /** CALL_NOT_IN_CARBON */

#if TARGET_OS_MAC && TARGET_CPU_68K
#if CALL_NOT_IN_CARBON
/**
 *  WideAdd()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
wide *
WideAdd(wide *target, const wide *source)
    THREEWORDINLINE(0x303C, 0x004C, 0xA832);

/**
 *  WideCompare()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
short
WideCompare(const wide *target, const wide *source)
    THREEWORDINLINE(0x303C, 0x004D, 0xA832);

/**
 *  WideNegate()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
wide *
WideNegate(wide *target) THREEWORDINLINE(0x303C, 0x004E, 0xA832);

/**
 *  WideShift()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
wide *
WideShift(wide *target, long shift) THREEWORDINLINE(0x303C, 0x004F, 0xA832);

/**
 *  WideSquareRoot()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
unsigned long
WideSquareRoot(const wide *source) THREEWORDINLINE(0x303C, 0x0050, 0xA832);

/**
 *  WideSubtract()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
wide *
WideSubtract(wide *target, const wide *source)
    THREEWORDINLINE(0x303C, 0x0051, 0xA832);

/**
 *  WideMultiply()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
wide *
WideMultiply(long multiplicand, long multiplier, wide *target)
    THREEWORDINLINE(0x303C, 0x0052, 0xA832);

/** returns the quotient */
/**
 *  WideDivide()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
long
WideDivide(const wide *dividend, long divisor, long *remainder)
    THREEWORDINLINE(0x303C, 0x0053, 0xA832);

/** quotient replaces dividend */
/**
 *  WideWideDivide()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
wide *
WideWideDivide(wide *dividend, long divisor, long *remainder)
    THREEWORDINLINE(0x303C, 0x0055, 0xA832);

#endif /** CALL_NOT_IN_CARBON */

#endif /** TARGET_OS_MAC && TARGET_CPU_68K */

#if CALL_NOT_IN_CARBON
/**
 *  VectorMultiply()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
wide *
VectorMultiply(long count, const long *vector1, long step1, const long *vector2,
               long step2, wide *dot) THREEWORDINLINE(0x303C, 0x0054, 0xA832);

/**
 *  RandomBits()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
unsigned long
RandomBits(long count, long focus) THREEWORDINLINE(0x303C, 0x0056, 0xA832);

/**
 *  SetRandomSeed()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
void
SetRandomSeed(const wide *seed) THREEWORDINLINE(0x303C, 0x0057, 0xA832);

/**
 *  GetRandomSeed()
 *

 *    \non_carbon_cfm   not available
 *    \carbon_lib        not available
 *    \mac_os_x         not available
 */
wide *
GetRandomSeed(wide *seed) THREEWORDINLINE(0x303C, 0x0058, 0xA832);

#endif /** CALL_NOT_IN_CARBON */

#define FixedRound(a) ((short)((Fixed)(a) + fixed1 / 2 >> 16))
#define FixedSquareRoot(a) ((Fixed)FractSquareRoot(a) + 64 >> 7)
#define FixedTruncate(a) ((short)((Fixed)(a) >> 16))
#define FixedToFract(a) ((Fract)(a) << 14)
#define FractToFixed(a) (((Fixed)(a) + 8192L) >> 14)
#define FixedToInt(a) ((short)(((Fixed)(a) + fixed1 / 2) >> 16))
#define IntToFixed(a) ((Fixed)(a) << 16)
#define FixedToFloat(a) ((float)(a) / fixed1)
#define FloatToFixed(a) ((Fixed)((float)(a) * fixed1))
#define FractToFloat(a) ((float)(a) / fract1)
#define FloatToFract(a) ((Fract)((float)(a) * fract1))
#define ColorToFract(a) (((Fract)(a) << 14) + ((Fract)(a) + 2 >> 2))
#define FractToColor(a) ((gxColorValue)((a) - ((a) >> 16) + 8191 >> 14))
#ifndef ff /** ff is already defined on some platforms */
#define ff(a) IntToFixed(a)
#define fl(a) FloatToFixed(a)
#endif

#if defined(__MWERKS__) && TARGET_CPU_68K
#pragma pop
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

#endif /** __GXMATH__ */
