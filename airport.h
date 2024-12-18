/**
 * Author: Jonathan Frank & Carson Tice
 * Date: 2024-12-07
 *
 * This is a collection of utility functions involving
 * and airport structure.
 */

/**
 * Airport structure to organize different aspects of a given array.
 */
typedef struct {
  char *gpsId;
  char *type;
  char *name;
  double latitude;
  double longitude;
  int elevationFeet;
  char *city;
  char *countryAbbrv;
} Airport;

/**
 * A function that generates and prints several reports on the
 * given array of Airport structures.
 */
void generateReports(Airport *airports, int n);

/**
 * Constructs a new string representation of the given
 * Airport structure.
 */
char* airportToString(const Airport* a);

/**
 * Prints all the airports in the given array of n
 * Airports.
 */
void printAirports(Airport *airports, int n);

/**
 * Converts given degrees into radians.
 */
double degToRad(double degrees);

/**
 * Rounds a given variable to the thousandths place.
 */
double roundToHundredth(double n);

/**
 * A factory function to create a new Airport with the given
 * attributes.  This function should make *deep* copies of each
 * of the relevant fields and return a pointer to the newly
 * created Airport structure.
 */
Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv);

/**
 * This function initializes an existing allocated
 * Airport structure with the given attributes.
 */
void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv);

/**
 * cmputes the air distance, in kilometers, between
 * the two Airports using their latitude/longitude
 */
double getAirDistance(const Airport* origin, const Airport* destination);

/**
 * cmputes the estimated travel time (in hours) for a flight
 * that involves the given stops using the average flight speed
 * (kilometers per hour) and average layover time (in hours)
 */
double getEstimatedTravelTime(const Airport* stops,
                              int size,
                              double aveKmsPerHour,
                              double aveLayoverTimeHrs);

/**
 * A comparator function that orders the two Airport structures by
 * their GPS IDs in lexicographic order.
 */
int cmpByGPSId(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * their type.
 */
int cmpByType(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * their name in lexicographic order.
 */
int cmpByName(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * their name in reverse lexicographic order.
 */
int cmpByNameDesc(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * country.
 */
int cmpByCountry(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * city.
 */
int cmpByCity(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures first by
 * country, then by city
 */
int cmpByCountryCity(const void* a, const void* b);

/**
 * A comparator function that orders the given Airport structures
 * by their latitudes north to south
 */
int cmpByLatitude(const void* a, const void* b);

/**
 * A comparator function that orders the given Airport structures
 * by their longitudes west to east
 */
int cmpByLongitude(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * their relative distance from Lincoln Municipal Airport
 * (0R2, 40.846176, -96.75471)
 * in ascending order according (closest to Lincoln would come first)
 */
int cmpByLincolnDistance(const void* a, const void* b);
