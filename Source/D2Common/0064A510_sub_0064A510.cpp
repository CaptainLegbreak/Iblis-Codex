struct Data0064A510 {
    unsigned int dwUnknown00;
    short sValue04;
};

struct Unit0064A510 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A510* pData;
};

// 0x0064A510
extern "C" __declspec(dllexport) int __stdcall sub_0064A510(Unit0064A510* pUnit) {
    if (pUnit && pUnit->nType == 3 && pUnit->pData) {
        return pUnit->pData->sValue04;
    }
    return -1;
}
