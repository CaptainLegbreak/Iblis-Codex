#include "D2Client.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"
#include "D2ClientGame.h"
#include "D2StormTypes.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2LevelTxt.h"
#include "D2ClientUi.h"

struct Unicode;

struct D2PanelAnimEntryStrc
{
    void* pData;
    char unk0x04[0x18];
};

struct T0045FED0
{
    unsigned int dwTick;
    char unk0x04[0x50];
    unsigned int nVersion;
    char unk0x58[8];
    void (__cdecl* pfnCallback)();
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290

int __cdecl GAME_IsExitPending();                                                                                 // 0x0044DA30

void __cdecl sub_0044DA70();                                                                                // 0x0044DA70

void __cdecl UI_StartUIVarDelay();                                                                                // 0x00453AE0

int __cdecl sub_00468730();                                                                                 // 0x00468730

int __cdecl sub_00468740();                                                                                 // 0x00468740

void __fastcall ROSTERPETS_RemoveHirelingEntries(int nUnused, int nKey);                                            // 0x00478AB0

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor);  // 0x004A7080

int __stdcall INV_GetTableByte(int nUnused, int nIndex);                                           // 0x004B92E0

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

extern int gnGlobal_0071146C;                                                                               // 0x0071146C

extern int gnGlobal_00711470;                                                                               // 0x00711470

extern D2PanelAnimEntryStrc gaPanelAnim_00712020[];                                                         // 0x00712020

extern int gnGlobal_007A2858;                                                                               // 0x007A2858

extern int gnGlobal_007A285C;                                                                               // 0x007A285C

extern int gnGlobal_007A524C;                                                                               // 0x007A524C

extern int gnGlobal_007BB5DC;                                                                               // 0x007BB5DC

extern unsigned char gbGlobal_007BB5E0;                                                                     // 0x007BB5E0

extern D2InvRectStrc gInvRect_007BCAA0;                                                                     // 0x007BCAA0

#define gnGlobal_007BCAA0 (gInvRect_007BCAA0.nLeft)

#define gnGlobal_007BCAA4 (gInvRect_007BCAA0.nRight)

#define gnGlobal_007BCAA8 (gInvRect_007BCAA0.nTop)

#define gnGlobal_007BCAAC (gInvRect_007BCAA0.nBottom)

int gbGlobal_007BCE90;                                                                                      // 0x007BCE90

extern void* gpGlobal_007BEEF4;                                                                             // 0x007BEEF4

#include "gen/data/Source/D2Client/GAME/RosterPets/gnGlobal_007129CC.inc"

static int gnGlobal_007A5248;                                                                               // 0x007A5248

static int gnGlobal_007A5254;                                                                               // 0x007A5254

static int gnGlobal_007A6AAC;                                                                               // 0x007A6AAC

static int gnGlobal_007A6AB0;                                                                               // 0x007A6AB0

static int gnGlobal_007A6ADC;                                                                               // 0x007A6ADC

static int gnGlobal_007A6AE0;                                                                               // 0x007A6AE0

static int gnGlobal_007A6AE8;                                                                               // 0x007A6AE8

static int gnGlobal_007A6AF0;                                                                               // 0x007A6AF0

static int gnGlobal_007A745C;                                                                               // 0x007A745C

static D2RosterPetStrc* gpRosterPets_007BB5BC;                                                          // 0x007BB5BC

static int gnGlobal_007BB5F0;                                                                               // 0x007BB5F0

static int gnGlobal_007BCA4C;                                                                               // 0x007BCA4C

static int gnGlobal_007BCBD8;                                                                               // 0x007BCBD8

static int gnGlobal_007BEEFC;                                                                               // 0x007BEEFC

static int gnGlobal_007C0280;                                                                               // 0x007C0280

static T0045FED0* gpTimer_007C0E54;                                                                 // 0x007C0E54

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2RosterPetStrc;

struct D2Packet81ArgsStrc;

struct D2HirelingInfoStrc;

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

