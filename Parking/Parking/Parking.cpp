// Parking.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include<random>
#include<map>
#include<iostream>
#include<list>
using namespace std;
class Location
{
public:
    int lane;
    int row;
    int floor;
    pair<double, double>loc;
    Location() {}
    Location(pair<double, double> loc) :loc(loc){}
    Location(int l, int r, int f) :lane(l), row(r), floor(f) {}
};
class Vehcile
{
public:
    Vehcile(string s = "car") :name(s) {};
    ~Vehcile() {};
    string name;
    int type;
    int building;
};
class Slot
{
public:
    int type;
    bool Occupied;
    Location loc;
    Vehcile* vehcile;
    Slot() {}
    Slot(Location loc) :loc(loc), Occupied(false) {}
    bool isOccupied() { return Occupied; }
    Location getLocation() { return loc; }
    void park(Vehcile* v) { vehcile = v; Occupied = true; }
    Vehcile* unpark() { Occupied = false; return vehcile; }
    bool operator=(Slot &s)
    {
        return  this->loc.floor == s.loc.floor
            && this->loc.lane == s.loc.lane
            && this->loc.row == s.loc.row;
         ;
    }
    long hashCode() { return rand(); }
};
class ParkingLot
{
public:
    ~ParkingLot() {};
    static const int numberOFSlotBuildingA = 100;
    static const int numberOFSlotBuildingB = 100;
    static const int numberOFSlotBuildingC = 100;
    map<long, Slot*>  occupiedSlot;// = new map<long, Slot>();
    list<Slot>* BuildingASlots;
    list<Slot>* BuildingBSlots;
    list<Slot>* BuildingCSlots;
    vector<list<Slot>*> allLocation;
    vector<int, std::pair<int, int>>* idgeoloc;
    void createSlots()
    {
        int counterToSlot = 0;
        for (int i = 1, j = 1, k = 1; i < numberOFSlotBuildingA; i++, j++, k++)
        {
            Location *l = new Location((*idgeoloc)[counterToSlot++]);
            BuildingASlots->push_back(*l);
        }

        for (int i = 1, j = 1, k = 1; i < numberOFSlotBuildingB; i++, j++, k++)
        {
            Location *l = new Location((*idgeoloc)[counterToSlot++]);
            BuildingBSlots->push_back(*l);
        }

        for (int i = 1, j = 1, k = 1; i < numberOFSlotBuildingC; i++, j++, k++)
        {
            Location *l = new Location((*idgeoloc)[counterToSlot++]);
            BuildingCSlots->push_back(*l);
        }
        allLocation.push_back(BuildingASlots);
        allLocation.push_back(BuildingBSlots);
        allLocation.push_back(BuildingCSlots);
    }
    ParkingLot() {
        BuildingASlots = new list<Slot>(numberOFSlotBuildingA);
        BuildingBSlots = new list<Slot>(numberOFSlotBuildingB);
        BuildingCSlots = new list<Slot>(numberOFSlotBuildingC);
       idgeoloc = new vector<int, std::pair<int, int>>(totalParkingSpace);
        FILE* fp = fopen("loc.txt", "r");
        if (NULL != fp)
        {
            int id;
            double lat, longt;
            while (fscanf(fp, "%d %f %f", &id, &lat, &longt))
            {
                (*idgeoloc)[id] = std::make_pair(lat, longt);
            }
        }
        createSlots();
    }
    Slot* getFirstEmptySlot(list<Slot>* List)
    {
        for (auto& s : *List)
        {
            if (s.Occupied == false)
                return &s;
        }
        return NULL;
    }
    long park(Vehcile* vehcile)
    {
        Slot* slot = NULL;
        long uniqueToken = -1;
        for (int i = 0; i < 3; i++)
        {
            list<Slot>*List = allLocation[(i + vehcile->building) % 3];
            slot = getFirstEmptySlot(List);
            if (NULL != slot) break;
        }
        if (NULL != slot)
        {
            slot->park(vehcile);
            long ret = slot->hashCode();
            occupiedSlot[ret] = slot;
            cout << "parked at [ "<<slot->loc.loc.first<< " , "<<slot->loc.loc.second<<" ]" << endl;
            return ret;
        }
        cout << "No empty slot found!!!!" << endl;
        return 0;
    }
    Vehcile*  unpark(long ticket)
    {
        if (ticket <= 0 && ticket > 100000/*max value take counter*/)
        {
            return NULL;
        }
        Slot *slot = occupiedSlot[ticket];
    cout << "Unparked from [ "<<slot->loc.loc.first<< " , "<<slot->loc.loc.second<<" ]" << endl;
        return slot->unpark();


    }
};
enum class building { buildingA, buildingB, buildingC };
int totalParkingSpace = 300;
int main()
{
    ParkingLot p;
    Vehcile v,v2,v3;
    v.building = 1;
    long loc = p.park(&v);
    p.unpark(loc);
    system("pause");
    return 0;
}

