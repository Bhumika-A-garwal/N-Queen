#include<iostream> 
using namespace std;
bool kyaplacekarsaktehai(int board[10][10],int i,int j,int n)
{
	//check row and column
	for(int k=0;k<n;k++)
	{
		if(board[i][k] || board[k][j])
		{
			return false;		
		}
	}
	//check for right above daigram
	int row=i;
	int col=j;
	while(i>=0 && j<n)
	{
		if(board[i][j])
		{
			return false;
		}
		i--;
		j++;
	}
	i=row;
	j=col;
	//check for left above diagram
	while(i>=0 && j>=0)
	{
		if(board[i][j]==1)
		{
			return false;	
		}
		i--;
		j--;
	}
	return true;
	
}
bool NQueen(int board[10][10],int i,int n)
{
	
	//base case
	if(i==n)
	{
		//print the board
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j]==1)
				{
					cout<<"Q";
				}
				else
				{
					cout<<"_";
				}
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
		//return true;//in case u want particular solution.
	}
	//recursive case
	for(int j=0;j<n;j++)
	{
		if(kyaplacekarsaktehai(board,i,j,n)==true)
		{
			board[i][j]=1;
			bool kyabakibaatbani=NQueen(board,i+1,n);
			if(kyabakibaatbani==true)
			{
				return true;
			}
			board[i][j]=0;
		}
	}
	
	return false;
}
int main()
{
	int board[10][10]={0};
	int n; 
	cin>>n;
	NQueen(board,0,n);
	return 0;
}
