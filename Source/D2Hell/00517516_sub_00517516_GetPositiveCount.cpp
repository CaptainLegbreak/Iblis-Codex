struct D2PositiveCountStrc {
    int unknown00;
    int unknown04;
    int count;
};
// 0x00517516
int __fastcall sub_00517516_GetPositiveCount(D2PositiveCountStrc* data)
{
    int value = data->count;
    if (value <= 0) value = 0;
    return value;
}
