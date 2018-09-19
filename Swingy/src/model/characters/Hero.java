package model.characters;

import com.sun.istack.internal.NotNull;

public abstract class Hero extends Character
{
	@NotNull
	private Weapon	weapon;
	@NotNull
	private Armor	armor;

	int level;
	int experience;
}