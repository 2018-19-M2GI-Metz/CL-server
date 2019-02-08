#include <jni.h>
#include <iostream>
#include "fr_mim_cl_server_services_JniDirectionService.h"
#include "CppToJavaConverter.h"


/*
 * Class:     fr_mim_cl_server_services_JniDirectionService
 * Method:    getShortestPath
 * Signature: (JJ)Ljava/util/List;
 */
JNIEXPORT jobject JNICALL Java_fr_mim_cl_server_services_JniDirectionService_getNearestPoint
  (JNIEnv * env, jobject, jdouble lat, jdouble lon)
  {
      std::cout << "Getting native nearest point" << std::endl;
      jclass jcls = env->FindClass("fr/mim/cl/server/model/Place");
      /*jobject jobj = env->AllocObject(jcls);
      if (jobj == NULL)
        std::cout << "Object cannot be created" << std::endl;
      else
        std::cout << "Object created" << std::endl;
      return jobj; */
      jmethodID mID1 = env->GetMethodID(jcls,"<init>", "(DD)V");
      jobject jobj2 = env->NewObject(jcls, mID1, lat, lon);
      if (jobj2 == NULL)
         std::cout << "Object cannot be created with constructor" << std::endl;
      else
         std::cout << "Object created with constructor" << std::endl;
      return jobj2;

  }

/*
 * Class:     fr_mim_cl_server_services_JniDirectionService
 * Method:    getTravelingSalesMan
 * Signature: (Ljava/util/Set;)Ljava/util/List;
 */
JNIEXPORT jobject JNICALL Java_fr_mim_cl_server_services_JniDirectionService_getShortestPath
  (JNIEnv * env, jobject, jlong, jlong)
  {
    std::cout << "Native call to getShortestPath" << std::endl;
    
    jclass arrayListClass = env->FindClass("java/util/ArrayList");
    //jclass placeClass = env->FindClass("fr/mim/cl/server/model/Place");
    jclass pathClass = env->FindClass("fr/mim/cl/server/model/Path");


    jmethodID arrayListConstructor = env->GetMethodID(arrayListClass,"<init>", "()V");
    //jmethodID placeConstructor = env->GetMethodID(placeClass, "<init>", "(DD)V");
    jmethodID pathConstructor = env->GetMethodID(pathClass, "<init>", "()V");
    jmethodID addStartPlaceToPath = env->GetMethodID(pathClass, "setStartPlace", "(Lfr/mim/cl/server/model/Place;)V");
    jmethodID addEndPlaceToPath = env->GetMethodID(pathClass, "setEndPlace", "(Lfr/mim/cl/server/model/Place;)V");
    jmethodID pathConstructor2 = env->GetMethodID(pathClass, "<init>", "(Lfr/mim/cl/server/model/Place;Lfr/mim/cl/server/model/Place;)V");
    jmethodID addToArrayList = env->GetMethodID(arrayListClass, "add", "(Ljava/lang/Object;)Z");
    
    // Create ArrayList
    jobject arrayList = env->NewObject(arrayListClass, arrayListConstructor);

    if (arrayList == NULL)
      std::cout << "arrayList cannot be created with constructor" << std::endl;
    else
      std::cout << "arrayList created with constructor" << std::endl;

    // Creating the Place objects.
    //jobject placeObject1 = env->NewObject(placeClass, placeConstructor, (jdouble) 12, (jdouble) 34);
    //jobject placeObject2 = env->NewObject(placeClass, placeConstructor, 19, 24);
    jobject placeObject1 = CppToJavaConverter::createPlace(new Place(1, "test", 10, 20), env);
    jobject placeObject2 = CppToJavaConverter::createPlace(new Place(1, "test", 10, 30), env);

    // Create the Path object.
    jobject pathObject = env->NewObject(pathClass, pathConstructor, placeObject1, placeObject2);

    if (pathObject == NULL)
      std::cout << "pathObject cannot be created with constructor" << std::endl;
    else
      std::cout << "pathObject created with constructor" << std::endl;
    
    env->CallVoidMethod(pathObject, addStartPlaceToPath, placeObject1);
    env->CallVoidMethod(pathObject, addEndPlaceToPath, placeObject2);
    env->CallObjectMethod(arrayList, addToArrayList, pathObject);
    env->CallObjectMethod(arrayList, addToArrayList, pathObject);
    env->CallObjectMethod(arrayList, addToArrayList, pathObject);

    return arrayList;
  }

/*
 * Class:     fr_mim_cl_server_services_JniDirectionService
 * Method:    getNearestPoint
 * Signature: (DD)Lfr/mim/cl/server/model/Place;
 */
JNIEXPORT jobject JNICALL Java_fr_mim_cl_server_services_JniDirectionService_getTravelingSalesMan
  (JNIEnv *, jobject, jobject)
  {
    std::cout << "Native call to getTravelingSalesman" << std::endl;
    return NULL;
  }