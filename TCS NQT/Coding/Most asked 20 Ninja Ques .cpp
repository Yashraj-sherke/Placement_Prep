CODING DIFFICULTY PROGRESSION — THREE TIERS


Basic Template

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;     // number of test cases

    while(t--)
    {
        // write logic here
    }

    return 0;
}


T1-01	Print right-angle triangle of stars

#include<bits/stdc++.h>
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);

cin.tie(NULL);

int t;
cin>>t;

while(t--)
{
int n;
cin>> n;


int N;

for(int row=1;row<=N;row++)
{
for(int col=1;col<=row;col++)
{

cout<<"*"<<" ";
}
cout<<"\n";
}
}
return 0;
}


T1-02	Check prime number

#include<bits/stdc++.h>
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int t;
cin>>t;

while(t--)
{
    int N;
    cin>>N;

    bool prime = true;

    if(N < 2)
        prime = false;

    for(int i=2;i<N;i++)
    {
        if(N%i==0)
        {
            prime = false;
            break;
        }
    }

    if(prime)
        cout<<"Prime\n";
    else
        cout<<"Not Prime\n";
}

return 0;
}

T1-03	Fibonacci up to N terms


#include<bits/stdc++.h>
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int t;
cin>>t;

while(t--)
{
    int n;
    cin>>n;

    int first = 0;
    int sec = 1;

    cout<<first<<" "<<sec<<" ";

    for(int i=3;i<=n;i++)
    {
        int curr = first + sec;
        cout<<curr<<" ";

        first = sec;
        sec = curr;
    }

    cout<<"\n";
}

return 0;
}

