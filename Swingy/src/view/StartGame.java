package view;

import model.characters.Hero;

import java.awt.event.ActionEvent;

import javax.swing.*;
import javax.swing.GroupLayout.Alignment;

import com.sun.xml.internal.bind.annotation.OverrideAnnotationOf;

import javafx.event.EventTarget;

/**
 * StartGame
 */
public class StartGame extends JFrame implements WindowManager
{

	private static final long serialVersionUID = 1L;

	public StartGame()
	{ initComponents(); }

	private void initComponents()
	{
		JButton jButton = new JButton();
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

		jButton.setText("Select Hero");
		jButton.addActionListener((evt) [jButtonActionPerformed(evt)]; );

		GroupLayout layout = new GroupLayout(getContentPane());
		getContentPane().setLayout(layout);
		layout.setVerticalGroup(layout.createParallelGroup(Alignment.LEADING)
									.addGroup(Alignment.TRAILING, layout.createSequentialGroup()
									.addContainerGap(142, Short.MAX_VALUE)
									.addComponent(jButton)
									.addGap(135, 135, 135))
								);
		pack();
	}

	private void jButtonActionPerformed(ActionEvent evt)
	{ showSelectHero(); }

	public void showSelectHero()
	{
		SelectHero	selectHeroPane = new SelectHero(this);
		setContentPane(selectHeroPane);
		pack();
	}

	public void showNewHero()
	{
		NewHero newHeroPanel = new NewHero(this);
		setContentPane(newHeroPanel);
		pack();
	}

	public void showSelectMission()
	{
		NewMission newMissionPanel = new NewMission(this);
		setContentPane(newMissionPanel);
		pack();
	}

	private JButton jButton;
}