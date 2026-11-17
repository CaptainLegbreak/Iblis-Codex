struct D2TxtLinkStrc;

extern D2TxtLinkStrc* gpSkillsLinker_0096C7CC;                                                              // 0x0096C7CC
extern D2TxtLinkStrc* gpMonTypeLinker_0096C868;                                                             // 0x0096C868
extern D2TxtLinkStrc* gpStatesLinker_0096BCF0;                                                              // 0x0096BCF0
extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB
int __stdcall FOG_GetRowFromTxt(D2TxtLinkStrc* pLinker, const char* szText, int nColumn);                   // 0x006BD3C0

// 0x006336A0
void __fastcall DATATBLS_ItemParamLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    int nRow = 0;

    if (pRecord)
    {
        int* pValue = (int*)((char*)pRecord + nOffset);
        if (pSrc && *pSrc)
        {
            if (*pSrc == '-' || *pSrc >= '0' && *pSrc <= '9')
            {
                *pValue = atoi(pSrc);
                return;
            }

            if (gpSkillsLinker_0096C7CC)
            {
                nRow = FOG_GetRowFromTxt(gpSkillsLinker_0096C7CC, pSrc, 0);
                if (nRow >= 0)
                {
                    *pValue = nRow;
                    return;
                }
            }

            if (gpMonTypeLinker_0096C868)
            {
                nRow = FOG_GetRowFromTxt(gpMonTypeLinker_0096C868, pSrc, 0);
                if (nRow >= 0)
                {
                    *pValue = nRow;
                    return;
                }
            }

            if (!gpStatesLinker_0096BCF0 || (nRow = FOG_GetRowFromTxt(gpStatesLinker_0096BCF0, pSrc, 0)) < 0)
            {
                *pValue = 0;
                return;
            }

            *pValue = nRow;
            return;
        }

        *pValue = 0;
    }
}
