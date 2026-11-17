#include "D2Client.h"

struct D2RosterSlotStrc;
struct D2RosterUnitStrc;
struct D2PacketRecord21Strc;
struct D2WaypointMenuEntryStrc;
struct D2WaypointRowRectStrc;

struct D2RosterSlotStrc
{
    int bFlag;
    int nX;
    int nY;
    int unk0x0C;
    int nCount;
    int nType;
    int nState;
    int bActive;
};

#pragma pack(push, 1)
struct D2RosterUnitStrc
{
    D2RosterSlotStrc f_0[5];
    char unkA0[0x25];
    int nId;
    char unkC9[4];
    D2RosterUnitStrc* pNext;
};

#pragma pack(pop)
struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    int lParam;
    unsigned int nNotifyCode;
    void* pExtra;
    int bReturn;
    int lResult;
};

int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry); // 0x004795A0
int __fastcall sub_00479B90(D2StoredUnitRecordStrc* pEntry); // 0x00479B90
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern D2RosterUnitStrc* gpRosterUnits_007BF014; // 0x007BF014
extern int gnWaypointSelected_007BF06D; // 0x007BF06D

struct D2PacketRecord21Strc
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char pWaypointData[16];
};
int __cdecl sub_0044DCC0(); // 0x0044DCC0
D2BitBufferStrc* __cdecl sub_004B32D0(); // 0x004B32D0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
void __cdecl sub_0049C7F0_BuildWaypointList(); // 0x0049C7F0
int __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
void __cdecl sub_0044DA40(); // 0x0044DA40
int __cdecl sub_0047F210_IsMouseInSlots(); // 0x0047F210
void __cdecl sub_0049C6C0_SendWaypointClose(); // 0x0049C6C0
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2); // 0x004786A0
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
extern D2WaypointRowRectStrc gaWaypointRowRects_007224F8[9]; // 0x007224F8
extern D2WaypointMenuEntryStrc gaWaypointEntries_007BF03C[9]; // 0x007BF03C
extern bool gbWaypointButton_007BF06C; // 0x007BF06C
extern char gbGlobal_007BF085; // 0x007BF085
extern int gnGlobal_00711470; // 0x00711470

// 0x0049BB40
static __forceinline void sub_0049BB40_SetSlotCount(D2RosterUnitStrc* pRow, int nSlot)
{
    if (pRow->f_0[nSlot].nState != 1)
        pRow->f_0[nSlot].nCount = 1;
}

void __fastcall sub_M110_Emit_0049BB40(D2RosterUnitStrc* pRow, int nSlot)
{
    sub_0049BB40_SetSlotCount(pRow, nSlot + 1);
}

int gnGlobal_007BF030; // 0x007BF030

int gbRosterMode_007BF038; // 0x007BF038

static __forceinline int sub_M165_InSlot(int nSlotX, int nSlotY, int nWidth)
{
    const int nCursorX = sub_00468730();
    const int nCursorY = sub_00468740();
    return nCursorX >= gnGlobal_007A2858 + nSlotX && nCursorX <= gnGlobal_007A2858 + nSlotX + nWidth && nCursorY >= nSlotY - gnGlobal_007A285C - 0x14 && nCursorY <= nSlotY - gnGlobal_007A285C;
}

