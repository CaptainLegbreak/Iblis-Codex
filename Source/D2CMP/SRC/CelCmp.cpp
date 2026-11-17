#include "D2CMP.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CmpCellStrc;
struct D2DrlgLevelStrc;
struct D2CmpTileCacheStrc;
struct D2TileLibraryEntryStrc;
struct D2TileLibraryHeaderStrc;
struct D2TSLinkStrc;
struct D2TSListStrc;
struct D2CmpCacheBlockOwnerStrc;
struct D2CmpCacheKeyStrc;
struct D2CmpCacheListEntryStrc;
struct D2CmpCacheNodeStrc;
struct D2CmpCacheStrc;
struct D2TileRecordStrc;
struct D2CmpCelFileStrc;
struct D2CelBlockStrc;
struct D2CelStrc;
struct D2CelFileStrc;
struct D2CmpCelContextStrc;
struct D2FindTileNodeStrc;
struct D2FindTileEntryStrc;
struct Cell;
struct CellTable;
struct Unit;
struct D2StormLinkStrc;
struct D2StormListStrc;
struct D2Storm4167B0Strc;
struct D2Storm4168F0Strc;
struct D2Storm416A90Strc;
struct PairStrc_00601BB0;
struct PairStrc_00601D20;
struct PairStrc_00601DB0;
struct PairStrc_0060E1B0;
struct PairStrc_0060E290;
struct sub_0040F7D0;
struct sub_00417810;
struct sub_00417860;
struct sub_004178C0;
struct sub_00417900;
struct sub_00417950;
struct sub_004179B0;
struct sub_004183F0;
struct sub_00418430;
struct sub_00418780;
struct sub_004187C0;
struct sub_00418800;
struct sub_00418840;
struct sub_00418880;
struct sub_004188C0;
struct sub_00418BA0;
struct sub_00418BE0;
struct sub_00418C20;
struct sub_00418E10;
struct sub_0041C3D0;
struct sub_0041C500;
struct sub_0041C730;
struct sub_0041C800;
struct sub_00420430;
struct sub_004204B0;
struct sub_00420710;
struct sub_004207E0;
struct sub_00426960;
struct sub_00426A80;
struct sub_00426CB0;
struct sub_00426D80;
struct sub_0044DDD0;
struct sub_0044DE90;
struct sub_0044ECC0;
struct sub_0044ED50;
struct sub_00601BF0;
struct sub_00601C70;
struct sub_00601D60;
struct sub_00601F20;
struct sub_00601F60;
struct sub_006020D0;
struct sub_00602140;
struct sub_006024A0;
struct sub_00602760;
struct sub_00417780;
struct sub_00417850;
struct sub_004178B0;
struct sub_00417940;
struct sub_00417990;
struct sub_00418760;
struct sub_00418770;
struct sub_00418A40;
struct sub_00418DE0;
struct sub_00418DF0;
struct sub_00418E00;
struct sub_00418E50;
struct sub_00418FF0;
struct sub_00419060;
struct sub_0041C4F0;
struct sub_0041C720;
struct sub_0041C7F0;
struct sub_004204A0;
struct sub_00420700;
struct sub_004207D0;
struct sub_00426CA0;
struct sub_00426D70;
struct sub_0044BDE0;
struct sub_0044ED40;
struct sub_0044ED90;
struct sub_00601F10;
struct sub_00602130;
struct sub_00602180;
struct sub_00602420;
struct sub_00602750;
struct D2CommonStormSlotListAStrc;
struct D2CommonStormSlotArrayAStrc;
struct D2ChatStormLinkStrc;
struct D2ChatStormLinkAStrc;
struct D2ChatStormLinkBStrc;
struct D2ChatStormNodeStrc;
struct D2ChatStormBaseArrayAStrc;
struct D2ChatStormBaseArrayBStrc;
struct D2ChatStormListAStrc;
struct D2ChatStormListBStrc;
struct D2ChatStormHashTableStrc;
struct D2ChatStormCtorLinkStrc;
struct D2ChatStormListCStrc;
struct D2ChatStormListDStrc;
struct D2ChatStormListEStrc;
struct D2CommonStormSlotLinkStrc;
struct D2CommonStormSlotListBStrc;
struct D2CommonMappingEntryNodeBaseStrc;
struct D2CommonMappingEntryNodeStrc;
struct D2CommonStringEntryNodeStrc;
struct D2CommonStormHashTableAStrc;
struct R0052E0F0;
struct R00601DC0;
struct D2StormNodeStrc;
struct D2StormNodeListStrc;
struct D2StormListEStrc;
struct D2StormListEArrayStrc;
struct D2StormHashTableEStrc;
struct D2StormSlotLinkStrc;
struct D2StormSlotListStrc;
struct D2StormSlotArrayStrc;
struct D2StormHashNodeStrc;
struct D2GameHashTableStrc;
struct CriticalSection;
struct LockedObject;
struct D2StormChunkLinkStrc;
struct D2StormCtorLinkStrc;
struct D2SGameDataStrc;
struct D2StormGameArrayStrc;
struct D2StormListAStrc;
struct D2StormChunkListStrc;
struct sub_0044F9F0;
struct D2StormList0044FB30Strc;
struct D2StormDeadListStrc;
struct sub_0044FBE0;
struct sub_0044FC20;
struct sub_0044FDD0;
struct D2StormGameGrowArrayStrc;
struct D2StormGameHashChunkStrc;
struct D2Storm408ElemStrc;
struct D2StormArray408Strc;
struct DeleteFlags;
struct SlotArray;
struct D2CriticalSectionStrc;
struct D2CelEntryStrc;
struct D2StormEntry38Strc;
struct D2GameDataTableStrc;

typedef unsigned int size_t;

struct D2CmpPoolStrc
{
    unsigned char unk0x00[0x34];
};

struct D2CmpTileCacheStrc
{
    unsigned char unk0x00[0x2C];
    int bActive;
    unsigned char unk0x30[0x20];
};

struct D2TileLibraryEntryStrc
{
    unsigned char unk0x00[0x60];
};

struct D2TileLibraryHeaderStrc
{
    int dwVersion;
    int dwFlags;
    char szLibraryName[260];
    int nTiles;
    D2TileLibraryEntryStrc* pFirst;
};

struct D2TSLinkStrc
{
    D2TSLinkStrc* pPrevLink;
    unsigned int nNext;
};

struct D2TSListStrc
{
    int nLinkOffset;
    D2TSLinkStrc tTerminator;

    void sub_00601E80_InitCopy(const D2TSListStrc& source);
};

extern D2CmpPoolStrc gCmpPool; // 0x0088CAE0
extern D2CmpPoolStrc gCmpTilePool; // 0x0088DB20
extern D2CmpTileCacheStrc gCmpTileCache; // 0x0089DB60
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
void __fastcall sub_005FDE50(void* pEntry); // 0x005FDE50
void __cdecl sub_006006B0_FreeTileRecords(); // 0x006006B0
void __fastcall sub_005FFBE0_FreeTileCache(D2CmpTileCacheStrc* pCache); // 0x005FFBE0
void __cdecl sub_0060CD50_ReleaseTileLock(); // 0x0060CD50
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection); // 0x006CC214
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2CmpCacheBlockOwnerStrc
{
    char unk0x00[0x54];
    int nBlockUsed;
    char unk0x58[4];
    void* pBlock;
};
extern const char* gszCmpCompressedExtension; // 0x00741F00
extern const char* gszCmpDefaultExtension; // 0x00741F04

struct D2CmpCacheKeyStrc
{
    int nKeyA;
    int nKeyB;
    int nKeyC;
    char unk0x0C[0x14];
    unsigned char nFlags;
    char unk0x21[0x8F];
    T00481720* pAsyncData;
};

struct D2CmpCacheListEntryStrc
{
    D2CmpCacheKeyStrc* pKey;
    char unk0x04[0x10];
    D2CmpCacheListEntryStrc* pNext;
};

extern D2CmpCacheListEntryStrc* gpCmpCacheEntries; // 0x0089DB7C

struct D2CmpCacheNodeStrc
{
    char unk0x00[0x04];
    unsigned int nSize;
    char unk0x08[0x04];
    unsigned int dwFlags;
};

struct D2CmpCacheStrc
{
    char unk0x00[0x04];
    unsigned int nMaxSize;
    unsigned int nTotalSize;
    char unk0x0C[0x24];
    char tLock[0x18];
};

D2CmpCacheNodeStrc* __fastcall sub_005FF4A0_EvictCacheNode(D2CmpCacheStrc* pCache, D2CmpCacheNodeStrc* pNode, int nArg); // 0x005FF4A0

