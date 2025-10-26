package threads.sync.src;

import java.util.HashMap;
import java.util.Map;

class SafeMap {
    private Map<String, Integer> map = new HashMap<>();

    public void put(String key, int value) {
        synchronized (map) {
            map.put(key, value);
        }
    }

    public int get(String key) {
        synchronized (map) {
            return map.getOrDefault(key, 0);
        }
    }
}
