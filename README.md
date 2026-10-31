# Library Management System

A console-based Library Management System developed in C++ using Object-Oriented Programming principles.

This project was created to practice C++ OOP concepts, STL containers, pointers, iterators, file handling, and modular project organization.

## Features

- Add a new book
- List all books
- Search for a book by ID
- Remove a book by ID
- Update book information
- Prevent duplicate book IDs
- Validate user inputs
- Save book records to a text file
- Load book records when the program starts
- Skip invalid records while loading data
- Console-based menu system

## Technologies

- C++
- Object-Oriented Programming (OOP)
- Standard Template Library (STL)
- `std::vector`
- Pointers
- Iterators
- File handling (`ifstream`, `ofstream`)
- Exception handling (`try-catch`)

## Project Structure

```text
LibraryManagementSystem/
│
├── include/
│   ├── Book.h
│   └── Library.h
│
├── src/
│   ├── Book.cpp
│   └── Library.cpp
│
├── output/
│
├── .gitignore
├── README.md
└── main.cpp
```

## OOP Concepts Used

### Encapsulation

Book information is stored inside the `Book` class using private member variables.

### Classes and Objects

The project contains separate `Book` and `Library` classes.

### Pointers

Pointers are used when searching for a book:

```cpp
Book* foundBook = library.findBook(id);
```

### Iterators

Iterators are used to search and remove books from the `std::vector`.

### STL

The library stores books using:

```cpp
std::vector<Book>
```

### File Handling

Book records are saved to and loaded from `books.txt` using file streams.

## How to Run

Compile the project using a C++ compiler:

```bash
g++ main.cpp src/Book.cpp src/Library.cpp -o main
```

On Windows, run:

```powershell
.\main.exe
```

The program creates or uses `books.txt` to store book records.

## Current Version

**v0.2.0 - Improved Library Management System**

### What's New in v0.2.0?

- Added book updating functionality
- Added input validation
- Prevented duplicate book IDs
- Improved file handling
- Added invalid record checking when loading data
- Improved error handling

The project is still under development. Future versions may include user management, borrowing and returning books, and more advanced features.

## Author

**Yusuf Yiğit**

GitHub: [yusufyigityazilim](https://github.com/yusufyigityazilim)
