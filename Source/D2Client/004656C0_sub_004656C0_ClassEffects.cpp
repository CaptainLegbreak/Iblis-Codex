struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit);                                              // 0x004DA000
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0
void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0
void __fastcall sub_0046BFF0(D2UnitStrc* pUnit);                                                            // 0x0046BFF0

// 0x004656C0
static void sub_004656C0_ClassEffects(D2UnitStrc* pUnit, int nClassId)
{
    switch (nClassId)
    {
    case 0xF2:
    case 0x2C0:
        sub_00470390(pUnit, 0x7A, 3, 0, 0, 0, 0, 0);
        break;
    case 0x14D:
        sub_00470390(pUnit, 0xBA, 2, 0, 0, 0, 0, 0);
        break;
    case 0x154:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, -0x20, -0x20, 0);
        break;
    case 0x155:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, -0x20, 0x20, 0);
        break;
    case 0x156:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, 0x20, 0x20, 0);
        break;
    case 0x157:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, 0x20, -0x20, 0);
        break;
    case 0x15F:
    case 0x160:
    case 0x161:
    {
        const int nBase = (!pUnit ? -1 : pUnit->dwClassId) - 0xB3;
        sub_00470390(pUnit, nBase, 4, 0, nBase + 3, 0, 0, 0);
        break;
    }
    case 0x196:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, 0, 0, -0x37);
        sub_004DA200_SetMotionVectorB(pUnit, 0, 0, 1, 1);
        sub_004DA2A0_SetMotionVectorC(pUnit, 0, 0, 0x32, 0);
        sub_004DA6E0_SetMotionFlag20(pUnit, 1);
        break;
    case 0x1A1:
    case 0x1A2:
        if (pUnit)
        {
            sub_00470390(pUnit, 0x10E, 2, 0, 0, 0, 0, 0);
        }
        break;
    case 0x209:
        sub_0046BFF0(pUnit);
        break;
    case 0x21F:
        sub_00470390(pUnit, 0x113, 3, 0, 0, 0, 0, 0);
        break;
    }
}

void sub_I08_Emit_004656C0(D2UnitStrc* pUnit, int nClassId)
{
    sub_004656C0_ClassEffects(pUnit, nClassId);
}
