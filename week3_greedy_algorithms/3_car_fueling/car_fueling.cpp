#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int numRefill=0;
    int curRefil=0;
    while(curRefil<=stops.size()){
        int lastRefil = curRefil;
        while(curRefil<stops.size() && (stops[curRefil+1] - stops[lastRefil] )<=tank){
            curRefil++;
        }
        if(curRefil==lastRefil){
            return -1;
        }
        if (curRefil<=stops.size()){
            numRefill++;
        }
    }
    return numRefill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
