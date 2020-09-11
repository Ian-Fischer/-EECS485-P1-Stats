//
//  stats.cpp
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

vector<vector<double> > summarize(vector<double> v) {
    sort(v);
    vector<double> info;
    vector<vector<double>> info2;
    int count = 1;
    for (int i = 0; i < v.size(); i++) {
        if (i + 1 == v.size()) {
            if (v[i] == v[i - 1]) {
                count = count + 1;
                info.push_back(v[i]);
                info.push_back(count);
                info2.push_back(info);
            }
            else {
                info.push_back(v[i]);
                info.push_back(count);
                info2.push_back(info);
                count = 1;
            }
        }
        else {
            if (v[i] == v[i + 1]) {
            count = count + 1;
            }
        else {
            info.push_back(v[i]);
            info.push_back(count);
            info2.push_back(info);
            count = 1;
            }
        }
        info.clear();
    }
    return info2;
}

int count(vector<double> v) {
    return v.size();;
}

double sum(vector<double> v) {
    double sumcount = 0;
    for (int i = 0; i < v.size(); i++) {
        sumcount = sumcount + v[i];
    }
    return sumcount;
  assert(false);
}

double mean(vector<double> v) {
    double sumcount = 0;
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        sumcount = sumcount + v[i];
        count = count + 1;
    }
    return sumcount / count;
  assert(false);
}

double median(vector<double> v) {
    sort(v);
    if (v.size() % 2 == 0) {
        double count = 0;
        count = v.size() / 2;
        int med1 = v[count];
        int med2 = v[count + 1];
        return med1 / med2;
    }
    else {
        double count = 0;
        count = v.size() / 2;
        count = ceil(count);
        return v[count];
    }
  assert(false);
}

double mode(vector<double> v) {
    sort(v);
    vector<double> info;
    vector<vector<double>> info2;
    int count = 1;
    for (int i = 0; i < v.size(); i++) {
        if (i + 1 == v.size()) {
            if (v[i] == v[i - 1]) {
                count = count + 1;
                info.push_back(v[i]);
                info.push_back(count);
                info2.push_back(info);
            }
            else {
                info.push_back(v[i]);
                info.push_back(count);
                info2.push_back(info);
                count = 1;
            }
        }
        else {
            if (v[i] == v[i + 1]) {
            count = count + 1;
            }
        else {
            info.push_back(v[i]);
            info.push_back(count);
            info2.push_back(info);
            count = 1;
            }
        }
        info.clear();
    }
    int a = 0;
    for (int i = 1; i < info2.size(); i++) {
        if (info2[a][1] < info2[i][1]) {
            a = i;
        }
    }
    return info2[a][0];
  assert(false);
}

double min(vector<double> v) {
    sort(v);
    int a = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[a] > v[i]) {
            a = i;
        }
    }
    return v[a];
  assert(false);
}

double max(vector<double> v) {
    sort(v);
    int a = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[a] < v[i]) {
            a = i;
        }
    }
    return v[a];
  assert(false);
}

double stdev(vector<double> v) {
    sort(v);
    double meanval = mean(v);
    double val = 0;
    double hold = 0;
    for (int i = 0; i < v.size(); i++) {
        val = 0;
        val = v[i] - meanval;
        val = pow(val, 2);
        hold = hold + val;
    }
    double intmin = v.size() - 1;
    hold = hold / intmin;
    hold = pow(hold, 0.5);
    return hold;
}

double percentile(vector<double> v, double p) {
    sort(v);
    double rank = 0;
    double size = v.size();
    double hold1 = 0;
    double hold2 = 0;
    hold1 = p;
    hold2 = size - 1;
    rank = hold1 * hold2 + 1;
    double k = 0;
    double d = 0;
    double percentileval = 0;
    d = modf(rank, &k);
    if (rank == v.size()) {
        return v[rank - 1];
    }
    else {
        double inner = 0;
        inner = v[k] - v[k - 1];
        percentileval = v[k - 1] + d * inner;
    }
    return percentileval;
}
