struct D2CompositeStrc;

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
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

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" char* __cdecl strchr(const char* szString, int nChar);                                           // 0x00687740
extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" int __cdecl strcmp(const char* szA, const char* szB);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall sub_0043E610_AddChatText(Unicode* pText, int nColor);                                        // 0x0043E610
int __fastcall sub_0043E630_ShowChannelText(Unicode* pText);                                                // 0x0043E630
void __stdcall sub_00446A90_RemoveTableString(Unicode* pText);                                              // 0x00446A90
void __cdecl sub_00447BB0_Refresh();                                                                        // 0x00447BB0
void __cdecl sub_00448050_ClearSelectedUser();                                                              // 0x00448050
void __fastcall sub_00448BD0_UpdateScroll(int nDelta);                                                      // 0x00448BD0
T0043E860* __stdcall sub_00449050_AddEntry(const char* szText, int nLength, int nA);                // 0x00449050
int __stdcall sub_005041B0_Destroy(D2CompositeStrc* pComposite, int nFlag);                                 // 0x005041B0
void __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);              // 0x00526E40
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20

int gbShowJoinLeave_0077BD54;                                                                               // 0x0077BD54
extern char gData_00798D30[];                                                                               // 0x00798D30
extern T0043E860* gpChannelUsers_00798F34;                                                          // 0x00798F34
extern int gnChannelLines_00798F40;                                                                         // 0x00798F40
extern T0043E860* gpSelectedChannelUser_00798F48;                                                   // 0x00798F48

// 0x00447AB0
static __declspec(noinline) int __stdcall sub_00447AB0_AddChatLine(const char* szText, int nColor)
{
    Unicode wszText[0x240];
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    sub_00446A90_RemoveTableString(wszText);
    sub_0043E610_AddChatText(wszText, nColor);
    return 1;
}

// 0x00449350
static __declspec(noinline) void sub_00449350_ShowUserJoined(const char* szName, int nLength, int nA)
{
    T0043E860* pUser = sub_00449050_AddEntry(szName, nLength, nA);
    if (!gbShowJoinLeave_0077BD54)
    {
        return;
    }

    char szText[500];
    if (strlen(pUser->szText))
    {
        sprintf(szText, "%s has joined the channel.", pUser->szText);
    }
    else
    {
        sprintf(szText, "%s has joined the channel.", szName);
    }
    sub_00447AB0_AddChatLine(szText, 5);
}

// 0x004493C0
int __fastcall sub_004493C0_OnUserJoin(int nA, int nB, const char* szText, int nLength)
{
    sub_00449350_ShowUserJoined(szText, nLength, nA);
    return 1;
}

// 0x004493E0
void __stdcall sub_004493E0_RemoveChannelUser(const char* szName)
{
    T0043E860* pPrev = 0;
    T0043E860* pUser = gpChannelUsers_00798F34;
    if (gpChannelUsers_00798F34)
    {
    while (pUser)
    {
        const char* szA = strchr(pUser->szName, '*');
        if (!szA)
        {
            szA = pUser->szName;
        }
        else
        {
            szA += 1;
        }
        const char* szB = strchr(szName, '*');
        if (!szB)
        {
            szB = szName;
        }
        else
        {
            szB += 1;
        }
        if (!strcmp(szA, szB))
        {
            break;
        }
        pPrev = pUser;
        pUser = pUser->pNext;
    }

    if (pUser)
    {
        if (gbShowJoinLeave_0077BD54)
        {
            char szText[500];
            if (pUser->szText && strlen(pUser->szText))
            {
                sprintf(szText, "%s has left the channel.", pUser->szText);
            }
            else
            {
                sprintf(szText, "%s has left the channel.", pUser->szName);
            }
            sub_00447AB0_AddChatLine(szText, 5);
        }

        if (pPrev)
        {
            pPrev->pNext = pUser->pNext;
        }
        else
        {
            gpChannelUsers_00798F34 = pUser->pNext;
        }

        if (gpSelectedChannelUser_00798F48 == pUser)
        {
            sub_00448050_ClearSelectedUser();
        }

        sub_005041B0_Destroy(pUser->f_9C, 1);
        pUser->f_9C = 0;
        FOG_Free(pUser, ".\\Src\\ComCallback.cpp", 0x7FE, 0);
    }
    }

    gnChannelLines_00798F40 -= 1;
    char szCount[0x100];
    sprintf(szCount, "%s (%d)", gData_00798D30, gnChannelLines_00798F40);
    Unicode wszCount[0x240];
    sub_00526F20_ToUnicode(wszCount, szCount, 0x240);
    sub_0043E630_ShowChannelText(wszCount);
    sub_00448BD0_UpdateScroll(0);
    sub_00447BB0_Refresh();
}
