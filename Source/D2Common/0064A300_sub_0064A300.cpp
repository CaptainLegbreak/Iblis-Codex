struct Data0064A300 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned short wUnknown0C;
    short sValue0E;
};

struct Unit0064A300 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A300* pData;
};

// 0x0064A300
extern "C" __declspec(dllexport) int __stdcall sub_0064A300(Unit0064A300* pUnit) {
    if (pUnit && pUnit->nType == 3 && pUnit->pData) {
        return pUnit->pData->sValue0E;
    }
    return 0;
}
