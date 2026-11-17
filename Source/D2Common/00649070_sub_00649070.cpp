struct Pad40_00649070 {
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

struct Obj00649070 {
    Pad40_00649070 tPad000;
    Pad40_00649070 tPad040;
    unsigned int dwUnknown80;
    unsigned int dwUnknown84;
    unsigned int dwUnknown88;
    unsigned int dwUnknown8C;
    unsigned char nUnknown90;
    unsigned char nUnknown91;
    unsigned char nUnknown92;
    unsigned char nValue93;
};

// 0x00649070
extern "C" __declspec(dllexport) void __stdcall sub_00649070(Obj00649070* pObj, unsigned char nValue) {
    if (pObj) {
        if (nValue >= 1 && nValue <= 19) {
            pObj->nValue93 = nValue - 1;
        } else {
            pObj->nValue93 = 0;
        }
    }
}
