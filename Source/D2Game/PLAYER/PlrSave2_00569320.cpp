#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
struct D2ClientStrc;
struct D2StatListStrc;
struct D2StatStrc;
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
struct D2StatListExStrc;
struct D2PlayerDataStrc;
struct D2QuestSaveStrc;
struct D2PlrIntroSaveStrc;
struct D2SaveHeaderStrc;
struct D2PackedWordStrc;


#pragma pack(push, 2)
struct D2QuestSaveStrc
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
    unsigned short wSize;
    unsigned char aQuestData[3][0x60];
};

#pragma pack(pop)
struct D2PlrIntroSaveStrc
{
    unsigned short nHeader;
    unsigned short nLength;
    unsigned char unk0x04[3][8];
    unsigned char unk0x1C[3][8];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
void __fastcall PLRINTRO_CopyQuestIntroFlagsToBuffer(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer); // 0x00572520
void __fastcall PLRINTRO_CopyNpcIntroFlagsToBuffer(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer); // 0x00572530


D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};




extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40
int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer); // 0x00410E90
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0
int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc* pStatList, D2StatStrc* pOutStatBuffer, int nBufferSize); // 0x00625C90


#pragma pack(push, 1)
struct D2SaveHeaderStrc
{
    unsigned int dwMagic, dwVersion, dwSize, dwChecksum, dwWeaponSwitch;
    char szName[16]; unsigned int dwFlags; unsigned char nClass; char pad29[3];
    unsigned int dwCreateTime; char pad30[8]; unsigned int nHotKeys[16]; unsigned int nSkills[4];
    char pad88[0x20]; unsigned char nActs[3]; unsigned int dwMapSeed; char padAF[0x20];
    unsigned char nUnknownCF; char padD0[0x7F];
};

#pragma pack(pop)

int __stdcall FOG_ComputeChecksum(unsigned char* pData, int nSize); // 0x00411130
void __fastcall CLIENTS_SetFlags(D2ClientStrc*, unsigned short); // 0x00538630
void __fastcall CLIENTS_SetClassId(D2ClientStrc*, int); // 0x00538620
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830
extern "C" int __cdecl _stricmp(const char*, const char*); // 0x006841E9
int __fastcall sub_00569D80(D2GameStrc*, unsigned short, D2ClientStrc*); // 0x00569D80
void __fastcall CLIENTS_SetCreateTime(D2ClientStrc*, unsigned int); // 0x00538760
void __fastcall CLIENTS_SetActNo(D2ClientStrc*, unsigned char); // 0x005382E0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int, int, int, int, D2GameStrc*, D2ActiveRoomStrc*, char, int, unsigned int); // 0x00555230
void __fastcall sub_00569F20_InitPlayerFromClient(D2GameStrc*, D2UnitStrc*, D2ClientStrc*); // 0x00569F20
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc*); // 0x005387C0
void __fastcall sub_00571F90(D2GameStrc*, D2UnitStrc*, D2ClientStrc*); // 0x00571F90

__declspec(noinline) void __fastcall sub_00569EC0_UnpackWord(unsigned int* pRaw, int* pId, int* pFlag, int* pCount);
void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID); // 0x005390A0
void __fastcall sub_005391C0_SetClientBytes(D2ClientStrc*, unsigned char, unsigned char, unsigned char); // 0x005391C0

// 0x00569320
int __fastcall sub_00569320(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pSectionEnd = pSection + sizeof(D2QuestSaveStrc);
    if (pSectionEnd > pEnd)
    {
        return 1;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 2;
    }

    D2QuestSaveStrc tQuestSave;
    memset(&tQuestSave, 0, sizeof(tQuestSave));
    tQuestSave.dwHeaderMagic = 0x216F6F57;
    tQuestSave.dwVersion = 6;
    tQuestSave.wSize = sizeof(tQuestSave);
    for (int i = 0; i < 3; ++i)
    {
        QUESTRECORD_CopyRecordToBuffer(pPlayerData->pQuestData[i], tQuestSave.aQuestData[i], 0x60, 1);
    }

    memcpy(pSection, &tQuestSave, sizeof(tQuestSave));
    *ppSection = pSectionEnd;
    return 0;
}

