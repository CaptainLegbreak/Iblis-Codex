struct TMESSAGESOURCE {
    int unk0;
    int unk4;
    int nHead;
    void __thiscall sub_005176B4_Destroy(int bFree); // 0x005176B4
    void __thiscall Clear();
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags); // 0x00412650
extern const char gszTMESSAGESOURCE[]; // 0x0072F9FC

// 0x005176F8
void __thiscall TMESSAGESOURCE::Clear()
{
    for (;;) {
        TMESSAGESOURCE* pNode = nHead > 0 ? (TMESSAGESOURCE*)nHead : 0;
        if (!pNode) return;
        pNode->sub_005176B4_Destroy(0);
        SMemFree(pNode, gszTMESSAGESOURCE, -2, 0);
    }
}
