typedef unsigned int size_t;

struct Unicode
{
    unsigned short wChar;
};

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual void VirtSlot3();
    virtual void VirtSlot4();
    virtual int IsFiltered(const char* szText);
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" size_t __cdecl strlen(const char* szString);
void __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);              // 0x00526E40
void __stdcall sub_00446A90_RemoveTableString(Unicode* pText);                                              // 0x00446A90
int __fastcall sub_0043E610_PrintText(Unicode* pText, int nColor);                                          // 0x0043E610
void __fastcall sub_00447560_SplitName(const char* szName, char* szTitle, char* szOut);                     // 0x00447560
D2SquelchListStrc* __cdecl sub_00611560_GetSquelchList();                                                   // 0x00611560

// 0x00448680
static void sub_00448680_PrintEmote(const char* szName, const char* szMessage)
{
    char szText[0x1F4];
    Unicode wszText[0x240];
    sprintf(szText, "*%s %s*", szName, szMessage);
    for (int i = 0; i < 0x240; i++)
        wszText[i].wChar = 0;
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    sub_00446A90_RemoveTableString(wszText);
    sub_0043E610_PrintText(wszText, 5);
}

// 0x004486F0
int __stdcall sub_004486F0_OnEmote(const char* szSender, const char* szMessage)
{
    char szName[0x100];
    char szTitle[0x100];
    char szOut[0x100];
    sub_00447560_SplitName(szSender, szTitle, szName);
    if (sub_00611560_GetSquelchList()->IsSquelched(szSender) || sub_00611560_GetSquelchList()->IsFiltered(szMessage))
    {
        return 1;
    }
    if (strlen(szName))
    {
        if (strlen(szTitle))
        {
            sprintf(szOut, "%s%s", szTitle, szName);
        }
        else
        {
            strcpy(szOut, szName);
        }
        sub_00448680_PrintEmote(szOut, szMessage);
    }
    else
    {
        sub_00448680_PrintEmote(szSender, szMessage);
    }
    return 1;
}
