extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);         // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith);                    // 0x0041D2C0
int __stdcall SMemCmp(const void* pLocation1, const void* pLocation2, unsigned int nSize);                  // 0x0041D200
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
char* __stdcall sub_004141E0_StrUpper(char* szString);                                                      // 0x004141E0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
void __stdcall SBigNew(void** phBig);                                                                       // 0x00423950
int __stdcall SBigFromBinary(void* hBig, const void* pData, unsigned int nSize);                            // 0x00423850
void __stdcall SBigPowMod(void* hResult, void* hBase, void* hExponent, void* hModulus);                     // 0x00425330
void __stdcall SBigToBinaryBuffer(void* hBig, void* pBuffer, unsigned int nSize, unsigned int* pRead);      // 0x00423B30
void __stdcall SBigDel(void* hBig);                                                                         // 0x00424E40
int __fastcall sub_006C79C0_Decompress(void* pDest, unsigned int* pDestSize, const void* pSource, unsigned int nSourceSize); // 0x006C79C0
void __cdecl sub_00480340();                                                                                // 0x00480340
void __cdecl sub_00480230();                                                                                // 0x00480230

extern "C" const unsigned char gabModulus_006D8D18[];                                                       // 0x006D8D18
extern "C" const unsigned char gabExponent_006D8D14[];                                                      // 0x006D8D14
extern "C" const unsigned char gabBuiltinModuleKey_006D8768[];                                              // 0x006D8768
extern "C" const unsigned char gabBuiltinModuleRc4Key_006D8778[];                                           // 0x006D8778
extern "C" const unsigned char gabBuiltinModule_006D74B0[];                                                 // 0x006D74B0

struct D2StormHashCtxStrc
{
    unsigned __int64 nBitCount;
    unsigned int nState[5];
    unsigned char pBlock[64];

    void sub_00425D90_Init();                                               // 0x00425D90
    void sub_00425DD0_Update(const unsigned char* pData, unsigned int nLen); // 0x00425DD0
    void sub_00425F00_Final(unsigned char* pDigest);                        // 0x00425F00
};

struct D2RC4Strc
{
    unsigned char S[0x100];
    unsigned char i;
    unsigned char j;

    void sub_004E09B0_Init(const unsigned char* pKey, unsigned int nKeySize); // 0x004E09B0
    void sub_0047F8C0_Crypt(unsigned char* pData, unsigned int nSize);       // 0x0047F8C0
};

class WardenModule
{
public:
    WardenModule()
    {
        pImage = 0;
        unk0x04 = 0;
        nImports = 0;
        unk0x0C = 0;
        f_10 = 0;
    }
    ~WardenModule();                                                                // 0x004E06A0
    void* operator new(unsigned int nSize)
    {
        return SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x10D, 0);
    }
    void operator delete(void* pMemory)
    {
        SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x117, 0);
    }
    bool sub_004E0730_Load(void* pData, int nSize);                         // 0x004E0730
    void* sub_004E0700_GetProc(int nOrdinal);                                // 0x004E0700

    void* pImage;
    int unk0x04;
    int nImports;
    int unk0x0C;
    void* f_10;
};

struct D2WardenFindArgStrc
{
    int unk0x00;
    int unk0x04;
};

struct D2ClientServiceStrc
{
    char unk0x00[0xC8];
    void (__fastcall* pfnFree)(void* pData, int nSize);
    int (__fastcall* pfnFind)(char* szName, int* pArg, void** ppData, int* pSize);
};

D2ClientServiceStrc* __cdecl sub_00518C10();                                                                // 0x00518C10
extern WardenModule* gpPendingWarden_007BC994;                                                                      // 0x007BC994
extern D2ClientServiceStrc* gpService_007BC998;                                                             // 0x007BC998
extern int gnWardenIfaceValue_00721C94;                                                                     // 0x00721C94

