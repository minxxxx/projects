import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * testSwing
 */
public class testSwing extends JFrame
{
	testSwing()
	{
		JButton jButton1 = new JButton("Yes");
		JButton jButton2 = new JButton("Yeno");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new FlowLayout());
		add(jButton1);
		add(jButton2);
		setSize(400, 400);
		setVisible(true);
	}

	public static void main(String[] args) {
		new testSwing();
	}
}