// 0x00569490
int __fastcall PLRSAVE2_WritePlrIntroSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pSectionEnd = pSection + sizeof(D2PlrIntroSaveStrc);
    if (pSectionEnd > pEnd)
    {
        return 1;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 2;
    }

    D2PlrIntroSaveStrc tPlrIntroSave;
    memset(&tPlrIntroSave, 0, sizeof(tPlrIntroSave));
    tPlrIntroSave.nHeader = 0x7701;
    tPlrIntroSave.nLength = sizeof(tPlrIntroSave);
    for (int i = 0; i < 3; ++i)
    {
        PLRINTRO_CopyQuestIntroFlagsToBuffer(pPlayerData->pPlayerIntro[i], tPlrIntroSave.unk0x04[i]);
        PLRINTRO_CopyNpcIntroFlagsToBuffer(pPlayerData->pPlayerIntro[i], tPlrIntroSave.unk0x1C[i]);
    }

    memcpy(pSection, &tPlrIntroSave, sizeof(tPlrIntroSave));
    *ppSection = pSectionEnd;
    return 0;
}

inline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x00569540
int __fastcall PLRSAVE2_WritePlayerStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd)
{
    D2StatStrc aStatBuffer[512];
    D2BitBufferStrc bitBuffer;

    unsigned char* pSection = *ppSection;
    unsigned char* pData = pSection + 2;
    if (pData > pEnd)
    {
        return 1;
    }

    *(unsigned short*)pSection = 0x6667;
    BITMANIP_Initialize(&bitBuffer, pData, pEnd - pData);

    if (pPlayer->pStatListEx)
    {
        const int nStats = STATLIST_GetBaseStatsData(pPlayer->pStatListEx, aStatBuffer, 512);
        if (nStats > 0)
        {
            for (int i = 0; i < nStats; ++i)
            {
                const int nStatId = (unsigned int)aStatBuffer[i].nPackedValue >> 16;
                const unsigned short nLayer = aStatBuffer[i].nLayer;
                int nValue = aStatBuffer[i].nValue;
                D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
                if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->nCsvBits > 0)
                {
                    if (pItemStatCostTxtRecord->nCsvBits < 32)
                    {
                        if (pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_CSVSIGNED >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_CSVSIGNED & 7])
                        {
                            const int nMin = -1 << (pItemStatCostTxtRecord->nCsvBits - 1);
                            nValue = D2_MIN(D2_MAX(nValue, nMin), (1 << (pItemStatCostTxtRecord->nCsvBits - 1)) - 1);
                        }
                        else
                        {
                            nValue = D2_MIN(D2_MAX(nValue, 0), (1 << pItemStatCostTxtRecord->nCsvBits) - 1);
                        }
                    }

                    BITMANIP_Write(&bitBuffer, nStatId, 9);
                    if (pItemStatCostTxtRecord->nCsvParam)
                    {
                        BITMANIP_Write(&bitBuffer, nLayer, pItemStatCostTxtRecord->nCsvParam);
                    }
                    BITMANIP_Write(&bitBuffer, nValue, pItemStatCostTxtRecord->nCsvBits);
                }
            }
        }
    }

    BITMANIP_Write(&bitBuffer, 0x1FF, 9);
    *ppSection = &pData[BITMANIP_GetSize(&bitBuffer)];
    return 0;
}

// 0x00569EC0
void __fastcall sub_00569EC0_UnpackWord(unsigned int* pRaw, int* pId, int* pFlag, int* pCount)
{
    D2PackedWordStrc* pPacked = (D2PackedWordStrc*)pRaw;
    if (pPacked->wRaw == 0xFFFF)
    {
        *pId = -1;
        *pFlag = 0;
        *pCount = -1;
        return;
    }

    *pId = pPacked->nId;
    *pFlag = pPacked->bFlag;
    *pCount = pPacked->nCount;
    if (!*pCount)
    {
        *pCount = -1;
    }
}

static __forceinline unsigned char GetSavedAct(unsigned char nAct)
{
    nAct &= 0x7F;
    if (nAct >= 5)
        nAct = 0;
    return nAct;
}

static __forceinline void StoreSkillPair(int* pSkill, int* pOwner, int nSkill, int nOwner)
{
    *pSkill = nSkill;
    *pOwner = nOwner;
}

