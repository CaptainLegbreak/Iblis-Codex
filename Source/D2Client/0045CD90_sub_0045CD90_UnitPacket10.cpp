struct D2UnitStrc;

struct D2GSPacketSrv10
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char nFlags;
    unsigned char nTargetType;
    unsigned char dwTargetGUID[4];
    unsigned char nCurrentPosX[2];
    unsigned char nCurrentPosY[2];
};

void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC); // 0x004804E0
int __fastcall sub_00480C10_UnitEvent(int nEvent, D2UnitStrc* pUnit, int* pArgs, int nFlag);                // 0x00480C10

// 0x0045CD90
void __fastcall sub_0045CD90_UnitPacket10(D2UnitStrc* pUnit, const D2GSPacketSrv10* pPacket)
{
    int args[7];
    args[0] = pPacket->nTargetType;
    args[1] = *(const int*)pPacket->dwTargetGUID;
    sub_004804E0_SetPosition(pUnit, *(const unsigned short*)pPacket->nCurrentPosX, *(const unsigned short*)pPacket->nCurrentPosY, 0, 0, 0);
    sub_00480C10_UnitEvent(pPacket->nFlags, pUnit, args, 1);
}
