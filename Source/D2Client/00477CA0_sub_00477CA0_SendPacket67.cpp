typedef unsigned int size_t;

struct D2ClientPacket67Strc
{
    unsigned char nHeader;
    char szName[16];
    unsigned char nGameType;
    unsigned char nClass;
    unsigned char nByte13;
    unsigned char nByte14;
    char szCharName[16];
    unsigned char aWord[2];
    unsigned char aFlags[4];
    unsigned char nByte2B;
    unsigned char nByte2C;
    unsigned char f_2D;
};

struct D2ClientCharRecordStrc
{
    char unk0x000[0x207];
    unsigned char aWord207[2];
    unsigned char aFlags209[4];
    unsigned char nByte20D;
    unsigned char nByte20E;
    unsigned char nByte20F;
    unsigned char nKind;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __cdecl sub_0047AA30_HasClassOverride();                                                                // 0x0047AA30
unsigned char __cdecl sub_0047AA20_GetClassOverride();                                                      // 0x0047AA20
int __cdecl sub_00525150();                                                                         // 0x00525150
int __stdcall sub_0052AE50_SendPacket(int nSize, int nFlags, void* pData);                                  // 0x0052AE50

extern int gdwGlobal_007A0610;                                                                              // 0x007A0610
extern unsigned char gbGlobal_007A0522;                                                                     // 0x007A0522
extern D2ClientCharRecordStrc* gpCharRecord_007A0438;                                                       // 0x007A0438
extern char gszCharName_007A05C4[];                                                                         // 0x007A05C4
extern int gnSentBytes_007A6AF8;                                                                            // 0x007A6AF8
extern int gnSentPackets_007A6B00;                                                                          // 0x007A6B00

// 0x00477CA0
void __fastcall sub_00477CA0_SendPacket67(const char* szName)
{
    D2ClientPacket67Strc tPacket;
    tPacket.nHeader = 0x67;
    SStrCopy(tPacket.szName, szName, 0x7FFFFFFF);
    switch (gdwGlobal_007A0610)
    {
    case 0:
        tPacket.nGameType = 3;
        break;
    case 6:
        tPacket.nGameType = 1;
        break;
    case 8:
        tPacket.nGameType = 2;
        break;
    default:
        tPacket.nGameType = 0;
        break;
    }
    if (sub_0047AA30_HasClassOverride())
        tPacket.nClass = sub_0047AA20_GetClassOverride();
    else
        tPacket.nClass = gbGlobal_007A0522;
    tPacket.f_2D = sub_00525150();
    if (!*(int*)gpCharRecord_007A0438->aFlags209)
    {
        *(int*)gpCharRecord_007A0438->aFlags209 = 4;
        *(int*)gpCharRecord_007A0438->aFlags209 |= 0x100000;
    }
    memcpy(tPacket.aWord, gpCharRecord_007A0438->aWord207, sizeof(tPacket.aWord));
    memcpy(tPacket.aFlags, gpCharRecord_007A0438->aFlags209, sizeof(tPacket.aFlags));
    tPacket.nByte13 = gpCharRecord_007A0438->nByte20D;
    tPacket.nByte2B = gpCharRecord_007A0438->nByte20E;
    tPacket.nByte2C = gpCharRecord_007A0438->nByte20F;
    tPacket.nByte14 = gpCharRecord_007A0438->nKind;
    SStrCopy(tPacket.szCharName, gszCharName_007A05C4, 0x7FFFFFFF);
    sub_0052AE50_SendPacket(sizeof(tPacket), 0, &tPacket);
    gnSentBytes_007A6AF8 += sizeof(tPacket);
    gnSentPackets_007A6B00 += 1;
}