struct D2HirelingInfoStrc
{
    unsigned short f_0;
    unsigned short unk0x02;
    int nSeed;
    int unk0x08[2];
};

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall CUNIT_UpdateAttackableFlag(D2UnitStrc* pUnit); // 0x004647D0

void __fastcall ROSTERPETS_SetRosterEntry(int nKey, int nArg, int nType, int nValue); // 0x00478B10

void __fastcall MONSTER_SetMonsterLight(D2UnitStrc* pUnit); // 0x004AE210

void __fastcall MONSTER_InitHireling(D2UnitStrc* pUnit, D2HirelingInfoStrc* pInfo); // 0x004B1090

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

struct D2ClientEntryStrc;

// 0x0045FED0
void __stdcall ROSTERPETS_HandlePopupButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    gnGlobal_007A524C = 0;
    if (gnGlobal_007A5248)
    {
        int nLeft = gnGlobal_007A2858 + 0x110;
        int nBottom = 0x136 - gnGlobal_007A285C;
        int nX = sub_00468730();
        int nY = sub_00468740();
        if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
        {
            gnGlobal_007A5254 = 1;
            gnGlobal_007A5248 = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    sub_0044DA70();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x00467F20
void __stdcall sub_00467F20_MsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    gnGlobal_007A6AB0 = pMsg->nXpos;
    gnGlobal_007A6AAC = pMsg->nYpos;
    gnGlobal_007A6AE8 = GetTickCount();
    if (gnGlobal_007A6AF0 != 5 && gaPanelAnim_00712020[gnGlobal_007A6ADC].pData)
    {
        gnGlobal_007A6AF0 = 5;
        gnGlobal_007A6ADC = 4;
        gnGlobal_007A6AE0 = 0;
    }
    pMsg->bReturn = 0;
}

// 0x00467FA0
void __stdcall sub_00467FA0_MsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    gnGlobal_007A6AB0 = pMsg->nXpos;
    gnGlobal_007A6AAC = pMsg->nYpos;
    gnGlobal_007A6AE8 = GetTickCount();
    if (gnGlobal_007A6AF0 == 5)
    {
        gnGlobal_007A6ADC = 5;
        gnGlobal_007A6AF0 = 1;
        gnGlobal_007A6AE0 = 0;
    }
    pMsg->bReturn = 0;
}

// 0x0046BD50
int __stdcall ROSTERPETS_GetPulseColor(unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    if (gnGlobal_007A745C || !INV_GetTableByte(0, 1))
    {
        return 0;
    }
    *pRed = 0xFF;
    *pGreen = 0x40;
    *pBlue = 0x30;
    if (gnGlobal_007129CC == -1)
    {
        return 0x50;
    }
    return (int)(sub_0040B330_Cos(gnGlobal_007129CC * 128 / 30) * 80.0);
}

// 0x00478A50
void __cdecl ROSTERPETS_FreeRosterPets()
{
    D2RosterPetStrc* pPet = gpRosterPets_007BB5BC;
    while (pPet)
    {
        D2RosterPetStrc* pNext = pPet->pNext;
        FOG_Free(pPet, ".\\GAME\\RosterPets.cpp", 0x2F, 0);
        pPet = pNext;
    }
    gpRosterPets_007BB5BC = 0;
}

// 0x00478A90
D2RosterPetStrc* __fastcall ROSTERPETS_FindRosterPet(int nKey)
{
    for (D2RosterPetStrc* pNode = gpRosterPets_007BB5BC; pNode; pNode = pNode->pNext)
    {
        if (pNode->dwUnitId == nKey)
        {
            return pNode;
        }
    }
    return 0;
}

