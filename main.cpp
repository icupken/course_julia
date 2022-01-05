#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include "lib.h"

using namespace std;

string path_input() {
    string filename;
    cout << "Введите имя файла с расширением: ";
    cin >> filename;
    return filename;
}

tuple<int, string> read_file(const string &path) {
    string line;
    ifstream fin(path);
    if (fin.is_open()) {
        while (getline(fin, line));
        fin.close();
    } else {
        std::tuple<int, string> ret = {-1, "None"};
        return ret;
    }
    std::tuple<int, string> ret = {0, line};
    return ret;
}

int main() {
    bool running = true;
    while (running) {
        cout << "Выберите действие:\n";
        cout << "(введите цифру):\n";
        cout << "1: Сжатие Rle:\n";
        cout << "2: Восстановление Rle:\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            string path = path_input();
            string non_compress;
            int error;
            tie(error, non_compress) = read_file(path);
            if (error != 0) {
                cout << "Невозможно открыть / Неверное имя файла!\n";
                cout << "\n";
            } else {
                string after_compress = Rle::compress(non_compress);
                cout << "До сжатия: " << non_compress << "\n" << "После сжатия: " << after_compress << "\n";
                running = false;
            }
        } else if (choice == 2) {
            string path = path_input();
            string compress_str;
            int error;
            tie(error, compress_str) = read_file(path);
            if (error != 0) {
                cout << "Невозможно открыть / Неверное имя файла!\n";
                cout << "\n";
            } else {
                string after_decompress = Rle::decompress(compress_str);
                cout << "До восстановления: " << compress_str << "\n" << "После восстановления: " << after_decompress
                     << "\n";
                running = false;
            }
        } else {
            cout << "Неверная опция!\n";
            cout << "\n";
        }
    }
    return 0;
}
