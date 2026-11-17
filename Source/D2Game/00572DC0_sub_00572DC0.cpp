struct Node00572DC0 {
    unsigned int dwValue00;
    unsigned int dwUnknown04;
    Node00572DC0* pNext;
};

struct List00572DC0 {
    Node00572DC0* pHead;
};

// 0x00572DC0
extern "C" __declspec(dllexport) int __fastcall sub_00572DC0(List00572DC0* pList) {
    for (Node00572DC0* pNode = pList->pHead; pNode; pNode = pNode->pNext) {
        if (pNode->dwValue00) {
            return 1;
        }
    }
    return 0;
}
