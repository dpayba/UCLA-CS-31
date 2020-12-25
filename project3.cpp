#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;

bool isValidUppercaseStateCode(string stateCode) // checks if a proper state code
{
    const string codes =
        "AL.AK.AZ.AR.CA.CO.CT.DE.DC.FL.GA.HI.ID.IL.IN.IA.KS."
        "KY.LA.ME.MD.MA.MI.MN.MO.MS.MT.NE.NV.NH.NJ.NM.NY.NC."
        "ND.OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    return (stateCode.size() == 2  &&
            stateCode.find('.') == string::npos  &&  // no '.' in stateCode
            codes.find(stateCode) != string::npos);  // match found
}

bool isSyntacticallyCorrect(string pollData) { // checks syntax of string
    
    int i = 0;
    while (i != pollData.size()) {
        if (pollData == "") // empty string is syntactically correct
            return true;
        else if (isdigit(pollData[i]) && isValidUppercaseStateCode(pollData.substr(i+1,2))) {
            if (isalpha(pollData[i+3])) // if string passes digit, state, and alpha test, loop again
                i+=4;
            else
                return false;
                
    }
        else if ((isdigit(pollData[i]) && (isdigit(pollData[i+1])))) {
            if ((isValidUppercaseStateCode(pollData.substr(i+2,2))) && (isalpha(pollData[i+4])))
                i+=5; // same process as above but this runs if detects 2 digits instead of 1
            else
                return false;
    }
        else {
            return false;
            break;
        }
    }
    return true;
}

bool checkZero(string pollData, int& pos) { // function created to check for any zeroes while reading string
    
    pos++;
    if (pos == pollData.size())
        return false;
    if (isalpha(pollData[pos]))
        return false;
    if (pollData[pos] == '0')
        return false;
    
    pos++;
    return true;
}

int tallyVotes(string pollData, char party, int& voteTally) {
    string upperData;
    for (int i = 0; i != pollData.size(); i++) // converts pollData to all uppercase
        upperData += toupper(pollData.at(i));
    
    if (!isSyntacticallyCorrect(upperData)) // returns 1 if not syntactically correct
        return 1;
    
    if (!isalpha(party)) // returns 2 if party isn't an alpha
        return 2;
    else
        party = toupper(party);
    
    int i = 0;
    while (i != upperData.size()) { // loop to check for any zeroes
        if (upperData[i] == '0') {
            if (!checkZero(upperData, i))
                return 3;
        }
        else {
            break;
        }
    }
    
    voteTally = 0;
    for (int i = 0; i != upperData.size(); i++) { // adds up all values ties to the party designated
        if (isdigit(upperData[i])) {
            if (isdigit(upperData[i+1])){
                if(upperData[i+4] == toupper(party)) { // if votes are 2 digits
                    voteTally += stoi(upperData.substr(i,2));
                    i++;
                }
            }
            else if(upperData[i+3] == toupper(party)) { // votes 1 digit
                voteTally += stoi(upperData.substr(i,1));
                i++;
            }
        }
    }
    return 0;
}
        

            
int main() {
    
    assert(isSyntacticallyCorrect("38TXR55CAD"));
    assert(!isSyntacticallyCorrect("38MXR55CAD"));
    int votes;
    int v = 0;
    assert(tallyVotes(" ", 'd', v));
    votes = -999;
    assert(tallyVotes("38TXR55CAD6Msr29nYd06UTL", 'd', votes) == 0  &&  votes == 84);
    votes = -999;    // so we can detect whether tallyVotes sets votes
    assert(tallyVotes("38TXR55CAD", '%', votes) == 2  &&  votes == -999);
    cout << "All tests succeeded" << endl;
    
}


