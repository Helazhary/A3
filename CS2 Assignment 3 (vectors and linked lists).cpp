#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

void insertAfter(int fv, int sv, vector<int>& v);
LinkedList makelist(vector<int> s) {
    LinkedList ll;

    //sorting

    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = 0; j < s.size() - i - 1; j++)
        {
            if (s[j] > s[j + 1])
            {
               int temp = s[j];
               s[j] = s[j + 1];
               s[j + 1] = temp;
            }
        }
    }
    

    ll.addnodeStart(s[0]);
    for (int i = 1; i < s.size();i++) {
        if (s[i] == s[i - 1]) {
            //++ occurance
            ll.getPointToLast()->occurences++;
        }
        else {
            ll.addnodeEnd(s[i]);
        }
    }
    
    return ll;
}
int main()
{
    int intam; //amount of integers to be initially inserted in the vector
    int value; //integer to be inserted by user into the vector
    int firstValue, secondValue;

    //------------------------user input to vector---------------------
    cout << "Please enter the amount of integers you wish to store:";
    cin >> intam;
    vector <int> values;
    for (int i = 0; i < intam; i++)
    {
        cin >> value;
        values.push_back(value);
    }

    cout << endl << endl;

    cout << "Vector before insert is: " << endl;
    for (int i = 0;i < values.size();i++) {
        cout << values[i] << endl;
    }
    cout << endl << endl;

    //-------------------------------insertAfter------------------------
    cout << "Please enter a value, and then one which you'd like to place after:" << endl;
    cout << "value to find: ";
    cin >> firstValue;
    cout << " value to insert afer: ";
    cin >> secondValue;
    insertAfter(firstValue, secondValue, values);

    cout << endl << endl;

    cout << "Vector after insert is: " << endl;
    for (int i = 0;i < values.size();i++) {
        cout << values[i] << endl;
    }

    cout << endl << endl;
    

    LinkedList test=makelist(values);
    cout << "Outputing LinkedList: " << endl;
    test.printlist();

    cout << endl << endl;
    cout << "Sum of node integer values is: " << test.sum() << endl;
    cout << endl << endl;

    cout << "Testing Remove: " << endl;
    test.removenode(1);
    test.printlist();

    cout << endl << endl;

    cout << "Testing Add: " << endl;
    test.addnodeStart(5);
    test.addnodeEnd(10);
    test.addnodeToX(15, 2);
    test.printlist();
}    

void insertAfter(int fv, int sv, vector<int>& v)
{
    int size = v.size();
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (fv == v[i])
        {
            v.insert(v.begin()+i+1, sv);
            count++;
        }
    }
    if (count == 0) {
        cout << "FirstValue does not exist in this vector. Nothing was inserted." << endl;
    }
}





