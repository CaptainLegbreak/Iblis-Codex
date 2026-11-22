#include "D2Win.h"
#include "D2Win32Types.h"
#include "D2CelContext.h"
#include "D2WinTypes.h"
#include "D2StormTypes.h"
#include "D2WinControls.h"
#include "D2Unicode.h"
#include "D2GfxTypes.h"
#include "D2MultiTypes.h"

typedef long (__stdcall* WNDPROC)(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam);

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CelFileStrc;

struct Control;

struct D2WinControlStrc;

struct D2WinButtonStrc;

struct D2CelContextStrc;

struct Point;

struct Obj004FA490;

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" __declspec(dllimport) int __stdcall GetWindowRect(void* hWnd, tagRECT* lpRect); // 0x006CC4BC

void* __cdecl WINDOW_GetWindow(); // 0x004F59A0

int __stdcall WINDOW_Create(int bWindowed, int nResolution); // 0x004F5610

int __stdcall WINDOW_Resize(int nResolution, int bForceResize); // 0x004F5AA0

void __stdcall WINDOW_EndCutScene(int nResolution); // 0x004F6080

int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004F60F0

int __stdcall D2GFX_EndScene(); // 0x004F6190

void __stdcall D2GFX_DrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6340

void __stdcall D2GFX_ClearScreen(int bPartial); // 0x004F63B0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall CONTROL_AppendToDeadList(D2WinControlStrc* pControl); // 0x004F9250

int __stdcall CONTROL_FreeDeadList(); // 0x004F9290

void __cdecl CURSOR_Draw(); // 0x004F97E0

void __cdecl D2COMP_DrawAllCompositeUnits(); // 0x004F9870

void __stdcall D2CMPSpriteCacheInit(void* pMemPool, unsigned int nMaxSize, int nArg, unsigned int nCacheSize); // 0x005FFD40

void __stdcall D2CMPSpriteCacheDestroy(int bFree); // 0x005FFE30

void* ghMainWindow_6F8FE23C; // 0x007D55AC

extern int gbWindowed_6F8FE244; // 0x007D55B4

D2WinControlStrc* dword_6F8FE250;                                                                           // 0x007D55C0

int dword_6F8FE254; // 0x007D55C4

D2WinEditBoxStrc* gpEditBox_6F8FE258; // 0x007D55C8

D2WinControlStrc* dword_6F8FE264; // 0x007D55D4

int dword_6F8FE26C; // 0x007D55DC

int (__cdecl* dword_6F8FE27C)(); // 0x007D55EC

int __stdcall WINDOW_Destroy(); // 0x004F5900

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

D2CelFileStrc* gpCursorCellFile; // 0x007D5594

int gnCursorFrame; // 0x007D55A0

tagPOINT gMousePosition_6F8FE234; // 0x007D55A4

extern "C" __declspec(dllimport) void* __stdcall GetDesktopWindow(); // 0x006CC494

extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void* hWnd, void* hWndInsertAfter, int X, int Y, int cx, int cy, unsigned int uFlags); // 0x006CC4DC

extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* lpRect); // 0x006CC4F8

extern "C" __declspec(dllimport) int __stdcall GetWindowPlacement(void* hWnd, tagWINDOWPLACEMENT* lpwndpl); // 0x006CC508

extern "C" __declspec(dllimport) int __stdcall GetMonitorInfoA(void* hMonitor, tagMONITORINFO* lpmi); // 0x006CC510

extern "C" __declspec(dllimport) void* __stdcall MonitorFromWindow(void* hWnd, unsigned long dwFlags); // 0x006CC514

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __cdecl D2GFX_IsFixedAspectRatio(); // 0x004F5180

void __stdcall WINDOW_GetResolutionSize(int nResolution, long* pWidth, long* pHeight); // 0x004F5570

int __stdcall WINDOW_IsFullScreen(); // 0x004F5A30

int __stdcall WINDOW_CenterWindow(int nResolution); // 0x004F5BC0

struct Point { int x, y; };

typedef int (__fastcall* ControlFn)(Control*);

struct Control {
    char prefix[0x0C];
    int x, y, width, height;
    char callbacks[0x1C];
    ControlFn shouldHandle;
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

D2WinControlStrc* gpControlList_6F8FE24C; // 0x007D55BC

void* dword_6F8FE260; // 0x007D55D0

void __stdcall D2Win_COMMANDS_VirtualKey_6F8ADB50(SMSGHANDLER_PARAMS* pMsg); // 0x004F9BF0

static D2WinControlStrc* __stdcall CONTROL_PickClosestToMouse(D2WinControlStrc* pScrollBar, D2WinControlStrc* pControl); // 0x004FA200

int __fastcall BUTTON_OnMouseWheelScrolled(D2WinButtonStrc* pButton, int nMouseWheelIncrement); // 0x00500B50

void __fastcall BUTTON_SimulateClick(SMSGHANDLER_PARAMS* pMsg); // 0x00500AB0

int __fastcall SCROLLBAR_HandleMouseWheel(SMSGHANDLER_PARAMS* pMsg, D2WinScrollBarStrc* pScrollBar, int a3); // 0x00508030

int __stdcall POPUP_IsActive(); // 0x005085C0

struct Obj004FA490 { unsigned int dwValue00; };

tagRECT gSavedWindowRect_007D5580; // 0x007D5580

D2CelFileStrc* gpBackgroundCellFile; // 0x007D55B0

int gnResolution_6F8FE248; // 0x007D55B8

D2WinEditBoxStrc* dword_6F8FE25C; // 0x007D55CC

WNDPROC gpfWndProc_6F8FE268; // 0x007D55D8

int dword_6F8FE278; // 0x007D55E8

struct D2WinEditBoxStrc;

struct D2WinTextBoxStrc;

struct D2WinControlInitStrc;

struct D2TransPaletteStrc;

struct D2Palette256Strc;

struct Unicode;

struct D2WinTextBoxLineStrc;

struct D2WinImageClickRectStrc;

struct D2WinImage2Strc;

struct D2HoverLineStrc;

struct D2WinListDataStrc;

struct D2WinListStrc;

struct D2WinAccountListDataStrc;

struct D2WinAccountListStrc;

struct D2WinPopUpLineStrc;

struct D2WinPopUpStrc;

enum D2ControlTypes
{
    D2WIN_EDITBOX = 1,
    D2WIN_IMAGE = 2,
    D2WIN_ANIMIMAGE = 3,
    D2WIN_TEXTBOX = 4,
    D2WIN_SCROLLBAR = 5,
    D2WIN_BUTTON = 6,
    D2WIN_LIST = 7,
    D2WIN_TIMER = 8,
    D2WIN_SMACK = 9,
    D2WIN_PROGRESSBAR = 10,
    D2WIN_POPUP = 11,
    D2WIN_ACCOUNTLIST = 12,
    D2WIN_IMAGE2 = 13,
};


struct D2TransPaletteStrc
{
    unsigned char data[0x10000];
};

struct D2Palette256Strc
{
    unsigned char data[0x100];
};

extern "C" __declspec(dllimport) int __stdcall PtInRect(const tagRECT* pRect, tagPOINT tPoint); // 0x006CC4B0

extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int nX, int nY); // 0x006CC4B4

extern "C" __declspec(dllimport) int __stdcall TrackMouseEvent(tagTRACKMOUSEEVENT* pEventTrack); // 0x006CC520

int __cdecl sub_00407FF0(); // 0x00407FF0

void __stdcall WINDOW_SetPaused(int bPaused); // 0x004F5990

int __stdcall WINDOW_GetDimensions(int* pWidth, int* pHeight); // 0x004F59B0

void __stdcall WINDOW_ShowCursor(int nArg); // 0x004F59F0

int __stdcall WINDOW_CheckCutScene(); // 0x004F5DD0

int __stdcall D2GFX_HardwareAcceleratedRenderMode(); // 0x004F6270

D2WinControlStrc* __fastcall D2Win_10042_TEXTBOX_Create(int nX, int nY, int nWidth, int nHeight, int a5, int a6, D2CelFileStrc* pCellFile, int a8, int a9, int a10, int a11); // 0x004FC7A0

void __fastcall EDITBOX_ClearSelection(D2WinEditBoxStrc* pEditBox); // 0x004FDCC0

D2WinControlStrc* __fastcall IMAGE2_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int a6, int a7, int a8); // 0x004FD6C0

D2WinControlStrc* __fastcall IMAGE_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int a6, int a7); // 0x004FD770

D2WinControlStrc* __fastcall TIMER_Create(int nTimeout, int a2); // 0x004FD9D0

D2WinControlStrc* __fastcall D2Win_10070_EDITBOX_Create(int nX, int nY, int nWidth, int nHeight, int a5, int a6, D2CelFileStrc* pCellFile, int a8, int a9, int a10, int a11); // 0x005001D0

D2WinControlStrc* __fastcall ANIMIMAGE_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int a6, int a7, int a8, int a9, int a10); // 0x00500850

D2WinControlStrc* __fastcall BUTTON_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int a6, int a7, int a8, int a9, int a10, int a11); // 0x00501290

D2WinControlStrc* __fastcall SMACK_Create(int nX, int nY, int nWidth, int nHeight, int a5); // 0x00506B70

D2WinControlStrc* __fastcall LIST_Create(int nX, int nY, int nWidth, int nHeight, int a5, int a6); // 0x005075E0

D2WinControlStrc* __fastcall ACCOUNTLIST_Create(int nX, int nY, int nWidth, int nHeight, int a5, int a6); // 0x00507CA0

D2WinControlStrc* __fastcall PROGRESSBAR_Create(int nX, int nY, int nWidth, int nHeight); // 0x00507E50

D2WinControlStrc* __fastcall SCROLLBAR_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int a6); // 0x005084F0

void __fastcall D2SOUND_10034(int nArg); // 0x005148F0

void __cdecl D2SOUND_FadeOutStreamChannel(); // 0x00514960

int __cdecl D2SOUND_GetMusicVolumeOption(); // 0x00514CF0

void __fastcall D2SOUND_10049(int nState); // 0x00514D00

int __cdecl D2SOUND_GetOptionsMusicOption(); // 0x00514D80

void __fastcall D2SOUND_10070(int nArg); // 0x00514D90

int __cdecl D2SOUND_AreWaveSlotsInitialized(); // 0x00515060

D2ArchiveHandleStrc* __fastcall sub_00517332_LoadMpqFile(const char* szFileName, void* hFile, void* pfShowMessage, int nPriority); // 0x00517332

extern "C" const char szD2XVideoMpq_006DC788[]; // 0x006DC788

extern unsigned int gdwInvBitMasks_006CE2E8[]; // 0x006CE2E8

extern int dword_6F8BDE20; // 0x0072DC44

