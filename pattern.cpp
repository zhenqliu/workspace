#include <iostream>
using namespace std;

#define  MAX_LINE_NUM 10
int main() {
    cout<<"pattern B"<<endl;
	for (int i = 0; i < MAX_LINE_NUM; i++)  //how many lines
    {
        for (int j = 0; j <= i; j++) // how many char '+' for per line
        {
            cout<<"+";
        }
        cout<<endl;
        
    }
    
    cout<<endl;

    cout<<"pattern B"<<endl;
    //pattern B
    for (int i = MAX_LINE_NUM; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<"+";
        }
        cout<<endl;
    }
	return 0;
}