package fr.mim.cl.server.controllers;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Collections;
import java.util.List;
import java.util.Set;

import fr.mim.cl.server.model.Path;
import fr.mim.cl.server.model.Place;
import fr.mim.cl.server.services.DirectionService;

@RestController
@RequestMapping("/api")
public class DirectionController
{
  private DirectionService directionService;

  public DirectionController(DirectionService directionService)
  {
    this.directionService = directionService;
  }

  @GetMapping("/shortestPath")
  public List<Path> getShortestPath(double startPosX, double startPosY,
                                    double endPosX, double endPosY)
  {
    return directionService.getShortestPath(new Place(startPosX, startPosY),
        new Place(endPosX, endPosY));
  }

  @GetMapping("/tsp")
  public List<Path> getTravelingSalesMan(Set<Place> places)
  {
    return directionService.getTravelingSalesMan(Collections.emptySet());
  }
}
