struct Obj00648AD0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned short wValue10;
    unsigned short wValue12;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwValue58;
};

// 0x00648AD0
extern "C" __declspec(dllexport) void __stdcall sub_00648AD0(Obj00648AD0* pObj, unsigned short wA, unsigned short wB) {
    if (pObj) {
        pObj->wValue10 = wA;
        pObj->wValue12 = wB;
        pObj->dwValue58 = 0;
    }
}
