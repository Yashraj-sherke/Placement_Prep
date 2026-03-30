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
if(arr[i]%2!=0)
{
sum= sum+arr[i];
}
}
cout<<sum;

238	Level 2 – Searching & Counting Logic	Find the count of prime numbers in the array.

int n;
cin>>n;

int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int count=0;

for(int i=2;i<n-1;i++)
{
if(arr[i]%i!==0)
{
continue;
}
else{
count++;
}
cout<<count;

239	Level 2 – Searching & Counting Logic	Count how many numbers are divisible by 3 and 5 both.

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
if(arr[i]%3==0 && arr[i]%5==0)
{
sum= sum+arr[i];
}
}
cout<<sum;
240	Level 2 – Searching & Counting Logic	Count how many elements are perfect squares.

int n;
cin>>n;

int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

 int count = 0;

    for(int i = 0; i < n; i++)
    {
        int root = sqrt(arr[i]);

        if(root * root == arr[i])
        {
            count++;
        }
    }

    cout << count;

                                                      🔥 Level 3 – Transformation & Manipulation 


241	Level 3 – Transformation & Manipulation	Create a new array containing squares of all numbers.

int n;
cin>>n;

int arr[n];
int sqr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

for(int i=0;i<n;i++)
{
int sq=arr[i]*arr[i];
// cin>>sqr[sq]; Yhn Par direct input le rahe hai aru square ko as a index de diya
 sqr[i]=arr[i]*arr[i];

}

for(int i=0;i<n;i++)
{
cout<<sqr[i]<<" ";
}


242	Level 3 – Transformation & Manipulation	Create a new array containing only even elements.

int n;
cin>>n;

int arr[n];
int even[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int j;
for(int i=0;i<n;i++)
{
if(arr[i]%2==0)
{
even[j]=arr[i];
}

}

for(int j=0;j<n;j++)
{
cout<<even[j];
}

243	Level 3 – Transformation & Manipulation	Replace every negative number with 0.


int n;
cin>>n;

int arr[n];
int even[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

for(int i=0;i<n;i++)
{
if(arr[i]<0)
{
arr[i]=0;
}
}

for(int i=0;i<n;i++)
{
cout<<arr[i]<< " ";
}



244	Level 3 – Transformation & Manipulation	Replace all even numbers with 1 and all odd with 0.


int n;
cin>>n;

int arr[n];
int even[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

for(int i=0;i<n;i++)
{
if(arr[i]%2==0)
{
arr[i]=1;
}
else{
arr[i]=0;
}
}

for(int i=0;i<n;i++)
{
cout<<arr[i]<< " ";
}

245	Level 3 – Transformation & Manipulation	Swap the first and last elements of the array.

int n;
cin>>n;

int arr[n];
int even[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

//for swapping

int temp=arr[0];
arr[0]=arr[n-1];
arr[n-1]=temp;

for(int i=0;i<n;i++)
{
cout<<arr[i];
}

246	Level 3 – Transformation & Manipulation	Reverse an array (without using built-in reverse)

int n;
cin>>n;

int arr[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int i=0;
int j=n-1;

while(i<j)
{
int temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
i++;
j--;
}
for(int i=0;i<n;i++)
{
cout<<arr[i];
}


247	Level 3 – Transformation & Manipulation	Rotate an array by one position to the left

int n;
cin>>n;

int arr[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int temp=arr[0];

for(int i=0;i<n-1;i++)
{
arr[i]=arr[i+1];
}

arr[n-1]=temp;

for(int i=0;i<n;i++)
{
cout<<arr[i];
}

248	Level 3 – Transformation & Manipulation	Rotate an array by one position to the right.

int n;
cin>>n;

int arr[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int temp=arr[n-1];

for(int i=n-1;i>0;i--)
{
arr[i]=arr[i-1];
}
arr[0]=temp;
for(int i=0;i<n;i++)
{
cout<<arr[i];
}

249	Level 3 – Transformation & Manipulation	Swap alternate elements (1st ↔ 2nd, 3rd ↔ 4th, etc.).

int n;
cin>>n;

int arr[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}

for(int i=0;i<n-1;i=i+2)
{
int temp = arr[i];
arr[i]=arr[i+1];
arr[i+1]=temp;
}

for(int i=0;i<n;i++)
{
cout<<arr[i];
}

250	Level 3 – Transformation & Manipulation	Copy one array to another manually.


int n;
cin>>n;

int arr[n];
int temp[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}

for(int i=0;i<n;i++)
{
temp[i]=arr[i];
}

for(int i=0;i<n;i++)
{
cout<<temp[i];
}
   


                                         🔥 Level 4 – Aggregate & Comparative Thinking

251	Level 4 – Aggregate & Comparative Thinking	Compare two arrays — check if they are equal (same elements & order).

#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n];
    int arr1[m];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }

    // Step 1: size check
    if(n != m)
    {
        cout << "Not Equal";
        return 0;
    }

    // Step 2: compare elements
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != arr1[i])
        {
            cout << "Not Equal";
            return 0;
        }
    }

    // Step 3: if all matched
    cout << "Equal";

    return 0;
}

252	Level 4 – Aggregate & Comparative Thinking	Compare two arrays — check if they contain the same elements (ignore order).


Wrong Approch:

  int n, m;
    cin >> n >> m;

    int arr[n];
    int arr1[m];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }



for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
if(arr[i]!=arr[j])
{
cout<<"Not Contain";
}
}
}
cout<<"Yes contain";

