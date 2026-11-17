struct D2BitBufferStrc;

#pragma pack(push, 1)
struct D2QuestPanelEntryStrc
{
    int nQuestId;
    char unk0x004[0x265 - 0x004];
    int bDone;
    char unk0x269[0x26A - 0x269];
};
#pragma pack(pop)

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg);                          // 0x004785B0
D2BitBufferStrc* __cdecl sub_004B32D0();                                                           // 0x004B32D0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

extern int gnGlobal_007BF298;                                                                               // 0x007BF298
int gnQuestCount_007BF2A0;                                                                                  // 0x007BF2A0
extern int gnGlobal_007BF2A4;                                                                               // 0x007BF2A4
extern int gnGlobal_007BF2AC;                                                                               // 0x007BF2AC
extern char gbGlobal_007BF2B0;                                                                              // 0x007BF2B0
extern char gbGlobal_007BF2B1;                                                                              // 0x007BF2B1
extern char gbGlobal_007BF2B2;                                                                              // 0x007BF2B2
extern char gbGlobal_007BF2B3;                                                                              // 0x007BF2B3
extern char gbGlobal_007BF2B4;                                                                              // 0x007BF2B4
extern int gnIndex_007BF2B5;                                                                                // 0x007BF2B5
extern int gnIndex_007BF2BD;                                                                                // 0x007BF2BD
extern int gnIndex_007BF2C1;                                                                                // 0x007BF2C1
extern int gnIndex_007BF2C5;                                                                                // 0x007BF2C5
extern int gnIndex_007BF2C9;                                                                                // 0x007BF2C9
extern int gnIndex_007BF2CD;                                                                                // 0x007BF2CD
extern void* gpCelFile_007BF2D1;                                                                            // 0x007BF2D1
extern void* gpCelFile_007BF2D5;                                                                            // 0x007BF2D5
extern void* gpCelFile_007BF2D9;                                                                            // 0x007BF2D9
extern void* gpCelFile_007BF2DD;                                                                            // 0x007BF2DD
extern void* gapCelFiles_007BF2E1[27];                                                                      // 0x007BF2E1
extern void* gpCelFile_007BF34D;                                                                            // 0x007BF34D
extern void* gpCelFile_007BF351;                                                                            // 0x007BF351
volatile char gabQuestFlagsA_007BF356[42];                                                                  // 0x007BF356
extern volatile char gabQuestFlagsB_007BF380[];                                                             // 0x007BF380
extern D2QuestPanelEntryStrc gaQuestEntries_007BF3AA[];                                                     // 0x007BF3AA
extern unsigned long gnGlobal_007C0259;                                                                     // 0x007C0259
extern char gbGlobal_007C025D;                                                                              // 0x007C025D
extern char gbGlobal_007C025E;                                                                              // 0x007C025E
extern char gbGlobal_007C025F;                                                                              // 0x007C025F
extern char gbGlobal_007C0260;                                                                              // 0x007C0260

// 0x004A2550
void __cdecl sub_004A2550_FreeQuestCels()
{
    if (gpCelFile_007BF2D5)
    {
        sub_00478A00(gpCelFile_007BF2D5);
        gpCelFile_007BF2D5 = 0;
    }
    if (gpCelFile_007BF2D9)
    {
        sub_00478A00(gpCelFile_007BF2D9);
        gpCelFile_007BF2D9 = 0;
    }
    if (gpCelFile_007BF34D)
    {
        sub_00478A00(gpCelFile_007BF34D);
        gpCelFile_007BF34D = 0;
    }
    if (gpCelFile_007BF2D1)
    {
        sub_00478A00(gpCelFile_007BF2D1);
        gpCelFile_007BF2D1 = 0;
    }
    if (gpCelFile_007BF2DD)
    {
        sub_00478A00(gpCelFile_007BF2DD);
        gpCelFile_007BF2DD = 0;
    }
    if (gpCelFile_007BF351)
    {
        sub_00478A00(gpCelFile_007BF351);
        gpCelFile_007BF351 = 0;
    }
    for (int i = 0; i < 27; ++i)
    {
        if (gapCelFiles_007BF2E1[i])
        {
            sub_00478A00(gapCelFiles_007BF2E1[i]);
            gapCelFiles_007BF2E1[i] = 0;
        }
    }
}

// 0x004A2600
void __cdecl sub_004A2600_FreeQuestPanel()
{
    sub_004A2550_FreeQuestCels();
}

// 0x004A2760
void __cdecl sub_004A2760_SendQuestUpdates()
{
    for (int i = 0; i < gnQuestCount_007BF2A0; ++i)
    {
        if (!gaQuestEntries_007BF3AA[i].bDone)
        {
            D2BitBufferStrc* pQuestInfo = sub_004B32D0();
            QUESTRECORD_SetQuestState(pQuestInfo, gaQuestEntries_007BF3AA[i].nQuestId, 0xC);
            sub_004785B0_SendPacket3(0x58, (unsigned short)gaQuestEntries_007BF3AA[i].nQuestId);
        }
    }
}

// 0x004A3020
void __cdecl sub_004A3020_ClearQuestFlags()
{
    for (int i = 0; i < 41; ++i)
    {
        gabQuestFlagsA_007BF356[i] = 0;
        gabQuestFlagsB_007BF380[i] = 0;
    }
}

// 0x004A3410
void __cdecl sub_004A3410_ResetQuestPanel()
{
    SRegSaveValue("Diablo II", "GAMEOVER", 0, 0);
    gnGlobal_007BF298 = 0;
    gpCelFile_007BF2D5 = 0;
    gpCelFile_007BF2D9 = 0;
    gpCelFile_007BF2D1 = 0;
    gpCelFile_007BF2DD = 0;
    gpCelFile_007BF351 = 0;
    gpCelFile_007BF34D = 0;
    memset(gapCelFiles_007BF2E1, 0, sizeof(gapCelFiles_007BF2E1));
    gnGlobal_007BF2A4 = 0;
    gnGlobal_007BF2AC = 0;
    gnGlobal_007C0259 = 0;
    for (int i = 0; i < 41; ++i)
    {
        gabQuestFlagsA_007BF356[i] = 0;
        gabQuestFlagsB_007BF380[i] = 0;
    }
    gbGlobal_007BF2B1 = 0;
    gbGlobal_007BF2B2 = 0;
    gbGlobal_007BF2B0 = 0;
    gbGlobal_007BF2B4 = 0;
    gbGlobal_007C025D = 0;
    gbGlobal_007C025E = 0;
    gbGlobal_007C025F = 0;
    gbGlobal_007C0260 = 0;
    gbGlobal_007BF2B3 = 0;
    gnIndex_007BF2B5 = -1;
    gnIndex_007BF2BD = -1;
    gnIndex_007BF2C1 = -1;
    gnIndex_007BF2C5 = -1;
    gnIndex_007BF2C9 = -1;
    gnIndex_007BF2CD = -1;
}
