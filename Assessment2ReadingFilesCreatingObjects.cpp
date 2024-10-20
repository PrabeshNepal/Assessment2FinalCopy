// Assessment2ReadingFilesCreatingObjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


using namespace std;
#include <vector>
#include <string>
#include <iostream>  // For std::cout
#include <fstream>   // For file input/output operations
#include "Vehicle.h" // Custom class for Vehicle objects
#include "Constant.h" // Custom class for Vehicle objects
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

#include <iomanip>   // for setw:



// ---------------------------------------------------------------------------------------------------------------------  //
// Task 1


class ChargingStation {
public:
    int cityId = 1;
    string cityName = "Sydney";            // Declare string and initialize it 
    int distanceToLastCity = 1;
    int numberOfChargers = 1;
    int distance_to_syd = 0;
    // Constructor to initialize city details
    ChargingStation() {};
    ChargingStation(int Stationid) {
        if (Stationid >= 0 && Stationid < NUM_CITIES) {
            cityId = Stationid;
            cityName = nameMap[Stationid];  // Correctly reference nameMap from Constant.h
            distanceToLastCity = distanceMap[Stationid];
            numberOfChargers = chargersMap[Stationid];
            

        }
        else {
            // Handle invalid city ID
            cout << "Invalid City ID!" << endl;
        }
    }
    // Display city information
    void displayCityID() const {
        cout << "City ID: " << cityId << endl;
    }
    void displayDistanceToLastCity() const {
        cout << "Distance to Last City: " << distanceToLastCity << " km" << endl;
    }
    void displayNumberOfChargers() const {
        cout << "Number of Chargers: " << numberOfChargers << endl;
    }
    void displayCityName() const {
        cout << "City Name: " << cityName << endl;
    }
    

    
    // Task 3
    static int displayDistanceToSydney(int cityid_temp) {
        //cityid_temp;
        int distance_to_syd = 0;
        int current_cityId = 0;
        for (int i = current_cityId; i <= cityid_temp; i++) {
            distance_to_syd += distanceMap[i];
        }
        //cout << distance_to_syd;
        return distance_to_syd;
    }

    static double averageWaitingTime(int temp_charger[]) {
        double half = 0.5;
        int hour = 1;

        

        for (int i = 0; i < 12; i++) {
            double avgWait = 0.5 * hour * ((temp_charger[i]) / chargersMap[i]);
            //double avgWait = temp_charger[i];
            cout << setw(20)<< "avg wait time for " << nameMap[i] << " is " << static_cast<double>(avgWait)<< " Hours" << endl;
        }

        
        return 1.0;


    }


};
// ---------------------------------------------------------------------------------------------------------------------  //


// ---------------------------------------------------------------------------------------------------------------------  //
// Task 2
Vehicle::Vehicle(int vId, int destId, int capRange, int remRange) : vehicleId(vId), destinationId(destId), capacityRange(capRange), remainingRange(remRange) {}// constructor

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle) {
    os << "[" << vehicle.vehicleId << "," << vehicle.destinationId << "," << vehicle.capacityRange << "," << vehicle.remainingRange << "]" << endl;
    return os;  // Return the output stream
}





int Vehicle::getVehicleId() const { return vehicleId; }
int Vehicle::getCurrentCityId() const { return currentCityId; }
int Vehicle::getDestinationId() const { return destinationId; }
int Vehicle::getCapacityRange() const { return capacityRange; }
int Vehicle::getRemainingRange() const { return remainingRange; }

// Setters
void Vehicle::setVehicleId(int vId) { vehicleId = vId; }
void Vehicle::setCurrentCityId(int currCityId) { currentCityId = currCityId; }
void Vehicle::setDestinationId(int destId) { destinationId = destId; }
void Vehicle::setCapacityRange(int capRange) { capacityRange = capRange; }
void Vehicle::setRemainingRange(int remRange) { remainingRange = remRange; }

// Display vehicle information
void Vehicle::displayVehicleInfo() const {

    cout << "[" << vehicleId << "," << destinationId << "," << capacityRange << "," << remainingRange << "]" << "endl";
}

bool Vehicle::canReachDestination(int dei, int farc) const{
    // assumes all cars start from sydney doesnt work with recharged cars
    const int arr[12] = { 0, 57, 117, 200, 286, 385, 500, 562, 636, 723, 829, 891 };
    //int destination_length = arr[destinationdistance];
    if (farc >= dei) {
        return true;
    }
    else {
        return false;
    }
}

int Vehicle::farCity(int rem) {
   
    int current_city_id = 0;
    int fd_city = 0;
    // assumes all cars start from sydney doesnt work with recharged cars
    const int arr[12] = { 0, 57, 117, 200, 286, 385, 500, 562, 636, 723, 829, 891 };

    for (int i = 0; i < 12; i++)
    {
        if (rem > arr[i])
        {
            fd_city = i;
        }
        else if(rem == arr[i])
        {
            fd_city = i;
            break;
        }
        else
        {
            fd_city = i-1;
            break;
        }
        
    }
    return fd_city;
    //cout << fd_city;
}


// ---------------------------------------------------------------------------------------------------------------------  //

