 Phase 3 : For Loop

1. Print all numbers from 1 to 10.

for(int i=1;i<=10;i++){
cout<<i;
}

2. Print from 10 to 1 reverse

for(int i=10;i>=1;i--)
{
cout<<i < " ";
}

3. Print all even numbers between 1 and 100

for(int i=1;i<=100;i++)
{
if(i%2==0)
{
cout<<i<<" ";
}}


4. Print all odd numbers between 1 and 100.
for(int i=1;i<=100;i++)
{
if(i%2!=0)
{
cout<<i<<" ";
}}

5. Print the multiplication table of a given number.

int n;
cin>> n;

for(int i=1;i<=10;i++)
{
cout<<n <<*<<i<<"="<<n*i<<endl;
}

6. Calculate and print the factorial of a given number.
int n;
cin>>n;

fact= 1;
for(int i =1;i<=n;i++)
{
fact=fact*i;
}
cout<<fact;

7. Calculate and print the factorial of every number from 1 to n.

int fact(int n)
{
fact=1;
for(int i=1;i<=n;i++)
{
fact=fact*i;
}
return fact;
}

int main(){

for(int i=1;i<=n;i++)
{
fac = fact(i);
cout<<fac;
}
