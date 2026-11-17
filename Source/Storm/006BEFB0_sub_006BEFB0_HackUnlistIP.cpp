struct D2Server006BEFB0Strc
{
    unsigned char unk_000[0xBD0];
    int bHackListBD0;
};
char* __stdcall sub_006B013E_InetNtoa(unsigned long dwAddress); // 0x006B013E
void __cdecl sub_00410660_Log(const char* szChannel, const char* szFormat, ...); // 0x00410660
void __fastcall sub_006BE890_UnlistIP(D2Server006BEFB0Strc* pServer, const char* szFile, unsigned long dwAddress, int nLine); // 0x006BE890
extern const char gszHackChannel_006FC4A8[]; // 0x006FC4A8

// 0x006BEFB0
void __stdcall sub_006BEFB0_HackUnlistIP(D2Server006BEFB0Strc* pServer, unsigned long dwAddress, const char* szFile, int nLine)
{
    if (pServer->bHackListBD0)
    {
        sub_00410660_Log(gszHackChannel_006FC4A8, "[HACKLIST]  IP:%s  QSHackUnlistIP() from FILE:%s  LINE:%d", sub_006B013E_InetNtoa(dwAddress), szFile, nLine);
        sub_006BE890_UnlistIP(pServer, szFile, dwAddress, nLine);
    }
}
