extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" unsigned int __cdecl strlen(const char* szString);

struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2RunesTxt;
struct D2CinematicPacketStrc;

struct D2DataTablesStrc
{
    char unk0x000[0xBA0];
    int nSkillsTxtRecordCount;
};

#pragma pack(push, 1)
struct D2GSPacketSrv2C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    unsigned short nSoundEvent;
};

struct D2GSPacketSrv59
{
    unsigned char nHeader;
    unsigned int dwGUID;
    unsigned char nClass;
    char szName[16];
    unsigned short nPosX;
    unsigned short nPosY;
};

struct D2GSPacketSrv5B
{
    unsigned char nHeader;
    unsigned short nPacketLen;
    int nUnitGUID;
    unsigned char nClass;
    char szName[16];
    unsigned short nLevel;
    unsigned short nPartyId;
    unsigned short unk0x1C;
    unsigned short nPartyFlags;
    unsigned short unk0x20;
    char szText[1];
};

struct D2GSPacketSrv5C
{
    unsigned char nHeader;
    int dwPlayerGUID;
};

struct D2GSPacketSrv92
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
};

struct D2GSPacketSrv5F
{
    unsigned char nHeader;
    int nPortalFlags;
};

struct D2GSPacketSrv61
{
    unsigned char nHeader;
    unsigned char unk0x01;
};

struct D2GSPacketSrv65
{
    unsigned char nHeader;
    int dwUnitId;
    unsigned short unk0x05;
};

struct D2GSPacketSrv75
{
    unsigned char nHeader;
    int nUnitGUID;
    unsigned short nPartyId;
    unsigned short nLevel;
    unsigned short nFlags;
    unsigned short unk0x0B;
};

struct D2GSPacketSrv79
{
    unsigned char nHeader;
    unsigned char nOwnerGUID;
    int dwGold;
};

struct D2GSPacketSrv7A
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned short unk0x03;
    int unk0x05;
    int unk0x09;
};

struct D2GSPacketSrv7B
{
    unsigned char nHeader;
    unsigned char nSlot;
    unsigned short wSkill;
    int nItemGUID;
};

struct D2GSPacketSrv7E
{
    unsigned char nHeader;
    unsigned char unk0x001[4];
};

struct D2GSPacketSrv7F
{
    unsigned char nHeader;
    unsigned char bIsPlayer;
    unsigned short nLifePercentage;
    int nUnitGUID;
    unsigned short nLevelId;
};

struct D2GSPacketSrv90
{
    unsigned char nHeader;
    int dwGUID;
    int dwPosX;
    int dwPosY;
};

struct D2GSPacketSrv8B
{
    unsigned char nHeader;
    int nUnitGUID;
    unsigned char bParty;
};

struct D2GSPacketSrv8C
{
    unsigned char nHeader;
    int dwPlayerGUID1;
    int dwPlayerGUID2;
    unsigned short nFlags;
};

struct D2GSPacketSrv8D
{
    unsigned char nHeader;
    int dwPlayerGUID;
    unsigned short nPartyGUID;
};

struct D2GSPacketSrv8E
{
    unsigned char nHeader;
    unsigned char nType;
    int dwPlayerGUID;
    int dwCorpseGUID;
};

struct D2GSPacketSrv9B
{
    unsigned char nHeader;
    unsigned short unk0x01;
    unsigned short unk0x03;
};

struct D2GSPacketSrv97
{
    unsigned char nHeader;
};

struct D2GSPacketSrvA6
{
    unsigned char nHeader;
    unsigned char bSkip;
    unsigned char unk0x02[2];
    unsigned short nRecordId;
    unsigned char pRecord[1];
};

struct D2GSPacketSrvA7
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nState;
};

struct D2GSPacketSrvA9
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nState;
};
#pragma pack(pop)

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

