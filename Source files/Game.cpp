#include "Game.h"

using namespace std;


// =====================================================
// KEY EDGE DETECTION HELPER
// =====================================================
// isKeyPressed() stays true for every frame a key is
// physically held down. For menu / state-change keys we
// only want to react ONCE per press (on the transition
// from "not pressed" to "pressed"), otherwise a single
// held key can trigger multiple state changes in one
// press (e.g. skipping straight through LEVEL_SELECT).

static bool isKeyJustPressed(
    sf::Keyboard::Key key,
    bool& wasPressedFlag
)
{
    bool isPressed =
        sf::Keyboard::isKeyPressed(key);

    bool justPressed =
        isPressed && !wasPressedFlag;

    wasPressedFlag =
        isPressed;

    return justPressed;
}


// =====================================================
// GAME OVER
// =====================================================

bool checkGameOver()
{
    if (
        !ghost1Returning &&
        pacmanRow == ghostRow &&
        pacmanCol == ghostCol
        )
    {
        return true;
    }


    if (
        !ghost2Returning &&
        pacmanRow == ghost2Row &&
        pacmanCol == ghost2Col
        )
    {
        return true;
    }


    if (
        !ghost3Returning &&
        pacmanRow == ghost3Row &&
        pacmanCol == ghost3Col
        )
    {
        return true;
    }


    return false;
}


// =====================================================
// LEVEL COMPLETE
// =====================================================

bool checkWin()
{
    for (int r = 0; r < Rows; r++)
    {
        for (int c = 0; c < Columns; c++)
        {
            if (
                maze[r][c] == 1
                )
            {
                return false;
            }
        }
    }


    return true;
}


// =====================================================
// INPUT
// =====================================================

