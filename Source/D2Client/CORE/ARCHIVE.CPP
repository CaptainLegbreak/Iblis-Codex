#include "D2Client.h"

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);
void* __stdcall sub_004FAC80();                                                                             // 0x004FAC80
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
void __stdcall CelFileNormalize(D2CelFileStrc* pFile, D2CelFileStrc** ppOutFile, const char* szFile, int nLine, int nSpecVersion, const char* szPath); // 0x00601340

// 0x004788B0
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType)
{
    char szPath[260];
    strcpy(szPath, szFile);
    strcat(szPath, D2CMPGetGfxFileExtension(nType));
    void* pFile = sub_00517079_LoadFile(sub_004FAC80(), szPath, 0, ".\\CORE\\ARCHIVE.CPP", 0x53);
    D2CelFileStrc* pCellFile = 0;
    CelFileNormalize((D2CelFileStrc*)pFile, &pCellFile, ".\\CORE\\ARCHIVE.CPP", 0x56, -1, szPath);
    return pCellFile;
}

// 0x00478950
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFileWithFileSize(const char* szFile, unsigned int* pFileSize, int nType)
{
    char szPath[260];
    strcpy(szPath, szFile);
    strcat(szPath, D2CMPGetGfxFileExtension(nType));
    void* pFile = sub_00517079_LoadFile(sub_004FAC80(), szPath, pFileSize, ".\\CORE\\ARCHIVE.CPP", 0x68);
    D2CelFileStrc* pCellFile = 0;
    CelFileNormalize((D2CelFileStrc*)pFile, &pCellFile, ".\\CORE\\ARCHIVE.CPP", 0x6B, -1, szPath);
    return pCellFile;
}
