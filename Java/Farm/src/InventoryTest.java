import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class InventoryTest {

    @Test
    void addItem() throws Exception {
        Inventory inventory = new Inventory();
        Item item = new Tool("Hoe");

        inventory.addItem(item);
        assertEquals(item,inventory.getItem(0));
    }

    @Test
    void getItem() throws Exception {
        Inventory inventory = new Inventory();
        Item item = new Tool("Hoe");
        Item item1 = new Tool("Axe");
        Item item2 = new Tool("Hand");

        inventory.addItem(item);
        inventory.addItem(item1);
        inventory.addItem(item2);

        assertEquals(item,inventory.getItem(0));
        assertEquals(item1,inventory.getItem(1));
        assertEquals(item2,inventory.getItem(2));
    }
}