#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct PairStrc_0044BE20;
struct PairStrc_0044DE50;
struct PairStrc_0044DEE0;
struct D2McpPacket06Strc;
struct D2McpInfoStrc;
struct D2ClientCharRecordStrc;
struct D2ClientNotifyStrc;
struct Unicode;
struct D2CmdLineArgStrc;
struct D2TickValueStrc;
struct D2StormLinkStrc;
struct D2StormListAStrc;
struct D2StormListBStrc;
struct D2StormListArrayStrc;
struct D2StormHashTableStrc;
struct D2StormListStrc;
struct D2TickTimerStrc;
struct sub_0040F7D0;
struct sub_00417810;
struct sub_00417860;
struct sub_004178C0;
struct sub_00417900;
struct sub_00417950;
struct sub_004179B0;
struct sub_004183F0;
struct sub_00418430;
struct sub_00418780;
struct sub_004187C0;
struct sub_00418800;
struct sub_00418840;
struct sub_00418880;
struct sub_004188C0;
struct sub_00418BA0;
struct sub_00418BE0;
struct sub_00418C20;
struct sub_00418E10;
struct sub_0041C3D0;
struct sub_0041C500;
struct sub_0041C730;
struct sub_0041C800;
struct sub_00420430;
struct sub_004204B0;
struct sub_00420710;
struct sub_004207E0;
struct sub_00426960;
struct sub_00426A80;
struct sub_00426CB0;
struct sub_00426D80;
struct sub_0044DDD0;
struct sub_0044DE90;
struct sub_0044ECC0;
struct sub_0044ED50;
struct sub_00601BF0;
struct sub_00601C70;
struct sub_00601D60;
struct sub_00601F20;
struct sub_00601F60;
struct sub_006020D0;
struct sub_00602140;
struct sub_006024A0;
struct sub_00602760;
struct sub_00417780;
struct sub_00417850;
struct sub_004178B0;
struct sub_00417940;
struct sub_00417990;
struct sub_00418760;
struct sub_00418770;
struct sub_00418A40;
struct sub_00418DE0;
struct sub_00418DF0;
struct sub_00418E00;
struct sub_00418E50;
struct sub_00418FF0;
struct sub_00419060;
struct sub_0041C4F0;
struct sub_0041C720;
struct sub_0041C7F0;
struct sub_004204A0;
struct sub_00420700;
struct sub_004207D0;
struct sub_00426CA0;
struct sub_00426D70;
struct sub_0044BDE0;
struct sub_0044ED40;
struct sub_0044ED90;
struct sub_00601F10;
struct sub_00602130;
struct sub_00602180;
struct sub_00602420;
struct sub_00602750;
struct D2ChatStormLinkStrc;
struct D2ChatStormLinkAStrc;
struct D2ChatStormLinkBStrc;
struct D2ChatStormNodeStrc;
struct D2ChatStormBaseArrayAStrc;
struct D2ChatStormBaseArrayBStrc;
struct D2ChatStormListAStrc;
struct D2ChatStormListBStrc;
struct D2ChatStormHashTableStrc;
struct D2ChatStormCtorLinkStrc;
struct D2ChatStormListCStrc;
struct D2ChatStormListDStrc;
struct D2ChatStormListEStrc;
struct D2CommonStormSlotLinkStrc;
struct D2CommonStormSlotListAStrc;
struct D2CommonStormSlotListBStrc;
struct D2CommonMappingEntryNodeBaseStrc;
struct D2CommonMappingEntryNodeStrc;
struct D2CommonStringEntryNodeStrc;
struct D2CommonStormHashTableAStrc;
extern int gdwGlobal_0077932C; // 0x0077932C
extern int gdwGlobal_007799D8; // 0x007799D8
extern char gData_00779A40[]; // 0x00779A40
extern int gdwGlobal_0077AC04; // 0x0077AC04
extern int gdwGlobal_0077BBF8; // 0x0077BBF8
extern char gData_00798D30[]; // 0x00798D30
extern int gdwGlobal_007992A4; // 0x007992A4
extern char gData_007992CC[]; // 0x007992CC
extern int gdwGlobal_00798FB0; // 0x00798FB0
extern int gdwGlobal_0079929C; // 0x0079929C
extern int gdwGlobal_00798F88; // 0x00798F88
extern int gdwGlobal_007992F4; // 0x007992F4
extern int gdwGlobal_007A0438; // 0x007A0438
extern int gdwGlobal_007A0460; // 0x007A0460

struct PairStrc_0044BE20
{
    int nFirst;
    int nSecond;
};

extern int gdwGlobal_007A065C; // 0x007A065C
extern int gdwGlobal_007A0660; // 0x007A0660
extern int gdwGlobal_007A0664; // 0x007A0664
extern int gdwGlobal_007A0654; // 0x007A0654
extern int gdwGlobal_007A0650; // 0x007A0650
extern int gdwGlobal_007A0674; // 0x007A0674
extern int gdwGlobal_007A04FC; // 0x007A04FC
extern int gdwGlobal_007A04A4; // 0x007A04A4
extern int gdwGlobal_007A04D0; // 0x007A04D0
extern char gData_007A04D4[]; // 0x007A04D4
extern int gdwGlobal_007A05F4; // 0x007A05F4
extern int gdwGlobal_007A0620; // 0x007A0620
extern int gdwGlobal_007A048C; // 0x007A048C
extern int gdwGlobal_007A04A8; // 0x007A04A8
extern int gdwGlobal_007A0488; // 0x007A0488
extern int gdwGlobal_007A05FC; // 0x007A05FC
extern int gdwGlobal_007A04F4; // 0x007A04F4

struct PairStrc_0044DE50
{
    int nFirst;
    int nSecond;
};

struct PairStrc_0044DEE0
{
    int nFirst;
    int nSecond;
};

extern "C" char* __cdecl strcpy(char* pDest, const char* pSource);
extern "C" unsigned int __cdecl strlen(const char* pString);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection); // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* lpOutputString); // 0x006CC200

struct D2McpPacket06Strc
{
    unsigned char f_0;
    unsigned char aRequestId[2];
    unsigned char aToken[4];
    unsigned char aValue[4];
    unsigned char nByte0B;
    unsigned char nByte0C;
    unsigned char nByte0D;
    unsigned char nCount;
    unsigned char aFirst[16];
    unsigned char aSecond[16];
    char szData[1];
};

struct D2McpInfoStrc
{
    unsigned short f_0;
    unsigned short unk0x02;
    int unk0x04;
    int nValue;
    unsigned char nByte0C;
    unsigned char nByte0D;
    unsigned char nByte0E;
    unsigned char unk0x0F;
    int nCount;
    int nToken;
    char unk0x18[0x10];
    char szName[0x20];
    unsigned short aFirst[16];
    unsigned short aSecond[16];
    char aNames[16][0x10];
};

struct D2ClientCharRecordStrc
{
    char unk0x00[0x1F];
    char szName[0x1D0];
    unsigned char aFlags[2];
    char unk0x1F1[0x1F];
    unsigned char nKind;
    char unk0x211[0x34];
    char szText245[0x18];
    char szText25D[0x10];
};

struct D2ClientNotifyStrc
{
    char unk0x00[0x34];
    void (__fastcall* pfnCharUpdate)(char* szName, char* szText245, char* szText25D, int nFlags);
    char unk0x38[0x58];
    void (__cdecl* pfnNotify)();
};
D2ClientNotifyStrc* __cdecl sub_0044B7B0_GetNotify(); // 0x0044B7B0
int __stdcall sub_0052EFF0(int nArg); // 0x0052EFF0
void* __stdcall sub_0052FC20(int nArg); // 0x0052FC20
extern unsigned short gwMcpRequestId_00798F8C; // 0x00798F8C
extern D2ClientCharRecordStrc* gpCharRecord_007A0438; // 0x007A0438
extern int gnQServerThreshold_0070F560; // 0x0070F560

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2UnitStrc
{
    int dwUnitType;
};