extern D2ArchiveHandleStrc* gpD2VideoMPQ; // 0x007D5614

struct D2WinImageClickRectStrc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    D2WinMsgHandler pCallback;
};

struct D2WinImage2Strc
{
    D2WinControlStrc controlHeader;
    int nFrame;
    int eDrawMode;
    D2WinImageClickRectStrc* pClickRect;
};

struct D2HoverLineStrc
{
    Unicode wszText[256];
    int nWidth;
    int nHeight;
};

struct D2WinListDataStrc
{
    Unicode wszText[256];
    int field_200;
    D2WinMsgHandler field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    char field_218;
    char field_219;
    char field_21A;
    char field_21B;
    int field_21C;
    D2WinListDataStrc* pNext;
};

struct D2WinPopUpLineStrc
{
    Unicode wszText[64];
    void (__stdcall* pfHandleMouseInput)();
};

struct D2WinPopUpStrc
{
    D2WinControlStrc controlHeader;
    int nLines;
    D2WinPopUpLineStrc lines[8];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall GetMessageA(tagMSG* pMsg, void* hWnd, unsigned int uMsgFilterMin, unsigned int uMsgFilterMax); // 0x006CC484

extern "C" __declspec(dllimport) long __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam); // 0x006CC488

extern "C" __declspec(dllimport) void __stdcall PostQuitMessage(int nExitCode); // 0x006CC4A4

int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam, int* pUseResult, int* pResult); // 0x00420B00

int __stdcall D2GFX_Initialize(void* hInstance, WNDPROC pfWndProc, int nRenderMode, int bWindowed); // 0x004F52E0

void __stdcall D2Win_UpdateAndDraw(); // 0x004F98E0

void __stdcall D2Win_COMMANDS_MouseMove_6F8AD670(SMSGHANDLER_PARAMS* pMsg); // 0x004FA6B0

void __stdcall D2Win_10168_WINMAIN_CreateScreenshot(); // 0x004FA7A0

int __fastcall D2Win_10053(D2WinTextBoxStrc* pTextBox, int nLine); // 0x004FBA30

int __fastcall D2Win_10055(D2WinTextBoxStrc* pTextBox); // 0x004FBAB0

int __stdcall EDITBOX_PlaceMultiLineCaret(SMSGHANDLER_PARAMS* pMsg, int nX, int nY); // 0x004FE3B0

int __fastcall D2Win_10074(D2WinEditBoxStrc* pEditBox, char nChar); // 0x004FEAE0

int __fastcall EDITBOX_HandleKeyDown(D2WinEditBoxStrc* pEditBox, char nKey); // 0x004FF050

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

int __stdcall POPUP_Destroy(); // 0x005085A0

int __stdcall POPUP_HandleMouseButtonInput(SMSGHANDLER_PARAMS* pMsg); // 0x005086A0

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

void __stdcall D2CMPSetNoCompress(int bCompress); // 0x005FE280

int gdwGlobal_007D5590; // 0x007D5590

extern D2WinPopUpStrc* gpPopUp_0087E974; // 0x0087E974

int gdwGlobal_007D55B4; // 0x007D55B4

int dword_6F8FE274; // 0x007D55E4

int gbMouseTracking_007D55F0; // 0x007D55F0

int dword_6F8FE284; // 0x007D55F8

int dword_6F8FE288; // 0x007D55FC

unsigned char gStandardColorsPalette_007D563C[44]; // 0x007D563C

D2Palette256Strc gStandardShiftsPalette_007D5668[13]; // 0x007D5668

unsigned char gbyPaletteMap_007D6368[256]; // 0x007D6368

unsigned char gScreenPalette_007DE468[65536]; // 0x007DE468

D2TransPaletteStrc gTransPalette_007EE468[3]; // 0x007EE468

unsigned char gDarkenPalette_0081E468[256]; // 0x0081E468

unsigned char gbyPaletteMap_0081E568[256]; // 0x0081E568

D2Palette256Strc gShadowsLightGammaPalette_0081EA68[49]; // 0x0081EA68

unsigned char gLuminancePalette_00821B68[65536]; // 0x00821B68

unsigned char gDarkBlendPalette_00831B68[65536]; // 0x00831B68

struct D2CompositeUnitStrc;

struct D2WinCommandRegisterStrc
{
    int nType;
    int nId;
    void* pCallback;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

int __fastcall D2Win_10177(unsigned char nAct);                                                             // 0x004FB480

int __fastcall D2Win_10043_TEXTBOX_Destroy(D2WinControlStrc* pControl);                                     // 0x004FC960

int __fastcall IMAGE_Destroy(void* pArg);                                                                    // 0x004FD0F0

int __fastcall IMAGE2_Destroy(void* pArg);                                                                    // 0x004FD100

int __fastcall TIMER_Destroy(void* pArg);                                                                    // 0x004FD820

int __fastcall D2Win_10071_EDITBOX_Destroy(D2WinControlStrc* pControl);                                     // 0x004FDAA0

int __fastcall ANIMIMAGE_Destroy(void* pArg);                                                                    // 0x00500300

int __fastcall BUTTON_Destroy(D2WinControlStrc* pControl);                                                  // 0x00500930

void __stdcall D2Win_10116(); // 0x005015F0

void __fastcall D2Win_10115_FONT();                                                                         // 0x00502C60

void __fastcall D2COMP_DrawCompositeShadow(D2CompositeUnitStrc* pCompositeUnit);                                          // 0x00503A50

int __fastcall D2COMP_DrawCompositeUnit(D2CompositeUnitStrc* pCompositeUnit, int nGamma); // 0x00503BA0

D2CompositeUnitStrc* __cdecl D2COMP_GetFirstCompositeUnit();                                                                // 0x00505150

D2CompositeUnitStrc* __stdcall D2Win_10148(D2CompositeUnitStrc* pCompositeUnit);                            // 0x00505160

void __cdecl D2Win_10157(); // 0x00505550

int __fastcall D2COMP_DrawCompositeLabel(D2CompositeUnitStrc* unit); // 0x00505810

int __fastcall D2COMP_DrawCompositeHover(D2CompositeUnitStrc* pCompositeUnit); // 0x00505A80

int __fastcall SMACK_Destroy(D2WinControlStrc* pControl);                                                   // 0x00506A40

void __fastcall WREGISTER_RegisterCommands(void* hWnd, D2WinCommandRegisterStrc* pCommandRegister, unsigned int nCommands); // 0x00506DA0

void __fastcall WREGISTER_UnregisterCommands(void* hWnd, D2WinCommandRegisterStrc* pCommandRegister, unsigned int nCommands); // 0x00506E00

int __fastcall LIST_Destroy(D2WinControlStrc* pControl);                                                    // 0x00506E60

void __stdcall LIST_LoadPentspinCellfile();                                                                 // 0x005070D0

void __stdcall LIST_UnloadPentspinCellfile();                                                               // 0x00507140

int __fastcall ACCOUNTLIST_Destroy(D2WinControlStrc* pControl);                                             // 0x00507AF0

int __fastcall PROGRESSBAR_Destroy(void* pArg);                                                                    // 0x00507DB0

int __fastcall SCROLLBAR_Destroy(void* pArg);                                                                    // 0x00507EE0

int __stdcall CelFileFreeHardware(D2CelFileStrc* pCelFile);                                           // 0x00601A50

extern D2WinCommandRegisterStrc gpCommandRegister_6F8BDE28[0x21];                                          // 0x0072DC48

struct JPEG_CORE_PROPERTIES;

struct JPEG_CORE_PROPERTIES
{
    int UseJPEGPROPERTIES;
    unsigned char* DIBBytes;
    int DIBWidth;
    int DIBHeight;
    int DIBPadBytes;
    int DIBChannels;
    int DIBColor;
    int DIBSubsampling;
    const char* JPGFile;
    unsigned char* JPGBytes;
    int JPGSizeBytes;
    int JPGWidth;
    int JPGHeight;
    int JPGChannels;
    int JPGColor;
    int JPGSubsampling;
    int JPGThumbWidth;
    int JPGThumbHeight;
    int cconversion_reqd;
    int upsampling_reqd;
    int jquality;
    int unk0x54[0x137B];
};

extern "C" __declspec(dllimport) int __stdcall ijlInit(JPEG_CORE_PROPERTIES* pProps); // 0x006CC5E0

extern "C" __declspec(dllimport) int __stdcall ijlWrite(JPEG_CORE_PROPERTIES* pProps, int nMode); // 0x006CC5E4

extern "C" __declspec(dllimport) int __stdcall ijlFree(JPEG_CORE_PROPERTIES* pProps); // 0x006CC5E8

extern int gnScreenshotIndex_0072DC40; // 0x0072DC40

void* __fastcall FOG_CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960

int __fastcall FOG_CloseFile(void* hFile); // 0x004069A0

int __stdcall D2GFX_GetBackBuffer(unsigned char* pBuffer); // 0x004F6250

extern int gnMouseX_007D55A4; // 0x007D55A4

extern int gnMouseY_007D55A8; // 0x007D55A8

unsigned long gdwLastScreenshotTick_007D5600; // 0x007D5600

struct D2LaunchRecordStrc;

struct D2FuncTable_0077ABF0Strc;

typedef void (__cdecl* D2LaunchDoneFn)();

void __cdecl CHARSEL_CreateBaseScreen(); // 0x0043C4F0

D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId); // 0x0042F430

D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId); // 0x0042F3A0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060

int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0

void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0

void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00

void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength); // 0x004FDD50

int __fastcall D2Win_10076(D2WinControlStrc* pControl, const char* szText); // 0x004FFE10

int __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc* pEditBox); // 0x004F91C0

void __fastcall sub_004FDDD0_LinkTab(D2WinControlStrc* pControl, D2WinControlStrc* pNext); // 0x004FDDD0

void __fastcall CHARSEL_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450

void __cdecl MAINMENUS_ShowMainMenu(); // 0x004336C0

int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg); // 0x004FA470

void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet); // 0x004FA420

void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0

void __fastcall sub_0042E6B0(int nValue); // 0x0042E6B0

void __fastcall sub_0042E6A0(void (__cdecl* pfnCallback)()); // 0x0042E6A0

void __cdecl CHARSEL_SetCancelled(); // 0x0043B810

void __cdecl MAINMENUS_UpdateStatus(); // 0x00436AD0

int __cdecl sub_004F5D60(); // 0x004F5D60

int __stdcall sub_0042FE70_FilterChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FE70

int __stdcall MAINMENUS_FilterRestrictedChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FEF0

int __stdcall sub_0042FF00_FilterChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FF00

int __stdcall MAINMENUS_OnEditChange(int nArg); // 0x00436F20

int __stdcall sub_004372A0_OnEnter(int nArg); // 0x004372A0

