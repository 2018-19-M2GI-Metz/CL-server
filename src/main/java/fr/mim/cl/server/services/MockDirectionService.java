package fr.mim.cl.server.services;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.context.annotation.Profile;
import org.springframework.stereotype.Component;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

import fr.mim.cl.server.model.Path;
import fr.mim.cl.server.model.Place;

@Component
@Profile("dev")
public class MockDirectionService implements DirectionService {
    private static final Logger logger = LoggerFactory.getLogger(MockDirectionService.class);
    private static Place METZ = new Place(1, "metz", 6.175982, 49.119457);
    private static Place NANCY = new Place(2, "nancy", 6.1834097, 48.6937223);
    private static Place PARIS = new Place(3, "paris", 2.348773, 48.856783);
    private static Place MARSEILLE = new Place(4, "marseille", 5.3699525, 43.2961743);
    private static Place[] CITIES = {METZ, NANCY, PARIS, MARSEILLE};

    @Override
    public List<Path> getShortestPath(long startId, long endId) {
        logger.info("Mocking getShortestPath");

        List<Path> res = new ArrayList<>();
        Place place1 = Arrays.stream(CITIES).filter((Place city) -> city.getId() == startId).findFirst().get();
        Place place2 = Arrays.stream(CITIES).filter((Place city) -> city.getId() == endId).findFirst().get();
        res.add(new Path(place1, place2));
        return res;
    }

    @Override
    public List<Path> getTravelingSalesMan(Set<Integer> places) {
        logger.info("Mocking getTsp");

        List<Path> res = new ArrayList<>();
        res.add(new Path(METZ, NANCY));
        res.add(new Path(NANCY, PARIS));
        res.add(new Path(PARIS, METZ));
        return res;
    }

    @Override
    public Place getNearestPoint(double lat, double lon) {
        logger.info("Mocking getNearestPoint");
        return METZ;
    }

    @Override
    public List<Place> searchPlacesByName(String name) {
        return Arrays.stream(CITIES).filter((Place city) -> city.getName().toLowerCase().contains(name.toLowerCase())).collect(Collectors.toList());
    }
}
