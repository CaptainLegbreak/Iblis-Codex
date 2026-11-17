struct Sub0058F000 {
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
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwField38;
};

struct Data0058F000 {
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
    Sub0058F000* f_28;
};

struct Unit0058F000 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0058F000* pData;
};

// 0x0058F000
extern "C" __declspec(dllexport) unsigned int* __stdcall sub_0058F000(Unit0058F000* pUnit) {
    Sub0058F000* pSub;
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pSub = pUnit->pData->f_28;
    } else {
        pSub = 0;
    }
    return &pSub->dwField38;
}
