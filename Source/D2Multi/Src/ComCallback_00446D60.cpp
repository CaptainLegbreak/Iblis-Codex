#ifdef MOVED_TEST
#define CASE_SHIFT 2
#else
#define CASE_SHIFT 0
#endif
// 0x00446D60
static __declspec(noinline) int sub_00446D60_Classify(int code) {
 switch(code) {
 case 0+CASE_SHIFT:
 case 1+CASE_SHIFT:
 case 6+CASE_SHIFT:
 case 9+CASE_SHIFT:
  return 0;
 default:
  return 1;
 }
}

int __fastcall EmitClassify(int code) { return sub_00446D60_Classify(code); }
