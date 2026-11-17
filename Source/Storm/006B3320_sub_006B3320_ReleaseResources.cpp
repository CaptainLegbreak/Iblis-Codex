struct D2ComObjectStrc;

struct D2ComVtblStrc
{
    void* pfQueryInterface;
    void* pfAddRef;
    unsigned long (__stdcall* pfRelease)(D2ComObjectStrc* pThis);
    void* pfGetGammaRamp;
    long (__stdcall* pfSetGammaRamp)(D2ComObjectStrc* pThis, unsigned long dwFlags, void* pRamp);
};

struct D2ComObjectStrc
{
    D2ComVtblStrc* f_0;
};

int gbVideoUp_00970E40;                                                                                     // 0x00970E40
int gnVideoState_00970E44;                                                                                  // 0x00970E44
D2ComObjectStrc* gpInterface_00970E68;                                                                      // 0x00970E68
D2ComObjectStrc* gpInterface_00970E6C;                                                                      // 0x00970E6C
D2ComObjectStrc* gpInterface_00970E70;                                                                      // 0x00970E70
D2ComObjectStrc* gpGammaControl_00970E74;                                                                   // 0x00970E74
extern D2ComObjectStrc* gpInterface_00970E78;                                                               // 0x00970E78
D2ComObjectStrc* gpInterface_00970E7C;                                                                      // 0x00970E7C
char gabGammaRamp_0096FCB8[1536];                                                                           // 0x0096FCB8
void __cdecl sub_006B9150();                                                                                // 0x006B9150
void __cdecl sub_006BB640();                                                                                // 0x006BB640
void __cdecl sub_006B32B0();                                                                                // 0x006B32B0
void __fastcall sub_006B20E0_ReportError(const char* szMessage, long hResult);                              // 0x006B20E0

// 0x006B3320
void __cdecl sub_006B3320_ReleaseResources()
{
    if (!gbVideoUp_00970E40)
    {
        return;
    }

    sub_006B9150();
    sub_006BB640();
    sub_006B32B0();

    if (gpInterface_00970E7C)
    {
        gpInterface_00970E7C->f_0->pfRelease(gpInterface_00970E7C);
        gpInterface_00970E7C = 0;
    }

    if (gpInterface_00970E78)
    {
        gpInterface_00970E78->f_0->pfRelease(gpInterface_00970E78);
        gpInterface_00970E78 = 0;
    }

    if (gpGammaControl_00970E74)
    {
        const long hResult = gpGammaControl_00970E74->f_0->pfSetGammaRamp(gpGammaControl_00970E74, 0, gabGammaRamp_0096FCB8);
        if (hResult && hResult != (long)0x887601C2)
        {
            sub_006B20E0_ReportError("Failed to restore original gamma ramp", hResult);
        }
        gpGammaControl_00970E74->f_0->pfRelease(gpGammaControl_00970E74);
        gpGammaControl_00970E74 = 0;
    }

    if (gpInterface_00970E70)
    {
        gpInterface_00970E70->f_0->pfRelease(gpInterface_00970E70);
        gpInterface_00970E70 = 0;
    }

    if (gpInterface_00970E6C)
    {
        gpInterface_00970E6C->f_0->pfRelease(gpInterface_00970E6C);
        gpInterface_00970E6C = 0;
    }

    if (gpInterface_00970E68)
    {
        gpInterface_00970E68->f_0->pfRelease(gpInterface_00970E68);
        gpInterface_00970E68 = 0;
    }

    gbVideoUp_00970E40 = 0;
    gnVideoState_00970E44 = 0;
}