struct D2TileRecordStrc
{
    char szLibraryName[260];
    D2TileLibraryHeaderStrc* pLibrary;
    void* pHashBlock;
    D2TileRecordStrc* pPrev;
};

extern D2TileRecordStrc* gpTileRecords; // 0x008ADBB4
extern int gnCmpGfxMode; // 0x00741F08
extern unsigned char gaItemShiftMaps[][105][256]; // 0x008ADBB8
extern "C" int __cdecl sub_00517ABB_BitScanForward1(unsigned int nValue); // 0x00517ABB
extern int gaDirectionIndex32[][32]; // 0x006E3A20

struct D2CmpCelFileStrc
{
    int nVersion;
    unsigned int dwFlags;
    int nFormat;
    int unk0x0C;
    int nDirections;
    int nFrames;
    D2CmpCellStrc* pCells[1];
};

typedef void(__fastcall* CELFILECONVERTFN)(D2CmpCelFileStrc* pSource, D2CmpCelFileStrc* pTarget, int nArg1, int nArg2);

extern CELFILECONVERTFN gpfCelFileConvert[]; // 0x006E3690

struct D2CelBlockStrc
{
    char unk0x00[0x28];
    unsigned char* pPixels;
};

struct D2CelStrc
{
    int bFlip;
    int nWidth;
    int nHeight;
    int nXOffset;
    int nYOffset;
    unsigned int nDataSize;
    D2CelBlockStrc* pBlockPixelData;
    unsigned int nLength;
};

struct D2CelFileStrc
{
    int nVersion;
    unsigned int dwFlags;
    int nFormat;
    int nTermination;
    int nDirections;
    int nCelsPerDirection;
    D2CelStrc* pCels[1];
};

struct D2CmpCelContextStrc
{
    unsigned int nFrame;
    char unk0x04[0x30];
    D2CelFileStrc* pCelFile;
    char unk0x38[0x04];
    D2CelStrc* pCel;
    unsigned int nDirection;
};

typedef void(__fastcall* CELDRAWFN)(D2CelStrc* pCel, unsigned char* pDst, int nX, int nArg4, int nArg5, int nPitch, int nSkipRows, int nRows, int nArg9, int nArg10, int nArg13);

extern CELDRAWFN gpfnCelDraw[]; // 0x006E3688

struct D2FindTileNodeStrc
{
    void* pTile;
    D2FindTileNodeStrc* pNext;
};

struct D2FindTileEntryStrc
{
    int nKey2;
    int nKey3;
    int nKey1;
    D2FindTileNodeStrc* pTileList;
    D2FindTileEntryStrc* pNext;
};

unsigned char __fastcall sub_0060CD70_WrapIndex(int a, int b, int c); // 0x0060CD70
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
int __stdcall sub_00600C90_GetDirectionIndex64(int nDirection, unsigned int nDirections); // 0x00600C90

struct Cell { int unk0; int width; int height; char pad[0x14]; unsigned char data[1]; };

struct CellTable { int type; unsigned char flags; char pad[0xB]; int nDirections; int stride; Cell* cells[1]; };

struct Unit { int type; char pad4[0xC]; int mode; };

extern "C" const char emptyAssert; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl sub_00681E09(int); // 0x00681E09

enum { REQUIRED_TYPE = 6 };

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
    D2StormLinkStrc* sub_0060E170_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_0060E1C0_NextLink(int nLinkOffset);
    ~D2StormLinkStrc()
    {
        Unlink();
    }
};

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

extern unsigned short gwValue_0077905C;

struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};

struct D2Storm416A90Strc
{
    char pad00[0x14C];
    int n14C;
    int n150;
};

struct PairStrc_00601BB0
{
    int nFirst;
    int nSecond;
};

struct PairStrc_00601D20
{
    int nFirst;
    int nSecond;
};

struct PairStrc_00601DB0
{
    int nFirst;
    int nSecond;
};

struct PairStrc_0060E1B0
{
    int nFirst;
    int nSecond;
};

struct PairStrc_0060E290
{
    int nFirst;
    int nSecond;
};

extern int gdwGlobal_0096CA48; // 0x0096CA48
int __fastcall sub_0067DCE0(D2DrlgLevelStrc* pLevel); // 0x0067DCE0

struct sub_0040F7D0
{
    D2StormLinkStrc f_0;
    ~sub_0040F7D0();
};

struct sub_00417810
{
    D2StormLinkStrc f_0;
    ~sub_00417810();
};

struct sub_00417860
{
    D2StormLinkStrc f_0;
    ~sub_00417860();
};

struct sub_004178C0
{
    D2StormLinkStrc f_0;
    ~sub_004178C0();
};

struct sub_00417900
{
    D2StormLinkStrc f_0;
    ~sub_00417900();
};

struct sub_00417950
{
    D2StormLinkStrc f_0;
    ~sub_00417950();
};

struct sub_004179B0
{
    D2StormLinkStrc f_0;
    ~sub_004179B0();
};

struct sub_004183F0
{
    D2StormLinkStrc f_0;
    ~sub_004183F0();
};

struct sub_00418430
{
    D2StormLinkStrc f_0;
    ~sub_00418430();
};

struct sub_00418780
{
    D2StormLinkStrc f_0;
    ~sub_00418780();
};

struct sub_004187C0
{
    D2StormLinkStrc f_0;
    ~sub_004187C0();
};

struct sub_00418800
{
    D2StormLinkStrc f_0;
    ~sub_00418800();
};

struct sub_00418840
{
    D2StormLinkStrc f_0;
    ~sub_00418840();
};

struct sub_00418880
{
    D2StormLinkStrc f_0;
    ~sub_00418880();
};

struct sub_004188C0
{
    D2StormLinkStrc f_0;
    ~sub_004188C0();
};

struct sub_00418BA0
{
    D2StormLinkStrc f_0;
    ~sub_00418BA0();
};

struct sub_00418BE0
{
    D2StormLinkStrc f_0;
    ~sub_00418BE0();
};

struct sub_00418C20
{
    D2StormLinkStrc f_0;
    ~sub_00418C20();
};

struct sub_00418E10
{
    D2StormLinkStrc f_0;
    ~sub_00418E10();
};

struct sub_0041C3D0
{
    D2StormLinkStrc f_0;
    ~sub_0041C3D0();
};

struct sub_0041C500
{
    D2StormLinkStrc f_0;
    ~sub_0041C500();
};

struct sub_0041C730
{
    D2StormLinkStrc f_0;
    ~sub_0041C730();
};

struct sub_0041C800
{
    D2StormLinkStrc f_0;
    ~sub_0041C800();
};

struct sub_00420430
{
    D2StormLinkStrc f_0;
    ~sub_00420430();
};

struct sub_004204B0
{
    D2StormLinkStrc f_0;
    ~sub_004204B0();
};

struct sub_00420710
{
    D2StormLinkStrc f_0;
    ~sub_00420710();
};

struct sub_004207E0
{
    D2StormLinkStrc f_0;
    ~sub_004207E0();
};

struct sub_00426960
{
    D2StormLinkStrc f_0;
    ~sub_00426960();
};

struct sub_00426A80
{
    D2StormLinkStrc f_0;
    ~sub_00426A80();
};

struct sub_00426CB0
{
    D2StormLinkStrc f_0;
    ~sub_00426CB0();
};

struct sub_00426D80
{
    D2StormLinkStrc f_0;
    ~sub_00426D80();
};

struct sub_0044DDD0
{
    D2StormLinkStrc f_0;
    ~sub_0044DDD0();
};

struct sub_0044DE90
{
    D2StormLinkStrc f_0;
    ~sub_0044DE90();
};

struct sub_0044ECC0
{
    D2StormLinkStrc f_0;
    ~sub_0044ECC0();
};

struct sub_0044ED50
{
    D2StormLinkStrc f_0;
    ~sub_0044ED50();
};

struct sub_00601BF0
{
    D2StormLinkStrc f_0;
    ~sub_00601BF0();
};

struct sub_00601C70
{
    D2StormLinkStrc f_0;
    ~sub_00601C70();
};

struct sub_00601D60
{
    D2StormLinkStrc f_0;
    ~sub_00601D60();
};

struct sub_00601F20
{
    D2StormLinkStrc f_0;
    ~sub_00601F20();
};

struct sub_00601F60
{
    D2StormLinkStrc f_0;
    ~sub_00601F60();
};

struct sub_006020D0
{
    D2StormLinkStrc f_0;
    ~sub_006020D0();
};

struct sub_00602140
{
    D2StormLinkStrc f_0;
    ~sub_00602140();
};

struct sub_006024A0
{
    D2StormLinkStrc f_0;
    ~sub_006024A0();
};

