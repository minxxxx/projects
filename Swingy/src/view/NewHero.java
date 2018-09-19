package view;

import java.awt.Color;

import javax.swing.DefaultComboBoxModel;
import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.GroupLayout.Alignment;
import javax.swing.GroupLayout.Group;
import javax.swing.LayoutStyle.ComponentPlacement;

import com.sun.xml.internal.ws.api.Component;

import controller.CharacterController;
import model.characters.Hero;

/**
 * NewHero
 */
public class NewHero extends JPanel
{
	private static final long serialVersionUID = 1L;
	private CharacterController characterController = new CharacterController();
	private WindowManager windowManager;

	public NewHero(WindowManager windowManager)
	{
		this.windowManager = windowManager;
		initComponents();
	}

	private void initComponents()
	{
		JTextField	jTextField 		= new JTextField();
		JLabel		jLabel1 		= new JLabel();
		JLabel		jLabel2 		= new JLabel();
		JLabel		errorMessage 	= new JLabel();
		errorMessage.setForeground(Color.RED);;
		JComboBox	jComboBox1		= new JComboBox<>();
		JButton		jButton1		= new JButton();

		jLabel1.setText("Name");
		jLabel2.setText("Type");
		jComboBox1.setModel(new DefaultComboBoxModel<>(new String[]{"Knight", "Elf"}));
		jButton1.setText("Create");
		jButton1.addActionListener((evt) {jButton1ActionPerformed(evt);});

		GroupLayout layout 			= new GroupLayout(this);
		this.setLayout(layout);
		layout.setHorizontalGroup(layout.createParallelGroup(Alignment.LEADING)
			.addGroup(layout.createSequentialGroup()
				.addGroup(layout.createParallelGroup(Alignment.LEADING)
					.addGroup(layout.createSequentialGroup()
						.addGap(29, 29, 29)
						.addGroup(layout.createParallelGroup(Alignment.LEADING)
							.addGroup(layout.createSequentialGroup()
								.addComponent(jLabel2)
								.addPreferredGap(ComponentPlacement.UNRELATED)
								.addComponent(jComboBox1, GroupLayout.PREFERRED_SIZE))
							.addGroup(layout.createSequentialGroup()
								.addComponent(jLabel1)
								.addPreferredGap(ComponentPlacement.UNRELATED)
								.addComponent(jTextField, GroupLayout.PREFERRED_SIZE)
								.addPreferredGap(ComponentPlacement.UNRELATED)
							)))
					.addGroup(layout.createSequentialGroup()
						.addGap(29, 29, 29)
						.addComponent(errorMessage))
					.addGroup(layout.createSequentialGroup()
						.addGap(80, 80, 80)
						.addComponent(jButton1)))
				.addContainerGap(30, Short.MAX_VALUE))
		);
		layout.setVerticalGroup(
			layout.createParallelGroup(Alignment.LEADING)
				.addGroup(Alignment.TRAILING, layout.createSequentialGroup()
					.addGap(19, 19, 19)
					.addGroup(layout.createParallelGroup(Alignment.BASELINE)
						.addComponent(jLabel2)
						.addComponent(jComboBox1, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE))
						.
		);
	}

}