import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * textField
 */
public class textField extends JFrame{

	public textField()
	{
		JTextField jTextField = new JTextField(20);
		add(jTextField);
		setLayout(new FlowLayout());
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(400, 400);
		setVisible(true);
	}

	public static void main(String[] args) {
		new textField();
	}
}