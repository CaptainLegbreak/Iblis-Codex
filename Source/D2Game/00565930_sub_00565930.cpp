struct Seed { unsigned low,high; };
struct Game { char pad0[0x78]; unsigned short format; char pad7A[0x56]; Seed seed; };
struct Item { char pad0[0xF6]; unsigned short format; char padF8[5]; unsigned char level; char padFE[0x35]; unsigned char spawnable; char pad134[0x74]; };
struct ItemRecordTable { int count; Item* records; };
ItemRecordTable* __stdcall sub_00633590();  // 0x00633590
unsigned __fastcall sub_0045C3E0(Seed*,int);  // 0x0045C3E0
int __stdcall sub_00629A90(int,int);  // 0x00629A90
extern "C" const char emptyAssert;  // 0x006CC837
extern "C" const char* __cdecl sub_00408090();  // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int);  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl sub_00681E09(int);  // 0x00681E09
enum { EXPANSION_FORMAT = 100 };
// 0x00565930
short __fastcall sub_00565930(Game* game,int level,int type)
{
    short choices[256];
    ItemRecordTable* table=sub_00633590();
    int count=0;
    if(!table) { sub_00408A60(&emptyAssert,sub_00408090(),0x384); sub_00681E09(-1); }
    int start=sub_0045C3E0(&game->seed,table->count);
    int stop=start-1;
    if(stop<0) stop=table->count-1;
    int index=start;
    while(index!=stop) {
        if(count>=256) break;
        if(sub_00629A90(index,type)) {
            Item* record=&table->records[index];
            if(record->spawnable && (record->format<EXPANSION_FORMAT || game->format>=EXPANSION_FORMAT) && record->level<=level) {
                choices[count++]=(short)index;
            }
        }
        ++index;
        if(index>=table->count) index=0;
    }
    if(!count) return 0;
    return choices[sub_0045C3E0(&game->seed,count)];
}
