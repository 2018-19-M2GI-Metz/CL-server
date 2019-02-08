#if !defined(PLACE)
#define PLACE

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

Place::Place(int id, string name, double x, double y) {
    this->id = id;
    this->name = name;
    this->x = x;
    this->y = y;
}

#endif // PLACE