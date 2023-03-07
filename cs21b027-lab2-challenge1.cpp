#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*Define your Wallet class here*/
class Wallet
{
    private:
        string order[15]={"2000","500","200","100","50","20n","10n","5n","20c","10c","5c","2","1","0.5","0.25"};
        int val[15]={0};
        double tot = 0;
    public:
        operator double() const
        {
            return tot;
        }
        int operator[](double d)
        {
            if(d==2000) return val[0];
            else if(d==500) return val[1];
            else if(d==200) return val[2];
            else if(d==100) return val[3];
            else if(d==50) return val[4];
            else if(d==20) return val[5]+val[8];
            else if(d==10) return val[6]+val[9];
            else if(d==5) return val[7]+val[10];
            else if(d==2) return val[11];
            else if(d==1) return val[12];
            else if(d==0.5) return val[13];
            else if(d==0.25) return val[14];
            else return 0;
        }
        void operator +(double d)
        {
            double inc= d;
            double sum=0;
            for(int i=0;i<15;i++)
            {
                if(i==0){int k=inc/2000;inc-=2000*k;val[i]+=k;sum+=2000*k;}
                if(i==1){int k=inc/500;inc-=500*k;val[i]+=k;sum+=500*k;}
                if(i==2){int k=inc/200;inc-=200*k;val[i]+=k;sum+=200*k;}
                if(i==3){int k=inc/100;inc-=100*k;val[i]+=k;sum+=100*k;}
                if(i==4){int k=inc/50;inc-=50*k;val[i]+=k;sum+=50*k;}
                if(i==5 || i==8){int k=inc/20;inc-=20*k;val[i]+=k;sum+=20*k;}
                if(i==6 || i==9){int k=inc/10;inc-=10*k;val[i]+=k;sum+=10*k;}
                if(i==7 || i==10){int k=inc/5;inc-=5*k;val[i]+=k;sum+=5*k;}
                if(i==11){int k=inc/2;inc-=2*k;val[i]+=k;sum+=2*k;}
                if(i==12){int k=inc/1;inc-=1*k;val[i]+=k;sum+=1*k;}
                if(i==13){int k=inc/(0.5);inc-=(0.5)*k;val[i]+=k;sum+=(0.5)*k;}
                if(i==14){int k=inc/(0.25);inc-=(0.25)*k;val[i]+=k;sum+=(0.25)*k;}
            }
            tot+=d;
        }
        void operator *(Wallet w)
        {
            double target= tot*w.tot;
            double inc= target;
            double sum=0;
            for(int i=0;i<15;i++)
            {
                if(i==0){int k=inc/2000;inc-=2000*k;val[i]=k;sum+=2000*k;}
                if(i==1){int k=inc/500;inc-=500*k;val[i]=k;sum+=500*k;}
                if(i==2){int k=inc/200;inc-=200*k;val[i]=k;sum+=200*k;}
                if(i==3){int k=inc/100;inc-=100*k;val[i]=k;sum+=100*k;}
                if(i==4){int k=inc/50;inc-=50*k;val[i]=k;sum+=50*k;}
                if(i==5 || i==8){int k=inc/20;inc-=20*k;val[i]=k;sum+=20*k;}
                if(i==6 || i==9){int k=inc/10;inc-=10*k;val[i]=k;sum+=10*k;}
                if(i==7 || i==10){int k=inc/5;inc-=5*k;val[i]=k;sum+=5*k;}
                if(i==11){int k=inc/2;inc-=2*k;val[i]=k;sum+=2*k;}
                if(i==12){int k=inc/1;inc-=1*k;val[i]=k;sum+=1*k;}
                if(i==13){int k=inc/(0.5);inc-=(0.5)*k;val[i]=k;sum+=(0.5)*k;}
                if(i==14){int k=inc/(0.25);inc-=(0.25)*k;val[i]=k;sum+=(0.25)*k;}
            }
            tot=sum;
        }
        void operator *(double d)
        {
            double target= tot*d;
            double inc= target;
            double sum=0;
            for(int i=0;i<15;i++)
            {
                if(i==0){int k=inc/2000;inc-=2000*k;val[i]=k;sum+=2000*k;}
                if(i==1){int k=inc/500;inc-=500*k;val[i]=k;sum+=500*k;}
                if(i==2){int k=inc/200;inc-=200*k;val[i]=k;sum+=200*k;}
                if(i==3){int k=inc/100;inc-=100*k;val[i]=k;sum+=100*k;}
                if(i==4){int k=inc/50;inc-=50*k;val[i]=k;sum+=50*k;}
                if(i==5 || i==8){int k=inc/20;inc-=20*k;val[i]=k;sum+=20*k;}
                if(i==6 || i==9){int k=inc/10;inc-=10*k;val[i]=k;sum+=10*k;}
                if(i==7 || i==10){int k=inc/5;inc-=5*k;val[i]=k;sum+=5*k;}
                if(i==11){int k=inc/2;inc-=2*k;val[i]=k;sum+=2*k;}
                if(i==12){int k=inc/1;inc-=1*k;val[i]=k;sum+=1*k;}
                if(i==13){int k=inc/(0.5);inc-=(0.5)*k;val[i]=k;sum+=(0.5)*k;}
                if(i==14){int k=inc/(0.25);inc-=(0.25)*k;val[i]=k;sum+=(0.25)*k;}
            }
            tot=sum;
        }
        void operator +(Wallet w)
        {
            for(int i=0;i<15;i++)
            {
                val[i]+=w.val[i];
            }
            tot+=w.tot;
        }
        void operator -(Wallet w)
        {
            for(int i=0;i<15;i++)
            {
                val[i]-=w.val[i];
            }
            tot-=double(w);
        }
        friend istream & operator >> (istream & in, Wallet & w);
        friend ostream & operator << (ostream & out, Wallet & w);
        
};
istream & operator >> (istream & in, Wallet & w)
{
    w.tot=0;
    int v[15];
    for(int i=0;i<15;i++)
    {
        in >> v[i];
        w.val[i] = v[i];
        if(i==0) w.tot+=2000*v[i];
        if(i==1) w.tot+=500*v[i];
        if(i==2) w.tot+=200*v[i];
        if(i==3) w.tot+=100*v[i];
        if(i==4) w.tot+=50*v[i];
        if(i==5) w.tot+=20*v[i];
        if(i==6) w.tot+=10*v[i];
        if(i==7) w.tot+=5*v[i];
        if(i==8) w.tot+=20*v[i];
        if(i==9) w.tot+=10*v[i];
        if(i==10) w.tot+=5*v[i];
        if(i==11) w.tot+=2*v[i];
        if(i==12) w.tot+=1*v[i];
        if(i==13) w.tot+=(0.5)*v[i];
        if(i==14) w.tot+=(0.25)*v[i];
    }
    return in;
}