// 0x0056A090
int __fastcall PLRSAVE2_ReadSaveHeader(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char** ppSection, unsigned char* pEnd, D2UnitStrc** ppPlayer)
{
    int& nSkillId = reinterpret_cast<int&>(pEnd);
    int nHand;
    int nOwner;
    D2SaveHeaderStrc* pHeader = (D2SaveHeaderStrc*)*ppSection;
    *ppPlayer = 0;
    CLIENTS_SetFlags(pClient, 0);
    unsigned char* pNext = (unsigned char*)(pHeader + 1);
    if (pNext > pEnd)
        return 4;
    unsigned int nSize = pEnd - (unsigned char*)pHeader;
    unsigned int& nChecksum = reinterpret_cast<unsigned int&>(pEnd);
    nChecksum = pHeader->dwChecksum;
    pHeader->dwChecksum = 0;
    if (FOG_ComputeChecksum((unsigned char*)pHeader, nSize) != nChecksum)
        return 6;
    if (nSize != pHeader->dwSize)
        return 5;
    if (pHeader->dwVersion <= 91 || pHeader->dwVersion > 96)
        return 7;
    pHeader->szName[15] = 0;
    const char* pName = CLIENTS_GetName(pClient);
    if (!pName)
        return 3;
    if (_stricmp(pName, pHeader->szName))
        return 7;
    int nError = sub_00569D80(pGame, (unsigned short)pHeader->dwFlags, pClient);
    if (nError)
        return nError;
    if (pHeader->nClass > 7)
        return 4;
    int nClass = pHeader->nClass;
    CLIENTS_SetClassId(pClient, nClass);
    if (pHeader->dwFlags & 1)
    {
        pHeader->dwFlags &= ~1;
        CLIENTS_SetFlags(pClient, (unsigned short)pHeader->dwFlags);
        *ppSection = pNext;
        return 2;
    }
    sub_00539230_SetWeaponSwitch(pClient, pHeader->dwWeaponSwitch & 1);
    CLIENTS_SetFlags(pClient, (unsigned short)pHeader->dwFlags);
    CLIENTS_SetCreateTime(pClient, pHeader->dwCreateTime);
    unsigned char nAct = pHeader->nActs[pGame->nDifficulty];
    int& bUseSeed = nSkillId;
    bUseSeed = nAct & 0x80;
    CLIENTS_SetActNo(pClient, GetSavedAct(nAct));
    if (pGame->nGameType == 3 && !pGame->InitSeed && bUseSeed)
        pGame->dwInitSeed = pHeader->dwMapSeed;
    *ppPlayer = SUNIT_AllocUnitData(0, nClass, 0, 0, pGame, 0, 0, 0, 0);
    sub_00569F20_InitPlayerFromClient(pGame, *ppPlayer, pClient);
    sub_00571F90(CLIENTS_GetGame(pClient), *ppPlayer, pClient);
    for (int i = 0; i < 16; ++i)
    {
        sub_00569EC0_UnpackWord(&pHeader->nHotKeys[i], &nSkillId, &nHand, &nOwner);
        CLIENTS_SetSkillHotKey(pClient, i, nSkillId, nHand, nOwner);
    }
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(*ppPlayer);
    if (!pPlayerData)
        return 4;
    sub_00569EC0_UnpackWord(&pHeader->nSkills[0], &nSkillId, &nHand, &nOwner);
    StoreSkillPair(&pPlayerData->nLeftSkillId, &pPlayerData->nLeftSkillFlags, nSkillId, nOwner);
    sub_00569EC0_UnpackWord(&pHeader->nSkills[1], &nSkillId, &nHand, &nOwner);
    StoreSkillPair(&pPlayerData->nRightSkillId, &pPlayerData->nRightSkillFlags, nSkillId, nOwner);
    sub_00569EC0_UnpackWord(&pHeader->nSkills[2], &nSkillId, &nHand, &nOwner);
    StoreSkillPair(&pPlayerData->nSwitchLeftSkillId, &pPlayerData->nSwitchLeftSkillFlags, nSkillId, nOwner);
    sub_00569EC0_UnpackWord(&pHeader->nSkills[3], &nSkillId, &nHand, &nOwner);
    StoreSkillPair(&pPlayerData->nSwitchRightSkillId, &pPlayerData->nSwitchRightSkillFlags, nSkillId, nOwner);
    sub_005391C0_SetClientBytes(pClient, pHeader->nUnknownCF, 0, 0);
    *ppSection = pNext;
    return 0;
}
