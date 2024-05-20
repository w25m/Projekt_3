#include <matplot/matplot.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int sgn(double x) {
    return x>=0 ? 1 : -1;
}

vector<complex<double>> computeDFT(const vector<double>& signal) {
    size_t N = signal.size();
    vector<complex<double>> dft(N);
    const complex<double> J(0, 1); // Imaginary unit

    for (size_t k = 0; k < N; ++k) {
        for (size_t n = 0; n < N; ++n) {
            double angle = 2 * M_PI * k * n / N;
            dft[k] += signal[n] * exp(-J * angle);
        }
    }

    return dft;
}


void plotDFT(const vector<complex<double>>& dft, double duration) {
    size_t N = dft.size();
    vector<double> frequencies(N);
    vector<double> magnitudes(N);
    double samplingRate = N / duration; 

   
    for (size_t i = 0; i < N; ++i) {
        frequencies[i] = i * samplingRate / N;
        magnitudes[i] = abs(dft[i])/N;
    }

    double maxMagnitude = *max_element(magnitudes.begin(), magnitudes.end());

    auto ax = matplot::subplot(2, 1, 2);
    matplot::plot(ax, frequencies, magnitudes);
    matplot::title(ax, "DFT");
    matplot::xlabel(ax, "Frequency [Hz]");
    matplot::ylabel(ax, "Magnitude");
    matplot::ylim(ax, { -0.1, maxMagnitude * 1.1 }); // Adjust y-axis to show peaks better
    matplot::xlim(ax, { -300, samplingRate+300 }); // Adjust x-axis to show peaks better
    
}


void generateSignal(const string& type, double frequency, double duration, const int samplingRate) {
    const int numSamples = static_cast<int>(duration * samplingRate);

    vector<double> timeValues(numSamples);
    vector<double> signalValues(numSamples);

    for (int i = 0; i < numSamples; ++i) {
        double t = static_cast<double>(i) / samplingRate;
        if (type == "sin") {
            signalValues[i] = sin(2.0 * M_PI * frequency * t);
        }
        else if (type == "cos") {
            signalValues[i] = cos(2.0 * M_PI * frequency * t);
        }
        else if (type == "rec") {
            signalValues[i] = (sin(2.0 * M_PI * frequency * t) <= 0) ? -1 : 1;
        }
        else if (type == "saw") {
            signalValues[i] = 2.0 * fmod(t * frequency, 1.0) - 1.0;
        }
        timeValues[i] = t;
    }


  
    auto ax1 = matplot::subplot(2, 1, 1);
    matplot::plot(ax1, timeValues, signalValues);
    matplot::xlabel(ax1, "Czas [s]");
    matplot::ylabel(ax1, "Amplituda");
    matplot::ylim(ax1, { -1.5, 1.5 }); // Adjust y-axis to show peaks better
    matplot::xlim(ax1, { -0.3, duration +0.3}); // Adjust x-axis to show peaks better
    
    vector<complex<double>> dft = computeDFT(signalValues);
    plotDFT(dft, duration);

    matplot::show(); // Show both plots at the same time
}


int main() {
    double time;
    double frequency;
    int value;
    string type;
    const double samplingRate = 4000.0;
    printf("Podaj typ funkcji (sin, cos, rec, saw): ");
    cin >> type;
    printf("Podaj czestotliwosc:");
    cin >> frequency;
    printf("Podaj czas sygnalu:");
    cin >> time;
    generateSignal(type, frequency, time, samplingRate);
    return 0;
}
