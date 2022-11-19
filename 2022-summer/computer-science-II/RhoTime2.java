// COSC 211
// Soobin Rho
// July 19, 2022
import java.util.Scanner;

public class RhoTime2 {
    /*
     * A class on time.
     * This is based on Fig. 8.5
     * as instructed by Exercise 8.7
    */

    private int hour;
    private int minute;
    private int second;

    // -----------------------------
    // Constructors
    // -----------------------------
    public RhoTime2() {
        this(0, 0, 0);
    }

    public RhoTime2(int hour) {
        this(hour, 0, 0);
    }

    public RhoTime2(int hour, int minute) {
        this(hour, minute, 0);
    }

    public RhoTime2(int hour, int minute, int second) {
        if (hour < 0 || hour >= 24) {
            throw new IllegalArgumentException("Invalid hour.");
        }
        if (minute < 0 || minute >= 60) {
            throw new IllegalArgumentException("Invalid minutes.");
        }
        if (second < 0 || second >= 60) {
            throw new IllegalArgumentException("Invalid seconds.");
        }
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public RhoTime2(RhoTime2 time) {
        this(time.hour, time.minute, time.second);
    }

    // -----------------------------
    // Setters
    // -----------------------------
    public void setTime(int hour, int minute, int second) {
        if (hour < 0 || hour >= 24) {
            throw new IllegalArgumentException("Invalid hour.");
        }
        if (minute < 0 || minute >= 60) {
            throw new IllegalArgumentException("Invalid minute.");
        }
        if (second < 0 || second >= 60) {
            throw new IllegalArgumentException("Invalid second.");
        }
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public void setHour(int hour) {
        if (hour < 0 || hour >= 24) {
            throw new IllegalArgumentException("Invalid hour.");
        }
        this.hour = hour;
    }

    public void setMinute(int minute) {
        if (minute < 0 || minute >= 60) {
            throw new IllegalArgumentException("Invalid minute.");
        }
        this.minute = minute;
    }

    public void setSecond(int second) {
        if (second < 0 || second >= 60) {
            throw new IllegalArgumentException("Invalid second.");
        }
        this.second = second;
    }

    // -----------------------------
    // Getters
    // -----------------------------
    public int getHour() {return hour;}
    public int getMinute() {return minute;}
    public int getSecond() {return second;}

    // -----------------------------
    // toString Methods
    // -----------------------------
    public String toString() {
        String output = String.format(
            "%d:%02d:%02d %s",
            ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12),
            getMinute(),
            getSecond(),
            (getHour() < 12 ? "AM" : "PM")
        );
        return output;
    }

    public String toUniversalString() {
        String output = String.format(
            "%02d:%02d:%02d",
            getHour(),
            getMinute(),
            getSecond()
        );
        return output;
    }

    // -----------------------------
    // Additional Methods
    // -----------------------------
    public void tick() {

        // -----------------------------
        // Two possible cases:
        // 1. No overflow. Add as usual.
        // 2. Overflow. Add the higher up.
        // -----------------------------

        // 1. No overflow. Add as usual.
        if (second != 59) {second++;}

        // 2. Overflow. Add the higher up.
        else {
            incrementMinute();
            setSecond(0);
        }

    }

    public void incrementMinute() {

        // -----------------------------
        // Two possible cases:
        // 1. No overflow. Add as usual.
        // 2. Overflow. Add the higher up.
        // -----------------------------

        // 1. No overflow. Add as usual.
        if (minute != 59) {minute++;}

        // 2. Overflow. Add the higher up.
        else {
            incrementHour();
            setMinute(0);
        }

    }

    public void incrementHour() {

        // -----------------------------
        // Two possible cases:
        // 1. No overflow. Add as usual.
        // 2. Overflow. Next day.
        // -----------------------------

        // 1. No overflow. Add as usual.
        if (hour != 23) {hour++;}

        // 2. Overflow. Next day.
        else {setHour(0);}

    }

}

