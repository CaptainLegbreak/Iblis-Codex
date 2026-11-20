#include "D2Structs.h"
#include "D2UnitData.h"
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

#pragma pack(push, 1)
struct D2NpcIndexStrc
{
    int nId;
    int nCount;
    unsigned short awIds[5];
    int (__cdecl* apfHandlers[5])();
    char bEnabled;
};

struct D2NpcEntryStrc
{
    int nId;
    char unk0x04[0x0E];
    char bFlag;
    char unk0x13[0x02];
    char bRefreshed;
};
#pragma pack(pop)

typedef char check_size_npcindex[(sizeof(D2NpcIndexStrc) == 0x27) ? 1 : -1];
typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];

typedef int (__fastcall* D2TextCallback)(void* pContext, int nArg, int nValue);
typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __cdecl sub_0044DA40();                                                                                // 0x0044DA40
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                         // 0x00455F20
void __fastcall sub_00456300(int nArg1, int nArg2);                                                         // 0x00456300
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_00464420_TurnTowardPlayer(D2UnitStrc* pUnit);                                                 // 0x00464420
void __fastcall sub_004644E0_PlayerFaceUnit(D2UnitStrc* pUnit);                                             // 0x004644E0
void __fastcall sub_00464990(UNITFN pfnCallback);                                                           // 0x00464990
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg);                          // 0x004785B0
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                                // 0x004786A0
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext);                   // 0x0049E7E0
D2TextHeaderStrc* __cdecl sub_0049F900();                                                                   // 0x0049F900
void __fastcall sub_004A10E0(D2UnitStrc* pUnit, unsigned short nMessage, int nArg);                         // 0x004A10E0
D2UnitStrc* __cdecl sub_004B1620_GetInteractNpc();                                                          // 0x004B1620
unsigned short __fastcall sub_004B1830_GetFreeStringId(unsigned short wStringId);                           // 0x004B1830
int __cdecl sub_004B1DD0_OpenTimedDialog62();                                                               // 0x004B1DD0
void __cdecl sub_004B2250_ResetHandlers();                                                                  // 0x004B2250
void __fastcall sub_004B2390_CheckMonStatsFlag(D2UnitStrc* pUnit);                                          // 0x004B2390
void __fastcall sub_004B3830_ClearNpcInventoryAndSound(int nUnitId);                                        // 0x004B3830
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20
void __cdecl sub_004B3DE0_CloseNpc();                                                                       // 0x004B3DE0
void __cdecl sub_004B4830_Rebuild();                                                                        // 0x004B4830
void __cdecl sub_004B4DB0_OpenGreetingDialog();                                                             // 0x004B4DB0
void __stdcall sub_004B4FD0(D2UnitStrc* pUnit);
int __cdecl sub_004B5C60_Handler();                                                                         // 0x004B5C60
int __cdecl sub_004B6410_InitHandler();                                                                     // 0x004B6410
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __fastcall sub_004BA840(int nHandle);                                                                  // 0x004BA840
void __fastcall sub_004CB190_ReleaseSkillSfx(D2UnitStrc* pUnit);                                            // 0x004CB190
int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType);                                     // 0x004E0590
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_CopyBufferToRecord(D2BitBufferStrc* pQuestRecord, unsigned char* pBuffer, unsigned short nBufferSize, int bResetStates); // 0x0065C4D0
unsigned short __stdcall sub_00661400(D2TextHeaderStrc* pTextHeader, int nNodeId);    // 0x00661400
unsigned short __stdcall sub_00661440(D2TextHeaderStrc* pTextHeader, int nNodeId);    // 0x00661440

