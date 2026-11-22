inline void* operator new(unsigned int, void* p) throw() { return p; }
void* __stdcall SMemAlloc(unsigned int, const char*, int, unsigned int); // 0x00413020
int __stdcall SMemFree(void*, const char*, int, unsigned int); // 0x00412650
#include "D2SysTypes.h"
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern D2CriticalSectionStrc gLock_00779068; // 0x00779068
extern const char gszEventType_007083D8[]; // 0x007083D8
extern const char gszRequestType_007083F0[]; // 0x007083F0
struct D2StormLinkStrc {
    D2StormLinkStrc* m_prevlink;
    char* m_next;
    D2StormLinkStrc* NextLink(int offset) {
        if ((int)m_next < 0) return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (offset < 0) offset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + offset);
    }
    char* Next() { return (char*)((((int)m_next <= 0) - 1) & (int)m_next); }
    void Unlink() {
        if (m_prevlink) {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};
struct EVENTREC {
    D2StormLinkStrc f_0;
    void* user;
    EVENTREC() { f_0.m_prevlink = 0; f_0.m_next = 0; }
};
struct REQUEST {
    D2StormLinkStrc f_0;
    void* user;
    int unk0C[6];
    void* buffer;
    void* other;
    int unk2C[6];
    ~REQUEST(); // 0x0041A020
};
struct D2StormEventListStrc {
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    D2StormLinkStrc* Link(char* p) { return p ? (D2StormLinkStrc*)p : &m_terminator; }
    void LinkNode(char* p, unsigned int type, char* existing) {
        D2StormLinkStrc* link = Link(p);
        link->Unlink();
        D2StormLinkStrc* e = Link(existing);
        switch (type) {
        case 1:
            link->m_prevlink = e;
            link->m_next = e->m_next;
            e->NextLink(m_linkoffset)->m_prevlink = link;
            e->m_next = p;
            break;
        default:
            D2StormLinkStrc* prev = e->m_prevlink;
            link->m_prevlink = prev;
            link->m_next = prev->m_next;
            prev->m_next = p;
            e->m_prevlink = link;
            break;
        }
    }
    EVENTREC* NewNode(unsigned int type, unsigned int extra, unsigned int flags) {
        void* memory = SMemAlloc(sizeof(EVENTREC) + extra, gszEventType_007083D8, -2, flags | 8);
        EVENTREC* record = memory ? new(memory) EVENTREC : 0;
        if (type) LinkNode((char*)record, type, 0);
        return record;
    }
};
struct D2StormRequestListStrc {
    int offset;
    D2StormLinkStrc m_terminator;
    D2StormLinkStrc* Link(REQUEST* p) { return p ? &p->f_0 : &m_terminator; }
};
extern D2StormRequestListStrc gRequests_00708360; // 0x00708360
extern D2StormEventListStrc gEvents_00708378; // 0x00708378
// 0x0041A300
int __stdcall sub_0041A300_CancelRequests(void* buffer, void* other) {
    if (!buffer && !other) return 0;
    EnterCriticalSection(&gLock_00779068);
    int result = 0;
    REQUEST* request = (REQUEST*)gRequests_00708360.m_terminator.Next();
    while ((int)request > 0) {
        if ((buffer && request->buffer == buffer) || (other && request->other == other)) {
            result = 1;
            if (request->user) {
                EVENTREC* event = gEvents_00708378.NewNode(2, 0, 0);
                event->user = request->user;
            }
            REQUEST* next = (REQUEST*)request->f_0.Next();
            request->~REQUEST();
            SMemFree(request, gszRequestType_007083F0, -2, 0);
            request = next;
        } else {
            request = (REQUEST*)gRequests_00708360.Link(request)->m_next;
        }
    }
    LeaveCriticalSection(&gLock_00779068);
    return result;
}
