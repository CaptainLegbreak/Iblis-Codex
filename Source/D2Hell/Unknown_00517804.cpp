#include "D2Hell.h"

#include "D2SysTypes.h"
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

struct D2MessageNode;
struct D2MessageLink {
 D2MessageLink* m_prevlink; D2MessageNode* m_next;
 D2MessageNode* Next() {return (int)m_next>0?m_next:0;}
};
struct D2MessageNode {
 D2MessageLink link;
 int (__stdcall* callback)(unsigned int,char*,unsigned int);
};
struct D2MessageList {
 int m_linkoffset;
 D2MessageLink m_terminator;
 D2MessageLink* Link(char* node) {return node?(D2MessageLink*)(node+m_linkoffset):&m_terminator;}
 D2MessageNode* Head(){return m_terminator.Next();}
};
struct D2MessageLock {D2CriticalSectionStrc lock;int enabled;};
extern D2MessageList gtMessages;  // 0x0072FA14
extern D2MessageLock gMessageLock_00881818;  // 0x00881818
extern "C" const char gszFaultError[];  // 0x006DEBCC
unsigned int __stdcall SStrCopy(char*,const char*,unsigned int);  // 0x004135D0
// 0x00517804
void __fastcall sub_00517804_GetMessage(unsigned int id,char* dest,unsigned int size) {
 if(gMessageLock_00881818.enabled) {
  EnterCriticalSection(&gMessageLock_00881818.lock);
  D2MessageNode* p=gtMessages.Head();
  for(; (int)p>0; p=gtMessages.Link((char*)p)->m_next) {
   if(p->callback(id,dest,size)) {
    LeaveCriticalSection(&gMessageLock_00881818.lock);
    return;
   }
  }
  LeaveCriticalSection(&gMessageLock_00881818.lock);
 }
 SStrCopy(dest,gszFaultError,size);
}

#include "gen/data/Source/D2Hell/Unknown_00517804.inc"
