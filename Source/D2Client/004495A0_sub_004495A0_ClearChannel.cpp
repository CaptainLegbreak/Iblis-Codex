struct D2CompositeStrc;
struct D2WinControlStrc;

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2ChannelEntryStrc
{
    char szName[0x32];
    char szAccount[0x12];
    D2ChannelEntryStrc* pNext;
};

struct T0043E860
{
    int nUnk0x00;
    char szName[0x32];
    char szText[0x50];
    unsigned char nClass;
    char unk0x87[0x15];
    D2CompositeStrc* f_9C;
    char unk0xA0[0x10];
    T0043E860* pNext;
};

struct D2LaunchCharInfoStrc
{
    char unk0x00[0x361];
    char szChannel0x361[0x20];
    char szChannel0x381[0x20];
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall sub_0043E610_AddChatText(Unicode* pText, int nColor);                                        // 0x0043E610
int __fastcall sub_0043E630_ShowChannelText(Unicode* pText);                                                // 0x0043E630
void __stdcall sub_00446A90_RemoveTableString(Unicode* pText);                                              // 0x00446A90
void __cdecl sub_00448050_ClearSelectedUser();                                                              // 0x00448050
void __fastcall sub_00448BD0_UpdateScroll(int nDelta);                                                      // 0x00448BD0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
void __fastcall sub_004F9740_SetControlState(D2WinControlStrc* pControl, int bSet);                         // 0x004F9740
int __stdcall sub_005041B0_Destroy(D2CompositeStrc* pComposite, int nFlag);                                 // 0x005041B0
void __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);              // 0x00526E40
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20

extern D2WinControlStrc* gapChatButtons_0077AD78[];                                                         // 0x0077AD78
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern D2WinControlStrc* gpChatControl_0077BC44;                                                            // 0x0077BC44
char gData_00798D30[256];                                                                                   // 0x00798D30
extern T0043E860* gpChannelUsers_00798F34;                                                          // 0x00798F34
D2ChannelEntryStrc* gpChannelEntries_00798F38;                                                              // 0x00798F38
int gnChannelEntries_00798F3C;                                                                              // 0x00798F3C
extern int gnChannelLines_00798F40;                                                                         // 0x00798F40
extern int gnChannelScroll_00798F44;                                                                        // 0x00798F44

// 0x004495A0
void __cdecl sub_004495A0_ClearChannel()
{
    char szText[0x100];
    sub_00448050_ClearSelectedUser();
    T0043E860* pUser = gpChannelUsers_00798F34;
    while (pUser)
    {
        T0043E860* pNext = pUser->pNext;
        sub_005041B0_Destroy(pUser->f_9C, 1);
        pUser->f_9C = 0;
        FOG_Free(pUser, ".\\Src\\ComCallback.cpp", 0x822, 0);
        pUser = pNext;
    }
    gpChannelUsers_00798F34 = 0;
    D2ChannelEntryStrc* pEntry = gpChannelEntries_00798F38;
    while (pEntry)
    {
        D2ChannelEntryStrc* pNext = pEntry->pNext;
        FOG_Free(pEntry, ".\\Src\\ComCallback.cpp", 0x82A, 0);
        pEntry = pNext;
    }
    gpChannelEntries_00798F38 = 0;
    gnChannelEntries_00798F3C = 0;
    gnChannelLines_00798F40 = 0;
    sprintf(szText, "%s (%d)", gData_00798D30, 0);
    Unicode wszText[0x240];
    sub_00526F20_ToUnicode(wszText, szText, 0x240);
    sub_0043E630_ShowChannelText(wszText);
    gnChannelScroll_00798F44 = 0;
    sub_00448BD0_UpdateScroll(0);
}

// 0x004496B0
int __fastcall sub_004496B0_OnJoinChannel(int nA, int nB, int nC, const char* szChannel)
{
    char szText[500];
    sprintf(szText, "You have joined channel: %s", szChannel);
    Unicode wszText[0x240];
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    sub_00446A90_RemoveTableString(wszText);
    sub_0043E610_AddChatText(wszText, 5);
    strcpy(gData_00798D30, szChannel);
    strcpy(gpCharInfo_0077BBD8->szChannel0x361, gData_00798D30);
    if (!gpCharInfo_0077BBD8->szChannel0x381[0])
    {
        strcpy(gpCharInfo_0077BBD8->szChannel0x381, gData_00798D30);
    }
    for (int i = 0; i < 11; i++)
    {
        sub_004F96F0_ControlClearState(gapChatButtons_0077AD78[i], 1);
    }
    sub_004F9740_SetControlState(gpChatControl_0077BC44, 0);
    sub_004495A0_ClearChannel();
    return 1;
}
