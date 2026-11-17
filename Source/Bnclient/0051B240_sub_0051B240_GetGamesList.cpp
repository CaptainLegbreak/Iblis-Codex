struct D2BnGamesListPacketStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int nCount;
    char szText[0x100];
};

struct D2BnAuthHashStrc
{
    int f_0;
    int f_4;
    unsigned char abPasswordHash[0x14];
};

struct D2BnLogonRealmPacketStrc
{
    int f_0;
    unsigned char abProof[0x14];
    char szRealmName[0x100];
};

struct D2BnSizedReplyStrc
{
    unsigned int nSize;
    unsigned char abData[0x14];
    unsigned int nValue;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" unsigned int __cdecl strlen(const char* szString);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                 // 0x004135D0
void __fastcall sub_005209D0_HashData(unsigned char* pDigest, const void* pData, unsigned int nLength);     // 0x005209D0
void __fastcall sub_00520C00_ClearReply(unsigned char nReply);                                              // 0x00520C00
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0
int __fastcall sub_00520B70_WaitForReply(unsigned char nReply);                                             // 0x00520B70

int gnClientToken_008818C4;                                                                                 // 0x008818C4
extern int gdwGlobal_008818BC;                                                                              // 0x008818BC
extern void* gpReply_008818D0;                                                                              // 0x008818D0
extern D2BnSizedReplyStrc* gpSizedReply_008818D4;                                                           // 0x008818D4

// 0x0051B240
void* __fastcall sub_0051B240_GetGamesList(const char* szGameName, const char* szGamePassword, int a3, int a4)
{
    D2BnGamesListPacketStrc tPacket;
    tPacket.unk0x00 = 0;
    tPacket.unk0x04 = 0;
    tPacket.unk0x08 = 0;
    tPacket.nCount = 0x19;

    char* pText = tPacket.szText;
    if (szGameName)
    {
        pText += SStrCopy(pText, szGameName, 0x100) + 1;
    }
    else
    {
        pText += SStrCopy(pText, &gszEmptyAssertText, 0x100) + 1;
    }

    if (szGamePassword)
    {
        pText += SStrCopy(pText, szGamePassword, 0x100) + 1;
    }
    else
    {
        pText += SStrCopy(pText, &gszEmptyAssertText, 0x100) + 1;
    }

    const int nLength = SStrCopy(pText, &gszEmptyAssertText, 0x100);
    const int nSize = (int)(pText - tPacket.szText) + nLength + 1 + 0x10;

    sub_00520C00_ClearReply(9);
    sub_0051C5C0_SendPacket(9, &tPacket, nSize);
    sub_00520B70_WaitForReply(9);
    return gpReply_008818D0;
}

// 0x0051B460
D2BnSizedReplyStrc* __fastcall sub_0051B460_LogonRealm(const char* szRealmName, const char* szRealmPassword)
{
    if (!szRealmName)
    {
        return 0;
    }

    D2BnAuthHashStrc tHash;
    gnClientToken_008818C4 += 1;
    tHash.f_0 = gnClientToken_008818C4;
    tHash.f_4 = gdwGlobal_008818BC;
    sub_005209D0_HashData(tHash.abPasswordHash, szRealmPassword, strlen(szRealmPassword));

    D2BnLogonRealmPacketStrc tPacket;
    tPacket.f_0 = gnClientToken_008818C4;
    sub_005209D0_HashData(tPacket.abProof, &tHash, 0x1C);
    const int nLength = SStrCopy(tPacket.szRealmName, szRealmName, 0x100) + 1;

    sub_00520C00_ClearReply(0x3E);
    if (sub_0051C5C0_SendPacket(0x3E, &tPacket, nLength + 0x18) < 0)
    {
        return 0;
    }

    sub_00520B70_WaitForReply(0x3E);
    return gpSizedReply_008818D4;
}
