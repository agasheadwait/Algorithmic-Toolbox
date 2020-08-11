#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool comp(string a, string b) {
    if (a.append(b).compare(b.append(a))) {
        return a>b;
    }
    else {
        return b>a;
    }
}

string largest_number(vector<string> a) {
    //write your code here
    sort(a.begin(), a.end(), comp);
    std::stringstream ret;
    for (size_t i = 0; i < a.size(); i++) {
        ret << a[i];
    }
    string result;
    ret >> result;
    return result;
}

int main() {
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    std::cout << largest_number(a)<<"\n";
}
