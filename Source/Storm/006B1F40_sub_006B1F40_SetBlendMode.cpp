struct D2GraphicsDeviceStrc;
struct D2GraphicsVTableStrc
{
    void* unk_00[22];
    int (__stdcall *SetRenderState)(D2GraphicsDeviceStrc*, int, int);
    void* unk_5C[17];
    int (__stdcall *SetTextureState)(D2GraphicsDeviceStrc*, int, int, int);
};
struct D2GraphicsDeviceStrc { D2GraphicsVTableStrc* pVTable; };
int gnState_00970E58;        // 0x00970E58
D2GraphicsDeviceStrc* gpDevice_00970E78;        // 0x00970E78

// 0x006B1F40
void __fastcall sub_006B1F40_SetBlendMode(int nState)
{
    if (gnState_00970E58 && nState == gnState_00970E58)
        return;
    switch (nState)
    {
    case 1:
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 27, 0);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 19, 2);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 20, 1);
        break;
    case 2:
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 27, 1);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 19, 2);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 20, 2);
        break;
    case 3:
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 27, 1);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 19, 1);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 20, 3);
        break;
    case 4:
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 27, 1);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 19, 5);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 20, 6);
        break;
    }
    gnState_00970E58 = nState;
}
