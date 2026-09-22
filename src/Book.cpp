#include "../include/Book.h"
#include <iostream>

Book::Book(int id, const std::string& title, const std::string& author)
{


                this -> id = id;
                this -> title = title;
                this -> author = author;

}

void Book::showBook() const
{

                std::cout << "ID: " << id << std::endl;
                std::cout << "Title: " << title << std::endl;
                std::cout << "Author: " << author << std::endl;

}

int Book::getId() const
{
                return id;
}

std::string Book::getTitle() const 
{
                return title;
}