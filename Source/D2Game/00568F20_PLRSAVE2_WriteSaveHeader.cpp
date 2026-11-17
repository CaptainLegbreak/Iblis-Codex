struct D2ClientStrc;
struct D2SkillStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
    int dwGameType;
    char unk0x78[0x04];
    unsigned int dwInitSeed;
};

struct D2UnitStrc;

struct D2DataTablesStrc
{
    char unk0x00[0xBA8];
    int nHighestClassSkillCount;
};

struct D2SaveSkillKeyStrc
{
    unsigned short nSkill;
    unsigned short nKey;
};

#pragma pack(push, 1)
struct D2SaveHeaderStrc
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
    char unk0x08[0x08];
    unsigned int dwWeaponSwitch;
    char szName[16];
    unsigned int dwSaveFlags;
    unsigned char nClass;
    unsigned char nStats;
    unsigned char nSkills;
    unsigned char nLevel;
    unsigned int dwCreateTime;
    unsigned int dwLasTime;
    unsigned int dwPlayTime;
    D2SaveSkillKeyStrc SkillKeys[16];
    unsigned short nLeftSkillId;
    unsigned short nLeftSkillItemIndex;
    unsigned short nRightSkillId;
    unsigned short nRightSkillItemIndex;
    unsigned short nSwitchLeftSkillId;
    unsigned short nSwitchLeftSkillItemIndex;
    unsigned short nSwitchRightSkillId;
    unsigned short nSwitchRightSkillItemIndex;
    unsigned char nComponent[16];
    unsigned char nCompColor[16];
    unsigned char nTown[3];
    unsigned int dwMapSeed;
    char unk0xAF[0x20];
    unsigned char nGuildEmblemBgColor;
    char unk0xD0[0x7F];
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;    // 0x006CC837
extern "C" const char* __cdecl sub_00408090();    // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);    // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);    // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);    // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern "C" long __cdecl _time32(long* pTime);    // 0x006850E6
extern D2DataTablesStrc* sgptDataTables;    // 0x00744304
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);    // 0x004135D0
void __fastcall CLIENTS_GetGuildEmblem(D2ClientStrc* pClient, unsigned char* pBackgroundColor, unsigned char* pForegroundColor, unsigned char* pEmblemType);    // 0x00539190
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient);    // 0x005382B0
int __fastcall sub_005385C0_GetPlayTime(D2ClientStrc* pClient);    // 0x005385C0
int __fastcall CLIENTS_GetClassId(D2ClientStrc* pClient);    // 0x005385F0
int __fastcall CLIENTS_GetFlags(D2ClientStrc* pClient);    // 0x00538640
int __fastcall CLIENTS_GetCreateTime(D2ClientStrc* pClient);    // 0x00538790
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient);    // 0x00538830
void __fastcall CLIENTS_GetSkillHotKey(D2ClientStrc* pClient, int nId, int* pSkillId, int* pHand, int* pItemGUID);    // 0x005390D0
unsigned char __fastcall CLIENTS_GetWeaponSwitch(D2ClientStrc* pClient);    // 0x00539220
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);    // 0x005531C0
unsigned short __fastcall PLRSAVE2_GetItemIndex(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nGUID);    // 0x00568DC0
void __fastcall PLRSAVE2_WriteMercData(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SaveHeaderStrc* pSaveHeader);    // 0x00568E60
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);    // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);    // 0x006201D0
void __stdcall UNITS_GetSwitchLeftSkillData(D2UnitStrc* pUnit, int* pSwitchLeftSkillId, int* pSwitchLeftSkillFlags);    // 0x00623220
void __stdcall UNITS_GetSwitchRightSkillData(D2UnitStrc* pUnit, int* pSwitchRightSkillId, int* pSwitchRightSkillFlags);    // 0x00623290
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);    // 0x00625480
void __stdcall INVENTORY_GetItemSaveGfxInfo(D2UnitStrc* pUnit, unsigned char* pComponents, unsigned char* pColors);    // 0x0063E510
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);    // 0x00643AD0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);    // 0x00643CE0

int __fastcall sub_00568D80_FindTerminator(const char* szText, int nSize)
{
    const char* pStart = szText;
    const char* pEnd = szText + nSize;
    while (szText < pEnd && *szText)
    {
        ++szText;
    }

    if (szText >= pEnd)
    {
        return -1;
    }

    return szText - pStart;
}

