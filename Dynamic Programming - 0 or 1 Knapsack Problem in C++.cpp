#include <bits/stdc++.h>
using namespace std;

void printknapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
             else
            {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    int res = K[n][W];
    cout << "Max-Profit: " << res << endl;
    cout << "\nThe Items are: \n\n";

    w = W;
    for (i = n; i > 0 && res > 0; i--)
    {
        if (res == K[i - 1][w])
            continue;
        else
        {
            cout <<"Item Number: " <<i << " and Weight: "<<wt[i - 1] <<"\n";
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
}

int main()
{
    int val[] = {3,4,5,6};
    int wt[] =  {2,3,4,5};
    int W=5;

    //int val[] = { 25, 20, 15, 40, 50 };
    //int wt[] = { 3, 2, 1, 4, 5 };
    //int W = 6;

    int n = sizeof(val) / sizeof(val[0]);

    printknapSack(W, wt, val, n);

    return 0;
}