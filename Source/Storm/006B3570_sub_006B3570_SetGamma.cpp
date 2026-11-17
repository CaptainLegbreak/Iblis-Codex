struct D2GammaRampStrc { int red[128], green[128], blue[128]; };
struct D2GammaControlStrc;
struct D2GammaControlVTableStrc
{
    void* unk_00[4];
    int (__stdcall *SetGammaRamp)(D2GammaControlStrc*, int, D2GammaRampStrc*);
};
struct D2GammaControlStrc { D2GammaControlVTableStrc* pVTable; };
extern const unsigned int gnGammaMask_006CE278; // 0x006CE278
extern unsigned int gnCapabilities_0096F3A8; // 0x0096F3A8
extern int gnGammaScale_0074C020; // 0x0074C020
extern D2GammaControlStrc* gpGammaControl_00970E74; // 0x00970E74
void __fastcall sub_006BE190_BuildGammaTable(int nGamma, void* pTable, double dScale, int nStride, int nEntries, int nMask); // 0x006BE190
void __fastcall sub_006B20E0_ReportError(const char* szMessage, int nResult); // 0x006B20E0
extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nBytes);

// 0x006B3570
void __fastcall sub_006B3570_SetGamma(int nGamma)
{
    D2GammaRampStrc ramp;
    if (gnCapabilities_0096F3A8 & gnGammaMask_006CE278)
    {
        sub_006BE190_BuildGammaTable(nGamma, (unsigned short*)ramp.red, gnGammaScale_0074C020, 2, 256, 65535);
        memcpy(ramp.green, ramp.red, sizeof(ramp.red));
        memcpy(ramp.blue, ramp.red, sizeof(ramp.red));
        if (gpGammaControl_00970E74)
        {
            int nResult = gpGammaControl_00970E74->pVTable->SetGammaRamp(gpGammaControl_00970E74, 0, &ramp);
            if (nResult)
                sub_006B20E0_ReportError("Failed to set gamma ramp", nResult);
        }
    }
}
