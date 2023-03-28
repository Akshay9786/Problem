/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;


struct Data {
    std::uint8_t x;
    double y;
    Data(std::uint8_t a,double b)
    {
        x=a;
        y=b;
    }
};

//Reorders the container in such a way, that subset A preceeds subset B.
void reorder1(vector<Data> &temp, vector<Data> &b)
{
    for(auto i :temp)
    {
        for (auto j:b)
        {
            if(i.x == j.x)
                {
                    unsigned char temp;
                    temp=i.x;
                    i.x=j.x;
                    j.x=temp;
                }
        }
    }
}

//Reorders elements of subset B in such a way, 
//that given number ```n``` of elements has smallest value of y and this n elements are in ascending order of y. 
//Let this ```n``` elements be subset C.
void reorder2(vector<Data> &temp, int n,vector<Data> &c)
{
    double smallestY=temp[0].y;
    c.clear();
    
    for(int i = 0; i < temp.size()-1; ++i)
    {
        if(smallestY>temp[i].y)
            smallestY=temp[i].y;
        if(temp[n].y<temp[n-1].y && i<n)
        {
            vector<Data> t;
            t=temp[n];
            temp[n]=temp[n+1];
            temp[n+1]=t;
            c.push_back(temp[i]);
        }
    }

    temp[n].y=smallestY;
    c.push_back(temp[n]);
}

int main()
{
    std::vector<struct Data> main;
    std::vector<struct Data> A;
    std::vector<struct Data> B;
    
    Data D1(253,10), D2(254,11), D3(255,12);

    main.push_back(D1);
    main.push_back(D3);
    main.push_back(D2);
    
    A.push_back(D1);
    A.push_back(D3);
    A.push_back(D2);
    
    reorder1(main,B);
    
    Data D4(256,13), D5(257,14), D6(258,15);
    
    main.push_back(D4);
    main.push_back(D6);
    main.push_back(D5);
    
    B.push_back(D4);
    B.push_back(D6);
    B.push_back(D5);
    
}
