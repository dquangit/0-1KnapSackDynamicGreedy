#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
fstream file;
int main()
{
    int n,c;
    srand (time(NULL));
    file.open("knapsack.txt",ios::out);
    for (int k=0;k<1000;k++)
    {
        n=rand()%100+10;
        c=rand()%100+10;
        file<<n<<" "<<c<<endl;
        for (int i=1;i<=n;i++)
        {
            file<<rand()%100+5<<" "<<rand()%100+5<<endl;
        }
    }

}