void __fastcall sub_004CBDE0_PlayEventSound(int nUnitId, unsigned char nUnitType, unsigned short nEvent);    // 0x004CBDE0
D2UnitStrc* __fastcall sub_00466200_CreatePlayerUnit(unsigned int nUnitId, int nClassId, int nX, int nY, char* szName); // 0x00466200
void __fastcall sub_0047A6F0(int nUnitId, int nClass, const char* szName, int nLevel, int nPartyId, int nArg1C, int nPartyFlags, int nArg20, const char* szText1, const char* szText2); // 0x0047A6F0
void __fastcall sub_0047A8B0(int nPlayerGUID);                                                              // 0x0047A8B0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_004C23E0(D2UnitStrc* pUnit);                                                            // 0x004C23E0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags);                             // 0x006221E0
void __fastcall sub_004B9320_PlayCinematicFromPacket(const D2CinematicPacketStrc* pPacket);                 // 0x004B9320
void __cdecl sub_0047F1D0_LoadResolution();                                                                 // 0x0047F1D0
void __fastcall sub_00479B10_SetKillCount(int nUnitId, unsigned short nValue);                              // 0x00479B10
void __fastcall sub_0047A850_UpdateRosterUnit(int nUnitId, unsigned short wPartyId, unsigned short wLevel, int nUnused, int nPartyFlags); // 0x0047A850
void __fastcall sub_004B90D0(int nGold, unsigned char nOwner);                                              // 0x004B90D0
void __fastcall sub_00478B10_SetRosterEntry(int nKey, int nArg, int nType, int nValue);                     // 0x00478B10
void __fastcall sub_00478C90(int nKey);                                                                     // 0x00478C90
void __fastcall sub_004AA0C0_SetSlot(int nSlot, int nValueA, int nValueB, int nValueC);                     // 0x004AA0C0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __fastcall sub_0046F310(unsigned char nAct);                                                           // 0x0046F310
void __fastcall sub_0047A0D0_SetLifeAndLevel(int nUnitId, int nLife, unsigned short wLevelId);              // 0x0047A0D0
void __fastcall sub_00479010_UpdatePetLife(int nUnitId, int nLifePercent, unsigned short nArg);             // 0x00479010
void __fastcall sub_0047A100_SetPosition(int nUnitId, int nX, int nY);                                      // 0x0047A100
void __fastcall sub_0047A350_SetPartyFlags(int nUnitId, unsigned char nFlags);                              // 0x0047A350
void __fastcall sub_0047A370_SetPvpFlags(int nUnitId1, int nUnitId2, unsigned short wFlags);                // 0x0047A370
void __fastcall sub_0047A330_SetPartyId(int nUnitId, unsigned short wPartyId);                              // 0x0047A330
void __fastcall sub_0047A3D0_AddCorpse(int nUnitId, int nCorpseId);                                         // 0x0047A3D0
void __fastcall sub_0047A490_DropCorpseEntry(int nUnitId, int nCorpseId);                                      // 0x0047A490
void __fastcall sub_004B6980_SetNpcMenuState(unsigned short wValue, int nValue);                            // 0x004B6980
extern "C" void __cdecl sub_0048A700();                                                                     // 0x0048A700
void __stdcall DATATBLS_AddOrChangeRunesTxtRecord(int nRecordId, D2RunesTxt* pRecord);                      // 0x00639CC0
void __fastcall sub_004D9B20_BeginState(D2UnitStrc* pUnit, int nState);                                    // 0x004D9B20
void __fastcall sub_004D9E60_EndState(D2UnitStrc* pUnit, int nState);                                      // 0x004D9E60
void __fastcall sub_004D9F40_EndClientState(D2UnitStrc* pUnit, int nState);                                // 0x004D9F40
void __fastcall sub_004D9C30_EndState(D2UnitStrc* pUnit, int nState);                                      // 0x004D9C30

// 0x0045E110
void __fastcall sub_0045E110_Packet2C(const D2GSPacketSrv2C* pPacket)
{
    sub_004CBDE0_PlayEventSound(pPacket->dwUnitGUID, pPacket->nUnitType, pPacket->nSoundEvent);
}

