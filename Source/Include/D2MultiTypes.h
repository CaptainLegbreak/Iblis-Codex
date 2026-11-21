#pragma once
// D2Multi: launch character records, the launch function tables and control init records.

#include "D2Check.h"
#include "D2Structs.h"

struct D2FuncRecordStrc;
struct D2LaunchGameListStrc;
struct D2LaunchMsgStrc;
struct D2LaunchPayloadStrc;
struct D2LaunchRecord3Strc;
struct D2MenuListStrc;
struct D2StatusStrc;
struct Unicode;
struct SMSGHANDLER_PARAMS;
struct D2LaunchCharInfoStrc;
struct D2LaunchFuncsStrc;
struct D2WinControlInitStrc;
struct D2LaunchRecordStrc;
struct D2FuncTable_0077ABF0Strc;
struct D2CompositeStrc;
struct D2MultiChannelUserStrc;
struct D2LaunchGameRecStrc;

#pragma pack(push, 1)
struct D2LaunchCharInfoStrc
{
    int unk0x00[6]; // 0x00
    unsigned char unk0x18; // 0x18
    char nState[4]; // 0x19
    char wValue[2]; // 0x1D
    char szText0x1F[24]; // 0x1F
    unsigned char unk0x37; // 0x37
    int unk0x38[21]; // 0x38
    unsigned char unk0x8C; // 0x8C
    char szText0x8D[16]; // 0x8D
    unsigned char unk0x9D; // 0x9D
    unsigned short unk0x9E; // 0x9E
    int unk0xA0[7]; // 0xA0
    unsigned char unk0xBC; // 0xBC
    char szName0xBD[305]; // 0xBD
    unsigned char nValue0x1EE; // 0x1EE
    char wFlags[2]; // 0x1EF
    unsigned char unk0x1F1; // 0x1F1
    unsigned short unk0x1F2; // 0x1F2
    int unk0x1F4[5]; // 0x1F4
    unsigned char unk0x208; // 0x208
    unsigned int dwFlags; // 0x209
    unsigned char unk0x20D; // 0x20D
    unsigned short unk0x20E; // 0x20E
    char nByte210; // 0x210
    unsigned char unk0x211; // 0x211
    unsigned short unk0x212; // 0x212
    int unk0x214[5]; // 0x214
    unsigned char unk0x228; // 0x228
    char nValue0x229[4]; // 0x229
    char nByte22D; // 0x22D
    unsigned short unk0x22E; // 0x22E
    int unk0x230[5]; // 0x230
    unsigned char unk0x244; // 0x244
    char szText0x245[16]; // 0x245
    unsigned char unk0x255; // 0x255
    unsigned short unk0x256; // 0x256
    int unk0x258; // 0x258
    unsigned char unk0x25C; // 0x25C
    char szText0x25D[16]; // 0x25D
    unsigned char unk0x26D; // 0x26D
    unsigned short unk0x26E; // 0x26E
    int unk0x270[59]; // 0x270
    unsigned short unk0x35C; // 0x35C
    char nType0x35E; // 0x35E
    unsigned char unk0x35F; // 0x35F
    unsigned char unk0x360; // 0x360
    char szRealm0x361[32]; // 0x361
    char szRealm0x381[32]; // 0x381
    char szText0x3A1[16]; // 0x3A1
    unsigned char unk0x3B1; // 0x3B1
    unsigned short unk0x3B2; // 0x3B2
    int unk0x3B4[3]; // 0x3B4
    unsigned char unk0x3C0; // 0x3C0
    unsigned char nValue0x3C1; // 0x3C1
    char nValue3C2; // 0x3C2
    unsigned int nWordHash; // 0x3C3
    int nWordLength; // 0x3C7
    unsigned char wFlags0x3CB[2]; // 0x3CB
};
#pragma pack(pop)

