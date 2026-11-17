// 0x0045D8C0
static __declspec(noinline) void __stdcall sub_0045D8C0_AddSignedByteOffsets(short nBaseY, short* pX, short* pY, short nBaseX, unsigned char nDY, unsigned char nDX)
{
    int nOffsetX = nDX;
    int nOffsetY = nDY;
    if (nOffsetX > 0x80)
        nOffsetX -= 0x100;

    if (nOffsetY > 0x80)
        nOffsetY -= 0x100;

    *pX = nBaseX + nOffsetX;
    *pY = nBaseY + nOffsetY;
}

void __fastcall sub_U05_Emit_0045D8C0(unsigned char* pBytes, short* pBase, short* pOut)
{
    sub_0045D8C0_AddSignedByteOffsets(pBase[1], &pOut[0], &pOut[1], pBase[0], pBytes[1], pBytes[0]);
    sub_0045D8C0_AddSignedByteOffsets(pBase[3], &pOut[2], &pOut[3], pBase[2], pBytes[3], pBytes[2]);
}
