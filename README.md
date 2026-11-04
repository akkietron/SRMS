# Student Record Management System (C++)

A modular, console-based Student Record Management System written in standard C++. The project uses Object-Oriented Programming (OOP) principles to encapsulate student academic and personal profiles, supporting structured data manipulation and lightweight CSV serialization for persistent storage.

---

## Features Implemented

- **OOP Encapsulation**: Private data members for academic and personal attributes with strictly validated public getters and setters.
- **Data Validation**:
  - GPA / CGPA bound checking ($0.0 \le \text{CGPA} \le 10.0$).
  - String field non-empty checks for names, branches, and contact info.
- **CSV Serialization & Parsing**:
  - `toCSV()`: Encodes object state into comma-separated text strings.
  - `fromCSV()`: Parses delimited CSV records with built-in stringstream processing and `try-catch` exception handling for robust type conversions (`stof`).
- **Flexible Constructors**:
  - Unparameterized default constructor using modern in-class member initialization to avoid garbage values.
  - Parameterized constructor utilizing member initializer lists for optimal memory and execution performance.

---

## Data Model

Each `Student` entity tracks the following fields:

| Field | Type | Description |
| :--- | :--- | :--- |
| `enrollnumber` | `string` | Unique student enrollment / registration ID |
| `name` | `string` | Full name of the student |
| `branch` | `string` | Academic discipline/department (e.g., CSE) |
| `semester` | `string` | Current semester designation |
| `cgpa` | `float` | Cumulative Grade Point Average (0.0 to 10.0 scale) |
| `email` | `string` | Contact email address |
| `phonenumber` | `string` | Contact phone number |

---

## Project Structure

```text
├── Student.h          # Core Student entity class definition (or main.cpp)
├── students.csv       # Persistent flat-file storage (generated at runtime)
├── .gitignore         # Ignores compiled binaries and temporary artifacts
└── README.md          # Project documentation