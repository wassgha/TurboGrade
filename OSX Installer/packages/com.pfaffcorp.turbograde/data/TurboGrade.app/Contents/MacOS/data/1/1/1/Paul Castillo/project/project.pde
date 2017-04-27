/*

               Wassim Gharbi
     Photo Editing Software Project
    _________________________________
    
    Started by making the first three functions
    as filters that apply to the whole image
    then made the functions that change the image
    using a simple square brush, after that I 
    switched to a more natural circle brush (two
    for loops and an if statement + trig)
    
    Explanation for the circle brush : http://i.imgur.com/bbjaIEE.jpg

*/

int brush=0, size=15, intensity=4;
int omouseX, omouseY, canvasx, canvasy, canvaswidth, canvasheight, mouseXinside, mouseYinside, brushesx=50;
int sizeSliderX=(int)map(size, 10, 30, 0, 200), intensitySliderX=(int)map(intensity, 1, 30, 0, 200);
PImage img, source, checkbox;
PImage[] brushes = new PImage[4];
boolean cursorhand=false, draggingSizeSlider=false, draggingIntensitySlider=false, circle=true, filter=false;
void setup(){
  
  size(800,740);
  rectMode(CORNER);  
  ellipseMode(CENTER);
  textSize(16); 
  frameRate(60); // Had to do this to stop the program from draining my laptop battery
  
  // Keep a copy intact in case of reset/erase
  source=loadImage("obama.jpg");

  img=loadImage("obama.jpg");

  // Elements for the GUI
  
  brushes[0] = loadImage("blurbrush.png");
  brushes[1] = loadImage("tintbrush.png");
  brushes[2] = loadImage("posterizebrush.png");
  brushes[3] = loadImage("erasebrush.png");
  checkbox=loadImage("checkbox.png");

  
  // Location and size of the canvas
  
  canvasx=20;
  canvasy=20;
  canvaswidth=width-40;
  canvasheight=(int)(((float)img.height/img.width)*width);

}