// 0x0049BB60
void __stdcall sub_0049BB60_OnRosterMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = sub_00468730();
    D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(0);
    pEntry = sub_004795A0_GetNextEntry(pEntry);
    D2RosterUnitStrc* pRow = gpRosterUnits_007BF014;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nCursorX = sub_00468730();
    int nCursorY = sub_00468740();
    if (nCursorX >= gnGlobal_007A2858 + 0x116 && nCursorX <= gnGlobal_007A2858 + 0x136 && nCursorY >= 0x185 - gnGlobal_007A285C && nCursorY <= 0x1A5 - gnGlobal_007A285C)
    {
        gnGlobal_007BF030 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    if (nX < gnGlobal_0071146C / 2)
    {
        while (pRow)
        {
            for (int i = 0; i < 5; ++i)
            {
                if (!pRow->f_0[i].bFlag)
                {
                    if (sub_M165_InSlot(pRow->f_0[i].nX, pRow->f_0[i].nY, 0x14))
                    {
                        if (pRow->f_0[i].nType == 1 && sub_00479B90(sub_004795A0_GetNextEntry(0)) < 9)
                        {
                            pMsg->bReturn = 1;
                            pMsg->lResult = 0;
                            sub_00420290_BreakHandlerChain(pMsg);
                            return;
                        }

                        if (pRow->f_0[i].nType == 1)
                        {
                            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
                            if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
                                continue;
                        }

                        const int nCount = pRow->f_0[i].nCount;
                        if (pRow->f_0[i].bActive)
                            continue;
                        pRow->f_0[i].nCount = nCount + 1;
                        pRow->f_0[i].bActive = 1;
                        gbRosterMode_007BF038 = 1;

                        pMsg->bReturn = 1;
                        pMsg->lResult = 0;
                        sub_00420290_BreakHandlerChain(pMsg);
                        return;
                    }
                }
                else if (sub_M165_InSlot(pRow->f_0[i].nX, pRow->f_0[i].nY, 0x35))
                {
                    if (pRow->f_0[i].nState != 1)
                        pRow->f_0[i].nCount = 1;
                    pRow->f_0[i].bActive = 1;
                    gbRosterMode_007BF038 = 1;
                    pMsg->bReturn = 1;
                    pMsg->lResult = 0;
                    sub_00420290_BreakHandlerChain(pMsg);
                    return;
                }
            }

            pRow = pRow->pNext;
            if (pEntry)
                pEntry = sub_004795A0_GetNextEntry(pEntry);
        }

        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    pMsg->bReturn = 0;
}

char gbGlobal_007BF06C; // 0x007BF06C

// 0x0049C470
static __forceinline bool sub_0049C470_IsPointInRect(int nX, int nY)
{
    if (nX >= 0x111 && nX <= 0x134 && nY >= 0x183 && nY <= 0x1A4)
        return true;
    return false;
}

int __stdcall sub_M113_Emit_0049C470(int nX, int nY)
{
    return sub_0049C470_IsPointInRect(nX, nY) ? 3 : 7;
}

// 0x0049C560
void __cdecl sub_0049C560_ResetSelection()
{
    gbGlobal_007BF06C = 0;
    gnWaypointSelected_007BF06D = -1;
}

// 0x0049C490
static int sub_0049C490_GetActTabAtPoint(int nX, int nY)
{
    if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
    {
        if (nY > 0x1E || nX > 0x140)
            return -1;
        if (nX < 0x40)
            return 0;
        if (nX < 0x80)
            return 1;
        if (nX < 0xC0)
            return 2;
        if (nX < 0x100)
            return 3;
        return 4;
    }

    if (nY > 0x1E || nX > 0x140)
        return -1;
    if (nX < 0x50)
        return 0;
    if (nX < 0xA0)
        return 1;
    if (nX < 0xF0)
        return 2;
    return 3;
}

// 0x0049C510
static int sub_0049C510_GetWaypointRowAtPoint(int nX, int nY)
{
    for (int i = 0; i < 9; ++i)
    {
        if (gaWaypointEntries_007BF03C[i].bEnabled && nX > gaWaypointRowRects_007224F8[i].nX && nX < gaWaypointRowRects_007224F8[i].nX + 0x118
            && nY > gaWaypointRowRects_007224F8[i].nY && nY < gaWaypointRowRects_007224F8[i].nY + 0x1E)
            return i;
    }
    return -1;
}

// 0x0049C760
static void sub_0049C760_SetWaypointAct(int nAct)
{
    if (nAct >= gnWaypointActCount_007224E4)
        nAct = 0;

    switch (nAct)
    {
    case 4:
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 0x1C, 0))
            nAct = 3;
    case 3:
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 0x17, 0))
            nAct = 2;
    case 2:
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 0xF, 0))
            nAct = 1;
    case 1:
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 7, 0))
            nAct = 0;
    }

    gnWaypointAct_007BF086 = nAct;
}

// 0x0049C980
void __cdecl sub_0049C980_UpdateWaypointAct()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
        if (pRoom)
        {
            const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
            if (nLevelId)
            {
                sub_0049C760_SetWaypointAct(DRLG_GetActNoFromLevelId(nLevelId));
                sub_0049C7F0_BuildWaypointList();
                return;
            }
        }
    }

    gnWaypointAct_007BF086 = 0;
    sub_0049C7F0_BuildWaypointList();
}

