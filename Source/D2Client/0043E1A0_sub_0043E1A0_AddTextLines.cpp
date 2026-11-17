struct D2WinControlStrc;

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2ChatMessageStrc
{
    char* szText;
    int nColor;
    int bClear;
    D2ChatMessageStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" unsigned int __cdecl strlen(const char* szString);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine);                                          // 0x004FBA30
void __fastcall sub_004FCFF0_SetTextA(D2WinControlStrc* pControl, const char* szText, int nArg);            // 0x004FCFF0

extern D2CriticalSectionStrc gtChatLock_0077AE28;                                                           // 0x0077AE28
D2WinControlStrc* gpChatTextBox_0077BD8C;                                                                   // 0x0077BD8C
extern D2ChatMessageStrc* gpChatQueueHead_0077BDAC;                                                         // 0x0077BDAC

// 0x0043E1A0
static void __stdcall sub_0043E1A0_AddTextLines(D2WinControlStrc* pControl, int bBlankLine, char* szText, int nColor)
{
    char* pText = szText;
    const int nLength = strlen(szText);
    if (nLength > 0)
    {
        while (*pText)
        {
            char* pBreak = 0;
            char* pLine = pText;
            while (*pText != '\n' && *pText)
            {
                pText++;
            }
            if (*pText == '\n')
            {
                pBreak = pText;
                *pText = 0;
                pText++;
            }
            sub_004FCFF0_SetTextA(pControl, pLine, nColor);
            if (bBlankLine)
            {
                sub_004FCFF0_SetTextA(pControl, &gszEmptyAssertText, nColor);
            }
            if (pBreak)
            {
                *pBreak = '\n';
            }
        }
    }
    else
    {
        sub_004FCFF0_SetTextA(pControl, &gszEmptyAssertText, nColor);
    }
}

static D2ChatMessageStrc* sub_0043E370()
{
    D2ChatMessageStrc* pMessage = 0;
    EnterCriticalSection(&gtChatLock_0077AE28);
    if (gpChatQueueHead_0077BDAC)
    {
        pMessage = gpChatQueueHead_0077BDAC;
        gpChatQueueHead_0077BDAC = gpChatQueueHead_0077BDAC->pNext;
    }
    LeaveCriticalSection(&gtChatLock_0077AE28);
    return pMessage;
}

static void sub_0043E2E0(D2ChatMessageStrc* pMessage)
{
    if (pMessage)
    {
        if (pMessage->szText)
        {
            FOG_Free(pMessage->szText, ".\\Src\\ChatDlg.cpp", 0xC38, 0);
        }
        FOG_Free(pMessage, ".\\Src\\ChatDlg.cpp", 0xC39, 0);
    }
}

// 0x0043E3A0
void __cdecl sub_0043E3A0_FlushChatMessages()
{
    for (;;)
    {
        D2ChatMessageStrc* pMessage = sub_0043E370();
        if (!pMessage)
        {
            return;
        }
        if (pMessage->bClear)
        {
            sub_004FB6A0_ClearText(gpChatTextBox_0077BD8C);
        }
        if (pMessage->szText)
        {
            sub_0043E1A0_AddTextLines(gpChatTextBox_0077BD8C, 0, pMessage->szText, pMessage->nColor);
        }
        sub_0043E2E0(pMessage);
        D2Win_10053(gpChatTextBox_0077BD8C, 0);
    }
}
