#include "CppToJavaConverter.h"
#include <jni.h>

jobject CppToJavaConverter::createPlace(Place* place, JNIEnv * env)
{
    jclass placeClass = env->FindClass("fr/mim/cl/server/model/Place");
    jmethodID placeConstructor = env->GetMethodID(placeClass, "<init>", "(DD)V");
    jobject placeObject2 = env->NewObject(placeClass, placeConstructor, 19, 24);
}