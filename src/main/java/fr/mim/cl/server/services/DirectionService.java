package fr.mim.cl.server.services;

import java.util.List;
import java.util.Set;

import fr.mim.cl.server.model.Path;
import fr.mim.cl.server.model.Place;

interface DirectionService
{
  List<Path> getShortestPath(Place startPlace, Place endPlace);
  List<Path> getTravelingSalesMan(Set<Place> places);
}
