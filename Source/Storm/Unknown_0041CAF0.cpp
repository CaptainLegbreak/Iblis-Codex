unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
extern "C" char* __cdecl strpbrk(const char* szString, const char* szCharSet);                              // 0x00686990
extern "C" const char gszTypeNameEnd_006CF32C[];                                                           // 0x006CF32C
extern "C" const char gszOpenParen_006CF328[];                                                             // 0x006CF328
extern "C" const char gszCloseParen_006CF324[];                                                            // 0x006CF324

__declspec(noinline) static int __stdcall sub_0041C1F0_FormatTypeName(const char*, char*, unsigned int);
static int __stdcall sub_0041C1F0_FormatTypeName(const char*, char*, unsigned int); // 0x0041C1F0

// 0x0041C1F0
static int __stdcall sub_0041C1F0_FormatTypeName(const char* szName, char* szOut, unsigned int nSize)
{
    if (SStrLen(szName) < 6)
        return 0;
    if (szName[0] != '.' || szName[3] != 'U')
        return 0;
    const char* pName = szName + 4;
    if (!strpbrk(pName, gszTypeNameEnd_006CF32C))
        return 0;
    SStrCopy(szOut, pName, nSize);
    char* p = strpbrk(szOut, gszTypeNameEnd_006CF32C);
    if (!p)
        return 0;
    *p = 0;
    for (p--; p >= szOut && *p == '_'; p--)
        *p = 0;
    sub_00413800(szOut, gszOpenParen_006CF328, nSize);
    sub_00413800(szOut, szName, nSize);
    sub_00413800(szOut, gszCloseParen_006CF324, nSize);
    return 1;
}

extern "C" __declspec(dllimport) int __stdcall LoadStringA(void* hInstance, unsigned int uId, char* buffer, int length); // 0x006CC46C
void* __cdecl sub_0041BEF0_GetExeModule(); // 0x0041BEF0
extern char gszMessageBuffer_00779100[256]; // 0x00779100
extern const char* gpszMessageFallback_006CF2F4[]; // 0x006CF2F4

__declspec(noinline) static const char* sub_0041C170_GetMessageText(int nIndex);
static const char* sub_0041C170_GetMessageText(int nIndex); // 0x0041C170
// 0x0041C170
static const char* sub_0041C170_GetMessageText(int nIndex)
{
    if (LoadStringA(sub_0041BEF0_GetExeModule(), nIndex + 0x5100, gszMessageBuffer_00779100, 256))
        return gszMessageBuffer_00779100;
    return gpszMessageFallback_006CF2F4[nIndex];
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void*,char*,unsigned long); // 0x006CC1BC
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char*,void*); // 0x006CC1CC
extern "C" __declspec(dllimport) int __stdcall FindClose(void*); // 0x006CC1C4
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char*); // 0x006CC200
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char*,const char*,...); // 0x006CC468
extern "C" __declspec(dllimport) int __stdcall IsWindow(void*); // 0x006CC474
extern "C" __declspec(dllimport) int __stdcall IsWindowVisible(void*); // 0x006CC470
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void*,const char*,const char*,unsigned int); // 0x006CC464
extern "C" __declspec(dllimport) unsigned long __stdcall GetVersion(); // 0x006CC138
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) int __stdcall GetExitCodeProcess(void*,unsigned long*); // 0x006CC324
extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void*,unsigned int); // 0x006CC274
void __cdecl sub_0041C1A0_LockErrorState(); // 0x0041C1A0
void __cdecl sub_0041C1E0_UnlockErrorState(); // 0x0041C1E0
void __cdecl sub_0041C160_DebugBreak(); // 0x0041C160
void __stdcall sub_0041C360_SetSuppress(int); // 0x0041C360
int __stdcall sub_0041C430_FormatError(unsigned long error, char* buffer, unsigned long size); // 0x0041C430
void __stdcall SMemZero(void*,unsigned int); // 0x0041D300
char* __stdcall SStrChrR(const char*,char); // 0x004134D0
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
void* __cdecl sub_00420310_GetWindow(); // 0x00420310
extern const char gszEmptyAssertText; // 0x006CC837
extern const char gszDiagnosticFormat_006CF330[]; // 0x006CF330
extern const char gszErrorFormat_006CF33C[]; // 0x006CF33C
extern const char gszLineFormat_006CF34C[]; // 0x006CF34C
extern int gbErrorSuppress_007790F0; // 0x007790F0
extern int gbErrorActive_007790E4; // 0x007790E4
struct D2ErrorHandlerStrc
{
    void* pPrevious;
    D2ErrorHandlerStrc* pNext;
    int (__stdcall* pfnHandler)(unsigned int,const char*,const char*,int,const char*);
};
extern D2ErrorHandlerStrc* gpErrorHandlers_00708428; // 0x00708428
typedef void (__fastcall* D2ErrorReportFn)(const char*,const char*,void*,void*,int,int);
extern D2ErrorReportFn gpErrorReport_007790F8; // 0x007790F8
struct D2FindDataStrc { unsigned int dwAttributes; unsigned int timesAndSize[10]; char szFileName[260]; char szAlternateName[16]; };

