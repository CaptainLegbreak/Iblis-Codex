#include "Storm.h"
#include "D2StormTypes.h"
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

struct D2ListNode006C4D70Strc;
struct D2List006C4D70Strc;
struct D2CmdArg006C4E50Strc;
struct D2CmdNodeStrc;
struct D2TargaHeaderStrc;

struct D2ListNode006C4D70Strc
{
    D2ListNode006C4D70Strc* pPrevLink;
    D2ListNode006C4D70Strc* pNext;
    int unk08;
    int nId;
    int unk10[11];
    int nValue;
};

struct D2List006C4D70Strc
{
    int nLinkOffset;
    D2ListNode006C4D70Strc* pTail;
    D2ListNode006C4D70Strc* pHead;
};

extern D2List006C4D70Strc gList_0074C48C; // 0x0074C48C
extern D2List006C4D70Strc gList_0074C498; // 0x0074C498
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
int __stdcall SCmdRegisterArgument(unsigned int dwFlags, unsigned int dwId, const char* szName, void* pVariable, unsigned int nBytes, int bSet, void* pfnCallback, void* pParam); // 0x006C4580

struct D2CmdArg006C4E50Strc
{
    unsigned int dwFlags;
    unsigned int dwId;
    const char* szName;
    void* pParam;
};

int __stdcall sub_006C4D70_FindValue(int nKey); // 0x006C4D70

extern const char* gszErrorDefaults_006FCC24[]; // 0x006FCC24
extern const char gszPercentS_006FFC58[]; // 0x006FFC58
extern const char gszNewline_006FFCB0[]; // 0x006FFCB0
void* __cdecl sub_0041BEF0_GetExeModule(); // 0x0041BEF0
unsigned int __stdcall SStrCopy(char*, const char*, unsigned int); // 0x004135D0
unsigned int __stdcall sub_00413800(char*, const char*, unsigned int); // 0x00413800
extern "C" char* __cdecl strstr(const char*, const char*);
extern "C" __declspec(dllimport) int __stdcall LoadStringA(void*, unsigned int, char*, int);
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char*, const char*, ...);
static void __stdcall sub_006C3E10_ReportCommandError(D2ErrorCallback callback, unsigned int error, const char* context);

