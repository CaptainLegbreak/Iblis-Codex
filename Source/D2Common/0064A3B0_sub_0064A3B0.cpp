struct Data0064A3B0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned short wUnknown0C;
    short sValue0E;
    short sValue10;
};

struct Unit0064A3B0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A3B0* pData;
};

// 0x0064A3B0
extern "C" __declspec(dllexport) int __stdcall sub_0064A3B0(Unit0064A3B0* pUnit) {
    Data0064A3B0* pData = (pUnit && pUnit->nType == 3) ? pUnit->pData : 0;
    if (pData) {
        return pData->sValue0E - pData->sValue10;
    }
    return 0;
}
