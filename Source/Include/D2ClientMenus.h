#pragma once
// Client: NPC menu entries and hotkey bindings, both 2-byte packed records.

#include "D2Check.h"
#include "D2Structs.h"

struct D2NpcEntryStrc;
struct D2HotkeyStrc;

#pragma pack(push, 2)
struct D2NpcEntryStrc
{
    int nId; // 0x00
    short unk0x04; // 0x04
    short unk0x06; // 0x06
    short unk0x08; // 0x08
    short unk0x0A; // 0x0A
    short unk0x0C; // 0x0C
    short unk0x0E; // 0x0E
    char unk0x10; // 0x10
    char bSelected; // 0x11
    char bFlag; // 0x12
    char unk0x13; // 0x13
    char bFlag14; // 0x14
    char bRefreshed; // 0x15
};

struct D2HotkeyStrc
{
    int nCommand; // 0x00
    unsigned short nKey; // 0x04
    int nMode; // 0x06
};
#pragma pack(pop)

D2_CHECK_SIZE(D2NpcEntryStrc, 0x16);
D2_CHECK_SIZE(D2HotkeyStrc, 0xA);
