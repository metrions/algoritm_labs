#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <chrono>
#include <stdlib.h>
#include <string>
#include <algorithm>
#define CATCH_CONFIG_MAIN
#include "function.h"
#include <cstdint>

TEST_CASE("push_list"){
    std::list <int> k{123, 2, 3, 13};
    k.push_back(16);
    k.push_back(10);
    k.push_back(129);
    REQUIRE(k.back() == 129);
    int a[] = {123, 2, 3, 13, 16, 10, 129};
    int m = 0;
    for (auto i : k){
        REQUIRE(i == a[m]);
        m++;
    }
}


TEST_CASE("push_vector"){
    std::vector <int> k{123, 2, 3, 13};
    k.push_back(16);
    REQUIRE(k.back() == 16);
    k.push_back(10);
    REQUIRE(k.back() == 10);
    k.push_back(129);
    REQUIRE(k.back() == 129);
    int a[] = {123, 2, 3, 13, 16, 10, 129};
    int m = 0;
    for (auto i : k){
        REQUIRE(i == a[m]);
        m++;
    }
}

TEST_CASE("insert_list"){
    std::list <int> k{123, 2, 3, 13};
    k.insert(k.begin(), 16);
    k.insert(k.begin(), 10);
    k.insert(k.begin(), 129);
    REQUIRE(*k.begin() == 129);
    int a[] = {129, 10, 16, 123, 2, 3, 13};
    int m = 0;
    for (auto i : k){
        REQUIRE(i == a[m]);
        m++;
    }
}


TEST_CASE("insert_set"){
    std::set <int> k{123, 2, 3, 13};
    k.insert(16);
    k.insert(10);
    k.insert(129);
    REQUIRE(k.find(16) != k.end());
    REQUIRE(k.find(10) != k.end());
    REQUIRE(k.find(129) != k.end());
    REQUIRE(k.find(2) != k.end());
    REQUIRE(k.find(5) == k.end());
}

TEST_CASE("unordered_set_set"){
    std::unordered_set <int> k{123, 2, 3, 13};
    k.insert(16);
    k.insert(10);
    k.insert(129);
    REQUIRE(k.find(16) != k.end());
    REQUIRE(k.find(10) != k.end());
    REQUIRE(k.find(129) != k.end());
    REQUIRE(k.find(2) != k.end());
    REQUIRE(k.find(5) == k.end());
}


TEST_CASE("find_list"){
    std::list <int> k{123, 2, 3, 13};
    k.push_back(129);
    REQUIRE(*std::find(k.begin(), k.end(), 123) == *k.begin());
    REQUIRE(*std::find(k.begin(), k.end(), 129) == *(--k.end()));
}

TEST_CASE("vector"){
    std::vector <int> k{123, 2, 3, 13};
    k.push_back(129);
    REQUIRE(*std::find(k.begin(), k.end(), 123) == *k.begin());
    REQUIRE(*std::find(k.begin(), k.end(), 129) == *(--k.end()));
}

TEST_CASE("set"){
    std::set <int> k{123, 2, 3, 13};
    k.insert(129);
    REQUIRE(k.find(123) != k.end());
    REQUIRE(k.find(2)!= k.end());
}

TEST_CASE("unordered_set"){
    std::unordered_set <int> k{123, 2, 3, 13};
    k.insert(129);
    REQUIRE(k.find(123) != k.end());
    REQUIRE(k.find(2)!= k.end());
}


TEST_CASE("has_dublicates"){
    int test_1[]{1, 2, 3, 22, 5, 33, 7, 42, 42, 10, 11, 12, 13, 14, 14, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38};
    int test_2[]{1, 1, 1, 1, 1, 1, 1};
    int test_3[]{1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < 1000; i++) {
        a[i] = (int)rand() % 1000;
    }
    cout << has_dublicates(test_1, 38) << endl;
    set <int> q = get_duplicates(test_1, 38);
    cout << "1 test: set ";
    print_set(q);
    cout << has_dublicates(test_2, 7) << endl;
    q = get_duplicates(test_2, 7);
    cout << "2 test: set ";
    print_set(q);
}