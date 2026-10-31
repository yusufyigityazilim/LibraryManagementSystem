#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"

class Library
{
                private:
                std::vector<Book> books;

                public:
                bool addBook(const Book& book);
                void showAllBooks() const;

                Book* findBook(int id);

                bool removeBook(int id);

                void saveToFile() const;
                void loadFromFile();
};



#endif