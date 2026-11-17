struct D2GraphicsDeviceStrc;
struct D2GraphicsVTableStrc
{
    void* unk_00[22];
    int (__stdcall *SetRenderState)(D2GraphicsDeviceStrc*, int, int);
    void* unk_5C[17];
    int (__stdcall *SetTextureState)(D2GraphicsDeviceStrc*, int, int, int);
};
struct D2GraphicsDeviceStrc { D2GraphicsVTableStrc* pVTable; };
extern int gnState_00970E54; // 0x00970E54
extern D2GraphicsDeviceStrc* gpDevice_00970E78; // 0x00970E78

// 0x006B1EA0
void __fastcall sub_006B1EA0_SetState(int nState)
{
    if (gnState_00970E54 && nState == gnState_00970E54)
        return;
    switch (nState)
    {
    case 1:
        gpDevice_00970E78->pVTable->SetTextureState(gpDevice_00970E78, 0, 1, 4);
        gpDevice_00970E78->pVTable->SetTextureState(gpDevice_00970E78, 0, 4, 4);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 15, 1);
        break;
    case 2:
        gpDevice_00970E78->pVTable->SetTextureState(gpDevice_00970E78, 0, 1, 3);
        gpDevice_00970E78->pVTable->SetTextureState(gpDevice_00970E78, 0, 4, 3);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 15, 0);
        break;
    }
    gnState_00970E54 = nState;
}
