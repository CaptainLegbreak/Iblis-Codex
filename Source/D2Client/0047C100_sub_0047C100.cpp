typedef unsigned int size_t;

struct D2ChatTextStrc
{
    char sz[0x100];
};

struct D2ChatMessageStrc
{
    unsigned char unk0x00;
    unsigned char nType;
    unsigned char unk0x02[6];
    unsigned char nColor;
    unsigned char unk0x09[0x11];
    D2ChatTextStrc tText;
};

struct D2ClientNotifyStrc
{
    char unk0x00[0x14];
    void(__fastcall* pfnResign)(const char* szInput);
};

extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385
extern "C" char* __cdecl strtok(char* szText, const char* szDelim);                                         // 0x0068264F
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" size_t __cdecl strlen(const char* sz);
const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __fastcall sub_0049F490_PrintChatMessage(D2ChatMessageStrc* pMessage);                                 // 0x0049F490
D2ClientNotifyStrc* __cdecl sub_0044B7B0_GetNotify();                                                       // 0x0044B7B0

static int __stdcall sub_0047B3B0_CompareCommand(const char* szCommand, const char* szInput)
{
    if (strlen(szInput) < strlen(szCommand))
        return -1;
    size_t nLength = strlen(szCommand);
    while (nLength)
    {
        --nLength;
        const int nDiff = toupper(*szInput) - toupper(*szCommand);
        if (nDiff)
            return (nDiff > 0) * 2 - 1;
        ++szInput;
        ++szCommand;
    }
    return 0;
}

// 0x0047C100
static int sub_0047C100(char* szInput, const char* szCommand)
{
    const size_t nLength = strlen(szCommand);
    if (!sub_0047B3B0_CompareCommand(szCommand, szInput))
    {
        const char c = szInput[nLength];
        if (c == 0x20 || !c)
        {
            char szDelim[] = " ";
            int nTokens = 0;
            if (strtok(szInput, szDelim))
            {
                do
                {
                    if (nTokens >= 2)
                    {
                        break;
                    }
                    nTokens += 1;
                }
                while (strtok(0, szDelim));
            }
            if (nTokens != 1)
            {
                D2ChatMessageStrc tMessage;
                tMessage.nType = 4;
                tMessage.nColor = 3;
                D2ChatTextStrc tBuffer;
                sprintf(tBuffer.sz, "<BattleNet>: Correct usage is: %s", szCommand);
                tMessage.tText = tBuffer;
                sub_0049F490_PrintChatMessage(&tMessage);
                return 1;
            }
            D2ClientNotifyStrc* pNotify = sub_0044B7B0_GetNotify();
            if (pNotify)
                pNotify->pfnResign(szInput);
            return 1;
        }
    }
    return 0;
}

int __fastcall sub_F07_Emit_0047C100(char* szInput)
{
    if (sub_0047C100(szInput, "/help"))
        return 1;
    if (sub_0047C100(szInput, "/?"))
        return 1;
    return 0;
}
