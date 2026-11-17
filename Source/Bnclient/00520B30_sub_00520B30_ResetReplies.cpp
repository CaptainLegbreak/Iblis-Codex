int __fastcall sub_00520520_SetState(int nState);                                                           // 0x00520520

extern int gdwGlobal_0072FFA8;                                                                              // 0x0072FFA8
extern "C" int gnSlotArrayA_00882128[94];                                                                   // 0x00882128
extern "C" int gnSlotArrayB_008822A8[94];                                                                   // 0x008822A8
extern "C" int gnFlag_00882528;                                                                             // 0x00882528

// 0x00520B30
int __cdecl sub_00520B30_ResetReplies()
{
    for (int i = 0; i < 94; ++i)
        gnSlotArrayB_008822A8[i] = 0;
    for (int i = 0; i < 94; ++i)
        gnSlotArrayA_00882128[i] = 0;
    gdwGlobal_0072FFA8 = 0xFF;
    gnFlag_00882528 = 0;
    sub_00520520_SetState(0);
    return 1;
}

// 0x00520BF0
int __fastcall sub_00520BF0_IsReplyReceived(unsigned char nReply)
{
    return gnSlotArrayA_00882128[nReply];
}
