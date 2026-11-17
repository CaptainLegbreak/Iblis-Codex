#include "D2Client.h"

struct Unicode
{
    unsigned short wChar;
    static Unicode* __fastcall strncpy(Unicode* dest, const Unicode* src, int count);                       // 0x00526790
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    long lParam;
    char unk0x10[8];
    int bUseResult;
    long lResult;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C
extern "C" T0046E1B0* __stdcall ImmGetContext(int hWnd);                                                       // 0x006B00C6
extern "C" int __stdcall ImmReleaseContext(int hWnd, T0046E1B0* hImc);                                         // 0x006B00B4
extern "C" long __stdcall ImmGetCompositionStringA(T0046E1B0* hImc, unsigned long dwIndex, void* pBuf, unsigned long dwBufLen); // 0x006B00C0
extern "C" int __stdcall ImmGetOpenStatus(T0046E1B0* hImc);                                                    // 0x006B00BA
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                            // 0x00420290

Unicode gwChatText_007BB5F8[32];                                                                            // 0x007BB5F8
extern Unicode gwszChatLine_007BB638[];                                                                     // 0x007BB638
Unicode gwChatText_007BC850[32];                                                                            // 0x007BC850
extern int gnChatCaret_007BB5E8;                                                                            // 0x007BB5E8

// 0x0047AA60
void __stdcall sub_0047AA60_OnImeComposition(SMSGHANDLER_PARAMS* pMsg)
{
    char szComp[200];
    memset(szComp, 0, sizeof(szComp));
    T0046E1B0* hImc = ImmGetContext(sub_004F59A0());
    if (hImc)
    {
        Unicode wszText[32];
        for (int i = 0; i < 32; ++i)
            wszText[i].wChar = 0;
        if (pMsg->lParam & 0x800)
        {
            unsigned long nLength = ImmGetCompositionStringA(hImc, 0x800, 0, 0);
            if (nLength > 199)
                nLength = 199;
            ImmGetCompositionStringA(hImc, 0x800, szComp, nLength);
            szComp[199] = 0;
            MultiByteToWideChar(0, 1, szComp, -1, (wchar_t*)wszText, 32);
            wszText[31].wChar = 0;
            const int nTextLength = sub_00526800(wszText);
            if (sub_00526800(gwszChatLine_007BB638) + sub_00526800(gwChatText_007BB5F8) < 0x7F)
            {
                sub_00526700(gwszChatLine_007BB638, gwChatText_007BB5F8);
                gnChatCaret_007BB5E8 += sub_00526800(gwChatText_007BB5F8);
            }
            if (sub_00526800(gwszChatLine_007BB638) + nTextLength < 0x7F)
            {
                sub_00526700(gwszChatLine_007BB638, wszText);
                gnChatCaret_007BB5E8 += nTextLength;
            }
            gwChatText_007BB5F8[0].wChar = 0;
            gwChatText_007BC850[0].wChar = 0;
        }
        if ((pMsg->lParam & 8) && ImmGetOpenStatus(hImc))
        {
            unsigned long nLength = ImmGetCompositionStringA(hImc, 8, 0, 0);
            if (nLength > 0)
            {
                memset(szComp, 0, sizeof(szComp));
                memset(wszText, 0, sizeof(wszText));
                if (nLength > 199)
                    nLength = 199;
                if (ImmGetCompositionStringA(hImc, 8, szComp, nLength) > 0)
                {
                    szComp[199] = 0;
                    MultiByteToWideChar(0, 1, szComp, -1, (wchar_t*)wszText, 32);
                    const int nCount = sub_00526800(wszText);
                    if (nCount < 31)
                        wszText[nCount].wChar = 0;
                    else
                        wszText[31].wChar = 0;
                    if (nCount >= 32)
                    {
                        Unicode::strncpy(gwChatText_007BC850, wszText, 31);
                        gwChatText_007BC850[31].wChar = 0;
                        sub_004B9A00(1, 0, 0, 0, 0);
                    }
                    else
                    {
                        sub_005267E0(gwChatText_007BC850, wszText);
                    }
                }
            }
        }
        ImmReleaseContext(sub_004F59A0(), hImc);
    }
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}
