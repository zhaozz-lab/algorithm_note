// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    std::vector<int> vi;
    for (int i = 0; i < 10; i++)
        vi.push_back(i);
    
    for (auto iter = vi.begin(); iter != vi.end(); iter++)
        std::cout << *iter << std::endl;

  
    auto iter = vi.begin();
    cout << "the out is " << *iter << endl;
    while (iter != vi.end())
    {
        cout << *iter << " " << endl;
        if (*iter > 5)
        {
            iter = vi.erase(iter);
            
        }
        else
        {
            iter++;
        }
        
        
       
    }

    for (auto iter = vi.begin(); iter != vi.end(); iter++)
        std::cout << *iter<<" ";
}
