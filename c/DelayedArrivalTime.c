#include <stdio.h>

int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
    return (arrivalTime + delayedTime) % 24;
}

void output(int arrivalTime, int delayedTime) {
    printf("Arrival time %02d:00 delayed by %d hours = %02d:00 - real arrival time\n", arrivalTime, delayedTime, findDelayedArrivalTime(arrivalTime, delayedTime));
}

int main() {
    output(15, 5);
    output(13, 11);
    return 0;
}