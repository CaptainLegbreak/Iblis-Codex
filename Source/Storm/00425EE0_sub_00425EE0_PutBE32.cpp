// 0x00425EE0
void __fastcall sub_00425EE0_PutBE32(unsigned int nValue, unsigned char* pOut)
{
    pOut[3] = (unsigned char)nValue; nValue >>= 8;
    pOut[2] = (unsigned char)nValue; nValue >>= 8;
    pOut[1] = (unsigned char)nValue; nValue >>= 8;
    pOut[0] = (unsigned char)nValue;
}
