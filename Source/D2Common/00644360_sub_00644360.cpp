struct Obj0063D650 { unsigned int dwUnknown00; unsigned int dwUnknown04; unsigned int dwValue08; };

// 0x00644360
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00644360(Obj0063D650* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue08;
}
