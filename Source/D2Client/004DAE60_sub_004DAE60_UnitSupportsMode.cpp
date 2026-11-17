struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2MonStats2Txt
{
    char unk0x00[0xE8];
    unsigned char nModeFlags[4];
};

struct D2ObjectsTxt
{
    char unk0x000[0x151];
    unsigned char nModeEnabled[16];
};

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_INVALID 6

// 0x004DAE60
int __fastcall sub_004DAE60_UnitSupportsMode(D2UnitStrc* pUnit, int nMode)
{
    if (nMode >= 16)
    {
        return 0;
    }

    int nCurrentMode;
    int nUnitType;
    int nClassId;

    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    nCurrentMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nCurrentMode, ".\\ENGINE\\GfxUtil.cpp", 603);

    switch (nUnitType)
    {
    case UNIT_PLAYER:
        switch (nMode)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 8:
        case 9:
            return 1;
        }
        break;

    case UNIT_MONSTER:
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if (pMonStats2TxtRecord && (pMonStats2TxtRecord->nModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7]))
        {
            return 1;
        }
        break;
    }

    case UNIT_OBJECT:
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
        if (pObjectsTxtRecord && pObjectsTxtRecord->nModeEnabled[nMode] == 1)
        {
            return 1;
        }
        break;
    }

    case UNIT_ITEM:
        if (nMode == 1)
        {
            return 1;
        }
        break;
    }

    return 0;
}
