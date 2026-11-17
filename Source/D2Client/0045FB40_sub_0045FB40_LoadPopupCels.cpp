struct D2CellFileStrc;

D2CellFileStrc* __fastcall sub_004788B0(const char* szFile, int nType);                             // 0x004788B0
void __fastcall sub_004FB480_SetActA(unsigned char nAct);                                                   // 0x004FB480

extern D2CellFileStrc* gpGlobal_007A523C;                                                                   // 0x007A523C
extern D2CellFileStrc* gpGlobal_007A5240;                                                                   // 0x007A5240
extern D2CellFileStrc* gpGlobal_007A5244;                                                                   // 0x007A5244

// 0x0045FB40
void __cdecl sub_0045FB40_LoadPopupCels()
{
    gpGlobal_007A523C = sub_004788B0("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5244 = sub_004788B0("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpGlobal_007A5240 = sub_004788B0("Data\\Global\\UI\\Menu\\okcancelbtn", 0);
    sub_004FB480_SetActA(0);
}
