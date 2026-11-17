struct D2ClientDialogLineStrc
{
    char unk0x00[0x10C];
    int bEnabled;
};

struct D2ClientDialogStrc
{
    unsigned long dwTick;
    int unk0x04;
    void* pCelFile;
    char unk0x0C[0x38];
    int f_44;
    int unk0x48;
    int unk0x4C;
    int nLines;
    char unk0x54[0x14];
    D2ClientDialogLineStrc aLines[10];
    void* pWidgets;
    D2ClientDialogStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x004B82F0
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex)
{
    D2_ASSERT(pDialog, 0x4E7);
    D2_ASSERT(nIndex < pDialog->nLines, 0x4ED);
    if (nIndex == -1)
    {
        pDialog->f_44 = nIndex;
        return;
    }

    for (int i = 0; i < pDialog->nLines; ++i)
    {
        const int* pbEnabled = &pDialog->aLines[i].bEnabled;
        if (nIndex == i)
        {
            if (*pbEnabled)
            {
                pDialog->f_44 = nIndex;
                return;
            }

            D2_ASSERT(0, 0x50F);
        }
    }

    D2_ASSERT(0, 0x513);
}
