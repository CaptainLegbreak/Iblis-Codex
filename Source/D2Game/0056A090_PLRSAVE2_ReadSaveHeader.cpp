struct D2UnitStrc;
struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2GameStrc
{
    char pad0[0x6A]; unsigned char nGameType; char pad6B[2]; unsigned char nDifficulty;
    char pad6E[0xE]; unsigned int dwInitSeed; int dwObjSeed; int bInitSeed;
};
struct D2PlayerDataStrc
{
    char pad0[0x70]; int nRightSkillId; int nLeftSkillId; int nRightSkillOwner; int nLeftSkillOwner;
    int nSwitchRightId; int nSwitchLeftId; int nSwitchRightOwner; int nSwitchLeftOwner;
};
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
unsigned int __stdcall FOG_ComputeChecksum(const unsigned char*, unsigned int); // 0x00411130
void __fastcall CLIENTS_SetFlags(D2ClientStrc*, unsigned short); // 0x00538630
void __fastcall CLIENTS_SetClassId(D2ClientStrc*, int); // 0x00538620
const char* __fastcall CLIENTS_GetName(D2ClientStrc*); // 0x00538830
extern "C" int __cdecl _stricmp(const char*, const char*); // 0x006841E9
int __fastcall sub_00569D80(D2GameStrc*, unsigned short, D2ClientStrc*); // 0x00569D80
void __fastcall sub_00539230_SetWeaponSwitch(D2ClientStrc*, unsigned char); // 0x00539230
void __fastcall CLIENTS_SetCreateTime(D2ClientStrc*, unsigned int); // 0x00538760
void __fastcall CLIENTS_SetActNo(D2ClientStrc*, unsigned char); // 0x005382E0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int, int, int, int, D2GameStrc*, D2ActiveRoomStrc*, char, int, unsigned int); // 0x00555230
void __fastcall sub_00569F20(D2GameStrc*, D2UnitStrc*, D2ClientStrc*); // 0x00569F20
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc*); // 0x005387C0
void __fastcall sub_00571F90(D2GameStrc*, D2UnitStrc*, D2ClientStrc*); // 0x00571F90
struct D2PackedWordStrc
{
    union
    {
        unsigned short wRaw;
        struct
        {
            unsigned short nId : 12;
            unsigned short nUnused : 3;
            unsigned short bFlag : 1;
        };
    };
    unsigned short nCount;
};

__declspec(noinline) void __fastcall sub_00569EC0_UnpackWord(unsigned int* pRaw, int* pId, int* pFlag, int* pCount);

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
void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc*, int, int, int, int); // 0x005390A0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
void __fastcall sub_005391C0_SetClientBytes(D2ClientStrc*, unsigned char, unsigned char, unsigned char); // 0x005391C0
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
    if (pGame->nGameType == 3 && !pGame->bInitSeed && bUseSeed)
        pGame->dwInitSeed = pHeader->dwMapSeed;
    *ppPlayer = SUNIT_AllocUnitData(0, nClass, 0, 0, pGame, 0, 0, 0, 0);
    sub_00569F20(pGame, *ppPlayer, pClient);
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
    StoreSkillPair(&pPlayerData->nLeftSkillId, &pPlayerData->nLeftSkillOwner, nSkillId, nOwner);
    sub_00569EC0_UnpackWord(&pHeader->nSkills[1], &nSkillId, &nHand, &nOwner);
    StoreSkillPair(&pPlayerData->nRightSkillId, &pPlayerData->nRightSkillOwner, nSkillId, nOwner);
    sub_00569EC0_UnpackWord(&pHeader->nSkills[2], &nSkillId, &nHand, &nOwner);
    StoreSkillPair(&pPlayerData->nSwitchLeftId, &pPlayerData->nSwitchLeftOwner, nSkillId, nOwner);
    sub_00569EC0_UnpackWord(&pHeader->nSkills[3], &nSkillId, &nHand, &nOwner);
    StoreSkillPair(&pPlayerData->nSwitchRightId, &pPlayerData->nSwitchRightOwner, nSkillId, nOwner);
    sub_005391C0_SetClientBytes(pClient, pHeader->nUnknownCF, 0, 0);
    *ppSection = pNext;
    return 0;
}
