package fr.mim.cl.server.services;

import org.springframework.stereotype.Component;

import java.util.Collections;
import java.util.List;
import java.util.Set;

import fr.mim.cl.server.model.Path;
import fr.mim.cl.server.model.Place;


@Component
public class JniDirectionService implements DirectionService
{
  @Override
  public List<Path> getShortestPath(Place startPlace, Place endPlace)
  {
    return Collections.emptyList();
  }

  @Override
  public List<Path> getTravelingSalesMan(Set<Place> places)
  {
    return Collections.emptyList();
  }
}
