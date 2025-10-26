package designpatterns.behaviour;

/*
 * Memento → save & restore state
 * The Memento pattern captures and restores an object’s internal state without violating encapsulation
 * Example: Undo/Redo functionality in text editors
 */

// Originator
class TextEditor {
    private String content;

    public void setContent(String content) {
        this.content = content;
    }

    public String getContent() {
        return content;
    }

    public Memento save() {
        return new Memento(content);
    }

    public void restore(Memento m) {
        content = m.getContent();
    }

    static class Memento {
        private final String content;

        public Memento(String content) {
            this.content = content;
        }

        public String getContent() {
            return content;
        }
    }
}

public class MementoPattern {
    public static void main(String[] args) {
        TextEditor editor = new TextEditor();
        editor.setContent("Version 1");
        TextEditor.Memento saved = editor.save();

        editor.setContent("Version 2");
        System.out.println(editor.getContent()); // Version 2

        editor.restore(saved);
        System.out.println(editor.getContent()); // Version 1

    }
}
