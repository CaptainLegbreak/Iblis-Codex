struct Pad40_006BC810 {
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

struct Obj006BC810 {
    Pad40_006BC810 tPad000;
    Pad40_006BC810 tPad040;
    Pad40_006BC810 tPad080;
    Pad40_006BC810 tPad0C0;
    unsigned int dwUnknown100;
    unsigned int dwUnknown104;
    unsigned int dwUnknown108;
    unsigned int dwUnknown10C;
    unsigned int dwValue110;
};

// 0x006BC810
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006BC810(Obj006BC810* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue110;
}
