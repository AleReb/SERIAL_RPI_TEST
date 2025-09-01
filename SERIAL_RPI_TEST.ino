// Descomenta la siguiente línea para usar SoftwareSerial en lugar de HardwareSerial
// #define USE_SOFTWARE_SERIAL

#ifdef USE_SOFTWARE_SERIAL
  #include <SoftwareSerial.h>
  // Define los pines para SoftwareSerial
  #define SOFTWARE_SERIAL_RX_PIN 10
  #define SOFTWARE_SERIAL_TX_PIN 11
  SoftwareSerial softSerial(SOFTWARE_SERIAL_RX_PIN, SOFTWARE_SERIAL_TX_PIN);
#else
  #include <HardwareSerial.h>
  // Define qué puerto HardwareSerial usar (0 para Serial, 1 para Serial1, 2 para Serial2, etc.)
  // Y los pines correspondientes a ese puerto en tu placa
  #define HW_SERIAL_PORT 2 // UART2
  #define HW_SERIAL_RX_PIN 26
  #define HW_SERIAL_TX_PIN 27
  HardwareSerial COMserial(HW_SERIAL_PORT);
#endif

// Puntero genérico a la clase Stream para abstraer el puerto de comunicación
Stream* pCom = nullptr;

void setup() {
  // Inicia el monitor serie principal (USB)
  Serial.begin(115200);
  Serial.println("Iniciando...");

#ifdef USE_SOFTWARE_SERIAL
  Serial.println("Usando SoftwareSerial");
  pCom = &softSerial;
  // Inicia la comunicación SoftwareSerial
  softSerial.begin(9600); // SoftwareSerial puede ser inestable a velocidades altas
#else
  Serial.println("Usando HardwareSerial en el puerto " + String(HW_SERIAL_PORT));
  pCom = &COMserial;
  // Inicia la comunicación HardwareSerial en los pines definidos
  COMserial.begin(115200, SERIAL_8N1, HW_SERIAL_RX_PIN, HW_SERIAL_TX_PIN);
#endif

  pCom->println("Puerto de comunicacion inicializado.");
}

void loop() {
  // Si llegan datos por el puerto de comunicación (HW o SW), los reenviamos al monitor USB
  if (pCom->available()) {
    char c = pCom->read();
    Serial.write(c);
  }

  // Si llegan datos por el monitor USB, los enviamos al puerto de comunicación (HW o SW)
  if (Serial.available()) {
    char c = Serial.read();
    pCom->write(c);
  }
}