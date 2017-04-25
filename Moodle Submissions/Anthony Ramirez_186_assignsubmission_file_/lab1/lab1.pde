/*
Lab 1
Batman
Wassim Gharbi
*/

size(300,400);
background(64,64,64);
noStroke();
ellipseMode(CENTER);
rectMode(CORNERS);

//MOON
fill(100);
ellipse(70,70, 50,50);

// BUILDINGS

fill(50);
rect(0,100,30,400);
rect(30,120,90,400);
rect(90,150,130,400);
rect(130,80,150,400);
rect(150,100,170,400);
rect(170,160,200,400);
rect(200,210,240,400);
rect(240,250,280,400);
rect(280,60,300,400);

//POWER LINES

stroke(50);
line(170,140,280,110);
line(170,130,280,100);

//HEAD
fill(0);
noStroke();
ellipse(150,200, 150,60);
rect(75,200, 225,350);


//EARS
triangle(75,110,75,250,120,250);
triangle(225,110,180,250,225,250);


//BODY
triangle(0,400,150,250,300,400);


//EYES
fill(255);
triangle(95,220,100,235,140,245);
triangle(205,220,200,235,160,245);


//MOUTH
fill(144,133,100);
quad(85,240,180,300,180,370,95,340);
quad(215,240,120,300,120,370,205,340);
triangle(95,340,150,300,120,370);
triangle(180,370,150,300,205,340);