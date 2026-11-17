struct HIMC__;
struct HKL__;
typedef HIMC__* HIMC;

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bUseResult;
    int lResult;
};

struct CANDIDATELIST
{
    unsigned long dwSize;
    unsigned long dwStyle;
    unsigned long dwCount;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __cdecl sub_004F59A0(); // 0x004F59A0
extern "C" int __stdcall ImmReleaseContext(int hWnd, HIMC hImc); // 0x006B00B4
extern "C" int __stdcall ImmGetOpenStatus(HIMC hImc); // 0x006B00BA
extern "C" HIMC __stdcall ImmGetContext(int hWnd); // 0x006B00C6
extern "C" unsigned long __stdcall ImmGetCandidateListA(HIMC hImc, unsigned long dwIndex, CANDIDATELIST* pCandList, unsigned long dwBufLen); // 0x006B00CC
extern "C" unsigned long __stdcall ImmGetCandidateListCountA(HIMC hImc, unsigned long* pListCount); // 0x006B00D2
extern "C" int __stdcall ImmIsIME(HKL__* hKl); // 0x006B00D8
extern "C" int __stdcall ImmGetConversionStatus(HIMC hImc, unsigned long* pConversion, unsigned long* pSentence); // 0x006B00DE
extern "C" __declspec(dllimport) HKL__* __stdcall GetKeyboardLayout(unsigned long idThread); // 0x006CC4C0
int gnLanguageId_007BB5DC;        // 0x007BB5DC
unsigned char gbImeOpen_007BB5E0;        // 0x007BB5E0
int gnImeState_007BB5F0;        // 0x007BB5F0
static CANDIDATELIST* gpCandidateList_007BB5F4; // 0x007BB5F4

// 0x0047AD60
static __declspec(noinline) void sub_0047AD60_RefreshCandidates(HIMC hImc)
{
    unsigned long nListCount;
    unsigned long nSize = ImmGetCandidateListCountA(hImc, &nListCount);
    if (ImmGetCandidateListA(hImc, 0, 0, 0) && nSize)
    {
        if (gpCandidateList_007BB5F4)
        {
            FOG_Free(gpCandidateList_007BB5F4, ".\\UI\\chat.cpp", 235, 0);
        }

        gpCandidateList_007BB5F4 = (CANDIDATELIST*)FOG_Alloc(nSize, ".\\UI\\chat.cpp", 237, 0);
        ImmGetCandidateListA(hImc, 0, gpCandidateList_007BB5F4, nSize);

        if (gpCandidateList_007BB5F4->dwStyle == 2 && gpCandidateList_007BB5F4->dwCount == 1)
        {
            FOG_Free(gpCandidateList_007BB5F4, ".\\UI\\chat.cpp", 242, 0);
            gpCandidateList_007BB5F4 = 0;
        }
    }
}

// 0x0047AE00
void __stdcall sub_0047AE00(SMSGHANDLER_PARAMS* pMsg)
{
    unsigned long nSentence;

    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);

    HIMC hImc = ImmGetContext(sub_004F59A0());
    if (!hImc)
    {
        return;
    }

    switch (pMsg->wParam)
    {
    case 8:
        switch (gnLanguageId_007BB5DC)
        {
        case 6:
            if (ImmGetOpenStatus(hImc))
            {
                gbImeOpen_007BB5E0 = 1;
                gnImeState_007BB5F0 = 3;
            }
            else
            {
                gbImeOpen_007BB5E0 = 0;
                gnImeState_007BB5F0 = 0;
            }
            break;

        case 8:
            if (ImmGetOpenStatus(hImc))
            {
                gbImeOpen_007BB5E0 = 1;
                gnImeState_007BB5F0 = 5;
            }
            else
            {
                gbImeOpen_007BB5E0 = 0;
                gnImeState_007BB5F0 = 0;
            }
            break;

        case 9:
            if (ImmGetOpenStatus(hImc))
            {
                gbImeOpen_007BB5E0 = 1;
                gnImeState_007BB5F0 = 4;
            }
            else
            {
                gbImeOpen_007BB5E0 = 0;
                gnImeState_007BB5F0 = 0;
            }
            break;
        }
        break;

    case 6:
    {
        unsigned long nConversion;
        ImmGetConversionStatus(hImc, &nConversion, &nSentence);
        if (gnLanguageId_007BB5DC == 7 || gnLanguageId_007BB5DC == 12)
        {
            if (nConversion & 1)
            {
                gnImeState_007BB5F0 = 1;
                gbImeOpen_007BB5E0 = 1;
            }
            else
            {
                gbImeOpen_007BB5E0 = 0;
                gnImeState_007BB5F0 = 0;
            }
        }
        break;
    }

    case 5:
        if (gnLanguageId_007BB5DC == 9)
        {
            sub_0047AD60_RefreshCandidates(hImc);
            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
        }
        if (gnLanguageId_007BB5DC == 8)
        {
            sub_0047AD60_RefreshCandidates(hImc);
            pMsg->lResult = 0;
            pMsg->bUseResult = 1;
        }
        break;

    case 4:
        if (gnLanguageId_007BB5DC == 9)
        {
            if (gpCandidateList_007BB5F4)
            {
                FOG_Free(gpCandidateList_007BB5F4, ".\\UI\\chat.cpp", 352, 0);
                gpCandidateList_007BB5F4 = 0;
            }
            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
        }
        if (gnLanguageId_007BB5DC == 8)
        {
            if (gpCandidateList_007BB5F4)
            {
                FOG_Free(gpCandidateList_007BB5F4, ".\\UI\\chat.cpp", 363, 0);
                gpCandidateList_007BB5F4 = 0;
            }
            pMsg->lResult = 0;
            pMsg->bUseResult = 1;
        }
        break;

    case 3:
        if (gnLanguageId_007BB5DC == 9)
        {
            sub_0047AD60_RefreshCandidates(hImc);
            pMsg->lResult = 0;
            pMsg->bUseResult = 1;
        }
        break;

    case 2:
        if (gnLanguageId_007BB5DC == 9)
        {
            gnImeState_007BB5F0 = ImmIsIME(GetKeyboardLayout(0)) ? 0 : 4;
            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
        }
        break;
    }

    ImmReleaseContext(sub_004F59A0(), hImc);
}
