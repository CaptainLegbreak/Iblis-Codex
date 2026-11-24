#include "D2StatIds.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2ClientMenus.h"
#include "D2NpcIndex.h"
struct D2BitBufferStrc;
struct D2TextHeaderStrc;
struct D2InventoryStrc;
struct D2DynamicPathStrc;

struct D2NpcQuestHandlerStrc
{
    int nNpcId;
    int nQuestId;
    int nState;
    int bSet;
    int (__cdecl* pfHandler)();
};

struct D2ClientStringListStrc
{
    unsigned short awStrings[10];
    unsigned short wCount;
};


typedef char check_size_npcindex[(sizeof(D2NpcIndexStrc) == 0x27) ? 1 : -1];
typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];

typedef int (__fastcall* D2TextCallback)(void* pContext, int nArg, int nValue);
typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __cdecl FOG_IsExpansion();                                                                 // 0x00408F20
void __cdecl GAME_ResetMouseState();                                                                                // 0x0044DA40
int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
int __fastcall UI_CloseUIVars(int bArg1, int nArg2); // 0x00456300
int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
void __fastcall CUNIT_TurnTowardPlayer(D2UnitStrc* pUnit);                                                 // 0x00464420
void __fastcall CUNIT_PlayerFaceUnit(D2UnitStrc* pUnit);                                             // 0x004644E0
void __fastcall CUNIT_ForEachMonster(UNITFN pfnCallback);                                                           // 0x00464990
void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg);                          // 0x004785B0
void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
void __cdecl INV_ResetHover();                                                                     // 0x00487990
void __fastcall TEXT_SetTextCallback(D2TextCallback pfnCallback, void* pContext);                   // 0x0049E7E0
D2TextHeaderStrc* __cdecl DLIGHTMAP_GetTextHeader();                                                                   // 0x0049F900
void __fastcall TEXT_ShowNpcMessage(D2UnitStrc* pUnit, unsigned short nMessage, int nArg);                         // 0x004A10E0
D2UnitStrc* __cdecl NPCMENU_GetInteractNpc();                                                          // 0x004B1620
unsigned short __fastcall NPCMENU_GetFreeStringId(unsigned short wStringId);                           // 0x004B1830
int __cdecl NPCMENU_ResurrectMercWait();                                                               // 0x004B1DD0
void __cdecl NPCMENU_ResetHandlers();                                                                  // 0x004B2250
void __fastcall NPCMENU_ClearInteractOverlay(D2UnitStrc* pUnit);                                          // 0x004B2390
extern "C" void __fastcall NPCMENU_ClearNpcInventoryAndSound(int nUnitId); // 0x004B3830
void __fastcall NPCMENU_EndNpcInteraction(int nValue);                                                                   // 0x004B3C20
void __cdecl sub_004B3DE0_CloseNpc();                                                                       // 0x004B3DE0
void __cdecl NPCMENU_BuildNpcMenu();                                                                        // 0x004B4830
void __cdecl NPCMENU_OpenGreetingDialog();                                                             // 0x004B4DB0
void __stdcall sub_004B4FD0_OpenNpcWindow(D2UnitStrc* pUnit);                                                             // 0x004B4FD0
int __cdecl NPCMENU_ShowMainMenu();                                                                         // 0x004B5C60
int __cdecl NPCMENU_InitHireHandler();                                                                     // 0x004B6410
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __fastcall sub_004BA840(int nHandle);                                                                  // 0x004BA840
void __fastcall UNITSND_ReleaseSkillSfx(D2UnitStrc* pUnit);                                            // 0x004CB190
int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType);                                     // 0x004E0590
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_CopyBufferToRecord(D2BitBufferStrc* pQuestRecord, unsigned char* pBuffer, unsigned short nBufferSize, int bResetStates); // 0x0065C4D0
short __stdcall TEXT_GetStringIdOfMenuType0Node(D2TextHeaderStrc* pTextHeader, int nNodeId); // 0x00661400
short __stdcall TEXT_GetStringIdOfMenuType1Node(D2TextHeaderStrc* pTextHeader, int nNodeId); // 0x00661440

