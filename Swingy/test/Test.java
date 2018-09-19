import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import java.applet.*;
import java.awt.event.*;
import java.awt.*;

public class Test extends Applet implements KeyListener
{
	private static final long serialVersionUID = 1L;
	String msg="Testing...";
	public void init()
	{
		addKeyListener(this);
	}
	public void keyPressed(KeyEvent k)
	{
		showStatus("KeyPressed");
	}
	public void keyReleased(KeyEvent k)
	{
		showStatus("KeyRealesed");
	}
	public void keyTyped(KeyEvent k)
	{
		msg = msg+k.getKeyChar();
		repaint();
	}
	public void paint(Graphics g)
	{
		g.drawString(msg, 20, 40);
	}
}
