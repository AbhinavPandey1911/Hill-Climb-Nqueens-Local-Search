
#include <bits/stdc++.h> 

using namespace std; 
bool check(pair<int,int>a,pair<int,int>b)
{
    if(a.first==b.first||a.second==b.second)
        return true;
    else if(abs(a.first-b.first)==abs(a.second-b.second))
        return true;
    return false;
}
long long findpairs(vector<pair<int,int>> coordinates,int flag)
{ long long cnt=0;
    for(int i=0;i<coordinates.size();i++)
 {
    for(int j=i+1;j<coordinates.size();j++)
    {
        if(check(coordinates[i],coordinates[j])==true)
            {
              if(flag)
             cout<<coordinates[i].second<<" "<<coordinates[i].first<<"---"<<coordinates[j].second<<" "<<coordinates[j].first<<"\n";
            cnt++;
        }
    }
 }
 return cnt;

}
int main(){
 int n;
 cin>>n;
 char a[n][n];
 cout<<"Enter The Initial Arrangement of the Board\n";
 cout<<"Mark X where the queens are placed and * where its empty";
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>a[i][j];
std::vector<pair<int,int>> coordinates;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        if(a[i][j]=='X'||a[i][j]=='x')
            coordinates.push_back({j,i});
    }
    cout<<"\n";
/* Display of all the coordinates Entered
for(int i=0;i<coordinates.size();i++)
    cout<<coordinates[i].first<<" "<<coordinates[i].second<<"\n";
*/
 sort(coordinates.begin(),coordinates.end());
long long cnt=0;
 cnt=findpairs(coordinates,0);

 cout<<"Initially for the Inputted Board, the no. Distinct pairs of attacking queens are:- ";
 cout<<cnt<<"\n";
 long long tempcnt=cnt;
 long long mini=INT_MAX;
 int t=5;
 long long prevtempcnt=INT_MAX;
while(tempcnt<prevtempcnt)
{ long long ix=-1,iy=-1;
prevtempcnt=tempcnt;
for(int i=0;i<n;i++)
    { for(int j=0;j<n;j++)
     {  long long tempx=coordinates[j].first,tempy=coordinates[j].second;
        coordinates[j].first=j;
        coordinates[j].second=i;
        cnt=findpairs(coordinates,0);
        cout<<cnt<<" ";
        if(tempcnt>cnt)
       {
        tempcnt=cnt;
        ix=i;
        iy=j;
       }
        coordinates[j].first=tempx;
        coordinates[j].second=tempy;
     }
    cout<<"\n";}
    coordinates[iy].first=iy;
    coordinates[iy].second=ix;
    cout<<"\n";

}
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
 {
    if(coordinates[j].first==j&&coordinates[j].second==i)
        cout<<"X";
    else cout<<"*";
 }
cout<<"\n";
}
cout<<"LOCAL MINIMA THAT WAS ENCOUNTERED WAS :- "<<tempcnt<<"\n";
 cout<<"The current Attacking pairs are :- \n";
 int flush=findpairs(coordinates,1);

}
