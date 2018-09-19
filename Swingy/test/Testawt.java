import java.awt.*;

public class Testawt extends Frame
{
	private static final long serialVersionUID = 1L;

	Testawt()
	{
		Button button = new Button("Hello Zupirio");
		add(button);
		setSize(400, 500);
		setTitle("Zunar");
		setLayout(new FlowLayout());
		setVisible(true);
	}

	public static void main(String[] args)
	{
		new Testawt();
	}
}