struct Obj00643860 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwValue08;
};

// 0x00643860
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00643860(void* pOwner, Obj00643860* pObj) {
    if (pOwner && pObj) {
        return pObj->dwValue08;
    }
    return 0;
}
