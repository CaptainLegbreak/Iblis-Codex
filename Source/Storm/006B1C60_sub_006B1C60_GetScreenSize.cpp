extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C

// 0x006B1C60
void __fastcall sub_006B1C60_GetScreenSize(int* width, int* height)
{
    *width = gnScreenWidth_007C9138;
    *height = gnScreenHeight_007C913C;
}
