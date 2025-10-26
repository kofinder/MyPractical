package designpatterns.behaviour;

/*
 * The State pattern allows an object to change its behavior when its internal state changes
 * Example: TCP connection states (Closed, Listening, Established)
 * Object changes behavior based on its state.
 */

// State interface
interface State {
    void doAction(Context context);
}

// Concrete States
class StartState implements State {
    public void doAction(Context context) {
        System.out.println("Player is in Start State");
        context.setState(this);
    }
}

class StopState implements State {
    public void doAction(Context context) {
        System.out.println("Player is in Stop State");
        context.setState(this);
    }
}

// Context
class Context {
    private State state;

    public void setState(State state) {
        this.state = state;
    }

    public State getState() {
        return state;
    }
}

public class StatePattern {
    public static void main(String[] args) {
        Context context = new Context();
        StartState start = new StartState();
        start.doAction(context);

        StopState stop = new StopState();
        stop.doAction(context);

    }
}
