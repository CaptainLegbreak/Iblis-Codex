#include "D2CMP.h"

#include "D2CmpTileRecord.h"

#include "D2CmpCelFile.h"

#include "D2GameTypes.h"

#include "D2DrlgMaps.h"

#include "D2CmpTypes.h"

#include "D2CmpStormList.h"

#include "D2CmpStormHash.h"

#include "D2LRUNode.h"
#include "D2StormListArray.h"
#include "D2FindTileEntry.h"
#include "D2CmpDC6CacheEntry.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CmpCellStrc;

struct D2DrlgLevelStrc;

struct D2CmpTileCacheStrc;

struct D2TileLibraryEntryStrc;

struct D2TSLinkStrc;

struct D2TSListStrc;

struct D2CmpCacheBlockOwnerStrc;

struct D2CmpCacheKeyStrc;

struct D2CmpCacheListEntryStrc;

struct D2CmpCacheNodeStrc;

struct D2CmpCacheStrc;

struct D2CelBlockStrc;

struct D2CmpCelContextStrc;

struct D2FindTileNodeStrc;

struct D2FindTileEntryStrc;

struct Cell;

struct CellTable;


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

struct D2StormListEArrayStrc;

struct D2StormHashTableEStrc;

struct CriticalSection;

struct LockedObject;

struct D2StormChunkLinkStrc;

struct D2StormCtorLinkStrc;

struct D2SGameDataStrc;

struct D2StormGameArrayStrc;

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

struct D2CmpPoolStrc;

class WardenModule;

struct D2Warden47F930Strc;

struct D2WardenModuleHolderAStrc;

struct D2WardenModuleHolderBStrc;

struct D2CmpTileCacheStrc
{
    unsigned char unk0x00[0x2C];
    int bActive;
    unsigned char unk0x30[0x20];
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

void __fastcall D2CMPTileCacheReleaseTile(void* pEntry); // 0x005FDE50

void __cdecl D2CMPDestroyTileHeaders(); // 0x006006B0

void __fastcall D2CMPSpriteCacheFreeAll(D2CmpTileCacheStrc* pCache); // 0x005FFBE0

void __cdecl CodecReleaseLock(); // 0x0060CD50

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

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
    D2CriticalSectionStrc tLock;
};

D2CmpCacheNodeStrc* __fastcall D2CMPSpriteCacheEvict(D2CmpCacheStrc* pCache, D2CmpCacheNodeStrc* pNode, int nArg); // 0x005FF4A0

extern D2TileRecordStrc* gpTileRecords; // 0x008ADBB4

extern int gnCmpGfxMode; // 0x00741F08

extern unsigned char gaItemShiftMaps[][105][256]; // 0x008ADBB8

int __cdecl sub_00517ABB_FindLowestSetBit(unsigned int dwMask); // 0x00517ABB

extern int gaDirectionIndex32[][32]; // 0x006E3A20

typedef void(__fastcall* CELFILECONVERTFN)(D2CelFileStrc* pSource, D2CelFileStrc* pTarget, int nArg1, int nArg2);

extern CELFILECONVERTFN gpfCelFileConvert[]; // 0x006E3690

typedef void(__fastcall* CELDRAWFN)(D2CelStrc* pCel, unsigned char* pDst, int nX, int nArg4, int nArg5, int nPitch, int nSkipRows, int nRows, int nArg9, int nArg10, int nArg13);

extern CELDRAWFN gpfnCelDraw[]; // 0x006E3688

struct D2FindTileNodeStrc
{
    void* pTile;
    D2FindTileNodeStrc* pNext;
};


unsigned char __fastcall FindTileHash(int a, int b, int c); // 0x0060CD70

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

int __stdcall CelGameDirToFileDir(int nDirection, unsigned int nDirections); // 0x00600C90

struct Cell { int unk0; int width; int height; char pad[0x14]; unsigned char data[1]; };

struct CellTable { int type; unsigned char flags; char pad[0xB]; int nDirections; int stride; Cell* cells[1]; };


extern "C" const char emptyAssert; // 0x006CC837

enum { REQUIRED_TYPE = 6 };

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

int __fastcall DRLGOUTSIEGE_GetBorderLookupId(D2DrlgLevelStrc* pLevel); // 0x0067DCE0

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

struct D2CommonStormSlotArrayAStrc {
 unsigned int m_alloc,m_count;
 D2CommonStormSlotListAStrc* m_data;
 unsigned int m_chunk;
 D2CommonStormSlotListAStrc* sub_00601CC0_At(unsigned int index);
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

extern "C" const char gszIgnoreListSourceFile_006E6290[];

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

int __stdcall CelFileFreeHardware(D2CelFileStrc* pCelFile); // 0x00601A50

struct D2StormListEArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormListEStrc* m_data;
    unsigned int m_chunk;

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
    unsigned int m_alloc;
    unsigned int m_count;
    D2SGameDataStrc* m_data;
    unsigned int m_chunk;

    ~D2StormGameArrayStrc();
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

struct DeleteFlags { unsigned value; };

int __stdcall sub_00412650(void*,const char*,int,unsigned); // 0x00412650

// build: symbol ?Destroy@SlotArray@@QAEXXZ 0x00603060
struct SlotArray { void Destroy(); SlotArray* sub_00603730(DeleteFlags flags); };

enum { DELETE_BIT = 1 };

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

typedef void (__fastcall* CelFileBuildFn)(D2StormEntry38Strc* pList, D2CelFileStrc* pCelFile);

extern CelFileBuildFn gapfnCelFileBuilders[]; // 0x006E3680

void __fastcall RawBuildCelFile(D2StormEntry38Strc* pList, D2CelFileStrc* pCelFile); // 0x0060D190

extern D2GameDataTableStrc gCelListTable; // 0x008E8CC0

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

extern "C" const char szWardenClientFile_006D8E18[];

class WardenModule
{
public:
    WardenModule();
    ~WardenModule();

    void* pImage;
    int unk0x04;
    int nImports;
    int unk0x0C;
    void* f_10;
};

struct D2Warden47F930Strc
{
    int n00;
    int n04;
    int n08;

    D2Warden47F930Strc();
};

struct D2WardenModuleHolderAStrc
{
    WardenModule tModule;

    ~D2WardenModuleHolderAStrc();
};

struct D2WardenModuleHolderBStrc
{
    WardenModule tModule;

    ~D2WardenModuleHolderBStrc();
};

int gbCmpPoolInitialized; // 0x0088CB14

int gnCmpPoolArg; // 0x0088CB18

extern const char gszCelCmp[]; // 0x006E5DD0

void* __stdcall SMemReAlloc(void* pLocation, unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x004133D0

struct D2CelStrc;

extern "C" int __cdecl sub_00517ABB_BitScanForward1(unsigned int nValue);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

struct D2StormListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* sub_006023E0_RawNext(D2StormLinkStrc* pLink);
};

struct D2StormListCStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListCStrc(const D2StormListCStrc& source);
};

struct D2StormListDStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListDStrc(const D2StormListDStrc& source);
};

struct D2StormNodeList006027A0Strc : D2StormNodeListStrc { ~D2StormNodeList006027A0Strc(); };

struct D2StormSlotList00602890Strc : D2StormSlotListStrc { ~D2StormSlotList00602890Strc(); };

struct D2StormListE006028D0Strc : D2StormListEStrc { ~D2StormListE006028D0Strc(); };

struct D2StormSlotList00602AA0Strc : D2StormSlotListStrc { ~D2StormSlotList00602AA0Strc(); };

struct D2StormListE00602AE0Strc : D2StormListEStrc { ~D2StormListE00602AE0Strc(); };

struct D2StormSlotList00602DF0Strc : D2StormSlotListStrc { ~D2StormSlotList00602DF0Strc(); };

struct D2StormEntry00602B20Strc : D2StormHashObjectStrc
{
    unsigned int dwFlags;
    int nType;
    int nData;
    unsigned int nCount;
    unsigned int nDirections;
    D2StormNodeList006027A0Strc tList;

    ~D2StormEntry00602B20Strc();
};

struct D2StormEntry00602EC0Strc : D2StormHashObjectStrc
{
    unsigned int dwFlags;
    int nType;
    int nData;
    unsigned int nCount;
    unsigned int nDirections;
    D2StormNodeList006027A0Strc tList;

    ~D2StormEntry00602EC0Strc();
};

extern "C" void _ReadWriteBarrier(void);

#pragma intrinsic(_ReadWriteBarrier)


struct D2StormHashTable006030E0Strc
{
    void* m_vtable;
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    char* CelListTableInternalFind(unsigned int nHashVal, int nKey);
};

struct D2StormEntry38Strc;

struct D2StormEntryGrowArrayStrc
{
    D2StormEntryArrayStrc tArray;

    ~D2StormEntryGrowArrayStrc();
};

struct D2Storm603530ArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;
    unsigned int m_chunk;
};

struct D2Storm603530Strc
{
    unsigned int unk0x00;
    D2Storm603530ArrayStrc tArray;

    D2Storm603530Strc();
};

struct D2Storm603570ArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;
    unsigned int m_chunk;

    D2Storm603570ArrayStrc()
    {
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
        m_chunk = 0;
    }
};

struct D2Storm603570LinkStrc
{
    D2Storm603570LinkStrc* m_prevlink;
    char* m_next;

