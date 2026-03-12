#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    virtual void display() = 0;
};

class Book : public Item {
private:
    string title;
    string author;
    int pages;

public:
    Book(string t = "", string a = "", int p = 0) {
        title = t;
        author = a;
        pages = p;
    }

    void display() {
        cout << "Book: " << title << ", Author: " << author << ", Pages: " << pages << endl;
    }

    string getTitle() {
        return title;
    }
    
    int getPages() {
        return pages;
    }
};

class Newspaper : public Item {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(string n = "", string d = "", string e = "") {
        name = n;
        date = d;
        edition = e;
    }

    void display() {
        cout << "Newspaper: " << name << ", Date: " << date << ", Edition: " << edition << endl;
    }

    string getName() {
        return name;
    }
   
    string getEdition() { 
        return edition;
    }
};

class Library {
private:
    Book books[50];
    Newspaper newspapers[50];
    int bookCount;
    int newspaperCount;

public:
    Library() {
        bookCount = 0;
        newspaperCount = 0;
    }

    void addBook(Book b) {
        books[bookCount] = b;
        bookCount++;
    }

    void addNewspaper(Newspaper n) {
        newspapers[newspaperCount] = n;
        newspaperCount++;
    }

    void displayCollection() {
        cout << "Books:" << endl;
        for (int i = 0; i < bookCount; i++)
            books[i].display();

        cout << "Newspapers:" << endl;
        for (int i = 0; i < newspaperCount; i++)
            newspapers[i].display();
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = i + 1; j < bookCount; j++) {
                if (books[i].getPages() > books[j].getPages()) {
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = i + 1; j < newspaperCount; j++) {
                if (newspapers[i].getEdition() > newspapers[j].getEdition()) {
                    Newspaper temp = newspapers[i];
                    newspapers[i] = newspapers[j];
                    newspapers[j] = temp;
                }
            }
        }
    }

    template <typename T>
    T* search(T arr[], int size, string key, string(T::* getter)()) {
        for (int i = 0; i < size; i++) {
            if ((arr[i].*getter)() == key)
                return &arr[i];
        }
        return nullptr;
    }

    Book* searchBookByTitle(string title) {
        return search(books, bookCount, title, &Book::getTitle);
    }

    Newspaper* searchNewspaperByName(string name) {
        return search(newspapers, newspaperCount, name, &Newspaper::getName);
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library library;
    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:" << endl;
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "After Sorting:" << endl;
    library.displayCollection();

    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "Found Book:" << endl;
        foundBook->display();
    }
    else {
        cout << "Book not found." << endl;
    }

    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "Found Newspaper:" << endl;
        foundNewspaper->display();
    }
    else {
        cout << "Newspaper not found." << endl;
    }

    return 0;
}