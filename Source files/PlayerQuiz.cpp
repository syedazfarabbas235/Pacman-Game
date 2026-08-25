#include "Game.h"

using namespace std;


// =====================================================
// PACMAN DIRECTION
// =====================================================

int dirRow = 0;
int dirCol = 0;

int nextDirRow = 0;
int nextDirCol = 0;


// =====================================================
// PACMAN MOVEMENT
// =====================================================

void movePacman()
{
    if (
        pacmanClock
        .getElapsedTime()
        .asMilliseconds() < 170
        )
    {
        return;
    }


    // Apply new direction if possible.
    if (
        maze[
            pacmanRow + nextDirRow
        ][
            pacmanCol + nextDirCol
        ] != 0
                )
    {
        dirRow =
            nextDirRow;

        dirCol =
            nextDirCol;
    }


    int newR =
        pacmanRow + dirRow;

    int newC =
        pacmanCol + dirCol;


    if (
        maze[newR][newC] != 0
        )
    {
        pacmanRow =
            newR;

        pacmanCol =
            newC;


        // Eat normal dot.
        if (
            maze[pacmanRow][pacmanCol]
            == 1
            )
        {
            score++;

            maze[
                pacmanRow
            ][
                pacmanCol
            ] = 2;


            dotSound->play();
        }


        // Power pellet.
        if (
            maze[pacmanRow][pacmanCol]
            == 3
            )
        {
            maze[
                pacmanRow
            ][
                pacmanCol
            ] = 2;


            powerMode =
                true;


            quizActive =
                true;


            powerSound->play();
        }
    }


    pacmanClock.restart();
}


// =====================================================
// PACMAN ANIMATION
// =====================================================

void updatePacmanAnimation()
{
    float targetX =
        pacmanCol * CellSize;

    float targetY =
        pacmanRow * CellSize;


    float speed =
        6.0f;


    pacmanX +=
        (targetX - pacmanX) /
        speed;


    pacmanY +=
        (targetY - pacmanY) /
        speed;
}


// =====================================================
// VALID CELL
// =====================================================

bool isValidCell(
    int r,
    int c
)
{
    return (
        r >= 0 &&
        r < Rows &&
        c >= 0 &&
        c < Columns &&
        maze[r][c] != 0
        );
}


// =====================================================
// FLEE MOVE
// =====================================================

Coordinate fleeMove(
    int gRow,
    int gCol
)
{
    int bestRow =
        gRow;

    int bestCol =
        gCol;


    int maxDist =
        -1;


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


    for (int i = 0; i < 4; i++)
    {
        int newR =
            gRow + dRow[i];

        int newC =
            gCol + dCol[i];


        if (
            isValidCell(
                newR,
                newC
            )
            )
        {
            int dist =
                abs(
                    newR - pacmanRow
                )
                +
                abs(
                    newC - pacmanCol
                );


            if (
                dist > maxDist
                )
            {
                maxDist =
                    dist;

                bestRow =
                    newR;

                bestCol =
                    newC;
            }
        }
    }


    return {
        bestRow,
        bestCol
    };
}


// =====================================================
// HANDLE ANSWER
// =====================================================

void handleAnswer(
    char ans,
    int index
)
{
    Question& qn =
        q[index];


    showFeedback =
        true;


    feedbackClock.restart();


    if (
        ans == qn.bestAnswer
        )
    {
        score += 20;


        answerFeedbackText->
            setString(
                "BEST ANSWER! +20"
            );


        ghost1Returning =
            true;

        ghost2Returning =
            true;

        ghost3Returning =
            true;
    }


    else if (
        ans == qn.avgAnswer
        )
    {
        score += 10;


        answerFeedbackText->
            setString(
                "AVERAGE ANSWER! +10"
            );


        Coordinate g1 =
            fleeMove(
                ghostRow,
                ghostCol
            );


        ghostRow =
            g1.row;

        ghostCol =
            g1.col;


        Coordinate g2 =
            fleeMove(
                ghost2Row,
                ghost2Col
            );


        ghost2Row =
            g2.row;

        ghost2Col =
            g2.col;


        Coordinate g3 =
            fleeMove(
                ghost3Row,
                ghost3Col
            );


        ghost3Row =
            g3.row;

        ghost3Col =
            g3.col;
    }


    else if (
        ans == qn.worstAnswer
        )
    {
        score += 5;


        answerFeedbackText->
            setString(
                "WORST ANSWER! +5"
            );
    }


    quizActive =
        false;
}


// =====================================================
// UPDATE QUIZ TEXT
// =====================================================

void updateQuizText()
{
    Question& qn =
        q[currentQuestion];


    string lines[] =
    {
        qn.story,
        "",
        qn.question,
        "",
        qn.optionA,
        qn.optionB,
        qn.optionC
    };


    string finalText =
        "";


    int maxChars =
        45;


    for (int i = 0; i < 7; i++)
    {
        string line =
            lines[i];


        while (
            line.length() >
            maxChars
            )
        {
            finalText +=
                line.substr(
                    0,
                    maxChars
                )
                +
                "\n";


            line =
                line.substr(
                    maxChars
                );
        }


        finalText +=
            line +
            "\n";
    }


    quizText->
        setString(
            finalText
        );
}


// =====================================================
// HANDLE QUIZ INPUT
// =====================================================

void handleQuizInput(
    sf::Keyboard::Key key
)
{
    char ans = 0;


    if (
        key ==
        sf::Keyboard::Key::A
        )
    {
        ans = 'A';
    }
    else if (
        key ==
        sf::Keyboard::Key::B
        )
    {
        ans = 'B';
    }
    else if (
        key ==
        sf::Keyboard::Key::C
        )
    {
        ans = 'C';
    }
    else
    {
        return;
    }


    handleAnswer(
        ans,
        currentQuestion
    );


    // Stay inside this level's 4 questions.
    int levelStart =
        (currentLevel - 1) * 4;


    currentQuestion =
        levelStart
        +
        (
            (
                currentQuestion -
                levelStart +
                1
                )
            % 4
            );


    quizActive =
        false;
}


// =====================================================
// DRAW QUIZ
// =====================================================

void drawQuiz(
    sf::RenderWindow& window
)
{
    if (!quizActive)
        return;


    updateQuizText();


    window.draw(
        quizPanel
    );


    window.draw(
        *quizText
    );
}
