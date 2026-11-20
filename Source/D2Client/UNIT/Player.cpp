#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2ClientGame.h"
#include "D2StormLink.h"
struct D2SkillStrc;
struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2LightStrc;
struct D2GameStrc;
struct D2GfxLightStrc;
struct D2StaticPathStrc;
struct D2MonStatsTxt;
struct D2ItemStatCostTxt;
struct D2PacketBufferStrc;
struct D2StormLinkStrc;
struct D2StormExplicitListStrc;
struct D2MsgFilterStrc;
struct D2PlayerDataStrc;
struct D2ClientUnitViewStrc;
union D2SeedStrc;
struct D2PlayerCmdStrc;
struct D2SkillsTxt;
struct D2StringRefStrc;

struct D2StormExplicitListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    void UnlinkAll();
};

struct D2MsgFilterStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pUnit04;
    D2UnitStrc* pUnit08;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __cdecl sub_0044DB30(); // 0x0044DB30
void __cdecl sub_0044DA70(); // 0x0044DA70
int __cdecl sub_0044DCC0(); // 0x0044DCC0
void __cdecl sub_00457520_UpdateAutomapLayout(); // 0x00457520
void __cdecl sub_00459700_PaintAutomap(); // 0x00459700
void __cdecl sub_00459E90_DrawGameInfoLines(); // 0x00459E90
void __cdecl sub_00459FF0_DrawStringLine(); // 0x00459FF0
void __cdecl sub_0045A050_DrawLevelName(); // 0x0045A050
void __cdecl sub_0045A0A0_DrawVersionLine(); // 0x0045A0A0
void __cdecl sub_0045A120_DrawLocalIpLine(); // 0x0045A120
void __cdecl sub_0045A190_DrawDifficultyLine(); // 0x0045A190
void __cdecl sub_0045AC90_DrawAutomapUnits(); // 0x0045AC90
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
D2PacketBufferStrc* __fastcall sub_00464770_GetPacketBuffer(void* pArg); // 0x00464770
void __fastcall sub_004647A0_SetPacketBuffer(void* pArg, D2PacketBufferStrc* pBuffer); // 0x004647A0
void __fastcall sub_004F52A0_SetOffset(int nOffset); // 0x004F52A0
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
extern void* gpGlobal_007A0634; // 0x007A0634
extern D2ViewStrc* gpView_007A0640; // 0x007A0640
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnAutomapTextY_007A51BC; // 0x007A51BC
extern int gdwGlobal_007A5208; // 0x007A5208
extern int gdwGlobal_007A520C; // 0x007A520C
extern int gdwGlobal_007A5210; // 0x007A5210
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnAutomapWidth_007A5220; // 0x007A5220
extern int gdwGlobal_007A5264; // 0x007A5264

struct D2ClientUnitViewStrc
{
    int dwUnitType;
    int unk0x04[4];
    D2PlayerDataStrc* pPlayerData;
};

D2LightStrc* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2); // 0x00643A00
void __fastcall sub_004743D0_ReleaseOverlayResource(D2LightStrc* pLight); // 0x004743D0
extern int gnGlobal_007A5258; // 0x007A5258
extern int gnGlobal_007A525C; // 0x007A525C

typedef void (__fastcall* STATLIST_CallbackFn)(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue);

extern int gnInTown_007A5260; // 0x007A5260
void __fastcall sub_004609F0_OnStatChanged(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue); // 0x004609F0
void __cdecl sub_004608C0_RefreshAdjacentPlayers(); // 0x004608C0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __fastcall sub_0046C6E0_AddToUnitSlots(D2UnitStrc* pUnit); // 0x0046C6E0
D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160
int __fastcall sub_00474350_GetLightSize(D2GfxLightStrc* pLight); // 0x00474350
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __stdcall UNITS_AllocPlayerData(D2UnitStrc* pUnit); // 0x00621F90
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, STATLIST_CallbackFn pfCallback, D2GameStrc* pGame); // 0x00626D40
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0
void __stdcall SKILLS_InitSkillList(D2UnitStrc* pUnit); // 0x00647EE0
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006488A0
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce); // 0x00649560
void __stdcall PATH_AllocDynamicPath(void* pMemPool, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pUnit, int bSetFlag); // 0x00649D00
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern int gnStringCount_00711EF0; // 0x00711EF0
extern D2StringRefStrc gaStringRefs_00711DDC[]; // 0x00711DDC
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill); // 0x004D9FC0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
void __cdecl sub_00453EC0(); // 0x00453EC0
void __fastcall sub_0045C470_ClearPendingAction(D2UnitStrc* pUnit); // 0x0045C470
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __fastcall sub_00467880_FindSkillTarget(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pX, int* pY, unsigned int dwFlags, int bForce); // 0x00467880
int __cdecl sub_00468830(); // 0x00468830
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00645460

