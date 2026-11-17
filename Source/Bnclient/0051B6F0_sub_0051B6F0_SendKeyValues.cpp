struct D2BnKeyValuePacketStrc
{
    int nType;
    unsigned int nCount;
    char szText[1];
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0
void __fastcall sub_00520C00_ClearReply(unsigned char nReply);                                              // 0x00520C00

// 0x0051B6F0
int __fastcall sub_0051B6F0_SendKeyValues(const char* szName, unsigned int nCount, const char** ppKeys, const char** ppValues)
{
    unsigned int nSize = SStrLen(szName) + 1;
    for (unsigned int i = 0; i < nCount; ++i)
    {
        nSize += SStrLen(ppKeys[i]) + 1;
        nSize += SStrLen(ppValues[i]) + 1;
    }

    D2BnKeyValuePacketStrc* pPacket = (D2BnKeyValuePacketStrc*)FOG_Alloc(nSize + 8, ".\\BnSend.cpp", 0x4C4, 0);
    pPacket->nType = 1;
    pPacket->nCount = nCount;

    char* pText = pPacket->szText;
    pText += SStrCopy(pText, szName, 0x7FFFFFFF) + 1;

    unsigned int i;
    for (i = 0; i < nCount; ++i)
    {
        pText += SStrCopy(pText, ppKeys[i], 0x7FFFFFFF) + 1;
    }

    for (i = 0; i < nCount; ++i)
    {
        pText += SStrCopy(pText, ppValues[i], 0x7FFFFFFF) + 1;
    }

    sub_00520C00_ClearReply(0x27);
    int bResult = sub_0051C5C0_SendPacket(0x27, pPacket, (unsigned int)(pText - (char*)pPacket)) >= 0;
    FOG_Free(pPacket, ".\\BnSend.cpp", 0x4E0, 0);
    return bResult;
}