Correct Approch: 

#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    if(n != m)
    {
        cout << "Not Contain";
        return 0;
    }

    int arr[n];
    int arr1[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    // Step 1: sort both arrays
    sort(arr, arr + n);
    sort(arr1, arr1 + n);

    // Step 2: compare
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != arr1[i])
        {
            cout << "Not Contain";
            return 0;
        }
    }

    cout << "Yes contain";
    return 0;
}


253	Level 4 – Aggregate & Comparative Thinking	Merge two arrays into a third array.

#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int arr[n];
    int arr1[m];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<m;i++)
    {
        cin>>arr1[i];
    }

    int ans[n+m];

    // copy first array
    for(int i=0;i<n;i++)
    {
        ans[i]=arr[i];
    }

    // correct second array copy
    for(int i=n;i<n+m;i++)
    {
        ans[i]=arr1[i-n];   // ⭐ main fix
    }

    // print correct array
    for(int i=0;i<n+m;i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}

254	Level 4 – Aggregate & Comparative Thinking	Find the common elements between two arrays

  #include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int arr[n];
    int arr1[m];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<m;i++)
    {
        cin>>arr1[i];
    }

    int ans[n+m];
    int k = 0;   // ⭐ important

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i] == arr1[j])
            {
                ans[k] = arr[i];
                k++;
                break;   // duplicate avoid karne ke liye
            }
        }
    }

    // print only filled elements
    for(int i=0;i<k;i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}

255	Level 4 – Aggregate & Comparative Thinking	Find elements that are in one array but not in the other.

int n,m;
cin>>n>>m;

int arr[n];
int arr1[m];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

for(int j=0;j<m;j++)
{
cin>>arr1[j];
}

int ans[n+m];
int k=0;


for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
if(arr[i]!=arr1[j])
{
ans[k]=arr[i];
k++;
ans[k]=arr1[j];
k++;
break;
}
}
}

for(int k=0;k<n+m;k++)
{
cout<<ans[k];
}

Corect Approch:

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr[n], arr1[m];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int j = 0; j < m; j++) {
        cin >> arr1[j];
    }

    // Elements in arr but not in arr1
    for(int i = 0; i < n; i++) {
        bool found = false;

        for(int j = 0; j < m; j++) {
            if(arr[i] == arr1[j]) {
                found = true;
                break;
            }
        }

        if(!found) {
            cout << arr[i] << " ";
        }
    }

    // Elements in arr1 but not in arr
    for(int i = 0; i < m; i++) {
        bool found = false;

        for(int j = 0; j < n; j++) {
            if(arr1[i] == arr[j]) {
                found = true;
                break;
            }
        }

        if(!found) {
            cout << arr1[i] << " ";
        }
    }

    return 0;
}


256	Level 4 – Aggregate & Comparative Thinking	Count how many elements are common between two arrays.

int n,m;
    cin>>n>>m;

    int arr[n];
    int arr1[m];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<m;i++)
    {
        cin>>arr1[i];
    }


    int k = 0; 
int count=0;  // ⭐ important

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i] == arr1[j])
            {
          
                count++;
                k++;
                break;   // duplicate avoid karne ke liye
            }
        }
    }


cout<<count;

    257	Level 4 – Aggregate & Comparative Thinking	Find element-wise sum of two arrays (A[i] + B[i]).

int n,m;
    cin>>n>>m;

    int arr[n];
    int arr1[m];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<m;i++)
    {
        cin>>arr1[i];
    }

   int sum[n+m];
int k=0;

for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{

sum[k]=arr[i]+arr1[j];
k++;
break;
}}

for(int k=0;k<n+m;k++)
{
cout<<sum[k]<<" ";
}

Correct Approch:

 int n, m;
    cin >> n >> m;

    int arr[n], arr1[m];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    int size = min(n, m);

    for(int i = 0; i < size; i++) {
        cout << arr[i] + arr1[i] << " ";
}

