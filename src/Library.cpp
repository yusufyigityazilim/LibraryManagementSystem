#include "../include/Library.h"
#include <iostream>

void Library::addBook(const Book& book)
{
                books.push_back(book);
}


void Library::showAllBooks() const
{
                for(const Book& book : books)
                {
                                book.showBook();
                                std::cout << "-----------------------\n";
                }
}

Book* Library ::findBook(int id)
{
                for(Book& book : books)
                {
                                if(book.getId() == id)
                                {
                                                return &book;
                                }
                }

                return nullptr;
}

void Library::removeBook(int id)
{
                for(auto it = books.begin(); it != books.end(); ++it)
                {
                                if(it->getId() == id)
                                {
                                                books.erase(it);
                                                return;
                                }
                                
                }
}