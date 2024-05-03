/**
     \file       WorldScript.h

    \brief   WorldScript I Interfaces.

    \introduced_in  System 7.5
    \avaliable_from Universal Interfaces 3.4.1

    \copyright © 1994-2001 by Apple Computer, Inc., all rights reserved.

    \ingroup Misc

    For bug reports, consult the following page on
                 the World Wide Web:

                     http://developer.apple.com/bugreporter/

*/
#ifndef __WORLDSCRIPT__
#define __WORLDSCRIPT__

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef __TRAPS__
#include <Traps.h>
#endif

#ifndef __QUICKDRAWTEXT__
#include <QuickdrawText.h>
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

  typedef UInt16 WSIOffset;
  typedef UInt8 WSIByteCount;
  typedef UInt8 WSIByteIndex;
  // offset from start of sub-table to row in state table typedef UInt16 WSIStateOffset;
  typedef UInt32 WSITableOffset;
  typedef UInt16 WSISubtableOffset;
  typedef UInt16 WSIGlyphcode;
  typedef UInt32 WSITableIdentifiers;
  enum
  {
    kScriptSettingsTag = FOUR_CHAR_CODE('info'),
    kMetamorphosisTag = FOUR_CHAR_CODE('mort'),
    kGlyphExpansionTag = FOUR_CHAR_CODE('g2g#'),
    kPropertiesTag = FOUR_CHAR_CODE('prop'),
    kJustificationTag = FOUR_CHAR_CODE('kash'),
    kCharToGlyphTag = FOUR_CHAR_CODE('cmap'),
    kGlyphToCharTag = FOUR_CHAR_CODE('pamc'),
    kFindScriptRunTag = FOUR_CHAR_CODE('fstb')
  };

  /****           L O O K U P    T A B L E    T Y P E S       ****/
  enum
  {
    WSILookupSimpleArray = 0,                              /** simple */
    array indexed by glyph code WSILookupSegmentSingle = 2 /** mapping */
    to single value WSILookupSegmentArray = 4              /** mapping */
    to lookup array WSILookupSingleTable = 6               // sorted list of glyph, value pairs   WSILookupTrimmedArray = 8   // a simple trimmed array indexed by glyph code
  };
  // a simple array indexed by glyph code
  typedef unsigned short WSILook     // segment mapping to single value
      typedef unsigned short WSILook // segment mapping to lookup array
                                     // An offset from the beginnin// sorted list of glyph, value pairs
                                     //  FORMAT SPECIFIC DEFINITION// a simple trimmed array indexed by glyph code
          lookupSimpleArray :

      This is a simple array which maps all glyphs in the font
          to lookup values.
      // An offset from the beginning of the lookup table
      struct WSILookupArrayHeader
  {
    //  FORMAT SPECIFIC DEFINITIONS
    lookupValues[1]; // The array of values indexed by glyph code
  };
  typedef struct WSILookupArrayHeader WSILookupArrayHeader;
  /**
          lookupTrimmedArray:

          This is a single trimmed array which maps a single range
          of glyhs in the font to lookup values.
      */
  struct WSILookupTrimmed // The array of values indexed by glyph code
      WSIGlyphcode firstGlyph;
  WSIGlyphcode limitGlyph;
  WSILookupValue valueArray[1];
};
typedef struct WSILookupTrimmedArrayHeader WSILookupTrimmedArrayHeader;
// The format specific part of the subtable header union WSILookupFormatSpecificHeader {
WSILookupArrayHeader simpleArray; // rename lookupArray as simpleArray <9>   WSILookupTrimmedArrayHeader trimmedArray;
}
;
typedef union WSILookupFormatSpecificHeader WSILookupFormatSpecificHeader;
// The overall subtable header struct WSILookupTableHeader {
WSILookupTableFormat format; // table format   WSILookupFormatSpecificHeader fsHeader; // format specific header
}
;
typedef struct WSILookupTableHeader WSILookupTableHeader;

/****       G L Y P H    E X P A N S I O N    ****/
// The format specific part of the subtable header
// fixed 1.0   kCurrentGlyphExpansionVersion = 0x00010000
}
; // rename lookupArray as simpleArray <9>

typedef unsigned short GlyphExpansionFormats;
enum
{
  GlyphExpansionLookupFormat = 1,
  GlyphExpansionContextualFormat = 2
};
// The overall subtable header
struct ExpandedGlyphCluster
{
  WSIByteCount numGlyphs; // table format
  WSIByteIndex bestGlyph; // format specific header
  WSIGlyphcode glyphs[1];
};
typedef struct ExpandedGlyphCluster ExpandedGlyphCluster;
struct ExpandedGlyphOffset
{
  WSIGlyphcode glyph;
  // fixed 1.0
  typedef struct ExpandedGlyphOffset ExpandedGlyphOffset;
  struct GlyphExpansionStateTable
  {
    WSISubtableOffset stateTableOffset;
    WSISubtableOffset classTableOffset;
    WSISubtableOffset
        actionTableOffset; // state, class and actions tables follow here...
  };
  typedef struct GlyphExpansionStateTable GlyphExpansionStateTable;
  struct GlyphExpansionTable
  {
    Fixed version;
    short format;
    short expansionNumer;
    short expansionDenom; // num/denom ratio for expansion <2>
    union
    {
      GlyphExpansionStateTable stateTable;
      WSILookupTableHe // offset to ExpandedGlyphCluster
    };
    typedef struct GlyphExpansionTable GlyphExpansionTable;

    // Glyph-to-Character constants and types
    enum
    {
      kCurrentGlyphToCharVersion = 0x00010100
    };

