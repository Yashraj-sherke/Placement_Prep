                                              For Loop & Nested Loop

95	Phase 3 – For Loop	Print all numbers from 1 to 10.💡 Key Points 

for(int i=1;i<=10;i++)
{
cout<<i;
}

96	Phase 3 – For Loop	Print numbers from 10 down to 1 in reverse order.

for(int i=10;i>=1;i--)
{
cout<<i;
}


97	Phase 3 – For Loop	Print all even numbers between 1 and 100.

for(int i=1;i<=100;i++)
{
if(i%2==0)
{
cout<<i<<" ";
}
}

98	Phase 3 – For Loop	Print all odd numbers between 1 and 100.

for(int i=1;i<=100;i++)
{
if(i%2!=0)
{
cout<<i<<" ";
}
}


99	Phase 3 – For Loop	Print the multiplication table of a given number.
int n;
cin>>n;

for(int i=1;i<=10;i++)
{
cout<<"n"*i<<"="<<n*i;
}

100	Phase 3 – For Loop	Calculate and print the factorial of a given number.

int n;
cin>>n;

int fact =1;

for(int i=0;i<n;i++)
{
fact = fact*(n-i);
}
cout<<"Factoral of No:"<<fact;


Approch 2:
 int n;
cin>>n;

int fact =1;

for(int i=1;i<=n;i++)
{
fact = fact*i;
}
cout<<"Factoral of No:"<<fact;


101	Phase 3 – For Loop	Calculate and print the factorial of every number from 1 to n.

int n;
cin>>n;

int fact = 1;
for(int i=1;i<=n;i++)
{
fact= fact*i;
cout<<fact<<endl;
}

102	Phase 3 – For Loop	Print all prime numbers between 1 and 100


for(int i=2;i<=100;i++)
{
    bool isPrime = true;

    for(int j=2;j<i;j++)
    {
        if(i % j == 0)
        {
            isPrime = false;
            break;
        }
    }

    if(isPrime)
    {
        cout << i << " ";
    }
}



Phase 3 – For Loop	Check whether the given number is a prime number.
int n;
cin>>n;

for(int i=2;i<=n;i++)
{
if(n%i==0)
{
cout<<"Not a prime no";
}
else{
cout<<"Prime No";
}

correct Approch :

int n;
cin>>n;

bool isprime=  true;

for(int i=2;i<n;i++)
{
if(n%i==0)
{
isprime = false;
break;
}
else{
isprime=true;
}
}

if(isprime && n>1)
{
cout<<"Prime No";
}
else{
cout<<"Not Prime No";
}

104	Phase 3 – For Loop	Print the Fibonacci series up to the required number of terms.




