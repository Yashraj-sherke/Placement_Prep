2 Print numbers from 10 down to 1 in reverse order


#include<bits.stdc++.h>
using namsspace std;

int main(){

int i=10;

while(i>=1){
cout<< i << " ";
i--;
}
return 0;
}


3. Print all even numbers between 1 and 100.

Approch 1:

#include<bits.stdc++.h>
using namespace std;

int main()
{
int i=1;
while(i<=100)
{
if(i%2==0)
{
cout<< i << " ";
}
i++;
}
return 0;

}

Approch 2

#include<bits.stdc++.h>
using namespace std;

int main()
{
int i=2;

while(i<=100){

cout<< i <" ";
i=i+2;

}
return 0;
}

4. Print all odd numbers between 1 and 100

#include<bits.stdc++.h>
using namespace std;

int main(){
int i=1;
while(i<100){
cout<<i <<"";
i=i+2;
}
return 0;
}

5. Print the multiplication table of a given number from n × 1 to n × 10.

#include<bits.stdc++.h>
using namsspace std;

int main()
{
int n ;
cin>>n;

int i=1;
while(i<=10)
{
cout<<n << "*" << i <<"="<< n*i <<endl;
i++;
}
return 0;
}

6. Calculate and print the sum of the first n natural numbers

#include<bits.stdc++.h>
using namespace std;

int main(){

int n;
cin>>n;

int sum =0;
int i =1;

while(i<=n)
{
sum= sum +i;
i++;
}
cout<<sum;

return 0;
}

7. Calculate the sum of all even numbers from 1 up to n.

#include<bits.stdc++.h>
using namespace std;

int main(){
int n;
cin>> n;

int i=1;
int sum=0;

while(i<=n)
{
if(i%2==0){
sum= sum+i;
}
i++;
}
cout<<sum;
return 0;
}

8. Calculate the sum of all odd numbers from 1 up to n.

#include<bits.stdc++.h>
using namespace std;

int main(){

int n;
cin>>n;

int sum =0;
int i=1;

while(i<=n)
{
sum = sum+i;
i+2; //Agar mene yhn par i = i+1 nhi likha to loop infinitely chalega
}
cout<<sum;
return 0;
}

9. Calculate and print the factorial of a given number.

#include<bits.stdc++.h>
using namespace std;

int main(){

int n;
cin>>n;

int fact =1;

while(n>=1)
{
fact=fact*n;

n= n-1;
}
cout<<fact<<"";
return 0
}

10. Find and print the product of all digits of a given number.

#include<bits.stdc++.h>
using namespace std ;

int main()
{
int n;
cin>>n;
int pro =1;

while(n>=1)
{

int digit = n%10;
pro= pro*digit;
n=n/10;
}
cout<<pro;
return 0;
}

11. Count and print the total number of digits in a given number.

#include<bits.stdc++.h>
using namespace std;

int main(){

int n;
cin>>n;
int count =0;

while(n>=1)
{
int digit = n%10;
count=count+1;
n=n/10;

}
cout<< count;
return 0;
}

12 . Reverse the given number and print the given number

#include<bits.stdc++.h>
using namespace std;

int main(){

int n;
cin>>n;

int rev =0;

while(n>=1)
{
int digit = n%10;

rev = rev*10+digit;

n=n/10;
}
cout<<rev;
return 0
}

13. Check the number is a palindrome

#include<bits.stdc++.h>
using namespace std;

int main(){

int n;
cin>>n;
int original = n;

int rev =0;

while(n>=1)
{
int digit = n%10;

rev = rev*10+digit;

n=n/10;
}
if(original==rev){
cout<<"palindrome";
}
else{
cout<<"not palindrome";
return 0
}

14 . Sum of the digit of the given number 

#include<iostream>
using namespace std;

int main(){

int n;
cin>>n;

int sum =0;

while(n>=1)
{
int digit = n%10;

sum = sum + digit ;

n=n/10;
}
cout<<"sum"<<sum;
return 0;
}

15. Check number is armstrog or not

#include<iostream>
using namespace std;

int main(){

int n;
cin>>n;
int original = n;

int sum =0;

while(n>=1)
{
int digit = n%10;

cube= (digit*digit*digit);

sum = sum+cube;

n=n/10;
}
if(original == sum)
{
cout<<"Armstrong";
}
else{
cout<<"Not Armstrong";
}
return 0;
}


16. Check whether the given number is a Perfect number.

#include<bits.stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;

int original = n;
int sum =0;
int i=1;

while(i<n)
{
if(n%i==0)
{
int digit =i;
}
sum = sum + i;
i++;
}

if(sum == original)
{
cout<<"Perfect No";
}
else{
cout<<"Not Perfect ";
}
return 0;
}

17. Print all prime numbers between 1 and 100.

#include<bits.stdc++.h>
using namespace std;

int main(){
int i=2;

while(i<=100){

int j=2;
while(j<i){
if(i%j!=0)
{
cout<< i << "";

}
j++
}
i++;
}
return 0;
}

18. Check whether the given number is a prime number

int n;
cin>>n;

int i=2;
while(i<n)
{
if(n%i==0){
cout<<"Not Prime No";

break;
}

i++;
}
cout<<"prime";

19. Print the Fibonacci series up to n terms.

int i=1;
int first =1;
int sec =1;
int fib;

cout<<first;
cout<<sec;

while(i<=n)
{
fib=first+sec;
cout<<fib<< " ";
first = sec;
sec= fib;

i++;
}


20. Find and print the sum of the Fibonacci series up to n terms.


int i=1;
int first =1;
int sec =1;
int fib;

int sum=first+sec;

cout<<first;
cout<<sec;

while(i<=n)
{
fib=first+sec;
sum = sum +fib;
first = sec;
sec= fib;

i++;
}
cout<<sum;

21. Print the square of each number from 1 to n.

int i=1;
int sqr;

while(i<=n)
{
sqr=i*i;
cout<<sqr << " ";
i++;
}

22. Print the cube of each number from 1 to n.

int i=1;
int cube;

while(i<=n)
{
cube= i*i*i;
cout<<cube<<" ";
i++;
}

23. Print all numbers between a and b that are divisible by 7.

int i=a;

while(i<=b)
{
if(i%7==0)
{
cout<< i << " ";

}
i++;
