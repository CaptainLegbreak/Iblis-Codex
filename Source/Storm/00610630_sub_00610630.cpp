inline void* __cdecl operator new(unsigned int size,void* where) throw() { return where; }
void* __stdcall sub_00413020(unsigned,const char*,int,unsigned);  // 0x00413020
extern "C" const char mappingName[];  // 0x0074362C
struct Link { Link* previous; char* next; Link() { previous=0; next=0; } };
struct Key { char* text; Key() { text=0; } };
struct Node { unsigned hash; Link slot,full; Key key; void* mapped; Node() { mapped=0; } };
struct List {
    void sub_0060E890(char*,int,char*);
    Node* sub_00610630(int,unsigned,unsigned);
};
enum { ALLOC_FLAG = 8 };
// build: symbol ?sub_0060E890@List@@QAEXPADH0@Z 0x0060E890
// 0x00610630
Node* List::sub_00610630(int linkType,unsigned extra,unsigned flags)
{
    void* memory=sub_00413020(sizeof(Node)+extra,mappingName,-2,flags|ALLOC_FLAG);
    Node* node=new(memory) Node;
    if(linkType) sub_0060E890((char*)node,linkType,0);
    return node;
}