extern unsigned short gnHirelingName;                                                                    // 0x00725494
extern D2NpcQuestHandlerStrc gaNpcHandlers[];                                                      // 0x007253E0
// build: symbol ?gnHandlerCount@* 0x007253DC
#include "gen/data/Source/D2Client/UI/npcmenu/gnHandlerCount.inc"
struct D2UnitStrc;
extern int gnNpcEntryCount;                                                                        // 0x0072554C
extern int gnNpcIndexCount;                                                                        // 0x00725A74
extern D2NpcEntryStrc gaNpcEntries[];                                                              // 0x00726850
extern D2NpcIndexStrc gaNpcIndex[];                                                                // 0x00726C48
extern char gabNpcMenuState[];                                                                            // 0x007C0C68
extern char gbNpcMessageShown;                                                                              // 0x007C0C69
extern int gnNpcMenuState;                                                                               // 0x007C0C6B
extern int gnNpcGoldSnapshot;                                                                               // 0x007C0C73
extern unsigned short gwNpcGreetingString;                                                                    // 0x007C0C77
extern unsigned short gwNpcMessageString;                                                                    // 0x007C0C79
extern unsigned short gwNpcLastString;                                                                    // 0x007C0C7B
extern int gnInteractNpcId;                                                                               // 0x007C0D25
extern int gbNpcInteracting;                                                                               // 0x007C0D29
extern int gnInteractNpcClassId;                                                                              // 0x007C0D2D
extern int gnNpcTradeMode;                                                                               // 0x007C0D31
extern D2BitBufferStrc* gpPlayerQuestFlags;                                                              // 0x007C0D43
extern D2ClientStringListStrc gtStringList;                                                        // 0x007C0D9A
extern int gbGambleShop;                                                                              // 0x007C0DB0
extern int gnNpcSoundActive;                                                                       // 0x007C0DB4
extern int gnNpcSoundHandle;                                                                       // 0x007C0DB8
extern int gnNpcMenuValue;                                                                               // 0x007C0DD0

// build: symbol ?NPCMENU_SetNpcInteract@* 0x004B1640
static void NPCMENU_SetNpcInteract(D2UnitStrc* pRecord)
{
    if (pRecord)
    {
        gbNpcInteracting = 1;
        gnInteractNpcId = pRecord->dwUnitId;
        gnInteractNpcClassId = pRecord->dwClassId;
    }
    else
    {
        gbNpcInteracting = 0;
    }
}

// build: symbol ?NPCMENU_AddUsedString@* 0x004B1980
void __fastcall NPCMENU_AddUsedString(unsigned short wStringId)
{
    if (gtStringList.wCount < 9)
    {
        gtStringList.awStrings[gtStringList.wCount] = wStringId;
        gtStringList.wCount++;
    }
}

// build: symbol ?NPCMENU_RunNpcQuestHandlers@* 0x004B19A0
static int __stdcall NPCMENU_RunNpcQuestHandlers(int nNpcId, D2BitBufferStrc* pQuestFlags, D2NpcQuestHandlerStrc* pTable, int nCount)
{
    int nResult = 1;
    for (int i = 0; i < nCount; ++i)
    {
        if (pTable[i].nNpcId == nNpcId)
        {
            if (pTable[i].bSet)
            {
                if (QUESTRECORD_GetQuestState(pQuestFlags, pTable[i].nQuestId, pTable[i].nState))
                    nResult = pTable[i].pfHandler();
            }
            else
            {
                if (!QUESTRECORD_GetQuestState(pQuestFlags, pTable[i].nQuestId, pTable[i].nState))
                    nResult = pTable[i].pfHandler();
            }
        }
    }
    return nResult;
}

// build: symbol ?NPCMENU_IsSpecialNpc@* 0x004B1A10
static bool NPCMENU_IsSpecialNpc(int nClassId)
{
    if (nClassId == 0x92 || nClassId == 0x20F || nClassId == 0x219 || nClassId == 0x21A || nClassId == 0x21B
        || nClassId == 0x209 || nClassId == 0x10A || nClassId == 0x17A || nClassId == 0xFB || nClassId == 0x179
        || nClassId == 0x14B || nClassId == 0x196 || nClassId == 0x198)
        return true;
    return false;
}

// build: symbol ?NPCMENU_FindNpcIndex@* 0x004B2E30
static int NPCMENU_FindNpcIndex(D2UnitStrc* pRecord)
{
    if (!pRecord)
        return -1;

    const int nId = pRecord->dwClassId;
    for (int i = 0; i < gnNpcIndexCount; ++i)
    {
        if (gaNpcIndex[i].nId == nId)
            return i;
    }
    return 0;
}

