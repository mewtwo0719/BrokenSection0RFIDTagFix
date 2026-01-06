  --------------------------------------------------------------------------------------------------------------------
  Program to fix a broken UID changeable MIFARE cards.
   --------------------------------------------------------------------------------------------------------------------
  Make sure you have installed a MFRC522 library; for further details and other examples see: https://github.com/miguelbalboa/rfid
  
  This sample shows how to fix a broken UID changeable MIFARE cards that have a corrupted sector 0.
  
  Typical pin layout used:
  -----------------------------------------------------------------------------------------
              MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
              Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
  Signal      Pin          Pin           Pin       Pin        Pin              Pin
  -----------------------------------------------------------------------------------------
  RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
  SPI SS      SDA(SS)      10            53        D10        10               10
  SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
  SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
  SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 
  More pin layouts for other boards can be found here: https://github.com/miguelbalboa/rfid#pin-layout
