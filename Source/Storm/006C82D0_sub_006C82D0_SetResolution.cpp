int gnValue_0098A168;        // 0x0098A168
int gnWidth_0098A16C;        // 0x0098A16C
extern int gnWideWidth_0098A16C; // 0x0098A16C

// 0x006C82D0
void __fastcall sub_006C82D0_SetResolution(int nMode)
{
    if (nMode != 0)
    {
        gnValue_0098A168 = 0;
        if (nMode != 3)
            gnWidth_0098A16C = 800;
        else
            gnWideWidth_0098A16C = 1344;
    }
    else
    {
        gnValue_0098A168 = 0;
        gnWidth_0098A16C = 640;
    }
}