struct sub_00602760
{
    D2StormLinkStrc f_0;
    ~sub_00602760();
};

struct sub_00417780
{
    D2StormLinkStrc f_0;
    sub_00417780();
};

struct sub_00417850
{
    D2StormLinkStrc f_0;
    sub_00417850();
};

struct sub_004178B0
{
    D2StormLinkStrc f_0;
    sub_004178B0();
};

struct sub_00417940
{
    D2StormLinkStrc f_0;
    sub_00417940();
};

struct sub_00417990
{
    D2StormLinkStrc f_0;
    sub_00417990();
};

struct sub_00418760
{
    D2StormLinkStrc f_0;
    sub_00418760();
};

struct sub_00418770
{
    D2StormLinkStrc f_0;
    sub_00418770();
};

struct sub_00418A40
{
    D2StormLinkStrc f_0;
    sub_00418A40();
};

struct sub_00418DE0
{
    D2StormLinkStrc f_0;
    sub_00418DE0();
};

struct sub_00418DF0
{
    D2StormLinkStrc f_0;
    sub_00418DF0();
};

struct sub_00418E00
{
    D2StormLinkStrc f_0;
    sub_00418E00();
};

struct sub_00418E50
{
    D2StormLinkStrc f_0;
    sub_00418E50();
};

struct sub_00418FF0
{
    D2StormLinkStrc f_0;
    sub_00418FF0();
};

struct sub_00419060
{
    D2StormLinkStrc f_0;
    sub_00419060();
};

struct sub_0041C4F0
{
    D2StormLinkStrc f_0;
    sub_0041C4F0();
};

struct sub_0041C720
{
    D2StormLinkStrc f_0;
    sub_0041C720();
};

struct sub_0041C7F0
{
    D2StormLinkStrc f_0;
    sub_0041C7F0();
};

struct sub_004204A0
{
    D2StormLinkStrc f_0;
    sub_004204A0();
};

struct sub_00420700
{
    D2StormLinkStrc f_0;
    sub_00420700();
};

struct sub_004207D0
{
    D2StormLinkStrc f_0;
    sub_004207D0();
};

struct sub_00426CA0
{
    D2StormLinkStrc f_0;
    sub_00426CA0();
};

struct sub_00426D70
{
    D2StormLinkStrc f_0;
    sub_00426D70();
};

struct sub_0044BDE0
{
    D2StormLinkStrc f_0;
    sub_0044BDE0();
};

struct sub_0044ED40
{
    D2StormLinkStrc f_0;
    sub_0044ED40();
};

struct sub_0044ED90
{
    D2StormLinkStrc f_0;
    sub_0044ED90();
};

struct sub_00601F10
{
    D2StormLinkStrc f_0;
    sub_00601F10();
};

struct sub_00602130
{
    D2StormLinkStrc f_0;
    sub_00602130();
};

struct sub_00602180
{
    D2StormLinkStrc f_0;
    sub_00602180();
};

struct sub_00602420
{
    D2StormLinkStrc f_0;
    sub_00602420();
};

struct sub_00602750
{
    D2StormLinkStrc f_0;
    sub_00602750();
};

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;

    ~D2CommonStormSlotLinkStrc()
    {
        Unlink();
    }
    D2CommonStormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2CommonStormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2CommonStormSlotLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;
    ~D2CommonStormSlotListAStrc();
    void UnlinkAll();
};

struct D2CommonStormSlotArrayAStrc {
 unsigned int m_alloc,m_count;
#ifdef MOVED_TEST
 int movedGap;
#endif
 D2CommonStormSlotListAStrc* m_data;
 unsigned int m_chunk;
 D2CommonStormSlotListAStrc* sub_00601CC0_At(unsigned int index);
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char gszIgnoreListSourceFile_006E6290[];

struct D2ChatStormLinkStrc
{
    D2ChatStormLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2ChatStormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2ChatStormLinkStrc*)(m_next + nLinkOffset);
    }
    char* MaskNext()
    {
        return (char*)((((int)m_next <= 0) - 1) & (int)m_next);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    bool sub_0060E0C0_IsLinked();
    char* sub_0060E1A0_Next();
    char* sub_0060E240_Next();
    void sub_0060E3B0_Unlink();
    void sub_0060E400_Unlink();
    void sub_0060E690_Unlink();
    void sub_0060E760_Unlink();
};

struct D2ChatStormLinkAStrc
{
    D2ChatStormLinkAStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkAStrc();
};

struct D2ChatStormLinkBStrc
{
    D2ChatStormLinkBStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkBStrc();
};

struct D2ChatStormNodeStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    char* sub_0060E0B0_GetKey();
};

struct D2ChatStormBaseArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;

    D2ChatStormBaseArrayAStrc();
    unsigned int sub_0060E230_Count();
};

struct D2ChatStormBaseArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;

    D2ChatStormBaseArrayBStrc();
    unsigned int sub_0060E250_Count();
};

struct D2ChatStormListAStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void sub_0060E260_InitializeTerminator();
    char* sub_0060E440_Head();
    void sub_0060E5F0_Reset();
};

struct D2ChatStormListBStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void sub_0060E270_InitializeTerminator();
    char* sub_0060E5D0_Head();
    void sub_0060E610_Reset();
};

struct D2ChatStormHashTableStrc
{
    void* m_pVTable;
    D2ChatStormListAStrc m_fulllist;

    char* sub_0060E6D0_Head();
};

struct D2ChatStormCtorLinkStrc
{
    D2ChatStormCtorLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormCtorLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2ChatStormListCStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListCStrc();
};

struct D2ChatStormListDStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListDStrc();
};

struct D2ChatStormListEStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListEStrc();
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    ~D2CommonStormSlotListBStrc();
    void UnlinkAll();
};

struct D2CommonMappingEntryNodeBaseStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    ~D2CommonMappingEntryNodeBaseStrc();
};

struct D2CommonMappingEntryNodeStrc : D2CommonMappingEntryNodeBaseStrc
{
    void* pMapped;

    ~D2CommonMappingEntryNodeStrc();
};

struct D2CommonStringEntryNodeStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    ~D2CommonStringEntryNodeStrc();
    void sub_0060EE30_Destroy();
};

struct D2CommonStormHashTableAStrc
{
    void sub_0060EB70_InternalClear(int bWarn);
    void sub_0060ED60_Clear();
};

struct R0052E0F0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_0052E0F0_IsOpen();
};

struct R00601DC0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_00601DC0_IsOpen();
};

int __stdcall D2CMP_CelFileFreeHardware(D2CelFileStrc* pCelFile); // 0x00601A50

struct D2StormNodeStrc
{
    D2StormLinkStrc f_0;
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    D2StormLinkStrc* Link(D2StormNodeStrc* pNode)
    {
        return pNode ? &pNode->f_0 : &m_terminator;
    }
    D2StormLinkStrc* sub_00601FA0_Link(D2StormNodeStrc* pNode);
    void sub_00601FC0_LinkNode(D2StormNodeStrc* pNode, int nLinkType, D2StormNodeStrc* pExistingNode);
    char* sub_00602070_Next(D2StormNodeStrc* pNode);
    void sub_00602190_UnlinkNode(D2StormNodeStrc* pNode);
    void sub_00602BF0_DeleteAll();                                                                          // 0x00602BF0
};

struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormLinkStrc* sub_00602110_Link(char* pNode);
    D2StormLinkStrc* sub_00602280_Link(char* pNode);
    void sub_006022F0_InitLinkField(int nLinkOffset);
    char* sub_00602310_Next(char* pNode);
    void sub_00602350_InitLinkField(int nLinkOffset);
    void sub_006024E0_LinkNode(char* pNode, int nLinkType, char* pExistingNode);
    void sub_00603F50_CopyLinkOffset(const D2StormListEStrc* pSource);
    void sub_00603FC0_LinkNode(char* pNode, int nLinkType, char* pExistingNode);
    void sub_0060E370_CopyLinkOffset(const D2StormListEStrc* pSource);
    void sub_0060E390_CopyLinkOffset(const D2StormListEStrc* pSource);
};

struct D2StormListEArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListEStrc* f_8;
    unsigned int f_C;

    D2StormListEStrc* sub_0060E0E0_At(unsigned int nIndex);
    D2StormListEStrc* sub_0060E110_At(unsigned int nIndex);
    unsigned int sub_0060E2A0_CalcChunkSize(unsigned int nCount);
    unsigned int sub_0060E300_CalcChunkSize(unsigned int nCount);
};

struct D2StormHashTableEStrc
{
    char unk0x00[0x24];
    unsigned int m_slotmask;

