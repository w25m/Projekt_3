#include <matplot/matplot.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int sgn(double x) {
    return x>=0 ? 1 : -1;
}

void gensin(double frequency, double duration) {
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


void gencos(double frequency, double duration) {
    const double samplingRate = 10000.0; // więcej tego bardziej dokładny wykres (nie wiesz daj na 10 to ogarniesz o co chodzi)
    const int numSamples = static_cast<int>(duration * samplingRate);

    vector<double> timeValues;
    vector<double> signalValues;

    for (int i = 0; i < numSamples; ++i) { // tworzy punkty na podstawie których wykres
        double t = static_cast<double>(i) / samplingRate;
        double amplitude = cos(2.0 * M_PI * frequency * t);

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

void genrec(double frequency, double duration) {
    const double samplingRate = 10000.0; // więcej tego bardziej dokładny wykres (nie wiesz daj na 10 to ogarniesz o co chodzi)
    const int numSamples = static_cast<int>(duration * samplingRate);

    vector<double> timeValues;
    vector<double> signalValues;

    for (int i = 0; i < numSamples; ++i) { // tworzy punkty na podstawie których wykres
        double t = static_cast<double>(i) / samplingRate;
        double sinValue = sin(2.0 * M_PI * frequency * t);
        double amplitude = (sinValue <= 0) ? -1 : 1;
        
        timeValues.push_back(t);
        signalValues.push_back(amplitude);
    }

    //Tworzy wykres
    matplot::plot(timeValues, signalValues);
    matplot::title("Sygnał");
    matplot::xlabel("Czas [s]");
    matplot::ylabel("Amplituda");
    matplot::xlim({ 0, duration });
    matplot::ylim({ -1.5, 1.5 });

    matplot::show();
}

void gensaw(double frequency, double duration) {
    const double samplingRate = 10000.0; // więcej tego bardziej dokładny wykres (nie wiesz daj na 10 to ogarniesz o co chodzi)
    const int numSamples = static_cast<int>(duration * samplingRate);

    vector<double> timeValues;
    vector<double> signalValues;

    for (int i = 0; i < numSamples; ++i) { // tworzy punkty na podstawie których wykres
        double t = static_cast<double>(i) / samplingRate;
        double amplitude = 2.0 * fmod(t * frequency, 1.0) - 1.0;
        

        timeValues.push_back(t);
        signalValues.push_back(amplitude);
    }

    //Tworzy wykres
    matplot::plot(timeValues, signalValues);
    matplot::title("Sygnał");
    matplot::xlabel("Czas [s]");
    matplot::ylabel("Amplituda");
    matplot::xlim({ 0, duration });
    matplot::ylim({ -1.5, 1.5 });

    matplot::show();
}

int main() {
    double frequency = 2.0; // ile sinusów na sekunde
    double time = 2.0;
    int value;
    printf("Podaj czestotliwosc:");
    cin >> frequency;
    printf("Podaj czas sygnalu:");
    cin >> time;
    printf("Podaj co chcesz wyswietlic sin[1], cos[2], rec[3], saw[4]: ");
    cin >> value;
    switch (value)
    {
    case 1:
        gensin(frequency, time);
        break;
    case 2:
        gencos(frequency, time);
        break;
    case 3:
        genrec(frequency, time);
        break;
    case 4:
        gensaw(frequency, time);
        break;
    default:
        break;
    }
    return 0;
}
