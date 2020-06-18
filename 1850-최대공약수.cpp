#include <iostream>
using namespace std;
void gcd(unsigned long long a, unsigned long long b)
{
    if (b == 0)
    {
        printf("%llu", a);
    }
    else
    {
        gcd(b, a % b);
    }
}
int main(void)
{

    unsigned long long a, b, answer;
    scanf("%llu %llu", &a, &b);
    gcd(a, b);
    return 0;
}