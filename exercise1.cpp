#include <iostream>
#include <ctime>
#include <list>
#include <utility>
#include <map>
#include <iterator>

/*
 * 1. Greg wrote an app for himself in order to track the books he borrowed from a library. He kept book information such as author_,
 * title_. currentDate_ and returnDate.
Using std::list:
- Store the borrowed books information (at least 5 entries);
- Remove the returned books from the list (returnDate_ > currentDate_);
- Add bookRating_ (1 to 5 stars) as information that the app tracks;
- His friends found out about the app and want to use it as well. Using std::map store data to keep track of every individual and their borrowed books list;
- Display all the books (from every user) that have a 5 star rating

 */

class Book{
private:
    std::string author_;
    time_t currDate_ = time(0);
    tm *returnDate, *current = localtime(&currDate_);
    std::string title_;
    char *cd = ctime(&currDate_), *rd;
    int bookRating_;
public:
    Book(std::string name, std::string title, time_t returnDate){
        this->author_ = std::move(name);
        this->title_ = std::move(title);
        this->returnDate = localtime(&returnDate);
        rd = ctime(&returnDate);
    }

    Book(std::string name, std::string title){
        this->author_ = std::move(name);
        this->title_ = std::move(title);
        this->returnDate = localtime(&currDate_);
        rd = ctime(&currDate_);
    }

    void printBook(){
        std::cout<<"Author: "<<this->author_<<std::endl;
        std::cout<<"Title: "<<this->title_<<std::endl;
        std::cout<<"Current date: "<<cd<<std::endl;
        strftime(rd, 50, "%d/%m/%Y", returnDate);
        std::cout<<"Return date: "<<rd<<std::endl;
    }

    void setReturnDate(char sign, int year, int month=0, int day=0){
        if(sign == '+'){
            this->returnDate->tm_year = this->returnDate->tm_year + year;
            this->returnDate->tm_mon = this->returnDate->tm_mon + month;
            this->returnDate->tm_mday = this->returnDate->tm_mday + day;
        }
        else
            if(sign == '-'){
                this->returnDate->tm_year = this->returnDate->tm_year - year;
                this->returnDate->tm_mon = 1 + this->returnDate->tm_mon - month;
                this->returnDate->tm_mday = this->returnDate->tm_mday - day;
            }

    }

    time_t getReturnDate(){
        return mktime(this->returnDate);
    }

    time_t getCurrDate(){
        return this->currDate_;
    }

    void setBookRating(int rating){
        if(rating >=1 && rating <=5){
            this->bookRating_ = rating;
        }
    }

    int getBookRating(){
        return this->bookRating_;
    }

    std::string gettitle(){
        return this->title_;
    }

};

void display5starBooks(std::map<std::string,std::list<Book>> individuals){
    for(auto it = individuals.begin(); it!=individuals.end();++it){
        std::cout<<"Name: "<<it->first;
        std::cout<<std::endl;
        std::list<Book> books = it->second;
        for(auto x: books){
            if(x.getBookRating()==5) {
                x.printBook();
                std::cout << std::endl;
            }
        }
    }
}

bool operator == (Book p1, Book p2)
{
    if(p1.gettitle()==p2.gettitle())
    return true;
    else
    return false;
}

void removereturnedbooks(std::map<std::string,std::list<Book>> &individuals){
    for(auto it = individuals.begin(); it!=individuals.end();++it){
        std::list<Book> books(it->second);
        for(auto x: books){
            if(difftime(x.getReturnDate(),x.getCurrDate()) < 0 ) {
                std::cout<<"Here";
                books.remove(x);
            }
        }
        it->second.assign(books.begin(),books.end());
    }
}

int main() {
    std::list<Book> books;
    std::string borrower;
    std::map<std::string,std::list<Book>> individuals;
    Book b1 = Book("Costica", "Neinvinsu", time(nullptr));
    Book b2 = Book("Milica", "Jijicu");
    Book b3 = Book("Daniel Kahnemann", "Thinking Fast and Slow");
    Book b4 = Book("Spinoza", "Etica");
    Book b5 = Book("Liviu Rebreanu", "Padurea Spanzuratilor");
    Book b6 = Book("Bertrand Russell", "In cautarea fericirii");
    Book b7 = Book("Brene Brown", "Dare Greatly");
    Book b8 = Book("Mircea Eliade", "Istoria ideilor si credintelor religioase Vol1");
    Book b9 = Book("Mircea Eliade", "Istoria ideilor si credintelor religioase Vol2");
    Book b10 = Book("Mircea Eliade", "Istoria ideilor si credintelor religioase Vol3");
    Book b11 = Book("Mircea Eliade", "Istoria ideilor si credintelor religioase Vol4");
    Book b12 = Book("Immanuel Kant", "Critica Ratiunii Pure");
    b1.printBook();
    b1.setBookRating(1);
    b2.setBookRating(2);
    b3.setBookRating(5);
    b4.setBookRating(3);
    b5.setBookRating(5);
    b6.setBookRating(5);
    b7.setBookRating(5);
    b8.setBookRating(5);
    b9.setBookRating(5);
    b10.setBookRating(5);
    b11.setBookRating(5);
    b12.setBookRating(5);
    books.push_back(b1);
    books.push_back(b2);
    borrower = "Mihai";
    if(individuals.find(borrower) == individuals.end()){
            individuals[borrower] = books;
        }
    books.clear();
    books.push_back(b3);
    books.push_back(b4);
    books.push_back(b5);
    books.push_back(b6);
    borrower = "Greg";
    if(individuals.find(borrower) == individuals.end()){
        individuals[borrower] = books;
    }
    books.clear();
    books.push_back(b6);
    books.push_back(b7);
    books.push_back(b8);
    books.push_back(b9);
    borrower = "Anna";
    if(individuals.find(borrower) == individuals.end()){
        individuals[borrower] = books;
    }
    books.clear();
    books.push_back(b10);
    books.push_back(b11);
    books.push_back(b12);
    borrower = "Ela";
    if(individuals.find(borrower) == individuals.end()){
        individuals[borrower] = books;
    }
    b2.setReturnDate('+', 1);
    b2.printBook();

    removereturnedbooks(individuals);
    display5starBooks(individuals);


    return 0;
}
