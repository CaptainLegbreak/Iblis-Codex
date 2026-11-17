struct D2UnitStrc;
struct D2ActiveRoomStrc;

struct D2ClientConfigStrc
{
    char unk0x000[0x1EF];
    unsigned char nFlags1EF;
};

typedef void (__fastcall* D2ClientCallbackFn)(void* pArg);

struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

void __cdecl sub_00449B70();                                                                                // 0x00449B70
void __cdecl sub_0044C000();                                                                                // 0x0044C000
void __cdecl sub_0044C2C0();                                                                                // 0x0044C2C0
void __cdecl sub_0044C6E0();                                                                                // 0x0044C6E0
void __cdecl sub_0044C790();                                                                                // 0x0044C790
__declspec(noinline) int __fastcall sub_0044CCA0(unsigned int nFrames, unsigned int nRemainder, int nRate);

// 0x0044CCA0
int __fastcall sub_0044CCA0(unsigned int nValue, unsigned int nUnused, int nLimit)
{
    int nCount = 0;
    if (nLimit < 7)
        nCount = 1;
    if ((int)nValue > 1)
        nCount++;
    if ((int)nValue > 9)
        nCount++;
    if ((int)nValue > 0x13)
        nCount++;
    if ((int)nValue > 0x1D)
        nCount++;
    return nCount;
}
void __cdecl sub_0044CCE0();                                                                                // 0x0044CCE0
void __cdecl sub_0044CE90();                                                                                // 0x0044CE90
void __cdecl sub_0044EEC0();                                                                                // 0x0044EEC0
void __cdecl sub_004519C0();                                                                                // 0x004519C0
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar);                                                  // 0x00453A90
int __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2);                                              // 0x00456300
void __cdecl sub_00462920();                                                                                // 0x00462920
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
void __cdecl sub_00467AC0();                                                                                // 0x00467AC0
void __cdecl sub_00477DD0();                                                                                // 0x00477DD0
void __cdecl sub_0047BDF0();                                                                                // 0x0047BDF0
void __fastcall sub_00480320(int nDelta);                                                                   // 0x00480320
void __cdecl sub_00480340();                                                                                // 0x00480340
void __fastcall sub_00481600(D2UnitStrc* pPlayer);                                                          // 0x00481600
void __cdecl sub_00482C20_Tick();                                                                           // 0x00482C20
int __stdcall WINDOW_GetState();                                                                            // 0x004F6070
void __fastcall sub_004FB480_SetActA(unsigned char nAct);                                                   // 0x004FB480
int __cdecl sub_00514840_IsChannelStreaming();                                                              // 0x00514840
void __cdecl sub_00514930();                                                                                // 0x00514930
void __fastcall sub_00515CE0_SetMasterVolume(int nVolume);                                                  // 0x00515CE0
void __fastcall sub_00515F50(int nArg);                                                                     // 0x00515F50
void __cdecl sub_0052CFE0();                                                                                // 0x0052CFE0
void __cdecl sub_0052E9C0();                                                                                // 0x0052E9C0
int __stdcall sub_0052FC20(int nArg);                                                                       // 0x0052FC20
void __stdcall sub_0052FD90(int nArg1, int nArg2);                                                          // 0x0052FD90

