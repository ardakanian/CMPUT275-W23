#include <iostream>
#include <climits>          // for INT_MAX
#include <unordered_map>

using namespace std;

// Challenge: Print the coins that are used
int make_change(const int* denominations, int num, int sum, unordered_map<int,int> &memo) {
    // since key is an integer, we could use an array instead of an unordered_map 
    // to cache and retrieve the result later
    if (memo.find(sum) == memo.end()) {
        // this must be the first time that we solve this subproblem

        if (sum == 0) memo[sum] = 0;            // base case
        else {
            int nc, minc = INT_MAX;             // INT_MAX is used instead of infinity
            for (int i=0; i<num; i++) {
                if (denominations[i] <= sum) {  // otherwise the problem is infeasible
                    nc = make_change(denominations, num, sum - denominations[i], memo) + 1;
                    if (nc < minc) minc = nc;
                }

            }
            memo[sum] = minc;
        }
    }
    // return the minimum number of coins needed to make the desired amount of change (sum)
    return memo[sum]; 
}

int main() {
    // hash table to store the solution to each subproblem
    unordered_map<int, int> table;

    int n;
    cout << "Enter the number of coin denominations" << endl;
    cin >> n;

    int denominations[n];
    for(int i = 0; i < n; i++) {
        cout << "Coin denomination #" << (i+1) << ": ";
        cin >> denominations[i];
    }

    int sum;
    cout << "What's the amount of change? ";
    cin >> sum;

    // top down approach
    cout << "The minimum number of coins required to make this change is: ";
    cout << make_change(denominations, n, sum, table) << endl;

    return 0; 
}
