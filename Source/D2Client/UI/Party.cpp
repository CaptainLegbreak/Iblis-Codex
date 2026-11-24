#include "D2Client.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2ClientTypes.h"
#include "D2ClientParty.h"

struct D2StoredUnitRecordStrc;

struct Unicode;

struct D2PartyRowStrc;

struct D2SevenIntStrc;


struct D2CelContextStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2StoredUnitRecordStrc* __fastcall ROSTER_GetNextStoredUnit(D2StoredUnitRecordStrc* pEntry); // 0x004795A0

unsigned short __fastcall ROSTER_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern int gnPanelOffsetX; // 0x007A2858

extern int gnPanelOffsetY; // 0x007A285C

extern void* gpPartyButtonsCel; // 0x007BF01C


#pragma pack(push, 1)


#pragma pack(pop)

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2SevenIntStrc
{
    int n0;
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int n6;
};

void __cdecl sub_K04_EmitUse(D2SevenIntStrc* pRecord);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0

int __fastcall ROSTER_GetLevel(D2StoredUnitRecordStrc* pEntry); // 0x00479B90

int __fastcall ROSTER_GetClassId(D2StoredUnitRecordStrc* pEntry); // 0x00479BA0

int __fastcall ROSTER_TestLootFlag(D2StoredUnitRecordStrc* pEntry); // 0x00479C20

int __fastcall ROSTER_TestMuteFlag(D2StoredUnitRecordStrc* pEntry); // 0x00479C60

int __fastcall ROSTER_TestSquelchFlag(D2StoredUnitRecordStrc* pEntry); // 0x00479CA0

int __fastcall ROSTER_TestHostileFlag(D2StoredUnitRecordStrc* pEntry); // 0x00479CE0

int __fastcall ROSTER_GetPartyFlags(D2StoredUnitRecordStrc* pEntry); // 0x00479D20

int __fastcall ROSTER_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord); // 0x0047A0C0

int __fastcall ROSTER_GetLevelId(D2StoredUnitRecordStrc* pEntry); // 0x0047A1E0

void __cdecl PARTY_FreeRosterUnits(); // 0x0049A020

D2PartyRowStrc* gpRosterUnits; // 0x007BF014

const Unicode* __fastcall UI_GetLevelName(int nLevelId); // 0x00453E70

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

int __fastcall ROSTER_IsHostileToPlayer(D2StoredUnitRecordStrc* pEntry); // 0x0047A5B0

void __stdcall sub_0049A690_DrawRosterButtons(D2PartyRowStrc* pRow); // 0x0049A690

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...); // 0x006CC468

extern "C" size_t __cdecl strlen(const char* szString);

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __fastcall sub_005262A0_Utf8CountChars(const char* pSrc, int nCount); // 0x005262A0

#pragma pack(push, 1)

struct D2PanelIconStrc
{
    int nX;
    int nY;
    D2CelFileStrc* pCelFile;
    unsigned int nFrame;
    int nType;
    int nState;
    int unk0x18[2];
};

struct D2PanelIconRecordStrc
{
    int unk0x00;
    D2PanelIconStrc pIcons[5];
    unsigned char unk0xA4[0x19];
    int nLevel;
    int unk0xC1;
    int nUnitId;
};

#pragma pack(pop)

static unsigned char gnBoxColor_007BF034;                                                                   // 0x007BF034

int __cdecl WINMAIN_IsHardcore();                                                                      // 0x0044B850

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, unsigned char nColor, unsigned char nArg6); // 0x0046EFD0

unsigned int __fastcall GFXUTIL_TestRelationFlags(int nUnitId1, int nUnitId2, unsigned int nFlags);              // 0x004DC440

void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

void* gpPartyBoxesCel; // 0x007BF020

// 0x00499FC0
static void __stdcall PARTY_DrawPanelCel(void* pCellFile, int nX, int nFrame, int nY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCellFile;
    tContext.nFrame = nFrame;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, gnPanelOffsetX + nX, nY - gnPanelOffsetY, -1, 5, 0);
}

