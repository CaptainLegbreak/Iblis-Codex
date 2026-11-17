struct D2Entry006BF0A0Strc
{
    unsigned char unk_00[0x20];
    int nValue20;
};
D2Entry006BF0A0Strc* __fastcall sub_006BE540_Find(void* pContainer, int nKey); // 0x006BE540

// 0x006BF0C0
int __stdcall sub_006BF0C0_GetValue(void* pContainer, int nKey)
{
    if (!nKey)
        return 0;
    D2Entry006BF0A0Strc* pEntry = sub_006BE540_Find(pContainer, nKey);
    if (!pEntry)
        return 0;
    return pEntry->nValue20;
}
