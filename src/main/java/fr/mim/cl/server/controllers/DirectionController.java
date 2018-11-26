package fr.mim.cl.server.controllers;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Collections;
import java.util.List;

import fr.mim.cl.server.model.Path;
import fr.mim.cl.server.model.Place;
import fr.mim.cl.server.services.DirectionService;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiResponse;
import io.swagger.annotations.ApiResponses;

@RestController
@RequestMapping("/api")
public class DirectionController
{
  private DirectionService directionService;
  private static final Logger logger = LoggerFactory.getLogger(DirectionController.class);

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
  @ApiOperation(value = "Do the tsp", nickname = "TSP", tags={ "Beers" })
  @ApiResponses(value = {
      @ApiResponse(code = 200, message = "Success") })
  public List<Path> getTravelingSalesMan(List<Place> places)
  {
    logger.info("{}", places);
    return directionService.getTravelingSalesMan(Collections.emptySet());
  }
}
