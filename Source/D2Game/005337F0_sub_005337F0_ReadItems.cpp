struct D2GameStrc;
struct D2UnitStrc;

int __fastcall PLRSAVE_ReadLegacyItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize); // 0x00533350
int __fastcall sub_005335E0(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize);

// 0x005337F0
int __fastcall sub_005337F0_ReadItems(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int nUnused, int* pReadSize)
{
    int nResult;
    if (nVersion == 0x47)
        nResult = PLRSAVE_ReadLegacyItems(pGame, pUnit, pSection, 0x47, nSize, nUnused, pReadSize);
    else if (nVersion < 0x48 || nVersion > 0x60)
        return 1;
    else
        nResult = sub_005335E0(pGame, pUnit, pSection, nVersion, nSize, nUnused, pReadSize);
    return nResult;
}
