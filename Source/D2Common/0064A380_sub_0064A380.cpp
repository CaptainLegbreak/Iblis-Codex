struct Data0064A380 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    short sValue10;
};

struct Unit0064A380 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A380* pData;
};

// 0x0064A380
extern "C" __declspec(dllexport) int __stdcall sub_0064A380(Unit0064A380* pUnit) {
    if (pUnit && pUnit->nType == 3 && pUnit->pData) {
        return pUnit->pData->sValue10;
    }
    return 0;
}
