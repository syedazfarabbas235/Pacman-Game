#include "Game.h"

#include <cstdlib>

using namespace std;


// =====================================================
// STACK
// =====================================================

StackNode* top = nullptr;


// =====================================================
// UI
// =====================================================

sf::Font gameFont;

sf::Text* scoreText = nullptr;
sf::Text* gameOverText = nullptr;
sf::Text* winText = nullptr;


// =====================================================
// SCORE
// =====================================================

int score = 0;


// =====================================================
// QUIZ
// =====================================================

bool quizActive = false;

int currentQuestion = 0;

sf::Text* quizText = nullptr;

sf::RectangleShape quizPanel;

bool powerMode = false;

sf::Clock powerClock;

sf::Text* answerFeedbackText = nullptr;

sf::Clock feedbackClock;

bool showFeedback = false;


// =====================================================
// AUDIO
// =====================================================

sf::SoundBuffer dotBuffer;
sf::Sound* dotSound = nullptr;

sf::SoundBuffer powerBuffer;
sf::Sound* powerSound = nullptr;

sf::SoundBuffer deathBuffer;
sf::Sound* deathSound = nullptr;

sf::Music bgMusic;


// =====================================================
// GHOST RETURN
// =====================================================

bool ghost1Returning = false;
bool ghost2Returning = false;
bool ghost3Returning = false;

sf::Clock ghostReturnClock;


// =====================================================
// GAME STATE
// =====================================================

GameState currentState = MENU;


// =====================================================
// MENU
// =====================================================

sf::Text* titleText = nullptr;
sf::Text* titleText2 = nullptr;

sf::Text* startOptionText = nullptr;
sf::Text* tutorialOptionText = nullptr;


// =====================================================
// CHARACTER SELECT
// =====================================================

int selectedCharacter = 0;

sf::Texture char1Texture;
sf::Texture char2Texture;
sf::Texture char3Texture;

sf::Sprite* char1Sprite = nullptr;
sf::Sprite* char2Sprite = nullptr;
sf::Sprite* char3Sprite = nullptr;

sf::Text* selectTitleText = nullptr;

sf::Text* char1Text = nullptr;
sf::Text* char2Text = nullptr;
sf::Text* char3Text = nullptr;

sf::RectangleShape selectionBox;


// =====================================================
// TUTORIAL
// =====================================================

sf::Text* tutorialContentText = nullptr;
sf::Text* backOptionText = nullptr;


// =====================================================
// LEVEL SELECT
// =====================================================

sf::Text* levelSelectTitleText = nullptr;

sf::Text* level1Text = nullptr;
sf::Text* level2Text = nullptr;
sf::Text* level3Text = nullptr;
sf::Text* level4Text = nullptr;
sf::Text* level5Text = nullptr;

sf::Text* levelBackText = nullptr;

// Its own box, separate from CHARACTER_SELECT's selectionBox.
sf::RectangleShape levelSelectionBox;


// =====================================================
// PACMAN
// =====================================================

int pacmanRow = 6;
int pacmanCol = 6;

float pacmanX = pacmanCol * CellSize;
float pacmanY = pacmanRow * CellSize;


// =====================================================
// GHOSTS
// =====================================================

int ghostRow = 8;
int ghostCol = 8;

int ghost2Row = 8;
int ghost2Col = 11;

int ghost3Row = 9;
int ghost3Col = 9;

int prevGhost3Row = -1;
int prevGhost3Col = -1;


float ghostX = ghostCol * CellSize;
float ghostY = ghostRow * CellSize;

float ghost2X = ghost2Col * CellSize;
float ghost2Y = ghost2Row * CellSize;

float ghost3X = ghost3Col * CellSize;
float ghost3Y = ghost3Row * CellSize;


// =====================================================
// QUESTIONS
// 4 QUESTIONS FOR EACH LEVEL
// =====================================================