    unsigned int sub_0060E1F0_SlotIndex(unsigned int nHashVal);
    unsigned int sub_0060E210_SlotIndex(unsigned int nHashVal);
};

struct D2StormSlotLinkStrc
{
    D2StormSlotLinkStrc* m_prevlink;
    char* m_next;

    D2StormSlotLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormSlotLinkStrc()
    {
        Unlink();
    }
    D2StormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormSlotLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormSlotLinkStrc m_terminator;

    D2StormSlotListStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    ~D2StormSlotListStrc()
    {
        UnlinkAll();
    }
    D2StormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
    void LinkToTail(char* pNode)
    {

        D2StormSlotLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormSlotLinkStrc* pExistingLink = Link(0);
        D2StormSlotLinkStrc* pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
    }
    void UnlinkAll();                                                                                       // 0x00602640
};

struct D2StormSlotArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormSlotListStrc* f_8;
    unsigned int f_C;

    void sub_00603300_SetCount(unsigned int nCount);                                                        // 0x00603300
};

struct D2StormHashNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
};

struct D2GameHashTableStrc
{
    virtual void sub_006036D0_InternalDelete(D2StormHashNodeStrc* pNode);                                   // 0x006036D0
    virtual void sub_00603610_VirtSlot1();                                                                  // 0x00603610
    virtual void sub_006037B0_VirtSlot2();                                                                  // 0x006037B0
    virtual void sub_00603780_VirtSlot3();                                                                  // 0x00603780
    D2StormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_00603C80_GrowListArray();
};

struct CriticalSection { unsigned data[6]; };

struct LockedObject { char pad[0x50]; CriticalSection lock; void sub_00602090(int acquired); };

enum { NOT_ACQUIRED = 0 };

struct D2StormChunkLinkStrc
{
    D2StormChunkLinkStrc* m_prevlink;
    char* m_next;

    D2StormChunkLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormChunkLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormChunkLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2StormCtorLinkStrc
{
    D2StormCtorLinkStrc* m_prevlink;
    char* m_next;

    D2StormCtorLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2SGameDataStrc
{
    char unk0x00[0x1DF4];

    ~D2SGameDataStrc();
};

struct D2StormGameArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2SGameDataStrc* f_8;
    unsigned int f_C;

    ~D2StormGameArrayStrc();
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormListAStrc();
    void UnlinkAll();
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormChunkListStrc();
    void UnlinkAll();
};

struct sub_0044F9F0
{
    D2SGameDataStrc tData;

    ~sub_0044F9F0();
};

struct D2StormList0044FB30Strc
{
    int m_linkoffset;
    D2StormCtorLinkStrc m_terminator;

    D2StormList0044FB30Strc();
};

struct D2StormDeadListStrc
{
    int m_linkoffset;
    D2StormCtorLinkStrc m_terminator;

    D2StormDeadListStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormDeadListStrc(const D2StormDeadListStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};

struct sub_0044FBE0 : D2StormListAStrc
{
    ~sub_0044FBE0();
};

struct sub_0044FC20 : D2StormChunkListStrc
{
    ~sub_0044FC20();
};

struct sub_0044FDD0 : D2StormListAStrc
{
    ~sub_0044FDD0();
};

struct D2StormGameGrowArrayStrc
{
    D2StormGameArrayStrc tArray;

    ~D2StormGameGrowArrayStrc();
};

struct D2StormGameHashChunkStrc
{
    D2StormGameArrayStrc tArray;
    D2StormChunkLinkStrc f_10;

    ~D2StormGameHashChunkStrc();
};

extern "C" const char gszTypeNewsTableItem_0072FF8C[];

struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
};

struct D2StormArray408Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2Storm408ElemStrc* f_8;
    unsigned int f_C;

    D2StormArray408Strc* sub_0051D2C0_InitBase();
    unsigned int sub_0051D2F0_CalcChunkSize(unsigned int nCount);
    void sub_0051D570_FreeData();
    void sub_0051D5D0_ReallocData(unsigned int nCount);
    void sub_0051D670_FreeData();
    D2StormArray408Strc* sub_0051D690_Init();
    void sub_0051D6A0_Clear();
    D2StormArray408Strc* sub_0051D720_Init();
    void sub_0051D730_FreeData();
    D2Storm408ElemStrc* sub_0051D7A0_New();
    void ReserveInline(unsigned int nCount, int bRound);
};

struct DeleteFlags { unsigned value; };

int __stdcall sub_00412650(void*,const char*,int,unsigned); // 0x00412650

struct SlotArray { void Destroy(); SlotArray* sub_00603730(DeleteFlags flags); };

enum { DELETE_BIT = 1 };

struct D2CriticalSectionStrc
{
    int nOpaque[6];
};

struct D2CelEntryStrc : D2StormNodeStrc
{
    int nArg8;
    unsigned int nHeight;
    unsigned int nWidth;
    unsigned int nSize;
    int nArg6;
    int nArg7;
    void* pData;
};

struct D2StormEntry38Strc
{
    char unk0x00[0x18];
    unsigned int dwFlags;
    int nType;
    int nData;
    unsigned int nCount;
    unsigned int nDirections;
    D2StormNodeListStrc tList;
};

typedef void (__fastcall* CelFileBuildFn)(D2StormEntry38Strc* pList, D2CelFileStrc* pCelFile);

extern CelFileBuildFn gpfnCelFileBuilders_006E3680[]; // 0x006E3680
void __fastcall sub_0060D190_BuildCelFileWithData(D2StormEntry38Strc* pList, D2CelFileStrc* pCelFile); // 0x0060D190

struct D2GameDataTableStrc
{
    virtual void InternalDelete(D2StormEntry38Strc* pNode);
    char unk0x04[0x40];
    int f_44;
    char unk0x48[0x08];
    D2CriticalSectionStrc m_sync;

    D2StormEntry38Strc* sub_006030E0_InternalFind(unsigned int nHashVal, const int& tKey);                 // 0x006030E0
    void sub_006021E0_UnlinkNode(D2StormEntry38Strc* pNode);                                                // 0x006021E0
    void SyncEnterLock(int* pLockHandle, int bForWriting)
    {
        EnterCriticalSection(&m_sync);
        *pLockHandle = bForWriting ? 1 : -1;
    }
    void SyncLeaveLock(int nLockHandle)
    {
        if (nLockHandle)
            LeaveCriticalSection(&m_sync);
    }
    D2StormEntry38Strc* Ptr(unsigned int hHandle)
    {
        return sub_006030E0_InternalFind(hHandle, f_44);
    }
    D2StormEntry38Strc* Lock(unsigned int hHandle, int* pLockHandle, int bForWriting)
    {
        SyncEnterLock(pLockHandle, bForWriting);
        D2StormEntry38Strc* pList = Ptr(hHandle);
        if (!pList)
        {
            SyncLeaveLock(*pLockHandle);
            *pLockHandle = 0;
        }
        return pList;
    }
    void sub_0052E590(D2StormEntry38Strc* pNode)
    {
        sub_006021E0_UnlinkNode(pNode);
        InternalDelete(pNode);
    }
};

extern D2GameDataTableStrc gCelListTable; // 0x008E8CC0

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

int gbCmpPoolInitialized; // 0x0088CB14

int gnCmpPoolArg; // 0x0088CB18

// 0x005FDE10
void __stdcall sub_005FDE10_FreeCelPool(int bFree)
{
    if (gbCmpPoolInitialized)
    {
        if (bFree)
        {
            sub_006093E0_PoolFreeAll(&gCmpPool);
        }

        memset(&gCmpPool, 0, sizeof(gCmpPool));
        gnCmpPoolArg = 0;
    }

    sub_006006B0_FreeTileRecords();
}

// 0x005FDF80
int __fastcall sub_005FDF80_GetTileLibrarySize(const char* szFilePath)
{
    void* hFile;
    if (!ARCHIVE_OpenFile(0, szFilePath, &hFile, 0))
    {
        return 0;
    }

    D2TileLibraryHeaderStrc tHeader;
    ARCHIVE_ReadFileToBuffer(0, hFile, &tHeader, sizeof(tHeader));
    ARCHIVE_CloseFile(0, hFile);
    return tHeader.nTiles * sizeof(D2TileLibraryEntryStrc) + sizeof(tHeader);
}

// 0x005FE120
void __stdcall sub_005FE120_InitCelPool(void* pMemPool, int nArg)
{
    gnCmpPoolArg = nArg;
    memset(&gCmpPool, 0, sizeof(gCmpPool));
    sub_00609020_PoolInit(&gCmpPool, pMemPool, nArg, sub_005FDE50, 0x1000);
    gbCmpPoolInitialized = 1;
}

