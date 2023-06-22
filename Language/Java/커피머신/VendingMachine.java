package 커피머신;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class VendingMachine extends JFrame {
	// 안내문 UI
	private JLabel UI_Label;

	// 밀크, 설탕, 커피
	private MilkBox milk = new MilkBox();
	private SugerBox suger = new SugerBox();
	private CoffeeBox coffee = new CoffeeBox();

	// 밀크버튼, 설탕버튼, 커피버튼
	private JButton milkCoffeeButton = new JButton("<html><body><center>밀크커피<br>(3백원)</center></body></html>");
	private JButton sugerCoffeeButton = new JButton("<html><body><center>설탕커피<br>(2백원)</center></body></html>");
	private JButton blackCoffeeButton = new JButton("<html><body><center>블랙커피<br>(1백원)</center></body></html>");
	
	// 캐시 박스
	private CasherBox cb = new CasherBox();

	public VendingMachine() {
		setTitle("커피머신");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		Container c = getContentPane();
		c.setLayout(null);

		// 안내문 UI--------------------------------------------------------
		UI_Label = new JLabel();
		UI_Label.setSize(160, 70);
		UI_Label.setLocation(100, 170);
		UI_Label.setHorizontalAlignment(JLabel.CENTER); // 텍스트 가운데 정렬
		c.add(UI_Label);
		// -----------------------------------------------------------------

		// 잔액 UI---------------------------------------------------------
		JLabel balanceText = new JLabel("잔액: ");
		balanceText.setSize(100, 50);
		balanceText.setLocation(20, 10);
		c.add(balanceText);

		JTextField balanceField = new JTextField(20);
		balanceField.setEditable(false); // 편집 불가능하도록 설정
		balanceField.setSize(250, 23);
		balanceField.setLocation(50, 25);
		balanceField.setText(Integer.toString(cb.ejectBalance())); // 잔액을 표시
		c.add(balanceField);
		// -----------------------------------------------------------------

		// 밀크커피 UI---------------------------------------------------------
		milkCoffeeButton.setBounds(20, 70, 90, 30);
		milkCoffeeButton.setEnabled(false);
		milkCoffeeButton.setBackground(Color.GRAY);

		milkCoffeeButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// 우유와 커피의 재료가 충족되면 버튼이 눌렸을 때 커피가 나온다.
				// 그것이 아니라면 재료가 부족하다는 안내문 띄우기
				if(milk.eject() && coffee.eject()) {
					cb.addBalance(-300);
					balanceField.setText(Integer.toString(cb.ejectBalance()));
					
					checkButton();
					UI_Label.setText("밀크커피가 나왔습니다.");
				}
				else 
					UI_Label.setText("<html>재료(밀크)가 부족합니다.<br>죄송하지만 다음에 이용 부탁 드립니다.</html>");
			}
		});

		c.add(milkCoffeeButton);
		// -----------------------------------------------------------------
		
		// 설탕커피 UI---------------------------------------------------------
		sugerCoffeeButton.setBounds(120,70,90,30);
		sugerCoffeeButton.setEnabled(false);
		sugerCoffeeButton.setBackground(Color.GRAY);

		sugerCoffeeButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// 설탕과 커피의 재료가 충족되면 버튼이 눌렸을 때 커피가 나온다.
				// 그것이 아니라면 재료가 부족하다는 안내문 띄우기
				if(suger.eject() && coffee.eject()) {
					cb.addBalance(-200);
					balanceField.setText(Integer.toString(cb.ejectBalance()));
					
					checkButton();
					UI_Label.setText("설탕커피가 나왔습니다.");
				}
				else 
					UI_Label.setText("<html>재료(설탕)가 부족합니다.<br>죄송하지만 다음에 이용 부탁 드립니다.</html>");
			}
		});

		c.add(sugerCoffeeButton);
		// -----------------------------------------------------------------
		
		// 블랙커피 UI---------------------------------------------------------
		blackCoffeeButton.setBounds(220,70,90,30);
		blackCoffeeButton.setEnabled(false);
		blackCoffeeButton.setBackground(Color.GRAY);
		
		blackCoffeeButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// 커피의 재료가 충족되면 버튼이 눌렸을 때 커피가 나온다.
				// 그것이 아니라면 재료가 부족하다는 안내문 띄우기
				if(coffee.eject()) {
					cb.addBalance(-100);
					balanceField.setText(Integer.toString(cb.ejectBalance()));
					
					checkButton();
					UI_Label.setText("블랙커피가 나왔습니다.");
				}
				else 
					UI_Label.setText("<html>재료(커피)가 부족합니다.<br>죄송하지만 다음에 이용 부탁 드립니다.</html>");
			}
		});

		c.add(blackCoffeeButton);
		// -----------------------------------------------------------------

		// 현급 투입 UI--------------------------------------------------------
		JLabel cashText = new JLabel("현금 투입: ");
		cashText.setSize(100, 50);
		cashText.setLocation(50, 120);
		c.add(cashText);

		JTextField cashField = new JTextField(20);
		cashField.setSize(60, 23);
		cashField.setLocation(110, 135);
		c.add(cashField);

		JButton inputButton = new JButton("투입");
		inputButton.setBounds(176, 135, 60, 23);

		// 돈이 투입되면 잔액 UI에 표시가 된다.
		inputButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String inputText = cashField.getText();
				int insertedAmount = Integer.parseInt(inputText);
				cb.addBalance(insertedAmount);
				balanceField.setText(Integer.toString(cb.ejectBalance()));
				
				checkButton();
			}
		});

		c.add(inputButton);

		// 반환 버튼
		JButton ejectButton = new JButton("반환");
		ejectButton.setBounds(240, 135, 60, 23);
		ejectButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// 잔액이 반환되었음을 알리는 UI
				UI_Label.setText("잔액 " + cb.ejectBalance() + "원이 반환되었습니다.");

				// 현재 잔액 0원으로 초기화
				int money = cb.ejectBalance();
				cb.addBalance(-money);
				balanceField.setText(Integer.toString(cb.ejectBalance()));

				checkButton();
			}
		});

		c.add(ejectButton);
		// -----------------------------------------------------------------

		setSize(350, 300);
		setVisible(true);
	}
	
	// 버튼을 지속적으로 검토해주는 메소드
	private void checkButton() {
		// 밀크커피 잔액이 충족되면 버튼 노란색으로 활성화
		if (cb.ejectBalance() >= 300) {
			milkCoffeeButton.setEnabled(true);
			milkCoffeeButton.setBackground(Color.YELLOW);
		} else {
			milkCoffeeButton.setEnabled(false);
			milkCoffeeButton.setBackground(Color.GRAY);
		}
		
		// 설탕커피 잔액이 충족되면 버튼 노란색으로 활성화
		if (cb.ejectBalance() >= 200) {
			sugerCoffeeButton.setEnabled(true);
			sugerCoffeeButton.setBackground(Color.YELLOW);
		} else {
			sugerCoffeeButton.setEnabled(false);
			sugerCoffeeButton.setBackground(Color.GRAY);
		}
		
		// 블랙커피 잔액이 충족되면 버튼 노란색으로 활성화
		if (cb.ejectBalance() >= 100) {
			blackCoffeeButton.setEnabled(true);
			blackCoffeeButton.setBackground(Color.YELLOW);
		} else {
			blackCoffeeButton.setEnabled(false);
			blackCoffeeButton.setBackground(Color.GRAY);
		}
	}

	public static void main(String[] args) {
		new VendingMachine();
	}
}
