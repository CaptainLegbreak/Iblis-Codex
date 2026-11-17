struct D2ExcelNode006BD070Strc
{
    unsigned char unk_00[0x24];
    D2ExcelNode006BD070Strc* pLeft24;
    D2ExcelNode006BD070Strc* pRight28;
};
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern const char gszExcelSourceFile_006FC448[]; // 0x006FC448

// 0x006BD070
void __fastcall sub_006BD070_FreeTree(D2ExcelNode006BD070Strc* pNode)
{
    if (pNode->pLeft24)
        sub_006BD070_FreeTree(pNode->pLeft24);
    if (pNode->pRight28)
        sub_006BD070_FreeTree(pNode->pRight28);
    FOG_FreeServerMemory(0, pNode, gszExcelSourceFile_006FC448, 0x346, 0);
}
