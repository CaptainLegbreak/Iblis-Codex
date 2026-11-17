struct D2NpcIndexMapStrc
{
    int nNpcClassId;
    int nIndex;
};

extern D2NpcIndexMapStrc gaPlrIntroNpcIndexMap[];                                                           // 0x00732738
extern int gnPlrIntroNpcIndexMapCount;                                                                      // 0x00732734

// 0x00572330
int __fastcall sub_00572330_GetNpcIndex(int nNpcId)
{
    for (int i = 0; i < gnPlrIntroNpcIndexMapCount; ++i)
    {
        if (gaPlrIntroNpcIndexMap[i].nNpcClassId == nNpcId)
        {
            return gaPlrIntroNpcIndexMap[i].nIndex;
        }
    }

    return 0;
}
