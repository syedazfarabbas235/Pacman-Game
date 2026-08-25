#include "Game.h"

#include <iostream>

using namespace std;


// =====================================================
// LOAD ASSETS
// =====================================================

void loadAssets()
{
    // =================================================
    // GHOST 1
    // =================================================

    bool ghostSuccess =
        ghostTexture.loadFromFile(
            "ghost.png"
        );


    if (!ghostSuccess)
    {
        cout << "Error loading ghost.png"
            << endl;
    }


    ghostSprite =
        new sf::Sprite(
            ghostTexture
        );


    ghostSprite->setScale(
        {
            (float)CellSize /
            ghostTexture.getSize().x,

            (float)CellSize /
            ghostTexture.getSize().y
        }
    );


    // =================================================
    // GHOST 2
    // =================================================

    bool g2Success =
        ghost2Texture.loadFromFile(
            "ghost2.png"
        );


    if (!g2Success)
    {
        cout << "Error loading ghost2.png"
            << endl;
    }


    ghost2Sprite =
        new sf::Sprite(
            ghost2Texture
        );


    ghost2Sprite->setScale(
        {
            (float)CellSize /
            ghost2Texture.getSize().x,

            (float)CellSize /
            ghost2Texture.getSize().y
        }
    );


    // =================================================
    // GHOST 3
    // =================================================

    bool g3Success =
        ghost3Texture.loadFromFile(
            "ghost3.png"
        );


    if (!g3Success)
    {
        cout << "Error loading ghost3.png"
            << endl;
    }


    ghost3Sprite =
        new sf::Sprite(
            ghost3Texture
        );


    ghost3Sprite->setScale(
        {
            (float)CellSize /
            ghost3Texture.getSize().x,

            (float)CellSize /
            ghost3Texture.getSize().y
        }
    );


    // =================================================
    // FONT
    // =================================================

    bool fontSuccess =
        gameFont.openFromFile(
            "roboto.ttf"
        );


    if (!fontSuccess)
    {
        cout << "Error loading roboto.ttf!"
            << endl;
    }


    // =================================================
    // SCORE
    // =================================================

    scoreText =
        new sf::Text(
            gameFont
        );


    scoreText->setCharacterSize(
        24
    );

    scoreText->setFillColor(
        sf::Color::White
    );

    scoreText->setPosition(
        {
            10.f,
            10.f
        }
    );


    // =================================================
    // GAME OVER
    // =================================================

    gameOverText =
        new sf::Text(
            gameFont
        );


    gameOverText->setString(
        "GAME OVER!"
    );


    gameOverText->setCharacterSize(
        60
    );


    gameOverText->setFillColor(
        sf::Color::Red
    );


    gameOverText->setPosition(
        {
            200.f,
            250.f
        }
    );


    // =================================================
    // WIN
    // =================================================

    winText =
        new sf::Text(
            gameFont
        );


    winText->setString(
        "YOU ESCAPED!"
    );


    winText->setCharacterSize(
        60
    );


    winText->setFillColor(
        sf::Color::Green
    );


    winText->setPosition(
        {
            180.f,
            250.f
        }
    );


    // =================================================
    // QUIZ
    // =================================================

    quizText =
        new sf::Text(
            gameFont
        );


    quizText->setCharacterSize(
        24
    );


    quizText->setFillColor(
        sf::Color::White
    );


    quizText->setPosition(
        {
            80.f,
            80.f
        }
    );


    quizPanel.setSize(
        {
            (float)WindowWidth - 160.f,
            (float)WindowHeight - 160.f
        }
    );


    quizPanel.setPosition(
        {
            80.f,
            80.f
        }
    );


    quizPanel.setFillColor(
        sf::Color(
            0,
            0,
            0,
            200
        )
    );


    answerFeedbackText =
        new sf::Text(
            gameFont
        );


    answerFeedbackText->setCharacterSize(
        30
    );


    answerFeedbackText->setFillColor(
        sf::Color::Yellow
    );


    answerFeedbackText->setPosition(
        {
            200.f,
            20.f
        }
    );


    // =================================================
    // SOUNDS
    // =================================================

    if (!dotBuffer.loadFromFile("dots.mp3"))
    {
        cout << "Error loading dots.mp3!"
            << endl;
    }


    dotSound =
        new sf::Sound(
            dotBuffer
        );


    dotSound->setVolume(
        60.f
    );


    if (!powerBuffer.loadFromFile("power.mp3"))
    {
        cout << "Error loading power.mp3!"
            << endl;
    }


    powerSound =
        new sf::Sound(
            powerBuffer
        );


    powerSound->setVolume(
        100.f
    );


    if (!deathBuffer.loadFromFile("death.mp3"))
    {
        cout << "Error loading death.mp3!"
            << endl;
    }


    deathSound =
        new sf::Sound(
            deathBuffer
        );


    deathSound->setVolume(
        150.f
    );


    if (!bgMusic.openFromFile("background.mp3"))
    {
        cout << "Error loading background.mp3!"
            << endl;
    }


    bgMusic.setVolume(
        30.f
    );


    bgMusic.setLooping(
        true
    );


    bgMusic.play();


    // =================================================
    // MENU
    // =================================================

    titleText =
        new sf::Text(
            gameFont
        );


    titleText->setString(
        "PACMAN"
    );


    titleText->setCharacterSize(
        70
    );


    titleText->setFillColor(
        sf::Color::Red
    );


    titleText->setPosition(
        {
            240.f,
            70.f
        }
    );


    titleText2 =
        new sf::Text(
            gameFont
        );


    titleText2->setString(
        "DEMON REALM"
    );


    titleText2->setCharacterSize(
        70
    );


    titleText2->setFillColor(
        sf::Color::Red
    );


    titleText2->setPosition(
        {
            140.f,
            160.f
        }
    );


    startOptionText =
        new sf::Text(
            gameFont
        );


    startOptionText->setString(
        "Press [ENTER] to Start Game"
    );


    startOptionText->setCharacterSize(
        30
    );


    startOptionText->setFillColor(
        sf::Color::White
    );


    startOptionText->setPosition(
        {
            175.f,
            280.f
        }
    );


    tutorialOptionText =
        new sf::Text(
            gameFont
        );


    tutorialOptionText->setString(
        "Press [T] for Tutorials"
    );


    tutorialOptionText->setCharacterSize(
        30
    );


    tutorialOptionText->setFillColor(
        sf::Color(
            188,
            170,
            130
        )
    );


    tutorialOptionText->setPosition(
        {
            230.f,
            360.f
        }
    );


    // =================================================
    // TUTORIAL
    // =================================================

    tutorialContentText =
        new sf::Text(
            gameFont
        );


    tutorialContentText->setString(
        "CONTROLS:\n"
        "W - Up\n"
        "S - Down\n"
        "A - Left\n"
        "D - Right\n\n"
        "MECHANICS:\n"
        "- Eating a purple Power Pellet triggers a Quiz.\n"
        "- BEST Answer: +20 Score\n"
        "- AVG Answer: +10 Score\n"
        "- WORST Answer: +5 Score"
    );


    tutorialContentText->setCharacterSize(
        24
    );


    tutorialContentText->setFillColor(
        sf::Color::White
    );


    tutorialContentText->setPosition(
        {
            80.f,
            100.f
        }
    );


    backOptionText =
        new sf::Text(
            gameFont
        );


    backOptionText->setString(
        "Press [B] to go Back"
    );


    backOptionText->setCharacterSize(
        30
    );


    backOptionText->setFillColor(
        sf::Color::Yellow
    );


    backOptionText->setPosition(
        {
            80.f,
            500.f
        }
    );


    // =================================================
    // CHARACTER SELECT
    // =================================================

    char1Texture.loadFromFile(
        "demon_pacman.png"
    );


    char1Sprite =
        new sf::Sprite(
            char1Texture
        );


    char1Sprite->setScale(
        {
            100.f /
            char1Texture.getSize().x,

            100.f /
            char1Texture.getSize().y
        }
    );


    char1Sprite->setPosition(
        {
            120.f,
            250.f
        }
    );


    char2Texture.loadFromFile(
        "devil2.png"
    );


    char2Sprite =
        new sf::Sprite(
            char2Texture
        );


    char2Sprite->setScale(
        {
            100.f /
            char2Texture.getSize().x,

            100.f /
            char2Texture.getSize().y
        }
    );


    char2Sprite->setPosition(
        {
            340.f,
            250.f
        }
    );


    char3Texture.loadFromFile(
        "demon3.png"
    );


    char3Sprite =
        new sf::Sprite(
            char3Texture
        );


    char3Sprite->setScale(
        {
            100.f /
            char3Texture.getSize().x,

            100.f /
            char3Texture.getSize().y
        }
    );


    char3Sprite->setPosition(
        {
            560.f,
            250.f
        }
    );


    selectTitleText =
        new sf::Text(
            gameFont
        );


    selectTitleText->setString(
        "Choose Your Character"
    );


    selectTitleText->setCharacterSize(
        40
    );


    selectTitleText->setFillColor(
        sf::Color::White
    );


    selectTitleText->setPosition(
        {
            130.f,
            120.f
        }
    );


    char1Text =
        new sf::Text(
            gameFont
        );


    char1Text->setString(
        "Press [1]"
    );


    char1Text->setCharacterSize(
        24
    );


    char1Text->setFillColor(
        sf::Color::Yellow
    );


    char1Text->setPosition(
        {
            110.f,
            360.f
        }
    );


    char2Text =
        new sf::Text(
            gameFont
        );


    char2Text->setString(
        "Press [2]"
    );


    char2Text->setCharacterSize(
        24
    );


    char2Text->setFillColor(
        sf::Color::Cyan
    );


    char2Text->setPosition(
        {
            325.f,
            360.f
        }
    );


    char3Text =
        new sf::Text(
            gameFont
        );


    char3Text->setString(
        "Press [3]"
    );


    char3Text->setCharacterSize(
        24
    );


    char3Text->setFillColor(
        sf::Color::Magenta
    );


    char3Text->setPosition(
        {
            545.f,
            360.f
        }
    );


    selectionBox.setSize(
        {
            100.f,
            100.f
        }
    );


    selectionBox.setFillColor(
        sf::Color::Transparent
    );


    selectionBox.setOutlineThickness(
        3
    );


    selectionBox.setOutlineColor(
        sf::Color::White
    );

    // =================================================
// LEVEL SELECT BOX (separate from CHARACTER SELECT)
// =================================================

    levelSelectionBox.setFillColor(
        sf::Color::Transparent
    );


    levelSelectionBox.setOutlineThickness(
        3
    );


    levelSelectionBox.setOutlineColor(
        sf::Color::White
    );

    // =================================================
    // LEVEL SELECT
    // =================================================

    levelSelectTitleText =
        new sf::Text(
            gameFont
        );


    levelSelectTitleText->setString(
        "CHOOSE LEVEL"
    );


    levelSelectTitleText->setCharacterSize(
        50
    );


    levelSelectTitleText->setFillColor(
        sf::Color::White
    );


    levelSelectTitleText->setPosition(
        {
            260.f,
            80.f
        }
    );


    level1Text =
        new sf::Text(
            gameFont
        );


    level1Text->setString(
        "[1] LEVEL 1"
    );


    level1Text->setCharacterSize(
        30
    );


    level1Text->setFillColor(
        sf::Color::Yellow
    );


    level1Text->setPosition(
        {
            290.f,
            180.f
        }
    );


    level2Text =
        new sf::Text(
            gameFont
        );


    level2Text->setString(
        "[2] LEVEL 2"
    );


    level2Text->setCharacterSize(
        30
    );


    level2Text->setFillColor(
        sf::Color::White
    );


    level2Text->setPosition(
        {
            290.f,
            230.f
        }
    );


    level3Text =
        new sf::Text(
            gameFont
        );


    level3Text->setString(
        "[3] LEVEL 3"
    );


    level3Text->setCharacterSize(
        30
    );


    level3Text->setFillColor(
        sf::Color::White
    );


    level3Text->setPosition(
        {
            290.f,
            280.f
        }
    );


    level4Text =
        new sf::Text(
            gameFont
        );


    level4Text->setString(
        "[4] LEVEL 4"
    );


    level4Text->setCharacterSize(
        30
    );


    level4Text->setFillColor(
        sf::Color::White
    );


    level4Text->setPosition(
        {
            290.f,
            330.f
        }
    );


    level5Text =
        new sf::Text(
            gameFont
        );


    level5Text->setString(
        "[5] LEVEL 5"
    );


    level5Text->setCharacterSize(
        30
    );


    level5Text->setFillColor(
        sf::Color::White
    );


    level5Text->setPosition(
        {
            290.f,
            380.f
        }
    );


    levelBackText =
        new sf::Text(
            gameFont
        );


    levelBackText->setString(
        "Press [B] to go Back"
    );


    levelBackText->setCharacterSize(
        25
    );


    levelBackText->setFillColor(
        sf::Color::Yellow
    );


    levelBackText->setPosition(
        {
            280.f,
            480.f
        }
    );
}


