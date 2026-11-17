struct D2TxtLinkStrc;

int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError);                 // 0x006BD130
int __stdcall FOG_GetRowFromTxt(D2TxtLinkStrc* pLinker, const char* szText, int nColumn);                   // 0x006BD3C0
extern D2TxtLinkStrc* gpSkillCalcLinker_0096BC6C;                                                           // 0x0096BC6C
D2TxtLinkStrc* gpMissileCalcLinker_0096BC8C;                                                                // 0x0096BC8C
extern D2TxtLinkStrc* gpSkillCodeLinker_0096BCA0;                                                           // 0x0096BCA0
extern D2TxtLinkStrc* gpMissilesLinker_0096C798;                                                            // 0x0096C798

// 0x006617B0
static void sub_006617B0_TextToLinkCode(const char* szText, char* szCode)
{
    if (!szText[0])
    {
        szCode[0] = ' ';
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
    }
    else
    {
        szCode[0] = szText[0];
        if (!szText[1])
        {
            szCode[1] = ' ';
            szCode[2] = ' ';
            szCode[3] = ' ';
        }
        else
        {
            szCode[1] = szText[1];
            if (!szText[2])
            {
                szCode[2] = ' ';
                szCode[3] = ' ';
            }
            else
            {
                szCode[2] = szText[2];
                if (!szText[3])
                {
                    szCode[3] = ' ';
                }
                else
                {
                    szCode[3] = szText[3];
                }
            }
        }
    }
}

// 0x00661880
int __fastcall sub_6FD62F20(char* szText, int* a2, int a3, int nKeywordNumber)
{
    char szCode[4];

    if (a3 == 1)
    {
        if (nKeywordNumber == 3)
        {
            if (gpSkillCodeLinker_0096BCA0)
            {
                const int nRow = FOG_GetRowFromTxt(gpSkillCodeLinker_0096BCA0, szText, 0);
                if (nRow >= 0)
                {
                    *a2 = 1;
                    return nRow;
                }

                sub_006617B0_TextToLinkCode(szText, szCode);
                const int nIndex = FOG_GetLinkIndex(gpSkillCalcLinker_0096BC6C, *(unsigned int*)szCode, 1);
                *a2 = 0;
                return nIndex;
            }
        }
        else if (nKeywordNumber == 4)
        {
            if (gpMissilesLinker_0096C798)
            {
                const int nRow = FOG_GetRowFromTxt(gpMissilesLinker_0096C798, szText, 0);
                if (nRow >= 0)
                {
                    *a2 = 1;
                    return nRow;
                }
            }

            sub_006617B0_TextToLinkCode(szText, szCode);
            const int nIndex = FOG_GetLinkIndex(gpMissileCalcLinker_0096BC8C, *(unsigned int*)szCode, 1);
            *a2 = 0;
            return nIndex;
        }
    }

    sub_006617B0_TextToLinkCode(szText, szCode);
    const int nIndex = FOG_GetLinkIndex(gpMissileCalcLinker_0096BC8C, *(unsigned int*)szCode, 1);
    *a2 = 0;
    return nIndex;
}
