struct D2UnitStrc;
struct D2CelFileStrc;

struct D2PetTypeTxt
{
    unsigned int dwHcIdx;
    unsigned char nPetFlags[4];
    short wGroup;
    short wBaseMax;
    unsigned short wName;
    unsigned char nIconType;
    char szIcon[5][32];
    char unk0xAF;
    unsigned short wClass[5];
    char unk0xBA[0x26];
};

struct D2DataTablesStrc
{
    char unk0x00[0xBE8];
    D2PetTypeTxt* pPetTypeTxt;
    char unk0xBEC[0x04];
    int nPetTypeTxtRecordCount;
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath);                                            // 0x004520C0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny);                   // 0x00478F20
int __fastcall sub_00479120_GetHirelingClassId(int nUnitId);                                                // 0x00479120

extern const unsigned int gdwBitMasks[];                                                                    // 0x006CE268
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern void** gppHirelingCels_007BEEAC;                                                                     // 0x007BEEAC

static __forceinline D2PetTypeTxt* sub_00493240_GetPetTypeTxtRecord(int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &sgptDataTables->pPetTypeTxt[nPetType];
    }
    return 0;
}

// 0x00493240
D2CelFileStrc* __fastcall sub_00493240_PetIconForType(D2UnitStrc* pOwner, int nPetType, int* pUnitId, int* pSingle)
{
    int aPath[0x40];

    D2PetTypeTxt* pPetTypeTxtRecord = sub_00493240_GetPetTypeTxtRecord(nPetType);
    if (!pPetTypeTxtRecord)
    {
        return 0;
    }

    if (pSingle)
    {
        *pSingle = pPetTypeTxtRecord->nPetFlags[5 >> 3] & gdwBitMasks[5 & 7];
    }

    int nUnitId = sub_00478F20_FindPetIdByOwner(pOwner, nPetType, 0);
    *pUnitId = nUnitId;
    if (nUnitId == -1)
    {
        return 0;
    }

    int nClassId = sub_00479120_GetHirelingClassId(nUnitId);
    int nIcon = 0;
    for (int i = 1; i < 5; ++i)
    {
        if (nClassId == pPetTypeTxtRecord->wClass[i] && pPetTypeTxtRecord->szIcon[i][0])
        {
            nIcon = i;
            break;
        }
    }

    int nSlot = nPetType * 5 + nIcon;
    void** ppCel = &gppHirelingCels_007BEEAC[nSlot];
    if (!*ppCel)
    {
        sprintf((char*)aPath, "hireables\\%s", pPetTypeTxtRecord->szIcon[nIcon]);
        ppCel = &gppHirelingCels_007BEEAC[nSlot];
        *ppCel = sub_004520C0_LoadUiCelFile((char*)aPath);
    }
    return (D2CelFileStrc*)*ppCel;
}
