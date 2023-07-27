#include <iostream>
#include <string>
#include <sstream>
#include<fstream>
#include <string.h>
#include <vector>
#include <iomanip>

using namespace std;
#define MAX_NUM 3

enum BILL_INCOME_TYPE {
	INCOME_ONE = 100,
    INCOME_TWO,
    INCOME_THREE,
};

enum BILL_EXPENSES_TYPE {
    EXPENSES_ONE = 200,
    EXPENSES_TWO,
    EXPENSES_THREE
};

struct bill_info_t {
   int type;
   int year;
   int month;
   int day;
   double money;
   string notes;
};

vector<bill_info_t> v_bill;

string income[MAX_NUM]={"生活费","奖学金","稿费"};
string expenses[MAX_NUM]={"学习用品","生活用品","游戏"};

void print_bill_list()
{
    cout<<"类别编码和类别名称的对应关系如下："<<endl;
    cout<<"收入类：";
    for (int i = 0; i < MAX_NUM; i++)
    {
        cout<<"a"<<i+1<<"-"<<income[i]<<" ";
    }
    cout<<endl;
    cout<<"支出类: ";
    for (int i = 0; i < MAX_NUM; i++)
    {
        cout<<"b"<<i+1<<"-"<<expenses[i]<<" ";
    }
    cout<<endl;
}
int parse_bill_type(char *in_str)
{
    if (!strcmp(in_str, "a1"))
    {
        return INCOME_ONE;
    }
    else if (!strcmp(in_str, "a2"))
    {
        return INCOME_TWO;
    }
    else if (!strcmp(in_str, "a3"))
    {
        return INCOME_THREE;
    }
    else if (!strcmp(in_str, "b1"))
    {
        return EXPENSES_ONE;
    }
    else if (!strcmp(in_str, "b2"))
    {
        return EXPENSES_TWO;
    }
    else if (!strcmp(in_str, "b3"))
    {
        return EXPENSES_THREE;
    }
    else
    {
        cout<<"类别编码输入错误"<<endl;
        return -1;
    }
}

void save_input_record(string record)
{
    ofstream out("record.txt",ios::app);
    out<<record;
    cout<<"\n";
    out.close();
}

int parse_input(char *data)
{
    char *p = strtok(data, " ");
    if (p ==NULL)
    {
        return -1;
    }
    int type = parse_bill_type(p);
    if(-1 == type)
    {
        return -1;
    }
    p = strtok(NULL," ");
    int year=0,month=0,day=0;
    sscanf(p, "%d-%d-%d", &year, &month, &day);
    //cout<<"******"<<type<<endl;
    //cout<<"******"<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
    p = strtok(NULL," ");
    double money = atof(p);
    //cout<<"******"<<money<<endl;
    p = strtok(NULL," ");
    string note = (p == NULL)?  "" : p;

    //cout<<"******"<<note<<endl;
    bill_info_t tmp;
    tmp.type = type;
    tmp.year = year;
    tmp.month =month;
    tmp.day = day;
    tmp.money = money;
    tmp.notes = note;

    v_bill.push_back(tmp);
    return 0;

}
void input_data()
{
    string instr;
    cout<<"请逐笔输入类别编码、发生日期、金额、备注（各数据用一个或多个连续空格分隔,直接输入回车表示输入结束):" << endl;
    cout<<"example: a1 2020-1-1 234.00 生活开销";
    do
    {
        printf("输入收支明细: ");

        getline(cin, instr);
        char *p= const_cast<char *>(instr.c_str());
        if(-1 !=parse_input(p))
        {
            save_input_record(instr);
        }
    }while(instr != "");

}
void print_detail_bill(int year, int month)
{
    cout <<"是否输出该月的各笔明细(y 为输出，其他为不输出):";
    string input;
    cin>>input;
    if(input != "y")
    {
        return;
    }
    cout<<year<<"年"<<month<<"月收支类别数据的明细"<<endl;
    cout<<"类别      收入/支出   发生日期     金额    备注"<<endl;

    for (int i = 0; i < v_bill.size(); i++) 
        {
            if (v_bill[i].year == year && v_bill[i].month == month)
            {
                if(v_bill[i].type >= INCOME_ONE && v_bill[i].type <= INCOME_THREE)
                {
                    cout<<setw(12)<<income[v_bill[i].type -INCOME_ONE]<<"  收入";
                }  
                
                if (v_bill[i].type >= EXPENSES_ONE && v_bill[i].type <= EXPENSES_THREE)
                {
                    cout<<setw(12)<<expenses[v_bill[i].type - EXPENSES_ONE]<<"  支出";
                }
                cout<<"      "<<v_bill[i].year<<"-"<<v_bill[i].month<<"-"<<v_bill[i].day;
                cout<<"      "<<fixed<<setprecision(2)<<v_bill[i].money<<"  "<<v_bill[i].notes<<endl;

            }
        }
        cout<<endl;
}
void print_bill_sum(int year, int month)
{
    double income_sum = 0;
    double expenses_sum = 0;
    cout<<year<<"年"<<month<<"月收支类别数据的汇总"<<endl;
    cout <<"收入/支出  明细类别     金额"<<endl;
    for (int i = 0; i < v_bill.size(); i++) 
    {

        if (v_bill[i].year == year && v_bill[i].month == month)
        {
            if(v_bill[i].type >= INCOME_ONE && v_bill[i].type <= INCOME_THREE)
            {
                cout<<"收入       "<<setw(12)<<income[v_bill[i].type -INCOME_ONE];
                income_sum += v_bill[i].money;
            }  
            
            if (v_bill[i].type >= EXPENSES_ONE && v_bill[i].type <= EXPENSES_THREE)
            {
                cout<<"支出       "<<setw(12)<<expenses[v_bill[i].type - EXPENSES_ONE];
                expenses_sum += v_bill[i].money;
            }

            cout<<"    "<<fixed<<setprecision(2)<<v_bill[i].money<<endl;
        }
    }
    cout<<endl;
    cout <<year<<"年"<<month<<"月的总收入为: "<<fixed<<setprecision(2)<<income_sum<<", 总支出为: "<<expenses_sum<<endl;
 
}
void get_bill_with_month()
{
    cout<<"请输入对收支类别数据进行汇总的月份: ";
    string instr;
    int year,month;
    getline(cin, instr);
    char *p= const_cast<char *>(instr.c_str());
    sscanf(p, "%d-%d", &year, &month);
    cout.setf(ios::left);
    print_bill_sum(year,month);
    print_detail_bill(year, month);
}


int main()
{
    print_bill_list();
    try
    {
        input_data();
    }
    catch(...)
    {
        cout<<"输入格式异常"<<endl;
    }
    get_bill_with_month();
    return 0;
}