package com.avaj.weather;

public class Coordinates {
    private int longitude;
    private int latitude;
    private int altitude;

    public Coordinates(int longitude, int latitude, int altitude) {
        if (longitude < 0) {
            longitude = 0;
        }
        if (latitude < 0) {
            latitude = 0;
        }
        if (altitude < 0) {
            altitude = 0;
        }
        if (altitude > 100) {
            altitude = 100;
        }
        this.longitude = longitude;
        this.latitude = latitude;
        this.altitude = altitude;
    }

    public int getLongitude() {
        if (this.longitude < 0) {
            this.longitude = 0;
        }
        return this.longitude;
    }

    public int getLatitude() {
        if (this.latitude < 0) {
            this.latitude = 0;
        }
        return this.latitude;
    }

    public int getAltitude() {
        if (this.altitude < 0) {
            this.altitude = 0;
        }
        if (this.altitude > 100) {
            this.altitude = 100;
        }
        return this.altitude;
    }

    public void setLongitude(int longitude) {
        this.longitude = longitude;
    }

    public void setLatitude(int latitude) {
        this.latitude = latitude;
    }

    public void setAltitude(int altitude) {
        this.altitude = altitude;
    }
}