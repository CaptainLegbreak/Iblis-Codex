#include "D2Gdi.h"

struct D2SmackRecordStrc
{
    void* f_0;
    unsigned char nType;
};

extern "C" __declspec(dllimport) void __stdcall SmackClose(void* hSmack);                                   // 0x006CC608

void* gpGdiSmackBuffer_0098A278;                                                                            // 0x0098A278

// 0x006C9640
void __fastcall sub_006C9640_GdiCloseSmacker(D2SmackRecordStrc* pRecord)
{
    if (gpGdiSmackBuffer_0098A278)
    {
        FOG_Free(gpGdiSmackBuffer_0098A278, ".\\Src\\gdiSmack.cpp", 0xF0, 0);
        gpGdiSmackBuffer_0098A278 = 0;
    }
    if (pRecord->nType == 's' && pRecord->f_0)
    {
        SmackClose(pRecord->f_0);
        pRecord->f_0 = 0;
    }
    pRecord->nType = 0;
}
