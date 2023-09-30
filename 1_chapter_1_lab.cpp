#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Returns shuffled sequence of unique numbers of specified size, with values from start to start + size - 1.
vector<int> shuffled_sequence(int size, int start = 0) {
    vector<int> result(size);
    iota(result.begin(), result.end(), start);
    random_shuffle(result.begin(), result.end());
    return result;
}

// Returns sequence of random numbers of specified size, with values from 0 to max.
vector<int> random_sequence(int size, int max) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, max);
    vector<int> result;
    for (int i = 0; i < size; i++) {
        result.push_back(distribution(generator));
    }
    return result;
}

int main() {
    const int size = 1000;
    
    // Container to use.
    vector<int> Vector;
    list<int> List;
    set<int> Set;
    unordered_set<int> Un_set;
    // Insert elements into container.

    const auto elems_to_add = shuffled_sequence(size);
    auto t_1 = steady_clock::now();
    for (const auto &elem: elems_to_add) {
        Vector.push_back(elem);
    }
    auto t_2 = steady_clock::now();
    cout << "Vector push_back - " << duration<double>(t_2 - t_1).count() << endl;

    t_1 = steady_clock::now();
    for (const auto &elem: elems_to_add) {
        List.push_back(elem);
    }
    t_2 = steady_clock::now();
    cout << "List push_back - " << duration<double>(t_2 - t_1).count() << "\n\n";

    t_1 = steady_clock::now();
    for (const auto &elem: elems_to_add) {
        Vector.insert(Vector.begin(), elem);
    }
    t_2 = steady_clock::now();
    cout << "Vector insert - " << duration<double>(t_2 - t_1).count() << endl;

    t_1 = steady_clock::now();
    for (const auto &elem: elems_to_add) {
        List.insert(List.begin(), elem);
    }
    t_2 = steady_clock::now();
    cout << "List insert - " << duration<double>(t_2 - t_1).count() << endl;

    t_1 = steady_clock::now();
    for (const auto &elem: elems_to_add) {
        Set.insert(elem);
    }
    t_2 = steady_clock::now();
    cout << "Set insert - " << duration<double>(t_2 - t_1).count() << endl;

    t_1 = steady_clock::now();
    for (const auto &elem: elems_to_add) {
        Un_set.insert(elem);
    }
    t_2 = steady_clock::now();
    cout << "Un_set insert - " << duration<double>(t_2 - t_1).count() << endl;
    
    // Iterate through elements.
    long long sum = 0;
    for (const auto &elem: Vector) {
        sum += elem;
    }    
    
    // Perform search into container
    int hits = 0;
    const auto elems_to_search = random_sequence(1000, 2 * size);
    cout << "\nFIND :" << endl;
    t_1 = steady_clock::now();
    for (const auto &elem: elems_to_search) {
        auto it = find(Vector.begin(), Vector.end(), elem);
        if (it != Vector.end()) {
            hits++;
        }        
    }
    t_2 = steady_clock::now();
    cout << "Vector - " << duration<double>(t_2 - t_1).count() << endl;
    t_1 = steady_clock::now();
    for (const auto &elem: elems_to_search) {
        auto it = find(List.begin(), List.end(), elem);
        if (it != List.end()) {
            hits++;
        }        
    }
    t_2 = steady_clock::now();
    cout << "List - " << duration<double>(t_2 - t_1).count() << endl;

    t_1 = steady_clock::now();
    for (const auto &elem: elems_to_search) {
        auto it = Set.find(elem);
        if (it != Set.end()) {
            hits++;
        }        
    }
    t_2 = steady_clock::now();
    cout << "Set - " << duration<double>(t_2 - t_1).count() << endl;

    t_1 = steady_clock::now();
    for (const auto &elem: elems_to_search) {
        auto it = Un_set.find(elem);
        if (it != Un_set.end()) {
            hits++;
        }        
    }
    t_2 = steady_clock::now();
    cout << "Un_set - " << duration<double>(t_2 - t_1).count() << endl;
}