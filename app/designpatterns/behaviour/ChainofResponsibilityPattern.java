package designpatterns.behaviour;

/*
 * Chain of Responsibility → pass request along chain of handlers
    * The Chain of Responsibility pattern passes a request along a chain of handlers until one handles it
    * Example: Event handling in UI components
 */

// Handler
abstract class Logger {
    public static int INFO = 1;
    public static int DEBUG = 2;
    public static int ERROR = 3;

    protected int level;
    protected Logger nextLogger;

    public void setNextLogger(Logger nextLogger) {
        this.nextLogger = nextLogger;
    }

    public void logMessage(int level, String message) {
        if (this.level <= level)
            write(message);
        if (nextLogger != null)
            nextLogger.logMessage(level, message);
    }

    abstract protected void write(String message);
}

// Concrete Handlers
class ConsoleLogger extends Logger {
    public ConsoleLogger(int level) {
        this.level = level;
    }

    protected void write(String message) {
        System.out.println("Console::Logger: " + message);
    }
}

class ErrorLogger extends Logger {
    public ErrorLogger(int level) {
        this.level = level;
    }

    protected void write(String message) {
        System.out.println("Error::Logger: " + message);
    }
}

public class ChainofResponsibilityPattern {
    public static Logger getChainOfLoggers() {
        Logger errorLogger = new ErrorLogger(Logger.ERROR);
        Logger consoleLogger = new ConsoleLogger(Logger.INFO);

        errorLogger.setNextLogger(consoleLogger);
        return errorLogger;
    }

    public static void main(String[] args) {
        Logger loggerChain = getChainOfLoggers();
        loggerChain.logMessage(Logger.INFO, "This is an info message.");
        loggerChain.logMessage(Logger.ERROR, "This is an error message.");

    }
}
