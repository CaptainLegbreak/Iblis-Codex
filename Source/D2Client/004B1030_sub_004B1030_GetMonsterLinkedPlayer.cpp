struct D2MonsterDataStrc
{
    char unk0x00[0x3C];
    int nUnk0x3C;
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

struct D2ClientStringListStrc
{
    unsigned short awStrings[10];
    unsigned short wCount;
};

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                            // 0x00463990
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern void* gpRes_007C0D6B;                                                                                // 0x007C0D6B
extern D2ClientStringListStrc gtStringList_007C0D9A;                                                        // 0x007C0D9A
extern D2UnitStrc* gpUnit_007C0DD4;                                                                         // 0x007C0DD4
extern unsigned short gwGlobal_007C0DD8;                                                                    // 0x007C0DD8
void __stdcall sub_M103_EmitSink(int nValue);

// 0x004B1030
D2UnitStrc* __fastcall sub_004B1030_GetMonsterLinkedPlayer(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 1 && pUnit->pMonsterData && pUnit->pMonsterData->nUnk0x3C != -1)
    {
        return sub_00463990(pUnit->pMonsterData->nUnk0x3C, 0);
    }
    return 0;
}

// 0x004B17D0
static __forceinline void sub_004B17D0_SetMenuState(int nState)
{
    gnGlobal_007C0C6B = nState;
}

// 0x004B17E0
static __forceinline void sub_004B17E0_SetMenuUnit(D2UnitStrc* pUnit)
{
    gpUnit_007C0DD4 = pUnit;
}

// 0x004B17F0
static __forceinline void sub_004B17F0_SetMenuValue(unsigned short wValue)
{
    gwGlobal_007C0DD8 = wValue;
}

// 0x004B1800
static __forceinline bool sub_004B1800_IsStringFree(unsigned short wString)
{
    for (int i = 0; i < gtStringList_007C0D9A.wCount; ++i)
    {
        if (gtStringList_007C0D9A.awStrings[i] == wString)
        {
            return false;
        }
    }
    return true;
}

// 0x004B1970
void __cdecl sub_004B1970_ResetUsedStrings()
{
    gtStringList_007C0D9A.wCount = 0;
}

// 0x004B1D50
void __cdecl sub_004B1D50_CloseRes()
{
    if (gpRes_007C0D6B)
    {
        sub_004B8020(gpRes_007C0D6B);
        gpRes_007C0D6B = 0;
    }
}

// 0x004B1F60
static __forceinline int sub_004B1F60_IsItemIdentified(D2UnitStrc* pItem)
{
    return ITEMS_CheckItemFlag(pItem, 0x10, 2457, ".\\UI\\npcmenu.cpp");
}

void __fastcall sub_M103_Emit_004B1000(D2UnitStrc* pItem, int nArg)
{
    if (sub_004B1800_IsStringFree((unsigned short)nArg))
    {
        sub_M103_EmitSink(sub_004B1F60_IsItemIdentified(pItem));
    }
    sub_004B17D0_SetMenuState(nArg);
    sub_004B17E0_SetMenuUnit(pItem);
    sub_004B17F0_SetMenuValue((unsigned short)nArg);
}