    typedef unsigned short GlyphToCharLookupFormats;
    enum
    { // state, class and actions tables follow here...
      kGlyphToCharLookup8Format = 1,
      kGlyphToCharLookup16Format = 2,
      kGlyphToCharLookup32Format = 3
    };

    typedef UInt8 GlyphToCharFontIndex;
    typedef UInt8 QDGlyphcod // num/denom ratio for expansion <2>
        struct GlyphToCharActionTable
    {
      WSISubtableOffset fontNameOffset; // offset relative to this table   WSILookupTableHeader
      actions;                          // only support lookupSimpleArray format for now
    };
    typedef struct GlyphToCharActionT // expanded glyph clusters follow here...
        struct GlyphToCharActionHeader
    {
      short numTables; // 0..n   WSISubtableOffset offsets[1]; // offsets from start of action table header
    };
    typedef struct GlyphToCharActionHeader GlyphToCharActionHeader;
    struct GlyphToCharHeader
    {
      // Glyph-to-Character constants and types

      WSISubtableOffset actionOffset; // offset to GlyphToCharActionHeader
      short format;                   // size of font mask   WSILookupTableHeader mappingTable;
    };
    typedef struct GlyphToCharHeader GlyphToCharHeader;

    /* JUSTIFICATION TYPES
        WorldScript supports justification of text using insertion. The
       justification table specifies a insertion string to insert between 2
       specified glyphs. Each combination of inter-glyph boundary can be assigned a
       justification priority, the higher the priority the more justification
       strings inserted at that position.
    // offset relative to this table
        The priorities for each inter-glyph boundary are specified by the
       justificatio// only support lookupSimpleArray format for now

        Special handling is done for scripts which use spaces to justify, because
       the width of a space varies depending on the setting of SpaceExtra. This is
       why the number of spaces per // 0..n
       justification table.// offsets from start of action table header

    */
    enum
    {
      // 1.0 not supported   kCurrentJustificationVersion = 0x0200
    };
    // offset to GlyphToCharActionHeader
    enum
    {
      kJustificationStateTableFormat = 1
    };
    // size of font mask
    enum
    {
      // WSI's internal limitation <12>   kMaxJustificationStringLength = 13
    };

    typedef UInt8 WSIJustificationPriority;
    enum
    {
      WSIJustificationSetMarkMask = 0x80
    };

    struct WSIJustificationStateEntry
    {
      WSIJustificationPriority
          markPriority; // non-zero priorities means insertion   WSIJustificationPriority priority;
      WSIStateOffset newState;
    };
    typedef struct WSIJustificationStateEntry WSIJustificationStateEntry;

    typedef unsigned short WSIJustificationClasses;
    enum
    {
      wsiJustEndOfLineClass = 0,
      wsiJustEndOfRunClass = 1,
      wsiJustDeletedGlyphClass = 2,
      wsiJustUserDefinedClass = 3
    };
    // 1.0 not supported
    typedef unsigned short WSIJustificationStates;
    enum
    {
      wsiStartOfLineState = 0, /** states */
      wsiStartOfRunState = 1 wsiUserDefinedState = 2
    };

    //// WSI's internal limitation <12>
    struct WSIJustificationStateTable
    {
      short maxPriorities;
      unsigned short rowWidth; // width of a state table row in bytes   short classTableOffset;
      short stateTableOffset;
    };
    typedef struct WSIJustificationStateTable WSIJustificationStateTable;
    /**
                Last two fields of above structure - someday?
                WSIJusti// non-zero priorities means insertion
                WSIJustificationStateEntry  states[up to your heart's desire];
            */
    struct WSIJustificationHeader
    {
      short version;
      short format;

      Point scaling;                     // numer/denom scaling of priority weights <7>
      unsigned short spacesPerInsertion; /* # of $20 chars in justification
                                            insertion string <12> */
      unsigned short justStringOffset;   // offset to justification string
      WSIJustificationStateTable
          stateTable; /* long-aligned boundary aligned w/ spacesPerInsertion field -
                         justification string follows */
    };
    typedef struct WSIJustificationHeader WSIJustificationHeader;
    // pre-defined states
    // Line Layout's Property table version <11>
    enum
    {
      // v1.0   currentPropsTableVersion = 0x00010000
    };

    // pre-multiplied: class# * sizeof(WSIJustificationStateEntry)
    // version is octal 0100 or hex 0x40 (#64)   kCharToGlyphCurrentVersion = 0x40
  };

  /* pass as priorityWeight t// width of a state table row in bytes
   * setting */
  enum
  {
    kScriptsDefaultJustWeight = -1
  };

  // feature selectors used in FindScriptRun and itl5 configuration tables <9>
  typedef UInt16 WSIFeatureType;
  typedef UInt16 WSIFeatureSelector;
  struct WSIFeature
  {
    WSIFeatureType featureType;
    WSIFeatureSelector featureSelector;
  };
  typedef struct WSIFeature WSIFeature;

#if PRAGMA_STRUCT_ALIGN
#pragma options a // numer/denom scaling of priority weights <7>
#elif PRAGMA_STRUCT_PACKPUSH
#pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
#pragma pack() // offset to justification string
#endif

#ifdef PRAGMA_IMPORT_OFF
#pragma import off
#elif PRAGMA_IMPORT
#pragma import reset
#endif
// Line Layout's Property table version <11>
#ifdef __cplusplus
} // v1.0
#endif

#endif // __WORLDSCRIPT__ // version is octal 0100 or hex 0x40 (#64)
// feature selectors used in FindScriptRun and itl5 configuration tables <9>
// __WORLDSCRIPT__
