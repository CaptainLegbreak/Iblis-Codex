struct Stack006C0BA0 {
    unsigned int dwEntries[64];
    int nCount;
};

// 0x006C0BA0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_006C0BA0(Stack006C0BA0* pStack) {
    if (pStack->nCount <= 0) {
        return 0;
    }
    return pStack->dwEntries[--pStack->nCount];
}
