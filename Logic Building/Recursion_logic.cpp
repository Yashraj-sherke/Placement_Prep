                                         🔥 Level 1 – Foundation of Recursion

181	Level 1 – Foundation of Recursion	Print numbers from 1 to n using recursion.


void print(int num, int n)
{
    if(num > n)   // better base condition
    {
        return;
    }

    cout << num << " ";
    print(num + 1, n);
}

int main()
{
    int n;
    cin >> n;

    print(1, n);
}

182	Level 1 – Foundation of Recursion	Print numbers from n down to 1 using recursion.


#include <iostream>
using namespace std;

void print(int n)
{
    if(n == 0)
    {
        return;
    }

    cout << n << " ";
    print(n - 1);
}

int main()
{
    int n;
    cin >> n;

    print(n);
}

183	Level 1 – Foundation of Recursion	Print only even numbers from 1 to n recursively.
Wrong : // Ye tabhi usefull  hai agar number 2 start hoga

void print(int num,int n)
{
if(num>n)
{
return ;
}
cout<<num<<" ";
print(num+2,n)
}

int main()
{
    int n;
    cin >> n;

    // Start from 2 (first even number)
    print(2, n);
}

void print(int num, int n)
{
    if(num > n)
    {
        return;
    }

    if(num % 2 == 0)
    {
        cout << num << " ";
    }

    print(num + 1, n);
}

184	Level 1 – Foundation of Recursion	Print only odd numbers from 1 to n recursively.

void print(int num, int n)
{
    if(num > n)
    {
        return;
    }

    if(num % 2 != 0)
    {
        cout << num << " ";
    }

    print(num + 1, n);
}

185	Level 1 – Foundation of Recursion	Print sum of first n natural numbers recursively.

void printSum(int num,int n)
{

if(num>n)
{
return;
}

int sum=0;

sum=sum+printSum(num+1,n);

cout<<sum;
}

int main(){
int n;
cin>>n;

printSum(1,n)
}

186	Level 1 – Foundation of Recursion	Print factorial of a number recursively.

#include <iostream>
using namespace std;

int printSum(int n)
{
    if(n == 0)
    {
        return 0;
    }

    return n + printSum(n - 1);
}

int main()
{
    int n;
    cin >> n;

    cout << printSum(n);
}

187	Level 1 – Foundation of Recursion	Calculate power of a number (xⁿ) using recursion.


int power(int x, int n)
{
    if(n == 0)
    {
        return 1;
    }

    return x * power(x, n - 1);
}


188	Level 1 – Foundation of Recursion	Find nth Fibonacci number recursively

int fib(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fib(n - 1) + fib(n - 2);
}

189	Level 1 – Foundation of Recursion	Print Fibonacci series up to n terms recursively.

190	Level 1 – Foundation of Recursion	Find sum of digits of a number recursively.

int sumDigits(int n)
{
    if(n == 0)
    {
        return 0;
    }

    return (n % 10) + sumDigits(n / 10);
}


                                             🔥 Level 2 – Number-based Recursive Thinking

191	Level 2 – Number-based Recursive Thinking	Count the number of digits in a number recursively.

int countDigits(int n)
{
    if(n == 0)
    {
        return 0;
    }

    return 1 + countDigits(n / 10);

}

192	Level 2 – Number-based Recursive Thinking	Reverse a number recursively.

#include <iostream>
using namespace std;

void reverseNum(int n, int rev)
{
    if(n == 0)
    {
        cout << rev;
        return;
    }

    int digit = n % 10;

    reverseNum(n / 10, rev * 10 + digit);
}

int main()
{
    int n;
    cin >> n;

    reverseNum(n, 0);
}

193	Level 2 – Number-based Recursive Thinking	Check if a number is a palindrome using recursion.

void reverseNum(int n, int rev)
{
    if(n == 0)
    {
        cout << rev;
        return;
    }

    int digit = n % 10;

    reverseNum(n / 10, rev * 10 + digit);
}

int main()
{
    int n;
    cin >> n;

    int num= reverseNum(n, 0);

if(num==n)
{
cout<<"Palindrome";
}
else{
cout<<"Not Palindrome";
}
}


194	Level 2 – Number-based Recursive Thinking	Find product of digits of a number recursively.

int  productNum(int n, int pro)
{
    if(n == 0)
    {
        cout << pro;
        return;
    }

    int digit = n % 10;

    productNum(n / 10, 1* digit);
}

Correct:

//Return Type
int productNum(int n)
{
    if(n == 0)
    {
        return 1;
    }

    return (n % 10) * productNum(n / 10);
}

//Paramaterized Type

void productNum(int n, int pro)
{
    if(n == 0)
    {
        cout << pro;
        return;
    }

    int digit = n % 10;

    productNum(n / 10, pro * digit);
}

195	Level 2 – Number-based Recursive Thinking	Find GCD (HCF) of two numbers using Euclid's algorithm recursively

int gcd(int a, int b)
{
if(b==0)
{
return a;
}

return gcd(b,a%b)
}

196	Level 2 – Number-based Recursive Thinking	Convert a number to binary recursively.

197	Level 2 – Number-based Recursive Thinking	Print digits of a number in words recursively (e.g., 123 → 'one two three').

198	Level 2 – Number-based Recursive Thinking	Calculate the sum of first n even numbers recursively.

199	Level 2 – Number-based Recursive Thinking	Calculate the sum of first n odd numbers recursively.

200	Level 2 – Number-based Recursive Thinking	Find nCr (Combination formula) recursively using Pascal's relation.
