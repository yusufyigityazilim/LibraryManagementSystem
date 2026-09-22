# Library Management System

A console-based Library Management System developed in C++ using Object-Oriented Programming principles.

This project was created to practice C++ OOP concepts, STL containers, pointers, iterators, and modular project organization.

## Features

* Add a new book
* List all books
* Search for a book by ID
* Remove a book by ID
* Console-based menu system
* Object-oriented project structure

## Technologies

* C++
* Object-Oriented Programming (OOP)
* Standard Template Library (STL)
* `std::vector`
* Pointers
* Iterators
* File and class separation

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

## How to Run

Compile the project using a C++ compiler:

```bash
g++ main.cpp src/Book.cpp src/Library.cpp -o main
```

Then run:

```bash
./main
```

On Windows:

```powershell
.\main.exe
```

## Current Version

**v0.1 - Basic Library Management System**

The project is currently under development. Future versions will include persistent file storage, book updating, user management, borrowing/returning functionality, exception handling, validation, and automated tests.

## Author

**Yusuf Yiğit**

GitHub: [yusufyigityazilim](https://github.com/yusufyigityazilim)
