struct D2GameStrc;
struct D2UnitStrc;
struct D2ClientStrc;
struct D2PetUpdateStrc
{
    int nUnitId;
    int nClassId;
    unsigned short nPetType;
    unsigned short unk_0A;
    int nParam;
};
D2ClientStrc* __fastcall sub_005531C0_GetClient(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x005531C0
void __fastcall sub_0053CB30_SendPetUpdate(D2ClientStrc* pClient, unsigned char nFlag, int nParam, int nUnitId, int nClassId, unsigned short nPetType); // 0x0053CB30
extern const char gszPlayerPets_006E15D8[]; // 0x006E15D8

// 0x00574410
void __fastcall sub_00574410_SendPetUpdate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2PetUpdateStrc* pData)
{
    sub_0053CB30_SendPetUpdate(sub_005531C0_GetClient(pUnit, gszPlayerPets_006E15D8, 0x43), 0, pData->nParam, pData->nUnitId, pData->nClassId, pData->nPetType);
}
