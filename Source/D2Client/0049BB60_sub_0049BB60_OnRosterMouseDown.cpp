struct D2StoredUnitRecordStrc;
struct D2UnitStrc;
struct D2ActiveRoomStrc;

struct SMSGHANDLER_PARAMS
{
    char unk0x00[0x18];
    int bReturn;
    int lResult;
};

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
    char unk0xA0[0x25];
    int nId;
    char unk0xC9[4];
    D2RosterUnitStrc* pNext;
};
#pragma pack(pop)

int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry);               // 0x004795A0
int __fastcall sub_00479B90(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479B90
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                           // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern D2RosterUnitStrc* gpRosterUnits_007BF014;                                                            // 0x007BF014
int gnGlobal_007BF030;                                                                                      // 0x007BF030
int gbRosterMode_007BF038;                                                                                  // 0x007BF038

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
