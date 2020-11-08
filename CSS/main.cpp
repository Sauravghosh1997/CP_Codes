//CSS: https://www.codechef.com/problems/CSS2/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map< int,unordered_map<int,pair<int,int>> > mp;
    while(n--)
    {
        int id,attr,val,pri;
        cin>>id>>attr>>val>>pri;
        if(mp.find(id)== mp.end())
            mp[id][attr]= make_pair(val, pri);
        else
        {
            if(mp[id].find(attr) == mp[id].end())
                mp[id][attr]= make_pair(val,pri);
            else
            {
                if(pri >= mp[id][attr].second)
                    mp[id][attr]=make_pair(val,pri);
            }
        }
    }
    while(m--)
    {
        int id, attr;
        cin>>id>>attr;
        cout<<mp[id][attr].first<<endl;
    }
    return 0;
}
