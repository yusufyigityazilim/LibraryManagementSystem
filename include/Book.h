#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
                private:
                int id;
                std::string title;
                std::string author;

                public:
                Book(int id, const std::string& title, const std::string& author);

                void showBook() const;

                int getId() const;

                std::string getTitle() const;
};

#endif