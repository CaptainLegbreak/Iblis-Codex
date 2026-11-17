struct D2CelFileStrc;

struct D2CharStrc
{
    unsigned short wChar;
    unsigned char unk0x02;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned char unk0x05;
    unsigned short unk0x06;
    unsigned short nImageIndex;
    unsigned short unk0x0A[2];
};

struct D2FontStrc;

struct D2FontCacheStrc
{
    D2CelFileStrc* pCellFile;
    D2FontStrc* pFontInfo[2];
    D2CharStrc* pCharInfo;
    unsigned int dwShiftedTickCount;
};

extern int gnCurrentFont_0072DFFC;                                                                          // 0x0072DFFC
extern D2FontCacheStrc gFontCache_00841DA8[];                                                               // 0x00841DA8

// 0x00501650
D2CharStrc* __fastcall sub_6F8AA100(unsigned short wChar)
{
    if (wChar > 0xFF)
    {
        return gFontCache_00841DA8[gnCurrentFont_0072DFFC].pCharInfo;
    }

    return &gFontCache_00841DA8[gnCurrentFont_0072DFFC].pCharInfo[wChar];
}
