struct D2CelFileStrc;

void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
extern D2CelFileStrc* gpAutomapCels_007A5168[4];                                                            // 0x007A5168
extern int gdwGlobal_00711428;                                                                              // 0x00711428
extern int gdwGlobal_0071142C;                                                                              // 0x0071142C
extern int gdwGlobal_007A520C;                                                                              // 0x007A520C
extern int gdwGlobal_007A5208;                                                                              // 0x007A5208

// 0x0045A280
void __cdecl sub_0045A280_FreeAutomapCels()
{
    for (int i = 0; i < 4; ++i)
    {
        if (gpAutomapCels_007A5168[i])
        {
            sub_00478A00(gpAutomapCels_007A5168[i]);
        }
        gpAutomapCels_007A5168[i] = 0;
    }
}

// 0x0045AE50
void __fastcall sub_0045AE50_SetGlobal00711428(int nValue)
{
    gdwGlobal_00711428 = nValue;
}

// 0x0045AE70
void __fastcall sub_0045AE70_SetGlobal0071142C(int nValue)
{
    gdwGlobal_0071142C = nValue;
}

// 0x0045AFE0
void __fastcall sub_0045AFE0_SetMouseOffsets(int nX, int nY)
{
    gdwGlobal_007A520C = nX;
    gdwGlobal_007A5208 = nY;
}

#include "gen/data/Source/D2Client/0045A280_sub_0045A280_FreeAutomapCels.inc"
