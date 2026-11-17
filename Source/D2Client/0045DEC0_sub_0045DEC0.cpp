struct D2UnitStrc;
#pragma pack(push, 1)
struct D2GSPacketCoordinateStrc
{
#ifdef MOVED_TEST
    unsigned char movedPrefix[4];
#endif
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned short f_6;
    unsigned char unk0x08[2];
    unsigned char nArg3;
    unsigned short wArg4;
    unsigned short wArg5;
    unsigned short wArg6;
};
#pragma pack(pop)
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);  // 0x00463990
int __fastcall sub_004CA230_Forward(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6);
// 0x0045DEC0
void __fastcall sub_0045DEC0(const D2GSPacketCoordinateStrc* pPacket)
{
    D2UnitStrc* pUnit=sub_00463990(pPacket->nUnitId,pPacket->nUnitType);
    if(pUnit)
        sub_004CA230_Forward(pUnit,pPacket->f_6,pPacket->nArg3,pPacket->wArg4,pPacket->wArg5,pPacket->wArg6);
}
