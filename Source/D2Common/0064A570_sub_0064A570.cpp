struct Data0064A570 {
    unsigned int dwUnknown00;
    unsigned short wUnknown04;
    short sValue06;
};

struct Unit0064A570 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A570* pData;
};

// 0x0064A570
extern "C" __declspec(dllexport) int __stdcall sub_0064A570(Unit0064A570* pUnit) {
    if (pUnit && pUnit->nType == 3 && pUnit->pData) {
        return pUnit->pData->sValue06;
    }
    return 0;
}
