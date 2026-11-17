typedef unsigned long DWORD;
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

struct CERT_CONTEXT;

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int CodePage, DWORD dwFlags, const char* lpMultiByteStr, int cbMultiByte, wchar_t* lpWideCharStr, int cchWideChar); // 0x006CC29C
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

void* __cdecl operator new(unsigned int nSize);   // 0x00405410
void __cdecl operator delete(void* pMemory);      // 0x004053F0

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
