#include "D2Client.h"
#include "D2Structs.h"


struct Unicode
{
    unsigned short wChar;
};

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470

// 0x00498EA0
void __cdecl sub_00498EA0_DrawExperienceBar()
{
    Unicode wszText[100];

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;
    const unsigned int nLevel = STATLIST_UnitGetStatValue(pPlayer, 0xC, 0);
    const unsigned int nExperience = STATLIST_UnitGetStatValue(pPlayer, 0xD, 0);
    const unsigned int nNextExperience = DATATBLS_GetLevelThreshold(nClass, STATLIST_GetUnitBaseStat(pPlayer, 0xC, 0));
    const unsigned int nLastExperience = DATATBLS_GetLevelThreshold(nClass, nLevel - 1);
    unsigned int nRange = nNextExperience - nLastExperience;
    unsigned int nProgress;
    if (nExperience > nLastExperience)
    {
        nProgress = nExperience - nLastExperience;
    }
    else
    {
        nProgress = 0;
    }

    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }

    if (nMouseX >= gnGlobal_0071146C / 2 - 0x92 && nMouseX <= gnGlobal_0071146C / 2 - 0x17 && nMouseY >= gnGlobal_00711470 - 0x2B && nMouseY <= gnGlobal_00711470 - 0x22)
    {
        sub_005269D0(100, wszText, D2LANG_GetStringFromTblIndex(0x1043), nExperience, nNextExperience);
        D2Win_10129_DrawFramedText(wszText, gnGlobal_0071146C / 2 - 0x92, gnGlobal_00711470 - 0x33, 0, 1);
    }

    if (nRange)
    {
        unsigned int nWidth;
        if (nProgress >= 0x226B902)
        {
            nWidth = (nProgress >> 7) * 0x77 / (nRange >> 7);
        }
        else
        {
            nWidth = nProgress * 0x77 / nRange;
        }

        if (nWidth > 0x77)
        {
            nWidth = 0;
        }

        if (nLevel < DATATBLS_GetMaxLevel(nClass) && nWidth > 0)
        {
            const int nX = gnGlobal_0071146C / 2 - 0x90;
            int nY = gnGlobal_00711470 - 0x26;
            D2GFX_DrawLine(nX, nY, nX + nWidth, nY, 0xFF, 0xFF);
            nY += 1;
            D2GFX_DrawLine(nX, nY, nX + nWidth, nY, 0xFF, 0xFF);
        }
    }
}
