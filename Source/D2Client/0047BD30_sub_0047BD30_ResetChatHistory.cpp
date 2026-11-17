extern int gnChatHistoryHead_00712F44;                                                                      // 0x00712F44
extern int gnChatHistoryTail_00712F48;                                                                      // 0x00712F48
extern int gnChatHistoryCursor_007BB5D8;                                                                    // 0x007BB5D8
extern unsigned short gwChatHistoryCount_007BB5E4;                                                          // 0x007BB5E4
extern int gnChatCaret_007BB5E8;                                                                            // 0x007BB5E8

// 0x0047BD30
void __cdecl sub_0047BD30_ResetChatHistory()
{
    gnChatHistoryHead_00712F44 = 7;
    gnChatHistoryTail_00712F48 = 7;
    gnChatHistoryCursor_007BB5D8 = 0;
    gwChatHistoryCount_007BB5E4 = 0;
    gnChatCaret_007BB5E8 = 0;
}
