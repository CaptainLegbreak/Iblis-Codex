struct Unit0064A3E0 {
    int nType;
    unsigned int dwValue04;
};

// 0x0064A3E0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_0064A3E0(Unit0064A3E0* pUnit) {
    if (pUnit && pUnit->nType == 3) {
        return pUnit->dwValue04;
    }
    return 0;
}
