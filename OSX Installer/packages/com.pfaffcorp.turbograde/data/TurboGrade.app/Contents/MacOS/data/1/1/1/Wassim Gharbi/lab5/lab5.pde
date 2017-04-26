PImage[] paintings= new PImage[8];
PImage hand, arrow;
int[] paintingwidths= new int[8];
int totalwidth=0, yoffset=100, xoffset=-150, uniformHeight=400, currentpainting,currentpaintingx;
String cursor="arrow";
PFont mono;

Gallery myGallery;
void setup() {

  // SETTING UP 3D & LOADING FONT
  size(1000,700, P3D);
  smooth(8);
  mono = createFont("Arial",32, true);
  textFont(mono);
  
  // CURSOR IMAGES FOR OPENGL
  hand=loadImage("hand.png");
  arrow=loadImage("arrow.png");


  // CREATE GALLERY
  myGallery = new Gallery("The Lafayette Gallery");
  myGallery.addPainting("Paul Cézanne","The Card Players",1892,259000000, "cardplayers.jpg");
  myGallery.addPainting("Paul Cézanne","Nature morte au crâne",1898,232000000, "naturemorte.jpg");
  myGallery.addPainting("Jackson Pollock","No. 5, 1948",1948,145000000, "5.jpg");
  myGallery.addPainting("Jackson Pollock","Stenographic Figure",1942,130000000, "stenographic.jpg");
  myGallery.addPainting("Willem de Kooning","Woman III",1953,137500000, "woman.jpg");
  myGallery.addPainting("Pablo Picasso","Le Rêve",1932,155000000, "reve.jpg");
  myGallery.addPainting("Pablo Picasso","Guernica",1937,185000000, "guernica.jpg");
  myGallery.addPainting("Pablo Picasso","Les Demoiselles d'Avignon",1907,215000000, "demoiselles.jpg");
  
  
  // LOAD THE PAINTINGS AND RESIZE THEM TO FIT THE WINDOW
  for (int i=0; i<myGallery.numPaintings(); i++) {
    paintings[i]=loadImage(myGallery.getPainting(i).getImage());
    paintingwidths[i]=widthToRatio(paintings[i], uniformHeight);
  }
  
  
  // PART ONE OF THE LAB (SEE CONSOLE)
  println(myGallery);
  double avgPrice = myGallery.calculateAvgPrice();
  println("The average price for a painting in the gallery is "+avgPrice+" dollars.");
  println();
  Painting  result = myGallery.searchCheapestByYear(1900,1950);
  println("The cheapest painting available in this dealer between 1900 and 1950 is "+result);
  println();
  myGallery.changePrice("Jackson Pollock","No. 5, 1948",154000000);
  result = myGallery.mostExpensive();
  println("The most expensive painting sold is "+result);
  println();
  myGallery.paintingsByPainter("Pablo Picasso");
  println();
  // END OF PART ONE
}
// EXTRA :
void draw() {
  background(0);
  
  // DISPLAY GALLERY NAME AND INFO ABOUT IT
  fill(255);
  textSize(30);
  text(myGallery.getName(), 30, 50);
  textSize(15);
  text("•  " + (myGallery.numSold()==0?"No paintings sold yet":"Biggest sale $" + nfc((int)myGallery.mostExpensive().getPrice())) + "  •  Average price $" + nfc((int)myGallery.calculateAvgPrice()), 360, 45);
  textSize(20);
  translate(0, 0, 0);
  
  rotateY(radians(12)); // 3D EFFECT

  // DISPLAY THE PAINTINGS
  totalwidth=0;
  for (int i=0; i<paintings.length; i++) {

    int alpha=255;
    image(paintings[i], xoffset+totalwidth, yoffset, paintingwidths[i], uniformHeight);

    // IF THE PAINTING IS INSIDE THE WINDOW THEN IT'S THE CURRENT ONE
    if (xoffset+totalwidth>width/2-paintingwidths[i]/2 && xoffset+totalwidth<width/2) {
      currentpainting=i;
    }

    // DIM THE OTHER PAINTINGS TO PUT THE EMPHASIS ON THE CURRENT ONE
    if(i!=currentpainting) {
      noStroke();
      fill(0,0,0,100);
      rect(xoffset+totalwidth, yoffset, paintingwidths[i], uniformHeight);
      alpha=100;
    } else {
      currentpaintingx=xoffset+totalwidth;
      alpha=255;
    }

    // DISPLAY INFO ABOUT EACH PAINTING
    fill(255, 255, 255, alpha);
    text("\"" + myGallery.getPainting(i).getTitle() + "\" (" + myGallery.getPainting(i).getYear() + ")", xoffset+totalwidth+paintingwidths[i]/2-textWidth("\"" + myGallery.getPainting(i).getTitle() + "\" (" + myGallery.getPainting(i).getYear() + ")")/2, yoffset+uniformHeight+30);
    text(myGallery.getPainting(i).getPainter(), xoffset+totalwidth+paintingwidths[i]/2-textWidth(myGallery.getPainting(i).getPainter())/2, yoffset+uniformHeight+60);
    text("$" + nfc((int)myGallery.getPainting(i).getPrice()), xoffset+totalwidth+paintingwidths[i]/2-textWidth("$" + nfc((int)myGallery.getPainting(i).getPrice()))/2, yoffset+uniformHeight+90);

    // DISPLAY SOLD OR BUY BUTTON :
    if(myGallery.getPainting(i).isSold()) {
      fill(127, 140, 141,alpha);
      rect(xoffset+totalwidth+paintingwidths[i]/2-50, yoffset+uniformHeight+110, 100, 30, 10, 10 ,10 ,10);
      fill(255, 255, 255,alpha);
      text("SOLD", xoffset+totalwidth+paintingwidths[i]/2-textWidth("SOLD")/2, yoffset+uniformHeight+132);
    } else {
      fill(46, 204, 113,alpha);
      rect(xoffset+totalwidth+paintingwidths[i]/2-50, yoffset+uniformHeight+110, 100, 30, 10, 10 ,10 ,10);
      fill(255, 255, 255,alpha);
      text("BUY", xoffset+totalwidth+paintingwidths[i]/2-textWidth("BUY")/2, yoffset+uniformHeight+132);
    }
    
    totalwidth+=paintingwidths[i]+20;
  }
  
   // IF THE MOUSE IS OVER THE CURRENT PAINTING THEN MAKE THE CURSOR A HAND
  if(mouseX > currentpaintingx && mouseX<currentpaintingx+paintingwidths[currentpainting] && mouseY>yoffset && mouseY<yoffset+uniformHeight+150 && mouseX < 4*width/5 && mouseX > width/5) {
      cursor="hand"; 
      if(mousePressed) {
          // WHEN THE CURRENT PAINTING IS CLICKED, SET IT TO SOLD
          myGallery.setSold(myGallery.getPainting(currentpainting).getPainter(),myGallery.getPainting(currentpainting).getTitle());
      }
  } else if(mousePressed && mouseX > 4*width/5 && xoffset>-totalwidth+paintingwidths[paintings.length-1]+200) {
    // MOVE PAINTINGS TO THE RIGHT
    xoffset=xoffset-((mouseX-width/2)/30);
  } else if (mousePressed && mouseX < width/5 && xoffset<300) {
    // MOVE PAINTINGS TO THE LEFT
    xoffset=xoffset+((width/2-mouseX)/30);
  } else {
    cursor="arrow";
  }
  if(cursor=="hand") {
      cursor(hand);
      cursor(HAND);
  } else {
      cursor(arrow);
      cursor(ARROW);
  }
}

// RETURNS THE NEW WIDTH FOR THE RESIZED PAINTING TO FIT THE WINDOW
int widthToRatio(PImage image, int newHeight) {
  return newHeight*image.width/image.height;
}
