#pragma once
// Battle.net client: the message bodies the client reads from the Battle.net server (client id, versioning,
// logon info and ad checks).

#include "D2Check.h"
#include "D2Win32Base.h"

struct D2BnClientIdReplyStrc
{
    unsigned int dwRegistrationVersion; // 0x00
    unsigned int dwRegistrationAuthority; // 0x04
    unsigned int dwClientId; // 0x08
    unsigned int f_C; // 0x0C
};

struct D2BnStartVersioningStrc
{
    D2FileTimeStrc tFileTime; // 0x00
    char szFileName[4]; // 0x08
};

struct D2BnAuthInfoStrc
{
    unsigned int dwLogonType; // 0x00
    unsigned int f_4; // 0x04
    unsigned int f_8; // 0x08
    D2FileTimeStrc tFileTime; // 0x0C
    char szFileName[4]; // 0x14
};

struct D2BnCheckAdReplyStrc
{
    unsigned int nAdId; // 0x00
    unsigned int nExtension; // 0x04
    unsigned char pData[1]; // 0x08
};
