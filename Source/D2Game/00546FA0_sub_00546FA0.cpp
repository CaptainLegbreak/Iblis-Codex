struct Pad40_00546FA0 {
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

struct Pad400_00546FA0 {
    Pad40_00546FA0 t000;
    Pad40_00546FA0 t040;
    Pad40_00546FA0 t080;
    Pad40_00546FA0 t0C0;
    Pad40_00546FA0 t100;
    Pad40_00546FA0 t140;
    Pad40_00546FA0 t180;
    Pad40_00546FA0 t1C0;
    Pad40_00546FA0 t200;
    Pad40_00546FA0 t240;
    Pad40_00546FA0 t280;
    Pad40_00546FA0 t2C0;
    Pad40_00546FA0 t300;
    Pad40_00546FA0 t340;
    Pad40_00546FA0 t380;
    Pad40_00546FA0 t3C0;
};

struct Obj00546FA0 {
    Pad400_00546FA0 tPad0000;
    Pad400_00546FA0 tPad0400;
    Pad400_00546FA0 tPad0800;
    Pad400_00546FA0 tPad0C00;
    Pad40_00546FA0 tPad1000;
    Pad40_00546FA0 tPad1040;
    Pad40_00546FA0 tPad1080;
    unsigned int dwUnknown10C0;
    unsigned int dwUnknown10C4;
    unsigned int dwUnknown10C8;
    unsigned int dwUnknown10CC;
    unsigned int dwUnknown10D0;
    unsigned int dwUnknown10D4;
    unsigned int dwUnknown10D8;
    unsigned int dwUnknown10DC;
    unsigned int dwUnknown10E0;
    unsigned int dwUnknown10E4;
    unsigned int dwUnknown10E8;
    unsigned int dwUnknown10EC;
    unsigned int dwValue10F0;
};

// 0x00546FA0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00546FA0(Obj00546FA0* pObj) {
    return pObj->dwValue10F0;
}
