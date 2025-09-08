//test.cp
#define CATCH_CONFIG_MAIN
#include "catch2/catch (2).hpp"
#include "prime.hpp"

// Testing few prime identification
TEST_CASE("testing PrimeIdentification", "[PrimeIdentification]"){
//REQUIRE_FALSE(isPrimeHalf(8));
    std::shared_ptr<long long> n=std::make_shared<long long>(0);
   //long long n;
   //half
    REQUIRE(isPrimeHalf(3, n) == true);
    REQUIRE(*n == 1);
    REQUIRE(isPrimeHalf(2, n) == true);
    REQUIRE(*n == 0);
    REQUIRE(isPrimeHalf(4, n) == false);
    REQUIRE(*n == 1);
    REQUIRE(isPrimeHalf(9, n) == false);
    REQUIRE(*n == 2);  
    //sqrt
    REQUIRE(isPrimeSqrt(3, n) == true);
    REQUIRE(*n == 1);
    REQUIRE(isPrimeSqrt(2, n) == true);
    REQUIRE(*n == 0);
    REQUIRE(isPrimeSqrt(4, n) == false);
    REQUIRE(*n == 1);
    REQUIRE(isPrimeSqrt(9, n) == false);
    REQUIRE(*n == 2);  

}
//Testing composite numbers
TEST_CASE("testing CompositeNumbers","[CompositeNumbers]"){
    std::shared_ptr<long long> n=std::make_shared<long long>(0);

    REQUIRE(isPrimeHalf(6, n) == false);
    REQUIRE(*n == 1);
    REQUIRE(isPrimeHalf(12, n) == false);
    REQUIRE(*n == 1); 
    REQUIRE(isPrimeHalf(15, n) == false);
    REQUIRE(*n == 2);
    REQUIRE(isPrimeHalf(21, n) == false);
    REQUIRE(*n == 2); 
    
    REQUIRE(isPrimeSqrt(6, n) == false);
    REQUIRE(*n == 1);
    REQUIRE(isPrimeSqrt(12, n) == false);
    REQUIRE(*n == 1);
    REQUIRE(isPrimeSqrt(15, n) == false);
    REQUIRE(*n == 2);
    REQUIRE(isPrimeSqrt(21, n) == false);
    REQUIRE(*n == 2);
}
// test for few range of prime numbers if both methods are consistent
TEST_CASE("testing range","[range]"){
    std::shared_ptr<long long> n=std::make_shared<long long>(0);

     for (int i = 2; i <= 5000; i++) {
        bool halfResult = isPrimeHalf(i, n);
        bool sqrtResult = isPrimeSqrt(i, n);
        REQUIRE(halfResult == sqrtResult); }
}
// Testing mod operation counts
TEST_CASE("testing ModOpCounts", "[ModOpCounts]"){
    std::shared_ptr<long long> n=std::make_shared<long long>(0);
    long long opsHalf = countModOps(isPrimeHalf, 2, 20);
    long long opsSqrt = countModOps(isPrimeSqrt, 2, 20);

    REQUIRE(opsHalf > 0);
    REQUIRE(opsSqrt > 0);

    REQUIRE(opsSqrt <= opsHalf);
}
// test edge cases
TEST_CASE("testing Edge","[Edge]"){
    std::shared_ptr<long long> n=std::make_shared<long long>(0);
    
    REQUIRE(isPrimeSqrt(-1, n) == false);
    REQUIRE(*n == 0);
    REQUIRE(isPrimeSqrt(0, n) == false);
    REQUIRE(*n == 0);
    REQUIRE(isPrimeSqrt(1, n) == false);
    REQUIRE(*n == 0);

    REQUIRE(isPrimeHalf(-1, n) == false);
    REQUIRE(*n == 0);
    REQUIRE(isPrimeHalf(0, n) == false);
    REQUIRE(*n == 0);
    REQUIRE(isPrimeHalf(1, n) == false);
    REQUIRE(*n == 0);
}