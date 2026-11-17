#pragma pack(push, 1)
struct D2ClientInfoStrc
{
    char unk0x00[0x1EF];
    unsigned short wFlags;
};
#pragma pack(pop)

extern D2ClientInfoStrc* gpClientInfo_007A0438;                                                             // 0x007A0438
extern unsigned char gnDifficulty_007A060C;                                                                 // 0x007A060C
static int gdwGlobal_007A0604;                                                                              // 0x007A0604

// 0x0044EC80
void __cdecl sub_0044EC80_SetDifficultyFlags()
{
    gdwGlobal_007A0604 = 1;
    gpClientInfo_007A0438->wFlags = ((gnDifficulty_007A060C + 1) << 10) | (gpClientInfo_007A0438->wFlags & 0xE0FF);
}