void __cdecl MAINMENUS_UpdateEmailOk(); // 0x00436EB0

void __cdecl MAINMENUS_UpdatePasswordOk(); // 0x004371E0

extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0

extern D2LaunchRecordStrc* gpLaunchRecord_007795D4; // 0x007795D4

extern D2WinControlStrc* gpEdit_00779334; // 0x00779334

extern D2WinControlStrc* gpEdit_00779340; // 0x00779340

extern D2WinControlStrc* gpEdit_0077958C; // 0x0077958C

extern D2WinControlStrc* gpEdit_007795A8; // 0x007795A8

extern D2WinControlStrc* gpPasswordOk_007799A4; // 0x007799A4

extern D2WinControlStrc* gpStatusText_007799A8; // 0x007799A8

extern D2WinControlStrc* gpCounterText_007799AC; // 0x007799AC

extern int gnStatusStringId_007799B0; // 0x007799B0

extern int gnStatusDots_007799B4; // 0x007799B4

extern unsigned long gdwStatusStart_007799B8; // 0x007799B8

extern D2WinControlStrc* gpPasswordEdit_007799BC; // 0x007799BC

extern D2WinControlStrc* gpPasswordEdit_007799C0; // 0x007799C0

extern D2WinControlStrc* gpPasswordEdit_007799C4; // 0x007799C4

extern D2WinControlStrc* gpPasswordEdit_007799C8; // 0x007799C8

extern D2WinControlStrc* gpEdit_007799DC; // 0x007799DC

extern D2WinControlStrc* gpEdit_007799E0; // 0x007799E0

extern D2WinControlStrc* gpButton_007799E4; // 0x007799E4

extern int gdwGlobal_007D55B8; // 0x007D55B8

void __stdcall WINDOW_ClearCaches(); // 0x004F5D50

int dword_6F8FE228; // 0x007D5598

int dword_6F8FE22C; // 0x007D559C

int gbIsMouseButtonPressed; // 0x007D55E0

int dword_6F8FE280; // 0x007D55F4

tagRECT gWindowRect_007C9160; // 0x007C9160

void __stdcall D2Win_COMMANDS_MouseWheel_6F8AE220(SMSGHANDLER_PARAMS* pMsg);

// 0x004F8F10
int __stdcall D2Win_InitializeSpriteCache(int bWindowed, int nResolution)
{
    dword_6F8FE26C = 1;

    if (!WINDOW_Create(bWindowed, nResolution))
    {
        return 0;
    }

    D2CMPSpriteCacheInit(0, 0x800000, 0x7D000, 0);
    ghMainWindow_6F8FE23C = WINDOW_GetWindow();
    gpBackgroundCellFile = 0;
    gpControlList_6F8FE24C = 0;
    dword_6F8FE250 = 0;
    dword_6F8FE254 = 0;
    dword_6F8FE25C = 0;
    dword_6F8FE260 = 0;
    gpEditBox_6F8FE258 = 0;
    gpfWndProc_6F8FE268 = 0;
    dword_6F8FE264 = 0;
    dword_6F8FE278 = 0;
    gnCursorFrame = 0;
    dword_6F8FE27C = 0;
    gnResolution_6F8FE248 = nResolution;
    gbWindowed_6F8FE244 = bWindowed;
    return 1;
}

// 0x004F8FC0
int __stdcall D2Win_10014_SetWndProc(WNDPROC wndProc)
{
    gpfWndProc_6F8FE268 = wndProc;
    return 1;
}

// 0x004F8FE0
int __fastcall D2Win_10015()
{
    D2Win_10115_FONT();
    sub_00502EF0(1);
    LIST_LoadPentspinCellfile();
    D2Win_10157();
    gpfWndProc_6F8FE268 = 0;
    WREGISTER_RegisterCommands(WINDOW_GetWindow(), gpCommandRegister_6F8BDE28, 0x21);
    D2Win_10177(0);
    dword_6F8FE27C = 0;
    return 1;
}

// 0x004F9030
int __stdcall D2Win_CloseSpriteCache()
{
    dword_6F8FE26C = 0;
    ghMainWindow_6F8FE23C = 0;
    D2CMPSpriteCacheDestroy(1);
    WINDOW_Destroy();
    return 1;
}

// build: symbol ?MAINMENUS_CreateLoginScreen@* 0x00432100
void __cdecl MAINMENUS_CreateLoginScreen()
{
    CHARSEL_CreateBaseScreen();
    MAINMENUS_CreateControl(0x15);
    MAINMENUS_CreateControl(0x16);
    MAINMENUS_CreateControl(0x18);
    MAINMENUS_CreateControl(0x19);
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x1A);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    pControl = MAINMENUS_CreateControl(0x1B);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B2C));
    pControl = MAINMENUS_CreateControl(0x1D);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B2D));
    pControl = MAINMENUS_CreateControl(0x1E);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B2E));
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
        pControl = MAINMENUS_CreateControl(0x21);
    else
        pControl = MAINMENUS_CreateControl(0x1F);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B2B), 0x0, 0x0, 0x0);
    gpEdit_0077958C = MAINMENUS_CreateControl(0x59);
    sub_004FDAD0_SetKeyCallback(gpEdit_0077958C, sub_0042FE70_FilterChar);
    sub_004FDD50_SetMaxLength(gpEdit_0077958C, 0x10);
    D2Win_10076(gpEdit_0077958C, gpLaunchRecord_007795D4->szAccount);
    gpEdit_00779334 = MAINMENUS_CreateControl(0x5A);
    sub_004FDAD0_SetKeyCallback(gpEdit_00779334, sub_0042FF00_FilterChar);
    sub_004FDD50_SetMaxLength(gpEdit_00779334, 0xD);
    gpEdit_00779340 = MAINMENUS_CreateControl(0x5B);
    sub_004FDD50_SetMaxLength(gpEdit_00779340, 0xD);
    gpEdit_007795A8 = MAINMENUS_CreateControl(0x5C);
    sub_004FDD50_SetMaxLength(gpEdit_007795A8, 0xD);
    if (gpLaunchRecord_007795D4->szAccount[0] != 0x0)
        CONTROL_SetFocusedEditBox(gpEdit_00779334);
    else
        CONTROL_SetFocusedEditBox(gpEdit_0077958C);
    sub_004FDDD0_LinkTab(gpEdit_0077958C, gpEdit_00779334);
    sub_004FDDD0_LinkTab(gpEdit_00779334, gpEdit_00779340);
    sub_004FDDD0_LinkTab(gpEdit_00779340, gpEdit_007795A8);
    sub_004FDDD0_LinkTab(gpEdit_007795A8, gpEdit_0077958C);
    MAINMENUS_CreateControl(0x5D);
    MAINMENUS_CreateControl(0x5E);
}

// build: symbol ?MAINMENUS_CreateEmailScreen@* 0x00436F30
void __cdecl MAINMENUS_CreateEmailScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        CHARSEL_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
        return;
    }
    CHARSEL_CreateBaseScreen();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x12B);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B6A), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x12E);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B5F), 0x0, 0x0, 0x0);
    MAINMENUS_CreateControl(0x12F);
    pControl = MAINMENUS_CreateControl(0x130);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    gpEdit_007799DC = MAINMENUS_CreateControl(0x131);
    sub_004FDD50_SetMaxLength(gpEdit_007799DC, 0x10);
    sub_004FDAD0_SetKeyCallback(gpEdit_007799DC, MAINMENUS_FilterRestrictedChar);
    sub_004FDB00_SetEnterCallback(gpEdit_007799DC, MAINMENUS_OnEditChange);
    MAINMENUS_CreateControl(0x132);
    pControl = MAINMENUS_CreateControl(0x133);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B57));
    gpEdit_007799E0 = MAINMENUS_CreateControl(0x134);
    sub_004FDB00_SetEnterCallback(gpEdit_007799E0, MAINMENUS_OnEditChange);
    D2Win_10076(gpEdit_007799DC, gpLaunchRecord_007795D4->szAccount);
    CONTROL_SetFocusedEditBox(gpEdit_007799DC);
    sub_004FDDD0_LinkTab(gpEdit_007799DC, gpEdit_007799E0);
    sub_004FDDD0_LinkTab(gpEdit_007799E0, gpEdit_007799DC);
    gpButton_007799E4 = MAINMENUS_CreateControl(0x12C);
    MAINMENUS_CreateControl(0x12D);
    MAINMENUS_UpdateEmailOk();
}

// build: symbol ?MAINMENUS_CreateInfoScreen@* 0x004370C0
void __cdecl MAINMENUS_CreateInfoScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        CHARSEL_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
        return;
    }
    CHARSEL_CreateBaseScreen();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x135);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B65), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x136);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B66), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x137);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B67), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x138);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B68), 0x0, 0x0, 0x0);
    MAINMENUS_CreateControl(0x139);
    MAINMENUS_CreateControl(0x13A);
    MAINMENUS_CreateControl(0x13B);
    MAINMENUS_CreateControl(0x13C);
}

// build: symbol ?MAINMENUS_CreatePasswordScreen@* 0x004372B0
void __cdecl MAINMENUS_CreatePasswordScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        CHARSEL_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
        return;
    }
    CHARSEL_CreateBaseScreen();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x13D);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B6C), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x13E);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B70), 0x0, 0x0, 0x0);
    MAINMENUS_CreateControl(0x13F);
    pControl = MAINMENUS_CreateControl(0x140);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    gpPasswordEdit_007799BC = MAINMENUS_CreateControl(0x141);
    D2Win_10076(gpPasswordEdit_007799BC, gpLaunchRecord_007795D4->szAccount);
    sub_004FDD50_SetMaxLength(gpPasswordEdit_007799BC, 0x10);
    sub_004FDAD0_SetKeyCallback(gpPasswordEdit_007799BC, MAINMENUS_FilterRestrictedChar);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit_007799BC, sub_004372A0_OnEnter);
    MAINMENUS_CreateControl(0x142);
    pControl = MAINMENUS_CreateControl(0x143);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B6D));
    gpPasswordEdit_007799C0 = MAINMENUS_CreateControl(0x144);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit_007799C0, sub_004372A0_OnEnter);
    MAINMENUS_CreateControl(0x145);
    pControl = MAINMENUS_CreateControl(0x146);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B6E));
    gpPasswordEdit_007799C8 = MAINMENUS_CreateControl(0x147);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit_007799C8, sub_004372A0_OnEnter);
    MAINMENUS_CreateControl(0x148);
    pControl = MAINMENUS_CreateControl(0x149);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B6F));
    gpPasswordEdit_007799C4 = MAINMENUS_CreateControl(0x14A);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit_007799C4, sub_004372A0_OnEnter);
    gpPasswordOk_007799A4 = MAINMENUS_CreateControl(0x14B);
    MAINMENUS_CreateControl(0x14C);
    CONTROL_SetFocusedEditBox(gpPasswordEdit_007799BC);
    sub_004FDDD0_LinkTab(gpPasswordEdit_007799BC, gpPasswordEdit_007799C0);
    sub_004FDDD0_LinkTab(gpPasswordEdit_007799C0, gpPasswordEdit_007799C8);
    sub_004FDDD0_LinkTab(gpPasswordEdit_007799C8, gpPasswordEdit_007799C4);
    sub_004FDDD0_LinkTab(gpPasswordEdit_007799C4, gpPasswordEdit_007799BC);
    MAINMENUS_UpdatePasswordOk();
}

