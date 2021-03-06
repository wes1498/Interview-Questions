#include <iostream>
#include <cassert> 
#include <unordered_map>
#include <vector>

using namespace std;

// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

// The order of output does not matter.

// Example 1:

// Input:
// s: "cbaebabacd" p: "abc"

// Output:
// [0, 6]

// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    unordered_map<char,int> table;
    
    // initialize table for counting
    for(auto _p : p){
        table[_p]++;
    }
    
    int counter=0,begin=0,end=0;
    
    while(end < s.size()){
        
        char endChar=s[end];
        if(table.find(endChar) != table.end()) {
            // if found, decrement the 'occurence' in table
            table[endChar]--;
            if(table[endChar]==0){counter++;}
        }
        end++;
        
        while(counter == table.size()){
            if(end-begin == p.length()){
                result.push_back(begin);
            }
            
            char startChar=s[begin];
            if(table.count(startChar) == 1){
                table[startChar]++;
                if(table[startChar] > 0){counter--;}
            }
            begin++;
        }
    }
    return result;
}

int main() {
    vector<int> result;
    result.push_back(0);
    result.push_back(6);

    assert(findAnagrams("cbaebabacd", "abc") == result);
    return 0;
}