// 0x0049CF90
void __fastcall sub_0049CF90(D2PacketRecord21Strc* pPacket)
{
    if (sub_00455F20(0x14, 0, 1) == 1)
    {
        sub_0044DA40();
        sub_0049C980_UpdateWaypointAct();
        gnGlobal_007BF07D = *(int*)pPacket->nUnitGUID;
        WAYPOINTS_CopyAndValidateWaypointData(gpWaypointData_007BF081, pPacket->pWaypointData);
        gbGlobal_007BF085 = 0;
        sub_0049C7F0_BuildWaypointList();
    }
}

void __stdcall sub_0049D010_WaypointMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (sub_0047F210_IsMouseInSlots())
        return;

    if (nX <= gnGlobal_0071146C && nY <= gnGlobal_00711470 - 0x31)
    {
        nX -= gnGlobal_007A2858;
        nY += gnGlobal_007A285C;
        if (gbWaypointButton_007BF06C)
        {
            if (nX >= 0x111 && nX <= 0x111 + 0x23 && nY >= 0x183 && nY <= 0x183 + 0x21)
            {
                sub_00455F20(0x14, 1, 0);
                sub_0049C6C0_SendWaypointClose();
            }
        }
        else if (gnWaypointSelected_007BF06D != -1 && gnWaypointSelected_007BF06D == sub_0049C510_GetWaypointRowAtPoint(nX, nY))
        {
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
            sub_004786A0_SendIntInt(0x49, gnGlobal_007BF07D, *(int*)gaWaypointEntries_007BF03C[gnWaypointSelected_007BF06D].nLevelId);
            gbGlobal_007BF085 = 1;
            sub_0049C6C0_SendWaypointClose();
            gbWaypointButton_007BF06C = false;
            gnWaypointSelected_007BF06D = -1;
            sub_00455F20(0x14, 1, 0);
            sub_004B9A00(0x8B7, 0, 0, 0, 0);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
            return;
        }

        gbWaypointButton_007BF06C = false;
        gnWaypointSelected_007BF06D = -1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
    else
    {
        gbWaypointButton_007BF06C = false;
        gnWaypointSelected_007BF06D = -1;
    }
}

// 0x0049D160
void __stdcall sub_0049D160_WaypointMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (sub_0047F210_IsMouseInSlots())
        return;

    if (nX > gnGlobal_0071146C / 2 || nY > gnGlobal_00711470 - 0x31)
    {
        if (!gbGlobal_007BF085 && sub_00463DD0_GetPlayerUnit() && UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()))
        {
            sub_004786A0_SendIntInt(0x49, gnGlobal_007BF07D, 0);
            gbGlobal_007BF085 = 1;
        }
        sub_00455F20(0x14, 1, 1);
        return;
    }

    nX -= gnGlobal_007A2858;
    nY += gnGlobal_007A285C;
    const int nTab = sub_0049C490_GetActTabAtPoint(nX, nY);
    if (nTab != -1)
    {
        if (nTab != gnWaypointAct_007BF086)
            sub_004B9A00(6, 0, 0, 0, 0);
        sub_0049C760_SetWaypointAct(nTab);
        sub_0049C7F0_BuildWaypointList();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }

    gnWaypointSelected_007BF06D = -1;
    if (nX >= 0x111 && nX <= 0x111 + 0x23 && nY >= 0x183 && nY <= 0x183 + 0x21)
    {
        gbWaypointButton_007BF06C = true;
        sub_004B9A00(4, 0, 0, 0, 0);
    }
    else
    {
        gnWaypointSelected_007BF06D = sub_0049C510_GetWaypointRowAtPoint(nX, nY);
        if (gnWaypointSelected_007BF06D != -1)
            sub_004B9A00(4, 0, 0, 0, 0);
    }

    if ((unsigned short)pMsg->lParam > gnGlobal_0071146C || (unsigned short)((unsigned int)pMsg->lParam >> 16) > gnGlobal_00711470 - 0x31)
        return;

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

#include "gen/data/Source/D2Client/Unknown_0049BB40.inc"