int gnGlobal_007A5214; // 0x007A5214

int gdwGlobal_007A5238; // 0x007A5238

int gnGlobal_007A526C; // 0x007A526C

inline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x00457490
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x0045AD60
void __cdecl sub_0045AD60()
{
    if (!gpGlobal_007A0634)
    {
        return;
    }
    if (!sub_00463DE0_GetPlayerUnit())
    {
        return;
    }
    if (!UNITS_GetRoom(sub_00463DE0_GetPlayerUnit()))
    {
        return;
    }
    sub_00457520_UpdateAutomapLayout();
    sub_00459700_PaintAutomap();
    sub_0045AC90_DrawAutomapUnits();
    gnAutomapTextY_007A51BC = 0x18;
    const int nAct = sub_0044DB30();
    const int nPrevious = sub_00502EF0(1);
    sub_00459E90_DrawGameInfoLines();
    sub_0045A050_DrawLevelName();
    sub_0045A0A0_DrawVersionLine();
    sub_0045A190_DrawDifficultyLine();
    if (nAct == 6 || nAct == 8)
    {
        sub_0045A120_DrawLocalIpLine();
    }
    if (sub_0044DCC0())
    {
        sub_00459FF0_DrawStringLine();
    }
    sub_00502EF0(nPrevious);
}

// 0x0045ADF0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x0045AE20
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x0045AEA0
void __fastcall sub_0045AEA0_SetPanelSlide(int nMode)
{
    switch (nMode)
    {
    case 0:
    case 3:
        gnGlobal_007A5214 = 0;
        break;
    case 1:
        gnGlobal_007A5214 = -(gnGlobal_0071146C / 4);
        break;
    case 2:
        gnGlobal_007A5214 = gnGlobal_0071146C / 4;
        break;
    }
    gdwGlobal_007A5210 = nMode;
    sub_004F52A0_SetOffset(gnGlobal_007A5214);
    const int nWidth = gnAutomapWidth_007A5220;
    const int nQuarter = nWidth / 4;
    switch (nMode)
    {
    case 0:
        sub_00476000_SetViewRect(gpView_007A0640, 0, 0, nWidth, gnAutomapHeight_007A521C);
        break;
    case 1:
        sub_00476000_SetViewRect(gpView_007A0640, -nQuarter, 0, nWidth - nQuarter, gnAutomapHeight_007A521C);
        break;
    case 2:
        sub_00476000_SetViewRect(gpView_007A0640, nQuarter, 0, nWidth + nQuarter, gnAutomapHeight_007A521C);
        break;
    case 3:
        sub_00476000_SetViewRect(gpView_007A0640, 0, 0, nWidth, gnAutomapHeight_007A521C);
        sub_0044DA70();
        break;
    }
}

// 0x0045AFC0
extern "C" int __cdecl sub_0045AFC0()
{
    return gdwGlobal_007A520C - gnGlobal_007A5214;
}

// 0x0045AFD0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset()
{
    return gdwGlobal_007A5208 - 8;
}

// 0x0045BD00
void D2StormExplicitListStrc::UnlinkAll()
{
    for (;;)
    {
        char* pNode = Head();
        if (!pNode)
        {
            break;
        }
        ((D2StormLinkStrc*)pNode)->Unlink();
    }
}

// 0x0045C460
int __fastcall DATATBLS_GetMonStatsTxtRecordCount()
{
    return sgptDataTables->nMonStatsTxtRecordCount;
}

// 0x0045C4F0
D2ItemStatCostTxt* __fastcall sub_0045C4F0_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x0045F9F0
void __fastcall sub_0045F9F0_FreePacketBuffer(void* pArg)
{
    D2PacketBufferStrc* pBuffer = sub_00464770_GetPacketBuffer(pArg);
    if (pBuffer)
    {
        FOG_Free(pBuffer->pData, ".\\GAME\\SCmd.cpp", 0x1516, 0);
        FOG_Free(pBuffer, ".\\GAME\\SCmd.cpp", 0x1517, 0);
        sub_004647A0_SetPacketBuffer(pArg, 0);
    }
}

// 0x00460480
void __fastcall sub_00460480(int bExpansion)
{
    gdwGlobal_007A5238 = bExpansion;
}

// 0x00462920
void __cdecl sub_00462920_ClearValue()
{
    gdwGlobal_007A5264 = 0;
}

