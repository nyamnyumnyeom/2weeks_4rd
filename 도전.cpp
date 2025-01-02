#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    int stock;

    Book(const string& title, const string& author, int stock)
        : title(title), author(author), stock(stock) {
    }

    bool canBorrow() const {
        return stock > 0;
    }

    void borrowBook() {
        if (canBorrow()) {
            stock--;
            cout << title << "��(��) �뿩�߽��ϴ�." << endl;
        }
        else {
            cout << title << "��(��) ��� �����ϴ�." << endl;
        }
    }

    void returnBook() {
        stock++;
        cout << title << "��(��) �ݳ��߽��ϴ�." << endl;
    }
};

class BookManager {
private:
    vector<Book> books;

public:

    void addBook(const string& title, const string& author, int stock) {
        books.push_back(Book(title, author, stock));
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << " (���: " << stock << " ��)" << endl;
    }


    void AllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (const auto& book : books) {
            cout << "- " << book.title << " by " << book.author << " (���: " << book.stock << " ��)" << endl;
        }
    }


    void searchByTitle(const string& title) {
        for (auto& book : books) {
            if (book.title == title) {
                cout << "ã�� å: " << book.title << " by " << book.author << " (���: " << book.stock << " ��)" << endl;
                if (book.canBorrow()) {
                    cout << "�� å�� �뿩�Ͻðڽ��ϱ�? (1: ��, 0: �ƴϿ�): ";
                    int choice;
                    cin >> choice;
                    if (choice == 1) {
                        book.borrowBook();
                    }
                }
                else {
                    cout << "���� �뿩�� �� �����ϴ�." << endl;
                }
                return;
            }
        }
        cout << "�ش� ������ å�� ã�� �� �����ϴ�." << endl;
    }


    void searchByAuthor(const string& author) {
        bool found = false;
        for (auto& book : books) {
            if (book.author == author) {
                if (!found) {
                    cout << author << "�� å ���:" << endl;
                    found = true;
                }
                cout << "- " << book.title << " (���: " << book.stock << " ��)" << endl;
                if (book.canBorrow()) {
                    cout << "\t�� å�� �뿩�Ͻðڽ��ϱ�? (1: ��, 0: �ƴϿ�): ";
                    int choice;
                    cin >> choice;
                    if (choice == 1) {
                        book.borrowBook();
                    }
                }
                else {
                    cout << "\t���� �뿩�� �� �����ϴ�." << endl;
                }
            }
        }
        if (!found) {
            cout << author << "�� å�� ã�� �� �����ϴ�." << endl;
        }
    }


    void returnBook(const string& title) {
        for (auto& book : books) {
            if (book.title == title) {
                book.returnBook();
                return;
            }
        }
        cout << "�ݳ��� å�� ã�� �� �����ϴ�." << endl;
    }
};

int main() {
    BookManager manager;
    int state = 0;

    while (state == 0) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl;
        cout << "2. ��� å ��� ����" << endl;
        cout << "3. ���� �˻� �� �뿩" << endl;
        cout << "4. �۰� �˻� �� �뿩" << endl;
        cout << "5. å �ݳ�" << endl;
        cout << "6. ����\n" << endl;
        cout << "--�Է½� ���� ����--" << endl;
        cout << "\n����: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, author;
            int stock;
            cout << "å ����: ";
            cin.ignore();
            getline(cin, title);
            cout << "å ����: ";
            getline(cin, author);
            cout << "����� �߰��ϳ��� ?: ";
            cin >> stock;
            manager.addBook(title, author, stock);
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
            string title;
            cout << "�ݳ��� å ����: ";
            cin.ignore();
            getline(cin, title);
            manager.returnBook(title);
        }
        else if (choice == 6) {
            cout << "���α׷��� �����մϴ�." << endl;
            state = 1;
        }
        else {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0;
}
