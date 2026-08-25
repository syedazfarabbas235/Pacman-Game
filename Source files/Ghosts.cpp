#include "Game.h"

using namespace std;


// =====================================================
// GHOST 1 - BFS
// =====================================================

void moveGhost()
{
    if (
        ghostClock
        .getElapsedTime()
        .asMilliseconds() < 250
        )
    {
        return;
    }


    if (ghost1Returning)
    {
        Coordinate next =
            bfs(
                ghostRow,
                ghostCol,
                GHOST_START_ROW,
                GHOST_START_COL
            );


        ghostRow =
            next.row;

        ghostCol =
            next.col;


        if (
            ghostRow ==
            GHOST_START_ROW &&
            ghostCol ==
            GHOST_START_COL
            )
        {
            ghost1Returning =
                false;
        }
    }
    else
    {
        Coordinate next =
            bfs(
                ghostRow,
                ghostCol,
                pacmanRow,
                pacmanCol
            );


        ghostRow =
            next.row;

        ghostCol =
            next.col;
    }


    ghostClock.restart();
}


// =====================================================
// GHOST 3 - RANDOM
// =====================================================

void moveGhostRandom()
{
    if (
        ghost3Clock
        .getElapsedTime()
        .asMilliseconds() < 250
        )
    {
        return;
    }


    if (ghost3Returning)
    {
        Coordinate next =
            bfs(
                ghost3Row,
                ghost3Col,
                GHOST3_START_ROW,
                GHOST3_START_COL
            );


        ghost3Row =
            next.row;

        ghost3Col =
            next.col;


        if (
            ghost3Row ==
            GHOST3_START_ROW &&
            ghost3Col ==
            GHOST3_START_COL
            )
        {
            ghost3Returning =
                false;
        }
    }
    else
    {
        Node* safeMove =
            availableMoves[
                ghost3Row
            ][
                ghost3Col
            ];


        int validRows[4];
        int validCols[4];

        int validCount = 0;


        int backRow = -1;
        int backCol = -1;


        bool onlyBackwardsAvailable =
            true;


        while (safeMove != nullptr)
        {
            if (
                safeMove->row ==
                prevGhost3Row &&
                safeMove->col ==
                prevGhost3Col
                )
            {
                backRow =
                    safeMove->row;

                backCol =
                    safeMove->col;
            }
            else
            {
                validRows[validCount] =
                    safeMove->row;

                validCols[validCount] =
                    safeMove->col;

                validCount++;


                onlyBackwardsAvailable =
                    false;
            }


            safeMove =
                safeMove->next;
        }


        if (
            onlyBackwardsAvailable &&
            backRow != -1
            )
        {
            validRows[0] =
                backRow;

            validCols[0] =
                backCol;

            validCount = 1;
        }


        if (validCount > 0)
        {
            int pick =
                rand() % validCount;


            prevGhost3Row =
                ghost3Row;

            prevGhost3Col =
                ghost3Col;


            ghost3Row =
                validRows[pick];

            ghost3Col =
                validCols[pick];
        }
    }


    ghost3Clock.restart();
}


// =====================================================
// GHOST 2 - DFS
// =====================================================

void moveGhostDFS()
{
    if (
        ghost2Clock
        .getElapsedTime()
        .asMilliseconds() < 170
        )
    {
        return;
    }


    if (ghost2Returning)
    {
        Coordinate next =
            bfs(
                ghost2Row,
                ghost2Col,
                GHOST2_START_ROW,
                GHOST2_START_COL
            );


        ghost2Row =
            next.row;

        ghost2Col =
            next.col;


        if (
            ghost2Row ==
            GHOST2_START_ROW &&
            ghost2Col ==
            GHOST2_START_COL
            )
        {
            ghost2Returning =
                false;


            startDFS(
                ghost2Row,
                ghost2Col
            );
        }
    }
    else
    {
        Coordinate next =
            moveDFS(
                ghost2Row,
                ghost2Col
            );


        ghost2Row =
            next.row;

        ghost2Col =
            next.col;
    }


    ghost2Clock.restart();
}


// =====================================================
// GHOST ANIMATION
// =====================================================

void updateGhostAnimations()
{
    float speed = 6.0f;


    float target1X =
        ghostCol * CellSize;

    float target1Y =
        ghostRow * CellSize;


    ghostX +=
        (target1X - ghostX) /
        speed;

    ghostY +=
        (target1Y - ghostY) /
        speed;


    float target2X =
        ghost2Col * CellSize;

    float target2Y =
        ghost2Row * CellSize;


    ghost2X +=
        (target2X - ghost2X) /
        speed;

    ghost2Y +=
        (target2Y - ghost2Y) /
        speed;


    float target3X =
        ghost3Col * CellSize;

    float target3Y =
        ghost3Row * CellSize;


    ghost3X +=
        (target3X - ghost3X) /
        speed;

    ghost3Y +=
        (target3Y - ghost3Y) /
        speed;
}