// 0x005FFE30
void __stdcall sub_005FFE30_FreeTileCache(int bFree)
{
    if (bFree && gCmpTileCache.bActive)
    {
        sub_005FFBE0_FreeTileCache(&gCmpTileCache);
    }

    memset(&gCmpTileCache, 0, sizeof(gCmpTileCache));

    if (bFree)
    {
        sub_006093E0_PoolFreeAll(&gCmpTilePool);
    }

    memset(&gCmpTilePool, 0, sizeof(gCmpTilePool));
    sub_0060CD50_ReleaseTileLock();
}

// 0x00601E80
void D2TSListStrc::sub_00601E80_InitCopy(const D2TSListStrc& source)
{
    nLinkOffset = source.nLinkOffset;
    tTerminator.pPrevLink = &tTerminator;
    tTerminator.nNext = ~(unsigned int)&tTerminator;
}

// 0x005FDF50
void __stdcall sub_005FDF50_FreeCacheBlock(D2CmpCacheBlockOwnerStrc* pOwner)
{
    sub_006092D0_PoolFree(&gCmpPool, pOwner->pBlock);
    pOwner->nBlockUsed = 0;
    pOwner->pBlock = 0;
}

// 0x005FE1F0
const char* __stdcall D2CMP_GetGfxFileExtension(int bAllowCompressed)
{
    if (bAllowCompressed && gbCmpCompressedDataMode)
    {
        return gszCmpCompressedExtension;
    }

    return gszCmpDefaultExtension;
}

// 0x005FF300
int __stdcall sub_005FF300_IsEntryPending(int nKeyA, int nKeyB, int nKeyC)
{
    for (D2CmpCacheListEntryStrc* pEntry = gpCmpCacheEntries; pEntry; pEntry = pEntry->pNext)
    {
        D2CmpCacheKeyStrc* pKey = pEntry->pKey;
        if (pKey && !(pKey->nFlags & 1) && pKey->nKeyC == nKeyC && pKey->nKeyB == nKeyB && pKey->nKeyA == nKeyA)
        {
            D2_ASSERT(pKey->pAsyncData, 0xB7B);
            if (!sub_0040A7F0_AsyncDataCheck(pKey->pAsyncData))
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x005FF630
void __fastcall sub_005FF630_ResizeCacheEntry(D2CmpCacheStrc* pCache, D2CmpCacheNodeStrc* pNode, int nDelta, int nArg)
{
    EnterCriticalSection(pCache->tLock);
    const unsigned int nNewSize = nDelta + pNode->nSize;
    pCache->nTotalSize -= pNode->nSize;
    pNode->dwFlags |= 2;
    pNode->nSize = nNewSize;
    pCache->nTotalSize += nNewSize;
    unsigned int nTotalSize = pCache->nTotalSize;
    LeaveCriticalSection(pCache->tLock);

    while (nTotalSize > pCache->nMaxSize)
    {
        D2CmpCacheNodeStrc* pEvicted = sub_005FF4A0_EvictCacheNode(pCache, 0, nArg);
        if (!pEvicted)
        {
            break;
        }

        D2_ASSERT(pEvicted != pNode, 0xA47);
        EnterCriticalSection(pCache->tLock);
        nTotalSize = pCache->nTotalSize;
        LeaveCriticalSection(pCache->tLock);
    }

    EnterCriticalSection(pCache->tLock);
    pNode->dwFlags &= ~2;
    LeaveCriticalSection(pCache->tLock);
}

// 0x00600960
D2TileLibraryHeaderStrc* __stdcall sub_00600960_FindTileLibrary(D2TileLibraryEntryStrc* pTile)
{
    for (D2TileRecordStrc* pRecord = gpTileRecords; pRecord; pRecord = pRecord->pPrev)
    {
        D2TileLibraryHeaderStrc* pLibrary = pRecord->pLibrary;
        for (int i = 0; i < pLibrary->nTiles; ++i)
        {
            if (pTile == &pLibrary->pFirst[i])
            {
                return pLibrary;
            }
        }
    }

    return 0;
}

// 0x00600C00
void __stdcall sub_00600C00_SetGfxMode(int nMode)
{
    if (nMode >= 1 && nMode <= 5)
    {
        gnCmpGfxMode = nMode;
    }
}

// 0x00600C20
unsigned char* __stdcall sub_00600C20(int nSet, int nIndex)
{
    if (nSet < 9 && nIndex < 21 && nSet != 0 && (nSet <= 2 || nSet > 4))
    {
        return gaItemShiftMaps[nSet][nIndex];
    }

    return 0;
}

// 0x00600C70
int __stdcall sub_00600C70_GetDirectionIndex32(int nDirection, unsigned int nDirections)
{
    return gaDirectionIndex32[sub_00517ABB_BitScanForward1(nDirections)][nDirection];
}

// 0x00600EE0
void __stdcall sub_00600EE0_CheckCelFile(D2CmpCelFileStrc* pCelFile, int nUnused)
{
    D2_ASSERT(pCelFile, 0x29C);
}

// 0x00600F10
int __stdcall sub_00600F10_CelFileConvert(D2CmpCelFileStrc* pSource, D2CmpCelFileStrc** ppTarget, int nArg1, int nArg2)
{
    D2_ASSERT(pSource->dwFlags & 4, 0x2AD);
    const int nCells = pSource->nDirections * pSource->nFrames;
    D2CmpCelFileStrc* pTarget = (D2CmpCelFileStrc*)FOG_Alloc(0x18 + nCells * sizeof(D2CmpCellStrc*), ".\\SRC\\CelCmp.cpp", 0x2B1, 0);
    pTarget->nVersion = 6;
    pTarget->dwFlags = pSource->dwFlags & ~7;
    pTarget->nDirections = pSource->nDirections;
    pTarget->nFrames = pSource->nFrames;
    pTarget->nFormat = 0;
    gpfCelFileConvert[pSource->nFormat](pSource, pTarget, nArg1, nArg2);
    *ppTarget = pTarget;
    return 1;
}

// 0x00601410
void __stdcall sub_00601410_CelFileFree(D2CmpCelFileStrc* pCelFile)
{
    D2_ASSERT(pCelFile, 0x40D);
    FOG_Free(pCelFile, ".\\SRC\\CelCmp.cpp", 0x40E, 0);
}

#include "gen/data/Source/D2CMP/SRC/CelCmp.inc"

// 0x00601340
void __stdcall D2CMP_CelFileNormalize(D2CelFileStrc* pFile, D2CelFileStrc** ppOutFile, const char* szFile, int nLine, int nSpecVersion, int nUnused)
{
    if (!pFile)
    {
        return;
    }

    const unsigned int dwFlags = pFile->dwFlags;
    D2_ASSERT(dwFlags & 1, 0x396);
    if (nSpecVersion == -1)
    {
        D2_ASSERT(pFile->nVersion == 6, 0x399);
    }
    else
    {
        D2_ASSERT(pFile->nVersion == nSpecVersion, 0x39B);
    }

    if (dwFlags & 2)
    {
        return;
    }

    const unsigned int nSize = pFile->nDirections * pFile->nCelsPerDirection * sizeof(D2CelBlockStrc);
    pFile->dwFlags = dwFlags | 2;
    D2CelBlockStrc* pBlocks = (D2CelBlockStrc*)FOG_Alloc(nSize, ".\\SRC\\CelCmp.cpp", 0x3A6, 0);
    memset(pBlocks, 0, nSize);
    unsigned int i = 0;
    if (i < (unsigned int)(pFile->nDirections * pFile->nCelsPerDirection))
    {
        D2CelBlockStrc* pBlock = pBlocks;
        D2CelStrc** ppCels = pFile->pCels;
        do
        {
            *ppCels = (D2CelStrc*)((char*)*ppCels + (unsigned int)pFile);
            (*ppCels)->pBlockPixelData = pBlock;
            ++i;
            ++pBlock;
            ++ppCels;
        }
        while (i < (unsigned int)(pFile->nDirections * pFile->nCelsPerDirection));
    }

    *ppOutFile = pFile;
}

// 0x006014C0
void __stdcall sub_006014C0(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11)
{
    D2CelFileStrc* pCelFile = pContext->pCelFile;
    if (pCelFile)
    {
        D2_ASSERT(pCelFile->nVersion == 6, 0x452);
        D2_ASSERT(!(pCelFile->dwFlags & 4), 0x453);
    }

    D2_ASSERT(pBuffer, 0x456);
    D2CelStrc* pCel = pContext->pCel;
    D2_ASSERT(pCel, 0x459);

    nY += pCel->nYOffset;
    nX += pCel->nXOffset;
    int nRows = pCel->nHeight;
    int nSkipRows = 0;
    if (nY - nRows < 0)
    {
        nRows = nY + 1;
    }

    if (nRows <= 0)
    {
        return;
    }

    if (nY >= nHeight)
    {
        nSkipRows = nY - nHeight + 1;
        nRows -= nSkipRows;
        if (nRows <= 0)
        {
            return;
        }
        nY = nHeight - 1;
    }

    if (!nArg4 && !nArg5)
    {
        if (nX < 0 || nY < 0)
        {
            return;
        }
    }

    unsigned char* pDst = pBuffer + nY * nPitch + nX;
    int nFormat = 0;
    if (pCelFile)
    {
        nFormat = pCelFile->nFormat;
    }

    CELDRAWFN pfnDraw = gpfnCelDraw[nFormat];
    D2_ASSERT(pfnDraw, 0x481);
    pfnDraw(pCel, pDst, nX, nArg4, nArg5, nPitch, nSkipRows, nRows, nArg9, nArg10, nArg11);
}

// 0x0060D040
int __fastcall sub_0060D040(D2FindTileEntryStrc** ppTable, void** ppResults, unsigned int nMax, int nKey1, int nKey2, int nKey3)
{
    int bFound = 0;
    int nCount = 0;
    D2_ASSERT(ppTable, 0xCF);
    D2_ASSERT(ppResults, 0xD0);
    if (!nMax)
    {
        return 0;
    }

    D2FindTileEntryStrc* pEntry = ppTable[sub_0060CD70_WrapIndex(nKey3, nKey2, nKey1)];
    while (pEntry && !bFound)
    {
        if (pEntry->nKey3 == nKey3 && pEntry->nKey2 == nKey2 && pEntry->nKey1 == nKey1)
            bFound = 1;
        else
            pEntry = pEntry->pNext;
    }

    if (bFound)
    {
        unsigned int i = 0;
        for (D2FindTileNodeStrc* pNode = pEntry->pTileList; pNode && i < nMax; pNode = pNode->pNext)
        {
            ppResults[i] = pNode->pTile;
            nCount += 1;
            i += 1;
        }
    }

    return nCount;
}

// 0x006015D0
int __stdcall sub_006015D0(CellTable* p, int nDirection, int nIndex, void* pDst)
{
    if (p->type != 6)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x4a0);
        exit(-1);
    }
    if ((p->flags & 4) == 0)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x4a1);
        exit(-1);
    }
    int idx = sub_00600C90_GetDirectionIndex64(nDirection, p->nDirections) * p->stride + nIndex;
    Cell* cell = p->cells[idx];
    int size = cell->height * cell->width;
    memcpy(pDst, cell->data, (unsigned int)size * 3);
    return 1;
}