struct D2LaunchFuncsStrc
{
    int unk0x00[4]; // 0x00
    void (__fastcall* pfn0x10)(void); // 0x10
    int (__fastcall* pfn0x14)(void*); // 0x14
    const char* (__cdecl* pfnGetUserName)(void); // 0x18
    int (__fastcall* pfn0x1C)(int, int, int); // 0x1C
    const char* (__fastcall* pfn0x20)(int); // 0x20
    int (__fastcall* pfnGetMessage)(int*, D2LaunchMsgStrc*); // 0x24
    int unk0x28[2]; // 0x28
    void (__fastcall* pfn0x30)(void); // 0x30
    int (__fastcall* pfn0x34)(char*, char*, const char*, int); // 0x34
    D2LaunchGameListStrc* (__fastcall* pfQueryGames)(const char*, const char*, int, int); // 0x38
    int (__fastcall* pfn0x3C)(char*, char*); // 0x3C
    int unk0x40; // 0x40
    D2LaunchPayloadStrc* (__fastcall* pfn0x44)(char*, const char*); // 0x44
    int unk0x48[3]; // 0x48
    void (__fastcall* pfn0x54)(char*, char*, int, char*, int); // 0x54
    void (__fastcall* pfn0x58)(void); // 0x58
    int unk0x5C[3]; // 0x5C
    int (__fastcall* pfn0x68)(void); // 0x68
    void (__fastcall* pfn0x6C)(void*, int); // 0x6C
    int unk0x70; // 0x70
    int (__fastcall* pfn0x74)(int, int, void*, D2LaunchRecord3Strc*); // 0x74
    int (__fastcall* pfn0x78)(int, int, int, void*); // 0x78
    int (__fastcall* pfn0x7C)(int, int, void*, D2LaunchRecord3Strc*); // 0x7C
    int unk0x80[3]; // 0x80
    int (__fastcall* pfn0x8C)(int*); // 0x8C
    int unk0x90[5]; // 0x90
    const char* (__fastcall* pfn0xA4)(void*); // 0xA4
    void (__fastcall* pfn0xA8)(void (__fastcall*)(void*, void*), void (__cdecl*)(void)); // 0xA8
    void (__fastcall* pfn0xAC)(void); // 0xAC
};

struct D2WinControlInitStrc
{
    int nType; // 0x00
    int nX; // 0x04
    int nY; // 0x08
    int nWidth; // 0x0C
    int nHeight; // 0x10
    int unk0x14; // 0x14
    int nStringId; // 0x18
    void* ppCellFile; // 0x1C
    int unk0x20[4]; // 0x20
};

#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    int unk0x00[6]; // 0x00
    unsigned char unk0x18; // 0x18
    char aState19[4]; // 0x19
    char aWord1D[2]; // 0x1D
    char nByte1F; // 0x1F
    int unk0x20[5]; // 0x20
    unsigned short unk0x34; // 0x34
    unsigned char unk0x36; // 0x36
    char szName[16]; // 0x37
    unsigned char unk0x47; // 0x47
    int unk0x48[15]; // 0x48
    unsigned char unk0x84; // 0x84
    unsigned char nFlag085; // 0x85
    unsigned char nFlag086; // 0x86
    unsigned char nFlag087; // 0x87
    unsigned char nFlag088; // 0x88
    unsigned char nFlag089; // 0x89
    unsigned char nFlag08A; // 0x8A
    unsigned char nFlag08B; // 0x8B
    unsigned char unk0x8C; // 0x8C
    char szAccount[24]; // 0x8D
    char szPassword[256]; // 0xA5
    unsigned char unk0x1A5; // 0x1A5
    unsigned short unk0x1A6; // 0x1A6
    int unk0x1A8[17]; // 0x1A8
    unsigned short unk0x1EC; // 0x1EC
    char nMode; // 0x1EE
    char aFlags1EF[2]; // 0x1EF
    unsigned char unk0x1F1; // 0x1F1
    unsigned short unk0x1F2; // 0x1F2
    int unk0x1F4[5]; // 0x1F4
    unsigned char unk0x208; // 0x208
    char aState209[4]; // 0x209
    unsigned char unk0x20D; // 0x20D
    unsigned short unk0x20E; // 0x20E
    char nByte210; // 0x210
    unsigned char unk0x211; // 0x211
    unsigned short unk0x212; // 0x212
    int unk0x214[3]; // 0x214
    unsigned short unk0x220; // 0x220
    unsigned char unk0x222; // 0x222
    char bFlag223; // 0x223
    unsigned char unk0x224; // 0x224
    D2FuncTable_0077ABF0Strc* pFuncTable; // 0x225
    unsigned char unk0x229; // 0x229
    unsigned short unk0x22A; // 0x22A
    unsigned char unk0x22C; // 0x22C
    char nByte22D; // 0x22D
    unsigned short unk0x22E; // 0x22E
    int unk0x230[5]; // 0x230
    unsigned char unk0x244; // 0x244
    char nByte245; // 0x245
    unsigned short unk0x246; // 0x246
    int unk0x248[69]; // 0x248
    unsigned char unk0x35C; // 0x35C
    char bRegistryMode; // 0x35D
    char nByte35E; // 0x35E
    char bIntroPlayed; // 0x35F
    unsigned char unk0x360; // 0x360
    char nByte361; // 0x361
    unsigned short unk0x362; // 0x362
    int unk0x364[7]; // 0x364
    unsigned char unk0x380; // 0x380
    char nByte381; // 0x381
    unsigned short unk0x382; // 0x382
    int unk0x384[7]; // 0x384
    unsigned char unk0x3A0; // 0x3A0
    char aData3A1[16]; // 0x3A1
    char aData3B1[16]; // 0x3B1
    char nByte3C1; // 0x3C1
    char nByte3C2; // 0x3C2
    unsigned int dwPasswordHash; // 0x3C3
    int nPasswordLength; // 0x3C7
    char aWord3CB[2]; // 0x3CB
};
#pragma pack(pop)

