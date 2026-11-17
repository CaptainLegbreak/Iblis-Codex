struct Pad40_00648690 {
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

struct Obj00648690 {
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
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    int nValue38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwUnknown58;
    unsigned int dwUnknown5C;
    unsigned int dwUnknown60;
    unsigned int dwUnknown64;
    unsigned int dwUnknown68;
    unsigned int dwUnknown6C;
    unsigned int dwUnknown70;
    unsigned int dwUnknown74;
    unsigned int dwUnknown78;
    int nValue7C;
    unsigned int dwUnknown80;
    int nValue84;
};

// 0x00648690
extern "C" __declspec(dllexport) void __stdcall sub_00648690(Obj00648690* pObj, int nValue, int nUnused3, int nUnused4) {
    if (pObj) {
        if (nValue != pObj->nValue7C) {
            pObj->nValue38 = 15;
        }
        pObj->nValue7C = nValue;
        pObj->nValue84 = nValue;
    }
}