// 0x0049A020
void __cdecl PARTY_FreeRosterUnits()
{
    D2PartyRowStrc* pUnit = gpRosterUnits;
    while (pUnit)
    {
        D2PartyRowStrc* pNext = pUnit->pNext;
        FOG_Free(pUnit, ".\\UI\\Party.cpp", 0x108, 0);
        pUnit = pNext;
    }
    gpRosterUnits = 0;
}

// 0x0049A060
static void __stdcall PARTY_FillRecord(D2SevenIntStrc* pRecord, int n0, int n1, int n2, int n3, int n4, int n5, int n6)
{
    pRecord->n0 = n0;
    pRecord->n1 = n1;
    pRecord->n2 = n2;
    pRecord->n3 = n3;
    pRecord->n4 = n4;
    pRecord->n5 = n5;
    pRecord->n6 = n6;
}

void __cdecl sub_K04_EmitFillRecord(int n0, int n1, int n2, int n3, int n4, int n5, int n6)
{
    D2SevenIntStrc tRecord;
    PARTY_FillRecord(&tRecord, n0, n1, n2, n3, n4, n5, n6);
    sub_K04_EmitUse(&tRecord);
}

static void sub_L04_InitSlot(D2RosterSlotStrc* pSlot, int bFlag, int nX, int nY, void* pCellFile, int nFrame, int nType, int nState)
{
    pSlot->bFlag = bFlag;
    pSlot->nX = nX;
    pSlot->nY = nY;
    pSlot->pCellFile = pCellFile;
    pSlot->nFrame = nFrame;
    pSlot->nType = nType;
    pSlot->nState = nState;
}

// 0x0049A090
static void PARTY_InitRosterUnit(D2StoredUnitRecordStrc* pEntry, D2PartyRowStrc* pUnit, int nY)
{
    pUnit->nY = nY + 0xD;
    sub_L04_InitSlot(&pUnit->aSlots[0], 1, 0xBE, nY, gpPartyButtonsCel, 0, 0, ROSTER_GetPartyFlags(pEntry));
    sub_L04_InitSlot(&pUnit->aSlots[1], 0, 0xE, nY + 7, gpPartyBoxesCel, ROSTER_TestHostileFlag(pEntry) ? 6 : 4, 1, 0);
    sub_L04_InitSlot(&pUnit->aSlots[2], 0, 0xF5, nY, gpPartyBoxesCel, ROSTER_TestLootFlag(pEntry) ? 0xE : 0xC, 2, 0);
    sub_L04_InitSlot(&pUnit->aSlots[3], 0, 0x10A, nY, gpPartyBoxesCel, ROSTER_TestMuteFlag(pEntry) ? 2 : 0, 3, 0);
    sub_L04_InitSlot(&pUnit->aSlots[4], 0, 0x11F, nY, gpPartyBoxesCel, ROSTER_TestSquelchFlag(pEntry) ? 0xA : 8, 4, 0);
    pUnit->nId = ROSTER_GetRecordUnitId(pEntry);
}

// 0x0049A1D0
static void PARTY_AddRosterUnit(int nY, D2StoredUnitRecordStrc* pEntry)
{
    D2PartyRowStrc* pLast = gpRosterUnits;
    D2PartyRowStrc* pUnit = (D2PartyRowStrc*)FOG_Alloc(sizeof(D2PartyRowStrc), ".\\UI\\Party.cpp", 0x14D, 0);
    memset(pUnit, 0, sizeof(D2PartyRowStrc));
    PARTY_InitRosterUnit(pEntry, pUnit, nY);
    strcpy(pUnit->szName, ROSTER_GetEntryName(pEntry));
    pUnit->nClass = ROSTER_GetClassId(pEntry);
    pUnit->nLevel = ROSTER_GetLevel(pEntry);
    pUnit->nLevelId = ROSTER_GetLevelId(pEntry);
    if (pLast)
    {
        while (pLast->pNext)
            pLast = pLast->pNext;
        pLast->pNext = pUnit;
    }
    else
    {
        gpRosterUnits = pUnit;
    }
}

