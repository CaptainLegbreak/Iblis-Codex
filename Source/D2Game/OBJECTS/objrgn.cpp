#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2GSPacketSrv26;
union D2SeedStrc;
struct D2ObjectControlStrc;
struct D2LevelsTxt;
struct Sub00546F90;
struct Obj00546F90;
struct Pad40_00546FA0;
struct Pad400_00546FA0;
struct Obj00546FA0;
struct Sub00546FB0;
struct Obj00546FB0;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* text, const char* file, int line); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);


struct D2ObjectRegionStrc
{
    unsigned char nAct;
    char unk0x01[7];
    int nMinDistance;
    char unk0x0C[0x10];
    int nWanderCount;
    char unk0x20[0x70];
};

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
    int nShrineCounts[8];
    int* pShrineIds[8];
    D2ObjectRegionStrc* pObjectRegion[1024];
    union
    {
        char unk0x1048[0xC8];
        unsigned short wGroupCount[0x61];
    };
    void* unk0x1110;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0xB0];
    D2SeedStrc pGameSeed;
    char unk0xD8[0x1018];
    D2ObjectControlStrc* pObjectControl;
    void sub_00546FF0_SendQuestText(const char* szText); // 0x00546FF0
};


struct D2LevelsTxt { char unk0x00[3]; unsigned char nAct; };

struct D2ShrinesTxt { char unk0x00[0xB2]; unsigned char nClass; };

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
int __cdecl sub_00641500(); // 0x00641500
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

struct Sub00546F90 { unsigned char bUnknown00[0x48]; void* pEntries48[1]; };

struct Obj00546F90 { unsigned char bUnknown00[0x10F0]; Sub00546F90* pSub10F0; };

struct Pad40_00546FA0 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Pad400_00546FA0 {
    Pad40_00546FA0 t000;
    Pad40_00546FA0 t040;
    Pad40_00546FA0 t080;
    Pad40_00546FA0 t0C0;
    Pad40_00546FA0 t100;
    Pad40_00546FA0 t140;
    Pad40_00546FA0 t180;
    Pad40_00546FA0 t1C0;
    Pad40_00546FA0 t200;
    Pad40_00546FA0 t240;
    Pad40_00546FA0 t280;
    Pad40_00546FA0 t2C0;
    Pad40_00546FA0 t300;
    Pad40_00546FA0 t340;
    Pad40_00546FA0 t380;
    Pad40_00546FA0 t3C0;
};

struct Obj00546FA0 {
    Pad400_00546FA0 tPad0000;
    Pad400_00546FA0 tPad0400;
    Pad400_00546FA0 tPad0800;
    Pad400_00546FA0 tPad0C00;
    Pad40_00546FA0 tPad1000;
    Pad40_00546FA0 tPad1040;
    Pad40_00546FA0 tPad1080;
    unsigned int dwUnknown10C0;
    unsigned int dwUnknown10C4;
    unsigned int dwUnknown10C8;
    unsigned int dwUnknown10CC;
    unsigned int dwUnknown10D0;
    unsigned int dwUnknown10D4;
    unsigned int dwUnknown10D8;
    unsigned int dwUnknown10DC;
    unsigned int dwUnknown10E0;
    unsigned int dwUnknown10E4;
    unsigned int dwUnknown10E8;
    unsigned int dwUnknown10EC;
    unsigned int dwValue10F0;
};

struct Sub00546FB0 { unsigned int dwUnknown00; unsigned int dwUnknown04; unsigned int dwMember08; };

struct Obj00546FB0 { unsigned char bUnknown00[0x10F0]; Sub00546FB0* pSub10F0; };

struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nMessageType;
    unsigned char nLang;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nMessageColor;
    unsigned char nNameColor;
    char szName[16];
    char szMessage[256];
};

void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, D2GSPacketSrv26* pPacket); // 0x0053C750
extern "C" char* __cdecl strcpy(char* pDestination, const char* pSource);

typedef void (__fastcall* GAME_ForEachIngameClientCallbackPtr)(D2ClientStrc*, void*);

extern void __fastcall GAME_ForEachIngameClient(D2GameStrc* pGame, GAME_ForEachIngameClientCallbackPtr pFn, void* pContext); // 0x0052DED0
extern void __fastcall sub_00546FE0_SendQuestTextToClient(D2ClientStrc* pClient, void* pContext); // 0x00546FE0

inline unsigned __int64 OBJECTS_RollGameSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 seed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(seed >> 32);
    pSeed->nLowSeed = (unsigned int)seed;
    return seed;
}

