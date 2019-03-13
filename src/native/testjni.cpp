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
      Place place = Place(1, "Metz", lat, lon);
      return CppToJavaConverter::createPlace(place, env);std::cout << "Getting native nearest point" << std::endl;
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

    /* jmethodID pathConstructor = env->GetMethodID(pathClass, "<init>", "()V");
    jmethodID addStartPlaceToPath = env->GetMethodID(pathClass, "setStartPlace", "(Lfr/mim/cl/server/model/Place;)V");
    jmethodID addEndPlaceToPath = env->GetMethodID(pathClass, "setEndPlace", "(Lfr/mim/cl/server/model/Place;)V");
    jmethodID pathConstructor2 = env->GetMethodID(pathClass, "<init>", "(Lfr/mim/cl/server/model/Place;Lfr/mim/cl/server/model/Place;)V"); */
    
    

    if (arrayList == NULL)
      std::cout << "arrayList cannot be created with constructor" << std::endl;
    else
      std::cout << "arrayList created with constructor" << std::endl;

    // Creating the Place objects.
    Place place1 = Place(1, "test", 10, 20);
    Place place2 = Place(1, "test 2", 10, 30);
  
    jobject placeObject1 = CppToJavaConverter::createPlace(place1, env);
    jobject placeObject2 = CppToJavaConverter::createPlace(place2, env);

    std::cout << "Created places" << std::endl;
  

    // Create the Path object.
    //jobject pathObject = env->NewObject(pathClass, pathConstructor, placeObject1, placeObject2);
    Path path = Path(place1, place2);
    std::cout << path.start.name << " & " << path.end.name << std::endl;
    jobject pathObject = CppToJavaConverter::createPath(path, env);

    if (pathObject == NULL)
      std::cout << "pathObject cannot be created with constructor" << std::endl;
    else
      std::cout << "pathObject created with constructor" << std::endl;
    
    env->CallObjectMethod(arrayList, addToArrayList, pathObject);
    env->CallObjectMethod(arrayList, addToArrayList, pathObject);
    env->CallObjectMethod(arrayList, addToArrayList, pathObject);

    std::cout << "Returning the arraylist" << std::endl;
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