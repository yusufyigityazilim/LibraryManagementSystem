#include <iostream>
#include "include/Book.h"
#include "include/Library.h"

int main()
{
                Library library;

                int choice;

                while(true)
                {
                                std::cout << "\n====== LIBRARY MANAGEMENT SYSTEM ======\n\n";
                                std::cout << "1. Add Book\n";
                                std::cout << "2. Show All Books\n";
                                std::cout << "3. Find Book\n";
                                std::cout << "4. Remove Book\n";
                                std::cout << "5. Exit\n";
                                std::cout << "Choose : ";
                                std::cin >> choice;

                                switch(choice)
                                {
                                                case 1:
                                                {
                                                                int id;
                                                                std::string title;
                                                                std::string author;

                                                                std::cout << "Book ID: ";
                                                                std::cin >> id;

                                                                std::cin.ignore();

                                                                std::cout << "Book Title: ";
                                                                std::getline(std::cin,title);

                                                                std::cout << "Book Author: ";
                                                                std::getline(std::cin,author);

                                                                Book book(id,title,author);
                                                                library.addBook(book);

                                                                std::cout << "Book added successfully..!\n";

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

                                                std::cout << "Enter Book ID: ",
                                                std::cin >> id;

                                                library.removeBook(id);
                                                
                                                break;
                                                }
                                                

                                                case 5:
                                                return 0;
                                                break;

                                                default:
                                                std::cout << "Invalid Choice...!\n";

                                                break;
                                }
                }


                return 0;
}