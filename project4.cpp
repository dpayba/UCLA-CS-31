#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);


int main () {
    
    string a[4] = { "martha", "mark", "lindsey", "sara" };
    assert(appendToAll(a, 4, "!!!") == 4 && a[1] == "mark!!!" && a[2] == "lindsey!!!");
    string b[3] = { "", "", ""};
    assert(appendToAll(b, 3, "Hello") == 3 && b[1] == "Hello" && b[2] == "Hello");
    string c[4] = { "martha", "mark", "lindsey", "sara" };
    assert(appendToAll(c, -5, "???") == -1);
    
    string d[7] = { "martha", "mark", "joe", "susan", "", "kamala", "lindsey" };
    assert(lookup(d, 7, "kamala") == 5);
    assert(lookup(d, 7, "joe") == 2);
    assert(lookup(d, 2, "joe") == -1);
    assert(lookup(d, 7, "donald") == -1);
    assert(lookup(d, -5, "kamala") == -1);
    assert(lookup(d, 7, "JoE") == -1);
    assert(lookup(d, 7, "") == 4);
    assert(lookup(d, 0, "") == -1);
    
    string e[7] = { "martha", "mark", "joe", "susan", "", "kamala", "lindsey" };
    assert(positionOfMax(e, 7) == 3);
    assert(positionOfMax(e, -5) == -1);
    assert(positionOfMax(e, 1) == 0);
    string f[3] = { "martha", "martha", "martha"};
    assert(positionOfMax(f, 3) == 0);
    string g[3] = { "Donald", "donald", "DONALD" };
    assert(positionOfMax(g, 3) == 1);
    
    string h[4] = { "martha", "mark", "lindsey", "sara" };
    assert(rotateLeft(h, 4, 1) == 1 && h[1] == "lindsey" && h[3] == "mark");
    assert(rotateLeft(h, 4, 5) == -1);
    assert(rotateLeft(h, 4, 4) == -1);
    string i[5] = { "kamala", "jamie", "lindsey", "sara", "mark" };
    assert(rotateLeft(i, 5, 1) == 1 && i[0] == "kamala" && i[4] == "jamie");
    string j[3] = { "martha", "martha", "martha"};
    assert(rotateLeft(j, 0, 0) == -1);
    
    string k[5] = { "mark", "mark", "mark", "susan", "susan" };
    assert(countRuns(k, 5) == 2);
    string l[9] = { "susan", "donald", "mike", "mike", "joe", "joe", "joe", "mike", "mike" };
    assert(countRuns(l, 9) == 5);
    string m[0] = { };
    assert(countRuns(m, 0) == -1);
    
    string n[3] = { "lindsey", "joe", "mike" };
    assert(flip(n, 3) == 3 && n[0] == "mike" && n[2] == "lindsey");
    string o[5] = { "kamala", "jamie", "lindsey", "sara", "mark" };
    assert(flip(o, 5) == 5 && o[0] == "mark" && n[2] == "lindsey");
    string p[6] = { "donald", "mike", "", "susan", "sara", "jamie" };
    assert(flip(p, 4) == 4 && p[0] == "susan" && p[5] == "jamie");
    
    string q[6] = { "donald", "mike", "", "susan", "sara", "jamie" };
    string r[5] = { "donald", "mike", "jamie", "", "susan" };
    assert(differ(q, 6, r, 5) == 2);
    assert(differ(q, 2, r, 1) == 1);
    string s[5] = { "donald", "mike", "jamie", "", "susan" };
    assert(differ(r, 5, s, 5) == 5);
    assert(differ(r, 3, s, 3) == 3);
    assert(differ(r, 5, s, 0) == 0);
    assert(differ(r, 0, s, 0) == 0);
    assert(differ(r, 7, s, 10) == 5);
    string t[3] = { "donald", "donald", "donald" };
    assert(differ(s, 5, t, 3) == 1);
    
    string u[10] = { "kamala", "mark", "sara", "martha", "donald", "lindsey" };
    string v[10] = { "mark", "sara", "martha" };
    assert(subsequence(u, 6, v, 3) == 1);
    string w[10] = { "mark", "martha", "sara", "mark", "sara", "martha" };
    string substring[3] = { "mark", "sara", "martha" };
    assert(subsequence(w, 10, substring, 3) == 3);
    string x[0];
    assert(subsequence(u, 10, x, 0) == -1);
    
    string y[10] = { "kamala", "mark", "sara", "martha", "donald", "lindsey" };
    string z[10] = { "jamie", "donald", "martha", "mark" };
    assert(lookupAny(y, 6, z, 4) == 1);
    assert(lookupAny(y, 6, z, 3) == 3);
    assert(lookupAny(y, 2, z, 4) == 1);
    assert(lookupAny(y, 6, z, 0) == -1);
    string a1[10] = { "jamie", "mark", "sara", "martha", "donald", "lindsey" };
    assert(lookupAny(z, 1, a1, 2) == 0);
    assert(lookupAny(z, 0, a1, 0) == -1);
    assert(lookupAny(z, 0, a1, 1) == -1);
    assert(lookupAny(z, 1, a1, 0) == -1);
    
    string b1[6] = { "jamie", "lindsey", "mark", "susan", "joe", "donald" };
    assert(divide(b1, 6, "kamala") == 3);
    assert(divide(b1, 6, "abe") == 0);
    assert(divide(b1, 3, "zoe") == 3);
    assert(divide(b1, 6, "zoe") == 6);
    assert(divide(b1, 6, "jamie") == 1);
    string c1[4] = { "mark", "sara", "lindsey", "mike" };
    assert(divide(c1, 4, "mike") == 2);
    assert(divide(c1, 4, "mark") == 1);
    string d1[10] = { "michael", "aaron", "jeff", "richard", "adam", "zoe", "zach", "daniel", "steven", "patrick" };
    assert(divide(d1, 10, "michael") == 4 && d1[4] == "michael" && d1[9] == "patrick");
    assert(divide(d1, 10, "matthew") == 4 && d1[1] == "aaron" && d1[3] == "adam");
    assert(divide(d1, 10, "zzzzz") == 10 && d1[6] == "zach" && d1[8] == "steven");
    assert(divide(d1, 10, "zoe") == 9);
    assert(divide(d1, 10, "aaaaa") == 0);
    string e1[7] = { "martha", "mark", "joe", "susan", "", "kamala", "lindsey" };
    assert(divide(e1, 7, "lindsey") == 3);
    assert(divide(e1, 7, "") == 0 && e1[0] == "");
    assert(divide(e1, 0, "mark") == 0);
    string f1[5] = { "mike", "mike", "mike", "mike", "mike" };
    assert(divide(f1, 5, "mike") == 0);
        
    cerr << "All tests succeeded" << endl;


}


