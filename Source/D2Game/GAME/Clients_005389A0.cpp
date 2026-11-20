#include "D2GameStrc.h"
struct Lock { int values[6]; };
struct D2ClientStrc {
 int nClientId; char pad4[0x3d8-4]; unsigned dwLastPacketTick; char pad3dc[0x4a8-0x3dc];
 D2ClientStrc* pNext; D2ClientStrc* pHashNext; int pad4b0;
 unsigned pings[16]; int pad4f4; __int64 average; unsigned count;
};
extern D2ClientStrc* gpClients_008842A8[256]; // 0x008842A8
extern Lock gLock_008846A8; // 0x008846A8
extern int gnReady_008846D8; // 0x008846D8
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(Lock*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(Lock*);
extern "C" __declspec(dllimport) unsigned __stdcall GetTickCount();
D2GameStrc* __fastcall GAME_GetGameByClientId(int nId); // 0x0052FEE0
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame); // 0x0052DA90
void __fastcall D2GAME_PACKETS_SendPacket0x8F_6FC3FA90(D2ClientStrc* pClient,int tick); // 0x0053E020
// 0x005389A0
void __fastcall CLIENTS_UpdatePing(int nClientId,int tick,int delay,int unused)
{
 D2GameStrc* pGame=GAME_GetGameByClientId(nClientId);
 if(pGame) {
  D2ClientStrc* pClient=pGame->pClientList;
  for(;pClient;pClient=pClient->pNext) {
   if(pClient->nClientId==nClientId) {
    unsigned now=GetTickCount();
    pClient->pings[pClient->count&15]=now-tick-delay;
    ++pClient->count;
    unsigned __int64 sum=0;
    int count=pClient->count>16?16:pClient->count;
    for(int i=0;i<count;++i)sum+=pClient->pings[i];
    pClient->average=sum/count;
    D2GAME_PACKETS_SendPacket0x8F_6FC3FA90(pClient,tick);
    pClient->dwLastPacketTick=now;
    break;
   }
  }
  GAME_LeaveGamesCriticalSection(pGame);
 } else if(gnReady_008846D8) {
  EnterCriticalSection(&gLock_008846A8);
  D2ClientStrc* pClient=gpClients_008842A8[nClientId&255];
  for(;pClient;pClient=pClient->pHashNext) {
   if(pClient->nClientId==nClientId) {
    unsigned now=GetTickCount();
    if(pClient->count<10) {
     __int64 weighted=pClient->count*pClient->average;
     int delta=now-tick-delay;
     ++pClient->count;
     pClient->average=(weighted+delta)/pClient->count;
    }
    D2GAME_PACKETS_SendPacket0x8F_6FC3FA90(pClient,tick);
    ++pClient->count;
    pClient->dwLastPacketTick=now;
    break;
   }
  }
  LeaveCriticalSection(&gLock_008846A8);
 }
}
