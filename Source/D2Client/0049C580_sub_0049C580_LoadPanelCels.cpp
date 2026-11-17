struct D2CelStrc;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    void* pfnHandler;
};

struct D2ClientDialogStrc
{
    unsigned long dwTick;
    int unk0x04;
    void* pCelFile;
    int unk0x0C;
    int unk0x10;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    int unk0x24;
    int unk0x28;
    int unk0x2C;
    int unk0x30;
    int unk0x34;
    int unk0x38;
    int unk0x3C;
    int unk0x40;
    int unk0x44;
    int unk0x48;
    int unk0x4C;
    int unk0x50;
    int unk0x54;
    int unk0x58;
    int unk0x5C;
    int unk0x60;
    int unk0x64;
    char unk0x68[0xB08 - 0x68];
    int unk0xB08;
    D2ClientDialogStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __cdecl sub_0044DA40();                                                                                // 0x0044DA40
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void* __cdecl sub_00454600();                                                                               // 0x00454600
void __fastcall sub_004545C0(int bSet);                                                                     // 0x004545C0
void* __fastcall sub_004788B0_LoadCelFile(const char* szPath, int nArg);                                    // 0x004788B0
unsigned char __cdecl sub_00483350();                                                                       // 0x00483350
void __fastcall sub_004898D0(int nState);                                                                   // 0x004898D0
void __cdecl sub_004A43E0();                                                                                // 0x004A43E0
void __cdecl sub_004A5060();                                                                                // 0x004A5060
void __cdecl sub_004B7C60();                                                                                // 0x004B7C60
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, int eDrawMode); // 0x004F6300
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
D2CelStrc* __stdcall D2CMP_CelGetHandle(D2CelContextStrc* pContext);                                        // 0x00601840
int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0
void* __stdcall sub_0065C430(void* pMemPool);                                                               // 0x0065C430

extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern D2MsgHandlerEntryStrc gaMsgHandlers_007273E4[];                                                      // 0x007273E4
extern D2MsgHandlerEntryStrc gaMsgHandlers_007273F0[];                                                      // 0x007273F0
extern const char* gaszDialogCels_007274AC[];                                                               // 0x007274AC
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern void* gpCelFile_007BF071;                                                                            // 0x007BF071
extern void* gpCelFile_007BF075;                                                                            // 0x007BF075
extern void* gpCelFile_007BF079;                                                                            // 0x007BF079
extern void* gpCelFile_007BF274;                                                                            // 0x007BF274
extern void* gpCelFile_007BF2D1;                                                                            // 0x007BF2D1
extern void* gpCelFile_007BF2D5;                                                                            // 0x007BF2D5
extern void* gpCelFile_007BF2D9;                                                                            // 0x007BF2D9
extern void* gpCelFile_007BF2DD;                                                                            // 0x007BF2DD
extern void* gpCelFile_007BF34D;                                                                            // 0x007BF34D
extern void* gpCelFile_007BF351;                                                                            // 0x007BF351
extern int gnGlobal_007C02AC;                                                                               // 0x007C02AC
extern int gnGlobal_007C02B0;                                                                               // 0x007C02B0
extern void* gpCelFile_007C02BC;                                                                            // 0x007C02BC
char gaGlobal_007C0C68[1];                                                                                  // 0x007C0C68
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern void* gpGlobal_007C0D43;                                                                             // 0x007C0D43
extern void* gpGlobal_007C0D47;                                                                             // 0x007C0D47
extern int gnGlobal_007C0DBC;                                                                               // 0x007C0DBC
extern int gnGlobal_007C0DC0;                                                                               // 0x007C0DC0
extern void* gpCelFile_007C0DC8;                                                                            // 0x007C0DC8
extern void* gpCelFile_007C0DCC;                                                                            // 0x007C0DCC
extern char gbGlobal_007C0DE0;                                                                              // 0x007C0DE0
extern int gnGlobal_007C0DE9;                                                                               // 0x007C0DE9
extern int gnGlobal_007C0DED;                                                                               // 0x007C0DED
extern int gnGlobal_007C0DF1;                                                                               // 0x007C0DF1
extern void* gpCelFile_007C546C;                                                                            // 0x007C546C
static int gnGlobal_007C0E4C;                                                                               // 0x007C0E4C
static D2ClientDialogStrc* gpGlobal_007C0E54;                                                               // 0x007C0E54
static int gnGlobal_007C0E58;                                                                               // 0x007C0E58
static int gnGlobal_007C0E5C;                                                                               // 0x007C0E5C

