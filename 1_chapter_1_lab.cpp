#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <chrono>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std::chrono;

const int n = 100000;
const int m = 100000;

struct table {
    std::string name;
    double time_insert;
    double time_push_back;
    double time_find;
};

double push_time(std::list<int>& q, int a[n]) {
    auto t_1 = steady_clock::now();
    for (int i = 0; i < n; i++) {
        q.push_back(a[i]);
    }
    auto t_2 = steady_clock::now();
    q.clear();
    return duration<double>(t_2 - t_1).count();
}

double insert_time(std::list<int>& q, int a[n]) {
    auto t_1 = steady_clock::now();
    for (int i = 0; i < n; i++) {
        q.insert(q.begin(), a[i]);
    }
    auto t_2 = steady_clock::now();
    q.clear();
    return duration<double>(t_2 - t_1).count();
}

double push_time(std::vector<int>& q, int a[n]) {
    auto t_1 = steady_clock::now();
    for (int i = 0; i < n; i++) {
        q.push_back(a[i]);
    }
    auto t_2 = steady_clock::now();
    q.clear();
    return duration<double>(t_2 - t_1).count();
}

double insert_time(std::vector<int>& q, int a[n]) {
    auto t_1 = steady_clock::now();
    for (int i = 0; i < n; i++) {
        q.insert(q.begin(), a[i]);
    }
    auto t_2 = steady_clock::now();
    q.clear();
    return duration<double>(t_2 - t_1).count();
}

double insert_time(std::set<int>& q, int a[n]) {
    auto t_1 = steady_clock::now();
    for (int i = 0; i < n; i++) {
        q.insert(a[i]);
    }
    auto t_2 = steady_clock::now();
    q.clear();
    return duration<double>(t_2 - t_1).count();
}

double insert_time(std::unordered_set<int>& q, int a[n]) {
    auto t_1 = steady_clock::now();
    for (int i = 0; i < n; i++) {
        q.insert(a[i]);
    }
    auto t_2 = steady_clock::now();
    q.clear();
    return duration<double>(t_2 - t_1).count();
}

double find_time(std::list<int>& q, int poisk[m]) {
    auto t_1 = steady_clock::now();
    for (int i = 0; i < m; i++) {
        std::find(q.begin(), q.end(), poisk[i]);
    }
    auto t_2 = steady_clock::now();
    return duration<double>(t_2 - t_1).count();
}

double find_time(std::vector<int>& q, int poisk[m]) {
    auto t_1 = steady_clock::now();
    for (int i = 0; i < m; i++) {
        std::find(q.begin(), q.end(), poisk[i]);
    }
    auto t_2 = steady_clock::now();
    return duration<double>(t_2 - t_1).count();
}

double find_time(std::set<int>& q, int poisk[m]) {
    auto t_1 = steady_clock::now();
    for (int i = 0; i < m; i++) {
        q.find(poisk[m]);
    }
    auto t_2 = steady_clock::now();
    return duration<double>(t_2 - t_1).count();
}

double find_time(std::unordered_set<int>& q, int poisk[m]) {
    auto t_1 = steady_clock::now();
    for (int i = 0; i < m; i++) {
        q.find(poisk[m]);
    }
    auto t_2 = steady_clock::now();
    return duration<double>(t_2 - t_1).count();
}

int main() {
    srand(23);
    std::list<int> test_list{};
    std::set<int> test_set{};
    std::vector<int> test_vector{};
    std::unordered_set<int> test_un_set{};

    table tab[4];
    tab[0].name = "list";
    tab[1].name = "vector";
    tab[2].name = "set";
    tab[3].name = "unordered_set";

    int a[n];
    int k[m];
    for (int i = 0; i < n; i++) {
        a[i] = (int)rand();
    }
    for (int i = 0; i < m; i++) {
        k[i] = (int)rand();
    }

    tab[0].time_push_back = push_time(test_list, a);
    tab[0].time_insert = insert_time(test_list, a);

    tab[1].time_push_back = push_time(test_vector, a);
    tab[1].time_insert = insert_time(test_vector, a);

    tab[2].time_insert = insert_time(test_set, a);

    tab[3].time_insert = insert_time(test_un_set, a);

    tab[0].time_find = find_time(test_list, k);
    tab[1].time_find = find_time(test_vector, k);
    tab[2].time_find = find_time(test_set, k);
    tab[3].time_find = find_time(test_un_set, k);

    std::cout << "Результаты добавления в контейнер:" << std::endl;
    std::cout << "List insert - " << tab[0].time_insert<< " push_back - " <<tab[0].time_push_back << std::endl;
    std::cout << "Vector insert - " << tab[1].time_insert << " push_back - " << tab[1].time_push_back << std::endl;
    std::cout << "Set insert - " << tab[2].time_insert << std::endl;
    std::cout << "Un_set insert - " << tab[2].time_insert << std::endl;
    std::cout << std::endl;
    std::cout << "Результаты поиска" << std::endl;
    std::cout << "List find - " << tab[0].time_find << std::endl;
    std::cout << "Vector find - " << tab[1].time_find << std::endl;
    std::cout << "Set find - " << tab[2].time_find << std::endl;
    std::cout << "Un_set find - " << tab[2].time_find << std::endl;

    return 0;
}
