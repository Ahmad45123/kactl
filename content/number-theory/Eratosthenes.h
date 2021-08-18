/**
 * Author: Håkan Terelius
 * Date: 2009-08-26
 * License: CC0
 * Source: http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 * Description: Prime sieve for generating all primes up to a certain limit. isprime$[i]$ is true iff $i$ is a prime.
 * Time: lim=100'000'000 $\approx$ 0.8 s. Runs 30\% faster if only odd indices are stored.
 * Status: Tested
 */
#pragma once

const int N = 1e6+5;
int prime[N];
void sieve(){
    for(int i=2; i<N; i++){
        if(prime[i])continue;
        prime[i] = i;
        for(int j=i*i; j<N; j+=i)
            prime[j]=i;
    }
    //getting prime factors of the number!
    for(int i=1; i<N; i++){
        int x = i;
        while(x != 1){
            x /= prime[x];
        }
    }
}