// 0x00546C60
unsigned int __fastcall sub_00546C60_AllocObjectControl(D2GameStrc* ptGame)
{
    if (!ptGame)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 41);
        exit(-1);
    }
    D2ObjectControlStrc* pControl = (D2ObjectControlStrc*)FOG_AllocPool(ptGame->pMemoryPool, sizeof(D2ObjectControlStrc), ".\\OBJECTS\\objrgn.cpp", 42, 0);
    ptGame->pObjectControl = pControl;
    SEED_InitSeed(&pControl->pSeed);
    const unsigned int nSeed = (unsigned int)OBJECTS_RollGameSeed(&ptGame->pGameSeed);
    SEED_InitLowSeed(&pControl->pSeed, nSeed);
    pControl->pObjectRegion[0] = 0;
    pControl->unk0x1110 = 0;
    for (int i = 1; i < sgptDataTables->nLevelsTxtRecordCount; i += 1)
    {
        D2ObjectRegionStrc* pRegion = (D2ObjectRegionStrc*)FOG_AllocPool(ptGame->pMemoryPool, sizeof(D2ObjectRegionStrc), ".\\OBJECTS\\objrgn.cpp", 54, 0);
        D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(i);
        memset(pRegion, 0, sizeof(D2ObjectRegionStrc));
        pRegion->nWanderCount = -1;
        pRegion->nAct = pLevelsTxt->nAct;
        pRegion->nMinDistance = 0x7FFFFFFF;
        pControl->pObjectRegion[i] = pRegion;
    }
    const int nShrines = sub_00641500();
    int nClassCounts[8] = {};
    for (int i = 0; i < nShrines; i += 1)
    {
        const unsigned char nClass = DATATBLS_GetShrinesTxtRecord(i)->nClass;
        if (nClass < 8)
            ++nClassCounts[nClass];
    }
    memset(pControl->unk0x1048, 0, sizeof(pControl->unk0x1048));
    memset(pControl->pShrineIds, 0, sizeof(pControl->pShrineIds));
    for (int i = 0; i < 8; i += 1)
    {
        if (nClassCounts[i] > 0)
        {
            pControl->pShrineIds[i] = (int*)FOG_AllocPool(ptGame->pMemoryPool, 4 * nClassCounts[i], ".\\OBJECTS\\objrgn.cpp", 84, 0);
            memset(pControl->pShrineIds[i], 0, 4 * nClassCounts[i]);
        }
        pControl->nShrineCounts[i] = 0;
    }
    for (int i = 0; i < nShrines; i += 1)
    {
        const unsigned char nClass = DATATBLS_GetShrinesTxtRecord(i)->nClass;
        if (nClass < 8)
        {
            pControl->pShrineIds[nClass][pControl->nShrineCounts[nClass]] = i;
            pControl->nShrineCounts[nClass] += 1;
        }
    }
    return nSeed;
}

// 0x00546F90
extern "C" __declspec(dllexport) void* __fastcall sub_00546F90(Obj00546F90* pObj, int nIndex) {
    return pObj->pSub10F0->pEntries48[nIndex];
}

// 0x00546FA0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00546FA0(Obj00546FA0* pObj) {
    return pObj->dwValue10F0;
}

// 0x00546FB0
extern "C" __declspec(dllexport) unsigned int* __fastcall sub_00546FB0(Obj00546FB0* pObj) {
    return &pObj->pSub10F0->dwMember08;
}

// 0x00546FC0
void __fastcall sub_00546FC0_IncrementGroupCount(D2GameStrc* pGame, int nGroup)
{
    if ((unsigned int)nGroup < 100)
    {
        D2ObjectControlStrc* pObjectControl = pGame->pObjectControl;
        ++pObjectControl->wGroupCount[nGroup];
    }
}

// 0x00546FE0
void __fastcall sub_00546FE0_SendServerMessageCallback(D2ClientStrc* pClient, void* pContext)
{
    D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(pClient, *(D2GSPacketSrv26**)pContext);
}

// 0x00546FF0
void D2GameStrc::sub_00546FF0_SendQuestText(const char* szText)
{
    D2GSPacketSrv26 packet;
    packet.szName[0] = 0;
    packet.nNameColor = 0;
    strcpy(packet.szMessage, szText);
    packet.nMessageColor = 0;
    packet.nHeader = 0x26;
    packet.dwUnitGUID = 0;
    packet.nUnitType = 2;
    packet.nMessageType = 1;
    D2GSPacketSrv26* pPacket = &packet;
    GAME_ForEachIngameClient(this, sub_00546FE0_SendQuestTextToClient, &pPacket);
}
