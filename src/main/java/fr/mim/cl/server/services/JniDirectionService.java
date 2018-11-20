package fr.mim.cl.server.services;

import org.springframework.stereotype.Component;

import java.util.List;
import java.util.Set;

import fr.mim.cl.server.model.Path;
import fr.mim.cl.server.model.Place;
import sun.reflect.generics.reflectiveObjects.NotImplementedException;

@Component
public class JniDirectionService implements DirectionService
{
  @Override
  public List<Path> getShortestPath(Place startPlace, Place endPlace)
  {
    throw new NotImplementedException();
  }

  @Override
  public List<Path> getTravelingSalesMan(Set<Place> places)
  {
    throw new NotImplementedException();
  }
}
