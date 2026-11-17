#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int gnProjectOriginX_00880B60;                                                                              // 0x00880B60
int gnGlideSpriteScale_00880B64;                                                                            // 0x00880B64
int gnProjectOriginY_00880B68;                                                                              // 0x00880B68
extern int* gpnPerspectiveTable_00880B6C;                                                                   // 0x00880B6C

// 0x0050DCD0
void __cdecl sub_0050DCD0_FillPerspectiveTable()
{
    int* pTable = gpnPerspectiveTable_00880B6C;
    for (int i = 0; i < 0x2000; ++i)
    {
        const int nX = i - 0x1000;
        pTable[i] = 0x2EE000 / (MIN(MAX(nX, -0xBB7), 0xBB7) - 0xBB8);
    }
    gnGlideSpriteScale_00880B64 = 0x100;
}

// 0x0050DD50
void __fastcall sub_0050DD50_SetProjectOrigin(int nX, int nY)
{
    gnProjectOriginX_00880B60 = nX;
    gnProjectOriginY_00880B68 = nY;
}

// 0x0050DF00
void __cdecl sub_0050DF00_ResetSpriteScale()
{
    gnGlideSpriteScale_00880B64 = 0x100;
}
