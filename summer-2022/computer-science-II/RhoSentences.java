// COSC 211
// Soobin Rho
// July 21, 2022
import java.util.Scanner;
import java.security.SecureRandom;

public class RhoSentences {
    /*
     * Exercise 14.5
     * Generate random sentences using
     * random-number generation.
    */
    private static final int NUM_SENTENCES = 20;
    private static final int ARRAY_LENGTH = 5;
    private static final String[] ARTICLE = {
        "the", "a", "one", "some", "any"
    };
    private static final String[] NOUN = {
        "boy", "girl", "dog", "town", "car"
    };
    private static final String[] VERB = {
        "drove", "jumped", "ran", "walked", "skipped"
    };
    private static final String[] PREPOSITION = {
        "to", "from", "over", "under", "on"
    };

    // Initializing a SecureRandom object.
    // This will be used for generating a random number.
    private static final SecureRandom random = new SecureRandom();

    public static void main(String[] args) {

        // ---------------------------------------
        // Overview
        // 1. Initialize a String.
        // 2. Choose a random article. Capitalize.
        // 3. Choose a random noun.
        // 4. Choose a random verb.
        // 5. Choose a random preposition.
        // 6. Choose a random article.
        // 7. Choose a random noun. End with a "."
        // ---------------------------------------

        for (int count = 0; count < NUM_SENTENCES; count++) {

            // 1. Initialize a String.
            String output = "";

            // 2. Choose a random article. Capitalize.
            int randomValue = getRandomValue();
            output = output.concat(ARTICLE[randomValue]);
            output = (
                output.substring(0, 1).toUpperCase() +
                output.substring(1) + " "
            );

            // 3. Choose a random noun.
            randomValue = getRandomValue();
            output = output.concat(NOUN[randomValue] + " ");

            // 4. Choose a random verb.
            randomValue = getRandomValue();
            output = output.concat(VERB[randomValue] + " ");

            // 5. Choose a random preposition.
            randomValue = getRandomValue();
            output = output.concat(PREPOSITION[randomValue] + " ");

            // 6. Choose a random article.
            randomValue = getRandomValue();
            output = output.concat(ARTICLE[randomValue] + " ");

            // 7. Choose a random noun. End with a "."
            randomValue = getRandomValue();
            output = output.concat(NOUN[randomValue] + ".");

            // Print the output.
            System.out.println(output);

        }

    }

    // A method for getting a random number
    // between 0 and (ARRAY_LENGTH - 1).
    private static int getRandomValue() {
        int randomValue = random.nextInt(ARRAY_LENGTH);
        return randomValue;
    }

}