extern unsigned short gwGlobal_00725494;                                                                    // 0x00725494
extern D2NpcQuestHandlerStrc gaNpcHandlers_007253E0[];                                                      // 0x007253E0
extern int gnHandlerCount_007253DC; // 0x007253DC
extern int gnNpcEntryCount_0072554C;                                                                        // 0x0072554C
extern int gnNpcIndexCount_00725A74;                                                                        // 0x00725A74
extern D2NpcEntryStrc gaNpcEntries_00726850[];                                                              // 0x00726850
extern D2NpcIndexStrc gaNpcIndex_00726C48[];                                                                // 0x00726C48
extern char gaGlobal_007C0C68[];                                                                            // 0x007C0C68
extern char gbGlobal_007C0C69;                                                                              // 0x007C0C69
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern int gnGlobal_007C0C73;                                                                               // 0x007C0C73
extern unsigned short gwGlobal_007C0C77;                                                                    // 0x007C0C77
extern unsigned short gwGlobal_007C0C79;                                                                    // 0x007C0C79
extern unsigned short gwGlobal_007C0C7B;                                                                    // 0x007C0C7B
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D29;                                                                               // 0x007C0D29
extern int gdwGlobal_007C0D2D;                                                                              // 0x007C0D2D
extern int gnGlobal_007C0D31;                                                                               // 0x007C0D31
extern D2BitBufferStrc* gpQuestFlags_007C0D43;                                                              // 0x007C0D43
extern D2ClientStringListStrc gtStringList_007C0D9A;                                                        // 0x007C0D9A
extern int gdwGlobal_007C0DB0;                                                                              // 0x007C0DB0
extern int gnNpcSoundActive_007C0DB4;                                                                       // 0x007C0DB4
extern int gnNpcSoundHandle_007C0DB8;                                                                       // 0x007C0DB8
extern int gnGlobal_007C0DD0;                                                                               // 0x007C0DD0

static __declspec(noinline) void sub_004B1640_SetNpcInteract(D2UnitStrc* pRecord)
{
    if (pRecord)
    {
        gnGlobal_007C0D29 = 1;
        gnGlobal_007C0D25 = pRecord->dwUnitId;
        gdwGlobal_007C0D2D = pRecord->dwClassId;
    }
    else
    {
        gnGlobal_007C0D29 = 0;
    }
}

void __fastcall sub_004B1980_AddUsedString(unsigned short wStringId)
{
    if (gtStringList_007C0D9A.wCount < 9)
    {
        gtStringList_007C0D9A.awStrings[gtStringList_007C0D9A.wCount] = wStringId;
        gtStringList_007C0D9A.wCount++;
    }
}

static int __stdcall sub_004B19A0_RunNpcQuestHandlers(int nNpcId, D2BitBufferStrc* pQuestFlags, D2NpcQuestHandlerStrc* pTable, int nCount)
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

static __declspec(noinline) bool sub_004B1A10_IsSpecialNpc(int nClassId)
{
    if (nClassId == 0x92 || nClassId == 0x20F || nClassId == 0x219 || nClassId == 0x21A || nClassId == 0x21B
        || nClassId == 0x209 || nClassId == 0x10A || nClassId == 0x17A || nClassId == 0xFB || nClassId == 0x179
        || nClassId == 0x14B || nClassId == 0x196 || nClassId == 0x198)
        return true;
    return false;
}

static __declspec(noinline) int sub_004B2E30_FindNpcIndex(D2UnitStrc* pRecord)
{
    if (!pRecord)
        return -1;

    const int nId = pRecord->dwClassId;
    for (int i = 0; i < gnNpcIndexCount_00725A74; ++i)
    {
        if (gaNpcIndex_00726C48[i].nId == nId)
            return i;
    }
    return 0;
}

static __declspec(noinline) int __stdcall sub_004B6440_ToggleNpcHandler(int bAdd, int nIndex);

