#include "D2Game.h"

typedef bool (__fastcall *Sequence)(Quest*);
typedef int (__stdcall *CodePointer)();
struct Quest { int number; Game* game; unsigned char act,notIntro,active,lastState,state; char padD[3]; int sequenceId; char pad14[0xDC]; Sequence sequence; };
Quest* __fastcall sub_00543640(Game*,int);  // 0x00543640
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(CodePointer);  // 0x006CC34C
extern "C" const char* __cdecl sub_00408090();  // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int);  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int);
enum { FINAL_STATE = 5 };
// 0x005B7CD0
bool __fastcall sub_005B7CD0(Quest* quest)
{
    if (quest->state != FINAL_STATE && quest->notIntro) return true;
    Quest* next = sub_00543640(quest->game,quest->sequenceId);
    if (next) {
        if (IsBadCodePtr((CodePointer)quest->sequence)) {
            sub_00408A60(&empty_assert,sub_00408090(),808);
            exit(-1);
        }
        return next->sequence(next);
    }
    return false;
}
