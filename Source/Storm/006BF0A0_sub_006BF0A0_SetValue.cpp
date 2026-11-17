struct D2Entry006BF0A0Strc
{
    unsigned char unk_00[0x20];
    int nValue20;
};
D2Entry006BF0A0Strc* __fastcall sub_006BE540_Find(void* pContainer, int nKey); // 0x006BE540

// 0x006BF0A0
void __stdcall sub_006BF0A0_SetValue(void* pContainer, int nKey, int nValue)
{
    if (nKey)
    {
        D2Entry006BF0A0Strc* pEntry = sub_006BE540_Find(pContainer, nKey);
        if (pEntry)
            pEntry->nValue20 = nValue;
    }
}
