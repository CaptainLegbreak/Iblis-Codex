struct Data0064A280 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned short wUnknown08;
    short sValue0A;
};

struct Unit0064A280 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A280* pData;
};

// 0x0064A280
extern "C" __declspec(dllexport) int __stdcall sub_0064A280(Unit0064A280* pUnit) {
    if (pUnit && pUnit->nType == 3 && pUnit->pData) {
        return pUnit->pData->sValue0A;
    }
    return 0;
}
