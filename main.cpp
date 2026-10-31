#include <iostream>
#include "include/Book.h"
#include "include/Library.h"
#include <limits> // Used for ignore().
#include <algorithm> // Used for std::all_of() function.
#include <cctype> // It allows for checking whether the character is well-ordered.

int main()
{
                Library library;
                library.loadFromFile();

                int choice;

                while(true)
                {
                                std::cout << "\n====== LIBRARY MANAGEMENT SYSTEM ======\n\n";
                                std::cout << "1. Add Book\n";
                                std::cout << "2. Show All Books\n";
                                std::cout << "3. Find Book\n";
                                std::cout << "4. Remove Book\n";
                                std::cout << "5. Update Book\n";
                                std::cout << "6.Exit\n";
                                std::cout << "Choose : ";
                                std::cin >> choice;
                                if(std::cin.fail())
                                {
                                                std::cin.clear();
                                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                                std::cout << "Invalid Choice!\n";
                                                continue;
                                }

                                switch(choice)
                                {
                                                case 1:
                                                {
                                                                int id;
                                                                std::string title;
                                                                std::string author;

                                                                std::cout << "Book ID: ";
                                                                std::cin >> id;
                                                                if(std::cin.fail())
                                                                {
                                                                                std::cin.clear();
                                                                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                                                                std::cout << "Invalid ID!\n";
                                                                                break;
                                                                }

                                                                if(id <= 0 )
                                                                {
                                                                                std::cout << "ID must be greater than zero!\n";
                                                                                break;
                                                                }
                                                                
                                                                

                                                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                                                std::cout << "Book Title: ";
                                                                std::getline(std::cin,title);
                                                                if(title.empty() || std::all_of(title.begin(),title.end(),[](unsigned char c){return std::isspace(c);}))
                                                                {
                                                                                std::cout << "Book title cannot be empty!\n";
                                                                                break;
                                                                }

                                                                std::cout << "Book Author: ";
                                                                std::getline(std::cin,author);
                                                                if(author.empty() || std::all_of(author.begin(),author.end(),[](unsigned char c){return std::isspace(c);}))
                                                                {
                                                                                std::cout << "Book author cannot be empty!\n";
                                                                                break;
                                                                }

                                                                Book book(id,title,author);
                                                                if(library.addBook(book))
                                                                {
                                                                                library.saveToFile();
                                                                                std::cout << "Book added successfully!\n";
                                                                }
                                                                else
                                                                {
                                                                                std::cout << "ID is already used..!\n";
                                                                }
                                                                break;

                                                }

                                                case 2:
                                                library.showAllBooks();
                                                break;

                                                case 3:
                                                {
                                                int id;

                                                std::cout << "Enter Book ID: ";
                                                std::cin >> id;

                                                Book* foundBook = library.findBook(id);

                                                if(foundBook != nullptr)
                                                {
                                                std::cout << "\nBook Found:\n";
                                                foundBook->showBook();
                                                }
                                                else
                                                {
                                                std::cout << "\nBook Not Found..!";                
                                                }
                                                
                                                break;
                                                }

                                                case 4:
                                                {
                                                int id;

                                                std::cout << "Enter Book ID: ";
                                                std::cin >> id;

                                                if(library.removeBook(id))
                                                {
                                                                std::cout << "Book removed successfully...!\n";
                                                                library.saveToFile();
                                                }
                                                else
                                                {
                                                                std::cout << "Book not found!\n";
                                                }
                                                break;
                                                }
                                                

                                                case 5:
                                                {
                                                int id;

                                                std::cout << "Enter Book ID: ";
                                                std::cin >> id;
                                                Book* book = library.findBook(id);

                                                if(book != nullptr)
                                                {
                                                                std::string title;
                                                                std::string author;

                                                                std::cin.ignore();

                                                                std:: cout << "New Book Title: ";
                                                                std::getline(std::cin,title);
                                                                if(title.empty() || std::all_of(title.begin(),title.end(),[](unsigned char c){return std::isspace(c);}))
                                                                {
                                                                                std::cout << "Book title cannot be empty!\n";
                                                                                break;
                                                                }

                                                                std::cout << "New Book Author: ";
                                                                std::getline(std::cin,author);
                                                                if(author.empty() || std::all_of(author.begin(),author.end(),[](unsigned char c){return std::isspace(c);}))
                                                                {
                                                                                std::cout << "Book author cannot be empty!\n";
                                                                                break;
                                                                }

                                                                book->setTitle(title);
                                                                book->setAuthor(author);

                                                                library.saveToFile();

                                                                std::cout << "Book updated successfully..!\n";
                                                }
                                                else
                                                {
                                                                std::cout << "Book not found.\n";
                                                }
                                                break;
                                                }

                                                case 6:
                                                return 0;

                                                default:
                                                {
                                                std::cout << "Invalid Choice...!\n";
                                                                
                                                break;
                                                }
                                }
                }


                return 0;
}