// 0x0049A2A0
int __cdecl PARTY_IsPlayerHostileLevel()
{
    return ROSTER_GetLevel(ROSTER_GetNextStoredUnit(0)) >= 9;
}

// 0x0049A2C0
static void __stdcall PARTY_DrawRosterName(int nY, int nColor, int bShort, const char* szName)
{
    Unicode wszName[100];
    sub_00526320_ToUnicode(wszName, szName, 100);
    Unicode* pEnd = &wszName[99];
    char szDots[5] = "...";
    Unicode wszDots[5];
    const int nWidth = D2Win_10121_GetTextWidth(wszName);
    if (bShort)
    {
        if (nWidth > 0x5F)
        {
            while (D2Win_10121_GetTextWidth(wszName) > 0x5F)
            {
                --pEnd;
                *pEnd = 0;
            }
            sub_00526320_ToUnicode(wszDots, szDots, 5);
            sub_00526700(wszName, wszDots);
        }
    }
    else if (nWidth > 0x87)
    {
        while (D2Win_10121_GetTextWidth(wszName) > 0x87)
        {
            --pEnd;
            *pEnd = 0;
        }
        sub_00526320_ToUnicode(wszDots, szDots, 5);
        sub_00526700(wszName, wszDots);
    }
    D2Win_10117_DrawText(wszName, gnPanelOffsetX + 0x24, nY - gnPanelOffsetY - 2, nColor, 0);
}

// 0x0049A3D0
static void __stdcall PARTY_DrawRosterClass(int nColor, int nY, int nClass)
{
    int nStringId;
    switch (nClass)
    {
    case 0:
        nStringId = 0x103A;
        break;
    case 1:
        nStringId = 0x103B;
        break;
    case 2:
        nStringId = 0x103D;
        break;
    case 3:
        nStringId = 0x103E;
        break;
    case 4:
        nStringId = 0x103C;
        break;
    case 5:
        nStringId = 0x2771;
        break;
    case 6:
        nStringId = 0x2772;
        break;
    default:
        return;
    }
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(nStringId), gnPanelOffsetX + 0x24, nY - gnPanelOffsetY, nColor, 0);
}

// 0x0049A510
void __cdecl PARTY_DrawPartyButtons()
{
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    D2Win_10127_SetFont(0);
    if (ROSTER_GetEntryIndex(pEntry) != 0xFFFF)
    {
        PARTY_DrawPanelCel(gpPartyButtonsCel, 0xE3, 0, 0x23);
        TEXT_DrawCenteredText(gnPanelOffsetX + 0xE3, 0x21 - gnPanelOffsetY, gnPanelOffsetX + 0x118, D2LANG_GetStringFromTblIndex(0x1038), 2);
    }
    D2Win_10127_SetFont(1);
}

// 0x0049A580
void __cdecl PARTY_DrawPlayerName()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;
    const char* szName = sub_0047A210(pPlayer);
    if (!szName)
        return;
    unsigned int nLen = sub_005262A0_Utf8CountChars(szName, strlen(szName)) + 1;
    if (nLen > 11)
    {
        if (nLen >= 14)
            D2Win_10127_SetFont(6);
        else
            D2Win_10127_SetFont(0);
    }
    Unicode* wszName = (Unicode*)FOG_Alloc(sizeof(Unicode) * nLen, ".\\UI\\Party.cpp", 0x211, 0);
    sub_00526320_ToUnicode(wszName, szName, nLen);
    TEXT_DrawCenteredText(gnPanelOffsetX + 0x14, 0x1F - gnPanelOffsetY, gnPanelOffsetX + 0xBE, wszName, 0);
    D2Win_10127_SetFont(0);
    FOG_Free(wszName, ".\\UI\\Party.cpp", 0x21A, 0);
}

