﻿//#include <cstdint>
// uint64_t
#include <vector>
// std::vector
#include <thread>
#include<iostream>
using namespace std;

template <
    typename value_t,
    typename index_t>

void fibo(value_t n,value_t *result) {
    value_t a_0 = 0;
    value_t a_1 = 1;
    for (index_t index = 0; index < n; index++)
    {
        const value_t tmp = a_0;
        a_0 = a_1;
        a_1 += tmp;
    }
    *result = a_0;
}


int main(int argc, char** argv)
{
    const uint64_t num_threads = 32;
    vector<thread> threads;

    vector<uint64_t> results(num_threads, 0);

    for (uint64_t id = 0; id < num_threads; id++)
        threads.emplace_back(fibo<uint64_t, uint64_t>, id, &(results[id]));

    for (auto& thread : threads)
        thread.join();

    for (const auto& result : results)
        cout << result << endl;

    
    
}