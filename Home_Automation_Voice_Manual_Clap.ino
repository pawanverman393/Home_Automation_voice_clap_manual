// Relay pins
const int relay1 = 7;
const int relay2 = 6;
const int relay3 = 5;
const int relay4 = 4;

const int Sensor = 8;  

int x = 0;
int y = 0;


void setup() {
  // Initialize relay pins as output
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  // Turn off all relays initially
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  pinMode(Sensor, INPUT);

  // Begin Bluetooth communication
  Serial.begin(9600);  
  Serial.println("Voice Controlled Home Automation System Ready");
}

void loop() {

x = digitalRead(Sensor);
y = digitalRead(relay4);

if (y == HIGH && x == LOW) { 
delay(250);
Serial.println("Sound detected!");
digitalWrite(relay4, LOW); 
}
if (y == LOW && x == HIGH) { 
delay(500);
digitalWrite(relay4, HIGH); 
}
  // Check for Bluetooth commands
  if (Serial.available() > 0) {
    String command = Serial.readString(); // Read command from Bluetooth
    command.trim();                       // Remove extra spaces or newline characters
    Serial.println("Command received: " + command);
    Serial.flush();

    // Match commands to control relays
    if (command == "turn on bulb 1" || command=="1") {
      digitalWrite(relay1, LOW);  // Activate relay for light
      Serial.println("Bulb-1 is ON");
    } else if (command == "turn off bulb 1" || command=="2") {
      digitalWrite(relay1, HIGH); // Deactivate relay for light
      Serial.println("Bulb-1 is OFF");
    } else if (command == "turn on bulb 2" || command=="3") {
      digitalWrite(relay2, LOW);  // Activate relay for fan
      Serial.println("Bulb-2 is ON");
    } else if (command == "turn off bulb 2" || command=="4") {
      digitalWrite(relay2, HIGH); // Deactivate relay for fan
      Serial.println("Bulb-2 is OFF");
    } else if (command == "turn on bulb 3" || command=="5") {
      digitalWrite(relay3, LOW);  // Activate relay for Bulb1
      Serial.println("Bulb-3 is ON");
    } else if (command == "turn off bulb 3" || command=="6") {
      digitalWrite(relay3, HIGH); // Deactivate relay for Bulb1
      Serial.println("Bulb-3 is OFF");
    } else if (command == "turn on bulb 4" || command=="7") {
      digitalWrite(relay4, LOW);  // Activate relay for AC
      Serial.println("Bulb-4 is ON");
    } else if (command == "turn off bulb 4" || command=="8") {
      digitalWrite(relay4, HIGH); // Deactivate relay for AC
      Serial.println("Bulb-4 is OFF");
    }
    else if (command == "turn on all") {
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, LOW);
      Serial.println("All Bulb is ON");
    } else if (command == "turn off all") {
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, HIGH);
      
      Serial.println("All Bulb is OFF");
    } else {
      Serial.println("Invalid Command. Try Again.");
    }
    Serial.flush();
  }
}
