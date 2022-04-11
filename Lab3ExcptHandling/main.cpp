#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
    unsigned min = index;
    for (unsigned i = index; i < vals.size(); ++i)
    {
        if (vals.at(i) < vals.at(min))
        {
            min = i;
        }
    }
    return min;
}

template<typename T>
void selection_sort(vector<T> &vals)
{
    for (unsigned i = 0; i < vals.size(); ++i)
    {   
        T temp = vals.at(i);
        unsigned minIn = min_index(vals, i);
        vals.at(i) = vals.at(minIn);
        vals.at(minIn) = temp;
    }
}

template<typename T>
T getElement(vector<T> vals, int index)
{
    return vals.at(index);
}


vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}




int main(){

    // vector<int> test(5);
    // test.at(0) = 9;
    // test.at(1) = 4;
    // test.at(2) = 8;
    // test.at(3) = 6;
    // test.at(4) = 1;
    // cout << "Before: ";
    // for (unsigned i = 0; i < test.size(); ++i)
    // {
    //     cout << test.at(i) << " ";
    // }
    // cout << endl;
    // selection_sort(test);
    // cout << "After: ";
    // for (unsigned i = 0; i < test.size(); ++i)
    // {
    //     cout << test.at(i) << " ";
    // }
    // cout << endl;
    // return 0;

    //Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     unsigned int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
        try {
            cout << "Enter a number: " << endl;
            cin >> index;
            if (index < 0 || index >= vals.size())
            {
                throw runtime_error("Invalid index.");
            }
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
        catch (runtime_error& excpt) {
            cout << excpt.what() << endl;
        } 
    }
    return 0;
}