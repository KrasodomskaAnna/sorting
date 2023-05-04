#include <iostream>
#include <string>
#include "quickSort.h"


int main() {
    Vector* list;
    int n;
    std::cin >> n;

    list = new Vector[n];

    char znak;
    std::cin.get(znak);

    for (int i = 0; i < n; i++) {
        bool endOfNumber = false;
        while (!endOfNumber) {
            std::cin.get(znak);
            if (znak == '\n' || znak == '\r') {
                endOfNumber = true;
                continue;
            }
            int liczba = znak - '0';
            list[i].push_back(znak - '0');
        }
    }

    // sortowanie
    quickSort(list, 0, n - 1);

    // print
    for (int i = 0; i < n; i++) {
        list[i].print();
        if (i + 1 != n) std::cout << std::endl;
    }

    //delete[] list;

    return 0;
}