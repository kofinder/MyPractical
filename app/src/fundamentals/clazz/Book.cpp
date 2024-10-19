#include <iostream>
using namespace std;


class Book {
    public:
        string title;
        string author;
        int* rates;
        int rateCounter;

        Book(string _title, string _author) {
            title = _title;
            author = _author;
            rateCounter = 2;
            rates = new int[rateCounter];
            rates[0] = 10;
            rates[1] = 440;
        }

        ~Book() {
            delete[] rates;
            rates = nullptr;
        }

        //copy constructor
        Book(const Book& original) {
            title = original.title;
            author = original.author;
            rateCounter = original.rateCounter;
            rates = new int[rateCounter];
            for(int i = 0; i< rateCounter; i++) {
                rates[i] = original.rates[i];
            }
        }

        // assigment operator
        Book& operator =(const Book& original) {
            title = original.title;
            author = original.author;
            rateCounter = original.rateCounter;
            rates = new int[rateCounter];
            for(int i = 0; i< rateCounter; i++) {
                rates[i] = original.rates[i];
            }

            return *this;
        }

};

void printBook(Book book) {
    cout << "Tittle =>" << book.title <<endl;
    cout << "Author ===>" << book.author <<endl;
    int sum = 0;

    for(int i = 0; i< book.rateCounter; i++) {
        sum+=book.rates[i];
    }

    cout << "Avg rate ==>" << sum/book.rateCounter << endl;
}