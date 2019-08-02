package fri_0802_practice;

class ContactNotFoundException extends Exception {

    public ContactNotFoundException() {
        super("존재하지 않는 전화번호 입니다");
    }

    public ContactNotFoundException(String message) {
        super(message);
    }

    public ContactNotFoundException(String message, Throwable cause) {
        super(message, cause);
    }

    public ContactNotFoundException(Throwable cause) {
        super(cause);
    }

    protected ContactNotFoundException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
