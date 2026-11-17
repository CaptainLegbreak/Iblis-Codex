extern const char gszEmptyAssertText; // 0x006CC837

static __forceinline int sub_00505640_IsFemaleClass(int nClass)
{
    switch (nClass)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 1;
    }
    return 0;
}

// 0x00505640
const char* __stdcall D2Win_10160_GetPlayerTitle(int nClass, int nTitle, int bExpansion)
{
    if (bExpansion)
    {
        if (!sub_00505640_IsFemaleClass(nClass))
        {
            switch (nTitle)
            {
            case 1: return "Slayer ";
            case 2: return "Champion ";
            case 3: return "Patriarch ";
            case 4: return "Destroyer ";
            case 5: return "Conqueror ";
            case 6: return "Guardian ";
            }
        }
        else
        {
            switch (nTitle)
            {
            case 1: return "Slayer ";
            case 2: return "Champion ";
            case 3: return "Matriarch ";
            case 4: return "Destroyer ";
            case 5: return "Conqueror ";
            case 6: return "Guardian ";
            }
        }
    }
    else
    {
        if (!sub_00505640_IsFemaleClass(nClass))
        {
            switch (nTitle)
            {
            case 1: return "Sir ";
            case 2: return "Lord ";
            case 3: return "Baron ";
            case 4: return "Count ";
            case 5: return "Duke ";
            case 6: return "King ";
            }
        }
        else
        {
            switch (nTitle)
            {
            case 1: return "Dame ";
            case 2: return "Lady ";
            case 3: return "Baroness ";
            case 4: return "Countess ";
            case 5: return "Duchess ";
            case 6: return "Queen ";
            }
        }
    }

    return &gszEmptyAssertText;
}
