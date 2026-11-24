#pragma once
// Client: small UI records several units share (the UI-variable close-kind table and a UI cel file with
// its path).

#include "D2Check.h"

struct D2UIVarRecordStrc
{
    int anCloseKind[0x26]; // 0x00
};

#pragma pack(push, 2)
struct D2UiCelFileStrc
{
    void* pCelFile; // 0x00
    char szPath[0x1E]; // 0x04
};
#pragma pack(pop)
