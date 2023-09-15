#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <chrono>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "function_2.h"

using namespace std;

using namespace std::chrono;

const int n = 100000;

struct table {
    std::string name;
    double time;
};


int main(){
    srand(45);
    vector <int> a(n);
    table answers[4];
    for (int i = 0; i < n; i++) {
        a[i] = (int)rand() % 10000000;
    }
    auto t_1 = steady_clock::now();
    has_duplicates(a);
    auto t_2 = steady_clock::now();
    answers[0].name = "Быстрый has_duplicates ";
    answers[0].time = duration<double>(t_2 - t_1).count();

    t_1 = steady_clock::now();
    has_duplicates_slow(a);
    t_2 = steady_clock::now();
    answers[1].name = "Медленный has_duplicates ";
    answers[1].time = duration<double>(t_2 - t_1).count();

    t_1 = steady_clock::now();
    get_duplicates(a);
    t_2 = steady_clock::now();
    answers[2].name = "Быстрый get_duplicates ";
    answers[2].time = duration<double>(t_2 - t_1).count();

    t_1 = steady_clock::now();
    get_duplicates_slow(a);
    t_2 = steady_clock::now();
    answers[3].name = "Медленный get_duplicates ";
    answers[3].time = duration<double>(t_2 - t_1).count();

    cout << answers[0].name << answers[0].time << endl;
    cout << answers[1].name << answers[1].time << endl;
    cout << answers[2].name << answers[2].time << endl;
    cout << answers[3].name << answers[3].time << endl;
}