struct D2CmdNodeStrc
{
    int unk0x00;
    D2CmdNodeStrc* pNext;
    unsigned int dwFlags;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern const char gszCmdSeparators_006FCC4C[]; // 0x006FCC4C
extern D2CmdNodeStrc* gpCmdList_0074C494; // 0x0074C494
void __stdcall SStrTokenize(char** ppString, char* pBuffer, unsigned int nBufferSize, const char* szSeparators, int* pbQuoted); // 0x00413B80
void __stdcall SMemZero(void* pDst, unsigned int nSize); // 0x0041D300
int __fastcall sub_006C4EC0_ParseCommandText(char** ppCursor, unsigned char* pState, D2CmdNodeStrc** ppCmd, void* pfnExtra, D2ErrorCallback pfnError); // 0x006C4EC0

struct D2TargaHeaderStrc { unsigned char bytes[18]; };

// 0x006C4D70
int __stdcall sub_006C4D70_FindValue(int nId)
{
    for (int i = 0; i <= 1; ++i)
    {
        D2List006C4D70Strc* pList = i ? &gList_0074C498 : &gList_0074C48C;
        for (D2ListNode006C4D70Strc* pNode = pList->pHead; (int)pNode > 0; pNode = pNode->pNext)
        {
            if (pNode->nId == nId)
            {
                return pNode->nValue;
            }
        }
    }
    return 0;
}

// 0x006C4E50
int __stdcall sub_006C4E50_RegisterArgList(D2CmdArg006C4E50Strc* pArgs, unsigned int nCount)
{
    VALIDATEBEGIN;
    VALIDATE(pArgs);
    VALIDATEEND;
    for (unsigned int i = 0; i < nCount; ++i, ++pArgs)
    {
        if (!SCmdRegisterArgument(pArgs->dwFlags, pArgs->dwId, pArgs->szName, 0, 0, 1, (void*)-1, pArgs->pParam))
        {
            return 0;
        }
    }
    return nValid ? 1 : 0;
}

// 0x006C4F90
int __stdcall sub_006C4F90_GetBool(int nKey)
{
    return sub_006C4D70_FindValue(nKey) != 0;
}

// 0x006C3E10
static void __stdcall sub_006C3E10_ReportCommandError(D2ErrorCallback callback, unsigned int error, const char* context)
{
    D2ErrorReportStrc report;
    report.callback = callback;
    char format[256];
    char message[256];
    int index;
    unsigned int resource;
    switch (error)
    {
    case 0x85100065:
        index = 0;
        resource = 0x5201;
        break;
    case 0x8510006D:
        index = 1;
        resource = 0x5202;
        break;
    case 110:
        index = 2;
        resource = 0x5203;
        break;
    default:
        return;
    }
    format[0] = 0;
    LoadStringA(sub_0041BEF0_GetExeModule(), resource, format, 256);
    if (!format[0])
        SStrCopy(format, gszErrorDefaults_006FCC24[index], 256);
    if (strstr(format, gszPercentS_006FFC58))
        wsprintfA(message, format, context);
    else
        SStrCopy(message, format, 256);
    if (message[0])
        sub_00413800(message, gszNewline_006FFCB0, 256);
    SErrSetLastError(error);
    report.error = error;
    report.context = context;
    report.message = message;
    report.callback(&report);
}

static inline D2CmdNodeStrc* CMD_LinkOrNull(D2CmdNodeStrc* pNode)
{
    return (int)pNode > 0 ? pNode : 0;
}

// 0x006C4FB0
int __stdcall SCmdProcess(char* szCommandLine, int bSkipFirst, void* pfnExtra, D2ErrorCallback pfnError)
{
    int nValid = -1;
    nValid &= szCommandLine ? -1 : 0;
    if (!nValid)
    {
        SErrSetLastError(0x57);
        return 0;
    }

    if (bSkipFirst)
    {
        SStrTokenize(&szCommandLine, 0, 0, gszCmdSeparators_006FCC4C, 0);
    }

    unsigned char aState[0x18];
    SMemZero(aState, sizeof(aState));
    D2CmdNodeStrc* pCmd = CMD_LinkOrNull(gpCmdList_0074C494);
    if (!sub_006C4EC0_ParseCommandText(&szCommandLine, aState, &pCmd, pfnExtra, pfnError))
    {
        return 0;
    }

    int bResult = 1;
    while (pCmd && bResult)
    {
        if ((pCmd->dwFlags & 0x3000000) == 0x2000000)
        {
            bResult = 0;
        }
        else if ((int)pCmd->pNext > 0)
        {
            pCmd = pCmd->pNext;
        }
        else
        {
            pCmd = 0;
        }
    }

    if (pfnError && !bResult)
    {
        sub_006C3E10_ReportCommandError(pfnError, 0x8510006D, &gszEmptyAssertText);
    }

    return nValid ? bResult : 0;
}

void __fastcall EmitCommandError(D2ErrorCallback callback, unsigned int error, const char* context)
{
    sub_006C3E10_ReportCommandError(callback, error + 1, context + 1);
}

static
// 0x006C5150
int __stdcall sub_006C5150_ReadTgaPalette(const D2TargaHeaderStrc* header, const unsigned char* source, int size, tagPALETTEENTRY* palette)
{
    int bytesPerColor = (header->bytes[7] + 7) / 8;
    int index = *(const unsigned short*)&header->bytes[3];
    int end = index + *(const unsigned short*)&header->bytes[5];
    if ((end - index) * bytesPerColor != size)
        return 0;
    SMemZero(palette, index * sizeof(tagPALETTEENTRY));
    for (; index < end; ++index)
    {
        palette[index].peRed = source[2];
        palette[index].peGreen = source[1];
        palette[index].peBlue = source[0];
        palette[index].peFlags = bytesPerColor > 3 ? source[3] : 0;
        source += bytesPerColor;
    }
    SMemZero(palette + index, (256 - index) * sizeof(tagPALETTEENTRY));
    return 1;
}

int __fastcall EmitReadTgaPalette(const D2TargaHeaderStrc* header, const unsigned char* source, int size, tagPALETTEENTRY* palette)
{
    return sub_006C5150_ReadTgaPalette(header + 1, source, size, palette);
}
