#pragma once

#include <string>

using namespace std;

class Place {
    public:
        long id;
        string name;
        double x;
        double y;
        Place(int id, string name, double x, double y);
};