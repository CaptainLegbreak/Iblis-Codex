struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct Unicode
{
    unsigned short wChar;
};

struct D2InventoryStrc;
struct D2SkillStrc;

struct D2MonsterDataStrc
{
    char unk0x00[0x3C];
    int nUnk0x3C;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x48];
    D2InventoryStrc* pInventory;
};

struct D2ClientNotifyStrc
{
    char unk0x00[0x90];
    void (__cdecl* pfnNotify)();
};

struct D2ClientNodeStrc
{
    char unk0x00[0x08];
    int nId;
    char unk0x0C[0x08];
    int nValueA;
    int nValueB;
    char unk0x1C[0x14];
    D2ClientNodeStrc* pNext;
};

struct D2RosterSubStrc
{
    int nUnk0x00;
    D2RosterSubStrc* pNext;
};

struct D2RosterEntryStrc
{
    char unk0x00[0x34];
    void* pResource;
    D2RosterSubStrc* pSubList;
    char unk0x3C[0x44];
    D2RosterEntryStrc* pNext;
};

struct D2RC4Strc
{
    unsigned char S[0x100];
    unsigned char i;
    unsigned char j;

    void sub_0047F8C0_Crypt(unsigned char* pData, unsigned int nSize);
};

struct _FILETIME
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2ClientServiceStrc
{
    char unk0x00[0xD0];
    int (__fastcall* pfnCall)(int nArg1, int nArg2, int nArg3, _FILETIME* pTime, int nArg5, int nArg6);
};

struct D2ClientSlotObjStrc
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2(int nArg1, int nArg2, int* pOut);
};

struct D2ClientSlotHolderStrc
{
    char unk0x00[0x0C];
    D2ClientSlotObjStrc* pObj;
};

struct D2ClientRecordStrc
{
    unsigned char nId;
    unsigned char nType;
    unsigned char nFlag;
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_5;
    unsigned char nValue3;
    unsigned char nUnk0x07;
    int nUnk0x08;
    int f_C;
    int f_10;
    int nUnk0x14;
    int nUnk0x18;
    int nUnk0x1C;
    int nUnk0x20;
    int nUnk0x24;
};

