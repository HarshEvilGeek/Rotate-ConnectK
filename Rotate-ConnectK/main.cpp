//
//  main.cpp
//  Rotate-ConnectK
//
//  Created by Akhil Verghese on 3/12/13.
//  Copyright (c) 2013 Akhil Verghese. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[])
{
    int t,n,k;
    char N[50][50],OldN[50][50];
    scanf("%d",&t);
    int x=0;
    while(t--)
    {
        x++;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%s",OldN[i]);
            for(int j=0;j<n;j++)
                N[i][j]='.';
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                N[i][j]=OldN[n-j-1][i];
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            int current=n-1;
            for(int j=n-1;j>=0;j--)
            {
                if(N[j][i]=='B'||N[j][i]=='R')
                {
                    N[current][i]=N[j][i];
                    if(current!=j)
                        N[j][i]='.';
                    current--;
                }
                
            }
        }

        
        int countrowR=0, countrowB=0, countcolR=0, countcolB=0, countrdiaR=0, countldiaR=0, countrdiaB=0, countldiaB=0, countrevrdiaR=0, countrevldiaR=0, countrevrdiaB=0, countrevldiaB=0;
        bool flagR=0,flagB=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0; j<n;j++)
            {
                
                if(N[i][j]=='B')
                    countrowB++;
                else
                    countrowB=0;
                if(N[i][j]=='R')
                    countrowR++;
                else
                    countrowR=0;
                if(N[j][i]=='B')
                    countcolB++;
                else
                    countcolB=0;
                if(N[j][i]=='R')
                    countcolR++;
                else
                    countcolR=0;
                if((i+j)<n)
                {
                    if(N[j+i][j]=='R')
                        countldiaR++;
                    else
                        countldiaR=0;
                    if(N[j+i][j]=='B')
                        countldiaB++;
                    else
                        countldiaB=0;
                    if(N[j][j+i]=='R'&i!=0)
                        countrdiaR++;
                    else
                        countrdiaR=0;
                    if(N[j][j+i]=='B'&i!=0)
                        countrdiaB++;
                    else
                        countrdiaB=0;
                }
                if(i+j<n)
                {
                    if(N[n-j-1-i][j]=='R')
                        countrevldiaR++;
                    else
                        countrevldiaR=0;
                    if(N[n-j-1-i][j]=='B')
                        countrevldiaB++;
                    else
                        countrevldiaB=0;
                    if(N[n-j-1][j+i]=='R'&i!=0)
                        countrevrdiaR++;
                    else
                        countrevrdiaR=0;
                    if(N[n-j-1][j+i]=='B'&i!=0)
                        countrevrdiaB++;
                    else
                        countrevrdiaB=0;
                }
                if(countrowR==k||countcolR==k||countrdiaR==k||countldiaR==k||countrevrdiaR==k||countrevldiaR==k)
                    flagR=1;
                if(countrowB==k||countcolB==k||countrdiaB==k||countldiaB==k||countrevrdiaB==k||countrevldiaB==k)
                    flagB=1;
            }
            countrowR=0; countrowB=0; countcolR=0; countcolB=0; countrdiaR=0; countldiaR=0; countrdiaB=0; countldiaB=0; countrevrdiaR=0; countrevldiaR=0; countrevrdiaB=0; countrevldiaB=0;
        }
        if(flagB==1&flagR==1)
            printf("Case #%d: Both\n",x);
        else if(flagB==1)
            printf("Case #%d: Blue\n",x);
        else if(flagR==1)
            printf("Case #%d: Red\n",x);
        else
            printf("Case #%d: Neither\n",x);
    }
    return 0;
}

