#include "function_2.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <algorithm>
#include <iostream>

template <class T>
std::vector<T> sorted(const typename std::vector<T> &data) {
    typename std::vector<T> sorted_data = data;
    std::sort(sorted_data.begin(), sorted_data.end());
    return sorted_data;
}

TEST_CASE ("Empty array") {
    const std::vector<int> data = {};
    CHECK_FALSE(has_duplicates(data));
    CHECK(sorted(get_duplicates(data)) == std::vector<int> {});
}

TEST_CASE ("Single element") {
    const std::vector<int> data = {1};
    CHECK_FALSE(has_duplicates(data));
    CHECK(sorted(get_duplicates(data)) == std::vector<int> {});
}

TEST_CASE ("Many elements") {
    const std::vector<int> data = {2, 1, -4, 7};
    CHECK_FALSE(has_duplicates(data));
    CHECK(sorted(get_duplicates(data)) == std::vector<int> {});
}

TEST_CASE ("Many elements, one duplicate") {
    const std::vector<int> data = {2, -3, 0, 2, 7, 1};
    CHECK(has_duplicates(data));
    CHECK(sorted(get_duplicates(data)) == std::vector<int> {2});
}

TEST_CASE ("Many elements, many duplicates") {
    const std::vector<int> data = {2, -3, 0, 2, 1, -3, 4, 1, -1, 2};
    CHECK(has_duplicates(data));
    CHECK(sorted(get_duplicates(data)) == std::vector<int> {-3, 1, 2});
}

TEST_CASE ("Single duplicated elem") {
    const std::vector<int> data = {4, 4, 4, 4};
    CHECK(has_duplicates(data));
    CHECK(sorted(get_duplicates(data)) == std::vector<int> {4});
}



TEST_CASE ("Empty array 2") {
    const std::vector<int> data = {};
    CHECK_FALSE(has_duplicates_slow(data));
    CHECK(sorted(get_duplicates_slow(data)) == std::vector<int> {});
}

TEST_CASE ("Single element 2") {
    const std::vector<int> data = {1};
    CHECK_FALSE(has_duplicates_slow(data));
    CHECK(sorted(get_duplicates_slow(data)) == std::vector<int> {});
}

TEST_CASE ("Many elements 2") {
    const std::vector<int> data = {2, 1, -4, 7};
    CHECK_FALSE(has_duplicates_slow(data));
    CHECK(sorted(get_duplicates_slow(data)) == std::vector<int> {});
}

TEST_CASE ("Many elements, one duplicate 2") {
    const std::vector<int> data = {2, -3, 0, 2, 7, 1};
    CHECK(has_duplicates_slow(data));
    CHECK(sorted(get_duplicates_slow(data)) == std::vector<int> {2});
}

TEST_CASE ("Many elements, many duplicates 2") {
    const std::vector<int> data = {2, -3, 0, 2, 1, -3, 4, 1, -1, 2};
    CHECK(has_duplicates_slow(data));
    CHECK(sorted(get_duplicates_slow(data)) == std::vector<int> {-3, 1, 2});
}

TEST_CASE ("Single duplicated elem 2") {
    const std::vector<int> data = {4, 4, 4, 4};
    CHECK(has_duplicates_slow(data));
    CHECK(sorted(get_duplicates_slow(data)) == std::vector<int> {4});
}