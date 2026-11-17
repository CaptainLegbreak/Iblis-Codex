// 0x00503F70
static __forceinline int sub_00503F70(unsigned int selector)
{
    switch (selector) {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    default:
        return 1;
    }
}

int __stdcall emit_selector_00503F70(unsigned int selector)
{
    return sub_00503F70(selector);
}
