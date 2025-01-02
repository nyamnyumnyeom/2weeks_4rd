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
            cout << title << "을(를) 대여했습니다." << endl;
        }
        else {
            cout << title << "은(는) 재고가 없습니다." << endl;
        }
    }

    void returnBook() {
        stock++;
        cout << title << "을(를) 반납했습니다." << endl;
    }
};

class BookManager {
private:
    vector<Book> books;

public:

    void addBook(const string& title, const string& author, int stock) {
        books.push_back(Book(title, author, stock));
        cout << "책이 추가되었습니다: " << title << " by " << author << " (재고: " << stock << " 권)" << endl;
    }


    void AllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (const auto& book : books) {
            cout << "- " << book.title << " by " << book.author << " (재고: " << book.stock << " 권)" << endl;
        }
    }


    void searchByTitle(const string& title) {
        for (auto& book : books) {
            if (book.title == title) {
                cout << "찾은 책: " << book.title << " by " << book.author << " (재고: " << book.stock << " 권)" << endl;
                if (book.canBorrow()) {
                    cout << "이 책을 대여하시겠습니까? (1: 예, 0: 아니요): ";
                    int choice;
                    cin >> choice;
                    if (choice == 1) {
                        book.borrowBook();
                    }
                }
                else {
                    cout << "현재 대여할 수 없습니다." << endl;
                }
                return;
            }
        }
        cout << "해당 제목의 책을 찾을 수 없습니다." << endl;
    }


    void searchByAuthor(const string& author) {
        bool found = false;
        for (auto& book : books) {
            if (book.author == author) {
                if (!found) {
                    cout << author << "의 책 목록:" << endl;
                    found = true;
                }
                cout << "- " << book.title << " (재고: " << book.stock << " 권)" << endl;
                if (book.canBorrow()) {
                    cout << "\t이 책을 대여하시겠습니까? (1: 예, 0: 아니요): ";
                    int choice;
                    cin >> choice;
                    if (choice == 1) {
                        book.borrowBook();
                    }
                }
                else {
                    cout << "\t현재 대여할 수 없습니다." << endl;
                }
            }
        }
        if (!found) {
            cout << author << "의 책을 찾을 수 없습니다." << endl;
        }
    }


    void returnBook(const string& title) {
        for (auto& book : books) {
            if (book.title == title) {
                book.returnBook();
                return;
            }
        }
        cout << "반납할 책을 찾을 수 없습니다." << endl;
    }
};

int main() {
    BookManager manager;
    int state = 0;

    while (state == 0) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;
        cout << "2. 모든 책 목록 보기" << endl;
        cout << "3. 제목 검색 및 대여" << endl;
        cout << "4. 작가 검색 및 대여" << endl;
        cout << "5. 책 반납" << endl;
        cout << "6. 종료\n" << endl;
        cout << "--입력시 띄어쓰기 주의--" << endl;
        cout << "\n선택: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, author;
            int stock;
            cout << "책 제목: ";
            cin.ignore();
            getline(cin, title);
            cout << "책 저자: ";
            getline(cin, author);
            cout << "몇권을 추가하나요 ?: ";
            cin >> stock;
            manager.addBook(title, author, stock);
        }
        else if (choice == 2) {
            manager.AllBooks();
        }
        else if (choice == 3) {
            string title;
            cout << "검색할 책 제목: ";
            cin.ignore();
            getline(cin, title);
            manager.searchByTitle(title);
        }
        else if (choice == 4) {
            string author;
            cout << "검색할 작가 이름: ";
            cin.ignore();
            getline(cin, author);
            manager.searchByAuthor(author);
        }
        else if (choice == 5) {
            string title;
            cout << "반납할 책 제목: ";
            cin.ignore();
            getline(cin, title);
            manager.returnBook(title);
        }
        else if (choice == 6) {
            cout << "프로그램을 종료합니다." << endl;
            state = 1;
        }
        else {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}
