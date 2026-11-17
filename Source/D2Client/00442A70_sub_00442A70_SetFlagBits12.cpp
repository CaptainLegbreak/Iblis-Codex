// 0x00442A70
void __fastcall sub_00442A70_SetFlagBits12(unsigned int* pFlags, int nValue)
{
    *pFlags = (*pFlags & 0xFFFF8FFF) | (nValue << 12);
}

// 0x00442A80
int __fastcall sub_00442A80_IsNightmareOpen(unsigned int nFlags)
{
    if (nFlags & 0x20)
        return (nFlags & 0x1F00) >= 0x500;
    return (nFlags & 0x1F00) >= 0x400;
}

// 0x00442AB0
int __fastcall sub_00442AB0_IsHellOpen(unsigned int nFlags)
{
    if (nFlags & 0x20)
        return (nFlags & 0x1F00) >= 0xA00;
    return (nFlags & 0x1F00) >= 0x800;
}
