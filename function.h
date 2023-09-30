#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <chrono>
#include <stdlib.h>
#include <string>
#include <algorithm>
#pragma once


using namespace std::chrono;

const int n = 100000;
const int m = 100000;


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

double find_time(const std::list<int>& q, int poisk[m]) {
    auto t_1 = steady_clock::now();
    int k = 0;
    for (int i = 0; i < m; i++) {
        if (std::find(q.begin(), q.end(), poisk[i]) != q.end()){
            k++;
        }
        else{
            k--;
        }
    }
    auto t_2 = steady_clock::now();
    std::cout << k << " ";
    return duration<double>(t_2 - t_1).count();
}

double find_time(const std::vector<int>& q, int poisk[m]) {
    auto t_1 = steady_clock::now();
    int  k = 0;
    for (int i = 0; i < m; i++) {
        auto it = std::find(q.begin(), q.end(), poisk[i]);
        if (it != q.end()){
            k++;
        }
        else{
            k--;
        }
    }
    auto t_2 = steady_clock::now();
    std::cout << k << " ";
    return duration<double>(t_2 - t_1).count();
}

double find_time(const std::set<int>& q, int poisk[m]) {
    auto t_1 = steady_clock::now();
    int k = 0;
    for (int i = 0; i < m; i++) {
        if (q.find(poisk[i]) != q.end()){
            k++;
        }
        else{
            k--;
        }
    }
    auto t_2 = steady_clock::now();
    std::cout << k << " ";
    return duration<double>(t_2 - t_1).count();
}

double find_time(const std::unordered_set<int>& q, int poisk[m]) {
    auto t_1 = steady_clock::now();
    int k = 0;
    for (int i = 0; i < m; i++) {
        if (q.find(poisk[i]) != q.end()){
            k++;
        }
        else{
            k--;
        }
    }
    auto t_2 = steady_clock::now();
    std::cout << k << " ";
    //std::cout << duration<double>(t_2 - t_1).count() << k;
    return duration<double>(t_2 - t_1).count();
}
