/*
 * --------------------------------------------------------------------------------------------------------------------
 * Example sketch/program to fix a broken UID changeable MIFARE cards.
 * --------------------------------------------------------------------------------------------------------------------
 * Make sure you have installed a MFRC522 library; for further details and other examples see: https://github.com/miguelbalboa/rfid
 * 
 * This sample shows how to fix a broken UID changeable MIFARE cards that have a corrupted sector 0.
 * 
 * @author Salko Hajric (extended version from Tom Clement)
 * @license Released into the public domain.
 * 
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 *
 * More pin layouts for other boards can be found here: https://github.com/miguelbalboa/rfid#pin-layout
 */

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   9     // Configurable, see typical pin layout above
#define SS_PIN    10    // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

void setup() {
  Serial.begin(9600);  // Initialize serial communications with the PC
  while (!Serial);     // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();         // Init SPI bus
  mfrc522.PCD_Init();  // Init MFRC522 card
  Serial.println(F("Warning: this example clears your mifare UID, use with care!"));
}

void loop() {
    // 1. Check if any card is present at all
  if (!mfrc522.PICC_IsNewCardPresent()) {
    Serial.println(F("Please, add the card"));
    delay(1000);
    return;
  }


  // 2. Try to read card serial (UID)
  if (!mfrc522.PICC_ReadCardSerial()) {
    Serial.println(F("Card detected but not readable"));

    // Try recovery only if card is detected but unreadable
    Serial.println(F("Attempting sector 0 recovery..."));

    if (mfrc522.MIFARE_UnbrickUidSector(false)) {
      Serial.println(F("Recovery attempted. Remove and re-present card."));
    } else {
      Serial.println(F("Recovery failed or card not supported."));
    }

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    delay(1500);
    return;
  }

  // 3. Card is readable — print UID
  Serial.print(F("Card readable. UID: "));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) Serial.print("0");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    Serial.print(" ");
  }

  Serial.println(F("No recovery needed."));

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
  delay(2000);
}
