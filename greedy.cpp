#include <iostream>
#include <fstream>
#include <stack>
#include <algorithm>
#define maximum 100001
using namespace std;
fstream file;

struct datatype
{
    char* filename;
};
datatype data[maximum];
void get_data()
{
data[0].filename="data/s10.txt";
data[1].filename="data/s10-1.txt";
data[2].filename="data/s50.txt";
data[3].filename="data/s50-1.txt";
data[4].filename="data/s100.txt";
data[5].filename="data/s100-1.txt";
data[6].filename="data/s500.txt";
data[7].filename="data/s500-1.txt";
data[8].filename="data/s1000.txt";
data[9].filename="data/s1000-1.txt";
data[10].filename="data/s5000.txt";
data[11].filename="data/s5000-1.txt";
data[12].filename="data/s10000.txt";
data[13].filename="data/s10000-1.txt";
data[14].filename="data/s100000.txt";
data[15].filename="data/u10.txt";
data[16].filename="data/u50.txt";
data[17].filename="data/u100.txt";
data[18].filename="data/u500.txt";
data[19].filename="data/u1000.txt";
data[20].filename="data/wc10.txt";
data[21].filename="data/wc50.txt";
data[22].filename="data/wc1000.txt";
data[23].filename="data/wc5000.txt";
data[24].filename="data/wc10000.txt";
}

int f_size(char* filename)
{
    float capicity;
    file.open(filename,ios::in);
    file>>capicity;
    int t;
    int d=0;
    while(file)
    {
        file>>t;
        d++;
    }
    file.close();
    return d/2;
}

bool myfunction(int a,int b)
{
    if (a>b) return true;
    else return false;
}
int n;
float c;
int value=0, weight=0;
pair <int, pair<int,int> > item[maximum];

void input(char* filename)
{
    n=f_size(filename);
    value=0;
    weight=0;
    file.open(filename,ios::in);
    file>>c;
    cout<<"input: "<<endl;
    cout<<"number of items: "<<n<<endl;
    cout<<"capacity:\t "<<c<<endl;
    pair <int, pair<int,int> > tmp;
    for (int i=1;i<=n;i++)
    {
        file>>item[i].second.first;

    }
    for (int i=1;i<=n;i++)
    {
        file>>item[i].second.second;
    }
    for (int i=1;i<=n;i++)
    {
        item[i].first=item[i].second.first/item[i].second.second;
    }
    file.close();
}
void output()
{
    for (int i=1;i<=n;i++)
    {
        cout<<item[i].second.first<<"\t"<<item[i].second.second<<"\t"<<item[i].first<<endl;
    }
}

void greedy()
{
    sort(item+1,item+n+1);
    cout<<endl;
    cout<<"output: "<<endl;
    cout<<"Value\tWeigh"<<endl;
    for (int i=n; i>0; i--)
    {
        if (c - item[i].second.second>=0)
        {
            c -= item[i].second.second;
            weight+=item[i].second.second;
            value += item[i].second.first;
            cout<<item[i].second.first<<"\t"<<item[i].second.second<<endl;
        }
    }
    cout<<endl;
    cout<<"Value:\t\t "<<value<<endl;
    cout<<"Weigh:\t\t "<<weight<<endl;
}

int main()
{
    get_data();
    //for (int i=0;i<25;i++)
    int i=0;
    {
    cout<<data[i].filename<<endl;
    input(data[i].filename);
    greedy();
    cout<<endl;
    }
}