// build: symbol ?MAINMENUS_CreateStatusScreen@* 0x00437550
void __cdecl MAINMENUS_CreateStatusScreen()
{
    gdwStatusStart_007799B8 = GetTickCount();
    MAINMENUS_DestroyControls();
    sub_0042E6B0(0x1);
    D2WinControlStrc* pFrame = MAINMENUS_CreateFromTemplate(0xE2);
    D2Win_10033(pFrame, 0x0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 0x1);
    D2WinControlStrc* pOther = MAINMENUS_CreateFromTemplate(0xE3);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 0x1);
    D2WinControlStrc* pText = MAINMENUS_CreateFromTemplate(0xE4);
    D2Win_10030_CONTROL_ToggleFourthFlag(pText, 0x1);
    D2Win_10051(pText, D2LANG_GetStringFromTblIndex(0x1433), 0x0, 0x0, 0x0);
    gpStatusText_007799A8 = MAINMENUS_CreateFromTemplate(0xE5);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpStatusText_007799A8, 0x1);
    gpCounterText_007799AC = MAINMENUS_CreateFromTemplate(0xE6);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpCounterText_007799AC, 0x1);
    gnStatusStringId_007799B0 = -1;
    gnStatusDots_007799B4 = 0x0;
    sub_0042E6A0(CHARSEL_SetCancelled);
    MAINMENUS_UpdateStatus();
}

// 0x004F9050
int __cdecl D2Win_10003()
{
    gdwGlobal_007D55B8 = 0x0;
    return sub_004F5D60();
}

// 0x004F9060
void __stdcall D2Win_10004(int nResolution)
{
    gnResolution_6F8FE248 = nResolution;

    if (nResolution == 1)
    {
        D2CMPSpriteCacheDestroy(1);
    }

    WINDOW_EndCutScene(nResolution);

    if (nResolution == 1)
    {
        D2CMPSpriteCacheInit(0, 0x800000, 0x7D000, 0);
    }
}

// 0x004F90A0
int __stdcall D2Win_10005(int nResolution)
{
    if (!gnResolution_6F8FE248 && !gSavedWindowRect_007D5580.right)
    {
        void* hWnd = WINDOW_GetWindow();
        WINDOW_GetDimensions((int*)&gSavedWindowRect_007D5580.right, (int*)&gSavedWindowRect_007D5580.bottom);
        GetWindowRect(hWnd, &gSavedWindowRect_007D5580);
    }

    gnResolution_6F8FE248 = nResolution;
    D2CMPSpriteCacheDestroy(1);
    if (!WINDOW_Resize(nResolution, 0))
    {
        sub_00410610_WriteLogLine("Failed to resize window... this is fatal!");
        exit(-1);
    }

    sub_004FB130_SetActiveState(0);
    D2CMPSpriteCacheInit(0, 0x800000, 0x7D000, 0);
    return 1;
}

// 0x004F9130
void __stdcall D2Win_10006_ClearDrawCaches()
{
    WINDOW_ClearCaches();
}

// 0x004F9140
int __stdcall BACKGROUND_SetCellFile(D2CelFileStrc* pCellFile)
{
    gpBackgroundCellFile = pCellFile;
    return 1;
}

// 0x004F9160
int __stdcall CURSOR_SetCellFile(D2CelFileStrc* pCellFile)
{
    gpCursorCellFile = pCellFile;
    return 1;
}

// 0x004F9180
void __stdcall D2Win_SetQuitCallback(int (__cdecl* a1)())
{
    dword_6F8FE27C = a1;
}

// 0x004F9190
int __fastcall D2Win_StopMessageLoop()
{
    dword_6F8BDF78 = 0;
    return 1;
}

// 0x004F91A0
int __stdcall CONTROL_SetCellFile(D2WinControlStrc* pControl, D2CelFileStrc* pCellFile)
{
    pControl->pCellFile = pCellFile;
    return 1;
}

// 0x004F91C0
int __stdcall CONTROL_SetFocusedEditBox(D2WinEditBoxStrc* pEditBox)
{
    if (gpEditBox_6F8FE258)
    {
        if (pEditBox != gpEditBox_6F8FE258)
        {
            EDITBOX_ClearSelection(gpEditBox_6F8FE258);
        }

        gpEditBox_6F8FE258 = pEditBox;
        return 1;
    }

    gpEditBox_6F8FE258 = pEditBox;
    return 1;
}

// 0x004F9210
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl)
{
    if (!gpControlList_6F8FE24C)
    {
        gpControlList_6F8FE24C = pControl;
        return 1;
    }

    D2WinControlStrc* pLast = gpControlList_6F8FE24C;
    while (pLast->pNext)
    {
        pLast = pLast->pNext;
    }
    pLast->pNext = pControl;
    return 1;
}

// 0x004F9250
int __fastcall CONTROL_AppendToDeadList(D2WinControlStrc* pControl)
{
    pControl->pNext = 0;
    if (!dword_6F8FE250)
    {
        dword_6F8FE250 = pControl;
        return 1;
    }

    D2WinControlStrc* pLast = dword_6F8FE250;
    while (pLast->pNext)
    {
        pLast = pLast->pNext;
    }
    pLast->pNext = pControl;
    return 1;
}

// 0x004F9290
int __stdcall CONTROL_FreeDeadList()
{
    if (gnWinCallbackDepth_007D55C4 > 0)
    {
        return 1;
    }

    while (dword_6F8FE250)
    {
        if (dword_6F8FE250->dwFlags & gdwBitMasks[0])
        {
            break;
        }

        D2WinControlStrc* pNext = dword_6F8FE250->pNext;
        FOG_Free(dword_6F8FE250, ".\\Src\\D2WinMain.cpp", 0x25A, 0);
        dword_6F8FE250 = pNext;
    }

    while (dword_6F8FE250)
    {
        if (dword_6F8FE250->dwFlags & gdwBitMasks[1])
        {
            break;
        }

        D2WinControlStrc* pNext = dword_6F8FE250->pNext;
        FOG_Free(dword_6F8FE250, ".\\Src\\D2WinMain.cpp", 0x263, 0);
        dword_6F8FE250 = pNext;
    }

    return 1;
}

// 0x004F9310
int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl)
{
    if ((D2WinControlStrc*)dword_6F8FE25C == pControl)
    {
        dword_6F8FE25C = 0;
    }

    if ((D2WinControlStrc*)gpEditBox_6F8FE258 == pControl)
    {
        gpEditBox_6F8FE258 = 0;
    }

    if (dword_6F8FE264 == pControl)
    {
        dword_6F8FE264 = 0;
        dword_6F8FE278 = 0;
    }

    if (dword_6F8FE260 == pControl)
    {
        dword_6F8FE260 = 0;
    }

    D2WinControlStrc* pPrevious = gpControlList_6F8FE24C;
    if (!pPrevious)
    {
        return 0;
    }

    if (pPrevious == pControl)
    {
        gpControlList_6F8FE24C = pControl->pNext;
        CONTROL_AppendToDeadList(pControl);
        return 1;
    }

    for (D2WinControlStrc* pCurrent = pPrevious->pNext; pCurrent; pCurrent = pCurrent->pNext)
    {
        if (pCurrent == pControl)
        {
            pPrevious->pNext = pCurrent->pNext;
            CONTROL_AppendToDeadList(pControl);
            return 1;
        }

        pPrevious = pCurrent;
    }

    return 1;
}

// 0x004F93C0
D2WinControlStrc* __stdcall CONTROL_Create(D2WinControlInitStrc* pControlInit)
{
    D2CelFileStrc* pCellFile = pControlInit->ppCellFile ? *(D2CelFileStrc**)pControlInit->ppCellFile : 0;

    switch (pControlInit->nType)
    {
    case D2WIN_TEXTBOX:
        return D2Win_10042_TEXTBOX_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->unk0x14, pControlInit->nStringId, pCellFile, pControlInit->unk0x20[0], pControlInit->unk0x20[3], pControlInit->unk0x20[2], pControlInit->unk0x20[1]);

    case D2WIN_EDITBOX:
        return D2Win_10070_EDITBOX_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->unk0x14, pControlInit->nStringId, pCellFile, pControlInit->unk0x20[1], pControlInit->unk0x20[0], pControlInit->unk0x20[3], pControlInit->unk0x20[2]);

    case D2WIN_IMAGE:
        return IMAGE2_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->unk0x20[0], pControlInit->unk0x20[1], pControlInit->unk0x20[2]);

    case D2WIN_ANIMIMAGE:
        return ANIMIMAGE_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->unk0x14, pControlInit->unk0x20[0], pControlInit->unk0x20[1], pControlInit->nStringId, pControlInit->unk0x20[2]);

    case D2WIN_IMAGE2:
        return IMAGE_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->unk0x14, pControlInit->nStringId);

    case D2WIN_SCROLLBAR:
        return SCROLLBAR_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->unk0x20[0]);

    case D2WIN_BUTTON:
        return BUTTON_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->unk0x20[0], pControlInit->unk0x14, pControlInit->unk0x20[1], pControlInit->unk0x20[3], pControlInit->nStringId, pControlInit->unk0x20[2]);

    case D2WIN_LIST:
        return LIST_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->unk0x20[1], pControlInit->unk0x20[2]);

    case D2WIN_TIMER:
        return TIMER_Create(pControlInit->nX, pControlInit->unk0x20[0]);

    case D2WIN_SMACK:
        return SMACK_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->unk0x20[0]);

    case D2WIN_PROGRESSBAR:
        return PROGRESSBAR_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight);

    case D2WIN_ACCOUNTLIST:
        return ACCOUNTLIST_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->unk0x20[3], pControlInit->unk0x20[2]);

    default:
        break;
    }

    return 0;
}

