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