// 0x004B6440
static int __stdcall sub_004B6440_ToggleNpcHandler(int bAdd, int nIndex)
{
    if (!sub_00408F20_HasExpansionMpq() || !sub_0044DCC0())
    {
        return 0;
    }

#define NPC_ENTRY (gaNpcIndex_00726C48[nIndex])
    if (bAdd)
    {
        for (int i = 0; i < NPC_ENTRY.nCount; ++i)
        {
            if (NPC_ENTRY.apfHandlers[i] == sub_004B1DD0_OpenTimedDialog62)
            {
                return 1;
            }
        }

        for (int i = 0; i < NPC_ENTRY.nCount; ++i)
        {
            if (NPC_ENTRY.apfHandlers[i] == sub_004B5C60_Handler)
            {
                for (int j = NPC_ENTRY.nCount - 1; j >= i; --j)
                {
                    NPC_ENTRY.apfHandlers[j + 1] = NPC_ENTRY.apfHandlers[j];
                    NPC_ENTRY.awIds[j + 1] = NPC_ENTRY.awIds[j];
                }
                ++NPC_ENTRY.nCount;
                NPC_ENTRY.apfHandlers[i] = sub_004B1DD0_OpenTimedDialog62;
                NPC_ENTRY.awIds[i] = 0x1507;
                return 1;
            }
        }

        const int nPos = NPC_ENTRY.nCount - 1;
        for (int j = NPC_ENTRY.nCount - 1; j >= nPos; --j)
        {
            NPC_ENTRY.apfHandlers[j + 1] = NPC_ENTRY.apfHandlers[j];
            NPC_ENTRY.awIds[j + 1] = NPC_ENTRY.awIds[j];
        }
        ++NPC_ENTRY.nCount;
        NPC_ENTRY.apfHandlers[nPos] = sub_004B1DD0_OpenTimedDialog62;
        NPC_ENTRY.awIds[nPos] = 0x1507;
        return 1;
    }
    else
    {
    for (int i = 0; i < (NPC_ENTRY.nCount); ++i)
    {
        if (NPC_ENTRY.apfHandlers[i] == sub_004B1DD0_OpenTimedDialog62)
        {
            for (int j = i; j < NPC_ENTRY.nCount - 1; ++j)
            {
                NPC_ENTRY.apfHandlers[j] = NPC_ENTRY.apfHandlers[j + 1];
                NPC_ENTRY.awIds[j] = NPC_ENTRY.awIds[j + 1];
            }
            --NPC_ENTRY.nCount;
            return 1;
        }
    }
    }
    return 1;
}
#undef NPC_ENTRY

static void __stdcall sub_004B66B0_OpenNpcInteract(D2UnitStrc* pUnit, int bReopen)
{
    sub_0044DA40();
    if (!pUnit)
    {
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return;
    }

    gnGlobal_007C0C6B = 1;
    gnGlobal_007C0D31 = 0;
    gnGlobal_007C0C73 = STATLIST_UnitGetStatValue(sub_00463DD0(), 0xE, 0);
    sub_00456300(0, 0);

    if (!bReopen)
    {
        if (pUnit == (gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0))
        {
            return;
        }
        if (gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0)
        {
            sub_004B3DE0_CloseNpc();
            return;
        }
    }
    else
    {
        gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
    }

    gnGlobal_007C0D29 = 1;
    gnGlobal_007C0D25 = pUnit->dwUnitId;
    gdwGlobal_007C0D2D = pUnit->dwClassId;
    pUnit->dwFlags &= ~2;

    const int nNpcId = pUnit->dwClassId;
    sub_004B19A0_RunNpcQuestHandlers(nNpcId, gpQuestFlags_007C0D43, gaNpcHandlers_007253E0, gnHandlerCount_007253DC);

    if (gnNpcSoundActive_007C0DB4)
    {
        if (gnNpcSoundHandle_007C0DB8)
        {
            sub_004BA840(gnNpcSoundHandle_007C0DB8);
            gnNpcSoundHandle_007C0DB8 = 0;
        }
        gnNpcSoundActive_007C0DB4 = 0;
    }

    switch (pUnit->dwClassId)
    {
    case 0x96:
        if (STATLIST_UnitGetStatValue(sub_00463DD0(), 0xC, 0) >= 8)
        {
            sub_004B6410_InitHandler();
        }
        sub_004B6440_ToggleNpcHandler(gwGlobal_00725494 != 0xFFFF, 0xB);
        break;

    case 0xC6:
        sub_004B6440_ToggleNpcHandler(gwGlobal_00725494 != 0xFFFF, 8);
        break;

    case 0xFC:
        sub_004B6440_ToggleNpcHandler(gwGlobal_00725494 != 0xFFFF, 0x18);
        break;

    case 0x16F:
        sub_004B6440_ToggleNpcHandler(gwGlobal_00725494 != 0xFFFF, 0x15);
        break;

    case 0x203:
        sub_004B6440_ToggleNpcHandler(gwGlobal_00725494 != 0xFFFF, 0x2B);
        break;
    }

    if (!sub_00455F20(8, 0, 0))
    {
        gnGlobal_007C0C6B = 0;
        pUnit->dwFlags |= 2;
        sub_004786A0_SendIntInt(0x30, 1, pUnit->dwUnitId);
        gnGlobal_007C0D29 = 0;
        sub_004B3830_ClearNpcInventoryAndSound(pUnit->dwUnitId);
        return;
    }

    sub_004B4830_Rebuild();
    if (bReopen)
    {
        return;
    }

    int nType = 0;
    for (int i = 0; i < gnNpcEntryCount_0072554C; ++i)
    {
        if (gaNpcEntries_00726850[i].nId == nNpcId)
        {
            if (gaNpcEntries_00726850[i].bFlag == 1)
            {
                gaNpcEntries_00726850[i].bFlag = 0;
                nType = 2;
            }
            if (gaNpcEntries_00726850[i].bRefreshed != 1)
            {
                return;
            }
            gaNpcEntries_00726850[i].bRefreshed = 0;
            break;
        }
    }

    const int nSound = sub_004E0590_PickNpcSound(pUnit, nType);
    if (!nSound)
    {
        return;
    }

    sub_004CB190_ReleaseSkillSfx(pUnit);
    gnNpcSoundHandle_007C0DB8 = sub_004B9A00(nSound, sub_00463DD0(), 0, 1, 0);
    if (nType == 2)
    {
        sub_004785B0_SendPacket3(0x4D, nNpcId);
        gnNpcSoundActive_007C0DB4 = 1;
        return;
    }
    gnNpcSoundHandle_007C0DB8 = 0;
}

