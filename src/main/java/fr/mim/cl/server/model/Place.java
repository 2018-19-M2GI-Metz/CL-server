package fr.mim.cl.server.model;

public class Place
{
  private long id;
  private String name;
  private double posX;
  private double posY;

  public Place(long id, String name, double posX, double posY)
  {
    this.id = id;
    this.name = name;
    this.posX = posX;
    this.posY = posY;
  }

  public double getPosX()
  {
    return posX;
  }

  public void setPosX(double posX)
  {
    this.posX = posX;
  }

  public double getPosY()
  {
    return posY;
  }

  public void setPosY(double posY)
  {
    this.posY = posY;
  }

  public long getId()
  {
    return id;
  }

  public void setId(long id)
  {
    this.id = id;
  }

  public String getName()
  {
    return name;
  }

  public void setName(String name)
  {
    this.name = name;
  }

  @Override
  public String toString()
  {
    return "Place{" +
        "id=" + id +
        ", name='" + name + '\'' +
        ", posX=" + posX +
        ", posY=" + posY +
        '}';
  }
}
