struct Data0064A540 {
    unsigned int dwUnknown00;
    unsigned short wUnknown04;
    unsigned short wValue06;
};

struct Unit0064A540 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A540* pData;
};

// 0x0064A540
extern "C" __declspec(dllexport) void __stdcall sub_0064A540(Unit0064A540* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 3 && pUnit->pData) {
        pUnit->pData->wValue06 = wValue;
    }
}
