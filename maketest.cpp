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
    n=rand()%100;
    c=rand()%100;
    file<<n<<" "<<c<<endl;
    for (int i=1;i<=n;i++)
    {
        file<<rand()%100+1<<" "<<rand()%100+1<<endl;
    }


}