extern unsigned int gdwFrameTime_0070EF1C;                                                                  // 0x0070EF1C
extern D2ClientConfigStrc* gpConfig_007A0438;                                                               // 0x007A0438
extern _RTL_CRITICAL_SECTION gCriticalSection_007A0468;                                                     // 0x007A0468
D2ClientCallbackFn gpfnClientCallback_007A0484;                                                             // 0x007A0484
unsigned int gdwGlobal_007A048C;                                                                            // 0x007A048C
unsigned int gdwLastFrame_007A0490;                                                                         // 0x007A0490
int gnGlobal_007A0494;                                                                                      // 0x007A0494
unsigned int gdwNextCheck_007A049C;                                                                         // 0x007A049C
extern unsigned int gdwLastCheck_007A04A0;                                                                  // 0x007A04A0
int gdwGlobal_007A04A8;                                                                                     // 0x007A04A8
int gnGlobal_007A04AC;                                                                                      // 0x007A04AC
int gnGlobal_007A04B0;                                                                                      // 0x007A04B0
int gnGlobal_007A04B4;                                                                                      // 0x007A04B4
extern unsigned int gdwGlobal_007A04B8;                                                                     // 0x007A04B8
extern unsigned int gdwGlobal_007A04BC;                                                                     // 0x007A04BC
void* ghEvent_007A05BC;                                                                                     // 0x007A05BC
int gnGameType_007A0610;                                                                                    // 0x007A0610
extern int gdwGlobal_007A061C;                                                                              // 0x007A061C
extern int gdwGlobal_007A0620;                                                                              // 0x007A0620
extern int gnGlobal_007A0648;                                                                               // 0x007A0648
extern int gnGlobal_007A0650;                                                                               // 0x007A0650
extern int gnGlobal_007A0654;                                                                               // 0x007A0654
int gnSkipped_007A0704;                                                                                     // 0x007A0704

