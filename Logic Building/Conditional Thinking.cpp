1	Level 1 – Simple Conditions	Take a number and print whether it's positive, negative, or zero.

int n;
cin>>n;

if(n>0)
{
cout<<"Positive";
}
else if(n<0)
{
cout<<"negative";
}
else{
cout<<"zero";
}

2	Level 1 – Simple Conditions	Check if a number is even or odd.

int n;
cin>>n;

if(n%2==0)
{
cout<<"even";
}
else{
cout<<"odd";
}

Level 1 – Simple Conditions	Check if a number is divisible by 5.

int n;
cin>>n;

if(n%5==0)
{
cout<<"YES";
}
else{
cout<<"NO";
}

4	Level 1 – Simple Conditions	Check if a number is divisible by both 3 and 5.

int n;
cin>>n;

if(n%3==0 && n%5)
{
cout<<"YES";
}
else{
cout<<"NO";
}

5	Level 1 – Simple Conditions	Check if a given year is a leap year.

int n;
cin>>n;

if(n%4==0 && n%100!=0)
{
cout<<"Leap Year";
}
else if(n%400==0)
{
cout<<"Leap Year";
}
else{
cout<<"Not Leap Year"
}

6	Level 1 – Simple Conditions	Take two numbers and print the larger one.

int a , b;
cin>>a>>b;

if(a>b)
{
cout<<a;
}
else{
cout<<b;
}

7	Level 1 – Simple Conditions	Take three numbers and print the largest.

int a, b,c;
cin>>a>>b>>c;

if(a>b && a>c){
cout<<a;
}
else if(b>a && b>c)
{
cout<<b;
}
else{
cout<<c;
}

8	Level 1 – Simple Conditions	Take a temperature value and print 'Cold', 'Warm', or 'Hot' using range conditions.

int n;
cin>>n;

if(n<0)
{
cout<<"Cold";
}

if(n>100)
{
cout<<"Hot";
}

if(n>0 && n<100)
{
cout<<"Warm";
}


9	Level 1 – Simple Conditions	Take a character and check if it's a vowel or consonant.

char c;
cin>>c;

if(c==a || a==i || a==o || a==u || a==e)
{
cout<<vowel;
}
else{
cout<<"consonant";
}

10	Level 1 – Simple Conditions	Take a character and check whether it's uppercase, lowercase, a digit, or a special character.

11	Level 2 – Nested If & Multiple Conditions	Take three sides and check if they form a valid triangle.

if(a+b>=c && b+c>=a && c+a>=b)
{
cout<<"Valid";

}
else{
cout<<"Not Valid";
}

12	Level 2 – Nested If & Multiple Conditions	If the sides form a valid triangle, determine whether it is equilateral, isosceles, or scalene.
if(a+b>=c && b+c>=a && c+a>=b)
{
cout<<"Valid";

if(a==b && b==c && c==a)
{
cout<<"Equilateral";
}
else if(a=b || b==c || c==a)
{
cout<<"isoscale";
}
else{
cout<<"scalene";}

}
else{
cout<<"Not Valid";
}


13	Level 2 – Nested If & Multiple Conditions	Take marks (0–100) and print the corresponding grade (A/B/C/D/F).

int n;
cin >>n;