// 0x006019B0
int __stdcall sub_006019B0(Unit* unit)
{
    if(unit->type!=REQUIRED_TYPE) {
        sub_00408A60(&emptyAssert,sub_00408090(),0x5C2);
        sub_00681E09(-1);
    }
    return unit->mode;
}

// 0x00601B40
void __cdecl sub_00601B40_Empty()
{
}

// 0x00601B50
void __cdecl sub_00601B50_Empty()
{
}

// 0x00601B60
char* __fastcall sub_00601B60_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00601C60
char* __fastcall sub_00601C60_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00601CE0
char* __fastcall sub_00601CE0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00601DF0
void __fastcall sub_00601DF0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00601E10
void __fastcall sub_00601E10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

unsigned short __stdcall sub_004166F0_GetWord()
{
    return gwValue_0077905C;
}

void __stdcall sub_00416750_Nop()
{
}

void __stdcall sub_00416760_Nop()
{
}

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00601B70
char* __fastcall sub_00416800_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
}

int gdwGlobal_0096C7F4; // 0x0096C7F4

int gdwGlobal_0096C8A4; // 0x0096C8A4

int gdwGlobal_0096D46C; // 0x0096D46C

// 0x00601BB0
void __fastcall sub_00601BB0(PairStrc_00601BB0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x00601D10
int __cdecl sub_00601D10()
{
    return 4;
}

// 0x00601D20
void __fastcall sub_00601D20(PairStrc_00601D20* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x00601DB0
void __fastcall sub_00601DB0(PairStrc_00601DB0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0060E0D0
int __cdecl sub_0060E0D0()
{
    return 4;
}

// 0x0060E100
int __cdecl sub_0060E100()
{
    return 4;
}

// 0x0060E1B0
void __fastcall sub_0060E1B0(PairStrc_0060E1B0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0060E290
void __fastcall sub_0060E290(PairStrc_0060E290* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x00611610
void __stdcall sub_00611610(int nUnused1)
{
}

// 0x00611640
void __stdcall sub_00611640(int nUnused1)
{
}

// 0x00611D10
int __cdecl sub_00611D10()
{
    return gdwGlobal_0096C7F4;
}

// 0x00611D20
int __cdecl sub_00611D20()
{
    return gdwGlobal_0096C8A4;
}

// 0x00624710
int __cdecl sub_00624710()
{
    return gdwGlobal_0096CA48;
}

// 0x0062A360
int __stdcall sub_0062A360(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x00631490
int __cdecl sub_00631490()
{
    return 2;
}

// 0x0063DB80
void __stdcall sub_0063DB80(int nUnused1, int nUnused2)
{
}

// 0x0063E050
void __stdcall sub_0063E050(int nUnused1, int nUnused2)
{
}

// 0x0063EBC0
void __stdcall sub_0063EBC0(int nUnused1, int nUnused2)
{
}

// 0x00641500
int __cdecl sub_00641500()
{
    return gdwGlobal_0096D46C;
}

// 0x00642740
int __cdecl sub_00642740()
{
    return 0;
}

// 0x0065CCB0
int __cdecl sub_0065CCB0()
{
    return 0;
}

// 0x00663740
void __stdcall sub_00663740(int nUnused1)
{
}

// 0x0066A210
void __stdcall sub_0066A210(int nUnused1, int nUnused2)
{
}

// 0x0066A220
void __stdcall sub_0066A220(int nUnused1, int nUnused2)
{
}

// 0x0066A230
int __stdcall sub_0066A230(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0066A240
int __stdcall sub_0066A240(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0066A250
void __stdcall sub_0066A250(int nUnused1)
{
}

// 0x00675810
int __fastcall sub_00675810(D2DrlgLevelStrc* pLevel)
{
    return sub_0067DCE0(pLevel);
}

// build: context sub_0068A420
int __cdecl sub_0068A420()
{
    return 0;
}

// build: context sub_0069FA20
int __cdecl sub_0069FA20()
{
    return 0;
}

// 0x0040F7D0
sub_0040F7D0::~sub_0040F7D0()
{
    f_0.Unlink();
}

// 0x00417810
sub_00417810::~sub_00417810()
{
    f_0.Unlink();
}

// 0x00417860
sub_00417860::~sub_00417860()
{
    f_0.Unlink();
}

// 0x004178C0
sub_004178C0::~sub_004178C0()
{
    f_0.Unlink();
}

// 0x00417900
sub_00417900::~sub_00417900()
{
    f_0.Unlink();
}

// 0x00417950
sub_00417950::~sub_00417950()
{
    f_0.Unlink();
}

// 0x004179B0
sub_004179B0::~sub_004179B0()
{
    f_0.Unlink();
}

// 0x004183F0
sub_004183F0::~sub_004183F0()
{
    f_0.Unlink();
}

// 0x00418430
sub_00418430::~sub_00418430()
{
    f_0.Unlink();
}

// 0x00418780
sub_00418780::~sub_00418780()
{
    f_0.Unlink();
}

// 0x004187C0
sub_004187C0::~sub_004187C0()
{
    f_0.Unlink();
}

// 0x00418800
sub_00418800::~sub_00418800()
{
    f_0.Unlink();
}

// 0x00418840
sub_00418840::~sub_00418840()
{
    f_0.Unlink();
}

// 0x00418880
sub_00418880::~sub_00418880()
{
    f_0.Unlink();
}

// 0x004188C0
sub_004188C0::~sub_004188C0()
{
    f_0.Unlink();
}

// 0x00418BA0
sub_00418BA0::~sub_00418BA0()
{
    f_0.Unlink();
}

// 0x00418BE0
sub_00418BE0::~sub_00418BE0()
{
    f_0.Unlink();
}

// 0x00418C20
sub_00418C20::~sub_00418C20()
{
    f_0.Unlink();
}

// 0x00418E10
sub_00418E10::~sub_00418E10()
{
    f_0.Unlink();
}

// 0x0041C3D0
sub_0041C3D0::~sub_0041C3D0()
{
    f_0.Unlink();
}

// 0x0041C500
sub_0041C500::~sub_0041C500()
{
    f_0.Unlink();
}

// 0x0041C730
sub_0041C730::~sub_0041C730()
{
    f_0.Unlink();
}

// 0x0041C800
sub_0041C800::~sub_0041C800()
{
    f_0.Unlink();
}

// 0x00420430
sub_00420430::~sub_00420430()
{
    f_0.Unlink();
}

// 0x004204B0
sub_004204B0::~sub_004204B0()
{
    f_0.Unlink();
}

// 0x00420710
sub_00420710::~sub_00420710()
{
    f_0.Unlink();
}

// 0x004207E0
sub_004207E0::~sub_004207E0()
{
    f_0.Unlink();
}

// 0x00426960
sub_00426960::~sub_00426960()
{
    f_0.Unlink();
}

// 0x00426A80
sub_00426A80::~sub_00426A80()
{
    f_0.Unlink();
}

// 0x00426CB0
sub_00426CB0::~sub_00426CB0()
{
    f_0.Unlink();
}

// 0x00426D80
sub_00426D80::~sub_00426D80()
{
    f_0.Unlink();
}

// 0x0044DDD0
sub_0044DDD0::~sub_0044DDD0()
{
    f_0.Unlink();
}

// 0x0044DE90
sub_0044DE90::~sub_0044DE90()
{
    f_0.Unlink();
}

// 0x0044ECC0
sub_0044ECC0::~sub_0044ECC0()
{
    f_0.Unlink();
}

// 0x0044ED50
sub_0044ED50::~sub_0044ED50()
{
    f_0.Unlink();
}

// 0x00601BF0
sub_00601BF0::~sub_00601BF0()
{
    f_0.Unlink();
}

// 0x00601C70
sub_00601C70::~sub_00601C70()
{
    f_0.Unlink();
}

// 0x00601D60
sub_00601D60::~sub_00601D60()
{
    f_0.Unlink();
}

// 0x00601F20
sub_00601F20::~sub_00601F20()
{
    f_0.Unlink();
}

// 0x00601F60
sub_00601F60::~sub_00601F60()
{
    f_0.Unlink();
}

// 0x006020D0
sub_006020D0::~sub_006020D0()
{
    f_0.Unlink();
}

// 0x00602140
sub_00602140::~sub_00602140()
{
    f_0.Unlink();
}

// 0x006024A0
sub_006024A0::~sub_006024A0()
{
    f_0.Unlink();
}

// 0x00602760
sub_00602760::~sub_00602760()
{
    f_0.Unlink();
}

// 0x00417780
sub_00417780::sub_00417780()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00417850
sub_00417850::sub_00417850()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x004178B0
sub_004178B0::sub_004178B0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00417940
sub_00417940::sub_00417940()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00417990
sub_00417990::sub_00417990()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418760
sub_00418760::sub_00418760()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418770
sub_00418770::sub_00418770()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418A40
sub_00418A40::sub_00418A40()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418DE0
sub_00418DE0::sub_00418DE0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418DF0
sub_00418DF0::sub_00418DF0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418E00
sub_00418E00::sub_00418E00()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418E50
sub_00418E50::sub_00418E50()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418FF0
sub_00418FF0::sub_00418FF0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00419060
sub_00419060::sub_00419060()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0041C4F0
sub_0041C4F0::sub_0041C4F0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0041C720
sub_0041C720::sub_0041C720()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0041C7F0
sub_0041C7F0::sub_0041C7F0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x004204A0
sub_004204A0::sub_004204A0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00420700
sub_00420700::sub_00420700()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x004207D0
sub_004207D0::sub_004207D0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00426CA0
sub_00426CA0::sub_00426CA0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00426D70
sub_00426D70::sub_00426D70()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0044BDE0
sub_0044BDE0::sub_0044BDE0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0044ED40
sub_0044ED40::sub_0044ED40()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0044ED90
sub_0044ED90::sub_0044ED90()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00601F10
sub_00601F10::sub_00601F10()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00602130
sub_00602130::sub_00602130()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00602180
sub_00602180::sub_00602180()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00602420
sub_00602420::sub_00602420()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00602750
sub_00602750::sub_00602750()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00601CC0
D2CommonStormSlotListAStrc* D2CommonStormSlotArrayAStrc::sub_00601CC0_At(unsigned int index) {return &m_data[index];}

// 0x00601CF0
extern "C" void* __fastcall sub_00601CF0(void* value) { return value; }

bool D2ChatStormLinkStrc::sub_0060E0C0_IsLinked()
{
    return m_next != 0;
}

char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

char* D2ChatStormNodeStrc::sub_0060E0B0_GetKey()
{
    return f_14;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::sub_0060E230_Count()
{
    return f_4;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::sub_0060E250_Count()
{
    return f_4;
}

void D2ChatStormListAStrc::sub_0060E260_InitializeTerminator()
{
    InitializeTerminator();
}

void D2ChatStormListBStrc::sub_0060E270_InitializeTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::sub_0060E5D0_Head()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::sub_0060E610_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x00601DA0
char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::sub_0060E6D0_Head()
{
    return m_fulllist.m_terminator.MaskNext();
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, gszIgnoreListSourceFile_006E6290, 0x11, 0);
}

void D2CommonStringEntryNodeStrc::sub_0060EE30_Destroy()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::sub_0060ED60_Clear()
{
    sub_0060EB70_InternalClear(0);
}

// 0x00436E90
int __stdcall sub_00436E90_AlwaysOne(int nArg)
{
    return 1;
}

// 0x004C6020
int __stdcall sub_004C6020_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00551FF0
int __stdcall sub_00551FF0_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00643880
int __stdcall sub_00643880_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00646260
int __stdcall sub_00646260_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00646270
int __stdcall sub_00646270_AlwaysOne(int nArg)
{
    return 1;
}

// 0x006436E0
int __fastcall sub_006436E0_Min(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

// 0x0064B700
int __fastcall sub_0064B700_Min(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

// 0x006436F0
int __fastcall sub_006436F0_Max(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

// 0x0064B710
int __fastcall sub_0064B710_Max(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

// 0x00648390
int __stdcall sub_00648390_AlwaysZero(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x004C5390
void __fastcall sub_004C5390_EnlargeVector(int* pX, int* pY)
{
    int nDistance = *pX * *pX + *pY * *pY;
    if (nDistance < 4)
    {
        *pX <<= 2;
        *pY <<= 2;
        nDistance = *pX * *pX + *pY * *pY;
    }

    if (nDistance < 16)
    {
        *pX <<= 1;
        *pY <<= 1;
    }
}

// 0x0052E0F0
bool R0052E0F0::sub_0052E0F0_IsOpen()
{
    return m_pFile != 0;
}

// 0x00601DC0
bool R00601DC0::sub_00601DC0_IsOpen()
{
    return m_pFile != 0;
}

// 0x00601EA0
void __stdcall sub_00601EA0_CelFileRelease(D2CelFileStrc* pCelFile)
{
    D2_ASSERT(pCelFile, 0x41B);
    if (pCelFile->dwFlags & 3)
    {
        if (pCelFile->dwFlags & 2)
        {
            D2CMP_CelFileFreeHardware(pCelFile);
        }
        FOG_Free(pCelFile, ".\\SRC\\CelCmp.cpp", 0x422, 0);
    }
}

// 0x00601F00
char* D2ChatStormListAStrc::sub_0060E440_Head()
{
    return m_terminator.MaskNext();
}

// 0x00601FA0
D2StormLinkStrc* D2StormNodeListStrc::sub_00601FA0_Link(D2StormNodeStrc* pNode)
{
    return pNode ? &pNode->f_0 : &m_terminator;
}

// 0x00601FC0
void D2StormNodeListStrc::sub_00601FC0_LinkNode(D2StormNodeStrc* pNode, int nLinkType, D2StormNodeStrc* pExistingNode)
{
    D2StormLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2StormLinkStrc* pExistingLink = Link(pExistingNode);
    D2StormLinkStrc* pPrevLink;
    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = (char*)pNode;
        break;
    default:
        pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = (char*)pNode;
        pExistingLink->m_prevlink = pLink;
        break;
    }
}

// 0x00602070
char* D2StormNodeListStrc::sub_00602070_Next(D2StormNodeStrc* pNode)
{
    return Link(pNode)->Next();
}

// 0x00602110
D2StormLinkStrc* D2StormListEStrc::sub_00602110_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
}

// 0x00602190
void D2StormNodeListStrc::sub_00602190_UnlinkNode(D2StormNodeStrc* pNode)
{
    Link(pNode)->Unlink();
}

// 0x00602280
D2StormLinkStrc* D2StormListEStrc::sub_00602280_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
}

// 0x006022F0
void D2StormListEStrc::sub_006022F0_InitLinkField(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x00602310
char* D2StormListEStrc::sub_00602310_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x00602350
void D2StormListEStrc::sub_00602350_InitLinkField(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x006024E0
void D2StormListEStrc::sub_006024E0_LinkNode(char* pNode, int nLinkType, char* pExistingNode)
{
    D2StormLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2StormLinkStrc* pExistingLink = Link(pExistingNode);
    D2StormLinkStrc* pPrevLink;
    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = pNode;
        break;
    default:
        pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
        break;
    }
}

// 0x00603C80
void D2GameHashTableStrc::sub_00603C80_GrowListArray()
{
    unsigned int nOldCount = m_slotmask + 1;
    unsigned int nNewCount = 2 * nOldCount;
    D2StormSlotListStrc tTempList;
    tTempList.ChangeLinkOffset(4);

    for (unsigned int i = 0; i < nOldCount; i++)
    {
        char* pNode;
        while ((pNode = m_slotlistarray.f_8[i].Head()) != 0)
            tTempList.LinkToTail(pNode);
    }

    m_slotlistarray.sub_00603300_SetCount(nNewCount);
    for (unsigned int i = 0; i < nNewCount; i++)
        m_slotlistarray.f_8[i].ChangeLinkOffset(4);
    m_slotmask = nNewCount - 1;

    char* pNode;
    while ((pNode = tTempList.Head()) != 0)
        m_slotlistarray.f_8[((D2StormHashNodeStrc*)pNode)->f_0 & m_slotmask].LinkToTail(pNode);
}

// 0x00603F50
void D2StormListEStrc::sub_00603F50_CopyLinkOffset(const D2StormListEStrc* pSource)
{
    m_linkoffset = pSource->m_linkoffset;
    InitializeTerminator();
}

// 0x00603FC0
void D2StormListEStrc::sub_00603FC0_LinkNode(char* pNode, int nLinkType, char* pExistingNode)
{
    D2StormLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2StormLinkStrc* pExistingLink = Link(pExistingNode);
    D2StormLinkStrc* pPrevLink;
    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = pNode;
        break;
    default:
        pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
        break;
    }
}

// 0x0060E0E0
D2StormListEStrc* D2StormListEArrayStrc::sub_0060E0E0_At(unsigned int nIndex)
{
    return &f_8[nIndex];
}

// 0x0060E110
D2StormListEStrc* D2StormListEArrayStrc::sub_0060E110_At(unsigned int nIndex)
{
    return &f_8[nIndex];
}

// 0x0060E170
D2StormLinkStrc* D2StormLinkStrc::sub_0060E170_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0060E1C0
D2StormLinkStrc* D2StormLinkStrc::sub_0060E1C0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0060E1F0
unsigned int D2StormHashTableEStrc::sub_0060E1F0_SlotIndex(unsigned int nHashVal)
{
    return m_slotmask & nHashVal;
}

// 0x0060E210
unsigned int D2StormHashTableEStrc::sub_0060E210_SlotIndex(unsigned int nHashVal)
{
    return m_slotmask & nHashVal;
}

// 0x0060E2A0
unsigned int D2StormListEArrayStrc::sub_0060E2A0_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x15)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    f_C = 0x15;
    return 0x15;
}

// 0x0060E2E0
unsigned int __stdcall sub_0060E2E0_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x0060E300
unsigned int D2StormListEArrayStrc::sub_0060E300_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x15)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    f_C = 0x15;
    return 0x15;
}

// 0x0060E340
unsigned int __stdcall sub_0060E340_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x0060E370
void D2StormListEStrc::sub_0060E370_CopyLinkOffset(const D2StormListEStrc* pSource)
{
    m_linkoffset = pSource->m_linkoffset;
    InitializeTerminator();
}

// 0x0060E390
void D2StormListEStrc::sub_0060E390_CopyLinkOffset(const D2StormListEStrc* pSource)
{
    m_linkoffset = pSource->m_linkoffset;
    InitializeTerminator();
}

// 0x00602090
void LockedObject::sub_00602090(int acquired)
{
    if(acquired!=NOT_ACQUIRED) LeaveCriticalSection(&lock);
}

// 0x00602370
void D2ChatStormListAStrc::sub_0060E5F0_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x00602710
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00602910
D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

sub_0044F9F0::~sub_0044F9F0()
{
}

D2StormListAStrc::~D2StormListAStrc()
{
    UnlinkAll();
}

D2StormChunkListStrc::~D2StormChunkListStrc()
{
    UnlinkAll();
}

// 0x00602930
D2StormList0044FB30Strc::D2StormList0044FB30Strc()
{
    m_linkoffset = 0x10;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

sub_0044FBE0::~sub_0044FBE0()
{
}

sub_0044FC20::~sub_0044FC20()
{
}

void __fastcall sub_0044FD60_CopyConstructDeadList(D2StormDeadListStrc* pList, const D2StormDeadListStrc* pSource)
{
    new (pList) D2StormDeadListStrc(*pSource);
}

sub_0044FDD0::~sub_0044FDD0()
{
}

D2StormGameGrowArrayStrc::~D2StormGameGrowArrayStrc()
{
}

D2StormGameHashChunkStrc::~D2StormGameHashChunkStrc()
{
    f_10.Unlink();
}

// 0x00602950
void __fastcall sub_0044FB50_ConstructDeadList(D2StormDeadListStrc* pList)
{
    new (pList) D2StormDeadListStrc;
}

inline unsigned int RoundUpInline(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

inline void D2StormArray408Strc::ReserveInline(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D2C0_InitBase()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    return this;
}

void __cdecl sub_0051D2D0_Nop()
{
}

void __cdecl sub_0051D2E0_Nop()
{
}

void __fastcall sub_0051D350_CopyElement(D2Storm408ElemStrc* pDst, const D2Storm408ElemStrc* pSrc)
{
    if (pDst)
        *pDst = *pSrc;
}

void D2StormArray408Strc::sub_0051D570_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

// 0x006031E0
D2StormArray408Strc* D2StormArray408Strc::sub_0051D690_Init()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    f_C = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D720_Init()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    f_C = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D730_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &f_8[f_4++];
}

// 0x00603730
SlotArray* SlotArray::sub_00603730(DeleteFlags flags)
{
    Destroy();
    if(flags.value & DELETE_BIT) {
        if(this) sub_00412650(this,"delete",-1,0);
    }
    return this;
}

// 0x006039C0
void __stdcall sub_006039C0(unsigned int hCelList)
{
    int hLock;
    D2StormEntry38Strc* pList = gCelListTable.Lock(hCelList, &hLock, 0);
    for (D2CelEntryStrc* pEntry = (D2CelEntryStrc*)((((int)pList->tList.m_terminator.m_next <= 0) - 1) & (int)pList->tList.m_terminator.m_next); (int)pEntry > 0; pEntry = (D2CelEntryStrc*)pEntry->f_0.m_next)
    {
        FOG_Free(pEntry->pData, ".\\SRC\\CelCmp.cpp", 588, 0);
    }
    pList->tList.sub_00602BF0_DeleteAll();
    gCelListTable.sub_0052E590(pList);
    gCelListTable.SyncLeaveLock(hLock);
}

// 0x00603A70
unsigned int __stdcall sub_00603A70(unsigned int hCelList, D2CelFileStrc** ppCelFile)
{
    int hLock;
    D2StormEntry38Strc* pList = gCelListTable.Lock(hCelList, &hLock, 0);
    *ppCelFile = 0;

    if (!pList->nCount)
    {
        return 0x85200001;
    }

    if (pList->nCount % pList->nDirections)
    {
        return 0x85200002;
    }

    D2CelFileStrc* pCelFile = (D2CelFileStrc*)FOG_Alloc(pList->nCount * sizeof(void*) + 0x18, ".\\SRC\\CelCmp.cpp", 615, 0);
    pCelFile->nVersion = 6;
    pCelFile->dwFlags = pList->dwFlags;
    pCelFile->nFormat = pList->nType;
    pCelFile->nDirections = pList->nDirections;
    pCelFile->nCelsPerDirection = pList->nCount / pList->nDirections;
    if (pList->dwFlags & 4)
    {
        sub_0060D190_BuildCelFileWithData(pList, pCelFile);
        pCelFile->nTermination = pList->nData;
    }
    else
    {
        gpfnCelFileBuilders_006E3680[pList->nType](pList, pCelFile);
    }

    gCelListTable.SyncLeaveLock(hLock);
    *ppCelFile = pCelFile;
    return 0;
}
