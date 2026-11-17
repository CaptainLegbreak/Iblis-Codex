extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

#pragma pack(push, 1)
struct D2TblHeaderStrc
{
    unsigned short nCRC;
    unsigned short nNumElements;
    int nHashTableSize;
    unsigned char nVersion;
    unsigned int dwIndexStart;
    unsigned int dwNumLoops;
    unsigned int dwFileSize;
};

struct D2TblNodeStrc
{
    unsigned char bUsed;
    unsigned short nIndexNo;
    unsigned int dwHashValue;
    unsigned int dwStringOffset;
    unsigned int dwKeyOffset;
    unsigned short nNameLen;
};
#pragma pack(pop)

void* __fastcall sub_00517079(void* hArchive, const char* szPath, int* pSize, const char* szFile, int nLine); // 0x00517079
void __stdcall CRC16_CalculateChecksum(unsigned short* crc16_checksum_out, const unsigned char* data, unsigned int start_index, unsigned int end_index); // 0x00525020
extern void* ghArchive_008829DC;                                                                            // 0x008829DC

// 0x00525920
static D2TblHeaderStrc* sub_00525920_LoadTblFile(const char* szPath)
{
    D2TblHeaderStrc* pTbl = (D2TblHeaderStrc*)sub_00517079(ghArchive_008829DC, szPath, 0, ".\\StrTable\\strtable.cpp", 0xC0);

    unsigned short nCRC;
    CRC16_CalculateChecksum(&nCRC, (const unsigned char*)pTbl, pTbl->dwIndexStart, pTbl->dwFileSize);
    D2_ASSERT(nCRC == pTbl->nCRC, 0xCE);

    D2TblNodeStrc* pNodes = (D2TblNodeStrc*)((char*)pTbl + sizeof(D2TblHeaderStrc) + pTbl->nNumElements * sizeof(unsigned short));
    for (int i = 0; i < pTbl->nHashTableSize; ++i)
    {
        D2_ASSERT(pNodes[i].dwStringOffset < pTbl->dwFileSize, 0xE0);
        D2_ASSERT(pNodes[i].dwKeyOffset < pTbl->dwFileSize, 0xE1);
    }

    return pTbl;
}

extern D2TblHeaderStrc* gpM15EmitTbl;
extern "C" const char szM15EmitFormat[];
int sub_M15_Emit_00525920(const char* szDir, const char* szLang)
{
    char szPath[0x104];
    sprintf(szPath, szM15EmitFormat, szDir, szLang);
    gpM15EmitTbl = sub_00525920_LoadTblFile(szPath);
    return gpM15EmitTbl != 0;
}
