#include <iostream>
using namespace std;

class LibraryItem {
public:
    virtual void display() = 0;
    virtual ~LibraryItem() {}
};
class Book : public LibraryItem {
public:
    const char* title;
    const char* author;
    int pages;

    Book(const char* t, const char* a, int p) : title(t), author(a), pages(p) {}

    void display() override {
        cout << "[Book] " << title << " | Pages: " << pages << endl;
    }
};
class Newspaper : public LibraryItem {
public:
    const char* name;
    const char* date;
    const char* edition;

    Newspaper(const char* n, const char* d, const char* e) : name(n), date(d), edition(e) {}

    void display() override {
        cout << "[News] " << name << " | Edition: " << edition << endl;
    }
};

class Library {
    Book* books[5];
    Newspaper* news[5];
    int bCount = 0, nCount = 0;

public:
    void addBook(Book& b) { books[bCount++] = &b; }
    void addNewspaper(Newspaper& n) { news[nCount++] = &n; }

    void displayCollection() {
        for (int i = 0; i < bCount; i++) books[i]->display();
        for (int i = 0; i < nCount; i++) news[i]->display();
    }

    void sortBooks() { 
        for (int i = 0; i < bCount - 1; i++)
            for (int j = 0; j < bCount - i - 1; j++)
                if (books[j]->pages > books[j + 1]->pages)
                    swap(books[j], books[j + 1]);
    }
    Book* search(const char* t) {
        for (int i = 0; i < bCount; i++)
            if (books[i]->title == t) return books[i];
        return nullptr;
    }
};

int main() {
    Book b1("Catcher","Salinger",277), b2("Mockingbird","Lee",324);
    Newspaper n1("Post","2024","Morning"), n2("Times","2024","Weekend");

    Library lib;
    lib.addBook(b1); lib.addBook(b2);
    lib.addNewspaper(n1); lib.addNewspaper(n2);

    cout << "Before Sorting"<<endl;
    lib.displayCollection();

    lib.sortBooks();
    cout << "nAfter Sorting Books by Pages"<<endl;
    lib.displayCollection();

    return 0;
}