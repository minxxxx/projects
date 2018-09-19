package com.avaj.simulator;

import java.io.*;
import java.util.*;

import com.avaj.simulator.*;
import com.avaj.simulator.vehicles.*;
import com.avaj.weather.*;

public class Simulator {

    private static List<Flyable> flyableList = new ArrayList<Flyable>();
    private static WeatherTower weatherTower;
    public static PrintWriter fileWriter;
    public static void main(String[] args) throws InterruptedException {

        AircraftFactory aircraftFactory = new AircraftFactory();

        try {
        	File simFile = new File("simulation.txt");
        	fileWriter = new PrintWriter(simFile);
            BufferedReader reader = new BufferedReader(new FileReader(args[0]));
            String line = reader.readLine();
            if (line != null) {
                weatherTower = new WeatherTower();
                int loop = Integer.parseInt(line.split(" ")[0]);

                if (loop < 0) {
                    System.out.println("Invalid simulations count " + loop);
                    System.exit(1);
                }

                while ((line = reader.readLine()) != null) {
                    String[] parsedCraft = line.split(" ");
                    try {
                        Flyable aircraft = aircraftFactory.newAircraft(parsedCraft[0],
                                        parsedCraft[1], Integer.parseInt(parsedCraft[2]), 
                                        Integer.parseInt(parsedCraft[3]),
                                        Integer.parseInt(parsedCraft[4]));
                        flyableList.add(aircraft);
                    } catch (ArrayIndexOutOfBoundsException e) {
                        System.out.println("Simulation file is invalid at: " + line);
                    }
                    
                }

                for (Flyable flyable : flyableList) {
                    flyable.registerTower(weatherTower);
                }

                for (int i = 0; i < loop; i++) {
                    weatherTower.changeWeather();
                }
                fileWriter.close();
            }
            reader.close();
        } catch (FileNotFoundException e) {
            System.out.println("Could not find file " + args[0]);
        } catch (IOException e) {
            System.out.println("There was an error reading the file " + args[0]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Specify simulation file " + args[0]);
        } catch (Exception e) {
            System.out.println("There was some error with the simulation file");
        }
    }
}