int appendToAll(string a[], int n, string value) {
    if (n < 0) // makes sure arrray has some type of element
        return -1;
    
    for (int i = 0; i < n; i++) // adds string value to end of each element
        a[i] += value;
    
    return n;
}


int lookup(const string a[], int n, string target) {
    if (n < 0)
        return -1;
    
    for (int i = 0; i < n; i++) { // loops through string until it finds target string, returns index
        if (a[i] == target) {
            return i;
        }
    }
    return -1; // return 1 if no match found
}


int positionOfMax(const string a[], int n) {
    if (n <= 0)
        return -1;
    
    string max = a[0];
    int maxIndex = 0;
    for (int i = 0; i < n; i++) { // compares every string in array
        if (a[i] > max) {
            max = a[i];      // when max found, records string and index of string
            maxIndex = i;
        }
    }
    
    return maxIndex;
}


int rotateLeft(string a[], int n, int pos) {
    if (n <= 0 || n <= pos)
        return -1;
    
    string position = a[pos];
    int i = 0;
    int j = 0;
    while(i < n) {
        if (i == pos) { // if index equal to pos, skip
            i++;
        }
        else {
            a[j] = a[i]; // copies all elements to left of pos
            i++;
            j++;
        }
    }
    
    a[n-1] = position; // sets last element to the element deleted
    
    return pos;
}


int countRuns(const string a[], int n) {
    if (n <= 0)
        return -1;
    
    int counter = 0;
    
    int i = 0;
    while(i < n) {
        if (a[i] != a[i+1]) { // if next element not equal, add to counter
            counter++;
            i++;
        }
        else {
            int j = i;
            while (j < n) {
                if (a[j] == a[j+1]) // loop until elements not equal
                    j++;
                else {
                    i = j;
                    break;
                }
            }
        }
    }
    
    return counter;
}


int flip(string a[], int n) {
    if (n <= 0)
        return -1;
    
    string temp;
    int j = 0;
    for (int i = n-1; i >= n/2; i--) { // loops half of n, switches strings with a temporary string
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        j++;
    }
    
    return n;
}


int differ(const string a1[], int n1, const string a2[], int n2) {
    if (n1 < 0 || n2 < 0)
        return -1;
    
    if (n1 == 0 || n2 == 0)
        return 0;
    
    if (n1 <= n2) { // checks which n value is smaller, tells which value to return
        for (int i = 0; i < n1; i++) {
            if (a1[i] != a2[i]) // if not equal, return index
                return i;
        }
        return n1; // if everything equal up to point
    }
    
    else {
        for(int i = 0; i < n2; i++) { // if n2 greater than n1
            if (a1[i] != a2[i])
                return i;
        }
        return n2;
    }
}

int subsequence(const string a1[], int n1, const string a2[], int n2) {
    if (n1 <= 0 || n2 <= 0)
        return -1;
    
    int counter = 0;
    for (int i = 0; i < n1; i++) {
        if (a1[i] == a2[0]) { // checks for where to start
            for (int j = 0; j < n2; j++) {
                if (a1[i+j] == a2[j]) // loops to check if everything equal, saves index
                    counter = i;
                
                else { // executes if no longer matches, reset counter and break
                    counter = 0;
                    break;
                }
            }
        }
    }
    
    if (counter > 0)
        return counter; // counter equals index of start
    else
        return -1;
    
}


int lookupAny(const string a1[], int n1, const string a2[], int n2) {
    if (n1 < 0 || n2 < 0)
        return -1;
    
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) { // looks through each a2 element, returns index if equal
            if (a1[i] == a2[j])
                return i;
            
        }
    }
        
    return -1;
    
}

int divide(string a[], int n, string divider) {
    if (n < 0)
        return -1;
    
    string temp;
    for (int i = 0; i < n-2; i++) {
        if (a[i] >= divider) { // find first element greater than divider
            int j = n-1;
            while(j > i) {
                if (a[j] >= divider) { // loop until finds an element less than divider to switch with
                    j--;
                }
                else {
                    temp = a[i]; // switch greater and less than elements
                    a[i] = a[j];
                    a[j] = temp;
                    break;
                }
            }
        }
    }
    
    for (int i = 0; i != n; i++) { // check array if divider is in the aray
        if (a[i] == divider) {
            for (int j = 0; j != n; j++) { // if it is, loop until element greater than divider found, then switch those
                if (a[j] > divider) {
                    temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                    break;
                }
            }
        }
    }
    
    int counter = 0;
    for (int i = 0; i < n; i++) { // loop to find position of first element not less than divider
        if (a[i] >= divider)
            break;
        else
            counter++;
    }
   
    return counter;
    
    }

