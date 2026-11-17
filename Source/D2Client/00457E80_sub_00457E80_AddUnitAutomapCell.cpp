#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_INVALID 6

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    struct D2UnitStrc* pUnitFirst;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0xB0];
    unsigned int dwFlagEx;
    char unk0xC8[0x20];
    D2UnitStrc* pRoomNext;
};

struct D2AutomapCellStrc
{
    unsigned int fSaved;
    unsigned short nCellNo;
    unsigned short xPixel;
    unsigned short yPixel;
    unsigned short wWeight;
    D2AutomapCellStrc* pPrev;
    D2AutomapCellStrc* pNext;
};

struct D2MonStatsTxt
{
    char unk0x00[0x18];
    short nMonStatsEx;
    char unk0x1A[0x18E];
};

struct D2MonStats2Txt
{
    char unk0x00[0x118];
    int dwAutomapCel;
    char unk0x11C[0x18];
};

struct D2ObjectsTxt
{
    char unk0x00[0x1BC];
    int dwAutomap;
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xC];
    D2MonStats2Txt* pMonStats2Txt;
    char unk0xA94[0x4];
    int nMonStats2TxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2AutomapCellStrc* __cdecl sub_00457C30();                                                       // 0x00457C30
void __fastcall sub_00457B00(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot);              // 0x00457B00
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gbRevealAutomap_007A51A0;                                                                        // 0x007A51A0

// 0x00457E80
static void __stdcall sub_00457E80_AddUnitAutomapCell(int nCellNo, D2AutomapCellStrc** ppRoot, D2UnitStrc* pUnit)
{
    D2AutomapCellStrc* pCell = sub_00457C30();
    const int nX = UNITS_GetClientCoordX(pUnit) / 10 + 1;
    const int nY = UNITS_GetClientCoordY(pUnit) / 10 - 3;
    D2_ASSERT(nX >= -0x8000 && nX <= 0x7FFF, 0x3C5);
    D2_ASSERT(nY >= -0x8000 && nY <= 0x7FFF, 0x3C6);
    D2_ASSERT(nCellNo >= -0x8000 && nCellNo <= 0x7FFF, 0x3C7);
    pCell->nCellNo = nCellNo;
    pCell->xPixel = nX;
    pCell->yPixel = nY;
    sub_00457B00(pCell, ppRoot);
}

void __stdcall sub_00458DC0_RevealRoomObjects(D2ActiveRoomStrc* pRoom, D2AutomapCellStrc** ppRoot)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
    {
        const int nFlag = pUnit ? (pUnit->dwFlagEx >> 28) & 1 : 0;
        const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        if (!gbRevealAutomap_007A51A0)
        {
            if (!nFlag)
                continue;

            if (pUnit ? (pUnit->dwFlagEx >> 29) & 1 : 0)
                continue;
        }

        if (pUnit)
            pUnit->dwFlagEx |= 0x20000000;

        switch (nUnitType)
        {
        case UNIT_MONSTER:
            if (pUnit)
            {
                const int nClassId = pUnit->dwClassId;
                if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
                {
                    const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nClassId].nMonStatsEx;
                    if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
                    {
                        D2MonStats2Txt* pMonStats2Txt = &sgptDataTables->pMonStats2Txt[nMonStatsEx];
                        if (pMonStats2Txt && pMonStats2Txt->dwAutomapCel)
                            sub_00457E80_AddUnitAutomapCell(pMonStats2Txt->dwAutomapCel, ppRoot, pUnit);
                    }
                }
            }
            break;

        case UNIT_OBJECT:
        {
            const int nClassId = pUnit ? pUnit->dwClassId : -1;
            D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(nClassId);
            if (!pObjectsTxt->dwAutomap)
                break;

            switch (nClassId)
            {
            case 0x10B:
            {
                const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
                if (nAct == 2 || nAct == 3)
                    sub_00457E80_AddUnitAutomapCell(pObjectsTxt->dwAutomap, ppRoot, pUnit);
                break;
            }
            case 0x16E:
                if (pUnit && pUnit->dwAnimMode == 2)
                    sub_00457E80_AddUnitAutomapCell(pObjectsTxt->dwAutomap, ppRoot, pUnit);
                break;

            case 0x192:
                if (DUNGEON_GetLevelIdFromRoom(pRoom) == 0x4A)
                    sub_00457E80_AddUnitAutomapCell(pObjectsTxt->dwAutomap, ppRoot, pUnit);
                break;

            default:
                sub_00457E80_AddUnitAutomapCell(pObjectsTxt->dwAutomap, ppRoot, pUnit);
                break;
            }
            break;
        }
        }
    }
}
