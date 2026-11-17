struct sub_006BCCC0_Owner
{
    char unk_000[0x108];
    int nFlag;
};

void __fastcall sub_006BCAC0_ResetDataArray(sub_006BCCC0_Owner* pOwner); // 0x006BCAC0

// 0x006BCCC0
void __fastcall sub_006BCCC0_Reset(sub_006BCCC0_Owner* pOwner)
{
    pOwner->nFlag = 1;
    sub_006BCAC0_ResetDataArray(pOwner);
}
