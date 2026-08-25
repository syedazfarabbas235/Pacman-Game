#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

// =====================================================
// CONSTANTS
// =====================================================

constexpr int Rows = 15;
constexpr int Columns = 20;
constexpr int CellSize = 40;

constexpr int WindowWidth = Columns * CellSize;
constexpr int WindowHeight = Rows * CellSize;

constexpr int GHOST_START_ROW = 8;
constexpr int GHOST_START_COL = 9;

constexpr int GHOST2_START_ROW = 8;
constexpr int GHOST2_START_COL = 10;

constexpr int GHOST3_START_ROW = 9;
constexpr int GHOST3_START_COL = 9;

constexpr int TOTAL_LEVELS = 5;


// =====================================================
// DATA STRUCTURES
// =====================================================

struct Coordinate
{
    int row;
    int col;
};


struct Node
{
    int row;
    int col;
    Node* next;
};


struct Question
{
    std::string story;
    std::string question;

    std::string optionA;
    std::string optionB;
    std::string optionC;

    char bestAnswer;
    char avgAnswer;
    char worstAnswer;
};


struct QueueNode
{
    int row;
    int col;
    QueueNode* next;
};


struct StackNode
{
    int row;
    int col;
    StackNode* next;
};


// =====================================================
// GAME STATES
// =====================================================

enum GameState
{
    MENU,
    TUTORIAL,
    CHARACTER_SELECT,
    LEVEL_SELECT,
    PLAYING
};


// =====================================================
// GLOBAL DATA
// =====================================================

extern StackNode* top;

extern sf::Font gameFont;

extern sf::Text* scoreText;
extern sf::Text* gameOverText;
extern sf::Text* winText;

extern int score;


// =====================================================
// QUIZ
// =====================================================

extern bool quizActive;
extern int currentQuestion;

extern sf::Text* quizText;
extern sf::RectangleShape quizPanel;

extern bool powerMode;
extern sf::Clock powerClock;

extern sf::Text* answerFeedbackText;
extern sf::Clock feedbackClock;

extern bool showFeedback;


// =====================================================
// AUDIO
// =====================================================

extern sf::SoundBuffer dotBuffer;
extern sf::Sound* dotSound;

extern sf::SoundBuffer powerBuffer;
extern sf::Sound* powerSound;

extern sf::SoundBuffer deathBuffer;
extern sf::Sound* deathSound;

extern sf::Music bgMusic;


// =====================================================
// GHOST RETURN
// =====================================================

extern bool ghost1Returning;
extern bool ghost2Returning;
extern bool ghost3Returning;

extern sf::Clock ghostReturnClock;


// =====================================================
// GAME STATE
// =====================================================

extern GameState currentState;


// =====================================================
// MENU
// =====================================================

extern sf::Text* titleText;
extern sf::Text* titleText2;

extern sf::Text* startOptionText;
extern sf::Text* tutorialOptionText;


// =====================================================
// CHARACTER SELECT
// =====================================================

extern int selectedCharacter;

extern sf::Texture char1Texture;
extern sf::Texture char2Texture;
extern sf::Texture char3Texture;

extern sf::Sprite* char1Sprite;
extern sf::Sprite* char2Sprite;
extern sf::Sprite* char3Sprite;

extern sf::Text* selectTitleText;

extern sf::Text* char1Text;
extern sf::Text* char2Text;
extern sf::Text* char3Text;

extern sf::RectangleShape selectionBox;


// =====================================================
// TUTORIAL
// =====================================================

extern sf::Text* tutorialContentText;
extern sf::Text* backOptionText;


// =====================================================
// LEVEL SELECT
// =====================================================

extern sf::Text* levelSelectTitleText;

extern sf::Text* level1Text;
extern sf::Text* level2Text;
extern sf::Text* level3Text;
extern sf::Text* level4Text;
extern sf::Text* level5Text;

extern sf::Text* levelBackText;

