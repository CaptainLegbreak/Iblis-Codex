struct D2ClientDialogStrc;
struct D2InventoryStrc;
struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

#pragma pack(push, 2)
struct D2NpcEntryStrc
{
    int nId;
    char unk0x04[0x0D];
    char bSelected;
    char bFlag;
    char unk0x13[0x02];
    char bRefreshed;
};
#pragma pack(pop)
typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg);                       // 0x00455F20
void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int nArg1, unsigned int nArg2, unsigned int nArg3); // 0x004786D0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);                    // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                           // 0x00463DD0
void __stdcall sub_004B1680(D2NpcEntryStrc* pEntry);

extern D2ClientDialogStrc* gpDialog_007C0D6B;                                                               // 0x007C0D6B
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D29;                                                                               // 0x007C0D29
extern int gdwGlobal_007C0DB0;                                                                              // 0x007C0DB0
extern D2UnitStrc* gpUnit_007C0DD4;                                                                         // 0x007C0DD4
extern unsigned short gwGlobal_007C0DD8;                                                                    // 0x007C0DD8
extern int gnNpcEntryCount_0072554C;                                                                        // 0x0072554C
extern D2NpcEntryStrc gaNpcEntries_00726850[];                                                              // 0x00726850

// 0x004B3D40
int __cdecl sub_004B3D40_NpcMenuTradeB()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }

    D2UnitStrc* pUnit = sub_00463990(gnGlobal_007C0D25, 1);
    if (!(pUnit ? pUnit->pInventory : 0))
    {
        sub_004B3C20(gnGlobal_007C0D25);
        return 1;
    }

    gnGlobal_007C0C6B = 3;
    gdwGlobal_007C0DB0 = 1;
    sub_00455F20(0xC, 0, 0);
    sub_004786D0_SendDwords3(0x38, 2, gnGlobal_007C0D25, 0);
    gpUnit_007C0DD4 = sub_00463DD0_GetPlayerUnit();
    gwGlobal_007C0DD8 = 0;
    return 1;
}

// 0x004B3E10
void __fastcall sub_004B3E10_RefreshNpcEntries(D2UnitStrc* pUnit)
{
    if (pUnit != sub_00463DD0_GetPlayerUnit())
        return;

    for (int i = 0; i < gnNpcEntryCount_0072554C; ++i)
    {
        if (gaNpcEntries_00726850[i].bSelected == 1)
        {
            gaNpcEntries_00726850[i].bSelected = 0;
            D2_ASSERT(sub_00463DD0_GetPlayerUnit(), 0xFAB);
            sub_004B1680(&gaNpcEntries_00726850[i]);
        }
        gaNpcEntries_00726850[i].bRefreshed = 1;
    }

    if (!(gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0))
        return;

    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    gnGlobal_007C0D29 = 0;
}
