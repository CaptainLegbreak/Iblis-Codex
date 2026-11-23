#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Unicode.h"

#define UNIT_MONSTER 1
struct Unicode;
struct D2RectStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2ImmunityTextStrc;

extern Unicode gwszHoverText[]; // 0x007A2A78
extern int gnHoverTextState; // 0x007A2C78
int __fastcall UI_GetHoverRect(D2RectStrc* pRect); // 0x00454880
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
D2UnitStrc* __cdecl sub_00467A10(); // 0x00467A10
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
int __fastcall MONSTER_IsUniqueMonster(D2UnitStrc* pUnit); // 0x004AE360




#pragma pack(push, 2)
struct D2ImmunityTextStrc
{
    int nStat;
    unsigned short wString;
    int nColor;
};

#pragma pack(pop)

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit); // 0x004521C0
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
const Unicode* __fastcall CUNIT_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
void __fastcall D2Win_10130_DrawFramedTextEx(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5, int nArg6); // 0x005022F0
int __fastcall AUTOMAP_GetHoverMonsterName(D2UnitStrc* pUnit, unsigned short nArg); // 0x00452580
void __fastcall GAME_SetHoverLine(const Unicode* pText, int nColor); // 0x00452520
int __fastcall NPCMENU_GetInteractNpcId(int* pLow); // 0x004B3230
int __cdecl TEXT_IsTextBoxOpen(); // 0x004A0000
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const D2ImmunityTextStrc gaImmunityTexts[6]; // 0x006D6418
extern Unicode gwszHoverName[]; // 0x007A2F38

Unicode gwszHoverLine[256]; // 0x007A2D30

int gnHoverTextColor; // 0x007A2F30

Unicode gwszHoverName[256]; // 0x007A2F38

static void __stdcall sub_004549F0_DrawCenteredText(const Unicode* wszText, int nFont, int nY, int nColor)
{
    Unicode wszBuffer[0x100];
    for (int i = 0; i < 0x100; ++i)
    {
        wszBuffer[i].wChar = 0;
    }
    D2RectStrc tRect;
    if (!UI_GetHoverRect(&tRect) || !wszText)
    {
        return;
    }
    const int nOldFont = sub_00502EF0(nFont);
    sub_005267E0(wszBuffer, wszText);
    const int nWidth = D2Win_10121_GetTextWidth(wszBuffer);
    const int nX = ((tRect.nLeft + tRect.nRight) >> 1) - (nWidth >> 1);
    D2Win_10117_DrawText(wszBuffer, nX, nY, nColor, 1);
    sub_00502EF0(nOldFont);
}

// 0x00454A70
void __cdecl sub_00454A70_DrawHoverText()
{
    D2UnitStrc* pUnit = sub_00467A10();
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }
    int nY = D2Win_10125() + 0x27;
    sub_004549F0_DrawCenteredText(gwszHoverLine, 6, nY, gnHoverTextColor);
    if (gwszHoverLine[0].wChar || gwszHoverName[0].wChar)
    {
        nY += D2Win_10125();
    }
    sub_004549F0_DrawCenteredText(gwszHoverText, 6, nY, gnHoverTextState);
}

// 0x004554B0
void __cdecl sub_004554B0_DrawHoverName()
{
    if (!sub_00526800(gwszHoverName))
    {
        return;
    }
    D2UnitStrc* pUnit = sub_00467A10();
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }
    int nColor = 0;
    if (MONSTER_IsUniqueMonster(pUnit))
    {
        nColor = 4;
    }
    if (sub_004AE320_IsMonsterFlag4(pUnit))
    {
        nColor = 3;
    }
    const int nY = D2Win_10125() + 0x27;
    sub_004549F0_DrawCenteredText(gwszHoverName, 6, nY, nColor);
}

// 0x004526C0
static void UI_BuildImmunityText(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId >= 0x2C0 && pUnit->dwClassId <= 0x2C5)
    {
        return;
    }
    const Unicode* pNewLine = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pComma = D2LANG_GetStringFromTblIndex(0xF0C);
    unsigned short wszText[0x100];
    for (int i = 0; i < 0x100; i++)
        wszText[i] = 0;
    wszText[0] = 0;
    for (int n = 0; n < 6; n++)
    {
        if (STATLIST_UnitGetStatValue(pUnit, gaImmunityTexts[n].nStat, 0) >= 100)
        {
            unsigned short wszItem[0x100];
            for (int i = 0; i < 0x100; i++)
                wszItem[i] = 0;
            if (wszText[0])
            {
                sub_00526700((Unicode*)wszText, pComma);
                sub_00526700((Unicode*)wszText, pNewLine);
            }
            sub_005267E0((Unicode*)wszItem, D2LANG_GetStringFromTblIndex(gaImmunityTexts[n].wString));
            INV_PrefixColorCode((Unicode*)wszItem, gaImmunityTexts[n].nColor);
            sub_00526700((Unicode*)wszText, (Unicode*)wszItem);
        }
    }
    sub_005267E0(gwszHoverText, (Unicode*)wszText);
    gnHoverTextState = 4;
}

