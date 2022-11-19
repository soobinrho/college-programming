// COSC 211
// Soobin Rho
// July 18, 2022
import java.util.Scanner;

public class RhoEmployeeTest {
    /*
     * Testing class RhoEmployee.
    */
    public static void main(String[] args) {

        // 1. Has three instance variables,
        //    has a constructor for them, and
        //    has a setter and getter for them:
        //
        //        String firstName
        //        String lastName
        //        double monthlySalary
        //
        RhoEmployee goodEmployee = new RhoEmployee(
            "Bean",
            "Soup",
            60000
        );
        System.out.println(goodEmployee);

        // 2. Create two employees and display
        //    each one's yearly salary.
        RhoEmployee niceEmployee = new RhoEmployee(
            "Chicken",
            "Noodle",
            55000
        );
        RhoEmployee coolEmployee = new RhoEmployee(
            "Mushroom",
            "Risotto",
            40000
        );
        System.out.println(niceEmployee);
        System.out.println(coolEmployee);

        // 3. Give each one a 10% raise.
        //    Display their yearly salary again.

        // niceEmployee
        double newMonthlySalary = niceEmployee.getMonthlySalary();
        newMonthlySalary *= 1.1;
        niceEmployee.setMonthlySalary(newMonthlySalary);
        System.out.println(niceEmployee);

        // coolEmployee
        newMonthlySalary = coolEmployee.getMonthlySalary();
        newMonthlySalary *= 1.1;
        coolEmployee.setMonthlySalary(newMonthlySalary);
        System.out.println(coolEmployee);

    }

}

