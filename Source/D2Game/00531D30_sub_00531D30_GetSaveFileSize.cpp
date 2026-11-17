struct D2GameStrc;
struct D2UnitStrc;

int __fastcall PLRSAVE2_CreateSaveFile(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int* pSize, unsigned int nMaxSize, int a6, int a7); // 0x00569AD0

// 0x00531D30
static unsigned int __stdcall sub_00531D30_GetSaveFileSize(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int nMaxSize, int a6, int a7)
{
    unsigned int nSize = 0;
    PLRSAVE2_CreateSaveFile(pGame, pPlayer, pData, &nSize, nMaxSize, a6, a7);
    return nSize;
}

unsigned int __fastcall sub_K10_EmitSaveFileSize(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    unsigned char aBuffer[4];
    return sub_00531D30_GetSaveFileSize(pGame, pPlayer, aBuffer, sizeof(aBuffer), 0, 0);
}
