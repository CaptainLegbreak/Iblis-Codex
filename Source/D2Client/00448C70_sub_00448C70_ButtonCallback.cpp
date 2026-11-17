struct D2WinControlStrc;
struct D2CompositeUnitStrc;
struct D2ChatMessageStrc { D2WinControlStrc* pControl; unsigned int nMessage; };
struct D2LaunchCharInfoStrc { char pad[0x8D]; char szName[0x30]; };
struct D2ChatChannelMemberStrc
{
    int nUnk0;
    char szName[0x32];
    char szText[0x50];
    unsigned char nClass;
    char pad87[0x15];
    D2CompositeUnitStrc* pComposite;
    int nValueA;
    int unkA4;
    int nValueB;
    int unkAC;
    D2ChatChannelMemberStrc* pNext;
};
extern D2WinControlStrc* gapChatButtons_0077AD78[11]; // 0x0077AD78
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8; // 0x0077BBD8
extern D2ChatChannelMemberStrc* gpChannelUsers_00798F34; // 0x00798F34
extern int gnChannelUserCount_00798F40; // 0x00798F40
extern int gnChannelUserOffset_00798F44; // 0x00798F44
extern D2ChatChannelMemberStrc* gpSelectedChannelUser_00798F48; // 0x00798F48
extern unsigned int gdwSelectionTick_00798F4C; // 0x00798F4C
extern int gnSelectedLine_0070EC1C; // 0x0070EC1C
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount();
extern "C" int __cdecl strcmp(const char*,const char*);
const char* __stdcall SStrChr(const char*,int); // 0x00413490
void __cdecl sub_00443E10(); // 0x00443E10
void __fastcall sub_00445A80_ShowProfileDialog(const char*,int,int); // 0x00445A80
void __fastcall sub_00445C70_ShowUserInfoDialog(const char*,const char*,int,int); // 0x00445C70
void __cdecl sub_00448050_ClearSelectedUser(); // 0x00448050
void __cdecl sub_004477A0_Refresh(); // 0x004477A0
unsigned int __stdcall D2Win_10155(D2CompositeUnitStrc*); // 0x00505330
void __stdcall D2Win_10156(D2CompositeUnitStrc*,int); // 0x00505360
#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText,sub_00408090(),line); exit(-1); }

// 0x00448C70
int __stdcall sub_00448C70_ButtonCallback(D2ChatMessageStrc* pMsg)
{
    int nButton;
    nButton = 0;
    for (;;)
    {
        if (!(nButton < 11))
            break;
        if (pMsg->pControl == gapChatButtons_0077AD78[nButton])
            goto found;
        ++nButton;
    }
    return 0;
found:
    const int nLine = gnChannelUserOffset_00798F44 + nButton;
    if (pMsg->nMessage == 0x205)
    {
        D2ChatChannelMemberStrc* pUser = gpChannelUsers_00798F34;
        for (int n = 0; pUser; ++n, pUser = pUser->pNext)
        {
            if (n == nLine)
            {
                sub_00443E10();
                const char* szName = pUser->szName;
                const char* szCompare = SStrChr(szName, '*');
                if (szCompare && szCompare[1])
                    ++szCompare;
                else
                    szCompare = szName;
                if (!strcmp(szCompare, gpCharInfo_0077BBD8->szName))
                {
                    sub_00445A80_ShowProfileDialog(pUser->szText, pUser->nValueA, pUser->nValueB);
                    return 1;
                }
                sub_00445C70_ShowUserInfoDialog(szName, pUser->szText, pUser->nValueA, pUser->nValueB);
                return 1;
            }
        }
        return 1;
    }
    const unsigned int nTick = GetTickCount();
    if (nLine == gnSelectedLine_0070EC1C)
    {
        sub_00448050_ClearSelectedUser();
        return 1;
    }
    if (nLine < gnChannelUserCount_00798F40)
    {
        sub_00448050_ClearSelectedUser();
        D2ChatChannelMemberStrc* pUser = gpChannelUsers_00798F34;
        for (int n = 0; pUser; ++n, pUser = pUser->pNext)
        {
            if (n == nLine)
            {
                D2_ASSERT(pUser->pComposite,0x135);
                const unsigned int nFlags = D2Win_10155(pUser->pComposite);
                D2Win_10156(pUser->pComposite, gdwBitMasks[10] | nFlags);
                gpSelectedChannelUser_00798F48 = pUser;
                gnSelectedLine_0070EC1C = nLine;
                gdwSelectionTick_00798F4C = nTick;
                sub_004477A0_Refresh();
            }
        }
    }
    return 1;
}
