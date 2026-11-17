struct Node00572DA0 {
    unsigned int dwValue00;
    unsigned int dwUnknown04;
    Node00572DA0* pNext;
};

struct List00572DA0 {
    Node00572DA0* pHead;
};

// 0x00572DA0
extern "C" __declspec(dllexport) int __fastcall sub_00572DA0(List00572DA0* pList) {
    int nCount = 0;
    for (Node00572DA0* pNode = pList->pHead; pNode; pNode = pNode->pNext) {
        if (pNode->dwValue00) {
            nCount++;
        }
    }
    return nCount;
}
