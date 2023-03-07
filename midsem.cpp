#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Wallet
{
     
    public:
        string name;
        vector<float> deno;
        explicit Wallet()
        {}
        void load(vector<float> den, string s)
        {
            name = s;
            int n=den.size();
            for(int i=0;i<n;i++)
            {
                deno.push_back(den[i]);
            }
        }
        int size()
        {
            return deno.size();
        }
        void print()
        {
            cout<<name<<endl;
            int n=deno.size();
            for(int i=0;i<n;i++)
                cout<<deno[i]<<" ";
            cout<<endl;
        }
        float value(vector<int> given)
        {
            float ans=0;
            int n=deno.size();
            for(int i=0;i<n;i++)
            {
                ans+=deno[i]*given[i];
            }
            return ans;
        }
        void fill(float val)
        {
            int n=deno.size();
            vector<int> ans(n);
            for(int i=0;i<n;i++)
            {
                ans[i]=0;
            }
            for(int i=0;i<n;i++)
            {
                int z=val/deno[i];
                val-=z*deno[i];
                ans[i]+=z;
            }
            
            for(int i=0;i<n;i++)
            {
                cout<<"("<<deno[i]<<" "<<ans[i]<<") ";
            }
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    vector<Wallet> cur(n);
    vector<string> ind;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int k;
        cin>>k;
        vector<float> denom;
        for(int i=0;i<k;i++)
        {
            float a;cin>>a;
            denom.push_back(a);
        }
        cur[i].load(denom,s);
        ind.push_back(s);
    }
    // for(int i=0;i<n;i++)
    // {
    //     cur[i].print();
    // }
    int m=(n*(n-1))/2;
    vector<pair<int,int> > p;
    vector<float> rate;
    for(int j=0;j<m;j++)
    {
        int a,b;
        float r;
        cin>>a>>b>>r;
        
        p.push_back({a,b});
        rate.push_back(r);
    }
    int command,l;
    cin>>command>>l;
    //cout<<command;
    //cout<<(command==1)<<endl;
    if(command==1)
    {
        //cout<<"inside";
        //cout<<"here";
        for(int j=0;j<l;j++)
        {
            //cout<<"herealso";
            string h;
            cin>>h;
            auto itr=find(ind.begin(),ind.end(),h);
            int index=std::distance(ind.begin(),itr);
            int b=cur[index].size();
            vector<int> given;
            for(int i=0;i<b;i++)
            {
                int r;cin>>r;
                given.push_back(r);
            }
            float val=cur[index].value(given);
            string h2;
            cin>>h2;
            auto itr2=find(ind.begin(),ind.end(),h2);
            int index2=std::distance(ind.begin(),itr2);
            auto itr3=find(p.begin(),p.end(),make_pair(index+1,index2+1));
            int flag=0;
            if(itr3==p.end())
            {
                itr3=find(p.begin(),p.end(),make_pair(index2+1,index+1));
                flag=1;
            }
            int i3=std::distance(p.begin(),itr3);
            //cout<<val<<endl;
            //cout<<i3<<endl;
            if(flag==0)
                val*=rate[i3];
            else
                val/=rate[i3];
            //cout<<val<<endl;
            cout<<h2<<" ";
            //cout<<index<<" "<<index2<<endl;
            cur[index2].fill(val);
            cout<<endl;
        }
    }
    else
    {
        int key=l;
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            if(find(p.begin(),p.end(),make_pair(key,i))!=p.end() || find(p.begin(),p.end(),make_pair(i,key))!=p.end())
            {
                v.push_back(i);
            }
        }
        int flag=0;
        int g=v.size();
        for(int i=0;i<g;i++)
        {
            for(int j=0;j<g;j++)
            {
                 if(find(p.begin(),p.end(),make_pair(v[i],v[j]))!=p.end() || find(p.begin(),p.end(),make_pair(v[j],v[i]))!=p.end())
                 {
                     float ans=1;
                     if(find(p.begin(),p.end(),make_pair(key,v[i]))!=p.end())
                     {
                         auto itr3=find(p.begin(),p.end(),make_pair(key,v[i]));
                         int i3=std::distance(p.begin(),itr3);
                         ans*=rate[i3];
                     }
                     else
                     {
                         auto itr3=find(p.begin(),p.end(),make_pair(v[i],key));
                         int i3=std::distance(p.begin(),itr3);
                         ans/=rate[i3];
                     }
                     
                     if(find(p.begin(),p.end(),make_pair(v[i],v[j]))!=p.end())
                     {
                         auto itr3=find(p.begin(),p.end(),make_pair(v[i],v[j]));
                         int i3=std::distance(p.begin(),itr3);
                         ans*=rate[i3];
                     }
                     else
                     {
                         auto itr3=find(p.begin(),p.end(),make_pair(v[j],v[i]));
                         int i3=std::distance(p.begin(),itr3);
                         ans/=rate[i3];
                     }
                     
                     if(find(p.begin(),p.end(),make_pair(v[j],key))!=p.end())
                     {
                         auto itr3=find(p.begin(),p.end(),make_pair(v[j],key));
                         int i3=std::distance(p.begin(),itr3);
                         ans*=rate[i3];
                     }
                     else
                     {
                         auto itr3=find(p.begin(),p.end(),make_pair(key,v[j]));
                         int i3=std::distance(p.begin(),itr3);
                         ans/=rate[i3];
                     }
                     if(ans!=1)
                     {
                        flag=1;break;
                     }
                 }
            }
            if(flag)
                break;
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

}
