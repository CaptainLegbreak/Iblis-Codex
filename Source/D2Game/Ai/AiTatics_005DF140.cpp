#include "D2Game.h"
struct D2GameStrc;

struct D2AiParamStrc;
struct D2MonsterDataStrc { char unknown[0x2C]; D2AiParamStrc* ai; };
struct D2StaticPathStrc { char unknown[12]; int x; int y; };
struct D2UnitStrc { int type; char unknown04[0x10]; D2MonsterDataStrc* monster; char unknown18[0x14]; union { D2PathRecordStrc* path; D2StaticPathStrc* staticPath; }; };
int __stdcall PATH_GetXPosition(D2PathRecordStrc* path); // 0x006488C0
int __stdcall PATH_GetYPosition(D2PathRecordStrc* path); // 0x00648900
void __fastcall sub_005A6260_SetAiParamFields(D2AiParamStrc* ai,int a,int velocity,unsigned char flags); // 0x005A6260
int __fastcall AITACTICS_MoveToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMode, int nX, int nY, unsigned char bStep, unsigned char nFlags); // 0x005DEB60
// build: context GetX
static inline unsigned int GetX(D2UnitStrc* unit) {
 switch(unit->type) {case 2:case 4:case 5:return unit->staticPath->x;}
 return unit->path?PATH_GetXPosition(unit->path):0;
}
// build: context GetY
static inline unsigned int GetY(D2UnitStrc* unit) {
 switch(unit->type) {case 2:case 4:case 5:return unit->staticPath->y;}
 return unit->path?PATH_GetYPosition(unit->path):0;
}
// 0x005DF140
int __fastcall sub_005DF140_Escape(D2GameStrc* game, D2UnitStrc* unit, D2UnitStrc* target, unsigned char distance, int deleteEvent)
{
    unsigned int x;
    unsigned int y;
    x = GetX(unit);
    y = GetY(unit);
    unsigned int targetX = GetX(target);
    unsigned int targetY = GetY(target);
    int dy = 0;
    int dx = 0;
    if (targetX > x)
        dx = -1;
    if (targetX < x)
        dx = 1;
    if (targetY > y)
        dy = -1;
    if (targetY < y)
        dy = 1;
    x += distance * dx;
    if (distance > 5)
    {
        y += distance * dy;
        D2AiParamStrc* ai;
        if (unit->type == 1)
        {
            if (unit->monster)
                ai = unit->monster->ai;
            else
                ai = 0;
        }
        else
            ai = 0;
        sub_005A6260_SetAiParamFields(ai, 0, 0, distance);
    }
    else
        y += distance * dy;
    int nFlags;
    if (deleteEvent)
        nFlags = 4;
    else
        nFlags = 0;
    return AITACTICS_MoveToTarget(game, unit, 0, 15, x, y, 1, nFlags);
}