void handleInput()
{
    // =================================================
    // STATIC "WAS PRESSED" FLAGS (one per key we edge-detect)
    // =================================================

    static bool enterHeld = false;
    static bool tHeld = false;
    static bool bHeld = false;

    static bool num1Held = false;
    static bool num2Held = false;
    static bool num3Held = false;
    static bool num4Held = false;
    static bool num5Held = false;

    static bool quizAHeld = false;
    static bool quizBHeld = false;
    static bool quizCHeld = false;


    // =================================================
    // MENU
    // =================================================

    if (
        currentState == MENU
        )
    {
        if (
            isKeyJustPressed(
                sf::Keyboard::Key::Enter,
                enterHeld
            )
            )
        {
            currentState =
                CHARACTER_SELECT;
        }


        else if (
            isKeyJustPressed(
                sf::Keyboard::Key::T,
                tHeld
            )
            )
        {
            currentState =
                TUTORIAL;
        }


        // Keep the other tracked keys in sync even while
        // on this screen, so a leftover "held" state from
        // a previous screen doesn't cause a false edge.
        isKeyJustPressed(sf::Keyboard::Key::B, bHeld);
        isKeyJustPressed(sf::Keyboard::Key::Num1, num1Held);
        isKeyJustPressed(sf::Keyboard::Key::Num2, num2Held);
        isKeyJustPressed(sf::Keyboard::Key::Num3, num3Held);
        isKeyJustPressed(sf::Keyboard::Key::Num4, num4Held);
        isKeyJustPressed(sf::Keyboard::Key::Num5, num5Held);
    }


    // =================================================
    // CHARACTER SELECT
    // =================================================

    else if (
        currentState ==
        CHARACTER_SELECT
        )
    {
        if (
            isKeyJustPressed(
                sf::Keyboard::Key::Num1,
                num1Held
            )
            )
        {
            selectedCharacter =
                1;
        }


        else if (
            isKeyJustPressed(
                sf::Keyboard::Key::Num2,
                num2Held
            )
            )
        {
            selectedCharacter =
                2;
        }


        else if (
            isKeyJustPressed(
                sf::Keyboard::Key::Num3,
                num3Held
            )
            )
        {
            selectedCharacter =
                3;
        }


        else if (
            isKeyJustPressed(
                sf::Keyboard::Key::Enter,
                enterHeld
            )
            )
        {
            if (
                selectedCharacter != 0
                )
            {
                if (
                    selectedCharacter == 1
                    )
                {
                    pacmanTexture =
                        char1Texture;
                }


                else if (
                    selectedCharacter == 2
                    )
                {
                    pacmanTexture =
                        char2Texture;
                }


                else if (
                    selectedCharacter == 3
                    )
                {
                    pacmanTexture =
                        char3Texture;
                }


                pacmanSprite =
                    new sf::Sprite(
                        pacmanTexture
                    );


                pacmanSprite->setScale(
                    {
                        (float)CellSize /
                        pacmanTexture.getSize().x,

                        (float)CellSize /
                        pacmanTexture.getSize().y
                    }
                );


                // Character selected.
                // Now show level selection.
                currentState =
                    LEVEL_SELECT;
            }
        }


        else if (
            isKeyJustPressed(
                sf::Keyboard::Key::B,
                bHeld
            )
            )
        {
            currentState =
                MENU;
        }


        // Keep unrelated tracked keys in sync.
        isKeyJustPressed(sf::Keyboard::Key::T, tHeld);
        isKeyJustPressed(sf::Keyboard::Key::Num4, num4Held);
        isKeyJustPressed(sf::Keyboard::Key::Num5, num5Held);
    }


    // =================================================
    // LEVEL SELECT
    // =================================================

    else if (
        currentState == LEVEL_SELECT
        )
    {
        if (
            isKeyJustPressed(
                sf::Keyboard::Key::Num1,
                num1Held
            )
            )
        {
            currentLevel = 1;
        }

        else if (
            isKeyJustPressed(
                sf::Keyboard::Key::Num2,
                num2Held
            )
            )
        {
            currentLevel = 2;
        }

        else if (
            isKeyJustPressed(
                sf::Keyboard::Key::Num3,
                num3Held
            )
            )
        {
            currentLevel = 3;
        }

        else if (
            isKeyJustPressed(
                sf::Keyboard::Key::Num4,
                num4Held
            )
            )
        {
            currentLevel = 4;
        }

        else if (
            isKeyJustPressed(
                sf::Keyboard::Key::Num5,
                num5Held
            )
            )
        {
            currentLevel = 5;
        }

        else if (
            isKeyJustPressed(
                sf::Keyboard::Key::Enter,
                enterHeld
            )
            )
        {
            loadLevel(currentLevel);

            isGameOver = false;
            isGameWon = false;
            quizActive = false;
            showFeedback = false;

            currentState = PLAYING;
        }

        else if (
            isKeyJustPressed(
                sf::Keyboard::Key::B,
                bHeld
            )
            )
        {
            currentState = CHARACTER_SELECT;
        }


        // Keep unrelated tracked keys in sync.
        isKeyJustPressed(sf::Keyboard::Key::T, tHeld);
    }


    // =================================================
    // TUTORIAL
    // =================================================

    else if (
        currentState ==
        TUTORIAL
        )
    {
        if (
            isKeyJustPressed(
                sf::Keyboard::Key::B,
                bHeld
            )
            )
        {
            currentState =
                MENU;
        }


        // Keep unrelated tracked keys in sync.
        isKeyJustPressed(sf::Keyboard::Key::Enter, enterHeld);
        isKeyJustPressed(sf::Keyboard::Key::T, tHeld);
        isKeyJustPressed(sf::Keyboard::Key::Num1, num1Held);
        isKeyJustPressed(sf::Keyboard::Key::Num2, num2Held);
        isKeyJustPressed(sf::Keyboard::Key::Num3, num3Held);
        isKeyJustPressed(sf::Keyboard::Key::Num4, num4Held);
        isKeyJustPressed(sf::Keyboard::Key::Num5, num5Held);
    }


    // =================================================
    // QUIZ
    // =================================================

    else if (
        quizActive
        )
    {
        if (
            isKeyJustPressed(
                sf::Keyboard::Key::A,
                quizAHeld
            )
            )
        {
            handleQuizInput(
                sf::Keyboard::Key::A
            );

            return;
        }


        else if (
            isKeyJustPressed(
                sf::Keyboard::Key::B,
                quizBHeld
            )
            )
        {
            handleQuizInput(
                sf::Keyboard::Key::B
            );

            return;
        }


        else if (
            isKeyJustPressed(
                sf::Keyboard::Key::C,
                quizCHeld
            )
            )
        {
            handleQuizInput(
                sf::Keyboard::Key::C
            );

            return;
        }


        return;
    }


    // =================================================
    // PACMAN MOVEMENT
    // =================================================
    // Movement keys stay as continuous polling on purpose:
    // holding W/A/S/D should keep queuing that direction.

    else if (
        sf::Keyboard::isKeyPressed(
            sf::Keyboard::Key::W
        )
        )
    {
        nextDirRow = -1;
        nextDirCol = 0;
    }


    else if (
        sf::Keyboard::isKeyPressed(
            sf::Keyboard::Key::S
        )
        )
    {
        nextDirRow = 1;
        nextDirCol = 0;
    }


    else if (
        sf::Keyboard::isKeyPressed(
            sf::Keyboard::Key::A
        )
        )
    {
        nextDirRow = 0;
        nextDirCol = -1;
    }


    else if (
        sf::Keyboard::isKeyPressed(
            sf::Keyboard::Key::D
        )
        )
    {
        nextDirRow = 0;
        nextDirCol = 1;
    }
}


