#include "Path.h"

Path::Path(Place start, Place end)
{
    this->start = start;
    this->end = end;
}

/* std::ostream & operator<<(std::ostream & Str, Path const & path) { 
    return Str << "Path[start=" << path.start << ", end=" << path.end << "]";
} */