#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{    
	int datalen=0;    
	double num[1500] = {0};

    ifstream fin("random.txt");
    istream_iterator<int> begin(fin),end;
    vector<int> vecInt(begin, end);
    for (auto itr = vecInt.cbegin(); itr != vecInt.cend(); ++itr)
    {
        num[datalen++] = *itr;        
        //cout<<*itr<<" ";
    }
    cout<<"datalen="<<datalen<<endl;

    double sum=0;
    for(int i=0;i<datalen-1;i++)    
    {        
    	sum += num[i];    
    }
    cout<<"sum="<<sum<<endl;

    double average =sum/datalen-1;
    cout<<"average="<<average<<endl;

    double max=num[0];
    for(int i=1;i<datalen-1;i++)    
    {        
    	if(num[i] > max)
        {
            max = num[i];
        }    
    }
    cout<<"max="<<max<<endl;
    double min=num[0];
    for(int i=1;i<datalen-1;i++)    
    {        
    	if(num[i] < min)
        {
            min = num[i];
        }    
    }
    cout<<"min="<<min<<endl;
    int num_max=0,num_min=0;
    for(int i=0;i<datalen-1;i++)    
    {        
    	if(max == num[i])
        {
            num_max++;
        }
   
        if(min == num[i])
        {
            num_min++;
        }
    }
    cout<<"max number of occurrences is "<<num_max<<endl;
    cout<<"min number of occurrences is "<<num_min<<endl;

    return 0;
}