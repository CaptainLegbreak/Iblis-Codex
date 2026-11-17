typedef unsigned int size_t;
typedef char* va_list;
#define va_start(ap, v) (ap = (va_list)&v + sizeof(v))

struct D2CelFileStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, va_list args); // 0x006CC4AC
extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType);                              // 0x004788B0
int __stdcall sub_006019F0(D2CelFileStrc* pCelFile);                                                // 0x006019F0
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20

extern int gdwGlobal_007A5150;                                                                              // 0x007A5150
extern D2CelFileStrc* gpAutomapCels_007A5168[4];                                                            // 0x007A5168
int gnAutomapCelFrames_007A5178[4];                                                                         // 0x007A5178
extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118

// 0x0045A2B0
void __cdecl sub_0045A2B0_ReloadAutomapCels()
{
    char szPath[260] = {0};
    for (int i = 0; i < 4; ++i)
    {
        if (gpAutomapCels_007A5168[i])
            sub_00478A00(gpAutomapCels_007A5168[i]);
        gpAutomapCels_007A5168[i] = 0;
    }
    switch (gdwGlobal_007A5150)
    {
    case 1:
        sprintf(szPath, "%s\\UI\\AutoMap\\MaxiMapS", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[0] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[0] = sub_006019F0(gpAutomapCels_007A5168[0]);
        sprintf(szPath, "%s\\UI\\AutoMap\\Act2MapS", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[1] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[1] = sub_006019F0(gpAutomapCels_007A5168[1]);
        sprintf(szPath, "%s\\UI\\AutoMap\\Act4MapS", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[2] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[2] = sub_006019F0(gpAutomapCels_007A5168[2]);
        sprintf(szPath, "%s\\UI\\AutoMap\\ExTnMapS", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[3] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[3] = sub_006019F0(gpAutomapCels_007A5168[3]);
        break;
    default:
        sprintf(szPath, "%s\\UI\\AutoMap\\MaxiMap", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[0] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[0] = sub_006019F0(gpAutomapCels_007A5168[0]);
        sprintf(szPath, "%s\\UI\\AutoMap\\Act2Map", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[1] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[1] = sub_006019F0(gpAutomapCels_007A5168[1]);
        sprintf(szPath, "%s\\UI\\AutoMap\\Act4Map", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[2] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[2] = sub_006019F0(gpAutomapCels_007A5168[2]);
        if (sub_00408F20_HasExpansionMpq())
        {
            sprintf(szPath, "%s\\UI\\AutoMap\\ExTnMap", szDataGlobal_006D4118);
            gpAutomapCels_007A5168[3] = sub_004788B0(szPath, 0);
            gnAutomapCelFrames_007A5178[3] = sub_006019F0(gpAutomapCels_007A5168[3]);
        }
        else
        {
            gpAutomapCels_007A5168[3] = 0;
            gnAutomapCelFrames_007A5178[3] = 0;
        }
        break;
    }
}

// build: context sub_0045B960_FilePrintf
void __cdecl sub_0045B960_FilePrintf(void* hFile, const char* szFormat, ...)
{
    char szBuffer[260];
    va_list args;
    va_start(args, szFormat);
    unsigned long nWritten = wvsprintfA(szBuffer, szFormat, args);
    WriteFile(hFile, szBuffer, nWritten, &nWritten, 0);
}