struct Unicode
{
    unsigned short wChar;
};

struct D2CmdLineArgStrc
{
    char unk0x00[0x18];
    const char* szValue;
};

struct D2TickValueStrc
{
    unsigned int dwTickCount;
    int nValue;

    void sub_0044BDF0_Set(int nValue);
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" int __cdecl abs(int nValue);
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526940_UnicodeStrStr(const Unicode* pString, const Unicode* pPattern); // 0x00526940
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned char nFlags, const char* szString); // 0x00415070
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
void __cdecl sub_00466FF0(); // 0x00466FF0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
void __fastcall sub_004693B0(int nSteps); // 0x004693B0
void __cdecl sub_00469270(); // 0x00469270
void __cdecl sub_00469230(); // 0x00469230
void __cdecl sub_004692B0(); // 0x004692B0
void __cdecl sub_00469330(); // 0x00469330
void __cdecl sub_004692F0(); // 0x004692F0
void __cdecl sub_00469370(); // 0x00469370
int __cdecl sub_004F5A30(); // 0x004F5A30
void __cdecl sub_00453DE0(); // 0x00453DE0
void __cdecl sub_00467A00(); // 0x00467A00
extern unsigned char gnGlobal_007A060D; // 0x007A060D
extern int gdwGlobal_007A0670; // 0x007A0670

typedef void (__fastcall* D2ClientCallbackFn)(void* pArg);

void* __cdecl sub_004F59A0(); // 0x004F59A0
extern D2ClientCallbackFn gpfnClientCallback_007A0484; // 0x007A0484
extern D2ClientCallbackFn gpfnClientCallbacks_0070EF0C[3]; // 0x0070EF0C
extern int gdwGlobal_007A277C; // 0x007A277C

struct D2LevelsTxt
{
    char unk0x000[0x218];
    unsigned int dwBlankScreen;
};

extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gdwGlobal_007A04B8; // 0x007A04B8
extern int gdwGlobal_007A061C; // 0x007A061C
extern int gdwGlobal_007A0658; // 0x007A0658
extern int gnAutomapHeight_007A521C; // 0x007A521C
int __cdecl sub_0045AE90(); // 0x0045AE90
int __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2); // 0x00456300
void __fastcall sub_00457640(int bForce); // 0x00457640
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom(); // 0x004646A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __stdcall sub_00420290_BreakHandlerChain(void* pMsg); // 0x00420290
extern int gnGlobal_007A0608; // 0x007A0608
void __fastcall sub_0047A9B0_SetFlag712EFC(int bClear); // 0x0047A9B0

#pragma pack(push, 1)
struct D2ConfigStrc
{
    char unk0x000[0x08];
    unsigned char bWindow;
    unsigned char bNoFixedAspect;
    unsigned char b3DFX;
    unsigned char bOpenGL;
    unsigned char bRave;
    unsigned char bD3D;
    unsigned char bPerspective;
    unsigned char bQuality;
    int dwGamma;
    unsigned char bVSync;
    int dwFramerate;
    int dwGameType;
    unsigned short wJoinID;
    char szGameName[0x18];
    char szServerIP[0x18];
    char szBattleNetIP[0x18];
    char szMCPIP[0x18];
    char unk0x07F[6];
    char bAmazon;
    char bPaladin;
    char bSorceress;
    char bNecromancer;
    char bBarbarian;
    char bDruid;
    char bAssassin;
    char unk0x08C[0x0BD - 0x08C];
    char szName[0x18];
    char szRealm[0x18];
    char unk0x0ED[0x1ED - 0x0ED];
    unsigned char nCTemp;
    char unk0x1EE[0x1FF - 0x1EE];
    int dwAct;
    unsigned char bNoPreload;
    unsigned char bDirect;
    unsigned char bLowEnd;
    unsigned char bNoCompress;
    char unk0x207[0x215 - 0x207];
    unsigned char bTxt;
    unsigned char bLog;
    unsigned char bMsgLog;
    unsigned char bSafeMode;
    char bFlag219;
    int dwSeed;
    char unk0x21E[0x225 - 0x21E];
    void* pComInterface;
    int dwValue229;
};

#pragma pack(pop)

extern char gszRealm_007A0500[]; // 0x007A0500
void __cdecl sub_004776E0(); // 0x004776E0
void __cdecl sub_004F5280(); // 0x004F5280
void __cdecl sub_004776F0(); // 0x004776F0
void __cdecl sub_00477700(); // 0x00477700
void __cdecl sub_00477710(); // 0x00477710
void __cdecl sub_00477720(); // 0x00477720
void __fastcall sub_004776C0(int nGamma); // 0x004776C0
void __cdecl D2GFX_EnableVSync(); // 0x004F5270
void __fastcall sub_00624B50(int nValue); // 0x00624B50
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
void __fastcall sub_0047AA10(int nValue); // 0x0047AA10
void __stdcall D2CMP_SetCompressedDataMode(int bCompress); // 0x005FE280
void __stdcall sub_006125A0(int bValue); // 0x006125A0
void __fastcall sub_0044B880_SetValue(int nValue); // 0x0044B880

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    D2StormLinkStrc* sub_0044DD90_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_0044DE60_NextLink(int nLinkOffset);
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListAStrc(const D2StormListAStrc& source);
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void UnlinkAll();                                                                                       // 0x0044F8E0
    void sub_0044DF90_CopyLinkOffset(const D2StormListAStrc* pSource);
    D2StormLinkStrc* sub_0044ED20_Link(char* pNode);
    void sub_0044EDC0_UnlinkNode(char* pNode);
    void sub_0044EE10_InitLinkField(int nLinkOffset);
    void sub_0044F980_ChangeLinkOffset(int nLinkOffset);
};

struct D2StormListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListBStrc(const D2StormListBStrc& source);
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormLinkStrc* sub_0044EDA0_Link(char* pNode);
    void sub_0044EE30_InitLinkField(int nLinkOffset);
    void sub_0044F890_UnlinkNode(char* pNode);
};

struct D2StormListArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;
    unsigned int f_C;

    D2StormListAStrc* sub_0044DE10_At(unsigned int nIndex);
    unsigned int sub_0044DF30_CalcChunkSize(unsigned int nCount);
};

struct D2StormHashTableStrc
{
    virtual void InternalDelete(char* pNode);                                                               // 0x004503F0
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0044FA00_InternalClear(int bWarn);
};

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2TickTimerStrc
{
    unsigned int dwStart;
    unsigned int dwDuration;

    unsigned int sub_0044DFB0_GetRemaining();
};

struct sub_0040F7D0
{
    D2StormLinkStrc f_0;
    ~sub_0040F7D0();
};

struct sub_00417810
{
    D2StormLinkStrc f_0;
    ~sub_00417810();
};

struct sub_00417860
{
    D2StormLinkStrc f_0;
    ~sub_00417860();
};

struct sub_004178C0
{
    D2StormLinkStrc f_0;
    ~sub_004178C0();
};

struct sub_00417900
{
    D2StormLinkStrc f_0;
    ~sub_00417900();
};

struct sub_00417950
{
    D2StormLinkStrc f_0;
    ~sub_00417950();
};

struct sub_004179B0
{
    D2StormLinkStrc f_0;
    ~sub_004179B0();
};

struct sub_004183F0
{
    D2StormLinkStrc f_0;
    ~sub_004183F0();
};

struct sub_00418430
{
    D2StormLinkStrc f_0;
    ~sub_00418430();
};

struct sub_00418780
{
    D2StormLinkStrc f_0;
    ~sub_00418780();
};

struct sub_004187C0
{
    D2StormLinkStrc f_0;
    ~sub_004187C0();
};

struct sub_00418800
{
    D2StormLinkStrc f_0;
    ~sub_00418800();
};

