public class Gallery {
  private Painting[] paintings = new Painting[1000];
  private int numPaintings=0;
  private String galleryName;
  
  
  Gallery(String name) {
    if(name.equals("")) 
      throwError("The gallery name can't be empty!");
    else
      this.galleryName=name;
  }
  
  
  public void addPainting(String painter, String title, int year, double price, String file) {
    if(price<0) 
      throwError("Failed to add Painting, price can't be negative.");
    else if (year<0)
      throwError("Failed to add Painting, year can't be negative.");
    else if (title.equals(""))
      throwError("Failed to add Painting, name can't be empty.");
    else if (painter.equals(""))
      throwError("Failed to add Painting, painter can't be empty.");
    else {
      boolean unique=true;
      for ( int i=0 ; i<numPaintings; i++) {
         if(paintings[i].getTitle().equals(title) && paintings[i].getPainter().equals(painter))
           unique = false;
      }
      if(!unique)
        throwError("Failed to add Painting, there is an other painting with same title and painter.");
      else {
        paintings[this.numPaintings]=new Painting(painter, title, year, price, file);
        this.numPaintings++;
      }
    }
  }
  
  
  public void setSold(String painter, String title) {
    for ( int i=0 ; i<numPaintings; i++) {
      if(paintings[i].getTitle().equals(title) && paintings[i].getPainter().equals(painter)) {
        paintings[i].setSold(true);
      }
    }
  }
  
  
  public void changePrice(String painter, String title, double newPrice) {
    for ( int i=0 ; i<numPaintings; i++) {
      if(paintings[i].getTitle().equals(title) && paintings[i].getPainter().equals(painter)) {
        paintings[i].setPrice(newPrice);
      }
    }
  }
  
  
  public int numUnsold() {
    int numUnsold=0;
    for ( int i=0 ; i<numPaintings; i++) {
      if(!paintings[i].isSold()) {
        numUnsold++;
      }
    }
    return numUnsold;
  }

   public int numPaintings() {
    return this.numPaintings;
  }
  

  public int numSold() {
    int numSold=0;
    for ( int i=0 ; i<numPaintings; i++) {
      if(paintings[i].isSold()) {
        numSold++;
      }
    }
    return numSold;
  }
  
  
  public double calculateAvgPrice() {
    if(this.numUnsold()==0) {
      throwError("Failed to calculate average : This gallery doesn't have any unsold paintings.");
      return -1;
    } else {
      int avg=0;
      for ( int i=0 ; i<numPaintings; i++) {
        if(!paintings[i].isSold()) {
          avg+=paintings[i].getPrice();
        }
      }
      return avg/this.numUnsold();
    }
  }
  
  
  public Painting searchCheapestByYear(int startYear, int endYear) {
    int cheapest=-1;
    int numBetweenYears=0;
    for ( int i=0 ; i<numPaintings; i++) {
      if(paintings[i].getYear()>=startYear && paintings[i].getYear()<=endYear && (cheapest==-1 || paintings[i].getPrice()< paintings[cheapest].getPrice())) {
        cheapest=i;
        numBetweenYears++;
      }
    }
    if ( numBetweenYears ==0) {
      throwError("There are no paintings in this year range");
      return paintings[0];
    } else
      return paintings[cheapest];
  }
  

  public Painting mostExpensive() {
    int mostExpensive=-1;
    for ( int i=0 ; i<numPaintings; i++) {
      if(paintings[i].isSold() && (mostExpensive==-1 || paintings[i].getPrice() > paintings[mostExpensive].getPrice())) {
        mostExpensive=i;
      }
    }

    if (this.numSold()==0) {
      throwError("No paintings were sold yet.");
      return paintings[0];
    } else 
      return paintings[mostExpensive];
  }


  public void paintingsByPainter(String painter) {
    System.out.println("Paintings by \"" + painter + "\" : ");
    for ( int i=0 ; i<numPaintings; i++) {
      if(paintings[i].getPainter().equals(painter)) {
        System.out.println(" * " + paintings[i]);
      }
    }

  }
  
  public Painting getPainting(int painting) {
   return paintings[painting];
  }
  
  public String getName() {
   return this.galleryName;
  }

  
  public String toString() {
       System.out.println("***********************************");
       System.out.println("*      " + this.galleryName + "      *");
       System.out.println("***********************************");
       for ( int i=0 ; i<numPaintings; i++) {
         System.out.println(" * " + this.paintings[i]);
       }
      return " ";
  }
  
  public void throwError(String error) {
    System.out.println("ERROR : " + error);
  }
}