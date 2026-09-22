#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"

class Library
{
                private:
                std::vector<Book> books;

                public:
                void addBook(const Book& book);
                void showAllBooks() const;

                Book* findBook(int id);

                void removeBook(int id);
};



#endif