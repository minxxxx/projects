package com.avaj.simulator.vehicles;

import com.avaj.simulator.vehicles.*;
import com.avaj.weather.*;

public class AircraftFactory {
    public Flyable newAircraft(String type, String name, int longitude, int latitude, int altitude) {
        Coordinates newCoords = new Coordinates(longitude, latitude, altitude);
        // newCoords.setLongitude(longitude);
        // newCoords.setLatitude(latitude);
        // newCoords.setAltitude(altitude);
        switch (type) {
            case "Balloon":
                Balloon newBalloon = new Balloon(name, newCoords);
                return newBalloon;
            case "JetPlane":
                JetPlane newJetPlane = new JetPlane(name, newCoords);
                return newJetPlane;
            case "Helicopter":
                Helicopter newHelicopter = new Helicopter(name, newCoords);
                return newHelicopter;
        }
        return null;
    }
}