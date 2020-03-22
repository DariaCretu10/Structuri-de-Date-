#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
long long Maxi(long long v[], long long n)
{int maxi=v[1];
 for(int i=2;i<=n;i++)
    if(v[i]>maxi) maxi=v[i];
 return maxi;
}
void BubbleSort(long long v[], long long n)
{
 for(long long i=0;i<n-1;i++)

    for(long long j=0;j<n-i-1;j++)

        if(v[j]>v[j+1])

             swap(v[j],v[j+1]);

}
void CountSort(long long v[], long long n)
{long long mini,maxi; mini=v[1]; maxi=v[1];

 long long fr[100001];

 for(long long i=1;i<=n;i++)

    {fr[v[i]]++;

     if(v[i]>maxi) maxi=v[i];

     if(v[i]<mini) mini=v[i];

    }
 for(int i=mini;i<=maxi;i++)
    while(fr[i]) {cout<<i<<" "; fr[i]--;}

}
void RadixSort(long long v[],long long n)
{int m=Maxi(v,n), c, i;

 long long e,grupe[10001][10001],d[100001];

 for(e=1;m/e>1;e*=10)

    {for(i=0;i<10;i++)
        d[i]=0;

     for(i=1;i<=n;i++)
        {c=v[i]/e%10;
        d[c]++;
        grupe[c][d[c]]=v[i];
        }
     n=0;
     for(i=0;i<10;i++)
        for(int j=0;j<=d[i];j++)
            v[n++]=grupe[i][j];

}

void Merge(long long v[], long long m, long long s, long long d)
{ int n1, n2;
  n1=m-s+1;
  n2=r-m;

  for(i=0;i<n1;i++)
    s[i]=v[i+1];

  for(j=0;j<n2;j++)
    d[j]=v[m+1+j];

  j=0;i=0;k=1;

  while(i<n1&&j<n2)
    if(s[i]<d[j])
        v[k++]=s[i++];
    else
        v[k++]=d[j++];
  while(i<n1)
       v[k++]=s[i++];
  while(j<n2)
       v[k++]=d[j++];

}

void MergeSort(long long v[], int s, int d)
{
  if(s<d)
    {int m=l+(r-1)/2;
     MergeSort(v,l,m);
     MergeSort(v,m+1,d);
     Merge(v,m,l,d);
    }

}

void QuickSort(long long v[], int s, int d)
{
if(s<d)
{
 int i=s; int j=d;
 int pi=v[(s+d)/2];
 while(i<=j)
    {while(v[i]<pi)
        i++;
     while(v[j]>pi)
        j--;
     if(i<=j)
        {swap(v[i],v[j]);
        i++;
        j--;
        }
    }
 QuickSort(v,s,j);
 QuickSort(v,i,d);
}
}

void QuickSort2(long long v[], int s, int d)
{
if(s<d)
{
 int i=s; int j=d;
 int pi=rand()Maxi(v,d);
 while(i<=j)
    {while(v[i]<pi)
        i++;
     while(v[j]>pi)
        j--;
     if(i<=j)
        {swap(v[i],v[j]);
        i++;
        j--;
        }
    }
 QuickSort2(v,s,j);
 QuickSort2(v,i,d);
}
}

void repunere(long long a[], long long x[], long long n)
{for(int i=1;i<=n;i++)
    a[i]=x[i];
}
int Testare(long long v[], int n)
{for(int i=1;i<=n;i++)
    if(v[i]>v[i+1])
        return 0;
 return 1;
}
int main()
{long long a[100001], m, n, i, t, x[100001];
 clock_t Start;
 clock_t Final;
 ifstream f("date.in");
 f>>t;
 while(t)
    {f>>n>>m;
     for(i=1;i<=n;i++)
        x[i]=rand()*rand()%m;
     Start=clock();
     repunere(a,x,n);
     BubbleSort(a,n);
     Final=Clock(); cout<<"BubbleSort"<<(Final-Start)/CLOCK_PER_SEC<<" "<<Testare(v,n)<<endl;
     repunere(a,x,n); Start=clock();
     CountSort(a,n);
     Final=clock(); cout<<"CountSort"<<(Final-Start)/CLOCK_PER_SEC<<" "<<Testare(v,n)<<endl;
     repunere(a,x,n); Start=clock();
     RadixSort(a,n);
     Final=clock(); cout<<"RadixSort"<<(Final-Start)/CLOCK_PER_SEC<<" "<<Testare(v,n)<<endl;
     repunere(a,x,n); Start=clock();
     MergeSort(a,1,n);
     Final=clock(); cout<<"MergeSort"<<(Final-Start)/CLOCK_PER_SEC<<" "<<Testare(v,n)<<endl;
     repunere(a,x,n); Start=clock();
     QuickSort(v,1,n);
     Final=clock(); cout<<"QuickSort"<<(Final-Start)/CLOCK_PER_SEC<<" "<<Testare(v,n)<<endl;
     repunere(a,x,n); Start=clock();
     QuickSort2(v,1,n);
     Final=clock(); cout<<"QuickSort2"<<(Final-Start)/CLOCK_PER_SEC<<" "<<Testare(v,n)<<endl;

    }

    return 0;
}
