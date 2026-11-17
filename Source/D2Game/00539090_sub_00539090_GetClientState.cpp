struct D2ClientStrc
{
    unsigned int dwClientId;
    int dwClientState;
};

// 0x00539090
int __fastcall sub_00539090_GetClientState(D2ClientStrc* pClient)
{
    return pClient->dwClientState;
}