// 0x00462930
int __fastcall sub_00462930_FilterMessage(D2MsgFilterStrc* pMsg)
{
    const unsigned int dwFlags = pMsg->dwFlags;
    if (dwFlags & 0x10)
    {
        gnGlobal_007A526C = 0;
        return 0;
    }
    if (dwFlags & 4)
    {
        gnGlobal_007A526C = (pMsg->pUnit08 != 0) + 1;
        return 1;
    }
    if (dwFlags & 8)
    {
        if (!gnGlobal_007A526C)
        {
            return 0;
        }
        if (pMsg->pUnit08)
        {
            const int nType = pMsg->pUnit08->dwUnitType;
            if (nType < 0)
            {
                return 0;
            }
            if (nType > 1 && nType != 5)
            {
                return 0;
            }
            if (pMsg->pUnit04)
            {
                const int nMode = pMsg->pUnit04->dwAnimMode;
                if (nMode == 2 || nMode == 3 || nMode == 6)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// 0x00463830
int __fastcall sub_00463830_GetBaseIdFromMonsterId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }
    return nMonsterId;
}

// 0x00460170
int __cdecl sub_00460170_IsEitherSet()
{
    if (gnGlobal_007A5258 || gnGlobal_007A525C)
        return 1;
    return 0;
}

// 0x00460760
void __fastcall sub_00460760_SetPlayerState(D2ClientUnitViewStrc* pUnit, int nState)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
        pUnit->pPlayerData->nState = nState;
}

// 0x004607D0
int __fastcall sub_004607D0_GetPlayerMode(D2ClientUnitViewStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
        return pUnit->pPlayerData->nMode;
    return 0;
}

// 0x004607F0
int __fastcall sub_004607F0_GetPlayerArg1(D2ClientUnitViewStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
        return pUnit->pPlayerData->nArg1;
    return 0;
}

// 0x00460810
int __fastcall sub_00460810_GetPlayerArg2(D2ClientUnitViewStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
        return pUnit->pPlayerData->nArg2;
    return 0;
}

// 0x00460FF0
static __forceinline void sub_00460FF0_ReleaseLight(D2UnitStrc* pUnit)
{
    D2LightStrc* pLight = D2Common_10958(pUnit, 0);
    if (pLight)
        sub_004743D0_ReleaseOverlayResource(pLight);
}

void __fastcall sub_M115_Emit_00460FF0(D2UnitStrc* pUnit)
{
    sub_00460FF0_ReleaseLight(pUnit);
}

// 0x00460BF0
void __fastcall sub_00460BF0_InitClientPlayer(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    sub_0046C6E0_AddToUnitSlots(pUnit);
    PATH_AllocDynamicPath(0, pRoom, nX, nY, pUnit, 1);
    if (!pUnit->pInventory)
    {
        pUnit->pInventory = INVENTORY_AllocInventory(0, pUnit);
    }

    pUnit->pSkills = SKILLS_AllocSkillList(0);
    SKILLS_InitSkillList(pUnit);
    STATLIST_AllocStatListEx(pUnit, 0, sub_004609F0_OnStatChanged, 0);
    STATLIST_SetUnitStat(pUnit, 0x44, 100, 0);
    STATLIST_SetUnitStat(pUnit, 0x43, 100, 0);
    STATLIST_SetUnitStat(pUnit, 0x45, 100, 0);
    gnInTown_007A5260 = DUNGEON_IsRoomInTown(pRoom);
    UNITS_ChangeAnimMode(pUnit, 5);
    pUnit->dwFlags &= ~0x20;
    pUnit->dwFlags |= 0xE;
    if (pUnit->dwAnimMode == 0x11 || pUnit->dwAnimMode == 0)
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
        sub_00649190_SetPathMode(pUnit, 5);
        PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, 0x8000);
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!sub_0061AB30(pRoom))
    {
        D2GfxLightStrc* pLight = sub_00474160_MakeLightEntry(pUnit, pPlayer && pUnit != pPlayer, 0xD, 0xFF, 0xFF, 0xFF, 0xFF);
        if (pLight)
        {
            pUnit->pLight = pLight;
            sub_00464CF0(pUnit, sub_00474350_GetLightSize(pLight));
        }
    }

    UNITS_AllocPlayerData(pUnit);
    if (pUnit != pPlayer)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        D2SeedStrc* pSeed = &pUnit->pSeed;
        unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
        pSeed->nLowSeed = (unsigned int)lSeed;
        pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
        PATH_SetDirection(pPath, (unsigned int)lSeed & 0x3F);
    }

    sub_004608C0_RefreshAdjacentPlayers();
}

static void __stdcall sub_00461070_RequestSkillString(D2UnitStrc* pUnit, int nIndex)
{
    D2_ASSERT(gnStringCount_00711EF0 > nIndex, 0x2CB);
    const unsigned short nStringId = gaStringRefs_00711DDC[nIndex].nStringId;
    if (nStringId)
        sub_004CB9C0_Request(pUnit, nStringId);
}

