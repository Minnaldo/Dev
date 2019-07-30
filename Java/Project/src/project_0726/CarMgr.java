package project_0726;

public class CarMgr {

    private static CarMgr cm = new CarMgr();

    // getInstance를 통해 클래스 외부로 클래스의 기능을 제공한다
    public static CarMgr getInstance() {
        return cm;
    }

    // 싱글톤 패턴을 사용하기 위해 생성자는 private 선언
    private CarMgr() {
    }

    // Car형 배열에 들어간 데이터의 마지막을 가리킨다
    private int index = 0;
    private Car[] cars = new Car[100];
    // Car형 배열의 doubling을 위한 변수
    private int max = 100;

    public void add(Car c) {
        if (index < max) {
            if (index > 0) {
                boolean flag = false;
                for (int i = 0; i < index; i++) {
                    if (cars[i].getNum().equals(c.getNum())) {
                        flag = true;
                    }
                }
                if (!flag) {
                    cars[index++] = c;

                } else {
                    System.out.println("해당 모델이 데이터베이스에 존재합니다.");
                }

            } else if(index == 0) {
                cars[index++] = c;
            }
            System.out.println("index="+index);

        } else {
            // array doubling
            max *= 2;
            Car[] tmp = new Car[max];
            System.arraycopy(cars, 0, tmp, 0, cars.length);
            cars = tmp;
            index++;
            cars[index] = c;
            System.out.println("index="+index);
        }
    }

    public Car[] search() {

        if (index > 0) {
            Car[] tmp = new Car[index];
            for (int i = 0; i < index; i++) {
                if (cars[i].getNum() != null)
                    tmp[i] = cars[i];
            }
            return tmp;
        } else {
            System.out.println("데이터가 없습니다");
            return null;
        }
    }

    public Car search(String num) {
        if (index > 0)
            for (int i = 0; i < index; i++) {
                if (cars[i].getNum().equals(num)) {
                    return cars[i];
                }
            }
        System.out.println("저장된 정보가 없습니다");
        return null;
    }

    public Car[] search(int price) {
        Car[] tmp = new Car[index];
        for (int i = 0; i < index; i++) {
            if (cars[i].getPrice() < price) {
                tmp[i] = cars[i];
            }
        }
        return tmp;
    }

    public void update(String num, int price) {
        for (int i = 0; i < index; i++) {
            if (cars[i].getNum().equals(num)) {
                cars[i].setPrice(price);
                break;
            }
        }
    }

    public void delete(String num) {
        boolean flag = false;
        for (int i = 0; i < index - 1; i++) {
            if (cars[i].getNum().equals(num)) {
                cars[i] = cars[index];
                cars[index--] = null;
                flag = true;
            }
        }

        if (!flag) {
            cars[index--] = null;
        }

    }

    public int size() {
        return index;
    }

    public int totalPrice() {
        int sum = 0;
        for (int i = 0; i < index; i++) {
            sum += cars[i].getPrice();
        }
        return sum;
    }


}