    D2Storm603570LinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2Storm603570ListStrc
{
    int m_linkoffset;
    D2Storm603570LinkStrc m_terminator;

    D2Storm603570ListStrc()
    {
        m_linkoffset = 0;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};

struct D2Storm603570Strc
{
    unsigned int unk0x00;
    D2Storm603570ArrayStrc tArray;
    char unk0x14[0x18];
    D2Storm603570ListStrc tList;

    D2Storm603570Strc();
};

struct D2Storm603ED0Strc
{
    unsigned int nFirst;
    unsigned int nSecond;

    unsigned int sub_00603ED0_GetDifference();
};

struct D2Storm603F40Strc
{
    int n00;
    int n04;
    int n08;

    D2Storm603F40Strc();
};

struct D2Storm604460Strc
{
    D2StormEntryArrayStrc tArray;

    D2StormEntry38Strc* sub_00604460_New();
};

struct D2Storm604470Strc
{
    unsigned int nField00;
    unsigned int nField04;
    unsigned int f_8;
    unsigned int nField0C;
    unsigned int nField10;
    unsigned int nField14;

    D2Storm604470Strc();
};

struct D2Storm603F70Strc
{
    unsigned int unk0x00;
    D2Storm603530ArrayStrc tArray;

    D2Storm603F70Strc(int nUnused);
};

int gdwGlobal_0096C7F4; // 0x0096C7F4

int gpAnimData; // 0x0096C8A4

int gdwGlobal_0096D46C; // 0x0096D46C

char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset);

int __cdecl sub_0068A420(); // 0x0068A420

int __cdecl sub_0069FA20(); // 0x0069FA20

sub_0040F7D0::~sub_0040F7D0()
{
    f_0.Unlink();
}

sub_00417780::sub_00417780()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00417810::~sub_00417810()
{
    f_0.Unlink();
}

sub_00417850::sub_00417850()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00417860::~sub_00417860()
{
    f_0.Unlink();
}

sub_004178B0::sub_004178B0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_004178C0::~sub_004178C0()
{
    f_0.Unlink();
}

sub_00417900::~sub_00417900()
{
    f_0.Unlink();
}

sub_00417940::sub_00417940()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00417950::~sub_00417950()
{
    f_0.Unlink();
}

sub_00417990::sub_00417990()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_004179B0::~sub_004179B0()
{
    f_0.Unlink();
}

sub_004183F0::~sub_004183F0()
{
    f_0.Unlink();
}

sub_00418430::~sub_00418430()
{
    f_0.Unlink();
}

sub_00418760::sub_00418760()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418770::sub_00418770()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418780::~sub_00418780()
{
    f_0.Unlink();
}

sub_004187C0::~sub_004187C0()
{
    f_0.Unlink();
}

sub_00418800::~sub_00418800()
{
    f_0.Unlink();
}

sub_00418840::~sub_00418840()
{
    f_0.Unlink();
}

sub_00418880::~sub_00418880()
{
    f_0.Unlink();
}

sub_004188C0::~sub_004188C0()
{
    f_0.Unlink();
}

sub_00418A40::sub_00418A40()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418BA0::~sub_00418BA0()
{
    f_0.Unlink();
}

sub_00418BE0::~sub_00418BE0()
{
    f_0.Unlink();
}

sub_00418C20::~sub_00418C20()
{
    f_0.Unlink();
}

sub_00418DE0::sub_00418DE0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418DF0::sub_00418DF0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418E00::sub_00418E00()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418E10::~sub_00418E10()
{
    f_0.Unlink();
}

sub_00418E50::sub_00418E50()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418FF0::sub_00418FF0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00419060::sub_00419060()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_0041C3D0::~sub_0041C3D0()
{
    f_0.Unlink();
}

sub_0041C4F0::sub_0041C4F0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_0041C500::~sub_0041C500()
{
    f_0.Unlink();
}

sub_0041C720::sub_0041C720()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_0041C730::~sub_0041C730()
{
    f_0.Unlink();
}

sub_0041C7F0::sub_0041C7F0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_0041C800::~sub_0041C800()
{
    f_0.Unlink();
}

sub_00420430::~sub_00420430()
{
    f_0.Unlink();
}

sub_004204A0::sub_004204A0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_004204B0::~sub_004204B0()
{
    f_0.Unlink();
}

sub_00420700::sub_00420700()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00420710::~sub_00420710()
{
    f_0.Unlink();
}

sub_004207D0::sub_004207D0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_004207E0::~sub_004207E0()
{
    f_0.Unlink();
}

sub_00426960::~sub_00426960()
{
    f_0.Unlink();
}

sub_00426A80::~sub_00426A80()
{
    f_0.Unlink();
}

sub_00426CA0::sub_00426CA0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00426CB0::~sub_00426CB0()
{
    f_0.Unlink();
}

sub_00426D70::sub_00426D70()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00426D80::~sub_00426D80()
{
    f_0.Unlink();
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::IGNORELIST_GetStringTableHead()
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

void D2CommonStringEntryNodeStrc::IGNORELIST_DestroyStringEntryNode()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::IGNORELIST_ClearStringTable()
{
    IGNORELIST_InternalClearStringTable(0);
}

int __stdcall sub_00436E90_AlwaysOne(int nArg)
{
    return 1;
}

sub_0044BDE0::sub_0044BDE0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_0044DDD0::~sub_0044DDD0()
{
    f_0.Unlink();
}

sub_0044DE90::~sub_0044DE90()
{
    f_0.Unlink();
}

sub_0044ECC0::~sub_0044ECC0()
{
    f_0.Unlink();
}

sub_0044ED40::sub_0044ED40()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_0044ED50::~sub_0044ED50()
{
    f_0.Unlink();
}

sub_0044ED90::sub_0044ED90()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// build: symbol ?SKILLS_ScaleUpDirection@* 0x004C5390
void __fastcall SKILLS_ScaleUpDirection(int* pX, int* pY)
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

int __stdcall sub_004C6020_AlwaysOne(int nArg)
{
    return 1;
}

bool R0052E0F0::sub_0052E0F0_IsOpen()
{
    return m_pFile != 0;
}

int __stdcall OBJECTS_SpawnNothing(int nArg)
{
    return 1;
}

typedef void(__fastcall* PixelDataFreeCallback)(void* pData);

static PixelDataFreeCallback gpfnPixelDataFree; // 0x008E8CB8

typedef int (__stdcall* D2FarProcFn)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn); // 0x006CC34C

struct D2CmpPoolEntryStrc
{
    int unk0x00;
    int unk0x04;
    D2CmpTileStrc* pTile;
};

typedef void (__fastcall* D2TileFreeCallbackFn)(D2CmpTileStrc* pTile);

struct D2TileLibraryStrc
{
    char unk0x000[0x10C];
    int nTiles;
    D2TileLibraryEntryStrc* pTiles;
};

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

D2TileFreeCallbackFn gpfnTileFreeCallback; // 0x0088CB1C

int __fastcall ARCHIVE_SetFilePointer(void* unused, void* file, long nOffset, long* pnOffsetHigh, int nMethod); // 0x00516F14

void __fastcall LRUCacheTouch(D2CmpPoolStrc* pPool, D2LRUNodeStrc* pNode); // 0x00609380

D2LRUNodeStrc* __fastcall LRUCacheAlloc(D2CmpPoolStrc* pPool, unsigned int nSize, D2TileLibraryEntryStrc* pOwner); // 0x00609420

void __stdcall TileNormalizeSubTiles(D2TileLibraryEntryStrc* pEntry); // 0x0060A4C0

struct Config;

struct D2CmpSpriteContextStrc;

struct D2CmpDC6HeaderStrc;

struct D2CmpDC6CacheEntryStrc;

struct D2CmpDC6FrameStrc;

typedef char* va_list;

extern "C" int __cdecl vsprintf(char*,const char*,va_list);

extern "C" char* __cdecl strcat(char*,const char*);

struct Config { int enabled; const char* compressed; const char* standard; };

extern Config extensions; // 0x00741EFC

enum { DISABLED = 0 };

void* __fastcall sub_0040A9E0(AsyncData* pAsync); // 0x0040A9E0


static void* __stdcall SPRITECACHE_FindDC6Frame(void* pData, D2CmpSpriteContextStrc* pContext, D2CmpDC6HeaderStrc* pHeader); // 0x005FEB80

static void* SPRITECACHE_GetCachedDC6Frame(D2CmpSpriteContextStrc* pContext, D2CmpDC6CacheEntryStrc* pEntry); // 0x005FEC50

void __stdcall sub_P04_Emit_005FEC50(D2CmpSpriteContextStrc* pContext, D2CmpDC6CacheEntryStrc* pEntry)
{
    pContext->pFrame = SPRITECACHE_GetCachedDC6Frame(pContext, pEntry);
}

// build: symbol ?SPRITECACHE_GetCachedDC6Frame@* 0x005FEC50
static void* SPRITECACHE_GetCachedDC6Frame(D2CmpSpriteContextStrc* pContext, D2CmpDC6CacheEntryStrc* pEntry)
{
    if (pEntry && pEntry->tHeader.pAsync)
    {
        D2CmpDC6HeaderStrc* pHeader = &pEntry->tHeader;
        void* pData = sub_0040A9E0(pHeader->pAsync);
        if (pData)
        {
            pContext->nFrames = pHeader->nFrames;
            return SPRITECACHE_FindDC6Frame(pData, pContext, pHeader);
        }

        return 0;
    }

    return 0;
}

// build: symbol ?SPRITECACHE_FindDC6Frame@* 0x005FEB80
static void* __stdcall SPRITECACHE_FindDC6Frame(void* pData, D2CmpSpriteContextStrc* pContext, D2CmpDC6HeaderStrc* pHeader)
{
    if (!pData)
    {
        return 0;
    }

    if (!pHeader)
    {
        return 0;
    }

    if ((unsigned int)pContext->nFrame >= pHeader->nFrames)
    {
        return 0;
    }

    int nIndex;
    D2CmpDC6FrameStrc* pFrame = (D2CmpDC6FrameStrc*)pData;
    if (pContext->nType == 6 && (pContext->dwFlags & 2))
    {
        nIndex = CelGameDirToFileDir(pContext->nDirection, pHeader->nDirections - 1);
    }
    else if (pContext->nType == 2)
    {
        nIndex = 0;
    }
    else if (pContext->nType == 4)
    {
        nIndex = pContext->nDirection;
    }
    else
    {
        nIndex = CelGameDirToFileDir(pContext->nDirection, pHeader->nDirections - 1);
    }

    if (nIndex >= pHeader->nDirections - 1)
    {
        return 0;
    }

    int nOffset = pHeader->aOffsets[nIndex];
    if (nOffset < 0)
    {
        return 0;
    }

    const int nFrame = pContext->nFrame;
    for (int i = 0; i <= nFrame; ++i)
    {
        pFrame = (D2CmpDC6FrameStrc*)((char*)pData + nOffset);
        if (pFrame->nFlip != 0)
        {
            return 0;
        }

        if (pFrame->nWidth > 0x100)
        {
            return 0;
        }

        if (pFrame->nHeight > 0x100)
        {
            return 0;
        }

        nOffset += pFrame->nLength + pFrame->nOffsetY_14 + 0x23;
        if (nOffset < 0)
        {
            return 0;
        }
    }

    return pFrame;
}

// 0x005FE210
void __stdcall D2CMPBuildFileName(char* output,int allowCompressed,const char* format,va_list args)
{
    vsprintf(output,format,args);
    const char* suffix=(allowCompressed!=DISABLED && extensions.enabled!=DISABLED)?extensions.compressed:extensions.standard;
    strcat(output,suffix);
}

// 0x006011F0
int __stdcall CelFileSerialize(D2CelFileStrc* pCelFile, D2CelFileStrc** ppNewCelFile, unsigned int* pnSize)
{
    const unsigned int nCels = pCelFile->nCelsPerDirection * pCelFile->nDirections;
    unsigned int nSize = nCels * sizeof(D2CelStrc*) + 0x18;
    for (unsigned int i = 0; i < nCels; i++)
    {
        nSize += pCelFile->pCels[i]->nLength + pCelFile->pCels[i]->nDataSize + 0x23;
    }
    D2CelFileStrc* pNewCelFile = (D2CelFileStrc*)FOG_Alloc(nSize, ".\\SRC\\CelCmp.cpp", 0x345, 0);
    *pNewCelFile = *pCelFile;
    pNewCelFile->dwFlags = pNewCelFile->dwFlags & ~2 | 1;
    char* pData = (char*)&pNewCelFile->pCels[nCels];
    D2CelBlockStrc* pBlockToFree = 0;
    for (unsigned int i = 0; i < nCels; i++)
    {
        D2CelStrc* pNewCel = (D2CelStrc*)pData;
        const unsigned int nCelSize = pCelFile->pCels[i]->nLength + 0x23;
        pNewCelFile->pCels[i] = (D2CelStrc*)(pData - (char*)pNewCelFile);
        memcpy(pData, pCelFile->pCels[i], nCelSize);
        pData += nCelSize;
        if (pCelFile->pCels[i]->pBlockPixelData && pCelFile->pCels[i]->pBlockPixelData->pPixels)
        {
            memcpy(pData, pCelFile->pCels[i]->pBlockPixelData->pPixels, pCelFile->pCels[i]->nDataSize);
            if (!i)
            {
                pBlockToFree = pCelFile->pCels[0]->pBlockPixelData;
            }
        }
        pNewCel->pBlockPixelData = (D2CelBlockStrc*)(pData - (char*)pNewCelFile);
        pData += pCelFile->pCels[i]->nDataSize;
    }
    if (pBlockToFree)
    {
        FOG_Free(pBlockToFree, ".\\SRC\\CelCmp.cpp", 0x375, 0);
    }
    *ppNewCelFile = pNewCelFile;
    *pnSize = nSize;
    return 1;
}

// 0x00601340
void __stdcall CelFileNormalize(D2CelFileStrc* pFile, D2CelFileStrc** ppOutFile, const char* szFile, int nLine, int nSpecVersion, int nUnused)
{
    if (!pFile)
    {
        return;
    }

    const unsigned int dwFlags = pFile->dwFlags;
    D2_ASSERT(dwFlags & 1, 0x396);
    if (nSpecVersion == -1)
    {
        D2_ASSERT(pFile->dwVersion == 6, 0x399);
    }
    else
    {
        D2_ASSERT(pFile->dwVersion == nSpecVersion, 0x39B);
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

// 0x00601410
void __stdcall CelFileFreeSerialized(D2CelFileStrc* pCelFile)
{
    D2_ASSERT(pCelFile, 0x40D);
    FOG_Free(pCelFile, ".\\SRC\\CelCmp.cpp", 0x40E, 0);
}

// 0x006014C0
void __stdcall CelDraw(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11)
{
    D2CelFileStrc* pCelFile = pContext->pCelFile;
    if (pCelFile)
    {
        D2_ASSERT(pCelFile->dwVersion == 6, 0x452);
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

// 0x006015D0
int __stdcall CelGetRawData(CellTable* p, int nDirection, int nIndex, void* pDst)
{
    if (p->type != 6)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x4a0);
        exit(-1);
    }
    if ((p->flags & 4) == 0)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x4a1);
        exit(-1);
    }
    int idx = CelGameDirToFileDir(nDirection, p->nDirections) * p->stride + nIndex;
    Cell* cell = p->cells[idx];
    int size = cell->height * cell->width;
    memcpy(pDst, cell->data, (unsigned int)size * 3);
    return 1;
}

// 0x00600C60
int __fastcall DATATBLS_CallFree(void* pMemory)
{
    return sub_00517ABB_FindLowestSetBit((unsigned int)pMemory);
}

// 0x00601E20
unsigned int D2StormSlotArrayStrc::CelSlotArrayCalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x15)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    m_chunk = 0x15;
    return 0x15;
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

