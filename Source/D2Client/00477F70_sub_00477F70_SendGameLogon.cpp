struct D2ClientInterfaceStrc
{
    char unk0x00[0x5C];
    int (__cdecl* pfnGetVersion)();
};

struct D2GameLogonPacketStrc
{
    unsigned char nHeader;
    unsigned char nServerHash[4];
    unsigned char f_5[2];
    unsigned char nClass;
    unsigned char nVersion[4];
    unsigned char nKey1[4];
    unsigned char nKey2[4];
    unsigned char f_14;
    char szName[16];
};

D2ClientInterfaceStrc* __cdecl sub_0044D540_GetClientInterface();                                           // 0x0044D540
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
unsigned char __cdecl sub_00525150();                                                               // 0x00525150
int __cdecl sub_0047AA30_HasClassOverride();                                                                // 0x0047AA30
unsigned char __cdecl sub_0047AA20_GetClassOverride();                                                      // 0x0047AA20
extern unsigned char gnCharClass_007A0522;                                                                  // 0x007A0522
extern char gszCharName_007A05C4[];                                                                         // 0x007A05C4
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __stdcall sub_0052AE50_SendPacket(int nSize, int nFlags, void* pData);                                  // 0x0052AE50
extern int gnSentBytes_007A6AF8;                                                                            // 0x007A6AF8
extern int gnSentPackets_007A6B00;                                                                          // 0x007A6B00

// 0x00477F70
void __fastcall sub_00477F70_SendGameLogon(int nServerToken, int nServerHash)
{
    D2GameLogonPacketStrc tPacket;
    tPacket.nHeader = 0x68;
    *(int*)tPacket.nServerHash = nServerHash;
    *(short*)tPacket.f_5 = (short)nServerToken;
    *(int*)tPacket.nVersion = sub_0044D540_GetClientInterface()->pfnGetVersion();
    *(unsigned int*)tPacket.nKey1 = sub_00408F20_HasExpansionMpq() ? 0xED5DCC50 : 0x2185EDD6;
    *(unsigned int*)tPacket.nKey2 = 0x91A519B6;
    tPacket.f_14 = sub_00525150();
    tPacket.nClass = sub_0047AA30_HasClassOverride() ? sub_0047AA20_GetClassOverride() : gnCharClass_007A0522;
    SStrCopy(tPacket.szName, gszCharName_007A05C4, 0x7FFFFFFF);
    sub_0052AE50_SendPacket(sizeof(D2GameLogonPacketStrc), 0, &tPacket);
    gnSentBytes_007A6AF8 += sizeof(D2GameLogonPacketStrc);
    gnSentPackets_007A6B00 += 1;
}