// 0x004610C0
static int __stdcall sub_004610C0_CheckSkillUse(D2SkillStrc** ppSkill, int* pUseState, D2UnitStrc* pUnit)
{
    if (pUnit != sub_00463DD0_GetPlayerUnit())
        return 1;

    if (!ppSkill || !*ppSkill)
        return 0;

    int nUseState = sub_004D9FC0(pUnit, *ppSkill);
    if (pUseState)
        *pUseState = nUseState;

    D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(*ppSkill);
    if (!pSkillsTxt)
        return 0;

    if (nUseState > 0 && (nUseState <= 2 || nUseState == 4)
        && (pSkillsTxt->nFlags[3] & gdwBitMasks[4]))
    {
        *ppSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, 0);
        nUseState = sub_004D9FC0(pUnit, *ppSkill);
    }

    if (nUseState == 5 || nUseState == 0)
        return 1;

    sub_00461070_RequestSkillString(pUnit, nUseState);
    return 0;
}

// 0x00461160
static __forceinline int sub_00461160_CheckCommandSkill(D2PlayerCmdStrc* pCmd, int* pUseState)
{
    return sub_004610C0_CheckSkillUse(&pCmd->pSkill, pUseState, pCmd->pPlayer);
}

int __stdcall sub_M135_Emit_00461160A(D2PlayerCmdStrc* pCmd, int* pUseState)
{
    return sub_00461160_CheckCommandSkill(pCmd, pUseState) + 0x3131;
}

int __stdcall sub_M135_Emit_00461160B(int nSkip, D2PlayerCmdStrc* pCmd)
{
    if (!sub_00461160_CheckCommandSkill(pCmd, 0))
        return nSkip;
    return 0x3133;
}

static inline int E06_GetPlayerMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
        return pUnit->pPlayerData->nMode;
    return 0;
}

static inline int E06_GetPlayerModeArg1(D2UnitStrc* pUnit)
{
    return pUnit ? (pUnit->dwUnitType == 0 ? (pUnit->pPlayerData ? pUnit->pPlayerData->nArg1 : 0) : 0) : 0;
}

static inline int E06_GetPlayerModeArg2(D2UnitStrc* pUnit)
{
    return pUnit ? (pUnit->dwUnitType == 0 ? (pUnit->pPlayerData ? pUnit->pPlayerData->nArg2 : 0) : 0) : 0;
}

static inline void E06_ClearPlayerMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nState = 0;
        pUnit->pPlayerData->nMode = 0;
        pUnit->pPlayerData->nArg1 = 0;
        pUnit->pPlayerData->nArg2 = 0;
    }
}

// 0x004621D0
static int sub_004621D0_PrepareCommand(D2PlayerCmdStrc* pCmd)
{
    const int nResult = D2Common_11016(pCmd->pPlayer, pCmd->pSkill);
    if (pCmd->pSkill && (pCmd->dwFlags & 2) && nResult != 1)
    {
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pCmd->pSkill);
        if (!pSkillsTxt)
            return 0;

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pCmd->pPlayer);
        if (!(pSkillsTxt->nFlags[1] & gdwBitMasks[0]) && DUNGEON_IsRoomInTown(pRoom))
        {
            sub_004CB9C0_Request(pCmd->pPlayer, 0x18);
            return 0;
        }

        if (pSkillsTxt->nFlags[0] & gdwBitMasks[4])
            return 0;
    }

    if (pCmd->dwFlags & 0x40)
    {
        pCmd->nArg = 3;
        pCmd->nMode = 4;
    }
    else
    {
        pCmd->nArg = 1;
        pCmd->nMode = 2;
    }

    const int nMode = E06_GetPlayerMode(pCmd->pPlayer);
    if (nMode)
    {
        if (nMode == 0x13)
        {
            const int nModeArg1 = E06_GetPlayerModeArg1(pCmd->pPlayer);
            const int nModeArg2 = E06_GetPlayerModeArg2(pCmd->pPlayer);
            if (sub_00463990(nModeArg2, nModeArg1))
                sub_0045C470_ClearPendingAction(pCmd->pPlayer);
        }
        else
        {
            E06_ClearPlayerMode(pCmd->pPlayer);
        }
    }

    if (!pCmd->pSkill)
        return 0;

    int bForce = (pCmd->dwFlags >> 5) & 1;
    if ((pCmd->dwFlags & 2) && !pCmd->pTarget)
        bForce = 1;
    pCmd->pTarget = sub_00467880_FindSkillTarget(pCmd->pSkill, pCmd->pTarget, &pCmd->nX, &pCmd->nY, pCmd->dwFlags, bForce);
    if (sub_00468830() == 6)
    {
        sub_00453EC0();
        return 1;
    }
    if (sub_00468830() == 8)
        sub_00478680_SendPacket5(0x4C, -1);
    return 1;
}

int __cdecl sub_E06_Emit_004621D0(D2PlayerCmdStrc* pCmd)
{
    if (!sub_004621D0_PrepareCommand(pCmd))
    {
        return 0;
    }
    return pCmd->nMode;
}
