typedef unsigned short U16;
typedef unsigned int U32;
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
typedef char check_pointer_width[sizeof(void*)==4?1:-1];
typedef char check_word_width[sizeof(U16)==2?1:-1];
struct PathPrecisionView
{
    U32 precisionX;
};
typedef char check_precision_x[OFFSET(PathPrecisionView,precisionX)==0?1:-1];

// 0x006489A0
extern "C" void __stdcall PATH_SetPrecisionX(PathPrecisionView* path,U32 precisionX)
{
    path->precisionX = precisionX;
}

struct PathPreviousView
{
    char retainedPrefix[0x14];
    U16 previousTargetX;
    U16 previousTargetY;
};
typedef char check_previous_x[OFFSET(PathPreviousView,previousTargetX)==0x14?1:-1];
typedef char check_previous_y[OFFSET(PathPreviousView,previousTargetY)==0x16?1:-1];

// 0x00649050
extern "C" void __stdcall sub_00649050(PathPreviousView* path)
{
    path->previousTargetX = 0;
    path->previousTargetY = 0;
}
