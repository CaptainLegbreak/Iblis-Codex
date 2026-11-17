struct Unicode
{
    unsigned short wChar;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
unsigned short gwChatHistoryCount_007BB5E4;                                                                 // 0x007BB5E4
extern int gnChatHistoryHead_00712F44;                                                                      // 0x00712F44
extern int gnChatHistoryTail_00712F48;                                                                      // 0x00712F48
extern int gnChatHistoryCursor_007BB5D8;                                                                    // 0x007BB5D8
extern Unicode gawszChatHistory_007BB840[8][257];                                                           // 0x007BB840
extern Unicode gwszChatLine_007BB638[];                                                                     // 0x007BB638

// 0x0047BA00
static void sub_0047BA00_PushChatHistory(const Unicode* pText)
{
    int nIndex;
    if (gwChatHistoryCount_007BB5E4 != 8)
    {
        if (gwChatHistoryCount_007BB5E4)
        {
            if (--gnChatHistoryHead_00712F44 < 0)
                gnChatHistoryHead_00712F44 = 7;
        }
        nIndex = gnChatHistoryHead_00712F44;
        ++gwChatHistoryCount_007BB5E4;
    }
    else
    {
        nIndex = gnChatHistoryTail_00712F48;
        gnChatHistoryHead_00712F44 = nIndex;
        if (--gnChatHistoryTail_00712F48 < 0)
            gnChatHistoryTail_00712F48 = 7;
    }
    gnChatHistoryCursor_007BB5D8 = nIndex;
    memcpy(gawszChatHistory_007BB840[nIndex], pText, sizeof(gawszChatHistory_007BB840[0]));
}

void sub_A23_Emit_0047BA00(int nSkip)
{
    const Unicode* pText = &gwszChatLine_007BB638[nSkip];
    if (sub_00526800(pText))
        sub_0047BA00_PushChatHistory(pText);
}

#include "gen/data/Source/D2Client/0047BA00_sub_0047BA00_PushChatHistory.inc"
