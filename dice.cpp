#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
using namespace std;

int main()
{
    int num = 0;
    int numSnakeEyes=0,numAceDeuce=0,numSevenOut=0,numYo=0,numBoxcars=0,numTrick=0;
    cout<<"how many times? ";
    cin>>num;
    if (num < 1)
    {
        cout<<"numbers of rolls less than one, parameter invalid"<<endl;
        return 0;
    }
    time_t seconds;
    time(&seconds);
    srand((unsigned int)seconds);
    for (int i = 0; i < num; i++)
    {
        int dices = 0;
        //time_t seconds;
        //time(&seconds);
        //srand((unsigned int)seconds);
        int roll1 = 1 + rand() % 6;
        int roll2 = 1 + rand() % 6;
        dices=roll1+roll2;

        if (dices == 2)
        {
            numSnakeEyes++;
            //cout<<"numSnakeEyes: "<<numSnakeEyes<<endl;
        }
        else if (dices == 3)
        {
            numAceDeuce++;
        }
        else if (dices == 7)
        {
            numSevenOut++;
            //cout<<"numSevenOut: "<<numSevenOut<<endl;
        }
        else if (dices == 11)
        {
            numYo++;
            //cout<<"numYo: "<<numYo<<endl;
        }
        else if (dices == 12)
        {
            numBoxcars++;
            //cout<<"numBoxcars: "<<numBoxcars<<endl;
        }
        else
        {
            numTrick++;
        }
    }
    cout<<"outcomes \t\t times \t\t percent"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"Snake eyes \t\t"<<numSnakeEyes<<"\t\t"<<numSnakeEyes*100.0/num<<"%"<<endl;
    cout<<"Ace Deuce  \t\t"<<numAceDeuce<<"\t\t"<<numAceDeuce*100.0/num<<"%"<<endl;
    cout<<"Seven Out  \t\t"<<numSevenOut<<"\t\t"<<numSevenOut*100.0/num<<"%"<<endl;
    cout<<"Yo         \t\t"<<numYo<<"\t\t"<<numYo*100.0/num<<"%"<<endl;
    cout<<"Boxcars    \t\t"<<numBoxcars<<"\t\t"<<numBoxcars*100.0/num<<"%"<<endl;
    cout<<"Trick      \t\t"<<numTrick<<"\t\t"<<numTrick*100.0/num<<"%"<<endl;

    return 0;
}
