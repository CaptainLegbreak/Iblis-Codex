#include "D2StormLink.h"
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void*,const char*,const char*,unsigned int); // 0x006CC464

#define D2_IMPORT __declspec(dllimport)

extern "C" D2_IMPORT int __stdcall MessageBoxA(void* window, const char* text, const char* caption, unsigned int flags);
extern "C" D2_IMPORT int __cdecl wsprintfA(char* buffer, const char* format, ...);

typedef void (__stdcall* FaultAssertHandler)(const char*, unsigned int, const char*);

extern FaultAssertHandler sgpfnAssertHandler; // 0x00881834
extern const char* const gpszModuleName; // 0x006CC848
extern const char sgszAssertFormatString[]; // 0x006DEBE8
void __cdecl sub_005173DF_TerminateCurrentProcess(); // 0x005173DF
extern "C" void __fastcall __security_check_cookie(unsigned int cookie); // 0x00681A48

struct CERT_CONTEXT;

struct GUID;

struct TRUSTFILEINFO;

struct TRUSTDATA;

struct CRYPT_INTEGER_BLOB;

struct CRYPT_ALGORITHM_IDENTIFIER;

struct CRYPT_BIT_BLOB;

struct FILETIME;

struct CERT_PUBLIC_KEY_INFO;

struct CERT_INFO;

struct CMSG_SIGNER_INFO;

void __fastcall sub_00517804_GetText(unsigned int, char*, unsigned int); // 0x00517804

void __cdecl sub_005173DF_TerminateCurrentProcess(); // 0x005173DF

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char*, const char*, char*); // 0x006CC4AC

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void*, const char*, const char*, unsigned int); // 0x006CC464

void __fastcall __security_check_cookie(unsigned int); // 0x00681A48

typedef unsigned long DWORD;

typedef long LONG;

typedef void* HANDLE;

typedef void* HWND;

struct GUID { unsigned long Data1; unsigned short Data2; unsigned short Data3; unsigned char Data4[8]; };

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int CodePage, DWORD dwFlags, const char* lpMultiByteStr, int cbMultiByte, wchar_t* lpWideCharStr, int cchWideChar); // 0x006CC29C

extern "C" __declspec(dllimport) DWORD __stdcall GetLastError(void); // 0x006CC1B4

void* __cdecl operator new(unsigned int nSize); // 0x00405410

void __cdecl operator delete(void* pMemory); // 0x004053F0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct TRUSTFILEINFO
{
    DWORD cbStruct;
    const wchar_t* pcwszFilePath;
    HANDLE hFile;
    GUID* pgKnownSubject;
};

struct TRUSTDATA
{
    DWORD cbStruct;
    void* pPolicyCallbackData;
    void* pSIPClientData;
    DWORD dwUIChoice;
    DWORD fdwRevocationChecks;
    DWORD dwUnionChoice;
    TRUSTFILEINFO* pFile;
    DWORD dwStateAction;
    HANDLE hWVTStateData;
    wchar_t* pwszURLReference;
    DWORD dwProvFlags;
    DWORD dwUIContext;
};

extern "C" LONG __stdcall BNCLIENT_WinVerifyTrust(HWND hWnd, GUID* pgActionID, void* pWVTData); // 0x006B00F6

typedef void* HCERTSTORE;

typedef void* HCRYPTMSG;

struct CRYPT_INTEGER_BLOB { DWORD cbData; unsigned char* pbData; };

struct CRYPT_ALGORITHM_IDENTIFIER { char* pszObjId; CRYPT_INTEGER_BLOB Parameters; };

struct CRYPT_BIT_BLOB { DWORD cbData; unsigned char* pbData; DWORD cUnusedBits; };

struct FILETIME { DWORD dwLowDateTime; DWORD dwHighDateTime; };

struct CERT_PUBLIC_KEY_INFO { CRYPT_ALGORITHM_IDENTIFIER Algorithm; CRYPT_BIT_BLOB PublicKey; };

struct CERT_INFO
{
    DWORD dwVersion;
    CRYPT_INTEGER_BLOB SerialNumber;
    CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    CRYPT_INTEGER_BLOB Issuer;
    FILETIME NotBefore;
    FILETIME NotAfter;
    CRYPT_INTEGER_BLOB Subject;
    CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
    CRYPT_BIT_BLOB IssuerUniqueId;
    CRYPT_BIT_BLOB SubjectUniqueId;
    DWORD cExtension;
    void* rgExtension;
};

