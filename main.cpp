#include "mbed.h"
#include "MMA7660.h"

// Define accelerometer and LED pins
MMA7660 MMA(p28, p27);
PwmOut red(p23);
PwmOut green(p24);
PwmOut blue(p25);

int main() {
    red.period(0.001);
    green.period(0.001);
    blue.period(0.001);

    while (1) {
        // Read accelerometer values
        float x = MMA.x();
        float y = MMA.y();
        float z = MMA.z();

        // Map accelerometer values to LED brightness
        float redBrightness = x;
        float greenBrightness = y;
        float blueBrightness = z;

        // Set LED brightness
        red.write(redBrightness);
        green.write(greenBrightness);
        blue.write(blueBrightness);

        // Wait a short period of time
        wait_ms(100);
    }
}
}
