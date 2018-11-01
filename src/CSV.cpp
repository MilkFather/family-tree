#include "CSV.hpp"
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::endl;

// CSV类的实现

CSVRow CSV::parseLine(string l) {
    CSVRow v;
    string tmp;
    for (int i = 0; i < l.length(); i++) {
        if (l[i] == ',') {
            v.push_back(tmp);
            tmp = "";
        } else {
            tmp += l[i];
        }
    }
    if (tmp != "") {
        v.push_back(tmp);
    }
    
    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i].substr(1, v[i].length() - 2);
    }
    return v;
}

string CSV::makeLine(CSVRow r) {
    if (r.size() <= 0) {
        return "";
    } else {
        string s = "\"" + r[0] + "\"";
        for (int i = 1; i < r.size(); i++) {
            s = s + "," + "\"" + r[i] + "\"";
        }
        return s;
    }
}

vector<CSVRow> CSV::openFile(string filename) {
    vector<CSVRow> table;
    ifstream f(filename);
    if (!f.is_open()) {
        return table;
    } else {
        string l;
        while (getline(f, l)) {
            CSVRow r = parseLine(l);
            table.push_back(r);
        }
        f.close();
        return table;
    }
}

void CSV::writeFile(vector<CSVRow> table, string filename) {
    ofstream f(filename);
    if (!f.is_open()) {
        for (int i = 0; i < table.size(); i++) {
            f << makeLine(table[i]) << endl;
        }
        f.close();
    }
}
