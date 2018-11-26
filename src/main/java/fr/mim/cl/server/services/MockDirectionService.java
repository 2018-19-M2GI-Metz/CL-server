package fr.mim.cl.server.services;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.context.annotation.Profile;
import org.springframework.stereotype.Component;

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
    return Collections.emptyList();
  }

  @Override
  public List<Path> getTravelingSalesMan(Set<Place> places)
  {
    logger.info("Mocking getTsp");
    return Collections.emptyList();
  }

  @Override
  public Place getNearestPoint(double lat, double lon)
  {
    logger.info("Mocking getNearestPoint");
    return new Place(lat, lon);
  }
}