static int __stdcall sub_004B6440_ToggleNpcHandler(int bAdd, int nIndex)
{
    if (!FOG_IsExpansion() || !GAME_IsExpansion())
    {
        return 0;
    }

    if (bAdd)
    {
        const int nCount = gaNpcIndex[nIndex].nCount;
        for (int i = 0; i < nCount; ++i)
        {
            if (gaNpcIndex[nIndex].apfHandlers[i] == NPCMENU_ResurrectMercWait)
            {
                return 1;
            }
        }

        for (int i = 0; i < nCount; ++i)
        {
            if (gaNpcIndex[nIndex].apfHandlers[i] == NPCMENU_ShowMainMenu)
            {
                for (int j = nCount - 1; j >= i; --j)
                {
                    gaNpcIndex[nIndex].apfHandlers[j + 1] = gaNpcIndex[nIndex].apfHandlers[j];
                    gaNpcIndex[nIndex].awIds[j + 1] = gaNpcIndex[nIndex].awIds[j];
                }
                ++gaNpcIndex[nIndex].nCount;
                gaNpcIndex[nIndex].apfHandlers[i] = NPCMENU_ResurrectMercWait;
                gaNpcIndex[nIndex].awIds[i] = 0x1507;
                return 1;
            }
        }

        const int nPos = nCount - 1;
        for (int j = nCount - 1; j >= nPos; --j)
        {
            gaNpcIndex[nIndex].apfHandlers[j + 1] = gaNpcIndex[nIndex].apfHandlers[j];
            gaNpcIndex[nIndex].awIds[j + 1] = gaNpcIndex[nIndex].awIds[j];
        }
        ++gaNpcIndex[nIndex].nCount;
        gaNpcIndex[nIndex].apfHandlers[nPos] = NPCMENU_ResurrectMercWait;
        gaNpcIndex[nIndex].awIds[nPos] = 0x1507;
        return 1;
    }

    const int nCount = gaNpcIndex[nIndex].nCount;
    for (int i = 0; i < nCount; ++i)
    {
        if (gaNpcIndex[nIndex].apfHandlers[i] == NPCMENU_ResurrectMercWait)
        {
            for (int j = i; j < gaNpcIndex[nIndex].nCount - 1; ++j)
            {
                gaNpcIndex[nIndex].apfHandlers[j] = gaNpcIndex[nIndex].apfHandlers[j + 1];
                gaNpcIndex[nIndex].awIds[j] = gaNpcIndex[nIndex].awIds[j + 1];
            }
            --gaNpcIndex[nIndex].nCount;
            return 1;
        }
    }
    return 1;
}

static void __stdcall sub_004B66B0_OpenNpcInteract(D2UnitStrc* pUnit, int bReopen);

// 0x004B66B0
static void __stdcall sub_004B66B0_OpenNpcInteract(D2UnitStrc* pUnit, int bReopen)
{
    GAME_ResetMouseState();
    if (!pUnit)
    {
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return;
    }

    gnNpcMenuState = 1;
    gnNpcTradeMode = 0;
    gnNpcGoldSnapshot = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0);
    UI_CloseUIVars(0, 0);

    if (!bReopen)
    {
        if (pUnit == (gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0))
        {
            return;
        }
        if (gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0)
        {
            sub_004B3DE0_CloseNpc();
            return;
        }
    }
    else
    {
        gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
    }

    gbNpcInteracting = 1;
    gnInteractNpcId = pUnit->dwUnitId;
    gnInteractNpcClassId = pUnit->dwClassId;
    pUnit->dwFlags &= ~2;

    const int nNpcId = pUnit->dwClassId;
    NPCMENU_RunNpcQuestHandlers(nNpcId, gpPlayerQuestFlags, gaNpcHandlers, gnHandlerCount);

    if (gnNpcSoundActive)
    {
        if (gnNpcSoundHandle)
        {
            sub_004BA840(gnNpcSoundHandle);
            gnNpcSoundHandle = 0;
        }
        gnNpcSoundActive = 0;
    }

    switch (pUnit->dwClassId)
    {
    case 0x96:
        if (STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_LEVEL, 0) >= 8)
        {
            NPCMENU_InitHireHandler();
        }
        sub_004B6440_ToggleNpcHandler(gnHirelingName != 0xFFFF, 0xB);
        break;

    case 0xC6:
        sub_004B6440_ToggleNpcHandler(gnHirelingName != 0xFFFF, 8);
        break;

    case 0xFC:
        sub_004B6440_ToggleNpcHandler(gnHirelingName != 0xFFFF, 0x18);
        break;

    case 0x16F:
        sub_004B6440_ToggleNpcHandler(gnHirelingName != 0xFFFF, 0x15);
        break;

    case 0x203:
        sub_004B6440_ToggleNpcHandler(gnHirelingName != 0xFFFF, 0x2B);
        break;
    }

    if (!UI_SetUIVar(8, 0, 0))
    {
        gnNpcMenuState = 0;
        pUnit->dwFlags |= 2;
        MSG_SendTwoDwords(0x30, 1, !pUnit ? -1 : pUnit->dwUnitId);
        gbNpcInteracting = 0;
        NPCMENU_ClearNpcInventoryAndSound(pUnit->dwUnitId);
        return;
    }

    NPCMENU_BuildNpcMenu();
    if (bReopen)
    {
        return;
    }

    int nType = 0;
    for (int i = 0; i < gnNpcEntryCount; ++i)
    {
        if (gaNpcEntries[i].nId == nNpcId)
        {
            if (gaNpcEntries[i].bFlag == 1)
            {
                gaNpcEntries[i].bFlag = 0;
                nType = 2;
            }
            if (gaNpcEntries[i].bRefreshed != 1)
            {
                return;
            }
            gaNpcEntries[i].bRefreshed = 0;
            break;
        }
    }

    const int nSound = sub_004E0590_PickNpcSound(pUnit, nType);
    if (!nSound)
    {
        return;
    }

    UNITSND_ReleaseSkillSfx(pUnit);
    gnNpcSoundHandle = sub_004B9A00(nSound, sub_00463DD0_GetPlayerUnit(), 0, 1, 0);
    if (nType == 2)
    {
        MSG_SendWord(0x4D, nNpcId);
        gnNpcSoundActive = 1;
        return;
    }
    gnNpcSoundHandle = 0;
}

