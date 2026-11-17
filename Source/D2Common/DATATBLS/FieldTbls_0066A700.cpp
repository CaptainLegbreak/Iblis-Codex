struct D2FieldStrc
{
    int nX;
    int nY;
};

struct D2CollisionFieldStrc
{
    int nWidth;
    int nHeight;
    int nArea;
    int nCenterX;
    int nCenterY;
};

struct D2DataTablesStrc
{
    char unk0x0000[0x1A00];
    int ExpFieldI[9];
    unsigned char* pFieldData;
    D2CollisionFieldStrc pCollisionField;
};

struct D2ActiveRoomStrc;

extern D2DataTablesStrc gtDataTables_0096BC30;                                                                       // 0x0096BC30
extern const int gnFieldXOffsets[9];                                                                          // 0x00749780
extern const int gnFieldYOffsets[9];                                                                          // 0x007497A4
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);               // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);             // 0x0040B480
void __fastcall sub_0040B3C0(void* pMemory, const char* szFile, int nLine, int n0);                          // 0x0040B3C0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                           // 0x006829C0
#pragma function(memcpy)
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma intrinsic(memset)
extern "C" const char gszDataGlobalPath[];                                                                      // 0x006D4118
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);           // 0x006CC468
void* __fastcall sub_00517079(void* hArchive, const char* szPath, int* pSize, const char* szFile, int nLine); // 0x00517079
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);         // 0x0064CB30
extern "C" const char gszEmptyAssertText;                                                                         // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                              // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                                // 0x00681E09

#define FIELD_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0066A2B0
int __stdcall DATATBLS_InitializeCollisionFieldTable(char* pExpField, int nSize)
{
    char* pFile = pExpField;
    pExpField += 2;
    const int nHeight = *(int*)pExpField;
    pExpField += 4;
    const int nWidth = *(int*)pExpField;
    pExpField += 4;
    const int nArea = nWidth * nHeight;

    unsigned char* pFieldData = (unsigned char*)sub_0040B430(0, nArea, ".\\DATATBLS\\FieldTbls.cpp", 62, 0);
    FIELD_ASSERT(pFieldData, 64);
    memcpy(pFieldData, pExpField, nArea);
    gtDataTables_0096BC30.pFieldData = pFieldData;

    gtDataTables_0096BC30.pCollisionField.nWidth = nWidth;
    gtDataTables_0096BC30.pCollisionField.nHeight = nHeight;
    gtDataTables_0096BC30.pCollisionField.nArea = nArea;
    gtDataTables_0096BC30.pCollisionField.nCenterX = nWidth >> 1;
    gtDataTables_0096BC30.pCollisionField.nCenterY = nHeight >> 1;

    for (int i = 0; i < 9; ++i)
    {
        gtDataTables_0096BC30.ExpFieldI[i] = gnFieldXOffsets[i] + nWidth * gnFieldYOffsets[i];
    }

    sub_0040B3C0(pFile, ".\\DATATBLS\\FieldTbls.cpp", 80, 0);
    return 1;
}

int __stdcall DATATBLS_FreeCollisionFieldTable()
{
    if (gtDataTables_0096BC30.pFieldData)
    {
        sub_0040B480(0, gtDataTables_0096BC30.pFieldData, ".\\DATATBLS\\FieldTbls.cpp", 91, 0);
    }

    gtDataTables_0096BC30.pFieldData = 0;
    gtDataTables_0096BC30.pCollisionField.nHeight = 0;
    gtDataTables_0096BC30.pCollisionField.nWidth = 0;
    gtDataTables_0096BC30.pCollisionField.nArea = 0;
    gtDataTables_0096BC30.pCollisionField.nCenterX = 0;
    gtDataTables_0096BC30.pCollisionField.nCenterY = 0;
    return 1;
}

void __stdcall DATATBLS_GetCollisionFieldCenter(int* pCenterX, int* pCenterY)
{
    *pCenterX = gtDataTables_0096BC30.pCollisionField.nCenterX;
    *pCenterY = gtDataTables_0096BC30.pCollisionField.nCenterY;
}

int __stdcall DATATBLS_GetCollisionFieldWidth()
{
    return gtDataTables_0096BC30.pCollisionField.nWidth;
}

int __stdcall DATATBLS_GetCollisionFieldHeight()
{
    return gtDataTables_0096BC30.pCollisionField.nHeight;
}

D2FieldStrc* __stdcall DATATBLS_AllocField()
{
    D2FieldStrc* pField = (D2FieldStrc*)sub_0040B430(0, sizeof(D2FieldStrc), ".\\DATATBLS\\FieldTbls.cpp", 135, 0);
    FIELD_ASSERT(pField, 136);

    memset(pField, 0, sizeof(D2FieldStrc));
    return pField;
}

void __stdcall DATATBLS_FreeField(D2FieldStrc* pField)
{
    FIELD_ASSERT(pField, 147);

    sub_0040B480(0, pField, ".\\DATATBLS\\FieldTbls.cpp", 148, 0);
}

void __stdcall DATATBLS_SetFieldCoordinates(D2FieldStrc* pField, int nX, int nY)
{
    FIELD_ASSERT(pField, 161);

    pField->nX = nX;
    pField->nY = nY;
}

int __stdcall D2Common_11097(D2FieldStrc* pField, int nX, int nY)
{
    FIELD_ASSERT(pField, 176);

    return *(&gtDataTables_0096BC30.pFieldData[((nY - pField->nY) << 8) - pField->nX] + nX);
}

int __stdcall D2Common_11098(D2FieldStrc* pField, int* pX, int* pY)
{
    FIELD_ASSERT(pField, 191);

    const int nIndex = *(&gtDataTables_0096BC30.pFieldData[((gtDataTables_0096BC30.pCollisionField.nCenterY + *pY - pField->nY) << 8) - pField->nX] + *pX + gtDataTables_0096BC30.pCollisionField.nCenterX);

    *pX += gnFieldXOffsets[nIndex];
    *pY += gnFieldYOffsets[nIndex];

    return *(&gtDataTables_0096BC30.pFieldData[((gtDataTables_0096BC30.pCollisionField.nCenterY + *pY - pField->nY) << 8) - pField->nX] + *pX + gtDataTables_0096BC30.pCollisionField.nCenterX) != 8;
}

int __stdcall D2Common_11099(D2FieldStrc* pField, D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short fMask)
{
    if (!pRoom)
    {
        return 0;
    }

    if (COLLISION_CheckMask(pRoom, nX, nY, fMask))
    {
        return 1;
    }

    while (D2Common_11098(pField, &nX, &nY))
    {
        if (COLLISION_CheckMask(pRoom, nX, nY, fMask))
        {
            return 1;
        }
    }

    return 0;
}

// 0x0066A700
int __fastcall DATATBLS_LoadExpFieldD2(void* hArchive)
{
    char szPath[260];
    int nSize;
    wsprintfA(szPath, "%s\\expfield.d2", gszDataGlobalPath);
    char* pExpField = (char*)sub_00517079(hArchive, szPath, &nSize, ".\\DATATBLS\\FieldTbls.cpp", 40);
    return DATATBLS_InitializeCollisionFieldTable(pExpField, nSize);
}
