                                            🔥 Category 1 – Basic String Handling 

271	Category 1 – Basic String Handling	Take a string input and print its length.

string s;
cin>>s;

cout<<s.size();

272	Category 1 – Basic String Handling	Print the first and last character of a string.

string s;
cin >> s;

if(s.size() > 0)
{
    cout << "First character: " << s[0] << endl;
    cout << "Last character: " << s[s.size() - 1] << endl;
}
else
{
    cout << "String is empty";
}

273	Category 1 – Basic String Handling	Convert all characters of a string to uppercase.

string s;
cin >> s;

int n = s.size();

for(int i = 0; i < n; i++)
{
    if(s[i] >= 'a' && s[i] <= 'z')
    {
        s[i] = s[i] - 32;
    }
}

cout << s;

274	Category 1 – Basic String Handling	Convert all characters of a string to lowercase.
string s;
cin>>s;

int n= s.size();

for(int i=0;i<n;i++)
{
if(s[i]>='A' && s[i]<='Z')
{
s[i]=s[i]+32;
}
}
cout<<s[i];

Method 2:

string s;
cin>>s;

int n= s.size();

for(int i=0;i<n;i++)
{

s[i]=tolower(s[i]);

}
cout<<s[i];

275	Category 1 – Basic String Handling	Count how many characters (excluding spaces) are in the string.

string s;
getline(cin, s);

int count = 0;

for(int i = 0; i < s.size(); i++)
{
    if(s[i] != ' ')
    {
        count++;
    }
}

cout << count;

276	Category 1 – Basic String Handling	Count how many words are in a sentence.

string s;
getline(cin, s);

int count = 0;

for(int i = 0; i < s.size(); i++)
{
    // Start of a word
    if(s[i] != ' ' && (i == 0 || s[i-1] == ' '))
    {
        count++;
    }
}

cout << "Total Words: " << count;

277	Category 1 – Basic String Handling	Take two strings and print them concatenated.

string s,s1;
cin>>s;
cin>>s1;


cout<<s+s1;


278	Category 1 – Basic String Handling	Compare two strings lexicographically (like dictionary order).

279	Category 1 – Basic String Handling	Print the ASCII value of each character in a string.

string s;
cin >> s;

int n= s.size();

for(int i=0;i<n;i++)
{
cout<<(int)s[i];
}


280	Category 1 – Basic String Handling	Check whether the string is empty or not.


280	Category 1 – Basic String Handling	Check whether the string is empty or not.


string s;
cin>>s;

int n=s.size();

if(n==0){
cout<<"empty";
}
else{
cout<<"Not empty"
}

                                 🔥 Category 2 – Counting & Character Analysis 


281	Category 2 – Counting & Character Analysis	Count how many vowels and consonants are in a string.

string s;
cin>>s;

int count =0;
count1=0;


int n=s.length();

for(int i=0;i<n;i++)
{
if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
{
count++;
}
else {
count1++
}
}

cout<<"vovel vount"<<count;
cout<<"Constant Count"<<count1;

282	Category 2 – Counting & Character Analysis	Count the number of digits, letters, and special characters in a string.
#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int digit = 0, letter = 0, special = 0;

    int n = s.size();

    for(int i = 0; i < n; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            digit++;
        }
        else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            letter++;
        }
        else
        {
            special++;
        }
    }

    cout << "Digits: " << digit << endl;
    cout << "Letters: " << letter << endl;
    cout << "Special Characters: " << special << endl;
}

283	Category 2 – Counting & Character Analysis	Count how many uppercase and lowercase letters a string has.

#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int lowercount = 0;
    int uppercount = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            lowercount++;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            uppercount++;
        }
    }

    cout << "Lowercase: " << lowercount << endl;
    cout << "Uppercase: " << uppercount << endl;
}

284	Category 2 – Counting & Character Analysis	Find the frequency of each character in a string (without using a map).

string s;
cin>>s;

int n=s.size();

int arr[26];

for(int i=0;i<n;i++)
{
arr[s[i]]++;
}

for(int i=0;i<26;i++)
{
cout<<arr[i];
}

Correct :

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int arr[26] = {0};

    for(int i = 0; i < s.size(); i++)
    {
        char ch = tolower(s[i]);  // convert to lowercase

        if(ch >= 'a' && ch <= 'z')
        {
            arr[ch - 'a']++;
        }
    }

    for(int i = 0; i < 26; i++)
    {
        if(arr[i] > 0)
        {
            cout << char(i + 'a') << " -> " << arr[i] << endl;
        }
    }
}

285	Category 2 – Counting & Character Analysis	Count how many spaces are there in a sentence.

string s;
geline(cin, s);

int count =0;
int n=s.size();

for(int i =0; i<n ;i++)
{
if(s[i]==' ')
{
count++;
}
}

cout<<"Count of Spacces"<<count;

286	Category 2 – Counting & Character Analysis	Count how many times a given character appears in a string.

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    char val;
    cin >> val;

    int count = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(tolower(s[i]) == tolower(val))
        {
            count++;
        }
    }

    cout << "Count: " << count << endl;
}

287	Category 2 – Counting & Character Analysis	Count how many alphabets are before 'm' and after 'm' in a given string.

#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    int index = -1;

    // find position of 'm'
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'm')
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        cout << "'m' not found in string";
    }
    else
    {
        cout << "Before: " << index << endl;
        cout << "After: " << n - index - 1 << endl;
    }
}


288	Category 2 – Counting & Character Analysis	Count how many substrings start and end with the same character (simple logic).


#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int freq[26] = {0};

    // count frequency
    for(int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }

    int ans = 0;

    // apply formula
    for(int i = 0; i < 26; i++)
    {
        int k = freq[i];
        ans += (k * (k + 1)) / 2;
    }

    cout << "Total substrings: " << ans << endl;
}

