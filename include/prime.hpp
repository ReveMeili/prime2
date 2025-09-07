//prime.hpp

#ifndef PRIME_H
#define PRIME_H
#pragma once

#include <memory>

using PrimeFn = bool(*)(int, std::shared_ptr<long long>);

bool isPrimeHalf(int n, std::shared_ptr<long long> modOps);

bool isPrimeSqrt(int n, std::shared_ptr<long long> modOps);

long long countModOps(PrimeFn isPrime, int lo, int hi);

#endif