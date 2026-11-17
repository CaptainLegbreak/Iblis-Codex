struct Data0064A210 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    short sValue0C;
};

struct Unit0064A210 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A210* pData;
};

// 0x0064A210
extern "C" __declspec(dllexport) int __stdcall sub_0064A210(Unit0064A210* pUnit) {
    if (pUnit && pUnit->nType == 3 && pUnit->pData) {
        return pUnit->pData->sValue0C;
    }
    return 0;
}
