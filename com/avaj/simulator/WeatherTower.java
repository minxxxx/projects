package com.avaj.simulator;

import com.avaj.weather.Coordinates;
import com.avaj.weather.WeatherProvider;


public class WeatherTower extends Tower{
    public String getWeather(Coordinates coordinates) {
        WeatherProvider weatherProvider = WeatherProvider.getProvider();
        return weatherProvider.getCurrentWeather(coordinates);
    }

    void changeWeather() {
        this.conditionsChanged();
    }
}