void __fastcall NPCMENU_SetNpcMenuState(unsigned short wValue, int nValue)
{
    gnHirelingName = wValue;
    gnNpcMenuValue = nValue;
    if (wValue == 0xFFFF)
    {
        sub_004B6440_ToggleNpcHandler(0, 0xB);
        sub_004B6440_ToggleNpcHandler(0, 8);
        sub_004B6440_ToggleNpcHandler(0, 0x18);
        sub_004B6440_ToggleNpcHandler(0, 0x15);
        sub_004B6440_ToggleNpcHandler(0, 0x2B);
    }
}

// build: symbol ?NPCMENU_NpcTextCallback@* 0x004B6A30
int __fastcall NPCMENU_NpcTextCallback(void* pContext, int nArg, int nValue)
{
    gwNpcMessageString = NPCMENU_GetFreeStringId(gwNpcGreetingString);
    if (gwNpcGreetingString == 0x251)
    {
        sub_004B9A00(0xF1, 0, 0, 0, 0);
    }
    if (gwNpcGreetingString == 0x21A)
    {
        sub_004B9A00(0xED, 0, 0, 0, 0);
    }

    if (gbNpcMessageShown == 1)
    {
        if (gwNpcMessageString != 0xFFFF && (gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0))
        {
            gwNpcLastString = gwNpcMessageString;
            TEXT_ShowNpcMessage(gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0, gwNpcLastString, 1);
            NPCMENU_AddUsedString(gwNpcLastString);
            TEXT_SetTextCallback(NPCMENU_NpcTextCallback, 0);
            gwNpcGreetingString = gwNpcLastString;
            MSG_SendTwoDwords(0x31, gnInteractNpcId, gwNpcLastString);
            gwNpcMessageString = NPCMENU_GetFreeStringId(gwNpcLastString);
            return 1;
        }

        gbNpcMessageShown = 0;
        TEXT_SetTextCallback(0, 0);
        const int nIndex = NPCMENU_FindNpcIndex(gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0);
        if ((!nArg || !nValue) && !NPCMENU_IsSpecialNpc(gnInteractNpcClassId) && nIndex >= 0 && NPCMENU_GetInteractNpc()
            && nIndex < gnNpcIndexCount && gaNpcIndex[nIndex].bEnabled)
        {
            gnNpcMenuState = 1;
            if (NPCMENU_GetInteractNpc())
            {
                sub_004B66B0_OpenNpcInteract(NPCMENU_GetInteractNpc(), 1);
                return 1;
            }
            sub_004B3DE0_CloseNpc();
            return 0;
        }

        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return 0;
    }

    gbNpcMessageShown = 0;
    TEXT_SetTextCallback(0, pContext);
    gwNpcGreetingString = 0xFFFF;
    NPCMENU_OpenGreetingDialog();
    return 0;
}

static inline int NPC_GetUnitClassId(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwClassId : -1;
}

