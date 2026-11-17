struct D2BitBufferStrc;
struct D2TextHeaderStrc;

struct D2MonsterDataStrc
{
    char unk0x00[0x40];
    int nMinionSpawnClassId;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x4];
    int dwUnitId;
    char unk0x10[0x4];
    D2MonsterDataStrc* pMonsterData;
};

#pragma pack(push, 1)
struct D2ClientPacket7Strc
{
    unsigned char nHeader;
    int dwUnitId;
    unsigned short f_5;
};

struct D2PacketRecord6Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitId;
};
#pragma pack(pop)

struct D2StringMapStrc
{
    unsigned short f_0;
    unsigned short wValue;
    char unk0x04[0x4];
};

struct D2ClientStringListStrc
{
    unsigned short awStrings[10];
    unsigned short wCount;
};

struct D2PartyRecordStrc
{
    unsigned char nFlag0;
    unsigned char nFlag1;
    char unk0x02[0x14];
};

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

extern int gnStringMapCount_00725C04;                                                                       // 0x00725C04
extern D2StringMapStrc gaStringMap_0072739C[];                                                              // 0x0072739C
extern unsigned short gwGlobal_00725494;                                                                    // 0x00725494
extern int gnPartyCount_0072554C;                                                                           // 0x0072554C
extern D2PartyRecordStrc gaParty_00726861[];                                                                // 0x00726861
extern unsigned char gbGlobal_007C0C6A;                                                                     // 0x007C0C6A
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D29;                                                                               // 0x007C0D29
extern D2BitBufferStrc* gpQuestFlags_007C0D43;                                                              // 0x007C0D43
extern void* gpRes_007C0D5F;                                                                                // 0x007C0D5F
extern void* gpRes_007C0D63;                                                                                // 0x007C0D63
extern void* gpRes_007C0D67;                                                                                // 0x007C0D67
extern void* gpRes_007C0D6B;                                                                                // 0x007C0D6B
extern void* gpRes_007C0D6F;                                                                                // 0x007C0D6F
extern void* gpRes_007C0D73;                                                                                // 0x007C0D73
extern void* gpRes_007C0D77;                                                                                // 0x007C0D77
extern void* gpRes_007C0D7B;                                                                                // 0x007C0D7B
unsigned char gbGlobal_007C0D89;                                                                            // 0x007C0D89
extern int gnGlobal_007C0D8E;                                                                               // 0x007C0D8E
extern int gnGlobal_007C0D96;                                                                               // 0x007C0D96
extern D2ClientStringListStrc gtStringList_007C0D9A;                                                        // 0x007C0D9A
unsigned char gbFound_007C0DDA;                                                                             // 0x007C0DDA

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                            // 0x00463990
void __fastcall sub_004649D0(UNITFN pfnCallback);                                                           // 0x004649D0
void __cdecl sub_00466FE0();                                                                                // 0x00466FE0
D2UnitStrc* __cdecl sub_00467A10();                                                             // 0x00467A10
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
void __cdecl sub_00487B70();                                                                                // 0x00487B70
D2TextHeaderStrc* __cdecl sub_0049F900();                                                                   // 0x0049F900
int __fastcall sub_004AE130(D2UnitStrc* pUnit);                                                // 0x004AE130
D2UnitStrc* __cdecl sub_004B1620_GetInteractNpc();                                                          // 0x004B1620
void __cdecl sub_004B23E0_InitPartyPanel();                                                                 // 0x004B23E0
void __cdecl sub_004B24A0();                                                                                // 0x004B24A0
void __cdecl sub_004B2940();                                                                                // 0x004B2940
void __fastcall sub_004B3360(D2UnitStrc* pUnit);                                                            // 0x004B3360
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);          // 0x004B9A00
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
unsigned short __stdcall sub_00661400(D2TextHeaderStrc* pTextHeader, int nNodeId);    // 0x00661400

// 0x004B1240
void __fastcall sub_004B1240_UsePacket7(D2ClientPacket7Strc* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, 1);
    if (pUnit)
    {
        const unsigned short wClassId = pPacket->f_5;
        const int nClassId = wClassId == 0xFFFF ? -1 : wClassId;
        if (pUnit->dwUnitType == 1 && pUnit->pMonsterData)
        {
            pUnit->pMonsterData->nMinionSpawnClassId = nClassId;
        }
    }
}

