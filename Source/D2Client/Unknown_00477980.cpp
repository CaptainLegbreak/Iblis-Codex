struct D2MemoryStatusStrc
{
    unsigned long dwLength;
    unsigned long dwMemoryLoad;
    unsigned long dwTotalPhys;
    unsigned long dwAvailPhys;
    unsigned long dwTotalPageFile;
    unsigned long dwAvailPageFile;
    unsigned long dwTotalVirtual;
    unsigned long dwAvailVirtual;
};

extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pStatus);            // 0x006CC1F4
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
void __cdecl D2GFX_OutputString(int nXPos, int nYPos, const char* szFormat, ...);                           // 0x004F6890
void __cdecl sub_00477760_DrawCacheStats(); // 0x00477760
int __stdcall sub_0044CE60(); // 0x0044CE60
int __cdecl sub_0044DAF0(); // 0x0044DAF0
int __cdecl UI_GetGfxMemory(); // 0x0046F980
int __cdecl UI_GetCofMemoryUsed(); // 0x0046F990
int __cdecl UI_GetCofMemoryLimit(); // 0x0046F9A0
int __cdecl D2CMPSpriteCacheGetMaxMemory(); // 0x005FEE40
int __cdecl D2CMPCelDataCacheGetUsedMemory(); // 0x005FEE60
int __cdecl D2CMPCelDataCacheGetMaxMemory(); // 0x005FEE70
int __stdcall sub_0040ABE0(); // 0x0040ABE0
void __cdecl sub_00481850(); // 0x00481850
unsigned int __cdecl D2CMPSpriteCacheGetUsedMemory(); // 0x005FEE10
int __cdecl sub_004F5140(); // 0x004F5140
extern "C" const char text_006CC780[]; // 0x006CC780
unsigned int g_007BB390;        // 0x007BB390
unsigned int g_007BB394;        // 0x007BB394
unsigned int g_007BB398;        // 0x007BB398
unsigned int g_007BB39C;        // 0x007BB39C
unsigned int g_007BB3A0;        // 0x007BB3A0
extern int g_007BB3A4; // 0x007BB3A4
extern int g_007BB3AC; // 0x007BB3AC

#define FRAME_INTERVAL 1000
#define SCREEN_X 10
#define SCREEN_RIGHT 160
#define MEMORY_SHIFT 20

// 0x00477980
void __fastcall sub_00477980()
{
    unsigned int nNow=GetTickCount();
    unsigned int nElapsed=nNow-g_007BB394;
    if(g_007BB3A4 && !g_007BB3A0){g_007BB3A0=nNow;g_007BB39C=0;}
    if(nElapsed<=FRAME_INTERVAL){++g_007BB398;++g_007BB39C;}
    else {g_007BB394=nNow;g_007BB390=g_007BB398;g_007BB398=0;}
    if(!g_007BB3A4){g_007BB3A0=0;return;}
    D2GFX_OutputString(SCREEN_X,2,"%d FPS  %d Skip",g_007BB390,sub_0044DAF0());
    D2GFX_OutputString(SCREEN_RIGHT,2,"Ping: %d",sub_0044CE60());
    D2MemoryStatusStrc memory;
    memory.dwLength=sizeof(memory);
    GlobalMemoryStatus(&memory);
    D2GFX_OutputString(SCREEN_X,16,"Phys:%d/%dm",((memory.dwTotalPhys-memory.dwAvailPhys)>>MEMORY_SHIFT)+1,(memory.dwTotalPhys>>MEMORY_SHIFT)+1);
    D2GFX_OutputString(SCREEN_RIGHT,16,"Page:%d/%dm",((memory.dwTotalPageFile-memory.dwAvailPageFile)>>MEMORY_SHIFT)+1,(memory.dwTotalPageFile>>MEMORY_SHIFT)+1);
    char text[32];
    switch(sub_004F5140()){
    case 1:sprintf(text,"Software");break;
    case 3:sprintf(text,"DirectDraw");break;
    case 4:sprintf(text,"Glide");break;
    case 5:sprintf(text,"OpenGL");break;
    case 6:sprintf(text,"Direct3D");break;
    case 2:sprintf(text,"Software");break;
    case 7:sprintf(text,"RAVE");break;
    default:sprintf(text,text_006CC780);break;
    }
    D2GFX_OutputString(500,2,"Video: %s",text);
    if(!g_007BB3AC){
        D2GFX_OutputString(SCREEN_X,120,"GFX Memory->%i",UI_GetGfxMemory());
        D2GFX_OutputString(SCREEN_X,132,"COF Memory->%i of %i",UI_GetCofMemoryUsed(),UI_GetCofMemoryLimit());
        D2GFX_OutputString(SCREEN_X,144,"Sprite Cache Memory->%i of %i",D2CMPSpriteCacheGetUsedMemory(),D2CMPSpriteCacheGetMaxMemory());
        D2GFX_OutputString(SCREEN_X,156,"Async Files->%i",sub_0040ABE0());
        D2GFX_OutputString(SCREEN_X,168,"CelData Cache Memory->%i of %i",D2CMPCelDataCacheGetUsedMemory(),D2CMPCelDataCacheGetMaxMemory());
        sub_00481850();
        sub_00477760_DrawCacheStats();
    }
}
