struct S { int pad; int type; };

// 0x004DF770
__declspec(noinline) static bool __fastcall sub_004DF770(S* p, char unused, int x) { return p->type == x; }
// build: context sub_004DF770_Shim

// calling-convention shim (not game code)
void sub_004DF770_Shim(S* p, int x) { (void)sub_004DF770(p, 0, x); }
