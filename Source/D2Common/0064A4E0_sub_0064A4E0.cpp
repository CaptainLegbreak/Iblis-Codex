struct Data0064A4E0 {
    unsigned int dwUnknown00;
    unsigned short wValue04;
};

struct Unit0064A4E0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A4E0* pData;
};

// 0x0064A4E0
extern "C" __declspec(dllexport) void __stdcall sub_0064A4E0(Unit0064A4E0* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 3 && pUnit->pData) {
        pUnit->pData->wValue04 = wValue;
    }
}
