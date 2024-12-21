#include <iostream>
#include <string>

class Publication {
protected:
    std::string title;
    float price;

public:
    virtual void getData() {
        std::cout << "Enter a name: ";
        std::getline(std::cin, title);
        std::cout << "enter a price: ";
        std::cin >> price;
        std::cin.ignore();
    }

    virtual void putData() const {
        std::cout << "name: " << title << std::endl;
        std::cout << "price: " << price << std::endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    void getData() override {
        Publication::getData();
        std::cout << "enter numbers of pages: ";
        std::cin >> pageCount;
        std::cin.ignore();
    }

    void putData() const override {
        Publication::putData();
        std::cout << "pages: " << pageCount << std::endl;
    }
};

class Tape : public Publication {
private:
    float playTime;

public:
    void getData() override {
        Publication::getData();
        std::cout << "Enter recording time (in minutes): ";
        std::cin >> playTime;
        std::cin.ignore();
    }

    void putData() const override {
        Publication::putData();
        std::cout << "Recording time (minutes): " << playTime << std::endl;
    }
};

int main() {
    Book book;
    Tape tape;

    std::cout << "Enter information for the book:\n";
    book.getData();
    std::cout << "\nEnter data for audio recording:\n";
    tape.getData();

    std::cout << "\nBook details:\n";
    book.putData();
    std::cout << "\nAudio recording data:\n";
    tape.putData();

    return 0;
}