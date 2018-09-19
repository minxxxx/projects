package com.avaj.simulator.vehicles;

import com.avaj.simulator.vehicles.Aircraft;
import com.avaj.weather.Coordinates;
import com.avaj.simulator.WeatherTower;
import com.avaj.simulator.Simulator;

public class Helicopter extends Aircraft implements Flyable{
    private WeatherTower weatherTower = new WeatherTower();

    Helicopter(String name, Coordinates coordinates) {
        super(name, coordinates);
        // this.name = name;
        // this.coordinates = coordinates;
    }

    public void updateConditions() {
        String weather = weatherTower.getWeather(this.coordinates);

        switch (weather) {
            case "SUN":
                this.coordinates.setLongitude(this.coordinates.getLongitude() + 10);
                this.coordinates.setAltitude(this.coordinates.getAltitude() + 2);
                Simulator.fileWriter.printf("Helicopter#%s(%d): This is hot.\n", this.name, this.id);                
                break; 
            case "RAIN":
                this.coordinates.setLongitude(this.coordinates.getLongitude() + 5);
                Simulator.fileWriter.printf("Helicopter#%s(%d): Water is flooding the cabin!\n", this.name, this.id);
                break;
            case "FOG":
                this.coordinates.setLongitude(this.coordinates.getLongitude() + 1);
                Simulator.fileWriter.printf("Helicopter#%s(%d): Someone get a bigger fan! The fog is blocking my view.\n", this.name, this.id); 
                break;
            case "SNOW":
                this.coordinates.setAltitude(this.coordinates.getAltitude() - 12);
                Simulator.fileWriter.printf("Helicopter#%s(%d): My rotor is going to freeze!\n", this.name, this.id); 
                break;

        }

        if (this.coordinates.getAltitude() > 100) {
            this.coordinates.setAltitude(100);
        }

        if (this.coordinates.getAltitude() <= 0) {
            this.weatherTower.unregister(this);
            Simulator.fileWriter.printf("Helicopter#%s(%d) landing at %d %d %d.\n", this.name, this.id,
            this.coordinates.getAltitude(), this.coordinates.getLongitude(), this.coordinates.getLatitude());
            Simulator.fileWriter.printf("Tower says: Helicopter#%s(%d) unregistered from weather tower.\n", this.name, this.id);

        }

    }

    public void registerTower(WeatherTower weatherTower) {
        this.weatherTower = weatherTower;
        this.weatherTower.register(this);
        Simulator.fileWriter.printf("Tower says: Helicopter#%s(%d) has registered to the weather tower \n", this.name, this.id);
    }
}