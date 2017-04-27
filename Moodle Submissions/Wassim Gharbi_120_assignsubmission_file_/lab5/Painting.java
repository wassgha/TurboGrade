public class Painting {
  private String painter, title, file;
  private int year;
  private double price;
  private boolean sold;
  
  public Painting(String painter, String title, int year, double price, String file) {
    this.painter = painter;
    this.title = title;
    this.year = year;
    this.price = price;
    this.file = file;
    this.sold = false;
  }
  public String toString() {
    return "\"" + this.title + "\" (" + year + ") by " + this.painter + ", " + (this.sold?"sold at ":"priced at ") + this.price;
  }
  public void setPrice(double price) {
    this.price = price;
  }
  public void setSold(boolean sold) {
    this.sold = sold;
  }
  public String getPainter() {
    return this.painter;
  }
  public String getTitle() {
    return this.title;
  }
  public int getYear() {
    return this.year;
  }
  public double getPrice() {
    return this.price;
  }
  public String getImage() {
    return this.file;
  }
  public boolean isSold() {
    return this.sold;
  }
}