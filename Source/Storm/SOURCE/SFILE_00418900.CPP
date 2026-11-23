#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2StormLink.h"

// 0x00418900
void D2StormList00708354Strc::sub_00418900_UnlinkAll()
{
    while (char* pNode = m_terminator.Next())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

// 0x00418940
void D2StormList00708360Strc::sub_00418940_UnlinkAll()
{
    while (char* pNode = m_terminator.Next())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

// 0x00418980
void D2StormList0070836CStrc::sub_00418980_UnlinkAll()
{
    while (char* pNode = m_terminator.Next())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

// 0x004189C0
void D2StormList00708378Strc::sub_004189C0_UnlinkAll()
{
    while (char* pNode = m_terminator.Next())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

// 0x00418A00
void D2StormList00708384Strc::sub_00418A00_UnlinkAll()
{
    while (char* pNode = m_terminator.Next())
        ((D2StormLinkStrc*)pNode)->Unlink();
}
