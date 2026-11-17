extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie); // 0x00681A48
int __fastcall sub_00517AD6_Check(void* pContext); // 0x00517AD6
bool __fastcall sub_00517C30_Read(void* pContext, char* pBuffer, int nSize); // 0x00517C30
int __cdecl sub_00686040_Compare(const void* pA, const void* pB, unsigned int nSize); // 0x00686040
extern const char* gpReference_0072F9F0; // 0x0072F9F0

// 0x00516DE1
bool __fastcall sub_00516DE1_Verify(void* pContext)
{
    char szBuffer[0x200];
    if (sub_00517AD6_Check(pContext))
    {
        return false;
    }
    bool bResult = sub_00517C30_Read(pContext, szBuffer, sizeof(szBuffer));
    if (bResult)
    {
        bResult = sub_00686040_Compare(szBuffer, gpReference_0072F9F0, sizeof(szBuffer)) == 0;
    }
    return bResult;
}

#include "gen/data/Source/D2Win/00516DE1_sub_00516DE1_Verify.inc"
