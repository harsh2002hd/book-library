#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    int id;
};

class User {
public:
    string name;
    int id;
};

vector<Book> books;
vector<User> users;

void addBook() {
    Book book;
    cout << "Enter book title: ";
    getline(cin, book.title);
    cout << "Enter book author: ";
    getline(cin, book.author);
    book.id = books.size() + 1;
    books.push_back(book);
    cout << "Book added successfully!" << endl;
}

void deleteBook() {
    int id;
    cout << "Enter book id: ";
    cin >> id;
    for (int i = 0; i < books.size(); i++) {
        if (books[i].id == id) {
            books.erase(books.begin() + i);
            cout << "Book deleted successfully!" << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void updateBook() {
    int id;
    cout << "Enter book id: ";
    cin >> id;
    for (int i = 0; i < books.size(); i++) {
        if (books[i].id == id) {
            cout << "Enter new title (or press Enter to keep current title): ";
            getline(cin, books[i].title);
            cout << "Enter new author (or press Enter to keep current author): ";
            getline(cin, books[i].author);
            cout << "Book updated successfully!" << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void addUser() {
    User user;
    cout << "Enter user name: ";
    getline(cin, user.name);
    user.id = users.size() + 1;
    users.push_back(user);
    cout << "User added successfully!" << endl;
}

void deleteUser() {
    int id;
    cout << "Enter user id: ";
    cin >> id;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].id == id) {
            users.erase(users.begin() + i);
            cout << "User deleted successfully!" << endl;
            return;
        }
    }
    cout << "User not found." << endl;
}

void displayMenu() {
    cout << "Library Management System\n"
         << "1. Add Book\n"
         << "2. Delete Book\n"
         << "3. Update Book\n"
         << "4. Add User\n"
         << "5. Delete User\n"
         << "6. Quit\n"
         << "Enter your choice (1,2,3,4,5 and 6 only): ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                deleteBook();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                addUser();
                break;
            case 5:
                deleteUser();
                break;
            case 6:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

   