struct sub_00418840
{
    D2StormLinkStrc f_0;
    ~sub_00418840();
};

struct sub_00418880
{
    D2StormLinkStrc f_0;
    ~sub_00418880();
};

struct sub_004188C0
{
    D2StormLinkStrc f_0;
    ~sub_004188C0();
};

struct sub_00418BA0
{
    D2StormLinkStrc f_0;
    ~sub_00418BA0();
};

struct sub_00418BE0
{
    D2StormLinkStrc f_0;
    ~sub_00418BE0();
};

struct sub_00418C20
{
    D2StormLinkStrc f_0;
    ~sub_00418C20();
};

struct sub_00418E10
{
    D2StormLinkStrc f_0;
    ~sub_00418E10();
};

struct sub_0041C3D0
{
    D2StormLinkStrc f_0;
    ~sub_0041C3D0();
};

struct sub_0041C500
{
    D2StormLinkStrc f_0;
    ~sub_0041C500();
};

struct sub_0041C730
{
    D2StormLinkStrc f_0;
    ~sub_0041C730();
};

struct sub_0041C800
{
    D2StormLinkStrc f_0;
    ~sub_0041C800();
};

struct sub_00420430
{
    D2StormLinkStrc f_0;
    ~sub_00420430();
};

struct sub_004204B0
{
    D2StormLinkStrc f_0;
    ~sub_004204B0();
};

struct sub_00420710
{
    D2StormLinkStrc f_0;
    ~sub_00420710();
};

struct sub_004207E0
{
    D2StormLinkStrc f_0;
    ~sub_004207E0();
};

struct sub_00426960
{
    D2StormLinkStrc f_0;
    ~sub_00426960();
};

struct sub_00426A80
{
    D2StormLinkStrc f_0;
    ~sub_00426A80();
};

struct sub_00426CB0
{
    D2StormLinkStrc f_0;
    ~sub_00426CB0();
};

struct sub_00426D80
{
    D2StormLinkStrc f_0;
    ~sub_00426D80();
};

struct sub_0044DDD0
{
    D2StormLinkStrc f_0;
    ~sub_0044DDD0();
};

struct sub_0044DE90
{
    D2StormLinkStrc f_0;
    ~sub_0044DE90();
};

struct sub_0044ECC0
{
    D2StormLinkStrc f_0;
    ~sub_0044ECC0();
};

struct sub_0044ED50
{
    D2StormLinkStrc f_0;
    ~sub_0044ED50();
};

struct sub_00601BF0
{
    D2StormLinkStrc f_0;
    ~sub_00601BF0();
};

struct sub_00601C70
{
    D2StormLinkStrc f_0;
    ~sub_00601C70();
};

struct sub_00601D60
{
    D2StormLinkStrc f_0;
    ~sub_00601D60();
};

struct sub_00601F20
{
    D2StormLinkStrc f_0;
    ~sub_00601F20();
};

struct sub_00601F60
{
    D2StormLinkStrc f_0;
    ~sub_00601F60();
};

struct sub_006020D0
{
    D2StormLinkStrc f_0;
    ~sub_006020D0();
};

struct sub_00602140
{
    D2StormLinkStrc f_0;
    ~sub_00602140();
};

struct sub_006024A0
{
    D2StormLinkStrc f_0;
    ~sub_006024A0();
};

struct sub_00602760
{
    D2StormLinkStrc f_0;
    ~sub_00602760();
};

struct sub_00417780
{
    D2StormLinkStrc f_0;
    sub_00417780();
};

struct sub_00417850
{
    D2StormLinkStrc f_0;
    sub_00417850();
};

struct sub_004178B0
{
    D2StormLinkStrc f_0;
    sub_004178B0();
};

struct sub_00417940
{
    D2StormLinkStrc f_0;
    sub_00417940();
};

struct sub_00417990
{
    D2StormLinkStrc f_0;
    sub_00417990();
};

struct sub_00418760
{
    D2StormLinkStrc f_0;
    sub_00418760();
};

struct sub_00418770
{
    D2StormLinkStrc f_0;
    sub_00418770();
};

struct sub_00418A40
{
    D2StormLinkStrc f_0;
    sub_00418A40();
};

struct sub_00418DE0
{
    D2StormLinkStrc f_0;
    sub_00418DE0();
};

struct sub_00418DF0
{
    D2StormLinkStrc f_0;
    sub_00418DF0();
};

struct sub_00418E00
{
    D2StormLinkStrc f_0;
    sub_00418E00();
};

struct sub_00418E50
{
    D2StormLinkStrc f_0;
    sub_00418E50();
};

struct sub_00418FF0
{
    D2StormLinkStrc f_0;
    sub_00418FF0();
};

struct sub_00419060
{
    D2StormLinkStrc f_0;
    sub_00419060();
};

struct sub_0041C4F0
{
    D2StormLinkStrc f_0;
    sub_0041C4F0();
};

struct sub_0041C720
{
    D2StormLinkStrc f_0;
    sub_0041C720();
};

struct sub_0041C7F0
{
    D2StormLinkStrc f_0;
    sub_0041C7F0();
};

struct sub_004204A0
{
    D2StormLinkStrc f_0;
    sub_004204A0();
};

struct sub_00420700
{
    D2StormLinkStrc f_0;
    sub_00420700();
};

struct sub_004207D0
{
    D2StormLinkStrc f_0;
    sub_004207D0();
};

struct sub_00426CA0
{
    D2StormLinkStrc f_0;
    sub_00426CA0();
};

struct sub_00426D70
{
    D2StormLinkStrc f_0;
    sub_00426D70();
};

struct sub_0044BDE0
{
    D2StormLinkStrc f_0;
    sub_0044BDE0();
};

struct sub_0044ED40
{
    D2StormLinkStrc f_0;
    sub_0044ED40();
};

struct sub_0044ED90
{
    D2StormLinkStrc f_0;
    sub_0044ED90();
};

struct sub_00601F10
{
    D2StormLinkStrc f_0;
    sub_00601F10();
};

struct sub_00602130
{
    D2StormLinkStrc f_0;
    sub_00602130();
};

struct sub_00602180
{
    D2StormLinkStrc f_0;
    sub_00602180();
};

struct sub_00602420
{
    D2StormLinkStrc f_0;
    sub_00602420();
};

struct sub_00602750
{
    D2StormLinkStrc f_0;
    sub_00602750();
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char gszIgnoreListSourceFile_006E6290[];

struct D2ChatStormLinkStrc
{
    D2ChatStormLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2ChatStormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2ChatStormLinkStrc*)(m_next + nLinkOffset);
    }
    char* MaskNext()
    {
        return (char*)((((int)m_next <= 0) - 1) & (int)m_next);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    bool sub_0060E0C0_IsLinked();
    char* sub_0060E1A0_Next();
    char* sub_0060E240_Next();
    void sub_0060E3B0_Unlink();
    void sub_0060E400_Unlink();
    void sub_0060E690_Unlink();
    void sub_0060E760_Unlink();
};

struct D2ChatStormLinkAStrc
{
    D2ChatStormLinkAStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkAStrc();
};

struct D2ChatStormLinkBStrc
{
    D2ChatStormLinkBStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkBStrc();
};

struct D2ChatStormNodeStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    char* sub_0060E0B0_GetKey();
};

struct D2ChatStormBaseArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;

    D2ChatStormBaseArrayAStrc();
    unsigned int sub_0060E230_Count();
};

struct D2ChatStormBaseArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;

    D2ChatStormBaseArrayBStrc();
    unsigned int sub_0060E250_Count();
};

struct D2ChatStormListAStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void sub_0060E260_InitializeTerminator();
    char* sub_0060E440_Head();
    void sub_0060E5F0_Reset();
};

struct D2ChatStormListBStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void sub_0060E270_InitializeTerminator();
    char* sub_0060E5D0_Head();
    void sub_0060E610_Reset();
};

