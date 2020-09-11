//
//  main.cpp
//  p1-stats
//
//  Created by Ian Fischer on 9/6/20.
//  Copyright © 2020 Ian Fischer. All rights reserved.
//

#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    cout << "enter a filename";
    string filename;
    cin >> filename;
    cout << endl << "enter a column name";
    string columnname;
    cin >> columnname;
    cout << endl << "reading column " << columnname << " from " << filename;
    vector<double> info = extract_column(filename, columnname);
    cout << endl << "Summary (value: frequency)" << endl;
    vector<vector<double>> info1 = summarize(info);
    for (int i = 0; i < info1.size(); i++) {
        cout << info1[i][0] << ": " << info1[i][1] << endl;
    }
    cout << endl;
    cout << "count = " << count(info) << endl;
    cout << "sum = " << sum(info) << endl;
    cout << "mean = " << mean(info) << endl;
    cout << "stdev = " << stdev(info) << endl;
    cout << "median = " << median(info) << endl;
    cout << "mode = " << mode(info) << endl;
    cout << "min = " << min(info) << endl;
    cout << "max = " << max(info) << endl;
    cout << "  0th percentile = " << min(info) << endl;
    cout << " 25th percentile = " << percentile(info, .25) << endl;
    cout << " 50th percentile = " << percentile(info, .5) << endl;
    cout << " 75th percentile = " << percentile(info, .75) << endl;
    cout << "100th percentile = " << percentile(info, 1) << endl;
}
