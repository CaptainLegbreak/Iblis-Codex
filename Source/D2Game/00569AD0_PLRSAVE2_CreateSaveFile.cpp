struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
};

struct D2UnitStrc
{
    int dwUnitType;
};

unsigned int __stdcall FOG_ComputeChecksum(const unsigned char* pData, unsigned int nSize);                 // 0x00411130
int __fastcall PLRSAVE2_WriteSaveHeader(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x00568F20
int __fastcall sub_00569320_WriteQuestSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x00569320
int __fastcall PLRSAVE2_WriteWaypointData(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x005693E0
int __fastcall PLRSAVE2_WritePlrIntroSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x00569490
int __fastcall PLRSAVE2_WritePlayerStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x00569540
int __fastcall sub_005696F0_WriteSkillSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x005696F0
int __fastcall sub_005697B0_WriteItemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int a6, int a7, int bSizing); // 0x005697B0
int __fastcall PLRSAVE2_WriteCorpsesSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int a7, int bSizing); // 0x005697F0
int __fastcall sub_005699A0_WriteMercSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int a7, int bSizing); // 0x005699A0
int __fastcall PLRSAVE2_WriteIronGolemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int a7, int bSizing); // 0x00569A00

// 0x00569AD0
int __fastcall PLRSAVE2_CreateSaveFile(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int* pSize, unsigned int nMaxSize, int a6, int a7)
{
    unsigned char aBuffer[0x8000];
    const unsigned char* pEnd = &pData[nMaxSize];
    unsigned char* pSection = pData;
    unsigned char* pBuffer = aBuffer;
    *pSize = 0;

    int nResult;
    if (!pPlayer || pPlayer->dwUnitType != 0)
    {
        nResult = 2;
        goto LABEL_FAIL;
    }

    nResult = PLRSAVE2_WriteSaveHeader(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto LABEL_FAIL;
    nResult = sub_00569320_WriteQuestSection(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto LABEL_FAIL;
    nResult = PLRSAVE2_WriteWaypointData(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto LABEL_FAIL;
    nResult = PLRSAVE2_WritePlrIntroSection(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto LABEL_FAIL;
    nResult = PLRSAVE2_WritePlayerStats(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto LABEL_FAIL;
    nResult = sub_005696F0_WriteSkillSection(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto LABEL_FAIL;

    {
        const int nRemaining = pEnd - pSection;
        nResult = sub_005697B0_WriteItemSection(pGame, pPlayer, &pBuffer, &aBuffer[sizeof(aBuffer)], a6, a7, 1);
        if (nResult) goto LABEL_FAIL;
        const int nItemsSize = pBuffer - aBuffer;
        nResult = PLRSAVE2_WriteCorpsesSection(pGame, pPlayer, &pBuffer, &aBuffer[sizeof(aBuffer)], a7, 1);
        if (nResult) goto LABEL_FAIL;
        if (pGame->bExpansion)
        {
            nResult = sub_005699A0_WriteMercSection(pGame, pPlayer, &pBuffer, &aBuffer[sizeof(aBuffer)], a7, 1);
            if (nResult) goto LABEL_FAIL;
            nResult = PLRSAVE2_WriteIronGolemSection(pGame, pPlayer, &pBuffer, &aBuffer[sizeof(aBuffer)], a7, 1);
            if (nResult) goto LABEL_FAIL;
        }

        const int nBufferSize = pBuffer - aBuffer;
        const unsigned char* pItemsEnd = nBufferSize <= nRemaining ? pEnd : pSection + (nItemsSize - nBufferSize + nRemaining);
        nResult = sub_005697B0_WriteItemSection(pGame, pPlayer, &pSection, pItemsEnd, a6, a7, 0);
        if (nResult) goto LABEL_FAIL;
        nResult = PLRSAVE2_WriteCorpsesSection(pGame, pPlayer, &pSection, pEnd, a7, 0);
        if (nResult) goto LABEL_FAIL;
        if (pGame->bExpansion)
        {
            nResult = sub_005699A0_WriteMercSection(pGame, pPlayer, &pSection, pEnd, a7, 0);
            if (nResult) goto LABEL_FAIL;
            nResult = PLRSAVE2_WriteIronGolemSection(pGame, pPlayer, &pSection, pEnd, a7, 0);
            if (nResult) goto LABEL_FAIL;
        }
    }

    {
        const unsigned int nSize = pSection - pData;
        *pSize = nSize;
        *(unsigned int*)(pData + 8) = nSize;
        *(unsigned int*)(pData + 0xC) = FOG_ComputeChecksum(pData, nSize);
    }
    return 0;

LABEL_FAIL:
    *pSize = 0;
    return nResult;
}