// 0x00478B10
void __fastcall ROSTERPETS_SetRosterEntry(int nKey, int nArg, int nType, int nValue)
{
    if (nType == 7)
    {
        ROSTERPETS_RemoveHirelingEntries(nKey, nKey);
    }
    for (D2RosterPetStrc* pNode = gpRosterPets_007BB5BC; pNode; pNode = pNode->pNext)
    {
        if (pNode->dwUnitId == nKey)
        {
            pNode->nType = nType;
            pNode->dwOwnerId = nArg;
            pNode->nClassId = nValue;
            pNode->bDead = 0;
            return;
        }
    }
    D2RosterPetStrc* pNew = (D2RosterPetStrc*)FOG_Alloc(sizeof(D2RosterPetStrc), ".\\GAME\\RosterPets.cpp", 0x7A, 0);
    memset(pNew, 0, sizeof(D2RosterPetStrc));
    D2RosterPetStrc* pHead = gpRosterPets_007BB5BC;
    pNew->dwUnitId = nKey;
    pNew->dwOwnerId = nArg;
    pNew->nType = nType;
    pNew->nClassId = nValue;
    pNew->nLifePercent = 0x64;
    pNew->pNext = pHead;
    gpRosterPets_007BB5BC = pNew;
}

// 0x00478AB0
void __fastcall ROSTERPETS_RemoveHirelingEntries(int nUnused, int nKey)
{
    D2RosterPetStrc* pPrev = 0;
    for (D2RosterPetStrc* pNode = gpRosterPets_007BB5BC; pNode; pNode = pNode->pNext)
    {
        if (pNode->nType == 7 && pNode->dwUnitId == nKey)
        {
            if (pPrev)
                pPrev->pNext = pNode->pNext;
            else
                gpRosterPets_007BB5BC = pNode->pNext;
            FOG_Free(pNode, ".\\GAME\\RosterPets.cpp", 0x59, 0);
            return;
        }
        pPrev = pNode;
    }
}

// 0x00478BB0
void __fastcall ROSTERPETS_AssignMercEntry(int nKey, int nArg, int nType, int nValue, D2Packet81ArgsStrc* pArgs)
{
    if (nType == 7)
        ROSTERPETS_RemoveHirelingEntries(nKey, nKey);

    D2RosterPetStrc* pNode;
    for (pNode = gpRosterPets_007BB5BC; pNode && pNode->dwUnitId != nKey; pNode = pNode->pNext)
        ;

    ROSTERPETS_SetRosterEntry(nKey, nArg, nType, nValue);

    for (pNode = gpRosterPets_007BB5BC; pNode && pNode->dwUnitId != nKey; pNode = pNode->pNext)
        ;
    D2_ASSERT(pNode, 0x95);

    pNode->dwUnitId = nKey;
    pNode->dwOwnerId = nArg;
    pNode->nType = nType;
    pNode->tEntry = *(D2ClientEntryStrc*)pArgs;

    if (nType == 7)
    {
        D2HirelingInfoStrc tInfo;
        tInfo.nSeed = pArgs->nArg0C;
        tInfo.f_0 = (unsigned short)pArgs->nArg10;
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(nKey, 1);
        if (pUnit)
        {
            MONSTER_InitHireling(pUnit, &tInfo);
            CUNIT_UpdateAttackableFlag(pUnit);
            MONSTER_SetMonsterLight(pUnit);
            UNITS_ChangeAnimMode(pUnit, 1);
        }
    }
}

// 0x00478C90
void __fastcall ROSTERPETS_DropPetEntry(int nKey)
{
    D2RosterPetStrc* pPrev = 0;
    for (D2RosterPetStrc* pNode = gpRosterPets_007BB5BC; pNode; pNode = pNode->pNext)
    {
        if (pNode->dwUnitId == nKey)
        {
            if (pNode->nType == 7)
            {
                D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
                if (pNode->dwOwnerId == (!pPlayer ? -1 : pPlayer->dwUnitId))
                {
                    pNode->bDead = 1;
                    return;
                }
            }
            if (pPrev)
                pPrev->pNext = pNode->pNext;
            else
                gpRosterPets_007BB5BC = pNode->pNext;
            FOG_Free(pNode, ".\\GAME\\RosterPets.cpp", 0xD1, 0);
            return;
        }
        pPrev = pNode;
    }
}

// 0x00478E40
D2ClientEntryStrc* __fastcall sub_00478E40_FindEntry(int nKey)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nKey)
            return &pPet->tEntry;
    }
    return 0;
}

