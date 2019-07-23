package app.programming.homework;

public class ProductTest {

	public static void main(String[] args) {

		TV[] tv = new TV[5];
		Refrigerator[] refri = new Refrigerator[5];

		tv[0] = new TV(11, "OLED TV", 2559000, 100, 80, "OLED");
		tv[1] = new TV(21, "QLED TV", 650000, 100, 65, "OLED");
		tv[2] = new TV(31, "OLED TV", 1000000, 100, 55, "LCD");
		tv[3] = new TV(41, "OLED TV", 5000000, 100, 80, "LCD");
		tv[4] = new TV(15, "LCD TV", 3200000, 100, 32, "LCD");

		refri[0] = new Refrigerator(11, "BESPOKE", 2000000, 10, 500);
		refri[1] = new Refrigerator(21, "BESPOKE", 2300000, 20, 600);
		refri[2] = new Refrigerator(13, "BESPOKE", 3000000, 5, 550);
		refri[3] = new Refrigerator(15, "BESPOKE", 1800000, 11, 400);
		refri[4] = new Refrigerator(19, "BESPOKE", 3500000, 13, 450);


		for(int i = 0; i<5; i++)
		{
			System.out.println(tv[i].toString());
		}

		for(int i = 0; i<5; i++)
		{
			System.out.println(refri[i].toString());
		}
	}

}
