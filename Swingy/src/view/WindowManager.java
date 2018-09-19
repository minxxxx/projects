package view;
import model.characters.Hero;
public interface WindowManager
{
	void showSelectHero();
	void showNewHero();
	void showSelectHero(Hero hero);
}