// 0x0049A640
void __cdecl PARTY_RebuildRosterUnits()
{
    PARTY_FreeRosterUnits();
    int nY = 0x5A;
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(ROSTER_GetNextStoredUnit(0));
    for (int i = 0; pEntry || i > 8; ++i)
    {
        PARTY_AddRosterUnit(nY, pEntry);
        nY += 0x26;
        pEntry = ROSTER_GetNextStoredUnit(pEntry);
    }
}

// 0x0049A690
void __stdcall PARTY_DrawPanelIcons(D2PanelIconRecordStrc* pRecord)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();

    D2CelContextStrc tGfx;
    memset(&tGfx, 0, sizeof(tGfx));
    tGfx.nDirection = 0;

    for (int i = 0; i < 5; ++i)
    {
        if (pRecord->pIcons[i].nType || pRecord->pIcons[i].nState != 1)
        {
            tGfx.pCellFile = pRecord->pIcons[i].pCelFile;
            const unsigned int nFrame = pRecord->pIcons[i].nFrame;
            tGfx.nFrame = nFrame;

            switch (pRecord->pIcons[i].nType)
            {
            case 1:
                if (nFrame < 4 || nFrame > 7)
                {
                    tGfx.nFrame = 4;
                }
                TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnPanelOffsetX, pRecord->pIcons[i].nY - gnPanelOffsetY, -1, 5, 0);
                break;

            case 2:
                if (nFrame < 12 || nFrame > 15)
                {
                    tGfx.nFrame = 12;
                }

                if (WINMAIN_IsHardcore())
                {
                    TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnPanelOffsetX, pRecord->pIcons[i].nY - gnPanelOffsetY, -1, 5, 0);
                }
                break;

            case 3:
                if (nFrame > 3)
                {
                    tGfx.nFrame = 0;
                }
                TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnPanelOffsetX, pRecord->pIcons[i].nY - gnPanelOffsetY, -1, 5, 0);
                break;

            case 4:
                if (nFrame < 8 || nFrame > 11)
                {
                    tGfx.nFrame = 8;
                }
                TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnPanelOffsetX, pRecord->pIcons[i].nY - gnPanelOffsetY, -1, 5, 0);
                break;

            default:
                TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnPanelOffsetX, pRecord->pIcons[i].nY - gnPanelOffsetY, -1, 5, 0);
                break;
            }
        }

        if (pRecord->pIcons[i].nType == 1)
        {
            int bShowBox = 0;
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
            if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
            {
                bShowBox = 1;
            }

            if (pRecord->nLevel < 9 && !GFXUTIL_TestRelationFlags(GAME_GetUnitGUID(pPlayer), pRecord->nUnitId, 8))
            {
                bShowBox = 1;
            }

            if (ROSTER_GetLevel(ROSTER_GetNextStoredUnit(0)) < 9 || bShowBox)
            {
                AUTOMAP_DrawFramedBox(pRecord->pIcons[i].nX + gnPanelOffsetX, pRecord->pIcons[i].nY - gnPanelOffsetY - 19, 20, 20, gnBoxColor_007BF034 = D2Win_10034_MixRGB(255, 0, 0), 1);
            }
        }
    }
}

// build: symbol ?ROSTERPETS_DrawPanelLabel@* 0x0049A460
static void __stdcall ROSTERPETS_DrawPanelLabel(int nY, int bAlt, unsigned short nFlag, int nType)
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
        D2Win_10127_SetFont(0);
        return;
    }

    int nLeft = gnPanelOffsetX + nX;
    TEXT_DrawCenteredText(nLeft, nY - gnPanelOffsetY - 2, nLeft + 0x35, D2LANG_GetStringFromTblIndex(nStringId), nColor);
}

