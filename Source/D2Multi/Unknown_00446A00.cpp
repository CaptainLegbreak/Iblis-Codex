#ifdef MOVED_TEST
#define BUFFER_SIZE 0x104
#define COMMAND_DELAY 1004
#define ERROR_STRING 0x14EB
#else
#define BUFFER_SIZE 0x100
#define COMMAND_DELAY 1000
#define ERROR_STRING 0x14E7
#endif
struct D2WinEditBoxStrc;
typedef int (__stdcall* D2LaunchCallback)(int nArg);
struct Unicode
{
    unsigned short wChar;
};

struct D2LaunchFuncsStrc
{
#ifdef MOVED_TEST
    char movedPrefix[4];
#endif
    char unk0x00[0x14];
    int (__fastcall* pfn0x14)(void* pBuffer);
    char unk0x18[0x50];
    int (__fastcall* pfn0x68)();
};
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_004FF5A0(D2WinEditBoxStrc* pEditBox, const Unicode* pText);                               // 0x004FF5A0
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone);                     // 0x00440140
int __stdcall sub_0043E6C0_OnError(int nArg);                                                               // 0x0043E6C0
extern D2WinEditBoxStrc* gpChatEditBox_0077BD94;  // 0x0077BD94
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;  // 0x0077B09C
static unsigned long s_dwLastCommandTick_00798F50;  // 0x00798F50

// 0x00446A00
int __stdcall sub_00446A00(int nUnused)
{
    char szText[BUFFER_SIZE];
    const unsigned long dwTick = GetTickCount();
    if (dwTick >= s_dwLastCommandTick_00798F50 + COMMAND_DELAY)
    {
        s_dwLastCommandTick_00798F50 = dwTick;
        sprintf(szText, "/away Away from the keyboard.");
        if (!gpLaunchFuncs_0077B09C->pfn0x68())
        {
            sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(ERROR_STRING), sub_0043E6C0_OnError);
            return 0;
        }
        gpLaunchFuncs_0077B09C->pfn0x14(szText);
        sub_004FF5A0(gpChatEditBox_0077BD94, 0);
    }
    return 1;
}
