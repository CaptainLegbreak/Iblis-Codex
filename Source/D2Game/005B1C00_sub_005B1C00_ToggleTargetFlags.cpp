struct D2UnitStrc { int dwUnitType; char pad[0xCC]; int dwNodeIndex; };
struct D2TargetNodeStrc { D2UnitStrc* pUnit; int nNodeData; D2TargetNodeStrc* pNext; D2TargetNodeStrc* pPrevious; };
struct D2GameStrc { char pad[0x10F8]; D2TargetNodeStrc* pTargetNodes[10]; };

D2TargetNodeStrc* __fastcall sub_005B1BC0_FindTargetNode(D2UnitStrc* pUnit, D2GameStrc* pGame); // 0x005B1BC0

// 0x005B1C00
void __fastcall sub_005B1C00_ToggleTargetFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFlags, int bSet)
{
    if (!pGame || !pUnit)
    {
        return;
    }

    D2TargetNodeStrc* pTargetNode;
    if (pUnit->dwUnitType == 0)
    {
        pTargetNode = sub_005B1BC0_FindTargetNode(pUnit, pGame);
    }
    else if (pUnit->dwUnitType == 1)
    {
        pTargetNode = sub_005B1BC0_FindTargetNode(pUnit, pGame);
    }
    else
    {
        return;
    }

    if (!pTargetNode)
    {
        return;
    }

    if (bSet)
    {
        pTargetNode->nNodeData |= nFlags;
    }
    else
    {
        pTargetNode->nNodeData &= ~nFlags;
    }
}
