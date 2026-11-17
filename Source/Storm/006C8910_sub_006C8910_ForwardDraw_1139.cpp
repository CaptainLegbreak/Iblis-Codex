int __fastcall sub_006C84B0_Draw(void* context, int second, int third, int fourth, int fifth, int last); // 0x006C84B0
// 0x006C8910
int __fastcall sub_006C8910_ForwardDraw(void* context, int second, int third, int fourth, int fifth, int unused, int last)
{
    return sub_006C84B0_Draw(context, second, third, fourth, fifth, last);
}
