//PROJECT : FLIGHT RESERVATION SYSTEM
// NAME : WAHAJ ALI

#include <iostream>
#include <string>

const int MAX_FLIGHTS = 10;
const int MAX_SEATS_PER_FLIGHT = 10;

// Function prototypes
void displayMenu();
void reserveSeat(int flights[][MAX_SEATS_PER_FLIGHT]);
void displaySeats(int flights[][MAX_SEATS_PER_FLIGHT]);

int main() {
    int flights[MAX_FLIGHTS][MAX_SEATS_PER_FLIGHT] = {0}; // Initialize all seats to 0 (empty)

    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                reserveSeat(flights);
                break;
            case 2:
                displaySeats(flights);
                break;
            case 3:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

void displayMenu() {
    std::cout << "\nFLIGHT RESERVATION SYSTEM\n";
    std::cout << "1. Reserve a seat\n";
    std::cout << "2. Display available seats\n";
    std::cout << "3. Exit\n";
}

void reserveSeat(int flights[][MAX_SEATS_PER_FLIGHT]) {
    int flightNumber, seatNumber;

    std::cout << "Enter flight number (0-" << MAX_FLIGHTS - 1 << "): ";
    std::cin >> flightNumber;
    if (flightNumber < 0 || flightNumber >= MAX_FLIGHTS) {
        std::cout << "Invalid flight number.\n";
        return;
    }

    std::cout << "Enter seat number (1-" << MAX_SEATS_PER_FLIGHT << "): ";
    std::cin >> seatNumber;
    if (seatNumber < 1 || seatNumber > MAX_SEATS_PER_FLIGHT) {
        std::cout << "Invalid seat number.\n";
        return;
    }

    if (flights[flightNumber][seatNumber - 1] == 0) {
        flights[flightNumber][seatNumber - 1] = 1;
        std::cout << "Seat reserved successfully.\n";
    } else {
        std::cout << "Seat already reserved.\n";
    }
}

void displaySeats(int flights[][MAX_SEATS_PER_FLIGHT]) {
    std::cout << "Available seats:\n";
    for (int i = 0; i < MAX_FLIGHTS; ++i) {
        std::cout << "Flight " << i << ":\t";
        for (int j = 0; j < MAX_SEATS_PER_FLIGHT; ++j) {
            if (flights[i][j] == 0) {
                std::cout << j + 1 << " ";
            }
        }
        std::cout << "\n";
    }
}
