package app.programming.homework;

public class TV {
	private int proNum;	// 제품 번호
	private String name;	// 제품 이름
	private int price;	// 제품 가격
	private int stock;	// 제품 재고
	private int inch;	// 제품의 화면 크기
	private String type;	// 제품의 디스플레이 타입

	TV() {
	}

	TV(int proNum, String name, int price, int stock, int inch, String type) {
		this.proNum = proNum;
		this.name = name;
		this.price = price;
		this.stock = stock;
		this.inch = inch;
		this.type = type;
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

	public int getInch() {
		return inch;
	}

	public void setInch(int inch) {
		this.inch = inch;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public String toString() {
		return proNum + " | " + name + " | " + price + " | " + stock + " | " + inch + " | " + type;
	}
}
