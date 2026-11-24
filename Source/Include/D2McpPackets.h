#pragma once
// MCP client: the realm (MCP) protocol packets the client builds and parses.

#include "D2Check.h"

#pragma pack(push, 1)
struct D2McpPacket02Strc
{
    unsigned char f_0;
    int nValue;
    unsigned short wValue;
    char szText[0x400];
};

struct D2McpPacket07Strc
{
    unsigned char f_0;
    char szText[0x400];
};

struct D2McpPacket04Strc
{
    unsigned char f_0;
    unsigned short f_1;
    char szText[0x400];
};

struct D2McpPacket08Strc
{
    unsigned char f_0;
    unsigned short f_1;
    char szText[0x400];
};

struct D2McpPacket09Strc
{
    unsigned char f_0;
    unsigned short f_1;
    char szText[0x400];
};

struct D2McpPacket0BStrc
{
    unsigned char f_0;
    char szText[0x400];
};

struct D2McpPacket0CStrc
{
    unsigned char f_0;
    char szText[0x400];
};

struct D2McpPacket16Strc
{
    unsigned char f_0;
    int nValue01;
    int nValue05;
    char szText[0x400];
};

struct D2McpPacket05Strc
{
    unsigned char f_0;
    unsigned short f_1;
    union
    {
        unsigned int dwFlags;
        int nValue;
    };
    union
    {
        struct
        {
            char szText[0x400];
        };
        struct
        {
            unsigned char nCount;
            int nToken;
            char szData[1];
        };
    };
};

struct D2McpPacket06Strc
{
    unsigned char f_0;
    unsigned short f_1;
    char szText[0x400];
};

struct D2McpPacket0AStrc
{
    unsigned char f_0;
    unsigned short f_1;
    char szText[0x400];
};

struct D2McpPacket18Strc
{
    unsigned char f_0;
    char szText[0x400];
};

struct D2McpPacket10Strc
{
    unsigned char f_0;
    int nValueB0;
    int nValue88;
    int f_9;
    int nCode;
};

struct D2McpPacket01Strc
{
    unsigned char f_0;
    int nValue01;
    int nValue05;
    int nValue09;
    int nValue0D;
    int nValue11;
    int nValue15;
    int nValue19;
    int nValue1D;
    int nValue21;
    int nValue25;
    int nValue29;
    int nValue2D;
    int nValue31;
    int nValue35;
    int nValue39;
    int nValue3D;
    char szText[0x400];
};

struct D2McpPacket03Strc
{
    unsigned char f_0;
    unsigned short wRequestId;
    int nValue;
    unsigned char nByte07;
    unsigned char nByte08;
    unsigned char nByte09;
    char szText[0x400];
};
#pragma pack(pop)
