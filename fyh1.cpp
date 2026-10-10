#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;
 
string reverse(string input[],int inputn[],int n) {
    vector<int> stack;
    vector<int> pp;
    string result;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        if (input[i]=="+")
        {
     
            int t = map[inputn[i]];
            while ( t!=0)
            {
                
                map[stack[stack.size() - 1]] = 0;
                stack.pop_back();
                
                t = map[inputn[i]];
                result += "-";
            }
            stack.push_back(inputn[i]);
            map[inputn[i]] = 1;
            result += "+";
        }
        else if (input[i]=="F")
        {
            int t = map[inputn[i]];
            while (t != 0)
            {

                map[stack[stack.size() - 1]] = 0;
                stack.pop_back();

                t = map[inputn[i]];
                result += "-";
            }
            result += "?";
        }
        else if (input[i] == "T")
        {
            result += "?";
        }
         
         
    }
    return result;
}

int main() {
    int rows = 0;
    int slength = 0;
    cin >> rows;
    for (int i = 0; i < rows; i++)
    {
        cin >> slength;
        string* input=new string[slength];
        int *inputN=new int[slength];
        for (int i = 0; i < slength; i++)
        {
            cin >> input[i];
            cin >> inputN[i];
        }
         
        cout << reverse(input, inputN, slength) << endl;
    }
     
    
};