struct Sub0058EE80 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwValue20;
};

struct Data0058EE80 {
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
    Sub0058EE80* f_28;
};

struct Unit0058EE80 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0058EE80* pData;
};

// 0x0058EE80
extern "C" __declspec(dllexport) unsigned int __fastcall sub_0058EE80(Unit0058EE80* pUnit) {
    Data0058EE80* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    Sub0058EE80* pSub = pData ? pData->f_28 : 0;
    if (!pSub) {
        return 0;
    }
    return pSub->dwValue20;
}