// 0x0045E4C0
void __fastcall sub_0045E4C0_Packet59(const D2GSPacketSrv59* pPacket)
{
    sub_00466200_CreatePlayerUnit(pPacket->dwGUID, pPacket->nClass, pPacket->nPosX, pPacket->nPosY, (char*)pPacket->szName);
}

// 0x0045E4E0
void __fastcall sub_0045E4E0_Packet5B(const D2GSPacketSrv5B* pPacket)
{
    const char* szText = pPacket->szText;
    sub_0047A6F0(pPacket->nUnitGUID, pPacket->nClass, pPacket->szName, pPacket->nLevel, pPacket->nPartyId, pPacket->unk0x1C,
                 pPacket->nPartyFlags, pPacket->unk0x20, szText, szText + strlen(szText) + 1);
}

// 0x0045E530
void __fastcall sub_0045E530_Packet5C(const D2GSPacketSrv5C* pPacket)
{
    sub_0047A8B0(pPacket->dwPlayerGUID);
}

// 0x0045E5B0
void __fastcall sub_0045E5B0_Packet92(const D2GSPacketSrv92* pPacket)
{
    const int nUnitGUID = pPacket->nUnitGUID;
    D2UnitStrc* pUnit = sub_00463990(nUnitGUID, pPacket->nUnitType);
    if (pUnit)
    {
        sub_004C23E0(pUnit);
    }
}

// 0x0045E5D0
void __fastcall sub_0045E5D0_Packet5F(const D2GSPacketSrv5F* pPacket)
{
    const int nPortalFlags = pPacket->nPortalFlags;
    D2UnitStrc* pPlayer = sub_00463DE0_GetStoredUnit();
    D2_ASSERT(pPlayer, 3349);
    UNITS_SetPlayerPortalFlags(pPlayer, nPortalFlags);
}

// 0x0045E660
void __fastcall sub_0045E660_Packet61(const D2GSPacketSrv61* pPacket)
{
    sub_004B9320_PlayCinematicFromPacket((const D2CinematicPacketStrc*)pPacket);
    sub_0047F1D0_LoadResolution();
}

// 0x0045E6B0
void __fastcall sub_0045E6B0_Packet65(const D2GSPacketSrv65* pPacket)
{
    sub_00479B10_SetKillCount(pPacket->dwUnitId, pPacket->unk0x05);
}

// 0x0045E7E0
void __fastcall sub_0045E7E0_Packet75(const D2GSPacketSrv75* pPacket)
{
    sub_0047A850_UpdateRosterUnit(pPacket->nUnitGUID, pPacket->nPartyId, pPacket->nLevel, pPacket->nFlags, pPacket->unk0x0B);
}

// 0x0045E850
void __fastcall sub_0045E850_Packet79(const D2GSPacketSrv79* pPacket)
{
    sub_004B90D0(pPacket->dwGold, pPacket->nOwnerGUID);
}

// 0x0045E860
void __fastcall sub_0045E860_Packet7A(const D2GSPacketSrv7A* pPacket)
{
    const int nKey = pPacket->unk0x09;
    if (pPacket->unk0x01)
    {
        sub_00478B10_SetRosterEntry(nKey, pPacket->unk0x05, pPacket->unk0x02, pPacket->unk0x03);
    }
    else
    {
        sub_00478C90(nKey);
    }
}

// 0x0045E8D0
void __fastcall sub_0045E8D0_Packet7B(const D2GSPacketSrv7B* pPacket)
{
    const unsigned short wSkill = pPacket->wSkill;
    const int nHand = wSkill & 0x8000;
    int nSkillId = wSkill & 0xFFF;
    if (nSkillId > sgptDataTables->nSkillsTxtRecordCount)
    {
        nSkillId = -1;
    }
    sub_004AA0C0_SetSlot(pPacket->nSlot, nSkillId, nHand != 0, pPacket->nItemGUID);
}

