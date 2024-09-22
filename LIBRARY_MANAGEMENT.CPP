// PROJECT : LIBRARY MANAGEMENT SYSTEM
// NAME : WAHAJ ALI 

#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;
// class for book info
class Book
{
private:
    string title;
    string author;
    bool available = true;

public:
    Book(){}

    void setTitle(const string &t)
    {
        title = t;
    }

    void setAuthor(const string &a)
    {
        author = a;
    }

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    bool isAvailable() const
    {
        return available;
    }

    void borrow()
    {
        available = false;
    }

    void returnBook()
    {
        available = true;
    }
};

// class for functions of library
class Library
{
private:
    Book books[MAX_BOOKS];
    int numBooks = 0;

public:
    Library(){}

    void addBook()
    {
        if (numBooks < MAX_BOOKS)
        {
            string title, author;
            cout << "Enter title of the book: ";
            getline(cin, title);
            cout << "Enter author of the book: ";
            getline(cin, author);
            books[numBooks].setTitle(title);
            books[numBooks].setAuthor(author);
            numBooks++;
            cout << "Book added successfully.\n";
        }
        else
        {
            cout << "Library is full, cannot add more books.\n";
        }
    }

    void displayBooks() const
    {
        cout << "\nLibrary Catalog:\n";
        for (int i = 0; i < numBooks; ++i)
        {
            cout << "Title: " << books[i].getTitle() << ", Author: " << books[i].getAuthor();
            if (books[i].isAvailable())
                cout << " (Available)\n";
            else
                cout << " (Not Available)\n";
        }
    }

    int findBook(const string &title) const
    {
        for (int i = 0; i < numBooks; ++i)
        {
            if (books[i].getTitle() == title)
                return i;
        }
        return -1;
    }

    void borrowBook(const string &title)
    {
        int index = findBook(title);
        if (index != -1)
        {
            if (books[index].isAvailable())
            {
                books[index].borrow();
                cout << "Book borrowed successfully.\n";
            }
            else
            {
                cout << "Sorry, this book is not available.\n";
            }
        }
        else
        {
            cout << "Book not found.\n";
        }
    }

    void returnBook(const string &title)
    {
        int index = findBook(title);
        if (index != -1)
        {
            books[index].returnBook();
            cout << "Book returned successfully.\n";
        }
        else
        {
            cout << "Book not found.\n";
        }
    }
};

int main()
{   
    Library library;
    int choice;

    do
    {
        cout << "\n______________Library Management System_________________\n";
        cout << "\n1. Add a book\n";
        cout << "2. Display available books\n";
        cout << "3. Borrow a book\n";
        cout << "4. Return a book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input

        switch (choice)
        {
        case 1:
            library.addBook();
            break;
        
        case 2:
            library.displayBooks();
            break;
        
        case 3:
        {
            string title;
            cout << "Enter title of the book to borrow: ";
            getline(cin, title);
            library.borrowBook(title);
        }
        break;
        
        case 4:
        {
            string title;
            cout << "Enter title of the book to return: ";
            getline(cin, title);
            library.returnBook(title);
        }
        break;
        
        case 5:
            cout << "Exiting program.\n";
            break;
        
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}