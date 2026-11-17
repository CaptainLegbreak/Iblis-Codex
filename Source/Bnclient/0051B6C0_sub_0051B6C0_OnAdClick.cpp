struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
};

struct D2StormArray408Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2Storm408ElemStrc* f_8;
    unsigned int f_C;
};

struct D2BigLoginRecordStrc
{
    char szName[0x20];
    char szPassword[0x20];
    unsigned char abPrivate[0x20];
    unsigned char abPublic[0x20];
    unsigned char abKey[0x28];
    unsigned char abProof[0x14];
};

struct D2BigPowModStrc
{
    void* pUnknown0x00;
    void* hBase;
    void* hModulus;

    void sub_00528480_HashThreeBlocks(const unsigned char* pFirst, const unsigned char* pSecond, const unsigned char* pThird, unsigned char* pDigest); // 0x00528480
};

struct D2BigPairStrc
{
    D2BigPowModStrc* pState;

    int sub_00528760_ComputeLoginProof(D2BigLoginRecordStrc* pRecord, const unsigned char* pSalt, const unsigned char* pServerPublic); // 0x00528760
    int sub_00528890_CompareServerProof(const D2BigLoginRecordStrc* pRecord, const unsigned char* pServerProof);
};

struct D2BnAdClickStrc
{
    int nAdId;
    int bFlag;
};

struct D2BnChangeProofStrc
{
    unsigned char abProof[0x14];
    unsigned char abVerifier[0x40];
};

struct D2PacketBufferStrc
{
    unsigned char data[1976];
    int nUsedBytes;
};

struct QServer;

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0
extern "C" __declspec(dllimport) long __stdcall InterlockedExchange(long volatile* pTarget, long nValue);    // 0x006CC3A4
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pThreadAttributes, unsigned long nStackSize, unsigned long (__stdcall* pStartAddress)(void*), void* pParameter, unsigned long nCreationFlags, unsigned long* pThreadId); // 0x006CC250
extern "C" int __cdecl memcmp(const void* pBuffer1, const void* pBuffer2, unsigned int nSize);

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags);                  // 0x00412650
void __stdcall sub_0041D2A0_MemCopy(void* pDst, const void* pSrc, unsigned int nSize);                      // 0x0041D2A0
void __stdcall sub_0041D300_ZeroMemory(void* pDest, unsigned int nSize);                                    // 0x0041D300
void __cdecl sub_00518D40_Log(const char* szFormat, ...);                                                   // 0x00518D40
int __cdecl sub_005193E0_OpenLog();                                                                         // 0x005193E0
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...);                                              // 0x0051A480
int __cdecl sub_0051A570_GetMode();                                                                         // 0x0051A570
int __fastcall sub_0051A7D0_ChangePasswordLegacy(const char* szAccountName, const char* szOldPassword, const char* szNewPassword); // 0x0051A7D0
int __cdecl sub_0051C470_Startup();                                                                         // 0x0051C470
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0
unsigned long __stdcall sub_0051D0A0_ConnectThread(void* pParameter);                                       // 0x0051D0A0
void __cdecl sub_0051D510_ReportNews();                                                                     // 0x0051D510
int __cdecl sub_0051DA30_LoadNews();                                                                        // 0x0051DA30
void __fastcall sub_0051ED00_QueryState(int* pState);                                                       // 0x0051ED00
int __cdecl sub_00520B30_ResetReplies();                                                                    // 0x00520B30
void __fastcall sub_00520C00_ClearReply(unsigned char nReply);                                              // 0x00520C00
void __cdecl sub_00521B50_ReseedLogin();                                                                     // 0x00521B50
int __fastcall sub_005221F0_ChangePasswordProof(const char* szAccountName, const char* szOldPassword, const char* szNewPassword); // 0x005221F0
void __fastcall CLIENT_ReadPacketFromBuffer(D2PacketBufferStrc* pBuffer, int nBufferSize);                  // 0x0052AEB0
int __stdcall sub_0052B330(unsigned char nFlags, int nClientId, void* pPacket, int nSize);                  // 0x0052B330
int __fastcall SERVER_GetClientPacketSize(D2PacketBufferStrc* pBuffer, unsigned int nBufferSize, int* pSize); // 0x0052BC20
int __fastcall sub_006BF6C0(void* pServer, int nClientId);                                                  // 0x006BF6C0

