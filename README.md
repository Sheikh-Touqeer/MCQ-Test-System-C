# MCQ Test Management System in C

A console-based MCQ test management system developed in C. The project uses file handling to manage question banks, supports multiple difficulty levels, records quiz results, and allows new questions to be added.

## Features

- User name input
- Easy, Normal, and Hard difficulty levels
- User-selectable number of MCQs
- Four answer options per question
- Input validation for A/B/C/D answers
- Immediate correct/incorrect feedback
- File-based question banks
- Add new MCQs to a selected difficulty level
- Quiz result summary
- Total quiz timing based on selected question count
- Persistent quiz history with date and time
- View previously recorded quiz history

## Question Banks

The project includes three question files:

- `easy.txt`
- `normal.txt`
- `hard.txt`

Each question contains four choices and a stored correct answer.

## Technologies & Concepts

- C
- File Handling
- Functions
- Arrays and Strings
- Conditional Logic
- Loops
- Switch Statements
- Input Validation
- Time Functions

## Project Structure

```text
MCQ-Test-System-C/
├── mcq_test_system.c
├── easy.txt
├── normal.txt
├── hard.txt
└── quiz_log.txt (created when quiz history is saved)
