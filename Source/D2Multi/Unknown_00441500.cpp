#include "D2Multi.h"

struct Unicode
{
    unsigned short wChar;
};

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct D2LaunchFuncsStrc
{
    char unk0x00[0x30];
    void (__fastcall* pfn0x30)();
    int (__fastcall* pfn0x34)(char* szA, char* szB, const char* szC, int nD);
    char unk0x38[0x04];
    int (__fastcall* pfn0x3C)(char* szA, char* szB);
};

struct D2LaunchCharInfoStrc
{
    char unk0x00[0x19];
    char nState[4];
    char wValue[2];
    char szText0x1F[0x18];
    char szText0x37[0x1B8];
    char wFlags[2];
    char unk0x1F1[0x38];
    char nValue0x229[4];
    char bOnline;
    char unk0x22E[0x17];
    char szText0x245[0x10];
    char unk0x255[0x16D];
    char bFlag0x3C2;
};

struct D2LaunchReplyStrc
{
    int nStatus;
    unsigned short f_4;
};
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __cdecl sub_004F9190();                                                              // 0x004F9190
int __stdcall CONTROL_MouseInsideRect(const tagRECT* pRect);                                                // 0x004F97B0
void __fastcall sub_0043FB50_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone);                      // 0x0043FB50
void __stdcall sub_004413E0_Enable(int bEnable);                                                            // 0x004413E0
void __cdecl sub_0043E3A0_ProcessQueue();                                                                   // 0x0043E3A0
void __fastcall sub_00442B90_HandleReply(D2LaunchReplyStrc* pReply);                                        // 0x00442B90
void __cdecl sub_00442E00_Poll();                                                                           // 0x00442E00
void __fastcall sub_00442EB0_HandleOther(D2LaunchReplyStrc* pReply);                                        // 0x00442EB0
void __cdecl sub_00443130_Reset();                                                                          // 0x00443130
int __cdecl sub_00447A10_Pump();                                                                            // 0x00447A10
void* __cdecl sub_00449BC0();                                                                               // 0x00449BC0
unsigned short __cdecl sub_00449BD0_GetRequestId();                                                         // 0x00449BD0
void* __cdecl sub_00449D50();                                                                               // 0x00449D50
void __cdecl sub_00449D60_ClearReply();                                                                     // 0x00449D60
int __cdecl sub_00449DE0();                                                                                 // 0x00449DE0
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                                  // 0x0077BBD8
unsigned short gwSavedRequestId_0077BBDC;                                                                   // 0x0077BBDC
unsigned short gwOtherRequestId_0077BBE0;                                                                   // 0x0077BBE0
int gnLaunchMode_0077BBE4;                                                                                  // 0x0077BBE4
unsigned long gdwConnectTime_0077BBF0;                                                                      // 0x0077BBF0
extern int gnLoopValueOut_0077BC14;                                                                         // 0x0077BC14
extern int gnLoopValueIn_0077BC18;                                                                          // 0x0077BC18
static int gbDone_0077BDA0;                                                                                 // 0x0077BDA0

