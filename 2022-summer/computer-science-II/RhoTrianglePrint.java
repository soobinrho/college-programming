// Soobin Rho
// Problem 4.15 | Public RhoTrianglePrint
// July 10, 2022

public class RhoTrianglePrint {
    /*
     * 1. (a)
     * 2. (b)
     * 3. (c)
     * 4. (d)
    */
    public static void main(String[] args) {

        // 1. (a)
        for (int count = 1; count < 11; count++) {
            for (int count2 = 0; count2 < count; count2++) {
                System.out.print("*");
            }
            System.out.println();
        }

        // 2. (b)
        for (int count = 1; count < 11; count++) {
            for (int count2 = 11; count2 > count; count2--) {
                System.out.print("*");
            }
            System.out.println();
        }


        // 3. (c)
        for (int count = 1; count < 11; count++) {
            for (int count3 = count; count3 > 1; count3--) {
                System.out.print(" ");
            }
            for (int count2 = 11; count2 > count; count2--) {
                System.out.print("*");
            }
            System.out.println();
        }

        // 4. (d)
        for (int count = 1; count < 11; count++) {
            for (int count3 = 10; count3 > count; count3--) {
                System.out.print(" ");
            }
            for (int count2 = 0; count2 < count; count2++) {
                System.out.print("*");
            }
            System.out.println();
        }

    } // End of method main
} // End of class RhoTrianglePrint

