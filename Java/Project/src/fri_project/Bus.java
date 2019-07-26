package fri_project;

public class Bus extends Car {

    private int seat;

    public Bus(String carNum, String model, int price, int seat) {
        super(carNum, model, price);
        this.seat = seat;
    }

    public Bus() {
    }

    @Override
    public String toString() {
        return "Bus{" +
                "CarNum=" + super.getNum() +
                "Model=" + super.getModel() +
                "Price=" + super.getPrice() +
                "seat=" + seat +
                '}';
    }
}
