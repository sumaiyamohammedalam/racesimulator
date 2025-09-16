#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ---------------- Structures section ----------------
typedef struct Race {
    int numberOfLaps;
    int currentLap;
    char firstPlaceDriverName[50];
    char firstPlaceRaceCarColor[20];
} Race;

typedef struct RaceCar {
    char driverName[50];
    char raceCarColor[20];
    int totalLapTime;
} RaceCar;

// ---------------- Print functions section ----------------
void printIntro() {
    printf("Welcome to our main event digital race fans!\n");
    printf("I hope everybody has their snacks because we are about to begin!\n\n");
}

void printCountDown() {
    printf("Racers Ready! In...\n");
    for (int i = 5; i > 0; i--) {
        printf("%d\n", i);
    }
    printf("Race!\n\n");
}

void printFirstPlaceAfterLap(Race race) {
    printf("After lap number %d\n", race.currentLap);
    printf("First Place Is: %s in the %s race car!\n\n",
           race.firstPlaceDriverName,
           race.firstPlaceRaceCarColor);
}

void printCongratulation(Race race) {
    printf("Let's all congratulate %s in the %s race car for an amazing performance.\n",
           race.firstPlaceDriverName,
           race.firstPlaceRaceCarColor);
    printf("It truly was a great race and everybody have a goodnight!\n");
}

// ---------------- Logic functions section ----------------
int calculateTimeToCompleteLap() {
    int speed = rand() % 3 + 1;        // random 1–3
    int acceleration = rand() % 3 + 1; // random 1–3
    int nerves = rand() % 3 + 1;       // random 1–3
    return speed + acceleration + nerves;
}

void updateRaceCar(RaceCar *raceCar) {
    raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(Race *race, RaceCar *raceCar1, RaceCar *raceCar2) {
    if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
        strcpy(race->firstPlaceDriverName, raceCar1->driverName);
        strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
    } else {
        strcpy(race->firstPlaceDriverName, raceCar2->driverName);
        strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
    }
}

// ---------------- Race simulation ----------------
void startRace(RaceCar *raceCar1, RaceCar *raceCar2) {
    Race race = {5, 1, "", ""}; // numberOfLaps = 5, currentLap = 1

    for (race.currentLap = 1; race.currentLap <= race.numberOfLaps; race.currentLap++) {
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);

        updateFirstPlace(&race, raceCar1, raceCar2);

        printFirstPlaceAfterLap(race);
    }

    printCongratulation(race);
}

// ---------------- main ----------------
int main() {
    srand(time(0)); // seed RNG

    RaceCar raceCar1 = {"George", "yellow", 0};
    RaceCar raceCar2 = {"Cosmo", "orange", 0};

    printIntro();
    printCountDown();
    startRace(&raceCar1, &raceCar2);

    return 0;
}
