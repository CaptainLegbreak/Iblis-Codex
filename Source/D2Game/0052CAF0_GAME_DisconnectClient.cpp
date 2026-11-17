typedef unsigned int size_t;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;
struct D2ClientStrc;
struct D2UnitStrc;

struct D2GameStrc
{
    char unk0x00[0x18];
    D2CriticalSectionStrc* lpCriticalSection;
    char unk0x1C[0xC];
    unsigned short nGameId;
    char szGameName[16];
    char unk0x3A[0x52];
    unsigned short nClients;
};

struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    unsigned char abParam[4];
    unsigned char nParam;
    char szText[32];
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);                                // 0x006829C0
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
void __stdcall D2NET_10016(int nClientId);                                                                  // 0x0052B570
int __stdcall SERVER_GetClientGameGUID(int nClientId);                                                      // 0x0052B610
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame);                                          // 0x0052DA90
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860
int __fastcall sub_0052F8B0_IsGameNameUnused(const char* szGameName);                                       // 0x0052F8B0
D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* pGame, int nClientId);                   // 0x00537810
int __fastcall sub_005381C0(D2GameStrc* pGame, int nClientId);                         // 0x005381C0
int __fastcall CLIENTS_GetClientId(D2ClientStrc* pClient);                                                  // 0x00538590
int __fastcall CLIENTS_GetClassId(D2ClientStrc* pClient);                                                   // 0x005385F0
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient);                                                    // 0x00538830
void __fastcall CLIENTS_CopyAccountNameToBuffer(D2ClientStrc* pClient, char* szBuffer);                     // 0x005392F0
void __fastcall CLIENTS_RemoveClientFromGame(D2GameStrc* pGame, int nClientId, int bTriggerSave);           // 0x00539DA0
void __fastcall sub_0053B1B0_SendGameInfo(void* pClientId, unsigned short nGameId, int nClients, const char* szGameName); // 0x0053B1B0
void __fastcall sub_0053B220_SendHeaderOnly0xB0(int nClientId);                                             // 0x0053B220
void __fastcall sub_0053C5D0(D2ClientStrc* pClient, D2UnitStrc* pUnit);                                     // 0x0053C5D0
void __fastcall sub_6FC84D40(D2GameStrc* pGame, D2GSPacketSrv5A* pPacket);                                  // 0x0054AA40
void __fastcall sub_6FD14C30(D2UnitStrc* pUnit);                                                            // 0x0056DE40
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove);   // 0x0056DEB0
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition);                                          // 0x006460F0
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId);                                                     // 0x00646140

extern int gnGamesGUIDs_6FD447F8[1024];                                                                     // 0x00882D38

// 0x0052CAF0
void __fastcall GAME_DisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType)
{
    if (!pClient)
        return;

    const int nClientId = CLIENTS_GetClientId(pClient);

    D2GSPacketSrv5A tPacket = {};
    tPacket.nHeader = 0x5A;
    tPacket.nType = nEventType;
    tPacket.nColor = 4;
    *(int*)tPacket.abParam = 0;
    CLIENTS_CopyAccountNameToBuffer(pClient, &tPacket.szText[16]);
    tPacket.szText[31] = '\0';
    SStrCopy(tPacket.szText, CLIENTS_GetName(pClient), 16);
    sub_6FC84D40(pGame, &tPacket);

    CLIENTS_RemoveClientFromGame(pGame, CLIENTS_GetClientId(pClient), 1);
    sub_0053B220_SendHeaderOnly0xB0(nClientId);
    D2NET_10016(nClientId);
}

// 0x0052E8E0
void __stdcall sub_0052E8E0(void* pArg)
{
    for (int i = 0; i < 1024; ++i)
    {
        const int nGUID = gnGamesGUIDs_6FD447F8[i];
        if (nGUID && nGUID != -1)
        {
            if (D2GameStrc* pGame = GAME_LockGame(nGUID))
            {
                const unsigned int nClients = pGame->nClients;
                const unsigned short nGameId = pGame->nGameId;
                char szGameName[16];
                SStrCopy(szGameName, pGame->szGameName, 0x7FFFFFFF);

                D2_ASSERT(pGame->lpCriticalSection, 0x1064);
                LeaveCriticalSection(pGame->lpCriticalSection);

                sub_0053B1B0_SendGameInfo(pArg, nGameId, nClients, szGameName);
            }
        }
    }

    sub_0053B1B0_SendGameInfo(pArg, 0xFFFF, 0, &gszEmptyAssertText);
}

// 0x0052F940
void __fastcall GAME_ResolveGameNameConflict(D2GameStrc* pGame, const char* szGameName, unsigned int dwFlags)
{
    if (sub_0052F8B0_IsGameNameUnused(szGameName))
    {
        SStrCopy(pGame->szGameName, szGameName, 0x7FFFFFFF);
        return;
    }

    char szName[16];
    size_t nLength = strlen(szGameName);
    if (0xF - nLength < 3)
        nLength = 0xB;
    memcpy(szName, szGameName, nLength);
    sprintf(&szName[nLength], "~%d", szGameName, 0);

    int nCounter = 1;
    while (!sub_0052F8B0_IsGameNameUnused(szName) && nCounter < 100)
    {
        sprintf(szName, "%s~%d", szGameName, nCounter);
        nCounter += 1;
    }
    D2_ASSERT(nCounter < 100, 0x263);

    SStrCopy(pGame->szGameName, szName, 0x7FFFFFFF);
}

// 0x00530300
void __stdcall sub_00530300(int nClientId)
{
    if (!nClientId)
        return;

    const int nGUID = SERVER_GetClientGameGUID(nClientId);
    D2GameStrc* pGame = GAME_LockGame(nGUID);
    if (!pGame)
        return;

    if (!sub_005381C0(pGame, nClientId))
    {
        GAME_LeaveGamesCriticalSection(pGame);
        return;
    }

    D2ClientStrc* pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
    D2GSPacketSrv5A tPacket = {};
    tPacket.nHeader = 0x5A;
    tPacket.nType = 0;
    tPacket.nColor = 4;
    *(int*)tPacket.abParam = 0;
    tPacket.szText[16] = 0;
    SStrCopy(tPacket.szText, CLIENTS_GetName(pClient), 16);
    sub_6FC84D40(pGame, &tPacket);
    CLIENTS_RemoveClientFromGame(pGame, CLIENTS_GetClientId(pClient), 1);
    GAME_LeaveGamesCriticalSection(pGame);
}

// 0x00532E90
int __fastcall sub_6FC8AEC0(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned char* pSection, int a5, int a6, int* pSkillCount)
{
    *pSkillCount = 0;

    if (*(unsigned short*)pSection != 0x6669)
        return 5;

    const unsigned char* pData = pSection + 2;
    const int nClassId = CLIENTS_GetClassId(pClient);
    for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClassId); ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
        if (pData[i])
        {
            D2GAME_SetSkills_6FD14C60(pUnit, nSkillId, pData[i], 1);
        }
    }

    sub_0053C5D0(pClient, pUnit);

    const int nCount = SKILLS_GetPlayerSkillCount(nClassId) + 2;
    sub_6FD14C30(pUnit);
    *pSkillCount = nCount;
    return 0;
}
