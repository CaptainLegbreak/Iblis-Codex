struct D2HackEntryStrc
{
    unsigned int unk_00;
    unsigned int retentionSeconds;
    unsigned int activeSeconds;
    D2HackEntryStrc* next;
};

struct D2CriticalSectionStrc
{
    void* debugInfo;
    long lockCount;
    long recursionCount;
    void* owningThread;
    void* lockSemaphore;
    unsigned long spinCount;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* section);
unsigned int gnLastHackListLog_00989C34;        // 0x00989C34
extern const char gszHackCategory_006FC4A8[]; // 0x006FC4A8
extern const char gszHackListSize_006FC4B0[]; // 0x006FC4B0
void __cdecl sub_00410660_Log(const char* category, const char* format, ...); // 0x00410660

struct D2HackListStrc
{
    unsigned char unk_000[0x888];
    unsigned int lastTick;
    D2HackEntryStrc* freeEntries;
    unsigned int entryCount;
    D2CriticalSectionStrc section;
    D2HackEntryStrc** buckets;
    unsigned int bucketCount;

    void __thiscall sub_006BE700_ExpireEntries(); // 0x006BE700
};

// 0x006BE700
void __thiscall D2HackListStrc::sub_006BE700_ExpireEntries()
{
    if (lastTick == ~0u)
        lastTick = GetTickCount();

    unsigned int now = GetTickCount();
    unsigned int elapsed = now - lastTick;
    if (elapsed >= 1000)
    {
        unsigned int seconds = elapsed / 1000;
        int changed = 0;
        EnterCriticalSection(&section);
        lastTick = now;
        for (unsigned int i = 0; i < bucketCount; ++i)
        {
            D2HackEntryStrc* current = buckets[i];
            D2HackEntryStrc* previous = 0;
            while (current)
            {
                D2HackEntryStrc* next = current->next;
                if (current->activeSeconds)
                {
                    if (current->activeSeconds > seconds)
                        current->activeSeconds -= seconds;
                    else
                    {
                        current->activeSeconds = 0;
                        if (seconds < 120)
                            current->retentionSeconds = 120 - seconds;
                        else
                            current->retentionSeconds = 0;
                        current->retentionSeconds += seconds;
                    }
                }
                if (current->retentionSeconds)
                {
                    if (current->retentionSeconds > seconds)
                        current->retentionSeconds -= seconds;
                    else
                    {
                        if (previous)
                        {
                            previous->next = next;
                            current->next = freeEntries;
                            freeEntries = current;
                            current = previous;
                        }
                        else
                        {
                            buckets[i] = buckets[i]->next;
                            current->next = freeEntries;
                            freeEntries = current;
                            current = 0;
                        }
                        --entryCount;
                        changed = 1;
                    }
                }
                previous = current;
                current = next;
            }
        }
        LeaveCriticalSection(&section);
        if (changed)
        {
            unsigned int count = entryCount;
            unsigned int logTick = GetTickCount();
            if (logTick - gnLastHackListLog_00989C34 > 2000)
            {
                sub_00410660_Log(gszHackCategory_006FC4A8, gszHackListSize_006FC4B0, count);
                gnLastHackListLog_00989C34 = logTick;
            }
        }
    }
}
