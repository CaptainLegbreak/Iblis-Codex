extern "C" unsigned int __cdecl strlen(const char* szString);

int __cdecl sub_0051BEC0_IsExpansion();                                                                     // 0x0051BEC0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0
int __fastcall sub_00520B70_WaitForReply(unsigned char nReply);                                             // 0x00520B70
void __fastcall sub_00520C00_ClearReply(unsigned char nReply);                                              // 0x00520C00
int __stdcall sub_006C7130_FromWide(char* pDst, unsigned int nDstSize, const unsigned short* pSrc, unsigned int nCount, unsigned int* pnWritten, int nFlags); // 0x006C7130
int __stdcall sub_006C7960_ToWide(unsigned short* pDst, const char* szSrc, unsigned int nCount);            // 0x006C7960

extern int gnChannelList_008818C8;                                                                          // 0x008818C8
extern char* gpAdUrlReply_008818DC;                                                                         // 0x008818DC

// 0x0051ABB0
char* __fastcall sub_0051ABB0_QueryAdUrl(int nAdId)
{
    sub_00520C00_ClearReply(0x41);
    if (sub_0051C5C0_SendPacket(0x41, &nAdId, 4) < 0)
    {
        return 0;
    }

    sub_00520B70_WaitForReply(0x41);
    if (!gpAdUrlReply_008818DC)
    {
        return 0;
    }

    return gpAdUrlReply_008818DC + 4;
}

// 0x0051AC50
int __fastcall sub_0051AC50_GetChannelList(int bNoExpansion)
{
    unsigned int nFlags = 0;
    if (sub_0051BEC0_IsExpansion() && !bNoExpansion)
    {
        nFlags |= 1;
    }

    sub_00520C00_ClearReply(0x0B);
    sub_0051C5C0_SendPacket(0x0B, &nFlags, 4);
    sub_00520B70_WaitForReply(0x0B);
    return gnChannelList_008818C8;
}

// 0x0051AF40
int __fastcall sub_0051AF40_ChatCommand(const char* szText)
{
    if (!szText || !strlen(szText))
    {
        return 0;
    }

    unsigned short wszText[0x200];
    unsigned int nLength = sub_006C7960_ToWide(wszText, szText, 0x1FF);
    if (!nLength)
    {
        return 0;
    }

    wszText[nLength] = 0;

    char szBuffer[0x200];
    if (sub_006C7130_FromWide(szBuffer, 0x1FF, wszText, 0x1FF, &nLength, 0))
    {
        return 0;
    }

    szBuffer[nLength] = 0;
    return sub_0051C5C0_SendPacket(0x0E, szBuffer, nLength) >= 0;
}
