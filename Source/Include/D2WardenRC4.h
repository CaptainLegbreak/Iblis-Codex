#pragma once
// RC4 state: the Warden client and its module loader encrypt and decrypt their payloads with it.

struct D2RC4Strc
{
    unsigned char S[0x100];
    unsigned char i;
    unsigned char j;

    void sub_004E09B0_Init(const unsigned char* pKey, unsigned int nKeySize); // 0x004E09B0
    void ApplyKeystream(unsigned char* pData, unsigned int nSize);       // 0x0047F8C0
};
