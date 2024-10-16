#include <BluetoothSerial.h>  // Include Bluetooth Serial library
#include <driver/i2s.h>       // Include I2S library for audio input

BluetoothSerial SerialBT;  // Create a Bluetooth Serial object

// I2S configuration for the microphone
i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),  // Set as master and receive mode
    .sample_rate = 44100,                                  // Sampling rate
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,         // Bit depth
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,         // Stereo
    .communication_format = I2S_COMM_FORMAT_I2S,          // I2S format
    .intr_alloc_flags = 0,                                 // No interrupt allocation flags
    .dma_buf_count = 8,                                    // Number of DMA buffers
    .dma_buf_len = 1024                                     // Length of each buffer
};

// I2S pin configuration
i2s_pin_config_t pin_config = {
    .bck_io_num = 26,   // Bit clock pin
    .ws_io_num = 25,    // Word select pin
    .data_out_num = I2S_PIN_NO_CHANGE, // Not used in RX
    .data_in_num = 34   // Data input pin
};

void setup() {
    Serial.begin(115200);       // Start serial communication
    SerialBT.begin("ESP32-Transmitter");  // Start Bluetooth with name
    i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);  // Install I2S driver
    i2s_set_pin(I2S_NUM_0, &pin_config); // Set I2S pins
}

void loop() {
    int16_t buffer[1024];  // Buffer to hold audio samples
    size_t bytesRead;

    // Read audio samples from the microphone
    i2s_read(I2S_NUM_0, (char *)buffer, sizeof(buffer), &bytesRead, portMAX_DELAY);

    // Send audio samples over Bluetooth
    SerialBT.write((uint8_t *)buffer, bytesRead);
}
