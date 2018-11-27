package fr.mim.cl.server.model;

public class Path
{
  private Place startPlace;
  private Place endPlace;

  public Path(Place startPlace, Place endPlace)
  {
    this.startPlace = startPlace;
    this.endPlace = endPlace;
  }

  public Path()
  {
  }

  public Place getStartPlace()
  {
    return startPlace;
  }

  public void setStartPlace(Place startPlace)
  {
    this.startPlace = startPlace;
  }

  public Place getEndPlace()
  {
    return endPlace;
  }

  public void setEndPlace(Place endPlace)
  {
    this.endPlace = endPlace;
  }

  @Override
  public String toString()
  {
    return "Path{" +
        "startPlace=" + startPlace +
        ", endPlace=" + endPlace +
        '}';
  }
}
