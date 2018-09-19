import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * checkBox
 */
public class checkbox extends JFrame{

	String namString[] = {"me","yuou","us"};
	public checkbox()
	{
		JComboBox jComboBox = new JComboBox<>(namString);
		add(jComboBox);
		setLayout(new FlowLayout());
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(400, 400);
		setVisible(true);
	}

	public static void main(String[] args) {
		new checkbox();
	}
}