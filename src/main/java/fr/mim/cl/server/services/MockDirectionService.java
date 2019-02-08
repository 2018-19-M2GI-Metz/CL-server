package fr.mim.cl.server.services;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.context.annotation.Profile;
import org.springframework.stereotype.Component;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Set;

import fr.mim.cl.server.model.Path;
import fr.mim.cl.server.model.Place;

@Component
@Profile("dev")
public class MockDirectionService implements DirectionService
{
  private static final Logger logger = LoggerFactory.getLogger(MockDirectionService.class);

  @Override
  public List<Path> getShortestPath(long startId, long endIdp)
  {
    logger.info("Mocking getShortestPath");
    Place metz = new Place(1, "Metz", 3.1, 3.4);
    Place nancy = new Place(2, "Nancy", 5.1, 9.4);
    Place paris = new Place(3, "Paris", 34, 1);

    List<Path> res = new ArrayList<>();
    res.add(new Path(metz, nancy));
    res.add(new Path(nancy, paris));
    return res;
  }

  @Override
  public List<Path> getTravelingSalesMan(Set<Place> places)
  {
    logger.info("Mocking getTsp");
    Place metz = new Place(1, "Metz", 3.1, 3.4);
    Place nancy = new Place(2, "Nancy", 5.1, 9.4);
    Place paris = new Place(3, "Paris", 34, 1);

    List<Path> res = new ArrayList<>();
    res.add(new Path(metz, nancy));
    res.add(new Path(nancy, paris));
    res.add(new Path(paris, metz));
    return res;
  }

  @Override
  public Place getNearestPoint(double lat, double lon)
  {
    logger.info("Mocking getNearestPoint");
    return new Place(1, "Metz", lat, lon);
  }

  @Override
  public List<Place> searchPlacesByName(String name)
  {
    List<Place> placeList = new ArrayList<>();
    placeList.add(new Place(1, "Metz", 3.1, 3.4));
    placeList.add(new Place(2, "Nancy", 9.4, 8.5));
    return placeList;
  }
}
