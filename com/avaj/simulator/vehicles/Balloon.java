package com.avaj.simulator.vehicles;

import com.avaj.simulator.Simulator;
import com.avaj.simulator.vehicles.Aircraft;
import com.avaj.weather.Coordinates;
import com.avaj.simulator.WeatherTower;

public class Balloon extends Aircraft implements Flyable{
    private WeatherTower weatherTower = new WeatherTower();

    Balloon(String name, Coordinates coordinates) {
        super(name, coordinates);
        // this.name = name;
        // this.coordinates = coordinates;
    }

    public void updateConditions() {
        String weather = weatherTower.getWeather(this.coordinates);

        switch (weather) {
            case "SUN":
                this.coordinates.setLongitude(this.coordinates.getLongitude() + 2);
                this.coordinates.setAltitude(this.coordinates.getAltitude() + 4);
                Simulator.fileWriter.printf("Balloon#%s(%d): Let's enjoy the good weather and take some pics.\n", this.name, this.id);
                break;
            case "RAIN":
                this.coordinates.setLongitude(this.coordinates.getLongitude() -5);
                Simulator.fileWriter.printf("Balloon#%s(%d): : Damn you rain! You messed up my balloon.\n", this.name, this.id);
                break;
            case "FOG":
                this.coordinates.setLongitude(this.coordinates.getLongitude() -3);
                Simulator.fileWriter.printf("Balloon#%s(%d): : I can't see! The FOG!\n", this.name, this.id);
                break;
            case "SNOW":
                this.coordinates.setAltitude(this.coordinates.getAltitude() - 15);
                Simulator.fileWriter.printf("Balloon#%s(%d): : It's snowing. We're gonna crash.\n", this.name, this.id);
                break;
        }

        if (this.coordinates.getAltitude() > 100) {
            this.coordinates.setAltitude(100);
        }

        if (this.coordinates.getAltitude() <= 0) {
            this.weatherTower.unregister(this);
            Simulator.fileWriter.printf("Balloon#%s(%d) landing at %d %d %d.\n", this.name, this.id,
                this.coordinates.getAltitude(), this.coordinates.getLongitude(), this.coordinates.getLatitude());
            Simulator.fileWriter.printf("Tower says: Balloon#%s(%d) unregistered from weather tower.\n", this.name, this.id);

        }
        
    }

    public void registerTower(WeatherTower weatherTower) {
        this.weatherTower = weatherTower;
        this.weatherTower.register(this);
        Simulator.fileWriter.printf("Tower says: Balloon#%s(%d) has registered to the weather tower \n", this.name, this.id);
    }
}