package fri_project;

public class Truck extends Car {

    private int ton;

    public Truck() {
    }

    public int getTon() {
        return ton;
    }

    public void setTon(int ton) {
        this.ton = ton;
    }

    public Truck(String carNum, String model, int price, int ton) {
        super(carNum, model, price);
        this.ton = ton;
    }

    @Override
    public String toString() {
        return "Truck{" +
                "CarNum=" + super.getNum() +
                "Model=" + super.getModel() +
                "Price=" + super.getPrice() +
                "ton=" + ton +
                '}';
    }
}
