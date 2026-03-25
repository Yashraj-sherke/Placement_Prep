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

 int n;
    cin >> n;

    int first = 0, sec = 1;

    if(n >= 1) cout << first << " ";
    if(n >= 2) cout << sec << " ";

    for(int i = 0; i < n-2; i++) {
        int fib = first + sec;
        cout << fib << " ";
        first = sec;
        sec = fib;
    }

105	Phase 3 – For Loop	Find and print the sum of the Fibonacci series.

   int n;
    cin >> n;

    int first = 0, sec = 1;
    int sum = 0;

    if(n >= 1) sum += first;
    if(n >= 2) sum += sec;

    for(int i = 0; i < n-2; i++) {
        int fib = first + sec;
        sum += fib;
        first = sec;
        sec = fib;


106	Phase 3 – For Loop	Print all factors of the given number.

int n;
cin>>n;

for(int i=1;i<=n;i++)
{
if(n%i==0)
{
cout<<i<<" ";
}
}

107	Phase 3 – For Loop	Find and print the sum of all factors of the given number.



int n;
cin>>n;
int sum=0;

for(int i=1;i<=n;i++)
{
if(n%i==0)
{
sum=sum+i;
}
}
cout<<sum;

108	Phase 3 – For Loop	Find the HCF (Highest Common Factor) of the given numbers.
 int a = 48, b = 18;

    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
}

109	Phase 3 – For Loop	Find the LCM (Least Common Multiple) of the given numbers.
 int a = 48, b = 18;

    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
}
a=hcf;

cout<<(a*b)/a;

110	Phase 3 – For Loop	Print the square of each number from 1 to n.

int n;
cin>>n;

for(int i=1;i<=n;i++)
{
cout<<i*i<<" "<<endl;
}


111	Phase 3 – For Loop	Print the cube of each number from 1 to n.

int n;
cin>>n;

for(int i=1;i<=n;i++)
{
cout<<i*i*i<<" "<<endl;
}

112	Phase 3 – For Loop	Print all numbers between a and b that are divisible by 7.

int a ,b;
cin>>a>>b;

for(int i=a;i<=b;i++)
{
if(i%7==0)
{
cout<<i<<endl;
}
}

113	Phase 3 – For Loop	Find and print the sum of the first n natural numbers

Method 1:
int n;
cin>>;

int sum=n*(n+1)/2;

cout<<sum;

Method 2:

int n;
cin>>n;
int sum=0;
for(int i=0;i<=n;i++)
{
sum=sum+i;
}
cout<<sum;

114	Phase 3 – For Loop	Find and print the sum of all even numbers from 1 up to n.


int n;
cin>>n;
int sum=0;
for(int i=0;i<=n;i++)
{
if(i%2==0)
{
sum=sum+i;
}
}
cout<<sum;

115	Phase 3 – For Loop	Find and print the sum of all odd numbers from 1 up to n.
int n;
cin>>n;
int sum=0;
for(int i=0;i<=n;i++)
{
if(i%2!=0)
{
sum=sum+i;
}
}
cout<<sum;











