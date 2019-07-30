package hw_java_0730;

public class CodeNotFoundException extends Exception {
    public CodeNotFoundException() {
        super();
    }

    public CodeNotFoundException(String message) {
        super(message);
    }

    public CodeNotFoundException(String message, Throwable cause) {
        super(message, cause);
    }

    public CodeNotFoundException(Throwable cause) {
        super(cause);
    }

    protected CodeNotFoundException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
