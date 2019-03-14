#include <jni.h>
#include <iostream>
#include "fr_mim_cl_server_services_JniDirectionService.h"
#include "CppToJavaConverter.h"
#include "../../core/src/core/API/interface.hpp"

/*
 * Class:     fr_mim_cl_server_services_JniDirectionService
 * Method:    getShortestPath
 * Signature: (JJ)Ljava/util/List;
 */
JNIEXPORT jobject JNICALL Java_fr_mim_cl_server_services_JniDirectionService_getNearestPoint(JNIEnv *env, jobject, jdouble lat, jdouble lon)
{
  /* Place place = Place(1, "Metz", lat, lon);
  return CppToJavaConverter::createPlace(place, env); */
}

/*
 * Class:     fr_mim_cl_server_services_JniDirectionService
 * Method:    getTravelingSalesMan
 * Signature: (Ljava/util/Set;)Ljava/util/List;
 */
JNIEXPORT jobject JNICALL Java_fr_mim_cl_server_services_JniDirectionService_getShortestPath(JNIEnv *env, jobject, jlong, jlong)
{
/*   Place place1 = Place(1, "test", 10, 20);
  Place place2 = Place(1, "test 2", 10, 30);
  Path path = Path(place1, place2);

  std::vector<Path> pathList;
  pathList.push_back(path);
  pathList.push_back(path);

  return CppToJavaConverter::createArrayListOfPath(pathList, env); */
}

/*
 * Class:     fr_mim_cl_server_services_JniDirectionService
 * Method:    getNearestPoint
 * Signature: (DD)Lfr/mim/cl/server/model/Place;
 */
JNIEXPORT jobject JNICALL Java_fr_mim_cl_server_services_JniDirectionService_getTravelingSalesMan(JNIEnv *env, jobject, jobject)
{
  /* Place place1 = Place(1, "Metz", 10, 20);
  Place place2 = Place(1, "Nancy", 10, 30);
  Path path = Path(place1, place2);

  std::vector<Path> pathList;
  pathList.push_back(path);
  pathList.push_back(path);

  return CppToJavaConverter::createArrayListOfPath(pathList, env); */
}

JNIEXPORT jobject JNICALL Java_fr_mim_cl_server_services_JniDirectionService_searchPlacesByName(JNIEnv *env, jobject, jstring)
{
  /* Place place1 = Place(1, "Metz", 10, 20);
  Place place2 = Place(1, "Nancy", 10, 30);

  std::vector<Place> placeList;
  placeList.push_back(place1);
  placeList.push_back(place2); */

  auto placeVector = searchPlace("Metz");

  return CppToJavaConverter::createArrayListOfPlace(placeVector, env);
}