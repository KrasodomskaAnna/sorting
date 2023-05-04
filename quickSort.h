#ifndef SORTING_QUICKSORT_H
#define SORTING_QUICKSORT_H

#include "vector.h"

int partition(Vector* table, int l, int r) {
    Vector pivot=table[l];
    int l_p = l - 1;
    int r_p = r + 1;
    while (true) {
        while (true) {
            l_p++;
            if (table[l_p] >= pivot) break;
        }
        while (true) {
            r_p--;
            if (table[r_p] <= pivot) break;
        }
        if (l_p < r_p) {
            std::swap(table[l_p], table[r_p]);
        }
        else {
            return r_p;
        }
    }
}

void quickSort(Vector* table, int l, int r) {
    if (l < r) {
        int q = partition(table, l, r);
        quickSort(table, l, q);
        quickSort(table, q + 1, r);
    }
}

#endif //SORTING_QUICKSORT_H
