                                                                     TCS Level 1 


1	Print numbers from 1 to N and from N to 1 (both using same while loop logic).
#include<bits/stdc++.h>
using namespace std;

int main(){
int N;
cin>>N;

int i=1;
while(i<=N)
{
cout<<i << " ";


cout<<N-i+1 << " ";

i++;
}
return 0;
}


int N;
cin>>N;

int i=1;
while(i<=N)
{
cout<<i << " ";

i++;
}

cout<<endl;

i = N;
while(i >= 1)
{
cout << i << " ";
i--;
}


2	Check if a given number is PRIME or NOT. [Must handle edge cases: 0, 1, negative]

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int N;
        cin >> N;

        // Edge cases
        if(N < 2)
        {
            cout << "NOT Prime\n";
            continue;
        }

        bool isPrime = true;

        for(int i = 2; i * i <= N; i++)
        {
            if(N % i == 0)
            {
                isPrime = false;
                break;
            }
        }

        if(isPrime)
            cout << "Prime\n";
        else
            cout << "NOT Prime\n";
    }

    return 0;
}
