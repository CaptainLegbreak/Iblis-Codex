struct D2ClientStrc
{
    char unk0x00[0x0A];
    unsigned short nSaveFlags;
};

// 0x00538670
int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag)
{
    return pClient->nSaveFlags & nFlag;
}
