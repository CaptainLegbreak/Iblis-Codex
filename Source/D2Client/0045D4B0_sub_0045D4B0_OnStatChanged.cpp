extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#pragma pack(push, 1)
struct D2PacketRecord11Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    int nUnitId;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
};

struct D2UnitStatPacketStrc
{
    unsigned char nHeader;
    unsigned char nStat;
    int nUnitId;
    union
    {
        unsigned char nByte;
        unsigned short nWord;
        unsigned int nDword;
    };
};

struct D2PlayerStatPacketStrc
{
    unsigned char nHeader;
    union
    {
        unsigned char nByte;
        unsigned short nWord;
        unsigned int nDword;
        struct
        {
            unsigned char nStat;
            union
            {
                unsigned char nByte2;
                unsigned short nWord2;
                unsigned int nDword2;
            };
        };
    };
};

struct D2UnitStatPacket2Strc
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char nStat;
    int nValue;
};
#pragma pack(pop)

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
};

void __fastcall sub_004C1BC0(D2PacketRecord11Strc* pPacket, int nArg);                                      // 0x004C1BC0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
void __fastcall sub_00480E70_SetState(D2UnitStrc* pUnit, int nArg);                                        // 0x00480E70
void __fastcall sub_004647D0(D2UnitStrc* pUnit);                                                            // 0x004647D0
void __fastcall sub_0045D3E0(D2UnitStrc* pUnit);                                                            // 0x0045D3E0
void __fastcall sub_004C1C10(D2UnitStrc* pUnit);                                                            // 0x004C1C10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

static void sub_0045D3B0_SendUnitStatus(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        D2PacketRecord11Strc tPacket;
        tPacket.nHeader = 0x47;
        tPacket.nUnitType = (unsigned char)pUnit->dwUnitType;
        tPacket.nUnitId = pUnit->dwUnitId;
        sub_004C1BC0(&tPacket, 0);
    }
}

// 0x0045D4B0
static void __stdcall sub_0045D4B0_OnStatChanged(int nValue, int nStat, D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    switch (nStat)
    {
    case 6:
        if (nValue && pUnit->dwAnimMode == 0x11)
        {
            sub_00480E70_SetState(pUnit, 5);
            sub_004647D0(pUnit);
        }
        break;

    case 0xC:
        sub_0045D3B0_SendUnitStatus(sub_00463DD0());
        if (pUnit != sub_00463DD0())
            break;
        sub_0045D3E0(pUnit);

    case 0:
    case 2:
        sub_004C1C10(pUnit);
        break;
    }
}

void __fastcall sub_0045D540_HandleUnitStatPacket(D2UnitStatPacketStrc* pPacket)
{
    int bAdd = 0;
    int nValue;
    switch (pPacket->nHeader)
    {
    case 0x9E:
        nValue = pPacket->nByte;
        break;
    case 0xA0:
        nValue = pPacket->nDword;
        break;
    case 0xA1:
        nValue = pPacket->nByte;
        bAdd = 1;
        break;
    case 0xA2:
        bAdd = 1;

    case 0x9F:
        nValue = pPacket->nWord;
        break;
    default:
        return;
    }

    const int nStat = pPacket->nStat;
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, 1);
    if (!pUnit)
        return;

    if (nStat == 0xC)
        sub_0045D3B0_SendUnitStatus(pUnit);

    if (bAdd)
        STATLIST_AddUnitStat(pUnit, nStat, nValue, 0);
    else
        STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

// 0x0045D780
void __fastcall sub_0045D780_HandlePlayerStatPacket(D2PlayerStatPacketStrc* pPacket)
{
    const unsigned char nHeader = pPacket->nHeader;
    int nValue = 0;
    int nStat = -1;
    D2UnitStrc* pPlayer = sub_00463DE0_GetStoredUnit();
    D2_ASSERT(pPlayer, 0x9AA);

    switch (nHeader)
    {
    case 0x19:
        nStat = 0xE;
        nValue = STATLIST_UnitGetStatValue(pPlayer, nStat, 0) + pPacket->nByte;
        break;
    case 0x1A:
        nStat = 0xD;
        nValue = STATLIST_UnitGetStatValue(pPlayer, nStat, 0) + pPacket->nByte;
        break;
    case 0x1B:
        nStat = 0xD;
        nValue = STATLIST_UnitGetStatValue(pPlayer, nStat, 0) + pPacket->nWord;
        break;
    case 0x1C:
        nValue = pPacket->nDword;
        nStat = 0xD;
        break;
    case 0x1D:
        nValue = pPacket->nByte2;
        nStat = pPacket->nStat;
        break;
    case 0x1E:
        nValue = pPacket->nWord2;
        nStat = pPacket->nStat;
        break;
    case 0x1F:
        nValue = pPacket->nDword2;
        nStat = pPacket->nStat;
        break;
    }

    STATLIST_SetUnitStat(pPlayer, nStat, nValue, 0);
    sub_0045D4B0_OnStatChanged(nValue, nStat, pPlayer);
}

// 0x0045D880
void __fastcall sub_0045D880_HandleUnitStatPacket2(D2UnitStatPacket2Strc* pPacket)
{
    const int nValue = pPacket->nValue;
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, 0);
    if (pUnit)
    {
        const int nStat = pPacket->nStat;
        STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
        sub_0045D4B0_OnStatChanged(nValue, nStat, pUnit);
    }
}
