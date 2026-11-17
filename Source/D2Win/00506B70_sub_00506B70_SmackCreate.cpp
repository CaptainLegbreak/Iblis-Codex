struct SMSGHANDLER_PARAMS;
struct D2CelFileStrc;
struct D2WinControlStrc;

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);
typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

#pragma pack(push, 1)
struct D2WinControlStrc
{
    int nType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    D2WinControlFn pfDraw;
    D2WinControlFn pfInitialize;
    D2WinMsgHandler pfHandleMouseDown;
    D2WinMsgHandler pfHandleMouseUp;
    D2WinMsgHandler pfHandleCharInput;
    D2WinMsgHandler pfHandleVirtualKeyInput;
    D2WinMsgHandler field_34;
    D2WinControlFn pfShouldMouseInputBeHandled;
    D2WinControlStrc* pNext;
};

struct D2WinSmackStrc
{
    D2WinControlStrc controlHeader;
    char szFile[0x100];
    int unk0x140;
    int unk0x144;
    int nMovieX;
    int nMovieY;
};

#pragma pack(pop)

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210
int __fastcall sub_00506A90_SmackDraw(D2WinControlStrc* pControl); // 0x00506A90
int __stdcall sub_00506B10_SmackMouseDown(SMSGHANDLER_PARAMS* pMsg); // 0x00506B10
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268

// 0x00506B70
D2WinSmackStrc* __fastcall sub_00506B70_SmackCreate(int nX, int nY, int nWidth, int nHeight, D2WinMsgHandler pfHandler)
{
    D2WinSmackStrc* pSmack = (D2WinSmackStrc*)FOG_Alloc(sizeof(D2WinSmackStrc), ".\\Src\\D2WinSmack.cpp", 0x23, 0);
    memset(pSmack, 0, sizeof(D2WinSmackStrc));
    pSmack->controlHeader.nType = 9;
    pSmack->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pSmack->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pSmack->controlHeader.nWidth = nWidth;
    pSmack->controlHeader.pNext = 0;
    memset(&pSmack->controlHeader.pfHandleMouseUp, 0, 3 * sizeof(D2WinMsgHandler));
    pSmack->controlHeader.nImageX = nX;
    pSmack->controlHeader.nImageY = nY;
    pSmack->controlHeader.nHeight = nHeight;
    pSmack->controlHeader.field_34 = pfHandler;
    pSmack->controlHeader.pfDraw = sub_00506A90_SmackDraw;
    pSmack->controlHeader.pfHandleMouseDown = sub_00506B10_SmackMouseDown;
    pSmack->szFile[0] = 0;
    memset(&pSmack->unk0x140, 0, 2 * sizeof(int));
    pSmack->nMovieX = (nWidth - 468) / 2 + nX;
    pSmack->nMovieY = (nHeight - 60) / 2 + nY;
    CONTROL_AppendToList(&pSmack->controlHeader);
    return pSmack;
}
