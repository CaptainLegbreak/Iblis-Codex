#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SaveFilePacketStrc;
struct D2RosterPetNodeStrc;

#pragma pack(push, 1)
struct D2SaveFilePacketStrc
{
    unsigned char nHeader;
    unsigned char f_1;
    int nTotalSize;
    unsigned char pData[0x100];
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" int __cdecl fseek(_iobuf* pFile, long nOffset, int nOrigin); // 0x00684A2A
extern "C" long __cdecl ftell(_iobuf* pFile); // 0x00684935
extern "C" size_t __cdecl fread(void* pBuffer, size_t nSize, size_t nCount, _iobuf* pFile); // 0x00684782
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __fastcall sub_00407050_GetSavePath(char* szPath, int nSize); // 0x00407050
void __fastcall sub_00478160_ShowProgressSteps(int nDone, int nTotal); // 0x00478160
extern char gszCharName_007A05C4[]; // 0x007A05C4
extern "C" const char gszSavePathFormat_006D4230[]; // 0x006D4230
extern "C" const char gszModeRb_006CDC90[]; // 0x006CDC90
extern int gnSentBytes_007A6AF8; // 0x007A6AF8
extern int gnSentPackets_007A6B00; // 0x007A6B00
extern int gnProgress_007BB3B4; // 0x007BB3B4

int __stdcall D2CMP_CelFileFreeHardware(D2CelFileStrc* pCelFile); // 0x00601A50
extern D2RosterPetNodeStrc* gpRosterPets_007BB5BC; // 0x007BB5BC

// 0x00478040
static unsigned char* sub_00478040(int* pnFileSize)
{
    char szSavePath[0x400];
    char szFileName[0x1F4];
    D2_ASSERT(gszCharName_007A05C4[0], 0x1EB);
    sub_00407050_GetSavePath(szSavePath, 0x400);
    sprintf(szFileName, gszSavePathFormat_006D4230, szSavePath, gszCharName_007A05C4);
    _iobuf* pFile = fopen(szFileName, gszModeRb_006CDC90);
    if (!pFile)
        return 0;
    if (fseek(pFile, 0, 2))
    {
        fclose(pFile);
        return 0;
    }
    *pnFileSize = ftell(pFile);
    fseek(pFile, 0, 0);
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(*pnFileSize, ".\\GAME\\Msg.cpp", 0x1FF, 0);
    fread(pBuffer, *pnFileSize, 1, pFile);
    fclose(pFile);
    return pBuffer;
}

int gnProgress_007BB3B4; // 0x007BB3B4

// 0x00478130
void __fastcall sub_00478130_SetScale(int nValue, int nDivisor)
{
    if (!nDivisor)
    {
        gnProgress_007BB3B4 = 0;
        return;
    }
    gnProgress_007BB3B4 = (nValue << 8) / nDivisor;
}

// 0x004781D0
void __fastcall sub_004781D0(int bAnimate)
{
    D2SaveFilePacketStrc tPacket;
    int nFileSize = 0;
    unsigned char* pBuffer = sub_00478040(&nFileSize);
    D2_ASSERT(pBuffer, 0x232);
    if (bAnimate)
        sub_00478160_ShowProgressSteps(0, 0);
    unsigned char* pRead = pBuffer;
    const int nChunks = nFileSize / 0xFF;
    for (int i = 0; i < nChunks; ++i)
    {
        tPacket.nHeader = 0x6C;
        tPacket.nTotalSize = nFileSize;
        tPacket.f_1 = 0xFF;
        for (int k = 0; k < 0xFF; ++k)
            tPacket.pData[k] = *pRead++;
        sub_0052AE50_SendPacket(0xFF + 7, 0, &tPacket);
        gnSentBytes_007A6AF8 += 0xFF + 7;
        gnSentPackets_007A6B00 += 1;
        if (bAnimate)
            sub_00478160_ShowProgressSteps(i, nChunks);
    }
    const int nRemain = nFileSize - nChunks * 0xFF;
    tPacket.nHeader = 0x6C;
    tPacket.nTotalSize = nFileSize;
    tPacket.f_1 = (unsigned char)nRemain;
    for (int k = 0; k < nRemain; ++k)
        tPacket.pData[k] = *pRead++;
    const int nSize = nRemain + 7;
    sub_0052AE50_SendPacket(nSize, 0, &tPacket);
    gnSentBytes_007A6AF8 += nSize;
    gnSentPackets_007A6B00 += 1;
    FOG_Free(pBuffer, ".\\GAME\\Msg.cpp", 0x262, 0);
    if (nChunks == 0)
        gnProgress_007BB3B4 = nChunks;
    else
        gnProgress_007BB3B4 = (nChunks << 8) / nChunks;
}

// 0x00478A00
void __fastcall sub_00478A00(void* pCel)
{
    D2CMP_CelFileFreeHardware((D2CelFileStrc*)pCel);
    if (pCel)
        FOG_Free(pCel, ".\\CORE\\ARCHIVE.CPP", 0x7A, 0);
}

// 0x00478AB0
void __fastcall sub_00478AB0_RemoveType7(int nUnused, int nKey)
{
    D2RosterPetNodeStrc* pPrev = 0;
    for (D2RosterPetNodeStrc* pNode = gpRosterPets_007BB5BC; pNode; pNode = pNode->pNext)
    {
        if (pNode->nType == 7 && pNode->nKey == nKey)
        {
            if (pPrev)
                pPrev->pNext = pNode->pNext;
            else
                gpRosterPets_007BB5BC = pNode->pNext;
            FOG_Free(pNode, ".\\GAME\\RosterPets.cpp", 0x59, 0);
            return;
        }
        pPrev = pNode;
    }
}
