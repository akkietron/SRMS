# Student Record Management System

A high-performance, modular console application implemented in modern C++ (C++17). Designed around core Object-Oriented Programming (OOP) principles, this system manages student academic records, profile details, and persistence via flat-file CSV storage.

---

## Key Features

- **Object-Oriented Architecture**: Full encapsulation of student entities with private attributes, safe constructors, and strict access controls via public getters/setters.
- **Defensive Data Validation**:
  - Boundary checking on academic metrics ($0.0 \le \text{CGPA} \le 10.0$).
  - Guard clauses against empty strings on profile updates.
- **Robust CSV Persistence**:
  - Native serialization (`toCSV`) and deserialization (`fromCSV`).
  - Stream parsing using `std::stringstream` with exception handling (`try-catch` over `std::stof`) to prevent crashes from malformed data lines.
- **Full CRUD Workflow**:
  - **Create**: Add new student profiles with duplicate enrollment ID prevention.
  - **Read**: Formatted tabular display of all enrolled students and single-record queries.
  - **Update**: Modify personal details, branch, semester, and academic standing in place.
  - **Delete**: Purge records by unique enrollment key.
- **Fail-Safe Terminal I/O**: Custom stream sanitizers (`std::cin.clear()`, `std::cin.ignore()`) that eliminate buffer residue and prevent infinite loops on invalid input types.

---

## Data Schema

| Field | Type | Constraint / Description |
| :--- | :--- | :--- |
| `enrollnumber` | `std::string` | Primary key / Unique registration identifier |
| `name` | `std::string` | Full student name |
| `branch` | `std::string` | Department / Academic discipline (e.g., CSE) |
| `semester` | `std::string` | Current term / semester designation |
| `cgpa` | `float` | Scale from `0.00` to `10.00` |
| `email` | `std::string` | Student institutional/contact email |
| `phonenumber` | `std::string` | Primary contact number |

---

## Project Architecture

```text
StudentRecordManagement/
├── main.cpp          # Complete system implementation (Entity, Manager, CLI)
├── students.csv      # Persistent flat-file storage database (auto-managed)
├── .gitignore        # Excludes compiled binaries (*.exe) and IDE artifacts
└── README.md         # Technical documentation