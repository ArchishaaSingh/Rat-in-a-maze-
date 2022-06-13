#include<iostream>
using namespace std;

bool isSafe(int **origarr, int x, int y, int n)
{
	if(x<n && y<n && origarr[x][y]==1)
	{
		return true;
	}
	return false;
	
}

bool ratinmaze(int **origarr, int x, int y, int n, int ** solarr)
{
	if(x==n-1 && y==n-1)
	{
		solarr[x][y]=1;
		return true;
	}
	
	if(isSafe(origarr,x,y,n))
	{
		solarr[x][y]=1;
		if(ratinmaze(origarr,x+1,y,n,solarr))
		{
			return true;
		}
			if(ratinmaze(origarr,x,y+1,n,solarr))
		{
			return true;
		}
		solarr[x][y]=0;   // backtracking
		return false;
		
	}
	return false;
		
}


int main()
{
	
	cout<<"\t\t***BACKTRACKING OF RAT IN A MAZE***\n";

	
	int size;
	
	cout<<" Array size: ";
	cin>>size;
	
	int **origarr = new int*[size];
	for(int i=0; i<size;i++)
	{
		origarr[i]= new int[size];
	}
	
	//initialise original array
	for(int i=0; i<size;i++){
		for(int j=0; j<size; j++)
		{
			cin>>origarr[i][j];
		}
	}
	
	//initialise solution array as 0 initially
	int **solarr = new int*[size];
	for(int i=0; i<size;i++)
	{
		solarr[i]= new int[size];
		for(int j=0; j<size; j++)
		{
			solarr[i][j]=0;
		}
		
	}

if(ratinmaze(origarr,0,0,size,solarr))
{  cout<<"\n";
		for(int i=0; i<size;i++){
		for(int j=0; j<size; j++)
		{
			cout<<solarr[i][j]<<" ";
		}cout<<"\n";
	}	
	
	
	return 0;
}
}
// 1 0 1 0 1
// 1 1 1 1 1 
// 0 1 0 1 0
// 1 0 0 1 1 
// 1 1 1 0 1
