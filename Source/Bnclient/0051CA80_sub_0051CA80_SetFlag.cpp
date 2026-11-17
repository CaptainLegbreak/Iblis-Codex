struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
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

struct D2BigPowModStrc;

struct D2BigPairStrc
{
    D2BigPowModStrc* pState;

    int sub_00528890_CompareServerProof(const D2BigLoginRecordStrc* pRecord, const unsigned char* pServerProof); // 0x00528890
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __stdcall sub_0041D300_ZeroMemory(void* pDest, unsigned int nSize);                                    // 0x0041D300

extern int gdwGlobal_00881C04;                                                                              // 0x00881C04
extern char gszEmptyStateText_00881F80[];                                                                   // 0x00881F80
extern D2CriticalSectionStrc gMessageLock_00882004;                                                         // 0x00882004
extern int gnBnState_0088201C;                                                                              // 0x0088201C
char gData_00882028[256];                                                                                   // 0x00882028
extern D2BigLoginRecordStrc gtLoginRecord_00882680;                                                         // 0x00882680
extern D2BigPairStrc gtBigPair_0088273C;                                                                    // 0x0088273C

// 0x0051CA80
void __fastcall sub_0051CA80_SetFlag(int nValue)
{
    gdwGlobal_00881C04 = nValue;
}

// 0x005204D0
int __fastcall sub_005204D0_SetErrorText(int nError, const char* szText)
{
    EnterCriticalSection(&gMessageLock_00882004);
    if (!gnBnState_0088201C)
    {
        gnBnState_0088201C = nError;
        SStrCopy(gszEmptyStateText_00881F80, szText, 0x80);
    }
    LeaveCriticalSection(&gMessageLock_00882004);
    return 1;
}

// 0x00520630
int __fastcall sub_00520630_SetText(const char* szText)
{
    SStrCopy(gData_00882028, szText, 0x100);
    return 1;
}

// 0x005224C0
int __fastcall sub_005224C0_CheckServerProof(const unsigned char* pServerProof)
{
    return gtBigPair_0088273C.sub_00528890_CompareServerProof(&gtLoginRecord_00882680, pServerProof);
}

// 0x005224F0
void __cdecl sub_005224F0_ClearPassword()
{
    sub_0041D300_ZeroMemory(gtLoginRecord_00882680.szPassword, sizeof(gtLoginRecord_00882680.szPassword));
}