extern "C" const char gszTypeNameCelEntry[];                                                                // 0x00741F14

extern "C" const char gszTypeNameCelList[];                                                                 // 0x00741F2C

extern "C" const char gszTypeNameCelHashChunk[];                                                            // 0x00741FB4

inline D2StormHashObjectStrc::~D2StormHashObjectStrc()
{
}

// build: symbol ??1?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAE@XZ 0x00604640
// build: symbol ??1?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAE@XZ 0x00603460
// build: symbol ?UnlinkAll@D2StormSlotListStrc@@QAEXXZ 0x00602640
// build: symbol ?UnlinkAll@D2StormNodeListStrc@@QAEXXZ 0x006025E0
// build: symbol ??1D2StormHashObjectStrc@@QAE@XZ 0x00602430
// build: symbol ??_G?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@UAEPAXI@Z 0x00604900
// build: symbol ??_G?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@UAEPAXI@Z 0x00604870
// build: symbol ??_7?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@6B@ 0x006E5DFC
// build: symbol ??1?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@UAE@XZ 0x00604800
// build: symbol ??1?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@UAE@XZ 0x006048A0
// build: symbol ??_G?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAEPAXI@Z 0x00604700
// build: symbol ??_G?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAEPAXI@Z 0x006037B0
// build: symbol ??_GD2StormEntry38Strc@@QAEPAXI@Z 0x00602CB0
// build: symbol ??_GD2StormHashChunkStrc@@QAEPAXI@Z 0x006037E0
// 0x006022A0
void D2StormListEStrc::sub_006022A0_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x00602590
void D2StormListEStrc::sub_00602590_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x006029B0
D2CelEntryStrc* D2StormNodeListStrc::CelEntryListNewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2CelEntryStrc) + nExtraBytes, gszTypeNameCelEntry, -2, nFlags | 8);
    D2CelEntryStrc* pEntry = pMemory ? new (pMemory) D2CelEntryStrc : 0;
    if (nLinkType)
        CelEntryListLinkNode(pEntry, nLinkType, 0);
    return pEntry;
}

// build: symbol ??_GD2StormSlotLinkStrc@@QAEPAXI@Z 0x00602A40
// build: symbol ??_GD2StormSlotListStrc@@QAEPAXI@Z 0x00602B70
// 0x00602C40
D2CelEntryStrc* D2StormNodeListStrc::CelEntryListDeleteNode(D2CelEntryStrc* pNode)
{
    D2CelEntryStrc* pNext = (D2CelEntryStrc*)Link(pNode)->Next();
    pNode->f_0.Unlink();
    SMemFree(pNode, gszTypeNameCelEntry, -2, 0);
    return pNext;
}

// 0x00602CB0
inline void D2StormEntry38Strc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00602D20
void D2StormSlotListStrc::CelReuseListDeleteAll()
{
    char* pNode;
    while ((pNode = m_terminator.Next()) != 0)
    {
        ((D2StormEntry38Strc*)pNode)->~D2StormEntry38Strc();
        SMemFree(pNode, gszTypeNameCelList, -2, 0);
    }
}

// 0x00602E30
char* D2StormSlotListStrc::CelReuseListDeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormEntry38Strc*)pNode)->~D2StormEntry38Strc();
    SMemFree(pNode, gszTypeNameCelList, -2, 0);
    return pNext;
}

// 0x00602F10
void D2StormSlotArrayStrc::CelSlotArrayReallocData(unsigned int nAlloc)
{
    D2StormSlotListStrc* pOld = m_data;
    for (unsigned int i = nAlloc; i < m_count; i++)
        pOld[i].~D2StormSlotListStrc();
    m_alloc = nAlloc;
    void* pNew = SMemReAlloc(pOld, nAlloc * sizeof(D2StormSlotListStrc), gszTypeNameCelSlotList, -2, 0x10);
    m_data = (D2StormSlotListStrc*)pNew;
    if (!pNew)
    {
        m_data = (D2StormSlotListStrc*)SMemAlloc(nAlloc * sizeof(D2StormSlotListStrc), gszTypeNameCelSlotList, -2, 0);
        if (pOld)
        {
            unsigned int nCopy = nAlloc >= m_count ? m_count : nAlloc;
            for (unsigned int i = 0; i < nCopy; i++)
            {
                new (&m_data[i]) D2StormSlotListStrc(pOld[i]);
                pOld[i].~D2StormSlotListStrc();
            }
            SMemFree(pOld, gszTypeNameCelSlotList, -2, 0);
        }
    }
}

// 0x00603060
D2StormSlotArrayStrc::~D2StormSlotArrayStrc() throw()
{
    for (unsigned int i = 0; i < m_count; ++i)
        m_data[i].~D2StormSlotListStrc();
    if (m_data)
        SMemFree(m_data, gszTypeNameCelSlotList, -2, 0);
}

// 0x005FDE50
void __fastcall D2CMPTileCacheReleaseTile(void* pEntry)
{
    D2CmpTileStrc* pTile = ((D2CmpPoolEntryStrc*)pEntry)->pTile;
    if (gpfnTileFreeCallback)
    {
        D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnTileFreeCallback), 0xB4);
        gpfnTileFreeCallback(pTile);
    }

    pTile->nCount = 0;
    pTile->pNext = 0;
}