// ---------------------------------------------------------------------------------------------------------------------  //
// Task 3
const int SIZE_OF_DEMAND = 200;
class DemandGenerator {
public:
    ofstream fout;
    

    void outputFunction() 
    {
        std::srand(static_cast<unsigned>(std::time(0)));
        fout.open("GeneratedDemands.txt");
        if (fout.fail()) {
            cout << "Demand Generator File Output Failed: " << endl;
            exit(1);
        }
        //int r = rand() % 10;
        cout << "Generated EV DEMANDS: " << endl;
        
        for (int i = 0; i < SIZE_OF_DEMAND; i++)
        {
            int vehicleId = i + 200;
            int destinationId = rand() % 13;
            int capacityRange = (rand() % 201) + 350;
            int remainRange = 300 + std::rand() % (capacityRange - 300 + 1);

            //int remansssssRange = 300 + std::rand() % (capacityRange - 300 + 1);

            fout << '[' << vehicleId << ','<<destinationId<<','<<capacityRange<<','<<remainRange<<']'<<endl;
            // outputs to console but we dont need it right now since the output and other stuff will be handled in the main section.
           // cout << '[' << vehicleId << ',' << destinationId << ',' << capacityRange << ',' << remainRange << ']' << endl;
        }
        fout.close();

    }
    
};





int main()
{
    DemandGenerator g;
    ChargingStation c;
    // this shows the distance to sydney from a cityid 
    //ChargingStation::displayDistanceToSydney(12);

    // storing value of distance to syd test
    //int sdf = ChargingStation::displayDistanceToSydney(3);
    //cout << "sdf: " << sdf << endl;
    g.outputFunction();
    Vehicle v;
 
    cout << endl;
    ifstream infile;
    
    infile.open("GeneratedDemands.txt");
    if (infile.fail()) {
        cout << "This file could not be opened";
        exit(1);
    }

    //std::cout << "Hello World!\n";
    vector<Vehicle> demands;
    vector<Vehicle> firstchargeDemands;
    while (!infile.eof()) 
    {
        char c;
        infile >> c;
        if (c == '[') 
        {
            int values[4];
            for (int i = 0; i < 4; i++) 
            {
                infile >> values[i];
                infile >> c;
                //currentCityId = 0;
            }
            if (c != ']') 
            {
                cout << "Problem of reading file" << endl;
                break;
            }
            Vehicle demand(values[0], values[1], values[2], values[3]);
            //demand.setLatestCharging();
            demands.push_back(demand);
        }
    }
    // works with 156 as limit for charging demands
    //cout << "Vehicle ID               Destination ID               Capacity Range               Remaining Range" << endl;
    
    // outputs the vehicle stuff in format
    int que[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < SIZE_OF_DEMAND; i++)
    {
        cout << demands[i];
        cout << "Vehicle ID: " << demands[i].getVehicleId() << endl;
        cout << "Destination ID: " << demands[i].getDestinationId() << endl;
        cout << "Capacity Range: " << demands[i].getCapacityRange() << endl;
        cout << "Remaining Range: " << demands[i].getRemainingRange() << endl;
        //cout << "Current City Id " << currentCityId;

        int destination = demands[i].getDestinationId();
        int remains = demands[i].getRemainingRange();
        cout << "farthest city can travel: " << Vehicle::farCity(remains)  << endl;
        int farcityNum = Vehicle::farCity(remains);

       // v.canReachDestination(destination, remains);
        if (v.canReachDestination(destination, farcityNum) == true) {
            cout << "Reached Destination? YES" << endl << endl;
        }
        else {
            cout << "Reached Destination? NO" << endl;
            cout << "This EV is queing in city: " << farcityNum << endl<<endl;
            que[farcityNum]++;

        }

        // previous code to check wether the car reaches destination before having to recharge.
        //if (farcityNum >= destination) {
        //    cout << "Reached Destination? YES" << endl << endl;
        //}
        //else {
        //    cout << "Reached Destination? NO" << endl << endl;
        //}
        //Vehicle::furthest_city(demands[i].getRemainingRange);
    }
    int temp_charger[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
    for (int i = 0; i < 12; i++) {
        std::cout << std::setw(15) << nameMap[i] << ": " << que[i] << endl; // Use nameMap[i] for charger names
        temp_charger[i] = que[i];
        //cout << "TTTTTTTTTTTTTT: "<< temp_charger[i] << endl;
    }
    cout << endl;

    c.averageWaitingTime(temp_charger);
    
    
    /*
    ifstream firstcharge;
    firstcharge.open("1stChargeEVs.txt");
    for (int i = 0; i < SIZE_OF_DEMAND; i++)
    {
        int destination = demands[i].getDestinationId();
        int remains = demands[i].getRemainingRange();
        int farcityNum = Vehicle::farCity(remains);

        if (v.canReachDestination(destination, farcityNum) == true) {
            continue;
        }
        else {
            
        }
        //cout << demands[i];
       
    }
    firstcharge.close();*/
    infile.close();

   // g.outputFunction();



    
    /*
    * // Already implemented in the above for loop to display furthest distance an ev can go with current remaining range
    int rr = 117;
    cout << "very far city " << Vehicle::farCity(rr) << endl;
    */
    
 
}

