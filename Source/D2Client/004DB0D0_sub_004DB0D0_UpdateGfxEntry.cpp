#pragma pack(push, 1)
struct D2GfxCodeRecordStrc
{
    unsigned char nCode;
    unsigned char unk0x01;
    unsigned char nValue;
    unsigned char unk0x03[6];
};

struct D2GfxCodeTableStrc
{
    unsigned char nCount;
    unsigned char unk0x01[0x1B];
    D2GfxCodeRecordStrc f_1C[1];
};
#pragma pack(pop)

// 0x004DB0D0
int __fastcall sub_004DB0D0_UpdateGfxEntry(const unsigned char* pData, int nCode)
{
    int nResult = 0;
    if (pData && nCode < 0x10)
    {
        const D2GfxCodeTableStrc* pTable = (const D2GfxCodeTableStrc*)pData;
        pData += 0x1C;
        for (int i = 0; i < pTable->nCount; ++i)
        {
            if (((const D2GfxCodeRecordStrc*)pData)->nCode == nCode)
            {
                nResult = ((const D2GfxCodeRecordStrc*)pData)->nValue;
                break;
            }
            pData += sizeof(D2GfxCodeRecordStrc);
        }
    }
    return nResult;
}
