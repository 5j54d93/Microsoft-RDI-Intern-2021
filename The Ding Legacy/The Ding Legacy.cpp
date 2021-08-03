#include <iostream>
using namespace std;

int main()
{
    int n, m;
    
    cin >> n >> m;
    
    int Z[n][m],row[n],column[m],A,B,C,a=0,b=0,c=0,ans=0;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> Z[i][j];
    
    cin >> A >> B >> C;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(j==0) row[i] = Z[i][j];
            else row[i] += Z[i][j];
        }
    
    for(int i=0;i<n-2;i++)
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=0;k<=i;k++) a += row[k];
            for(int k=i+1;k<=j;k++) b += row[k];
            for(int k=j+1;k<n;k++) c += row[k];
            
            if(a==A && b==B && c==C) ans++;
            else if(a==A && c==B && b==C) ans++;
            else if(b==A && a==B && c==C) ans++;
            else if(b==A && c==B && a==C) ans++;
            else if(c==A && a==B && b==C) ans++;
            else if(c==A && b==B && a==C) ans++;
            
            a = 0; b = 0; c = 0;
        }
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(j==0) column[i] = Z[j][i];
            else column[i] += Z[j][i];
        }
    
    for(int i=0;i<m-2;i++)
        for(int j=i+1;j<m-1;j++)
        {
            for(int k=0;k<=i;k++) a += column[k];
            for(int k=i+1;k<=j;k++) b += column[k];
            for(int k=j+1;k<m;k++) c += column[k];
            
            if(a==A && b==B && c==C) ans++;
            else if(a==A && c==B && b==C) ans++;
            else if(b==A && a==B && c==C) ans++;
            else if(b==A && c==B && a==C) ans++;
            else if(c==A && a==B && b==C) ans++;
            else if(c==A && b==B && a==C) ans++;
            
            a = 0; b = 0; c = 0;
        }
    
    cout << ans;
    
    return 0;
}
