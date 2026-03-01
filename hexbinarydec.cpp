#include <iostream>
using namespace std;
#include <string>
#include <cmath>
#include <vector>
// converts a decimal to binary
string dectobin(string d) {
    bool done = false; // tracks completion
    string b;
    int temp = stoi(d);
    int rem;
    while (!done) {
        rem = temp % 2;
        b = to_string(rem) + b;
        temp = temp / 2;
        if (temp == 1) {
            b = "1" + b;
            done = true;
        }
    }
    return b;
}
// converts a decimal to hex
string dectohex(string d) {
    bool done = false; // tracks completion
    string h;
    int temp = stoi(d);
    int rem;
    while (!done) {
        rem = temp % 16; // determining value
        if (rem == 10) {
            h = "A" + h;
        } else if (rem == 11) {
            h = "B" + h;
        } else if (rem == 12) {
            h = "C" + h;
        } else if (rem == 13) {
            h = "D" + h;
        } else if (rem == 14) {
            h = "E" + h;
        } else if (rem == 15) {
            h = "F" + h;   
        } else {
            h = to_string(rem) + h;
        }
        temp = temp / 16;  // putting respective letter in string
        if (temp < 16) {
            if (temp == 10) {
                h = "A" + h;
            } else if (temp == 11) {
                h = "B" + h;
            } else if (temp == 12) {
                h = "C" + h;
            } else if (temp == 13) {
                h = "D" + h;
            } else if (temp == 14) {
                h = "E" + h;
            } else if (temp == 15) {
                h = "F" + h;   
            } else {
                h = to_string(temp) + h;
            }
            done = true;
        }
    }
    return h;
}
// converts a binary to decimal
int bintodec(string b) {
    int d = 0;
    int j = 0;
    for (int i = b.length() - 1; i >= 0; i--) {  // goes through each bit
        int mult = 1;
        if (j == 0) {
            d = ((b[i] - '0') *  1) + d;
        } else {
            for (int c = 1; c <= j; c++) {
                mult = mult * 2;
            }
            d = ((b[i] - '0') * mult) + d;
        }
        j = j + 1;
    }
    return d;
}
// converts a binary to hex (uses bintodec() and dectohex())
string bintohex(string b) {
    string h;
    int temp = bintodec(b);
    h = dectohex(to_string(temp));
    return h;
}
// converts a hex to decimal
int hextodec(string h) {
    int d = 0;
    int j = 0;
    int temp = 0;
    for (int i = h.length() - 1; i >= 0; i--) { // goes through each character and gets value
        int mult = 1;
        if (h[i] == 'A') {
            temp = 10;
        } else if (h[i] == 'B') {
            temp = 11;
        } else if (h[i] == 'C') {
            temp = 12;
        } else if (h[i] == 'D') {
            temp = 13;
        } else if (h[i] == 'E') {
            temp = 14;
        } else if (h[i] == 'F') {
            temp = 15;
        } else {
            temp = (h[i] - '0');
        }
        if (j == 0) {
            d = (temp *  1) + d;
        } else {
            for (int c = 1; c <= j; c++) {
                mult = mult * 16;
            }
            d = (temp * mult) + d;
        }
        j = j + 1; // updates a pointer
    }
    return d;
}
// converts a hex to binary (uses hextodec() and dectobin())
string hextobin(string h) {
    string b;
    int temp = hextodec(h);
    b = dectobin(to_string(temp));
    return b;
}
// Function I am reusing from one of my homeworks in CS3.
vector<string> split(string str, char delim) {
    vector<string> respvec;
    string temp;
    for (int i = 0; i < str.length(); i++) {
        char curr = str[i];
        if (curr == delim) {
            respvec.push_back(temp);
            temp.clear();
        } else if (i == (str.length() - 1)) {
            temp = temp + curr;
            respvec.push_back(temp);
        } else {
            temp = temp + curr;
        }
    }
    return respvec;
}
// M A I N
int main() {
    vector<string> splitresp;
    string resp;
    string b;
    string h;
    string d;
    getline(cin, resp);
    splitresp = split(resp, ' ');
    if (splitresp.at(1) == "h") {
        h = splitresp.at(0);
        if (splitresp.at(2) == "b") {
            b = hextobin(h);
            cout << b << endl;
        } else if (splitresp.at(2) == "d") {
            int temp = hextodec(h);
            d = to_string(temp);
            cout << d << endl;
        } else {
            cout << h << endl; // failsafe
        }
    } else if (splitresp.at(1) == "d")  {
        d = splitresp.at(0);
        if (splitresp.at(2) == "h") {
            h = dectohex(d);
            cout << h << endl;
        } else if (splitresp.at(2) == "b") {
            b = dectobin(d);
            cout << b << endl;
        } else {
            cout << d << endl; // failsafe
        }
    } else if (splitresp.at(1) == "b") {
        b = splitresp.at(0);
        if (splitresp.at(2) == "h") {
            h = bintohex(b);
            cout << h << endl;
        } else if (splitresp.at(2) == "d") {
            int temp = bintodec(b);
            d = to_string(temp);
            cout << d << endl;
        } else {
            cout << b << endl; // failsafe
        }
    } else {
        cout << "womp womp" << endl;
    }
    return 0;
}