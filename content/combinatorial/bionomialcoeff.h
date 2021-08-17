/**
 * Author: Ahmed Mamdouh
 * Date: 2021-08-18
 * License: CC0
 * Source: Ahmed
 * Description: Gets binomial coefficient `nCk`. inverse is modular inverse function or precomputed.
 * Status: Works
 */
#pragma once

long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;
}