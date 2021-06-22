#include <stdio.h>

int find_sum_primes(long long n);
int is_prime(long long a);
int main(void)
{

    long long N;
    scanf("%lld", &N);

    int result = find_sum_primes(N);
    printf("result: %d\n", result);


}

int find_sum_primes(long long n)
{
    int num = 0;

    long long sum_prime = 2;

    for (long long i = 3; i <= n; i++)
    {
        if (is_prime(i) && sum_prime + i <= n)
        {
            sum_prime += i;

            if (is_prime(sum_prime))
            {
                printf("prime: %lld\n", sum_prime);
                num++;
            }
        }

        if (sum_prime >= n)
        {
            break;
        }
    }
    return num;
}

int is_prime(long long a)
{
    if (a % 2 == 0)
        return 0;


    for (int i = 3; i * i <= a; i += 2)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}