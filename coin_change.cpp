#include <iostream>
using namespace std;

int countWays(int coins[], int n, int sum)
{
    int dp[sum + 1];

    
    for (int i = 0; i <= sum; i++)
        dp[i] = 0;

    dp[0] = 1; 

    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= sum; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[sum];
}

int main()
{
    int n, sum;


    cout << "Enter number of coin types: ";
    cin >> n;

    int coins[n];
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

  
    cout << "Enter the target sum: ";
    cin >> sum;


    cout << "Number of ways to make sum " << sum << " = "
         << countWays(coins, n, sum) << endl;

    return 0;
}
