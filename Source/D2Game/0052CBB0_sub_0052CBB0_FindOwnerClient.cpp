struct D2ClientStrc;

unsigned int __fastcall CLIENT_IsGameOwner(D2ClientStrc* pClient);                                          // 0x00539030

// 0x0052CBB0
void __fastcall sub_0052CBB0_FindOwnerClient(D2ClientStrc* pClient, void* pContext)
{
    D2ClientStrc** ppClient = (D2ClientStrc**)pContext;
    if (CLIENT_IsGameOwner(pClient))
    {
        *ppClient = pClient;
    }
}

// 0x0052CBD0
void __fastcall sub_0052CBD0_FindFirstClient(D2ClientStrc* pClient, void* pContext)
{
    D2ClientStrc** ppClient = (D2ClientStrc**)pContext;
    if (!*ppClient)
    {
        *ppClient = pClient;
    }
}
