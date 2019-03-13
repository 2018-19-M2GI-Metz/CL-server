#include "CppToJavaConverter.h"
#include <jni.h>

jobject CppToJavaConverter::createPlace(Place place, JNIEnv *env)
{
    jclass placeClass = env->FindClass("fr/mim/cl/server/model/Place");
    jmethodID placeConstructor = env->GetMethodID(placeClass, "<init>", "(JLjava/lang/String;DD)V");
    jobject placeObject = env->NewObject(placeClass, placeConstructor, (jint)place.id, env->NewStringUTF(place.name.c_str()), (jdouble)place.x, (jdouble)place.y);

    return placeObject;
}

jobject CppToJavaConverter::createPath(Path path, JNIEnv *env)
{
    jclass pathClass = env->FindClass("fr/mim/cl/server/model/Path");
    jmethodID pathConstructor = env->GetMethodID(pathClass, "<init>", "(Lfr/mim/cl/server/model/Place;Lfr/mim/cl/server/model/Place;)V");

    jobject startPlace = createPlace(path.start, env);
    jobject endPlace = createPlace(path.end, env);

    jobject pathObject = env->NewObject(pathClass, pathConstructor, startPlace, endPlace);

    return pathObject;
}

jobject CppToJavaConverter::createArrayListOfPlace(vector<Place> placeList, JNIEnv *env)
{
    jclass arrayListClass = env->FindClass("java/util/ArrayList");
    jmethodID arrayListConstructor = env->GetMethodID(arrayListClass, "<init>", "()V");
    jmethodID addToArrayList = env->GetMethodID(arrayListClass, "add", "(Ljava/lang/Object;)Z");

    jobject arrayList = env->NewObject(arrayListClass, arrayListConstructor);

    for (Place &place : placeList)
    {
        env->CallObjectMethod(arrayList, addToArrayList, createPlace(place, env));
    }

    return arrayList;
}

jobject CppToJavaConverter::createArrayListOfPath(vector<Path> pathList, JNIEnv *env)
{
    jclass arrayListClass = env->FindClass("java/util/ArrayList");
    jmethodID arrayListConstructor = env->GetMethodID(arrayListClass, "<init>", "()V");
    jmethodID addToArrayList = env->GetMethodID(arrayListClass, "add", "(Ljava/lang/Object;)Z");

    jobject arrayList = env->NewObject(arrayListClass, arrayListConstructor);

    for (Path &path : pathList)
    {
        env->CallObjectMethod(arrayList, addToArrayList, createPath(path, env));
    }

    return arrayList;
}
