struct D2StatListStrc;
struct D2UnitStrc { char unknown00[0xC8]; unsigned int dwFlagsEx; };
#pragma pack(push, 1)
struct D2PacketSpawnStrc
{
    unsigned char nHeader; unsigned int nUnitId; short nClassId;
    unsigned short nX, nY; unsigned char nLife, nLength; unsigned char aData[1];
};
#pragma pack(pop)
struct D2BitBufferStrc { unsigned char* pBuffer; int nBits, nPos, nPosBits, bFull; };
struct D2MonStatsTxt { char unknown00[0x18]; short wMonStatsEx; char unknown1A[0x1A8-0x1A]; };
struct D2MonStats2Txt { char unknown00[0x15]; unsigned char nComponentChoices[16]; char unknown25[0x134-0x25]; };
struct D2ItemStatCostTxt { short nStat; short unknown02; unsigned char nFlags[4], nSendBits, nSendParamBits; char unknown0A[0x144-10]; };
struct D2DataTablesStrc
{
    char unknown00[0xA78]; D2MonStatsTxt* pMonStatsTxt; int unknownA7C; int nMonStatsTxtRecordCount;
    char unknownA84[0xA90-0xA84]; D2MonStats2Txt* pMonStats2Txt; int unknownA94; int nMonStats2TxtRecordCount;
    char unknownA9C[0xBCC-0xA9C]; D2ItemStatCostTxt* pItemStatCostTxt; int unknownBD0; int nItemStatCostTxtRecordCount;
};
struct D2UnitSpawnExtraStrc { int nFlags, nUniqueId; };
struct D2UnitSpawnStrc { unsigned int nUnitId; int nClassId, nX, nY; D2UnitSpawnExtraStrc tExtra; int nMode; };
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
void __stdcall BITMANIP_Initialize(D2BitBufferStrc*, unsigned char*, int); // 0x00410E40
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc*, int); // 0x00411020
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc*, int); // 0x00411030
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc*); // 0x0044BE50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc*); // 0x00451F50
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __fastcall sub_00466360_AddClientMonster(D2UnitSpawnStrc*, unsigned char*, unsigned char*, unsigned short, int, int); // 0x00466360
void __fastcall sub_00470B70_ResetMonsterMode(D2UnitStrc*); // 0x00470B70
void __fastcall sub_00477170_LoadPalShift(int); // 0x00477170
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc*, int, int); // 0x00478F20
void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc*, int, int); // 0x00621CC0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, int, int, int, int); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc*, int); // 0x006252D0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc*, int, int); // 0x006257D0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc*, int, int, int); // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc*); // 0x0063EE90

// 0x00409000
int __fastcall sub_00409000_GetBitWidth(unsigned int nValue)
{
    if (!nValue)
    {
        return 0;
    }
    __asm
    {
        bsr eax, nValue
        inc eax
        mov nValue, eax
    }
    return nValue;
}

// build: context Log2Ceil
static __forceinline int Log2Ceil(int nValue)
{
    return nValue < 3 ? 1 : sub_00409000_GetBitWidth(nValue - 1);
}

// build: context GetMonStats2TxtRecordFromMonsterId
static __forceinline D2MonStats2Txt* GetMonStats2TxtRecordFromMonsterId(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount) return 0;
    int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
    if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
    {
        return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
    }
    return 0;
}

