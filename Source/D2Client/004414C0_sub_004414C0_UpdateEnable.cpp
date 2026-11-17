#pragma pack(push, 1)
struct D2LaunchCharInfoStrc
{
    char unk0x000[0x1EF];
    unsigned short wFlags1EF;
    char unk0x1F1[0x22D - 0x1F1];
    unsigned char nByte22D;
};
#pragma pack(pop)

extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
int __cdecl sub_00449B30_QueryAddress();                                                                    // 0x00449B30
void __stdcall sub_004413E0_Enable(int bEnable);                                                            // 0x004413E0

// 0x004414C0
void __cdecl sub_004414C0_UpdateEnable()
{
    if ((gpCharInfo_0077BBD8->wFlags1EF & 8) && (gpCharInfo_0077BBD8->wFlags1EF & 4))
    {
        return;
    }

    int bEnable = 0;
    if (gpCharInfo_0077BBD8->nByte22D && !sub_00449B30_QueryAddress())
    {
        bEnable = 1;
    }

    sub_004413E0_Enable(bEnable);
}
