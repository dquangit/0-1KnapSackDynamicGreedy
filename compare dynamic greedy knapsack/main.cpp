#include "global.h"
#include "greedy.h"
#include "dynamic.h"
int dynamics[maximum],greedys[maximum];
int main()
{
    file.open("knapsack.txt",ios::in);
    for (int k=0;k<10000;k++)
    {
        weigh=0;
        value=0;
        dynamics[k]=dynamic_algorithm();
    }
    file.close();

    file.open("knapsack.txt",ios::in);
    for (int k=0;k<10000;k++)
    {
        weight=0;
        value=0;
        greedys[k]=greedy_algorithm();
    }
    file.close();

    int dem=0,de=0;
    int both=0;
    file.open("cmparelog.txt",ios::out);
    file<<"Greedy\tDynamic\n";
    for (int i=0;i<10000;i++)
        {
            file<<greedys[i]<<"\t"<<dynamics[i]<<"\t";
            if (greedys[i]<dynamics[i])
                {
                    dem++;
                    file<<"Dynamic"<<endl;
                }
            else if (greedys[i]==dynamics[i])
                    {
                        both++;
                        file<<"Both"<<endl;
                    }
                else if (greedys[i]>dynamics[i])
                        {
                            de++;
                            file<<"Greedy"<<endl;
                        }
        }

    cout<<"dynamic: "<<dem<<endl;
    cout<<"greedy: "<<de<<endl;
    cout<<"both: "<<both<<endl;
}
