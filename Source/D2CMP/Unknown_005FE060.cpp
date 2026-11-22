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

extern "C" int __cdecl BNDOWNLOAD_HasPendingDownloads(); // 0x0051E5E0

extern "C" int __cdecl BNDOWNLOAD_SetDisconnected(); // 0x00520AD0

extern "C" void __fastcall BNDOWNLOAD_ClearReply(unsigned char nSlot); // 0x00520C00

extern "C" int __fastcall BNDOWNLOAD_GetReplyValue(unsigned char nSlot); // 0x00520C20

extern "C" int __fastcall GRID_GetCDKey(int bSecond); // 0x00523AB0

// 0x005FE060
extern "C" void __cdecl D2CMPResetTileCacheHits()
{
    gnValue_0088CB10 = 0;
    gnValue_0088CB0C = 0;
}
