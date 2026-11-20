#include "D2BnCryptTypes.h"

void __fastcall sub_00524360_ExpandKey(const D2IdeaUserKeyStrc* pUserKey, D2IdeaKeyScheduleStrc* pSchedule); // 0x00524360
void __fastcall sub_005243E0_InvertKey(const unsigned short* pEK, unsigned short* pDK);                    // 0x005243E0
void __fastcall sub_00524540_Cipher(const unsigned short* pIn, unsigned short* pOut, const unsigned short* pKey); // 0x00524540

extern D2IdeaKeyScheduleStrc gaIdeaKeySchedules_00882878[];                                                // 0x00882878

// 0x00524760
void __fastcall sub_00524760_CipherBlock(int nIndex, const unsigned short* pIn, unsigned short* pOut)
{
    sub_00524540_Cipher(pIn, pOut, gaIdeaKeySchedules_00882878[nIndex].aKey);
}

// build: context sub_00524780_SetKey
void __fastcall sub_00524780_SetKey(int nIndex, int bEncrypt, const D2IdeaUserKeyStrc* pUserKey)
{
    D2IdeaUserKeyStrc tUserKey = *pUserKey;
    if (bEncrypt)
    {
        sub_00524360_ExpandKey(&tUserKey, &gaIdeaKeySchedules_00882878[nIndex]);
    }
    else
    {
        D2IdeaKeyScheduleStrc tTemp;
        sub_00524360_ExpandKey(&tUserKey, &tTemp);
        sub_005243E0_InvertKey(tTemp.aKey, gaIdeaKeySchedules_00882878[nIndex].aKey);
    }
}
