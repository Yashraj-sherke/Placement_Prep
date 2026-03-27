                                      🔥 Level 1 – Fundamentals of Arrays 

221	Level 1 – Fundamentals of Arrays	Input n and take n integers into an array; print them.

int n;
cin>>n;

int arr[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}

for(int i=0;i<n;i++)
{
cout<<arr[i]<<" ";
)


222	Level 1 – Fundamentals of Arrays	Find the sum of all elements in an array.

int n;
cin>>n;

int arr[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int sum=0;

for(int i=0;i<n;i++)
{
sum=sum+arr[i];
}
cout<<sum;


223	Level 1 – Fundamentals of Arrays	Find the average of array elements.

int n;
cin>>n;

int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}


int sum=0;
for(int i=0;i<n;i++)
{
sum=sum+arr[i];
}
double avg=(double)sum/n;
cout<<avg;

224	Level 1 – Fundamentals of Arrays	Find the maximum element in an array

int n;
cin>>n;

int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int max=-1;

for(int i=0;i<n;i++)
{
if(arr[i]>max)
{
max=arr[i];
}
}
cout<<max; 


225	Level 1 – Fundamentals of Arrays	Find the minimum element in an array.

int n;
cin>>n;

int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int min=INT_MAX;

for(int i=0;i<n;i++)
{
if(arr[i]<min)
{
min=arr[i];
}
}
cout<<min; 

226	Level 1 – Fundamentals of Arrays	Count how many elements are positive, negative, or zero.

int n;
cin>>n;
int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int pos=0;
int neg=0;
int zero=0;

for(int i=0;i<n;i++)
{
if(arr[i]==0)
{
zero++;
}
else if(arr[i]>0)
{
pos++;
}
else
{
neg++;
}
}
cout<<pos<<" "<<neg<<" "<<zero;


227	Level 1 – Fundamentals of Arrays	Count how many elements are even and odd.
int n;
cin>>n;

int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int even=0;
int odd=0;

for(int i=0;i<n;i++)
{
if(arr[i]%2==0)
{
even++;
}
else
{
odd++;
}
}
cout<<even<<" "<<odd;


228	Level 1 – Fundamentals of Arrays	Find the index of the maximum element

  int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max = INT_MIN;
    int index = -1;

    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
            index = i; // store index
        }
    }

    cout << index;


229	Level 1 – Fundamentals of Arrays	Find the index of the minimum element

230	Level 1 – Fundamentals of Arrays	Take n elements and print only those greater than a given value k.

int n;
int k;
cin>>k;
cin>>n;

int arr[n];

   for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

for(int i=0;i<n;i++)
{
if(arr[i]>k)
{
cout<<arr[i]<<" ";
}
}



                                          🔥 Level 2 – Searching & Counting Logic 

231	Level 2 – Searching & Counting Logic	Input an element x — check if it exists in the array.

int n,x;
cin>>n;
cin>>x;
int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

for(int i=0;i<n;i++)
{
if(x==arr[i])
{
cout<<"Yes";
break;
}
}
cout<<"NO";

//Agar Nhi mila to fir bhi har bar no print hoga 

Method 2:

for(int i=0;i<n;i++)
{
if(x==arr[i])
{
cout<<"Yes";
return 0; //Progrma yhi se khatam ho jayega
}
}
cout<<"NO";

Method 3: By use of flag

   int n, x;
    cin >> n;
    cin >> x;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool found = false;

    for(int i = 0; i < n; i++) {
        if(x == arr[i]) {
            cout << "Yes";
            found = true;
            break;
        }
    }

    if(!found) {
        cout << "No";
    }


232	Level 2 – Searching & Counting Logic	Count how many times a given element appears.

 int n, x;
    cin >> n;
    cin >> x;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

int count=0;

for(int i=0;i<n;i++)
{
if(x==arr[i])
{
count++;
}
}
cout<<count;

233	Level 2 – Searching & Counting Logic	Find the first occurrence of a given number.


 int n, x;
    cin >> n;
    cin >> x;

    int arr[n];

 for(int i = 0; i < n; i++) {
  cin >> arr[i];
}



for(int i=0;i<n;i++)
{
if(x==arr[i])
{
cout<<i;
break;
}
}

Level 2 – Searching & Counting Logic	Find the last occurrence of a given number.


 int n, x;
    cin >> n;
    cin >> x;

    int arr[n];

 for(int i = 0; i < n; i++) {
  cin >> arr[i];
}

bool found = false;

for(int i=n-1;i=0;i--)
{
if(x==arr[i])
{
cout<<i;
found=true;
break;
}

if(!forund)
{
cout<<-1;
}

235	Level 2 – Searching & Counting Logic	Check if all elements in an array are unique.


int n;
cin>>n;

int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}



for(int i=0;i<n-1;i++)
{
for(int j=i+1;j<n;j++)
{
if(arr[i]==arr[j])
{
cout<<"Not Unique";
break;
}
}
}


236	Level 2 – Searching & Counting Logic	Find the sum of even elements only.



int n;
cin>>n;

int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int sum=0;

for(int i=0;i<n;i++)
{
if(arr[i]%2==0)
{
sum= sum+arr[i];
}
}
cout<<sum;

237	Level 2 – Searching & Counting Logic	Find the sum of odd elements only.

238	Level 2 – Searching & Counting Logic	Find the count of prime numbers in the array.

239	Level 2 – Searching & Counting Logic	Count how many numbers are divisible by 3 and 5 both.

240	Level 2 – Searching & Counting Logic	Count how many elements are perfect squares.


