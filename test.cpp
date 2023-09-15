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