// 0x0047F990
static void __stdcall sub_0047F990_HashModule(const char* szName, unsigned char* pDigest, const unsigned char* pData, unsigned int nSkip, unsigned int nSize)
{
    D2StormHashCtxStrc tCtx;
    char szBuffer[0x400];
    tCtx.sub_00425D90_Init();
    if (nSkip)
    {
        tCtx.sub_00425DD0_Update(pData + nSkip, nSize - nSkip);
        tCtx.sub_00425DD0_Update(pData, nSkip);
    }
    else
    {
        tCtx.sub_00425DD0_Update(pData, nSize);
    }
    SStrCopy(szBuffer, szName, 0x400);
    sub_004141E0_StrUpper(szBuffer);
    tCtx.sub_00425DD0_Update((const unsigned char*)szBuffer, SStrLen(szBuffer));
    tCtx.sub_00425F00_Final(pDigest);
}

static int __stdcall sub_0047FA20_VerifyModuleSignature(const char* szName, unsigned char* pData, const unsigned char* pModulus, const unsigned char* pExponent, unsigned int nExponentSize, unsigned int nSkip, unsigned int nSize, unsigned int nSignatureSize)
{
    D2_ASSERT(nSkip <= nSize, 0xA3);
    unsigned int nDataSize = nSize - nSignatureSize - 4;
    if (nSize < nSignatureSize + 4)
    {
        return 0;
    }
    unsigned char* pSignature = pData + nDataSize;
    {
        int nTag;
        SMemCopy(&nTag, pSignature, 4);
        if (nTag != 0x5349474E)
        {
            return 0;
        }
    }
    unsigned char* pExpected = (unsigned char*)SMemAlloc(nSignatureSize, ".\\WARDEN\\WardenClient.cpp", 0xAB, 0);
    SMemFill(pExpected, nSignatureSize, 0xBB);
    pExpected[nSignatureSize - 1] = 0x0B;
    sub_0047F990_HashModule(szName, pExpected, pData, nSkip, nDataSize);
    unsigned char* pDecrypted = (unsigned char*)SMemAlloc(nSignatureSize, ".\\WARDEN\\WardenClient.cpp", 0xB5, 0);
    SMemCopy(pDecrypted, pSignature + 4, nSignatureSize);
    void* hResult;
    void* hSignature;
    void* hExponent;
    void* hModulus;
    SBigNew(&hResult);
    SBigNew(&hSignature);
    SBigNew(&hExponent);
    SBigNew(&hModulus);
    SBigFromBinary(hSignature, pDecrypted, nSignatureSize);
    SBigFromBinary(hExponent, pExponent, nExponentSize);
    SBigFromBinary(hModulus, pModulus, nSignatureSize);
    SBigPowMod(hResult, hSignature, hExponent, hModulus);
    SBigToBinaryBuffer(hResult, pDecrypted, nSignatureSize, 0);
    int bValid = !SMemCmp(pDecrypted, pExpected, nSignatureSize);
    SMemFree(pExpected, ".\\WARDEN\\WardenClient.cpp", 0xCC, 0);
    SMemFree(pDecrypted, ".\\WARDEN\\WardenClient.cpp", 0xCD, 0);
    SBigDel(hResult);
    SBigDel(hSignature);
    SBigDel(hExponent);
    SBigDel(hModulus);
    return bValid;
}

