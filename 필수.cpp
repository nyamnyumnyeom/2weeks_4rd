#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BookManager {
private:
    vector<Book> books; // å ���

public:
    // å �߰�
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author));
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å
    void AllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) {
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    // �����Ǥ� �˻�
    void searchByTitle(const string& title) const {
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "ã�� å: " << book.title << " by " << book.author << endl;
                return;
            }
        }
        cout << "�ش� ������ å�� ã�� �� �����ϴ�." << endl;
    }

    // �۰� �˻�
    void searchByAuthor(const string& author) const {
        bool found = false;
        for (const auto& book : books) {
            if (book.author == author) {
                if (!found) {
                    cout << author << "�� å ���:" << endl;
                    found = true;
                }
                cout << "- " << book.title << endl;
            }
        }
        if (!found) {
            cout << author << "�� å�� ã�� �� �����ϴ�." << endl;
        }
    }
};

int main() {
    BookManager manager;
    int state = 0;
    while (state == 0) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl;
        cout << "2. ��� å ��� ����" << endl;
        cout << "3. ���� �˻�" << endl;
        cout << "4. �۰� �˻�" << endl;
        cout << "5. ����" << endl;
        cout << "\n���⿡ �����ϼ���. Made by ����\n" << endl;
        cout << "����: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, author;
            cout << "å ����: ";
            cin.ignore();
            getline(cin, title);
            cout << "å ����: ";
            getline(cin, author);
            manager.addBook(title, author);
        }
        else if (choice == 2) {
            manager.AllBooks();
        }
        else if (choice == 3) {
            string title;
            cout << "�˻��� å ����: ";
            cin.ignore();
            getline(cin, title);
            manager.searchByTitle(title);
        }
        else if (choice == 4) {
            string author;
            cout << "�˻��� �۰� �̸�: ";
            cin.ignore();
            getline(cin, author);
            manager.searchByAuthor(author);
        }
        else if (choice == 5) {
            cout << "���α׷��� �����մϴ�." << endl;
            state = 1;
            break;
        }
        else {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0;
}