// 0x004F95C0
int __stdcall CONTROL_Destroy(D2WinControlStrc** ppControl)
{
    if (!ppControl)
    {
        return 0;
    }

    D2WinControlStrc* pControl = *ppControl;
    if (!pControl)
    {
        return 0;
    }

    int nResult;
    switch (pControl->eType)
    {
    case D2WIN_TEXTBOX:
        nResult = D2Win_10043_TEXTBOX_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_EDITBOX:
        nResult = D2Win_10071_EDITBOX_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_IMAGE:
        nResult = IMAGE_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_IMAGE2:
        nResult = IMAGE2_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_ANIMIMAGE:
        nResult = ANIMIMAGE_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_SCROLLBAR:
        nResult = SCROLLBAR_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_BUTTON:
        nResult = BUTTON_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_LIST:
        nResult = LIST_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_TIMER:
        nResult = TIMER_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_SMACK:
        nResult = SMACK_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_PROGRESSBAR:
        nResult = PROGRESSBAR_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_ACCOUNTLIST:
        nResult = ACCOUNTLIST_Destroy(pControl);
        *ppControl = 0;
        break;

    default:
        nResult = 0;
        *ppControl = 0;
        break;
    }

    return nResult;
}

// 0x004F96F0
void __fastcall CONTROL_SetEnabled(D2WinControlStrc* pControl, int nFlags)
{
    if (!pControl)
    {
        return;
    }

    if (nFlags)
    {
        pControl->dwFlags |= gdwBitMasks[0];
    }
    else
    {
        pControl->dwFlags &= gdwInvBitMasks[0];
    }
}

// 0x004F9710
int __fastcall CONTROL_IsEnabled(D2WinControlStrc* pControl)
{
    D2_ASSERT(pControl, 0x33F);

    return pControl->dwFlags & gdwBitMasks[0];
}

// 0x004F9740
void __fastcall CONTROL_SetVisible(D2WinControlStrc* pControl, int bSet)
{
    D2_ASSERT(pControl, 0x34C);

    if (bSet)
    {
        pControl->dwFlags |= gdwBitMasks[2];
    }
    else
    {
        pControl->dwFlags &= gdwInvBitMasks[2];
    }
}

// 0x004F9780
int __fastcall CONTROL_IsVisible(D2WinControlStrc* pControl)
{
    D2_ASSERT(pControl, 0x35A);

    return pControl->dwFlags & gdwBitMasks[2];
}

// 0x004F97B0
int __stdcall CONTROL_MouseInsideRect(const tagRECT* pRect)
{
    return PtInRect(pRect, gMousePosition_6F8FE234);
}

// 0x004F98E0
void __stdcall D2Win_UpdateAndDraw()
{
    if (WINDOW_GetState())
    {
        return;
    }

    for (D2WinControlStrc* i = gpControlList_6F8FE24C; i; i = i->pNext)
    {
        if (i->pfInitialize)
        {
            i->pfInitialize(i);
        }
    }

    if (gpfWndProc_6F8FE268)
    {
        return;
    }

    long nScreenWidth;
    long nScreenHeight;
    WINDOW_GetDimensions((int*)&nScreenWidth, (int*)&nScreenHeight);

    if (D2GFX_StartDraw(0, 0, 0, 0))
    {
        D2GFX_ClearScreen(0);

        if (gpBackgroundCellFile)
        {
            D2CelContextStrc tContext;
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = gpBackgroundCellFile;
            tContext.nDirection = 0;
            tContext.nFrame = 0;

            for (int y = 256; y < 768; y += 256)
            {
                for (int x = 0; x < 1024; x += 256)
                {
                    sub_004F6480(&tContext, x, y, -1, 5, 0);
                    ++tContext.nFrame;
                }
            }

            for (int x = 0; x < 1024; x += 256)
            {
                sub_004F6480(&tContext, x, nScreenHeight - 1, -1, 5, 0);
                ++tContext.nFrame;
            }
        }

        for (D2WinControlStrc* i = gpControlList_6F8FE24C; i; i = i->pNext)
        {
            if (i->pfDraw && !(i->dwFlags & gdwBitMasks_006CE268[3]))
            {
                i->pfDraw(i);
            }
        }

        D2COMP_DrawAllCompositeUnits();

        if (dword_6F8FE278)
        {
            D2GFX_DrawBoxAlpha(0, 0, nScreenWidth, nScreenHeight, 0, 127);
        }

        for (D2WinControlStrc* i = gpControlList_6F8FE24C; i; i = i->pNext)
        {
            if (i->pfDraw && (i->dwFlags & gdwBitMasks_006CE268[3]))
            {
                i->pfDraw(i);
            }
        }

        CURSOR_Draw();
        D2GFX_EndScene();
    }

    CONTROL_FreeDeadList();
}

// 0x004F97E0
void __cdecl CURSOR_Draw()
{
    if (gpCursorCellFile && dword_6F8BDE18)
    {
        int nX = gMousePosition_6F8FE234.x;
        int nY = gMousePosition_6F8FE234.y;
        dword_6F8FE228 = nX;
        dword_6F8FE22C = nY;

        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.nFrame = gnCursorFrame;
        tContext.pCellFile = gpCursorCellFile;
        tContext.nDirection = 0;
        sub_004F6480(&tContext, nX <= 0 ? 0 : nX, (nY <= 0 ? 0 : nY) - 1, -1, 5, 0);
    }
}

// 0x004F9870
void __cdecl D2COMP_DrawAllCompositeUnits()
{
    for (D2CompositeUnitStrc* p = D2COMP_GetFirstCompositeUnit(); p; p = D2Win_10148(p))
    {
        D2COMP_DrawCompositeShadow(p);
    }

    for (D2CompositeUnitStrc* p = D2COMP_GetFirstCompositeUnit(); p; p = D2Win_10148(p))
    {
        D2COMP_DrawCompositeUnit(p, -1);
    }

    for (D2CompositeUnitStrc* p = D2COMP_GetFirstCompositeUnit(); p; p = D2Win_10148(p))
    {
        D2COMP_DrawCompositeLabel(p);
        D2COMP_DrawCompositeHover(p);
    }
}

static inline int CONTROL_IsMouseInside_004FA860(D2WinControlStrc* pControl)
{
    const int nImageY = pControl->nImageY;
    return gMousePosition_6F8FE234.x >= pControl->nImageX && gMousePosition_6F8FE234.y >= nImageY - pControl->nHeight
        && gMousePosition_6F8FE234.x < pControl->nImageX + pControl->nWidth && gMousePosition_6F8FE234.y < nImageY;
}

