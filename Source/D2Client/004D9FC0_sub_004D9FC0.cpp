typedef unsigned int U32;
struct D2UnitStrc;
struct D2SkillStrc;
typedef char check_pointer_width[sizeof(void*)==4?1:-1];
typedef char check_scalar_width[sizeof(U32)==4?1:-1];
extern "C" int __stdcall SKILLS_GetUseState(D2UnitStrc* unit,D2SkillStrc* skill); // 0x00647960
extern "C" D2UnitStrc* __cdecl sub_00463DE0(); // 0x00463DE0
extern "C" U32 __cdecl sub_0044DA90(); // 0x0044DA90
extern "C" U32 __cdecl sub_0044CE50(); // 0x0044CE50

// 0x004D9FC0
extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill)
{
    int status = SKILLS_GetUseState(unit,skill);
    if (status)
        return status;
    if (unit == sub_00463DE0())
    {
        U32 first = sub_0044DA90();
        U32 second = sub_0044CE50();
        if (first < second)
            return 8;
    }
    return 0;
}