void __fastcall sub_004B6980_SetNpcMenuState(unsigned short wValue, int nValue)
{
    gwGlobal_00725494 = wValue;
    gnGlobal_007C0DD0 = nValue;
    if (wValue == 0xFFFF)
    {
        sub_004B6440_ToggleNpcHandler(0, 0xB);
        sub_004B6440_ToggleNpcHandler(0, 8);
        sub_004B6440_ToggleNpcHandler(0, 0x18);
        sub_004B6440_ToggleNpcHandler(0, 0x15);
        sub_004B6440_ToggleNpcHandler(0, 0x2B);
    }
}

int __fastcall sub_004B6A30_NpcTextCallback(void* pContext, int nArg, int nValue)
{
    gwGlobal_007C0C79 = sub_004B1830_GetFreeStringId(gwGlobal_007C0C77);
    if (gwGlobal_007C0C77 == 0x251)
    {
        sub_004B9A00(0xF1, 0, 0, 0, 0);
    }
    if (gwGlobal_007C0C77 == 0x21A)
    {
        sub_004B9A00(0xED, 0, 0, 0, 0);
    }

    if (gbGlobal_007C0C69 == 1)
    {
        if (gwGlobal_007C0C79 != 0xFFFF && (gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0))
        {
            gwGlobal_007C0C7B = gwGlobal_007C0C79;
            sub_004A10E0(gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0, gwGlobal_007C0C7B, 1);
            sub_004B1980_AddUsedString(gwGlobal_007C0C7B);
            sub_0049E7E0_SetTextCallback(sub_004B6A30_NpcTextCallback, 0);
            gwGlobal_007C0C77 = gwGlobal_007C0C7B;
            sub_004786A0_SendIntInt(0x31, gnGlobal_007C0D25, gwGlobal_007C0C7B);
            gwGlobal_007C0C79 = sub_004B1830_GetFreeStringId(gwGlobal_007C0C7B);
            return 1;
        }

        gbGlobal_007C0C69 = 0;
        sub_0049E7E0_SetTextCallback(0, 0);
        const int nIndex = sub_004B2E30_FindNpcIndex(gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0);
        if ((!nArg || !nValue) && !sub_004B1A10_IsSpecialNpc(gdwGlobal_007C0D2D) && nIndex >= 0 && sub_004B1620_GetInteractNpc()
            && nIndex < gnNpcIndexCount_00725A74 && gaNpcIndex_00726C48[nIndex].bEnabled)
        {
            gnGlobal_007C0C6B = 1;
            if (sub_004B1620_GetInteractNpc())
            {
                sub_004B66B0_OpenNpcInteract(sub_004B1620_GetInteractNpc(), 1);
                return 1;
            }
            sub_004B3DE0_CloseNpc();
            return 0;
        }

        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return 0;
    }

    gbGlobal_007C0C69 = 0;
    sub_0049E7E0_SetTextCallback(0, pContext);
    gwGlobal_007C0C77 = 0xFFFF;
    sub_004B4DB0_OpenGreetingDialog();
    return 0;
}