// =====================================================
// DRAW MAZE
// =====================================================

void drawMaze(
    sf::RenderWindow& window
)
{
    for (int r = 0; r < Rows; r++)
    {
        for (int c = 0; c < Columns; c++)
        {
            float x =
                c * CellSize;

            float y =
                r * CellSize;


            if (maze[r][c] == 0)
            {
                sf::RectangleShape wall(
                    sf::Vector2f(
                        CellSize,
                        CellSize
                    )
                );


                wall.setPosition(
                    {
                        x,
                        y
                    }
                );


                wall.setFillColor(
                    sf::Color(
                        188,
                        170,
                        130
                    )
                );


                wall.setOutlineThickness(
                    1
                );


                wall.setOutlineColor(
                    sf::Color(
                        0,
                        0,
                        80
                    )
                );


                window.draw(wall);
            }


            else if (maze[r][c] == 1)
            {
                sf::RectangleShape cell(
                    sf::Vector2f(
                        CellSize,
                        CellSize
                    )
                );


                cell.setPosition(
                    {
                        x,
                        y
                    }
                );


                cell.setFillColor(
                    sf::Color::Black
                );


                window.draw(cell);


                sf::CircleShape dot(
                    4
                );


                dot.setFillColor(
                    sf::Color(
                        180,
                        0,
                        0
                    )
                );


                dot.setPosition(
                    {
                        x +
                        CellSize / 2 -
                        4,

                        y +
                        CellSize / 2 -
                        4
                    }
                );


                window.draw(dot);
            }


            else if (maze[r][c] == 2)
            {
                sf::RectangleShape cell(
                    sf::Vector2f(
                        CellSize,
                        CellSize
                    )
                );


                cell.setPosition(
                    {
                        x,
                        y
                    }
                );


                cell.setFillColor(
                    sf::Color::Black
                );


                window.draw(cell);
            }


            else if (maze[r][c] == 3)
            {
                sf::RectangleShape cell(
                    sf::Vector2f(
                        CellSize,
                        CellSize
                    )
                );


                cell.setPosition(
                    {
                        x,
                        y
                    }
                );


                cell.setFillColor(
                    sf::Color::Black
                );


                window.draw(cell);


                sf::CircleShape pellet(
                    10
                );


                pellet.setFillColor(
                    sf::Color(
                        128,
                        0,
                        128
                    )
                );


                pellet.setPosition(
                    {
                        x +
                        CellSize / 2 -
                        10,

                        y +
                        CellSize / 2 -
                        10
                    }
                );


                window.draw(pellet);
            }
        }
    }
}


// =====================================================
// DRAW PACMAN
// =====================================================

void drawPacman(
    sf::RenderWindow& window
)
{
    pacmanSprite->setPosition(
        {
            pacmanX,
            pacmanY
        }
    );


    window.draw(
        *pacmanSprite
    );
}


// =====================================================
// DRAW GHOSTS
// =====================================================

void drawGhosts(
    sf::RenderWindow& window
)
{
    ghostSprite->setPosition(
        {
            ghostX,
            ghostY
        }
    );


    window.draw(
        *ghostSprite
    );


    ghost2Sprite->setPosition(
        {
            ghost2X,
            ghost2Y
        }
    );


    window.draw(
        *ghost2Sprite
    );


    ghost3Sprite->setPosition(
        {
            ghost3X,
            ghost3Y
        }
    );


    window.draw(
        *ghost3Sprite
    );
}
