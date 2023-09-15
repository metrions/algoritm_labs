#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include "function_2.h"

using namespace std;


void print_set(set <int> &t){
    for (auto i : t) cout << i << " ";
    cout << endl;
}


int main(){
    srand(38);
    int a[1000];
    vector<int> test_1{1, 2, 3, 22, 5, 33, 7, 42, 42, 10, 11, 12, 13, 14, 14, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38};
    vector<int> test_2{1, 1, 1, 1, 1, 1, 1};
    vector<int> test_3{1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < 1000; i++) {
        a[i] = (int)rand() % 1000;
    }
    cout << has_dublicates_slow(test_1) << endl;
    set <int> q = get_dublicates_slow(test_1);
    cout << "1 test: set ";
    print_set(q);
    cout << has_dublicates_slow(test_2) << endl;
    q = get_dublicates_slow(test_2);
    cout << "2 test: set ";
    print_set(q);
}