# SERIAL_RPI_TEST

Sketch de Arduino para establecer una comunicación serie bidireccional, ideal para conectar con dispositivos como una Raspberry Pi.

## Características

- **Comunicación Bidireccional**: Reenvía datos desde el monitor serie (USB) al puerto de comunicación y viceversa.
- **Configurable**: Permite elegir fácilmente entre `HardwareSerial` (UART por hardware) y `SoftwareSerial` (UART por software).

## Configuración

Para cambiar entre el modo de comunicación por hardware o por software, abre el archivo `SERIAL_RPI_TEST.ino` y edita las siguientes líneas al principio del código:

### Usar HardwareSerial (Modo por defecto)

Asegúrate de que la línea `#define USE_SOFTWARE_SERIAL` esté comentada.

```cpp
// Descomenta la siguiente línea para usar SoftwareSerial en lugar de HardwareSerial
// #define USE_SOFTWARE_SERIAL
```

Puedes configurar qué puerto `HardwareSerial` y qué pines utilizar:

```cpp
#define HW_SERIAL_PORT 2 // UART2
#define HW_SERIAL_RX_PIN 26
#define HW_SERIAL_TX_PIN 27
```

### Usar SoftwareSerial

Descomenta la línea `#define USE_SOFTWARE_SERIAL`.

```cpp
// Descomenta la siguiente línea para usar SoftwareSerial en lugar de HardwareSerial
#define USE_SOFTWARE_SERIAL
```

Puedes configurar los pines que se usarán para la comunicación por software:

```cpp
#define SOFTWARE_SERIAL_RX_PIN 10
#define SOFTWARE_SERIAL_TX_PIN 11
```

**Nota**: `SoftwareSerial` puede ser inestable a velocidades de baudios altas. Se ha configurado a `9600` por defecto.

## Licencia

Este proyecto se distribuye bajo la licencia **Creative Commons Atribución-NoComercial 4.0 Internacional (CC BY-NC 4.0)**.

Puedes ver el texto completo de la licencia en el archivo [LICENSE](LICENSE).

## Descargo de Responsabilidad

El autor de este software no se hace responsable de ningún daño, pérdida de datos o cualquier otro problema que pueda surgir del uso de este código. Utilízalo bajo tu propio riesgo.
