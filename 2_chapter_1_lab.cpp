#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;


bool has_dublicates_slow(int a[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (a[i] == a[j]) return true;
        }
    }
    return false;
}

set <int> get_dublicates_slow(int a[], int n){
    set <int> q{};
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (a[i] == a[j]){
                q.insert(a[i]);
            }
        }
    }
    return q;
}

bool has_dublicates(int a[], int n){
    set <int> q{};
    for (int i=0; i<n; i++){
        if (q.find(a[i]) != q.end()) return true;
        else q.insert(a[i]);
        }
    return false;
}

set <int> get_duplicates(int a[], int n){
    set <int> q{};
    set <int> answer{};
    for (int i=0; i<n; i++){
        if (q.find(a[i]) != q.end()) answer.insert(a[i]);
        else q.insert(a[i]);
        }
    return answer;
}

void print_set(set <int> &t){
    for (auto i : t) cout << i << " ";
    cout << endl;
}


int main(){
    srand(38);
    int a[1000];
    int test_1[]{1, 2, 3, 22, 5, 33, 7, 42, 42, 10, 11, 12, 13, 14, 14, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38};
    int test_2[]{1, 1, 1, 1, 1, 1, 1};
    int test_3[]{1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < 1000; i++) {
        a[i] = (int)rand() % 1000;
    }
    cout << has_dublicates_slow(test_1, 38) << endl;
    set <int> q = get_dublicates_slow(test_1, 38);
    cout << "1 test: set ";
    print_set(q);
    cout << has_dublicates_slow(test_2, 7) << endl;
    q = get_dublicates_slow(test_2, 7);
    cout << "2 test: set ";
    print_set(q);
}