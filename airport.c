/**
 * Author: Jonathan Frank & Carson Tice
 * Date: 2024-12-07
 *
 * Holds the logic and functions to create and organize Airport structures.
 */
#include <stdlib.h>
#include <stdio.h>

#include "airport.h"

void generateReports(Airport *airports, int n) {

  printf("Airports (original): \n");
  printf("==============================\n");
  printAirports(airports, n);

  printf("\nAirports By GPS ID: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByGPSId);
  printAirports(airports, n);

  printf("\nAirports By Type: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByType);
  printAirports(airports, n);

  printf("\nAirports By Name: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByName);
  printAirports(airports, n);

  printf("\nAirports By Name - Reversed: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByNameDesc);
  printAirports(airports, n);

  printf("\nAirports By Country/City: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByCountryCity);
  printAirports(airports, n);

  printf("\nAirports By Latitude: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLatitude);
  printAirports(airports, n);

  printf("\nAirports By Longitude: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLongitude);
  printAirports(airports, n);

  printf("\nAirports By Distance from Lincoln: \n");
  printf("==============================\n");
  qsort(airports, n, sizeof(Airport), cmpByLincolnDistance);
  printAirports(airports, n);

  printf("\nClosest Airport to Lincoln: \n");
  printf("==============================\n");

  printf("\nFurthest Airport from Lincoln: \n");
  printf("==============================\n");

  printf("\nEast-West Geographic Center: \n");
  printf("==============================\n");

  printf("\nNew York, NY airport: \n");
  printf("==============================\n");
  //if none found, print: "No New York airport found!\n"

  printf("\nLarge airport: \n");
  printf("==============================\n");
  //if none found, print: "No large airport found!\n"

  return;
}

char* airportToString(const Airport* a) {
  char temp[1000];
  //this formatting is required but the code may need to be adapted
  // to your definiion of your Airport structure.
  sprintf(temp, "%-8s %-15s %-20s %.2f %.2f %d %-10s %-2s", a->gpsId, a->type, a->name,
          a->latitude, a->longitude, a->elevationFeet, a->city,
          a->countryAbbrv);
  char* result = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
  strcpy(result, temp);
  return result;
}

void printAirports(Airport *airports, int n) {

  for(int i=0; i<n; i++) {
    char *s = airportToString(&airports[i]);
    printf("%s\n", s);
    free(s);
  }

  return;
}

double degToRad(double degrees) {
    double radians = (degrees / 180) * M_PI;
    return radians;
}

double roundToHundredth(double n) {
    double rounded = (round(n * 100)) / 100;
    return rounded;
}

Airport* createAirport(const char* gpsId, const char* type, const char* name, double latitude, double longitude, int elevationFeet, const char* city, const char* countryAbbrv) {
    Airport *airport = malloc(sizeof(Airport));
    char* gpsIdCopy = strdup(gpsId);
    char* typeCopy = strdup(type);
    char* nameCopy = strdup(name);
    char* cityCopy = strdup(city);
    char* countryAbbrvCopy = strdup(countryAbbrv);
    double latitudeCopy = latitude;
    double longitudeCopy = longitude;
    int elevationFeetCopy = elevationFeet;
    airport->gpsId = gpsIdCopy;
    airport->type = typeCopy;
    airport->name = nameCopy;
    airport->city = cityCopy;
    airport->countryAbbrv = countryAbbrvCopy;
    airport->latitude = latitudeCopy;
    airport->longitude = longitudeCopy;
    airport->elevationFeet = elevationFeetCopy;
    return airport;
}

void initAirport(Airport* airport, const char* gpsId, const char* type, const char* name, double latitude, double longitude, int elevationFeet, const char* city, const char* countryAbbrv) {
    if(airport == NULL) {
        return;
    }
    airport->gpsId = strdup(gpsId);
    airport->type = strdup(type);
    airport->name = strdup(name);
    airport->city = strdup(city);
    airport->countryAbbrv = strdup(countryAbbrv);
    airport->latitude = latitude;
    airport->longitude = longitude;
    airport->elevationFeet = elevationFeet;
}

double getAirDistance(const Airport* origin, const Airport* destination) {
    if(origin->latitude > 90 || origin->latitude < -90 || origin->longitude > 180 || origin->longitude < -180){
        return 1;
    }
    if(destination->latitude > 90 || destination->latitude < -90 || destination->longitude > 180 || destination->longitude < -180){
        return 2;
    }
    int earthRadius = 6371;
    double LatitudeA = degToRad(origin->latitude);
    double LongitudeA = degToRad(origin->longitude);
    double LatitudeB = degToRad(destination->latitude);
    double LongitudeB = degToRad(destination->longitude);
    double airDistance = acos((sin(LatitudeA) * sin(LatitudeB)) + (cos(LatitudeA) * cos(LatitudeB) * cos(LongitudeB - LongitudeA))) * earthRadius;
    return airDistance;
}

double getEstimatedTravelTime(const Airport* stops, int size, double aveKmsPerHour, double aveLayoverTimeHrs) {
    double travelTime = 0.0;
    for (int i = 1; i < size; i++) {
        travelTime += getAirDistance(&stops[i - 1], &stops[i]) / aveKmsPerHour;
        if (i < size - 1) {
            travelTime += aveLayoverTimeHrs;
        }
    }
    return travelTime;
}

int cmpByGPSId(const void* a, const void* b){
    const Airport *x = (const Airport*) a;
    const Airport *y = (const Airport*) b;
    return strcmp(x->gpsId, y->gpsId);
}

int cmpByType(const void* a, const void* b){
    const Airport *x = (const Airport*) a;
    const Airport *y = (const Airport*) b;
    return strcmp(x->type, y->type);
}

int cmpByName(const void* a, const void* b){
    const Airport *x = (const Airport*) a;
    const Airport *y = (const Airport*) b;
    return strcmp(x->name, y->name);
}

int cmpByNameDesc(const void* a, const void* b){
    const Airport *x = (const Airport*) a;
    const Airport *y = (const Airport*) b;
    return strcmp(y->name, x->name);
}

int cmpByCountry(const void* a, const void* b){
    const Airport *x = (const Airport*) a;
    const Airport *y = (const Airport*) b;
    return strcmp(x->countryAbbrv, x->countryAbbrv);
}

int cmpByCity(const void*a, const void* b){
    const Airport *x = (const Airport*) a;
    const Airport *y = (const Airport*) b;
    return strcmp(x->city, x->city);
}

int cmpByCountryCity(const void* a, const void* b){
  int result = cmpByCountry(a, b);
  if(result == 0) {
    int result = cmpByCity(a, b);
  }
  return result;
}

int cmpByLatitude(const void* a, const void* b) {
    const Airport *x = (const Airport*) a;
    const Airport *y = (const Airport*) b;
    if(x->latitude > y->latitude) {
      return -1;
    } if(x->latitude < y->latitude) {
      return 1;
    }
    return 0;
}

int cmpByLongitude(const void* a, const void* b) {
    const Airport *x = (const Airport*) a;
    const Airport *y = (const Airport*) b;
    if(x->longitude < y->longitude) {
      return -1;
    } if(x->longitude > y->longitude) {
      return 1;
    }
    return 0;
}

int cmpByLincolnDistance(const void* a, const void* b) {
    const double lincolnLatitude = 40.846176;
    const double lincolnLongitude = -96.75471;
    const Airport *x = (const Airport*) a;
    const Airport *y = (const Airport*) b;
    Airport lincolnAirport;
    initAirport(&lincolnAirport, "0R2", "", "", lincolnLatitude, lincolnLongitude, 0, "", "");
    double distanceX = getAirDistance(&lincolnAirport, x);
    double distanceY = getAirDistance(&lincolnAirport, y);
    if(distanceX < distanceY) {
      return -1;
    } if(distanceX > distanceY) {
      return 1;
    }
    return 0;
}
