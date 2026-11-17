struct Unicode { unsigned short wChar; };
struct D2WinControlStrc;
const Unicode* __fastcall D2Win_10077_EDITBOX_GetText(D2WinControlStrc*); // 0x004FDD90
int __fastcall sub_00526800(const Unicode*); // 0x00526800
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc*,int); // 0x004F96F0
extern D2WinControlStrc* gpEdit_007799CC; // 0x007799CC
extern D2WinControlStrc* gpEdit_007799D0; // 0x007799D0
extern D2WinControlStrc* gpControl_007799D4; // 0x007799D4
// 0x00436CF0
void __cdecl sub_00436CF0()
{
 const Unicode* pText1=D2Win_10077_EDITBOX_GetText(gpEdit_007799CC);
 const Unicode* pText2=D2Win_10077_EDITBOX_GetText(gpEdit_007799D0);
 int bOk=sub_00526800(pText1)>0;
 bOk|=sub_00526800(pText2)>0;
 sub_004F96F0_ControlClearState(gpControl_007799D4,bOk);
}
