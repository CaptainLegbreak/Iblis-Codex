struct D2TxtLinkStrc;

extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB
int __stdcall FOG_GetRowFromTxt(D2TxtLinkStrc* pLinker, const char* szText, int nColumn);                   // 0x006BD3C0

extern D2TxtLinkStrc* gTxtLink_0096C800;                                                                    // 0x0096C800

// 0x006690E0
void __fastcall DATATBLS_CubeMainParamLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    int nValue = 0;

    if (pRecord && pSrc && *pSrc)
    {
        if (*pSrc == '-' || *pSrc >= '0' && *pSrc <= '9')
        {
            *(int*)pRecord = atoi(pSrc);
        }
        else
        {
            if (gTxtLink_0096C800)
            {
                nValue = FOG_GetRowFromTxt(gTxtLink_0096C800, pSrc, 0);
                if (nValue >= 0)
                {
                    *(int*)pRecord = nValue;
                    return;
                }
            }

            *(int*)pRecord = 0;
        }
    }
}
