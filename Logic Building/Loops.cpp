
#1
Print 1 to N

for(int i=1;i<N;i++)
{
cout<<i;
}


#2
Print N to 1 (Reverse)
Very Easy

for(int i=N;i>0;i--)
{
cout<<i;
}

▾

#3
Print All Even Numbers 1 to N
Very Easy

for(int i=1;i<N;i++)
{
if(i%2==0)
{
cout<<i;
}
}
▾

#4
Print All Odd Numbers 1 to N
Very Easy

for(int i=1;i<N;i++)
{
if(i%2!=0)
{
cout<<i;
}
}

▾

#5
Sum of First N Natural Numbers
Very Easy

int sum= 0;

for(int i=0;i<N;i++)
{
sum+=i;
}

cout<<sum;
▾

#6
Multiplication Table
Very Easy

int n;
cin>>n;

for(int i=1;i<=10;i++)
{
cout<<n<<"*"<<i <<"="<<n*i<<endl;
}

▾

#7
Factorial of N
Very Easy

int n;
cin>>n;
int fact=1;

for(int i=1;i<=n;i++}
{
fact=fact*i;
}
cout<<fact;
▾

#8
Sum of Digits
Very Easy

int sum=0;
int n;
cin>>n;

while(n>0)
{
int digit = n%10;

sum= sum+digit;

n=n/10;
}
cout<<sum;


▾

#9
Count Digits
Very Easy

int count=0;
int n;
cin>>n;

while(n>0)
{
int digit = n%10;

count++;

n=n/10;
}
cout<count;

▾

#10
Reverse a Number
Very Easy

int rev=0;
int n;
cin>>n;

while(n>0)
{
int digit = n%10;

rev=rev*10+digit;

n=n/10;
}
cout<<rev;

▾

#11
Print Sum of Even Numbers 1 to N
Easy

int sum=0;

for(int i=0;i<=N;i++)
{
if(i%2==0)
{
sum+=i;
}
}
cout<<sum;


▾

#12
Print Sum of Odd Numbers 1 to N
Easy
int sum=0;

for(int i=0;i<=N;i++)
{
if(i%2!=0)
{
sum+=i;
}
}
cout<<sum;

▾

#13
Product of Digits
Easy

int pro=1;

int n;
cin>>n;

while(n>0)
{
int digit = n%10;

pro=pro*digit;

n=n/10;
}
cout<<pro;
▾

#14
Check Palindrome Number
Easy

int n;
cin>>n;

int temp=n;

int rev=0;
while(n>0)
{
int  digit = n%10;
rev=rev*10+digit;
n=n/10;
}
cout<<rev;
▾

#15
Check Prime Number
Easy

int n;
cin>>n;
bool prime = false;

for(int i=2;i<n-1;i++)
{
if(n%i==0)
{
prime= false;

}
else{
prime = true;
}


▾

#16
Print All Factors of N
Easy

int n ;
cin>>n;

for(int i=0;i<n;i++)
{
if(n%i==0)
{
cout<<i;
}
}
▾

#17
Fibonacci Series up to N terms
Easy

int first=0;
int sec=1;

int curr = first+sec;
first = sec;
sec= curr;

cout<<curr;


▾

#18
Print Squares 1 to N
Easy

int n;
cin>>n;
for(int i=1;i<N;i++)
{
cout<<i*i<<endl;
}
▾

#19
Print Cubes 1 to N
Easy
int n;
cin>>n;
for(int i=1;i<N;i++)
{
cout<<i*i*i<<endl;
}
▾

#20
Numbers Divisible by 7 in Range
Easy

int n,m;
cin>>n>>m;

for(int i=n;i<=m;i++)
{
if(i%7==0)
{
cout<<i;
}
}
▾

#21
Sum of Factors of N
Easy

int n;
cin>>N;
int sum=0;

for(int i=1;i<n;i++)
{
if(n%i==0)
{
sum=sum+i;
}
}
cout<<sum;
▾

#22
Find Smallest Digit in a Number
Easy

int n;
cin>>n;

vector<int>v;

int digit=n%10;
v.push_back(digit);
n=n/10;

int smll=INT_MAX;
for(int i=0;i<v.size();i++)
{
smll=min(smll,v[i]);
}
cout<<smll;

▾

#23
Find Largest Digit in a Number
Easy

int n;
cin>>n;

vector<int>v;

int digit=n%10;
v.push_back(digit);
n=n/10;

int lar=INT_MIN;
for(int i=0;i<v.size();i++)
{
lar=max(smll,v[i]);
}
cout<<lar;

▾

#24
HCF/GCD of Two Numbers
Easy

int a,b;
cin>>a>>b;

while(b!=0)
{
temp=b;

b=a%b;

a = temp;

}

cout<<a;


▾

#25
LCM of Two Numbers
Easy

int a,b;
cin>>a>>b;

while(b!=0)
{
temp=b;

b=a%b;

a = temp;

}
int gcd= a;

cout<<(a*b)/GCD;

▾

#26
Check Armstrong Number
Easy

int n;
cin>>n;

int count =0;
while(n>0){
int digit =n%10;
count++;
n=n/10;
}
int sum=0;
while(n>0){
int digit =n%10;
sum= sum+digit;
n=n/10;
}




▾

#27
Check Perfect Number
Easy

int n;
cin>>n;

int sum=0;
for(int i=1;i<n;i++)
{
if(n%i==0)
{
sum=sum+i;
}
}
cout<<sum;


▾

#28
Print Primes from 1 to N
Easy

int n;
cin>>n;

for(int i=1;i<n;i++)
{






▾

#29
Sum of Fibonacci Series
Easy
▾

#30
Do-While: Sum Until Zero
Easy
▾

#31
Do-While: Find Largest Input
Easy
▾

#32
Do-While: Count Positive Inputs
Easy
▾

#33
Do-While: Menu-Driven Program
Easy
▾

#34
Separate Sum of Even and Odd Digits
Easy
▾

#35
Factorial of Each Number 1 to N
Easy
▾

#36
Break: Stop at First Multiple of 17
Easy
▾

#37
Continue: Skip Multiples of 5
Easy
▾

#38
Skip Zeros, Sum the Rest
Easy
▾

#39
Sum Until Exceeds 100
Easy
▾

#40
Search for a Number
Easy
▾

#41
Print Only Even Numbers, Skip Odd
Easy
▾

#42
AP Series Generator
Moderate
▾

#43
GP Series Generator
Moderate
▾

#44
Sum of Squares Series
Moderate
▾

#45
Sum of Cubes Series
Moderate
▾

#46
Harmonic Series Sum
Moderate
▾

#47
Powers of 2 Series
Moderate
▾

#48
Sum of Factorials Series
Moderate
▾

#49
Strong Number Check
Moderate
▾
🏆 Top 10 Must-Do Questions
1
Print 1 to N — the absolute first loop you should master
2
Sum of First N Natural Numbers — introduces the accumulator pattern
3
Factorial of N — multiplying accumulator, essential for math problems
4
Reverse a Number — digit extraction loop, used in 10+ other problems
5
Check Palindrome Number — combines reversal with comparison
6
Check Prime Number — nested condition inside loop, divisibility logic
7
Fibonacci Series — two-variable state tracking in a loop
8
HCF/GCD of Two Numbers — Euclid's algorithm, foundation for number theory
9
Break: Stop at First Multiple of 17 — teaches loop control flow
10
Strong Number Check — combines multiple concepts: digit extraction + factorial + comparison
