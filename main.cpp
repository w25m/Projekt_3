#include <matplot/matplot.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h> //1234
using namespace std;
void generateSinusoidalSignal(double frequency, double duration) {
    const double samplingRate = 10000.0; // więcej tego bardziej dokładny wykres (nie wiesz daj na 10 to ogarniesz o co chodzi)
    const int numSamples = static_cast<int>(duration * samplingRate);

    vector<double> timeValues;
    vector<double> signalValues;

    for (int i = 0; i < numSamples; ++i) { // tworzy punkty na podstawie których wykres
        double t = static_cast<double>(i) / samplingRate;
        double amplitude = sin(2.0 * M_PI * frequency * t);

        timeValues.push_back(t);
        signalValues.push_back(amplitude);
    }

    //Tworzy wykres
    matplot::plot(timeValues, signalValues);
    matplot::title("Sygnał");
    matplot::xlabel("Czas [s]");
    matplot::ylabel("Amplituda");

  
    matplot::show();
}

int main() {
    
    double desiredFrequency = 4.0; // ile sinusów na sekunde
    double signalDuration = 2.0; // czas oś X

    generateSinusoidalSignal(desiredFrequency, signalDuration);

    return 0;
}
	
	
