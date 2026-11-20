#include "D2Client.h"
#include "D2Unicode.h"

struct D2CelFileStrc;

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
int __cdecl sub_0044B850_IsHardcore();                                                                      // 0x0044B850
unsigned char __cdecl sub_0044DCD0_GetDifficulty();                                                         // 0x0044DCD0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType);                             // 0x004788B0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
void __fastcall sub_00502680_DrawCellFile(D2CelFileStrc* pCell, int nX, int nY, int nA, int nB, int nC);  // 0x00502680
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...);                  // 0x005269D0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
int gbDeathScreenShown_007A2890;                                                                            // 0x007A2890
D2CelFileStrc* gpYouDiedHardcoreCel_007A2894;                                                              // 0x007A2894
D2CelFileStrc* gpYouDiedInstCel_007A2898;                                                                  // 0x007A2898
extern int gnAutomapWidth_007A5220;                                                                         // 0x007A5220

// 0x00453100
void __cdecl sub_00453100_DrawDeathScreen()
{
    char szPath[0x104];
    char szLanguage[4];
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;

    if (sub_00464820_IsDeadOrDying(pPlayer))
    {
        int nY = gnGlobal_00711470 / 2 - 0x5E;
        sub_00525260(szLanguage, 0);
        if (!gpYouDiedHardcoreCel_007A2894)
        {
            sprintf(szPath, "%s\\UI\\%s\\youdiedhardcore", szDataLocal_006D41A8, szLanguage);
            gpYouDiedHardcoreCel_007A2894 = sub_004788B0(szPath, 0);
        }
        if (gpYouDiedHardcoreCel_007A2894)
            sub_00502680_DrawCellFile(gpYouDiedHardcoreCel_007A2894, gnGlobal_0071146C / 2, nY, 1, 5, 1);

        nY += 0x30;
        gbDeathScreenShown_007A2890 = 1;
        if (!gpYouDiedInstCel_007A2898)
        {
            sprintf(szPath, "%s\\UI\\%s\\youdiedinst", szDataLocal_006D41A8, szLanguage);
            gpYouDiedInstCel_007A2898 = sub_004788B0(szPath, 0);
        }
        if (gpYouDiedInstCel_007A2898)
            sub_00502680_DrawCellFile(gpYouDiedInstCel_007A2898, gnGlobal_0071146C / 2, nY, 1, 5, 1);

        Unicode wszText[0x100];
        if (sub_0044B850_IsHardcore())
        {
            sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x13E8));
        }
        else
        {
            if (!STATLIST_UnitGetStatValue(pPlayer, 0xAF, 0))
                goto second_text;
            sub_005269D0(0x100, wszText, D2LANG_GetStringFromTblIndex(0x13E6), STATLIST_UnitGetStatValue(pPlayer, 0xAF, 0));
        }
        nY += 0x30;
        sub_00502EF0(2);
        {
            const int nWidth = sub_00501820(wszText);
            const int nX = gnAutomapWidth_007A5220 / 2 - nWidth / 2;
            sub_00502320(wszText, nX, nY, 1, 1);
        }

second_text:
        if (sub_0044DCD0_GetDifficulty() > 0 && !sub_0044B850_IsHardcore())
        {
            sub_00502EF0(2);
            const int nWidth = sub_00501820(D2LANG_GetStringFromTblIndex(0x13E7));
            const int nX = gnAutomapWidth_007A5220 / 2 - nWidth / 2;
            nY += 0x30;
            sub_00502320(D2LANG_GetStringFromTblIndex(0x13E7), nX, nY, 1, 1);
        }
    }
    else
    {
        gbDeathScreenShown_007A2890 = 0;
    }
}
