#include "include/hasher.hpp"

// int main(int argc, char **argv)
// {
//    XXH32_hash_t hash     = XXH32("Hello World", 11, 0);
//    XXH128_hash_t hash128 = XXH128("Hello World", 11, 0);
//
//    printf("32-bit hash: %u \n", hash);
//    printf("128-bit hash: %llu %llu \n", hash128.high64, hash128.low64);
//
//    return 0;
// }

// create a function that takes string as a input and return a 128 bit hash

XXH128_hash_t stringToHash(std::string input)
{
   XXH128_hash_t hash128 = XXH128(input.c_str(), input.length(), 0);
   return hash128;
}

std::string hashString(std::string input)
{
   XXH128_hash_t hash128 = stringToHash(input);
   std::string hashString = std::to_string(hash128.high64) + std::to_string(hash128.low64);
   return hashString;
}
