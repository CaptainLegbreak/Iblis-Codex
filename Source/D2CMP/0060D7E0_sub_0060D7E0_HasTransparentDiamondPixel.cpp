struct D2CmpSubTileRecordStrc
{
    int unk0x00;
    int unk0x04;
    short unk0x08;
    unsigned short nLength;
    int unk0x0C;
    unsigned char* pData;
};

void __stdcall sub_M92_EmitSinkA(D2CmpSubTileRecordStrc* pRecord);
void __stdcall sub_M92_EmitSinkB(unsigned char* pData, D2CmpSubTileRecordStrc* pRecord);

// 0x0060D7E0
static __declspec(noinline) int sub_0060D7E0_HasTransparentDiamondPixel(const unsigned char* pData)
{
    int y = 0;
    int nOffset = 14;
    int nWidth = 4;
    for (; y < 15; ++y)
    {
        for (int x = 0; x < nWidth; ++x)
        {
            if (pData[nOffset + x] == 0)
            {
                return 1;
            }
        }

        pData += 32;
        if (y < 7)
        {
            nOffset -= 2;
            nWidth += 4;
        }
        else
        {
            nOffset += 2;
            nWidth -= 4;
        }
    }

    return 0;
}

void __fastcall sub_M92_Emit_0060D7E0(D2CmpSubTileRecordStrc* pRecord)
{
    unsigned char* pData = pRecord->pData;
    if (sub_0060D7E0_HasTransparentDiamondPixel(pData))
    {
        sub_M92_EmitSinkA(pRecord);
    }
    else
    {
        sub_M92_EmitSinkB(pData, pRecord);
    }
}
