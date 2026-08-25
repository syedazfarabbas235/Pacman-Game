#include "Game.h"

using namespace std;


// =====================================================
// BFS
// =====================================================

Coordinate bfs(
    int startRow,
    int startCol,
    int targetRow,
    int targetCol
)
{
    clearQueue();


    bool visited[Rows][Columns] =
    {
        false
    };


    int parentRow[Rows][Columns];
    int parentCol[Rows][Columns];


    for (int r = 0; r < Rows; r++)
    {
        for (int c = 0; c < Columns; c++)
        {
            parentRow[r][c] = -1;
            parentCol[r][c] = -1;
        }
    }


    enqueue(
        startRow,
        startCol
    );


    visited[startRow][startCol] =
        true;


    bool found = false;


    while (front != nullptr)
    {
        QueueNode* current =
            dequeue();


        if (!current)
            break;


        int r =
            current->row;

        int c =
            current->col;


        delete current;


        if (
            r == targetRow &&
            c == targetCol
            )
        {
            found = true;
            break;
        }


        Node* neighbor =
            availableMoves[r][c];


        while (neighbor != nullptr)
        {
            int nr =
                neighbor->row;

            int nc =
                neighbor->col;


            if (
                !visited[nr][nc]
                )
            {
                visited[nr][nc] =
                    true;


                parentRow[nr][nc] =
                    r;

                parentCol[nr][nc] =
                    c;


                enqueue(
                    nr,
                    nc
                );
            }


            neighbor =
                neighbor->next;
        }
    }


    Coordinate nextStep =
    {
        startRow,
        startCol
    };


    const int MAX_PATH =
        Rows * Columns;


    if (found)
    {
        int pathRow[MAX_PATH];
        int pathCol[MAX_PATH];

        int pathLength = 0;


        int stepRow =
            targetRow;

        int stepCol =
            targetCol;


        while (
            stepRow != -1 &&
            stepCol != -1 &&
            pathLength < MAX_PATH
            )
        {
            pathRow[pathLength] =
                stepRow;

            pathCol[pathLength] =
                stepCol;


            pathLength++;


            int nextRow =
                parentRow[
                    stepRow
                ][
                    stepCol
                ];


            int nextCol =
                parentCol[
                    stepRow
                ][
                    stepCol
                ];


            stepRow =
                nextRow;

            stepCol =
                nextCol;
        }


        if (pathLength >= 2)
        {
            nextStep.row =
                pathRow[
                    pathLength - 2
                ];

            nextStep.col =
                pathCol[
                    pathLength - 2
                ];
        }
    }


    clearQueue();


    return nextStep;
}


// =====================================================
// DFS STATE
// =====================================================

bool dfsVisited[Rows][Columns] =
{
    false
};

bool dfsPathOnStack[Rows][Columns] =
{
    false
};

bool dfsReachedPacman =
false;


// =====================================================
// START DFS
// =====================================================

void startDFS(
    int startRow,
    int startCol
)
{
    clearStack();


    for (int r = 0; r < Rows; r++)
    {
        for (int c = 0; c < Columns; c++)
        {
            dfsVisited[r][c] =
                false;

            dfsPathOnStack[r][c] =
                false;
        }
    }


    dfsReachedPacman =
        false;


    push(
        startRow,
        startCol
    );


    dfsVisited[
        startRow
    ][
        startCol
    ] =
            true;


        dfsPathOnStack[
            startRow
        ][
            startCol
        ] =
                true;
}


// =====================================================
// MOVE DFS
// =====================================================

Coordinate moveDFS(
    int ghostR,
    int ghostC
)
{
    if (top == nullptr)
    {
        startDFS(
            ghostR,
            ghostC
        );
    }


    StackNode* current =
        top;


    int r =
        current->row;

    int c =
        current->col;


    if (
        r == pacmanRow &&
        c == pacmanCol
        )
    {
        dfsReachedPacman =
            true;


        return {
            r,
            c
        };
    }


    Node* neighbor =
        availableMoves[r][c];


    bool movedForward =
        false;


    while (neighbor != nullptr)
    {
        int nr =
            neighbor->row;

        int nc =
            neighbor->col;


        if (!dfsVisited[nr][nc])
        {
            dfsVisited[nr][nc] =
                true;


            push(
                nr,
                nc
            );


            movedForward =
                true;


            break;
        }


        neighbor =
            neighbor->next;
    }


    if (!movedForward)
    {
        StackNode* removed =
            pop();

        delete removed;


        if (top == nullptr)
        {
            startDFS(
                ghostR,
                ghostC
            );


            return {
                ghostR,
                ghostC
            };
        }
    }


    return {
        top->row,
        top->col
    };
}
