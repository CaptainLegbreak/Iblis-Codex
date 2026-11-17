extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc;
struct D2SkillStrc;

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xBC0 - 0xA84];
    int nOverlayTxtRecordCount;
};

#pragma pack(push, 1)
struct D2GSPacketSrv11
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned short wOverlay;
};

struct D2GSPacketSrv28
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nArg;
    unsigned char pBuffer[1];
};

struct D2GSPacketSrv62
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
};

struct D2GSPacketSrvA4
{
    unsigned char nHeader;
    unsigned short wMonsterId;
};

struct D2GSPacketSrv21
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char bRemove;
    int nUnitId;
    unsigned short wSkillId;
    unsigned char nSkillLevel;
};

struct D2SkillLevelEntryStrc
{
    unsigned short wSkillId;
    unsigned char nSkillLevel;
};

struct D2GSPacketSrv94
{
    unsigned char nHeader;
    unsigned char nCount;
    int nUnitId;
    D2SkillLevelEntryStrc pEntries[1];
};

struct D2GSPacketSrv22
{
    unsigned char nHeader;
    unsigned char unk0x01[2];
    int nUnitId;
    unsigned short wSkillId;
    unsigned char nQuantity;
    unsigned char unk0x0A;
    unsigned char bSkip;
};

struct D2GSPacketSrv23
{
    unsigned char nHeader;
    unsigned char unk0x01;
    int nUnitId;
    unsigned char bLeft;
    unsigned short wSkillId;
    int nOwnerGUID;
};

struct D2GSPacketSrv99
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned short f_6;
    unsigned char nArg3;
    unsigned char nTargetType;
    int f_A;
    unsigned short wArg5;
};
#pragma pack(pop)

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_00464E50(D2UnitStrc* pUnit, int nOverlay, int nArg);                                    // 0x00464E50
void __fastcall sub_004B6DD0_NpcInteractPacket(unsigned char nUnitType, int nUnitId, unsigned char* pBuffer, unsigned char nArg); // 0x004B6DD0
void __fastcall sub_004B5320(unsigned char nUnitType, int nUnitId);                                         // 0x004B5320
void __fastcall sub_004B2620(const unsigned char* pData);                                                   // 0x004B2620
void __fastcall sub_0046F870_LoadMonsterCofs(int nMonsterId, int bLoadNow);                                 // 0x0046F870
D2SkillStrc* __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
extern "C" void __cdecl sub_004AA8F0_ClearValue7C0C3C();                                                    // 0x004AA8F0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);               // 0x006439B0
void __stdcall SKILLS_SetQuantity(D2SkillStrc* pSkill, int nQuantity);                                      // 0x00645120
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                  // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                 // 0x00643C50
int __fastcall sub_004CA200_Forward(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5);               // 0x004CA200

// 0x0045D0F0
void __fastcall sub_0045D0F0_Packet11(const D2GSPacketSrv11* pPacket)
{
    const int nUnitType = pPacket->nUnitType;
    const int nUnitId = pPacket->nUnitId;
    const unsigned short wOverlay = pPacket->wOverlay;
    D2UnitStrc* pUnit = sub_00463990(nUnitId, nUnitType);
    if (pUnit && wOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        sub_00464E50(pUnit, wOverlay, 0);
    }
}

// 0x0045D370
void __fastcall sub_0045D370_Packet28(const D2GSPacketSrv28* pPacket)
{
    sub_004B6DD0_NpcInteractPacket(pPacket->nUnitType, pPacket->nUnitId, (unsigned char*)pPacket->pBuffer, pPacket->nArg);
}

// 0x0045D390
void __fastcall sub_0045D390_Packet62(const D2GSPacketSrv62* pPacket)
{
    sub_004B5320(pPacket->nUnitType, pPacket->nUnitId);
}

// 0x0045D3A0
void __fastcall sub_0045D3A0_Packet29(const unsigned char* pPacket)
{
    sub_004B2620(pPacket + 1);
}

// 0x0045D760
void __fastcall sub_0045D760_PacketA4(const D2GSPacketSrvA4* pPacket)
{
    const unsigned short wMonsterId = pPacket->wMonsterId;
    if (wMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        sub_0046F870_LoadMonsterCofs(wMonsterId, 0);
    }
}

// 0x0045DCD0
void __fastcall sub_0045DCD0_Packet21_AssignSkill(const D2GSPacketSrv21* pPacket)
{
    const unsigned short wSkillId = pPacket->wSkillId;
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        SKILLS_AssignSkill(pUnit, wSkillId, pPacket->nSkillLevel, pPacket->bRemove, ".\\GAME\\SCmd.cpp", 2700);
        sub_004AA8F0_ClearValue7C0C3C();
    }
}

// 0x0045DD60
void __fastcall sub_0045DD60_Packet94_AssignSkills(const D2GSPacketSrv94* pPacket)
{
    const int nUnitId = pPacket->nUnitId;
    const unsigned char nCount = pPacket->nCount;
    const D2SkillLevelEntryStrc* pEntry = pPacket->pEntries;
    D2UnitStrc* pUnit = sub_00463990(nUnitId, 0);
    if (pUnit)
    {
        for (int i = 0; i < nCount; ++i)
        {
            SKILLS_AssignSkill(pUnit, pEntry->wSkillId, pEntry->nSkillLevel, 0, ".\\GAME\\SCmd.cpp", 2743);
            ++pEntry;
        }
    }
}

// 0x0045DDB0
void __fastcall sub_0045DDB0_Packet22_SetSkillQuantity(const D2GSPacketSrv22* pPacket)
{
    if (pPacket->bSkip)
    {
        return;
    }
    const unsigned short wSkillId = pPacket->wSkillId;
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, 0);
    if (pUnit)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, wSkillId, -1);
        D2_ASSERT(pSkill, 2774);
        SKILLS_SetQuantity(pSkill, pPacket->nQuantity);
    }
}

// 0x0045DE10
void __fastcall sub_0045DE10_Packet23_SetActiveSkill(const D2GSPacketSrv23* pPacket)
{
    const unsigned short wSkillId = pPacket->wSkillId;
    const int nOwnerGUID = pPacket->nOwnerGUID;
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, 0);
    if (pUnit)
    {
        if (pPacket->bLeft)
        {
            SKILLS_SetLeftActiveSkill(pUnit, wSkillId, nOwnerGUID);
        }
        else
        {
            SKILLS_SetRightActiveSkill(pUnit, wSkillId, nOwnerGUID);
        }
    }
}

// 0x0045DE80
void __fastcall sub_0045DE80_Packet99(const D2GSPacketSrv99* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        D2UnitStrc* pTarget = sub_00463990(pPacket->f_A, pPacket->nTargetType);
        if (pTarget)
        {
            sub_004CA200_Forward(pUnit, pPacket->f_6, pPacket->nArg3, (int)pTarget, pPacket->wArg5);
        }
    }
}
