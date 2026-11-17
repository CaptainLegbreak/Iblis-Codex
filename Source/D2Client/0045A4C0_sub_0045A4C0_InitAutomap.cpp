struct D2SkillStrc;
struct D2InventoryStrc;
struct D2CelFileStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x5C];
    D2InventoryStrc* pInventory;
};

struct D2UnitTargetStrc
{
    int nParam1;
    int nParam2;
    int unk0x08[5];
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x62];
    int dwAuraRangeCalc;
};

struct D2UnitOverlayStrc
{
    int nType;
    int nOverlay;
    int nUnk0x08;
    int f_C;
    int unk0x10[2];
    int nFrame;
    int nFrames;
    int nOffsetX;
    int nOffsetY;
    int unk0x28[3];
    int bFront;
    int unk0x38;
    int nUnk0x3C;
    char unk0x40[0x64];
    D2UnitOverlayStrc* pNext;
};

struct D2GfxDataStrc
{
    char unk0x00[0x2C];
    D2UnitOverlayStrc* pOverlays;
};

struct D2OverlayTxt
{
    char unk0x00[0x7C];
    unsigned char nTrans;
    char unk0x7D[7];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBBC];
    D2OverlayTxt* pOverlayTxt;
    int nOverlayTxtRecordCount;
};

struct D2AutomapPairStrc
{
    int nIndex;
    int nValue;
};

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

struct D2UiRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2UiRecordStrc
{
    int unk0x00;
    unsigned char nIndex;
    unsigned char unk0x05;
    unsigned short unk0x06;
    D2UiRectStrc aRects[16];
};

struct D2ClientSlotObjStrc
{
    virtual void Slot0(int* pValue, int nSize);
    virtual void Slot1();
    virtual void Slot2(int nArg1, int nArg2, int* pOut);
};

struct D2WardenIfaceStrc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags);                           // 0x00412650

class WardenModule
{
public:
    ~WardenModule();
    void operator delete(void* pMemory)
    {
        SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x117, 0);
    }

    void* pImage;
    int unk0x04;
    int nImports;
    D2ClientSlotObjStrc* pObj;
    D2ClientSlotObjStrc* (__fastcall* pfnCreate)(D2WardenIfaceStrc* pIface);
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void __cdecl sub_0045A2B0_ReloadAutomapCels();                                                              // 0x0045A2B0
int __fastcall sub_00461250_QueueMove(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg); // 0x00461250
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                       // 0x00463E10
void __stdcall sub_0046E040_RemoveOverlay(D2UnitStrc* pUnit, D2UnitOverlayStrc* pOverlay);                 // 0x0046E040
void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget);   // 0x004AFF60
void __fastcall sub_004BD6D0_ObjectCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget);    // 0x004BD6D0
void __fastcall sub_004C1B80_ItemCommand(int nCommand, D2UnitStrc* pUnit, int nParam1, int nParam2);       // 0x004C1B80
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300
D2UnitStrc* __stdcall sub_00623990_GetWeapon(D2UnitStrc* pUnit, int nArg);                                  // 0x00623990
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                    // 0x006289F0
int __stdcall ITEMS_CanItemBeUsedForThrowSkill(D2UnitStrc* pItem);                                          // 0x0062A310
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem);                                                         // 0x0062E6F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                        // 0x006416D0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall sub_00660CB0_GetUiRecord(int nIndex, int nRow, D2UiRecordStrc* pRecord);                    // 0x00660CB0

