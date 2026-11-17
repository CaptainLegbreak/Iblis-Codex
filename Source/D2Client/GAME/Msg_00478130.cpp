#include "D2Client.h"

struct D2RosterPetNodeStrc
{
    int nValue;
    int nType;
    int nKey;
    int nArg;
    int unk0x10[3];
    int nInit;
    int nClear;
    int unk0x24[3];
    D2RosterPetNodeStrc* pNext;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __stdcall D2CMP_CelFileFreeHardware(D2CelFileStrc* pCelFile);                                           // 0x00601A50
int gnProgress_007BB3B4;                                                                                    // 0x007BB3B4
extern D2RosterPetNodeStrc* gpRosterPets_007BB5BC;                                                          // 0x007BB5BC

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
