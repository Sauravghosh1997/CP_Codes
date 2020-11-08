//https://www.codechef.com/problems/CAMC

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector< pair<long,int> > v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i].first;
            v[i].second=i%m;
        }
        sort(v.begin(),v.end());
        vector< int > colors(m,0);
        int right=0;
        int count=m;
        long res=1e18;
        for(int left=0; left<n; left++)
        {
            while( right<n && count>0)
            {
                count-= colors[v[right].second]==0;
                colors[v[right].second]++;
                right++;
            }
            if(count==0)
                 res=min(res, v[right-1].first - v[left].first);
            if(colors[v[left].second]>0)
                colors[v[left].second]--;
            count+= colors[v[left].second] == 0;
        }
        cout<<res<<endl;
    }
    return 0;
}
