package fr.mim.cl.server.services;

import org.springframework.context.annotation.Profile;
import org.springframework.stereotype.Component;

import java.util.List;
import java.util.Set;

import fr.mim.cl.server.model.Path;
import fr.mim.cl.server.model.Place;


@Component
@Profile("prod")
public class JniDirectionService implements DirectionService
{
  static {
    System.loadLibrary("map");
  }

  @Override
  public native List<Path> getShortestPath(long startId, long endId);

  @Override
  public native List<Path> getTravelingSalesMan(Set<Place> places);

  @Override
  public native Place getNearestPoint(double lat, double lon);
}