// 0x00601980
char* __stdcall CelGetControlData(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 0x5B4);
    return pCel->data;
}

// 0x006019B0
int __stdcall CelFileGetNumDirections(D2UnitStrc* unit)
{
    if(unit->dwUnitType!=REQUIRED_TYPE) {
        FOG_DisplayHalt(&emptyAssert,sub_00408090(),0x5C2);
        exit(-1);
    }
    return unit->dwAnimMode;
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

// 0x00601B70
char* __fastcall DRLGPRESET_GetLinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

// 0x00601B80
void D2GameDataTableStrc::CelListTableSyncEnterLock(int* pLockHandle, int bForWriting)
{
    EnterCriticalSection(&m_sync.m_critsect);
    *pLockHandle = bForWriting ? 1 : -1;
}

// 0x00601BB0
void __fastcall sub_00601BB0(PairStrc_00601BB0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x00601BC0
D2StormLinkStrc* D2StormLinkStrc::sub_00601BC0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00601BF0
sub_00601BF0::~sub_00601BF0()
{
    f_0.Unlink();
}

int __stdcall CelValidateContext(D2CmpCelContextStrc* pContext)
{
    D2CelFileStrc* pCelFile = (D2CelFileStrc*)pContext->pCelFile;
    if (!pCelFile)
    {
        return 0;
    }

    if (pCelFile->dwVersion != 6)
    {
        return 0;
    }

    if (pContext->nDirection >= 0x40)
    {
        return 0;
    }

    if (pContext->nFrame > pCelFile->nFrames)
    {
        return 0;
    }

    return 1;
}

// 0x00601A50
int __stdcall CelFileFreeHardware(D2CelFileStrc* ptFile)
{
    if (!ptFile)
    {
        return 0;
    }
    D2_ASSERT(ptFile->dwVersion == 6, 0x5F1);
    D2CelBlockStrc* pBlocks = ptFile->pCels[0]->pBlockPixelData;
    D2_ASSERT(pBlocks, 0x5F5);
    for (unsigned int i = 0; i < ptFile->nCelsPerDirection * ptFile->nDirections; i++)
    {
        if (ptFile->pCels[i] && ptFile->pCels[i]->pBlockPixelData)
        {
            if (gpfnPixelDataFree)
            {
                gpfnPixelDataFree(ptFile->pCels[i]->pBlockPixelData);
            }
            ptFile->pCels[i]->pBlockPixelData = 0;
        }
    }
    FOG_Free(pBlocks, ".\\SRC\\CelCmp.cpp", 0x61D, 0);
    return 1;
}

// 0x00601840
D2CelStrc* __stdcall CelGetHandle(D2CmpCelContextStrc* pCelContext)
{
    D2_ASSERT(pCelContext, 0x566);
    D2_ASSERT(CelValidateContext(pCelContext), 0x567);

    D2CelFileStrc* pCelFile = (D2CelFileStrc*)pCelContext->pCelFile;
    const unsigned int nDirection = pCelContext->nDirection;
    const unsigned int nDirections = pCelFile->nDirectionCount;
// build: symbol ?gaDirectionIndex64@* 0x006E45A0
    const int nIndex = gaDirectionIndex64[sub_00517ABB_BitScanForward1(nDirections)][nDirection];
    return pCelFile->pCels[nIndex * pCelFile->nFrames + pCelContext->nFrame];
}

// 0x00601C30
D2StormLinkStrc* D2StormLinkStrc::sub_00601C30_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00601C60
char* __fastcall sub_00601C60_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00601C70
sub_00601C70::~sub_00601C70()
{
    f_0.Unlink();
}

// 0x00601CB0
int D2GameDataTableStrc::CelListTableIsWriteLock(int nLockHandle)
{
    return nLockHandle == 1;
}

unsigned short __stdcall SFileGetLocale()
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

// 0x00601CC0
D2CommonStormSlotListAStrc* D2CommonStormSlotArrayAStrc::sub_00601CC0_At(unsigned int index) {return &m_data[index];}

static unsigned int __stdcall STORM_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// build: symbol ??0?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@QAE@XZ 0x00603BD0

// build: symbol ??_7?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@6B@ 0x006E5DE8
// 0x00601CE0
char* __fastcall sub_00601CE0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
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

// 0x00601CF0
extern "C" void* __fastcall sub_00601CF0(void* value) { return value; }

// 0x00601D00
unsigned int D2GameDataTableStrc::CelListTableSlotIndex(unsigned int nHashVal)
{
    return m_slotmask & nHashVal;
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

// 0x00601D30
D2StormLinkStrc* D2StormLinkStrc::sub_00601D30_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00601D60
sub_00601D60::~sub_00601D60()
{
    f_0.Unlink();
}

// 0x00601DA0
char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

// 0x00601DB0
void __fastcall sub_00601DB0(PairStrc_00601DB0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x00601DC0
bool R00601DC0::sub_00601DC0_IsOpen()
{
    return m_pFile != 0;
}

// 0x00601DF0
void __fastcall sub_00601DF0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00601E00
D2Warden47F930Strc::D2Warden47F930Strc()
{
    n00 = 0;
    n04 = 0;
    n08 = 0;
}

// 0x00601E10
void __fastcall sub_00601E10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00601E60
unsigned int __stdcall sub_00601E60_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x00601E80
void D2TSListStrc::sub_00601E80_InitCopy(const D2TSListStrc& source)
{
    nLinkOffset = source.nLinkOffset;
    tTerminator.pPrevLink = &tTerminator;
    tTerminator.nNext = ~(unsigned int)&tTerminator;
}

// 0x00601EA0
void __stdcall CelFileFree(D2CelFileStrc* pCelFile)
{
    D2_ASSERT(pCelFile, 0x41B);
    if (pCelFile->dwFlags & 3)
    {
        if (pCelFile->dwFlags & 2)
        {
            CelFileFreeHardware(pCelFile);
        }
        FOG_Free(pCelFile, ".\\SRC\\CelCmp.cpp", 0x422, 0);
    }
}

bool D2ChatStormLinkStrc::IGNORELIST_IsLinkLinked()
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

char* D2ChatStormNodeStrc::IGNORELIST_GetStringEntryKey()
{
    return m_key;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::IGNORELIST_GetStringSlotArrayCount()
{
    return m_count;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::IGNORELIST_GetMappingSlotArrayCount()
{
    return m_count;
}

void D2ChatStormListAStrc::IGNORELIST_InitStringListTerminator()
{
    InitializeTerminator();
}

void D2ChatStormListBStrc::IGNORELIST_InitMappingListTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::IGNORELIST_GetMappingListHead()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::IGNORELIST_ResetMappingList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x00601F00
char* D2ChatStormListAStrc::IGNORELIST_GetStringListHead()
{
    return m_terminator.MaskNext();
}

// 0x00601F10
sub_00601F10::sub_00601F10()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
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

namespace NWardenClient
{
struct Library
{
    Library();
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
};
}

// build: symbol ?WARDENCLIENT_SwapBytes@* 0x0047F8B0
void __fastcall WARDENCLIENT_SwapBytes(unsigned char* pA, unsigned char* pB)
{
    unsigned char nTemp = *pA;
    *pA = *pB;
    *pB = nTemp;
}

// 0x00601FA0
D2StormLinkStrc* D2StormNodeListStrc::CelEntryListLink(D2StormNodeStrc* pNode)
{
    return pNode ? &pNode->f_0 : &m_terminator;
}

// 0x00601FC0
void D2StormNodeListStrc::CelEntryListLinkNode(D2StormNodeStrc* pNode, int nLinkType, D2StormNodeStrc* pExistingNode)
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
char* D2StormNodeListStrc::CelEntryListNext(D2StormNodeStrc* pNode)
{
    return Link(pNode)->Next();
}

// 0x00602090
void LockedObject::sub_00602090(int acquired)
{
    if(acquired!=NOT_ACQUIRED) LeaveCriticalSection((D2CriticalSectionStrc*)&lock);
}

// 0x006020C0
char* D2ChatStormListAStrc::sub_006020C0_Head()
{
    return m_terminator.MaskNext();
}

// 0x006020D0
sub_006020D0::~sub_006020D0()
{
    f_0.Unlink();
}

// 0x00602110
D2StormLinkStrc* D2StormListEStrc::sub_00602110_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
}

// 0x00602130
sub_00602130::sub_00602130()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00602140
sub_00602140::~sub_00602140()
{
    f_0.Unlink();
}

// 0x00602180
sub_00602180::sub_00602180()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00602190
void D2StormNodeListStrc::CelEntryListUnlinkNode(D2StormNodeStrc* pNode)
{
    Link(pNode)->Unlink();
}

// 0x006021E0
void D2GameDataTableStrc::CelListTableUnlinkNode(D2StormEntry38Strc* pNode)
{
    if (pNode->m_linktoslot.m_next)
    {
        pNode->m_linktoslot.Unlink();
        pNode->m_linktofull.Unlink();
    }
}

// 0x00602260
char* D2StormSlotListStrc::CelSlotListRawNext(char* pNode)
{
    return Link(pNode)->m_next;
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

// 0x00602370
void D2ChatStormListAStrc::IGNORELIST_ResetStringList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x006023B0
D2StormListCStrc::D2StormListCStrc(const D2StormListCStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x006023E0
char* D2StormListBStrc::sub_006023E0_RawNext(D2StormLinkStrc* pLink)
{
    return pLink ? pLink->m_next : m_terminator.m_next;
}

// 0x00602400
void D2GameDataTableStrc::CelListTableSyncLeaveLock(int nLockHandle)
{
    if (nLockHandle)
        LeaveCriticalSection(&m_sync.m_critsect);
}

// 0x00602420
sub_00602420::sub_00602420()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x006024A0
sub_006024A0::~sub_006024A0()
{
    f_0.Unlink();
}

// 0x006024E0
void D2StormSlotListStrc::CelReuseListLinkNode(char* pNode, int nLinkType, char* pExistingNode)
{
    D2StormSlotLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2StormSlotLinkStrc* pExistingLink = Link(pExistingNode);
    D2StormSlotLinkStrc* pPrevLink;
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

// 0x00602620
void D2GameDataTableStrc::CelListTableDelete(D2StormEntry38Strc* pNode)
{
    CelListTableUnlinkNode(pNode);
    InternalDelete(pNode);
}

// 0x006026E0
void D2StormSlotListStrc::CelSlotListChangeLinkOffset(int nLinkOffset)
{
    if (nLinkOffset != m_linkoffset)
    {
        UnlinkAll();
        m_linkoffset = nLinkOffset;
        InitializeTerminator();
    }
}

// 0x00602710
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00602750
sub_00602750::sub_00602750()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00602760
sub_00602760::~sub_00602760()
{
    f_0.Unlink();
}

// 0x006027A0
D2StormNodeList006027A0Strc::~D2StormNodeList006027A0Strc()
{
}

// 0x006027E0
void D2GameDataTableStrc::sub_006027E0_Delete(D2StormEntry38Strc* pNode)
{
    CelListTableUnlinkNode(pNode);
    InternalDelete(pNode);
}

// 0x00602800
void D2GameHashTableStrc::CelListTableInternalClear(int bWarn)
{
    m_fullnessIndicator = 0;
    m_fulllist.UnlinkAll();
    for (unsigned int i = 0; i < m_slotlistarray.m_count; ++i)
    {
        for (;;)
        {
            char* pNode = m_slotlistarray.m_data[i].Head();
            if (!pNode)
                break;
            if (bWarn)
                m_slotlistarray.m_data[i].sub_006C4290(pNode);
            else
                InternalDelete((D2StormEntry38Strc*)pNode);
        }
    }
}

// 0x00602890
D2StormSlotList00602890Strc::~D2StormSlotList00602890Strc()
{
}

// 0x006028D0
D2StormListE006028D0Strc::~D2StormListE006028D0Strc()
{
    UnlinkAll();
}

// 0x00602910
D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00602930
D2StormList0044FB30Strc::D2StormList0044FB30Strc()
{
    m_linkoffset = 0x10;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00602950
void __fastcall sub_0044FB50_ConstructDeadList(D2StormDeadListStrc* pList)
{
    new (pList) D2StormDeadListStrc;
}

// 0x00602980
D2StormListDStrc::D2StormListDStrc(const D2StormListDStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00602A10
void D2GameDataTableStrc::CelListTableDeleteUnlock(D2StormEntry38Strc* pNode, int nLockHandle)
{
    CelListTableDelete(pNode);
    SyncLeaveLock(nLockHandle);
}

// 0x00602AA0
D2StormSlotList00602AA0Strc::~D2StormSlotList00602AA0Strc()
{
}

// 0x00602AE0
D2StormListE00602AE0Strc::~D2StormListE00602AE0Strc()
{
    UnlinkAll();
}

// 0x00602B20
D2StormEntry00602B20Strc::~D2StormEntry00602B20Strc()
{
}

// 0x00602BD0
void __fastcall sub_00602BD0(D2StormSlotListStrc* destination,const D2StormSlotListStrc* source)
{
    new(destination) D2StormSlotListStrc(*source);
}

// 0x00602DF0
D2StormSlotList00602DF0Strc::~D2StormSlotList00602DF0Strc()
{
}

// 0x00602EC0
D2StormEntry00602EC0Strc::~D2StormEntry00602EC0Strc()
{
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

// 0x006030E0
char* D2StormHashTable006030E0Strc::CelListTableInternalFind(unsigned int nHashVal, int nKey)
{
    for (char* pNode = m_slotlistarray.m_data[nHashVal & m_slotmask].Head(); _ReadWriteBarrier(), (int)pNode > 0; pNode = m_slotlistarray.m_data[nHashVal & m_slotmask].RawNext(pNode))
    {
        if (((D2StormEntry38Strc*)pNode)->m_hashval == nHashVal)
        {
            return pNode;
        }
    }
    return 0;
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

// 0x00603140
D2StormEntryArrayStrc::~D2StormEntryArrayStrc()
{
    for (unsigned int i = 0; i < m_count; ++i)
        m_data[i].~D2StormEntry38Strc();
    if (m_data)
        SMemFree(m_data, gszTypeNameCelList, -2, 0);
}

// 0x006031E0
D2StormArray408Strc* D2StormArray408Strc::sub_0051D690_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

// 0x00603240
D2StormSlotGrowArrayStrc::~D2StormSlotGrowArrayStrc() throw()
{
}

// 0x00603250
inline D2StormEntry38Strc* D2GameDataTableStrc::CelListTablePtr(unsigned int hHandle)
{
    return sub_006030E0_InternalFind(hHandle, f_44);
}

// 0x00603270
D2StormEntryGrowArrayStrc::~D2StormEntryGrowArrayStrc()
{
}

// 0x006032C0
D2StormHashChunkStrc::~D2StormHashChunkStrc()
{
}

// 0x00603400
inline D2StormEntry38Strc* D2GameDataTableStrc::CelListTableLock(unsigned int hHandle, int* pLockHandle, int bForWriting)
{
    SyncEnterLock(pLockHandle, bForWriting);
    D2StormEntry38Strc* pList = CelListTablePtr(hHandle);
    if (!pList)
    {
        SyncLeaveLock(*pLockHandle);
        *pLockHandle = 0;
    }
    return pList;
}

// 0x00603500
void __fastcall sub_00603500_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00603510
void D2ChatStormListAStrc::sub_00603510_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x00603530
D2Storm603530Strc::D2Storm603530Strc()
{
    tArray.m_alloc = 0;
    tArray.m_count = 0;
    tArray.m_data = 0;
    tArray.m_chunk = 0;
}

// 0x00603550
D2ChatStormListFStrc::D2ChatStormListFStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00603570
D2Storm603570Strc::D2Storm603570Strc()
{
}

// 0x006035A0
D2StormEntry38Strc* D2StormSlotListStrc::CelReuseListNewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormEntry38Strc) + nExtraBytes, gszTypeNameCelList, -2, nFlags | 8);
    D2StormEntry38Strc* pList = pMemory ? new (pMemory) D2StormEntry38Strc : 0;
    if (nLinkType)
        CelReuseListLinkNode((char*)pList, nLinkType, 0);
    return pList;
}

// build: symbol ??1D2StormHashObjectStrc@@QAE@XZ 0x00602430
// 0x00603730
SlotArray* SlotArray::sub_00603730(DeleteFlags flags)
{
    Destroy();
    if(flags.value & DELETE_BIT) {
        if(this) sub_00412650(this,"delete",-1,0);
    }
    return this;
}

// 0x00603760
void D2StormSlotArrayStrc::CelSlotArrayClear()
{
    this->D2StormSlotArrayStrc::~D2StormSlotArrayStrc();
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

// build: symbol ?Destroy@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAEXXZ 0x00603780
void D2GameHashTableStrc::Destroy()
{
    CelListTableInternalClear(1);
    m_fullnessIndicator = 0;
    m_slotmask = 0;
    m_slotlistarray.Clear();
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
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D2C0_InitBase()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    return this;
}

void __cdecl sub_0051D2D0_Nop()
{
}

void __cdecl sub_0051D2E0_Nop()
{
}

// build: symbol ?BNNEWS_CopyNewsItem@* 0x0051D350
void __fastcall BNNEWS_CopyNewsItem(D2Storm408ElemStrc* pDst, const D2Storm408ElemStrc* pSrc)
{
    if (pDst)
        *pDst = *pSrc;
}

void D2StormArray408Strc::sub_0051D570_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

// 0x00603300
void D2StormSlotArrayStrc::CelSlotArraySetCount(unsigned int nCount)
{
    if (nCount > m_count)
    {
        if (nCount > m_alloc)
        {
            unsigned int nChunk = m_chunk ? m_chunk : CelSlotArrayCalcChunkSize(nCount);
            CelSlotArrayReallocData(STORM_RoundUp(nCount, nChunk));
        }
        for (unsigned int i = m_count; i < nCount; i++)
            new (&m_data[i]) D2StormSlotListStrc;
    }
    else if (nCount < m_count)
    {
        for (unsigned int i = nCount; i < m_count; i++)
            m_data[i].~D2StormSlotListStrc();
    }
    m_count = nCount;
}

// build: symbol ?InternalNew@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAEPAUD2StormEntry38Strc@@PAUD2StormSlotListStrc@@II@Z 0x00603610
D2StormEntry38Strc* D2GameHashTableStrc::InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormEntry38Strc) + nExtraBytes, gszTypeNameCelList, -2, nFlags | 8);
    D2StormEntry38Strc* pNode = pMemory ? new (pMemory) D2StormEntry38Strc : 0;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

// build: symbol ?InternalDelete@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAEXPAUD2StormEntry38Strc@@@Z 0x006036D0
void D2GameHashTableStrc::InternalDelete(D2StormEntry38Strc* pNode)
{
    pNode->~D2StormEntry38Strc();
    SMemFree(pNode, gszTypeNameCelList, -2, 0);
}

// 0x006037B0
inline void D2GameHashTableStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x006037E0
inline void D2StormHashChunkStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

void __fastcall sub_005179B3_ConvertCelPixels(void* pDst, void* pSrc, int nRows, unsigned int nSrcSize, unsigned int nWidth, int nRows2); // 0x005179B3

static inline D2CelEntryStrc* __cdecl sub_F43_NewCelEntry(D2StormNodeListStrc* pList, int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2CelEntryStrc) + nExtraBytes, gszTypeNameCelEntry, -2, nFlags | 8);
    D2CelEntryStrc* pEntry = pMemory ? new (pMemory) D2CelEntryStrc : 0;
    if (nLinkType)
        pList->LinkNode(pEntry, nLinkType, 0);
    return pEntry;
}

// 0x00603860
void __stdcall CelCompressAddImage(unsigned int hCelList, void* pSrc, unsigned int nSrcSize, unsigned int dwPixelWidth, unsigned int dwPixelHeight, int nArg6, int nArg7, int nArg8)
{
    D2_ASSERT(dwPixelWidth && dwPixelHeight, 0x229);
    D2_ASSERT(nSrcSize >= dwPixelHeight, 0x22A);
    int hLock;
    D2StormEntry38Strc* pList = gCelListTable.CelListTableLock(hCelList, &hLock, 0);
    D2CelEntryStrc* pEntry = sub_F43_NewCelEntry(&pList->tList, 2, 0, 0);
    ++pList->nCount;
    pEntry->nSize = dwPixelWidth * dwPixelHeight;
    pEntry->nArg6 = nArg6;
    pEntry->nWidth = dwPixelWidth;
    pEntry->nHeight = dwPixelHeight;
    pEntry->nArg7 = nArg7;
    pEntry->nArg8 = nArg8;
    const int nRows = pList->dwFlags & 4 ? 3 * dwPixelHeight : dwPixelHeight;
    pEntry->pData = FOG_Alloc(nRows * dwPixelWidth, ".\\SRC\\CelCmp.cpp", 0x239, 0);
    sub_005179B3_ConvertCelPixels(pEntry->pData, pSrc, nRows, nSrcSize, dwPixelWidth, nRows);
    gCelListTable.SyncLeaveLock(hLock);
}

// 0x00603B60
void D2StormListEStrc::CelChunkListDeleteAll()
{
    char* pNode;
    while ((pNode = m_terminator.Next()) != 0)
    {
        ((D2StormHashChunkStrc*)pNode)->~D2StormHashChunkStrc();
        SMemFree(pNode, gszTypeNameCelHashChunk, -2, 0);
    }
}

// 0x00603BD0
D2GameHashTableStrc::TSHashTable()
{
    m_fullnessIndicator = 0;
    m_fulllist.ChangeLinkOffset(0xC);
    m_slotmask = 3;
    m_slotlistarray.CelSlotArraySetCount(4);
    for (unsigned int i = 0; i <= m_slotmask; i++)
        m_slotlistarray.m_data[i].ChangeLinkOffset(4);
}

// 0x00603C80
void D2GameHashTableStrc::CelListTableGrowListArray()
{
    unsigned int nOldCount = m_slotmask + 1;
    unsigned int nNewCount = 2 * nOldCount;
    D2StormSlotListStrc tTempList;
    tTempList.ChangeLinkOffset(4);

    for (unsigned int i = 0; i < nOldCount; i++)
    {
        char* pNode;
        while ((pNode = m_slotlistarray.m_data[i].Head()) != 0)
            tTempList.LinkToTail(pNode);
    }

    m_slotlistarray.CelSlotArraySetCount(nNewCount);
    for (unsigned int i = 0; i < nNewCount; i++)
        m_slotlistarray.m_data[i].ChangeLinkOffset(4);
    m_slotmask = nNewCount - 1;

    char* pNode;
    while ((pNode = tTempList.Head()) != 0)
        m_slotlistarray.m_data[((D2StormEntry38Strc*)pNode)->m_hashval & m_slotmask].LinkToTail(pNode);
}

// build: symbol ?InternalDelete@?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAEXPAUD2StormEntry38Strc@@@Z 0x00604150
void D2GameHashTableReuseStrc::InternalDelete(D2StormEntry38Strc* pNode)
{
    pNode->~D2StormEntry38Strc();
    SMemFree(pNode, gszTypeNameCelList, -2, 0);
}

// 0x00604460
D2StormEntry38Strc* D2Storm604460Strc::sub_00604460_New()
{
    return tArray.sub_006043B0_New();
}

// 0x00604470
D2Storm604470Strc::D2Storm604470Strc()
{
    nField00 = 0;
    nField04 = 0;
    f_8 = 0;
    nField0C = 0;
    nField10 = 0;
    nField14 = 0;
}

// 0x00604490
D2StormHashChunkStrc* D2StormListEStrc::CelChunkListNewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormHashChunkStrc) + nExtraBytes, gszTypeNameCelHashChunk, -2, nFlags | 8);
    D2StormHashChunkStrc* pChunk = pMemory ? new (pMemory) D2StormHashChunkStrc : 0;
    if (nLinkType)
        CelChunkListLinkNode((char*)pChunk, nLinkType, 0);
    return pChunk;
}

// 0x006045B0
int TSHashTable<CELLIST, HASHKEY_NONE>::sub_006045B0(unsigned int nSlot)
{
    D2StormSlotListStrc* const& pListArray = m_slotlistarray.m_data;
    if (m_slotmask >= 0x3FF)
    {
        return 0;
    }

    if (m_fullnessIndicator > 3)
    {
        m_fullnessIndicator -= 3;
    }
    else
    {
        m_fullnessIndicator = 0;
    }

    D2StormSlotLinkStrc* const pTerminator = &pListArray[nSlot].m_terminator;
    char* const pHead = (int)pTerminator->m_next <= 0 ? 0 : pTerminator->m_next;
    for (char* pEntry = pHead; (int)pEntry > 0; )
    {
        ++m_fullnessIndicator;
        if (m_fullnessIndicator > 13)
        {
            m_fullnessIndicator = 0;
            CelListTableGrowListArray();
            return 1;
        }

        pEntry = pListArray[nSlot].Link(pEntry)->m_next;
    }

    return 0;
}

// 0x006031F0
void D2StormSlotArrayStrc::CelSlotArrayReserve(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : CelSlotArrayCalcChunkSize(nCount);
            nCount = STORM_RoundUp(nCount, nChunk);
        }
        CelSlotArrayReallocData(nCount);
    }
}

// 0x00603850
void D2StormSlotArrayStrc::sub_00603850_SetCount(unsigned int nCount)
{
    CelSlotArraySetCount(nCount);
}

// 0x006039C0
void __stdcall CelCompressDestroy(unsigned int hCelList)
{
    int hLock;
    D2StormEntry38Strc* pList = gCelListTable.Lock(hCelList, &hLock, 0);
    for (D2CelEntryStrc* pEntry = (D2CelEntryStrc*)((((int)pList->tList.m_terminator.m_next <= 0) - 1) & (int)pList->tList.m_terminator.m_next); (int)pEntry > 0; pEntry = (D2CelEntryStrc*)pEntry->f_0.m_next)
    {
        FOG_Free(pEntry->pData, ".\\SRC\\CelCmp.cpp", 588, 0);
    }
    pList->tList.CelEntryListDeleteAll();
// build: symbol ?Delete@* 0x0052E590
    gCelListTable.Delete(pList);
    gCelListTable.SyncLeaveLock(hLock);
}

// 0x00603A70
unsigned int __stdcall CelCompressCreateCelFile(unsigned int hCelList, D2CelFileStrc** ppCelFile)
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
    pCelFile->dwVersion = 6;
    pCelFile->dwFlags = pList->dwFlags;
    pCelFile->nFormat = pList->nType;
    pCelFile->nDirections = pList->nDirections;
    pCelFile->nCelsPerDirection = pList->nCount / pList->nDirections;
    if (pList->dwFlags & 4)
    {
        RawBuildCelFile(pList, pCelFile);
        pCelFile->nTermination = pList->nData;
    }
    else
    {
        gapfnCelFileBuilders[pList->nType](pList, pCelFile);
    }

    gCelListTable.SyncLeaveLock(hLock);
    *ppCelFile = pCelFile;
    return 0;
}

