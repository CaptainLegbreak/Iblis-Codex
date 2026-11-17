typedef char check_int_width[(sizeof(int) == 4) ? 1 : -1];
typedef char check_long_width[(sizeof(long) == 4) ? 1 : -1];
typedef char check_uchar_width[(sizeof(unsigned char) == 1) ? 1 : -1];

extern "C" long gnPendingCount_00881D5C;
extern "C" int gnFlag_00882528;
extern "C" int gnSlotArrayA_00882128[94];
extern "C" int gnSlotArrayB_008822A8[94];
extern "C" int gnValue_00882744;
extern "C" int gnValue_0088274C;
extern "C" int gnValue_0088CB0C; // 0x0088CB0C
extern "C" int gnValue_0088CB10; // 0x0088CB10

// build: context sub_0051E5E0_IsPendingCountPositive
extern "C" int __cdecl sub_0051E5E0_IsPendingCountPositive()
{
    return gnPendingCount_00881D5C > 0;
}

// build: context sub_00520AD0_SetFlag882528
extern "C" int __cdecl sub_00520AD0_SetFlag882528()
{
    return gnFlag_00882528 = 1;
}

// build: context sub_00520C00_ClearSlotPair
extern "C" void __fastcall sub_00520C00_ClearSlotPair(unsigned char nSlot)
{
    gnSlotArrayA_00882128[nSlot] = 0;
    gnSlotArrayB_008822A8[nSlot] = 0;
}

// build: context sub_00520C20_GetSlotB
extern "C" int __fastcall sub_00520C20_GetSlotB(unsigned char nSlot)
{
    return gnSlotArrayB_008822A8[nSlot];
}

// build: context sub_00523AB0_SelectValue
extern "C" int __fastcall sub_00523AB0_SelectValue(int bSecond)
{
    return bSecond ? gnValue_0088274C : gnValue_00882744;
}

// 0x005FE060
extern "C" void __cdecl sub_005FE060_ClearPair88CB10()
{
    gnValue_0088CB10 = 0;
    gnValue_0088CB0C = 0;
}
