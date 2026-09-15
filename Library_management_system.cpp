#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    bool isBorrowed;

    Book(string t, string a) {
        title = t;
        author = a;
        isBorrowed = false;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author));
        cout << "Book \"" << title << "\" added.\n";
    }

    void removeBook(const string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                books.erase(it);
                cout << "Book \"" << title << "\" removed.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void borrowBook(const string& title) {
        for (auto& b : books) {
            if (b.title == title) {
                if (b.isBorrowed) {
                    cout << "Book \"" << title << "\" is already borrowed.\n";
                } else {
                    b.isBorrowed = true;
                    cout << "\"" << title << "\" borrowed successfully.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(const string& title) {
        for (auto& b : books) {
            if (b.title == title) {
                if (!b.isBorrowed) {
                    cout << "Book was not borrowed.\n";
                } else {
                    b.isBorrowed = false;
                    cout << "\"" << title << "\" returned successfully.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void searchBook(const string& query) {
        bool found = false;
        for (const auto& b : books) {
            if (b.title.find(query) != string::npos || b.author.find(query) != string::npos) {
                cout << "Title: " << b.title << " | Author: " << b.author 
                     << " | Status: " << (b.isBorrowed ? "Borrowed" : "Available") << "\n";
                found = true;
            }
        }
        if (!found) cout << "No matching books found.\n";
    }

    void displayAll() const {
        if (books.empty()) {
            cout << "No books in library.\n";
            return;
        }
        for (const auto& b : books) {
            cout << "Title: " << b.title << " | Author: " << b.author 
                 << " | Status: " << (b.isBorrowed ? "Borrowed" : "Available") << "\n";
        }
    }
};

int main() {
    Library lib;
    int choice = 0;

    while (choice != 7) {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book\n";
        cout << "6. Display All Books\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            string title, author;
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            lib.addBook(title, author);
        } else if (choice == 2) {
            string title;
            cout << "Enter book title to remove: ";
            cin.ignore();
            getline(cin, title);
            lib.removeBook(title);
        } else if (choice == 3) {
            string title;
            cout << "Enter book title to borrow: ";
            cin.ignore();
            getline(cin, title);
            lib.borrowBook(title);
        } else if (choice == 4) {
            string title;
            cout << "Enter book title to return: ";
            cin.ignore();
            getline(cin, title);
            lib.returnBook(title);
        } else if (choice == 5) {
            string query;
            cout << "Enter title or author to search: ";
            cin.ignore();
            getline(cin, query);
            lib.searchBook(query);
        } else if (choice == 6) {
            lib.displayAll();
        } else if (choice == 7) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}