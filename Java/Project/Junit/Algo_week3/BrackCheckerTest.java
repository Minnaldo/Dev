package Algo_week3;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class BrackCheckerTest {

    long start, end = 0;

    @Before
    public void setUp() throws Exception {
        start = System.nanoTime();
    }


    @After
    public void tearDown() throws Exception {
        end = System.nanoTime();
        System.out.println("Process Time : "+ (double)(end-start)/1000000000 +" sec");
    }

    @Test
    public void main() {
        BrackChecker b = new BrackChecker();
        b.main(null);
    }
}