// 0x004F9A80
long __stdcall D2Win_MAINWINDOW_WndProc_6F8AD9B0(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam)
{
    if (!dword_6F8FE26C)
    {
        return 0;
    }

    if (gpfWndProc_6F8FE268)
    {
        return gpfWndProc_6F8FE268(hWnd, uMsg, wParam, lParam);
    }

    int bUseResult = 0;
    int lResult = 0;
    if (uMsg == 0x10)
    {
        dword_6F8FE280 = 1;
        PostQuitMessage(0);
        return 0;
    }

    if (SMsgDispatchMessage(hWnd, uMsg, wParam, lParam, &bUseResult, &lResult) && bUseResult)
    {
        return lResult;
    }

    return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

// 0x004F9B30
int __fastcall CONTROL_IsActiveListMember(D2WinControlStrc* pControl)
{
    if (dword_6F8FE264)
    {
        for (D2WinControlStrc* p = dword_6F8FE264; p; p = p->pNext)
        {
            if (p == pControl)
            {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

// 0x004F9B60
void __stdcall D2Win_COMMANDS_Char_6F8ADA80(SMSGHANDLER_PARAMS* pMsg)
{
    const int nChar = pMsg->wParam;
    if (dword_6F8FE25C)
    {
        if (dword_6F8FE264)
        {
            for (D2WinControlStrc* i = dword_6F8FE264; i; i = i->pNext)
            {
                if ((D2WinEditBoxStrc*)i == dword_6F8FE25C)
                {
                    goto check_edit_box;
                }
            }
            goto dispatch;
        }

check_edit_box:
        if (D2Win_10074(dword_6F8FE25C, nChar))
        {
            goto done;
        }
    }

dispatch:
    {
        D2WinControlStrc* pControl = dword_6F8FE264;
        if (!pControl)
        {
            pControl = gpControlList_6F8FE24C;
        }

        while (pControl)
        {
            if (pControl->pfHandleCharInput)
            {
                pMsg->hWnd = pControl;
                ++dword_6F8FE254;
                const int nResult = pControl->pfHandleCharInput(pMsg);
                --dword_6F8FE254;
                if (nResult)
                {
                    break;
                }
            }
            pControl = pControl->pNext;
        }
    }

done:
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004F9BF0
void __stdcall D2Win_COMMANDS_VirtualKey_6F8ADB50(SMSGHANDLER_PARAMS* pMsg)
{
    const int nKey = pMsg->wParam;
    if (dword_6F8FE25C)
    {
        if (dword_6F8FE264)
        {
            for (D2WinControlStrc* i = dword_6F8FE264; i; i = i->pNext)
            {
                if ((D2WinEditBoxStrc*)i == dword_6F8FE25C)
                {
                    goto check_edit_box;
                }
            }
            goto dispatch;
        }

check_edit_box:
        if (EDITBOX_HandleKeyDown(dword_6F8FE25C, nKey))
        {
            goto done;
        }
    }

dispatch:
    {
        D2WinControlStrc* pControl = dword_6F8FE264;
        if (!pControl)
        {
            pControl = gpControlList_6F8FE24C;
        }

        while (pControl)
        {
            if (pControl->pfHandleVirtualKeyInput)
            {
                pMsg->hWnd = pControl;
                ++dword_6F8FE254;
                const int nResult = pControl->pfHandleVirtualKeyInput(pMsg);
                --dword_6F8FE254;
                if (nResult)
                {
                    break;
                }
            }
            pControl = pControl->pNext;
        }
    }

done:
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004F9C80
void __stdcall D2Win_COMMANDS_Control_6F8ADBE0(SMSGHANDLER_PARAMS* pMsg)
{
    dword_6F8FE274 = 1;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004F9CA0
void __stdcall D2Win_COMMANDS_Control_6F8ADBF0(SMSGHANDLER_PARAMS* pMsg)
{
    dword_6F8FE274 = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004F9CC0
void __stdcall D2Win_COMMANDS_SysCommand(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned short nCommand = pMsg->wParamLow & 0xFFF0;
    if (nCommand == 0xF130 || nCommand == 0xF100 || (nCommand == 0xF010 && WINDOW_IsFullScreen()))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        return;
    }

    if (nCommand != 0xF030)
    {
        return;
    }

    if (WINDOW_IsFullScreen())
    {
        return;
    }

    void* hWnd = WINDOW_GetWindow();
    void* hMonitor = MonitorFromWindow(hWnd, 2);
    tagMONITORINFO tMonitorInfo;
    tMonitorInfo.cbSize = sizeof(tagMONITORINFO);
    GetMonitorInfoA(hMonitor, &tMonitorInfo);

    tagRECT tClientRect = {};
    GetClientRect(hWnd, &tClientRect);
    const int nClientWidth = tClientRect.right - tClientRect.left;
    const int nClientHeight = tClientRect.bottom - tClientRect.top;

    tagRECT tWorkArea = tMonitorInfo.rcWork;
    const int nWorkWidth = tWorkArea.right - tWorkArea.left;
    const int nWorkHeight = tWorkArea.bottom - tWorkArea.top;

    tagRECT tRect = {};
    const int nMode = D2GFX_GetResolutionMode();
    WINDOW_GetResolutionSize(nMode, &tRect.right, &tRect.bottom);

    tagRECT tDesktopRect;
    GetClientRect(GetDesktopWindow(), &tDesktopRect);

    if (nClientWidth == tRect.right && nClientHeight == tRect.bottom
        && tDesktopRect.right - tDesktopRect.left > tRect.right && tDesktopRect.bottom - tDesktopRect.top > tRect.bottom)
    {
        tRect.left = tWorkArea.left;
        tRect.top = tWorkArea.top;
        if (!D2GFX_IsFixedAspectRatio())
        {
            return;
        }

        tagWINDOWPLACEMENT tPlacement;
        GetWindowPlacement(hWnd, &tPlacement);
        if (tPlacement.showCmd != 3)
        {
            while (tRect.right < nWorkWidth && tRect.bottom < nWorkHeight)
            {
                tRect.right += 4;
                tRect.bottom += 3;
            }
            tRect.right -= 12;
            tRect.bottom -= 9;
            tRect.left = (nWorkWidth - tRect.right) / 2 + tWorkArea.left;
            tRect.top = (nWorkHeight - tRect.bottom) / 2 + tWorkArea.top;
            if (tRect.top < 0)
            {
                tRect.top = 0;
            }
            if (tRect.left < 0)
            {
                tRect.left = 0;
            }
            gWindowRect_007C9160 = tPlacement.rcNormalPosition;
            SetWindowPos(hWnd, (void*)-2, tRect.left, tRect.top, tRect.right, tRect.bottom, 0x14);
        }
    }
    else if (tRect.bottom < tWorkArea.bottom && tRect.right < tWorkArea.right)
    {
        tagRECT tNewRect = { 0 };
        const int nResolution = D2GFX_GetResolutionMode();
        WINDOW_GetResolutionSize(nResolution, &tNewRect.right, &tNewRect.bottom);
        SetWindowPos(hWnd, (void*)-2, 0, 0, tNewRect.right, tNewRect.bottom, 0x14);
        WINDOW_CenterWindow(nResolution);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x004F9F20
void __stdcall D2Win_COMMANDS_ActivateApp_6F8ADC40(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nActive = pMsg->wParam;
    dword_6F8BDE20 = nActive != 0;
    if (nActive)
    {
        if (!sub_00407FF0())
        {
            WINDOW_SetPaused(0);
            sub_004FB130_SetActiveState(1);
        }

        D2SOUND_10049(dword_6F8FE284);
        dword_6F8FE288 = 0;
    }
    else
    {
        if (!dword_6F8FE288)
        {
            dword_6F8FE284 = D2SOUND_GetMusicVolumeOption();
        }

        dword_6F8FE288 = 1;
        if (gdwGlobal_007D55B4 != 1)
        {
            WINDOW_SetPaused(1);
        }
    }

    if (WINDOW_CheckCutScene())
    {
        WINDOW_GetState();
    }

    pMsg->bReturn = 0;
}

// 0x004F9FB0
static void __stdcall D2Win_WriteScreenshotJpeg(unsigned char* pData, const char* szFile, int nWidth, int nHeight)
{
    char szName[256];
    JPEG_CORE_PROPERTIES tProps;
    while (1)
    {
        sprintf(szName, "Screenshot%03d.jpg", gnScreenshotIndex_0072DC40);
        ++gnScreenshotIndex_0072DC40;
        void* hFile = FOG_CreateFileA(szFile ? szFile : szName, 0x80000000, 0, 0, 3, 0x80, 0);
        if (hFile == (void*)-1)
        {
            break;
        }

        FOG_CloseFile(hFile);
        if (szFile)
        {
            return;
        }
    }

    memset(&tProps, 0, sizeof(tProps));
    ijlInit(&tProps);
    tProps.DIBWidth = nWidth;
    tProps.DIBHeight = nHeight;
    tProps.DIBBytes = pData;
    tProps.DIBColor = 1;
    tProps.DIBPadBytes = ((nWidth * 3 + 3) & ~3) - nWidth * 3;
    if (szFile)
    {
        tProps.JPGFile = szFile;
    }
    else
    {
        tProps.JPGFile = szName;
    }
    tProps.JPGWidth = nWidth;
    tProps.JPGHeight = nHeight;
    tProps.jquality = 100;
    ijlWrite(&tProps, 8);
    ijlFree(&tProps);
}

// 0x004FA0C0
void __fastcall D2Win_SaveScreenshotToFile(const char* szFile)
{
    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastScreenshotTick_007D5600 < 1000 && !szFile)
    {
        return;
    }

    int nWidth = 0;
    int nHeight = 0;
    WINDOW_GetDimensions((int*)&nWidth, (int*)&nHeight);
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(nHeight * nWidth * 3, ".\\Src\\D2WinMain.cpp", 0x6A7, 0);
    if (D2GFX_GetBackBuffer(pBuffer))
    {
        D2Win_WriteScreenshotJpeg(pBuffer, szFile, nWidth, nHeight);
    }

    gdwLastScreenshotTick_007D5600 = dwTick;
    FOG_Free(pBuffer, ".\\Src\\D2WinMain.cpp", 0x6B4, 0);
}

// 0x004FA160
void __stdcall D2Win_COMMANDS_ToggleMusic(SMSGHANDLER_PARAMS* pMsg)
{
    if (!dword_6F8FE274 || !D2SOUND_AreWaveSlotsInitialized())
    {
        return;
    }

    if (D2SOUND_GetOptionsMusicOption())
    {
        D2SOUND_FadeOutStreamChannel();
        D2SOUND_10070(0);
    }
    else
    {
        D2SOUND_10034(1);
        D2SOUND_10070(1);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x004FA1B0
static inline int CONTROL_IsPointInside(Control* control, const Point* point)
{
    if (control->shouldHandle)
        return control->shouldHandle(control);
    const int left = control->x;
    const int bottom = control->y;
    if (point->x >= left && point->y >= bottom - control->height
        && point->x < left + control->width && point->y < bottom)
        return 1;
    return 0;
}

// 0x004FA200
static D2WinControlStrc* __stdcall CONTROL_PickClosestToMouse(D2WinControlStrc* first, D2WinControlStrc* second)
{
    if (!first) return second;
    if (!second) return first;
    int mouseX = gnMouseX_007D55A4;
    int mouseY = gnMouseY_007D55A8;
    int dx1, dy1, dx2, dy2;
    if (mouseX < first->nImageX)
        dx1 = mouseX - first->nImageX;
    else if (mouseX > first->nWidth + first->nImageX)
        dx1 = mouseX - first->nWidth - first->nImageX;
    else
        dx1 = 0;
    if (mouseY < first->nImageY - first->nHeight)
        dy1 = first->nHeight - first->nImageY + mouseY;
    else if (mouseY > first->nImageY)
        dy1 = mouseY - first->nImageY;
    else
        dy1 = 0;

    if (mouseX < second->nImageX)
        dx2 = mouseX - second->nImageX;
    else if (mouseX > second->nWidth + second->nImageX)
        dx2 = mouseX - second->nWidth - second->nImageX;
    else
        dx2 = 0;
    if (mouseY < second->nImageY - second->nHeight)
        dy2 = second->nHeight - second->nImageY + mouseY;
    else if (mouseY > second->nImageY)
        dy2 = mouseY - second->nImageY;
    else
        dy2 = 0;
    int alignedFirst = dy1 == 0 && dx1 <= 0;
    int alignedSecond = dy2 == 0 && dx2 <= 0;
    if (alignedFirst && !alignedSecond)
        return first;
    if (!alignedFirst && alignedSecond)
        return second;
    if (alignedFirst && alignedSecond)
    {
        if (dx1 > dx2)
            return first;
        return second;
    }
    if (dy1 * dy1 + dx1 * dx1 < dy2 * dy2 + dx2 * dx2)
        return first;
    return second;
}

int __stdcall emit_hit_test_004FA1B0(Control* control, const Point* point) { return CONTROL_IsPointInside(control, point); }

inline int CONTROL_IsInActiveList(void* pControl)
{
    if (!dword_6F8FE264)
    {
        return 1;
    }

    for (D2WinControlStrc* p = dword_6F8FE264; p; p = p->pNext)
    {
        if (p == pControl)
        {
            return 1;
        }
    }

    return 0;
}

// 0x004FA340
void __stdcall D2Win_COMMANDS_MouseWheel_6F8AE220(SMSGHANDLER_PARAMS* pMsg)
{
    const int nIncrement = (int)(short)(pMsg->wParam >> 16) / 120;

    if (POPUP_IsActive())
    {
        return;
    }

    D2WinControlStrc* pScrollBar = 0;
    D2WinControlStrc* pFirst = dword_6F8FE264 ? dword_6F8FE264 : gpControlList_6F8FE24C;
    if (pFirst)
    {
        D2WinControlStrc* pControl = pFirst;
        do
        {
            if (pControl->eType == D2WIN_SCROLLBAR && pControl->dwFlags & gdwBitMasks[2] && pControl->dwFlags & gdwBitMasks[0] && SCROLLBAR_GetMaxSteps((D2WinScrollBarStrc*)pControl) > 0)
            {
                pScrollBar = CONTROL_PickClosestToMouse(pScrollBar, pControl);
            }

            pControl = pControl->pNext;
        }
        while (pControl);

        if (pScrollBar && SCROLLBAR_HandleMouseWheel(pMsg, (D2WinScrollBarStrc*)pScrollBar, nIncrement))
        {
            goto done;
        }
    }

    for (D2WinControlStrc* i = pFirst; i; i = i->pNext)
    {
        if (i->eType == D2WIN_BUTTON && BUTTON_OnMouseWheelScrolled((D2WinButtonStrc*)i, nIncrement))
        {
            break;
        }
    }

done:
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004FA520
int __stdcall D2Win_CreateWindow(void* hInstance, int nRenderMode, int bWindowed, int bCompress)
{
    gdwGlobal_007D5590 = nRenderMode;
    D2CMPSetNoCompress(bCompress);
    return D2GFX_Initialize(hInstance, D2Win_MAINWINDOW_WndProc_6F8AD9B0, nRenderMode, bWindowed);
}

// 0x004FA550
int __fastcall D2Win_10016()
{
    gnWinCallbackDepth_007D55C4 = 0;
    CONTROL_FreeDeadList();
    LIST_UnloadPentspinCellfile();
    D2Win_10116();
    WREGISTER_UnregisterCommands(WINDOW_GetWindow(), gpCommandRegister_6F8BDE28, 0x21);
    return 1;
}

// 0x004FA590
int __stdcall D2Win_RunMessageLoop(void (__stdcall* pCallback)(unsigned long))
{
    unsigned long dwCounter = 0;
    unsigned long dwTickCount = GetTickCount();
    int nSleepMillis = 0;

    while (dword_6F8BDF78)
    {
        tagMSG tMsg;
        if (PeekMessageA(&tMsg, 0, 0, 0, 0))
        {
            dword_6F8BDF78 = GetMessageA(&tMsg, 0, 0, 0);
            if (!dword_6F8BDF78 && dword_6F8FE27C)
            {
                dword_6F8FE27C();
            }

            TranslateMessage(&tMsg);
            DispatchMessageA(&tMsg);
        }
        else
        {
            unsigned long dwTickDiff = GetTickCount() - dwTickCount;
            dwTickCount = GetTickCount();
            if (dwTickDiff > 1000)
            {
                dwTickDiff = 1000;
            }

            nSleepMillis -= dwTickDiff;
            if (nSleepMillis <= 0)
            {
                nSleepMillis += 40;
                if (nSleepMillis < -1000)
                {
                    nSleepMillis = 0;
                }

                if (pCallback)
                {
                    pCallback(dwCounter);
                    dwCounter += 1;
                }

                D2Win_UpdateAndDraw();
            }

            dword_6F8FE25C = gpEditBox_6F8FE258;
            unsigned long dwSleepMillis = nSleepMillis;
            if (dwSleepMillis > 20)
            {
                dwSleepMillis = 20;
            }

            if (dword_6F8BDE20)
            {
                dwSleepMillis = 0;
            }

            Sleep(dwSleepMillis);
        }
    }

    D2Win_UpdateAndDraw();
    if (!dword_6F8FE280)
    {
        dword_6F8BDF78 = 1;
    }

    return 0;
}

// 0x004FA6B0
void __stdcall D2Win_COMMANDS_MouseMove_6F8AD670(SMSGHANDLER_PARAMS* pMsg)
{
    if (!gbMouseTracking_007D55F0)
    {
        tagTRACKMOUSEEVENT tEventTrack;
        tEventTrack.cbSize = sizeof(tEventTrack);
        tEventTrack.dwFlags = 2;
        tEventTrack.hwndTrack = pMsg->hWnd;
        tEventTrack.dwHoverTime = 0;
        TrackMouseEvent(&tEventTrack);
        gbMouseTracking_007D55F0 = 1;
    }

    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    dword_6F8BDE18 = 1;
    WINDOW_ShowCursor(1);

    int nScreenWidth;
    int nScreenHeight;
    WINDOW_GetDimensions((int*)&nScreenWidth, (int*)&nScreenHeight);
    --nScreenWidth;
    --nScreenHeight;

    if (D2GFX_HardwareAcceleratedRenderMode())
    {
        int bSetCursorPos = 0;
        if (nX > nScreenWidth)
        {
            nX = nScreenWidth;
            bSetCursorPos = 1;
        }

        if (nY > nScreenHeight)
        {
            nY = nScreenHeight;
            bSetCursorPos = 1;
        }

        if (bSetCursorPos)
        {
            SetCursorPos(nX, nY);
        }
    }

    gMousePosition_6F8FE234.x = nX;
    gMousePosition_6F8FE234.y = nY;
}

// 0x004FA760
void __stdcall D2Win_COMMANDS_Escape_6F8ADB10(SMSGHANDLER_PARAMS* pMsg)
{
    if (dword_6F8FE260 && CONTROL_IsInActiveList(dword_6F8FE260))
    {
        pMsg->hWnd = dword_6F8FE260;
        BUTTON_SimulateClick(pMsg);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    D2Win_COMMANDS_VirtualKey_6F8ADB50(pMsg);
}

// 0x004FA7A0
void __stdcall D2Win_10168_WINMAIN_CreateScreenshot()
{
    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastScreenshotTick_007D5600 < 1000)
    {
        return;
    }

    int nWidth = 0;
    int nHeight = 0;
    WINDOW_GetDimensions((int*)&nWidth, (int*)&nHeight);
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(nHeight * nWidth * 3, ".\\Src\\D2WinMain.cpp", 0x6A7, 0);
    if (D2GFX_GetBackBuffer(pBuffer))
    {
        D2Win_WriteScreenshotJpeg(pBuffer, 0, nWidth, nHeight);
    }

    gdwLastScreenshotTick_007D5600 = dwTick;
    FOG_Free(pBuffer, ".\\Src\\D2WinMain.cpp", 0x6B4, 0);
}

// 0x004FA840
void __stdcall D2Win_COMMANDS_Snapshot_6F8ADE70(SMSGHANDLER_PARAMS* pMsg)
{
    D2Win_10168_WINMAIN_CreateScreenshot();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x004FA860
void __stdcall D2Win_COMMANDS_MouseButton_6F8AE070(SMSGHANDLER_PARAMS* pMsg)
{
    D2Win_COMMANDS_MouseMove_6F8AD670(pMsg);
    if (POPUP_IsActive())
    {
        const int bInputHandled = POPUP_HandleMouseButtonInput(pMsg);
        POPUP_Destroy();
        if (bInputHandled)
        {
            return;
        }
    }

    D2WinControlStrc* pControl = dword_6F8FE264;
    if (!pControl)
    {
        pControl = gpControlList_6F8FE24C;
    }

    switch (pMsg->uMessage)
    {
    case 0x201:
    case 0x204:
        gbIsMouseButtonPressed = 1;
        while (pControl)
        {
            if (pControl->pfShouldMouseInputBeHandled ? pControl->pfShouldMouseInputBeHandled(pControl) : CONTROL_IsMouseInside_004FA860(pControl))
            {
                pMsg->hWnd = pControl;
                if (pControl->pfHandleMouseDown)
                {
                    ++dword_6F8FE254;
                    const int nResult = pControl->pfHandleMouseDown(pMsg);
                    --dword_6F8FE254;
                    if (nResult)
                    {
                        break;
                    }
                }
            }
            pControl = pControl->pNext;
        }
        break;

    case 0x202:
    case 0x205:
        gbIsMouseButtonPressed = 0;
        while (pControl)
        {
            pMsg->hWnd = pControl;
            if (pControl->pfHandleMouseUp)
            {
                ++dword_6F8FE254;
                pControl->pfHandleMouseUp(pMsg);
                --dword_6F8FE254;
            }
            pControl = pControl->pNext;
        }
        break;
    }

    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004FAD10
int __fastcall ARCHIVE_LoadVideoArchives(void* pfShowMessage, void* hFile, int bExpansion)
{
    if (sub_00406D20())
    {
        pfShowMessage = 0;
    }

    if (bExpansion)
    {
        gpD2XVideoMPQ = sub_00517332_LoadMpqFile(szD2XVideoMpq_006DC788, hFile, pfShowMessage, 1000);
        if (!gpD2XVideoMPQ)
        {
            return 0;
        }
    }
    else
    {
        gpD2VideoMPQ = sub_00517332_LoadMpqFile("d2video.mpq", hFile, pfShowMessage, 1000);
        if (!gpD2VideoMPQ)
        {
            return 0;
        }
    }

    return 1;
}

// 0x004FB010
void __cdecl PALETTE_ApplyPaletteTables()
{
    D2PaletteTableStrc tPaletteTable;

    for (int i = 0; i < 3; ++i)
    {
        tPaletteTable.pTransPalettes[i] = gTransPalette_007EE468[i].data;
    }

    for (int i = 0; i < 49; ++i)
    {
        tPaletteTable.pShadowLightGammaPalettes[i] = gShadowsLightGammaPalette_0081EA68[i].data;
    }

    for (int i = 0; i < 13; ++i)
    {
        tPaletteTable.pStandardShiftPalettes[i] = gStandardShiftsPalette_007D5668[i].data;
    }

    tPaletteTable.pScreenPalette = gScreenPalette_007DE468;
    tPaletteTable.pLuminancePalette = gLuminancePalette_00821B68;
    tPaletteTable.pDarkBlendPalette = gDarkBlendPalette_00831B68;
    tPaletteTable.pDarkenPalette = gDarkenPalette_0081E468;
    tPaletteTable.pStandardColorsPalette = gStandardColorsPalette_007D563C;
    tPaletteTable.pRemap = gbyPaletteMap_007D6368;
    tPaletteTable.unk0x11C = gbyPaletteMap_0081E568;
    D2GFX_SetPaletteTables(&tPaletteTable);
}

// 0x004FB740
int __fastcall D2Win_10062(D2WinTextBoxStrc* ptTextData, int a2, int a3)
{
    D2_ASSERT(ptTextData, 0xFA);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0xFB);

    ptTextData->unk0xA0 = a2;
    ptTextData->unk0xA4 = a3;
    return 1;
}

// 0x004FA410
void __stdcall D2Win_10029(int a1)
{
    dword_6F8BDE18 = a1;
}

// 0x004FA420
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet)
{
    if (bSet)
    {
        pControl->dwFlags |= gdwBitMasks_006CE268[3];
    }
    else
    {
        pControl->dwFlags &= gdwInvBitMasks_006CE2E8[3];
    }
}

// 0x004FA450
void __stdcall CONTROL_SetEscapeButton(void* a1)
{
    dword_6F8FE260 = a1;
}

// 0x004FA470
int __stdcall D2Win_10033(D2WinControlStrc* a1, int a2)
{
    dword_6F8FE264 = a1;
    dword_6F8FE278 = a2;
    return 1;
}


// 0x004FA490
extern "C" __declspec(dllexport) unsigned int __stdcall CONTROL_GetType(Obj004FA490* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue00;
}

// 0x004FA4C0
void __stdcall D2Win_COMMANDS_NcMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->wParam == 2)
    {
        dword_6F8BDE18 = 0;
        WINDOW_ShowCursor(0);
    }
    else
    {
        dword_6F8BDE18 = 0;
    }
    pMsg->bReturn = 0;
    pMsg->lResult = 0;
}

// 0x004FA4F0
void __stdcall D2Win_COMMANDS_MouseLeave(SMSGHANDLER_PARAMS* pMsg)
{
    gbMouseTracking_007D55F0 = 0;
    if (gdwGlobal_007D5590 != 4)
    {
        dword_6F8BDE18 = 0;
    }
    WINDOW_ShowCursor(0);
    pMsg->bReturn = 0;
    pMsg->lResult = 0;
}

// 0x004FBB90
Unicode* __fastcall D2Win_10196(D2WinTextBoxStrc* pTextBox, int nLineNum, int nColumnNum)
{
    D2_ASSERT(pTextBox, 0x2C2);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x2C3);
    D2_ASSERT(nLineNum <= pTextBox->nNumLines, 0x2C4);
    D2_ASSERT(nColumnNum < 5, 0x2C5);

    D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine;
    int i = 0;
    while (i < nLineNum)
    {
        if (!pLine->pNext)
        {
            break;
        }

        pLine = pLine->pNext;
        ++i;
    }

    D2_ASSERT(pLine, 0x2CF);
    D2_ASSERT(i == nLineNum, 0x2D0);

    return pLine->pColumns[nColumnNum];
}

// 0x004FBDE0
int __fastcall D2Win_10188(D2WinTextBoxStrc* pTextBox, int nLineNum, int a3)
{
    D2_ASSERT(pTextBox, 0x368);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x369);

    if (nLineNum == -1)
    {
        for (D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine; pLine; pLine = pLine->pNext)
        {
            pLine->unk0x14 = a3;
        }

        return 1;
    }

    D2_ASSERT(nLineNum <= pTextBox->nNumLines, 0x378);

    D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine;
    int i = 0;
    while (i < nLineNum)
    {
        if (!pLine->pNext)
        {
            break;
        }

        pLine = pLine->pNext;
        ++i;
    }

    D2_ASSERT(pLine, 0x382);
    D2_ASSERT(i == nLineNum, 0x383);

    pLine->unk0x14 = a3;
    return 1;
}

// 0x004FC3F0
int __stdcall TEXTBOX_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinTextBoxStrc* pTextBox = (D2WinTextBoxStrc*)pMsg->hWnd;

    D2_ASSERT(pTextBox, 0x501);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x502);

    if (!(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[0])
// build: symbol ?CONTROL_GetFocusedEditBox@* 0x004F9200
        || pTextBox->nNumLines < 1 || pTextBox->nCurrentLine == -1 || CONTROL_GetFocusedEditBox())
    {
        return 0;
    }

    const int nNumLines = pTextBox->nNumLines;
    int nLine = pTextBox->nLine;
    int nCurrentLine = pTextBox->nCurrentLine;
    const int nVisibleLines = D2Win_10055((D2WinTextBoxStrc*)pMsg->hWnd);

    switch (pMsg->wParam)
    {
    case 0x21:
        if (nCurrentLine > nLine)
        {
            nCurrentLine = nLine;
        }
        else if (nLine > 0)
        {
            nLine = D2WIN_MAX(nLine - nVisibleLines + 1, 0);
            nCurrentLine = nLine;
        }
        break;

    case 0x22:
    {
        const int nLastVisible = nVisibleLines + nLine - 1;
        if (nCurrentLine < nLastVisible)
        {
            nCurrentLine = D2WIN_MIN(nLastVisible, nNumLines - 1);
        }
        else if (nLine < nNumLines - nVisibleLines)
        {
            nLine = D2WIN_MIN(nLastVisible, nNumLines - nVisibleLines);
            nCurrentLine = D2WIN_MIN(nVisibleLines + nLine - 1, nNumLines - 1);
        }
        break;
    }

    case 0x26:
        if (nCurrentLine > 0)
        {
            --nCurrentLine;
            if (nCurrentLine < nLine)
            {
                nLine = nCurrentLine;
            }
            else if (nCurrentLine > nVisibleLines + nLine - 1)
            {
                nLine = nCurrentLine - nVisibleLines + 1;
            }
        }
        break;

    case 0x28:
        if (nCurrentLine < nNumLines - 1)
        {
            ++nCurrentLine;
            if (nCurrentLine < nLine)
            {
                nLine = nCurrentLine;
            }
            else if (nCurrentLine > nVisibleLines + nLine - 1)
            {
                nLine = nCurrentLine - nVisibleLines + 1;
            }
        }
        break;

    case 0x24:
        nCurrentLine = 0;
        nLine = 0;
        break;

    case 0x23:
        nCurrentLine = nNumLines - 1;
        nLine = nNumLines - nVisibleLines;
        break;
    }

    const int bHasChanged = nCurrentLine != pTextBox->nCurrentLine;
    pTextBox->nCurrentLine = nCurrentLine;

    if (nNumLines > nVisibleLines && nLine != pTextBox->nLine)
    {
        D2Win_10053((D2WinTextBoxStrc*)pMsg->hWnd, nLine);
    }

    if (bHasChanged && pTextBox->controlHeader.field_34)
    {
        pTextBox->controlHeader.field_34(pMsg);
    }

    return 0;
}

// 0x004FD5D0
int __stdcall IMAGE2_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinImage2Strc* pImage = (D2WinImage2Strc*)pMsg->hWnd;

    D2_ASSERT(pImage->controlHeader.eType == D2WIN_IMAGE, 0x159);

    if (!(pImage->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pImage->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const int nX = gMousePosition_6F8FE234.x - pImage->controlHeader.nImageX;
    const int nY = gMousePosition_6F8FE234.y + pImage->controlHeader.nHeight - pImage->controlHeader.nImageY;

    D2WinImageClickRectStrc* pClickRect = pImage->pClickRect;
    if (pClickRect)
    {
        for (int i = 0; pClickRect[i].pCallback; ++i)
        {
            const int nRectX = pClickRect[i].nX;
            const int nRectY = pClickRect[i].nY;
            if (nX >= nRectX && nY >= nRectY - pClickRect[i].nHeight && nX < nRectX + pClickRect[i].nWidth && nY < nRectY)
            {
                return pClickRect[i].pCallback(pMsg);
            }
        }
    }

    if (((D2WinImage2Strc*)pMsg->hWnd)->controlHeader.field_34)
    {
        return ((D2WinImage2Strc*)pMsg->hWnd)->controlHeader.field_34(pMsg);
    }

    return 0;
}

// 0x004FE710
int __stdcall EDITBOX_HandleMultiLineMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinEditBoxStrc* pEditBox = (D2WinEditBoxStrc*)pMsg->hWnd;

    D2_ASSERT(pEditBox, 0x7E5);
    D2_ASSERT(pEditBox->controlHeader.eType == D2WIN_EDITBOX, 0x7E6);

    const int nX = gMousePosition_6F8FE234.x - pEditBox->nTextInsetX - pEditBox->controlHeader.nImageX;
    const int nY = gMousePosition_6F8FE234.y + pEditBox->controlHeader.nHeight - pEditBox->nTextInsetY - pEditBox->controlHeader.nImageY;
    return EDITBOX_PlaceMultiLineCaret(pMsg, nX, nY);
}

// 0x00503FA0
void __stdcall D2COMP_AddHoverTextLine(const Unicode* wszText, D2HoverLineStrc* pLines, int* pCount, int* pMaxWidth, int* pTotalHeight)
{
    D2HoverLineStrc* pLine = &pLines[*pCount];
    D2_ASSERT(*pCount < 7, 0x738);

    sub_005267E0(pLine->wszText, wszText);
    D2Win_10131_GetTextDimensions(pLine->wszText, &pLine->nWidth, &pLine->nHeight);
    *pMaxWidth = *pMaxWidth > pLine->nWidth + 6 ? *pMaxWidth : pLine->nWidth + 6;
    *pTotalHeight += pLine->nHeight;
    ++*pCount;
}


// 0x00507A10
int __stdcall ACCOUNTLIST_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinAccountListStrc* pAccountList = (D2WinAccountListStrc*)pMsg->hWnd;

    D2_ASSERT(pAccountList->controlHeader.eType == D2WIN_ACCOUNTLIST, 0x10D);

    if (!(pAccountList->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pAccountList->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    if (!pAccountList->pDataList)
    {
        return 0;
    }

    const int nIndex = (gMousePosition_6F8FE234.x - pAccountList->controlHeader.nImageX) / 120
        + 6 * ((pAccountList->controlHeader.nHeight - pAccountList->controlHeader.nImageY + gMousePosition_6F8FE234.y + 4) / 20);
    D2WinAccountListDataStrc* pData = pAccountList->pDataList;
    for (int nCounter = 0; pData; ++nCounter)
    {
        if (nCounter == nIndex)
        {
            pAccountList->pSelectedDataEntry = pData;
            return 1;
        }
        pData = pData->pNext;
    }

    pAccountList->pSelectedDataEntry = 0;
    return 1;
}

// 0x00508030
int __fastcall SCROLLBAR_HandleMouseWheel(SMSGHANDLER_PARAMS* pMsg, D2WinScrollBarStrc* ptScrollbarData, int a3)
{
    D2_ASSERT(ptScrollbarData->controlHeader.eType == D2WIN_SCROLLBAR, 0x99);

    if (!ptScrollbarData->bIsStepIndicatorDragged)
    {
        if (a3 > 0)
        {
            --ptScrollbarData->nCurrentStep;
            ptScrollbarData->bIsUpperArrowPressed = 1;
        }
        else if (a3 < 0)
        {
            ++ptScrollbarData->nCurrentStep;
            ptScrollbarData->bIsLowerArrowPressed = 1;
        }

        if (ptScrollbarData->nCurrentStep < 0)
        {
            ptScrollbarData->nCurrentStep = 0;
        }
        else if (ptScrollbarData->nCurrentStep > ptScrollbarData->nMaxSteps)
        {
            ptScrollbarData->nCurrentStep = ptScrollbarData->nMaxSteps;
        }

        if (ptScrollbarData->pTextBox)
        {
            D2Win_10053(ptScrollbarData->pTextBox, ptScrollbarData->nCurrentStep);
        }

        if (ptScrollbarData->field_5C)
        {
            ptScrollbarData->field_5C(pMsg);
        }
    }

    return 0;
}

// 0x00508610
int __stdcall POPUP_AddLine(D2WinPopUpLineStrc* pPopUpLine)
{
    D2WinPopUpStrc* pPopUp = gpPopUp_0087E974;

    D2_ASSERT(pPopUp->controlHeader.eType == D2WIN_POPUP, 0x74);

    if (pPopUp->nLines >= 8)
    {
        return 0;
    }

    pPopUp->lines[pPopUp->nLines] = *pPopUpLine;
    sub_00502EF0(1);

    const int nTextWidth = D2Win_10121_GetTextWidth(pPopUpLine->wszText);
    pPopUp->controlHeader.nWidth = pPopUp->controlHeader.nWidth > nTextWidth ? pPopUp->controlHeader.nWidth : nTextWidth;
    ++pPopUp->nLines;
    pPopUp->controlHeader.nHeight = 20 * pPopUp->nLines;
    return 1;
}

#include "gen/data/Source/D2Win/Src/D2WinMain.inc"
