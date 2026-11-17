struct D2SlotStrc
{
    int f_0;
    int nType;
    char unk0x08[0x18];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int gdwGlobal_007C8A70;                                                                                     // 0x007C8A70
extern D2SlotStrc gaSlots_007C8A78[16];                                                                     // 0x007C8A78
extern int gdwGlobal_007C8C78;                                                                              // 0x007C8C78
int __cdecl sub_00513B50();                                                                                 // 0x00513B50
int __cdecl sub_00513B60();                                                                                 // 0x00513B60
int __fastcall sub_00513B70_IsSoundEnvironEnabled();                                                        // 0x00513B70
int __fastcall sub_00514C90_GetSoundMode();                                                                 // 0x00514C90
void __fastcall sub_00514CA0(int nMode);                                                                    // 0x00514CA0
int __fastcall sub_00515530(int nType, int nArg);                                                           // 0x00515530
void __fastcall sub_004DF6C0(int nArg);                                                                     // 0x004DF6C0
void __cdecl sub_004DFA60();                                                                                // 0x004DFA60

// 0x004DFAA0
static int sub_004DFAA0_InitSoundChannels(int nMode)
{
    if (!sub_00513B50())
        return 0;

    D2_ASSERT(!gdwGlobal_007C8C78, 204);

    for (int i = 0; i < 16; ++i)
    {
        gaSlots_007C8A78[i].nType = 0;
        if (i < 4)
            gaSlots_007C8A78[i].nType = 1;
        else if (nMode == 1)
            gaSlots_007C8A78[i].nType = 2;
        else
            gaSlots_007C8A78[i].nType = nMode == 2 ? 6 : 0;

        gaSlots_007C8A78[i].f_0 = sub_00515530(gaSlots_007C8A78[i].nType, gdwGlobal_007C8A70);
        if (!gaSlots_007C8A78[i].f_0)
        {
            sub_004DFA60();
            return 0;
        }
    }

    sub_004DF6C0(0);
    gdwGlobal_007C8C78 = 1;
    return 1;
}

// 0x004E0000
int __fastcall sub_004E0000_SetSoundMode(int nMode)
{
    if (nMode == 1 && !sub_00513B60())
        return 0;

    if (nMode == 2 && !sub_00513B70_IsSoundEnvironEnabled())
        return 0;

    sub_004DFA60();
    if (!sub_004DFAA0_InitSoundChannels(nMode))
        return 0;

    if (sub_00514C90_GetSoundMode() != nMode)
        sub_00514CA0(nMode);

    return 1;
}

// 0x004E0050
void __fastcall sub_004E0050_RestartSound(int nArg)
{
    gdwGlobal_007C8A70 = nArg;
    if (!sub_004E0000_SetSoundMode(sub_00514C90_GetSoundMode()))
        sub_004E0000_SetSoundMode(0);
}
