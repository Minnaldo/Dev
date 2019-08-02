package fri_0802_practice;

class DuplicateContactException extends Exception {
    public DuplicateContactException() {
        super("중복된 전화번호");
    }

    public DuplicateContactException(String message) {
        super(message);
    }

    public DuplicateContactException(String message, Throwable cause) {
        super(message, cause);
    }

    public DuplicateContactException(Throwable cause) {
        super(cause);
    }

    protected DuplicateContactException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
