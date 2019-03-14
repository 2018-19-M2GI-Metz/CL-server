#include "CppToJavaConverter.h"
#include <jni.h>

jobject CppToJavaConverter::createPlace(shared_ptr<Point> place, JNIEnv *env)
{
    jclass placeClass = env->FindClass("fr/mim/cl/server/model/Place");
    jmethodID placeConstructor = env->GetMethodID(placeClass, "<init>", "(JLjava/lang/String;DD)V");
    jobject placeObject = env->NewObject(placeClass, placeConstructor, (jint)place->getId(), env->NewStringUTF(place->getName().c_str()), (jdouble)place->getLatitude(), (jdouble)place->getLongitude());

    return placeObject;
}

jobject CppToJavaConverter::createPath(shared_ptr<Segment> path, JNIEnv *env)
{
    jclass pathClass = env->FindClass("fr/mim/cl/server/model/Path");
    jmethodID pathConstructor = env->GetMethodID(pathClass, "<init>", "(Lfr/mim/cl/server/model/Place;Lfr/mim/cl/server/model/Place;)V");

    jobject startPlace = createPlace(path->getStartPoint(), env);
    jobject endPlace = createPlace(path->getEndPoint(), env);

    jobject pathObject = env->NewObject(pathClass, pathConstructor, startPlace, endPlace);

    return pathObject;
}

jobject CppToJavaConverter::createArrayListOfPlace(vector<shared_ptr<Point>> placeList, JNIEnv *env)
{
    jclass arrayListClass = env->FindClass("java/util/ArrayList");
    jmethodID arrayListConstructor = env->GetMethodID(arrayListClass, "<init>", "()V");
    jmethodID addToArrayList = env->GetMethodID(arrayListClass, "add", "(Ljava/lang/Object;)Z");

    jobject arrayList = env->NewObject(arrayListClass, arrayListConstructor);

    for (auto &place : placeList)
    {
        env->CallObjectMethod(arrayList, addToArrayList, createPlace(place, env));
    }

    return arrayList;
}

jobject CppToJavaConverter::createArrayListOfPath(vector<shared_ptr<Segment>> pathList, JNIEnv *env)
{
    jclass arrayListClass = env->FindClass("java/util/ArrayList");
    jmethodID arrayListConstructor = env->GetMethodID(arrayListClass, "<init>", "()V");
    jmethodID addToArrayList = env->GetMethodID(arrayListClass, "add", "(Ljava/lang/Object;)Z");

    jobject arrayList = env->NewObject(arrayListClass, arrayListConstructor);

    for (auto path : pathList)
    {
        env->CallObjectMethod(arrayList, addToArrayList, createPath(path, env));
    }

    return arrayList;
}
