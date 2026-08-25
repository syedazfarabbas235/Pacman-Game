#include "Game.h"

#include <cstdlib>
#include <ctime>


int main()
{
    // =================================================
    // RANDOM NUMBER GENERATOR
    // =================================================

    srand(
        time(0)
    );


    // =================================================
    // CREATE WINDOW
    // =================================================

    sf::RenderWindow window(
        sf::VideoMode(
            {
                (unsigned int)WindowWidth,
                (unsigned int)WindowHeight
            }
        ),
        "Pacman - Demon Realm"
    );


    // =================================================
    // FRAME RATE
    // =================================================

    window.setFramerateLimit(
        60
    );


    // =================================================
    // LOAD ASSETS
    // =================================================

    loadAssets();


    // =================================================
    // START LEVEL 1
    // =================================================

    loadLevel(1);


    // =================================================
    // MAIN GAME LOOP
    // =================================================

    while (
        window.isOpen()
        )
    {
        while (
            const auto event =
            window.pollEvent()
            )
        {
            if (
                event->is<
                sf::Event::Closed
                >()
                )
            {
                window.close();
            }
        }


        // Update
        updateGameLogic();


        // Draw
        renderGame(
            window
        );
    }


    return 0;
}
