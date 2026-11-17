struct Data0064A6F0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwValue30;
};

struct Unit0064A6F0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0064A6F0* pData;
};

// 0x0064A6F0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_0064A6F0(Unit0064A6F0* pUnit) {
    if (pUnit && pUnit->nType == 3 && pUnit->pData) {
        return pUnit->pData->dwValue30;
    }
    return 0;
}
