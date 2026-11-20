#pragma once
// Win32: the point and rectangle records the game modules declare for themselves.

struct tagPOINT
{
    long x; // 0x00
    long y; // 0x04
};

struct tagRECT
{
    long left; // 0x00
    long top; // 0x04
    long right; // 0x08
    long bottom; // 0x0C
};
