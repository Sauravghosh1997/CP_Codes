#include <bits/stdc++.h>

using namespace std;

int main()
{
        int n;
        long count=0;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        vector<int> lhs;
        vector<int> rhs;
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<n; b++)
            {
                for(int c=0; c<n; c++)
                {
                    lhs.push_back(v[a]*v[b]+v[c]);
                }
            }
        }
        for(int d=0; d<n; d++)
        {
            for(int e=0; e<n; e++)
            {
                for(int f=0; f<n; f++)
                {
                    if(v[d]==0)
                       continue;
                    rhs.push_back( (v[f]+v[e])*v[d] );
                }
            }
        }
        sort(lhs.begin(),lhs.end());
        sort(rhs.begin(),rhs.end());
        /*for(int i=0;i<lhs.size();i++)
        {
            for(int j=0; j<rhs.size(); j++)
            {
                if(lhs[i]==rhs[j])
                    count++;
            }
        }*/
        for(int i=0;i<lhs.size();i++)
        {
            int low=lower_bound(rhs.begin(),rhs.end(),lhs[i])-rhs.begin();
            int high=upper_bound(rhs.begin(),rhs.end(),lhs[i])-rhs.begin();
            count+=high-low;
        }
        cout<<count;
    return 0;
}
