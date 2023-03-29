#include <iostream>
#include <climits>  // INT_MAX
#include <unordered_map>

using namespace std;

// Challenge: Print the coins that are used
int make_change(const int* denominations, int num, int sum) {
    int table[sum];
    table[0] = 0;

    // solve smaller subproblems first
    for (int i=1; i<=sum; i++) {
        table[i] = INT_MAX; // minimum number of coins we need to make the desired amount of change (i)
        for (int j=0; j<num; j++) {
            if (i >= denominations[j]) {
                if (table[i] > table[i-denominations[j]] + 1)
                    table[i] = table[i-denominations[j]] + 1;
            }
        }
    }
    // return the minimum number of coins needed to make the desired amount of change (sum)
    return table[sum];
}
  
int main() {
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

    // bottom up approach
    cout << "The minimum number of coins required to make this change is: ";
    cout << make_change(denominations, n, sum) << endl; 

    return 0; 
} 