struct D2FuncTable_0077ABF0Strc
{
    int (__fastcall* pfnInit)(D2LaunchRecordStrc*); // 0x00
    void* (__fastcall* pfnSlot04)(void); // 0x04
    void (__fastcall* pfnSlot08)(char*, char*); // 0x08
    int (__fastcall* pfnSlot0C)(void); // 0x0C
    void (__fastcall* pfnSlot10)(void); // 0x10
    int unk0x14[5]; // 0x14
    int (__fastcall* pfnSlot28)(D2StatusStrc*); // 0x28
    int unk0x2C[5]; // 0x2C
    D2MenuListStrc* (__fastcall* pfnGetMenuList)(int); // 0x40
    D2LaunchPayloadStrc* (__fastcall* pfn0x44)(const char*, const char*); // 0x44
    int (__fastcall* pfnSlot48)(int*); // 0x48
    int (__fastcall* pfnSlot4C)(void); // 0x4C
    int unk0x50[4]; // 0x50
    void (__fastcall* pfnSlot60)(char*, char*); // 0x60
    int (__fastcall* pfnSlot64)(int*); // 0x64
    int (__fastcall* pfnSlot68)(void); // 0x68
    int unk0x6C; // 0x6C
    int (__fastcall* pfnSlot70)(void); // 0x70
    int unk0x74[3]; // 0x74
    void (__fastcall* pfnSlot80)(int*); // 0x80
    int unk0x84[5]; // 0x84
    D2FuncRecordStrc* (__cdecl* pfnGetRecord)(void); // 0x98
    void (__fastcall* pfnSlot9C)(char*, char*, char*); // 0x9C
    int (__fastcall* pfnSlotA0)(int*); // 0xA0
    int unk0xA4[4]; // 0xA4
    int (__fastcall* pfnSlotB4)(void); // 0xB4
    void (__fastcall* pfnSlotB8)(char*); // 0xB8
    int (__fastcall* pfnSlotBC)(char*, char*); // 0xBC
    int (__fastcall* pfnSlotC0)(char*, char*, char*); // 0xC0
};

struct D2MultiChannelUserStrc
{
    unsigned int dwCode; // 0x00
    char szName[50]; // 0x04
    char szText[16]; // 0x36
    char szRealm[32]; // 0x46
    unsigned char aComponents[16]; // 0x66
    unsigned char aColors[16]; // 0x76
    unsigned char nClass; // 0x86
    unsigned char unk0x87; // 0x87
    unsigned short wLevel; // 0x88
    unsigned short wFlags; // 0x8A
    unsigned short wW8C; // 0x8C
    unsigned short unk0x8E; // 0x8E
    unsigned int dwFlags; // 0x90
    unsigned char nB94; // 0x94
    unsigned char nB95; // 0x95
    unsigned char nB96; // 0x96
    char szS97[5]; // 0x97
    D2CompositeStrc* pComposite; // 0x9C
    int bFlagA0; // 0xA0
    int bFlagA4; // 0xA4
    int bFlagA8; // 0xA8
    int bFlagAC; // 0xAC
    D2MultiChannelUserStrc* pNext; // 0xB0
};

struct D2LaunchGameRecStrc
{
    unsigned char unk0x00; // 0x00
    union
    {
        char szName[48]; // 0x01
        struct
        {
            char szShortName[16]; // 0x01
            char szDesc[32]; // 0x11
        };
    };
    char wValue0x31[2]; // 0x31
    char wValue0x33[2]; // 0x33
    unsigned char unk0x35; // 0x35
    unsigned char unk0x36; // 0x36
    char nAddress0x37[4]; // 0x37
};

D2_CHECK_SIZE(D2MultiChannelUserStrc, 0xB4);
D2_CHECK_SIZE(D2LaunchGameRecStrc, 0x3B);
D2_CHECK_SIZE(D2LaunchCharInfoStrc, 0x3CD);
D2_CHECK_SIZE(D2LaunchFuncsStrc, 0xB0);
D2_CHECK_SIZE(D2WinControlInitStrc, 0x30);
D2_CHECK_SIZE(D2LaunchRecordStrc, 0x3CD);
D2_CHECK_SIZE(D2FuncTable_0077ABF0Strc, 0xC4);
