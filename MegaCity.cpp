#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    int NumberOfLocations;
    long Population;
    cin>>NumberOfLocations>>Population;
    long population=Population;
    
    vector< vector< long > > location(NumberOfLocations,vector<long>(2));
   
    for(int i=0; i<NumberOfLocations; i++)
    {
        long x,y;
        
        cin>>x>>y>>location[i][1];
        
        long Rsquare=pow(x,2)+pow(y,2);
        
        location[i][0]=Rsquare;
        
        Population+=location[i][1];
    }
    
    if(Population<pow(10,6))
    {
        cout<<"-1"<<endl;
        return 0;
    }
    
    sort(location.begin(),location.end());
    
    for(int i=0; i<NumberOfLocations; i++)
    {
        population+=location[i][1];
        
        if(population>=pow(10,6))
        {
            cout<<setprecision(8)<<sqrt((long double)location[i][0])<<endl;
            break;
        }
    }
    return 0;
}