// =====================================================
// UPDATE
// =====================================================

void updateGameLogic()
{
    handleInput();


    if (
        currentState ==
        PLAYING
        )
    {
        if (
            !isGameOver &&
            !isGameWon
            )
        {
            if (!quizActive)
            {
                movePacman();

                updatePacmanAnimation();


                // Ghost 1 - BFS
                moveGhost();


                // Ghost 3 - Random
                moveGhostRandom();


                // Ghost 2 - DFS
                moveGhostDFS();


                updateGhostAnimations();


                // Check death.
                isGameOver =
                    checkGameOver();


                if (isGameOver)
                {
                    deathSound->play();
                }


                // Check current level.
                if (
                    checkWin()
                    )
                {
                    if (
                        currentLevel <
                        TOTAL_LEVELS
                        )
                    {
                        // Automatically start next level.
                        loadNextLevel();
                    }
                    else
                    {
                        // Level 5 completed.
                        isGameWon =
                            true;
                    }
                }
            }
            else
            {
                pacmanClock.restart();

                ghostClock.restart();

                ghost2Clock.restart();

                ghost3Clock.restart();
            }
        }
    }
}


// =====================================================
// RENDER
// =====================================================

void renderGame(
    sf::RenderWindow& window
)
{
    window.clear(
        sf::Color::Black
    );


    // =================================================
    // MENU
    // =================================================

    if (
        currentState ==
        MENU
        )
    {
        window.draw(
            *titleText
        );

        window.draw(
            *titleText2
        );

        window.draw(
            *startOptionText
        );

        window.draw(
            *tutorialOptionText
        );
    }


    // =================================================
    // TUTORIAL
    // =================================================

    else if (
        currentState ==
        TUTORIAL
        )
    {
        window.draw(
            *tutorialContentText
        );

        window.draw(
            *backOptionText
        );
    }


    // =================================================
    // CHARACTER SELECT
    // =================================================

    else if (
        currentState ==
        CHARACTER_SELECT
        )
    {
        window.draw(
            *selectTitleText
        );


        window.draw(
            *char1Sprite
        );

        window.draw(
            *char2Sprite
        );

        window.draw(
            *char3Sprite
        );


        window.draw(
            *char1Text
        );

        window.draw(
            *char2Text
        );

        window.draw(
            *char3Text
        );


        if (
            selectedCharacter == 1
            )
        {
            selectionBox.setPosition(
                {
                    119.f,
                    250.f
                }
            );
        }


        else if (
            selectedCharacter == 2
            )
        {
            selectionBox.setPosition(
                {
                    339.f,
                    250.f
                }
            );
        }


        else if (
            selectedCharacter == 3
            )
        {
            selectionBox.setPosition(
                {
                    559.f,
                    250.f
                }
            );
        }


        if (
            selectedCharacter != 0
            )
        {
            window.draw(
                selectionBox
            );
        }
    }


    // ======================================
    // LEVEL SELECT
    // ======================================

    else if (currentState == LEVEL_SELECT)
    {
        window.draw(*levelSelectTitleText);

        window.draw(*level1Text);
        window.draw(*level2Text);
        window.draw(*level3Text);
        window.draw(*level4Text);
        window.draw(*level5Text);

        window.draw(*levelBackText);


        // ==================================
        // WHITE SELECTION BOX
        // ==================================
        if (currentLevel == 1)
        {
            auto bounds = level1Text->getLocalBounds();

            levelSelectionBox.setPosition({
                level1Text->getPosition().x + bounds.position.x - 15.f,
                level1Text->getPosition().y + bounds.position.y - 10.f
                });

            levelSelectionBox.setSize({
                bounds.size.x + 30.f,
                bounds.size.y + 20.f
                });
        }

        else if (currentLevel == 2)
        {
            auto bounds = level2Text->getLocalBounds();

            levelSelectionBox.setPosition({
                level2Text->getPosition().x + bounds.position.x - 15.f,
                level2Text->getPosition().y + bounds.position.y - 10.f
                });

            levelSelectionBox.setSize({
                bounds.size.x + 30.f,
                bounds.size.y + 20.f
                });
        }

        else if (currentLevel == 3)
        {
            auto bounds = level3Text->getLocalBounds();

            levelSelectionBox.setPosition({
                level3Text->getPosition().x + bounds.position.x - 15.f,
                level3Text->getPosition().y + bounds.position.y - 10.f
                });

            levelSelectionBox.setSize({
                bounds.size.x + 30.f,
                bounds.size.y + 20.f
                });
        }

        else if (currentLevel == 4)
        {
            auto bounds = level4Text->getLocalBounds();

            levelSelectionBox.setPosition({
                level4Text->getPosition().x + bounds.position.x - 15.f,
                level4Text->getPosition().y + bounds.position.y - 10.f
                });

            levelSelectionBox.setSize({
                bounds.size.x + 30.f,
                bounds.size.y + 20.f
                });
        }

        else if (currentLevel == 5)
        {
            auto bounds = level5Text->getLocalBounds();

            levelSelectionBox.setPosition({
                level5Text->getPosition().x + bounds.position.x - 15.f,
                level5Text->getPosition().y + bounds.position.y - 10.f
                });

            levelSelectionBox.setSize({
                bounds.size.x + 30.f,
                bounds.size.y + 20.f
                });
        }


        // ==================================
        // WHITE OUTLINE
        // ==================================

        levelSelectionBox.setFillColor(
            sf::Color::Transparent
        );

        levelSelectionBox.setOutlineColor(
            sf::Color::White
        );

        levelSelectionBox.setOutlineThickness(3.f);


        window.draw(levelSelectionBox);
    }

    // =================================================
    // GAME
    // =================================================

    else if (
        currentState ==
        PLAYING
        )
    {
        drawMaze(
            window
        );

        drawPacman(
            window
        );

        drawGhosts(
            window
        );

        drawQuiz(
            window
        );


        scoreText->setString(
            "SCORE: " +
            to_string(score)
        );


        window.draw(
            *scoreText
        );


        if (showFeedback)
        {
            if (
                feedbackClock
                .getElapsedTime()
                .asSeconds() > 5.f
                )
            {
                showFeedback =
                    false;
            }


            window.draw(
                *answerFeedbackText
            );
        }


        if (isGameOver)
        {
            window.draw(
                *gameOverText
            );
        }


        if (isGameWon)
        {
            window.draw(
                *winText
            );
        }
    }


    window.display();
}
