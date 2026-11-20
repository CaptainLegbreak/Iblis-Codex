#include "D2Client.h"
#include "D2Unicode.h"

#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    char unk0x000[0xBD];
    char szCharName[0x18];
    char szAccount[0x119];
    unsigned char nClass;
    unsigned short wFlags;
    char unk0x1F1[0x16D];
    unsigned char nByte35E;
    char unk0x35F[0x42];
    char aData3A1[0x10];
    char aData3B1[0x10];
    unsigned char nByte3C1;
    unsigned char nByte3C2;
    char unk0x3C3[8];
    unsigned short wFlags3CB;
};
#pragma pack(pop)
extern int gnLaunchState_007795E8; // 0x007795E8
extern "C" const unsigned char gabDefault_006D4D88[]; // 0x006D4D88

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300
void __cdecl sub_0042F3F0_DestroyControls(); // 0x0042F3F0
int __stdcall sub_00432FA0_OnReceiveA(int nArg); // 0x00432FA0
void __fastcall sub_00433380_ShowMessage(const Unicode* pText, void (__cdecl* pfnDone)(), int nArg); // 0x00433380
char* __cdecl sub_00437D00(); // 0x00437D00
int __cdecl sub_00449B30_QueryAddress(); // 0x00449B30
int __cdecl sub_00449C00(); // 0x00449C00
int __stdcall sub_00449DF0_Forward3(const char* szName, int nClass, int nFlags); // 0x00449DF0
int __fastcall sub_004F9190(); // 0x004F9190
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

static __forceinline void __fastcall ShowText(const Unicode* pText, void (__cdecl* pfnDone)())
{
    sub_00433380_ShowMessage(pText, pfnDone, 1);
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00435E10
void __cdecl sub_00435E10()
{
    switch (sub_00432480(sub_00437D00(), 0))
    {
    case 1:
    case 2:
        sub_00435580();
        return;
    }

    if (!sub_00449C00() && sub_00449B30_QueryAddress())
    {
        if (sub_00449B30_QueryAddress())
        {
            gpLaunchRecord_007795D4->nByte3C1 = 1;
            SMemCopy(gpLaunchRecord_007795D4->aData3A1, gabDefault_006D4D88, 0x10);
            SMemZero(gpLaunchRecord_007795D4->aData3B1, 0x10);
            gpLaunchRecord_007795D4->nByte3C2 = (gpLaunchRecord_007795D4->wFlags >> 6) & 1;
            gpLaunchRecord_007795D4->wFlags3CB = gpLaunchRecord_007795D4->wFlags;
            sub_00449DF0_Forward3(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->wFlags);
            sub_0042F6E0();
            sub_004FA590_RunLoop(sub_00432FA0_OnReceiveA);
            if (gdwGlobal_00779974)
            {
                sub_0042F3F0_DestroyControls();
                return;
            }

            int nError = sub_00449C00();
            if (nError)
            {
                if (nError != 20)
                {
                    Unicode wszName[100];
                    sub_00410610_WriteLogLine("Error from MCP trying to create '%s' (err=%d)", gpLaunchRecord_007795D4->szCharName, sub_00449C00());
                    D2MCPClientCloseMCP();
                    Unicode wszText[255];
                    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x145E));
                    Unicode wszTail[255];
                    sub_005267E0(wszTail, D2LANG_GetStringFromTblIndex(0x145F));
                    char szName[80];
                    sprintf(szName, "%s", gpLaunchRecord_007795D4->szCharName);
                    sub_00526320_ToUnicode(wszName, szName, 100);
                    sub_00526700(wszText, wszName);
                    sub_00526700(wszText, wszTail);
                    ShowText(wszText, sub_00435580);
                    return;
                }

                D2MCPClientCloseMCP();
                Unicode wszText[256];
                Unicode wszName[256];
                sub_00526F20_ToUnicode(wszName, gpLaunchRecord_007795D4->szCharName, 256);
                sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0x2B33), wszName);
                ShowText(wszText, sub_00435580);
                return;
            }

            sub_0043C6A0(1);
            SStrCopy(gpLaunchRecord_007795D4->szAccount, sub_00437D00(), 0x7FFFFFFF);
            gpLaunchRecord_007795D4->wFlags |= 2;
            gpLaunchRecord_007795D4->nByte35E = 2;
            gnLaunchState_007795E8 = 3;
        }

        sub_004F9190();
        return;
    }

    D2MCPClientCloseMCP();
    int nString;
    switch (sub_00449C00())
    {
    case 2:
        nString = 0x145B;
        break;

    case 10:
    case 11:
    case 12:
        ShowText(D2LANG_GetStringFromTblIndex(0x145D), sub_00435580);
        return;

    case 71:
        nString = 0x145C;
        break;

    default:
        nString = 0x145C;
        break;
    }

    ShowText(D2LANG_GetStringFromTblIndex(nString), sub_0042FDD0);
}

#include "gen/data/Source/D2Client/Unknown_00435E10.inc"