Question q[20] =
{
    // =================================================
    // LEVEL 1
    // =================================================

    {
        "A child is hungry in the demon realm.",
        "What will you do?",
        "A. Ignore the child",
        "B. Give the child food",
        "C. Take the food away",
        'B',
        'C',
        'A'
    },

    {
        "A traveler is injured while ghosts chase you.",
        "What will you do?",
        "A. Help the traveler",
        "B. Run away",
        "C. Steal the traveler's money",
        'A',
        'B',
        'C'
    },

    {
        "You find a crystal with dark power.",
        "What will you choose?",
        "A. Use it selfishly",
        "B. Destroy it",
        "C. Hide it",
        'B',
        'C',
        'A'
    },

    {
        "A lonely spirit asks you to listen.",
        "What will you do?",
        "A. Mock the spirit",
        "B. Comfort the spirit",
        "C. Walk away",
        'B',
        'C',
        'A'
    },


    // =================================================
    // LEVEL 2
    // =================================================

    {
        "A demon drops his supplies on the road.",
        "What will you do?",
        "A. Return them",
        "B. Hide them",
        "C. Break them",
        'A',
        'B',
        'C'
    },

    {
        "You see a lost child near a dangerous cave.",
        "What will you do?",
        "A. Guide the child",
        "B. Leave the child",
        "C. Scare the child",
        'A',
        'B',
        'C'
    },

    {
        "A guard is being treated unfairly.",
        "What is the best choice?",
        "A. Laugh",
        "B. Speak up",
        "C. Ignore it",
        'B',
        'C',
        'A'
    },

    {
        "You find a magical healing potion.",
        "What should you do?",
        "A. Waste it",
        "B. Share it with someone hurt",
        "C. Hide it forever",
        'B',
        'C',
        'A'
    },


    // =================================================
    // LEVEL 3
    // =================================================

    {
        "A ghost asks for directions.",
        "What will you do?",
        "A. Help the ghost",
        "B. Mislead it",
        "C. Ignore it",
        'A',
        'C',
        'B'
    },

    {
        "You can save one trapped traveler.",
        "What do you choose?",
        "A. Help them",
        "B. Walk away",
        "C. Take their belongings",
        'A',
        'B',
        'C'
    },

    {
        "A dark spell is hurting the village.",
        "What should you do?",
        "A. Make it stronger",
        "B. Stop the spell",
        "C. Ignore it",
        'B',
        'C',
        'A'
    },

    {
        "A frightened spirit needs courage.",
        "What will you do?",
        "A. Encourage it",
        "B. Mock it",
        "C. Leave immediately",
        'A',
        'C',
        'B'
    },


    // =================================================
    // LEVEL 4
    // =================================================

    {
        "A demon offers you a reward for helping.",
        "What is the best choice?",
        "A. Help only for money",
        "B. Help because it is right",
        "C. Refuse all help",
        'B',
        'A',
        'C'
    },

    {
        "You discover a secret safe path.",
        "What should you do?",
        "A. Share it with others",
        "B. Block it",
        "C. Keep everyone trapped",
        'A',
        'C',
        'B'
    },

    {
        "A monster is protecting a helpless creature.",
        "What will you do?",
        "A. Attack without thinking",
        "B. Observe and understand",
        "C. Run away",
        'B',
        'C',
        'A'
    },

    {
        "Your friend makes a serious mistake.",
        "What is the best response?",
        "A. Help fix it",
        "B. Humiliate them",
        "C. Ignore them",
        'A',
        'C',
        'B'
    },


    // =================================================
    // LEVEL 5
    // =================================================

    {
        "The final gate can only open with cooperation.",
        "What will you do?",
        "A. Work together",
        "B. Betray everyone",
        "C. Give up",
        'A',
        'C',
        'B'
    },

    {
        "A weak traveler asks for protection.",
        "What is the kind choice?",
        "A. Protect them",
        "B. Threaten them",
        "C. Leave them",
        'A',
        'C',
        'B'
    },

    {
        "You find treasure that belongs to the village.",
        "What should you do?",
        "A. Keep everything",
        "B. Return it",
        "C. Destroy it",
        'B',
        'C',
        'A'
    },

    {
        "You finally reach the demon realm exit.",
        "What should you remember?",
        "A. Help others when possible",
        "B. Betray everyone",
        "C. Never trust anyone",
        'A',
        'C',
        'B'
    }
};


// =====================================================
// MAZE
// =====================================================

// 0 = wall
// 1 = dot
// 2 = already eaten
// 3 = power pellet

int maze[Rows][Columns] =
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

    {0,1,1,1,3,1,1,1,1,0,0,1,1,1,1,1,1,1,3,0},

    {0,1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0},

    {0,1,1,0,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,0},

    {0,1,1,0,0,1,1,0,1,1,1,1,0,0,0,1,0,0,1,0},

    {0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0},

    {0,1,0,0,0,1,1,0,0,2,2,0,0,0,0,1,1,0,1,0},

    {0,1,1,1,0,1,1,0,0,2,2,0,0,1,0,1,1,1,1,0},

    {0,1,1,1,1,1,0,0,2,2,2,2,0,1,1,1,0,1,1,0},

    {0,1,0,1,1,1,0,0,2,2,2,2,0,0,1,1,0,1,1,0},

    {0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0},

    {0,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,3,0},

    {0,1,0,0,0,1,0,1,1,1,1,1,1,0,0,1,1,0,1,0},

    {0,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},

    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};


// =====================================================
// TEXTURES
// =====================================================

sf::Texture pacmanTexture;
sf::Sprite* pacmanSprite = nullptr;

sf::Texture ghostTexture;
sf::Sprite* ghostSprite = nullptr;

sf::Texture ghost2Texture;
sf::Sprite* ghost2Sprite = nullptr;

sf::Texture ghost3Texture;
sf::Sprite* ghost3Sprite = nullptr;


// =====================================================
// CLOCKS
// =====================================================

sf::Clock pacmanClock;
sf::Clock ghostClock;
sf::Clock ghost2Clock;
sf::Clock ghost3Clock;


// =====================================================
// GAME OVER / WIN
// =====================================================

bool isGameOver = false;
bool isGameWon = false;


// =====================================================
// GRAPH
// =====================================================

Node* availableMoves[Rows][Columns] =
{
    nullptr
};


// =====================================================
// QUEUE
// =====================================================

QueueNode* front = nullptr;
QueueNode* rear = nullptr;
