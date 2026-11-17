struct Pad40_005392E0 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj005392E0 {
    Pad40_005392E0 tPad000;
    Pad40_005392E0 tPad040;
    Pad40_005392E0 tPad080;
    Pad40_005392E0 tPad0C0;
    Pad40_005392E0 tPad100;
    Pad40_005392E0 tPad140;
    unsigned int dwUnknown180;
    unsigned int dwUnknown184;
    unsigned int dwUnknown188;
    unsigned int dwUnknown18C;
    unsigned int dwUnknown190;
    unsigned int dwUnknown194;
    unsigned int dwUnknown198;
    unsigned int dwUnknown19C;
    unsigned int dwUnknown1A0;
    unsigned int dwUnknown1A4;
    unsigned int dwUnknown1A8;
    unsigned int dwUnknown1AC;
    unsigned int dwUnknown1B0;
    unsigned int dwUnknown1B4;
    unsigned int dwValue1B8;
};

// 0x005392E0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_005392E0(Obj005392E0* pObj) {
    return pObj->dwValue1B8;
}
