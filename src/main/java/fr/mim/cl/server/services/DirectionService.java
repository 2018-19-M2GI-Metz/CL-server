package fr.mim.cl.server.services;

import java.util.List;
import java.util.Set;

import fr.mim.cl.server.model.Path;
import fr.mim.cl.server.model.Place;

public interface DirectionService
{
  List<Path> getShortestPath(long startId, long endIdp);
  List<Path> getTravelingSalesMan(Set<Long> places);
  Place getNearestPoint(double lat, double lon);
  List<Place> searchPlacesByName(String name);
}
