struct D2UnitStrc;
struct D2ClientDialogStrc;
struct D2TextHeaderStrc;

#pragma pack(push, 1)
struct D2NpcEntryStrc
{
    int nId;
    char unk0x04[0x0D];
    char bSelected;
    char bFlag;
    char unk0x13;
    char bFlag14;
    char bRefreshed;
};
#pragma pack(pop)

typedef int (__fastcall* D2TextCallback)(void* pContext, int nArg, int nValue);

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext);                   // 0x0049E7E0
void __fastcall sub_004A10E0(D2UnitStrc* pUnit, unsigned short nMessage, int nArg);                         // 0x004A10E0
unsigned short __fastcall sub_004B1830_GetFreeStringId(unsigned short wStringId);                           // 0x004B1830
int __cdecl sub_004B5BC0_SelectNpcEntry();                                                                  // 0x004B5BC0
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
int __fastcall sub_004B8580(D2ClientDialogStrc* pDialog);                                  // 0x004B8580
D2TextHeaderStrc* __cdecl sub_0049F900();                                                                   // 0x0049F900
short __stdcall TEXT_GetStringIdOfMenuType2Node(D2TextHeaderStrc* pTextHeader, int nNodeId);                // 0x006613C0

char gbGlobal_007C0C69;                                                                                     // 0x007C0C69
extern unsigned short gwGlobal_007C0C7B;                                                                    // 0x007C0C7B
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D29;                                                                               // 0x007C0D29
extern int gnGlobal_007C0C81;                                                                               // 0x007C0C81
extern D2ClientDialogStrc* gpDialog_007C0D6F;                                                               // 0x007C0D6F
extern D2NpcEntryStrc gaNpcEntries_00726850[];                                                              // 0x00726850

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x004B18C0
int __fastcall sub_004B18C0(void* pContext, int nArg, int nValue)
{
    if (gbGlobal_007C0C69 == 1)
    {
        const unsigned short wStringId = sub_004B1830_GetFreeStringId(gwGlobal_007C0C7B);
        if (wStringId != 0xFFFF && gnGlobal_007C0D29 && sub_00463990(gnGlobal_007C0D25, 1))
        {
            gwGlobal_007C0C7B = wStringId;
            D2UnitStrc* pNpc = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
            sub_004A10E0(pNpc, wStringId, 0);
            sub_0049E7E0_SetTextCallback(sub_004B18C0, 0);
            return 1;
        }
    }

    gbGlobal_007C0C69 = 0;
    sub_0049E7E0_SetTextCallback(0, pContext);
    sub_004B5BC0_SelectNpcEntry();
    return 1;
}

// 0x004B1A80
int __cdecl sub_004B1A80_OnSelectMessage()
{
    const int nSelected = sub_004B8580(gpDialog_007C0D6F);
    const int nFirstLine = gaNpcEntries_00726850[gnGlobal_007C0C81].bFlag14 ? 2 : 3;
    if (nSelected < nFirstLine)
    {
        return 0;
    }

    if (!gnGlobal_007C0D29 || !sub_00463990(gnGlobal_007C0D25, 1))
    {
        return 0;
    }

    const int nNodeId = sub_004B8580(gpDialog_007C0D6F) - nFirstLine;
    D2TextHeaderStrc* pTextHeader = sub_0049F900();
    D2_ASSERT(pTextHeader, 0x710);
    const unsigned short wStringId = TEXT_GetStringIdOfMenuType2Node(pTextHeader, nNodeId);
    gwGlobal_007C0C7B = wStringId;
    D2UnitStrc* pNpc = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
    sub_004A10E0(pNpc, wStringId, 0);
    gbGlobal_007C0C69 = 1;
    sub_0049E7E0_SetTextCallback(sub_004B18C0, 0);
    sub_004B8020(gpDialog_007C0D6F);
    gpDialog_007C0D6F = 0;
    return 1;
}
