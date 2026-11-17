struct Node00572DE0 { int nId; unsigned int dwUnknown04; Node00572DE0* pNext; };
struct List00572DE0 { Node00572DE0* pHead; };
// 0x00572DE0
extern "C" __declspec(dllexport) int __fastcall sub_00572DE0(List00572DE0* pList, int nId) {
    for (Node00572DE0* pNode = pList->pHead; pNode; pNode = pNode->pNext) {
        if (pNode->nId == nId) {
            return 1;
        }
    }
    return 0;
}
