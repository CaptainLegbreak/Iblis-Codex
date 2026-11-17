struct D2CinematicPacketStrc
{
    unsigned char nHeader;
    unsigned char nCinematic;
};

void __fastcall sub_00482EF0_PlayCinematic(int nIndex);                                                      // 0x00482EF0

// 0x004B9320
void __fastcall sub_004B9320_PlayCinematicFromPacket(const D2CinematicPacketStrc* pPacket)
{
    sub_00482EF0_PlayCinematic(pPacket->nCinematic);
}
