struct D2LaunchNameNodeStrc
{
    char szName[0x204];
    D2LaunchNameNodeStrc* pNext;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
extern D2LaunchNameNodeStrc* gpNameList_0077BDB4;                                                           // 0x0077BDB4

// 0x0043F800
void __cdecl sub_0043F800_FreeNameList()
{
    D2LaunchNameNodeStrc* pNode = gpNameList_0077BDB4;
    while (pNode)
    {
        D2LaunchNameNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\Src\\ChatDlg.cpp", 0x1C01, 0);
        pNode = pNext;
    }
    gpNameList_0077BDB4 = 0;
}
