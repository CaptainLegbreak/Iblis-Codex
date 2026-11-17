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

unsigned char* gpFieldData_0096D654;        // 0x0096D654
D2CollisionFieldStrc gCollisionField_0096D658;        // 0x0096D658
extern const int gnFieldXOffsets[9];                                                                       // 0x00749780
extern const int gnFieldYOffsets[9];                                                                       // 0x007497A4
extern "C" const char gszEmptyAssertText;                                                                  // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                     // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                              // 0x00681E09

#define FIELD_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define FIELD_CELL(pFieldArg, nPosX, nPosY) \
    *reinterpret_cast<unsigned char*>(gCollisionField_0096D658.nCenterX \
        + ((((nPosY - (pFieldArg)->nY + gCollisionField_0096D658.nCenterY) << 8) - (pFieldArg)->nX + nPosX) \
        + reinterpret_cast<unsigned int>(gpFieldData_0096D654)))

// 0x0066A5D0
int __stdcall D2Common_11098(D2FieldStrc* pField, int* pX, int* pY)
{
    FIELD_ASSERT(pField, 191);

    const int nIndex = FIELD_CELL(pField, *pX, *pY);

    *pX += gnFieldXOffsets[nIndex];
    *pY += gnFieldYOffsets[nIndex];

    return FIELD_CELL(pField, *pX, *pY) != 8;
}
