struct D2WinControlStrc;

struct D2GameDetailsStrc
{
    char unk0x00[0x0C];
    unsigned int dwElapsed;
    unsigned char nLevel;
    unsigned char nLevelDiff;
    unsigned char nMaxPlayers;
    char unk0x13;
    int nPlayers;
    char unk0x18[0x14];
    char szDescription[0x20];
    unsigned short wClass[16];
    unsigned short wLevel[16];
    char szNames[16][16];
};

extern "C" const char gszEmptyString_006CC837[]; // 0x006CC837
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" unsigned int __cdecl strlen(const char* szString);

void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl); // 0x004FB6A0
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine); // 0x004FBA30
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
void __fastcall D2Win_10046(D2WinControlStrc* pTextBox, const char* szText, int nArg); // 0x004FCFF0

D2WinControlStrc* gpGameInfoText_00798BC4;        // 0x00798BC4

// 0x00442EB0
void __fastcall sub_00442EB0_ShowGameDetails(D2GameDetailsStrc* pDetails)
{
    char szLine[0x100];

    if (!gpGameInfoText_00798BC4)
        return;

    sub_004FB6A0_ClearText(gpGameInfoText_00798BC4);
    if (strlen(pDetails->szDescription))
    {
        sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, pDetails->szDescription);
        sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, gszEmptyString_006CC837);
    }

    unsigned int nSecondsPerHour = 3600;
    unsigned int nSecondsPerMinute = 60;
    unsigned int dwElapsed = pDetails->dwElapsed;
    unsigned int nHours = dwElapsed / nSecondsPerHour;
    unsigned int nRest = dwElapsed % nSecondsPerHour;
    sprintf(szLine, "Elapsed Time: %d:%02d:%02d", nHours, nRest / 60, dwElapsed % nSecondsPerMinute);
    sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, szLine);

    unsigned char nLevelDiff = pDetails->nLevelDiff;
    if (nLevelDiff < 100)
    {
        if (nLevelDiff)
        {
            int nDiff = nLevelDiff;
            int nLevel = pDetails->nLevel;
            int nMin = nLevel - nDiff;
            if (nMin <= 1)
                nMin = 1;
            int nMax = nDiff + nLevel;
            if (nMax >= 99)
                nMax = 99;
            sprintf(szLine, "Level %d to %d", nMin, nMax);
        }
        else
        {
            sprintf(szLine, "Level %d", pDetails->nLevel);
        }
        sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, szLine);
    }

    if (pDetails->nMaxPlayers > 0 && pDetails->nMaxPlayers < 8)
    {
        sprintf(szLine, "Up to %d Players", pDetails->nMaxPlayers);
        sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, szLine);
    }

    sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, gszEmptyString_006CC837);

    for (int i = 0; i < pDetails->nPlayers; ++i)
    {
        if (pDetails->szNames[i][0])
        {
            sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, pDetails->szNames[i]);
            switch (pDetails->wClass[i])
            {
            case 0:
                sprintf(szLine, "Level %d Amazon", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            case 1:
                sprintf(szLine, "Level %d Sorceress", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            case 2:
                sprintf(szLine, "Level %d Necromancer", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            case 3:
                sprintf(szLine, "Level %d Paladin", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            case 4:
                sprintf(szLine, "Level %d Barbarian", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            case 5:
                sprintf(szLine, "Level %d Druid", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            case 6:
                sprintf(szLine, "Level %d Assassin", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            default:
                sprintf(szLine, "Level %d", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            }
        }
    }

    D2Win_10053(gpGameInfoText_00798BC4, 0);
}
