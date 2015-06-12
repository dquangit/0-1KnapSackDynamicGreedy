#include <iostream>
#include <algorithm>
#include <stack>
#include <fstream>
#define maximum 22000
using namespace std;
fstream file;
stack <int> choosen;
int n,c;
int w[maximum],p[maximum],dmax[maximum][maximum];

struct datatype
{
    char* filename;
};
datatype data[500];

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

void input(char *filename)
{
    float capicity;
    n=f_size(filename);
    file.open(filename,ios::in);
    file>>capicity;
    c=(int)capicity;
    cout<<"input: "<<endl;
    cout<<"number of items: "<<n<<endl;
    cout<<"capacity:\t "<<c<<endl;
    for (int i=1;i<=n;i++)
    {
        file>>p[i];
    }
    for (int i=1;i<=n;i++)
    {
        file>>w[i];
    }
    file.close();
}

void process()
{
    for (int i=1;i<=n;i++)
        for (int j=0;j<=c;j++)
            if (j-w[i]>=0)
            {
                dmax[i][j]=max(dmax[i-1][j-w[i]]+p[i],dmax[i-1][j]);
            }
            else
                dmax[i][j]=dmax[i-1][j];
    while (n>0)
    {
        if (dmax[n-1][c-w[n]]+p[n]==dmax[n][c])
        {
            choosen.push(n);
            c-=w[n];
        }
        n--;
    }
}

void show_result()
{
    int index,value=0,weigh=0;
    cout<<"\noutput:"<<endl;
    cout<<"Value\tWeigh"<<endl;
    while (!choosen.empty())
    {
        index=choosen.top();
        weigh+=w[index];
        value+=p[index];
        cout<<p[index]<<"\t"<<w[index]<<endl;
        choosen.pop();
    }
    cout<<endl;
    cout<<"Value:\t\t "<<value<<endl;
    cout<<"Weigh:\t\t "<<weigh<<endl;
}

int main()
{
    get_data();
    //for (int i=0;i<25;i++)
    int i=0;
    {
        cout<<data[i].filename<<endl;
        input(data[i].filename);
        process();
        show_result();
        cout<<endl;
    }
}
