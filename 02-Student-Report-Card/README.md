# Student Report Card Management System

This is a C++ project built using Object-Oriented Programming (OOP) concepts. It allows a student’s data to be managed — such as their name, roll number, subject names and marks — and calculates the average and grade based on entered scores. The final report is also stored in a file (`Report.txt`).

---

## General Explanation

The project is designed with two main classes: `Student` and `ReportCard`.

- The `Student` class handles personal details like name and roll number.
- The `ReportCard` class is responsible for taking subject names and marks, computing the average, deciding the grade, displaying the report, and saving it to a file.

The `ReportCard` class **uses a `Student` class object inside it**, which explains the report card includes student information.

### How I Used OOP Concepts:

#### 1. **Encapsulation**
I kept all the important data members (`name`, `rollNumber`, `marks`, etc.) as `private` so they cannot be accessed directly from outside the class. Instead, I used `public` methods like `input()`, `display()`, and `calculateAvg()` to safely access and modify that data.

#### 2. **Abstraction**
I have broken the project into small, readable functions like `inputMarks()`, `calculateGrade()`, and `saveToFile()` so the internal logic is hidden from the main function. This keeps the code clean and easy to understand.

#### 3. **Composition**
This means one class has another class object as a member. I included a `Student` object inside the `ReportCard` class — so it shows a "has-a" relationship (a report card **has a** student).

#### 4. **Modularity**
The entire code is divided into self-contained blocks. Each class has a specific responsibility, and each function performs one task. This makes it easy to debug and maintain the code.

---

## Functionalities

- Enter any number of subjects dynamically
- Validate that marks are between 0 and 100
- Calculate average marks
- Grade is assigned based on average:
- Display the report in the terminal
- Save the report to a file

---
## Eample Output:
   
   ![output Preview](output.png) 

## Compilation & Execution

Make sure you have a C++ compiler installed. To compile and run the code:

```bash
g++ -o report code.cpp
./report



