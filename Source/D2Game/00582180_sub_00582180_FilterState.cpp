struct D2ContextDataStrc { unsigned char padding[16]; unsigned int state; };
struct D2ContextStrc { int unknown; D2ContextDataStrc* data; };
int __fastcall sub_00581F60_HandleState(D2ContextStrc* context, void* argument); // 0x00581F60

// 0x00582180
int __fastcall sub_00582180_FilterState(D2ContextStrc* context, void* argument)
{
    if (context->data)
    {
        unsigned int state = context->data->state;
        if ((short)state && (short)state == 2)
            return sub_00581F60_HandleState(context, argument);
    }
    return 0;
}
