#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

 // Function I am reusing from one of my homeworks in CS3. again hehehehe
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

int main() {
    long int val;
    string inptype;
    string outtype;
    string resp;
    vector<string> respcheck;
    getline(cin, resp);
    respcheck = split(resp, ' ');
    if (respcheck.size() == 3) { // checks for correct size
        long double temp;
        val = stoi(respcheck.at(0));
        inptype = respcheck.at(1);
        outtype = respcheck.at(2);
        // first convert everything to bits (b) as it is the smallest possible
        if (inptype[inptype.size() - 1] == 'B') { // converts everything to b
            temp = 1;
            temp = temp * 8;
            string unit = "";
            for (int i = 0; i < inptype.size() - 1; i++) { // gets the units (if there is one)
                unit = unit + inptype[i];
            }
            if (unit == "K" || unit == "k") {
                // 1000
                temp = temp * 1000;
            } else if (unit == "M" || unit == "m") {
                // 1000^2
                temp = temp * pow(1000, 2);
            } else if (unit == "G" || unit == "g") {
                // 10^9
                temp = temp * pow(10, 9);
            } else if (unit == "Ki" || unit == "ki" || unit == "KI" || unit == "kI") {
                // 2^10
                temp = temp * pow(2, 10);
            } else if (unit == "Mi" || unit == "mi" || unit == "MI" || unit == "mI") {
                // 2^20
                temp = temp * pow(2, 20);
            } else if (unit == "Gi" || unit == "gi" || unit == "GI" || unit == "gI") {
                // 2^30
                temp = temp * pow(2, 30);
            } else {
                temp = temp * 1;
            }
        } else { // still converts everything to b, but only changes the units (if there are any)
            temp = 1;
            temp = temp * 1;
            string unit = "";
            for (int i = 0; i < inptype.size() - 1; i++) {
                unit = unit + inptype[i];
            }
            if (unit == "K" || unit == "k") {
                // 1000
                temp = temp * 1000;
            } else if (unit == "M" || unit == "m") {
                // 1000^2
                temp = temp * pow(1000, 2);
            } else if (unit == "G" || unit == "g") {
                // 10^9
                temp = temp * pow(10, 9);
            } else if (unit == "Ki" || unit == "ki" || unit == "KI" || unit == "kI") {
                // 2^10
                temp = temp * pow(2, 10);
            } else if (unit == "Mi" || unit == "mi" || unit == "MI" || unit == "mI") {
                // 2^20
                temp = temp * pow(2, 20);
            } else if (unit == "Gi" || unit == "gi" || unit == "GI" || unit == "gI") {
                // 2^30
                temp = temp * pow(2, 30);
            } else {
                temp = temp * 1;
            }
        }
        // if needed, convert back to Bytes (B) and deal with whatever unit was requested
        if (outtype[outtype.size() - 1] == 'B') {
            temp = temp / 8;
            string unit = "";
            for (int i = 0; i < outtype.size() - 1; i++) {
                unit = unit + outtype[i];
            }
            if (unit == "K" || unit == "k") {
                // 1000
                temp = temp / 1000;
            } else if (unit == "M" || unit == "m") {
                // 1000^2
                temp = temp / pow(1000, 2);
            } else if (unit == "G" || unit == "g") {
                // 10^9
                temp = temp / pow(10, 9);
            } else if (unit == "Ki" || unit == "ki" || unit == "KI" || unit == "kI") {
                // 2^10
                temp = temp / pow(2, 10);
            } else if (unit == "Mi" || unit == "mi" || unit == "MI" || unit == "mI") {
                // 2^20
                temp = temp / pow(2, 20);
            } else if (unit == "Gi" || unit == "gi" || unit == "GI" || unit == "gI") {
                // 2^30
                temp = temp / pow(2, 30);
            } else {
                temp = temp / 1;
            }
        } else {
            temp = temp / 1;
            string unit = "";
            for (int i = 0; i < outtype.size() - 1; i++) {
                unit = unit + outtype[i];
            }
            if (unit == "K" || unit == "k") {
                // 1000
                temp = temp / 1000;
            } else if (unit == "M" || unit == "m") {
                // 1000^2
                temp = temp / pow(1000, 2);
            } else if (unit == "G" || unit == "g") {
                // 10^9
                temp = temp / pow(10, 9);
            } else if (unit == "Ki" || unit == "ki" || unit == "KI" || unit == "kI") {
                // 2^10
                temp = temp / pow(2, 10);
            } else if (unit == "Mi" || unit == "mi" || unit == "MI" || unit == "mI") {
                // 2^20
                temp = temp / pow(2, 20);
            } else if (unit == "Gi" || unit == "gi" || unit == "GI" || unit == "gI") {
                // 2^30
                temp = temp / pow(2, 30);
            } else {
                temp = temp / 1;
            }
        }
        temp = temp * val; // the value from the beginning
        cout << temp << endl;
    } else {
        cout << "Error: Requires three inputs" << endl;
    }
    return 0;
}