extern "C" const char gszNewsItemTypeName_0072FF8C[];                                                       // 0x0072FF8C
extern int gbDnsPending_008818E0;                                                                           // 0x008818E0
extern long volatile gnConnected_00881BF0;                                                                  // 0x00881BF0
extern long volatile gnDnsDone_00881BFC;                                                                    // 0x00881BFC
int gdwGlobal_00881C04;                                                                                     // 0x00881C04
extern int gbNewsActive_00881C24;                                                                           // 0x00881C24
extern int (__fastcall* gpfnNewsMessage_00881C28)(unsigned int nStamp, const char* szText);                // 0x00881C28
extern int (__cdecl* gpfnNewsRefresh_00881C2C)();                                                           // 0x00881C2C
extern D2StormArray408Strc gtNewsItems_00881C30;                                                            // 0x00881C30
extern unsigned int gnNewsFirstIndex_00881C40;                                                              // 0x00881C40
extern unsigned int gnNewsNewest_00881C44;                                                                  // 0x00881C44
extern unsigned char gabNewVerifier_00882640[0x40];                                                         // 0x00882640
extern D2BigLoginRecordStrc gtLoginRecord_00882680;                                                         // 0x00882680
extern D2BigPairStrc gtBigPair_0088273C;                                                                    // 0x0088273C
extern void* gpGlobal_00882D08;                                                                             // 0x00882D08

// 0x0051B6C0
int __fastcall sub_0051B6C0_OnAdClick(int nAdId, int bFlag)
{
    D2BnAdClickStrc tRecord;
    tRecord.nAdId = nAdId;
    tRecord.bFlag = bFlag != 0;
    sub_0051C5C0_SendPacket(0x16, &tRecord, sizeof(tRecord));
    return 1;
}

// 0x0051C350
int __fastcall sub_0051C350_ChangePassword(const char* szAccountName, const char* szOldPassword, const char* szNewPassword)
{
    switch (sub_0051A570_GetMode())
    {
    case 0:
        sub_00520C00_ClearReply(0x31);
        sub_0051A7D0_ChangePasswordLegacy(szAccountName, szOldPassword, szNewPassword);
        return 1;
    case 1:
        sub_00520C00_ClearReply(0x56);
        return sub_005221F0_ChangePasswordProof(szAccountName, szOldPassword, szNewPassword);
    }
    return 0;
}

// 0x0051D1C0
void* __cdecl sub_0051D1C0_OpenBNetConnection()
{
    unsigned long nThreadId;
    sub_00518D40_Log("Connecting to Battle.net...");
    if (InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0))
    {
        sub_0051A480_DebugLog("   already connected");
        return 0;
    }
    if (!sub_0051C470_Startup())
        return 0;
    InterlockedExchange(&gnDnsDone_00881BFC, 0);
    gbDnsPending_008818E0 = 0;
    Sleep(10);
    sub_005193E0_OpenLog();
    sub_00520B30_ResetReplies();
    sub_00521B50_ReseedLogin();
    gdwGlobal_00881C04 = 0;
    return CreateThread(0, 0, sub_0051D0A0_ConnectThread, 0, 0, &nThreadId);
}

// 0x0051DBF0
int __fastcall sub_0051DBF0_LoadBNetNews(int (__fastcall* pfnMessage)(unsigned int nStamp, const char* szText), int (__cdecl* pfnRefresh)())
{
    gbNewsActive_00881C24 = 1;
    gpfnNewsMessage_00881C28 = pfnMessage;
    gpfnNewsRefresh_00881C2C = pfnRefresh;
    if (gtNewsItems_00881C30.f_8)
        SMemFree(gtNewsItems_00881C30.f_8, gszNewsItemTypeName_0072FF8C, -2, 0);
    gtNewsItems_00881C30.f_0 = 0;
    gtNewsItems_00881C30.f_4 = 0;
    gtNewsItems_00881C30.f_8 = 0;
    gnNewsNewest_00881C44 = 0;
    gnNewsFirstIndex_00881C40 = 0;
    if (sub_0051DA30_LoadNews())
        sub_0051D510_ReportNews();
    unsigned int nStamp = gnNewsNewest_00881C44;
    sub_0051C5C0_SendPacket(0x46, &nStamp, sizeof(nStamp));
    return 1;
}

// 0x0051F2D0
int __fastcall sub_0051F2D0_PatchUnk(int* pResult)
{
    int nState;
    sub_0051ED00_QueryState(&nState);
    switch (nState)
    {
    case 0:
        return 1;
    case 1:
        return 1;
    case 2:
        *pResult = 1;
        break;
    }
    return 0;
}