struct D2ChatStormHashTableStrc
{
    void* m_pVTable;
    D2ChatStormListAStrc m_fulllist;

    char* sub_0060E6D0_Head();
};

struct D2ChatStormCtorLinkStrc
{
    D2ChatStormCtorLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormCtorLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2ChatStormListCStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListCStrc();
};

struct D2ChatStormListDStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListDStrc();
};

struct D2ChatStormListEStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListEStrc();
};

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;

    ~D2CommonStormSlotLinkStrc()
    {
        Unlink();
    }
    D2CommonStormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2CommonStormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2CommonStormSlotLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    ~D2CommonStormSlotListAStrc();
    void UnlinkAll();
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    ~D2CommonStormSlotListBStrc();
    void UnlinkAll();
};

struct D2CommonMappingEntryNodeBaseStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    ~D2CommonMappingEntryNodeBaseStrc();
};

struct D2CommonMappingEntryNodeStrc : D2CommonMappingEntryNodeBaseStrc
{
    void* pMapped;

    ~D2CommonMappingEntryNodeStrc();
};

struct D2CommonStringEntryNodeStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    ~D2CommonStringEntryNodeStrc();
    void sub_0060EE30_Destroy();
};

struct D2CommonStormHashTableAStrc
{
    void sub_0060EB70_InternalClear(int bWarn);
    void sub_0060ED60_Clear();
};

extern unsigned char gnBetaScreenIndex_007A060D; // 0x007A060D

#pragma pack(push, 1)
struct D2ClientInfoStrc
{
    char unk0x00[0x1EF];
    unsigned short wFlags;
};

#pragma pack(pop)
extern unsigned char gnDifficulty_007A060C; // 0x007A060C

int gdwGlobal_0077AC08; // 0x0077AC08

int gdwGlobal_007992E8; // 0x007992E8

int gdwGlobal_007992E0; // 0x007992E0

int gdwGlobal_00799298; // 0x00799298

int gdwGlobal_007992F0; // 0x007992F0

int gdwGlobal_00799100; // 0x00799100

int gdwGlobal_007992A0; // 0x007992A0

char gData_00799108[4]; // 0x00799108

int gdwGlobal_007992A8; // 0x007992A8

int gdwGlobal_00798F5C; // 0x00798F5C

int gdwGlobal_00798F84; // 0x00798F84

int gdwGlobal_00799104; // 0x00799104

int gdwGlobal_00798F7C; // 0x00798F7C

int gdwGlobal_007A0498; // 0x007A0498

int gdwGlobal_007A04C8; // 0x007A04C8

int gdwGlobal_007A04C4; // 0x007A04C4

// 0x0042F6D0
int __cdecl sub_0042F6D0()
{
    return gdwGlobal_00779974;
}

// 0x0042FA30
int __cdecl sub_0042FA30()
{
    return gdwGlobal_0077932C;
}

// 0x00430B40
int __cdecl sub_00430B40()
{
    return gdwGlobal_0077998C;
}

// 0x00436EA0
int __cdecl sub_00436EA0()
{
    return gdwGlobal_007799D8;
}

// 0x00437D00
void* __cdecl sub_00437D00()
{
    return gData_00779A40;
}

// 0x00437D10
int __cdecl sub_00437D10()
{
    return 0;
}

// 0x0043B830
int __cdecl sub_0043B830()
{
    return gdwGlobal_0077AC04;
}

// 0x0043B840
int __cdecl sub_0043B840()
{
    return gdwGlobal_0077AC08;
}

// 0x0043DB10
int __cdecl sub_0043DB10()
{
    return gdwGlobal_0077BBF8;
}

// 0x0043F840
int __cdecl sub_0043F840()
{
    return 1;
}

// 0x00446CF0
void* __cdecl sub_00446CF0()
{
    return gData_00798D30;
}

// 0x004473F0
int __cdecl sub_004473F0()
{
    return 1;
}

// 0x004476F0
int __cdecl sub_004476F0()
{
    return 1;
}

