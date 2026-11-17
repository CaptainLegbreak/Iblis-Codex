struct Character { signed char value; };
enum { FIRST_DIGIT = 48, LAST_DIGIT = 57 };
// 0x004FE770
int __stdcall sub_004FE770(void* unused1,void* unused2,const Character* text)
{
    return text->value>=FIRST_DIGIT && text->value<=LAST_DIGIT;
}
