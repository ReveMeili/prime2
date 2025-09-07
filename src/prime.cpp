//prime.cpp
#include "prime.hpp"
#include <cmath>

// TODO: Implement isPrimeHalf

bool isPrimeHalf(int n, std::shared_ptr<long long> modOps){
   // Your implementation here
   // Checks for divisibility up to n/2
   //return true if n is prime else return false
   //count modulo operations when modOps is not nullptr
    if (modOps){
    (*modOps)=0;}
    if (n<=1){return false;} //not prime
    if (n==2){return true;} //is prime, divided by 2 would be prime (special case)
        
    if (modOps) (*modOps)++;
    if (n % 2 == 0) {           // if even, divisible by 2, not prime
        //to count when modOps is not nullptr
        //(*modOps)++;
        return false;
    }
    
    for(int i=3; i<=n/2; i+=2){
        if (modOps) (*modOps)++;// count every mod operation        
        if (n%i ==0) return false;// if divisible it"s not prime
    }
   return true;
}

//TODO: Implement isPrimeSqrt
bool isPrimeSqrt(int n, std::shared_ptr<long long> modOps){
    //Your implementation here
    //Checks for divisibility up to square root of n
    //return true if n is prime else return false
    //Remember to count modulo operations when modOps is not nullptr
    if (modOps){
    (*modOps)=0;}
    if (n<=1){return false;} //not prime
    if (n==2){return true;} //is prime, divided by 2 would be prime (special case)
    
    if (modOps) (*modOps)++;//works same shared vs raw pointer
    if (n % 2 == 0) {           // any other even number
        
        //(*modOps)++;
        return false;
    }

    //int limit = static_cast<int>(std::sqrt(n));
    for(int i=3; i<= std::sqrt(n); i+=2){//isstd::needed
        if (modOps) (*modOps)++;// count every mod operation        
        if (n% i ==0) return false;// if divisible it"s not prime
    }    
    return true;

}

// TODO: Implement countModOps
long long countModOps(PrimeFn isPrime, int lo, int hi) {
    // Your implementation here
    //This should call the provided isPrime function for each number in range [lo, hi]
    //and return the total number of modulo operations performed
    long long total_c=0;// counts all mod ops
    
   for(int i=lo;i <=hi;i++){
        std::shared_ptr<long long> c=std::make_shared<long long>(0);// counts mod ops for each
        //long long c = 0;
        // c is a shared ptr to long long at 0
        isPrime(i, c);// calls isPrime func
        //passes smart pointer directly *c is not a shared pointer 
        //&c for raw becasue function expects raw adress, with shared pointer, just pass c?
        //??in all use * to dereferece (find underlying long long vale)
        total_c+=*c;// add the count of mod ops each number in range

   }     // the *c dereferences to read int inside pointer
    
    return total_c;//returns total mod operations


}