// 0x00568F20
int __fastcall PLRSAVE2_WriteSaveHeader(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd)
{
    D2ClientStrc* pClient;
    unsigned char* pSection = *ppSection;
    pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrSave2.cpp", 0x1B4);
    if (!pClient)
    {
        return 2;
    }

    const char* szName = CLIENTS_GetName(pClient);
    if (!szName)
    {
        return 2;
    }

    if (sub_00568D80_FindTerminator(szName, 16) < 1)
    {
        return 2;
    }

    if (pSection + sizeof(D2SaveHeaderStrc) > pEnd)
    {
        return 1;
    }

    D2SaveHeaderStrc saveHeader;
    memset(&saveHeader, 0, sizeof(D2SaveHeaderStrc));
    saveHeader.dwHeaderMagic = 0xAA55AA55;
    saveHeader.dwVersion = 0x60;
    SStrCopy(saveHeader.szName, szName, 0x7FFFFFFF);
    saveHeader.dwSaveFlags = CLIENTS_GetFlags(pClient);
    if (pGame->bExpansion)
    {
        saveHeader.dwSaveFlags |= 0x20;
    }

    if (pGame->dwGameType)
    {
        saveHeader.dwSaveFlags |= 0x40;
    }

    saveHeader.nClass = CLIENTS_GetClassId(pClient);
    saveHeader.nLevel = STATLIST_UnitGetStatValue(pPlayer, 0xC, 0);
    saveHeader.dwCreateTime = CLIENTS_GetCreateTime(pClient);
    saveHeader.dwLasTime = _time32(0);
    saveHeader.dwPlayTime = sub_005385C0_GetPlayTime(pClient);
    saveHeader.dwMapSeed = pGame->dwInitSeed;
    saveHeader.nStats = 16;
    saveHeader.nSkills = (unsigned char)sgptDataTables->nHighestClassSkillCount;
    if (CLIENTS_GetWeaponSwitch(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrSave2.cpp", 0x1DD)))
    {
        saveHeader.dwWeaponSwitch |= 1;
    }

    int nGUID;
    int nSkill;
    for (int i = 0; i < 16; ++i)
    {
        int nParam;
        CLIENTS_GetSkillHotKey(pClient, i, &nSkill, &nParam, &nGUID);
        D2_ASSERT(nSkill < 0x8000, 0x1EB);
        saveHeader.SkillKeys[i].nSkill = (unsigned short)nSkill | (nParam != 0 ? 0x8000 : 0);
        saveHeader.SkillKeys[i].nKey = PLRSAVE2_GetItemIndex(pGame, pPlayer, nGUID);
    }

    D2SkillStrc* pSkill = UNITS_GetLeftSkill(pPlayer);
    if (pSkill)
    {
        saveHeader.nLeftSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrSave2.cpp", 0x1F5);
        saveHeader.nLeftSkillItemIndex = PLRSAVE2_GetItemIndex(pGame, pPlayer, SKILLS_GetOwnerGUIDFromSkill(pSkill));
    }

    pSkill = UNITS_GetRightSkill(pPlayer);
    saveHeader.nRightSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrSave2.cpp", 0x1FC);
    saveHeader.nRightSkillItemIndex = PLRSAVE2_GetItemIndex(pGame, pPlayer, SKILLS_GetOwnerGUIDFromSkill(pSkill));

    int nSkillId;
    UNITS_GetSwitchLeftSkillData(pPlayer, &nSkillId, &nGUID);
    saveHeader.nSwitchLeftSkillId = nSkillId;
    saveHeader.nSwitchLeftSkillItemIndex = PLRSAVE2_GetItemIndex(pGame, pPlayer, nGUID);

    UNITS_GetSwitchRightSkillData(pPlayer, &nSkillId, &nGUID);
    saveHeader.nSwitchRightSkillId = nSkillId;
    saveHeader.nSwitchRightSkillItemIndex = PLRSAVE2_GetItemIndex(pGame, pPlayer, nGUID);

    saveHeader.nTown[pGame->nDifficulty] = CLIENTS_GetActNo(pClient) | 0x80;

    memset(saveHeader.nComponent, 0xFF, 16);
    memset(saveHeader.nCompColor, 0xFF, 16);
    INVENTORY_GetItemSaveGfxInfo(pPlayer, saveHeader.nComponent, saveHeader.nCompColor);
    PLRSAVE2_WriteMercData(pGame, pPlayer, &saveHeader);

    unsigned char nSaveField;
    unsigned char nUnused1;
    unsigned char nUnused2;
    CLIENTS_GetGuildEmblem(pClient, &nSaveField, &nUnused1, &nUnused2);
    saveHeader.nGuildEmblemBgColor = nSaveField;

    memcpy(pSection, &saveHeader, sizeof(D2SaveHeaderStrc));
    *ppSection = pSection + sizeof(D2SaveHeaderStrc);
    return 0;
}