extern D2AutomapPairStrc gaAutomapPairs_00711258[49];                                                       // 0x00711258
extern int gdwGlobal_007113E0;                                                                              // 0x007113E0
extern int gdwGlobal_007113E4;                                                                              // 0x007113E4
extern int gdwGlobal_007113E8;                                                                              // 0x007113E8
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnWardenIfaceValue_00721C94;                                                                     // 0x00721C94
extern D2WardenIfaceStrc gWardenIface_00721C98;                                                             // 0x00721C98
extern int gnUiRecordIndex_00722354;                                                                        // 0x00722354
extern int gaAutomapCellTable_007A3150[0x800];                                                              // 0x007A3150
extern int gdwAutoMapFade_007A51A8;                                                                         // 0x007A51A8
extern int gdwGlobal_007A51E0;                                                                              // 0x007A51E0
extern int gdwGlobal_007A51E4;                                                                              // 0x007A51E4
extern int gdwGlobal_007A51E8;                                                                              // 0x007A51E8
extern int gnUiRecordRow_007A5218;                                                                          // 0x007A5218
WardenModule* gpSlotHolder_007BC990;                                                                        // 0x007BC990
WardenModule* gpPendingWarden_007BC994;                                                                     // 0x007BC994
extern int gbUiRecordMode_007BEF98;                                                                         // 0x007BEF98

// build: symbol ??1WardenModule@@QAE@XZ 0x004E06A0
// 0x0045A4C0
void __cdecl sub_0045A4C0_InitAutomap()
{
    unsigned long dwValue = 0;
    sub_0045A2B0_ReloadAutomapCels();
    for (int i = 0; i < 0x800; i++)
    {
        gaAutomapCellTable_007A3150[i] = -1;
    }
    for (int i = 0; i < 49; i++)
    {
        gaAutomapCellTable_007A3150[gaAutomapPairs_00711258[i].nIndex] = gaAutomapPairs_00711258[i].nValue;
    }
    dwValue = 0;
    SRegLoadValue("Diablo II", "AutoMapFade", 0, &dwValue);
    gdwAutoMapFade_007A51A8 = dwValue;
    dwValue = 1;
    SRegLoadValue("Diablo II", "AutoMap Centers", 0, &dwValue);
    gdwGlobal_007113E0 = dwValue;
    dwValue = 1;
    SRegLoadValue("Diablo II", "AutoMap Party", 0, &dwValue);
    gdwGlobal_007113E4 = dwValue;
    dwValue = 1;
    SRegLoadValue("Diablo II", "AutoMap Party Names", 0, &dwValue);
    gdwGlobal_007113E8 = dwValue;
    dwValue = 1;
    SRegLoadValue("Diablo II", "AutoMap Left", 0, &dwValue);
    gdwGlobal_007A51E0 = dwValue;
    gdwGlobal_007A51E4 = dwValue;
    gdwGlobal_007A51E8 = dwValue;
}

// 0x00461AC0
int __fastcall sub_00461AC0_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer || !pSkill || !pTarget)
    {
        return 0;
    }
    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    *pRange = SKILLS_EvaluateSkillFormula(pPlayer, pSkillsTxtRecord->dwAuraRangeCalc, pSkillsTxtRecord->nSkillId,
        SKILLS_GetSkillLevel(pPlayer, pSkill, 1));
    *pDistance = sub_006416D0_UnitEdgeDistance(pPlayer, pTarget);
    return *pDistance <= *pRange;
}

// 0x0046EFD0
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6)
{
    D2GFX_DrawBox(nX, nY, nX + nWidth, nY + nHeight, nArg5, nArg6);
}

inline D2OverlayTxt* DATATBLS_GetOverlayTxtRecordInline(int nOverlay)
{
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        return &sgptDataTables->pOverlayTxt[nOverlay];
    }
    return 0;
}

// 0x0046F0C0
void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue)
{
    if (!pUnit)
    {
        return;
    }
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (!pGfxData)
    {
        return;
    }
    D2_ASSERT(DATATBLS_GetOverlayTxtRecordInline(nValue), 0xCA9);
    D2UnitOverlayStrc* pOverlay = pGfxData->pOverlays;
    while (pOverlay)
    {
        D2UnitOverlayStrc* pNext = pOverlay->pNext;
        if (pOverlay->nOverlay == nValue)
        {
            sub_0046E040_RemoveOverlay(pUnit, pOverlay);
            return;
        }
        const int nType = pOverlay->nType;
        if ((nType == 4 || nType == 9) && (pOverlay->nUnk0x08 == nValue || pOverlay->f_C == nValue))
        {
            sub_0046E040_RemoveOverlay(pUnit, pOverlay);
            return;
        }
        pOverlay = pNext;
    }
}