// 0x00603E50
void D2GameHashTableReuseStrc::CelListTableDeleteReuseLists()
{
    m_chunkList.CelChunkListDeleteAll();
    m_reuseList.CelReuseListDeleteAll();
}

// 0x00603ED0
unsigned int D2Storm603ED0Strc::sub_00603ED0_GetDifference()
{
    return nFirst - nSecond;
}

// 0x00603EE0
unsigned int D2StormEntryArrayStrc::CelListArrayCalcChunkSize(unsigned int nCount)
{
    if (nCount < 8)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    m_chunk = 8;
    return 8;
}

void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D720_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D730_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &m_data[m_count++];
}

// 0x00603F20
unsigned int __stdcall sub_00603F20_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x00603F40
D2Storm603F40Strc::D2Storm603F40Strc()
{
    n00 = 0;
    n04 = 0;
    n08 = 0;
}

// 0x00603F50
void D2StormListEStrc::sub_00603F50_CopyLinkOffset(const D2StormListEStrc* pSource)
{
    m_linkoffset = pSource->m_linkoffset;
    InitializeTerminator();
}

// 0x00603F70
D2Storm603F70Strc::D2Storm603F70Strc(int nUnused)
{
    tArray.m_alloc = 0;
    tArray.m_count = 0;
    tArray.m_data = 0;
    tArray.m_chunk = 0;
}

