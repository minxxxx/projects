import javax.swing.*;
import java.awt.*;

/**
 * First
 */
public class First
{

	JFrame jFrame;

	public First()
	{
		jFrame = new JFrame("myWindow");
		JButton jButton = new JButton("Say hello");
		add(jButton);
		setLayout(new FlowLayout());
		setDefaultCloseOperation(jFrame.EXIT_ON_CLOSE);
		setSize(400, 400);
		setVisible(true);
	}

	public static void main(String[] args) {
		new First();
	}
}