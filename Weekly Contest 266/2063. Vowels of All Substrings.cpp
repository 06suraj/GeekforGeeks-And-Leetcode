class Solution {
public:
  // taken from  https://www.geeksforgeeks.org/count-the-number-of-vowels-occurred-in-the-substrings-of-given-string/
    
    long long vowel_calc(string s)
{
    int n = s.length();
    vector<long long int> arr;
 
    for (int i = 0; i < n; i++) {
 
        if (i == 0)
            // No. of occurrences of 0th character
            // in all the substrings
            arr.push_back(n);
 
        else
            // No. of occurrences of the ith character
            // in all the substrings
            arr.push_back((n - i) + arr[i - 1] - i);
    }
 
   long long int sum = 0;
    for (int i = 0; i < n; i++)
 
        // Check if ith character is a vowel
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
            || s[i] == 'o' || s[i] == 'u')
            sum += arr[i];
 
    // Return the total sum
    // of occurrences of vowels
    return sum;
}
    long long countVowels(string word) {
        return (vowel_calc(word));
    }
};
