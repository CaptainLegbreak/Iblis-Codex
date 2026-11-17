#pragma pack(push, 1)
struct D2GSPacketSrv09
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char unk0x06;
    unsigned short nPosX;
    unsigned short nPosY;
};

struct D2GSPacketSrv0A
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
};

struct D2GSPacketSrv0B
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
};

struct D2GSPacketSrv51
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned short nObject;
    unsigned short nPosX;
    unsigned short nPosY;
    unsigned char unk0x0C;
    unsigned char nInteractType;
};
#pragma pack(pop)

struct D2UnitStrc
{
    int dwUnitType;
};

void __cdecl sub_0044C880();                                                                                // 0x0044C880
void __cdecl sub_00409B80(int nArg);                                                                        // 0x00409B80
extern int gdwGlobal_007A061C;                                                                              // 0x007A061C
extern int gnValue_007A0624;                                                                                // 0x007A0624
int gdwGlobal_007A0524;                                                                                     // 0x007A0524
extern int gdwGlobal_007A0610;                                                                              // 0x007A0610
extern int gdwGlobal_007A0620;                                                                              // 0x007A0620
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
int __cdecl sub_0044C870();                                                                                 // 0x0044C870
void __fastcall sub_0044E380_SetConnectionError(int nError);                                                // 0x0044E380
D2UnitStrc* __fastcall sub_004661C0_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5); // 0x004661C0
void __fastcall sub_00470B70_ResetMonsterMode(D2UnitStrc* pUnit);                                           // 0x00470B70
D2UnitStrc* __fastcall sub_00466300_CreateObjectUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5, int nArg6, unsigned char nInteractType); // 0x00466300
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny);                  // 0x00478F20
void __fastcall sub_00465EE0_RemoveClientSideUnit(int nUnitId, int nUnitType);                              // 0x00465EE0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_00463D90(int nArg);                                                                     // 0x00463D90
void __cdecl sub_0046F360();                                                                                // 0x0046F360

// 0x0045CA30
void __fastcall sub_0045CA30_GamePacket05_UnloadDone(void* pPacket)
{
    sub_0044C880();
    sub_00409B80(0);
    gdwGlobal_007A061C = 0;
    gnValue_007A0624 = 1;
    gdwGlobal_007A0524 = GetTickCount();
}

// 0x0045CA60
void __fastcall sub_0045CA60_GamePacket06_LogoutDone(void* pPacket)
{
    if (gdwGlobal_007A0610 == 7 || gdwGlobal_007A0610 == 9)
    {
        if (!sub_0044C870())
            sub_0044E380_SetConnectionError(8);
    }
    if ((gdwGlobal_007A0610 == 2 || gdwGlobal_007A0610 == 3) && gdwGlobal_007A061C)
        sub_0044E380_SetConnectionError(7);
    gdwGlobal_007A0620 = 1;
}

// 0x0045CB90
void __fastcall sub_0045CB90_GamePacket09_AssignWarp(D2GSPacketSrv09* pPacket)
{
    const int nUnitGUID = pPacket->dwUnitGUID;
    const unsigned short nX = pPacket->nPosX;
    const unsigned short nY = pPacket->nPosY;
    D2UnitStrc* pUnit = sub_004661C0_AllocClientUnit(nUnitGUID, pPacket->unk0x06, nX, nY, pPacket->nUnitType, 0);
    if (pUnit && pUnit->dwUnitType == 1)
        sub_00470B70_ResetMonsterMode(pUnit);
}

// 0x0045CBD0
void __fastcall sub_0045CBD0_GamePacket51_AssignObject(D2GSPacketSrv51* pPacket)
{
    sub_00466300_CreateObjectUnit(pPacket->dwUnitGUID, pPacket->nObject, pPacket->nPosX, pPacket->nPosY, pPacket->nUnitType, 0, pPacket->unk0x0C, pPacket->nInteractType);
}

// 0x0045CC10
void __fastcall sub_0045CC10_GamePacket0A_RemoveObject(D2GSPacketSrv0A* pPacket)
{
    const int nUnitGUID = pPacket->dwUnitGUID;
    if (pPacket->nUnitType == 1 && nUnitGUID == sub_00478F20_FindPetIdByOwner(sub_00463DD0(), 7, 1))
        return;
    sub_00465EE0_RemoveClientSideUnit(nUnitGUID, pPacket->nUnitType);
}

// 0x0045CC50
void __fastcall sub_0045CC50_GamePacket0B_Handshake(D2GSPacketSrv0B* pPacket)
{
    const int nUnitGUID = pPacket->dwUnitGUID;
    D2UnitStrc* pUnit = sub_00463990(nUnitGUID, pPacket->nUnitType);
    if (pUnit)
        sub_00463D90((int)pUnit);
    sub_0046F360();
}
