package ws_java_0805;

public class QuantityException extends Exception {
    public QuantityException() {
        System.out.println("Exception :: QuantityException");
    }

    public QuantityException(String message) {
        super(message);
    }

    public QuantityException(String message, Throwable cause) {
        super(message, cause);
    }

    public QuantityException(Throwable cause) {
        super(cause);
    }

    public QuantityException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
