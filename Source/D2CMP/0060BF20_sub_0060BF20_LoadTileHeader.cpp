#pragma pack(push, 1)
struct D2CmpTileFileHeaderStrc
{
    unsigned char nType;
    unsigned char nByte1;
    unsigned char nCount;
    int nDword3;
    int nDword7;
    int nUnk0x0B;
};
#pragma pack(pop)

struct D2CmpTileHeaderTargetStrc
{
    unsigned char bFlags;
    char pad0x01[3];
    int nByte1;
    int nDword7;
    int nZero0C;
    int f_10;
    int nCount;
    int nDword3;
    unsigned int adwData[33];
};

int __fastcall sub_004068E0(const char* szFileName, void** phFile);                                          // 0x004068E0
void __fastcall sub_004068F0(void* hFile);                                                                // 0x004068F0
int __fastcall sub_00406900(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900
int __fastcall sub_00406930(void* hFile, unsigned int* pnSizeHigh);                                       // 0x00406930

// 0x0060BF20
int __fastcall sub_0060BF20_LoadTileHeader(const char* szFile, D2CmpTileHeaderTargetStrc* pTarget)
{
    void* hFile;
    sub_004068E0(szFile, &hFile);
    if (!hFile)
    {
        return 0;
    }

    D2CmpTileFileHeaderStrc tHeader;
    int nRead;
    int bLoaded = 0;
    if (sub_00406900(hFile, &tHeader, sizeof(tHeader), &nRead, 0, 0, 0) && nRead == sizeof(tHeader) && tHeader.nType == 't')
    {
        pTarget->nByte1 = tHeader.nByte1;
        pTarget->nDword7 = tHeader.nDword7;
        pTarget->nZero0C = 0;
        pTarget->nCount = tHeader.nCount;
        pTarget->nDword3 = tHeader.nDword3;
        if (tHeader.nCount > 32)
        {
            tHeader.nCount = 32;
        }

        const int nSize = tHeader.nCount * sizeof(unsigned int);
        if (sub_00406900(hFile, pTarget->adwData, nSize, &nRead, 0, 0, 0) && nRead == nSize)
        {
            bLoaded = 1;
        }
    }

    if (!bLoaded)
    {
        sub_004068F0(hFile);
        return 0;
    }

    pTarget->adwData[tHeader.nCount] = sub_00406930(hFile, 0);
    sub_004068F0(hFile);
    pTarget->bFlags |= 2;
    return 1;
}
