#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

string* arr;
string* arr0;
string* arr1;

string* brr;
string* brr0;
string* brr1;

vector <string> crr;
vector <string> :: iterator itr;

vector <string> drr;

int counter=0;

string concat0 (string s)
{
    string s1;
    for(int i=0;s[i]!='\0';i++)
    {
        for(int k=0;(arr0[(int)(s[i])-48])[k]!='\0';k++)
        {
            if((arr0[(int)(s[i])-48])[k]=='#') continue;
            int temp = 0;
            for(int j=0;s1[j]!='\0';j++)
            {
                if((arr0[(int)(s[i])-48])[k]==s1[j]) temp=1;
            }
            if(temp == 0) s1=s1+(arr0[(int)(s[i])-48])[k];
        }
    }

    sort(s1.begin(),s1.end());

    return s1;
}

string concat1 (string s)
{
    string s1;
    for(int i=0;s[i]!='\0';i++)
    {
        for(int k=0;(arr1[(int)(s[i])-48])[k]!='\0';k++)
        {
            if((arr1[(int)(s[i])-48])[k]=='#') continue;
            int temp = 0;
            for(int j=0;s1[j]!='\0';j++)
            {
                if((arr1[(int)(s[i])-48])[k]==s1[j]) temp=1;
                if(s=="023"&&i==2) cout << "**" << (arr1[(int)(s[i])-48])[k] << "**" << s1 << endl;
            }
            if(temp == 0) s1=s1+(arr1[(int)(s[i])-48])[k];
        }
    }

    sort(s1.begin(),s1.end());

    return s1;
}

int main (void)
{
	int nodes;

	cin >> nodes;

	cout << "NFA:" << endl;

	arr = new string [nodes];
	arr0 = new string [nodes];
	arr1 = new string [nodes];

	int power = pow(2,nodes);

	brr = new string [power];
	brr0 = new string [power];
	brr1 = new string [power];


    for(int i = 0; i < nodes; i++)
    {
        cin >> arr[i] >> arr0[i] >> arr1[i];
    }

    brr[counter]=arr[counter];
    drr.push_back(brr[counter]);
    brr0[counter]=arr0[counter];
    brr1[counter]=arr1[counter];

    counter++;

    int temp0=0,temp1=0;
    for(itr=drr.begin();itr!=drr.end();itr++)
    {
        if(brr0[counter-1]==*itr) temp0=1;
        if(brr1[counter-1]==*itr) temp1=1;
    }

    if(temp0==0) crr.push_back(brr0[counter-1]);
    if(temp1==0) crr.push_back(brr1[counter-1]);

    while(crr.size()!=0)
    {
        if(crr.back().empty()) crr.pop_back();
        brr[counter]=crr.back();
        drr.push_back(brr[counter]);
        crr.pop_back();
        brr0[counter]=concat0(brr[counter]);
        brr1[counter]=concat1(brr[counter]);

        counter++;

        int temp0=0,temp1=0;
        for(itr=drr.begin();itr!=drr.end();itr++)
        {
            if(brr0[counter-1]==*itr) temp0=1;
            if(brr1[counter-1]==*itr) temp1=1;
        }

        for(itr=crr.begin();itr!=crr.end();itr++)
        {
            if(brr0[counter-1]==*itr) temp0=-1;
            if(brr1[counter-1]==*itr) temp1=-1;
        }

        if(temp0==0) crr.push_back(brr0[counter-1]);
        if(temp1==0) crr.push_back(brr1[counter-1]);
    }

    cout << "DFA:" << endl;

    for(int i=0;i<counter;i++)
    {
        if(brr0[i].empty()) brr0[i] = "#";
        if(brr1[i].empty()) brr1[i] = "#";
        cout << brr[i] << ' ' << brr0[i] << ' ' << brr1[i] << endl;
    }

	return 0;
}