// 0x0049C580
void __cdecl sub_0049C580_LoadPanelCels()
{
    char szPath[0x104];
    if (!gpCelFile_007BF071)
    {
        sprintf(szPath, "%s\\ui\\menu\\waygatebackground", szDataGlobal_006D4118);
        gpCelFile_007BF071 = sub_004788B0_LoadCelFile(szPath, 0);
    }
    if (!gpCelFile_007BF075)
    {
        if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
        {
            sprintf(szPath, "%s\\ui\\menu\\expwaygatetabs", szDataGlobal_006D4118);
        }
        else
        {
            sprintf(szPath, "%s\\ui\\menu\\waygatetabs", szDataGlobal_006D4118);
        }
        gpCelFile_007BF075 = sub_004788B0_LoadCelFile(szPath, 0);
    }
    if (!gpCelFile_007BF079)
    {
        sprintf(szPath, "%s\\ui\\menu\\waygateicons", szDataGlobal_006D4118);
        gpCelFile_007BF079 = sub_004788B0_LoadCelFile(szPath, 0);
    }
}

// 0x0049FA10
void __cdecl sub_0049FA10_DrawPanelFrame()
{
    char szPath[0x104];
    D2CelContextStrc tContext;

    D2GFX_DrawBox(gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, gnGlobal_0071146C / 2, gnGlobal_00711470 - 0x30, 0, 5);

    void* pCelFile = gpCelFile_007BF274;
    if (!pCelFile)
    {
        wsprintfA(szPath, "%s\\UI\\MENU\\scroin", szDataGlobal_006D4118);
        pCelFile = sub_004788B0_LoadCelFile(szPath, 0);
        gpCelFile_007BF274 = pCelFile;
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCelFile;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x6D, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0x6D, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x31, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0x31, -1, 5, 0);
    tContext.pCellFile = sub_00454600();
    tContext.nFrame = 10;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x115, gnGlobal_00711470 + gnGlobal_007A285C - 0x3D, -1, 5, 0);
}

// 0x004A23D0
void __cdecl sub_004A23D0_LoadPanelCels()
{
    char szPath[0x104];
    if (sub_00483350())
    {
        return;
    }
    if (!gpCelFile_007BF2D5)
    {
        sprintf(szPath, "%s\\ui\\menu\\questbackground", szDataGlobal_006D4118);
        gpCelFile_007BF2D5 = sub_004788B0_LoadCelFile(szPath, 0);
    }
    if (!gpCelFile_007BF2D9)
    {
        if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
        {
            sprintf(szPath, "%s\\ui\\menu\\expquesttabs", szDataGlobal_006D4118);
        }
        else
        {
            sprintf(szPath, "%s\\ui\\menu\\questtabs", szDataGlobal_006D4118);
        }
        gpCelFile_007BF2D9 = sub_004788B0_LoadCelFile(szPath, 0);
    }
    if (!gpCelFile_007BF2D1)
    {
        sprintf(szPath, "%s\\ui\\menu\\questsockets", szDataGlobal_006D4118);
        gpCelFile_007BF2D1 = sub_004788B0_LoadCelFile(szPath, 0);
    }
    if (!gpCelFile_007BF2DD)
    {
        sprintf(szPath, "%s\\ui\\menu\\questdone", szDataGlobal_006D4118);
        gpCelFile_007BF2DD = sub_004788B0_LoadCelFile(szPath, 0);
    }
    if (!gpCelFile_007BF351)
    {
        sprintf(szPath, "%s\\ui\\menu\\invps", szDataGlobal_006D4118);
        gpCelFile_007BF351 = sub_004788B0_LoadCelFile(szPath, 0);
    }
    if (!gpCelFile_007BF34D)
    {
        sprintf(szPath, "%s\\ui\\menu\\questlast", szDataGlobal_006D4118);
        gpCelFile_007BF34D = sub_004788B0_LoadCelFile(szPath, 0);
    }
}

// 0x004A5190
void __cdecl sub_004A5190_InitTextSlider()
{
    char szPath[0x104];
    sub_004A43E0();
    sprintf(szPath, "%s\\UI\\Menu\\TextSlid", szDataGlobal_006D4118);
    gpCelFile_007C02BC = sub_004788B0_LoadCelFile(szPath, 0);
    sub_004A5060();
    gnGlobal_007C02AC = 0;
    gnGlobal_007C02B0 = 0;
}