// 0x0044EFA0
int __stdcall sub_0044EFA0_GameFrame(int nUnused)
{
    int bFrame = 0;
    int bDrawn = 0;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (gnGameType_007A0610 == 0 || gnGameType_007A0610 == 1)
    {
        if (WINDOW_GetState())
        {
            gdwLastFrame_007A0490 = GetTickCount();
            return 0;
        }

        if ((sub_00453A90_GetUIVarUnchecked(9) || sub_00453A90_GetUIVarUnchecked(11)) && pPlayer && sub_004646A0_GetPlayerRoom())
        {
            gdwLastFrame_007A0490 = GetTickCount();
            gpfnClientCallback_007A0484(0);
            sub_00482C20_Tick();
            return 0;
        }
    }

    sub_004519C0();
    if (gnGlobal_007A0650)
    {
        sub_0044C000();
    }

    if (gnGlobal_007A0654)
    {
        sub_0044C2C0();
    }

    sub_0044CE90();

    unsigned int dwNow = GetTickCount();
    if (gdwNextCheck_007A049C < dwNow)
    {
        sub_00477DD0();
        gdwLastCheck_007A04A0 = dwNow;
        if (gpConfig_007A0438->nFlags1EF & 4)
        {
            gdwNextCheck_007A049C = dwNow + 5000;
        }
        else
        {
            gdwNextCheck_007A049C = dwNow + 5000;
        }
    }

    gdwGlobal_007A048C = GetTickCount();
    if (!gdwLastFrame_007A0490)
    {
        gdwLastFrame_007A0490 = gdwGlobal_007A048C - gdwFrameTime_0070EF1C;
    }

    sub_00480320(gdwLastFrame_007A0490 - gdwGlobal_007A048C);
    sub_0044CCE0();

    unsigned int nElapsed = gdwGlobal_007A048C - gdwLastFrame_007A0490;
    if (nElapsed >= gdwFrameTime_0070EF1C)
    {
        gdwLastFrame_007A0490 = gdwGlobal_007A048C;
        bFrame = 1;
        if (gdwGlobal_007A048C < gdwGlobal_007A04BC)
        {
            nElapsed -= gdwFrameTime_0070EF1C;
            unsigned int nLate = gdwFrameTime_0070EF1C - 1;
            if (nElapsed < nLate)
            {
                nLate = nElapsed;
            }

            gdwLastFrame_007A0490 = gdwGlobal_007A048C - nLate;
            gnSkipped_007A0704 = 0;
            nElapsed = gdwFrameTime_0070EF1C;
            gdwGlobal_007A04B8 = gdwGlobal_007A048C;
            gdwGlobal_007A04A8 = 25;
            gnGlobal_007A04B0 = 0;
            gnGlobal_007A04AC = 0;
            gnGlobal_007A04B4 = 0;
        }

        if (gdwGlobal_007A061C)
        {
            sub_00481600(pPlayer);
        }
    }

    int bReady = 0;
    if (gnGameType_007A0610 == 0)
    {
        sub_0052CFE0();
        bReady = sub_0052FC20(1);
        if (bReady)
        {
            sub_0052FD90(1, 0);
        }
    }
    else if (gnGameType_007A0610 == 1)
    {
        sub_0052CFE0();
        bReady = sub_0052FC20(1);
        sub_0052FD90(0, 0);
    }

    sub_0044C6E0();
    sub_0047BDF0();
    sub_00449B70();
    sub_0044EEC0();

    if (gdwGlobal_007A061C)
    {
        if (gnGameType_007A0610 != 0 && gnGameType_007A0610 != 1)
        {
            if (bFrame)
            {
                sub_0044C790();
                gdwLastFrame_007A0490 += gdwFrameTime_0070EF1C - nElapsed;
                bDrawn = 1;
                const int nRate = gdwGlobal_007A04A8;
                const unsigned int nFrames = nElapsed / gdwFrameTime_0070EF1C;
                const unsigned int nRest = nElapsed % gdwFrameTime_0070EF1C;
                int nLimit = sub_0044CCA0(nFrames, nRest, nRate);
                if (nRate > 28)
                {
                    nLimit = 0;
                }

                if (gnSkipped_007A0704 > nLimit)
                {
                    gnSkipped_007A0704 = 0;
                }
            }
            else if (gdwGlobal_007A04A8 > 22)
            {
                gnSkipped_007A0704 = 0;
            }
        }
        else if (bReady)
        {
            sub_0044C790();
            bDrawn = 1;
            if (nElapsed <= gdwFrameTime_0070EF1C)
            {
                gnSkipped_007A0704 = 0;
            }
            else if (nElapsed < 2 * gdwFrameTime_0070EF1C)
            {
                gdwLastFrame_007A0490 += gdwFrameTime_0070EF1C - nElapsed;
                gnSkipped_007A0704 = 0;
            }
            else
            {
                gnSkipped_007A0704 = gnSkipped_007A0704 <= 1;
                gdwLastFrame_007A0490 += 1 - gdwFrameTime_0070EF1C;
            }
        }
    }

    if (gdwGlobal_007A061C)
    {
        sub_00462920();
        sub_00467AC0();
        if (sub_00514840_IsChannelStreaming())
        {
            sub_00515F50(0xB4);
            sub_00514930();
            sub_00515CE0_SetMasterVolume(0xFF);
        }

        if (!gnSkipped_007A0704)
        {
            if (sub_004646A0_GetPlayerRoom())
            {
                gpfnClientCallback_007A0484(0);
                ++gnGlobal_007A0494;
                ++gnGlobal_007A04AC;
            }
        }
        else if (bFrame)
        {
            ++gnGlobal_007A04B4;
        }

        if (bDrawn)
        {
            sub_00482C20_Tick();
        }

        ++gnSkipped_007A0704;
    }
    else
    {
        WINDOW_GetState();
    }

    if (!gdwGlobal_007A0620)
    {
        return 0;
    }

    sub_00480340();
    sub_004FB480_SetActA(0);
    sub_00456300_CloseUIVars(1, 0);
    if (gnGameType_007A0610 == 0 || gnGameType_007A0610 == 1)
    {
        sub_0052E9C0();
    }

    if (gnGameType_007A0610 == 6 || gnGameType_007A0610 == 8)
    {
        EnterCriticalSection(&gCriticalSection_007A0468);
        gnGlobal_007A0648 = 1;
        LeaveCriticalSection(&gCriticalSection_007A0468);
        WaitForSingleObject(ghEvent_007A05BC, 10000);
        ghEvent_007A05BC = 0;
    }

    return 1;
}

#include "gen/data/Source/D2Client/0044EFA0_sub_0044EFA0_GameFrame.inc"