struct D2ClientStringListStrc
{
    Unicode* pStrings[6];
    unsigned short nCount;
    unsigned char f_1A[4];
    unsigned char unk0x1E[8];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall GetSystemTimeAsFileTime(_FILETIME* pTime);                  // 0x006CC358
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00420290
D2ClientNotifyStrc* __cdecl sub_0044B7B0_GetNotify();                                                       // 0x0044B7B0
void __cdecl sub_0044DA70();                                                                                // 0x0044DA70
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar);                                                  // 0x00453A90
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00467A10();                                                             // 0x00467A10
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __cdecl sub_00468F00();                                                                                // 0x00468F00
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3);               // 0x00478600
void __cdecl sub_00480230();                                                                                // 0x00480230
void __cdecl sub_0048A050();                                                                                // 0x0048A050
void __cdecl sub_0048A730();                                                                                // 0x0048A730
void __cdecl sub_00494FC0();                                                                                // 0x00494FC0
void __fastcall sub_0049EB10_PostRecord(D2ClientRecordStrc* pRecord);                                       // 0x0049EB10
void __stdcall sub_004A1770(SMSGHANDLER_PARAMS* pMsg);                                                      // 0x004A1770
void __cdecl sub_004B8CB0();                                                                                // 0x004B8CB0
void __fastcall sub_004DC2B0(void* pResource);                                                              // 0x004DC2B0
int __cdecl D2GFX_GetResolutionMode();                                                                      // 0x004F5160
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0
int __stdcall sub_0052AE50_SendPacket(int nSize, int nFlags, void* pData);                                  // 0x0052AE50
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
void __stdcall SKILLS_SetSkillMode(D2SkillStrc* pSkill, int nMode);                                         // 0x00644340
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_00721E3C;                                                                               // 0x00721E3C
extern int gnGlobal_00721E40;                                                                               // 0x00721E40
extern int gnGlobal_00721E44;                                                                               // 0x00721E44
extern int gnGlobal_00721E48;                                                                               // 0x00721E48
extern int gnGlobal_00721E4C;                                                                               // 0x00721E4C
extern int gnGlobal_00721E50;                                                                               // 0x00721E50
extern int gdwGlobal_007A0610;                                                                              // 0x007A0610
extern int gdwGlobal_007A0618;                                                                              // 0x007A0618
extern int gdwGlobal_007A061C;                                                                              // 0x007A061C
extern int gdwGlobal_007A0620;                                                                              // 0x007A0620
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
int gnSentBytes_007A6AF8;                                                                                   // 0x007A6AF8
int gnSentPackets_007A6B00;                                                                                 // 0x007A6B00
extern D2ClientNodeStrc* gpNodeList_007BB5BC;                                                               // 0x007BB5BC
extern D2RosterEntryStrc* gpRosterListA_007BB5C0;                                                           // 0x007BB5C0
D2RosterEntryStrc* gpRosterListB_007BB5C4;                                                                  // 0x007BB5C4
extern int gdwGlobal_007BB5DC;                                                                              // 0x007BB5DC
extern unsigned char gnGlobal_007BB5E0;                                                                     // 0x007BB5E0
int gdwGlobal_007BB5EC;                                                                                     // 0x007BB5EC
extern short gwGlobal_007BB5F8;                                                                             // 0x007BB5F8
extern short gwGlobal_007BC850;                                                                             // 0x007BC850
extern D2ClientSlotHolderStrc* gpSlotHolder_007BC990;                                                       // 0x007BC990
D2ClientServiceStrc* gpService_007BC998;                                                                    // 0x007BC998
extern int gdwGlobal_007BCBE4;                                                                              // 0x007BCBE4
int gdwGlobal_007BCBE8;                                                                                     // 0x007BCBE8
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
extern int gdwGlobal_007BCBF4;                                                                              // 0x007BCBF4
int gdwGlobal_007BCBF8;                                                                                     // 0x007BCBF8
extern int gdwGlobal_007BCEA4;                                                                              // 0x007BCEA4
extern Unicode gwszName_007BCEA8[];                                                                         // 0x007BCEA8
int gdwGlobal_007BEEFC;                                                                                     // 0x007BEEFC
extern int gdwGlobal_007BF202;                                                                              // 0x007BF202
extern int gdwGlobal_007BF20A;                                                                              // 0x007BF20A
extern unsigned char gnGlobal_007BF23A;                                                                     // 0x007BF23A
extern int gdwGlobal_007BF23B;                                                                              // 0x007BF23B
extern int gdwGlobal_007BF23F;                                                                              // 0x007BF23F
extern int gnHotkeySkill_007C06C8[16];                                                                      // 0x007C06C8
extern int gnHotkeyOwner_007C0768[16];                                                                      // 0x007C0768
extern int gbHotkeyLeft_007C07B8[16];                                                                       // 0x007C07B8
extern unsigned char gaTable_007C0EA4[];                                                                    // 0x007C0EA4
extern int gdwTableInit_007C0ECC;                                                                           // 0x007C0ECC

// 0x00477EE0
void __cdecl sub_00477EE0_SendPacket69()
{
    unsigned char nHeader = 0x69;
    sub_0052AE50_SendPacket(1, 0, &nHeader);
    gnSentBytes_007A6AF8 += 1;
    gnSentPackets_007A6B00 += 1;
    if (gdwGlobal_007A0610 != 0 && gdwGlobal_007A0610 != 1 && gdwGlobal_007A0610 != 6 && gdwGlobal_007A0610 != 7
        && gdwGlobal_007A0610 != 8 && gdwGlobal_007A0610 != 9)
    {
        gdwGlobal_007A0620 = 1;
        gdwGlobal_007A061C = 0;
        gdwGlobal_007A0618 = 0;
    }
    if (gdwGlobal_007A0610 == 6 || gdwGlobal_007A0610 == 7)
    {
        D2ClientNotifyStrc* pNotify = sub_0044B7B0_GetNotify();
        if (pNotify)
            pNotify->pfnNotify();
    }
}

