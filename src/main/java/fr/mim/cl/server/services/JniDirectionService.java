package fr.mim.cl.server.services;

import org.springframework.stereotype.Component;

import java.util.List;
import java.util.Set;

import fr.mim.cl.server.model.Path;
import fr.mim.cl.server.model.Place;


@Component
public class JniDirectionService implements DirectionService
{
  @Override
  public native List<Path> getShortestPath(Place startPlace, Place endPlace);

  @Override
  public native List<Path> getTravelingSalesMan(Set<Place> places);
}
