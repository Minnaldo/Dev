package hw_java_0730;

import java.time.Duration;

import static org.junit.Assert.*;

public class ProductTestTest {

    long start, end;

    @org.junit.Before
    public void setUp() throws Exception {
        start = System.nanoTime();
    }

    @org.junit.After
    public void tearDown() throws Exception {
        end = System.nanoTime();
        System.out.println("Duration : " + Duration.ofNanos(start));
    }

    @org.junit.Test
    public void main() {
        ProductTest pt = new ProductTest();
        pt.main(null);
    }
}