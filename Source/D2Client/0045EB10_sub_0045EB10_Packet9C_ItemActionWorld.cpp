extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

struct D2GSPacketSrv9C
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    int nItemId;
    unsigned char pBitstream[244];
};

struct D2GSPacketSrv9D
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    unsigned char pItemId[4];
    unsigned char nOwnerType;
    unsigned char nUnitId[4];
    unsigned char pBitstream[0xF4];
};

void __fastcall sub_004C20B0(D2GSPacketSrv9C* pPacket);                                                     // 0x004C20B0
void __fastcall sub_004C2340(D2GSPacketSrv9D* pPacket);                                                     // 0x004C2340
void __fastcall sub_004C25B0(D2GSPacketSrv9C* pPacket);                                                     // 0x004C25B0
void __fastcall sub_004C2650(D2GSPacketSrv9C* pPacket);                                                     // 0x004C2650
void __fastcall sub_004C26F0(D2GSPacketSrv9C* pPacket);                                                     // 0x004C26F0
void __fastcall sub_004C2810(D2GSPacketSrv9C* pPacket);                                                     // 0x004C2810
void __fastcall sub_004C2AD0(D2GSPacketSrv9C* pPacket);                                                     // 0x004C2AD0
void __fastcall sub_004C2C80(D2GSPacketSrv9D* pPacket);                                                     // 0x004C2C80
void __fastcall sub_004C2E90(D2GSPacketSrv9D* pPacket);                                                     // 0x004C2E90
void __fastcall sub_004C3070(D2GSPacketSrv9D* pPacket);                                                     // 0x004C3070
void __fastcall sub_004C3380(D2GSPacketSrv9D* pPacket);                                                     // 0x004C3380
void __fastcall sub_004C3920(D2GSPacketSrv9D* pPacket);                                                     // 0x004C3920
void __fastcall sub_004C3B00(D2GSPacketSrv9D* pPacket);                                                     // 0x004C3B00
void __fastcall sub_004C3B30_UpdateItemFromPacket9C(D2GSPacketSrv9C* pPacket);                              // 0x004C3B30
void __fastcall sub_004C3C00(D2GSPacketSrv9C* pPacket);                                                     // 0x004C3C00
void __fastcall sub_004C40D0(D2GSPacketSrv9C* pPacket);                                                     // 0x004C40D0
void __fastcall sub_004C4130(D2GSPacketSrv9C* pPacket);                                                     // 0x004C4130
void __fastcall sub_004C42A0(D2GSPacketSrv9C* pPacket);                                                     // 0x004C42A0
void __fastcall sub_004C45C0(D2GSPacketSrv9C* pPacket);                                                     // 0x004C45C0
void __fastcall sub_004C4740(D2GSPacketSrv9D* pPacket);                                                     // 0x004C4740
void __fastcall sub_004C4990(D2GSPacketSrv9D* pPacket);                                                     // 0x004C4990
void __fastcall sub_004C4AA0(D2GSPacketSrv9D* pPacket);                                                     // 0x004C4AA0
void __fastcall sub_004C4C70(D2GSPacketSrv9D* pPacket);                                                     // 0x004C4C70

// 0x0045EB10
void __fastcall sub_0045EB10_Packet9C_ItemActionWorld(const D2GSPacketSrv9C* pPacket)
{
    D2GSPacketSrv9C tPacket = *pPacket;
    D2GSPacketSrv9C* pCopy = &tPacket;
    switch (pCopy->nAction)
    {
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0x11:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xF6D);
        exit(-1);
    case 0:
        sub_004C25B0(pCopy);
        break;
    case 1:
        sub_004C2650(pCopy);
        break;
    case 2:
        sub_004C26F0(pCopy);
        break;
    case 3:
        sub_004C2810(pCopy);
        break;
    case 4:
        sub_004C2AD0(pCopy);
        break;
    case 0xA:
        sub_004C3B30_UpdateItemFromPacket9C(pCopy);
        break;
    case 0xD:
        sub_004C40D0(pCopy);
        break;
    case 0xE:
        sub_004C4130(pCopy);
        break;
    case 0xF:
        sub_004C42A0(pCopy);
        break;
    case 0x10:
        sub_004C45C0(pCopy);
        break;
    case 0x12:
        sub_004C20B0(pCopy);
        break;
    case 0xB:
    case 0xC:
        sub_004C3C00(pCopy);
        break;
    }
}

// 0x0045EC70
void __fastcall sub_0045EC70_Packet9D_ItemActionOwned(const D2GSPacketSrv9D* pPacket)
{
    D2GSPacketSrv9D tPacket = *pPacket;
    D2GSPacketSrv9D* pCopy = &tPacket;
    switch (pCopy->nAction)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x12:
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xFB7);
        exit(-1);
    case 5:
        sub_004C2C80(pCopy);
        break;
    case 6:
        sub_004C2E90(pCopy);
        break;
    case 7:
        sub_004C3070(pCopy);
        break;
    case 8:
        sub_004C3380(pCopy);
        break;
    case 9:
        sub_004C3920(pCopy);
        break;
    case 0x17:
        sub_004C3B00(pCopy);
        break;
    case 0x11:
        sub_004C4740(pCopy);
        break;
    case 0x13:
        sub_004C4990(pCopy);
        break;
    case 0x14:
        sub_004C4AA0(pCopy);
        break;
    case 0x15:
        sub_004C4C70(pCopy);
        break;
    case 0x16:
        sub_004C2340(pCopy);
        break;
    }
}
