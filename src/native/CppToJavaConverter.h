#pragma once

#include <jni.h>
#include <iostream>
#include <vector>
#include "core/Path.h"
#include "core/Place.h"

using namespace std;

class CppToJavaConverter {
    public:
        static jobject createArrayListOfPath(vector<Path> pathList, JNIEnv * env);
        static jobject createArrayListOfPlace(vector<Place> placeList, JNIEnv * env);
        static jobject createPlace(Place* place, JNIEnv * env);
        static jobject createPath(Path* path, JNIEnv * env);
};