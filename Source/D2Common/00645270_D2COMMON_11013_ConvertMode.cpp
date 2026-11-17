struct D2StatesTxt
{
    char unk0x00[0x2D];
    unsigned char nGfxType;
    short wGfxClass;
    char unk0x30[0x0C];
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC4];
    unsigned int dwFlagEx;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC];
    D2StatesTxt* pStatesTxt;
    char unk0x0C0[0x04];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xB4];
    unsigned short* pTransformStates;
    short nTransformStates;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gnShapeshiftMonModes_006EB308[];                                                           // 0x006EB308
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall D2Common_11014_ConvertShapeShiftedMode(int nArrayIndex, int nMonsterId);                      // 0x00645190

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInl(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nState];
    }

    return 0;
}

inline int STATES_IsUnitShapeShiftedInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

// 0x00645270
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine)
{
    if (!STATES_IsUnitShapeShiftedInl(pUnit))
    {
        return;
    }

    for (int nCounter = 0; nCounter < sgptDataTables->nTransformStates; ++nCounter)
    {
        const short nState = sgptDataTables->pTransformStates[nCounter];
        if (STATES_CheckState(pUnit, nState))
        {
            D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInl(nState);
            if (pStatesTxtRecord)
            {
                switch (pStatesTxtRecord->nGfxType)
                {
                case 2:
                {
                    *pType = 0;
                    const int nClass = pStatesTxtRecord->wGfxClass;
                    *pClass = nClass;

                    if (pUnit->dwUnitType == 1)
                    {
                        const int nMode = *pMode;
                        *pMode = (nClass == 6 && nMode == 4) ? 12 : gnShapeshiftMonModes_006EB308[nMode];
                    }
                    return;
                }

                case 1:
                {
                    *pType = 1;
                    const int nMonsterId = pStatesTxtRecord->wGfxClass;
                    *pClass = nMonsterId;

                    if (pUnit->dwUnitType == 0)
                    {
                        *pMode = D2Common_11014_ConvertShapeShiftedMode(*pMode, nMonsterId);
                    }
                    return;
                }
                }
            }
        }
    }
}
