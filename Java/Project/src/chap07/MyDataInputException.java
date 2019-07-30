package chap07;

// User defined Exception ( Customize Exception class)
// Exception을 상속받아주어야 한다.
public class MyDataInputException extends Exception {
    String errMsg;

    public MyDataInputException() {
    }

    public MyDataInputException(String errMsg) {
        this.errMsg = errMsg;
    }

    public void showError() {
        System.out.println(errMsg);
    }
}
