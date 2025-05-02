#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Parcel {
    int id;
    int priority;
};

Parcel parcels[MAX_SIZE];
int parcelCount = 0; 

void insertParcelArray(Parcel newParcel) 
{
    if (parcelCount >= MAX) 
    {
        cout << "Parcel array is full!" << endl;
        return;
    }

    int i = parcelCount - 1;
    while (i >= 0 && parcelArray[i].priority > newParcel.priority) 
    {
        parcelArray[i + 1] = parcelArray[i]; // Shift right
        i--;
    }
    parcelArray[i + 1] = newParcel;
    parcelCount++;
}

void displayParcelArray() 
{
    if (parcelCount == 0) 
    {
        cout << "No parcels to display!" << endl;
        return;
    }

    cout << "Parcels in Priority Order (Array):\n";
    for (int i = 0; i < parcelCount; i++) 
    {
        cout << "Parcel ID: " << parcelArray[i].id << ", Priority: " << parcelArray[i].priority << endl;
    }
}

int main() 
{
    Parcel p1 = {201, 2};
    Parcel p2 = {202, 1};
    Parcel p3 = {203, 3};
    Parcel p4 = {204, 1};

    insertParcelArray(p1);
    insertParcelArray(p2);
    insertParcelArray(p3);
    insertParcelArray(p4);

    displayParcelArray();

    return 0;
}
