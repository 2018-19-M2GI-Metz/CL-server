#pragma once

#include <jni.h>
#include <iostream>
#include <vector>
#include <memory>

/* #include "core/Path.h"
#include "core/Place.h" */
#include "../../core/src/core/Models/Point.hpp"
#include "../../core/src/core/Models/Path.hpp"


using namespace std;

class CppToJavaConverter {
    public:
        static jobject createArrayListOfPath(vector<shared_ptr<Path>> pathList, JNIEnv * env);
        static jobject createArrayListOfPlace(vector<shared_ptr<Point>> placeList, JNIEnv * env);
        static jobject createPlace(shared_ptr<Point> place, JNIEnv * env);
        static jobject createPath(shared_ptr<Path> path, JNIEnv * env);
};