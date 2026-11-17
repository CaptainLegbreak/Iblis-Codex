struct D2Interface006B1C30Strc;
struct D2Interface006B1C30VtblStrc
{
    void* pfnSlots00[11];
    int (__stdcall* pfnMethod2C)(D2Interface006B1C30Strc* pThis, int nArg, int nMode);
};
struct D2Interface006B1C30Strc
{
    D2Interface006B1C30VtblStrc* f_0;
};
struct D2Config006B1C30Strc
{
    unsigned char unk_00[0x10];
    int nFlag10;
};
extern D2Config006B1C30Strc* gpConfig_007C9148; // 0x007C9148
extern D2Interface006B1C30Strc* gpInterface_00970E68; // 0x00970E68

// 0x006B1C30
int __cdecl sub_006B1C30_SetMode()
{
    if (gpConfig_007C9148->nFlag10)
        gpInterface_00970E68->f_0->pfnMethod2C(gpInterface_00970E68, 0, 1);
    else
        gpInterface_00970E68->f_0->pfnMethod2C(gpInterface_00970E68, 0, 9);
    return 1;
}
