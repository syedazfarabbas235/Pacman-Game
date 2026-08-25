<div align="center">

# 👹 PACMAN — DEMON REALM

### *Enter the Realm. Outsmart the Demons. Survive the Maze.*

<br>

<img src="assets/hero.png" alt="Pacman Demon Realm" width="900">

<br><br>

![C++](https://img.shields.io/badge/C%2B%2B-17%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-3.1-8CC445?style=for-the-badge&logo=sfml&logoColor=white)
![DSA](https://img.shields.io/badge/DSA-Algorithms-8B0000?style=for-the-badge)
![OOP](https://img.shields.io/badge/OOP-C%2B%2B-6A0DAD?style=for-the-badge)
![Game Development](https://img.shields.io/badge/Game-Development-111111?style=for-the-badge)

<br>

[![GitHub Repository](https://img.shields.io/badge/GitHub-Repository-181717?style=for-the-badge&logo=github)](https://github.com/syedazfarabbas235/Pacman-Game)
[![License](https://img.shields.io/badge/License-Educational-blue?style=for-the-badge)](#-credits)

</div>

---

# 🌑 THE DEMON REALM

> **A classic maze. A cursed realm. Intelligent demons.**
>
> **PACMAN — DEMON REALM** transforms the familiar Pacman-style maze into a dark supernatural world while using **Data Structures, Algorithms, Object-Oriented Programming, AI-style pathfinding and real-time game programming** underneath the gameplay.

The project was developed as a practical demonstration of how theoretical **Data Structures and Algorithms** can be transformed into an interactive game.

Instead of simply implementing BFS, DFS, queues, stacks and graphs as isolated programs, the project places these concepts inside a playable environment where they directly influence the behavior of the game.

<div align="center">

### 👹 ENTER THE MAZE

**🗺️ Navigate the Realm**  
**🧠 Outsmart the Demons**  
**⚡ Survive the Hunt**  
**🏆 Clear the Levels**

</div>

---

# 🎮 GAME OVERVIEW

<div align="center">

| 🌑 **DEMON REALM** | 🧠 **ALGORITHMIC AI** | ⚔️ **SURVIVAL** |
|:---:|:---:|:---:|
| Dark supernatural maze environment | BFS / DFS / Random movement | Avoid demons and clear the maze |
| Multiple playable levels | Graph-based movement | Score and power mode |
| Interactive menus | Queue & Stack based algorithms | Level progression |

</div>

The game combines several systems into one application:

- 🎮 Real-time player movement
- 🗺️ Grid-based maze
- 👹 Multiple ghost behaviors
- 🧠 BFS pathfinding
- 🔍 DFS-based movement
- 🎲 Random ghost movement
- 🕸️ Graph representation
- 📦 Queue implementation
- 📚 Stack implementation
- ⚡ Power mode
- 🧩 Interactive quizzes
- 🏆 Score system
- 🎭 Character selection
- 🌑 Multiple levels
- 🔊 Sound and music
- 🖥️ SFML rendering
- 🎛️ Multiple game states

---

# 🖼️ GAMEPLAY SHOWCASE

<div align="center">

## 🌑 Enter the Realm

<img src="assets/gameplay.gif" alt="Gameplay" width="850">

*Navigate the maze while the demons hunt you.*

</div>

---

## 🏯 The Main Menu

The game begins inside the **Demon Realm** interface.

The menu provides access to the main gameplay and tutorial system.

<img src="assets/menu.png" alt="Main Menu" width="800">

---

## 🎭 Choose Your Character

Players can select between the available playable characters before entering the maze.

<img src="assets/character-select.png" alt="Character Selection" width="800">

---

## 🗺️ Choose Your Level

The game includes a dedicated level-selection interface.

Players can select a level and confirm the selection before entering the maze.

<img src="assets/level-select.png" alt="Level Selection" width="800">

---

# 👹 THE DEMON CODEX

The ghosts are not simply decorative enemies.

Their movement is connected to different algorithmic approaches.

<div align="center">

| Demon | Behavior | Algorithm |
|:---:|:---|:---:|
| 👹 **Demon I** | Attempts to efficiently approach the player | **BFS** |
| 👁️ **Demon II** | Explores the maze using traversal logic | **DFS** |
| 🩸 **Demon III** | Moves using randomized behavior | **Random Movement** |

</div>

This makes the enemy system an important part of the project's DSA implementation.

---

## 🔵 BFS Demon — The Pathfinder

The BFS-based demon uses the maze as a graph and searches through reachable cells.

Conceptually:

```text
              PLAYER
                 ▲
                 │
          shortest route
                 │
                 │
        ┌────────┴────────┐
        │     GRAPH       │
        │                 │
        │  ●──●──●──●     │
        │  │  │  │  │     │
        │  ●──●──●──●     │
        │        ▲        │
        │        │        │
        └────────┼────────┘
                 │
              DEMON
