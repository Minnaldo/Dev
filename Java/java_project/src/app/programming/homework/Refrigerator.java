package app.programming.homework;

public class Refrigerator {
	private int proNum;
	private String name;
	private int price;
	private int stock;
	private int capacity;

	Refrigerator() {

	}

	Refrigerator(int proNum, String name, int price, int stock, int capacity) {
		super();
		this.proNum = proNum;
		this.name = name;
		this.price = price;
		this.stock = stock;
		this.capacity = capacity;
	}

	public int getProNum() {
		return proNum;
	}

	public void setProNum(int proNum) {
		this.proNum = proNum;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getPrice() {
		return price;
	}

	public void setPrice(int price) {
		this.price = price;
	}

	public int getStock() {
		return stock;
	}

	public void setStock(int stock) {
		this.stock = stock;
	}

	public int getCapacity() {
		return capacity;
	}

	public void setCapacity(int capacity) {
		this.capacity = capacity;
	}

	public String toString() {
		return proNum + " | " + name + " | " + price + " | " + stock + " | " + capacity;
	}

}