// build: symbol ??0D2StormNodeListStrc@@QAE@ABU0@@Z 0x00603F90
D2StormNodeListStrc::D2StormNodeListStrc(const D2StormNodeListStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00603FC0
void D2StormListEStrc::CelChunkListLinkNode(char* pNode, int nLinkType, char* pExistingNode)
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

// 0x00604070
void D2GameHashTableStrc::sub_00604070_Clear()
{
    CelListTableInternalClear(0);
}

// 0x00604080
void __fastcall DATATBLS_ConstructEntry(D2StormEntry38Strc* pEntry)
{
    new (pEntry) D2StormEntry38Strc;
}

// build: symbol ??0D2StormEntry38Strc@@QAE@ABU0@@Z 0x006040B0
D2StormEntry38Strc::D2StormEntry38Strc(const D2StormEntry38Strc& source)
    : dwFlags(source.dwFlags), nType(source.nType), nData(source.nData),
      nCount(source.nCount), nDirections(source.nDirections), tList(source.tList)
{
}

// 0x00604100
void __fastcall DATATBLS_CopyConstructEntry(D2StormEntry38Strc* pEntry, const D2StormEntry38Strc* pSource)
{
    new (pEntry) D2StormEntry38Strc(*pSource);
}

// 0x006041B0
void D2StormEntryArrayStrc::sub_006041B0_ReallocData(unsigned int nAlloc)
{
    D2StormEntry38Strc* pOldData = m_data;
    for (unsigned int i = nAlloc; i < m_count; ++i)
    {
        pOldData[i].~D2StormEntry38Strc();
    }

    m_alloc = nAlloc;
    m_data = (D2StormEntry38Strc*)SMemReAlloc(pOldData, nAlloc * sizeof(D2StormEntry38Strc), gszTypeNameCelList, -2, 0x10);
    if (!m_data)
    {
        m_data = (D2StormEntry38Strc*)SMemAlloc(nAlloc * sizeof(D2StormEntry38Strc), gszTypeNameCelList, -2, 0);
        if (pOldData)
        {
            const unsigned int nCopy = nAlloc < m_count ? nAlloc : m_count;
            for (unsigned int i = 0; i < nCopy; ++i)
            {
                new (&m_data[i]) D2StormEntry38Strc(pOldData[i]);
                pOldData[i].~D2StormEntry38Strc();
            }
            SMemFree(pOldData, gszTypeNameCelList, -2, 0);
        }
    }
}

// 0x00604350
void D2StormEntryArrayStrc::CelListArrayReserve(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : CelListArrayCalcChunkSize(nCount);
            nCount = STORM_RoundUp(nCount, nChunk);
        }
        sub_006041B0_ReallocData(nCount);
    }
}

