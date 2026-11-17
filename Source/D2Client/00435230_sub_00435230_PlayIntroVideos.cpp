extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2LaunchRecordStrc
{
    char unk0x000[0x35F];
    char bFlag35F;
};

extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4

void __stdcall D2Win_10029(int a1);                                                                         // 0x004FA410
void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
void __cdecl sub_004317D0_FlushInput();                                                                     // 0x004317D0
int __cdecl sub_004F9050();                                                                                 // 0x004F9050
int __cdecl sub_0040EB10();                                                                                 // 0x0040EB10
void __stdcall WINDOW_OpenSmackCutscene(const char* szFile, int nResolution, void* pfFrame);                // 0x004F5D90
int __cdecl sub_0042FA40_InitAuxBattleNet();                                                                // 0x0042FA40
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq);    // 0x0041BA60
void __cdecl sub_00433640_ShowVersionText();                                                                // 0x00433640
int __stdcall SFileCloseArchive(void* hMpq);                                                                // 0x00419A80
void __stdcall D2Win_10004(int nResolution);                                                                // 0x004F9060
void __cdecl sub_0042FB20();                                                                                // 0x0042FB20
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __cdecl sub_0042FAB0_GetAuxFlag();                                                                      // 0x0042FAB0
void __cdecl sub_004334E0_PlayIntro();                                                                      // 0x004334E0

// 0x00435230
void __cdecl sub_00435230_PlayIntroVideos()
{
    D2_ASSERT(!gpLaunchRecord_007795D4->bFlag35F, 0x8D4);
    D2Win_10029(0);
    sub_0042F480_Reset();
    sub_004317D0_FlushInput();
    if (sub_004F9050())
    {
        if (!sub_0040EB10())
        {
            WINDOW_OpenSmackCutscene("Data\\Local\\Video\\New_BLIZ640x480.bik", 0, 0);
            WINDOW_OpenSmackCutscene("Data\\Local\\Video\\BlizNorth640x480.bik", 0, 0);
        }
        else
        {
            WINDOW_OpenSmackCutscene("Data\\Local\\Video\\New_BLIZ640x240.bik", 2, 0);
            WINDOW_OpenSmackCutscene("Data\\Local\\Video\\BlizNorth640x240.bik", 2, 0);
        }
        if (!sub_0042FA40_InitAuxBattleNet())
        {
            void* hMpq = 0;
            SFileOpenArchive("d2video.mpq", 0x64, 0, &hMpq);
            if (hMpq)
            {
                sub_00433640_ShowVersionText();
                SFileCloseArchive(hMpq);
            }
        }
        else
        {
            if (sub_00408F20_HasExpansionMpq() && sub_0042FAB0_GetAuxFlag())
                sub_004334E0_PlayIntro();
        }
    }
    D2Win_10004(1);
    sub_0042FB20();
}
