extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

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

struct D2ClientNotifyStrc
{
    char unk0x00[0x14];
    void (__fastcall* pfnSendCommand)(const char* szText);
};

int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry);               // 0x004795A0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __cdecl sub_0044DA70();                                                                                // 0x0044DA70
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                            // 0x00420290
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                       // 0x00479BC0
int __stdcall sub_0049AA50_IsMouseInRect(int nX, int nY, int nWidth, int nHeight);                          // 0x0049AA50
void __cdecl sub_00479FC0();                                                                                // 0x00479FC0
int __fastcall sub_00479B90(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479B90
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
void __fastcall sub_00479FE0(D2StoredUnitRecordStrc* pEntry);                                               // 0x00479FE0
int __fastcall sub_00479CE0(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479CE0
int __cdecl sub_0044B850_IsHardcore();                                                                      // 0x0044B850
void __fastcall sub_00479DA0(D2StoredUnitRecordStrc* pEntry);                                               // 0x00479DA0
int __fastcall sub_00479C20(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479C20
void __fastcall sub_00479DE0(D2StoredUnitRecordStrc* pEntry);                                               // 0x00479DE0
int __fastcall sub_00479C60(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479C60
void __fastcall sub_00479E20(D2StoredUnitRecordStrc* pEntry);                                               // 0x00479E20
int __fastcall sub_00479CA0(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479CA0
const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry);                           // 0x004795C0
void __fastcall sub_00479EB0(D2StoredUnitRecordStrc* pEntry);                                               // 0x00479EB0
int __fastcall sub_00479D20(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479D20
D2ClientNotifyStrc* __cdecl sub_0044B7B0_GetNotify();                                                       // 0x0044B7B0

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern D2RosterUnitStrc* gpRosterUnits_007BF014;                                                            // 0x007BF014
extern int gnGlobal_007BF030;                                                                               // 0x007BF030
extern int gbRosterMode_007BF038;                                                                           // 0x007BF038

// 0x0049B990
static int sub_0049B990_DoRosterButtonAction(D2StoredUnitRecordStrc* pEntry, int nType)
{
    int nResult = 0;
    switch (nType)
    {
    case 1:
        sub_00479FE0(pEntry);
        nResult = sub_00479CE0(pEntry);
        break;
    case 2:
        if (!sub_0044B850_IsHardcore())
            break;
        sub_00479DA0(pEntry);
        nResult = sub_00479C20(pEntry);
        break;
    case 3:
        sub_00479DE0(pEntry);
        nResult = sub_00479C60(pEntry);
        break;
    case 4:
    {
        sub_00479E20(pEntry);
        nResult = sub_00479CA0(pEntry);
        D2ClientNotifyStrc* pNotify = sub_0044B7B0_GetNotify();
        if (pNotify)
        {
            char szText[0x200];
            if (nResult)
                strcpy(szText, "/squelch ");
            else
                strcpy(szText, "/unsquelch ");
            strcat(szText, sub_004795C0_GetEntryName(pEntry));
            pNotify->pfnSendCommand(szText);
        }
        break;
    }
    }
    return nResult;
}

// 0x0049BAD0
static void sub_0049BAD0_SetRosterButtonState(D2RosterUnitStrc* pRow, int nSlot, D2StoredUnitRecordStrc* pEntry)
{
    if (pRow->f_0[nSlot].nState == 1)
        return;

    const int nId = pRow->nId;
    sub_00479EB0(pEntry);
    const int nState = sub_00479D20(pEntry);
    D2RosterUnitStrc* pFound = gpRosterUnits_007BF014;
    while (pFound && pFound->nId != nId)
        pFound = pFound->pNext;
    D2_ASSERT(pFound, 0x4E3);
    pFound->f_0[nSlot].nState = nState;
}

// 0x0049BDD0
void __stdcall sub_0049BDD0_OnRosterClick(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = sub_00468730();
    D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(0);
    D2RosterUnitStrc* pRow = gpRosterUnits_007BF014;
    gnGlobal_007BF030 = 0;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (nX < gnGlobal_0071146C / 2)
    {
        nX = sub_00468730();
        int nY = sub_00468740();
        if (nX >= gnGlobal_007A2858 + 0x116 && nX <= gnGlobal_007A2858 + 0x136 && nY >= 0x185 - gnGlobal_007A285C && nY <= 0x1A5 - gnGlobal_007A285C)
        {
            sub_00455F20(0x16, 1, 0);
            sub_0044DA70();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
            return;
        }

        if (sub_0049AA50_IsMouseInRect(0xE3, 0x23, 0x35, 0xB) && sub_00479BC0_GetEntryIndex(pEntry) != 0xFFFF)
        {
            sub_00479FC0();
        }
        else if (gbRosterMode_007BF038)
        {
            pEntry = sub_004795A0_GetNextEntry(pEntry);
            if (pEntry)
            {
            do
            {
                if (!pRow)
                    break;
                for (int i = 0; i < 5; i++)
                {
                    D2RosterSlotStrc* pSlot = &pRow->f_0[i];
                    if (!pSlot->bFlag)
                    {
                        const int nSlotX = pSlot->nX;
                        const int nSlotY = pSlot->nY;
                        nX = sub_00468730();
                        nY = sub_00468740();
                        if (nX >= gnGlobal_007A2858 + nSlotX && nX <= gnGlobal_007A2858 + nSlotX + 0x14 && nY >= nSlotY - gnGlobal_007A285C - 0x14 && nY <= nSlotY - gnGlobal_007A285C)
                        {
                            if (pSlot->nType == 1 && sub_00479B90(sub_004795A0_GetNextEntry(0)) < 9)
                            {
                                pMsg->bReturn = 1;
                                goto result;
                            }
                            if (pSlot->nType == 1)
                            {
                                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
                                if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
                                    continue;
                            }
                            const int bDone = sub_0049B990_DoRosterButtonAction(pEntry, pSlot->nType);
                            int nCount = pSlot->nCount;
                            if (bDone)
                            {
                                nCount += 2;
                                pSlot->nCount = nCount;
                            }
                            else
                            {
                                pSlot->nCount = nCount;
                            }
                        }
                    }
                    else
                    {
                        const int nSlotX = pSlot->nX;
                        const int nSlotY = pSlot->nY;
                        nX = sub_00468730();
                        nY = sub_00468740();
                        if (nX >= gnGlobal_007A2858 + nSlotX && nX <= gnGlobal_007A2858 + nSlotX + 0x35 && nY >= nSlotY - gnGlobal_007A285C - 0x14 && nY <= nSlotY - gnGlobal_007A285C)
                        {
                            sub_0049BAD0_SetRosterButtonState(pRow, i, pEntry);
                            goto done;
                        }
                    }
                }
                pRow = pRow->pNext;
                pEntry = sub_004795A0_GetNextEntry(pEntry);
            } while (pEntry);
            }
            gbRosterMode_007BF038 = 0;
        }
        else
        {
            for (; pRow; pRow = pRow->pNext)
            {
                for (int i = 0; i < 5; i++)
                {
                    if (pRow->f_0[i].bActive)
                    {
                        pRow->f_0[i].nCount--;
                        pRow->f_0[i].bActive = 0;
                    }
                }
            }
        }
done:
        sub_0044DA70();
        pMsg->bReturn = 1;
result:
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        return;
    }
    pMsg->bReturn = 0;
}
