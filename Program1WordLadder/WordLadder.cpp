#include "WordLadder.h"
#include <fstream>


using namespace std;

    /* Passes in the name of a file that contains a dictionary of 5-letter words.
       Fills the list (dict) with the words within this file. 
       If the file does not open for any reason or if any word within the file
       does not have exactly 5 characters, this function should output an
       error message and return.
    */

WordLadder::WordLadder(const string & s) {

    ifstream fin;
    string word;
    fin.open(s);
    
    if(!fin.is_open()) {
        cout << "Could not open file." << endl;
        exit(0);
    }

    else {
        while (fin >> word) {
            dict.push_back(word);
        //     if (word.size() != 5) {
        //     cout << "Word does not have 5 characters." << endl;
        //     return;
        // }
        }
    }

    fin.close();
}

    /* Passes in two 5-letter words and the name of an output file.
       Outputs to this file a word ladder that starts from the first word passed in
       and ends with the second word passed in.
       If either word passed in does not exist in the dictionary (dict),
       this function should output an error message and return.
       Otherwise, this function outputs to the file the word ladder it finds or outputs
       to the file, the message, "No Word Ladder Found."
    */
void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    string wordAtFront;
    bool foundStart = false;
    bool foundEnd = false;
    
    for(list<string>::iterator i = dict.begin(); i != dict.end(); ++i) {
        if(*i == start) {
            foundStart = true;
        }
        if(*i == end) {
            foundEnd = true;
        }
    }
    if(foundStart == false || foundEnd == false) {
        cout << start << " or " << end << " does not exist in the dictionary." << endl;
        return;
    }

    ofstream outFS;
    outFS.open(outputFile);
    if (!outFS.is_open())
    {
        cout << "Error opening " << outputFile << endl;
        return;
    }

    if (start == end)
    {
        outFS << start;
        outFS.close();
        return;
    }
    stack<string> stackS;
    queue<stack<string> > queueS;

    stackS.push(start);
    queueS.push(stackS);
    while (!queueS.empty())
    {
        string wordTop = queueS.front().top();
        // for (list<string>::iterator i = dict.begin(); i != dict.end(); ++i)
        // {
        list<string>::iterator i = dict.begin();
        while (i != dict.end()){
            int counter = 0;
            for (unsigned j = 0; j < wordTop.size(); ++j)
            {
                if (i->at(j) == wordTop.at(j))
                {
                    ++counter;
                }
            }
            if (counter == 4)
            {
                // cout << "if: " << *i ;
                stack<string> copyStack = queueS.front();
                copyStack.push(*i);
                if (*i == end)
                {
                    vector <string> output;
                    while (!copyStack.empty())
                    {
                        output.insert(output.begin(), copyStack.top());
                        copyStack.pop();
                    }
                    for (unsigned k = 0; k < output.size(); ++k)
                    {
                        outFS << output.at(k) << " ";
                    }

                    outFS.close();
                    return;
                }
                else
                {
                    // cout << " ib: " << *i;
                    queueS.push(copyStack);
                    i = dict.erase(i);
                    // cout << " ia: " << *i << endl;            
                }
            }
            else
            {
                ++i;
            }
            
        }  
        queueS.pop();
    }

    outFS << "No Word Ladder Found.";
    outFS.close();
}


