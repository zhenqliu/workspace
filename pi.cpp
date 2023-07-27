#include <iostream>
#include <cstdlib>
#include "ctime"
using namespace std;

#define PRECISION  999
int main()
{
    long N = 0, M=0;
    float Pi=0.0;
    cout<<"how many times? ";
    cin>>N;
    if (N < 1)
    {
        cout<<"numbers of rolls less than one, parameter invalid"<<endl;
        return 0;
    }
    //srand(time(NULL));
    time_t seconds;
    time(&seconds);
    srand((unsigned int)seconds);
    for (long i = 0; i < N; i++)
    {
        float x = rand() % (PRECISION+1) / (float)(PRECISION+1);
        float y =rand() % (PRECISION+1) / (float)(PRECISION+1);
        float sum=(x*x)+(y*y);
        if(sum < 1)  //半径R=1
        {
            M++;
        }
    }
    cout<<"M= "<<M<<endl;
    Pi=(4*(float)M)/(float)N;
    cout<<"Pi= "<<Pi<<endl;
    return 0;
}
