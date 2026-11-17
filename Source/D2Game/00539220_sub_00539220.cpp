struct Pad40_00539220 {
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

struct Pad400_00539220 {
    Pad40_00539220 t000;
    Pad40_00539220 t040;
    Pad40_00539220 t080;
    Pad40_00539220 t0C0;
    Pad40_00539220 t100;
    Pad40_00539220 t140;
    Pad40_00539220 t180;
    Pad40_00539220 t1C0;
    Pad40_00539220 t200;
    Pad40_00539220 t240;
    Pad40_00539220 t280;
    Pad40_00539220 t2C0;
    Pad40_00539220 t300;
    Pad40_00539220 t340;
    Pad40_00539220 t380;
    Pad40_00539220 t3C0;
};

struct Obj00539220 {
    Pad400_00539220 tPad000;
    Pad40_00539220 tPad400;
    unsigned int dwUnknown440;
    unsigned int dwUnknown444;
    unsigned int dwUnknown448;
    unsigned int dwUnknown44C;
    unsigned int dwUnknown450;
    unsigned int dwUnknown454;
    unsigned int dwUnknown458;
    unsigned char nValue45C;
};

// 0x00539220
extern "C" __declspec(dllexport) unsigned char __fastcall sub_00539220(Obj00539220* pObj) {
    return pObj->nValue45C;
}
