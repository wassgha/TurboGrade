/******************************
*             Lab 4           *
*        Wassim Gharbi        *
*******************************/

float[] data; //This array will store the stock prices
float max_val,min_val,scale_x,scale_y;
int smooth_value=10, max, max_gain, max_drop, min, number_labels, price_per_label, label;
float[] smooth_data; //This array will store the stock prices
float[] gain_data; //This array will store the stock prices
String[] dates; //This array will store the dates as Strings

//Finds the maximum value of an array
public float maximum(float [] array){
  float maximum=array[0];
  for ( int i=1; i<array.length; i++) { 
    if(array[i]>maximum) // a number than is higher than the maximum IS the maximum
      maximum=array[i];
  }
  return maximum;
}
//Finds the minimum value of an array
public float minimum(float [] array){
  float minimum=array[0];
  for ( int i=1; i<array.length; i++) { 
    if(array[i]<minimum) // a number than is lower than the minimum IS the minimum
      minimum=array[i];
  }
  return minimum;
}

// Finds the index of a value in an array
public int find(float [] array, float searchfor){
  int pos=-1;
  for ( int i=0; i<array.length; i++) { 
    if(array[i]==searchfor) // if the values are equal, we return the position
      pos=i;
  }
  return pos;
}

// Calculates the gain and puts it in an array
public float [] gain(float [] array){
  float [] array_2=new float[array.length-1];
  for ( int i=0; i<array.length-1; i++) { 
    array_2[i]=array[i+1]-array[i];
  }
  return array_2;
}

// Calculates the moving average and puts it in an array
float [] moving_average(float [] array, int N){
  float [] array_2 = new float[array.length-N]; //This array will store the stock prices
  for ( int i=0; i<(array_2.length); i++) { 
    // We calculate average from the Nth value to the last value
    float average=0;
    for ( int j=i; j<=i+N; j++) {
       average=average+data[j];
    }
    average=average/(N+1);
    array_2[i]=average;
  }
  
  return array_2;
}


void setup()
{
  size(700, 400);
  rectMode(CORNERS);
  ellipseMode(CENTER);
  
  // File operations
  String[] lines = loadStrings("MSFTstockPrices.txt"); //Load stock prices as strings
  data = float(lines); // Convert strings to floats
  dates = loadStrings("dates.txt"); // Load dates as strings
  
  // Calculate maximum and minimum
  max_val=maximum(data);
  min_val=minimum(data);
  
  // Find the index of maximum and minimum
  max=find(data, max_val);
  min=find(data, min_val);
  
  // Calculate highest gain and lowest drop
  gain_data = gain(data);
  float gain_value=maximum(gain_data); // defined in setup because we don't need it in draw
  float drop_value=minimum(gain_data); // defined in setup because we don't need it in draw
  // Find the index of maximum drop and maximum gain
  max_drop=find(gain_data, drop_value);
  max_gain=find(gain_data, gain_value);
  
  // Fill array for smooth curve using moving average
  smooth_data = moving_average(data, smooth_value);
  
  scale_x=(width-100)/((float)(data.length-1)); //width of the canvas divided by number of data points gives the horizontal scale
  scale_y=(height-100)/(max_val-min_val); //height of the canvas divided by vertical range gives the vertical scale
  
  number_labels=(height-100)/100;
  price_per_label=round((max_val-min_val)/number_labels);
  
}
void draw() {
  
  background(0);
  fill(255);
  noStroke();
  
  // Draw canvas
  rect(50, 50, width-50, height-50);
  
  // Draw title
  textSize(32);
  textAlign(CENTER);
  text("Stock Prices", width/2, 35);
  
  //Draw labels
  textSize(14);
  label=(int)(max_val);
  stroke(190);
  for(int i=0; i<=number_labels; i++) { 
    text(label, 25, 50+i*100);    
    line(50,50+i*100, width-51, 50+i*100);
    label-=price_per_label;
  }
  
  // Draw the line curve
  stroke(0);
  for(int i=0; i<data.length-1; i++) { 
    // if we're drawing the highest spike or the highest drop, we change color otherwise we use black
    if (i==max_drop)
      stroke(255,0,0);
    else if (i==max_gain)
      stroke(0, 255, 0);
    else
      stroke(0);
    /*
      X= i*scale_x+50 (50 is the padding of the canvas)
      Y=(height-50)-(data[i]-min_val)*scale_y (we use height-Y because our axes are inverted
     */
 
    line(i*scale_x+50, (height-50)-(data[i]-min_val)*scale_y,  (i+1)*scale_x+50, (height-50)-(data[i+1]-min_val)*scale_y);
  }
  
  // Draw circles for the highest and lowest values
  fill(255);
  stroke(0,255,0);
  ellipse(max*scale_x+50, (height-50)-(data[max]-min_val)*scale_y, 5, 5);
  stroke(255,0,0);
  ellipse(min*scale_x+50, (height-50)-(data[min]-min_val)*scale_y, 5, 5);
  
  // Make it interactive
  stroke(0);
  if(mouseX > 50 && mouseX<=(width-50)) {
    int i=floor((mouseX-50)/scale_x);
    // draw an ellipse at the same position of the data point
    ellipse(i*scale_x+50, (height-50)-(data[i]-min_val)*scale_y, 5, 5);
    text(dates[i] + ", " + data[i], width/2, height-20);
    
  }
  
  // Recalculate the smooth curve for every value (use keys 0 to 9 )
  if (keyPressed && key>='0' && key<='9') {
      println(smooth_value);
      smooth_value=key-48;//-48 to convert from ascii to numbers
      println(smooth_value);
      smooth_data = moving_average(data, smooth_value);
      for(int i=0; i<smooth_data.length;i++) {
          println("smooth_data[" + i + " ]= " + smooth_data[i]);
      }
      delay(300);
  }
  
  
  // Draw the smooth curve
  stroke(0,0,255);
  for(int i=0; i<(smooth_data.length-1); i++) { 
    line((i+smooth_value)*scale_x+50, (height-50)-(smooth_data[i]-min_val)*scale_y,  (i+1+smooth_value)*scale_x+50, (height-50)-(smooth_data[i+1]-min_val)*scale_y);
  }
}