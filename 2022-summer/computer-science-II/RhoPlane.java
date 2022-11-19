// Soobin Rho
// Problem 6.19 | Public RhoPlane
// July 14, 2022
import java.util.Scanner;

public class RhoPlane {
    /*
     * 1. The plane has 10 seats.
     * 2. Please type 1 for First Class.
     *    Please type 2 for Economy.
     * 3. Seats 1-5 for First Class
     *    Seats 6-10 for Economy.
     * 4. If First Class / Economy is full,
     *    ask if it's acceptable to be
     *    placed in the other section.
     * 5. Print Next flight leaves in
     *    3 hours if no.
     * 6. Display the boarding pass with
     *    the seat number and seat type.
     *
    */

    // 1. The plane has 10 seats.
    public static final int NUMSEATS = 10;
    public static boolean[] arrayAssigned = new boolean[NUMSEATS];
    public static SeatType[] arrayType = new SeatType[NUMSEATS];
    private enum SeatType {FIRSTCLASS, ECONOMY};

    public static void main(String[] args) {

        // Uncomment for debugging.
        // arrayType[0] = SeatType.ECONOMY;
        // System.out.printf(
        //     "e.g. SeatType[0]: " + arrayType[0],
        //     "%n"
        // );

        boolean isDone = false;
        while (isDone == false) {

            // 2. Please type 1 for First Class.
            //    Please type 2 for Economy.
            Scanner userInput = new Scanner(System.in);
            System.out.printf(
                "Please type 1 for the First Class, " +
                "2 for the Economy, or " +
                "q to end the program.%n" +
                "Enter: "
            );
            String menu = userInput.nextLine();

            // First Class
            if(menu.equals("1")) {

                // Check if any seat is available.
                boolean isAvailable = false;
                SeatType chosenType = SeatType.FIRSTCLASS;
                int availableSeat = getAvailableSeat(chosenType);

                if (availableSeat != -1) {
                    isAvailable = true;
                }

                // 6. Display the boarding pass with
                //    the seat number and seat type.
                if (isAvailable == true) {
                    System.out.printf(
                        "%nBOARDING PASS%nSeat No %d, %s%n%n",
                        availableSeat,
                        arrayType[availableSeat - 1]
                    );
                }

                else if (isAvailable == false) {

                    // 4. If First Class / Economy is full,
                    //    ask if it's acceptable to be
                    //    placed in the other section.
                    System.out.printf(
                        "%nAll First Class seats are taken.%n" +
                        "(c)hange to Economy or " +
                        "(w)ait for the next flight: "
                    );
                    menu = userInput.nextLine();

                    if (menu.equals("c")) {

                        // Check if any seat is available.
                        isAvailable = false;
                        chosenType = SeatType.ECONOMY;
                        availableSeat = getAvailableSeat(chosenType);

                        if (availableSeat != -1) {
                            isAvailable = true;
                        }

                        // 6. Display the boarding pass with
                        //    the seat number and seat type.
                        if (isAvailable == true) {
                            System.out.printf(
                                "%nBOARDING PASS%nSeat No %d, %s%n%n",
                                availableSeat,
                                arrayType[availableSeat - 1]
                            );
                        }

                        // If all the seats are taken.
                        else {
                            System.out.printf(
                                "Sorry! All seats are taken.%n%n"
                            );
                        }

                    }

                    // 5. Print Next flight leaves in
                    //    3 hours if no.
                    else {
                        System.out.printf(
                            "Sorry about that! " +
                            "The next flight " +
                            "leaves in 3 hours.%n%n"
                        );
                    }

                }

            }

            // Economy Class
            if(menu.equals("2")) {

                // Check if any seat is available.
                boolean isAvailable = false;
                SeatType chosenType = SeatType.ECONOMY;
                int availableSeat = getAvailableSeat(chosenType);

                if (availableSeat != -1) {
                    isAvailable = true;
                }

                // 6. Display the boarding pass with
                //    the seat number and seat type.
                if (isAvailable == true) {
                    System.out.printf(
                        "%nBOARDING PASS%nSeat No %d, %s%n%n",
                        availableSeat,
                        arrayType[availableSeat - 1]
                    );
                }

                else if (isAvailable == false) {

                    // 4. If First Class / Economy is full,
                    //    ask if it's acceptable to be
                    //    placed in the other section.
                    System.out.printf(
                        "%nAll Economy seats are taken.%n" +
                        "(c)hange to First Class or " +
                        "(w)ait for the next flight: "
                    );
                    menu = userInput.nextLine();

                    if (menu.equals("c")) {

                        // Check if any seat is available.
                        isAvailable = false;
                        chosenType = SeatType.FIRSTCLASS;
                        availableSeat = getAvailableSeat(chosenType);

                        if (availableSeat != -1) {
                            isAvailable = true;
                        }

                        // 6. Display the boarding pass with
                        //    the seat number and seat type.
                        if (isAvailable == true) {
                            System.out.printf(
                                "%nBOARDING PASS%nSeat No %d, %s%n%n",
                                availableSeat,
                                arrayType[availableSeat - 1]
                            );
                        }

                        // If all the seats are taken.
                        else {
                            System.out.printf(
                                "Sorry! All seats are taken.%n%n"
                            );
                        }

                    }

                    // 5. Print Next flight leaves in
                    //    3 hours if no.
                    else {
                        System.out.printf(
                            "Sorry about that! " +
                            "The next flight " +
                            "leaves in 3 hours.%n%n"
                        );
                    }

                }

            }

            // Quit.
            else if(menu.equals("q")) {
                isDone = true;
            }

        }

    }

    public static int getAvailableSeat(SeatType chosenType) {

        // Check if any seat is available.
        boolean isAvailable = true;
        int availableSeat = -1;
        int rangeStart = 0;
        int rangeEnd = 0;

        // 3. Seats 1-5 for First Class
        //    Seats 6-10 for Economy.
        if (chosenType == SeatType.FIRSTCLASS) {
            rangeStart = 0;
            rangeEnd = 4;
        }
        else if (chosenType == SeatType.ECONOMY) {
            rangeStart = 5;
            rangeEnd = 9;
        }

        for (int count = rangeStart; count < rangeEnd; count++) {

            if (arrayAssigned[count] == true) {
                isAvailable = false;
            }
            else if (availableSeat == -1) {
                isAvailable = true;
                availableSeat = count + 1;
                arrayAssigned[count] = true;
                arrayType[count] = chosenType;
            }

            // Uncomment for debugging.
            // System.out.println(
            //     "Seat index " +
            //     count +
            //     " : " +
            //     arrayAssigned[count] +
            //     " " +
            //     arrayType[count]
            // );
        }

        return availableSeat;

    }

}