struct CMSG_SIGNER_INFO
{
    DWORD dwVersion;
    CRYPT_INTEGER_BLOB Issuer;
    CRYPT_INTEGER_BLOB SerialNumber;
};

extern "C" __declspec(dllimport) int __stdcall WideCharToMultiByte(unsigned int CodePage, DWORD dwFlags, const wchar_t* lpWideCharStr, int cchWideChar, char* lpMultiByteStr, int cbMultiByte, const char* lpDefaultChar, int* lpUsedDefaultChar); // 0x006CC194

extern "C" __declspec(dllimport) void* __stdcall LocalAlloc(unsigned int uFlags, unsigned int uBytes); // 0x006CC380

extern "C" __declspec(dllimport) void* __stdcall LocalFree(void* hMem); // 0x006CC37C

extern "C" __declspec(dllimport) int __stdcall CryptQueryObject(DWORD dwObjectType, const void* pvObject, DWORD dwExpectedContentTypeFlags, DWORD dwExpectedFormatTypeFlags, DWORD dwFlags, DWORD* pdwMsgAndCertEncodingType, DWORD* pdwContentType, DWORD* pdwFormatType, HCERTSTORE* phCertStore, HCRYPTMSG* phMsg, const void** ppvContext); // 0x006CC064

extern "C" __declspec(dllimport) int __stdcall CryptMsgGetParam(HCRYPTMSG hCryptMsg, DWORD dwParamType, DWORD dwIndex, void* pvData, DWORD* pcbData); // 0x006CC060

extern "C" __declspec(dllimport) const CERT_CONTEXT* __stdcall CertFindCertificateInStore(HCERTSTORE hCertStore, DWORD dwCertEncodingType, DWORD dwFindFlags, DWORD dwFindType, const void* pvFindPara, const CERT_CONTEXT* pPrevCertContext); // 0x006CC05C

extern "C" __declspec(dllimport) DWORD __stdcall CertGetNameStringW(const CERT_CONTEXT* pCertContext, DWORD dwType, DWORD dwFlags, void* pvTypePara, wchar_t* pszNameString, DWORD cchNameString); // 0x006CC070

extern "C" __declspec(dllimport) int __stdcall CertFreeCertificateContext(const CERT_CONTEXT* pCertContext); // 0x006CC058

extern "C" __declspec(dllimport) int __stdcall CertCloseStore(HCERTSTORE hCertStore, DWORD dwFlags); // 0x006CC068

extern "C" __declspec(dllimport) int __stdcall CryptMsgClose(HCRYPTMSG hCryptMsg); // 0x006CC06C

#include "gen/data/Source/D2Hell/Unknown_005173EF.inc"

void __fastcall sub_00517804_GetMessage(unsigned int,char*,unsigned int);
void __fastcall sub_005173EF_Display(const char*);
#define BUFFER_SIZE 512

extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void* process, unsigned int exitCode); // 0x006CC274

// 0x005173DF
void __cdecl sub_005173DF_TerminateCurrentProcess()
{
    TerminateProcess(GetCurrentProcess(), (unsigned int)-1);
}

// 0x005173EF
int __fastcall sub_005173EF_FatalBox(const char* text) {
 MessageBoxA(0,text,gpszModuleName,0x2010);
 sub_005173DF_TerminateCurrentProcess();
 return 0;
}

// 0x0051740B
int __fastcall sub_0051740B_ErrorBox(const char* text) {
 MessageBoxA(0,text,gpszModuleName,0x2010);
 return 1;
}
// 0x00517423
int __fastcall FaultDoAssert(const char* a1, unsigned int a2, const char* a3)
{
    char Text[512];

    if (sgpfnAssertHandler)
        sgpfnAssertHandler(a1, a2, a3);
    wsprintfA(Text, sgszAssertFormatString, a1, a2, a3);
    const int buttonID = MessageBoxA(0, Text, gpszModuleName, 0x52212);
    if (buttonID == 3) {
        sub_005173DF_TerminateCurrentProcess();
        return 1;
    }
    return buttonID == 4;
}

// 0x005174AA
int D2StormLinkStrc::sub_005174AA_Next()
{
    int nNext = (int)m_next;
    if (nNext <= 0)
    {
        nNext = 0;
    }
    return nNext;
}

// 0x005174B4
int D2StormLinkStrc::sub_005174B4_RawNext()
{
    return (int)m_next;
}