static int __stdcall sub_0047FC70_LoadModule(const unsigned char* pData, const unsigned char* pKey, unsigned int nSize)
{
    char szName[10];
    szName[0] = (char)0x5F;
    szName[1] = (char)0x7B;
    szName[2] = (char)0x53;
    szName[3] = (char)0xE7;
    szName[4] = (char)0xF2;
    szName[5] = (char)0x5A;
    szName[6] = (char)0xBF;
    szName[7] = (char)0x75;
    szName[8] = (char)0x8C;
    szName[9] = 0;
    for (unsigned int i = 0; i < 10; ++i)
    {
        szName[i] *= 0xD3;
    }
    if (gpPendingWarden_007BC994)
    {
        gpPendingWarden_007BC994->~WardenModule();
        delete gpPendingWarden_007BC994;
        gpPendingWarden_007BC994 = 0;
    }
    unsigned char* pBuffer = (unsigned char*)SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x16E, 0);
    SMemCopy(pBuffer, pData, nSize);
    if (!pBuffer)
    {
        return 0;
    }
    D2RC4Strc tRc4;
    tRc4.sub_004E09B0_Init(pKey, 0x10);
    tRc4.sub_0047F8C0_Crypt(pBuffer, nSize);
    if (!sub_0047FA20_VerifyModuleSignature(szName, pBuffer, gabModulus_006D8D18, gabExponent_006D8D14, 4, 0, nSize, 0x100))
    {
        SMemFree(pBuffer, ".\\WARDEN\\WardenClient.cpp", 0x17C, 0);
        return 0;
    }
    unsigned int nModuleSize = *(unsigned int*)pBuffer;
    unsigned char* pModule = (unsigned char*)SMemAlloc(nModuleSize, ".\\WARDEN\\WardenClient.cpp", 0x182, 0);
    if (!pModule)
    {
        SMemFree(pBuffer, ".\\WARDEN\\WardenClient.cpp", 0x185, 0);
        return 0;
    }
    if (sub_006C79C0_Decompress(pModule, &nModuleSize, pBuffer + 4, nSize - 4))
    {
        SMemFree(pBuffer, ".\\WARDEN\\WardenClient.cpp", 0x18D, 0);
        SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x18E, 0);
        return 0;
    }
    SMemFree(pBuffer, ".\\WARDEN\\WardenClient.cpp", 0x193, 0);
    WardenModule* pWarden = new WardenModule;
    if (!pWarden)
    {
        SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x199, 0);
        return 0;
    }
    if (!pWarden->sub_004E0730_Load(pModule, nModuleSize))
    {
        SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x1A0, 0);
        delete pWarden;
        return 0;
    }
    pWarden->f_10 = pWarden->sub_004E0700_GetProc(1);
    if (!pWarden->f_10)
    {
        pWarden->~WardenModule();
        SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x1AA, 0);
        delete pWarden;
        return 0;
    }
    SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x1B0, 0);
    gpPendingWarden_007BC994 = pWarden;
    return 1;
}

// 0x0047FEE0
static int __stdcall sub_0047FEE0_LoadModuleByKey(const unsigned char* pRc4Key, const unsigned char* pModuleKey)
{
    if (!SMemCmp(pModuleKey, gabBuiltinModuleKey_006D8768, 0x10))
    {
        return sub_0047FC70_LoadModule(gabBuiltinModule_006D74B0, gabBuiltinModuleRc4Key_006D8778, 0x12B2);
    }
    char szName[0x28];
    for (unsigned int i = 0; i < 0x10; ++i)
    {
        sprintf(&szName[i * 2], "%02x", pModuleKey[i]);
    }
    SStrCopy(&szName[0x20], ".mod", 5);
    if (!gpService_007BC998)
    {
        return 0;
    }
    D2WardenFindArgStrc tFindArg;
    void* pModule;
    int nModuleSize;
    if (!gpService_007BC998->pfnFind(szName, &tFindArg.unk0x00, &pModule, &nModuleSize))
    {
        return 0;
    }
    int nResult = sub_0047FC70_LoadModule((const unsigned char*)pModule, pRc4Key, nModuleSize);
    gpService_007BC998->pfnFree(pModule, nModuleSize);
    return nResult;
}

// 0x00480020
bool __stdcall sub_00480020_LoadModuleByKey(const unsigned char* pModuleKey, const unsigned char* pRc4Key)
{
    return sub_0047FEE0_LoadModuleByKey(pRc4Key, pModuleKey);
}

int __fastcall sub_004803C0_InitWarden(int nValue)
{
    sub_00480340();
    gnWardenIfaceValue_00721C94 = nValue;
    gpService_007BC998 = sub_00518C10();
    if (!gpService_007BC998)
    {
        return 0;
    }
    sub_0047FEE0_LoadModuleByKey(gabBuiltinModuleRc4Key_006D8778, gabBuiltinModuleKey_006D8768);
    sub_00480230();
    return 1;
}

#include "gen/data/Source/D2Client/0047FEE0_sub_0047FEE0_LoadModuleByKey.inc"
