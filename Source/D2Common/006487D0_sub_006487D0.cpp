struct Pad40_006487D0 {
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

struct Obj006487D0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwValue28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    Pad40_006487D0 tPad040;
    unsigned int dwUnknown80;
    unsigned int dwUnknown84;
    unsigned int dwUnknown88;
    unsigned int dwUnknown8C;
    unsigned int dwUnknown90;
    unsigned int dwUnknown94;
    unsigned int dwUnknown98;
    unsigned int dwField9C;
};

// 0x006487D0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006487D0(Obj006487D0* pObj, unsigned int** ppOut) {
    *ppOut = &pObj->dwField9C;
    return pObj->dwValue28;
}
