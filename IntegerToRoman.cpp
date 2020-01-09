12. Integer to Roman
Medium

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"

Example 2:

Input: 4
Output: "IV"

Example 3:

Input: 9
Output: "IX"

Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

/*
class Solution {
    
string digitToString(int digit, int count) {
    string result = "";
    switch (count) {
        case 1:
            if (digit <= 3) {
                while (digit > 0) {
                    result = result + "I";
                    digit--;
                }
                return result;
            }
            
            if (digit == 4) return "IV";
            
            if (digit < 9) {
                result = "V";
                while (digit > 5) {
                    result += "I";
                    digit--;
                }
                return result;
            }
            
            if (digit == 9) return "IX"; 
            break;
        case 2:
            if (digit <= 3) {
                while (digit > 0) {
                    result = result + "X";
                    digit--;
                }
                return result;
            }
            
            if (digit == 4) {
                return "XL";
            }
            
            if (digit < 9) {
                result = "L";
                while (digit > 5) {
                    result += "X";
                    digit--;
                }
                return result;
            }
            
            if (digit == 9) return "XC";
            break;
        case 3:
           if (digit <= 3) {
                while (digit > 0) {
                    result = result + "C";
                    digit--;
                }
                return result;
            } 
            if (digit == 4) {
                return "CD";
            }
            if (digit < 9) {
                result = "D";
                while (digit > 5) {
                    result += "C";
                    digit--;
                }
                return result;
            }
            if (digit == 9) return "CM";
            break;
        case 4: 
            if (digit <= 3) {
              while (digit > 0) {
                    result = result + "M";
                    digit--;
                }
                return result;
            }
            cout << "Number larger than 3999";
            break;
    }
    return result;
}
    
public:
    string intToRoman(int num) {
        
        string result = ""; int count = 1;
        
        int number = num;
        
        while (number > 0) {
            int digit = number % 10;
            number = number/10;
            cout << "count - " << count << " num - " << number << endl;
            string digit_result = digitToString(digit, count);
            result = digit_result + result;
            count++;
        }
        return result;
    }
};
*/
class Solution {
private:
    const vector<pair<int, char*>> conv = {{1000, "M"},
                                            {900, "CM"},
                                            {500, "D"},
                                            {400, "CD"},
                                            {100, "C"},
                                            {90, "XC"},
                                            {50, "L"},
                                            {40, "XL"},
                                            {10, "X"},
                                            {9, "IX"},
                                            {5, "V"},
                                            {4, "IV"},
                                            {1, "I"}};
public:
    string intToRoman(int num) {
        string res;
        auto it = conv.begin();
        while (num > 0 && it != conv.end()) {
            if (num >= it->first) {
                num -= it->first;
                res += it->second;
            } else {
                ++it;
            }
        }
        return res;
    }
};