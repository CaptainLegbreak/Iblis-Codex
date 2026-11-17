#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define SKILLSFLAGINDEX_TARGETALLY 26

struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    int dwUnitId;
};

struct D2SkillsTxt
{
    char unk0x00[4];
    unsigned char nFlags[8];
};

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType);               // 0x0058F090
unsigned short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                            // 0x00554630
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60

// 0x00554D20
int __fastcall SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId)
{
    if (!pOwner || !pPet)
    {
        return 0;
    }

    const int nOwnerUnitType = pOwner ? pOwner->dwUnitType : UNIT_INVALID;
    if (nOwnerUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    const int nPetType = pPet->dwUnitType;
    int nUnitType = nPetType;
    if (nPetType != UNIT_PLAYER && nPetType != UNIT_MONSTER)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETALLY >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETALLY & 7]))
    {
        return 0;
    }

    int nUnitGUID = pPet->dwUnitId;
    if (nPetType == UNIT_MONSTER)
    {
        AIGENERAL_GetOwnerData(pPet, &nUnitGUID, &nUnitType);
        if (nUnitGUID == -1 || nUnitType != UNIT_PLAYER)
        {
            return 0;
        }
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pOwner);
    if (nPartyId == 0xFFFF)
    {
        return 0;
    }

    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (!pOtherPlayer)
    {
        return 0;
    }

    return nPartyId == SUNIT_GetPartyId(pOtherPlayer);
}
