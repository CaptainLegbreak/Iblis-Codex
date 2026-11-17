struct Data005A01E0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned short wUnknown24;
    short sValue26;
};

struct Unit005A01E0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A01E0* pData;
};

// 0x005A01E0
extern "C" __declspec(dllexport) short __fastcall sub_005A01E0(Unit005A01E0* pUnit) {
    Data005A01E0* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return -1;
    }
    return pData->sValue26;
}
