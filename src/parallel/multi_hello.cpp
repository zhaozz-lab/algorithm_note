#include <cstdint>
// uint64_t
#include <vector>
// std::vector
#include <thread>
#include<iostream>
using namespace std;
void say_hello(uint64_t id)
{

    //cout << "hello world"<<id << endl; 
    printf("hello world %d \n", id);
   
}


int main(int argc, char** argv)
{

    const uint64_t num_thread = 4;
    vector<thread> threads;

    for (uint64_t id = 0; id < num_thread; id++)
    {
        threads.emplace_back(say_hello, id);
        //threads.push_back(say_hello, id);
    }

    for(auto& thread:threads)
    {
        thread.join();
    }
}