258	Level 4 – Aggregate & Comparative Thinking	Find element-wise product of two arrays.

int n, m;
    cin >> n >> m;

    int arr[n], arr1[m];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    int size = min(n, m);

    for(int i = 0; i < size; i++) {
        cout << arr[i] *arr1[i] << " ";
}

259	Level 4 – Aggregate & Comparative Thinking	Create a frequency array of numbers (count occurrence of each number).

int n;
cin>>n;

int arr[n];

for(int i=0;i<n;i++)
{
cin>>arr[i];
}

int frq[n]={0};

for(int i=0;i<n;i++)
{
frq[arr[i]]++;
}

for(int i=0;i<n;i++)
{
cout<<frq[i];
}


correct Logic:
int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int frq[101] = {0};  // assume values 0–100

    // count frequency
    for(int i = 0; i < n; i++) {
        frq[arr[i]]++;
    }

    // print frequency
    for(int i = 0; i < 101; i++) {
        if(frq[i] > 0) {
            cout << i << " -> " << frq[i] << endl;
        }
    }


260	Level 4 – Aggregate & Comparative Thinking	Print all elements that appear more than once.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    int frq[101] = {0};

    for(int i = 0; i < n; i++) {
        frq[arr[i]]++;
    }

    for(int i = 0; i < 101; i++) {
        if(frq[i] > 1) {
            cout << i << " ";
        }
    }
}

                          🔥 Level 5 – Logical & Applied Array Problems


261	Level 5 – Logical & Applied Array Problems	Check if the array is sorted in ascending order.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool isSorted = true;

    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            isSorted = false;
            break;
        }
    }

    if(isSorted) {
        cout << "Sorted";
    } else {
        cout << "Not Sorted";
    }

    return 0;
}

262	Level 5 – Logical & Applied Array Problems	Check if the array is sorted in descending order.

  int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool isSorted = true;

    for(int i = 0; i < n - 1; i++) {
        if(arr[i] < arr[i + 1]) {
            isSorted = false;
            break;
        }
    }

    if(isSorted) {
        cout << "Sorted";
    } else {
        cout << "Not Sorted";
    }

263	Level 5 – Logical & Applied Array Problems	Find the second largest element in an array


  int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

int first =INT_MIN;

for(int i=0;i<n-1;i++)
{
if(arr[i]>arr[i+1])
{
first=arr[i];
}
}


int sec =INT_MIN;

for(int i=0;i<n-1;i++)
{
if(arr[i]>arr[i+1])
{
sec=arr[i];
}
}

if(sec!=first)
{
cout<<sec;
}


263	Level 5 – Logical & Applied Array Problems	Find the second largest element in an array.

int n;
cin>>n;

int arr[n];

if(int i=0;i<n;i++)
{
cin>>arr[i];
}

int first=INT_MIN;
int second =INT_MIN;

for(int i=0;i<n;i++)
{
if(arr[i]>first)
{
second=first;
first=second;
}

if(arr[i]>second && arr[i]!=first)
{
second=arr[i];
}
}

cou<<first<<" "<<second;
264	Level 5 – Logical & Applied Array Problems	Find the second smallest element in an array.

int n;
cin>>n;

int arr[n];

if(int i=0;i<n;i++)
{
cin>>arr[i];
}

int first=INT_MAX;
int second =INT_MAX;

for(int i=0;i<n;i++)
{
if(arr[i]<first)
{
second=first;
first=second;
}

if(arr[i]<second && arr[i]!=first)
{
second=arr[i];
}
}

cou<<first<<" "<<second;

265	Level 5 – Logical & Applied Array Problems	Find the difference between the largest and smallest element.

int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mx = INT_MIN;
    int mn = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(arr[i] > mx) {
            mx = arr[i];
        }
        if(arr[i] < mn) {
            mn = arr[i];
        }
    }

    cout << mx - mn;

266	Level 5 – Logical & Applied Array Problems	Find the sum of all elements except the largest and smallest

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mx = INT_MIN;
    int mn = INT_MAX;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(arr[i] > mx) {
            mx = arr[i];
        }
        if(arr[i] < mn) {
            mn = arr[i];
        }
    }

    cout << sum - mx - mn;

    return 0;
}

267	Level 5 – Logical & Applied Array Problems	Count how many pairs of elements have a sum equal to a given number k.

268	Level 5 – Logical & Applied Array Problems	Count how many elements are greater than the average of the array.
269	Level 5 – Logical & Applied Array Problems	Print the frequency of each distinct element.
270	Level 5 – Logical & Applied Array Problems	Print all unique elements (those that occur exactly once).
