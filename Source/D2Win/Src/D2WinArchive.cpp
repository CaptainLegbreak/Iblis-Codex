#include "D2Win.h"

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
const char* __stdcall D2CMPGetGfxFileExtension(int bAllowCompressed);                                      // 0x005FE1F0
void __stdcall CelFileNormalize(D2CelFileStrc* pFile, D2CelFileStrc** ppOutFile, const char* szFile, int nLine, int nSpecVersion, int nUnused); // 0x00601340

int __stdcall CelFileFreeHardware(D2CelFileStrc* pCelFile);                                           // 0x00601A50

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

// 0x004FA9B0
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFile(const char* szFile, int nType)
{
    char szPath[260];
    strcpy(szPath, szFile);
    strcat(szPath, D2CMPGetGfxFileExtension(nType));
    void* pFile = sub_00517079_LoadFile(0, szPath, 0, ".\\Src\\D2WinArchive.cpp", 0x41);
    D2CelFileStrc* pCellFile;
    CelFileNormalize((D2CelFileStrc*)pFile, &pCellFile, ".\\Src\\D2WinArchive.cpp", 0x42, -1, 0);
    return pCellFile;
}

// 0x004FAA40
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFileWithFileSize(const char* szFile, unsigned int* pFileSize, int nType)
{
    char szPath[260];
    strcpy(szPath, szFile);
    strcat(szPath, D2CMPGetGfxFileExtension(nType));
    void* pFile = sub_00517079_LoadFile(0, szPath, pFileSize, ".\\Src\\D2WinArchive.cpp", 0x52);
    D2CelFileStrc* pCellFile;
    CelFileNormalize((D2CelFileStrc*)pFile, &pCellFile, ".\\Src\\D2WinArchive.cpp", 0x53, -1, 0);
    return pCellFile;
}

// 0x004FAAE0
void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile)
{
    CelFileFreeHardware(pCellFile);
    if (pCellFile)
    {
        FOG_Free(pCellFile, ".\\Src\\D2WinArchive.cpp", 0x5C, 0);
    }
}
