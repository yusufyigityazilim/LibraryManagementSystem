#include "../include/Library.h"
#include <iostream>
#include <fstream>
#include <sstream>

bool Library::addBook(const Book& book)
{
     for(const Book& existingBook : books)
     {
          if(existingBook.getId() == book.getId())
          {
               return false;
          }
     }

     books.push_back(book);
     return true;
}


void Library::showAllBooks() const
{
          if(books.empty())
          {
               std::cout << "There are no books in the library.\n";
               return;
          }
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

bool Library::removeBook(int id)
{
                for(auto it = books.begin(); it != books.end(); ++it)
                {
                                if(it->getId() == id)
                                {
                                           books.erase(it);
                                           return true;
                                }
                              
                }
               return false;
}

void Library::saveToFile() const
{
                std::ofstream file("books.txt");

                if(!file.is_open())
                {
                    std::cerr << "Error: Could not open books.txt!\n";
                    return;
                }

                for (const Book& book : books)
                {
                                file << book.getId() << "|"
                                     << book.getTitle() << "|"
                                     << book.getAuthor() << "\n";
                }

                file.close();
}

void Library::loadFromFile()
{
                std::ifstream file("books.txt");

                if(!file.is_open())
                {
                      std::cout << "No existing book file found. Starting with an empty library.\n";         
                      return;
                }

                std::string line;

                while(std::getline(file, line))
                {
                                std::stringstream ss(line);

                                std::string idText;
                                std::string title;
                                std::string author;

                                std::getline(ss,idText,'|');
                                std::getline(ss,title,'|');
                                std::getline(ss,author,'|');

                                if(idText.empty() || title.empty() || author.empty())
                                {
                                   std::cerr << "Invalid book record found!\n";
                                   continue;
                                }
                              
                                int id;
                                try{

                                id = std::stoi(idText);

                                }
                                catch(const std::exception& e)
                                {
                                   std::cerr << "Error loading book: " << e.what() << "\n";
                                   continue;
                                }
                                Book book(id,title,author);

                                books.push_back(book); 
                }

                file.close();
}