📘 Embedded Systems & OOP Lab Projects – README
This repository contains all assignments and projects developed across multiple university lab modules: Advanced Software Design Techniques, Advanced Programming Techniques, Advanced Microcontroller Systems and Real Time Operating System using Erika OS. Each folder represents a standalone assignment with full C/C++ implementations, UML diagrams, Doxygen documentation, and test files.
________________________________________
📂 Repository Structure
├── AMA_EOS_Lab_01/          # AMA_EOS Lab 1: Timing Analyzer API
├── AMA_EOS_Lab_02/          # AMA_EOS Lab 2: Reaction Game + Arcadian effects
├── APT_Lab1a/               # APT Lab 1 – Exercise 1.1
├── APT_Lab1b/               # APT Lab 1 – Exercise 2.1
├── APT_Lab1c/                # APT Lab 1 – Exercise 3.1
├── APT_Lab2a/                # APT Lab 2 – Complete Battleship model
│   ├── part1tests.cpp
│   ├── part2tests.cpp
│   └── part3tests.cpp
├── ASDT_LAB1/               # ASDT Lab 1: Tic Tac Toe Game         
└── README.md
_________________________________________________________________________
⏱️ AMS Lab – Timing Analyzer
A configurable timing measurement API for bare metal embedded systems.
Features
•	Supports SysTick, DWT cycle counter, output pin toggling
•	Start / Stop / Pause / Resume state machine
•	Multiple analyzers running in parallel
•	UART based reporting (assembled before single shot transmit)
•	Designed with object oriented C (struct + function pointer patterns)
Configurations
•	DWT, DWT + OutputPin
•	SysTick, SysTick + OutputPin
•	OutputPin only
_________________________________________________________________________
🎮 EOS Lab – Reaction Game (ErikaOS)
A reaction-time game implemented using OSEK/Erika OS, tasks, events, and alarms.
Game Requirements Implemented
•	Random delay generation (1–3 seconds)
•	7 segment displays showing target
•	Button based reaction capture
•	Timeout detection
•	Score + average time
Arcadian Light Effects
•	Knight Rider style LED fading animation
•	RGB glow engine using configurable tables
•	Non blocking design → does not interfere with the main game
_________________________________________________________________________
🎮 APT Lab 1 – Reversi Board (Exercise 1.1)
A complete board engine for the Reversi/Othello game.
Highlights
•	Enum based board state representation
•	Move validation + auto flipping of pieces
•	ReversiConsoleView for clean game rendering
•	Modular design for future extension
_________________________________________________________________________
🔢 APT Lab 1 – Modulo Counter (Exercise 2.1)
Re implementation of single digit and multi digit modulo counters using C++ classes.
Supports
•	Operator overloading (++prefix, postfix++)
•	Dynamic multi digit counter with carry operations
•	Decimal / Octal / Binary / Hexadecimal modes
•	UML diagrams + Doxygen
_________________________________________________________________________
🌡️ APT Lab 1 – Heat Controller (Exercise 3.1)
An object oriented model of a modular heat controller.
Includes
•	Decomposition into functional components (sensors, actuators, regulators, display units)
•	Full documentation of each component’s purpose, state, and capabilities
•	A "story" describing system behavior when temperature increases
_________________________________________________________________________
🚢 APT Lab 2 – Battleship Game Model
A full OO model of the Battleship board system.
Implemented Components
•	GridPosition (immutable)
•	Ship (occupied & blocked area computation)
•	OwnGrid & OpponentGrid
•	Shot + hit / miss / sunk resolution
•	ConsoleView for dual grid visualization
•	Comprehensive test suite (part1tests, part2tests, part3tests)
Core Algorithms
•	Ship placement validation via set intersections
•	Blocked area analysis (8 neighborhood mapping)
•	Sinking detection via hit set comparison
_________________________________________________________________________
🧩 ASDT – TicTacToe (Assignment 1)
Console-based TicTacToe implementation:
•	Full object-oriented design with static & dynamic polymorphism
•	Human vs Computer, Computer vs Computer, and Human vs Human modes
•	A computer player that never loses (defense-first heuristics)
•	Clean screen abstraction for future GUI extensions
Key Features
•	Class hierarchy: CTicTacToe, CBoard, CPosition, CScreen, CPlayer subclasses
•	Doxygen documentation + UML diagrams
•	Defensive AI implementation (detects rows/columns/diagonals)
_________________________________________________________________________
🛠️ Build & Run Instructions
Each project includes detailed instructions in its own folder.
General guideline:
•	APT & ASDT projects compile with any C++17+ toolchain
•	AMS Lab runs on embedded targets with DWT + SysTick
•	EOS Lab requires Erika Enterprise + configured OIL files
_________________________________________________________________________
📄 Documentation
All projects contain:
•	UML diagrams (hand-drawn or tool-generated)
•	Doxygen configuration + generated HTML documentation
•	Code following max 80 character rule (as required)
To regenerate docs:
doxygen <project_name>.doxyfile
Look inside the generated HTML/ folder.
_________________________________________________________________________
📬 Contact
For any clarifications, improvements, or collaboration, feel free to write an email.
_________________________________________________________________________
This README summarises all work across multiple embedded systems modules and reflects structured, well-documented engineering practice.

