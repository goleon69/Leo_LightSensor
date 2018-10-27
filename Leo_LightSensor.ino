bool debug = true; // debug off
String errore =""; //string for error check across the libraries
int LightSensorAnalogPort = 0; //Analog port where the light sensor is connected


void setup() {
Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
while (!Serial) {
    ;               // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  
float Light = ReadLight();
Serial.println (Light);

  if( errore!="") {
  //here the code of the error
  }

}

/*Leo_LightSensor-2, 
Light sensor function ver 26-10-2018. Give the results in lux
works throught a regression algorithm reading several values of the analog output and compare
with a real value from a luxmeter (smartphone with luxmeter!)

Need the :                  
no libraries to include
String errore =""; //string for error check across the libraries
int LightSensorAnalogPort = 0; //Analog port where the light sensor is connected, to change according needs

Errors :
Not included errors for now.

Debug:
bool debug = false; // debug off

if debug = true  will print on the serial print all the data and errors.
 */

int ReadLight(){

float val; // internal variable
float lux; // lux variable according the sensor calibration.
  val=analogRead(LightSensorAnalogPort);
  
//this regression wiht R2 of 0.9968 is based on analog light sensor YWrobot SEN080605    
  lux = 0.0002*pow(val,3) - 0.0413*pow(val,2) + 4.4722*val - 25.543;  
      
  if (debug) {
    Serial.print(val,DEC);
    Serial.print("  : ");
    Serial.println(lux,DEC);      
  }
  delay(80); //estimated delay to get another read from the sensor
  
return(lux);
}