// build: symbol ??_H* 0x00403040
// 0x00454AD0
void __fastcall sub_00454AD0_DrawUnitHoverName(D2UnitStrc* pUnit)
{
    const int nOld = sub_00502EF0(1);
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxt = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
    int bDead = 0;
    D2MonStats2Txt* pMonStats2Txt;
    unsigned short wszText[0x800];
    for (int i = 0; i < 0x800; i++)
        wszText[i] = 0;
    if (!(gdwMask_006CE26C & pMonStatsTxt->nMonStatsFlags[1]) && (gdwTitleMaskB_006CE284 & pMonStatsTxt->nMonStatsFlags[1]) && pMonStatsTxt->wNameStr)
    {
        pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
        if (pMonStats2Txt)
        {
// build: symbol ?gnHoverY@* 0x0070F858
            gnHoverY -= pMonStats2Txt->nPixHeight;
        }
        sub_005267E0((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700((Unicode*)wszText, CUNIT_GetUnitName(pUnit));
        sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        if (pUnit && pUnit->dwAnimMode == 12)
        {
            if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
            {
                return;
            }
            bDead = 1;
            if (!STRTABLE_GetLanguage())
            {
                sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0x90B));
            }
            else
            {
                Unicode wszParen[2];
                char szParen[] = "(";
                sub_00526F20_ToUnicode(wszParen, szParen, 2);
                sub_00526700((Unicode*)wszText, wszParen);
                sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0x90B));
                strcpy(szParen, ")");
                sub_00526F20_ToUnicode(wszParen, szParen, 2);
                sub_00526700((Unicode*)wszText, wszParen);
            }
            sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        }
        sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        const int nY = sub_004525F0_GetHoverTextY(pUnit);
        int nColor = 0;
        if (MONSTER_IsUniqueMonster(pUnit))
        {
            nColor = 4;
        }
        if (sub_004AE320_IsMonsterFlag4(pUnit))
        {
            nColor = 3;
        }
        if (bDead)
        {
            nColor = 1;
        }
        if (nClassId == 0xF3 || nClassId == 0x14D || nClassId == 0xF2 || nClassId == 0xD3 || nClassId == 0x220
            || nClassId == 0x23A || nClassId == 0xE5 || nClassId == 0x2C4 || nClassId == 0x2C3 || nClassId == 0x2C2
            || nClassId == 0x2C1 || nClassId == 0x2C5 || nClassId == 0x2C0)
        {
            nColor = 4;
        }
        D2RectStrc tRect;
        if (UI_GetHoverRect(&tRect))
        {
            const int nX = ((tRect.nRight + tRect.nLeft) >> 1) - (D2Win_10121_GetTextWidth((Unicode*)wszText) >> 1);
            D2Win_10130_DrawFramedTextEx((Unicode*)wszText, nX, 0x20, nColor, 0, nY);
            if (!bDead)
            {
                D2MonStatsTxt* pRecord = DATATBLS_GetMonStatsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
                unsigned short nTypeString = 0;
                if (MONSTERS_IsDemon(pUnit))
                {
                    nTypeString = 0x275E;
                }
                else if (MONSTERS_IsUndead(pUnit))
                {
                    nTypeString = 0x275D;
                }
                if (!AUTOMAP_GetHoverMonsterName(pUnit, nTypeString))
                {
                    if (nTypeString)
                    {
                        Unicode wszLine[0x200];
                        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(nTypeString));
                        sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(0xF9B));
                        if (pRecord->wDescStr != 0x1506)
                        {
                            sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(pRecord->wDescStr));
                        }
                        GAME_SetHoverLine(wszLine, nColor);
                    }
                    else if (pRecord->wDescStr != 0x1506)
                    {
                        GAME_SetHoverLine(D2LANG_GetStringFromTblIndex(pRecord->wDescStr), nColor);
                    }
                }
                UI_BuildImmunityText(pUnit);
            }
            else
            {
                gwszHoverName[0].wChar = 0;
            }
        }
    }
    else
    {
        gwszHoverName[0].wChar = 0;
        int nTickLow;
        if (!NPCMENU_GetInteractNpcId(&nTickLow) && !TEXT_IsTextBoxOpen())
        {
            pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
            if (pMonStats2Txt)
            {
                gnHoverY -= pMonStats2Txt->nPixHeight;
            }
// build: symbol ?gnHoverX@* 0x0070F854
            D2Win_10129_DrawFramedText(CUNIT_GetUnitName(pUnit), gnHoverX, gnHoverY, 0, 1);
        }
    }
    sub_00502EF0(nOld);
}
