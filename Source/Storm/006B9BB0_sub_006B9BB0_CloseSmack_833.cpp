#define D2_IMPORT __declspec(dllimport)
extern "C" D2_IMPORT void __stdcall SmackClose(void* handle);
struct D2VideoHandleStrc { void* handle; char type; };
// 0x006B9BB0
void __fastcall sub_006B9BB0_CloseSmack(D2VideoHandleStrc* video)
{
    if (video->type == 's' && video->handle) {
        SmackClose(video->handle);
        video->handle = 0;
    }
}