// 0x0047ACA0
void __stdcall ROSTERPETS_HandleImeStartComposition(SMSGHANDLER_PARAMS* pMsg)
{
    gbGlobal_007BB5E0 = 1;
    gwGlobal_007BC850 = 0;
    gwGlobal_007BB5F8 = 0;
    if (gnGlobal_007BB5DC == 9)
        gnGlobal_007BB5F0 = 4;
    else if (gnGlobal_007BB5DC == 8)
        gnGlobal_007BB5F0 = 5;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004890B0
int __stdcall ROSTERPETS_HandleRectClick(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (nX < gnGlobal_007BCAA0 || nX >= gnGlobal_007BCAA4 || nY < gnGlobal_007BCAA8 || nY > gnGlobal_007BCAAC)
    {
        gbGlobal_007BCE90 = 0;
        return 0;
    }
    if (nX >= gnGlobal_0071146C - gnGlobal_007A2858 - 0x12E && nX <= gnGlobal_0071146C - gnGlobal_007A2858 - 0x10E
        && nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x60 && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x40
        && gbGlobal_007BCE90)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        sub_004C0440();
    }
    gbGlobal_007BCE90 = 0;
    return 1;
}

// 0x00494620
void __cdecl ROSTERPETS_DrawHelpColumn()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpGlobal_007BEEF4;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    int nY = 0x49;
    for (int i = 0; i < 8; ++i)
    {
        sub_004F6480(&tContext, 0x68, nY, -1, 5, 0);
        nY += 0x14;
    }
}

// 0x00494F30
void __stdcall ROSTERPETS_HandleHelpButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (D2GFX_GetResolutionMode() == 2)
    {
        if (nX >= 0x2AD && nX <= 0x2CD && nY >= 0x18 && nY <= 0x38)
        {
            gnGlobal_007BEEFC = 1;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    else
    {
        if (nX >= 0x20D && nX <= 0x22D && nY >= 0x18 && nY <= 0x38)
        {
            gnGlobal_007BEEFC = 1;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    sub_0044DA70();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0049A460
void __fastcall sub_0049A460_DrawPanelLabel(int nType, int nUnused, int nY, int bAlt, unsigned short nFlag)
{
    int nStringId;
    int nColor = 0;
    int nX = 0xBE;
    switch (nType)
    {
    case 1:
        if (nFlag == 0xFFFF)
        {
            return;
        }

        if (bAlt)
        {
            nStringId = 0x1034;
            nColor = 2;
            nX = 0x9B;
        }
        else
        {
            nStringId = 0x1035;
            nColor = 8;
            nX = 0xAF;
        }
        break;
    case 0:
        nStringId = 0x1036;
        break;
    case 2:
        nStringId = 0x1037;
        break;
    case 3:
        nStringId = 0x1038;
        break;
    case 4:
        nStringId = 0x13EF;
        break;
    default:
        sub_00502EF0(0);
        return;
    }

    int nLeft = gnGlobal_007A2858 + nX;
    TEXT_DrawCenteredText(nLeft, nY - gnGlobal_007A285C - 2, nLeft + 0x35, D2LANG_GetStringFromTblIndex(nStringId), nColor);
}

// 0x004A5980
void __stdcall ROSTERPETS_HandlePanelButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    gnGlobal_007C0280 = 1;
    sub_004A4AD0_Press(pMsg->nXpos, pMsg->nYpos);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004B76D0
void __stdcall ROSTERPETS_HandleDialogEscape(SMSGHANDLER_PARAMS* pMsg)
{
    T0045FED0* pTimer = gpTimer_007C0E54;
    if (pTimer && pTimer->dwTick + 0x50 > GetTickCount())
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    pTimer = gpTimer_007C0E54;
    D2_ASSERT(pTimer, 0x1C2);
    if (pTimer->nVersion >= 5)
    {
        void (__cdecl* pfnCallback)() = pTimer->pfnCallback;
        if (pfnCallback)
        {
            pfnCallback();
            UI_StartUIVarDelay();
        }
    }
}

#include "gen/data/Source/D2Client/GAME/RosterPets.inc"
