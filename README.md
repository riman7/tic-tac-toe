# Tic Tac Toe Game

This project is a **Tic Tac Toe** game implemented in **C++** with the use of the **graphics.h** library for graphical rendering. The game features intelligent techniques such as attack and defense strategies, making it an engaging experience for players.

---

## Features

1. **Graphical Interface**: The game includes a user-friendly graphical interface powered by `graphics.h`.
2. **Single Player Mode**: Play against the computer.
3. **Attack and Defense Techniques**: The computer uses strategies to:
   - Win the game when possible (attack).
   - Block the player from winning (defense).
4. **Winning Combinations**: The game checks for 8 possible winning conditions to determine the outcome.
5. **Game States**: Supports win, loss, and draw scenarios.

---

## Prerequisites

- **Turbo C++** or any compatible IDE with support for `graphics.h`.
- A system capable of running legacy C++ graphics programs (e.g., DOSBox or native support).

---

## Installation and Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/tic-tac-toe-graphics.git
   ```
2. Open the project in your C++ IDE.
3. Ensure the `graphics.h` library is properly set up in your environment.
4. Compile and run the project.

---

## How It Works

### Graphics Part

- The **game board** is displayed using graphical functions from `graphics.h`.
- Mouse clicks are used to detect player moves.
- The grid and symbols (X and O) are drawn dynamically based on user and computer input.

### Logic Part

1. **Attack Strategy**:
   - The computer identifies opportunities to win by completing a row, column, or diagonal.
2. **Defense Strategy**:
   - The computer blocks the player from winning by checking for imminent threats in any row, column, or diagonal.
3. **Winning Combinations**:
   - The game uses an array-based representation to evaluate the 8 possible winning conditions:
     - 3 rows
     - 3 columns
     - 2 diagonals
4. **Outcome Detection**:
   - The program checks for win, loss, or draw after every move.

---

## Controls

- Use the mouse to select your position on the board.
- The game alternates turns between the player and the computer.

---

## Example Gameplay

- The player chooses a position using the mouse.
- The computer evaluates the board and makes its move based on attack or defense.
- The game continues until one of the following occurs:
  - A player wins.
  - The game ends in a draw.

---

## Collaboration

This project was a collaborative effort with **Sufal KC** ([GitHub Profile](https://github.com/Sufal-kc)), my classmate in the Bachelor program at **Sagarmatha Engineering College**. It was developed as a group semester minor project in the second semester for the **C++ subject**.

---

## Future Enhancements

- Add a multiplayer mode.
- Implement different difficulty levels for the computer.
- Add sound effects and animations.

---

## Acknowledgments

- `graphics.h` library for rendering the game interface.
- Algorithms for attack and defense logic inspired by classic AI techniques.

---



Enjoy the game and happy coding!

