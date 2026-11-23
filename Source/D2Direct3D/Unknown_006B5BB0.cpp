struct D2ResourceEntryStrc { int value0; int value4; int rest[6]; };
struct D2ResourceGroupStrc { D2ResourceEntryStrc* entries; int rest[6]; };
struct D2ResourcePairStrc { int group; int entry; };
struct D2ResourceSetStrc { D2ResourcePairStrc pairs[5]; };
extern D2ResourceGroupStrc gaResourceGroups[]; // 0x00970EE0
// 0x006B5BB0
void __fastcall sub_006B5BB0_ClearResourceEntries(D2ResourceSetStrc* set)
{
    for (int i = 0; i < 5; ++i)
    {
        int group = set->pairs[i].group - 1;
        if (group >= 0)
        {
            int entry = set->pairs[i].entry - 1;
            if (entry >= 0)
                gaResourceGroups[group].entries[entry].value4 = 0;
        }
    }
}
