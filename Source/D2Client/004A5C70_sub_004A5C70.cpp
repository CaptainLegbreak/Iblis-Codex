struct Message { char pad[0x0C]; unsigned int lParam; char pad10[8]; int handled; int result; };
extern int global_00724728;  // 0x00724728
int __cdecl sub_0044DA30();  // 0x0044DA30
void __cdecl sub_00469D50();  // 0x00469D50
void __fastcall sub_00455F20(int, int, int);  // 0x00455F20
void __fastcall sub_0047E090(int, int);  // 0x0047E090
int __fastcall sub_004B9A00(int, void*, int, int, int);  // 0x004B9A00
int __stdcall sub_00420290(Message*);  // 0x00420290
enum { REPEAT_MASK = 0x40000000, UI_VARIABLE = 11 };
// 0x004A5C70
void __stdcall sub_004A5C70(Message* message)
{
    if (sub_0044DA30()) { message->handled = 0; return; }
    if (global_00724728) {
        if (!(message->lParam & REPEAT_MASK)) {
            sub_00469D50();
            sub_00455F20(UI_VARIABLE, 1, 0);
            sub_0047E090(0, 1);
            sub_004B9A00(1, 0, 0, 0, 0);
        }
    } else global_00724728 = 1;
    message->handled = 1;
    message->result = 0;
    sub_00420290(message);
}
