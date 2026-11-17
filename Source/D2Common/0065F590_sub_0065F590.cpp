struct Unit { int type; };
struct Property { int id; int layer; int minimum; int maximum; };
void __stdcall sub_006286C0(Unit*,unsigned char*,unsigned char*,const char*,int);  // 0x006286C0
unsigned char __stdcall sub_0062BC20(Unit*);  // 0x0062BC20
int __fastcall sub_0065E9E0(Unit*,int,int);  // 0x0065E9E0
void __stdcall sub_006280D0(Unit*,unsigned,int);  // 0x006280D0
void __stdcall sub_00627260(Unit*,int,int,unsigned short);  // 0x00627260
enum { SOCKET_FLAG = 0x800 };
#define MAXIMUM(a,b) (((a)>(b))?(a):(b))
#define MINIMUM(a,b) (((a)<(b))?(a):(b))
// 0x0065F590
int __fastcall sub_0065F590(int type,Unit* unit,Unit* item,const Property* property,int set,short stat,int layer,int value,int state,int statList,Unit* other)
{
    if(!property) return 0;
    if(!item || item->type!=4) return 0;
    int limit=6;
    unsigned char width=0,height=0;
    sub_006286C0(item,&width,&height,"d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h",0x6DC);
    int area=width*height;
    limit=MINIMUM(limit,area);
    if(limit<=0) return 0;
    limit=MINIMUM(limit,sub_0062BC20(item));
    int count=value;
    if(count<=0) {
        count=sub_0065E9E0(item,property->minimum,property->maximum);
        if(count<=0) count=property->layer;
    }
    count=MINIMUM(MAXIMUM(count,1),limit);
    if(count<=0) return 0;
    sub_006280D0(item,SOCKET_FLAG,1);
    sub_00627260(item,194,count,0);
    return count;
}
