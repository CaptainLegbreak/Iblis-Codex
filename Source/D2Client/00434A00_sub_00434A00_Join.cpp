#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    char unk0x000[0x19];
    int nState19;
    char unk0x01D[0x85 - 0x1D];
    unsigned char nFlag085;
    unsigned char nFlag086;
    unsigned char nFlag087;
    unsigned char nFlag088;
    unsigned char nFlag089;
    unsigned char nFlag08A;
    unsigned char nFlag08B;
    char unk0x08C[0xBD - 0x8C];
    char szGameName[0x18];
    char szPassword[0x18];
    char unk0x0ED[0x101];
    char nMode;
    unsigned short wFlags;
    char unk0x1F1[0x18];
    unsigned int dwFlags209;
    char unk0x20D[0x20];
    char nByte22D;
    char unk0x22E[0x130];
    char nByte35E;
};
#pragma pack(pop)

struct Unicode
{
    unsigned short wChar;

    Unicode();                                                                                              // 0x0042F530
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x68];
    int (__fastcall* pfnSlot68)();
};

typedef void (__cdecl* D2LaunchDoneFn)();
typedef int (__stdcall* D2LaunchCallback)(int nArg);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040

void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
void __cdecl sub_0042F6E0();                                                                                // 0x0042F6E0
void __cdecl sub_0042FDD0();                                                                                // 0x0042FDD0
int __stdcall sub_00431D10(int nArg);                                                                       // 0x00431D10
int __fastcall sub_00432480(const char* szName, int bFlag);                                                 // 0x00432480
int __stdcall sub_00432FE0_OnReceiveB(int nArg);                                                            // 0x00432FE0
void __fastcall sub_00433380_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg);           // 0x00433380
int __cdecl sub_0043BF60();                                                                    // 0x0043BF60
int __fastcall sub_0043C180_Connect(D2LaunchRecordStrc* pRecord, int bFlag, int nMode);                     // 0x0043C180
void __cdecl sub_0043C4F0();                                                                                // 0x0043C4F0
void __cdecl D2MCPClientCloseMCP();                                                                         // 0x00449AD0
int __cdecl sub_00449B30_QueryAddress();                                                                    // 0x00449B30
int __cdecl sub_00449C00();                                                                                 // 0x00449C00
int __stdcall sub_00449E10_Forward1(const char* szName);                                                    // 0x00449E10
void __cdecl sub_004F9190();                                                              // 0x004F9190
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20

extern char gaGlobal_007089C4[];                                                                            // 0x007089C4
extern void* gpGlobal_0070B738;                                                                             // 0x0070B738
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4
extern int gnLaunchState_007795E8;                                                                          // 0x007795E8
extern int gnLaunchMode_007795EC;                                                                           // 0x007795EC
extern int gdwGlobal_00779974;                                                                              // 0x00779974
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0

static void sub_00431E70_SetModeFlags(char nMode);                                                          // 0x00431E70

static __declspec(noinline) void sub_00431E70_SetModeFlags(char nMode)
{
    gpLaunchRecord_007795D4->nMode = nMode;
    gpLaunchRecord_007795D4->nFlag085 = 0;
    gpLaunchRecord_007795D4->nFlag089 = 0;
    gpLaunchRecord_007795D4->nFlag088 = 0;
    gpLaunchRecord_007795D4->nFlag086 = 0;
    gpLaunchRecord_007795D4->nFlag087 = 0;
    gpLaunchRecord_007795D4->nFlag08A = 0;
    gpLaunchRecord_007795D4->nFlag08B = 0;

    if (nMode == 0)
    {
        gpLaunchRecord_007795D4->nFlag085 = 1;
    }
    else if (nMode == 4)
    {
        gpLaunchRecord_007795D4->nFlag089 = 1;
    }
    else if (nMode == 2)
    {
        gpLaunchRecord_007795D4->nFlag088 = 1;
    }
    else if (nMode == 3)
    {
        gpLaunchRecord_007795D4->nFlag086 = 1;
    }
    else if (nMode == 1)
    {
        gpLaunchRecord_007795D4->nFlag087 = 1;
    }
    else if (nMode == 5)
    {
        gpLaunchRecord_007795D4->nFlag08A = 1;
    }
    else if (nMode == 6)
    {
        gpLaunchRecord_007795D4->nFlag08B = 1;
    }
}