// 0x005174B8
void D2StormLinkStrc::sub_005174B8_Clear()
{
    m_prevlink = 0;
    m_next = 0;
}

// 0x00517874
int __cdecl sub_00517874_ShowError(unsigned int message, ...)
{
 char format[512];
 char text[512];
 sub_00517804_GetText(message, format, sizeof(format));
 wvsprintfA(text, format, (char*)(&message+1));
 int result;
 if(MessageBoxA(0,text,gpszModuleName,0x2215)==4) result=1;
 else {sub_005173DF_TerminateCurrentProcess();result=0;}
 return result;
}

// 0x005178E9
void __cdecl sub_005178E9_Format(unsigned int id,...) {
 char formatted[BUFFER_SIZE];
 char format[BUFFER_SIZE];
 sub_00517804_GetMessage(id,format,BUFFER_SIZE);
 wvsprintfA(formatted,format,(char*)(&id+1));
 sub_005173EF_Display(formatted);
}

// 0x005179B3
void __fastcall sub_005179B3_CopyRect(unsigned char* pDest, const unsigned char* pSource, int nDestPitch, int nSourcePitch, int nRows, int nWidth)
{
    int nSourceSkip = nSourcePitch - nWidth;
    int nDestSkip = nDestPitch - nWidth;
    __asm
    {
        mov edi, pDest
        mov esi, pSource
        mov ebx, nRows
    nextrow:
        mov edx, nWidth
        mov ecx, edx
        and edx, 3
        je dwords
        cmp edx, 1
        je one
        cmp edx, 2
        je two
        mov al, [esi]
        mov [edi], al
        mov al, [esi + 1]
        mov [edi + 1], al
        mov al, [esi + 2]
        mov [edi + 2], al
        add edi, 3
        add esi, 3
        jmp dwords
    two:
        mov al, [esi]
        mov [edi], al
        mov al, [esi + 1]
        mov [edi + 1], al
        add edi, 2
        add esi, 2
        jmp dwords
    one:
        mov al, [esi]
        mov [edi], al
        inc edi
        inc esi
    dwords:
        shr ecx, 2
        rep movsd
        add esi, nSourceSkip
        add edi, nDestSkip
        dec ebx
        jne nextrow
    }
}

// 0x00517A36
int __fastcall sub_00517A36_CompareMemory(const void* pFirst, const void* pSecond, unsigned int nSize)
{
    __asm
    {
        mov edi, pFirst
        mov esi, pSecond
        mov edx, nSize
        mov ecx, edx
        and edx, 3
        je dwords
        cmp edx, 1
        je one
        cmp edx, 2
        je two
        mov al, [esi]
        mov bl, [edi]
        cmp al, bl
        jne different
        mov al, [esi + 1]
        mov bl, [edi + 1]
        cmp al, bl
        jne different
        mov al, [esi + 2]
        mov bl, [edi + 2]
        cmp al, bl
        jne different
        add edi, 3
        add esi, 3
        jmp dwords
    two:
        mov al, [esi]
        mov bl, [edi]
        cmp al, bl
        jne different
        mov al, [esi + 1]
        mov bl, [edi + 1]
        cmp al, bl
        jne different
        add edi, 2
        add esi, 2
        jmp dwords
    one:
        mov al, [esi]
        mov bl, [edi]
        cmp al, bl
        jne different
        inc edi
        inc esi
    dwords:
        shr ecx, 2
        repe cmpsd
        jne different
    }
    return 1;
different:
    return 0;
}

// 0x00517ABB
int __cdecl sub_00517ABB_FindLowestSetBit(unsigned int dwMask)
{
    int nIndex;
    if (!dwMask)
        return 0;
    __asm
    {
        bsf eax, dwMask
        inc eax
        mov nIndex, eax
    }
    return nIndex;
}

