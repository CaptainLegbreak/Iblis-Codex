enum D2ControlTypes
{
    D2WIN_LIST = 7,
    D2WIN_ACCOUNTLIST = 12,
};

struct Unicode
{
    unsigned short wChar;
};

struct D2CelFileStrc;
struct D2WinControlStrc;
struct SMSGHANDLER_PARAMS;

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);
typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct D2WinControlStrc
{
    int nType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    D2WinControlFn pfDraw;
    D2WinControlFn pfInitialize;
    D2WinMsgHandler pfHandleMouseDown;
    D2WinMsgHandler pfHandleMouseUp;
    D2WinMsgHandler pfHandleCharInput;
    D2WinMsgHandler pfHandleVirtualKeyInput;
    D2WinMsgHandler field_34;
    D2WinControlFn pfShouldMouseInputBeHandled;
    D2WinControlStrc* pNext;
};

struct D2WinListDataStrc
{
    Unicode wszText[256];
    int unk0x200[8];
    D2WinListDataStrc* pNext;
};

struct D2WinListStrc
{
    D2WinControlStrc controlHeader;
    int unk0x40[4];
    int field_50;
    int unk0x54[4];
    D2WinListDataStrc* pDataList;
    D2WinListDataStrc* pSelectedDataEntry;
};

struct D2WinAccountListDataStrc
{
    char szText[50];
    short field_32;
    D2WinAccountListDataStrc* pNext;
};

struct D2WinAccountListStrc
{
    D2WinControlStrc controlHeader;
    D2WinAccountListDataStrc* pDataList;
    D2WinAccountListDataStrc* pSelectedDataEntry;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

// 0x00507000
int __fastcall LIST_GetSelectedDataIndex(D2WinListStrc* pList)
{
    D2_ASSERT(pList->controlHeader.nType == D2WIN_LIST, 0xD2);
    int nIndex = 0;
    D2WinListDataStrc* pData = pList->pDataList;
    while (pData)
    {
        if (pList->pSelectedDataEntry == pData)
        {
            break;
        }
        pData = pData->pNext;
        ++nIndex;
    }
    if (pData)
    {
        return nIndex;
    }
    return -1;
}

// 0x00507050
D2WinListDataStrc* __fastcall LIST_GetDataFromIndex(D2WinListStrc* pList, int nIndex)
{
    D2_ASSERT(pList->controlHeader.nType == D2WIN_LIST, 0xE5);
    int nCounter = 0;
    D2WinListDataStrc* pData = pList->pDataList;
    while (pData)
    {
        if (nCounter == nIndex)
        {
            break;
        }
        pData = pData->pNext;
        ++nCounter;
    }
    if (pData)
    {
        return pData;
    }
    return 0;
}

// 0x005070A0
int __fastcall D2Win_10141(D2WinListStrc* pList)
{
    D2_ASSERT(pList->controlHeader.nType == D2WIN_LIST, 0xF8);
    return pList->field_50;
}

// 0x005078A0
void __fastcall ACCOUNTLIST_AllocData(D2WinAccountListStrc* pAccountList, const char* szText)
{
    D2_ASSERT(pAccountList->controlHeader.nType == D2WIN_ACCOUNTLIST, 0x72);
    D2WinAccountListDataStrc* pData = (D2WinAccountListDataStrc*)FOG_Alloc(sizeof(D2WinAccountListDataStrc), ".\\Src\\D2WinAccountList.cpp", 0x77, 0);
    strncpy(pData->szText, szText, sizeof(pData->szText));
    pData->pNext = pAccountList->pDataList;
    pAccountList->pDataList = pData;
}

// 0x005079C0
int __fastcall ACCOUNTLIST_GetTextFromSelectedEntry(D2WinAccountListStrc* pAccountList, char* szBuffer)
{
    D2_ASSERT(pAccountList->controlHeader.nType == D2WIN_ACCOUNTLIST, 0xB9);
    const char* szText = pAccountList->pSelectedDataEntry->szText;
    if (szText)
    {
        char c;
        do
        {
            c = *szText;
            *szBuffer = c;
            ++szText;
            ++szBuffer;
        }
        while (c);
        return 1;
    }
    return 0;
}
