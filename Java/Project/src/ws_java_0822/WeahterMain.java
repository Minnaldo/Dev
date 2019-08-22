package ws_java_0822;

public class WeahterMain {

    static WeatherDAO dao;
    static WeatherDAO2 dao2;

    public void createGUI() {

    }

    public void addEvent() {
    }

    public void showListWithDom() {
        for (Weather w : dao.getWeatherList()) {
            System.out.println(w.toString());
        }
    }

    public void showListWithSax() {
        for (Weather w : dao2.getWeatherList()) {
            System.out.println(w.toString());
        }
    }

    public static void main(String[] args) {
        dao = WeatherDAO.getInstance();
        dao2 = WeatherDAO2.getInstance();
//        new WeahterMain().showListWithDom();

        new WeahterMain().showListWithSax();
    }
}