if(n>90 && n<=100)
{
cout<<"A";
}
else if(n>80 && n<=90)
{
cout<<"B";
}
else if((n>70 && n<=80)
{
cout<<"C";
}
else if(n>60 && n<=70)
{
cout<<"D";
}
else{
cout<<"F";
}




14	Level 2 – Nested If & Multiple Conditions	Check if one of two given numbers is a multiple of the other.

int a , b;

if(a%b==0)
{
cout<<"Yes";
}
else if(b%a==0)
{
cout<<"Yes";
}

15	Level 2 – Nested If & Multiple Conditions	Take the hour of the day (0–23) and print 'Good Morning', 'Good Afternoon', 'Good Evening', or 'Good Night'.

int h;
cin>>h

if(

16	Level 2 – Nested If & Multiple Conditions	Check voting eligibility for a given age (18+).

int age;
cin >> age;

if(age>=18)
{
cout<<"Eligible";
}
else{
cout<<"Not Eligible";
}


17	Level 2 – Nested If & Multiple Conditions	Take two numbers and determine whether both are even, both are odd, or one is even and one is odd.

int a,b;
cin>>a>>b;

if(a%2==0 && b%2==0)
{
cout<<"Even";
}
else if(a%2!=0 && b%2!=0)
{
cout<<"Odd";
}
else if(a%2==0 && b%2!=0 || a%2!=0 && b%2==0)
{
cout<<"Odd";
}

18	Level 2 – Nested If & Multiple Conditions	Take an alphabet character and check if it lies between 'a' and 'm' or 'n' and 'z'.

char ch;
cin>>ch;

if(ch>='a' && ch<='m')
{
cout<<"First Condition";
}
else if(ch>='n' && ch<='z')
{
cout<<"second Conditotin";
}


19	Level 2 – Nested If & Multiple Conditions	Take a day number (1–7) and print the corresponding day name.

int n;
cin >>n;

if(n==1)
{
cout<<"Mondey";
}
else if(n==2)
{
cout<<"Tuesday";
}
.....
else{
cout<<"Sunday";
}

20	Level 2 – Nested If & Multiple Conditions	Take a month number (1–12) and print the number of days in that month (ignore leap years).

int n;
cin>>n;

if(n==1 ||n==3 ||n==5||n==7 || n==8||n==10||n==12)
{
cout<<"31 Days";
}

else if( n==4 || n==6 || n==9 || n== 11)
{
cout<<"30 days";
}
else if(n==2)
{
cout<<"28Days";
}

21	Level 3 – Math and Number Logic	Take a 3-digit number and check if all digits are distinct.
int n;
cin >> n;

int d1 = n % 10;
n /= 10;

int d2 = n % 10;
n /= 10;

int d3 = n % 10;

if(d1 != d2 && d1 != d3 && d2 != d3)
{
    cout << "Distinct";
}
else
{
    cout << "Not Distinct";
}

22	Level 3 – Math and Number Logic	Take a 3-digit number and determine if the middle digit is the largest, smallest, or neither.

int n;
cin>>n;

int d1 = n%10;
n=n/10;

int d2= n%10;
n=n/10;

int d3= n%10;
n=n/10;

if(d2>d1 && d2>d3)
{
cout<<"largest";
}
else if(d2<d1 && d2<d3)
{
cout<<"Smallest";
}
else{
cout<<"Niether";
}


23	Level 3 – Math and Number Logic	Take a 4-digit number and check if the first and last digits are equal.

int n;
cin>>n;

int d1 = n%10;
n=n/10;

int d2= n%10;
n=n/10;

int d3= n%10;
n=n/10;

int d4 =n%10;
n= n/10;

if(d4==d1){
cout<<"Yes Equal";
}
else 
{
cout<<"Not Equql";
}

Approch 2 :

int n;
cin >> n;

int last = n % 10;
int first = n / 1000;

if(first == last)
{
    cout << "Yes Equal";
}
else
{
    cout << "Not Equal";
}


24	Level 3 – Math and Number Logic	Check whether a given integer is single-digit, double-digit, or multi-digit.

int n;
cin>>n;

int count=0;

while(n>0)
{
int digit = n%10;
count++;
n=n/10;
}
if(count==1)
{
cout<<"Single Digit";
}
else if(count==2)
{
cout<<"Double Digit";
}
else{
cout<<"Multidigit";
}


25	Level 3 – Math and Number Logic	Check if a number is a multiple of 7 or ends with 7.


int n;
cin>>n;
int ori =n;
int digit = n%10;

if(ori%7==0 || digit == 7)
{
cout<< "Yes";
}
else{
cout<<"No";
}


26	Level 3 – Math and Number Logic	Take coordinates (x, y) and determine which quadrant the point lies in.


int x, y;
cin >> x >> y;

if(x > 0 && y > 0)
{
    cout << "First Quadrant";
}
else if(x < 0 && y > 0)
{
    cout << "Second Quadrant";
}
else if(x < 0 && y < 0)
{
    cout << "Third Quadrant";
}
else if(x > 0 && y < 0)
{
    cout << "Fourth Quadrant";
}
else if(x == 0 && y != 0)
{
    cout << "On Y-axis";
}
else if(x != 0 && y == 0)
{
    cout << "On X-axis";
}
else
{
    cout << "Origin";
}


27	Level 3 – Math and Number Logic	Check if an amount can be evenly divided into 2000, 500, and 100 currency notes.

28	Level 3 – Math and Number Logic	Check if a number lies within the range [100, 999].

int n;
cin>>n;

if(n>=100 && n<=999)
{
cout<<"within Rang";
}
else {
cout<<"Not Within Range";
}

29	Level 3 – Math and Number Logic	Take two angles of a triangle and compute the third angle.

int a, b;
cin >> a >> b;

if(a > 0 && b > 0 && (a + b) < 180)
{
    int c = 180 - (a + b);
    cout << "Third Angle of Triangle is: " << c;
}
else
{
    cout << "Invalid angles";
}

30	Level 3 – Math and Number Logic	Check whether a number is a perfect square (without using the square root function).


int n;
cin >> n;

int i = 1;

while(i * i <= n)
{
    if(i * i == n)
    {
        cout << "Perfect Square";
        return 0;
    }
    i++;
}

cout << "Not Perfect Square";
















