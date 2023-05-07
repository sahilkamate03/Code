unsigned long lastBackgroundTime = 0;
bool isBackgroundRunning = false;

void normal()
{
    Serial.println("Hello");
  	delay(1000);
}

void backgroundFxn()
{
    Serial.println("World");
  	delay(5000);
}

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
  
    // Set up interrupt on pin 2 to trigger on rising edge
    pinMode(2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(2), isr, RISING);
}

void loop()
{
    normal();
    
    // Check if the background function should run
    if (isBackgroundRunning && (millis() - lastBackgroundTime >= 5000)) {
        backgroundFxn();
      	Serial.println("checking");
        lastBackgroundTime = millis();
    }
}

void isr()
{
    // Toggle the background function flag on interrupt
    isBackgroundRunning = !isBackgroundRunning;
}
