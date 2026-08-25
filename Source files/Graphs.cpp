#include "Game.h"

using namespace std;


// =====================================================
// CLEAR GRAPH
// =====================================================

void clearGraph()
{
    for (int r = 0; r < Rows; r++)
    {
        for (int c = 0; c < Columns; c++)
        {
            Node* cur =
                availableMoves[r][c];


            while (cur != nullptr)
            {
                Node* del =
                    cur;

                cur =
                    cur->next;

                delete del;
            }


            availableMoves[r][c] =
                nullptr;
        }
    }
}


// =====================================================
// BUILD GRAPH
// =====================================================

void buildGraph()
{
    clearGraph();


    int dRow[] =
    {
        -1,
        1,
        0,
        0
    };


    int dCol[] =
    {
        0,
        0,
        -1,
        1
    };


    for (
        int currentRow = 0;
        currentRow < Rows;
        currentRow++
        )
    {
        for (
            int currentCol = 0;
            currentCol < Columns;
            currentCol++
            )
        {
            // Wall
            if (
                maze[currentRow][currentCol]
                == 0
                )
            {
                continue;
            }


            for (int i = 0; i < 4; i++)
            {
                int checkRow =
                    currentRow +
                    dRow[i];

                int checkCol =
                    currentCol +
                    dCol[i];


                if (
                    checkRow >= 0 &&
                    checkRow < Rows &&
                    checkCol >= 0 &&
                    checkCol < Columns &&
                    maze[checkRow][checkCol] != 0
                    )
                {
                    Node* validMove =
                        new Node;


                    validMove->row =
                        checkRow;

                    validMove->col =
                        checkCol;


                    validMove->next =
                        availableMoves[
                            currentRow
                        ][
                            currentCol
                        ];


                    availableMoves[
                        currentRow
                    ][
                        currentCol
                    ] =
                            validMove;
                }
            }
        }
    }
}
