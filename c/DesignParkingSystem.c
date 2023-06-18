#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int big_capacity, big_count;
    int medium_capacity, medium_count;
    int small_capacity, small_count;
} ParkingSystem;

ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem *ps = malloc(sizeof(ParkingSystem));
    ps->big_capacity = big;
    ps->medium_capacity = medium;
    ps->small_capacity = small;
    ps->big_count = 0;
    ps->medium_count = 0;
    ps->small_count = 0;
    return ps;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    switch(carType) {
    case 1:
        obj->big_count += 1;
        if (obj->big_capacity < obj->big_count) {
            return false;
        }
        break;
    case 2:
        obj->medium_count += 1;
        if (obj->medium_capacity < obj->medium_count) {
            return false;
        }
        break;
    case 3:
        obj->small_count += 1;
        if (obj->small_capacity < obj->small_count) {
            return false;
        }
        break;
    }
    return true;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}

int main() {
    ParkingSystem* obj = parkingSystemCreate(1, 1, 0);
    printf("can a big car occupy a car slot? - %s\n", parkingSystemAddCar(obj, 1) ? "yes" : "no");
    printf("can a medium car occupy a car slot? - %s\n", parkingSystemAddCar(obj, 2) ? "yes" : "no");
    printf("can a small car occupy a car slot? - %s\n", parkingSystemAddCar(obj, 3) ? "yes" : "no");
    printf("can another big car occupy a car slot? - %s\n", parkingSystemAddCar(obj, 1) ? "yes" : "no");
    parkingSystemFree(obj);
    return 0;
}