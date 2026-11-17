extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
int __fastcall sub_00520BF0_IsReplyReceived(unsigned char nReply);                                          // 0x00520BF0

static void* gpReply_008818D8;                                                                              // 0x008818D8

struct D2BnReadUserDataReplyStrc
{
    unsigned int nAccounts;
    unsigned int nKeys;
    unsigned int nCookie;
    char aData[1];
};

// 0x0051B960
int __fastcall sub_0051B960_GetReadUserDataReply(unsigned int nKeys, unsigned int nCookie, char** ppValues, const unsigned int* pSizes)
{
    if (!sub_00520BF0_IsReplyReceived(0x26))
        return 0;

    D2BnReadUserDataReplyStrc* pReply = (D2BnReadUserDataReplyStrc*)gpReply_008818D8;
    if (!pReply || pReply->nAccounts != 1 || pReply->nKeys != nKeys || pReply->nCookie != nCookie)
        return 0;

    const char* pText = pReply->aData;
    for (unsigned int i = 0; i < nKeys; ++i)
    {
        if (*pText)
        {
            strncpy(ppValues[i], pText, pSizes[i]);
            const unsigned int nSize = pSizes[i];
            ppValues[i][nSize] = 0;
        }
        else
        {
            *ppValues[i] = 0;
        }
        pText += SStrLen(pText) + 1;
    }
    return 1;
}
