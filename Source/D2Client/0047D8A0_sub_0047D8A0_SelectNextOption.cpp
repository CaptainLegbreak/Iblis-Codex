struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    int lParam;
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};

struct D2OptionHeaderStrc
{
    int nCount;
};

struct D2OptionEntryStrc
{
    int nKind;
    char unk0x004[0x10C];
    int (__cdecl* pfnEnabled)();
    void (__fastcall* pfnChanged)(D2OptionEntryStrc* pEntry, int nArg);
    int unk0x118[2];
    unsigned int nValues;
    unsigned int nValue;
    char unk0x128[0x428];
};

void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00420290
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00

static int gnOptionSelected_007BC938;                                                                       // 0x007BC938
extern D2OptionHeaderStrc* gpOptionHeader_007BC93C;                                                         // 0x007BC93C
extern D2OptionEntryStrc* gpOptionEntries_007BC940;                                                         // 0x007BC940

// 0x0047D8A0
void __stdcall sub_0047D8A0_SelectNextOption(SMSGHANDLER_PARAMS* pMsg)
{
    do
    {
        ++gnOptionSelected_007BC938;
        if (gnOptionSelected_007BC938 > gpOptionHeader_007BC93C->nCount - 1)
        {
            gnOptionSelected_007BC938 = 0;
        }
    }
    while (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nKind == -1
        || gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnEnabled && !gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnEnabled());
    sub_004B9A00(1, 0, 0, 0, 0);
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0047D920
void __stdcall sub_0047D920_SelectPreviousOption(SMSGHANDLER_PARAMS* pMsg)
{
    do
    {
        --gnOptionSelected_007BC938;
        if (gnOptionSelected_007BC938 < 0)
        {
            gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
        }
    }
    while (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nKind == -1
        || gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnEnabled && !gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnEnabled());
    sub_004B9A00(1, 0, 0, 0, 0);
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}