// 0x00478010
void __cdecl sub_00478010()
{
    unsigned char nHeader = 0x6A;
    sub_0052AE50_SendPacket(1, 0, &nHeader);
    gnSentBytes_007A6AF8 += 1;
    gnSentPackets_007A6B00 += 1;
}

// 0x004790B0
void __fastcall sub_004790B0_FindNodeValues(int nId, int* pValueA, int* pValueB)
{
    for (D2ClientNodeStrc* pNode = gpNodeList_007BB5BC; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nId)
        {
            *pValueA = pNode->nValueA;
            *pValueB = pNode->nValueB;
            return;
        }
    }
    *pValueA = 0;
    *pValueB = 0;
}

// 0x004794B0
void __cdecl sub_004794B0_FreeRosterLists()
{
    D2RosterEntryStrc* pEntry = gpRosterListA_007BB5C0;
    while (pEntry)
    {
        D2RosterEntryStrc* pNext = pEntry->pNext;
        sub_004DC2B0(pEntry->pResource);
        pEntry->pResource = 0;
        D2RosterSubStrc* pSub = pEntry->pSubList;
        while (pSub)
        {
            D2RosterSubStrc* pSubNext = pSub->pNext;
            FOG_Free(pSub, ".\\GAME\\Roster.cpp", 0x110, 0);
            pSub = pSubNext;
        }
        pEntry->pSubList = 0;
        FOG_Free(pEntry, ".\\GAME\\Roster.cpp", 0x14D, 0);
        pEntry = pNext;
    }
    gpRosterListA_007BB5C0 = 0;

    pEntry = gpRosterListB_007BB5C4;
    while (pEntry)
    {
        D2RosterEntryStrc* pNext = pEntry->pNext;
        sub_004DC2B0(pEntry->pResource);
        pEntry->pResource = 0;
        D2RosterSubStrc* pSub = pEntry->pSubList;
        while (pSub)
        {
            D2RosterSubStrc* pSubNext = pSub->pNext;
            FOG_Free(pSub, ".\\GAME\\Roster.cpp", 0x110, 0);
            pSub = pSubNext;
        }
        pEntry->pSubList = 0;
        FOG_Free(pEntry, ".\\GAME\\Roster.cpp", 0x159, 0);
        pEntry = pNext;
    }
    gpRosterListB_007BB5C4 = 0;
}

// 0x0047AD10
void __stdcall sub_0047AD10_ResetSelectionMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gwGlobal_007BC850 = 0;
    gwGlobal_007BB5F8 = 0;
    gdwGlobal_007BB5EC = -2;
    if (gdwGlobal_007BB5DC == 6)
        gnGlobal_007BB5E0 = 0;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0047B070
void __stdcall sub_0047B070_SetHandled(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x0047BC70
void __stdcall sub_0047BC70_LowClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->nYpos > gnGlobal_00711470 - 0x31)
        sub_00455F20(5, 1, 0);
}

// 0x0047F8C0
void D2RC4Strc::sub_0047F8C0_Crypt(unsigned char* pData, unsigned int nSize)
{
    for (unsigned int n = 0; n < nSize; ++n)
    {
        ++i;
        j += S[i];
        unsigned char* pA = &S[i];
        unsigned char* pB = &S[j];
        unsigned char t = *pA;
        *pA = *pB;
        *pB = t;
        pData[n] ^= S[(unsigned char)(S[j] + S[i])];
    }
}

// 0x0047FFB0
int __stdcall sub_0047FFB0_CallServiceWithTime(int nArg1, int nArg2, int nArg3)
{
    if (!gpService_007BC998)
        return 0;
    _FILETIME tTime;
    GetSystemTimeAsFileTime(&tTime);
    return gpService_007BC998->pfnCall(nArg1, nArg2, nArg3, &tTime, -1, -1);
}

