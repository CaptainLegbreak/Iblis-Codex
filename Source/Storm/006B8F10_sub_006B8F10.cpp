struct Vertex { float x,y,z,rhw; unsigned int diffuse,specular; float u,v; };
struct BufferDescription { unsigned int size,caps,format,count; };
struct VertexBuffer {
 virtual long __stdcall QueryInterface(const void*,void**) = 0;
 virtual unsigned long __stdcall AddRef() = 0;
 virtual unsigned long __stdcall Release() = 0;
 virtual long __stdcall Lock(unsigned int,Vertex**,unsigned int*) = 0;
 virtual long __stdcall Unlock() = 0;
};
struct GraphicsInterface {
 virtual long __stdcall QueryInterface(const void*,void**) = 0;
 virtual unsigned long __stdcall AddRef() = 0;
 virtual unsigned long __stdcall Release() = 0;
 virtual void __stdcall Unused0C() = 0;
 virtual void __stdcall Unused10() = 0;
 virtual void __stdcall Unused14() = 0;
 virtual void __stdcall Unused18() = 0;
 virtual void __stdcall Unused1C() = 0;
 virtual void __stdcall Unused20() = 0;
 virtual long __stdcall CreateVertexBuffer(BufferDescription*,VertexBuffer**,unsigned int,void*) = 0;
};
struct IndexStrip { unsigned short indices[12];unsigned short last; };
extern int gTileWidth; // 0x0096F4DC
extern int gTileHeight; // 0x009702B8
extern GraphicsInterface* gGraphics; // 0x00970E64
extern VertexBuffer* gGridBuffer; // 0x00971734
extern IndexStrip gIndexStrips[5]; // 0x009716B0
extern const char gCreateFailure[]; // 0x006FC2C4
extern const char gLockFailure[]; // 0x006FC330
extern const char gUnlockFailure[]; // 0x006FC310
void __fastcall sub_006B39B0(const char*,long); // 0x006B39B0
void __fastcall sub_006B20E0(const char*,long); // 0x006B20E0
// 0x006B8F10
void __cdecl sub_006B8F10()
{
    float xStep = (float)(160.0 / gTileWidth);
    xStep = (float)(xStep / 10.0);
    float yStep = (float)(80.0 / gTileHeight);
    yStep = (float)(yStep / 10.0);

    BufferDescription description = { sizeof(BufferDescription) };
    description.caps = 0x10800;
    description.format = 0x1C4;
    description.count = 36;
    long result = gGraphics->CreateVertexBuffer(&description, &gGridBuffer, 4, 0);
    if (result)
    {
        sub_006B39B0(gCreateFailure, result);
        return;
    }

    Vertex* data;
    result = gGridBuffer->Lock(0x21, &data, 0);
    if (result)
    {
        sub_006B20E0(gLockFailure, result);
        return;
    }

    for (int row = 0; row < 6; ++row)
    {
        for (int column = 0; column < 6; ++column)
        {
            int xBorder = 0;
            int yBorder = 0;
            if (column == 0)
            {
                xBorder = 1;
                yBorder = 1;
            }
            else if (column == 5)
            {
                xBorder = -1;
                yBorder = -1;
            }

            if (row == 0)
            {
                --xBorder;
                ++yBorder;
            }
            else if (row == 5)
            {
                ++xBorder;
                --yBorder;
            }

            float u = (float)(xBorder + 80) / gTileWidth;
            u += (column - row) * xStep;
            float v = (float)yBorder / gTileHeight;
            v += (column + row) * yStep;
            data->z = 0.5f;
            data->rhw = 1.0f;
            data->u = u;
            data->v = v;
            ++data;
        }
    }

    result = gGridBuffer->Unlock();
    if (result)
    {
        sub_006B20E0(gUnlockFailure, result);
        return;
    }

    unsigned short indices[5][12];
    for (int row = 0; row < 5; ++row)
    {
        for (int column = 0; column < 6; ++column)
        {
            unsigned short* pTop = &indices[row][column * 2];
            unsigned short* pBottom = &indices[row][column * 2 + 1];
            *pTop = row * 6 + (unsigned short)column;
            *pBottom = row * 6 + (unsigned short)column + 6;
        }
    }

    IndexStrip* pStrip = gIndexStrips;
    for (int row = 0; row < 5; ++row)
    {
        const unsigned short* pSource = indices[row];
        for (int i = 0; i < 6; ++i)
        {
            ((int*)pStrip->indices)[i] = ((int*)pSource)[i];
        }
        pStrip->last = pStrip->indices[11];
        ++pStrip;
    }
}

#include "gen/data/Source/Storm/006B8F10_sub_006B8F10.inc"
