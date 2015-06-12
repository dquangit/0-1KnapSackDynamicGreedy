bool myfunction(int a,int b)
{
    if (a>b) return true;
    else return false;
}
int value=0, weight=0;
pair <int, pair<int,int> > item[maximum];
void g_input()
{
    file>>n>>c;
    pair <int, pair<int,int> > tmp;
    for (int i=1;i<=n;i++)
    {
        file>>item[i].second.first>>item[i].second.second;
        item[i].first=item[i].second.first/item[i].second.second;
    }
}

void greedy()
{
    sort(item+1,item+n+1);
    for (int i=n; i>0; i--)
    {
        if (c - item[i].second.second>=0)
        {
            c -= item[i].second.second;
            weight+=item[i].second.second;
            value += item[i].second.first;
        }
    }
}

int greedy_algorithm()
{
    g_input();
    greedy();
    return value;
}
