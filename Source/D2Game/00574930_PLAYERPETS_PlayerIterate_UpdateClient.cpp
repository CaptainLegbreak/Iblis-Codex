struct D2GameStrc;
struct D2UnitStrc;
struct D2ClientStrc;

struct D2PetArgStrc
{
    int nPetGUID;
    int nUnitGUID;
    unsigned short nPetClass;
    char unk0x0A[2];
    int nPetType;
    int nSeed;
    int nName;
};

extern "C" const char gszPlayerPetsSourceFile[];                                                            // 0x006E15D8

D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x7A_6FC3E100(D2ClientStrc* pClient, char a2, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass); // 0x0053CB30
void __fastcall D2GAME_PACKETS_SendPacket0x81_6FC3E160(D2ClientStrc* pClient, char a2, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass, int nSeed, int nName); // 0x0053CB80

// 0x00574930
void __fastcall PLAYERPETS_PlayerIterate_UpdateClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg)
{
    D2PetArgStrc* pPetArg = (D2PetArgStrc*)pArg;

    if (!pPetArg->nSeed && !pPetArg->nName)
    {
        D2GAME_PACKETS_SendPacket0x7A_6FC3E100(SUNIT_GetClientFromPlayer(pPlayer, gszPlayerPetsSourceFile, 830), 1, pPetArg->nPetType, pPetArg->nPetGUID, pPetArg->nUnitGUID, pPetArg->nPetClass);
    }
    else
    {
        D2GAME_PACKETS_SendPacket0x81_6FC3E160(SUNIT_GetClientFromPlayer(pPlayer, gszPlayerPetsSourceFile, 837), 1, pPetArg->nPetType, pPetArg->nPetGUID, pPetArg->nUnitGUID, pPetArg->nPetClass, pPetArg->nSeed, pPetArg->nName);
    }
}
