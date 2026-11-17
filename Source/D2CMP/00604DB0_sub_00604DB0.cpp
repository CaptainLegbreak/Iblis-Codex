struct T00604DB0 { double value[1]; };
enum { VALUE_SLOT_INDEX = 0 };
// 0x00604DB0
double __stdcall sub_00604DB0(T00604DB0 a,T00604DB0 b)
{
    return a.value[VALUE_SLOT_INDEX]>b.value[VALUE_SLOT_INDEX] ? a.value[VALUE_SLOT_INDEX] : b.value[VALUE_SLOT_INDEX];
}
