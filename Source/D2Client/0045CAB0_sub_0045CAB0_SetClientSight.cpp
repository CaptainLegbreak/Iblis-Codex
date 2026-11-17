#pragma pack(push, 1)
struct D2ClientSightPacketStrc
{
    unsigned char unk0x00;
    unsigned short nX;
    unsigned short nY;
    unsigned char nLevelId;
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText_006CC837; // 0x006CC837
extern "C" void* gpAct_007A0634; // 0x007A0634
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl sub_00463DD0(); // 0x00463DD0
extern "C" void* __stdcall UNITS_GetRoom(void* pUnit); // 0x00620BB0
extern "C" void __stdcall DUNGEON_SetClientIsInSight(void* pAct, int nLevelId, int nX, int nY, void* pRoom); // 0x0061A070

// 0x0045CAB0
void __fastcall sub_0045CAB0_SetClientSight(D2ClientSightPacketStrc* pPacket)
{
    unsigned short nX = pPacket->nX;
    unsigned short nY = pPacket->nY;
    if (!gpAct_007A0634)
    {
        sub_00408A60(&gszEmptyAssertText_006CC837, sub_00408090(), 0x58A);
        exit(-1);
    }
    void* pPlayer = sub_00463DD0();
    void* pRoom = pPlayer ? UNITS_GetRoom(pPlayer) : 0;
    DUNGEON_SetClientIsInSight(gpAct_007A0634, pPacket->nLevelId, nX, nY, pRoom);
}
