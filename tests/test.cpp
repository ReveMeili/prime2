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

}
// test for few range of prime numbers if both methods are consistent
TEST_CASE("testing range","[range]"){
    std::shared_ptr<long long> n=std::make_shared<long long>(0);

}
// Testing mod operation counts
TEST_CASE("testing ModOpCounts", "[ModOpCounts]"){
    std::shared_ptr<long long> n=std::make_shared<long long>(0);

}
// test edge cases
TEST_CASE("testing Edge","[Edge]"){
    std::shared_ptr<long long> n=std::make_shared<long long>(0);
    
}