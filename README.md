# Spotify Listening Advisor

### A personalized C++ console guide for Spotify plans, listening habits, and music discovery

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)
![Application](https://img.shields.io/badge/application-console-1DB954)
![Status](https://img.shields.io/badge/status-active-2E7D32)

Spotify Listening Advisor is an interactive console application that studies a listener's habits and recommends a suitable listening option. It combines plan comparison, preference-based scoring, genre recommendations, listening estimates, input validation, feedback collection, and persistent text-file storage in one approachable C++ program.

## What It Does

The advisor asks users about:

- listener type
- usual listening situation
- budget preference
- student plan eligibility
- advertisement tolerance
- interest in music discovery
- favourite music genre
- weekly listening time

It then compares three possible choices:

1. Spotify Basic
2. Spotify Premium
3. Buying or downloading music for ownership

The final result includes a recommendation, explanation, score breakdown, monthly listening estimate, listener category, and genre-based song suggestions.

## Features

- Clear menu-based console interface
- Spotify plan and price comparison tables
- Personalized recommendation scoring
- Student plan and monthly cost estimate
- Five music genres with song or playlist suggestions
- Weekly-to-monthly listening estimates
- Estimated cost per listening hour for Premium recommendations
- Light, regular, and heavy listener categories
- Input validation for every numbered choice
- `q` or `Q` quit option throughout the questionnaire
- Repeatable sessions using a loop
- User rating and written review collection
- Session feedback stored with `vector`
- Persistent feedback saved to `spotify_feedback_reviews.txt`

## Program Flow

```text
Plan comparison
      |
User preference questions
      |
Recommendation scoring
      |
Plan recommendation and explanation
      |
Listening summary and song suggestions
      |
Rating and written feedback
      |
Repeat or quit
```

## Build And Run

Requirements:

- A C++17-compatible compiler such as `g++` or `clang++`
- Terminal, Command Prompt, or an IDE with C++ support

Compile:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o spotify_listener_advisor
```

Run on macOS or Linux:

```bash
./spotify_listener_advisor
```

Run on Windows:

```powershell
.\spotify_listener_advisor.exe
```

## Quitting Safely

At supported prompts, enter:

```text
q
```

or:

```text
Q
```

The application exits cleanly and displays any feedback already stored during the current session.

## Feedback Storage

After a recommendation, users can give a rating from 1 to 5 and write a short review. Feedback is held in memory for the current session and appended to:

```text
spotify_feedback_reviews.txt
```

Example:

```text
Recommendation: Spotify Premium
Rating: 5/5
Review: The recommendation matched my listening habits.
------------------------------
```

The feedback file is generated in the directory from which the program is run. It is excluded from Git by default so personal test feedback is not committed accidentally.

## Project Files

```text
Spotify_Listening_Advisor/
|-- main.cpp       Main program source
|-- README.md      Project documentation
`-- .gitignore     Generated files excluded from Git
```

## Concepts Demonstrated

This project demonstrates:

- functions and reusable output helpers
- `if`, `else if`, and `switch` decisions
- loops and validated user input
- arrays, strings, structures, and vectors
- formatted console tables with `<iomanip>`
- file writing with `<fstream>`
- basic recommendation scoring

## Important Note

The plan prices displayed by the program are reference values entered directly in the source code. Spotify pricing and promotional offers may change, so verify the values before presenting or submitting the project.