// 0x00517AD6
int __fastcall sub_00517AD6(const char* szPath)
{
    if (!szPath || !*szPath)
        return 4;

    int nLen = MultiByteToWideChar(0, 0, szPath, -1, 0, 0);
    if (nLen <= 0)
        return 4;

    wchar_t* wszPath = new wchar_t[nLen];
    MultiByteToWideChar(0, 0, szPath, -1, wszPath, nLen);

    TRUSTFILEINFO tFile;
    memset(&tFile, 0, sizeof(tFile));
    tFile.cbStruct = sizeof(tFile);
    tFile.pcwszFilePath = wszPath;
    tFile.hFile = 0;
    tFile.pgKnownSubject = 0;

    GUID tAction = { 0x00AAC56B, 0xCD44, 0x11D0, { 0x8C, 0xC2, 0x00, 0xC0, 0x4F, 0xC2, 0x95, 0xEE } };

    TRUSTDATA tData;
    memset(&tData, 0, sizeof(tData));
    tData.cbStruct = sizeof(tData);
    tData.pPolicyCallbackData = 0;
    tData.pSIPClientData = 0;
    tData.dwUIChoice = 2;
    tData.fdwRevocationChecks = 0;
    tData.dwUnionChoice = 1;
    tData.pFile = &tFile;
    tData.dwStateAction = 0;
    tData.hWVTStateData = 0;
    tData.pwszURLReference = 0;
    tData.dwUIContext = 0;

    LONG nResult = BNCLIENT_WinVerifyTrust(0, &tAction, &tData);
    int nRet;
    switch (nResult)
    {
    case 0x80092026:
    case 0x800B0004:
    case 0x800B0111:
        nRet = 3;
        break;
    case 0x800B0100:
        nRet = (GetLastError() != 0x800B0100) + 1;
        break;
    default:
        nRet = nResult ? 4 : 0;
        break;
    }

    delete wszPath;
    return nRet;
}

// build: symbol __SEH_prolog4 0x00687FB0
// build: symbol __SEH_epilog4 0x00687FF5
// 0x00517C30
bool __fastcall sub_00517C30_GetSignerOrganization(const char* szFilePath, char* szName, int nNameSize)
{
    bool bResult;
    int nLen;
    HCRYPTMSG hMsg;
    const CERT_CONTEXT* pCertContext;
    CMSG_SIGNER_INFO* pSignerInfo;
    HCERTSTORE hStore;
    wchar_t* wszFilePath;
    DWORD dwSignerInfo;

    if (!szFilePath || !*szFilePath)
        return false;

    nLen = MultiByteToWideChar(0xFDE9, 0, szFilePath, -1, 0, 0);
    if (nLen <= 0)
        return false;

    wszFilePath = new wchar_t[nLen];
    MultiByteToWideChar(0xFDE9, 0, szFilePath, -1, wszFilePath, nLen);

    bResult = false;
    hStore = 0;
    hMsg = 0;
    pCertContext = 0;
    pSignerInfo = 0;
    __try
    {
        int bOk = CryptQueryObject(1, wszFilePath, 0x400, 2, 0, 0, 0, 0, &hStore, &hMsg, 0);
        if (!bOk)
            __leave;

        bOk = CryptMsgGetParam(hMsg, 6, 0, 0, &dwSignerInfo);
        if (!bOk)
            __leave;

        pSignerInfo = (CMSG_SIGNER_INFO*)LocalAlloc(0x40, dwSignerInfo);
        if (!pSignerInfo)
            __leave;

        bOk = CryptMsgGetParam(hMsg, 6, 0, pSignerInfo, &dwSignerInfo);
        if (!bOk)
            __leave;

        CERT_INFO tCertInfo;
        tCertInfo.Issuer = pSignerInfo->Issuer;
        tCertInfo.SerialNumber = pSignerInfo->SerialNumber;
        pCertContext = CertFindCertificateInStore(hStore, 0x10001, 0, 0xB0000, &tCertInfo, 0);
        if (!pCertContext)
            __leave;

        DWORD dwNameLen = CertGetNameStringW(pCertContext, 3, 0, "2.5.4.10", 0, 0);
        if (!dwNameLen)
            __leave;

        wchar_t* wszName = new wchar_t[dwNameLen];
        if (CertGetNameStringW(pCertContext, 3, 0, "2.5.4.10", wszName, dwNameLen))
        {
            int nSize = WideCharToMultiByte(0xFDE9, 0, wszName, -1, 0, 0, 0, 0);
            if (nSize > 0)
            {
                WideCharToMultiByte(0xFDE9, 0, wszName, -1, szName, nNameSize, 0, 0);
                bResult = true;
            }
        }
        delete wszName;
    }
    __finally
    {
        if (pSignerInfo)
            LocalFree(pSignerInfo);
        if (pCertContext)
            CertFreeCertificateContext(pCertContext);
        if (hStore)
            CertCloseStore(hStore, 0);
        if (hMsg)
            CryptMsgClose(hMsg);
    }
    return bResult;
}

