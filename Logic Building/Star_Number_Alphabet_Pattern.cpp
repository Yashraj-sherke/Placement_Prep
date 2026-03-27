                                                     Star Patterns

1. Square Pattern
* * * * 
* * * * 
* * * * 
* * * * 
 
int n;
cin>>n;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
cout<<"*"<<" ";
}
cout<<endl;
}

2. Right Triangle (Increasing)
*
* *
* * *
* * * *

for(int i=1;i<=n;i++)
{
for(int j=1;j<=i ;j++)
{
cout<<"*"<<" ";
}
cout<<endl;
}

3. Right Triangle (Number)
1
1 2
1 2 3
1 2 3 4

for(int i=1;i<=n;i++)
{
for(int j=1;j<=i;j++)
{
cout<<j<<" ";
}
cout<<endl;
}

4. Right Triangle (Same Number)

1
2 2
3 3 3
4 4 4 4

for(int i=1;i<=n;i++)
{
for(int j=1;j<=i;j++)
{
cout<<i<<" ";
}
cout<<endl;
}

5. Reverse Triangle

* * * *
* * *
* *
*


for(int i=1;i<=n;i++)
{
for(int j=1;j<=n-i+1;j++)
{
cout<<"*"<<" ";
}
cout<<endl;
}



🔹 NUMBER BASED LOGIC

6. Reverse Number Triangle

1 2 3 4
1 2 3
1 2
1

for(int i=1;i<=n;i++)
{
for(int j=1;j<=n-i+1;j++)
{
cout<<"j"<<" ";
}
cout<<endl;
}

7. Right Triangle (Reverse Number)

1
2 1
3 2 1
4 3 2 1

for(int i=1;i<=n;i++)
{
int num=i;
for(int j=1;j<=i;j++)
{
cout<<num<<" ";
num=num-1;
}
cout<<endl;
}



8. Triangle (Increasing Continuous Number)

1
2 3
4 5 6
7 8 9 10
Incorrect:
for(int i=1;i<=n;i++)
{
int num=1;
for(int j=1;j<=i;j++)
{
cout<<num<<" ";
num=num+1;
}
cout<<endl;
}

correct:

👉 Kya hoga?

num ek hi baar start hoga
continuously badhta rahega

int num = 1;

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=i;j++)
    {
        cout<<num<<" ";
        num++;
    }
    cout<<endl;
}


👉 (Floyd’s Triangle)

9. Binary Triangle
1
0 1
1 0 1
0 1 0 1

int num = 1;

for(int i=1;i<=n;i++)
{
if(i%2!=0)
{
num=1;
}
else{
num=0;
}
for(int j=1;j<=i;j++)
{
cout<<num<<" ";
num=1-num;
}
cout<<endl
}


🔺 PYRAMID PATTERNS (IMPORTANT)

10. Star Pyramid
   *
  ***
 *****
*******

for(int i=1;i<=n;i++)
{
space
for(int j=1;j<=n-i+1;j++)
{
cout<<" ";
}

star
for(int j=1;j<=2*i-1;j++)
{
cout<<"*"<<" ";
}


space
for(int j=1;j<=n-i+1;j++)
{
cout<<" ";
}
cout<<endl;
}


11. Inverted Pyramid

*******
 *****
  ***
   *


for(int i=1;i<=n;i++)
{
space
for(int j=1;j<=i-1;j++)
{
cout<<" ";
}

star
for(int j=1;j<=2*n-(2*i-1);j++)
{
cout<<"*";
}

space
for(int j=1;j<=i-1;j++)
{
cout<<" ";
}
cout<<endl;
}


12. Diamond Pattern
   *
  ***
 *****
*******
 *****
  ***
   *

for(int i=1;i<=2*n-1;i++)
{
    int star;

    // stars count
    if(i <= n)
        star = 2*i - 1;
    else
        star = 2*(2*n - i) - 1;

    // spaces
    int space = (2*n - 1 - star)/2;

    // print spaces
    for(int j=1;j<=space;j++)
    {
        cout<<" ";
    }

    // print stars
    for(int j=1;j<=star;j++)
    {
        cout<<"*";
    }

    cout<<endl;
}



🔤 ALPHABET PATTERNS
13. Alphabet Triangle
A
A B
A B C
A B C D

for(int i=1;i<=n;i++)
{
char star= 'A';
for(int j=1;j<=i;j++)
{
cout<<star<<" ";
star=star+1;
}
cout<<endl;
}


14. Reverse Alphabet

A B C D
A B C
A B
A

for(int i=1;i<=n;i++)
{
char star= 'A';
for(int j=1;j<=n-i+1;j++)
{
cout<<star<<" ";
star=star+1;
}
cout<<endl;
}

15. Alphabet Pyramid

   A
  ABA
 ABCBA
ABCDCBA


🔥 ADVANCED PATTERNS
16. Hollow Square
* * * *
*     *
*     *
* * * *
17. Number Crown Pattern
1      1
12    21
123  321
12344321
18. Increasing + Decreasing Star

*
**
***
****
***
**
*

19. Star Butterfly

*      *
**    **
***  ***
********
***  ***
**    **
*      *
20. Hollow Pyramid

   *
  * *
 *   *
*******
21. Number Pyramid

   1
  121
 12321
1234321

22. Symmetric Pattern

1      1
12    21
123  321
12344321




