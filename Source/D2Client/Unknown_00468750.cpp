extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int X, int Y);

extern int data_007A6AB0; // 0x007A6AB0
extern int data_007A6AAC; // 0x007A6AAC

// 0x00468750
void __fastcall sub_00468750_SetCursorPos(int nX, int nY)
{
    SetCursorPos(nX, nY);
    data_007A6AB0 = nX;
    data_007A6AAC = nY;
}
