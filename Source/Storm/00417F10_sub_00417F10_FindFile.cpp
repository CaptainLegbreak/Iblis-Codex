extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2StormMpqHeaderStrc
{
    unsigned int dwSignature;

    unsigned int nHeaderSize;
    unsigned int nArchiveSize;
    unsigned short wVersion;
    unsigned char nSectorShift;
    unsigned char unk0x0F;
    unsigned int nHashOffset;
    unsigned int nBlockOffset;
    unsigned int nHashEntries;
    unsigned int nBlockEntries;
};

struct D2StormHashEntryStrc
{
    unsigned int nName1;
    unsigned int nName2;

    unsigned short wLocale;
    unsigned char nPlatform;
    unsigned char unk0x0B;
    int nBlockIndex;
};

struct D2StormBlockStrc
{
    unsigned int nOffset;
    unsigned int nPackedSize;

    unsigned int nFileSize;
    unsigned int dwFlags;
    unsigned int unk0x10;
    unsigned int unk0x14;
    unsigned int nCrc;
    unsigned int unk0x1C[4];

    void sub_004156A0_ExpandEntries(unsigned int nCount);                                                    // 0x004156A0
};

struct D2StormFileRecStrc;

struct D2StormArchiveRecStrc
{
    D2StormLinkStrc tLink;

    char szName[0x104];
    void* hFile;
    int nMode;
    int bNoDiskSearch;
    int nPriority;
    D2StormFileRecStrc* pCachedFile;
    unsigned int nCachedOffset;
    unsigned int nBlockSize;
    unsigned char* pBlockBuffer;
    unsigned int nCachedSize;
    unsigned int nArchiveOffset;
    unsigned int nArchiveLimit;
    D2StormMpqHeaderStrc* pHeader;
    D2StormBlockStrc* pBlockTable;
    D2StormHashEntryStrc* pHashTable;
    unsigned int nFilePos;
    int bNested;
    void* hNestedFile;
    D2StormArchiveRecStrc* pPatch;
    char szPrefix[0x104];
    int nRefs;

    D2StormArchiveRecStrc()
    {
        tLink.m_prevlink = 0;
        tLink.m_next = 0;
    }
    ~D2StormArchiveRecStrc();                                                                                // 0x00418A50
    void sub_0041B0B0_LoadAttributes(D2StormBlockStrc* pBlockTable, unsigned int nCount);                    // 0x0041B0B0
};

struct D2StormFileRecStrc
{
    D2StormLinkStrc tLink;

    char szName[0x108];
    void* hFile;
    D2StormArchiveRecStrc* pArchive;
    D2StormBlockStrc* pBlock;
    unsigned int nKey;
    unsigned int nPosition;
    int unk0x124;
    unsigned int nBlocks;
    unsigned int* pBlockOffsets;
    int bOffsetsLoaded;
    char pad0x134[0x10];
    int nRequests;
    unsigned int nCrc;
    int bCrc;
    int nCrcState;
    unsigned int nCrcPos;
};

struct D2StormSoundBufferStrc
{
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCaps(void* pCaps) = 0;
    virtual long __stdcall GetCurrentPosition(unsigned long* pnPlay, unsigned long* pnWrite) = 0;
    virtual long __stdcall GetFormat(void* pFormat, unsigned long nSize, unsigned long* pnWritten) = 0;
    virtual long __stdcall GetVolume(long* pnVolume) = 0;
    virtual long __stdcall GetPan(long* pnPan) = 0;
    virtual long __stdcall GetFrequency(unsigned long* pnFrequency) = 0;
    virtual long __stdcall GetStatus(unsigned long* pnStatus) = 0;
    virtual long __stdcall Initialize(void* pDirectSound, const void* pDesc) = 0;
    virtual long __stdcall Lock(unsigned long nOffset, unsigned long nBytes, void** ppPtr1, unsigned long* pnBytes1, void** ppPtr2, unsigned long* pnBytes2, unsigned long nFlags) = 0;
    virtual long __stdcall Play(unsigned long nReserved, unsigned long nPriority, unsigned long nFlags) = 0;
    virtual long __stdcall SetCurrentPosition(unsigned long nPosition) = 0;
    virtual long __stdcall SetFormat(const void* pFormat) = 0;
    virtual long __stdcall SetVolume(long nVolume) = 0;
    virtual long __stdcall SetPan(long nPan) = 0;
    virtual long __stdcall SetFrequency(unsigned long nFrequency) = 0;
    virtual long __stdcall Stop() = 0;
    virtual long __stdcall Unlock(void* pPtr1, unsigned long nBytes1, void* pPtr2, unsigned long nBytes2) = 0;
};

