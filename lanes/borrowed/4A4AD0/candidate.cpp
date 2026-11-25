// 0x004A4AD0
void __stdcall sub_004A4AD0_Press(int nX, int nY)
{
    gnKeyConfigPressedButton = 3;
    if (gbKeyConfigPressRepeat)
        return;

    const int bInList = TEXT_IsInKeyConfigList(nX, nY);
    const int bUp = TEXT_IsOnUpArrow(nX, nY);
    const int bDown = TEXT_IsOnDownArrow(nX, nY);
    const int bPageUp = TEXT_IsAboveThumb(nX, nY);
    const int bThumb = TEXT_IsOnThumb(nX, nY);
    int bPageDown = 0;
    if (TEXT_IsBelowThumb(nX, nY)) bPageDown = 1;
    const int bButton = TEXT_GetKeyConfigButtonAt(nX, nY) != 3;

    if (sub_F08_NoOtherPressed(7) && !bPageDown && !bButton && !bThumb && !bPageUp && !bDown && !bUp && !bInList)
    {
        gbKeyConfigPressRepeat = gbRedraw;
        return;
    }

    if (sub_F08_NoOtherPressed(0) && (gaPressed[0] || bInList))
    {
        gaPressed[0] = gbRedraw;
        if (gbRedraw)
        {
            const int nTop = sub_F08_ListTop();
            if (nY < nTop + 0x28)
                TEXT_MoveKeyConfigSelection(-1);
            if (nY > nTop + 0x136)
                TEXT_MoveKeyConfigSelection(1);

            const int nOldD4 = gnKeyConfigColumn;
            const int nOldSelected = gnKeyConfigSelected;
            const int nLine = TEXT_GetKeyConfigLineAt(nY);
            gnKeyConfigSelected = nLine;
            gnKeyConfigColumn = TEXT_IsAbovePanelLine(nX);
            if (gpListEntries[nLine].nId == 0x39)
            {
                gnKeyConfigColumn = nOldD4;
                gnKeyConfigSelected = nOldSelected;
            }
        }
    }

    if (sub_F08_NoOtherPressed(1) && bUp)
    {
        gaPressed[1] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(-1);
        }
    }

    if (sub_F08_NoOtherPressed(2) && bDown)
    {
        gaPressed[2] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(1);
        }
    }

    if (sub_F08_NoOtherPressed(3) && bPageUp)
    {
        gaPressed[3] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(1 - sub_F08_VisibleLines());
        }
    }

    if (sub_F08_NoOtherPressed(4) && (bThumb || gaPressed[4]))
    {
        if (bThumb && !gaPressed[4] && gbRedraw)
        {
            gnDragThumbY = gnKeyConfigThumbY;
            gnDragMouseY = nY;
        }
        gaPressed[4] = gbRedraw;
        if (gbRedraw)
        {
            const int nTop = sub_F08_ListTop();
            TEXT_ScrollKeyConfigList((gnDragThumbY - nTop - gnDragMouseY + nY - 0x2F)
                * (gnThumbRange + 1) / sub_F08_TrackSpan() - gnKeyConfigFirstVisible);
        }
    }

    if (sub_F08_NoOtherPressed(5) && (bPageDown || gaPressed[5]))
    {
        gaPressed[5] = bPageDown ? gbRedraw : 0;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(sub_F08_VisibleLines() - 1);
        }
    }

    if (sub_F08_NoOtherPressed(6) && bButton)
    {
        gaPressed[6] = gbRedraw;
        gnKeyConfigPressedButton = TEXT_GetKeyConfigButtonAt(nX, nY);
    }
}
