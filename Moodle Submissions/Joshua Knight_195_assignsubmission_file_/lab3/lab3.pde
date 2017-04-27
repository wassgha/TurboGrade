int score_1, score_2, paddle_width, paddle_height, paddle1_x, paddle1_y, paddle2_x, paddle2_y, ball_dimension, red, green, blue, level;
float angle, ball_y, ball_x, speed;
boolean single_player;
void setup()
{
  size(600, 400);
  fill(255);
  noStroke();
  frameRate(120); // Makes the game smoother
  paddle_width=20;
  paddle_height=height/6;
  paddle1_x=0;
  paddle1_y=height/2-paddle_height/2;  // Initialise paddle 1 to the middle of the screen
  paddle2_x=width-paddle_width;
  paddle2_y=height/2-paddle_height/2;  // Initialise paddle 2 to the middle of the screen
  // Intialise the ball to the middle too
  ball_x=width/2;
  ball_y=height/2;
  ball_dimension=10;
  speed=3;
  angle=0;
  score_1=0;
  score_2=0;
  single_player=false;
  red=0;
  green=0;
  blue=0;
  // Level 1 is the slowest speed for the single player mode
  level=1;
  // Randomly change the background
  red=(int)random(0,190);
  green=(int)random(0,190);
  blue=(int)random(0,190);
}
void draw()
{
  background(red, green, blue);

  rectMode(CORNERS);
  
  //SINGLE/MULTIPLAYER
  
    if(keyPressed && key=='2' && single_player==false) {
      single_player=true;
      // RESET THE GAME
        speed=3;
        score_1=0;
        score_2=0;
        // Set ball and paddles to the middle of the screen
        ball_x=width/2;
        ball_y=height/2;
        angle=0;
        paddle1_x=0;
        paddle1_y=height/2-paddle_height/2;
        paddle2_x=width-paddle_width;
        paddle2_y=height/2-paddle_height/2;
        red=(int)random(0,190);
        green=(int)random(0,190);
        blue=(int)random(0,190);
        delay(100);  
      // END RESET

    } else if(keyPressed && key=='1' && single_player==true) {
      single_player=false;
      // RESET THE GAME
        speed=3;
        score_1=0;
        score_2=0;
        // Set ball and paddles to the middle of the screen
        ball_x=width/2;
        ball_y=height/2;
        angle=0;
        paddle1_x=0;
        paddle1_y=height/2-paddle_height/2;
        paddle2_x=width-paddle_width;
        paddle2_y=height/2-paddle_height/2;
        red=(int)random(0,190);
        green=(int)random(0,190);
        blue=(int)random(0,190);
        delay(100);  
      // END RESET
    } else if (keyPressed && keyCode==UP && single_player==true) {
      level+=1;
      delay(100);  
    } else if (keyPressed && keyCode==DOWN && single_player==true) {
      level-=1;
      delay(100);  
    }
    
   textSize(12); 
   if(single_player) {
        text("SINGLE PLAYER MODE (Press 1 to switch)", width/2-textWidth("SINGLE PLAYER MODE (Press 1 to switch)")/2, 20);
        text("LEVEL " + level + " (Press Up and Down to switch)", width/2-textWidth("LEVEL " + level + " (Press Up and Down to switch)")/2, 50);
    } else {
        text("MULTI PLAYER MODE (Press 2 to switch)", width/2-textWidth("MULTI PLAYER MODE (Press 2 to switch)")/2, 20);
    }

  // PADDLE 1
  if(single_player) {
      rect(paddle1_x, paddle1_y, paddle1_x + paddle_width, paddle1_y+paddle_height);
      // Algorithm for the paddle to automatically follow the ball
      if((paddle1_y+(paddle_height/3)) > ball_y  && paddle1_y>5) {
        // move the paddle with a speed equal to the level number
        paddle1_y-=level;
      } else if ((paddle1_y+(2*paddle_height/3)) < ball_y   && paddle1_y<(height-paddle_height-5))  {
        // move the paddle with a speed equal to the level number
        paddle1_y+=level;
      }
  } else {
      rect(paddle1_x, paddle1_y, paddle1_x + paddle_width, paddle1_y+paddle_height);
      if(mouseY<paddle1_y && paddle1_y>5) {
        paddle1_y-=3;
      } else if (mouseY>(paddle1_y+paddle_height)  && paddle1_y<(height-paddle_height-5)) {
        paddle1_y+=3;
      }
  }
  // PADDLE 2
  rect(paddle2_x, paddle2_y, paddle2_x + paddle_width, paddle2_y+paddle_height);
  if(keyPressed && (key=='A' || key=='a') && paddle2_y>5) {
    paddle2_y-=3;
  } else if (keyPressed && (key=='Z' || key=='z')  && paddle2_y<(height-paddle_height-5)) {
    paddle2_y+=3;
  } 
  // BALL
  rectMode(CENTER);
  rect(ball_x, ball_y, ball_dimension, ball_dimension);
  // Ball movement determined by a calculated angle and an increasing speed
  ball_x=ball_x+speed*cos(angle);
  ball_y=ball_y+speed*sin(angle);
  if((ball_x)>=paddle2_x && ball_y>(paddle2_y-ball_dimension+1) && ball_y<(paddle2_y+paddle_height+ball_dimension-1)) {
    speed+=0.5; // increase the speed to make the game harder
    ball_x=paddle2_x-ball_dimension;
    /* 
       Convert the position where the ball hit the paddle relative to the paddle height to an angle between 45 and -45 degrees
       Used the formula ball_y - (paddle_y + ball dimension) to get a number between 0 and paddle_height that indicates the position
       of the hit then used the map function to convert it to an angle.
    */
    angle=-map(ball_y-paddle2_y+ball_dimension, 0, paddle_height+2*ball_dimension, -PI/4, PI/4) + PI; 
    // Added PI and multiplied by -1 to reverse the angle (ex : 45 degrees becomes 135 degrees) since we are working on the right paddle
  } else if(ball_x<=(paddle1_x+paddle_width) && ball_y>(paddle1_y-ball_dimension+1) && ball_y<(paddle1_y+paddle_height+ball_dimension-1)) {
    speed+=0.5; // increase the speed to make the game harder
    ball_x=(paddle1_x+paddle_width);
    /* 
       Convert the position where the ball hit the paddle relative to the paddle height to an angle between 45 and -45 degrees
       Used the formula ball_y - (paddle_y + ball dimension) to get a number between 0 and paddle_height that indicates the position
       of the hit then used the map function to convert it to an angle.
    */
    angle=map(ball_y-paddle1_y+ball_dimension, 0, paddle_height+2*ball_dimension, -PI/4, PI/4);
  } else if(ball_y>=height || ball_y<=0) {
    // Reflection = -angle
    angle=-1*angle;
  }
  
  // SCORE
  
  if (ball_x>width) {
    score_1=score_1+1;
    // RESET THE GAME
      speed=3; // Reset the speed
      // Set ball and paddles to the middle of the screen
      ball_x=width/2;
      ball_y=height/2;
      paddle1_x=0;
      paddle1_y=height/2-paddle_height/2;
      paddle2_x=width-paddle_width;
      paddle2_y=height/2-paddle_height/2;
      angle=PI; // goes in the direction of the left paddle
      red=(int)random(0,190);
      green=(int)random(0,190);
      blue=(int)random(0,190);
      delay(100);  
    // END RESET
 } else if (ball_x<0) {
    score_2=score_2+1;
    // RESET THE GAME
      speed=3; // Ball goes to the winning player
      // Set ball and paddles to the middle of the screen
      ball_x=width/2;
      ball_y=height/2;
      paddle1_x=0;
      paddle1_y=height/2-paddle_height/2;
      paddle2_x=width-paddle_width;
      paddle2_y=height/2-paddle_height/2;
      angle=0;
      red=(int)random(0,190);
      green=(int)random(0,190);
      blue=(int)random(0,190);
      delay(100);  
    // END RESET
  }
  // DRAW SCORES
  textSize(26); 
  text(score_1, 30, 40); // Left score
  text(score_2, width-30, 40); // Right score
}