struct D2StormStreamStrc
{
    D2StormLinkStrc tLink;

    D2StormFileRecStrc* pFile;
    unsigned int nWritePos;
    int unk0x10;
    int bRestart;
    int nState;
    unsigned int nCounter;
    unsigned int nStart;
    unsigned int nSize;
    unsigned int nOffset;
    unsigned int nPlayed;
    unsigned int nWritten;
    int nVolume;
    int nPan;
    D2StormSoundBufferStrc* pBuffer;
    unsigned int nBufferSize;
    int unk0x44;
    unsigned char nFill;
    char pad0x49[3];
    int nRefs;
};

struct D2StormRequestCallbackStrc
{
    void (__stdcall* pfnDone)(unsigned int nSize, unsigned char* pEnd, D2StormRequestCallbackStrc* pCallback);
};

struct D2StormRequestStrc
{
    D2StormLinkStrc tLink;

    void* hEvent;
    D2StormFileRecStrc* pFile;
    unsigned int nPosition;
    unsigned int nFileOffset;
    unsigned int nDueTime;
    int nArg9;
    unsigned char* pDest;
    unsigned int nDestSize;
    D2StormSoundBufferStrc* pBuffer;
    unsigned int nBufferOffset;
    D2StormStreamStrc* pStream;
    unsigned int nBytes;
    int bDelete;
    unsigned int nRead;
    D2StormRequestCallbackStrc* pCallback;

    ~D2StormRequestStrc();                                                                                  // 0x0041A020
};

struct D2StormArchiveListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormArchiveRecStrc* Head()
    {
        return (D2StormArchiveRecStrc*)m_terminator.Next();
    }
    void LinkBefore(D2StormArchiveRecStrc* pNode, D2StormArchiveRecStrc* pExisting)
    {
        pNode->tLink.Unlink();
        D2StormLinkStrc* pExistingLink = pExisting ? &pExisting->tLink : &m_terminator;
        D2StormLinkStrc* pPrevLink = pExistingLink->m_prevlink;
        pNode->tLink.m_prevlink = pPrevLink;
        pNode->tLink.m_next = pPrevLink->m_next;
        pPrevLink->m_next = (char*)pNode;
        pExistingLink->m_prevlink = &pNode->tLink;
    }
};

struct D2StormEventStrc
{
    D2StormLinkStrc tLink;
    void* hEvent;
};

struct D2StormEventListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* sub_00419690_DeleteNode(char* pNode);                                                             // 0x00419690
};

struct D2StormCryptFuncsStrc
{
    int (__stdcall* pfnAcquireContext)(unsigned int* phProv, const char* szContainer, const char* szProvider, unsigned int nProvType, unsigned int nFlags);
    int (__stdcall* pfnCreateHash)(unsigned int hProv, unsigned int nAlgId, unsigned int hKey, unsigned int nFlags, unsigned int* phHash);
    int (__stdcall* pfnDestroyHash)(unsigned int hHash);
    int (__stdcall* pfnDestroyKey)(unsigned int hKey);
    int (__stdcall* pfnHashData)(unsigned int hHash, const unsigned char* pData, unsigned int nSize, unsigned int nFlags);
    int (__stdcall* pfnImportKey)(unsigned int hProv, const void* pKey, unsigned int nSize, unsigned int hPubKey, unsigned int nFlags, unsigned int* phKey);
    int (__stdcall* pfnReleaseContext)(unsigned int hProv, unsigned int nFlags);
    int (__stdcall* pfnSignHash)(unsigned int hHash, unsigned int nKeySpec, const char* szDesc, unsigned int nFlags, unsigned char* pSig, unsigned int* pnSigLen);
    int (__stdcall* pfnVerifySignature)(unsigned int hHash, const unsigned char* pSig, unsigned int nSigLen, unsigned int hKey, const char* szDesc, unsigned int nFlags);

};

