struct D2LaunchRecordStrc
{
    char unk0x000[0x85];
    unsigned char nFlag085;
    unsigned char nFlag086;
    unsigned char nFlag087;
    unsigned char nFlag088;
    unsigned char nFlag089;
    unsigned char nFlag08A;
    unsigned char nFlag08B;
    char unk0x08C[0x1EE - 0x85 - 7];
    char nMode;
};

extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4
extern int gnTextSentinel_0070CB80;                                                                           // 0x0070CB80

// 0x00431E70
static void sub_00431E70_SetModeFlags(char nMode)
{
    gpLaunchRecord_007795D4->nMode = nMode;
    gpLaunchRecord_007795D4->nFlag085 = 0;
    gpLaunchRecord_007795D4->nFlag089 = 0;
    gpLaunchRecord_007795D4->nFlag088 = 0;
    gpLaunchRecord_007795D4->nFlag086 = 0;
    gpLaunchRecord_007795D4->nFlag087 = 0;
    gpLaunchRecord_007795D4->nFlag08A = 0;
    gpLaunchRecord_007795D4->nFlag08B = 0;

    if (nMode == 0)
    {
        gpLaunchRecord_007795D4->nFlag085 = 1;
    }
    else if (nMode == 4)
    {
        gpLaunchRecord_007795D4->nFlag089 = 1;
    }
    else if (nMode == 2)
    {
        gpLaunchRecord_007795D4->nFlag088 = 1;
    }
    else if (nMode == 3)
    {
        gpLaunchRecord_007795D4->nFlag086 = 1;
    }
    else if (nMode == 1)
    {
        gpLaunchRecord_007795D4->nFlag087 = 1;
    }
    else if (nMode == 5)
    {
        gpLaunchRecord_007795D4->nFlag08A = 1;
    }
    else if (nMode == 6)
    {
        gpLaunchRecord_007795D4->nFlag08B = 1;
    }
}

void __cdecl sub_I03_Emit_00431E70(char nMode)
{
    sub_00431E70_SetModeFlags(gnTextSentinel_0070CB80);
    sub_00431E70_SetModeFlags(nMode);
}