static int CLIENT_IsStringUsed(unsigned short wString)
{
    for (int i = 0; i < gtStringList_007C0D9A.wCount; ++i)
    {
        if (gtStringList_007C0D9A.awStrings[i] == wString)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004B1830
unsigned short __fastcall sub_004B1830_GetFreeStringId(unsigned short wStringId)
{
    for (int i = 0; i < gnStringMapCount_00725C04; ++i)
    {
        if (gaStringMap_0072739C[i].f_0 == wStringId)
        {
            return gaStringMap_0072739C[i].wValue;
        }
    }

    D2TextHeaderStrc* pTextHeader = sub_0049F900();
    int nNode = 0;
    unsigned short wNode = sub_00661400(pTextHeader, nNode);
    while (wNode != 0xFFFF)
    {
        if (wNode != wStringId && !CLIENT_IsStringUsed(wNode))
        {
            return wNode;
        }
        ++nNode;
        wNode = sub_00661400(pTextHeader, nNode);
    }
    return 0xFFFF;
}

// 0x004B1980
void __fastcall sub_004B1980_AddUsedString(unsigned short wStringId)
{
    if (gtStringList_007C0D9A.wCount < 9)
    {
        gtStringList_007C0D9A.awStrings[gtStringList_007C0D9A.wCount] = wStringId;
        gtStringList_007C0D9A.wCount++;
    }
}

// 0x004B2110
void __cdecl sub_004B2110_FreeResources()
{
    if (gpRes_007C0D6F) { sub_004B8020(gpRes_007C0D6F); gpRes_007C0D6F = 0; }
    if (gpRes_007C0D73) { sub_004B8020(gpRes_007C0D73); gpRes_007C0D73 = 0; }
    if (gpRes_007C0D6B) { sub_004B8020(gpRes_007C0D6B); gpRes_007C0D6B = 0; }
    if (gpRes_007C0D7B) { sub_004B8020(gpRes_007C0D7B); gpRes_007C0D7B = 0; }
    if (gpRes_007C0D5F) { sub_004B8020(gpRes_007C0D5F); gpRes_007C0D5F = 0; }
    if (gpRes_007C0D63) { sub_004B8020(gpRes_007C0D63); gpRes_007C0D63 = 0; }
    if (gpRes_007C0D67) { sub_004B8020(gpRes_007C0D67); gpRes_007C0D67 = 0; }
    if (gpRes_007C0D77) { sub_004B8020(gpRes_007C0D77); gpRes_007C0D77 = 0; }
}

// 0x004B2640
void __fastcall sub_004B2640(int nUnused)
{
    sub_00487B70();
}

// 0x004B2A00
void __fastcall sub_004B2A00(int nUnitId)
{
    if (gnGlobal_007C0D96 && gbGlobal_007C0D89 == 1 && nUnitId == gnGlobal_007C0D8E)
    {
        sub_004B2940();
    }
}

// 0x004B2A20
void __fastcall sub_004B2A20(int nUnitId)
{
    if (gnGlobal_007C0D96 && gbGlobal_007C0D89 == 1 && nUnitId == gnGlobal_007C0D8E)
    {
        sub_004B2940();
    }
}

// 0x004B2A40
void __fastcall sub_004B2A40(int nUnitId)
{
    if (gnGlobal_007C0D96 && gbGlobal_007C0D89 == 0 && nUnitId == gnGlobal_007C0D8E)
    {
        sub_004B2940();
    }
}

// 0x004B2A60
void __fastcall sub_004B2A60(int nUnitId)
{
    if (gnGlobal_007C0D96 && gbGlobal_007C0D89 == 0 && nUnitId == gnGlobal_007C0D8E)
    {
        sub_004B2940();
    }
}

// 0x004B2A80
void __fastcall sub_004B2A80_ResetHoverForItem(int nUnitId)
{
    D2UnitStrc* pSelected = sub_00467A10();
    if (pSelected && gnGlobal_007C0D29 && sub_00463990(gnGlobal_007C0D25, 1)
        && pSelected->dwUnitType == 4 && pSelected->dwUnitId == nUnitId)
    {
        sub_00466FE0();
        sub_00487990_ResetHover();
    }
}

// 0x004B2E20
int __cdecl sub_004B2E20_IsQuestActive()
{
    return gnGlobal_007C0C6B != 0;
}

// 0x004B3230
int __fastcall sub_004B3230_GetTickPair(int* pLow)
{
    *pLow = gnGlobal_007C0D25;
    return gnGlobal_007C0D29;
}

// 0x004B32F0
void __cdecl sub_004B32F0()
{
    gwGlobal_00725494 = 0xFFFF;
    sub_004B24A0();
    sub_004B23E0_InitPartyPanel();
    gbGlobal_007C0C6A = 0;
    for (int i = 0; i < gnPartyCount_0072554C; ++i)
    {
        gaParty_00726861[i].nFlag0 = 0;
        gaParty_00726861[i].nFlag1 = 0;
    }
}

// 0x004B3380
void __fastcall sub_004B3380(D2PacketRecord6Strc* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    if (pUnit->dwClassId == 0x216)
    {
        if (sub_004AE130(pUnit) != -1)
        {
            sub_004B9A00(0x11FB, pUnit, 0, 0, 0);
        }
        else
        {
            sub_004B9A00(0x11FF, pUnit, 0, 0, 0);
        }
        return;
    }

    D2UnitStrc* pNpc = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
    if (pUnit == pNpc)
    {
        return;
    }

    sub_00470390(pUnit, 0x48, 3, 0, 0, 0, 0, 0);
    if (pUnit->dwClassId != 0x14B || sub_004B1620_GetInteractNpc() || !gpQuestFlags_007C0D43)
    {
        return;
    }
    if (QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43, 12, 8) || QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43, 12, 1))
    {
        return;
    }

    gbFound_007C0DDA = 0;
    sub_004649D0(sub_004B3360);
    if (!gbFound_007C0DDA)
    {
        sub_004B9A00(0xF8F, pUnit, 0, 0, 0);
    }
}

// 0x004B3470
int __cdecl sub_004B3470_IsNpcQuestActive()
{
    if (gnGlobal_007C0D29 && sub_00463990(gnGlobal_007C0D25, 1) && gnGlobal_007C0C6B == 1)
    {
        return 1;
    }
    return 0;
}

#include "gen/data/Source/D2Client/004B1240_sub_004B1240_UsePacket7.inc"
