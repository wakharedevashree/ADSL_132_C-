#include <iostream>
using namespace std;


bool canFinish(int task[], int n, int D, int limit)
{
    int days = 1; 
    int work = 0; 

    for (int i = 0; i < n; i++)
    {
        if (work + task[i] > limit)
        { 
            days++;
            work = 0;
        }
        work += task[i];
        if (days > D)
            return false; 
    }
    return true; 
}

int minWorkPerDay(int task[], int n, int D)
{
   
    int low = task[0], high = 0;
    for (int i = 0; i < n; i++)
    {
        if (task[i] > low)
            low = task[i]; 
        high += task[i];   
    }

    int ans = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canFinish(task, n, D, mid))
        {
            ans = mid; 
            high = mid - 1;
        }
        else
        {
            low = mid + 1; 
        }
    }
    return ans;
}

int main()
{
    int n, D;

    cout << "Enter number of tasks: ";
    cin >> n;

    int task[n]; 

    cout << "Enter work units for each task: ";
    for (int i = 0; i < n; i++)
    {
        cin >> task[i];
    }

    cout << "Enter number of days: ";
    cin >> D;

    int result = minWorkPerDay(task, n, D);
    cout << "Minimum work per day: " << result << endl;

    return 0;
}
