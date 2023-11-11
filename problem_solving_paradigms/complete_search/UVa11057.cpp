#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int a;
    int b;
} Pair;

bool binary_search(int *A, int size, int number, int index)
{
    int l = 0; int r = size - 1; int m = (l+r)/2;
    while(l <= r)
    {
        m = (l+r)/2; 
        if(A[m] == number && A[m] != index)
            {return true;}
        if(A[m] > number)
            r = m - 1;
        else 
            l = m + 1;  
    }
    return false;
}

Pair exact_sum(int *A, int sum, int size)
{
    int dif = 1123456; Pair answer;
    for(int i = 0; i < size; i++)
    {
        int x_pair = A[i]; 
        if(binary_search(A, size, sum - A[i], i))
        {
            if(fabs(x_pair - (sum - A[i])) < dif) 
                {answer.a = x_pair; answer.b = sum - A[i]; dif = fabs(x_pair - (sum - A[i]));}
        }
    }
    return answer;
}

int main()
{
    int A[10000], size, sum;
    Pair answer;
    memset(A, 0, sizeof A);
    while(scanf("%d", &size) != EOF)
    {
        for(int i = 0; i < size; i++) scanf("%d", &A[i]);
        sort(A, A + size); 
        scanf("%d", &sum); 
        answer = exact_sum(A, sum, size);
        printf("Peter should buy books whose prices are %d and %d.\n\n", answer.a, answer.b);
    }
    return 0;
}
