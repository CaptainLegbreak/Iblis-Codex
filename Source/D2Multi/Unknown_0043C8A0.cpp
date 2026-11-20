struct _iobuf;
typedef struct _iobuf FILE;

extern "C" const char gszEmptyAssertText_006CC837; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" FILE* __cdecl fopen(const char* szFileName, const char* szMode); // 0x0068239A
extern "C" unsigned int __cdecl fread(void* pBuffer, unsigned int nSize, unsigned int nCount, FILE* pFile); // 0x00684782
extern "C" int __cdecl fclose(FILE* pFile); // 0x00681FDC
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
#pragma intrinsic(memcpy)

int __fastcall sub_00407050_GetSavePath(char* szPath, int nSize); // 0x00407050
void __stdcall sub_006BBF40_PutPackedWord(unsigned char* pStream, unsigned short nValue); // 0x006BBF40

extern const char gszDefaultSaveName_0070CCC8[]; // 0x0070CCC8

// 0x0043C8A0
int __fastcall sub_0043C8A0_ReadSaveSummary(const char* szName, unsigned char* pOut)
{
    int bResult = 0;
    if (!szName[0])
    {
        sub_00408A60(&gszEmptyAssertText_006CC837, sub_00408090(), 0xE9);
        exit(-1);
    }

    char szSaveDir[0x400];
    sub_00407050_GetSavePath(szSaveDir, 0x400);

    char szPath[500];
    sprintf(szPath, "%s%s.d2s", szSaveDir, szName);
    FILE* pFile = fopen(szPath, "rb");
    if (!pFile)
        return 0;

    unsigned char aBuffer[0x2000];
    unsigned int nRead = fread(aBuffer, 1, 0x2000, pFile);
    if (nRead >= 8 && *(unsigned int*)aBuffer == 0xAA55AA55)
    {
        unsigned int nVersion = *(unsigned int*)(aBuffer + 4);
        const char* pCharName;
        unsigned char nLevel;
        unsigned short nFlags;
        unsigned char nClass;
        const char* pTitle;

        if (nVersion <= 0x5B)
        {
            if (nRead < 0x82 || nVersion < 0x47)
                goto LABEL_CLOSE;
            pCharName = (const char*)aBuffer + 0x26;
            pTitle = (const char*)aBuffer + 0x36;
            nClass = aBuffer[0x22];
            nLevel = aBuffer[0x24];
            nFlags = *(unsigned short*)(aBuffer + 0x18);
        }
        else
        {
            if (nRead < 0x14F || nVersion > 0x60)
                goto LABEL_CLOSE;
            pCharName = (const char*)aBuffer + 0x88;
            pTitle = (const char*)aBuffer + 0x98;
            nClass = aBuffer[0x28];
            nLevel = aBuffer[0x2B];
            nFlags = *(unsigned short*)(aBuffer + 0x24);
        }

        sub_006BBF40_PutPackedWord(pOut, 0xE);
        pOut += 2;
        if (!pCharName[0])
        {
            for (int i = 0; i < 11; ++i)
                *pOut++ = gszDefaultSaveName_0070CCC8[i];
        }
        else
        {
            memcpy(pOut, pCharName, 11);
            pOut += 11;
        }
        *pOut++ = nClass + 1;
        memcpy(pOut, pTitle, 11);
        pOut += 11;
        *pOut++ = nLevel;
        sub_006BBF40_PutPackedWord(pOut, nFlags);
        pOut += 2;
        sub_006BBF40_PutPackedWord(pOut, 0);
        pOut += 2;
        *pOut++ = 0xFF;
        *pOut++ = 0xFF;
        *pOut = 0xFF;
        pOut[1] = 0;
        bResult = 1;
    }

LABEL_CLOSE:
    fclose(pFile);
    return bResult;
}