// 0x004802E0
void __fastcall sub_004802E0_CallHolderSlot2(int nArg1, int nArg2)
{
    if (gpSlotHolder_007BC990)
    {
        int nOut = 0;
        gpSlotHolder_007BC990->pObj->Slot2(nArg1, nArg2, &nOut);
        sub_00480230();
    }
}

// 0x00488DF0
void __stdcall sub_00488DF0_HandledMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x00488EC0
void __stdcall sub_00488EC0_KeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if ((gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 3 || gdwGlobal_007BCBF0 == 4
        || gdwGlobal_007BCBF0 == 9) && !(pMsg->lParam & 0x40000000))
        sub_00468F00();
    pMsg->bReturn = 1;
    pMsg->lResult = 1;
    sub_00420290_HandleMsg(pMsg);
}

// 0x00489770
void __stdcall sub_00489770_HandledIfState11(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0xB)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x004897A0
void __stdcall sub_004897A0_HandledIfState11Ex(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0xB)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (!sub_00453A90_GetUIVarUnchecked(5))
            sub_004B8CB0();
    }
}

// 0x00489CE0
void __stdcall sub_00489CE0_HandledIfState12(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0xC)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (!sub_00453A90_GetUIVarUnchecked(5))
        {
            sub_00455F20(0x19, 1, 0);
            sub_00478600_SendShorts(0x4F, 0x12, 0, 0);
            gnGlobal_00721E3C = -1;
            gnGlobal_00721E40 = -1;
            gnGlobal_00721E44 = -1;
            gnGlobal_00721E48 = -1;
            gnGlobal_00721E4C = -1;
            gnGlobal_00721E50 = -1;
            gdwGlobal_007BCBE4 = 0;
            gdwGlobal_007BCBE8 = 0;
            gdwGlobal_007BCBF4 = 0;
            gdwGlobal_007BCBF8 = 0;
        }
    }
}

// 0x00489D70
void __stdcall sub_00489D70_KeyNoRepeatMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!(pMsg->lParam & 0x40000000))
        sub_00468F00();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0048A3B0
void __stdcall sub_0048A3B0_HandledIfState14(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0xE)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0048A3E0
void __stdcall sub_0048A3E0_HandledIfState14Ex(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0xE)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (!sub_004538D0(1))
        {
            gnGlobal_00721E3C = -1;
            gnGlobal_00721E40 = -1;
            gnGlobal_00721E44 = -1;
            gnGlobal_00721E48 = -1;
            gnGlobal_00721E4C = -1;
            gnGlobal_00721E50 = -1;
            gdwGlobal_007BCBE4 = 0;
            gdwGlobal_007BCBE8 = 0;
            gdwGlobal_007BCBF4 = 0;
            gdwGlobal_007BCBF8 = 0;
        }
        if (!sub_00453A90_GetUIVarUnchecked(5))
            sub_0048A050();
    }
}

// 0x0048A630
void __cdecl sub_0048A630_EnterState1()
{
    gdwGlobal_007BCBF0 = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
    D2ClientRecordStrc tRecord;
    tRecord.nId = 0x5A;
    tRecord.nFlag = 1;
    *(int*)&tRecord.nValue0 = 0;
    tRecord.nType = 0x0E;
    sub_0049EB10_PostRecord(&tRecord);
}

// 0x0048A790
int __stdcall sub_0048A790_IsCursorInRect(int nLeft, int nTop, int nRight, int nBottom)
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom)
        return 1;
    return 0;
}

// 0x0048BBE0
void __fastcall sub_0048BBE0_SetNameText(const Unicode* wszName, int nUnused, int nArg)
{
    sub_005267E0(gwszName_007BCEA8, wszName);
    gdwGlobal_007BCEA4 = nArg;
    sub_00455F20(0x25, 0, 0);
}

