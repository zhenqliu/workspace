#include <iostream>

using namespace std;

int main()
{ 
    int speed,hours;
    cout<<"What is the speed of the vehicle in mph?";
    cin>>speed;
    if(speed < 0)
    {
        cout<<"the input is invalid"<<endl;
        return 0;
    }
    cout<<"How many hours has it traveled?";
    cin>>hours;
    if(hours < 1)
    {
        cout<<"the input is invalid"<<endl;
        return 0;
    }
    cout <<"Hour\t\tDistance Traveled"<<endl;
    cout<<"---------------------------------------"<<endl;
    for (int i = 1; i <= hours; i++)
    {
        cout<<i<<"\t\t"<<speed*i<<endl;
    }
    
return 0;
}