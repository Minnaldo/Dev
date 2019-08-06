package ws_java_0805;

public class ISBNNotFoundException extends Exception{
    public ISBNNotFoundException() {
        System.out.println("Exception :: ISBNNotFoundException");
    }

    public ISBNNotFoundException(String message) {
        super(message);
    }

    public ISBNNotFoundException(String message, Throwable cause) {
        super(message, cause);
    }

    public ISBNNotFoundException(Throwable cause) {
        super(cause);
    }

    public ISBNNotFoundException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
