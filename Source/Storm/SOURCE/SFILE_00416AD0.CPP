#include "Storm.h"

struct D2StormBlockStrc { unsigned int offset, packedSize, fileSize, flags; };
struct D2StormArchiveStrc {
    char unknown00[8]; char name[0x104]; void* handle;
    char unknown110[0x14]; unsigned int blockSize;
    char unknown128[0x1C]; unsigned int filePos;
};
struct D2StormFileStrc {
    char unknown00[0x114]; D2StormArchiveStrc* archive;
    D2StormBlockStrc* block; unsigned int key;
    char unknown120[8]; unsigned int blockCount;
    unsigned int* offsets; int offsetsLoaded;
    char unknown134[0x18]; int crcEnabled, crcState;
};
extern const char gszSFileCpp_006CF084[]; // 0x006CF084
extern unsigned int* gpCryptTable_00779048; // 0x00779048
typedef int (__stdcall* ReadErrorCallback)(const char*, unsigned long, int);
extern ReadErrorCallback gpfnReadErrorCallback_00779030; // 0x00779030
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void*, long, long*, unsigned long); // 0x006CC1AC
extern "C" __declspec(dllimport) int __stdcall ReadFile(void*, void*, unsigned long, unsigned long*, void*); // 0x006CC1A4
void __stdcall sub_0041C340_SetLastError(unsigned long); // 0x0041C340
int __stdcall SErrDisplayError(unsigned int, const char*, int, const char*, int, unsigned int); // 0x0041CAF0
void* __stdcall SMemAlloc(unsigned int, const char*, int, unsigned int); // 0x00413020
int __stdcall SMemFree(void*, const char*, int, unsigned int); // 0x00412650
void __stdcall SMemCopy(void*, const void*, unsigned int); // 0x0041D2A0
int __stdcall sub_00415240_Explode(void*, const void*, unsigned int); // 0x00415240
int __stdcall sub_0041E720_Decompress(void*, unsigned int*, const void*, unsigned int, const char*); // 0x0041E720
static void sub_004152D0_DecryptBlock(unsigned int*, unsigned int, unsigned int);
// 0x004152D0
static void sub_004152D0_DecryptBlock(unsigned int* data, unsigned int bytes, unsigned int key)
{
    unsigned int seed = 0xEEEEEEEE;
    unsigned int count = bytes >> 2;
    while (count--) {
        seed += gpCryptTable_00779048[0x400 + (key & 0xFF)];
        *data ^= key + seed;
        seed = *data + seed + (seed << 5) + 3;
        ++data;
        key = ((~key << 21) + 0x11111111) | (key >> 11);
    }
}
static int __stdcall sub_004154B0_ReadAt(unsigned int, unsigned int*, void*, unsigned int, const char*, unsigned long*, void*);
// 0x004154B0
static int __stdcall sub_004154B0_ReadAt(unsigned int offset, unsigned int* filePos, void* buffer, unsigned int size, const char* name, unsigned long* read, void* handle)
{
    int retry = 0;
    for (;;) {
        if (offset != -1) SetFilePointer(handle, offset, 0, 0);
        const int ok = ReadFile(handle, buffer, size, read, 0);
        *filePos = *read + offset;
        if (ok) {
            if (*read == size) return 1;
            sub_0041C340_SetLastError(0x26);
            return 0;
        }
        const unsigned long error = GetLastError();
        switch (gnValueA_0070834C) {
        case 0: return 0;
        case 1:
            if (!gpfnReadErrorCallback_00779030) return 0;
            if (!gpfnReadErrorCallback_00779030(name, error, retry++)) return 0;
            break;
        case 2: SErrDisplayError(error, name, -4, 0, 0, 1); break;
        }
    }
}
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x00416AD0
unsigned int __stdcall sub_00416AD0_ReadBlocks(D2StormFileStrc* file, unsigned int offset, unsigned char* buffer, unsigned int size)
{
    VALIDATEBEGIN;
    VALIDATE(!((file->archive->blockSize - 1) & offset));
    VALIDATEEND;
    if (!size) return 0;
    if ((file->block->flags & 0xFF00) && !file->offsetsLoaded) {
        unsigned long tableRead = 0;
        if (!sub_004154B0_ReadAt(file->block->offset, &file->archive->filePos, file->offsets, 4 * file->blockCount + 4, file->archive->name, &tableRead, file->archive->handle)) return 0;
        if (file->block->flags & 0x10000)
            sub_004152D0_DecryptBlock(file->offsets, tableRead, file->key - 1);
        for (unsigned int i = 0; i < file->blockCount; ++i) {
            if (file->offsets[i] > file->offsets[i + 1]) return 0;
        }
        file->offsetsLoaded = 1;
    }
    unsigned int packedOffset = offset;
    unsigned int packedSize = size;
    if (file->block->flags & 0xFF00) {
        packedOffset = file->offsets[offset / file->archive->blockSize];
        packedSize = file->offsets[(offset + size) / file->archive->blockSize] - packedOffset;
    }
    unsigned char* packed = buffer;
    if (file->block->flags & 0xFF00)
        packed = (unsigned char*)SMemAlloc(packedSize + 4, gszSFileCpp_006CF084, 0x382, 0);
    unsigned long bytesRead = 0;
    sub_004154B0_ReadAt(file->block->offset + packedOffset, &file->archive->filePos, packed, packedSize, file->archive->name, &bytesRead, file->archive->handle);
    unsigned int result = size;
    if (bytesRead < packedSize) {
        if (file->block->flags & 0xFF00) {
            unsigned int blockSize = file->archive->blockSize;
            result = 0;
            for (unsigned int i = offset / blockSize + 1; i <= file->blockCount; ++i) {
                if (bytesRead < file->offsets[i] - packedOffset) break;
                result += blockSize;
            }
        } else result = bytesRead;
    }
    if (file->block->flags & 0x10000) {
        unsigned int blockSize = file->archive->blockSize;
        unsigned int i = offset / blockSize;
        unsigned int count = (blockSize + result - 1) / blockSize;
        unsigned int position = 0;
        while (i < file->blockCount && count--) {
            unsigned int bytes;
            if (file->block->flags & 0xFF00) {
                bytes = file->offsets[i + 1] - file->offsets[i];
            } else {
                bytes = (file->archive->blockSize < result - position) ? file->archive->blockSize : result - position;
                if (i == file->blockCount - 1 && (file->block->fileSize & (file->archive->blockSize - 1)))
                    bytes = (bytes < (file->block->fileSize & (file->archive->blockSize - 1))) ? bytes : (file->block->fileSize & (file->archive->blockSize - 1));
            }
            sub_004152D0_DecryptBlock((unsigned int*)(packed + position), bytes & ~3u, file->key + i);
            ++i;
            position += bytes;
        }
    }
    if (file->block->flags & 0xFF00) {
        unsigned int blockSize = file->archive->blockSize;
        unsigned int destOffset = 0;
        unsigned int sourceOffset = 0;
        unsigned int i = offset / blockSize;
        unsigned int count = (blockSize + result - 1) / blockSize;
        for (; i < file->blockCount && count--; ++i) {
            unsigned int sourceSize = file->offsets[i + 1] - file->offsets[i];
            unsigned int destSize;
            if (i == file->blockCount - 1) {
                if (!file->block->fileSize || (file->block->fileSize & (file->archive->blockSize - 1)))
                    destSize = file->block->fileSize & (file->archive->blockSize - 1);
                else destSize = file->archive->blockSize;
            } else destSize = file->archive->blockSize;
            if (destSize > sourceSize) {
                switch (file->block->flags & 0xFF00) {
                case 0x100:
                    sub_00415240_Explode(buffer + destOffset, packed + sourceOffset, sourceSize);
                    break;
                case 0x200:
                    {
                        unsigned int outputSize = destSize;
                        if (file->crcEnabled && file->crcState != 1 && (packed[sourceOffset] & 0xC0)) file->crcState = 1;
                        if (!sub_0041E720_Decompress(buffer + destOffset, &outputSize, packed + sourceOffset, sourceSize, file->archive->name))
                            SErrDisplayError(0x85100083, file->archive->name, -4, 0, 0, 1);
                    }
                    break;
                }
            } else if (packed != buffer) {
                SMemCopy(buffer + destOffset, packed + sourceOffset, destSize);
            }
            destOffset += destSize;
            sourceOffset += sourceSize;
        }
    }
    if (packed != buffer) SMemFree(packed, gszSFileCpp_006CF084, 0x3EF, 0);
    return nValid ? result : 0;
}
