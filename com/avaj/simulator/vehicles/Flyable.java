package com.avaj.simulator.vehicles;

import com.avaj.simulator.WeatherTower;

public interface Flyable {
    public void updateConditions();
    
    public void registerTower(WeatherTower weatherTower);
}