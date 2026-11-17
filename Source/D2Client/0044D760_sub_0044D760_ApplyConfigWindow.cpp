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

extern char gszRealm_007A0500[];                                                                            // 0x007A0500
void* gpComInterface_007A05F4;                                                                              // 0x007A05F4

void __cdecl sub_004776E0();                                                                                // 0x004776E0
void __cdecl sub_004F5280();                                                                                 // 0x004F5280
void __cdecl sub_004776F0();                                                                                // 0x004776F0
void __cdecl sub_00477700();                                                                                // 0x00477700
void __cdecl sub_00477710();                                                                                // 0x00477710
void __cdecl sub_00477720();                                                                                // 0x00477720
void __fastcall sub_004776C0(int nGamma);                                                                   // 0x004776C0
void __cdecl D2GFX_EnableVSync();                                                                           // 0x004F5270
void __fastcall sub_00624B50(int nValue);                                                                   // 0x00624B50
void __stdcall GAME_SetInitSeed(int nInitSeed);                                                             // 0x0052C320
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
void __fastcall sub_0047AA10(int nValue);                                                                   // 0x0047AA10
void __stdcall D2CMP_SetCompressedDataMode(int bCompress);                                                  // 0x005FE280
void __stdcall sub_006125A0(int bValue);                                                                    // 0x006125A0

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
