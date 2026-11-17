struct Character { signed char value; };
enum { FIRST_PRINTABLE = 32, AFTER_PRINTABLE = 128 };
// 0x004435D0
int __stdcall sub_004435D0(void* unused1,void* unused2,const Character* text)
{
    return text->value>=FIRST_PRINTABLE && text->value<AFTER_PRINTABLE;
}