ostream & operator << (ostream & out, Wallet & w)
{
    for(int i=0;i<15;i++)
    {
        out<<"("<<w.order[i]<<" "<<w.val[i]<<")"<<" ";
    }
    return out;
}

int main()
{
    int N;
    cin >> N;
    Wallet w,w1;
    int command;
    double d;
    for (int i = 0; i < N; i++)
    {
        cin >> command;
        switch (command)
        {
            case 1: /*initialize wallet*/
                cin >> w;
                break;
            
            case 2: /*print wallet*/
                cout << "Wallet contains: " << w << endl;
                break;
            
            case 3: /*wallet balance*/
                cout << "Wallet has balance: " << (double) w << endl;
                break;
            
            case 4: /*denomination query*/
                cin >> d;
                cout << "Wallet contains " << w[d] << " number of notes/coins of denomination " << d << endl;
                break;
            
            case 5: /*add two wallets*/
                cin >> w1;
                w + w1;
                break;
            
            case 6: /*add money to wallet*/
                cin >> d;
                w + d;
                break;

            case 7: /*subtract from wallet*/
                cin >> w1;
                //cout << double(w1) <<"*"<<endl;
                w - w1;
                break;
            
            case 8: /*multiply wallets*/
                cin >> w1;
                w * w1;
                break;
            
            case 9: /*multiply wallet and double*/
                cin >> d;
                w * d;
                break;

            default:
                break;
        }
    }
}