static void __stdcall sub_0049A830_DrawRosterArea(int nY, D2PartyRowStrc* pEntry, int nColor)
{
    Unicode wszName[0xFF];
    sub_005267E0(wszName, UI_GetLevelName(pEntry->nLevelId));
    Unicode* pEnd = &wszName[0xFE];
    if (D2Win_10121_GetTextWidth(wszName) > 0x8C)
    {
        const int nLength = sub_00526800(wszName);
        const Unicode wLast = wszName[nLength - 1];
        char szDots[] = "....";
        Unicode wszDots[5];
        sub_00526320_ToUnicode(wszDots, szDots, 5);
        wszDots[3] = wLast;
        const int nMax = 0x8B - D2Win_10121_GetTextWidth(wszDots);
        while (D2Win_10121_GetTextWidth(wszName) > nMax)
        {
            --pEnd;
            *pEnd = 0;
        }
        sub_00526700(wszName, wszDots);
    }
    D2Win_10117_DrawText(wszName, gnPanelOffsetX + 0x7E, nY - gnPanelOffsetY + 0xC, nColor, 0);
}

static void __stdcall sub_0049C170_DrawRosterLevel(int nY, int nLevel, int nColor)
{
    Unicode wszText[100];
    Unicode wszNumber[10];
    char szNumber[100];
    Unicode::strncpy(wszText, D2LANG_GetStringFromTblIndex(0xD28), 0x14);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
// build: symbol ?gszFormat2u@* 0x006DA0CC
    wsprintfA(szNumber, gszFormat2u, nLevel);
    sub_00526F20_ToUnicode(wszNumber, szNumber, 9);
    sub_00526700(wszText, wszNumber);
    D2Win_10117_DrawText(wszText, gnPanelOffsetX + 0x10A, nY - gnPanelOffsetY, nColor, 0);
}

// 0x0049C270
void __cdecl PARTY_DrawPartyRows()
{
    D2PartyRowStrc* pRow = gpRosterUnits;
    int nY = 0x5A;
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    const unsigned short nSelfIndex = ROSTER_GetEntryIndex(pEntry);
    pEntry = ROSTER_GetNextStoredUnit(pEntry);
    int nCount = 0;
    while (pRow && pEntry && nCount < 8)
    {
        int nColor = 0;
        int bSelf = 0;
        const unsigned short nIndex = ROSTER_GetEntryIndex(pEntry);
        if (ROSTER_GetEntryIndex(pEntry) != 0xFFFF)
        {
            if (nSelfIndex == nIndex)
            {
                nColor = 2;
                bSelf = 1;
            }
            else
            {
                nColor = 8;
            }
        }
        if (ROSTER_IsHostileToPlayer(pEntry))
        {
            nColor = 1;
        }
        D2Win_10127_SetFont(0);
        if (nIndex == 0xFFFF)
        {
            PARTY_DrawRosterName(nY, nColor, 0, pRow->szName);
        }
        else
        {
            PARTY_DrawRosterName(nY, nColor, 1, pRow->szName);
        }
        PARTY_DrawRosterClass(nColor, nY + 0xC, pRow->nClass);
        sub_0049C170_DrawRosterLevel(nY + 0xC, pRow->nLevel, nColor);
        if (bSelf && pRow->nLevelId)
        {
            sub_0049A830_DrawRosterArea(nY, pRow, nColor);
        }
        sub_0049A690_DrawRosterButtons(pRow);
        if (nSelfIndex == nIndex)
        {
            ROSTERPETS_DrawPanelLabel(nY, 1, nIndex, pRow->aSlots[0].nState);
        }
        else
        {
            ROSTERPETS_DrawPanelLabel(nY, 0, nIndex, pRow->aSlots[0].nState);
        }
        pRow = pRow->pNext;
        ++nCount;
        nY += 0x26;
        pEntry = ROSTER_GetNextStoredUnit(pEntry);
        D2Win_10127_SetFont(1);
    }
}
