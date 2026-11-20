#include "D2MultiTypes.h"
extern "C" int __cdecl strcmp(const char* szA, const char* szB);
#pragma intrinsic(strcmp)

#define D2_STACKARG(x) (x)

extern D2MultiChannelUserStrc* gpChannelUsers_00798F34;                                                          // 0x00798F34
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
unsigned char __fastcall sub_00446D90_ParseStatString(D2MultiChannelUserStrc* pUser, unsigned int nFlags);    // 0x00446D90

static __declspec(noinline) void __fastcall sub_00447FD0_UpdateUser(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const char* szName, const unsigned char* pStat);

// calling-convention shim (not game code)
static void __fastcall sub_00447FD0_UpdateUser(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const char* szName, const unsigned char* pStat)
{
    pUser->dwFlags = nFlags;
    pUser->dwCode = *pStat;
    sub_00446D90_ParseStatString(pUser, nFlags);
    SStrCopy(pUser->szName, (const char*)D2_STACKARG(szName), 0x7FFFFFFF);
}

// 0x004480D0
int __fastcall sub_004480D0_OnUserUpdate(unsigned int nFlags, int nUnused, const char* szName, const unsigned char* pStat)
{
    D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34;
    if (gpChannelUsers_00798F34)
    {
        do
        {
            if (!strcmp(pUser->szName, szName))
            {
                sub_00447FD0_UpdateUser(pUser, nFlags, szName, pStat);
                return 1;
            }
            pUser = pUser->pNext;
        }
        while (pUser);
    }

    return 0;
}