// 0x00480230
void __cdecl sub_00480230()
{
    while (gpPendingWarden_007BC994)
    {
        if (gpSlotHolder_007BC990)
        {
            gpSlotHolder_007BC990->pObj->Slot1();
            gpSlotHolder_007BC990->~WardenModule();
            delete gpSlotHolder_007BC990;
        }
        gpSlotHolder_007BC990 = gpPendingWarden_007BC994;
        gpPendingWarden_007BC994 = 0;
        gpSlotHolder_007BC990->pObj = gpSlotHolder_007BC990->pfnCreate(&gWardenIface_00721C98);
        int nValue = gnWardenIfaceValue_00721C94;
        gpSlotHolder_007BC990->pObj->Slot0(&nValue, 4);
    }
}

// 0x00480C10
int __fastcall sub_00480C10_DispatchUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg)
{
    switch (pUnit->dwUnitType)
    {
    case 0:
        return sub_00461250_QueueMove(nCommand, pUnit, pTarget, nArg);
    case 1:
        sub_004AFF60_MonsterCommand(nCommand, pUnit, pTarget);
        return 1;
    case 2:
        sub_004BD6D0_ObjectCommand(nCommand, pUnit, pTarget);
        return 1;
    case 4:
        sub_004C1B80_ItemCommand(nCommand, pUnit, pTarget->nParam1, pTarget->nParam2);
        return 1;
    }
    return 1;
}

// 0x00498DC0
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UiRecordStrc tRecord;
    sub_00660CB0_GetUiRecord(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRecord);
    if (gbUiRecordMode_007BEF98)
    {
        const D2UiRectStrc* pRect = &tRecord.aRects[tRecord.nIndex - 4];
        if (nX >= pRect->nLeft && nX <= tRecord.aRects[3].nRight && nY >= pRect->nTop && nY <= tRecord.aRects[3].nBottom)
        {
            return 1;
        }
    }
    else if (nY > gnGlobal_00711470 - 0x30 && nX >= gnGlobal_0071146C / 2 + 0x17 && nX <= gnGlobal_0071146C / 2 + 0x91
        && nY >= gnGlobal_00711470 - 0x27 && nY <= gnGlobal_00711470 - 0xA)
    {
        return 1;
    }
    return 0;
}

// 0x004C5420
D2UnitStrc* __fastcall sub_004C5420_RequestAtTarget(D2UnitStrc* pUnit, int nRequest, int nArg3, int nArg4)
{
    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY) || !nX || !nY)
    {
        return 0;
    }
    return sub_004CDBA0_SubmitOwnerRequest(pUnit, nRequest, nX, nY, nArg3, nArg4);
}

// 0x004C54F0
int __fastcall sub_004C54F0_CanThrow(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    if (pUnit->dwUnitType != 0)
    {
        return 1;
    }
    D2UnitStrc* pWeapon = sub_00623990_GetWeapon(pUnit, 0);
    int bNoAmmo = 1;
    if (!pWeapon)
    {
        return 1;
    }
    if (ITEMS_GetAmmoType(pWeapon))
    {
        bNoAmmo = 0;
        if (!SKILLS_GetSkillIdFromSkill(UNITS_GetUsedSkill(pUnit), ".\\SKILLS\\Skills.cpp", 0xB6)
            && STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, 0x9D, 0))
        {
            return 1;
        }
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }
    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (pItem && (!bNoAmmo || pItem == pWeapon)
        && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x7D, 0)))
    {
        return ITEMS_CanItemBeUsedForThrowSkill(pItem);
    }
    pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (pItem && (!bNoAmmo || pItem == pWeapon)
        && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x7D, 0)))
    {
        return ITEMS_CanItemBeUsedForThrowSkill(pItem);
    }
    return 0;
}

#include "gen/data/Source/D2Client/0045A4C0_sub_0045A4C0_InitAutomap.inc"
