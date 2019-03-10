#include "CppToJavaConverter.h"
#include <jni.h>

jobject CppToJavaConverter::createPlace(Place* place, JNIEnv * env)
{
    std::cout << "Entering create place" << std::endl;
    jclass placeClass = env->FindClass("fr/mim/cl/server/model/Place");
    std::cout << "Retrieving place class" << std::endl;
    jmethodID placeConstructor = env->GetMethodID(placeClass, "<init>", "(JLjava/lang/String;DD)V");
    std::cout << "Retrieving method" << std::endl;
    jobject placeObject1 = env->NewObject(placeClass, placeConstructor, (jint) 1, (jstring) "Metz", (jdouble) 12, (jdouble) 34);
    std::cout << "Creating object" << std::endl;
    return placeObject1;
}