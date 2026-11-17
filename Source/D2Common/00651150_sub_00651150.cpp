extern "C" unsigned int __cdecl strlen(const char* sz);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

struct D2TxtLinkStrc;

struct D2MonStatsTxt
{
    char unk0x000[0x170];
    short nSkill[8];
    char nSkillMode[8];
    short nSequence[8];
};

extern D2TxtLinkStrc* gTxtLink_0096BC5C;                                                                    // 0x0096BC5C
extern D2TxtLinkStrc* gpMonTableLinker_96C7AC;                                                              // 0x0096C7AC

int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError);                 // 0x006BD130
int __stdcall FOG_GetRowFromTxt(D2TxtLinkStrc* pLinker, const char* szText, int nColumn);                   // 0x006BD3C0

static __declspec(noinline) void sub_00650EB0_MakeCode(const char* szText, char* szCode) // 0x00650EB0
{
    if (!szText[0])
    {
        szCode[0] = ' ';
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[0] = szText[0];
    if (!szText[1])
    {
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[1] = szText[1];
    if (!szText[2])
    {
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[2] = szText[2];
    if (!szText[3])
    {
        szCode[3] = ' ';
        return;
    }
    szCode[3] = szText[3];
}

// 0x00651150
void __fastcall sub_00651150(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    D2MonStatsTxt* pMonStatsTxtRecord = (D2MonStatsTxt*)pRecord;
    if (!pMonStatsTxtRecord || (unsigned int)nOffset > 7)
    {
        return;
    }

    pMonStatsTxtRecord->nSkillMode[nOffset] = 0;
    pMonStatsTxtRecord->nSequence[nOffset] = -1;
    if (pMonStatsTxtRecord->nSkill[nOffset] < 0 || !pSrc)
    {
        return;
    }

    if (strlen(pSrc) <= 3)
    {
        int nText;
        unsigned int dwCode;
        strcpy((char*)&nText, pSrc);
        sub_00650EB0_MakeCode((const char*)&nText, (char*)&dwCode);
        const char nMode = (char)FOG_GetLinkIndex(gTxtLink_0096BC5C, dwCode, 1);
        pMonStatsTxtRecord->nSkillMode[nOffset] = nMode;
        if (nMode >= 0 && nMode != 14)
        {
            return;
        }
    }

    pMonStatsTxtRecord->nSkillMode[nOffset] = 14;
    pMonStatsTxtRecord->nSequence[nOffset] = FOG_GetRowFromTxt(gpMonTableLinker_96C7AC, pSrc, 1);
}