// 0x006043A0
D2StormEntryArrayStrc* D2StormEntryArrayStrc::sub_006043A0_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

// 0x006043B0
D2StormEntry38Strc* D2StormEntryArrayStrc::sub_006043B0_New()
{
    CelListArrayReserve(1, 1);
    new (&m_data[m_count]) D2StormEntry38Strc;
    return &m_data[m_count++];
}

// 0x00604440
void D2StormEntryArrayStrc::CelListArrayGrow(unsigned int nCount)
{
    unsigned int nNewCount = m_count + nCount;
    if (nNewCount > m_alloc)
        sub_006041B0_ReallocData(nNewCount);
}

// build: symbol ?InternalNew@?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAEPAUD2StormEntry38Strc@@PAUD2StormSlotListStrc@@II@Z 0x006044F0
D2StormEntry38Strc* D2GameHashTableReuseStrc::InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormEntry38Strc) + nExtraBytes, gszTypeNameCelList, -2, nFlags | 8);
    D2StormEntry38Strc* pNode = pMemory ? new (pMemory) D2StormEntry38Strc : 0;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

// 0x00604640
D2GameHashTableReuseStrc::~TSHashTableReuse()
{
    m_chunkList.CelChunkListDeleteAll();
    m_reuseList.CelReuseListDeleteAll();
}

// build: symbol ?Destroy@?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAEXXZ 0x006046E0
void D2GameHashTableReuseStrc::Destroy()
{
    CelListTableInternalClear(0);
    m_chunkList.CelChunkListDeleteAll();
    m_reuseList.CelReuseListDeleteAll();
}

// 0x00604700
inline void D2GameHashTableReuseStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00604760
char* D2GameDataTableStrc::CelListTableNew(unsigned int nHashVal, const int& tKey, int nExtraBytes, int nFlags)
{
    unsigned int nSlot = nHashVal & m_slotmask;
    if (sub_006045B0(nSlot))
        nSlot = nHashVal & m_slotmask;
    D2StormSlotListStrc* pSlotList = &m_slotlistarray.m_data[nSlot];
    D2StormEntry38Strc* pNode = InternalNew(pSlotList, nExtraBytes, nFlags);
    m_fulllist.LinkNode((char*)pNode, 2, 0);
    pNode->m_hashval = nHashVal;
    return (char*)pNode;
}

// 0x00604840
char* D2GameDataTableStrc::CelListTableNewHandle(unsigned int* pHandle)
{
    unsigned int nHandle = CelListTableGenerateHandle();
    *pHandle = nHandle;
    return CelListTableNew(nHandle, f_44, 0, 0);
}

// 0x00604870
inline void D2GameExportTableSimpleStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x006048C0
char* D2GameDataTableStrc::CelListTableNewLock(unsigned int* pHandle, int* pLockHandle)
{
    SyncEnterLock(pLockHandle, 1);
    return CelListTableNewHandle(pHandle);
}

// 0x00604900
inline void D2GameDataTableStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

#define D2CMP_BITCOUNT_BX(x) ((x) - (((x) >> 1) & 0x77777777) - (((x) >> 2) & 0x33333333) - (((x) >> 3) & 0x11111111))

#define D2CMP_BITCOUNT(x) (((D2CMP_BITCOUNT_BX(x) + (D2CMP_BITCOUNT_BX(x) >> 4)) & 0x0F0F0F0F) % 255)

// 0x00604940
unsigned int __stdcall CelCompressCreate(int nType, unsigned int nDirections, int* pData, int bHasData)
{
    D2_ASSERT(D2CMP_BITCOUNT(nDirections) == 1, 0x1FF);
    D2_ASSERT(nDirections <= 32, 0x200);
    D2_ASSERT(nType < 2, 0x201);
    unsigned int hHandle;
    int hLock;
    D2StormEntry38Strc* pList = (D2StormEntry38Strc*)gCelListTable.CelListTableNewLock(&hHandle, &hLock);
    pList->tList.CelEntryListDeleteAll();
    pList->nType = nType;
    pList->nDirections = nDirections;
    pList->nCount = 0;
    pList->dwFlags = 0;
    if (bHasData)
    {
        pList->dwFlags = 4;
        if (pData)
        {
            pList->nData = *pData;
        }
    }
    gCelListTable.SyncLeaveLock(hLock);
    return hHandle;
}

void sub_F43_EmitDeletes(D2StormSlotLinkStrc* pLink, D2StormSlotListStrc* pSlotList, D2StormEntry38Strc* pList, D2StormHashChunkStrc* pChunk)
{
    delete pLink;
    delete pSlotList;
    delete pList;
    delete pChunk;
}

void sub_F43_EmitTableVtables(void* pTable, void* pReuse, void* pSimple, void* pSync)
{
    new (pTable) D2GameHashTableStrc(1);
    new (pReuse) D2GameHashTableReuseStrc(1);
    new (pSimple) D2GameExportTableSimpleStrc(1);
    new (pSync) D2GameDataTableStrc(1);
}

typedef D2StormEntry38Strc* (D2GameDataTableStrc::*D2CELTABLEPTRFN)(unsigned int hHandle);

typedef D2StormEntry38Strc* (D2GameDataTableStrc::*D2CELTABLELOCKFN)(unsigned int hHandle, int* pLockHandle, int bForWriting);

void sub_F43_EmitTableMembers(D2CELTABLEPTRFN* ppfnPtr, D2CELTABLELOCKFN* ppfnLock)
{
    *ppfnPtr = &D2GameDataTableStrc::CelListTablePtr;
    *ppfnLock = &D2GameDataTableStrc::CelListTableLock;
}

