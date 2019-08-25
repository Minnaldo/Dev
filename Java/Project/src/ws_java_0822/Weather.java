package ws_java_0822;

public class Weather {
    private int seq;
    private int hour;
    private double temp;
    private String wfKor;
    private int reh;

    public Weather() {
    }

    public Weather(int hour, double temp, String wfKor, int reh) {
        this.hour = hour;
        this.temp = temp;
        this.wfKor = wfKor;
        this.reh = reh;
    }

    public int getSeq() {
        return seq;
    }

    public void setSeq(int seq) {
        this.seq = seq;
    }

    @Override
    public String toString() {
        return "Weather{" +
                "seq=" + seq +
                ", hour=" + hour +
                ", temp=" + temp +
                ", wfKor='" + wfKor + '\'' +
                ", reh=" + reh +
                '}';
    }

    public int getHour() {
        return hour;
    }

    public void setHour(int hour) {
        this.hour = hour;
    }

    public double getTemp() {
        return temp;
    }

    public void setTemp(double temp) {
        this.temp = temp;
    }

    public String getWfKor() {
        return wfKor;
    }

    public void setWfKor(String wfKor) {
        this.wfKor = wfKor;
    }

    public int getReh() {
        return reh;
    }

    public void setReh(int reh) {
        this.reh = reh;
    }
}
