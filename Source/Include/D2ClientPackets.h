#pragma once
// Client: the fixed-size packet shapes the client sends to the game server.

#pragma pack(push, 1)
struct D2PacketSize1Strc
{
    unsigned char nHeader;
};

struct D2PacketSize3Strc
{
    unsigned char nHeader;
    unsigned short w1;
};

struct D2PacketShorts5Strc
{
    unsigned char nHeader;
    unsigned short w1;
    unsigned short w3;
};

struct D2PacketShorts7Strc
{
    unsigned char nHeader;
    unsigned short w1;
    unsigned short w3;
    unsigned short w5;
};

struct D2PacketShorts9Strc
{
    unsigned char nHeader;
    unsigned short w1;
    unsigned short w3;
    unsigned short w5;
    unsigned short w7;
};

struct D2PacketDword5Strc
{
    unsigned char nHeader;
    unsigned int d1;
};

struct D2PacketDwords13Strc
{
    unsigned char nHeader;
    unsigned int d1;
    unsigned int d5;
    unsigned int d9;
};

struct D2PacketDwords17Strc
{
    unsigned char nHeader;
    unsigned int d1;
    unsigned int d5;
    unsigned int d9;
    unsigned int d13;
};

struct D2PacketPvp7Strc
{
    unsigned char nHeader;
    unsigned char b1;
    unsigned char bFlag;
    unsigned int d3;
};

struct D2PacketParty6Strc
{
    unsigned char nHeader;
    unsigned char b1;
    unsigned int d2;
};
#pragma pack(pop)
