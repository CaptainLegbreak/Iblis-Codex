struct D2CelFileStrc;

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
const char* __stdcall D2CMP_GetGfxFileExtension(int bAllowCompressed);                                      // 0x005FE1F0
void __stdcall D2CMP_CelFileNormalize(D2CelFileStrc* pFile, D2CelFileStrc** ppOutFile, const char* szFile, int nLine, int nSpecVersion, int nUnused); // 0x00601340

// 0x004FA9B0
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFile(const char* szFile, int nType)
{
    char szPath[260];
    strcpy(szPath, szFile);
    strcat(szPath, D2CMP_GetGfxFileExtension(nType));
    void* pFile = sub_00517079_LoadFile(0, szPath, 0, ".\\Src\\D2WinArchive.cpp", 0x41);
    D2CelFileStrc* pCellFile;
    D2CMP_CelFileNormalize((D2CelFileStrc*)pFile, &pCellFile, ".\\Src\\D2WinArchive.cpp", 0x42, -1, 0);
    return pCellFile;
}

// 0x004FAA40
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFileWithFileSize(const char* szFile, unsigned int* pFileSize, int nType)
{
    char szPath[260];
    strcpy(szPath, szFile);
    strcat(szPath, D2CMP_GetGfxFileExtension(nType));
    void* pFile = sub_00517079_LoadFile(0, szPath, pFileSize, ".\\Src\\D2WinArchive.cpp", 0x52);
    D2CelFileStrc* pCellFile;
    D2CMP_CelFileNormalize((D2CelFileStrc*)pFile, &pCellFile, ".\\Src\\D2WinArchive.cpp", 0x53, -1, 0);
    return pCellFile;
}
