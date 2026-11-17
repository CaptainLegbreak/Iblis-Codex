inline void* __cdecl operator new(unsigned int size,void* where) throw() { return where; }
void* __stdcall sub_00413020(unsigned,const char*,int,unsigned);  // 0x00413020
extern "C" const char eventName[];  // 0x007083D8
struct Node { Node* previous; char* next; int payload; Node() { previous=0; next=0; } };
struct List {
    void sub_00417C70(char*,unsigned,char*);
    Node* sub_00418F90(unsigned,unsigned,unsigned);
};
enum { ALLOC_FLAG = 8 };
// build: symbol ?sub_00417C70@List@@QAEXPADI0@Z 0x00417C70
// 0x00418F90
Node* List::sub_00418F90(unsigned linkType,unsigned extra,unsigned flags)
{
    void* memory=sub_00413020(sizeof(Node)+extra,eventName,-2,flags|ALLOC_FLAG);
    Node* node=new(memory) Node;
    if(linkType) sub_00417C70((char*)node,linkType,0);
    return node;
}

#include "gen/data/Source/Storm/00418F90_sub_00418F90.inc"