void __fastcall sub_004B6DD0_NpcInteractPacket(unsigned char nUnitType, int nUnitId, unsigned char* pBuffer, unsigned char nArg)
{
    if (nUnitType == 6)
    {
        QUESTRECORD_CopyBufferToRecord(gpQuestFlags_007C0D43, pBuffer, 0x60, 0);
        return;
    }

    D2UnitStrc* pUnit = sub_00463990(nUnitId, nUnitType);
    if (!pUnit)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        if (pPlayer && pPlayer->dwUnitType == 0 && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nState = 0;
            pPlayer->pPlayerData->nMode = 0;
            pPlayer->pPlayerData->nArg1 = 0;
            pPlayer->pPlayerData->nArg2 = 0;
        }
        sub_004786A0_SendIntInt(0x30, nArg, nUnitId);
        sub_004B3830_ClearNpcInventoryAndSound(nUnitId);
        return;
    }

    sub_00464990(sub_004B2390_CheckMonStatsFlag);
    pUnit->dwFlags |= 2;
    QUESTRECORD_CopyBufferToRecord(gpQuestFlags_007C0D43, pBuffer, 0x60, 0);
    sub_004B2250_ResetHandlers();
    sub_004786A0_SendIntInt(0x2F, nUnitType, nUnitId);
    sub_0044DA40();

    if (gaGlobal_007C0C68[0])
    {
        gbGlobal_007C0C69 = 1;
        sub_004B1640_SetNpcInteract(pUnit);
        pUnit->dwFlags &= ~2;
        return;
    }

    D2TextHeaderStrc* pTextHeader = sub_0049F900();
    D2_ASSERT(pTextHeader, 0x1060);

    const unsigned short wString = sub_00661400(pTextHeader, 0);
    const int nClassId = pUnit->dwClassId;
    if (sub_00457490_CheckMonStatsFlag(nClassId, 9) && nClassId != 0x219 && nClassId != 0x21A && nClassId != 0x21B
        && nClassId != 0x20F)
    {
        sub_00464420_TurnTowardPlayer(pUnit);
    }

    if (INVENTORY_GetCursorItem(sub_00463DD0()->pInventory))
    {
        gnGlobal_007C0D29 = 1;
        gnGlobal_007C0D25 = pUnit->dwUnitId;
        gdwGlobal_007C0D2D = pUnit->dwClassId;
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return;
    }

    gtStringList_007C0D9A.wCount = 0;
    if (wString != 0xFFFF)
    {
        sub_00456300(0, 0);
        gwGlobal_007C0C77 = wString;
        sub_004A10E0(pUnit, wString, 1);
        sub_004B1980_AddUsedString(wString);
        gwGlobal_007C0C79 = sub_004B1830_GetFreeStringId(wString);
        sub_004786A0_SendIntInt(0x31, pUnit->dwUnitId, wString);
        gbGlobal_007C0C69 = 1;
        sub_0049E7E0_SetTextCallback(sub_004B6A30_NpcTextCallback, 0);
        sub_004B1640_SetNpcInteract(pUnit);
    }
    else
    {
        const unsigned short wString2 = sub_00661440(pTextHeader, 0);
        if (pUnit->dwClassId != 0x20F)
        {
            sub_004644E0_PlayerFaceUnit(pUnit);
        }
        if (pUnit->pDynamicPath)
        {
            D2Common_10153(pUnit->pDynamicPath);
        }

        if (wString2 != 0xFFFF)
        {
            sub_00487990_ResetHover();
            sub_00456300(0, 0);
            gwGlobal_007C0C77 = wString2;
            gwGlobal_007C0C79 = sub_004B1830_GetFreeStringId(wString2);
            sub_004B4FD0(pUnit);
        }
        else
        {
            const int nClass = pUnit->dwClassId;
            if (sub_00457490_CheckMonStatsFlag(nClass, 9))
            {
                if (sub_004B1A10_IsSpecialNpc(nClass))
                {
                    gnGlobal_007C0D29 = 1;
                    gnGlobal_007C0D25 = pUnit->dwUnitId;
                    gdwGlobal_007C0D2D = pUnit->dwClassId;
                    sub_004B3C20(gnGlobal_007C0D25);
                    sub_00455F20(8, 1, 0);
                    return;
                }
                sub_00487990_ResetHover();
                sub_00456300(0, 0);
                sub_004B66B0_OpenNpcInteract(pUnit, 0);
            }
            else
            {
                sub_004B3C20(gnGlobal_007C0D25);
                sub_00455F20(8, 1, 0);
            }
        }
    }
    gdwGlobal_007C0DB0 = 0;
}