// Separate box from CHARACTER_SELECT's selectionBox so the
// two screens never leave leftover size/position on a
// shared shape (this was causing the stray white box bug).
extern sf::RectangleShape levelSelectionBox;


// =====================================================
// PACMAN
// =====================================================

extern int pacmanRow;
extern int pacmanCol;

extern float pacmanX;
extern float pacmanY;


// =====================================================
// GHOSTS
// =====================================================

extern int ghostRow;
extern int ghostCol;

extern int ghost2Row;
extern int ghost2Col;

extern int ghost3Row;
extern int ghost3Col;

extern int prevGhost3Row;
extern int prevGhost3Col;


extern float ghostX;
extern float ghostY;

extern float ghost2X;
extern float ghost2Y;

extern float ghost3X;
extern float ghost3Y;


// =====================================================
// QUESTIONS + MAZE
// =====================================================

extern Question q[20];

extern int maze[Rows][Columns];


// =====================================================
// TEXTURES / SPRITES
// =====================================================

extern sf::Texture pacmanTexture;
extern sf::Sprite* pacmanSprite;

extern sf::Texture ghostTexture;
extern sf::Sprite* ghostSprite;

extern sf::Texture ghost2Texture;
extern sf::Sprite* ghost2Sprite;

extern sf::Texture ghost3Texture;
extern sf::Sprite* ghost3Sprite;


// =====================================================
// CLOCKS
// =====================================================

extern sf::Clock pacmanClock;
extern sf::Clock ghostClock;
extern sf::Clock ghost2Clock;
extern sf::Clock ghost3Clock;


// =====================================================
// GAME OVER / WIN
// =====================================================

extern bool isGameOver;
extern bool isGameWon;


// =====================================================
// PACMAN DIRECTION
// =====================================================

extern int dirRow;
extern int dirCol;

extern int nextDirRow;
extern int nextDirCol;


// =====================================================
// GRAPH
// =====================================================

extern Node* availableMoves[Rows][Columns];


// =====================================================
// QUEUE
// =====================================================

extern QueueNode* front;
extern QueueNode* rear;


// =====================================================
// LEVEL SYSTEM
// =====================================================

extern int currentLevel;

void loadLevel(int level);
void loadNextLevel();


// =====================================================
// QUEUE / STACK
// =====================================================

void enqueue(int r, int c);
QueueNode* dequeue();
void clearQueue();

void push(int r, int c);
StackNode* pop();
void clearStack();


// =====================================================
// GRAPH
// =====================================================

void clearGraph();
void buildGraph();


// =====================================================
// AI
// =====================================================

Coordinate bfs(
    int startRow,
    int startCol,
    int targetRow,
    int targetCol
);

void startDFS(
    int startRow,
    int startCol
);

Coordinate moveDFS(
    int ghostR,
    int ghostC
);


// =====================================================
// ASSETS + DRAWING
// =====================================================

void loadAssets();

void drawMaze(
    sf::RenderWindow& window
);

void drawPacman(
    sf::RenderWindow& window
);

void drawGhosts(
    sf::RenderWindow& window
);

void drawQuiz(
    sf::RenderWindow& window
);


// =====================================================
// PACMAN + QUIZ
// =====================================================

void movePacman();

void updatePacmanAnimation();

bool isValidCell(
    int r,
    int c
);

Coordinate fleeMove(
    int gRow,
    int gCol
);

void handleAnswer(
    char ans,
    int index
);

void updateQuizText();

void handleQuizInput(
    sf::Keyboard::Key key
);


// =====================================================
// GHOSTS
// =====================================================

void moveGhost();

void moveGhostRandom();

void moveGhostDFS();

void updateGhostAnimations();


// =====================================================
// GAME
// =====================================================

bool checkGameOver();

bool checkWin();

void handleInput();

void updateGameLogic();

void renderGame(
    sf::RenderWindow& window
);