// 0x004B23E0
void __cdecl sub_004B23E0_InitPartyPanel()
{
    char szPath[0x104];
    gnGlobal_007C0DC0 = 0;
    gnGlobal_007C0DBC = 0;
    GetTickCount();
    memset(gaGlobal_007C0C68, 0, 0x160);
    gpGlobal_007C0D43 = sub_0065C430(0);
    gpGlobal_007C0D47 = sub_0065C430(0);
    gnGlobal_007C0C6B = 0;
    sprintf(szPath, "%s\\ui\\panel\\buysell", szDataGlobal_006D4118);
    gpCelFile_007C0DC8 = sub_004788B0_LoadCelFile(szPath, 0);
    sprintf(szPath, "%s\\ui\\menu\\goldbtn", szDataGlobal_006D4118);
    gpCelFile_007C0DCC = sub_004788B0_LoadCelFile(szPath, 0);
    gnGlobal_007C0DED = 0;
    gbGlobal_007C0DE0 = 0;
    gnGlobal_007C0DF1 = 0;
    gnGlobal_007C0DE9 = 0;
}

// 0x004B7CD0
D2ClientDialogStrc* __fastcall sub_004B7CD0_CreateDialogFromFile(int nArg1, int nArg2, int nArg8, int nArgC, int nType, int nArg14)
{
    char szPath[0x104];
    D2CelContextStrc tContext;

    sub_004545C0(0);
    sub_004898D0(0);
    sub_0044DA40();
    if (!nArg8)
    {
        return 0;
    }
    if (nType >= 1)
    {
        return 0;
    }

    gnGlobal_007C0E5C += 1;
    D2ClientDialogStrc* pDialog = (D2ClientDialogStrc*)FOG_Alloc(sizeof(D2ClientDialogStrc), ".\\UI\\dialog.cpp", 0x396, 0);
    memset(pDialog, 0, sizeof(D2ClientDialogStrc));
    pDialog->pNext = gpGlobal_007C0E54;
    gpGlobal_007C0E54 = pDialog;
    memset(pDialog, 0, sizeof(D2ClientDialogStrc));
    pDialog->unk0x34 = 0;
    pDialog->unk0x38 = 0;
    pDialog->unk0x50 = 0;
    pDialog->unk0x4C = 0;
    pDialog->unk0x44 = -1;
    pDialog->unk0x5C = 2;
    pDialog->unk0x2C = 0;
    pDialog->unk0x30 = 0;
    pDialog->unk0xB08 = 0;
    pDialog->unk0x60 = nArg8;
    pDialog->unk0x64 = nArgC;
    pDialog->unk0x58 = 0;
    pDialog->unk0x14 = 0;
    pDialog->dwTick = GetTickCount();
    pDialog->unk0x18 = nArg14;
    pDialog->unk0x48 = -1;
    pDialog->unk0x10 = 0;
    pDialog->unk0x54 = 0;
    pDialog->unk0x0C = 1;
    sprintf(szPath, "%s\\ui\\menu\\%s", szDataGlobal_006D4118, gaszDialogCels_007274AC[nType]);
    pDialog->pCelFile = sub_004788B0_LoadCelFile(szPath, 0);

    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pDialog->pCelFile;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    D2CelStrc* pCel = D2CMP_CelGetHandle(&tContext);
    D2_ASSERT(pCel, 0x3B3);
    pDialog->unk0x34 = sub_006018C0(pCel);
    pDialog->unk0x38 = sub_006018F0(pCel);
    pDialog->unk0x24 = nArg1;
    pDialog->unk0x28 = nArg2;
    pDialog->unk0x2C = nArg1;
    pDialog->unk0x30 = nArg2;
    gnGlobal_007C0E58 = 1;
    sub_004B7C60();
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_007273F0, 0xE);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_007273E4, 1);
    gnGlobal_007C0E4C += 1;
    D2_ASSERT(gnGlobal_007C0E5C == 1, 0x3C8);
    return pDialog;
}

// 0x004BE020
void __cdecl sub_004BE020_LoadTextSliderCel()
{
    char szPath[0x104];
    sprintf(szPath, "%s\\ui\\menu\\textslid", szDataGlobal_006D4118);
    gpCelFile_007C546C = sub_004788B0_LoadCelFile(szPath, 0);
}

#include "gen/data/Source/D2Client/0049C580_sub_0049C580_LoadPanelCels.inc"