// 0x004B6DD0
void __fastcall sub_004B6DD0_NpcInteractPacket(unsigned char nUnitType, int nUnitId, unsigned char* pBuffer, unsigned char nArg)
{
    if (nUnitType == 6)
    {
        QUESTRECORD_CopyBufferToRecord(gpPlayerQuestFlags, pBuffer, 0x60, 0);
        return;
    }

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, nUnitType);
    if (!pUnit)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nState = 0;
            pPlayer->pPlayerData->nMode = 0;
            pPlayer->pPlayerData->nArg1 = 0;
            pPlayer->pPlayerData->nArg2 = 0;
        }
        MSG_SendTwoDwords(0x30, nArg, nUnitId);
        NPCMENU_ClearNpcInventoryAndSound(nUnitId);
        return;
    }

    CUNIT_ForEachMonster(NPCMENU_ClearInteractOverlay);
    pUnit->dwFlags |= 2;
    QUESTRECORD_CopyBufferToRecord(gpPlayerQuestFlags, pBuffer, 0x60, 0);
    NPCMENU_ResetHandlers();
    MSG_SendTwoDwords(0x2F, nUnitType, nUnitId);
    GAME_ResetMouseState();

    if (gabNpcMenuState[0])
    {
        gbNpcMessageShown = 1;
        NPCMENU_SetNpcInteract(pUnit);
        pUnit->dwFlags &= ~2;
        return;
    }

    D2TextHeaderStrc* pTextHeader = DLIGHTMAP_GetTextHeader();
    D2_ASSERT(pTextHeader, 0x1060);

    const unsigned short wString = TEXT_GetStringIdOfMenuType0Node(pTextHeader, 0);
    const int nClassId = NPC_GetUnitClassId(pUnit);
    if (MONSTERUNIQUE_CheckMonStatsFlag(nClassId, 9) && nClassId != 0x219 && nClassId != 0x21A && nClassId != 0x21B
        && nClassId != 0x20F)
    {
        CUNIT_TurnTowardPlayer(pUnit);
    }

    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (INVENTORY_GetCursorItem(pInventory))
    {
        gbNpcInteracting = 1;
        gnInteractNpcId = pUnit->dwUnitId;
        gnInteractNpcClassId = pUnit->dwClassId;
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return;
    }

    gtStringList.wCount = 0;
    if (wString != 0xFFFF)
    {
        UI_CloseUIVars(0, 0);
        gwNpcGreetingString = wString;
        TEXT_ShowNpcMessage(pUnit, wString, 1);
        NPCMENU_AddUsedString(wString);
        gwNpcMessageString = NPCMENU_GetFreeStringId(wString);
        MSG_SendTwoDwords(0x31, pUnit->dwUnitId, wString);
        gbNpcMessageShown = 1;
        TEXT_SetTextCallback(NPCMENU_NpcTextCallback, 0);
        NPCMENU_SetNpcInteract(pUnit);
    }
    else
    {
        const unsigned short wString2 = TEXT_GetStringIdOfMenuType1Node(pTextHeader, 0);
        if (pUnit->dwClassId != 0x20F)
        {
            CUNIT_PlayerFaceUnit(pUnit);
        }
        if (pUnit->pDynamicPath)
        {
            D2Common_10153(pUnit->pDynamicPath);
        }

        if (wString2 != 0xFFFF)
        {
            INV_ResetHover();
            UI_CloseUIVars(0, 0);
            gwNpcGreetingString = wString2;
            gwNpcMessageString = NPCMENU_GetFreeStringId(wString2);
            sub_004B4FD0_OpenNpcWindow(pUnit);
        }
        else
        {
            const int nClass = pUnit->dwClassId;
            if (MONSTERUNIQUE_CheckMonStatsFlag(nClass, 9))
            {
                if (NPCMENU_IsSpecialNpc(nClass))
                {
                    gbNpcInteracting = 1;
                    gnInteractNpcId = pUnit->dwUnitId;
                    gnInteractNpcClassId = pUnit->dwClassId;
                    NPCMENU_EndNpcInteraction(gnInteractNpcId);
                    UI_SetUIVar(8, 1, 0);
                    return;
                }
                INV_ResetHover();
                UI_CloseUIVars(0, 0);
                sub_004B66B0_OpenNpcInteract(pUnit, 0);
            }
            else
            {
                NPCMENU_EndNpcInteraction(gnInteractNpcId);
                UI_SetUIVar(8, 1, 0);
            }
        }
    }
    gbGambleShop = 0;
}
