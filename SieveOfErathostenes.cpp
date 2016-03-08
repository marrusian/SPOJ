#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdint>
#include <cinttypes>

using namespace std;

vector<bool> soe(uint_fast32_t n)
{
    const uint_fast32_t SIZE = n/2+1;
    const uint_fast32_t LIM  = sqrt(SIZE)+1;

    vector<bool> arr(SIZE);

    for(uint_fast32_t i=1; i<=LIM; ++i)
        if(!arr[i])
            for(uint_fast32_t j=2*i*(i+1); j<SIZE; j+=(2*i+1))
                arr[j] = true;

    return arr;
}

vector<bool> offset_soe(uint_fast32_t lower, uint_fast32_t upper)
{
    lower = lower%2? (lower==1? lower : lower-2) : lower-1;
    const uint_fast32_t LENGTH = (upper-lower)/2 + 1;

    vector<bool> sieve  = soe(sqrt(upper));
    vector<bool> seg_sieve(LENGTH);

    for(uint_fast32_t k=1, p, offset, lim = sieve.size(); k<lim; ++k)
        if(!sieve[k])
        {
            p = 2*k+1;
            offset = p - (lower % p);
            if(offset%2)
                offset += p;
            offset /= 2;
            while(offset < LENGTH){
                if(lower + offset != k+1)
                    seg_sieve[offset] = true;
                offset += p;
            }
        }

    return seg_sieve;
}

void show_primes(uint_fast32_t lower, uint_fast32_t upper)
{
    vector<bool> primes = offset_soe(lower, upper);

    uint_fast32_t base = lower%2? (lower==1? lower : lower-2) : lower-1;

    if(lower <= 2) printf("%d\n", 2);
    for(uint_fast32_t i=1, lim = primes.size(); i<lim; ++i)
        if(!primes[i])
            printf("%" PRIuFAST32 "\n", base+2*i);
}

int main(void)
{
    uint_fast32_t t;
    uint_fast32_t a,b;

    scanf("%" SCNuFAST32, &t);
    while(t--)
    {
        scanf("%" PRIuFAST32 "%" PRIuFAST32, &a, &b);
        show_primes(a,b);
    }

    return 0;
}