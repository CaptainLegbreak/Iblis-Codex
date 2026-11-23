#pragma once
// Animation data records: frame count, speed and per-frame event flags of a unit animation

#include "D2Check.h"
#include "D2Structs.h"

struct D2AnimDataRecordStrc;

struct D2AnimDataRecordStrc
{
    char szAnimDataName[8]; // 0x00
    unsigned int dwFrames; // 0x08
    unsigned int dwAnimSpeed; // 0x0C
    unsigned char pFrameFlags[144]; // 0x10
};

D2_CHECK_SIZE(D2AnimDataRecordStrc, 0xA0);

struct D2AnimSeqTxt;

struct D2AnimSeqRecordStrc
{
    D2AnimSeqTxt* pAnimSeqTxtRecord; // 0x00
    int nSeqFramesCount; // 0x04
    int nFramesCount; // 0x08
};

D2_CHECK_SIZE(D2AnimSeqRecordStrc, 0xC);
