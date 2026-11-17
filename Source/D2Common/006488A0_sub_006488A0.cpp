struct Obj006488A0 {
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
    unsigned int dwUnknown38;
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
    unsigned char nValue64;
    unsigned char nValue65;
};

// 0x006488A0
extern "C" __declspec(dllexport) void __stdcall sub_006488A0(Obj006488A0* pObj, unsigned char nValue) {
    if (pObj) {
        unsigned char nMasked = nValue & 0x3F;
        pObj->nValue64 = nMasked;
        pObj->nValue65 = nMasked;
    }
}
