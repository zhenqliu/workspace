#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{ 
    double emploeeNo,grossPay,salesTax,federalTax,fica;
    while (1)
    {
        cout<<"input employee number: ";
        cin>>emploeeNo;
        if (0 == emploeeNo)
        {
            return 0;
        }
        cout<<"input gross pay: ";
        cin>>grossPay;
        cout<<"input sales tax: ";
        cin>>salesTax;
        cout<<"input federal tax: ";
        cin>>federalTax;
        cout<<"input FICA withholdings: ";
        cin>>fica;
        if (emploeeNo<0 || grossPay<0 || salesTax<0 || federalTax<0 || fica<0)
        {
            cout<<"input is invalid"<<endl;
            return 0;
        }
        double netpay=grossPay-salesTax-federalTax-fica;
        if(netpay < 0)
        {
            cout<<"inout data is invalid, please input right data"<<endl;
            break;
        }
        else
        {
            cout<<"gross pay\tstate tax\tFICA withholdings \tnet pay"<<endl;
            cout<<"------------------------------------------------------------------------"<<endl;
            cout<<grossPay<<"\t\t"<<salesTax+federalTax<<"\t\t"<<fica<<"\t\t\t"<<netpay<<endl;
            
        }
        cout<<"if need continue get employee, please input 1,otherwise exit process! please input: ";
        int confirm;
        cin>>confirm;
        if (confirm != 1)
        {
            return 0;
        }
    }
    
    

    return 0;

}