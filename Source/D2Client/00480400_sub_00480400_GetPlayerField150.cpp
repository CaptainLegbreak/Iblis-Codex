struct D2PlayerDataStrc
{
    char unk0x000[0x150];
    int nField0x150;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2PlayerDataStrc* pPlayerData;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBF0];
    int nPetTypeTxtRecordCount;
};

struct D2QuestLookupEntryStrc
{
    int nKey;
    int nValue;
    int unk0x08;
    int unk0x0C;
};

#pragma pack(push, 1)
struct D2QuestPanelValuesStrc
{
    char unk0x00[0x7];
    int nValues[0x96];
};
#pragma pack(pop)

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

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern void* const gapWardenServices_006D8E68[7];                                                           // 0x006D8E68
int gnGlobal_007B9564;                                                                                      // 0x007B9564
extern D2QuestLookupEntryStrc gaQuestLookup_00723F38[0x29];                                                 // 0x00723F38
unsigned int __cdecl sub_0044CE60_GetPing();                                                                // 0x0044CE60

static int gnGlobal_007BEECC;                                                                               // 0x007BEECC
static int gnPopupX_007BEED4;                                                                               // 0x007BEED4

struct D2WardenClientM114Strc
{
    void* const* pServices;
    D2WardenClientM114Strc();
};

// 0x004801C0
D2WardenClientM114Strc::D2WardenClientM114Strc() : pServices(gapWardenServices_006D8E68)
{
}

// 0x00480400
int __fastcall sub_00480400_GetPlayerField150(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        return pUnit->pPlayerData->nField0x150;
    }
    return 0;
}

// 0x004804D0
unsigned int __cdecl sub_004804D0_GetPingScaled()
{
    return (sub_0044CE60_GetPing() + 0x32) >> 7;
}

// 0x004769B0
void __cdecl sub_004769B0_Toggle()
{
    gnGlobal_007B9564 = gnGlobal_007B9564 == 0;
}

// 0x004A3070
int __fastcall sub_004A3070_LookupValue(int nUnused, int nKey)
{
    for (unsigned int i = 0; i < 0x29; ++i)
    {
        if (gaQuestLookup_00723F38[i].nKey == nKey)
        {
            return gaQuestLookup_00723F38[i].nValue;
        }
    }
    return 0x2A;
}

// 0x004A3200
D2QuestPanelValuesStrc* __fastcall sub_004A3200_ClearValues(D2QuestPanelValuesStrc* pValues)
{
    for (int i = 0; i < 0x96; ++i)
    {
        pValues->nValues[i] = 0;
    }
    return pValues;
}

// 0x00492BC0
int __cdecl sub_00492BC0_GetPetTypeCount()
{
    return sgptDataTables->nPetTypeTxtRecordCount;
}

static inline int InBox(int nX, int nY, int nLeft, int nRight, int nTop, int nBottom)
{
    return nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom;
}

// 0x00492BD0
int __fastcall sub_00492BD0_IsInPetIcon(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    return gnGlobal_007BEECC != 2 && InBox(nX, nY, gnPopupX_007BEED4, gnPopupX_007BEED4 + 0x2E, 0x18, 0x18 + 0x24);
}

void __stdcall sub_M114_Emit_00492BD0(int nMode, int nPopupX)
{
    gnGlobal_007BEECC = nMode;
    gnPopupX_007BEED4 = nPopupX;
}

#include "gen/data/Source/D2Client/00480400_sub_00480400_GetPlayerField150.inc"
