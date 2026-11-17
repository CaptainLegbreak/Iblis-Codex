extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2SkillsTxt;

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits);                      // 0x00411020
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __cdecl sub_00477DA0();                                                                   // 0x00477DA0
void __fastcall sub_004A40D0_StorePacket52(void* pPacket);                                                  // 0x004A40D0

// 0x0045C300
unsigned int __fastcall sub_0045C300_ReadVarUnsigned(D2BitBufferStrc* pBuffer)
{
    if (!sub_00411020_ReadBits(pBuffer, 1))
        return sub_00411020_ReadBits(pBuffer, 8);
    if (!sub_00411020_ReadBits(pBuffer, 1))
        return sub_00411020_ReadBits(pBuffer, 0x10);
    return sub_00411020_ReadBits(pBuffer, 0x20);
}

// 0x0045C340
unsigned int __fastcall sub_0045C340_ReadVarUnsigned16(D2BitBufferStrc* pBuffer)
{
    if (!sub_00411020_ReadBits(pBuffer, 1))
        return sub_00411020_ReadBits(pBuffer, 8);
    return sub_00411020_ReadBits(pBuffer, 0x10);
}

// 0x0045C4E0
int __cdecl sub_0045C4E0_GetSkillsTxtRecordCount()
{
    return sgptDataTables->nSkillsTxtRecordCount;
}

// 0x0045C900
void __fastcall sub_0045C900_GamePacketIgnored(void* pPacket)
{
}

// 0x0045C910
void __fastcall sub_0045C910_GamePacket02(void* pPacket)
{
    sub_00477DA0();
}

// 0x0045C920
int __cdecl sub_0045C920_GetPlayerActNo()
{
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (pRoom)
        return DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x527);
    exit(-1);
}

// 0x0045C960
int __fastcall sub_0045C960_GetUnitActNo(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom)
        return DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x538);
    exit(-1);
}

// 0x0045CC00
void __fastcall sub_0045CC00_GamePacket52(void* pPacket)
{
    sub_004A40D0_StorePacket52(pPacket);
}
