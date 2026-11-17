struct Pad40_00539070 {
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

struct Obj00539070 {
    Pad40_00539070 tPad000;
    Pad40_00539070 tPad040;
    unsigned int dwUnknown80;
    unsigned int dwUnknown84;
    unsigned int dwValue88;
};

// 0x00539070
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00539070(Obj00539070* pObj) {
    return pObj->dwValue88;
}
