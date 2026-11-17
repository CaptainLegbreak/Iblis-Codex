struct D2Unk00540B70Obj
{
    char unk0x000[0x504];
    int f_504[1];
};

struct D2Unk00540B70Owner
{
    char unk0x00[0xB8];
    D2Unk00540B70Obj* pObj;
};

extern const int gaSlotRows_006E0B9C[];                                                                     // 0x006E0B9C

// 0x00540B70
static int* __stdcall sub_00540B70_GetSlot(D2Unk00540B70Owner* pOwner, int nType, int nIndex)
{
    if (nIndex == -1)
    {
        return 0;
    }
    return &pOwner->pObj->f_504[gaSlotRows_006E0B9C[nType] * 64 + nIndex % 64];
}

int* __fastcall sub_K10_EmitGetSlot(D2Unk00540B70Owner* pOwner, int nType)
{
    return sub_00540B70_GetSlot(pOwner, nType, nType + 1);
}
