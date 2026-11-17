typedef unsigned short U16;
typedef unsigned int U32;
struct BitStreamContext;
extern "C" int gnScreenWidth; // 0x0071146C
extern "C" int gnScreenHeight; // 0x00711470
extern "C" int __cdecl sub_00468730_MouseX();
extern "C" int __cdecl sub_00468740_MouseY();
extern "C" U32 __fastcall sub_004538D0_UIState(U32 index);
extern "C" const U16* __fastcall sub_00524A30_LocalizedText(U16 index);
extern "C" void __fastcall sub_00502280_SetTooltip(const U16* text, int x, int y, int color, int mode);
extern "C" void __stdcall sub_00410EB0_WriteBits(BitStreamContext* stream, U32 value, int bitCount);

// 0x00498340
extern "C" void __cdecl sub_00498340_UpdateTooltip()
{
    const int mouseX = sub_00468730_MouseX();
    const int mouseY = sub_00468740_MouseY();
    if (mouseX >= gnScreenWidth / 2 - 8 && mouseX <= gnScreenWidth / 2 + 5
        && mouseY >= gnScreenHeight - 39 && mouseY <= gnScreenHeight - 13)
    {
        if (sub_004538D0_UIState(21))
            sub_00502280_SetTooltip(sub_00524A30_LocalizedText(4168), gnScreenWidth / 2 - 1, gnScreenHeight - 39, 0, 1);
        else
            sub_00502280_SetTooltip(sub_00524A30_LocalizedText(4167), gnScreenWidth / 2 - 1, gnScreenHeight - 39, 0, 1);
    }
}

extern "C" void __fastcall sub_0053B0E0_WriteVariableValue(BitStreamContext* stream, U32 value)
{
    if (value < 256u)
    {
        sub_00410EB0_WriteBits(stream, 0, 1);
        sub_00410EB0_WriteBits(stream, value, 8);
    }
    else
    {
        sub_00410EB0_WriteBits(stream, 1, 1);
        if (value < 65536u)
        {
            sub_00410EB0_WriteBits(stream, 0, 1);
            sub_00410EB0_WriteBits(stream, value, 16);
        }
        else
        {
            sub_00410EB0_WriteBits(stream, 1, 1);
            sub_00410EB0_WriteBits(stream, value, 32);
        }
    }
}
