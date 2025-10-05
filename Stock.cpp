#include <iostream>
using namespace std;

int maxProfit(int prices[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

int main()
{
    int prices[20];
    int n;
    cout<<"ENter the no of Stocks:";
    cin>>n;
    cout<<"Enter the stock prices for each day:";
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    cout << "the stock prices for each day are:";
    for(int i=0;i<n;i++){
        cout << prices[i]<<" ";
    }
cout<< "\nMaximum Profit: " << maxProfit(prices, n) << endl;
    return 0;
}
