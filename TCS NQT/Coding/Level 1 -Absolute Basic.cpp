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

3	Print all prime numbers between 1 and N.

#include<bits/stdc++.h>
using namespace std;

int main(){

int t;
cin>>t;

while(t--)
{
int N;
cin>>N;

for(itn i=2;i*i<=N;i++)
{
if(N%i!=0)
{
cout<<i<<" ";
}
}
cout<<endl;
}
return0
}


4  Check if a number is an ARMSTRONG number (e.g., 153 = 1³+5³+3³) [PYQ 2022-24]PYQ

#include<bits/stdc++.h>
using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{

int N;
cin>>N;

int orig = N;

int sum=0;

while(N>0)
{
int digit = N%10;

sum= sum+(digit*digit*digit);

N=N/10;
}

if(orig == sum)
{
cout<<"Armstrong No";
}
else{
cout<<"Not Armstrong";
}
}
return 0;
}


Check if a number is a PALINDROME (e.g., 121, 1331) [PYQ 2022-25]

int N;
cin>>N;

int orig= N;

int rev=0;

while(N>0)
{
int digit= N%10;

rev=rev*10+digit;

N=N/10;
}

if(rev==orig)
{
cout<<"Palindrome\n";
}
else
{
cout<<"Not Palindrome\n";

6	Level 1	REVERSE a given number (e.g., 1234 → 4321) [PYQ]PYQ

int N;
cin>>N;
int rev=0;
while(N>0)
{
int digit=N%10;
rev= rev*10+digit;
N=N/10;
}

cout<<rev<<"\n";


7	Level 1	Find the SUM OF DIGITS of a number (e.g., 1234 → 10) [PYQ 2023]PYQ


int N;
cin>>N;
int sum=0;
while(N>0)
{
int digit=N%10;
sum=sum+digit;
N=N/10;
}

cout<<sum<<"\n";


8	Level 1	Calculate the FACTORIAL of N (loop and recursion) [PYQ]PYQ

int N;
cin>>N;

int fact=N;
for(int i=1;i<N;i++)
{
fact= fact*(N-i);
}
cout<<fact<<"\n";


9	Level 1	Print the FIBONACCI series up to N terms [PYQ 2023-25]PYQ

int N;
cin>> N;

int first=0;
int sec=1;

cout<<first << " "<< sec<< " ";

int i=1;

while(i<=N-2)
{
int fibo=first+sec;
first=sec;
sec=fibo;

cout<<fibo<<" ";

i++}


10	Level 1	Find the Nth FIBONACCI NUMBER using recursion

#include<bits/stdc++.h>
using namespace std;

int getFibo(int n)
{
if(n==0) return 0;
if(n==1) return 1;

return getFibo(n-1)+getFibo(n-2);

;
} 

int main()
{
int N;
cin>>N;

int Fibo = getFibo(N);

cout<<Fibo<<"\n";

return 0;
}


11	Level 1	Find the PRODUCT of all digits of a number


int N;
cin>>N;
int pro=1;
while(N>0)
{
int digit=N%10;
pro=pro*digit;
N=N/10;
}

cout<<sum<<"\n";

12	Level 1	COUNT the total number of digits in a number

int N;
cin>>N;

int count=0;
while(N>0)
{
int digit= N%10;
count++;
N=N/10;
}

cout<<count;

13	Level 1	Print a STAR PATTERN — right-angled triangle

int N;
cin>>N;

for(int row=1;row<=N;row++)
{
for(int col=1;col<=row;col++)
{
cout<<"*" <<" ";
}
cout<<endl;
}

14	Level 1	Print an INVERTED STAR PATTERN (reverse triangle)

int N;
cin>>N;
for(int i=1;i<=N;i++)
{
for(int j=1;j<=N-i+1;j++)
{
cout<<"*"<<" ";
}
cout<<endl;
}



15	Level 1	SWAP two numbers WITHOUT using a third variable

int a=5;
int b=10
cin>>a>>b;

cout<<"Before Swap"<<a<<" "<<b<<endl;

a=a+b
b=a-b;
a=a-b;
cout<<"After Swap"<<a<<" "<<b<<endl;

16	Level 1	Check if a year is a LEAP YEAR [PYQ]PYQ

int year;
cin>>year;

if((year%4==0 && year%100!=0)||(year%400==0))
{
cout<<"Leap Year\n";
}
else
{
cout<<"Not Leap Year";
}

17	Level 1	Print FLOYD'S TRIANGLE (1 2 3 / 4 5 6 / ...) [PYQ]PYQ

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int num = 1;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }

    return 0;
}

18	Level 1	Print PYRAMID / centred star triangle [PYQ]PYQ

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        // spaces
        for(int j = 1; j <= N - i; j++)
        {
            cout << " ";
        }

        // stars
        for(int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}

19	Level 1	Print DIAMOND star pattern [PYQ]PYQ
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    // Upper Pyramid
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N - i; j++)
            cout << " ";

        for(int j = 1; j <= i; j++)
            cout << "* ";

        cout << endl;
    }

    // Lower Inverted Pyramid
    for(int i = N - 1; i >= 1; i--)
    {
        for(int j = 1; j <= N - i; j++)
            cout << " ";

        for(int j = 1; j <= i; j++)
            cout << "* ";

        cout << endl;
    }

    return 0;
}
















