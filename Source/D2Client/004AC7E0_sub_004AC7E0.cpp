struct Data004AC7E0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned short wUnknown14;
    unsigned short wFlags16;
};

struct Unit004AC7E0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data004AC7E0* pData;
};

// 0x004AC7E0
extern "C" __declspec(dllexport) int __fastcall sub_004AC7E0(Unit004AC7E0* pUnit, unsigned short wMask) {
    Data004AC7E0* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return (unsigned short)(pData->wFlags16 & wMask) != 0;
}