// 0x0045E970
void __fastcall sub_0045E970_Packet7E(const D2GSPacketSrv7E* pPacket)
{
    sub_0046F310(DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(sub_00463DD0()))));
}

// 0x0045E990
void __fastcall sub_0045E990_Packet7F(const D2GSPacketSrv7F* pPacket)
{
    const int nUnitGUID = pPacket->nUnitGUID;
    const unsigned short nLife = pPacket->nLifePercentage;
    const unsigned short nLevelId = pPacket->nLevelId;
    if (pPacket->bIsPlayer)
    {
        sub_0047A0D0_SetLifeAndLevel(nUnitGUID, nLife, nLevelId);
    }
    else
    {
        sub_00479010_UpdatePetLife(nUnitGUID, nLife, nLevelId);
    }
}

// 0x0045E9C0
void __fastcall sub_0045E9C0_Packet90(const D2GSPacketSrv90* pPacket)
{
    sub_0047A100_SetPosition(pPacket->dwGUID, pPacket->dwPosX, pPacket->dwPosY);
}

// 0x0045EA60
void __fastcall sub_0045EA60_Packet8B(const D2GSPacketSrv8B* pPacket)
{
    sub_0047A350_SetPartyFlags(pPacket->nUnitGUID, pPacket->bParty);
}

// 0x0045EA70
void __fastcall sub_0045EA70_Packet8C(const D2GSPacketSrv8C* pPacket)
{
    sub_0047A370_SetPvpFlags(pPacket->dwPlayerGUID1, pPacket->dwPlayerGUID2, pPacket->nFlags);
}

// 0x0045EA90
void __fastcall sub_0045EA90_Packet8D(const D2GSPacketSrv8D* pPacket)
{
    sub_0047A330_SetPartyId(pPacket->dwPlayerGUID, pPacket->nPartyGUID);
}

// 0x0045EAA0
void __fastcall sub_0045EAA0_Packet8E(const D2GSPacketSrv8E* pPacket)
{
    const int nPlayerGUID = pPacket->dwPlayerGUID;
    const int nCorpseGUID = pPacket->dwCorpseGUID;
    if (pPacket->nType)
    {
        sub_0047A3D0_AddCorpse(nPlayerGUID, nCorpseGUID);
    }
    else
    {
        sub_0047A490_DropCorpseEntry(nPlayerGUID, nCorpseGUID);
    }
}

// 0x0045EAC0
void __fastcall sub_0045EAC0_Packet9B(const D2GSPacketSrv9B* pPacket)
{
    sub_004B6980_SetNpcMenuState(pPacket->unk0x01, pPacket->unk0x03);
}

// 0x0045EAD0
void __fastcall sub_0045EAD0_Packet97(const D2GSPacketSrv97* pPacket)
{
    D2_ASSERT(pPacket->nHeader == 0x97, 3910);
    sub_0048A700();
}

// 0x0045EDC0
void __fastcall sub_0045EDC0_PacketA6(const D2GSPacketSrvA6* pPacket)
{
    if (!pPacket->bSkip)
    {
        DATATBLS_AddOrChangeRunesTxtRecord(pPacket->nRecordId, (D2RunesTxt*)pPacket->pRecord);
    }
}

// 0x0045EDE0
void __fastcall sub_0045EDE0_PacketA7(const D2GSPacketSrvA7* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        const int nState = pPacket->nState;
        sub_004D9B20_BeginState(pUnit, nState);
        sub_004D9E60_EndState(pUnit, nState);
    }
}

// 0x0045EF60
void __fastcall sub_0045EF60_PacketA9(const D2GSPacketSrvA9* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        const int nState = pPacket->nState;
        sub_004D9F40_EndClientState(pUnit, nState);
        sub_004D9C30_EndState(pUnit, nState);
    }
}
