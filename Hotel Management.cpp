#include <iostream>
#include <vector>

class Room {
public:
    int roomNumber;
    bool isOccupied;
    double rate;

    Room(int number, double rate) : roomNumber(number), isOccupied(false), rate(rate) {}

    void display() const {
        printf("Room Number: %d, Rate: $%.2f per night, %s\n", roomNumber, rate, isOccupied ? "Occupied" : "Available");
    }
};

class Hotel {
private:
    std::vector<Room> rooms;

public:
    Hotel(int numRooms) {
        for (int i = 1; i <= numRooms; ++i) {
            double rate = 100.0; 
            rooms.push_back(Room(i, rate));
        }
    }

    void displayRooms() const {
        printf("Hotel Rooms:\n");
        for (const Room& room : rooms) {
            room.display();
        }
    }

    void bookRoom(int roomNumber) {
        for (Room& room : rooms) {
            if (room.roomNumber == roomNumber && !room.isOccupied) {
                room.isOccupied = true;
                printf("Room %d booked successfully.\n", roomNumber);
                return;
            }
        }
        printf("Room %d is not available or does not exist.\n", roomNumber);
    }

    void checkoutRoom(int roomNumber) {
        for (Room& room : rooms) {
            if (room.roomNumber == roomNumber && room.isOccupied) {
                room.isOccupied = false;
                printf("Checkout for Room %d completed.\n", roomNumber);
                return;
            }
        }
        printf("Room %d is not occupied or does not exist.\n", roomNumber);
    }
};

int main() {
    Hotel hotel(10); 

    int choice;
    do {
        printf("\nHotel Management System\n");
        printf("1. Display Rooms\n");
        printf("2. Book a Room\n");
        printf("3. Checkout from a Room\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                hotel.displayRooms();
                break;
            case 2: {
                int roomNumber;
                printf("Enter the room number to book: ");
                scanf("%d", &roomNumber);
                hotel.bookRoom(roomNumber);
                break;
            }
            case 3: {
                int roomNumber;
                printf("Enter the room number to checkout: ");
                scanf("%d", &roomNumber);
                hotel.checkoutRoom(roomNumber);
                break;
            }
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
