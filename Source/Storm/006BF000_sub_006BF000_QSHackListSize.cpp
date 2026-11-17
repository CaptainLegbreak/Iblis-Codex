struct D2QueueServerStrc
{
    char unk0x000[0x890];
    int unk0x890;
    char unk0x894[0xBD0 - 0x894];
    int unk0xBD0;
};

void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410660

// 0x006BF000
void __stdcall sub_006BF000_QSHackListSize(D2QueueServerStrc* pServer, unsigned int nFile, unsigned int nLine)
{
    if (pServer->unk0xBD0)
    {
        sub_00410660_LogWritePrefixed("HACK", "[HACKLIST]  Size:%s  QSHackListSize() from FILE:%s  LINE:%d", pServer->unk0x890, nFile, nLine);
    }
}