void draw() {
  
    background(#ecf0f1);
    
    
    
    // Size Slider
    stroke(136);
    fill(238);
    rect(width-250, height-100, 200, 10, 4, 4, 4, 4);
    fill(#2c3e50);
    text("Brush size : ", width-265-textWidth("Brush size :"), height-90);
    text( size, width-40, height-90);
    noStroke();
    ellipse(width-250 + sizeSliderX, height-95, 20,20);
    if (draggingIntensitySlider || (mousePressed && mouseX>(width-250 + sizeSliderX-10) && mouseX<(width-250 + sizeSliderX+10) && mouseY>height-95-20 && mouseY<height-95+20)) {
        sizeSliderX=constrain(sizeSliderX+(mouseX-pmouseX), 0, 200); // Add the difference between the mousex in the previous frame and the new one, while keeping sliderx between 0 and 200
        draggingIntensitySlider=true;
    }
    size = (int)map(sizeSliderX, 0, 200, 10, 30); // Change slider position to a value between 10 and 30
    
    
    
    
    // Display current brush size and intensity
    text("Current Brush : ", width-280-60, height-200 -40);   
    stroke(0);
    fill(255);
    rect(width-280-40, height-200 -20, 80, 80);
    stroke(#2c3e50);
    fill(color(44, 62, 80,255*(float)intensity/30));
    if(circle)
    ellipse(width-280, height-180, 2*size, 2*size);
    else
    rect(width-280-size, height-180-size, 2*size, 2*size);
    
    
    
    // Checkboxes for Filter/Brush and Circle/Square Brush
    
    fill(50);
    textSize(12);
    text("Apply on whole image", width-100-60, height-150 -40);
    
    if(filter)
      image( checkbox.get(0,0,30,30), width-100-95, height-150 -58);
    else
      image( checkbox.get(27,0,30,30), width-100-95, height-150 -58);
      
    if (mousePressed && mouseX>width-100-95 && mouseX<width-100-95+30 && mouseY>height-150 -58 && mouseY<height-150 -58+30) { // If the user clicks to change filter/brush
      filter=!filter; // changes to opposite
      delay(100);
    }


    text("Circle Brush", width-100-60, height-150 -10);
    
    if(circle)
      image( checkbox.get(0,0,30,30), width-100-95, height-150 -28);
    else
      image( checkbox.get(28,0,30,30), width-100-95, height-150 -28);
    
    if (mousePressed && mouseX>width-100-95 && mouseX<width-100-95+30 && mouseY>height-150 -28 && mouseY<height-150 -28+30) { // If the user clicks to change the brush type
      circle=!circle; // changes to opposite
      delay(100);
    }
    

    //Reset textSize
    textSize(16);

    
    
    
    // Intensity Slider
    stroke(136);
    fill(238);
    rect(width-250, height-50, 200, 10, 4, 4, 4, 4);
    fill(#2c3e50);
    text("Intensity : ", width-265-textWidth("Intensity :"), height-40);
    text(intensity,  width-40, height-40);
    noStroke();
    ellipse(width-250 + intensitySliderX, height-45, 20,20);
    if (draggingSizeSlider || (mousePressed && mouseX>(width-250 + intensitySliderX-10) && mouseX<(width-250 + intensitySliderX+10) && mouseY>height-50-20 && mouseY<height-50+20)) {
        intensitySliderX=constrain(intensitySliderX+(mouseX-pmouseX), 0, 200); // Add the difference between the mousex in the previous frame and the new one, while keeping sliderx between 0 and 200
        draggingSizeSlider=true;
    }
    intensity = (int)map(intensitySliderX, 0, 200, 1, 30); // Change slider position to a value between 1 and 30
       
    //used old mousex and old mousey to stop re-applying effect when the mouse is not moving
    if(mousePressed && omouseX!=mouseX &&omouseY!=mouseY && mouseX>canvasx && mouseX<canvasx+canvaswidth && mouseY>canvasy && mouseY<canvasy+canvasheight) { 
      
      // convert the mouseX and mouseY to their position inside the original image
      mouseXinside=(int)map(mouseX, canvasx, canvasx+canvaswidth, 0, img.width);
      mouseYinside=(int)map(mouseY, canvasy, canvasy+canvasheight, 0, img.height);
      
      // Detect which brush is selected and apply effect
      switch (brush) { 
        case 0 : 
          if (filter) 
            Blur(img, intensity);
          else
            BlurBrush(img, mouseXinside, mouseYinside , size, intensity, circle);
          break;
        case 1 :
          if (filter) 
            sepiaTint(img, intensity);
          else 
            sepiaTintBrush(img, mouseXinside, mouseYinside , size, intensity, circle);
          break;
        case 2 :
          if (filter)
            Posterize(img, intensity);
          else
            PosterizeBrush(img, mouseXinside, mouseYinside , size, intensity, circle);
          break;
        case 3 :
          if (filter)
            img=source.get();
          else
            EraseBrush(img, mouseXinside, mouseYinside , size, intensity, circle);
          break;
      }
      
      // Register the mouse position to prevent re-applying effect when the mouse is not moving
      omouseX=mouseX;
      omouseY=mouseY;
    }
    
    // If the mouse is not pressed reset the old positions otherwise the mouse would never be able to click
    if(!mousePressed) {
      omouseX=0;
      omouseY=0;
      draggingSizeSlider=false;
      draggingIntensitySlider=false;
    }
    
    // Detect whether the mouse is over a brush or not to change the cursor
    cursorhand=false;
    
    // Draw the brushes & tools and move them if the mouse is over one of them
    for(int i=0; i<brushes.length; i++) {
      if ((mouseX> brushesx + i*100 && mouseX< brushesx + 100 + i*80 && mouseY>height-220 && mouseY<height) || brush==i) {
        image(brushes[i], brushesx + i*100, height-220);
        String text="Blur";
        switch (i) { 
          case 0 : 
            text="Blur";
            break;
          case 1 :
            text="Sepia";
            break;
          case 2 :
            text="Posterize";
            break;
          case 3 :
            text="Eraser";
            break;
        }
        fill(0);
        text(text, brushesx + 20 - textWidth(text)/2 + 97*i, height-230);
        cursorhand=true;
        if(mousePressed) {
          brush=i; // brush/tool i is selected
        }
      } else {
        image(brushes[i],  brushesx + i*100, height-180);
      }        
    }
    
    // Change the cursor based on whether a brush is getting selected or not
    
    if(cursorhand) {
      cursor(HAND);
    } else {
      cursor(ARROW);
    }
    
    // draw the canvas
    fill(#2c3e50);
    rect(canvasx-10,canvasy-10, canvaswidth+20, canvasheight+20, 5, 5, 5, 5);
    image(img,canvasx,canvasy, canvaswidth, canvasheight);
    

}

/*
  Filters (applied on whole image)
*/


public void sepiaTint(PImage img, int intensity)
{
  float newIntensity=map(intensity, 1, 30, 0.8, 1.3);
  for(int i=0;i<img.width;i++)
  {
    for(int j=0;j<img.height;j++)
    {
      color c = img.get(i,j);  
      float newRed = (red(c) * .393) + (green(c) *.769) + (blue(c) * .189);
      float newGreen = (red(c) * .349) + (green(c) *.686) + (blue(c) * .168);
      float newBlue = (red(c) * .272) + (green(c) *.534) + (blue(c) * .131);
      img.set(i,j,color(newRed*newIntensity,newGreen*newIntensity,newBlue*newIntensity));
    }
  }
  
}

public void Posterize(PImage img, int intensity)
{
  for(int i=0;i<img.width;i++)
  {
    for(int j=0;j<img.height;j++)
    {
      color c = img.get(i,j);  
      float newRed =  ((float)255/(intensity - 1)) * floor(red(c)/((float)256/intensity));
      float newGreen =   ((float)255/(intensity - 1)) *floor(green(c)/((float)256/intensity));
      float newBlue =   ((float)255/(intensity - 1)) *floor(blue(c)/((float)256/intensity));
      img.set(i,j,color(newRed,newGreen,newBlue));
    }
  }
  
}

public void Blur(PImage img, int intensity)
{
  for(int i=0;i<img.width;i++)
  {
    for(int j=0;j<img.height;j++)
    {
      img.set(i,j,AvgAround(img,  i, j, intensity));
    }
  }
  
}

/*
  Functions for the brushes
  The circle boolean parameter makes the brushe a circle instead of square
  Explanation for the circle brush : http://i.imgur.com/bbjaIEE.jpg
*/

public void sepiaTintBrush(PImage img, int x, int y, int size, int intensity, boolean circle)
{
  PImage img2 = img.get();
  float newIntensity=map(intensity, 1, 30, 0.8, 1.3);
  for(int j=y-size;j<=y+size;j++)
  {
    for (int i =x-size; i<=x+size; i++) {
        if(circle && i>x+size*cos(PI-asin((float)(y-j)/size)) && i<x+size*cos(asin((float)(y-j)/size) )) { // makes the brush a circle
          color c = img2.get(i,j);  
          float newRed = (red(c) * .393) + (green(c) *.769) + (blue(c) * .189);
          float newGreen = (red(c) * .349) + (green(c) *.686) + (blue(c) * .168);
          float newBlue = (red(c) * .272) + (green(c) *.534) + (blue(c) * .131);
          img.set(i,j,color(newRed*newIntensity,newGreen*newIntensity,newBlue*newIntensity));
        }
      }
  }
  
}

public void PosterizeBrush(PImage img, int x, int y, int size, int intensity, boolean circle)
{
  PImage img2 = img.get();
  for(int j=y-size;j<=y+size;j++)
  {
    for (int i =x-size; i<=x+size; i++) {
        color c = img2.get(i,j);  
        float newRed =  ((float)255/(intensity - 1)) * floor(red(c)/((float)256/intensity));
        float newGreen =   ((float)255/(intensity - 1)) *floor(green(c)/((float)256/intensity));
        float newBlue =   ((float)255/(intensity - 1)) *floor(blue(c)/((float)256/intensity));
        if(circle) // makes the brush a circle
        {
          if(i>x+size*cos(PI-asin((float)(y-j)/size)) && i<x+size*cos(asin((float)(y-j)/size) ))
            img.set(i,j,color(newRed,newGreen,newBlue));
        } else
          img.set(i,j,color(newRed,newGreen,newBlue));
    }
  }
  
}


public void BlurBrush(PImage img,  int x, int y, int size, int intensity, boolean circle)
{
  PImage img2 = img.get();
  for(int j=y-size;j<=y+size;j++)
  {
    for (int i =x-size; i<=x+size; i++) {
        if(circle) // makes the brush a circle
        {
          if(i>x+size*cos(PI-asin((float)(y-j)/size)) && i<x+size*cos(asin((float)(y-j)/size) ))
            img.set(i,j,AvgAround(img2,  i, j, intensity));
        } else
          img.set(i,j,AvgAround(img2,  i, j, intensity));
    }
  }
  
}

public void EraseBrush(PImage img,  int x, int y, int size, int intensity, boolean circle)
{
  PImage img2 = source.get();
  for(int j=y-size;j<=y+size;j++)
  {
    for (int i =x-size; i<=x+size; i++) {
        if(circle) // makes the brush a circle
        { 
            if(i>x+size*cos(PI-asin((float)(y-j)/size)) && i<x+size*cos(asin((float)(y-j)/size) ))
              img.set(i,j,img2.get(i,j));
        } else
          img.set(i,j,img2.get(i,j));
    }
  }
  
}

// Finds the average color of the pixels in the area around x,y of radius intensity

public color AvgAround(PImage img, int x, int y, int intensity) {
  float sumred=0, sumblue=0, sumgreen=0, numberpixels=(int)pow(intensity*2,2);
  for(int i=x-intensity;i<x+intensity;i++)
  {
    for(int j=y-intensity;j<y+intensity;j++)
    {
      color c = img.get(i,j);  
      sumred=sumred+red(c);
      sumblue=sumblue+blue(c);
      sumgreen=sumgreen+green(c);
    }
  }
  return color(sumred/numberpixels, sumgreen/numberpixels, sumblue/numberpixels);
}