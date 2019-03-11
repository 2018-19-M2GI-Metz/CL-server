package fr.mim.cl.server.controllers;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.web.bind.annotation.*;

import java.util.Collections;
import java.util.List;

import fr.mim.cl.server.model.Path;
import fr.mim.cl.server.model.Place;
import fr.mim.cl.server.services.DirectionService;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiResponse;
import io.swagger.annotations.ApiResponses;

@RestController
@CrossOrigin
@RequestMapping("/api")
public class DirectionController
{
  private DirectionService directionService;
  private static final Logger logger = LoggerFactory.getLogger(DirectionController.class);

  public DirectionController(DirectionService directionService)
  {
    this.directionService = directionService;
  }

  @GetMapping("/path")
  @ApiOperation(value = "Gets the shortest path between two points", nickname = "ShortestPath",
      tags={ "MapAPI" })
  @ApiResponses(value = {
      @ApiResponse(code = 200, message = "Success") })
  public List<Path> getShortestPath(long startId, long endId)
  {
    logger.info("Getting shortest path with startId = {} and endId = {}", startId, endId);
    return directionService.getShortestPath(startId,endId);
  }

  @GetMapping("/tsp")
  @ApiOperation(value = "Do the tsp", nickname = "TSP", tags={ "MapAPI" })
  @ApiResponses(value = {
      @ApiResponse(code = 200, message = "Success") })
  public List<Path> getTravelingSalesMan(@RequestParam("id")  List<Integer> idPlaces)
  {
    logger.info("Ids = {}", idPlaces);
    return directionService.getTravelingSalesMan(Collections.emptySet());
  }

  @GetMapping("/nearestpoint")
  @ApiOperation(value = "Gets the nearest point", nickname = "Nearest Point", tags={ "MapAPI" })
  @ApiResponses(value = {
      @ApiResponse(code = 200, message = "Success") })
  public Place getNearestPoint(double lat, double lon)
  {
    logger.info("Getting nearest point for lat = {} and long = {}", lat, lon);
    return directionService.getNearestPoint(lat, lon);
  }

  @GetMapping("/searchbyname")
  @ApiOperation(value = "Search places by a name or a part of the name", nickname = "Search by name", tags={ "MapAPI" })
  @ApiResponses(value = {
      @ApiResponse(code = 200, message = "Success") })
  public List<Place> searchPlacesByName(String name)
  {
    logger.info("Searching places with name {}", name);
    return directionService.searchPlacesByName(name);
  }
}
