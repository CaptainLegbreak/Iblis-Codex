struct _iobuf;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);                               // 0x0068239A
extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684449
extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
void __fastcall sub_00407050_GetSavePath(char* szPath, int nSize);                                          // 0x00407050

struct D2SaveHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
};

#pragma pack(push, 1)

struct D2ClientCharRecordStrc
{
    char unk0x000[0x1EF];
    unsigned short wValue;
};
#pragma pack(pop)

extern char gszCharName_007A05C4[];                                                                         // 0x007A05C4
extern D2ClientCharRecordStrc* gpCharRecord_007A0438;                                                       // 0x007A0438
unsigned char* gpSaveBuffer_007A5224;                                                                        // 0x007A5224
unsigned int gnSaveBufferSize_007A5228;                                                                     // 0x007A5228

// 0x0045C520
void __cdecl sub_0045C520_SaveCharFile()
{
    char szPath[500];
    char szDir[0x400];

    D2_ASSERT(gszCharName_007A05C4[0], 0x25);

    const unsigned int nSize = gnSaveBufferSize_007A5228;
    if (nSize < 8)
    {
        return;
    }

    unsigned char* pBuffer = gpSaveBuffer_007A5224;
    const D2SaveHeaderStrc tHeader = *(D2SaveHeaderStrc*)pBuffer;
    if (tHeader.dwMagic != 0xAA55AA55)
    {
        return;
    }

    if (tHeader.dwVersion <= 0x5B)
    {
        if (nSize < 0x82)
        {
            return;
        }
        gpCharRecord_007A0438->wValue = *(unsigned short*)(pBuffer + 0x18);
    }
    else
    {
        if (nSize < 0x14F)
        {
            return;
        }
        gpCharRecord_007A0438->wValue = *(unsigned short*)(pBuffer + 0x24);
    }

    sub_00407050_GetSavePath(szDir, 0x400);
    sprintf(szPath, "%s%s.d2s", szDir, gszCharName_007A05C4);
    _iobuf* pFile = fopen(szPath, "wb");
    if (pFile)
    {
        fwrite(gpSaveBuffer_007A5224, gnSaveBufferSize_007A5228, 1, pFile);
        fclose(pFile);
    }
}
