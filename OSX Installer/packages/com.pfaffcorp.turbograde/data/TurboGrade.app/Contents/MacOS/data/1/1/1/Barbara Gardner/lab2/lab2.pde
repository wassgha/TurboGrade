  int circleradius,minutes;
  float hour, hourangle, minuteangle,secondangle;
void setup() {
   size(400,400);
   background(255);
   circleradius=(width-100)/2;
}
void draw() {
  //Calculations
  minutes=(int)map(mouseY,0,height,0,60);
  println("minutes " + minutes);
  hour=map(mouseX,0,width,0,12)+map(minutes,0,60,0,1);
  println("hour " + hour);
  hourangle=(map(hour,0,12,0,360)+90)*PI/180;
  minuteangle=(map(minutes,0,60,0,360)+90)*PI/180;
  secondangle=(map(second(),0,60,0,360)+90)*PI/180;

  
  
  rectMode(CORNERS);
  noStroke();
  fill(45);
  rect(width/3, 0, 2*width/3, height);
  ellipseMode(CORNERS);
  fill(50);
  stroke(100);
  strokeWeight(10);
  ellipse(50,50,width-50,height-50);
  //Indicators
  stroke(150);
  strokeWeight(3);
  line(width/2,height*70.0/400,width/2, height*90.0/400);
  line(width/2,height-height*70.0/400,width/2, height-height*90.0/400);
  line(width*70.0/400,height/2,width*90.0/400, height/2);
  line(width-width*90.0/400,height/2,width-width*70.0/400, height/2);
  stroke(0);
  fill(120);
  noStroke();
  stroke(230);
  //hours hand (middle, middle, middle - hypothenus * cos(hourangle), middle - hypothenus * sin(hourangle)) and hypotenuse is the length of the hand
  line(width/2,height/2, width/2 - (circleradius/2) * cos(hourangle), height/2 - (circleradius/2) * sin(hourangle));
  //minutes hand
  line(width/2,height/2, width/2 - (3*circleradius/4) * cos(minuteangle), height/2 - (3*circleradius/4) * sin(minuteangle));
  //seconds hand
  stroke(231, 76, 60);
  line(width/2,height/2, width/2 - (4*circleradius/5) * cos(secondangle), height/2 - (3*circleradius/4) * sin(secondangle));
  ellipseMode(CENTER);
  fill(231, 76, 60);
  ellipse(width/2,height/2,10,10);

}