// 0x00447730
int __stdcall sub_00447730(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x00449AC0
int __cdecl sub_00449AC0()
{
    return gdwGlobal_007992A4;
}

// 0x00449BC0
void* __cdecl sub_00449BC0()
{
    return gData_007992CC;
}

// 0x00449BE0
int __cdecl sub_00449BE0()
{
    return gdwGlobal_00798FB0;
}

// 0x00449C00
int __cdecl sub_00449C00()
{
    return gdwGlobal_0079929C;
}

// 0x00449C10
int __cdecl sub_00449C10()
{
    return gdwGlobal_007992E8;
}

// 0x00449C30
int __cdecl sub_00449C30()
{
    return gdwGlobal_007992E0;
}

// 0x00449C50
int __cdecl sub_00449C50()
{
    return gdwGlobal_00799298;
}

// 0x00449C70
int __cdecl sub_00449C70()
{
    return gdwGlobal_007992F0;
}

// 0x00449CA0
int __cdecl sub_00449CA0()
{
    return gdwGlobal_00799100;
}

// 0x00449CB0
int __cdecl sub_00449CB0()
{
    return gdwGlobal_007992A0;
}

// 0x00449D50
void* __cdecl sub_00449D50()
{
    return gData_00799108;
}

// 0x00449D80
int __cdecl sub_00449D80()
{
    return gdwGlobal_007992A8;
}

// 0x00449DA0
int __cdecl sub_00449DA0()
{
    return gdwGlobal_00798F5C;
}

// 0x00449DC0
int __cdecl sub_00449DC0()
{
    return gdwGlobal_00798F84;
}

// 0x00449DE0
int __cdecl sub_00449DE0()
{
    return gdwGlobal_00798F88;
}

// 0x00449E20
int __cdecl sub_00449E20()
{
    return gdwGlobal_00799104;
}

// 0x00449E40
int __cdecl sub_00449E40()
{
    return gdwGlobal_00798F7C;
}

// 0x00449E60
int __cdecl sub_00449E60()
{
    return gdwGlobal_007992F4;
}

// 0x0044B7A0
int __cdecl sub_0044B7A0()
{
    return gdwGlobal_007A0438;
}

// 0x0044B890
int __cdecl sub_0044B890()
{
    return gdwGlobal_0070EE8C;
}

// 0x0044BBA0
int __cdecl sub_0044BBA0()
{
    return gdwGlobal_007A0460;
}

// 0x0044BE20
void __fastcall sub_0044BE20(PairStrc_0044BE20* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0044BE70
int __cdecl sub_0044BE70()
{
    return gdwGlobal_007A065C;
}

// 0x0044BE90
int __cdecl sub_0044BE90()
{
    return gdwGlobal_007A0660;
}

// 0x0044BEB0
int __cdecl sub_0044BEB0()
{
    return gdwGlobal_007A0664;
}

// 0x0044BF00
int __cdecl sub_0044BF00()
{
    return gdwGlobal_0070F234;
}

// 0x0044BF10
int __cdecl sub_0044BF10()
{
    return gdwGlobal_0070F2BC;
}

// 0x0044BF20
int __cdecl sub_0044BF20()
{
    return gdwGlobal_007A0654;
}

// 0x0044BF30
int __cdecl sub_0044BF30()
{
    return gdwGlobal_007A0650;
}

// 0x0044C870
int __cdecl sub_0044C870()
{
    return gdwGlobal_007A0674;
}

// 0x0044CE50
int __cdecl sub_0044CE50()
{
    return gdwGlobal_007A04FC;
}

// 0x0044CE60
int __cdecl sub_0044CE60()
{
    return gdwGlobal_007A04A4;
}

// 0x0044CE70
int __cdecl sub_0044CE70()
{
    return gdwGlobal_007A04D0;
}

// 0x0044CE80
void* __cdecl sub_0044CE80()
{
    return gData_007A04D4;
}

// 0x0044D540
int __cdecl sub_0044D540()
{
    return gdwGlobal_007A05F4;
}

// 0x0044DA30
int __cdecl sub_0044DA30()
{
    return gdwGlobal_007A0620;
}

// 0x0044DA90
int __cdecl sub_0044DA90()
{
    return gdwGlobal_007A0498;
}

// 0x0044DAA0
int __cdecl sub_0044DAA0()
{
    return gdwGlobal_007A048C;
}

// 0x0044DAB0
int __cdecl sub_0044DAB0()
{
    return gdwGlobal_007A0494;
}

// 0x0044DAC0
int __cdecl sub_0044DAC0()
{
    return gdwGlobal_007A04C8;
}

// 0x0044DAE0
int __cdecl sub_0044DAE0()
{
    return gdwGlobal_007A04A8;
}

// 0x0044DAF0
int __cdecl sub_0044DAF0()
{
    return gdwGlobal_007A04B0;
}

// 0x0044DB00
int __cdecl sub_0044DB00()
{
    return gdwGlobal_007A0498;
}

// 0x0044DB10
int __cdecl sub_0044DB10()
{
    return gdwGlobal_007A04C4;
}

// 0x0044DB20
int __cdecl sub_0044DB20()
{
    return gdwGlobal_007A0488;
}

// 0x0044DB30
int __cdecl sub_0044DB30()
{
    return gdwGlobal_007A0610;
}

// 0x0044DC60
int __cdecl sub_0044DC60()
{
    return gdwGlobal_007A05FC;
}

// 0x0044DCC0
int __cdecl sub_0044DCC0()
{
    return gdwGlobal_007A04F4;
}

// 0x0044DE40
int __cdecl sub_0044DE40()
{
    return 4;
}

// 0x0044DE50
void __fastcall sub_0044DE50(PairStrc_0044DE50* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0044DEE0
void __fastcall sub_0044DEE0(PairStrc_0044DEE0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

#include "gen/data/Source/D2Client/GAME/Game.inc"

D2McpInfoStrc gMcpInfo_0079910C; // 0x0079910C

char gtQServerLock_007A0468[0x18]; // 0x007A0468

int gbQServerStop_007A0648; // 0x007A0648

int gbQServerRestart_007A064C; // 0x007A064C

// 0x0044ACA0
int __fastcall sub_0044ACA0(D2McpPacket06Strc* pPacket, int nSize)
{
    const int nToken = *(int*)pPacket->aToken;
    const int nValue = *(int*)pPacket->aValue;
    if (*(unsigned short*)pPacket->aRequestId != gwMcpRequestId_00798F8C)
        return 1;
    gMcpInfo_0079910C.f_0 = gwMcpRequestId_00798F8C;
    gMcpInfo_0079910C.nToken = nToken;
    gMcpInfo_0079910C.nCount = pPacket->nCount;
    gMcpInfo_0079910C.nValue = nValue;
    gMcpInfo_0079910C.nByte0C = pPacket->nByte0B;
    gMcpInfo_0079910C.nByte0D = pPacket->nByte0C;
    gMcpInfo_0079910C.nByte0E = pPacket->nByte0D;
    if (nToken == -1)
    {
        sub_00449BF0_SetValue(0x32);
        return 1;
    }
    if (nToken == -2)
    {
        sub_00449BF0_SetValue(0x33);
        return 1;
    }
    const char* pString = pPacket->szData;
    const char* szName = pString;
    pString += strlen(pString) + 1;
    strcpy(gMcpInfo_0079910C.szName, szName);
    for (int i = 0; i < pPacket->nCount; i++)
    {
        gMcpInfo_0079910C.aFirst[i] = pPacket->aFirst[i];
        gMcpInfo_0079910C.aSecond[i] = pPacket->aSecond[i];
        const char* szEntry = pString;
        pString += strlen(pString) + 1;
        strcpy(gMcpInfo_0079910C.aNames[i], szEntry);
    }
    return 1;
}

// 0x0044CF20
unsigned long __stdcall sub_0044CF20(void* pArg)
{
    int nLast = 0;
    void* pSession = 0;
    EnterCriticalSection(gtQServerLock_007A0468);
    int bStop = gbQServerStop_007A0648;
    int bRestart = gbQServerRestart_007A064C;
    LeaveCriticalSection(gtQServerLock_007A0468);
    while (!bStop)
    {
        if (bRestart)
        {
            sub_0052CFE0();
            pSession = sub_0052FC20(1);
            if (pSession)
                sub_0052FD90(0, 0);
        }
        if (pSession)
        {
            Sleep(30);
            D2ClientNotifyStrc* pNotify = sub_0044B7B0_GetNotify();
            if (pNotify)
            {
                const int nLevel = sub_0052EFF0(1);
                if (nLevel != nLast)
                {
                    if (nLast < gnQServerThreshold_0070F560)
                    {
                        if (nLevel >= gnQServerThreshold_0070F560)
                            pNotify->pfnNotify();
                    }
                    else if (nLevel < gnQServerThreshold_0070F560)
                    {
                        int nFlags = 0;
                        if (gpCharRecord_007A0438->nKind == 1)
                            nFlags = 1;
                        if (gpCharRecord_007A0438->nKind == 2)
                            nFlags |= 2;
                        const unsigned short wFlags = *(unsigned short*)gpCharRecord_007A0438->aFlags;
                        if (wFlags & 4)
                            nFlags |= 4;
                        if (wFlags & 0x20)
                            nFlags |= 8;
                        pNotify->pfnCharUpdate(gpCharRecord_007A0438->szName, gpCharRecord_007A0438->szText245, gpCharRecord_007A0438->szText25D, nFlags);
                    }
                    nLast = nLevel;
                }
            }
        }
        else
        {
            Sleep(10);
        }
        EnterCriticalSection(gtQServerLock_007A0468);
        bStop = gbQServerStop_007A0648;
        bRestart = gbQServerRestart_007A064C;
        LeaveCriticalSection(gtQServerLock_007A0468);
    }
    sub_0052E9C0();
    sub_0052FD90(0, 1);
    DeleteCriticalSection(gtQServerLock_007A0468);
    OutputDebugStringA("Open server thread shut down\n");
    return 1;
}

int gdwGlobal_007A061C; // 0x007A061C

int gdwGlobal_007A0650; // 0x007A0650

int gdwGlobal_007A0654; // 0x007A0654

int gdwGlobal_007A0658; // 0x007A0658

int gdwGlobal_007A06F8; // 0x007A06F8

// 0x0044B230
void __stdcall sub_0044B230_StripStringAndNextChar(Unicode* pString)
{
    D2_ASSERT(sub_00526800(pString) < 500, 0x342);
    const Unicode* pPattern = D2LANG_GetStringFromTblIndex(0xF9A);
    int nLength = sub_00526800(pPattern);
    for (Unicode* pFound = sub_00526940_UnicodeStrStr(pString, pPattern); pFound && pFound[nLength].wChar; pFound = sub_00526940_UnicodeStrStr(pString, pPattern))
    {
        memmove(pFound, &pFound[nLength + 1], (sub_00526800(pFound) - nLength) * sizeof(Unicode));
    }
}

// 0x0044B5E0
int __stdcall sub_0044B5E0_SaveDefaultCmdLine(D2CmdLineArgStrc* pArg, int nUnused)
{
    return SRegSaveString("Diablo II", "Default Command Line", 0, pArg->szValue);
}

// 0x0044BDF0
void D2TickValueStrc::sub_0044BDF0_Set(int nValue)
{
    dwTickCount = GetTickCount();
    this->nValue = nValue;
}

// 0x0044BF40
void __stdcall sub_0044BF40_ClickMapMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_0070F234 = 4;
    gdwGlobal_007A0658 = 0;
    sub_00466FF0();
    if (gdwGlobal_007A061C)
    {
        gdwGlobal_007A0650 = 1;
        D2UnitStrc* pPlayer = sub_00463DD0();
        int nFlags = 0;
        if (gdwGlobal_007A065C)
            nFlags = 8;
        if (gdwGlobal_007A0660)
            nFlags |= 8;
        if (gdwGlobal_007A0664)
            nFlags |= 4;
        if (pPlayer && pPlayer->dwUnitType == 0)
        {
            gdwGlobal_007A0650 = sub_00462D00(0, pMsg->nXpos, pMsg->nYpos, nFlags);
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C370
void __stdcall sub_0044C370_ClickMapMsgMode5(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_0070F2BC = 0x10;
    gdwGlobal_007A0654 = 0;
    gdwGlobal_007A0670 = 1;
    gdwGlobal_007A0658 = 0;
    sub_00466FF0();
    if (gdwGlobal_007A061C)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        if (pPlayer && pPlayer->dwUnitType == 0)
        {
            gdwGlobal_007A0654 = sub_00462D00(5, pMsg->nXpos, pMsg->nYpos, pMsg->nWParamLo);
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C400
void __stdcall sub_0044C400_WheelMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007A061C)
    {
        gdwGlobal_007A06F8 += pMsg->nWParamHi;
        if (abs(gdwGlobal_007A06F8) >= 120)
        {
            sub_004693B0(gdwGlobal_007A06F8 / 120);
            gdwGlobal_007A06F8 = 0;
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C470
void __stdcall sub_0044C470_Call469270Msg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007A061C)
    {
        sub_00469270();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C4A0
void __stdcall sub_0044C4A0_Call469230Msg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007A061C)
    {
        sub_00469230();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C4D0
void __stdcall sub_0044C4D0_HiWordDispatchMsgA(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007A061C)
    {
        unsigned short nCode = pMsg->nWParamHi;
        if (nCode == 1)
            sub_004692B0();
        else if (nCode == 2)
            sub_00469330();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C520
void __stdcall sub_0044C520_HiWordDispatchMsgB(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007A061C)
    {
        unsigned short nCode = pMsg->nWParamHi;
        if (nCode == 1)
            sub_004692F0();
        else if (nCode == 2)
            sub_00469370();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C570
void __stdcall sub_0044C570_SysCommandMsg(SMSGHANDLER_PARAMS* pMsg)
{
    unsigned short nCommand = pMsg->nWParamLo & 0xFFF0;
    if (nCommand == 0xF130 || nCommand == 0xF100 || (nCommand == 0xF010 && sub_004F5A30()))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C5C0
void __stdcall sub_0044C5C0_DefaultMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0044D0A0
void __stdcall sub_0044D0A0_IncCounterMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gnGlobal_007A060D += 1;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0044D0D0
void __stdcall sub_0044D0D0_IncCounterNoRepeatMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!(pMsg->lParam & 0x40000000))
        gnGlobal_007A060D += 1;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0044DBE0
void __cdecl sub_0044DBE0_ReadColorFlag()
{
    if (gdwGlobal_007A05FC == 0)
    {
        void* hFile;
        if (ARCHIVE_OpenFile(0, "Data\\Local\\Color.txt", &hFile, 1))
        {
            char nFlag;
            ARCHIVE_ReadFileToBuffer(0, hFile, &nFlag, 1);
            ARCHIVE_CloseFile(0, hFile);
            if (nFlag == '1')
                gdwGlobal_007A05FC = 1;
        }
    }
}

// 0x0044E0B0
void __stdcall sub_0044E0B0_ToggleMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_007A065C = 0;
    if (gdwGlobal_007A0620)
    {
        sub_00453DE0();
        sub_00467A00();
        pMsg->bReturn = 0;
        return;
    }
    sub_00477EE0();
    gdwGlobal_007A0674 = 1;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

int gnClientState_007A0480; // 0x007A0480

int gdwGlobal_007A2784; // 0x007A2784

// 0x0044BE60
void __fastcall sub_0044BE60_SetFlag(int nValue)
{
    gdwGlobal_007A065C = nValue;
}

// 0x0044C930
void __fastcall sub_0044C930_SetClientState(int nState)
{
    gnClientState_007A0480 = nState;
    gpfnClientCallback_007A0484 = gpfnClientCallbacks_0070EF0C[nState];
}

// 0x004519A0
void __cdecl sub_004519A0_ToggleFlags()
{
    if (gdwGlobal_007A2784)
        gdwGlobal_007A2784 = 0;
    else
        gdwGlobal_007A277C = 1;
}

// 0x00451F20
void __cdecl sub_00451F20_RegisterWindowHandlers()
{
    sub_00420320_RegisterHandlers(sub_004F59A0());
}

// 0x0044C100
static __forceinline int sub_0044C100_IsInLeftPanel(int nX, int nY)
{
    int bLeftPanel = 0;
    if (sub_0045AE90() == 2 && nX > 0 && nX < gnGlobal_0071146C / 2 && nY > 0 && nY < gnGlobal_00711470 - 0x2F)
    {
        bLeftPanel = 1;
    }
    return bLeftPanel;
}

// 0x0044C140
static __forceinline int sub_0044C140_IsInRightPanel(int nX, int nY)
{
    int bRightPanel = 0;
    if (sub_0045AE90() == 1 && nX > gnGlobal_0071146C / 2 && nX < gnGlobal_0071146C && nY > 0 && nY < gnAutomapHeight_007A521C)
    {
        bRightPanel = 1;
    }
    return bRightPanel;
}

// 0x0044C340
void __cdecl sub_0044C340_ResetClickState()
{
    gdwGlobal_0070F2BC = 0x10;
    gdwGlobal_007A0654 = 0;
    gdwGlobal_007A0670 = 1;
    gdwGlobal_007A0658 = 0;
    sub_00466FF0();
}

// 0x0044C6A0
void __cdecl sub_0044C6A0_Nothing()
{
}

// 0x0044C6B0
void __cdecl sub_0044C6B0()
{
    if (gdwGlobal_007A061C && !sub_00456300_CloseUIVars(0, 1))
    {
        sub_00457640(0);
        sub_00456300_CloseUIVars(1, 0);
    }
}

// 0x0044C950
unsigned int __cdecl sub_0044C950_GetLevelBlankScreen()
{
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (!pRoom)
    {
        return 0;
    }

    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pLevelsTxtRecord, 0x5DE);
    return pLevelsTxtRecord->dwBlankScreen;
}

// 0x0044CD40
void __cdecl sub_0044CD40_ResetTimer()
{
    gdwGlobal_007A04B8 = gdwGlobal_007A048C;
    gdwGlobal_007A04A8 = 0x19;
    gdwGlobal_007A04B0 = 0;
    gdwGlobal_007A04AC = 0;
    gdwGlobal_007A04B4 = 0;
}

int __fastcall sub_M118_Emit_0044C100(int nX, int nY)
{
    const int bLeftPanel = sub_0044C100_IsInLeftPanel(nX, nY);
    const int bRightPanel = sub_0044C140_IsInRightPanel(nX, nY);
    return bLeftPanel || bRightPanel;
}

// 0x0044D320
static __declspec(noinline) int __stdcall sub_0044D320_IsMouseInRect(int nX, int nY, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX < nX || nMouseX > nX + nWidth || nMouseY < nY - nHeight || nMouseY > nY)
    {
        return 0;
    }
    return 1;
}

int __stdcall sub_K02_EmitIsMouseInRect(int nX, int nY, int nWidth, int nHeight)
{
    return sub_0044D320_IsMouseInRect(nX, nY, nWidth, nHeight);
}

// 0x0044D360
void __stdcall sub_0044D360_UpdateMessage(void* pMsg)
{
    int nOne = 1;
    if ((*(int*)((char*)pMsg + 0x0C) & 0x40000000) == 0)
        gnGlobal_007A0608 = nOne;
    *(int*)((char*)pMsg + 0x18) = nOne;
    *(int*)((char*)pMsg + 0x1C) = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

int gdwGlobal_007A05FC; // 0x007A05FC

// 0x0044D730
void __fastcall sub_0044D730_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D740
void __fastcall sub_0044D740_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D750
void __fastcall sub_0044D750_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D7C0
void __fastcall sub_0044D7C0_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D7F0
void __fastcall sub_0044D7F0_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D800
void __fastcall sub_0044D800_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D810
void __fastcall sub_0044D810_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D820
void __fastcall sub_0044D820_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D830
void __fastcall sub_0044D830_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D880
void __fastcall sub_0044D880_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D920
void __fastcall sub_0044D920_ApplyConfigSetFlag(D2ConfigStrc* pConfig)
{
    sub_0047A9B0_SetFlag712EFC(0);
}

// 0x0044D930
void __fastcall sub_0044D930_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D940
void __fastcall sub_0044D940_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D950
void __fastcall sub_0044D950_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D980
void __fastcall sub_0044D980_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D990
void __fastcall sub_0044D990_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D9E0
void __fastcall sub_0044D9E0_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044DC40
void __cdecl sub_0044DC40_ToggleGlobal()
{
    gdwGlobal_007A05FC = !gdwGlobal_007A05FC;
}

void* gpComInterface_007A05F4; // 0x007A05F4

// 0x0044D760
void __fastcall sub_0044D760_ApplyConfigWindow(D2ConfigStrc* pConfig)
{
    if (pConfig->bWindow)
        sub_004776E0();
}

// 0x0044D770
void __fastcall sub_0044D770_ApplyConfigNoFixAspect(D2ConfigStrc* pConfig)
{
    if (pConfig->bNoFixedAspect)
        sub_004F5280();
}

// 0x0044D780
void __fastcall sub_0044D780_ApplyConfig3DFX(D2ConfigStrc* pConfig)
{
    if (pConfig->b3DFX)
        sub_004776F0();
}

// 0x0044D790
void __fastcall sub_0044D790_ApplyConfigOpenGL(D2ConfigStrc* pConfig)
{
    if (pConfig->bOpenGL)
        sub_00477700();
}

// 0x0044D7A0
void __fastcall sub_0044D7A0_ApplyConfigD3D(D2ConfigStrc* pConfig)
{
    if (pConfig->bD3D)
        sub_00477710();
}

// 0x0044D7B0
void __fastcall sub_0044D7B0_ApplyConfigRave(D2ConfigStrc* pConfig)
{
    if (pConfig->bRave)
        sub_00477720();
}

// 0x0044D7D0
void __fastcall sub_0044D7D0_ApplyConfigGamma(D2ConfigStrc* pConfig)
{
    if (pConfig->dwGamma)
        sub_004776C0(pConfig->dwGamma);
}

// 0x0044D7E0
void __fastcall sub_0044D7E0_ApplyConfigVSync(D2ConfigStrc* pConfig)
{
    if (pConfig->bVSync)
        D2GFX_EnableVSync();
}

// 0x0044D840
void __fastcall sub_0044D840_ApplyConfigLog(D2ConfigStrc* pConfig)
{
    if (pConfig->bLog)
        sub_00624B50(1);
}

// 0x0044D860
void __fastcall sub_0044D860_ApplyConfigSeed(D2ConfigStrc* pConfig)
{
    if (pConfig->dwSeed)
        GAME_SetInitSeed(pConfig->dwSeed);
}

// 0x0044D900
void __fastcall sub_0044D900_ApplyConfigRealm(D2ConfigStrc* pConfig)
{
    SStrCopy(gszRealm_007A0500, pConfig->szRealm, 0x20);
}

// 0x0044D960
void __fastcall sub_0044D960_ApplyConfigCTemp(D2ConfigStrc* pConfig)
{
    sub_0047AA10(pConfig->nCTemp);
}

// 0x0044D970
void __fastcall sub_0044D970_ApplyConfigComInterface(D2ConfigStrc* pConfig)
{
    if (pConfig->pComInterface)
        gpComInterface_007A05F4 = pConfig->pComInterface;
}

// 0x0044D9A0
void __fastcall sub_0044D9A0_ApplyConfigNoCompress(D2ConfigStrc* pConfig)
{
    if (pConfig->bNoCompress)
        D2CMP_SetCompressedDataMode(pConfig->bNoCompress);
}

// 0x0044D9C0
void __fastcall sub_0044D9C0_ApplyConfigTxt(D2ConfigStrc* pConfig)
{
    sub_006125A0(!pConfig->bTxt);
}

int gdwGlobal_007A0674; // 0x007A0674

// 0x0044DD60
void __cdecl sub_0044DD60()
{
    sub_0044B880_SetValue(0);
    gdwGlobal_007A0674 = 1;
    sub_00477EE0();
    gdwGlobal_007A0620 = 1;
}

// 0x0044DD90
D2StormLinkStrc* D2StormLinkStrc::sub_0044DD90_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0044DE10
D2StormListAStrc* D2StormListArrayStrc::sub_0044DE10_At(unsigned int nIndex)
{
    return &f_8[nIndex];
}

// 0x0044DE60
D2StormLinkStrc* D2StormLinkStrc::sub_0044DE60_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0044DF30
unsigned int D2StormListArrayStrc::sub_0044DF30_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x15)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    f_C = 0x15;
    return 0x15;
}

// 0x0044DF70
unsigned int __stdcall sub_0044DF70_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x0044DF90
void D2StormListAStrc::sub_0044DF90_CopyLinkOffset(const D2StormListAStrc* pSource)
{
    m_linkoffset = pSource->m_linkoffset;
    InitializeTerminator();
}

// 0x0044ED20
D2StormLinkStrc* D2StormListAStrc::sub_0044ED20_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
}

// 0x0044EDA0
D2StormLinkStrc* D2StormListBStrc::sub_0044EDA0_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
}

// 0x0044EDC0
void D2StormListAStrc::sub_0044EDC0_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x0044EE10
void D2StormListAStrc::sub_0044EE10_InitLinkField(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x0044EE30
void D2StormListBStrc::sub_0044EE30_InitLinkField(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x0044EE90
D2StormListAStrc::D2StormListAStrc(const D2StormListAStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0044F890
void D2StormListBStrc::sub_0044F890_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x0044F980
void D2StormListAStrc::sub_0044F980_ChangeLinkOffset(int nLinkOffset)
{
    if (nLinkOffset != m_linkoffset)
    {
        UnlinkAll();
        m_linkoffset = nLinkOffset;
        InitializeTerminator();
    }
}

// 0x0044FA00
void D2StormHashTableStrc::sub_0044FA00_InternalClear(int bWarn)
{
    m_fullnessIndicator = 0;
    m_fulllist.UnlinkAll();
    for (unsigned int i = 0; i < m_slotlistarray.f_4; i++)
    {
        char* pNode;
        while ((pNode = m_slotlistarray.f_8[i].Head()) != 0)
        {
            if (bWarn)
                m_slotlistarray.f_8[i].Link(pNode)->Unlink();
            else
                InternalDelete(pNode);
        }
    }
}

// 0x0044FB80
D2StormListBStrc::D2StormListBStrc(const D2StormListBStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0044DDC0
char* __fastcall sub_0044DDC0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x0044DE30
char* __fastcall sub_0044DE30_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x0044DF00
void __fastcall sub_0044DF00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x0044DF20
void __fastcall sub_0044DF20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x0044DFB0
unsigned int D2TickTimerStrc::sub_0044DFB0_GetRemaining()
{
    unsigned int dwNow = GetTickCount();
    if (dwNow >= dwStart + dwDuration)
    {
        dwStart = 0;
        dwDuration = 0;
        return 0;
    }
    return dwStart + dwDuration - dwNow;
}

// 0x0040F7D0
sub_0040F7D0::~sub_0040F7D0()
{
    f_0.Unlink();
}

// 0x00417810
sub_00417810::~sub_00417810()
{
    f_0.Unlink();
}

// 0x00417860
sub_00417860::~sub_00417860()
{
    f_0.Unlink();
}

// 0x004178C0
sub_004178C0::~sub_004178C0()
{
    f_0.Unlink();
}

// 0x00417900
sub_00417900::~sub_00417900()
{
    f_0.Unlink();
}

// 0x00417950
sub_00417950::~sub_00417950()
{
    f_0.Unlink();
}

// 0x004179B0
sub_004179B0::~sub_004179B0()
{
    f_0.Unlink();
}

// 0x004183F0
sub_004183F0::~sub_004183F0()
{
    f_0.Unlink();
}

// 0x00418430
sub_00418430::~sub_00418430()
{
    f_0.Unlink();
}

// 0x00418780
sub_00418780::~sub_00418780()
{
    f_0.Unlink();
}

// 0x004187C0
sub_004187C0::~sub_004187C0()
{
    f_0.Unlink();
}

// 0x00418800
sub_00418800::~sub_00418800()
{
    f_0.Unlink();
}

// 0x00418840
sub_00418840::~sub_00418840()
{
    f_0.Unlink();
}

// 0x00418880
sub_00418880::~sub_00418880()
{
    f_0.Unlink();
}

// 0x004188C0
sub_004188C0::~sub_004188C0()
{
    f_0.Unlink();
}

// 0x00418BA0
sub_00418BA0::~sub_00418BA0()
{
    f_0.Unlink();
}

// 0x00418BE0
sub_00418BE0::~sub_00418BE0()
{
    f_0.Unlink();
}

// 0x00418C20
sub_00418C20::~sub_00418C20()
{
    f_0.Unlink();
}

// 0x00418E10
sub_00418E10::~sub_00418E10()
{
    f_0.Unlink();
}

// 0x0041C3D0
sub_0041C3D0::~sub_0041C3D0()
{
    f_0.Unlink();
}

// 0x0041C500
sub_0041C500::~sub_0041C500()
{
    f_0.Unlink();
}

// 0x0041C730
sub_0041C730::~sub_0041C730()
{
    f_0.Unlink();
}

// 0x0041C800
sub_0041C800::~sub_0041C800()
{
    f_0.Unlink();
}

// 0x00420430
sub_00420430::~sub_00420430()
{
    f_0.Unlink();
}

// 0x004204B0
sub_004204B0::~sub_004204B0()
{
    f_0.Unlink();
}

// 0x00420710
sub_00420710::~sub_00420710()
{
    f_0.Unlink();
}

// 0x004207E0
sub_004207E0::~sub_004207E0()
{
    f_0.Unlink();
}

// 0x00426960
sub_00426960::~sub_00426960()
{
    f_0.Unlink();
}

// 0x00426A80
sub_00426A80::~sub_00426A80()
{
    f_0.Unlink();
}

// 0x00426CB0
sub_00426CB0::~sub_00426CB0()
{
    f_0.Unlink();
}

// 0x00426D80
sub_00426D80::~sub_00426D80()
{
    f_0.Unlink();
}

// 0x0044DDD0
sub_0044DDD0::~sub_0044DDD0()
{
    f_0.Unlink();
}

// 0x0044DE90
sub_0044DE90::~sub_0044DE90()
{
    f_0.Unlink();
}

// 0x0044ECC0
sub_0044ECC0::~sub_0044ECC0()
{
    f_0.Unlink();
}

// 0x0044ED50
sub_0044ED50::~sub_0044ED50()
{
    f_0.Unlink();
}

// 0x00601BF0
sub_00601BF0::~sub_00601BF0()
{
    f_0.Unlink();
}

// 0x00601C70
sub_00601C70::~sub_00601C70()
{
    f_0.Unlink();
}

// 0x00601D60
sub_00601D60::~sub_00601D60()
{
    f_0.Unlink();
}

// 0x00601F20
sub_00601F20::~sub_00601F20()
{
    f_0.Unlink();
}

// 0x00601F60
sub_00601F60::~sub_00601F60()
{
    f_0.Unlink();
}

// 0x006020D0
sub_006020D0::~sub_006020D0()
{
    f_0.Unlink();
}

// 0x00602140
sub_00602140::~sub_00602140()
{
    f_0.Unlink();
}

// 0x006024A0
sub_006024A0::~sub_006024A0()
{
    f_0.Unlink();
}

// 0x00602760
sub_00602760::~sub_00602760()
{
    f_0.Unlink();
}

// 0x00417780
sub_00417780::sub_00417780()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00417850
sub_00417850::sub_00417850()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x004178B0
sub_004178B0::sub_004178B0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00417940
sub_00417940::sub_00417940()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00417990
sub_00417990::sub_00417990()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418760
sub_00418760::sub_00418760()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418770
sub_00418770::sub_00418770()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418A40
sub_00418A40::sub_00418A40()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418DE0
sub_00418DE0::sub_00418DE0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418DF0
sub_00418DF0::sub_00418DF0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418E00
sub_00418E00::sub_00418E00()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418E50
sub_00418E50::sub_00418E50()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418FF0
sub_00418FF0::sub_00418FF0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00419060
sub_00419060::sub_00419060()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0041C4F0
sub_0041C4F0::sub_0041C4F0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0041C720
sub_0041C720::sub_0041C720()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0041C7F0
sub_0041C7F0::sub_0041C7F0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x004204A0
sub_004204A0::sub_004204A0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00420700
sub_00420700::sub_00420700()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x004207D0
sub_004207D0::sub_004207D0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00426CA0
sub_00426CA0::sub_00426CA0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00426D70
sub_00426D70::sub_00426D70()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0044BDE0
sub_0044BDE0::sub_0044BDE0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0044ED40
sub_0044ED40::sub_0044ED40()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0044ED90
sub_0044ED90::sub_0044ED90()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00601F10
sub_00601F10::sub_00601F10()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00602130
sub_00602130::sub_00602130()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00602180
sub_00602180::sub_00602180()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00602420
sub_00602420::sub_00602420()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00602750
sub_00602750::sub_00602750()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

bool D2ChatStormLinkStrc::sub_0060E0C0_IsLinked()
{
    return m_next != 0;
}

char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

char* D2ChatStormNodeStrc::sub_0060E0B0_GetKey()
{
    return f_14;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::sub_0060E230_Count()
{
    return f_4;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::sub_0060E250_Count()
{
    return f_4;
}

void D2ChatStormListAStrc::sub_0060E260_InitializeTerminator()
{
    InitializeTerminator();
}

void D2ChatStormListBStrc::sub_0060E270_InitializeTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::sub_0060E5D0_Head()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::sub_0060E610_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x0044DED0
char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::sub_0060E6D0_Head()
{
    return m_fulllist.m_terminator.MaskNext();
}

D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, gszIgnoreListSourceFile_006E6290, 0x11, 0);
}

void D2CommonStringEntryNodeStrc::sub_0060EE30_Destroy()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::sub_0060ED60_Clear()
{
    sub_0060EB70_InternalClear(0);
}

int gdwGlobal_007A0600; // 0x007A0600

// 0x0044EC50
void __cdecl sub_0044EC50_ResetBetaScreen()
{
    gdwGlobal_007A0600 = 1;
    gnBetaScreenIndex_007A060D = 0;
    sub_00477EE0();
    gdwGlobal_007A0620 = 1;
}

static int gdwGlobal_007A0604; // 0x007A0604

// 0x0044EC80
void __cdecl sub_0044EC80_SetDifficultyFlags()
{
    gdwGlobal_007A0604 = 1;
    gpClientInfo_007A0438->wFlags = ((gnDifficulty_007A060C + 1) << 10) | (gpClientInfo_007A0438->wFlags & 0xE0FF);
}

// 0x0044ED00
char* D2ChatStormListAStrc::sub_0060E440_Head()
{
    return m_terminator.MaskNext();
}

// 0x0044EE50
void D2ChatStormListAStrc::sub_0060E5F0_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}