// 0x00434A00
int __fastcall sub_00434A00_Join(const char* szGameName, unsigned short wFlags, char nMode, const char* szPassword)
{
    int bPassword = szPassword[0] != 0;
    strcpy(gpLaunchRecord_007795D4->szGameName, szGameName);
    strcpy(gpLaunchRecord_007795D4->szPassword, szPassword);
    gpLaunchRecord_007795D4->wFlags = wFlags;
    sub_00431E70_SetModeFlags(nMode);

    if (gnLaunchMode_007795EC == 1 || gnLaunchMode_007795EC == 3)
    {
        if (!gpFuncTable_0077ABF0->pfnSlot68())
        {
            sub_0043C4F0();
            if (!sub_0043BF60())
                return 0;
            if (!sub_0043C180_Connect(gpLaunchRecord_007795D4, 0, 0))
                return 0;
        }
    }

    if (gnLaunchMode_007795EC == 0)
    {
        gpLaunchRecord_007795D4->nByte35E = 1;
        gnLaunchState_007795E8 = 1;
        gpLaunchRecord_007795D4->nState19 = 0;
        gpLaunchRecord_007795D4->dwFlags209 = 4;
        if (wFlags & 4)
            gpLaunchRecord_007795D4->dwFlags209 = 0x804;
        if (gpLaunchRecord_007795D4->wFlags & 0x20)
            gpLaunchRecord_007795D4->dwFlags209 |= 0x100000;
        sub_004F9190();
        return 1;
    }

    if (gnLaunchMode_007795EC == 2)
    {
        gpLaunchRecord_007795D4->nByte35E = 3;
        gnLaunchState_007795E8 = 1;
        gpLaunchRecord_007795D4->dwFlags209 = 4;
        if (wFlags & 4)
            gpLaunchRecord_007795D4->dwFlags209 = 0x804;
        if (gpLaunchRecord_007795D4->wFlags & 0x20)
            gpLaunchRecord_007795D4->dwFlags209 |= 0x100000;
        sub_004F9190();
        return 1;
    }
    {
        int bNewGame;
        if (bPassword)
        {
            switch (sub_00432480(szPassword, 0))
            {
            case 1:
                return 0;
            case 2:
            {
                const Unicode* pText = D2LANG_GetStringFromTblIndex(0x145B);
                sub_00433380_ShowMessage(pText, sub_0042FDD0, 1);
                return 1;
            }
            }

            if (sub_00449C00())
            {
                D2MCPClientCloseMCP();
                int nString;
                switch (sub_00449C00())
                {
                case 2:
                    nString = 0x145B;
                    break;
                case 0x47:
                    nString = 0x145C;
                    break;
                default:
                    nString = 0x145B;
                    break;
                }
                const Unicode* pText = D2LANG_GetStringFromTblIndex(nString);
                sub_00433380_ShowMessage(pText, sub_0042FDD0, 1);
                return 1;
            }

            sub_00449E10_Forward1(gpLaunchRecord_007795D4->szGameName);
            sub_0042F6E0();
            sub_004FA590_RunLoop(sub_00432FE0_OnReceiveB);
            int nState = sub_00449C00();
            if (nState == 0x46 || !sub_00449B30_QueryAddress())
            {
                sub_0042F3F0_DestroyControls();
                const Unicode* pText = D2LANG_GetStringFromTblIndex(0x140D);
                sub_00433380_ShowMessage(pText, sub_0042FDD0, 1);
                return 0;
            }

            if (nState == 0x7B)
            {
                Unicode wszText[256];
                Unicode wszName[256];
                sub_00526F20_ToUnicode(wszName, gpLaunchRecord_007795D4->szGameName, 256);
                D2MCPClientCloseMCP();
                sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0x2B89), wszName);
                sub_0042F3F0_DestroyControls();
                void* pSaved = gpGlobal_0070B738;
                gpGlobal_0070B738 = gaGlobal_007089C4;
                sub_00433380_ShowMessage(wszText, sub_0042FDD0, 1);
                gpGlobal_0070B738 = pSaved;
                return 0;
            }

            if (gdwGlobal_00779974)
            {
                sub_0042F3F0_DestroyControls();
                return 0;
            }

            bNewGame = 0;
        }
        else
        {
            gpLaunchRecord_007795D4->nByte22D = 0;
            gpLaunchRecord_007795D4->szPassword[0] = 0;
            bNewGame = 1;
        }

        if (!bNewGame)
        {
            gpLaunchRecord_007795D4->nByte35E = 2;
        }
        else
        {
            gpLaunchRecord_007795D4->nByte35E = 4;
            gpLaunchRecord_007795D4->dwFlags209 = 4;
            if (wFlags & 4)
                gpLaunchRecord_007795D4->dwFlags209 = 0x804;
            if (gpLaunchRecord_007795D4->wFlags & 0x20)
                gpLaunchRecord_007795D4->dwFlags209 |= 0x100000;
        }

        gnLaunchState_007795E8 = 3;
        sub_0042F6E0();
        sub_004FA590_RunLoop(sub_00431D10);
        sub_004F9190();
        return 1;
    }
}

#include "gen/data/Source/D2Client/00434A00_sub_00434A00_Join.inc"
