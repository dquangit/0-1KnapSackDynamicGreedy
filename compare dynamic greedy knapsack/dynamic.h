stack <int> choosen;
int weigh=0;
int w[maximum],p[maximum],dmax[maximum][maximum];

void d_input()
{
    file>>n>>c;
    for (int i=1;i<=n;i++)
    {
        file>>p[i]>>w[i];
    }
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
    int index;
    while (!choosen.empty())
    {
        index=choosen.top();
        weigh+=w[index];
        value+=p[index];
        choosen.pop();
    }
}

int dynamic_algorithm()
{
    d_input();
    process();
    show_result();
    return value;
}
