typedef unsigned int size_t;
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl atoi(const char* szString);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2ConfigStrc;

struct D2CmdArgStrc
{
    char szSection[0x1B];
    char szKey[0x1B];
    char szCommand[0x1B];
    unsigned char nType;
    int nIndex;
    int nDefault;
};

#define CMD_BOOLEAN 0
#define CMD_INTEGER 1
#define CMD_STRING 2

extern D2CmdArgStrc gaCmdArguments[58];

void __stdcall sub_00405450_LoadIniSettings(char* pSettings);
void __cdecl sub_006114E0_CreateIgnoreList();
int __fastcall sub_00405710_ParseCmdArgument(char* szCommandNameTestBuf, const char* pszCommand, char* szCommandValueBuf);

static void __stdcall sub_004058A0_ParseCmdArgs(D2ConfigStrc* pCfg, const char* argv)
{
    char szCommandNameTestBuf[0x100];
    char szCommandValueBuf[0x100];

    const int nArgvLength = strlen(argv);
    for (int nCharIndex = 0; nCharIndex < nArgvLength; nCharIndex++)
    {
        if (argv[nCharIndex] != '-')
        {
            continue;
        }
        nCharIndex++;

        if (nCharIndex < nArgvLength)
        {
            const int nCommandIndex = sub_00405710_ParseCmdArgument(szCommandNameTestBuf, &argv[nCharIndex], szCommandValueBuf);
            if (nCommandIndex != -1)
            {
                void* pCfgMember = (char*)pCfg + gaCmdArguments[nCommandIndex].nIndex;

                switch (gaCmdArguments[nCommandIndex].nType)
                {
                case CMD_INTEGER:
                    *(int*)pCfgMember = atoi(szCommandValueBuf);
                    break;
                case CMD_STRING:
                    strcpy((char*)pCfgMember, szCommandValueBuf);
                    break;
                case CMD_BOOLEAN:
                    *(unsigned char*)pCfgMember = 1;
                    break;
                }
            }
        }
    }
}

// 0x004059A0
void __fastcall ParseCmdLine(D2ConfigStrc* pCfg, const char* argv)
{
    memset(pCfg, 0, 0x3CD);
    sub_00405450_LoadIniSettings((char*)pCfg);
    sub_006114E0_CreateIgnoreList();
    sub_004058A0_ParseCmdArgs(pCfg, argv);
}