// 0x0060D040
int __fastcall FindTileGetTiles(D2FindTileEntryStrc** ppTable, void** ppResults, unsigned int nMax, int nKey1, int nKey2, int nKey3)
{
    int bFound = 0;
    int nCount = 0;
    D2_ASSERT(ppTable, 0xCF);
    D2_ASSERT(ppResults, 0xD0);
    if (!nMax)
    {
        return 0;
    }

    D2FindTileEntryStrc* pEntry = ppTable[FindTileHash(nKey3, nKey2, nKey1)];
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

// 0x0060E0D0
int __cdecl sub_0060E0D0()
{
    return 4;
}

// 0x0060E0E0
D2StormListEStrc* D2StormListEArrayStrc::sub_0060E0E0_At(unsigned int nIndex)
{
    return &m_data[nIndex];
}

// 0x0060E100
int __cdecl sub_0060E100()
{
    return 4;
}

// 0x0060E110
D2StormListEStrc* D2StormListEArrayStrc::sub_0060E110_At(unsigned int nIndex)
{
    return &m_data[nIndex];
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

// 0x0060E1B0
void __fastcall sub_0060E1B0(PairStrc_0060E1B0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
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

// 0x0060E290
void __fastcall sub_0060E290(PairStrc_0060E290* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
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
    m_chunk = 0x15;
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
    m_chunk = 0x15;
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

// 0x00611610
void __stdcall sub_00611610(int nUnused1)
{
}

// 0x00611640
void __stdcall sub_00611640(int nUnused1)
{
}

// 0x00611D10
int __cdecl DATATBLS_GetCharstatsTxtTable()
{
    return gdwGlobal_0096C7F4;
}

// 0x00611D20
int __cdecl DATATBLS_GetAnimData()
{
    return gpAnimData;
}

// 0x00641500
int __cdecl DATATBLS_GetShrinesTxtRecordCount()
{
    return gdwGlobal_0096D46C;
}

// 0x00600C00
void __stdcall D2CMPPalShiftSetAct(int nMode)
{
    if (nMode >= 1 && nMode <= 5)
    {
        gnCmpGfxMode = nMode;
    }
}

// 0x00600C20
unsigned char* __stdcall D2CMPPalShiftGetTransform(int nSet, int nIndex)
{
    if (nSet < 9 && nIndex < 21 && nSet != 0 && (nSet <= 2 || nSet > 4))
    {
        return gaItemShiftMaps[nSet][nIndex];
    }

    return 0;
}

// 0x00600C70
int __stdcall CelNormalDirToFileDir(int nDirection, unsigned int nDirections)
{
    return gaDirectionIndex32[sub_00517ABB_FindLowestSetBit(nDirections)][nDirection];
}

// 0x00600EE0
void __stdcall CelFileHalve(D2CelFileStrc* hFile, int nUnused)
{
    D2_ASSERT(hFile, 0x29C);
}

// 0x00600F10
int __stdcall CelFileConvert24To8(D2CelFileStrc* pFile, D2CelFileStrc** ppTarget, int nArg1, int nArg2)
{
    D2_ASSERT(pFile->dwFlags & 4, 0x2AD);
    const int nCells = pFile->nDirections * pFile->nCelsPerDirection;
    D2CelFileStrc* pTarget = (D2CelFileStrc*)FOG_Alloc(0x18 + nCells * sizeof(D2CmpCellStrc*), ".\\SRC\\CelCmp.cpp", 0x2B1, 0);
    pTarget->dwVersion = 6;
    pTarget->dwFlags = pFile->dwFlags & ~7;
    pTarget->nDirections = pFile->nDirections;
    pTarget->nCelsPerDirection = pFile->nCelsPerDirection;
    pTarget->nFormat = 0;
    gpfCelFileConvert[pFile->nFormat](pFile, pTarget, nArg1, nArg2);
    *ppTarget = pTarget;
    return 1;
}

// 0x00600FB0
void __stdcall CelFileConvertOldToNew(unsigned* cell,unsigned** output,unsigned* outputSize)
{
 unsigned* cellCopy = cell;
 D2_ASSERT(cellCopy[1]&1,0x2cb);
 D2_ASSERT(cellCopy[0]==5,0x2cc);
 cellCopy[1]|=2;
 for(unsigned i=0;i<cellCopy[4]*(cellCopy[5]);++i) {
  unsigned* frame=(unsigned*)(cellCopy[13+i]+(unsigned)cellCopy);
  cellCopy[13+i]=(unsigned)frame;
  if(frame[7])frame[8]+=(unsigned)cellCopy;else frame[8]=0;
 }
 unsigned count=cellCopy[4]*cellCopy[5];
 unsigned header=24+4*count;
 unsigned size=header;
 for(unsigned i=0;i<count;++i) {
  unsigned* frame=(unsigned*)cellCopy[13+i];
  size+=frame[9]+frame[7]+35;
 }
 unsigned* result=(unsigned*)FOG_Alloc(size,gszCelCmp,0x2e3,0);
 result[0]=6;
 result[1]=((unsigned char)cellCopy[1]&4)|1;
 result[2]=0;result[3]=0;
 result[4]=cellCopy[4];result[5]=cellCopy[5];
 unsigned char* cursor=(unsigned char*)result+header;
 for(unsigned i=0;i<count;++i) {
  result[6+i]=(unsigned)(cursor-(unsigned char*)result);
  unsigned* out=(unsigned*)cursor;
  out[0]=((unsigned*)cellCopy[13+i])[1];
  out[1]=((unsigned*)cellCopy[13+i])[3];
  out[2]=((unsigned*)cellCopy[13+i])[4];
  out[3]=((unsigned*)cellCopy[13+i])[5];
  out[4]=((unsigned*)cellCopy[13+i])[6];
  out[5]=((unsigned*)cellCopy[13+i])[7];
  out[7]=((unsigned*)cellCopy[13+i])[9];
  memcpy(out+8,(unsigned*)cellCopy[13+i]+10,out[7]);
  cursor+=out[7]+35;
  if(((unsigned*)cellCopy[13+i])[8]) {
   memcpy(cursor,(unsigned*)cellCopy[13+i]+8,((unsigned*)cellCopy[13+i])[7]);
   out[6]=(unsigned)(cursor-(unsigned char*)result);
   cursor+=((unsigned*)cellCopy[13+i])[7];
  }else out[6]=0;
 }
 *output=result;*outputSize=size;
}

// 0x005FE1F0
const char* __stdcall D2CMPGetGfxFileExtension(int bAllowCompressed)
{
    if (bAllowCompressed && gbCmpCompressedDataMode)
    {
        return gszCmpCompressedExtension;
    }

    return gszCmpDefaultExtension;
}

// 0x005FF300
int __stdcall D2CMPSpriteFindAsynchSiblings(int nKeyA, int nKeyB, int nKeyC)
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

// 0x005FE280
void __stdcall D2CMPSetNoCompress(int bAllowCompressed)
{
    SRegLoadValue("Diablo II", "CompressedData", 1, (unsigned long*)&gbCmpCompressedDataMode);
    if (!bAllowCompressed)
    {
        gbCmpCompressedDataMode = 0;
    }
}

// 0x005FFE30
void __stdcall D2CMPSpriteCacheDestroy(int bFree)
{
    if (bFree && gCmpTileCache.bActive)
    {
        D2CMPSpriteCacheFreeAll(&gCmpTileCache);
    }

    memset(&gCmpTileCache, 0, sizeof(gCmpTileCache));

    if (bFree)
    {
        sub_006093E0_PoolFreeAll(&gCmpTilePool);
    }

    memset(&gCmpTilePool, 0, sizeof(gCmpTilePool));
    CodecReleaseLock();
}

// 0x00600960
D2TileLibraryHeaderStrc* __stdcall D2CMPFindTileProject(D2TileLibraryEntryStrc* pTile)
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

int __fastcall SKILLS_GetMinimum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

int __fastcall SKILLS_GetMaximum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

int __stdcall SKILLS_Return1(int nArg)
{
    return 1;
}

int __stdcall sub_00646260_AlwaysOne(int nArg)
{
    return 1;
}

int __stdcall sub_00646270_AlwaysOne(int nArg)
{
    return 1;
}

int __stdcall sub_00648390_AlwaysZero(int nUnused1, int nUnused2)
{
    return 0;
}

int __fastcall MISSILE_GetMinimum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

int __fastcall MISSILE_GetMaximum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

int __cdecl sub_0065CCB0()
{
    return 0;
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

int __fastcall sub_00675810(D2DrlgLevelStrc* pLevel)
{
    return DRLGOUTSIEGE_GetBorderLookupId(pLevel);
}

D2WardenModuleHolderAStrc::~D2WardenModuleHolderAStrc()
{
}

WardenModule::WardenModule()
{
    pImage = 0;
    unk0x04 = 0;
    nImports = 0;
    unk0x0C = 0;
    f_10 = 0;
}

D2WardenModuleHolderBStrc::~D2WardenModuleHolderBStrc()
{
}

// build: symbol ?WARDENCLIENT_AllocLoaderMemory@* 0x0047FBF0
void* __fastcall WARDENCLIENT_AllocLoaderMemory(unsigned int nSize)
{
    return SMemAlloc(nSize, szWardenClientFile_006D8E18, 0x10D, 0);
}

// build: symbol ?WARDENCLIENT_FreeLoaderMemory@* 0x0047FC10
void __fastcall WARDENCLIENT_FreeLoaderMemory(void* pMemory)
{
    SMemFree(pMemory, szWardenClientFile_006D8E18, 0x117, 0);
}

NWardenClient::Library::Library()
{
}

// 0x005FF630
void __fastcall D2CMPSpriteCacheResize(D2CmpCacheStrc* pCache, D2CmpCacheNodeStrc* pNode, int nDelta, int nArg)
{
    EnterCriticalSection(&pCache->tLock);
    const unsigned int nNewSize = nDelta + pNode->nSize;
    pCache->nTotalSize -= pNode->nSize;
    pNode->dwFlags |= 2;
    pNode->nSize = nNewSize;
    pCache->nTotalSize += nNewSize;
    unsigned int nTotalSize = pCache->nTotalSize;
    LeaveCriticalSection(&pCache->tLock);

    while (nTotalSize > pCache->nMaxSize)
    {
        D2CmpCacheNodeStrc* pEvicted = D2CMPSpriteCacheEvict(pCache, 0, nArg);
        if (!pEvicted)
        {
            break;
        }

        D2_ASSERT(pEvicted != pNode, 0xA47);
        EnterCriticalSection(&pCache->tLock);
        nTotalSize = pCache->nTotalSize;
        LeaveCriticalSection(&pCache->tLock);
    }

    EnterCriticalSection(&pCache->tLock);
    pNode->dwFlags &= ~2;
    LeaveCriticalSection(&pCache->tLock);
}

void __stdcall sub_F43_EmitPixelDataFreeWriter(PixelDataFreeCallback pfnCallback)
{
    gpfnPixelDataFree = pfnCallback;
}

// 0x005FE120
void __stdcall D2CMPTileCacheInit(void* pMemPool, int nArg)
{
    gnCmpPoolArg = nArg;
    memset(&gCmpPool, 0, sizeof(gCmpPool));
    sub_00609020_PoolInit(&gCmpPool, pMemPool, nArg, D2CMPTileCacheReleaseTile, 0x1000);
    gbCmpPoolInitialized = 1;
}

// 0x005FDE10
void __stdcall D2CMPTileCacheDestroy(int bFree)
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

    D2CMPDestroyTileHeaders();
}

// 0x005FDF50
void __stdcall D2CMPTileCacheFreeTile(D2CmpCacheBlockOwnerStrc* pOwner)
{
    sub_006092D0_PoolFree(&gCmpPool, pOwner->pBlock);
    pOwner->nBlockUsed = 0;
    pOwner->pBlock = 0;
}

// 0x005FDEA0
int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc* pEntry, int a2, int a3)
{
    if (pEntry->pNode)
    {
        LRUCacheTouch(&gCmpPool, pEntry->pNode);
        return 1;
    }

    if (!pEntry->nBlocks)
    {
        return 0;
    }

    pEntry->pNode = LRUCacheAlloc(&gCmpPool, pEntry->nSize, pEntry);
    pEntry->pBlocks = (D2GlideTileStrc*)pEntry->pNode->pData;
    memset(pEntry->pBlocks, 0, pEntry->nSize);

    void* hFile;
    if (!ARCHIVE_OpenFile(0, pEntry->szFilePath, &hFile, 0))
    {
        return 0;
    }

    ARCHIVE_SetFilePointer(0, hFile, pEntry->nFileOffset, 0, 0);
    ARCHIVE_ReadFileToBuffer(0, hFile, pEntry->pBlocks, pEntry->nSize);
    ARCHIVE_CloseFile(0, hFile);
    TileNormalizeSubTiles(pEntry);
    return 1;
}

// 0x005FDF80
int __fastcall D2CMPGetTileHeadersSize(const char* szFilePath)
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

// 0x005FE080
void __fastcall D2CMPTileCacheFreeProject(D2TileLibraryStrc* pLibrary)
{
    for (int i = 0; i < pLibrary->nTiles; ++i)
    {
        D2TileLibraryEntryStrc* pEntry = &pLibrary->pTiles[i];
        if (pEntry->pNode)
        {
            sub_006092D0_PoolFree(&gCmpPool, pEntry->pNode);
            pEntry->pBlocks = 0;
            pEntry->pNode = 0;
        }
    }
}

#include "gen/data/Source/D2CMP/SRC/CelCmp.inc"
