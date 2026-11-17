struct Node005169D0 { int nId; Node005169D0* pNext; };
// 0x005169D0
extern "C" __declspec(dllexport) int __fastcall sub_005169D0(Node005169D0* pNode, int nId) {
    for (; pNode; pNode = pNode->pNext) {
        if (pNode->nId == nId) {
            return 1;
        }
    }
    return 0;
}
