#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

bool has_duplicates_slow(const vector <int> &a){
    for (int i=0; i<a.size()-1; i++){
        for (int j=i+1; j<a.size(); j++){
            if (a[i] == a[j]) return true;
        }
    }
    return false;
}

vector <int> get_duplicates_slow(const vector <int> &a){
    set <int> q{};
    for (int i=0; i<a.size()-1; i++){
        for (int j=i+1; j<a.size(); j++){
            if (a[i] == a[j]){
                q.insert(a[i]);
            }
        }
    }
    std::vector<int> v(q.size());
    v.assign(q.begin(), q.end());
    return v;
}

bool has_duplicates(const vector <int> &a){
    set <int> q{};
    for (int i=0; i<a.size(); i++){
        if (q.find(a[i]) != q.end()) return true;
        else q.insert(a[i]);
        }
    return false;
}

vector <int> get_duplicates(const vector <int> &a){
    set <int> q{};
    set <int> answer{};
    for (int i=0; i<a.size(); i++){
        if (q.find(a[i]) != q.end()) answer.insert(a[i]);
        else q.insert(a[i]);
        }
    std::vector<int> v(q.size());
    v.assign(answer.begin(), answer.end());
    return v;
}