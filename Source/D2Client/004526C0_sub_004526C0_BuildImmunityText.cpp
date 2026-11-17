struct Unicode
{
    unsigned short wChar;

    Unicode();                                                                                              // 0x0042F530
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
};

struct D2MonStatsTxt
{
    char unk0x00[0x06];
    unsigned short wNameStr;
    unsigned short wDescStr;
    char unk0x0A[0x02];
    unsigned char dwMonStatsFlags[4];
    char unk0x10[0x1A8 - 0x10];
};

struct D2MonStats2Txt
{
    char unk0x00[0x0D];
    unsigned char nPixHeight;
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

#pragma pack(push, 2)
struct D2ImmunityTextStrc
{
    int nStat;
    unsigned short wString;
    int nColor;
};
#pragma pack(pop)

struct D2ActiveRoomStrc;

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                     // 0x00625480
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit);                               // 0x004521C0
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit);                                   // 0x00464A60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                            // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __cdecl sub_00525150();                                                                         // 0x00525150
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
int __fastcall sub_004525F0_GetHoverTextY(D2UnitStrc* pUnit);                                            // 0x004525F0
int __fastcall sub_004AE360_IsMonsterFlag8(D2UnitStrc* pUnit);                                           // 0x004AE360
int __fastcall sub_004AE320_IsMonsterFlag4(D2UnitStrc* pUnit);                                           // 0x004AE320
int __fastcall sub_00454880_GetHoverRect(D2RectStrc* pRect);                                                // 0x00454880
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_005022F0_ShowPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5, int nArg6); // 0x005022F0
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster);                                                    // 0x0063E940
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster);                                                   // 0x0063E990
int __fastcall sub_00452580_GetHoverMonsterName(D2UnitStrc* pUnit, int nArg);                            // 0x00452580
void __fastcall sub_00452520_SetHoverLine(const Unicode* pText, int nColor);                                // 0x00452520
int __fastcall sub_004B3230_GetTickPair(int* pLow);                                                         // 0x004B3230
int __cdecl sub_004A0000();                                                                                 // 0x004A0000
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const D2ImmunityTextStrc gaImmunityTexts_006D6418[6];                                                // 0x006D6418
extern Unicode gwszText_007A2A78[];                                                                         // 0x007A2A78
extern int gnHoverTextState_007A2C78;                                                                       // 0x007A2C78
extern Unicode gwszHoverName_007A2F38[];                                                                    // 0x007A2F38
extern int gnHoverX_0070F854;                                                                               // 0x0070F854
extern int gnHoverY_0070F858;                                                                               // 0x0070F858
extern const unsigned int gdwMask_006CE26C;                                                                 // 0x006CE26C
extern const unsigned int gdwTitleMaskB_006CE284;                                                           // 0x006CE284

// 0x004526C0
static void sub_004526C0_BuildImmunityText(D2UnitStrc* pUnit)
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
        if (STATLIST_UnitGetStatValue(pUnit, gaImmunityTexts_006D6418[n].nStat, 0) >= 100)
        {
            unsigned short wszItem[0x100];
            for (int i = 0; i < 0x100; i++)
                wszItem[i] = 0;
            if (wszText[0])
            {
                sub_00526700((Unicode*)wszText, pComma);
                sub_00526700((Unicode*)wszText, pNewLine);
            }
            sub_005267E0((Unicode*)wszItem, D2LANG_GetStringFromTblIndex(gaImmunityTexts_006D6418[n].wString));
            sub_004521C0_PrefixLevelText((Unicode*)wszItem, gaImmunityTexts_006D6418[n].nColor);
            sub_00526700((Unicode*)wszText, (Unicode*)wszItem);
        }
    }
    sub_005267E0(gwszText_007A2A78, (Unicode*)wszText);
    gnHoverTextState_007A2C78 = 4;
}

void __fastcall sub_00454AD0_DrawUnitHoverName(D2UnitStrc* pUnit)
{
    const int nOld = sub_00502EF0(1);
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxt = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
    int bDead = 0;
    unsigned short wszText[0x800];
    for (int i = 0; i < 0x800; i++)
        wszText[i] = 0;
    if (!(gdwMask_006CE26C & pMonStatsTxt->dwMonStatsFlags[1]) && (gdwTitleMaskB_006CE284 & pMonStatsTxt->dwMonStatsFlags[1]) && pMonStatsTxt->wNameStr)
    {
        D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
        if (pMonStats2Txt)
        {
            gnHoverY_0070F858 -= pMonStats2Txt->nPixHeight;
        }
        sub_005267E0((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700((Unicode*)wszText, sub_00464A60_GetUnitName(pUnit));
        sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        if (pUnit && pUnit->dwAnimMode == 12)
        {
            if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
            {
                return;
            }
            bDead = 1;
            if (!sub_00525150())
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
        if (sub_004AE360_IsMonsterFlag8(pUnit))
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
        if (sub_00454880_GetHoverRect(&tRect))
        {
            const int nWidth = sub_00501820((Unicode*)wszText);
            sub_005022F0_ShowPopUpText((Unicode*)wszText, ((tRect.nLeft + tRect.nRight) >> 1) - (nWidth >> 1), 0x20, nColor, 0, nY);
            if (bDead)
            {
                gwszHoverName_007A2F38[0].wChar = 0;
            }
            else
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
                if (!sub_00452580_GetHoverMonsterName(pUnit, nTypeString))
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
                        sub_00452520_SetHoverLine(wszLine, nColor);
                    }
                    else if (pRecord->wDescStr != 0x1506)
                    {
                        sub_00452520_SetHoverLine(D2LANG_GetStringFromTblIndex(pRecord->wDescStr), nColor);
                    }
                }
                sub_004526C0_BuildImmunityText(pUnit);
            }
        }
    }
    else
    {
        gwszHoverName_007A2F38[0].wChar = 0;
        if (!sub_004B3230_GetTickPair(&bDead) && !sub_004A0000())
        {
            D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
            if (pMonStats2Txt)
            {
                gnHoverY_0070F858 -= pMonStats2Txt->nPixHeight;
            }
            sub_00502280_SetPopUpText(sub_00464A60_GetUnitName(pUnit), gnHoverX_0070F854, gnHoverY_0070F858, 0, 1);
        }
    }
    sub_00502EF0(nOld);
}

#include "gen/data/Source/D2Client/004526C0_sub_004526C0_BuildImmunityText.inc"
