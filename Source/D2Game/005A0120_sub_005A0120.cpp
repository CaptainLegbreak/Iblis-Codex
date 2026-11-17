struct Data005A0120 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwField1C;
};

struct Unit005A0120 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A0120* pData;
};

// 0x005A0120
extern "C" __declspec(dllexport) unsigned int* __fastcall sub_005A0120(Unit005A0120* pUnit) {
    Data005A0120* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return &pData->dwField1C;
}