// 0x00441500
int __stdcall sub_00441500(int nUnused)
{
    static unsigned long s_dwTimer_0077BDC0; // 0x0077BDC0
    static unsigned long s_dwTimer_0077BDBC; // 0x0077BDBC
    static unsigned long s_dwTimer_0077BDB8; // 0x0077BDB8
    tagRECT tRect;
    SetRect(&tRect, 0x91, 0xB, 0x28F, 0x47);
    if (CONTROL_MouseInsideRect(&tRect))
        sub_004F9160_SetLoopValue(gnLoopValueIn_0077BC18);
    else
        sub_004F9160_SetLoopValue(gnLoopValueOut_0077BC14);

    if (gnLaunchMode_0077BBE4 == 2 && gdwConnectTime_0077BBF0 > 0)
    {
        if (GetTickCount() - gdwConnectTime_0077BBF0 > 30000)
        {
            gnLaunchMode_0077BBE4 = 0;
            sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1415), 0);
            gdwConnectTime_0077BBF0 = 0;
        }
    }

    int bPending;
    do
    {
        bPending = sub_00447A10_Pump() | sub_00449B70_Receive();

        switch (gnLaunchMode_0077BBE4)
        {
        case 3:
            if (sub_00449B30_QueryAddress())
            {
                D2LaunchReplyStrc* pReply = (D2LaunchReplyStrc*)sub_00449D50();
                const unsigned short wId = pReply->f_4;
                if (wId != 0)
                {
                    if (wId == gwSavedRequestId_0077BBDC)
                    {
                        const int nResult = sub_00449C00();
                        if (nResult == 0x33)
                        {
                            sub_00442C20_HandleList();
                            sub_00449D60_ClearReply();
                        }
                        else if (nResult == 0x32)
                        {
                            sub_00443130_Reset();
                            sub_004413E0_Enable(1);
                            sub_00449D60_ClearReply();
                        }
                        else if (pReply->nStatus)
                        {
                            sub_00442C20_HandleList();
                            sub_00449D60_ClearReply();
                        }
                        else
                        {
                            sub_00442B90_HandleReply(pReply);
                            sub_00449D60_ClearReply();
                        }
                    }
                    else
                    {
                        if (wId == gwOtherRequestId_0077BBE0)
                            sub_00442EB0_HandleOther(pReply);
                        sub_00449D60_ClearReply();
                    }
                }
            }
            break;

        case 2:
            if (sub_00449B30_QueryAddress())
            {
                const int nId = sub_00449BD0_GetRequestId();
                if (nId != 0 && nId == gwSavedRequestId_0077BBDC)
                {
                    switch (sub_00449C00())
                    {
                    case 0:
                    {
                        *(int*)gpCharInfo_0077BBD8->nState = 3;
                        *(unsigned short*)gpCharInfo_0077BBD8->wValue = (unsigned short)sub_00449BE0();
                        *(int*)gpCharInfo_0077BBD8->nValue0x229 = sub_00449DE0();
                        const char* szSource = (const char*)sub_00449BC0();
                        char* szDest = gpCharInfo_0077BBD8->szText0x37;
                        char c;
                        do
                        {
                            c = *szSource;
                            *szDest = c;
                            szSource++;
                            szDest++;
                        }
                        while (c != 0);
                        gbDone_0077BDA0 = 1;
                        gpLaunchFuncs_0077B09C->pfn0x3C(gpCharInfo_0077BBD8->szText0x1F, gpCharInfo_0077BBD8->szText0x245);
                        sub_004F9160_SetLoopValue(0);
                        sub_004F9190();
                        return 1;
                    }
                    case 42:
                        gnLaunchMode_0077BBE4 = 0;
                        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1427), sub_0043DAF0_OnConnect);
                        break;
                    case 41:
                        gnLaunchMode_0077BBE4 = 0;
                        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1428), sub_0043DAF0_OnConnect);
                        break;
                    case 43:
                        gnLaunchMode_0077BBE4 = 0;
                        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1429), sub_0043DAF0_OnConnect);
                        break;
                    case 44:
                        gnLaunchMode_0077BBE4 = 0;
                        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x142A), sub_0043DAF0_OnConnect);
                        break;
                    case 115:
                        gnLaunchMode_0077BBE4 = 0;
                        if (*(unsigned short*)gpCharInfo_0077BBD8->wFlags & 0x20)
                            sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x5522), sub_0043DAF0_OnConnect);
                        else
                            sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x14F4), sub_0043DAF0_OnConnect);
                        break;
                    case 116:
                        gnLaunchMode_0077BBE4 = 0;
                        if (*(unsigned short*)gpCharInfo_0077BBD8->wFlags & 0x20)
                            sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x5521), sub_0043DAF0_OnConnect);
                        else
                            sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x14F3), sub_0043DAF0_OnConnect);
                        break;
                    case 125:
                        gnLaunchMode_0077BBE4 = 0;
                        if (gpCharInfo_0077BBD8->bFlag0x3C2)
                            sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x2AB1), sub_0043DAF0_OnConnect);
                        else
                            sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x2AB2), sub_0043DAF0_OnConnect);
                        break;
                    case 113:
                        gnLaunchMode_0077BBE4 = 0;
                        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1426), sub_0043DAF0_OnConnect);
                        break;
                    case 120:
                        gnLaunchMode_0077BBE4 = 0;
                        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x2775), sub_0043DAF0_OnConnect);
                        break;
                    case 121:
                        gnLaunchMode_0077BBE4 = 0;
                        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x2776), sub_0043DAF0_OnConnect);
                        break;
                    default:
                        gnLaunchMode_0077BBE4 = 0;
                        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1415), sub_0043DAF0_OnConnect);
                        break;
                    }
                }
            }
            break;

        case 1:
            if (sub_00449B30_QueryAddress())
            {
                const int nId = sub_00449BD0_GetRequestId();
                if (nId != 0 && nId == gwSavedRequestId_0077BBDC)
                {
                    switch (sub_00449C00())
                    {
                    case 0:
                        gnLaunchMode_0077BBE4 = 2;
                        while (++gwRequestId_0070CD60 == 0)
                        {
                        }
                        sub_0044A4E0_SendConnect(gpCharInfo_0077BBD8->szText0x1F, gpCharInfo_0077BBD8->szText0x245, gwRequestId_0070CD60);
                        gwSavedRequestId_0077BBDC = gwRequestId_0070CD60;
                        gpLaunchFuncs_0077B09C->pfn0x34(gpCharInfo_0077BBD8->szText0x1F, gpCharInfo_0077BBD8->szText0x245, &gszEmptyAssertText, 0);
                        break;
                    case 30:
                        gnLaunchMode_0077BBE4 = 0;
                        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1411), sub_0043DAF0_OnConnect);
                        break;
                    case 31:
                        gnLaunchMode_0077BBE4 = 0;
                        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1412), sub_0043DAF0_OnConnect);
                        break;
                    case 32:
                        gnLaunchMode_0077BBE4 = 0;
                        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), sub_0043DAF0_OnConnect);
                        break;
                    default:
                        gnLaunchMode_0077BBE4 = 0;
                        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1414), sub_0043DAF0_OnConnect);
                        break;
                    }
                }
            }
            break;
        }

        int bUpdated = 0;
        unsigned long dwElapsed = GetTickCount() - s_dwTimer_0077BDC0;
        if (dwElapsed >= 15000)
        {
            s_dwTimer_0077BDC0 += dwElapsed;
            bUpdated = 1;
            gpLaunchFuncs_0077B09C->pfn0x30();
            const unsigned short wFlags = *(unsigned short*)gpCharInfo_0077BBD8->wFlags;
            if (!(wFlags & 8) || !(wFlags & 4))
            {
                int bEnable = 0;
                if (gpCharInfo_0077BBD8->bOnline && !sub_00449B30_QueryAddress())
                    bEnable = 1;
                sub_004413E0_Enable(bEnable);
            }
        }
        if (gnLaunchMode_0077BBE4 == 3)
        {
            dwElapsed = GetTickCount() - s_dwTimer_0077BDBC;
            if (dwElapsed >= 15000)
            {
                s_dwTimer_0077BDBC += dwElapsed;
                bUpdated = 1;
                sub_00445020_SendLaunchRequest();
            }
        }
        dwElapsed = GetTickCount() - s_dwTimer_0077BDB8;
        if (dwElapsed >= 1000)
        {
            s_dwTimer_0077BDB8 += dwElapsed;
            bUpdated = 1;
            sub_00442E00_Poll();
        }
        sub_0043E3A0_ProcessQueue();
        if (!bUpdated)
            return 0;
    }
    while (bPending);
    return 1;
}
