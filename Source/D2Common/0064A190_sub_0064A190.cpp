struct Data0064A190 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwValue14;
};

struct Unit0064A190 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A190* pData;
};

// 0x0064A190
extern "C" __declspec(dllexport) unsigned int __stdcall sub_0064A190(Unit0064A190* pUnit) {
    if (pUnit && pUnit->nType == 3 && pUnit->pData) {
        return pUnit->pData->dwValue14;
    }
    return 0;
}
