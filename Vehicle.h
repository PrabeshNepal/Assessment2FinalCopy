#pragma once // or use #ifndef/#define guards

class Vehicle {
private:
    int vehicleId = 0;           // Unique ID for the vehicle
    
    int destinationId = 0;        // ID representing the destination city
    int capacityRange = 0;      // Maximum range the vehicle can cover (e.g., in kilometers)
    int remainingRange = 0;     // Remaining range based on fuel or charge
    

public:
    int currentCityId = 0;        // ID representing the current city
    //int f_city = 0;
   // ChargingStation ch;
    // Constructor
    Vehicle(int vId, int destId, int capRange, int remRange);

    // Getters and Setters
    
    Vehicle() {};
      int getVehicleId() const;
    int getCurrentCityId() const;
    int getDestinationId() const;
    int getCapacityRange() const;
    int getRemainingRange() const;

    void setVehicleId(int vId);
    void setCurrentCityId(int currCityId);
    void setDestinationId(int destId);
    void setCapacityRange(int capRange);
    void setRemainingRange(int remRange);

    // Additional methods
    void displayVehicleInfo() const;
    bool canReachDestination(int rr, int dd) const; // Check if vehicle can reach its destination
    
 
    static int farCity(int rem);
    
  

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);  // Declaration


};
