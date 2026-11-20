extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
struct D2CellFileStrc* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath);                          // 0x004520C0
int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
int __fastcall sub_00502EF0(int nSize);                                                                     // 0x00502EF0

enum D2C_UIvars
{
    UI_GAME = 0x00,
    UI_INVENTORY = 0x01,
    UI_STATSCREEN = 0x02,
    UI_MINISKILL = 0x03,
    UI_SKILLTREE = 0x04,
    UI_CHATBOX = 0x05,
    UI_NEWSTATS = 0x06,
    UI_NEWSKILLS = 0x07,
    UI_NPCMENU = 0x08,
    UI_ESCMENU = 0x09,
    UI_AUTOMAP = 0x0A,
    UI_CONFIG = 0x0B,
    UI_NPCSHOP = 0x0C,
    UI_HOLDALT = 0x0D,
    UI_ANVIL = 0x0E,
    UI_QUESTSCREEN = 0x0F,
    UI_INISCROLL = 0x10,
    UI_QUESTLOG = 0x11,
    UI_UNKNOWN18 = 0x12,
    UI_HIRICONS = 0x13,
    UI_WAYPOINT = 0x14,
    UI_MINIPANEL = 0x15,
    UI_PARTYSCREEN = 0x16,
    UI_MPTRADE = 0x17,
    UI_MSGLOG = 0x18,
    UI_STASH = 0x19,
    UI_CUBE = 0x1A,
    UI_STEEGSTONE = 0x1B,
    UI_GUILDVAULT = 0x1C,
    UI_UNKNOWN29 = 0x1D,
    UI_UNKNOWN30 = 0x1E,
    UI_BELTROWS = 0x1F,
    UI_UNKNOWN32 = 0x20,
    UI_HELPSCREEN = 0x21,
    UI_HELPBUTTON = 0x22,
    UI_HIREICONS = 0x23,
    UI_MERCINV = 0x24,
    UI_RECIPESCROLL = 0x25
};

enum DrawMode
{
    DRAWMODE_TRANS25,
    DRAWMODE_TRANS50,
    DRAWMODE_TRANS75,
    DRAWMODE_MODULATE,
    DRAWMODE_BURN,
    DRAWMODE_NORMAL,
    DRAWMODE_TRANSHIGHLIGHT,
    DRAWMODE_HIGHLIGHT
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04;
    int unk0x08;
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
    struct D2CellFileStrc* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

int __stdcall TEXTURE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, unsigned int nGamma, DrawMode eDrawMode, unsigned char* pPalette); // 0x004F6480
void __fastcall sub_00502320(const unsigned short* wszText, int nX, int nY, int nColor, int bCentered);   // 0x00502320

extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern struct D2CellFileStrc* gpRecipeScrollCel_007BCE8C;                                                  // 0x007BCE8C
extern int gnRecipeScrollColor_007BCEA4;                                                                    // 0x007BCEA4
extern unsigned short gwszRecipeScrollText_007BCEA8[];                                                      // 0x007BCEA8

// 0x0048BC10
void __stdcall sub_0048BC10()
{
    D2CelContextStrc tContext;

    if (!sub_0044DCC0() || !sub_004538D0(UI_RECIPESCROLL))
    {
        return;
    }

    if (!gpRecipeScrollCel_007BCE8C)
    {
        gpRecipeScrollCel_007BCE8C = sub_004520C0_LoadUiCelFile("menu\\recipescroll");
        if (!gpRecipeScrollCel_007BCE8C)
        {
            return;
        }
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpRecipeScrollCel_007BCE8C;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    TEXTURE_CelDraw(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 224, -1, DRAWMODE_NORMAL, 0);
    tContext.nFrame = 1;
    TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 256, gnGlobal_00711470 + gnGlobal_007A285C - 224, -1, DRAWMODE_NORMAL, 0);
    tContext.nFrame = 2;
    TEXTURE_CelDraw(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 48, -1, DRAWMODE_NORMAL, 0);
    tContext.nFrame = 3;
    TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 256, gnGlobal_00711470 + gnGlobal_007A285C - 48, -1, DRAWMODE_NORMAL, 0);

    const int nOldSize = sub_00502EF0(4);
    sub_00502320(gwszRecipeScrollText_007BCEA8, gnGlobal_007A2858 + 80, 130 - gnGlobal_007A285C, gnRecipeScrollColor_007BCEA4, 0);
    sub_00502EF0(nOldSize);
}
