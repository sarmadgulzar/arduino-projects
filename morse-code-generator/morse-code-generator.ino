// Define the LED pin
const int LED_PIN = 13;

// Create two arrays, one to hold the characters and other to hold their Morse codes
char letters[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
String codes[36] = {".-", "-...", "-.-.", "-..", ".", "..-", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--....", "---..", "----.", "-----"};
  
void MorseCode(String message)
{
  
  // Loop over the 'message' variable
  for (int i = 0; i < message.length(); i++) {

    // Loop over the 'letters' array and check which character matches the current character in 'message' array
    for (int j = 0; j < 36; j++) {
      
      if (letters[j] == message[i]) {

        // Get the Morse code of current character and loop over its contents
        for (int k = 0; k < codes[j].length(); k++) {

          // For the dot, blink the LED for 250ms
          if (codes[j][k] == '.') {
            digitalWrite(LED_PIN, HIGH);
            delay(250);
          }

          // For the dash, blink the LED for 750ms
          else {
            digitalWrite(LED_PIN, HIGH);
            delay(750);
          }

          // After each character, turn LED off for 250ms
          digitalWrite(LED_PIN, LOW);
          delay(250);

        }

        // If character is found in 'letters', break and move to the next index in 'message'
        break;

      }

    }

  }

}

void setup() {

  // Initialize the Serial Monitor with baud rate of 9600
  Serial.begin(9600);

  // Set the LED_PIN as OUTPUT
  pinMode(LED_PIN, OUTPUT);
}

void loop() {

  // Initialize a String variable with empty string
  String response = "";

  // Wait while something is sent through Serial Monitor
  while (Serial.available() == 0)
    {
    }

  // Read from Serial Monitor to the response variable
  response = Serial.readString();
  
  // Call the MorseCode() function with received response as argument
  MorseCode(response);
}
