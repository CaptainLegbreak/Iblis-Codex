#include "D2Client.h"
#include "D2Unicode.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Constants.h"

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2PalShiftDataStrc
{
    int unk0x00;
    unsigned char aShift[8][0x100];
    unsigned char aShiftBlood[8][0x100];
};

struct T0044A980
{
    int nId;
    D2PalShiftDataStrc* pData;
};

extern int gnTimerEnd; // 0x007A7464
extern int gnScreenWidth; // 0x0071146C
extern T0044A980* gpPalShiftEntries; // 0x007B9578
extern unsigned char gaGlobalPalShifts_007B9580[0x1E][0x100]; // 0x007B9580
extern int gbGlobalPalShifts_007BB380; // 0x007BB380

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
int __fastcall CUNIT_GetPalShiftIndex(D2UnitStrc* pUnit); // 0x00463EB0
int __cdecl GAME_GetColorFlag(); // 0x0044DC60
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320


// 0x00477530
unsigned char* __fastcall CUNIT_GetPalShift(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        D2PalShiftDataStrc* pData = gpPalShiftEntries[pUnit->dwClassId].pData;
        if (!pData)
            return 0;
        int nMode = CUNIT_GetPalShiftIndex(pUnit);
        switch (nMode)
        {
        case 0:
        case 1:
            switch (pUnit->dwClassId)
            {
            case 0x16B:
            case 0x16C:
                return pData->aShift[nMode];
            }
            return 0;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            break;
        default:
            if (gbGlobalPalShifts_007BB380)
            {
                nMode -= 8;
                D2_ASSERT(nMode >= 0 && nMode < 0x1E, 0x160);
                return gaGlobalPalShifts_007B9580[nMode];
            }
            break;
        }
        if (GAME_GetColorFlag())
        {
            D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
            if (pMonStats2TxtRecord && pMonStats2TxtRecord->nLocalBlood == 2)
                return pData->aShiftBlood[nMode];
        }
        return pData->aShift[nMode];
    }
    return 0;
}