typedef int (__stdcall* D2CryptAcquireContextFn)(unsigned int*, const char*, const char*, unsigned int, unsigned int);
typedef int (__stdcall* D2CryptCreateHashFn)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
typedef int (__stdcall* D2CryptDestroyFn)(unsigned int);
typedef int (__stdcall* D2CryptHashDataFn)(unsigned int, const unsigned char*, unsigned int, unsigned int);
typedef int (__stdcall* D2CryptImportKeyFn)(unsigned int, const void*, unsigned int, unsigned int, unsigned int, unsigned int*);
typedef int (__stdcall* D2CryptReleaseContextFn)(unsigned int, unsigned int);
typedef int (__stdcall* D2CryptSignHashFn)(unsigned int, unsigned int, const char*, unsigned int, unsigned char*, unsigned int*);
typedef int (__stdcall* D2CryptVerifySignatureFn)(unsigned int, const unsigned char*, unsigned int, unsigned int, const char*, unsigned int);

struct D2StormSignatureKeyStrc
{
    const char* szResourceName;
    unsigned int nResult;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();                                    // 0x006CC1B4
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName);        // 0x006CC1B0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long nMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName);                   // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);     // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule);                                  // 0x006CC14C
extern "C" __declspec(dllimport) void* __stdcall CreateFileMappingA(void* hFile, void* pAttributes, unsigned long nProtect, unsigned long nSizeHigh, unsigned long nSizeLow, const char* szName); // 0x006CC314
extern "C" __declspec(dllimport) void* __stdcall MapViewOfFile(void* hMapping, unsigned long nAccess, unsigned long nOffsetHigh, unsigned long nOffsetLow, unsigned long nBytes); // 0x006CC310
extern "C" __declspec(dllimport) int __stdcall UnmapViewOfFile(const void* pView);                          // 0x006CC2F8
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) void* __stdcall FindResourceA(void* hModule, const char* szName, const char* szType); // 0x006CC30C
extern "C" __declspec(dllimport) void* __stdcall LoadResource(void* hModule, void* hResInfo);               // 0x006CC308
extern "C" __declspec(dllimport) void* __stdcall LockResource(void* hResData);                              // 0x006CC304
extern "C" __declspec(dllimport) unsigned long __stdcall SizeofResource(void* hModule, void* hResInfo);     // 0x006CC300
extern "C" __declspec(dllimport) int __stdcall FreeResource(void* hResData);                                // 0x006CC2FC
extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385
extern "C" char* __cdecl strstr(const char* szString, const char* szSubString);                             // 0x00686900
extern "C" char* __cdecl _fullpath(char* szAbsPath, const char* szRelPath, unsigned int nMaxLength);        // 0x006867F7
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith);                    // 0x0041D2C0
const char* __stdcall SStrChrR(const char* szString, char nChar);                                           // 0x004134D0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __fastcall sub_0041D810_Crc32(const unsigned char* pData, unsigned int nSize, unsigned int* pCrc, unsigned char nFlags); // 0x0041D810
void __cdecl sub_004158E0_InitBasePath();                                                                   // 0x004158E0
int __cdecl sub_00418B50();                                                                         // 0x00418B50
void* __cdecl sub_0041BEF0_GetExeModule();                                                                  // 0x0041BEF0
void __cdecl sub_0041A880_StartThread();                                                                    // 0x0041A880
void __cdecl sub_00419C00_PumpStreams();
int __stdcall sub_004198D0(void* pArg);                                                                     // 0x004198D0
int __stdcall SFileCloseArchive(void* hMpq);                                                                // 0x00419A80
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, int nSearchScope, void** phFile);
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq);
int __stdcall sub_00415BB0_CheckAuthentication(void* hArchive, unsigned int* pnResult, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00415BB0
unsigned int __stdcall sub_00416AD0_ReadBlocks(D2StormFileRecStrc* pFile, unsigned int nOffset, unsigned char* pBuffer, unsigned int nSize);
void __stdcall sub_0041A450_PickRequest(D2StormArchiveRecStrc* pLastArchive, unsigned int nLastOffset, D2StormRequestStrc** ppDue, D2StormRequestStrc** ppNear, int* pnDistance); // 0x0041A450

extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068
extern unsigned int* gpCryptTable_00779048;                                                                 // 0x00779048
extern int gnValueA_0070834C;                                                                               // 0x0070834C
extern int (__stdcall* gpfnReadErrorCallback_00779030)(const char* szName, unsigned long dwError, int nRetry); // 0x00779030
extern char gszBasePath_00778F28[];                                                                         // 0x00778F28
extern "C" const char gszPathJoinFormat_006CE200[];                                                         // 0x006CE200
extern "C" const char gszDriveRoot_006CF09C[];                                                              // 0x006CF09C
extern "C" const char gszUncPrefix_006CF098[];                                                              // 0x006CF098
extern "C" const char gszBackslash_006FF9B8[];                                                              // 0x006FF9B8
extern "C" const char gszSFileCpp_006CF084[];                                                               // 0x006CF084
extern "C" const char gszDelete_006CC824[];                                                                 // 0x006CC824
extern "C" const char gszSignatureName_006CF18C[];                                                          // 0x006CF18C
extern "C" const char gszHashTableKey_006CF1D8[];                                                           // 0x006CF1D8
extern "C" const char gszBlockTableKey_006CF1C8[];                                                          // 0x006CF1C8
extern "C" const char gszAdvapi32_006CCA1C[];                                                               // 0x006CCA1C
extern "C" const char gszCryptAcquireContextA_006CF174[];                                                   // 0x006CF174
extern "C" const char gszCryptCreateHash_006CF164[];                                                        // 0x006CF164
extern "C" const char gszCryptDestroyHash_006CF150[];                                                       // 0x006CF150
extern "C" const char gszCryptDestroyKey_006CF140[];                                                        // 0x006CF140
extern "C" const char gszCryptHashData_006CF130[];                                                          // 0x006CF130
extern "C" const char gszCryptImportKey_006CF120[];                                                         // 0x006CF120
extern "C" const char gszCryptReleaseContext_006CF10C[];                                                    // 0x006CF10C
extern "C" const char gszCryptSignHashA_006CF0FC[];                                                         // 0x006CF0FC
extern "C" const char gszCryptVerifySignatureA_006CF0E4[];                                                  // 0x006CF0E4
extern "C" const char gszCryptProvider_006CF0B8[];                                                          // 0x006CF0B8
extern "C" const char gszCryptContainer_006CF0A8[];                                                         // 0x006CF0A8
extern "C" const char gszKeyResourceType_006CF0A0[];                                                        // 0x006CF0A0
extern const D2StormSignatureKeyStrc gaSignatureKeys_006CF07C[];                                            // 0x006CF07C
extern D2StormArchiveListStrc gArchiveList_00708354;                                                        // 0x00708354
extern D2StormArchiveRecStrc* gpArchiveHead_0070835C;                                                       // 0x0070835C
extern D2StormEventListStrc gEventList_00708378;                                                            // 0x00708378
extern char* gpEventHead_00708380;                                                                          // 0x00708380
extern char gszTypeNameArchiveRec_00708398[];                                                               // 0x00708398
extern unsigned short gwLocale_0077905C;                                                                    // 0x0077905C
extern unsigned char gnPlatform_0077905E;                                                                   // 0x0077905E
extern int gbThreadStop_00778F24;                                                                           // 0x00778F24
extern unsigned int gnReadRate_0077904C;                                                                    // 0x0077904C
extern unsigned int gnReadUnit_00708348;                                                                    // 0x00708348
extern void* ghStormEvent_00779054;                                                                         // 0x00779054
static D2StormRequestStrc* gpCurrentRequest_0077902C;                                                       // 0x0077902C
extern unsigned int gnStreamChunk_00779038;                                                                 // 0x00779038
extern unsigned char* gpStreamBuffer_00779050;                                                              // 0x00779050

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

static inline D2StormArchiveRecStrc* ArchiveHead()
{
    return (int)gpArchiveHead_0070835C > 0 ? gpArchiveHead_0070835C : 0;
}

static inline char* EventHead()
{
    return (int)gpEventHead_00708380 > 0 ? gpEventHead_00708380 : 0;
}

static __declspec(noinline) int sub_00415930_GetArchiveRec(void* hArchive, D2StormArchiveRecStrc** ppRec)
{
    *ppRec = (D2StormArchiveRecStrc*)hArchive;
    return 1;
}

static unsigned int __stdcall sub_00415330_HashString(unsigned int nHashType, const char* szString)
{
    unsigned int nSeed1 = 0x7FED7FED;
    unsigned int nSeed2 = 0xEEEEEEEE;
    while (szString && *szString)
    {
        unsigned int nChar = (unsigned char)toupper(*szString++);
        nSeed1 = gpCryptTable_00779048[(nHashType << 8) + nChar] ^ (nSeed1 + nSeed2);
        nSeed2 = nChar + nSeed2 + (nSeed2 << 5) + nSeed1 + 3;
    }
    return nSeed1;
}

static __declspec(noinline) D2StormBlockStrc* sub_004155B0_GetBlockEntry(D2StormArchiveRecStrc* pArchive, int nHashIndex)
{
    return &pArchive->pBlockTable[pArchive->pHashTable[nHashIndex].nBlockIndex];
}

static int __stdcall sub_004155D0_FindHashEntry(unsigned short wLocale, unsigned char nPlatform, D2StormArchiveRecStrc* pArchive, const char* szName)
{
    const unsigned int nHash = sub_00415330_HashString(0, szName);
    const unsigned int nName1 = sub_00415330_HashString(1, szName);
    const unsigned int nName2 = sub_00415330_HashString(2, szName);
    const unsigned int nMask = pArchive->pHeader->nHashEntries - 1;
    unsigned int nIndex = nMask & nHash;
    D2StormHashEntryStrc* pEntry = &pArchive->pHashTable[nIndex];
    const unsigned int nStart = nIndex;
    int nBest = -1;
    while (pEntry->nBlockIndex != -1)
    {
        if (pEntry->nName1 == nName1 && pEntry->nName2 == nName2 && pEntry->nBlockIndex != -2)
        {
            if (pEntry->wLocale == wLocale && pEntry->nPlatform == nPlatform)
                return nIndex;
            if ((!pEntry->wLocale || pEntry->wLocale == wLocale) && (!pEntry->nPlatform || pEntry->nPlatform == nPlatform))
                nBest = nIndex;
        }
        nIndex = (nIndex + 1) & nMask;
        if (nIndex == nStart)
            break;
        pEntry = &pArchive->pHashTable[nIndex];
    }
    return nBest;
}

static __declspec(noinline) int sub_00415940_PathPresent(const char* szPath)
{
    return ~(GetFileAttributesA(szPath) >> 4) & 1;
}

static void __stdcall sub_00415A80_BuildPath(int bStripPath, const char* szName, char* szOut)
{
    if (!gszBasePath_00778F28[0])
        sub_004158E0_InitBasePath();
    if (bStripPath)
    {
        const char* szSlash = SStrChrR(szName, 0x5C);
        if (szSlash)
            szName = szSlash + 1;
    }
    char szBuffer[0x104];
    wsprintfA(szBuffer, gszPathJoinFormat_006CE200, gszBasePath_00778F28, szName);
    _fullpath(szOut, szBuffer, 0x104);
}

static int __stdcall sub_00415B00_FindDiskFile(unsigned int nFlags, const char* szName, char* szOut)
{
    int bResult = 0;
    if (nFlags & 3)
    {
        if (nFlags & 2)
        {
            sub_00415A80_BuildPath(1, szName, szOut);
            bResult = sub_00415940_PathPresent(szOut);
            if (bResult)
                return bResult;
        }
        if (nFlags & 1)
        {
            if (*szName != 0x5C && !strstr(szName, gszDriveRoot_006CF09C) && !strstr(szName, gszUncPrefix_006CF098))
            {
                sub_00415A80_BuildPath(0, szName, szOut);
                return sub_00415940_PathPresent(szOut);
            }
            SStrCopy(szOut, szName, 0x104);
            return sub_00415940_PathPresent(szOut);
        }
    }
    return bResult;
}

static int sub_00415930_GetArchiveRec(void* hArchive, D2StormArchiveRecStrc** ppRec); // 0x00415930
static D2StormBlockStrc* sub_004155B0_GetBlockEntry(D2StormArchiveRecStrc* pArchive, int nHashIndex); // 0x004155B0
static int __stdcall sub_004155D0_FindHashEntry(unsigned short wLocale, unsigned char nPlatform, D2StormArchiveRecStrc* pArchive, const char* szName); // 0x004155D0
static int __stdcall sub_00415B00_FindDiskFile(unsigned int nFlags, const char* szName, char* szOut); // 0x00415B00

static __declspec(noinline) int __stdcall sub_00417F10_FindFile(void* hArchive, const char* szName, unsigned int nFlags, D2StormArchiveRecStrc** ppArchive, D2StormBlockStrc** ppBlock, char* szFoundPath);

// 0x00417F10
static int __stdcall sub_00417F10_FindFile(void* hArchive, const char* szName, unsigned int nFlags, D2StormArchiveRecStrc** ppArchive, D2StormBlockStrc** ppBlock, char* szFoundPath)
{
    if (ppArchive)
        *ppArchive = 0;
    if (ppBlock)
        *ppBlock = 0;
    int bResult = 0;
    D2StormArchiveRecStrc* pOnly = 0;
    if (!hArchive || sub_00415930_GetArchiveRec(hArchive, &pOnly))
    {
        D2StormArchiveRecStrc* pArchive = ArchiveHead();
        do
        {
            if (pOnly && pArchive != pOnly)
                continue;
            if (pArchive && pArchive->nRefs > 0)
                continue;
            D2StormArchiveRecStrc* pSearch = pArchive;
            if (pArchive && pArchive->pPatch)
                pSearch = pArchive->pPatch;
            const char* szLookup = szName;
            char szPrefixed[0x104];
            if (pArchive && pArchive->szPrefix[0])
            {
                char* szEnd = szPrefixed + SStrCopy(szPrefixed, pArchive->szPrefix, 0x104);
                szEnd += SStrCopy(szEnd, gszBackslash_006FF9B8, 0x104);
                SStrCopy(szEnd, szName, 0x104);
                szLookup = szPrefixed;
            }
            char szDiskPath[0x104];
            if ((nFlags & 3) && (!pSearch || !pSearch->bNoDiskSearch)
                && sub_00415B00_FindDiskFile(nFlags, szLookup, szDiskPath))
            {
                if (szFoundPath)
                    SStrCopy(szFoundPath, szDiskPath, 0x104);
                bResult = 2;
                goto Done;
            }
            if (pArchive)
            {
                const int nIndex = sub_004155D0_FindHashEntry(gwLocale_0077905C, gnPlatform_0077905E, pSearch, szLookup);
                if (nIndex != -1)
                {
                    bResult = 1;
                    D2StormBlockStrc* pBlock = sub_004155B0_GetBlockEntry(pSearch, nIndex);
                    const int bValid = (pBlock->dwFlags & 0x80000000) && (!(nFlags & 4) || !(pBlock->dwFlags & 0x1FF00));
                    if (!bValid)
                    {
                        bResult = 0;
                        sub_0041C340_SetLastError(0x3EE);
                    }
                    else
                    {
                        if (ppArchive)
                            *ppArchive = pSearch;
                        if (ppBlock)
                            *ppBlock = pBlock;
                    }
                    goto Done;
                }
            }
        }
        while (pArchive && (pArchive = (D2StormArchiveRecStrc*)pArchive->tLink.Next()) != 0);
        sub_0041C340_SetLastError(2);
    }
Done:
    return bResult;
}

void __cdecl sub_00415B90_InitCryptTable();                                                                // 0x00415B90
#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// build: context sub_00418390_FileQuery
int __stdcall sub_00418390_FileQuery(void* hArchive, const char* szFileName, int nFlags)
{
    VALIDATEBEGIN;
    VALIDATE(szFileName);
    VALIDATE(*(const volatile char*)szFileName);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    sub_00415B90_InitCryptTable();
    int nResult = sub_00417F10_FindFile(hArchive, szFileName, nFlags, 0, 0, 0);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nResult;
}
