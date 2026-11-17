struct Pad40_00553970 {
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

struct Obj00553970 {
    Pad40_00553970 tPad000;
    Pad40_00553970 tPad040;
    Pad40_00553970 tPad080;
    unsigned int dwUnknownC0;
    unsigned int dwUnknownC4;
    unsigned int dwUnknownC8;
    unsigned int dwUnknownCC;
    unsigned int dwUnknownD0;
    unsigned int dwUnknownD4;
    unsigned int dwUnknownD8;
    unsigned int dwValueDC;
};

// 0x00553970
extern "C" __declspec(dllexport) void __fastcall sub_00553970(Obj00553970* pObj, unsigned int dwValue) {
    if (pObj) {
        pObj->dwValueDC = dwValue;
    }
}
