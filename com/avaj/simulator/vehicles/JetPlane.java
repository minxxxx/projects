package com.avaj.simulator.vehicles;

import com.avaj.simulator.vehicles.Aircraft;
import com.avaj.weather.Coordinates;
import com.avaj.simulator.Simulator;
import com.avaj.simulator.WeatherTower;

public class JetPlane extends Aircraft implements Flyable{
    private WeatherTower weatherTower = new WeatherTower();

    JetPlane(String name, Coordinates coordinates) {
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
                Simulator.fileWriter.printf("JetPlane#%s(%d): Hell has come to take us all!\n", this.name, this.id); 
                break;
            case "RAIN":
                this.coordinates.setLongitude(this.coordinates.getLongitude() + 5);
                Simulator.fileWriter.printf("JetPlane#%s(%d): It's raining. Better watch out for lightning!\n", this.name, this.id); 
                break;
            case "FOG":
                this.coordinates.setLongitude(this.coordinates.getLongitude() + 1);
                Simulator.fileWriter.printf("JetPlane#%s(%d): I'm flying blind.\n", this.name, this.id); 
                break;
            case "SNOW":
                this.coordinates.setAltitude(this.coordinates.getAltitude() - 7);
                Simulator.fileWriter.printf("JetPlane#%s(%d): OMG! Winter is coming!\n", this.name, this.id); 
                break;
        }

        if (this.coordinates.getAltitude() > 100) {
            this.coordinates.setAltitude(100);
        }

        if (this.coordinates.getAltitude() <= 0) {
            this.weatherTower.unregister(this);
            Simulator.fileWriter.printf("JetPlane#%s(%d) landing at %d %d %d.\n", this.name, this.id,
            this.coordinates.getAltitude(), this.coordinates.getLongitude(), this.coordinates.getLatitude());
            Simulator.fileWriter.printf("Tower says: JetPlane#%s(%d) unregistered from weather tower.\n", this.name, this.id);

        }                                            
    }

    public void registerTower(WeatherTower weatherTower) {
        this.weatherTower = weatherTower;
        this.weatherTower.register(this);
        Simulator.fileWriter.printf("Tower says: JetPlane#%s(%d) has registered to the weather tower \n", this.name, this.id);
    }
}