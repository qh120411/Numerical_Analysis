#include<stdio.h>

int main()
{
    double a[4][4] = {
        {10, -1, 2, -3},
        {1, 10, -1, 2},
        {2, 3, 20, -1},
        {3, 2, 1, 20}
    };
    double b[4] = {0, 5, -10, 15};
    int n = 4;

    //Giai thuan - khu Gauss
    for(int k = 0; k < n - 1; k++)
    {
        for(int i = k + 1; i < n; i++)
        {
            double t = a[i][k] / a[k][k];
            for(int j = k; j < n; j++)
            {
                a[i][j] = a[i][j] - t * a[k][j];
            }
            b[i] = b[i] - t * b[k];
        }
    }

    printf("Ma tran sau khi khu Gauss\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%10.4lf  ", a[i][j]);
        }
        printf("|  %10.4lf\n", b[i]);
    }

    //Giai nghich - tim x;
    double x[100];

    for(int i = n - 1; i >= 0; i--)
    {
        double S = b[i];
        for(int j = i + 1; j <= n; j++)
        {
            S -= a[i][j] * x[j];
        }
        x[i] = S / a[i][i];
    }

    for(int i = 0; i < n; i++)
    {
        printf("x[%d] = %10.4lf\n", i, x[i]);
    }

    return 0;
}
