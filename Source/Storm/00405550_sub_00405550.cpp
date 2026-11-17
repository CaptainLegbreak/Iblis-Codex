struct Character { signed char value; };
enum { UPPER_FIRST = 65, UPPER_LAST = 90, CASE_DELTA = 32 };
// 0x00405550
void __fastcall sub_00405550(Character* text)
{
    while(text->value) {
        if(text->value>=UPPER_FIRST && text->value<=UPPER_LAST)
            text->value+=CASE_DELTA;
        ++text;
    }
}