289	Category 2 – Counting & Character Analysis	Print how many words start with a vowel in a sentence.
290	Category 2 – Counting & Character Analysis	Count how many words end with 's'.
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int count = 0;
    int n = s.size();

    for(int i = 0; i < n; i++)
    {
        // check end of word
        if((i == n-1 || s[i+1] == ' ') && isalpha(s[i]))
        {
            char ch = tolower(s[i]);

            if(ch == 's')
            {
                count++;
            }
        }
    }

    cout << "Words ending with 's': " << count << endl;
}

                                    🔥 Category 3 – Reversing & Palindromic Thinking
291	Category 3 – Reversing & Palindromic Thinking	Reverse a string without using built-in reverse.

string s;
cin>>s;

int n= s.size();

string rev =' ';

for(int i=n-1;i>=0;i--)
{
rev=rev+s[i];
}


cout<<rev;

292	Category 3 – Reversing & Palindromic Thinking	Reverse each word in a sentence.

#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    string word = "";
    string result = "";

    for(int i = 0; i <= s.size(); i++)
    {
        // word end
        if(i == s.size() || s[i] == ' ')
        {
            // reverse current word
            for(int j = word.size() - 1; j >= 0; j--)
            {
                result += word[j];
            }

            result += ' ';  // add space
            word = "";      // reset
        }
        else
        {
            word += s[i];
        }
    }

    cout << result;
}


293	Category 3 – Reversing & Palindromic Thinking	Reverse the order of words in a sentence

#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    string word = "";
    string result = "";

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            // reverse word
            for(int j = word.size() - 1; j >= 0; j--)
            {
                result += word[j];
            }

            result += ' ';
            word = "";
        }
        else
        {
            word += s[i];
        }
    }

    // reverse last word (important)
    for(int j = word.size() - 1; j >= 0; j--)
    {
        result += word[j];
    }

    cout << result;
}

294	Category 3 – Reversing & Palindromic Thinking	Check whether a string is a palindrome.

string s;
cin>>s;


int n = s.size();

string rev="";
for(int i=n-1;i>=0;i--)
{
rev+=s[i];
}

if(rev==s)
{
cout<<"Palindrome";
}
else{
cout<<"Not Palindrome";
}

295	Category 3 – Reversing & Palindromic Thinking	Check if two strings are the reverse of each other.

string s1,s2;
cin>>s1>>s2;


int n = s1.size();

string rev="";
for(int i=n-1;i>=0;i--)
{
rev+=s1[i];
}

if(rev==s2)
{
cout<<"Reverse of Eachother";
}
else{
cout<<"Not Reverse of Eachother";
}

296	Category 3 – Reversing & Palindromic Thinking	Print the middle character(s) of a string.
#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    if(n % 2 == 0)
    {
        // even length → 2 middle characters
        cout << s[n/2 - 1] << s[n/2];
    }
    else
    {
        // odd length → 1 middle character
        cout << s[n/2];
    }
}
297	Category 3 – Reversing & Palindromic Thinking	Print the second half of the string in reverse.

#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    int mid = n / 2;

    string rev = "";

    for(int i = n - 1; i >= mid; i--)
    {
        rev += s[i];
    }

    cout << rev;
}

299	Category 3 – Reversing & Palindromic Thinking	Reverse only characters, keeping digits in place.





300	Category 3 – Reversing & Palindromic Thinking	Reverse string but skip spaces.

 string s;
    getline(cin, s);

    int i = 0, j = s.size() - 1;

    while(i < j)
    {
        if(s[i] == ' ')
        {
            i++;
        }
        else if(s[j] == ' ')
        {
            j--;
        }
        else
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }


                        🔥 Category 4 – Character & Word Manipulation

301	Category 4 – Character & Word Manipulation	Remove all vowels from a string.

string s;
cin>> s;

int n= s.size();

for(int i=0;i<n;i++)
{
if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
{
continue;
}
cout<<s[i];
}

302	Category 4 – Character & Word Manipulation	Remove all spaces from a string.

  string s;
    getline(cin, s);   // important

    string result = "";

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            continue;
        }
        result += s[i];
    }

    cout << result;
}

303	Category 4 – Character & Word Manipulation	Replace all vowels with '*'.
#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string result = "";

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            result += '*';
        }
        else
        {
            result += s[i];
        }
    }

    cout << result;
}

304	Category 4 – Character & Word Manipulation	Replace all spaces with '_'.

305	Category 4 – Character & Word Manipulation	Print the string after removing all digits.

string s;
    getline(cin, s);   // important

    string result = "";

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i]<='9')
        {
            continue;
        }
        result += s[i];
    }

    cout << result;

306	Category 4 – Character & Word Manipulation	Remove duplicate characters from a string

string s;
cin>>s;

int n= s.size();

int arr[26]={0};

for(int i=0;i<n;i++)
{
arr[s[i]-'a']++;

}

for(int i=0;i<26;i++)
{
if(arr[i]==1)
{
cout<<i+'a';
}
}

Correct: 
string s;
    cin >> s;

    int visited[256] = {0};  // for all ASCII

    string result = "";

    for(int i = 0; i < s.size(); i++)
    {
        if(visited[s[i]] == 0)
        {
            result += s[i];
            visited[s[i]] = 1;
        }
    }

    cout << result;


307	Category 4 – Character & Word Manipulation	Keep only the first occurrence of each character.

    string s;
    cin >> s;

    int visited[256] = {0};  // for all ASCII

    string result = "";

    for(int i = 0; i < s.size(); i++)
    {
        if(visited[s[i]] == 0)
        {
            result += s[i];
            visited[s[i]] = 1;
        }
    }

    cout << result;