// 0x00492770
void __stdcall sub_00492770_KeyIfReadyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DCC0())
    {
        if (!(pMsg->lParam & 0x40000000) && !sub_00453A90_GetUIVarUnchecked(5))
            sub_0048A730();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x00496720
void __stdcall sub_00496720_ButtonReleaseMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (gdwGlobal_007BEEFC)
    {
        if (D2GFX_GetResolutionMode() == 2)
        {
            if (nX >= 0x2AD && nX <= 0x2CD && nY >= 0x18 && nY <= 0x38)
            {
                sub_00455F20(0x21, 2, 0);
                sub_00494FC0();
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }
        }
        else
        {
            if (nX >= 0x20D && nX <= 0x22D && nY >= 0x18 && nY <= 0x38)
            {
                sub_00455F20(0x21, 2, 0);
                sub_00494FC0();
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }
        }
    }
    gdwGlobal_007BEEFC = 0;
    sub_0044DA70();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0049DB10
D2ClientStringListStrc* __fastcall sub_0049DB10_CloneStringList(D2ClientStringListStrc* pSource)
{
    D2ClientStringListStrc* pCopy = (D2ClientStringListStrc*)FOG_Alloc(0x26, ".\\UI\\text.cpp", 0x9D0, 0);
    memset(pCopy, 0, 0x26);
    for (int i = 0; i < pSource->nCount; ++i)
    {
        pCopy->pStrings[i] = (Unicode*)FOG_Alloc((sub_00526800(pSource->pStrings[i]) + 1) * sizeof(Unicode), ".\\UI\\text.cpp", 0x9D4, 0);
        sub_005267E0(pCopy->pStrings[i], pSource->pStrings[i]);
    }
    pCopy->nCount = pSource->nCount;
    *(int*)pCopy->f_1A = *(int*)pSource->f_1A;
    return pCopy;
}

// 0x004A17D0
void __stdcall sub_004A17D0(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_007BF23F = 1;
    if (sub_00467A10())
    {
        if (gdwGlobal_007BF20A && sub_00463990(gdwGlobal_007BF202, 1) == sub_00467A10())
            return;
    }
    else if (!sub_00467A10() && gnGlobal_007BF23A)
    {
        D2UnitStrc* pUnit = sub_00463990(gdwGlobal_007BF23B, 1);
        if (pUnit && pUnit == sub_00463990(gdwGlobal_007BF202, 1))
        {
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
        }
        return;
    }
    sub_004A1770(pMsg);
}

// 0x004AA0C0
void __fastcall sub_004AA0C0_SetSlot(int nSlot, int nValueA, int nValueB, int nValueC)
{
    gnHotkeySkill_007C06C8[nSlot] = nValueA;
    gbHotkeyLeft_007C07B8[nSlot] = nValueB;
    gnHotkeyOwner_007C0768[nSlot] = nValueC;
}

// 0x004ACD70
void __fastcall sub_004ACD70_AssignSkillB8(D2UnitStrc* pUnit, int nUnused, int bAssign)
{
    if (bAssign)
    {
        SKILLS_AssignSkill(pUnit, 0xB8, 1, 1, ".\\UNIT\\MonUnique.cpp", 0x157);
        SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, 0xB8), 4);
    }
}

// 0x004B1050
int __fastcall sub_004B1050_GetMonsterValue(D2UnitStrc* pUnit, char* pNotFound, int* pValue)
{
    *pNotFound = 1;
    *pValue = -1;
    if (pUnit->dwUnitType == 1 && pUnit->pMonsterData && pUnit->pMonsterData->nUnk0x3C != -1)
    {
        *pValue = pUnit->pMonsterData->nUnk0x3C;
        *pNotFound = 0;
        return 1;
    }
    return 0;
}

// 0x004B92E0
int __stdcall sub_004B92E0_GetTableByte(int nUnused, int nIndex)
{
    D2_ASSERT(gdwTableInit_007C0ECC, 0x60);
    D2_ASSERT(nIndex < 0x25, 0x65);
    return gaTable_007C0EA4[nIndex];
}
