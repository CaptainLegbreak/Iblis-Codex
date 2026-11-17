struct Pad40_00539230 {
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

struct Pad400_00539230 {
    Pad40_00539230 t000;
    Pad40_00539230 t040;
    Pad40_00539230 t080;
    Pad40_00539230 t0C0;
    Pad40_00539230 t100;
    Pad40_00539230 t140;
    Pad40_00539230 t180;
    Pad40_00539230 t1C0;
    Pad40_00539230 t200;
    Pad40_00539230 t240;
    Pad40_00539230 t280;
    Pad40_00539230 t2C0;
    Pad40_00539230 t300;
    Pad40_00539230 t340;
    Pad40_00539230 t380;
    Pad40_00539230 t3C0;
};

struct Obj00539230 {
    Pad400_00539230 tPad000;
    Pad40_00539230 tPad400;
    unsigned int dwUnknown440;
    unsigned int dwUnknown444;
    unsigned int dwUnknown448;
    unsigned int dwUnknown44C;
    unsigned int dwUnknown450;
    unsigned int dwUnknown454;
    unsigned int dwUnknown458;
    unsigned char nValue45C;
};

// 0x00539230
extern "C" __declspec(dllexport) void __fastcall sub_00539230(Obj00539230* pObj, unsigned char nValue) {
    pObj->nValue45C = nValue;
}
