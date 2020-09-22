#include <bits/stdc++.h>

using namespace std;

int main (void)
{
	int number;
	
	cin >> number;
	
	int arr[number][2];
	
	
	
	for(int i=0;i<number;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin >> arr[i][j];
		}
	}
	
	string s;
	
	cin >> s;
	
	int state=0;
	
	for(int i=0;s[i]!='\0';i++)
	{
		int temp;
		if(s[i]=='0') temp=0;
		else if(s[i]=='1') temp=1;
		state=arr[state][temp];
		cout << state;
	}
	
	if(state==number-1)
		cout << "\nAccepted!" << endl;
	else
		cout << "\nNot accepted!" << endl;

	return 0;
}
