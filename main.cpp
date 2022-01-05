#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include "lib.h"

using namespace std;

// функция получения имени файла
string path_input() {
    string filename;
    cout << "Введите имя файла с расширением: ";
    cin >> filename;
    return filename;
}
// функция считывания содержимого файла
// в качестве типа данных используется картеж из int и string
// т.к встроенная проверка ошибок в c++ ужасна,
// будем передавать код состояния 0 - успех, 1 - произошла ошибка и строку
tuple<int, string> read_file(const string &path) {
    string line;
    ifstream fin(path);
    if (fin.is_open()) {
        while (getline(fin, line));
        fin.close();
    } else {
        std::tuple<int, string> ret = {1, "None"};
        return ret;
    }
    std::tuple<int, string> ret = {0, line};
    return ret;
}

int main() {
    bool running = true;
    //основной цикл программы
    while (running) {
        cout << "Выберите действие:\n";
        cout << "(введите цифру):\n";
        cout << "1: Сжатие Rle:\n";
        cout << "2: Восстановление Rle:\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            string path = path_input();
            string non_compress; // не сжатая строка
            int error; // код ошибки
            tie(error, non_compress) = read_file(path);
            if (error != 0) {
                cout << "Невозможно открыть / Неверное имя файла!\n";
                cout << "\n";
            } else {
                string after_compress = Rle::compress(non_compress);
                cout << "До сжатия: " << non_compress << "\n"
                     << "После сжатия: " << after_compress << "\n";
                running = false;
            }
        } else if (choice == 2) {
            string path = path_input();
            string compress_str;// сжатая строка
            int error; // код ошибки
            tie(error, compress_str) = read_file(path);
            if (error != 0) {
                cout << "Невозможно открыть / Неверное имя файла!\n";
                cout << "\n";
            } else {
                string after_decompress = Rle::decompress(compress_str);
                cout << "До восстановления: " << compress_str << "\n"
                     << "После восстановления: " << after_decompress << "\n";
                running = false;
            }
        } else {
            cout << "Неверная опция!\n";
            cout << "\n";
        }
    }
    return 0;
}
