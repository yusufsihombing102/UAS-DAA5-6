#include <iostream>
#include <string.h>
using namespace std;

void preKMP(string x, int m, int kmpNext[])
{
    int i,j;
    i=0;
    j=kmpNext[0]=-1;
    while (i<m)
    {
        while (j>-1&&x[i]!=x[j])
        {
            j=kmpNext[j];
        }
        i++;
        j++;
        if(x[i]==x[j])
        {
            kmpNext[i]=kmpNext[j];
        }
        else
        {
            kmpNext[i]=j;
        }
        
    }
}
void KMP(string x, int m, string y, int n)
{
    int i,j,kmpNext[m];
    preKMP(x,m,kmpNext);
    cout<<"Tabel kmpNext : "<<endl;
    for(int a=0; a<=m; a++)
    {
        cout<<kmpNext[a]<<" ";
    }
    cout<<endl<<endl;
    i=j=0;
    while(j<n)
    {
        while (i>-1&&x[i]!=y[j])
        {
            i=kmpNext[i];
        }
        i++;
        j++;
        if(i>=m)
        {
            cout<<"Ditemukan di indeks : "<<(j-i)<<endl;
            i=kmpNext[i];
        }
        else if(i<m && j==n)
        {
            cout<<endl;
            cout<<"Data Tidak Ditemukan";
        }
    }
}

int main()
{
    string text;
    string pattern;
    cout<<"Masukkan Kata/Kalimat : ";
    getline(cin,text);
    cout<<endl;
    cout<<"Masukkan Kata/Kalimat yang mau dicara : ";
    getline(cin,pattern);
    cout<<endl;
    KMP(pattern,pattern.length(),text,text.length());
    return 0;
}
