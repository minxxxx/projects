import java.applet.*;
import java.awt.*;
public class MyApplet extends Applet
{
	private static final long serialVersionUID = 1L;
	int height, width;
	public void init()
	{
		height = getSize().height;
		width = getSize().width;
		setName("MyApplet");
	}
	public void paint(Graphics g)
	{
		g.drawRoundRect(10, 30, 120, 120, 2, 3);
	}
}