// 0x0041CAF0
int __stdcall SErrDisplayError(unsigned int nErrorCode,const char* szFile,int nLine,const char* szDescription,int bRecoverable,unsigned int nExitCode)
{
    if(gbErrorSuppress_007790F0) return 0;
    if(gbErrorActive_007790E4) return 0;
    gbErrorActive_007790E4=1;
    sub_0041C1A0_LockErrorState();
    char szModulePath[0x104];
    char szModuleName[0x104];
    szModulePath[0]=0;
    szModuleName[0]=0;
    GetModuleFileNameA(0,szModulePath,0x104);
    {
    D2FindDataStrc findData;
    SMemZero(&findData,sizeof(findData));
    void* hFind=FindFirstFileA(szModulePath,&findData);
    if(hFind) FindClose(hFind);
    SStrCopy(szModuleName,findData.szFileName,0x104);
    }
    if(SStrChrR(szModuleName,'.')) *SStrChrR(szModuleName,'.')=0;
    char szError[0x100];
    szError[0]=0;
    sub_0041C430_FormatError(nErrorCode,szError,0x100);
    if(!szError[0]) wsprintfA(szError,sub_0041C170_GetMessageText(0),(unsigned short)nErrorCode,nErrorCode);
    const char* szName=szFile;
    char szTypeName[0x100];
    if(szName && *szName && (nLine==-2 || nLine==-3) && sub_0041C1F0_FormatTypeName(szName,szTypeName,0x100)) szName=szTypeName;
    char szMessage[0x400];
    char* p=szMessage;
    if(szName) p+=SStrCopy(p,szName,0x7fffffff);
    if(nLine>0) { wsprintfA(p,gszLineFormat_006CF34C,nLine);p+=SStrLen(p); }
    wsprintfA(p,gszErrorFormat_006CF33C,(unsigned short)nErrorCode);p+=SStrLen(p);
    SStrCopy(p,szError,0x7fffffff);
    OutputDebugStringA(szMessage);
    wsprintfA(szMessage,sub_0041C170_GetMessageText(1),szError);
    p=szMessage+SStrLen(szMessage);
    wsprintfA(p,sub_0041C170_GetMessageText(2),szModulePath);p+=SStrLen(p);
    if(szName && *szName)
    {
        switch(nLine)
        {
        case -1: wsprintfA(p,sub_0041C170_GetMessageText(4),szName);break;
        case -2: wsprintfA(p,sub_0041C170_GetMessageText(5),szName);break;
        case -3: wsprintfA(p,sub_0041C170_GetMessageText(6),szName);break;
        case -4: wsprintfA(p,sub_0041C170_GetMessageText(11),szName);break;
        default: wsprintfA(p,sub_0041C170_GetMessageText(3),szName,nLine);break;
        }
        p+=SStrLen(p);
    }
    if(nErrorCode==0x85100000) wsprintfA(p,sub_0041C170_GetMessageText(7),szDescription?szDescription:&gszEmptyAssertText);
    else wsprintfA(p,sub_0041C170_GetMessageText(8),szDescription?szDescription:&gszEmptyAssertText);
    p+=SStrLen(p);
    if(bRecoverable) SStrCopy(p,sub_0041C170_GetMessageText(10),0x7fffffff);
    else SStrCopy(p,sub_0041C170_GetMessageText(9),0x7fffffff);
    if(gpErrorReport_007790F8)
    {
        char szDiagnostic[0x104];
        SStrPrintf(szDiagnostic,0x104,gszDiagnosticFormat_006CF330,szError,szName?szName:&gszEmptyAssertText,nLine);
        gpErrorReport_007790F8(szDiagnostic,szMessage,0,0,nLine,0);
    }
    unsigned long nFlags=(bRecoverable?3:1)|0x52010;
    int nChoice=7;
    D2ErrorHandlerStrc* pHandler=(int)gpErrorHandlers_00708428<=0?0:gpErrorHandlers_00708428;
    while((int)pHandler>0)
    {
        if(!pHandler->pfnHandler(nErrorCode,szError,szName,nLine,szDescription?szDescription:&gszEmptyAssertText)) goto DialogDone;
        pHandler=pHandler->pNext;
    }
    if(!gpErrorReport_007790F8)
    {
        void* hWindow=sub_00420310_GetWindow();
        if(!IsWindow(hWindow) || !IsWindowVisible(hWindow)) hWindow=0;
        nChoice=MessageBoxA(hWindow,szMessage,szModuleName,nFlags);
    }
DialogDone:
    sub_0041C1E0_UnlockErrorState();
    if(bRecoverable && nChoice==7)
    {
        gbErrorActive_007790E4=0;
        return 1;
    }
    if(nChoice==2) sub_0041C160_DebugBreak();
    sub_0041C360_SetSuppress(1);
    {
        unsigned long dwProcessExitCode;
        if(!(GetVersion()&0x80000000) || !GetExitCodeProcess(GetCurrentProcess(),&dwProcessExitCode) || dwProcessExitCode==0x103)
            TerminateProcess(GetCurrentProcess(),nExitCode);
    }
    gbErrorActive_007790E4=0;
    return 0;
}

#include "gen/data/Source/Storm/Unknown_0041CAF0.inc"
