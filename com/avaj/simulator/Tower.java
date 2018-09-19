package com.avaj.simulator;

import com.avaj.simulator.vehicles.Flyable;
import java.util.ArrayList;
import java.util.List;

public abstract class Tower {
    private List<Flyable> observers = new ArrayList<Flyable>();

    public void register (Flyable flyable) {
        if (observers.contains(flyable) == false) {
            observers.add(flyable);
        }
    }

    public void unregister(Flyable flyable) {
        if (observers.contains(flyable))
            observers.remove(flyable);
    }

    protected void conditionsChanged() {
        for (int i = 0; i < observers.size(); i++) {
            observers.get(i).updateConditions();
        }
    }
}