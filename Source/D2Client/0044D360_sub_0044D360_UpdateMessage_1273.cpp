int __stdcall sub_00420290_BreakHandlerChain(void* pMsg); // 0x00420290
extern int gnGlobal_007A0608; // 0x007A0608

// 0x0044D360
void __stdcall sub_0044D360_UpdateMessage(void* pMsg)
{
    int nOne = 1;
    if ((*(int*)((char*)pMsg + 0x0C) & 0x40000000) == 0)
        gnGlobal_007A0608 = nOne;
    *(int*)((char*)pMsg + 0x18) = nOne;
    *(int*)((char*)pMsg + 0x1C) = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}
