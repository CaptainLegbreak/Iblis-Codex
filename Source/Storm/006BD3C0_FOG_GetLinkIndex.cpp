struct D2TxtLinkNodeStrc
{
    char szText[0x20];
    int nLinkIndex;
    D2TxtLinkNodeStrc* pPrevious;
    D2TxtLinkNodeStrc* pNext;
};

struct D2TxtLinkStrc
{
    int nRecords;
    int unk0x04[2];
    D2TxtLinkNodeStrc* pFirstNode;
};

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

extern "C" const char gszEmptyAssertText_006CC837;                                                          // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __fastcall sub_004113C0(char* szText, int nLength);                                                    // 0x004113C0

// 0x006BD3C0
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLink, const char* szText, int bLogError)
{
    char szKey[0x20];
    SStrCopy(szKey, szText, sizeof(szKey));
    sub_004113C0(szKey, sizeof(szKey));

    D2TxtLinkNodeStrc* pNode = pLink->pFirstNode;
    if (pLink->nRecords && !pNode)
    {
        sub_00408A60(&gszEmptyAssertText_006CC837, sub_00408090(), 0x475);
        exit(-1);
    }

    while (pNode)
    {
        const int nCompare = strcmp(szKey, pNode->szText);
        if (!nCompare)
        {
            return pNode->nLinkIndex;
        }

        if (nCompare < 0)
        {
            pNode = pNode->pPrevious;
        }
        else
        {
            pNode = pNode->pNext;
        }
    }

    return -1;
}