// 0x005220B0
int __fastcall sub_005220B0_SendLogonProof(const unsigned char* pSalt, const unsigned char* pServerPublic)
{
    unsigned char abProof[0x14];
    const int bResult = gtBigPair_0088273C.sub_00528760_ComputeLoginProof(&gtLoginRecord_00882680, pSalt, pServerPublic);
    sub_0041D300_ZeroMemory(gtLoginRecord_00882680.szPassword, sizeof(gtLoginRecord_00882680.szPassword));
    if (bResult)
    {
        sub_0041D2A0_MemCopy(abProof, gtLoginRecord_00882680.abProof, sizeof(abProof));
        sub_0051C5C0_SendPacket(0x54, abProof, sizeof(abProof));
        return 1;
    }
    return 0;
}

// 0x00522310
int __fastcall sub_00522310_SendChangeProof(const unsigned char* pSalt, const unsigned char* pServerPublic)
{
    D2BnChangeProofStrc tPacket;
    const int bResult = gtBigPair_0088273C.sub_00528760_ComputeLoginProof(&gtLoginRecord_00882680, pSalt, pServerPublic);
    sub_0041D300_ZeroMemory(gtLoginRecord_00882680.szPassword, sizeof(gtLoginRecord_00882680.szPassword));
    if (bResult)
    {
        sub_0041D2A0_MemCopy(tPacket.abProof, gtLoginRecord_00882680.abProof, sizeof(tPacket.abProof));
        sub_0041D2A0_MemCopy(tPacket.abVerifier, gabNewVerifier_00882640, sizeof(tPacket.abVerifier));
        sub_0041D300_ZeroMemory(gabNewVerifier_00882640, sizeof(gabNewVerifier_00882640));
        sub_0051C5C0_SendPacket(0x56, &tPacket, sizeof(tPacket));
        return 1;
    }
    return 0;
}

// 0x00528890
int D2BigPairStrc::sub_00528890_CompareServerProof(const D2BigLoginRecordStrc* pRecord, const unsigned char* pServerProof)
{
    unsigned char abProof[0x14];
    pState->sub_00528480_HashThreeBlocks(pRecord->abPublic, pRecord->abProof, pRecord->abKey, abProof);
    return memcmp(abProof, pServerProof, sizeof(abProof)) == 0;
}

// 0x0052B0E0
int __fastcall sub_0052B0E0(QServer* pUnused, D2PacketBufferStrc* pPacketBuffer, int nBufferSize)
{
    CLIENT_ReadPacketFromBuffer(pPacketBuffer, nBufferSize);
    return 1;
}

// 0x0052B100
int __fastcall SERVER_ValidateClientPacket(D2PacketBufferStrc* pPacketBuffer, int nBufferSize, int* pPacketSize, int* pFlags, int* pType, int* pPriority, int nUnused1, int nUnused2, int nClientId)
{
    if (nBufferSize < sizeof(unsigned char))
        return 3;
    const unsigned char nHeader = pPacketBuffer->data[0];
    int nSize;
    if (SERVER_GetClientPacketSize(pPacketBuffer, nBufferSize, &nSize))
    {
        if (nHeader >= 0x71 && nHeader != 0xFF)
            return 4;
        if ((unsigned short)nSize > 0x204)
            return 4;
        const int nPacketSize = (unsigned short)nSize;
        if (nPacketSize <= nBufferSize)
        {
            *pFlags = 0;
            *pPacketSize = nPacketSize;
            if (nHeader < 0x67)
            {
                *pType = 1;
            }
            else if (nHeader < 0x71)
            {
                *pType = 0;
            }
            else
            {
                if (!sub_006BF6C0(gpGlobal_00882D08, nClientId))
                    return 4;
                *pType = 2;
            }
            *pPriority = 100;
            if (*pType == 0)
                return 2;
            if (*pType == 1)
                return 1;
            return *pType == 2 ? 1 : 2;
        }
    }
    return 3;
}

// 0x0052B720
int __fastcall sub_6FC020B0(QServer* pServer, int nClientId, const char* szFile, int nLine)
{
    unsigned char data[2];
    data[0] = 0xAF;
    data[1] = 1;
    sub_0052B330(0, nClientId, data, sizeof(data));
    return 1;
}
