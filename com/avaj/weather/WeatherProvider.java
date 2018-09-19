package com.avaj.weather;

import com.avaj.weather.Coordinates;

public class WeatherProvider {
    private static WeatherProvider weatherProvider = new WeatherProvider();
    private static String[] weather = {
        "RAIN", "FOG", "SUN", "SNOW"
    };

    private WeatherProvider() {

    }
    
    public static WeatherProvider getProvider() {
        return WeatherProvider.weatherProvider;
    }

    public String getCurrentWeather(Coordinates coordinates) {
        int weatherSeed = coordinates.getAltitude() + (coordinates.getLatitude() * coordinates.getLongitude());
        return weather[Math.abs(weatherSeed) % 4];
    }
}