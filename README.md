# Quiz Game 🎮

A console-based trivia quiz game built in C++ that tests your general knowledge across various topics including geography, history, science, literature, and pop culture.

---

## 📋 Table of Contents

- [Features](#features)
- [Game Modes](#game-modes)
- [Quiz Lengths](#quiz-lengths)
- [How to Play](#how-to-play)
- [Installation](#installation)
- [Compilation](#compilation)
- [Gameplay](#gameplay)
- [Score System](#score-system)
- [Technologies Used](#technologies-used)
- [Future Enhancements](#future-enhancements)
- [Contributing](#contributing)
- [License](#license)

---

## ✨ Features

- **50 Diverse Questions** covering multiple topics
- **Multiple Game Modes** (Normal and Hard)
- **Customizable Quiz Length** (Short, Medium, Long)
- **Streak System** to track consecutive correct answers
- **Lives System** in Hard Mode for added challenge
- **Score Tracking** with persistent scoreboard
- **Random Question Selection** for variety
- **Input Validation** to ensure smooth gameplay
- **Replay Option** to play multiple rounds

---

## 🎯 Game Modes

### Normal Mode
- **Lives:** Unlimited (99 lives)
- **Difficulty:** Standard
- **Best for:** Learning and casual play
- Focus on improving your knowledge without pressure

### Hard Mode
- **Lives:** 10 lives
- **Difficulty:** Challenging
- **Best for:** Competitive players
- Game ends when you run out of lives

---

## 📏 Quiz Lengths

Choose from three different quiz lengths:

| Length | Questions | Time Estimate |
|--------|-----------|---------------|
| **Short** | 10 questions | ~5 minutes |
| **Medium** | 25 questions | ~12 minutes |
| **Long** | 50 questions | ~25 minutes |

---

## 🎮 How to Play

1. **Start the Game** - Launch the executable
2. **Enter Your Name** - Personalize your game session
3. **Select Options:**
   - Choose quiz length (Short/Medium/Long)
   - Choose game mode (Normal/Hard)
4. **Answer Questions** - Select from multiple choice options (A, B, C, or D)
5. **Track Your Progress** - Monitor your score, streak, and lives
6. **Replay** - Choose to play again or exit

---

## 🔧 Installation

### Prerequisites

- **C++ Compiler** (Visual Studio, g++, or any C++11 compatible compiler)
- **Windows OS** (due to `windows.h` dependency)

### Download

```bash
git clone https://github.com/Jashbindar/QuizGame.git
cd QuizGame
```

---

## 🛠️ Compilation

### Using Visual Studio

1. Open `ConsoleApplication2.sln` in Visual Studio
2. Build the solution: `Ctrl + Shift + B`
3. Run without debugging: `Ctrl + F5`

### Using g++ (Command Line)

```bash
g++ ConsoleApplication2.cpp -o QuizGame.exe
./QuizGame.exe
```

### Using MinGW

```bash
g++ -o QuizGame.exe ConsoleApplication2.cpp
QuizGame.exe
```

---

## 🕹️ Gameplay

### Main Menu

```
*********
Welcome to the Quiz Game!
*********
1. Start Game    2. Quiz Length
3. Gamemode      4. Quit
```

### During the Game

- Questions are presented one at a time
- Enter your answer (A, B, C, or D)
- Receive immediate feedback (Correct/Incorrect)
- Track your:
  - **Current Streak** - Consecutive correct answers
  - **Current Score** - Total correct answers
  - **Lives Left** - Remaining attempts (Hard Mode only)

### Sample Question

```
1. What is the capital of France?
 A. Rome
 B. Berlin
 C. Paris
 D. Madrid

Enter your answer: C
Correct!

Current Streak: 1
Current Score: 1
```

---

## 📊 Score System

### Scoring Mechanics

- **+1 point** for each correct answer
- **Streak counter** increases with consecutive correct answers
- **Streak resets** to 0 on incorrect answer
- Scores are saved to `Scoreboard.txt` after each game

### Scoreboard Format

```
Player name: John || Score: 15
Player name: Sarah || Score: 23
Player name: Mike || Score: 18
```

---

## 💻 Technologies Used

- **Language:** C++
- **Libraries:**
  - `<iostream>` - Input/output operations
  - `<stdlib.h>` - Standard library utilities
  - `<windows.h>` - Windows-specific functions
  - `<algorithm>` - STL algorithms
  - `<array>` - Array container
  - `<fstream>` - File handling

---

## 🔮 Future Enhancements

Potential improvements for future versions:

- [ ] Add more question categories
- [ ] Implement difficulty levels for individual questions
- [ ] Add timer feature for time-based challenges
- [ ] Create a graphical user interface (GUI)
- [ ] Add multiplayer mode
- [ ] Implement a leaderboard with sorting
- [ ] Add hints or lifelines feature
- [ ] Support for custom question banks
- [ ] Cross-platform compatibility (remove Windows dependency)
- [ ] Add sound effects and visual feedback

---

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Fork the repository**
2. **Create a feature branch**
   ```bash
   git checkout -b feature/YourFeature
   ```
3. **Commit your changes**
   ```bash
   git commit -m 'Add some feature'
   ```
4. **Push to the branch**
   ```bash
   git push origin feature/YourFeature
   ```
5. **Open a Pull Request**

### Contribution Ideas

- Add new questions to the question bank
- Fix typos in existing questions
- Improve error handling
- Optimize code performance
- Add new game modes
- Improve documentation

---

## 📝 Known Issues

- Question bank reloading function (`reloadQuestionBank()`) creates local arrays that don't affect global arrays
- Hard Mode lives set to 10 in main but description says 3
- Limited cross-platform support due to `windows.h` dependency
- Some input validation could be more robust

---

## 📜 License

This project is currently under no specific license. You may add a license (MIT, GPL, etc.) depending on your sharing preference.

---

## 👤 Author

**Jashbindar**
- GitHub: [@Jashbindar](https://github.com/Jashbindar)

---

## 🙏 Acknowledgments

- Thanks to all contributors and testers
- Inspired by classic trivia games
- Question content sourced from general knowledge topics

---

**Enjoy the Quiz Game! Test your knowledge and have fun! 🎉**

---

*For bug reports or feature requests, please open an issue on GitHub.*
