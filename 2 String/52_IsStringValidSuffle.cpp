#include <bits/stdc++.h>

using namespace std;

/*
1XY2 is a valid shuffle of XY and 12
Y1X2 is a valid shuffle of XY and 12     
Y21XX is not a valid shuffle of XY and 12
*/

/*
import java.util.Arrays;

class Test {


  // length of result string should be equal to sum of two strings
  static boolean checkLength(String first, String second, String result) {
    if (first.length() + second.length() != result.length()) {
      return false;
    }
    else {
      return true;
    }
  }

  // this method converts the string to char array 
  // sorts the char array
  // convert the char array to string and return it
  static String sortString(String str) {
  
    char[] charArray = str.toCharArray();
    Arrays.sort(charArray);

    // convert char array back to string
    str = String.valueOf(charArray);

    return str;
  }

  // this method compares each character of the result with 
  // individual characters of the first and second string
  static boolean shuffleCheck(String first, String second, String result) {
    
    // sort each string to make comparison easier
    first = sortString(first);
    second = sortString(second);
    result = sortString(result);

    // variables to track each character of 3 strings
    int i = 0, j = 0, k = 0;

    // iterate through all characters of result
    while (k != result.length()) {

      // check if first character of result matches
      // with first character of first string
      if (i < first.length() && first.charAt(i) == result.charAt(k))
        i++;

      // check if first character of result matches
      // with the first character of second string
      else if (j < second.length() && second.charAt(j) == result.charAt(k))
        j++;

      // if the character doesn't match
      else {
        return false;
      }

      // access next character of result
      k++;
    }

    // after accessing all characters of result
    // if either first or second has some characters left
    if(i < first.length() || j < second.length()) {
      return false;
    }

    return true;
  }

  public static void main(String[] args) {

    String first = "XY";
    String second = "12";
    String[] results = {"1XY2", "Y1X2", "Y21XX"};

    // call the method to check if result string is
    // shuffle of the string first and second
    for (String result : results) {
      if (checkLength(first, second, result) == true && shuffleCheck(first, second, result) == true) {
        System.out.println(result + " is a valid shuffle of " + first + " and " + second);
      }
      else {
        System.out.println(result + " is not a valid shuffle of " + first + " and " + second);
      }
    }
  }
}

*/

int main(){
    int n;
    cin>>n;
    int *arr = new int(n); 

    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<n;i++) cout<<arr[i];

    return 0;
}