// build: context GetItemStatCostTxtRecord
static __forceinline D2ItemStatCostTxt* GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x0045F190
void __fastcall sub_0045F190_SpawnMonsterPacket(D2PacketSpawnStrc* pPacket)
{
    unsigned int nUnitId = pPacket->nUnitId;
    unsigned short nX = pPacket->nX;
    unsigned short nY = pPacket->nY;
    short nClassId = pPacket->nClassId;
    D2BitBufferStrc tBuffer;
    unsigned char aComponents[16];
    unsigned char aMods[9];
    BITMANIP_Initialize(&tBuffer, pPacket->aData, pPacket->nLength - 13);
    unsigned char nMode = (unsigned char)sub_00411020_ReadBits(&tBuffer, 4);
    unsigned char* pComponents = 0;
    if (sub_00411020_ReadBits(&tBuffer, 1))
    {
        D2MonStats2Txt* pRecord = GetMonStats2TxtRecordFromMonsterId(nClassId);
        if (!pRecord) return;
        pComponents = aComponents;
        for (int i = 0; i < 16; ++i)
            aComponents[i] = (unsigned char)sub_00411020_ReadBits(&tBuffer, Log2Ceil(pRecord->nComponentChoices[i]));
    }
    unsigned char* pMods = 0;
    unsigned short nFlags = 0;
    int nUniqueId = -1;
    int nSpecial = 0;
    unsigned short nPalette = 0;
    if (sub_00411020_ReadBits(&tBuffer, 1))
    {
        nFlags = sub_00411020_ReadBits(&tBuffer, 1) ? 4 : 0;
        nFlags |= sub_00411020_ReadBits(&tBuffer, 1) ? 8 : 0;
        nFlags |= sub_00411020_ReadBits(&tBuffer, 1) ? 2 : 0;
        nFlags |= sub_00411020_ReadBits(&tBuffer, 1) ? 16 : 0;
        nFlags |= sub_00411020_ReadBits(&tBuffer, 1) ? 64 : 0;
        if (nFlags & 2) nSpecial = (unsigned short)BITMANIP_ReadSigned(&tBuffer, 16);
        for (int i = 0; i < 9; ++i) aMods[i] = 0;
        pMods = aMods;
        int nModIndex = 0;
        for (unsigned char nMod = (unsigned char)sub_00411020_ReadBits(&tBuffer, 8); nMod; nMod = (unsigned char)sub_00411020_ReadBits(&tBuffer, 8))
            aMods[nModIndex++] = nMod;
        nPalette = (unsigned char)sub_00411020_ReadBits(&tBuffer, 16);
        if (sub_00411020_ReadBits(&tBuffer, 1)) nUniqueId = sub_00411020_ReadBits(&tBuffer, 32);
    }
    D2UnitSpawnStrc tSpawn;
    memset(&tSpawn, 0, sizeof(tSpawn));
    tSpawn.nUnitId = nUnitId;
    tSpawn.nClassId = nClassId;
    tSpawn.nX = nX;
    tSpawn.nY = nY;
    tSpawn.tExtra.nFlags = nFlags;
    tSpawn.tExtra.nUniqueId = nUniqueId;
    tSpawn.nMode = nMode;
    sub_00477170_LoadPalShift(nClassId);
    D2UnitStrc* pUnit = sub_00466360_AddClientMonster(&tSpawn, pComponents, pMods, nPalette, nSpecial, 0);
    if (!pUnit) return;
    sub_00470B70_ResetMonsterMode(pUnit);
    if (!MONSTERS_GetHirelingTypeId(pUnit) || nUnitId != sub_00478F20_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 1))
    {
        STATLIST_SetUnitStat(pUnit, 7, 0x8000, 0);
        STATLIST_SetUnitStat(pUnit, 6, pPacket->nLife << 8, 0);
    }
    if (MONSTERS_GetHirelingTypeId(pUnit) && nMode == 1) pUnit->dwFlagsEx &= ~0x40000;
    STATLIST_SetUnitStat(pUnit, 0x148, (unsigned short)(nX + nY), 0);
    if (sub_00411020_ReadBits(&tBuffer, 1)) UNITS_StoreOwnerTypeAndGUID(pUnit, 0, sub_00411020_ReadBits(&tBuffer, 31));
    if (sub_00411020_ReadBits(&tBuffer, 1))
    {
        D2StatListStrc* pStatList = 0;
        for (int nStat = sub_00411020_ReadBits(&tBuffer, 9); nStat < 511; nStat = sub_00411020_ReadBits(&tBuffer, 9))
        {
            D2ItemStatCostTxt* pRecord = GetItemStatCostTxtRecord(nStat);
            if (!pRecord || pRecord->nSendBits <= 0) return;
            int nLayer = 0;
            if (pRecord->nSendParamBits > 0) nLayer = (unsigned short)BITMANIP_ReadSigned(&tBuffer, pRecord->nSendParamBits);
            int nValue;
            if (pRecord->nSendBits < 32 && (pRecord->nFlags[0] & (unsigned char)gdwBitMasks[1]))
                nValue = BITMANIP_ReadSigned(&tBuffer, pRecord->nSendBits);
            else
                nValue = sub_00411020_ReadBits(&tBuffer, pRecord->nSendBits);
            if (!pStatList)
            {
                pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, 0, 0x40);
                if (!pStatList)
                {
                    pStatList = STATLIST_AllocStatList(0, 0x40, 0, sub_0044BE50_GetUnitTypeOrInvalid(pUnit), sub_00451F50_GetUnitGUID(pUnit));
                    STATLIST_SetState(pStatList, 0);
                    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                }
            }
            if (pStatList) STATLIST_SetStatIfListIsValid(pStatList, nStat, nValue, nLayer);
        }
    }
}
