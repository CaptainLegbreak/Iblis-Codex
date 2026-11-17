struct Data0064A640 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    short sValue08;
};

struct Unit0064A640 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A640* pData;
};

// 0x0064A640
extern "C" __declspec(dllexport) int __stdcall sub_0064A640(Unit0064A640* pUnit) {
    if (pUnit && pUnit->nType == 3 && pUnit->pData) {
        return pUnit->pData->sValue08;
    }
    return 0;
}
